const Collision garage_wall_collision[] = {
	COL_INIT(),
	COL_VERTEX_INIT(4),
	COL_VERTEX(-36, 0, 73),
	COL_VERTEX(-36, 250, 73),
	COL_VERTEX(-36, 250, -77),
	COL_VERTEX(-36, 0, -77),
	COL_TRI_INIT(SURFACE_DEFAULT, 2),
	COL_TRI(0, 1, 2),
	COL_TRI(0, 2, 3),
	COL_TRI_STOP(),
	COL_END()
};
