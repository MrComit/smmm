void scroll_sts_mat_pool_barrier_GhostBarrier_layer5() {
	Gfx *mat = segmented_to_virtual(mat_pool_barrier_GhostBarrier_layer5);
	shift_t(mat, 14, PACK_TILESIZE(0, 1));
	shift_s(mat, 22, PACK_TILESIZE(0, 4));
	shift_t(mat, 22, PACK_TILESIZE(0, 1));
};

void scroll_hmc_level_geo_pool_barrier() {
	scroll_sts_mat_pool_barrier_GhostBarrier_layer5();
}
