void scroll_sts_mat_thi_dl_BooSand_layer1() {
	Gfx *mat = segmented_to_virtual(mat_thi_dl_BooSand_layer1);
	shift_s(mat, 10, PACK_TILESIZE(0, 1));
	shift_t(mat, 15, PACK_TILESIZE(0, 1));
};

void scroll_sts_mat_thi_dl_BooSand_001_layer1() {
	Gfx *mat = segmented_to_virtual(mat_thi_dl_BooSand_001_layer1);
	shift_s(mat, 10, PACK_TILESIZE(0, 1));
	shift_t(mat, 15, PACK_TILESIZE(0, 1));
};

void scroll_thi() {
	scroll_sts_mat_thi_dl_BooSand_layer1();
	scroll_sts_mat_thi_dl_BooSand_001_layer1();
}
