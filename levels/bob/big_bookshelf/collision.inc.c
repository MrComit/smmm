const Collision big_bookshelf_collision[] = {
	COL_INIT(),
	COL_VERTEX_INIT(8),
	COL_VERTEX(900, 0, 0),
	COL_VERTEX(900, 823, 0),
	COL_VERTEX(0, 823, 0),
	COL_VERTEX(0, 0, 0),
	COL_VERTEX(900, 0, -200),
	COL_VERTEX(900, 823, -200),
	COL_VERTEX(0, 823, -200),
	COL_VERTEX(0, 0, -200),
	COL_TRI_INIT(SURFACE_NOT_SLIPPERY, 10),
	COL_TRI(0, 1, 2),
	COL_TRI(0, 2, 3),
	COL_TRI(4, 5, 1),
	COL_TRI(4, 1, 0),
	COL_TRI(3, 2, 6),
	COL_TRI(3, 6, 7),
	COL_TRI(2, 1, 5),
	COL_TRI(2, 5, 6),
	COL_TRI(5, 4, 7),
	COL_TRI(5, 7, 6),
	COL_TRI_STOP(),
	COL_END()
};
