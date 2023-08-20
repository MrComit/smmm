void scroll_sts_mat_c4_swinging_plat_WoodPlat_001_layer1() {
	static int intervalTex1 = 2;
	static int curInterval1 = 2;
	Gfx *mat = segmented_to_virtual(mat_c4_swinging_plat_WoodPlat_001_layer1);

	if (--curInterval1 <= 0) {
		shift_s(mat, 15, PACK_TILESIZE(0, 1));
		shift_t(mat, 15, PACK_TILESIZE(0, 1));
		curInterval1 = intervalTex1;
	}
};

void scroll_ttc_level_geo_c4_swinging_plat() {
	scroll_sts_mat_c4_swinging_plat_WoodPlat_001_layer1();
}
