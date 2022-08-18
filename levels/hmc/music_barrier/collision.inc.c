const Collision music_barrier_collision[] = {
	COL_INIT(),
	COL_VERTEX_INIT(8),
	COL_VERTEX(0, 0, 500),
	COL_VERTEX(0, 1500, 500),
	COL_VERTEX(0, 1500, -500),
	COL_VERTEX(0, 0, -500),
	COL_VERTEX(1000, 1500, -500),
	COL_VERTEX(1000, 0, -500),
	COL_VERTEX(1000, 0, 500),
	COL_VERTEX(1000, 1500, 500),
	COL_TRI_INIT(SURFACE_DEFAULT, 6),
	COL_TRI(0, 1, 2),
	COL_TRI(0, 2, 3),
	COL_TRI(3, 2, 4),
	COL_TRI(3, 4, 5),
	COL_TRI(1, 0, 6),
	COL_TRI(1, 6, 7),
	COL_TRI_STOP(),
	COL_END()
};
