const Collision dirt_mound_collision[] = {
	COL_INIT(),
	COL_VERTEX_INIT(13),
	COL_VERTEX(-117, 38, -67),
	COL_VERTEX(-117, 38, 67),
	COL_VERTEX(0, 89, 0),
	COL_VERTEX(0, 38, 135),
	COL_VERTEX(117, 38, 67),
	COL_VERTEX(117, 38, -67),
	COL_VERTEX(0, 38, -135),
	COL_VERTEX(0, 0, -174),
	COL_VERTEX(-150, 0, -87),
	COL_VERTEX(150, 0, -87),
	COL_VERTEX(150, 0, 87),
	COL_VERTEX(0, 0, 174),
	COL_VERTEX(-150, 0, 87),
	COL_TRI_INIT(SURFACE_NOT_SLIPPERY, 18),
	COL_TRI(0, 1, 2),
	COL_TRI(1, 3, 2),
	COL_TRI(3, 4, 2),
	COL_TRI(4, 5, 2),
	COL_TRI(5, 6, 2),
	COL_TRI(6, 0, 2),
	COL_TRI(7, 8, 0),
	COL_TRI(7, 0, 6),
	COL_TRI(9, 7, 6),
	COL_TRI(9, 6, 5),
	COL_TRI(10, 9, 5),
	COL_TRI(10, 5, 4),
	COL_TRI(11, 10, 4),
	COL_TRI(11, 4, 3),
	COL_TRI(12, 11, 3),
	COL_TRI(12, 3, 1),
	COL_TRI(8, 12, 1),
	COL_TRI(8, 1, 0),
	COL_TRI_STOP(),
	COL_END()
};