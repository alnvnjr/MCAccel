// 67d7842dbbe25473c3c32b93c0da8047785f30d78e8a024de1b57352245f9689

#ifndef XTLM_SIMPLE_INTERCONNECT_H_
#define XTLM_SIMPLE_INTERCONNECT_H_

#include "xtlm.h"
class xtlm_simple_interconnect_model;
class xtlm_simple_interconnect: public sc_core::sc_module {
public:
	xtlm_simple_interconnect(sc_module_name name, xsc::common_cpp::properties& properties);
	virtual ~xtlm_simple_interconnect();
	//Socket_declaration
		xtlm::xtlm_aximm_initiator_socket* initiator_0_rd_socket;
		xtlm::xtlm_aximm_initiator_socket* initiator_0_wr_socket;
		xtlm::xtlm_aximm_initiator_socket* initiator_1_rd_socket;
		xtlm::xtlm_aximm_initiator_socket* initiator_1_wr_socket;
		xtlm::xtlm_aximm_initiator_socket* initiator_2_rd_socket;
		xtlm::xtlm_aximm_initiator_socket* initiator_2_wr_socket;
		xtlm::xtlm_aximm_initiator_socket* initiator_3_rd_socket;
		xtlm::xtlm_aximm_initiator_socket* initiator_3_wr_socket;
		xtlm::xtlm_aximm_initiator_socket* initiator_4_rd_socket;
		xtlm::xtlm_aximm_initiator_socket* initiator_4_wr_socket;
		xtlm::xtlm_aximm_initiator_socket* initiator_5_rd_socket;
		xtlm::xtlm_aximm_initiator_socket* initiator_5_wr_socket;
		xtlm::xtlm_aximm_initiator_socket* initiator_6_rd_socket;
		xtlm::xtlm_aximm_initiator_socket* initiator_6_wr_socket;
		xtlm::xtlm_aximm_initiator_socket* initiator_7_rd_socket;
		xtlm::xtlm_aximm_initiator_socket* initiator_7_wr_socket;
		xtlm::xtlm_aximm_initiator_socket* initiator_8_rd_socket;
		xtlm::xtlm_aximm_initiator_socket* initiator_8_wr_socket;
		xtlm::xtlm_aximm_initiator_socket* initiator_9_rd_socket;
		xtlm::xtlm_aximm_initiator_socket* initiator_9_wr_socket;
		xtlm::xtlm_aximm_initiator_socket* initiator_10_rd_socket;
		xtlm::xtlm_aximm_initiator_socket* initiator_10_wr_socket;
		xtlm::xtlm_aximm_initiator_socket* initiator_11_rd_socket;
		xtlm::xtlm_aximm_initiator_socket* initiator_11_wr_socket;
		xtlm::xtlm_aximm_initiator_socket* initiator_12_rd_socket;
		xtlm::xtlm_aximm_initiator_socket* initiator_12_wr_socket;
		xtlm::xtlm_aximm_initiator_socket* initiator_13_rd_socket;
		xtlm::xtlm_aximm_initiator_socket* initiator_13_wr_socket;
		xtlm::xtlm_aximm_initiator_socket* initiator_14_rd_socket;
		xtlm::xtlm_aximm_initiator_socket* initiator_14_wr_socket;
		xtlm::xtlm_aximm_initiator_socket* initiator_15_rd_socket;
		xtlm::xtlm_aximm_initiator_socket* initiator_15_wr_socket;
		xtlm::xtlm_aximm_initiator_socket* initiator_16_rd_socket;
		xtlm::xtlm_aximm_initiator_socket* initiator_16_wr_socket;
		xtlm::xtlm_aximm_initiator_socket* initiator_17_rd_socket;
		xtlm::xtlm_aximm_initiator_socket* initiator_17_wr_socket;
		xtlm::xtlm_aximm_initiator_socket* initiator_18_rd_socket;
		xtlm::xtlm_aximm_initiator_socket* initiator_18_wr_socket;
		xtlm::xtlm_aximm_initiator_socket* initiator_19_rd_socket;
		xtlm::xtlm_aximm_initiator_socket* initiator_19_wr_socket;
		xtlm::xtlm_aximm_initiator_socket* initiator_20_rd_socket;
		xtlm::xtlm_aximm_initiator_socket* initiator_20_wr_socket;
		xtlm::xtlm_aximm_initiator_socket* initiator_21_rd_socket;
		xtlm::xtlm_aximm_initiator_socket* initiator_21_wr_socket;
		xtlm::xtlm_aximm_initiator_socket* initiator_22_rd_socket;
		xtlm::xtlm_aximm_initiator_socket* initiator_22_wr_socket;
		xtlm::xtlm_aximm_initiator_socket* initiator_23_rd_socket;
		xtlm::xtlm_aximm_initiator_socket* initiator_23_wr_socket;
		xtlm::xtlm_aximm_initiator_socket* initiator_24_rd_socket;
		xtlm::xtlm_aximm_initiator_socket* initiator_24_wr_socket;
		xtlm::xtlm_aximm_initiator_socket* initiator_25_rd_socket;
		xtlm::xtlm_aximm_initiator_socket* initiator_25_wr_socket;
		xtlm::xtlm_aximm_initiator_socket* initiator_26_rd_socket;
		xtlm::xtlm_aximm_initiator_socket* initiator_26_wr_socket;
		xtlm::xtlm_aximm_initiator_socket* initiator_27_rd_socket;
		xtlm::xtlm_aximm_initiator_socket* initiator_27_wr_socket;
		xtlm::xtlm_aximm_initiator_socket* initiator_28_rd_socket;
		xtlm::xtlm_aximm_initiator_socket* initiator_28_wr_socket;
		xtlm::xtlm_aximm_initiator_socket* initiator_29_rd_socket;
		xtlm::xtlm_aximm_initiator_socket* initiator_29_wr_socket;
		xtlm::xtlm_aximm_initiator_socket* initiator_30_rd_socket;
		xtlm::xtlm_aximm_initiator_socket* initiator_30_wr_socket;
		xtlm::xtlm_aximm_initiator_socket* initiator_31_rd_socket;
		xtlm::xtlm_aximm_initiator_socket* initiator_31_wr_socket;

