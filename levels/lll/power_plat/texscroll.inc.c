void scroll_sts_mat_power_plat_PowerPlat_layer1() {
	Gfx *mat = segmented_to_virtual(mat_power_plat_PowerPlat_layer1);
	shift_s_down(mat, 13, PACK_TILESIZE(0, 2));
};

void scroll_lll_level_geo_power_plat() {
	scroll_sts_mat_power_plat_PowerPlat_layer1();
}
