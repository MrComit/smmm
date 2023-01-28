Vtx bottled_lava_BottledLava_001_mesh_layer_1_vtx_cull[8] = {
	{{{-267, 0, 267}, 0, {-16, -16}, {0x0, 0x0, 0x0, 0x0}}},
	{{{-267, 10, 267}, 0, {-16, -16}, {0x0, 0x0, 0x0, 0x0}}},
	{{{-267, 10, -267}, 0, {-16, -16}, {0x0, 0x0, 0x0, 0x0}}},
	{{{-267, 0, -267}, 0, {-16, -16}, {0x0, 0x0, 0x0, 0x0}}},
	{{{267, 0, 267}, 0, {-16, -16}, {0x0, 0x0, 0x0, 0x0}}},
	{{{267, 10, 267}, 0, {-16, -16}, {0x0, 0x0, 0x0, 0x0}}},
	{{{267, 10, -267}, 0, {-16, -16}, {0x0, 0x0, 0x0, 0x0}}},
	{{{267, 0, -267}, 0, {-16, -16}, {0x0, 0x0, 0x0, 0x0}}},
};

Vtx bottled_lava_BottledLava_001_mesh_layer_1_vtx_0[24] = {
	{{{267, 0, 71}, 0, {-166, -166}, {0x0, 0x81, 0x0, 0xFF}}},
	{{{-71, 0, 267}, 0, {1158, -166}, {0x0, 0x81, 0x0, 0xFF}}},
	{{{-267, 0, -71}, 0, {1158, 1158}, {0x0, 0x81, 0x0, 0xFF}}},
	{{{71, 0, -267}, 0, {-166, 1158}, {0x0, 0x81, 0x0, 0xFF}}},
	{{{267, 10, 71}, 0, {-166, -166}, {0x0, 0x7F, 0x0, 0xFF}}},
	{{{71, 10, -267}, 0, {-166, 1158}, {0x0, 0x7F, 0x0, 0xFF}}},
	{{{-267, 10, -71}, 0, {1158, 1158}, {0x0, 0x7F, 0x0, 0xFF}}},
	{{{-71, 10, 267}, 0, {1158, -166}, {0x0, 0x7F, 0x0, 0xFF}}},
	{{{267, 0, 71}, 0, {-166, -166}, {0x3F, 0x0, 0x6E, 0xFF}}},
	{{{267, 10, 71}, 0, {-166, -166}, {0x3F, 0x0, 0x6E, 0xFF}}},
	{{{-71, 10, 267}, 0, {1158, -166}, {0x3F, 0x0, 0x6E, 0xFF}}},
	{{{-71, 0, 267}, 0, {1158, -166}, {0x3F, 0x0, 0x6E, 0xFF}}},
	{{{-267, 0, -71}, 0, {1158, 1158}, {0xC1, 0x0, 0x92, 0xFF}}},
	{{{-267, 10, -71}, 0, {1158, 1158}, {0xC1, 0x0, 0x92, 0xFF}}},
	{{{71, 10, -267}, 0, {-166, 1158}, {0xC1, 0x0, 0x92, 0xFF}}},
	{{{71, 0, -267}, 0, {-166, 1158}, {0xC1, 0x0, 0x92, 0xFF}}},
	{{{-71, 0, 267}, 0, {1158, -166}, {0x92, 0x0, 0x40, 0xFF}}},
	{{{-71, 10, 267}, 0, {1158, -166}, {0x92, 0x0, 0x40, 0xFF}}},
	{{{-267, 10, -71}, 0, {1158, 1158}, {0x92, 0x0, 0x40, 0xFF}}},
	{{{-267, 0, -71}, 0, {1158, 1158}, {0x92, 0x0, 0x40, 0xFF}}},
	{{{71, 0, -267}, 0, {-166, 1158}, {0x6E, 0x0, 0xC1, 0xFF}}},
	{{{71, 10, -267}, 0, {-166, 1158}, {0x6E, 0x0, 0xC1, 0xFF}}},
	{{{267, 10, 71}, 0, {-166, -166}, {0x6E, 0x0, 0xC1, 0xFF}}},
	{{{267, 0, 71}, 0, {-166, -166}, {0x6E, 0x0, 0xC1, 0xFF}}},
};

Gfx bottled_lava_BottledLava_001_mesh_layer_1_tri_0[] = {
	gsSPVertex(bottled_lava_BottledLava_001_mesh_layer_1_vtx_0 + 0, 24, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
	gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
	gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
	gsSP2Triangles(16, 17, 18, 0, 16, 18, 19, 0),
	gsSP2Triangles(20, 21, 22, 0, 20, 22, 23, 0),
	gsSPEndDisplayList(),
};


Gfx mat_bottled_lava_PinkLava[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetEnvColor(201, 82, 120, 255),
	gsSPEndDisplayList(),
};

Gfx bottled_lava_BottledLava_001_mesh_layer_1[] = {
	gsSPClearGeometryMode(G_LIGHTING),
	gsSPVertex(bottled_lava_BottledLava_001_mesh_layer_1_vtx_cull + 0, 8, 0),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPCullDisplayList(0, 7),
	gsSPDisplayList(mat_bottled_lava_PinkLava),
	gsSPDisplayList(bottled_lava_BottledLava_001_mesh_layer_1_tri_0),
	gsSPEndDisplayList(),
};

Gfx bottled_lava_material_revert_render_settings[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};

