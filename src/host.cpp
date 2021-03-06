// Implement a Exponentiation Function

#include "xcl2.hpp"
// #include "hls_math.h"
#include <algorithm>
#include <cstdio>
#include <random>
#include <vector>
#include <iostream>
#include <fstream>
#include <iterator>
#include <cmath>
#include "ap_fixed.h"


using std::vector;
using std::mt19937;
using std::generate;
using std::uniform_real_distribution;
using std::vector;

#define DATA_SIZE 10000
#define CONST_SIZE 4
#define NUM_STEPS 10

#define WORK_GROUP 4 


typedef ap_fixed<32,16> red_fix_type;

// Random number generation: Gaussian Box Muller
float gen_random() {
    std::random_device seed;
    static mt19937 re (seed());
    static std::uniform_real_distribution<float> unif(0.0, RAND_MAX);
    return unif(re);
}

red_fix_type gaussian_box_muller() {
  float x = 0.0;
  float y = 0.0;
  float euclid_sq = 0.0;

  do {
    x = 2.0 * gen_random() / static_cast<float>(RAND_MAX)-1;
    y = 2.0 * gen_random() / static_cast<float>(RAND_MAX)-1;
    euclid_sq = x*x + y*y;
  } while (euclid_sq >= 1.0);  

  float a1 = x*sqrt(-2*log(euclid_sq)/euclid_sq);
  red_fix_type o1 = static_cast<red_fix_type>(a1);  

  return o1;
}

// write source contents into .csv file
void verify(
            vector<float, aligned_allocator<float>> &source_sw_results,
            vector<red_fix_type, aligned_allocator<red_fix_type>> &source_hw_results) {

    bool match = false;
    std::ofstream output_file("./monte_sim_sw_res.csv");
    std::ostream_iterator<float> output_iterator(output_file, "\n");
    std::copy(source_sw_results.begin(), source_sw_results.end(), output_iterator);
    std::ofstream f("./monte_sim_hw_res.csv");
    std::ostream_iterator<red_fix_type> output_iter(f, "\n");
    std::copy(source_hw_results.begin(), source_hw_results.end(), output_iter);

    std::cout << "TEST " << (match ? "PASSED" : "FAILED") << std::endl;
}


void acc_measure(vector<float, aligned_allocator<float>> &source_sw_results,
            vector<red_fix_type, aligned_allocator<red_fix_type>> &source_hw_results) {
    float hw_sum_val = 0;
    float sw_sum_val = 0;
    float tot_hw = 0;
    float tot_sw = 0;  

    for (int i = 0; i < (DATA_SIZE * NUM_STEPS); i++) {
        
        float conv_hw_res = static_cast<float>(source_hw_results[i]);
        // Count annomaly numbers
        hw_sum_val += conv_hw_res;
        sw_sum_val += source_sw_results[i];

        if (i % NUM_STEPS == 0) {
            float temp_avg = hw_sum_val / NUM_STEPS;
            float temp_avg_sw = sw_sum_val / NUM_STEPS; 
            tot_hw += temp_avg;
            tot_sw += temp_avg_sw;
            hw_sum_val = 0;
            sw_sum_val = 0;
        }
     
    }
    float hw_avg_val = tot_hw / DATA_SIZE;
    float sw_avg_val = tot_sw / DATA_SIZE;
    float sum_err = abs(hw_avg_val - sw_avg_val) / sw_avg_val;
   
    std::cout << "Average Percent Error: " << sum_err
              << " Average Stock Value (HW): " << hw_avg_val
              << " Average Stock Value (SW): " << sw_avg_val 
              << std::endl;

}

// Monte Carlo Benchmark Function 

