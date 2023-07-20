const Collision red_spot_collision[] = {
	COL_INIT(),
	COL_VERTEX_INIT(4),
	COL_VERTEX(18, 5, -99),
	COL_VERTEX(-103, 5, -75),
	COL_VERTEX(-36, 5, 154),
	COL_VERTEX(65, 5, 60),
	COL_TRI_INIT(SURFACE_DEFAULT, 2),
	COL_TRI(0, 1, 2),
	COL_TRI(0, 2, 3),
	COL_TRI_STOP(),
	COL_END()
};