		xtlm::xtlm_aximm_target_socket* target_0_rd_socket;
		xtlm::xtlm_aximm_target_socket* target_0_wr_socket;
		xtlm::xtlm_aximm_target_socket* target_1_rd_socket;
		xtlm::xtlm_aximm_target_socket* target_1_wr_socket;
		xtlm::xtlm_aximm_target_socket* target_2_rd_socket;
		xtlm::xtlm_aximm_target_socket* target_2_wr_socket;
		xtlm::xtlm_aximm_target_socket* target_3_rd_socket;
		xtlm::xtlm_aximm_target_socket* target_3_wr_socket;
		xtlm::xtlm_aximm_target_socket* target_4_rd_socket;
		xtlm::xtlm_aximm_target_socket* target_4_wr_socket;
		xtlm::xtlm_aximm_target_socket* target_5_rd_socket;
		xtlm::xtlm_aximm_target_socket* target_5_wr_socket;
		xtlm::xtlm_aximm_target_socket* target_6_rd_socket;
		xtlm::xtlm_aximm_target_socket* target_6_wr_socket;
		xtlm::xtlm_aximm_target_socket* target_7_rd_socket;
		xtlm::xtlm_aximm_target_socket* target_7_wr_socket;
		xtlm::xtlm_aximm_target_socket* target_8_rd_socket;
		xtlm::xtlm_aximm_target_socket* target_8_wr_socket;
		xtlm::xtlm_aximm_target_socket* target_9_rd_socket;
		xtlm::xtlm_aximm_target_socket* target_9_wr_socket;
		xtlm::xtlm_aximm_target_socket* target_10_rd_socket;
		xtlm::xtlm_aximm_target_socket* target_10_wr_socket;
		xtlm::xtlm_aximm_target_socket* target_11_rd_socket;
		xtlm::xtlm_aximm_target_socket* target_11_wr_socket;
		xtlm::xtlm_aximm_target_socket* target_12_rd_socket;
		xtlm::xtlm_aximm_target_socket* target_12_wr_socket;
		xtlm::xtlm_aximm_target_socket* target_13_rd_socket;
		xtlm::xtlm_aximm_target_socket* target_13_wr_socket;
		xtlm::xtlm_aximm_target_socket* target_14_rd_socket;
		xtlm::xtlm_aximm_target_socket* target_14_wr_socket;
		xtlm::xtlm_aximm_target_socket* target_15_rd_socket;
		xtlm::xtlm_aximm_target_socket* target_15_wr_socket;
		xtlm::xtlm_aximm_target_socket* target_16_rd_socket;
		xtlm::xtlm_aximm_target_socket* target_16_wr_socket;
		xtlm::xtlm_aximm_target_socket* target_17_rd_socket;
		xtlm::xtlm_aximm_target_socket* target_17_wr_socket;
		xtlm::xtlm_aximm_target_socket* target_18_rd_socket;
		xtlm::xtlm_aximm_target_socket* target_18_wr_socket;
		xtlm::xtlm_aximm_target_socket* target_19_rd_socket;
		xtlm::xtlm_aximm_target_socket* target_19_wr_socket;
		xtlm::xtlm_aximm_target_socket* target_20_rd_socket;
		xtlm::xtlm_aximm_target_socket* target_20_wr_socket;
		xtlm::xtlm_aximm_target_socket* target_21_rd_socket;
		xtlm::xtlm_aximm_target_socket* target_21_wr_socket;
		xtlm::xtlm_aximm_target_socket* target_22_rd_socket;
		xtlm::xtlm_aximm_target_socket* target_22_wr_socket;
		xtlm::xtlm_aximm_target_socket* target_23_rd_socket;
		xtlm::xtlm_aximm_target_socket* target_23_wr_socket;
		xtlm::xtlm_aximm_target_socket* target_24_rd_socket;
		xtlm::xtlm_aximm_target_socket* target_24_wr_socket;
		xtlm::xtlm_aximm_target_socket* target_25_rd_socket;
		xtlm::xtlm_aximm_target_socket* target_25_wr_socket;
		xtlm::xtlm_aximm_target_socket* target_26_rd_socket;
		xtlm::xtlm_aximm_target_socket* target_26_wr_socket;
		xtlm::xtlm_aximm_target_socket* target_27_rd_socket;
		xtlm::xtlm_aximm_target_socket* target_27_wr_socket;
		xtlm::xtlm_aximm_target_socket* target_28_rd_socket;
		xtlm::xtlm_aximm_target_socket* target_28_wr_socket;
		xtlm::xtlm_aximm_target_socket* target_29_rd_socket;
		xtlm::xtlm_aximm_target_socket* target_29_wr_socket;
		xtlm::xtlm_aximm_target_socket* target_30_rd_socket;
		xtlm::xtlm_aximm_target_socket* target_30_wr_socket;
		xtlm::xtlm_aximm_target_socket* target_31_rd_socket;
		xtlm::xtlm_aximm_target_socket* target_31_wr_socket;

