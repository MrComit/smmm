void scroll_sts_mat_wall_hammerbro_HammerBroNoHammer() {
	static int intervalTex0 = 8;
	static int curInterval0 = 8;
	Gfx *mat = segmented_to_virtual(mat_wall_hammerbro_HammerBroNoHammer);

	if (--curInterval0 <= 0) {
		shift_s(mat, 19, PACK_TILESIZE(0, 64));
		curInterval0 = intervalTex0;
	}
};

void scroll_lll_level_geo_wall_hammerbro() {
	scroll_sts_mat_wall_hammerbro_HammerBroNoHammer();
}
