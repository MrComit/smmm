const Collision foreroom_wall_collision[] = {
	COL_INIT(),
	COL_VERTEX_INIT(4),
	COL_VERTEX(0, 0, 282),
	COL_VERTEX(0, 520, 282),
	COL_VERTEX(0, 520, -282),
	COL_VERTEX(0, 0, -282),
	COL_TRI_INIT(SURFACE_DEFAULT, 2),
	COL_TRI(0, 1, 2),
	COL_TRI(0, 2, 3),
	COL_TRI_STOP(),
	COL_END()
};
