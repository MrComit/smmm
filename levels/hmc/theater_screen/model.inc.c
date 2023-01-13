
Vtx theater_screen_screen_mesh_layer_1_vtx_0[8] = {
	{{{-1059, 1059, 0},0, {-8416, -2571},{0x5, 0x6, 0x12, 0xD9}}},
	{{{1250, 1260, 0},0, {-16, -3092},{0x5, 0x6, 0x12, 0xFF}}},
	{{{-1250, 1260, 0},0, {-9110, -3092},{0x5, 0x6, 0x12, 0xFF}}},
	{{{1059, 1059, 0},0, {-710, -2571},{0x5, 0x6, 0x12, 0xD9}}},
	{{{1059, 191, 0},0, {-710, -196},{0x5, 0x6, 0x12, 0xD9}}},
	{{{-1059, 191, 0},0, {-8416, -196},{0x5, 0x6, 0x12, 0xD9}}},
	{{{-1250, -10, 0},0, {-9110, 325},{0x5, 0x6, 0x12, 0xFF}}},
	{{{1250, -10, 0},0, {-16, 325},{0x5, 0x6, 0x12, 0xFF}}},
};

Gfx theater_screen_screen_mesh_layer_1_tri_0[] = {
	gsSPVertex(theater_screen_screen_mesh_layer_1_vtx_0 + 0, 8, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
	gsSP2Triangles(4, 3, 0, 0, 4, 0, 5, 0),
	gsSP2Triangles(5, 0, 2, 0, 5, 2, 6, 0),
	gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
	gsSP2Triangles(3, 4, 7, 0, 3, 7, 1, 0),
	gsSPEndDisplayList(),
};


Gfx mat_theater_screen_Screen_002[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, SHADE, SHADE, 0, ENVIRONMENT, 0, 0, 0, 0, SHADE, SHADE, 0, ENVIRONMENT, 0),
	gsSPGeometryMode(G_LIGHTING, 0),
	gsSPTexture(65535, 65535, 0, 0, 1),
    gsSPLightColor(LIGHT_1, 0xfefefeff),
    gsSPLightColor(LIGHT_2, 0x7f7f7fff),
	gsSPEndDisplayList(),
};

Gfx mat_revert_theater_screen_Screen_002[] = {
	gsDPPipeSync(),
	gsSPGeometryMode(0, G_LIGHTING),
	gsSPEndDisplayList(),
};

Gfx theater_screen_screen_mesh_layer_1[] = {
	gsSPDisplayList(mat_theater_screen_Screen_002),
	gsSPDisplayList(theater_screen_screen_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_theater_screen_Screen_002),
	gsSPEndDisplayList(),
};

Gfx theater_screen_material_revert_render_settings[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};

