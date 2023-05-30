void scroll_sts_mat_controller_BooGoo_layer5() {
	Gfx *mat = segmented_to_virtual(mat_controller_BooGoo_layer5);
	shift_s(mat, 10, PACK_TILESIZE(0, 1));
	shift_s(mat, 15, PACK_TILESIZE(0, 1));
	shift_t(mat, 15, PACK_TILESIZE(0, 1));
};

void scroll_ddd_level_geo_controller() {
	scroll_sts_mat_controller_BooGoo_layer5();
}
