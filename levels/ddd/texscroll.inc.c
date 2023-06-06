void scroll_sts_mat_ddd_dl_BooGooObjWall_layer1() {
	Gfx *mat = segmented_to_virtual(mat_ddd_dl_BooGooObjWall_layer1);
	shift_s(mat, 10, PACK_TILESIZE(0, 1));
	shift_s(mat, 15, PACK_TILESIZE(0, 1));
	shift_t(mat, 15, PACK_TILESIZE(0, 1));
};

void scroll_sts_mat_ddd_dl_BooGooDropperPillars_layer1() {
	Gfx *mat = segmented_to_virtual(mat_ddd_dl_BooGooDropperPillars_layer1);
	shift_s(mat, 10, PACK_TILESIZE(0, 1));
	shift_s(mat, 15, PACK_TILESIZE(0, 1));
	shift_t(mat, 15, PACK_TILESIZE(0, 1));
};

void scroll_sts_mat_ddd_dl_BooGooObjWall_001_layer1() {
	Gfx *mat = segmented_to_virtual(mat_ddd_dl_BooGooObjWall_001_layer1);
	shift_s(mat, 10, PACK_TILESIZE(0, 1));
	shift_s(mat, 15, PACK_TILESIZE(0, 1));
	shift_t(mat, 15, PACK_TILESIZE(0, 1));
};

void scroll_sts_mat_ddd_dl_RedMist_layer4() {
	Gfx *mat = segmented_to_virtual(mat_ddd_dl_RedMist_layer4);
	shift_t(mat, 16, PACK_TILESIZE(0, 2));
};

void scroll_ddd() {
	scroll_sts_mat_ddd_dl_BooGooObjWall_layer1();
	scroll_sts_mat_ddd_dl_BooGooDropperPillars_layer1();
	scroll_sts_mat_ddd_dl_BooGooObjWall_001_layer1();
	scroll_sts_mat_ddd_dl_RedMist_layer4();
}