		sc_in<bool> m00_axi_aclk;
		sc_in<bool> m00_axi_aresetn;
		sc_in<bool> m01_axi_aclk;
		sc_in<bool> m01_axi_aresetn;
		sc_in<bool> m02_axi_aclk;
		sc_in<bool> m02_axi_aresetn;
		sc_in<bool> m03_axi_aclk;
		sc_in<bool> m03_axi_aresetn;
		sc_in<bool> m04_axi_aclk;
		sc_in<bool> m04_axi_aresetn;
		sc_in<bool> m05_axi_aclk;
		sc_in<bool> m05_axi_aresetn;
		sc_in<bool> m06_axi_aclk;
		sc_in<bool> m06_axi_aresetn;
		sc_in<bool> m07_axi_aclk;
		sc_in<bool> m07_axi_aresetn;
		sc_in<bool> m08_axi_aclk;
		sc_in<bool> m08_axi_aresetn;
		sc_in<bool> m09_axi_aclk;
		sc_in<bool> m09_axi_aresetn;
		sc_in<bool> m10_axi_aclk;
		sc_in<bool> m10_axi_aresetn;
		sc_in<bool> m11_axi_aclk;
		sc_in<bool> m11_axi_aresetn;
		sc_in<bool> m12_axi_aclk;
		sc_in<bool> m12_axi_aresetn;
		sc_in<bool> m13_axi_aclk;
		sc_in<bool> m13_axi_aresetn;
		sc_in<bool> m14_axi_aclk;
		sc_in<bool> m14_axi_aresetn;
		sc_in<bool> m15_axi_aclk;
		sc_in<bool> m15_axi_aresetn;
		sc_in<bool> m16_axi_aclk;
		sc_in<bool> m16_axi_aresetn;
		sc_in<bool> m17_axi_aclk;
		sc_in<bool> m17_axi_aresetn;
		sc_in<bool> m18_axi_aclk;
		sc_in<bool> m18_axi_aresetn;
		sc_in<bool> m19_axi_aclk;
		sc_in<bool> m19_axi_aresetn;
		sc_in<bool> m20_axi_aclk;
		sc_in<bool> m20_axi_aresetn;
		sc_in<bool> m21_axi_aclk;
		sc_in<bool> m21_axi_aresetn;
		sc_in<bool> m22_axi_aclk;
		sc_in<bool> m22_axi_aresetn;
		sc_in<bool> m23_axi_aclk;
		sc_in<bool> m23_axi_aresetn;
		sc_in<bool> m24_axi_aclk;
		sc_in<bool> m24_axi_aresetn;
		sc_in<bool> m25_axi_aclk;
		sc_in<bool> m25_axi_aresetn;
		sc_in<bool> m26_axi_aclk;
		sc_in<bool> m26_axi_aresetn;
		sc_in<bool> m27_axi_aclk;
		sc_in<bool> m27_axi_aresetn;
		sc_in<bool> m28_axi_aclk;
		sc_in<bool> m28_axi_aresetn;
		sc_in<bool> m29_axi_aclk;
		sc_in<bool> m29_axi_aresetn;
		sc_in<bool> m30_axi_aclk;
		sc_in<bool> m30_axi_aresetn;
		sc_in<bool> m31_axi_aclk;
		sc_in<bool> m31_axi_aresetn;

