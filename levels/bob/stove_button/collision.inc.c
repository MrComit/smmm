const Collision stove_button_collision[] = {
	COL_INIT(),
	COL_VERTEX_INIT(8),
	COL_VERTEX(102, 108, 23),
	COL_VERTEX(100, -121, 23),
	COL_VERTEX(100, -122, 0),
	COL_VERTEX(97, 111, 0),
	COL_VERTEX(-107, -121, 23),
	COL_VERTEX(-106, 109, 23),
	COL_VERTEX(-106, 110, 0),
	COL_VERTEX(-107, -121, 0),
	COL_TRI_INIT(SURFACE_DEFAULT, 10),
	COL_TRI(0, 1, 2),
	COL_TRI(0, 2, 3),
	COL_TRI(4, 5, 6),
	COL_TRI(4, 6, 7),
	COL_TRI(4, 7, 2),
	COL_TRI(4, 2, 1),
	COL_TRI(4, 1, 0),
	COL_TRI(4, 0, 5),
	COL_TRI(0, 3, 6),
	COL_TRI(0, 6, 5),
	COL_TRI_STOP(),
	COL_END()
};
