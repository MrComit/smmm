void scroll_sts_mat_opening_wall_WallOpacity_layer5() {
	static int intervalTex1 = 2;
	static int curInterval1 = 2;
	Gfx *mat = segmented_to_virtual(mat_opening_wall_WallOpacity_layer5);

	if (--curInterval1 <= 0) {
		shift_s(mat, 21, PACK_TILESIZE(0, 1));
		curInterval1 = intervalTex1;
	}
};

void scroll_hmc_level_geo_opening_wall() {
	scroll_sts_mat_opening_wall_WallOpacity_layer5();
}
