const Collision attic_rock_collision[] = {
	COL_INIT(),
	COL_VERTEX_INIT(9),
	COL_VERTEX(-500, -127, 499),
	COL_VERTEX(-500, -127, -501),
	COL_VERTEX(500, -127, -501),
	COL_VERTEX(500, -127, 499),
	COL_VERTEX(500, 0, 499),
	COL_VERTEX(-500, 0, 501),
	COL_VERTEX(-500, 0, -501),
	COL_VERTEX(500, 0, -499),
	COL_VERTEX(0, 45, -1),
	COL_TRI_INIT(SURFACE_DEFAULT, 14),
	COL_TRI(0, 1, 2),
	COL_TRI(0, 2, 3),
	COL_TRI(0, 3, 4),
	COL_TRI(0, 4, 5),
	COL_TRI(1, 6, 7),
	COL_TRI(1, 7, 2),
	COL_TRI(2, 7, 4),
	COL_TRI(2, 4, 3),
	COL_TRI(1, 0, 5),
	COL_TRI(1, 5, 6),
	COL_TRI(7, 8, 4),
	COL_TRI(6, 8, 7),
	COL_TRI(5, 8, 6),
	COL_TRI(4, 8, 5),
	COL_TRI_STOP(),
	COL_END()
};
