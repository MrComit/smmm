void scroll_sts_mat_maze_wins_OrangeWave() {
	Gfx *mat = segmented_to_virtual(mat_maze_wins_OrangeWave);
	shift_s(mat, 9, PACK_TILESIZE(0, 1));
};

void scroll_ssl_level_geo_maze_wins() {
	scroll_sts_mat_maze_wins_OrangeWave();
}
