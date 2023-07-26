const Collision purple_cushion_collision[] = {
	COL_INIT(),
	COL_VERTEX_INIT(12),
	COL_VERTEX(114, 92, -113),
	COL_VERTEX(-114, 92, -113),
	COL_VERTEX(-114, 92, 113),
	COL_VERTEX(114, 92, 113),
	COL_VERTEX(150, 46, 150),
	COL_VERTEX(150, 46, -150),
	COL_VERTEX(-150, 46, 150),
	COL_VERTEX(-150, 46, -150),
	COL_VERTEX(114, 0, -113),
	COL_VERTEX(114, 0, 113),
	COL_VERTEX(-114, 0, 113),
	COL_VERTEX(-114, 0, -113),
	COL_TRI_INIT(SURFACE_NOT_SLIPPERY, 20),
	COL_TRI(0, 1, 2),
	COL_TRI(0, 2, 3),
	COL_TRI(0, 3, 4),
	COL_TRI(0, 4, 5),
	COL_TRI(3, 2, 6),
	COL_TRI(3, 6, 4),
	COL_TRI(2, 1, 7),
	COL_TRI(2, 7, 6),
	COL_TRI(1, 0, 5),
	COL_TRI(1, 5, 7),
	COL_TRI(8, 9, 10),
	COL_TRI(8, 10, 11),
	COL_TRI(8, 5, 4),
	COL_TRI(8, 4, 9),
	COL_TRI(9, 4, 6),
	COL_TRI(9, 6, 10),
	COL_TRI(10, 6, 7),
	COL_TRI(10, 7, 11),
	COL_TRI(11, 7, 5),
	COL_TRI(11, 5, 8),
	COL_TRI_STOP(),
	COL_END()
};
