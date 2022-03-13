const Collision tight_rope_collision[] = {
	COL_INIT(),
	COL_VERTEX_INIT(4),
	COL_VERTEX(-90, 0, 500),
	COL_VERTEX(90, 0, 500),
	COL_VERTEX(90, 0, -500),
	COL_VERTEX(-90, 0, -500),
	COL_TRI_INIT(SURFACE_TIGHT_ROPE, 2),
	COL_TRI(0, 1, 2),
	COL_TRI(0, 2, 3),
	COL_TRI_STOP(),
	COL_END()
};
