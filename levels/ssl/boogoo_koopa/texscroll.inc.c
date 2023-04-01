void scroll_sts_mat_boogoo_koopa_BooGooObj_layer1() {
	Gfx *mat = segmented_to_virtual(mat_boogoo_koopa_BooGooObj_layer1);
	shift_s(mat, 13, PACK_TILESIZE(0, 1));
	shift_s(mat, 21, PACK_TILESIZE(0, 1));
	shift_t(mat, 21, PACK_TILESIZE(0, 1));
};

void scroll_ssl_level_geo_boogoo_koopa() {
	scroll_sts_mat_boogoo_koopa_BooGooObj_layer1();
}
