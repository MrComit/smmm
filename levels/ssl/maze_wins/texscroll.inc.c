void scroll_sts_mat_maze_wins_OrangeWave_002() {
	Gfx *mat = segmented_to_virtual(mat_maze_wins_OrangeWave_002);
	shift_s(mat, 10, PACK_TILESIZE(0, 1));
};

void scroll_ssl_level_geo_maze_wins() {
	scroll_sts_mat_maze_wins_OrangeWave_002();
}
