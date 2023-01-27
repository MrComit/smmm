
Vtx lightning_spinner_spinner_mesh_layer_1_vtx_0[32] = {
	{{{-174, -321, 62}, 0, {-16, 1008}, {0x0, 0x8A, 0x2E, 0xFF}}},
	{{{-247, -351, 3}, 0, {-16, 1008}, {0x0, 0x8A, 0x2E, 0xFF}}},
	{{{-174, -368, -60}, 0, {-16, 1008}, {0x0, 0x8A, 0x2E, 0xFF}}},
	{{{-4, -351, 3}, 0, {-16, 1008}, {0x0, 0x8A, 0x2E, 0xFF}}},
	{{{-174, -306, 58}, 0, {-16, 1008}, {0x0, 0x76, 0xD2, 0xFF}}},
	{{{-174, -353, -64}, 0, {-16, 1008}, {0x0, 0x76, 0xD2, 0xFF}}},
	{{{-247, -336, -1}, 0, {-16, 1008}, {0x0, 0x76, 0xD2, 0xFF}}},
	{{{-4, -336, -1}, 0, {-16, 1008}, {0x0, 0x76, 0xD2, 0xFF}}},
	{{{174, -321, -62}, 0, {-16, 1008}, {0x0, 0x8A, 0xD2, 0xFF}}},
	{{{247, -351, -3}, 0, {-16, 1008}, {0x0, 0x8A, 0xD2, 0xFF}}},
	{{{174, -368, 60}, 0, {-16, 1008}, {0x0, 0x8A, 0xD2, 0xFF}}},
	{{{4, -351, -3}, 0, {-16, 1008}, {0x0, 0x8A, 0xD2, 0xFF}}},
	{{{174, -306, -58}, 0, {-16, 1008}, {0x0, 0x76, 0x2E, 0xFF}}},
	{{{174, -353, 64}, 0, {-16, 1008}, {0x0, 0x76, 0x2E, 0xFF}}},
	{{{247, -336, 1}, 0, {-16, 1008}, {0x0, 0x76, 0x2E, 0xFF}}},
	{{{4, -336, 1}, 0, {-16, 1008}, {0x0, 0x76, 0x2E, 0xFF}}},
	{{{-174, -368, -60}, 0, {-16, 1008}, {0xED, 0x99, 0xB8, 0xFF}}},
	{{{-247, -351, 3}, 0, {-16, 1008}, {0x99, 0xB9, 0x15, 0xFF}}},
	{{{-247, -336, -1}, 0, {-16, 1008}, {0x96, 0x43, 0xEC, 0xFF}}},
	{{{-174, -306, 58}, 0, {-16, 1008}, {0xEF, 0x69, 0x45, 0xFF}}},
	{{{-174, -321, 62}, 0, {-16, 1008}, {0xED, 0xD8, 0x77, 0xFF}}},
	{{{-4, -336, -1}, 0, {-16, 1008}, {0x6B, 0x42, 0xEE, 0xFF}}},
	{{{-4, -351, 3}, 0, {-16, 1008}, {0x6A, 0xBC, 0x13, 0xFF}}},
	{{{-174, -353, -64}, 0, {-16, 1008}, {0xEF, 0x2C, 0x8A, 0xFF}}},
	{{{174, -368, 60}, 0, {-16, 1008}, {0x13, 0x99, 0x48, 0xFF}}},
	{{{247, -351, -3}, 0, {-16, 1008}, {0x67, 0xB9, 0xEB, 0xFF}}},
	{{{247, -336, 1}, 0, {-16, 1008}, {0x6A, 0x43, 0x14, 0xFF}}},
	{{{174, -306, -58}, 0, {-16, 1008}, {0x11, 0x69, 0xBB, 0xFF}}},
	{{{174, -321, -62}, 0, {-16, 1008}, {0x13, 0xD8, 0x89, 0xFF}}},
	{{{4, -336, 1}, 0, {-16, 1008}, {0x95, 0x42, 0x12, 0xFF}}},
	{{{4, -351, -3}, 0, {-16, 1008}, {0x96, 0xBC, 0xED, 0xFF}}},
	{{{174, -353, 64}, 0, {-16, 1008}, {0x11, 0x2C, 0x76, 0xFF}}},
};

Gfx lightning_spinner_spinner_mesh_layer_1_tri_0[] = {
	gsSPVertex(lightning_spinner_spinner_mesh_layer_1_vtx_0 + 0, 32, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSP2Triangles(4, 5, 6, 0, 4, 7, 5, 0),
	gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
	gsSP2Triangles(12, 13, 14, 0, 12, 15, 13, 0),
	gsSP2Triangles(16, 17, 18, 0, 17, 19, 18, 0),
	gsSP2Triangles(17, 20, 19, 0, 20, 21, 19, 0),
	gsSP2Triangles(20, 22, 21, 0, 22, 23, 21, 0),
	gsSP2Triangles(22, 16, 23, 0, 16, 18, 23, 0),
	gsSP2Triangles(24, 25, 26, 0, 25, 27, 26, 0),
	gsSP2Triangles(25, 28, 27, 0, 28, 29, 27, 0),
	gsSP2Triangles(28, 30, 29, 0, 30, 31, 29, 0),
	gsSP2Triangles(30, 24, 31, 0, 24, 26, 31, 0),
	gsSPEndDisplayList(),
};


Gfx mat_lightning_spinner_Spinner_002[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(ENVIRONMENT, 0, SHADE, 0, 0, 0, 0, 1, ENVIRONMENT, 0, SHADE, 0, 0, 0, 0, 1),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetEnvColor(173, 87, 0, 255),
    gsSPLightColor(LIGHT_1, 0xffffffff),
    gsSPLightColor(LIGHT_2, 0x7f7f7fff),
	gsSPEndDisplayList(),
};

Gfx lightning_spinner_spinner_mesh_layer_1[] = {
	gsSPDisplayList(mat_lightning_spinner_Spinner_002),
	gsSPDisplayList(lightning_spinner_spinner_mesh_layer_1_tri_0),
	gsSPEndDisplayList(),
};

Gfx lightning_spinner_material_revert_render_settings[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};

