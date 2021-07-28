void scroll_sts_mat_ghost_barrier_GhostBarrier_001_v4_layer5() {
	Gfx *mat = segmented_to_virtual(mat_ghost_barrier_GhostBarrier_001_v4_layer5);
	shift_s(mat, 13, PACK_TILESIZE(0, 1));
	shift_t(mat, 13, PACK_TILESIZE(0, 1));
	shift_t(mat, 21, PACK_TILESIZE(0, 1));
};

void scroll_bob_level_geo_ghost_barrier() {
	scroll_sts_mat_ghost_barrier_GhostBarrier_001_v4_layer5();
}