		sc_in<bool> s00_axi_aclk;
		sc_in<bool> s00_axi_aresetn;
		sc_in<bool> s01_axi_aclk;
		sc_in<bool> s01_axi_aresetn;
		sc_in<bool> s02_axi_aclk;
		sc_in<bool> s02_axi_aresetn;
		sc_in<bool> s03_axi_aclk;
		sc_in<bool> s03_axi_aresetn;
		sc_in<bool> s04_axi_aclk;
		sc_in<bool> s04_axi_aresetn;
		sc_in<bool> s05_axi_aclk;
		sc_in<bool> s05_axi_aresetn;
		sc_in<bool> s06_axi_aclk;
		sc_in<bool> s06_axi_aresetn;
		sc_in<bool> s07_axi_aclk;
		sc_in<bool> s07_axi_aresetn;
		sc_in<bool> s08_axi_aclk;
		sc_in<bool> s08_axi_aresetn;
		sc_in<bool> s09_axi_aclk;
		sc_in<bool> s09_axi_aresetn;
		sc_in<bool> s10_axi_aclk;
		sc_in<bool> s10_axi_aresetn;
		sc_in<bool> s11_axi_aclk;
		sc_in<bool> s11_axi_aresetn;
		sc_in<bool> s12_axi_aclk;
		sc_in<bool> s12_axi_aresetn;
		sc_in<bool> s13_axi_aclk;
		sc_in<bool> s13_axi_aresetn;
		sc_in<bool> s14_axi_aclk;
		sc_in<bool> s14_axi_aresetn;
		sc_in<bool> s15_axi_aclk;
		sc_in<bool> s15_axi_aresetn;
		sc_in<bool> s16_axi_aclk;
		sc_in<bool> s16_axi_aresetn;
		sc_in<bool> s17_axi_aclk;
		sc_in<bool> s17_axi_aresetn;
		sc_in<bool> s18_axi_aclk;
		sc_in<bool> s18_axi_aresetn;
		sc_in<bool> s19_axi_aclk;
		sc_in<bool> s19_axi_aresetn;
		sc_in<bool> s20_axi_aclk;
		sc_in<bool> s20_axi_aresetn;
		sc_in<bool> s21_axi_aclk;
		sc_in<bool> s21_axi_aresetn;
		sc_in<bool> s22_axi_aclk;
		sc_in<bool> s22_axi_aresetn;
		sc_in<bool> s23_axi_aclk;
		sc_in<bool> s23_axi_aresetn;
		sc_in<bool> s24_axi_aclk;
		sc_in<bool> s24_axi_aresetn;
		sc_in<bool> s25_axi_aclk;
		sc_in<bool> s25_axi_aresetn;
		sc_in<bool> s26_axi_aclk;
		sc_in<bool> s26_axi_aresetn;
		sc_in<bool> s27_axi_aclk;
		sc_in<bool> s27_axi_aresetn;
		sc_in<bool> s28_axi_aclk;
		sc_in<bool> s28_axi_aresetn;
		sc_in<bool> s29_axi_aclk;
		sc_in<bool> s29_axi_aresetn;
		sc_in<bool> s30_axi_aclk;
		sc_in<bool> s30_axi_aresetn;
		sc_in<bool> s31_axi_aclk;
		sc_in<bool> s31_axi_aresetn;
private :
		sc_signal<bool> m00_axi_aclk_sig;
		sc_signal<bool> m00_axi_aresetn_sig;
		sc_signal<bool> m01_axi_aclk_sig;
		sc_signal<bool> m01_axi_aresetn_sig;
		sc_signal<bool> m02_axi_aclk_sig;
		sc_signal<bool> m02_axi_aresetn_sig;
		sc_signal<bool> m03_axi_aclk_sig;
		sc_signal<bool> m03_axi_aresetn_sig;
		sc_signal<bool> m04_axi_aclk_sig;
		sc_signal<bool> m04_axi_aresetn_sig;
		sc_signal<bool> m05_axi_aclk_sig;
		sc_signal<bool> m05_axi_aresetn_sig;
		sc_signal<bool> m06_axi_aclk_sig;
		sc_signal<bool> m06_axi_aresetn_sig;
		sc_signal<bool> m07_axi_aclk_sig;
		sc_signal<bool> m07_axi_aresetn_sig;
		sc_signal<bool> m08_axi_aclk_sig;
		sc_signal<bool> m08_axi_aresetn_sig;
		sc_signal<bool> m09_axi_aclk_sig;
		sc_signal<bool> m09_axi_aresetn_sig;
		sc_signal<bool> m10_axi_aclk_sig;
		sc_signal<bool> m10_axi_aresetn_sig;
		sc_signal<bool> m11_axi_aclk_sig;
		sc_signal<bool> m11_axi_aresetn_sig;
		sc_signal<bool> m12_axi_aclk_sig;
		sc_signal<bool> m12_axi_aresetn_sig;
		sc_signal<bool> m13_axi_aclk_sig;
		sc_signal<bool> m13_axi_aresetn_sig;
		sc_signal<bool> m14_axi_aclk_sig;
		sc_signal<bool> m14_axi_aresetn_sig;
		sc_signal<bool> m15_axi_aclk_sig;
		sc_signal<bool> m15_axi_aresetn_sig;
		sc_signal<bool> m16_axi_aclk_sig;
		sc_signal<bool> m16_axi_aresetn_sig;
		sc_signal<bool> m17_axi_aclk_sig;
		sc_signal<bool> m17_axi_aresetn_sig;
		sc_signal<bool> m18_axi_aclk_sig;
		sc_signal<bool> m18_axi_aresetn_sig;
		sc_signal<bool> m19_axi_aclk_sig;
		sc_signal<bool> m19_axi_aresetn_sig;
		sc_signal<bool> m20_axi_aclk_sig;
		sc_signal<bool> m20_axi_aresetn_sig;
		sc_signal<bool> m21_axi_aclk_sig;
		sc_signal<bool> m21_axi_aresetn_sig;
		sc_signal<bool> m22_axi_aclk_sig;
		sc_signal<bool> m22_axi_aresetn_sig;
		sc_signal<bool> m23_axi_aclk_sig;
		sc_signal<bool> m23_axi_aresetn_sig;
		sc_signal<bool> m24_axi_aclk_sig;
		sc_signal<bool> m24_axi_aresetn_sig;
		sc_signal<bool> m25_axi_aclk_sig;
		sc_signal<bool> m25_axi_aresetn_sig;
		sc_signal<bool> m26_axi_aclk_sig;
		sc_signal<bool> m26_axi_aresetn_sig;
		sc_signal<bool> m27_axi_aclk_sig;
		sc_signal<bool> m27_axi_aresetn_sig;
		sc_signal<bool> m28_axi_aclk_sig;
		sc_signal<bool> m28_axi_aresetn_sig;
		sc_signal<bool> m29_axi_aclk_sig;
		sc_signal<bool> m29_axi_aresetn_sig;
		sc_signal<bool> m30_axi_aclk_sig;
		sc_signal<bool> m30_axi_aresetn_sig;
		sc_signal<bool> m31_axi_aclk_sig;
		sc_signal<bool> m31_axi_aresetn_sig;

