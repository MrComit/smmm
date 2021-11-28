Lights1 horizontal_pole_Band_001_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFE, 0xFE, 0xFE, 0x28, 0x28, 0x28);

Lights1 horizontal_pole_Pole_001_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFE, 0xFE, 0xFE, 0x28, 0x28, 0x28);

Vtx horizontal_pole_HorizontalPole_mesh_layer_1_vtx_cull[8] = {
	{{{-296, -250, 32},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{-296, 150, 32},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{-296, 150, -32},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{-296, -250, -32},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{296, -250, 32},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{296, 150, 32},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{296, 150, -32},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{296, -250, -32},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
};

Vtx horizontal_pole_HorizontalPole_mesh_layer_1_vtx_0[20] = {
	{{{-250, 0, 11},0, {1008, 1008},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-250, 20, 16},0, {-16, 1008},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-250, 33, 0},0, {-16, 496},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-250, 0, -11},0, {1008, -16},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-250, 20, -16},0, {-16, -16},{0x81, 0x0, 0x0, 0xFF}}},
	{{{250, 33, 0},0, {-16, 496},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{250, 20, 16},0, {-16, 1008},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{250, 0, 11},0, {1008, 1008},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{250, 20, -16},0, {-16, -16},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{250, 0, -11},0, {1008, -16},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{-250, 0, -11},0, {1008, -16},{0xB5, 0xAF, 0xC1, 0xFF}}},
	{{{-250, 20, -16},0, {-16, -16},{0xB3, 0x20, 0xA0, 0xFF}}},
	{{{250, 20, -16},0, {-16, -16},{0x4D, 0x20, 0xA0, 0xFF}}},
	{{{250, 33, 0},0, {-16, 496},{0x4B, 0x67, 0x0, 0xFF}}},
	{{{-250, 33, 0},0, {-16, 496},{0xB5, 0x67, 0x0, 0xFF}}},
	{{{250, 20, 16},0, {-16, 1008},{0x4D, 0x20, 0x60, 0xFF}}},
	{{{-250, 20, 16},0, {-16, 1008},{0xB3, 0x20, 0x60, 0xFF}}},
	{{{250, 0, 11},0, {1008, 1008},{0x4B, 0xAF, 0x3F, 0xFF}}},
	{{{-250, 0, 11},0, {1008, 1008},{0xB5, 0xAF, 0x3F, 0xFF}}},
	{{{250, 0, -11},0, {1008, -16},{0x4B, 0xAF, 0xC1, 0xFF}}},
};

Gfx horizontal_pole_HorizontalPole_mesh_layer_1_tri_0[] = {
	gsSPVertex(horizontal_pole_HorizontalPole_mesh_layer_1_vtx_0 + 0, 20, 0),
	gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
	gsSP2Triangles(2, 4, 3, 0, 5, 6, 7, 0),
	gsSP2Triangles(7, 8, 5, 0, 7, 9, 8, 0),
	gsSP2Triangles(10, 11, 12, 0, 11, 13, 12, 0),
	gsSP2Triangles(11, 14, 13, 0, 14, 15, 13, 0),
	gsSP2Triangles(14, 16, 15, 0, 16, 17, 15, 0),
	gsSP2Triangles(16, 18, 17, 0, 18, 19, 17, 0),
	gsSP2Triangles(18, 10, 19, 0, 10, 12, 19, 0),
	gsSPEndDisplayList(),
};

