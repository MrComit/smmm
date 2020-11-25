const Collision lever_collision[] = {
	COL_INIT(),
	COL_VERTEX_INIT(8),
	COL_VERTEX(-49, -11, 49),
	COL_VERTEX(-49, 102, 49),
	COL_VERTEX(-49, 102, -49),
	COL_VERTEX(-49, -11, -49),
	COL_VERTEX(49, 102, -49),
	COL_VERTEX(49, -11, -49),
	COL_VERTEX(49, 102, 49),
	COL_VERTEX(49, -11, 49),
	COL_TRI_INIT(SURFACE_DEFAULT, 8),
	COL_TRI(0, 1, 2),
	COL_TRI(0, 2, 3),
	COL_TRI(3, 2, 4),
	COL_TRI(3, 4, 5),
	COL_TRI(5, 4, 6),
	COL_TRI(5, 6, 7),
	COL_TRI(7, 6, 1),
	COL_TRI(7, 1, 0),
	COL_TRI_STOP(),
	COL_END()
};