		sc_signal<bool> s00_axi_aclk_sig;
		sc_signal<bool> s00_axi_aresetn_sig;
		sc_signal<bool> s01_axi_aclk_sig;
		sc_signal<bool> s01_axi_aresetn_sig;
		sc_signal<bool> s02_axi_aclk_sig;
		sc_signal<bool> s02_axi_aresetn_sig;
		sc_signal<bool> s03_axi_aclk_sig;
		sc_signal<bool> s03_axi_aresetn_sig;
		sc_signal<bool> s04_axi_aclk_sig;
		sc_signal<bool> s04_axi_aresetn_sig;
		sc_signal<bool> s05_axi_aclk_sig;
		sc_signal<bool> s05_axi_aresetn_sig;
		sc_signal<bool> s06_axi_aclk_sig;
		sc_signal<bool> s06_axi_aresetn_sig;
		sc_signal<bool> s07_axi_aclk_sig;
		sc_signal<bool> s07_axi_aresetn_sig;
		sc_signal<bool> s08_axi_aclk_sig;
		sc_signal<bool> s08_axi_aresetn_sig;
		sc_signal<bool> s09_axi_aclk_sig;
		sc_signal<bool> s09_axi_aresetn_sig;
		sc_signal<bool> s10_axi_aclk_sig;
		sc_signal<bool> s10_axi_aresetn_sig;
		sc_signal<bool> s11_axi_aclk_sig;
		sc_signal<bool> s11_axi_aresetn_sig;
		sc_signal<bool> s12_axi_aclk_sig;
		sc_signal<bool> s12_axi_aresetn_sig;
		sc_signal<bool> s13_axi_aclk_sig;
		sc_signal<bool> s13_axi_aresetn_sig;
		sc_signal<bool> s14_axi_aclk_sig;
		sc_signal<bool> s14_axi_aresetn_sig;
		sc_signal<bool> s15_axi_aclk_sig;
		sc_signal<bool> s15_axi_aresetn_sig;
		sc_signal<bool> s16_axi_aclk_sig;
		sc_signal<bool> s16_axi_aresetn_sig;
		sc_signal<bool> s17_axi_aclk_sig;
		sc_signal<bool> s17_axi_aresetn_sig;
		sc_signal<bool> s18_axi_aclk_sig;
		sc_signal<bool> s18_axi_aresetn_sig;
		sc_signal<bool> s19_axi_aclk_sig;
		sc_signal<bool> s19_axi_aresetn_sig;
		sc_signal<bool> s20_axi_aclk_sig;
		sc_signal<bool> s20_axi_aresetn_sig;
		sc_signal<bool> s21_axi_aclk_sig;
		sc_signal<bool> s21_axi_aresetn_sig;
		sc_signal<bool> s22_axi_aclk_sig;
		sc_signal<bool> s22_axi_aresetn_sig;
		sc_signal<bool> s23_axi_aclk_sig;
		sc_signal<bool> s23_axi_aresetn_sig;
		sc_signal<bool> s24_axi_aclk_sig;
		sc_signal<bool> s24_axi_aresetn_sig;
		sc_signal<bool> s25_axi_aclk_sig;
		sc_signal<bool> s25_axi_aresetn_sig;
		sc_signal<bool> s26_axi_aclk_sig;
		sc_signal<bool> s26_axi_aresetn_sig;
		sc_signal<bool> s27_axi_aclk_sig;
		sc_signal<bool> s27_axi_aresetn_sig;
		sc_signal<bool> s28_axi_aclk_sig;
		sc_signal<bool> s28_axi_aresetn_sig;
		sc_signal<bool> s29_axi_aclk_sig;
		sc_signal<bool> s29_axi_aresetn_sig;
		sc_signal<bool> s30_axi_aclk_sig;
		sc_signal<bool> s30_axi_aresetn_sig;
		sc_signal<bool> s31_axi_aclk_sig;
		sc_signal<bool> s31_axi_aresetn_sig;
		xtlm_simple_interconnect_model* m_model;
};

#endif /* XTLM_SIMPLE_INTERCONNECT_H_ */
