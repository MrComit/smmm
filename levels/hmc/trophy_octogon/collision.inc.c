const Collision trophy_octogon_collision[] = {
	COL_INIT(),
	COL_VERTEX_INIT(14),
	COL_VERTEX(216, 100, -522),
	COL_VERTEX(522, 100, -216),
	COL_VERTEX(522, 0, -216),
	COL_VERTEX(216, 0, -522),
	COL_VERTEX(-216, 100, 522),
	COL_VERTEX(-522, 100, 216),
	COL_VERTEX(-522, 0, 216),
	COL_VERTEX(-216, 0, 522),
	COL_VERTEX(-216, 100, -522),
	COL_VERTEX(-216, 0, -522),
	COL_VERTEX(216, 100, 522),
	COL_VERTEX(216, 0, 522),
	COL_VERTEX(0, 100, 0),
	COL_VERTEX(0, 0, 0),
	COL_TRI_INIT(SURFACE_DEFAULT, 24),
	COL_TRI(0, 1, 2),
	COL_TRI(0, 2, 3),
	COL_TRI(4, 5, 6),
	COL_TRI(4, 6, 7),
	COL_TRI(8, 0, 3),
	COL_TRI(8, 3, 9),
	COL_TRI(10, 4, 7),
	COL_TRI(10, 7, 11),
	COL_TRI(5, 4, 12),
	COL_TRI(4, 10, 12),
	COL_TRI(1, 0, 12),
	COL_TRI(0, 8, 12),
	COL_TRI(10, 11, 13),
	COL_TRI(10, 13, 12),
	COL_TRI(9, 3, 13),
	COL_TRI(3, 2, 13),
	COL_TRI(12, 13, 2),
	COL_TRI(12, 2, 1),
	COL_TRI(9, 13, 12),
	COL_TRI(9, 12, 8),
	COL_TRI(11, 7, 13),
	COL_TRI(7, 6, 13),
	COL_TRI(6, 5, 12),
	COL_TRI(6, 12, 13),
	COL_TRI_STOP(),
	COL_END()
};