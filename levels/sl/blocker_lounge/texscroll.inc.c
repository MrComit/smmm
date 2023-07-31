void scroll_sts_mat_blocker_lounge_Wall_002() {
	static int intervalTex1 = 2;
	static int curInterval1 = 2;
	Gfx *mat = segmented_to_virtual(mat_blocker_lounge_Wall_002);

	if (--curInterval1 <= 0) {
		shift_s(mat, -1, PACK_TILESIZE(0, 1));
		curInterval1 = intervalTex1;
	}
};

void scroll_sl_level_geo_blocker_lounge() {
	scroll_sts_mat_blocker_lounge_Wall_002();
}
