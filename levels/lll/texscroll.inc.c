void scroll_sts_mat_lll_dl_CorridorWall_layer1() {
	static int intervalTex1 = 2;
	static int curInterval1 = 2;
	Gfx *mat = segmented_to_virtual(mat_lll_dl_CorridorWall_layer1);

	if (--curInterval1 <= 0) {
		shift_s(mat, 21, PACK_TILESIZE(0, 1));
		curInterval1 = intervalTex1;
	}
};

void scroll_lll() {
	scroll_sts_mat_lll_dl_CorridorWall_layer1();
}
