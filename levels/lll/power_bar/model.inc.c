Vtx power_bar_pbar_mesh_layer_1_vtx_0[10] = {
	{{{0, -10, 50}, 0, {186, 265}, {0xD9, 0xD9, 0xD9, 0xE5}}},
	{{{0, 10, 50}, 0, {15, 727}, {0xD9, 0xD9, 0xD9, 0xE5}}},
	{{{-20, 0, 50}, 0, {100, 727}, {0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{0, -10, 0}, 0, {186, 265}, {0xD9, 0xD9, 0xD9, 0xE5}}},
	{{{-20, 0, 0}, 0, {100, 265}, {0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{0, 10, 0}, 0, {15, 727}, {0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{0, -10, 0}, 0, {186, 727}, {0xD9, 0xD9, 0xD9, 0xE5}}},
	{{{-20, 0, 50}, 0, {100, 265}, {0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{-20, 0, 0}, 0, {100, 727}, {0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{0, 10, 50}, 0, {15, 265}, {0xD9, 0xD9, 0xD9, 0xE5}}},
};

Gfx power_bar_pbar_mesh_layer_1_tri_0[] = {
	gsSPVertex(power_bar_pbar_mesh_layer_1_vtx_0 + 0, 10, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
	gsSP2Triangles(6, 0, 7, 0, 6, 7, 8, 0),
	gsSP2Triangles(8, 7, 9, 0, 8, 9, 5, 0),
	gsSPEndDisplayList(),
};


Gfx mat_power_bar_PowerBar[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(SHADE, 0, ENVIRONMENT, 0, 0, 0, 0, 1, SHADE, 0, ENVIRONMENT, 0, 0, 0, 0, 1),
	gsSPGeometryMode(G_LIGHTING, 0),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPEndDisplayList(),
};

Gfx mat_revert_power_bar_PowerBar[] = {
	gsDPPipeSync(),
	gsSPGeometryMode(0, G_LIGHTING),
	gsSPEndDisplayList(),
};

Gfx power_bar_pbar_mesh_layer_1[] = {
	gsSPDisplayList(mat_power_bar_PowerBar),
	gsSPDisplayList(power_bar_pbar_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_power_bar_PowerBar),
	gsSPEndDisplayList(),
};

Gfx power_bar_material_revert_render_settings[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};

