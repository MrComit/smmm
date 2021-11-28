const Collision horizontal_pole_collision[] = {
	COL_INIT(),
	COL_VERTEX_INIT(16),
	COL_VERTEX(-296, -250, 32),
	COL_VERTEX(-230, -250, 32),
	COL_VERTEX(-230, 150, 32),
	COL_VERTEX(-296, 150, 32),
	COL_VERTEX(-296, -250, -32),
	COL_VERTEX(-296, 150, -32),
	COL_VERTEX(-230, 150, -32),
	COL_VERTEX(296, -250, -32),
	COL_VERTEX(230, -250, -32),
	COL_VERTEX(230, 150, -32),
	COL_VERTEX(296, 150, -32),
	COL_VERTEX(296, -250, 32),
	COL_VERTEX(296, 150, 32),
	COL_VERTEX(230, 150, 32),
	COL_VERTEX(230, -250, 32),
	COL_VERTEX(-230, -250, -32),
	COL_TRI_INIT(SURFACE_DEFAULT, 20),
	COL_TRI(0, 1, 2),
	COL_TRI(0, 2, 3),
	COL_TRI(4, 0, 3),
	COL_TRI(4, 3, 5),
	COL_TRI(3, 2, 6),
	COL_TRI(3, 6, 5),
	COL_TRI(7, 8, 9),
	COL_TRI(7, 9, 10),
	COL_TRI(11, 7, 10),
	COL_TRI(11, 10, 12),
	COL_TRI(13, 12, 10),
	COL_TRI(13, 10, 9),
	COL_TRI(8, 14, 13),
	COL_TRI(8, 13, 9),
	COL_TRI(1, 15, 6),
	COL_TRI(1, 6, 2),
	COL_TRI(14, 11, 12),
	COL_TRI(14, 12, 13),
	COL_TRI(15, 4, 5),
	COL_TRI(15, 5, 6),
	COL_TRI_STOP(),
	COL_END()
};
