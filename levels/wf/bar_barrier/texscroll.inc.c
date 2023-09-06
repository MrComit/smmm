void scroll_sts_mat_bar_barrier_GhostBarrier_002_layer1() {
	Gfx *mat = segmented_to_virtual(mat_bar_barrier_GhostBarrier_002_layer1);
	shift_t(mat, 11, PACK_TILESIZE(0, 1));
	shift_s(mat, 16, PACK_TILESIZE(0, 4));
	shift_t(mat, 16, PACK_TILESIZE(0, 1));
};

void scroll_wf_level_geo_bar_barrier() {
	scroll_sts_mat_bar_barrier_GhostBarrier_002_layer1();
}
