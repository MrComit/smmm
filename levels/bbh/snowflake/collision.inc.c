const Collision snowflake_collision[] = {
	COL_INIT(),
	COL_VERTEX_INIT(4),
	COL_VERTEX(-552, 0, 107),
	COL_VERTEX(184, 0, 531),
	COL_VERTEX(551, 0, -106),
	COL_VERTEX(-184, 0, -530),
	COL_TRI_INIT(SURFACE_SUPER_SLIPPERY, 2),
	COL_TRI(0, 1, 2),
	COL_TRI(0, 2, 3),
	COL_TRI_STOP(),
	COL_END()
};