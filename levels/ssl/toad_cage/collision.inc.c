const Collision toad_cage_collision[] = {
	COL_INIT(),
	COL_VERTEX_INIT(64),
	COL_VERTEX(-9, 617, -122),
	COL_VERTEX(-80, 617, -92),
	COL_VERTEX(-92, 617, -80),
	COL_VERTEX(-122, 617, -9),
	COL_VERTEX(-122, 617, 9),
	COL_VERTEX(-92, 617, 80),
	COL_VERTEX(-80, 617, 92),
	COL_VERTEX(-9, 617, 122),
	COL_VERTEX(9, 617, 122),
	COL_VERTEX(80, 617, 92),
	COL_VERTEX(92, 617, 80),
	COL_VERTEX(122, 617, 9),
	COL_VERTEX(122, 617, -9),
	COL_VERTEX(92, 617, -80),
	COL_VERTEX(80, 617, -92),
	COL_VERTEX(9, 617, -122),
	COL_VERTEX(9, 578, -122),
	COL_VERTEX(80, 578, -92),
	COL_VERTEX(-9, 578, -122),
	COL_VERTEX(-80, 578, -92),
	COL_VERTEX(-9, 578, 122),
	COL_VERTEX(-80, 578, 92),
	COL_VERTEX(80, 578, 92),
	COL_VERTEX(9, 578, 122),
	COL_VERTEX(92, 578, 80),
	COL_VERTEX(92, 578, -80),
	COL_VERTEX(-92, 578, -80),
	COL_VERTEX(-92, 578, 80),
	COL_VERTEX(-122, 578, 9),
	COL_VERTEX(-122, 578, -9),
	COL_VERTEX(122, 578, -9),
	COL_VERTEX(122, 578, 9),
	COL_VERTEX(19, 500, -266),
	COL_VERTEX(-19, 500, -266),
	COL_VERTEX(266, 500, 19),
	COL_VERTEX(202, 500, 175),
	COL_VERTEX(202, 0, 175),
	COL_VERTEX(266, 0, 19),
	COL_VERTEX(19, 500, 266),
	COL_VERTEX(175, 500, 202),
	COL_VERTEX(175, 500, -202),
	COL_VERTEX(-19, 500, 266),
	COL_VERTEX(202, 500, -175),
	COL_VERTEX(-175, 500, 202),
	COL_VERTEX(-266, 500, -19),
	COL_VERTEX(-266, 500, 19),
	COL_VERTEX(-202, 500, 175),
	COL_VERTEX(-202, 500, -175),
	COL_VERTEX(266, 500, -19),
	COL_VERTEX(-175, 500, -202),
	COL_VERTEX(-175, 0, -202),
	COL_VERTEX(-202, 0, -175),
	COL_VERTEX(175, 0, 202),
	COL_VERTEX(-19, 0, -266),
	COL_VERTEX(19, 0, 266),
	COL_VERTEX(19, 0, -266),
	COL_VERTEX(-19, 0, 266),
	COL_VERTEX(175, 0, -202),
	COL_VERTEX(-175, 0, 202),
	COL_VERTEX(202, 0, -175),
	COL_VERTEX(-202, 0, 175),
	COL_VERTEX(266, 0, -19),
	COL_VERTEX(-266, 0, -19),
	COL_VERTEX(-266, 0, 19),
	COL_TRI_INIT(SURFACE_DEFAULT, 110),
	COL_TRI(0, 1, 2),
	COL_TRI(2, 3, 4),
	COL_TRI(4, 5, 6),
	COL_TRI(6, 7, 8),
	COL_TRI(8, 9, 10),
	COL_TRI(10, 11, 12),
	COL_TRI(12, 13, 14),
	COL_TRI(14, 15, 0),
	COL_TRI(0, 2, 4),
	COL_TRI(4, 6, 8),
	COL_TRI(8, 10, 12),
	COL_TRI(12, 14, 0),
	COL_TRI(0, 4, 8),
	COL_TRI(8, 12, 0),
	COL_TRI(16, 15, 14),
	COL_TRI(16, 14, 17),
	COL_TRI(0, 18, 19),
	COL_TRI(0, 19, 1),
	COL_TRI(20, 7, 6),
	COL_TRI(20, 6, 21),
	COL_TRI(22, 9, 8),
	COL_TRI(22, 8, 23),
	COL_TRI(24, 10, 9),
	COL_TRI(24, 9, 22),
	COL_TRI(17, 14, 13),
	COL_TRI(17, 13, 25),
	COL_TRI(19, 26, 2),
	COL_TRI(19, 2, 1),
	COL_TRI(27, 5, 4),
	COL_TRI(27, 4, 28),
	COL_TRI(28, 4, 3),
	COL_TRI(28, 3, 29),
	COL_TRI(12, 30, 25),
	COL_TRI(12, 25, 13),
	COL_TRI(21, 6, 5),
	COL_TRI(21, 5, 27),
	COL_TRI(31, 30, 12),
	COL_TRI(31, 12, 11),
	COL_TRI(23, 8, 7),
	COL_TRI(23, 7, 20),
	COL_TRI(24, 31, 11),
	COL_TRI(24, 11, 10),
	COL_TRI(18, 0, 15),
	COL_TRI(18, 15, 16),
	COL_TRI(29, 3, 2),
	COL_TRI(29, 2, 26),
	COL_TRI(18, 16, 32),
	COL_TRI(18, 32, 33),
	COL_TRI(34, 35, 36),
	COL_TRI(34, 36, 37),
	COL_TRI(22, 23, 38),
	COL_TRI(22, 38, 39),
	COL_TRI(16, 17, 40),
	COL_TRI(16, 40, 32),
	COL_TRI(23, 20, 41),
	COL_TRI(23, 41, 38),
	COL_TRI(17, 25, 42),
	COL_TRI(17, 42, 40),
	COL_TRI(20, 21, 43),
	COL_TRI(20, 43, 41),
	COL_TRI(28, 29, 44),
	COL_TRI(28, 44, 45),
	COL_TRI(21, 27, 46),
	COL_TRI(21, 46, 43),
	COL_TRI(29, 26, 47),
	COL_TRI(29, 47, 44),
	COL_TRI(25, 30, 48),
	COL_TRI(25, 48, 42),
	COL_TRI(27, 28, 45),
	COL_TRI(27, 45, 46),
	COL_TRI(30, 31, 34),
	COL_TRI(30, 34, 48),
	COL_TRI(26, 19, 49),
	COL_TRI(26, 49, 47),
	COL_TRI(31, 24, 35),
	COL_TRI(31, 35, 34),
	COL_TRI(19, 18, 33),
	COL_TRI(19, 33, 49),
	COL_TRI(24, 22, 39),
	COL_TRI(24, 39, 35),
	COL_TRI(47, 49, 50),
	COL_TRI(47, 50, 51),
	COL_TRI(35, 39, 52),
	COL_TRI(35, 52, 36),
	COL_TRI(49, 33, 53),
	COL_TRI(49, 53, 50),
	COL_TRI(39, 38, 54),
	COL_TRI(39, 54, 52),
	COL_TRI(33, 32, 55),
	COL_TRI(33, 55, 53),
	COL_TRI(38, 41, 56),
	COL_TRI(38, 56, 54),
	COL_TRI(32, 40, 57),
	COL_TRI(32, 57, 55),
	COL_TRI(41, 43, 58),
	COL_TRI(41, 58, 56),
	COL_TRI(40, 42, 59),
	COL_TRI(40, 59, 57),
	COL_TRI(43, 46, 60),
	COL_TRI(43, 60, 58),
	COL_TRI(42, 48, 61),
	COL_TRI(42, 61, 59),
	COL_TRI(45, 44, 62),
	COL_TRI(45, 62, 63),
	COL_TRI(44, 47, 51),
	COL_TRI(44, 51, 62),
	COL_TRI(48, 34, 37),
	COL_TRI(48, 37, 61),
	COL_TRI(46, 45, 63),
	COL_TRI(46, 63, 60),
	COL_TRI_STOP(),
	COL_END()
};