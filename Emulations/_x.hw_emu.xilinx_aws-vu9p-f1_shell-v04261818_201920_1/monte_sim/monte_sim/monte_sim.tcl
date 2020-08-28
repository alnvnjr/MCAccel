catch {::common::set_param -quiet hls.xocc.mode csynth};
# 
# Hls run script generated by the compiler
# 

set vpp_optimize_level 0
open_project monte_sim
set_top monte_sim
add_files "/home/centos/src/project_data/aws-fpga/Vitis/examples/xilinx_2019.2/cpp_kernels/monte_sim/src/monte_sim.cpp" -cflags " -g -I /home/centos/src/project_data/aws-fpga/Vitis/examples/xilinx_2019.2/cpp_kernels/monte_sim/src "
open_solution solution
set_part xcvu9p-flgb2104-2-i
create_clock -period 250.000000MHz -name default
config_sdx -target xocc
config_rtl -kernel_profile
config_export -vivado_optimization_level $vpp_optimize_level
config_dataflow -strict_mode warning
config_debug -enable
set_clock_uncertainty 27.000000%
config_rtl -enable_maxiConservative=1
config_interface -m_axi_addr64
config_export -format ip_catalog -ipname monte_sim
csynth_design
export_design
close_project
puts "HLS completed successfully"
exit