const Collision bob_area_1_collision[] = {
	COL_INIT(),
	COL_VERTEX_INIT(4),
	COL_VERTEX(-4751, -379, 29577),
	COL_VERTEX(4751, -379, 29577),
	COL_VERTEX(4751, -379, 20075),
	COL_VERTEX(-4751, -379, 20075),
	COL_TRI_INIT(SURFACE_DEFAULT, 2),
	COL_TRI(0, 1, 2),
	COL_TRI(0, 2, 3),
	COL_TRI_STOP(),
	COL_END()
};
