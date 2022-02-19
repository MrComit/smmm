void scroll_sts_mat_pool_floor_WoodFloorTransparent_001_layer5() {
	static int intervalTex1 = 3;
	static int curInterval1 = 3;
	Gfx *mat = segmented_to_virtual(mat_pool_floor_WoodFloorTransparent_001_layer5);

	if (--curInterval1 <= 0) {
		shift_s(mat, 23, PACK_TILESIZE(0, 1));
		shift_t(mat, 23, PACK_TILESIZE(0, 2));
		curInterval1 = intervalTex1;
	}
};

void scroll_hmc_level_geo_pool_floor() {
	scroll_sts_mat_pool_floor_WoodFloorTransparent_001_layer5();
}
