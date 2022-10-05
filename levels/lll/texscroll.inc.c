void scroll_sts_mat_lll_dl_CorridorWall_layer1() {
	Gfx *mat = segmented_to_virtual(mat_lll_dl_CorridorWall_layer1);
	shift_s(mat, 21, PACK_TILESIZE(0, 1));
};

void scroll_lll() {
	scroll_sts_mat_lll_dl_CorridorWall_layer1();
}
