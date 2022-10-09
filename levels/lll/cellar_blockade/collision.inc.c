const Collision cellar_blockade_collision[] = {
	COL_INIT(),
	COL_VERTEX_INIT(4),
	COL_VERTEX(190, -140, 17),
	COL_VERTEX(190, 146, 17),
	COL_VERTEX(-184, 146, 17),
	COL_VERTEX(-184, -140, 17),
	COL_TRI_INIT(SURFACE_DEFAULT, 2),
	COL_TRI(0, 1, 2),
	COL_TRI(0, 2, 3),
	COL_TRI_STOP(),
	COL_END()
};
