const Collision obs_boogoo_collision[] = {
	COL_INIT(),
	COL_VERTEX_INIT(13),
	COL_VERTEX(-203, 116, 0),
	COL_VERTEX(-101, 116, 176),
	COL_VERTEX(0, 164, 0),
	COL_VERTEX(-101, 116, -176),
	COL_VERTEX(203, 116, 0),
	COL_VERTEX(101, 116, -176),
	COL_VERTEX(101, 116, 176),
	COL_VERTEX(-376, -143, 0),
	COL_VERTEX(-188, -143, 326),
	COL_VERTEX(188, -143, 326),
	COL_VERTEX(376, -143, 0),
	COL_VERTEX(188, -143, -326),
	COL_VERTEX(-188, -143, -326),
	COL_TRI_INIT(SURFACE_INSTANT_QUICKSAND, 18),
	COL_TRI(0, 1, 2),
	COL_TRI(3, 0, 2),
	COL_TRI(4, 5, 2),
	COL_TRI(1, 6, 2),
	COL_TRI(5, 3, 2),
	COL_TRI(6, 4, 2),
	COL_TRI(1, 0, 7),
	COL_TRI(1, 7, 8),
	COL_TRI(6, 1, 8),
	COL_TRI(6, 8, 9),
	COL_TRI(4, 6, 9),
	COL_TRI(4, 9, 10),
	COL_TRI(5, 4, 10),
	COL_TRI(5, 10, 11),
	COL_TRI(3, 5, 11),
	COL_TRI(3, 11, 12),
	COL_TRI(0, 3, 12),
	COL_TRI(0, 12, 7),
	COL_TRI_STOP(),
	COL_END()
};
