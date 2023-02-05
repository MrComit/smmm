void scroll_sts_mat_pool_barrier_GhostBarrier_layer1() {
	Gfx *mat = segmented_to_virtual(mat_pool_barrier_GhostBarrier_layer1);
	shift_t(mat, 14, PACK_TILESIZE(0, 1));
	shift_s(mat, 22, PACK_TILESIZE(0, 4));
	shift_t(mat, 22, PACK_TILESIZE(0, 1));
};

void scroll_sts_mat_pool_barrier_GhostBarrierConsole_layer1() {
	Gfx *mat = segmented_to_virtual(mat_pool_barrier_GhostBarrierConsole_layer1);
	shift_s(mat, 14, PACK_TILESIZE(0, 4));
	shift_t(mat, 14, PACK_TILESIZE(0, 1));
	shift_t(mat, 22, PACK_TILESIZE(0, 1));
};

void scroll_hmc_level_geo_pool_barrier() {
	scroll_sts_mat_pool_barrier_GhostBarrier_layer1();
	scroll_sts_mat_pool_barrier_GhostBarrierConsole_layer1();
}
