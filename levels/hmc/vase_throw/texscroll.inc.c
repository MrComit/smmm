void scroll_sts_mat_vase_throw_Vase_v4_layer1() {
	Gfx *mat = segmented_to_virtual(mat_vase_throw_Vase_v4_layer1);
	shift_s(mat, 13, PACK_TILESIZE(0, 4));
};

void scroll_hmc_level_geo_vase_throw() {
	scroll_sts_mat_vase_throw_Vase_v4_layer1();
}
