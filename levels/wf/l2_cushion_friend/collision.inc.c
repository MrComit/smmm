const Collision l2_cushion_friend_collision[] = {
	COL_INIT(),
	COL_VERTEX_INIT(12),
	COL_VERTEX(-77, 0, -76),
	COL_VERTEX(-77, 28, -77),
	COL_VERTEX(77, 28, -77),
	COL_VERTEX(77, 0, -76),
	COL_VERTEX(-77, 0, 76),
	COL_VERTEX(-77, 28, 77),
	COL_VERTEX(77, 0, 76),
	COL_VERTEX(77, 28, 77),
	COL_VERTEX(58, 46, -58),
	COL_VERTEX(-58, 46, -58),
	COL_VERTEX(-58, 46, 58),
	COL_VERTEX(58, 46, 58),
	COL_TRI_INIT(SURFACE_NOT_SLIPPERY, 18),
	COL_TRI(0, 1, 2),
	COL_TRI(0, 2, 3),
	COL_TRI(4, 5, 1),
	COL_TRI(4, 1, 0),
	COL_TRI(6, 7, 5),
	COL_TRI(6, 5, 4),
	COL_TRI(3, 2, 7),
	COL_TRI(3, 7, 6),
	COL_TRI(8, 9, 10),
	COL_TRI(8, 10, 11),
	COL_TRI(8, 11, 7),
	COL_TRI(8, 7, 2),
	COL_TRI(11, 10, 5),
	COL_TRI(11, 5, 7),
	COL_TRI(10, 9, 1),
	COL_TRI(10, 1, 5),
	COL_TRI(9, 8, 2),
	COL_TRI(9, 2, 1),
	COL_TRI_STOP(),
	COL_END()
};
