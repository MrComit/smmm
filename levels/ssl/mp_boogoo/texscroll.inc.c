void scroll_sts_mat_mp_boogoo_BooGooObject_layer1() {
	Gfx *mat = segmented_to_virtual(mat_mp_boogoo_BooGooObject_layer1);
	shift_s(mat, 10, PACK_TILESIZE(0, 1));
	shift_s(mat, 15, PACK_TILESIZE(0, 1));
	shift_t(mat, 15, PACK_TILESIZE(0, 1));
};

void scroll_ssl_level_geo_mp_boogoo() {
	scroll_sts_mat_mp_boogoo_BooGooObject_layer1();
}
