const Collision mem_vase_collision[] = {
	COL_INIT(),
	COL_VERTEX_INIT(12),
	COL_VERTEX(-70, 203, -41),
	COL_VERTEX(0, 203, -81),
	COL_VERTEX(0, 0, -81),
	COL_VERTEX(-70, 0, -41),
	COL_VERTEX(70, 0, -41),
	COL_VERTEX(70, 203, -41),
	COL_VERTEX(0, 0, 81),
	COL_VERTEX(70, 0, 41),
	COL_VERTEX(70, 203, 41),
	COL_VERTEX(0, 203, 81),
	COL_VERTEX(-70, 0, 41),
	COL_VERTEX(-70, 203, 41),
	COL_TRI_INIT(SURFACE_DEFAULT, 16),
	COL_TRI(0, 1, 2),
	COL_TRI(0, 2, 3),
	COL_TRI(4, 2, 1),
	COL_TRI(4, 1, 5),
	COL_TRI(6, 7, 8),
	COL_TRI(6, 8, 9),
	COL_TRI(7, 4, 5),
	COL_TRI(7, 5, 8),
	COL_TRI(10, 6, 9),
	COL_TRI(10, 9, 11),
	COL_TRI(1, 0, 11),
	COL_TRI(11, 9, 8),
	COL_TRI(8, 5, 1),
	COL_TRI(11, 8, 1),
	COL_TRI(3, 10, 11),
	COL_TRI(3, 11, 0),
	COL_TRI_STOP(),
	COL_END()
};
