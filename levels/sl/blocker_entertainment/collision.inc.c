const Collision blocker_entertainment_collision[] = {
	COL_INIT(),
	COL_VERTEX_INIT(4),
	COL_VERTEX(75, 250, 0),
	COL_VERTEX(-75, 250, 0),
	COL_VERTEX(-75, 0, 0),
	COL_VERTEX(75, 0, 0),
	COL_TRI_INIT(SURFACE_DEFAULT, 2),
	COL_TRI(0, 1, 2),
	COL_TRI(0, 2, 3),
	COL_TRI_STOP(),
	COL_END()
};
