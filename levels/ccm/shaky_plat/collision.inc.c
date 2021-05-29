const Collision shaky_plat_collision[] = {
	COL_INIT(),
	COL_VERTEX_INIT(8),
	COL_VERTEX(-272, 0, 0),
	COL_VERTEX(272, 0, 0),
	COL_VERTEX(272, 0, 453),
	COL_VERTEX(-272, 0, 453),
	COL_VERTEX(-272, 64, 0),
	COL_VERTEX(-272, 64, 453),
	COL_VERTEX(272, 64, 453),
	COL_VERTEX(272, 64, 0),
	COL_TRI_INIT(SURFACE_DEFAULT, 10),
	COL_TRI(0, 1, 2),
	COL_TRI(0, 2, 3),
	COL_TRI(4, 5, 6),
	COL_TRI(4, 6, 7),
	COL_TRI(3, 2, 6),
	COL_TRI(3, 6, 5),
	COL_TRI(0, 3, 5),
	COL_TRI(0, 5, 4),
	COL_TRI(2, 1, 7),
	COL_TRI(2, 7, 6),
	COL_TRI_STOP(),
	COL_END()
};
