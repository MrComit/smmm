Vtx mirror_light_Light_mesh_layer_5_vtx_0[15] = {
	{{{-15, 100, 10},0, {-16, 1008},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{15, 100, 10},0, {1008, 1008},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{0, 100, -10},0, {-16, -16},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{15, 0, 10},0, {1008, 1008},{0x66, 0x0, 0xB4, 0xFF}}},
	{{{0, 0, -10},0, {-16, -16},{0x66, 0x0, 0xB4, 0xFF}}},
	{{{0, 100, -10},0, {-16, -16},{0x66, 0x0, 0xB4, 0xFF}}},
	{{{15, 100, 10},0, {1008, 1008},{0x66, 0x0, 0xB4, 0xFF}}},
	{{{-15, 0, 10},0, {-16, 1008},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{15, 0, 10},0, {1008, 1008},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{15, 100, 10},0, {1008, 1008},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-15, 100, 10},0, {-16, 1008},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{0, 0, -10},0, {-16, -16},{0x9A, 0x0, 0xB4, 0xFF}}},
	{{{-15, 0, 10},0, {-16, 1008},{0x9A, 0x0, 0xB4, 0xFF}}},
	{{{-15, 100, 10},0, {-16, 1008},{0x9A, 0x0, 0xB4, 0xFF}}},
	{{{0, 100, -10},0, {-16, -16},{0x9A, 0x0, 0xB4, 0xFF}}},
};

Gfx mirror_light_Light_mesh_layer_5_tri_0[] = {
	gsSPVertex(mirror_light_Light_mesh_layer_5_vtx_0 + 0, 15, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
	gsSP2Triangles(3, 5, 6, 0, 7, 8, 9, 0),
	gsSP2Triangles(7, 9, 10, 0, 11, 12, 13, 0),
	gsSP1Triangle(11, 13, 14, 0),
	gsSPEndDisplayList(),
};


Gfx mat_mirror_light_Light_001[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetEnvColor(254, 254, 0, 76),
	gsSPEndDisplayList(),
};

Gfx mirror_light_Light_mesh_layer_5[] = {
	gsSPDisplayList(mat_mirror_light_Light_001),
	gsSPDisplayList(mirror_light_Light_mesh_layer_5_tri_0),
	gsSPEndDisplayList(),
};

Gfx mirror_light_material_revert_render_settings[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};

