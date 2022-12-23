void scroll_sts_mat_power_bar_PowerBar() {
	Gfx *mat = segmented_to_virtual(mat_power_bar_PowerBar);
	shift_s_down(mat, -1, PACK_TILESIZE(0, 2));
};

void scroll_lll_level_geo_power_bar() {
	scroll_sts_mat_power_bar_PowerBar();
}
