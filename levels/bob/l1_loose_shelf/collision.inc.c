const Collision l1_loose_shelf_collision[] = {
	COL_INIT(),
	COL_VERTEX_INIT(8),
	COL_VERTEX(242, 0, 450),
	COL_VERTEX(242, 0, 0),
	COL_VERTEX(0, 0, 0),
	COL_VERTEX(0, 0, 450),
	COL_VERTEX(242, -46, 450),
	COL_VERTEX(0, -46, 450),
	COL_VERTEX(0, -46, 0),
	COL_VERTEX(242, -46, 0),
	COL_TRI_INIT(SURFACE_DEFAULT, 8),
	COL_TRI(0, 1, 2),
	COL_TRI(0, 2, 3),
	COL_TRI(4, 5, 6),
	COL_TRI(4, 6, 7),
	COL_TRI(1, 7, 6),
	COL_TRI(1, 6, 2),
	COL_TRI(0, 4, 7),
	COL_TRI(0, 7, 1),
	COL_TRI_STOP(),
	COL_END()
};
