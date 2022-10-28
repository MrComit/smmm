const Collision laundry_bounce_box_collision[] = {
	COL_INIT(),
	COL_VERTEX_INIT(8),
	COL_VERTEX(-86, 0, 86),
	COL_VERTEX(86, 0, 86),
	COL_VERTEX(86, 115, 86),
	COL_VERTEX(-86, 115, 86),
	COL_VERTEX(86, 0, -86),
	COL_VERTEX(-86, 0, -86),
	COL_VERTEX(-86, 115, -86),
	COL_VERTEX(86, 115, -86),
	COL_TRI_INIT(SURFACE_DEFAULT, 10),
	COL_TRI(0, 1, 2),
	COL_TRI(0, 2, 3),
	COL_TRI(4, 5, 6),
	COL_TRI(4, 6, 7),
	COL_TRI(5, 0, 3),
	COL_TRI(5, 3, 6),
	COL_TRI(1, 4, 7),
	COL_TRI(1, 7, 2),
	COL_TRI(3, 2, 7),
	COL_TRI(3, 7, 6),
	COL_TRI_STOP(),
	COL_END()
};
