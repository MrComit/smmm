Vtx hammer_ham_mesh_layer_1_vtx_0[24] = {
	{{{-9, -45, 9}, 0, {368, 1008}, {0xD9, 0x9D, 0x1, 0xFF}}},
	{{{-9, 9, 9}, 0, {624, 1008}, {0xFF, 0xB9, 0x1, 0xFF}}},
	{{{-9, 9, -9}, 0, {624, 752}, {0xFF, 0xB9, 0x1, 0xFF}}},
	{{{-9, -45, -9}, 0, {368, 752}, {0xD9, 0x9D, 0x1, 0xFF}}},
	{{{9, 9, -9}, 0, {624, 496}, {0xFF, 0xB9, 0x1, 0xFF}}},
	{{{9, -45, -9}, 0, {368, 496}, {0xD9, 0x9D, 0x1, 0xFF}}},
	{{{9, 9, 9}, 0, {624, 240}, {0xFF, 0xB9, 0x1, 0xFF}}},
	{{{9, -45, 9}, 0, {368, 240}, {0xD9, 0x9D, 0x1, 0xFF}}},
	{{{-9, 9, 9}, 0, {624, -16}, {0xFF, 0xB9, 0x1, 0xFF}}},
	{{{-9, -45, 9}, 0, {368, -16}, {0xD9, 0x9D, 0x1, 0xFF}}},
	{{{-9, -45, -9}, 0, {112, 496}, {0xD9, 0x9D, 0x1, 0xFF}}},
	{{{-9, -45, 9}, 0, {112, 240}, {0xD9, 0x9D, 0x1, 0xFF}}},
	{{{-14, 9, 27}, 0, {624, -16}, {0x7C, 0x88, 0x8A, 0xFF}}},
	{{{14, 27, 27}, 0, {624, 240}, {0x8D, 0x9A, 0x9D, 0xFF}}},
	{{{-14, 27, 27}, 0, {624, -16}, {0x8D, 0x9A, 0x9D, 0xFF}}},
	{{{14, 9, 27}, 0, {624, 240}, {0x7C, 0x88, 0x8A, 0xFF}}},
	{{{-14, 9, -27}, 0, {624, 752}, {0x7C, 0x88, 0x8A, 0xFF}}},
	{{{14, 9, -27}, 0, {624, 496}, {0x7C, 0x88, 0x8A, 0xFF}}},
	{{{-14, 27, -27}, 0, {624, 752}, {0x8D, 0x9A, 0x9D, 0xFF}}},
	{{{-14, 27, 27}, 0, {624, 1008}, {0x8D, 0x9A, 0x9D, 0xFF}}},
	{{{-14, 9, 27}, 0, {624, 1008}, {0x7C, 0x88, 0x8A, 0xFF}}},
	{{{14, 27, -27}, 0, {624, 496}, {0x8D, 0x9A, 0x9D, 0xFF}}},
	{{{-14, 27, -27}, 0, {880, 496}, {0x8D, 0x9A, 0x9D, 0xFF}}},
	{{{-14, 27, 27}, 0, {880, 240}, {0x8D, 0x9A, 0x9D, 0xFF}}},
};

Gfx hammer_ham_mesh_layer_1_tri_0[] = {
	gsSPVertex(hammer_ham_mesh_layer_1_vtx_0 + 0, 24, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSP2Triangles(3, 2, 4, 0, 3, 4, 5, 0),
	gsSP2Triangles(5, 4, 6, 0, 5, 6, 7, 0),
	gsSP2Triangles(7, 6, 8, 0, 7, 8, 9, 0),
	gsSP2Triangles(10, 5, 7, 0, 10, 7, 11, 0),
	gsSP2Triangles(12, 13, 14, 0, 12, 15, 13, 0),
	gsSP2Triangles(16, 15, 12, 0, 16, 17, 15, 0),
	gsSP2Triangles(17, 16, 18, 0, 16, 19, 18, 0),
	gsSP2Triangles(16, 20, 19, 0, 17, 18, 21, 0),
	gsSP2Triangles(17, 21, 13, 0, 13, 21, 22, 0),
	gsSP2Triangles(13, 22, 23, 0, 17, 13, 15, 0),
	gsSPEndDisplayList(),
};


Gfx mat_hammer_VertColSolid_001[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPGeometryMode(G_LIGHTING, 0),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPEndDisplayList(),
};

Gfx mat_revert_hammer_VertColSolid_001[] = {
	gsDPPipeSync(),
	gsSPGeometryMode(0, G_LIGHTING),
	gsSPEndDisplayList(),
};

Gfx hammer_ham_mesh_layer_1[] = {
	gsSPDisplayList(mat_hammer_VertColSolid_001),
	gsSPDisplayList(hammer_ham_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_hammer_VertColSolid_001),
	gsSPEndDisplayList(),
};

Gfx hammer_material_revert_render_settings[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};

