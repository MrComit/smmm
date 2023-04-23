void scroll_sts_mat_mind_2d_goomba__2DGoomba() {
	static int intervalTex0 = 8;
	static int curInterval0 = 8;
	Gfx *mat = segmented_to_virtual(mat_mind_2d_goomba__2DGoomba);

	if (--curInterval0 <= 0) {
		shift_s(mat, 14, PACK_TILESIZE(0, 64));
		curInterval0 = intervalTex0;
	}
};

void scroll_ssl_level_geo_mind_2d_goomba() {
	scroll_sts_mat_mind_2d_goomba__2DGoomba();
}
