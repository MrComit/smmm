void scroll_sts_mat_swinging_plat_WoodPlat_layer1() {
	static int intervalTex1 = 2;
	static int curInterval1 = 2;
	Gfx *mat = segmented_to_virtual(mat_swinging_plat_WoodPlat_layer1);

	if (--curInterval1 <= 0) {
		shift_s(mat, 21, PACK_TILESIZE(0, 1));
		shift_t(mat, 21, PACK_TILESIZE(0, 1));
		curInterval1 = intervalTex1;
	}
};

void scroll_lll_level_geo_swinging_plat() {
	scroll_sts_mat_swinging_plat_WoodPlat_layer1();
}
