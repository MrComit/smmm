void scroll_sts_mat_wdw_dl_BooGoo_001_layer1() {
	Gfx *mat = segmented_to_virtual(mat_wdw_dl_BooGoo_001_layer1);
	shift_s(mat, 10, PACK_TILESIZE(0, 1));
	shift_s(mat, 15, PACK_TILESIZE(0, 1));
	shift_t(mat, 15, PACK_TILESIZE(0, 1));
};

void scroll_sts_mat_wdw_dl_BooGoo_002_layer1() {
	Gfx *mat = segmented_to_virtual(mat_wdw_dl_BooGoo_002_layer1);
	shift_s(mat, 10, PACK_TILESIZE(0, 1));
	shift_s(mat, 15, PACK_TILESIZE(0, 1));
	shift_t(mat, 15, PACK_TILESIZE(0, 1));
};

void scroll_sts_mat_wdw_dl_Vase_v4_003_layer1() {
	Gfx *mat = segmented_to_virtual(mat_wdw_dl_Vase_v4_003_layer1);
	shift_s(mat, 10, PACK_TILESIZE(0, 4));
};

void scroll_wdw() {
	scroll_sts_mat_wdw_dl_BooGoo_001_layer1();
	scroll_sts_mat_wdw_dl_BooGoo_002_layer1();
	scroll_sts_mat_wdw_dl_Vase_v4_003_layer1();
}
