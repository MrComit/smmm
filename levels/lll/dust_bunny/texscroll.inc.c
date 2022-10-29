void scroll_sts_mat_dust_bunny_Mips_layer5() {
	Gfx *mat = segmented_to_virtual(mat_dust_bunny_Mips_layer5);
	shift_s(mat, 20, PACK_TILESIZE(0, 1));
};

void scroll_lll_level_geo_dust_bunny() {
	scroll_sts_mat_dust_bunny_Mips_layer5();
}
