void scroll_sts_mat_trophy_rectangle_WoodFloorTrophyRoom_002_layer1() {
	static int intervalTex1 = 3;
	static int curInterval1 = 3;
	Gfx *mat = segmented_to_virtual(mat_trophy_rectangle_WoodFloorTrophyRoom_002_layer1);

	if (--curInterval1 <= 0) {
		shift_s(mat, 22, PACK_TILESIZE(0, 1));
		shift_t(mat, 22, PACK_TILESIZE(0, 2));
		curInterval1 = intervalTex1;
	}
};

void scroll_hmc_level_geo_trophy_rectangle() {
	scroll_sts_mat_trophy_rectangle_WoodFloorTrophyRoom_002_layer1();
}
