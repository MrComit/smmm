void scroll_sts_mat_end_shyguy_BooGooObj_layer1() {
	Gfx *mat = segmented_to_virtual(mat_end_shyguy_BooGooObj_layer1);
	shift_s(mat, 10, PACK_TILESIZE(0, 1));
	shift_s(mat, 15, PACK_TILESIZE(0, 1));
	shift_t(mat, 15, PACK_TILESIZE(0, 1));
};

void scroll_ddd_level_geo_end_shyguy() {
	scroll_sts_mat_end_shyguy_BooGooObj_layer1();
}
