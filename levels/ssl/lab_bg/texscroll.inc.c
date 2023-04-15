void scroll_sts_mat_lab_bg_BooGooObject_layer1() {
	Gfx *mat = segmented_to_virtual(mat_lab_bg_BooGooObject_layer1);
	shift_s(mat, 13, PACK_TILESIZE(0, 1));
	shift_s(mat, 21, PACK_TILESIZE(0, 1));
	shift_t(mat, 21, PACK_TILESIZE(0, 1));
};

void scroll_ssl_level_geo_lab_bg() {
	scroll_sts_mat_lab_bg_BooGooObject_layer1();
}