Vtx horizontal_pole_HorizontalPole_mesh_layer_1_vtx_1[22] = {
	{{{-230, 120, 22},0, {1008, -16},{0x5D, 0x30, 0x48, 0xFF}}},
	{{{-271, -250, 32},0, {-16, -16},{0xD8, 0x0, 0x79, 0xFF}}},
	{{{-230, -250, 22},0, {1008, -16},{0x65, 0x0, 0x4E, 0xFF}}},
	{{{-271, 120, 32},0, {-16, -16},{0xDB, 0x2E, 0x70, 0xFF}}},
	{{{-260, 150, 0},0, {523, 496},{0xFF, 0x7F, 0x0, 0xFF}}},
	{{{-230, 120, -22},0, {1008, 1008},{0x5D, 0x30, 0xB8, 0xFF}}},
	{{{-230, -250, -22},0, {1008, 1008},{0x65, 0x0, 0xB2, 0xFF}}},
	{{{-271, 120, -32},0, {-16, 1008},{0xDB, 0x2E, 0x90, 0xFF}}},
	{{{-271, -250, -32},0, {-16, 1008},{0xD8, 0x0, 0x87, 0xFF}}},
	{{{-296, 120, 0},0, {-16, 496},{0x8A, 0x2F, 0x0, 0xFF}}},
	{{{-296, -250, 0},0, {-16, 496},{0x81, 0x0, 0x0, 0xFF}}},
	{{{230, 120, -22},0, {1008, -16},{0xA3, 0x30, 0xB8, 0xFF}}},
	{{{271, -250, -32},0, {-16, -16},{0x28, 0x0, 0x87, 0xFF}}},
	{{{230, -250, -22},0, {1008, -16},{0x9B, 0x0, 0xB2, 0xFF}}},
	{{{271, 120, -32},0, {-16, -16},{0x25, 0x2E, 0x90, 0xFF}}},
	{{{260, 150, 0},0, {523, 496},{0x1, 0x7F, 0x0, 0xFF}}},
	{{{230, 120, 22},0, {1008, 1008},{0xA3, 0x30, 0x48, 0xFF}}},
	{{{230, -250, 22},0, {1008, 1008},{0x9B, 0x0, 0x4E, 0xFF}}},
	{{{271, 120, 32},0, {-16, 1008},{0x25, 0x2E, 0x70, 0xFF}}},
	{{{271, -250, 32},0, {-16, 1008},{0x28, 0x0, 0x79, 0xFF}}},
	{{{296, 120, 0},0, {-16, 496},{0x76, 0x2F, 0x0, 0xFF}}},
	{{{296, -250, 0},0, {-16, 496},{0x7F, 0x0, 0x0, 0xFF}}},
};

Gfx horizontal_pole_HorizontalPole_mesh_layer_1_tri_1[] = {
	gsSPVertex(horizontal_pole_HorizontalPole_mesh_layer_1_vtx_1 + 0, 22, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
	gsSP2Triangles(3, 0, 4, 0, 0, 5, 4, 0),
	gsSP2Triangles(5, 0, 2, 0, 5, 2, 6, 0),
	gsSP2Triangles(7, 5, 6, 0, 7, 6, 8, 0),
	gsSP2Triangles(9, 7, 8, 0, 9, 8, 10, 0),
	gsSP2Triangles(3, 9, 10, 0, 3, 10, 1, 0),
	gsSP2Triangles(9, 3, 4, 0, 7, 9, 4, 0),
	gsSP2Triangles(5, 7, 4, 0, 11, 12, 13, 0),
	gsSP2Triangles(11, 14, 12, 0, 14, 11, 15, 0),
	gsSP2Triangles(11, 16, 15, 0, 16, 11, 13, 0),
	gsSP2Triangles(16, 13, 17, 0, 18, 16, 17, 0),
	gsSP2Triangles(18, 17, 19, 0, 20, 18, 19, 0),
	gsSP2Triangles(20, 19, 21, 0, 14, 20, 21, 0),
	gsSP2Triangles(14, 21, 12, 0, 20, 14, 15, 0),
	gsSP2Triangles(18, 20, 15, 0, 16, 18, 15, 0),
	gsSPEndDisplayList(),
};


Gfx mat_horizontal_pole_Band_001[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(ENVIRONMENT, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, ENVIRONMENT, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetEnvColor(155, 113, 79, 255),
	gsSPSetLights1(horizontal_pole_Band_001_lights),
	gsSPEndDisplayList(),
};

Gfx mat_horizontal_pole_Pole_001[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(ENVIRONMENT, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, ENVIRONMENT, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetEnvColor(124, 53, 33, 255),
	gsSPSetLights1(horizontal_pole_Pole_001_lights),
	gsSPEndDisplayList(),
};

Gfx horizontal_pole_HorizontalPole_mesh_layer_1[] = {
	gsSPClearGeometryMode(G_LIGHTING),
	gsSPVertex(horizontal_pole_HorizontalPole_mesh_layer_1_vtx_cull + 0, 8, 0),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPCullDisplayList(0, 7),
	gsSPDisplayList(mat_horizontal_pole_Band_001),
	gsSPDisplayList(horizontal_pole_HorizontalPole_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_horizontal_pole_Pole_001),
	gsSPDisplayList(horizontal_pole_HorizontalPole_mesh_layer_1_tri_1),
	gsSPEndDisplayList(),
};

Gfx horizontal_pole_material_revert_render_settings[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};

