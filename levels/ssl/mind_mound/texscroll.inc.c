void scroll_sts_mat_mind_mound_PalaceFloor_layer1() {
	Gfx *mat = segmented_to_virtual(mat_mind_mound_PalaceFloor_layer1);
	shift_s_down(mat, 10, PACK_TILESIZE(0, 1));
};

void scroll_ssl_level_geo_mind_mound() {
	scroll_sts_mat_mind_mound_PalaceFloor_layer1();
}