void mcaccel (
    const float& so,
    const float& r,
    const float& sig,
    const float& t,
    vector<red_fix_type, aligned_allocator<red_fix_type>>& source_in1, 
    vector<float, aligned_allocator<float>>& source_sw_results
) {

    float dt = t / static_cast<float>(NUM_STEPS);
    float drift = exp(dt*(r - 0.5*sig*sig));
    float vol = sqrt(sig*sig*dt);     
    float sw_results [NUM_STEPS][DATA_SIZE];
    int iter = 0;

    for (int i = 0; i < DATA_SIZE; i++) {
        for (int j = 0; j < NUM_STEPS; j++){

            float result = (j == 0) ? so : sw_results[j-1][i];
            red_fix_type x = source_in1[iter];
            float x1 = static_cast<float>(x);
            sw_results[j][i] = result * drift * exp(vol*x1);
            iter++;
        }
    }

    for (int j = 0, k = 0, itr = 0; itr < (DATA_SIZE * NUM_STEPS); j++, itr++){

        if (j == NUM_STEPS){
            j = 0;
            k++;
        }
        source_sw_results[itr] = sw_results[j][k];
    }
}


int main(int argc, char **argv) {

    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <XCLBIN File" << std::endl;
        return EXIT_FAILURE;
    }

    std::string binaryFile = argv[1];
    size_t vector_size_bytes = sizeof(red_fix_type) * DATA_SIZE * NUM_STEPS;
    size_t const_vector_size_bytes = sizeof(red_fix_type) * CONST_SIZE;


    cl_int err;
    cl::Context context;
    cl::Kernel kernel_monte_sim;
    cl::CommandQueue q;
    cl::Program program;

    std::vector<red_fix_type, aligned_allocator<red_fix_type>> source_in1(DATA_SIZE * NUM_STEPS);
    std::vector<red_fix_type, aligned_allocator<red_fix_type>> source_const(CONST_SIZE);
    std::vector<red_fix_type, aligned_allocator<red_fix_type>> source_hw_results(DATA_SIZE * NUM_STEPS, 0);    
    std::vector<float, aligned_allocator<float>> source_sw_results(DATA_SIZE * NUM_STEPS);

    // Create the test data
    std::generate(source_in1.begin(), source_in1.end(), gaussian_box_muller);

    float t;
    float so;
    float r;
    float sig;

    // TODO: User Input

    // test sample
    so = 50.0;
    r = 0.07;
    sig = 0.20;
    t = 0.5;

    // Constant vector assignment
    // Small enough for 
    source_const.at(0) = (float)(t); // time
    source_const.at(1) = (float)(so); // so
    source_const.at(2) = (float)(r); // r
    source_const.at(3) = (float)(sig); // sigma
    
    // generate sw_results
    mcaccel(so, r, sig, t, source_in1, source_sw_results);

    // -------------------------------------------------------------------------
    // OpenCL Host Area Start
    auto devices = xcl::get_xil_devices();
    auto fileBuf = xcl::read_binary_file(binaryFile);
    cl::Program::Binaries bins{{fileBuf.data(), fileBuf.size()}};
    int valid_device = 0;
    for (unsigned int i = 0; i < devices.size(); i++) {
        auto device = devices[i];
        // Create Context and Command Queue
        OCL_CHECK(err, context = cl::Context({device}, NULL, NULL, NULL, &err));
        OCL_CHECK(err, q = cl::CommandQueue(context, {device}, CL_QUEUE_PROFILING_ENABLE, &err));

        /* 
            FOR MULTIPLE KERNELS ON ONE DEVICE      
            OCL_CHECK(err, q = cl::CommandQueue(context, {device}, CL_QUEUE_OUT_OF_ORDER_EXEC_MODE_ENABLE, &err));
        */
        std::cout << "Trying to program device[" << i
                  << "]: " << device.getInfo<CL_DEVICE_NAME>() << std::endl;
        program = cl::Program(context, {device}, bins, NULL, &err);
        if (err != CL_SUCCESS) {
            std::cout << "Faied to program device [" << i
                      << "] with xclbin file!\n";
        } else {
            std::cout << "Device[" << i << "]: program successful!\n";
            valid_device++;
            break;
        }
    }
    if (valid_device == 0) {
        std::cout << "Failed to program any device found, exit!\n";
        exit(EXIT_FAILURE);
    }

    // Allocate Buffer in Global Memory
    // Buffers are allocated using CL_MEM_USE_HOST_PTR for efficient mem
    // and Device-to-host communication
    OCL_CHECK(err,
                cl::Buffer buffer_in1(context,
                                    CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY,
                                    vector_size_bytes,
                                    source_in1.data(),
                                    &err));

    OCL_CHECK(err,
                cl::Buffer buffer_in2(context,
                                    CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY,
                                    const_vector_size_bytes,
                                    source_const.data(),
                                    &err));

    OCL_CHECK(err,
                cl::Buffer buffer_output(context,
                                        CL_MEM_USE_HOST_PTR | CL_MEM_WRITE_ONLY,
                                        vector_size_bytes,
                                        source_hw_results.data(),
                                        &err));

    int size = DATA_SIZE * NUM_STEPS;
    int narg = 0;

    /* 
        FOR MULTIPLE KERNELS ON ONE DEVICE
        OCL_CHECK(err, kernel_monte_sim = cl::Kernel(program, "monte_sim:{monte_sim_1,monte_sim_2,monte_sim_3,monte_sim_4}", &err));
    */   
    OCL_CHECK(err, kernel_monte_sim = cl::Kernel(program, "monte_sim", &err));    
    OCL_CHECK(err, err = kernel_monte_sim.setArg(narg++, buffer_in1));
    OCL_CHECK(err, err = kernel_monte_sim.setArg(narg++, buffer_in2));
    OCL_CHECK(err, err = kernel_monte_sim.setArg(narg++, buffer_output));
    OCL_CHECK(err, err = kernel_monte_sim.setArg(narg++, size));

    // Copy input data to device global memory
    OCL_CHECK(err, err = q.enqueueMigrateMemObjects({buffer_in1, buffer_in2}, 0));
    int work_group = WORK_GROUP;
    cl::Event events[work_group];
    // cl::Event event;           // Multiple Kernels
    uint64_t duration;
    
    auto kernel_start = std::chrono::high_resolution_clock::now(); // CPU timing (not great measure)
    
    for (int i = 0; i < work_group; i++) {
        /*  FOR MULTIPLE KERNELS ON ONE DEVICE:
            OCL_CHECK(err, err = kernel_monte_sim.setArg(3, i));
            OCL_CHECK(err, err = kernel_monte_sim.setArg(4, work_group)); */
        OCL_CHECK(err, err = q.enqueueTask(kernel_monte_sim, NULL, &events[i]));

    }
    // OCL_CHECK(err, err = q.enqueueTask(kernel_monte_sim, NULL, &event));
    OCL_CHECK(err, err = q.enqueueMigrateMemObjects({buffer_output},
                                                    CL_MIGRATE_MEM_OBJECT_HOST));
    q.finish();
    auto kernel_end = std::chrono::high_resolution_clock::now();
    auto kernel_time = std::chrono::duration<uint64_t, std::nano>(kernel_end - kernel_start);
    duration =  kernel_time.count();

/*
    OCL_CHECK(err, err = event.getProfilingInfo<uint64_t>(CL_PROFILING_COMMAND_START, &nstimestart));
    OCL_CHECK(err, err = event.getProfilingInfo<uint64_t>(CL_PROFILING_COMMAND_END, &nstimeend));
    auto monte_sim_time = nstimeend - nstimestart;
*/
    verify(source_sw_results, source_hw_results);
    acc_measure(source_sw_results, source_hw_results);

    

    printf("|-------------------------+-------------------------|\n"
           "| Kernel                  |    Wall-Clock Time (ns) |\n"
           "|-------------------------+-------------------------|\n");

    printf("| %-23s | %23lu |\n", "monte_sim: ", duration);
    printf("|-------------------------+-------------------------|\n");
    //OpenCL Host Code Area End

    return EXIT_SUCCESS;
    
    // TODO: Clean up memory


}