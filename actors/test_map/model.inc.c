Vtx test_map_TestMap_mesh_vtx_0[4] = {
	{{{-42, 17, 42}, 0, {61, 931}, {0xB2, 0xB2, 0xB2, 0xFF}}},
	{{{42, 17, 42}, 0, {931, 931}, {0xB2, 0xB2, 0xB2, 0xFF}}},
	{{{42, 17, -42}, 0, {931, 61}, {0xB2, 0xB2, 0xB2, 0xFF}}},
	{{{-42, 17, -42}, 0, {61, 61}, {0xB2, 0xB2, 0xB2, 0xFF}}},
};

Gfx test_map_TestMap_mesh_tri_0[] = {
	gsSPVertex(test_map_TestMap_mesh_vtx_0 + 0, 4, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSPEndDisplayList(),
};

Vtx test_map_TestMap_mesh_vtx_1[16] = {
	{{{50, 7, 50}, 0, {1008, 1008}, {0xB2, 0xB2, 0xB2, 0xB2}}},
	{{{50, 7, -50}, 0, {1008, -16}, {0xB2, 0xB2, 0xB2, 0xB2}}},
	{{{50, 17, -50}, 0, {1008, -16}, {0xB2, 0xB2, 0xB2, 0xB2}}},
	{{{-50, 17, -50}, 0, {-16, -16}, {0xB2, 0xB2, 0xB2, 0xB2}}},
	{{{-50, 7, -50}, 0, {-16, -16}, {0xB2, 0xB2, 0xB2, 0xB2}}},
	{{{-50, 17, 50}, 0, {-16, 1008}, {0xB2, 0xB2, 0xB2, 0xB2}}},
	{{{-50, 7, 50}, 0, {-16, 1008}, {0xB2, 0xB2, 0xB2, 0xB2}}},
	{{{50, 17, 50}, 0, {1008, 1008}, {0xB2, 0xB2, 0xB2, 0xB2}}},
	{{{-42, 17, 42}, 0, {61, 931}, {0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{-42, 17, -42}, 0, {61, 61}, {0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{-50, 17, -50}, 0, {-16, -16}, {0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{50, 17, -50}, 0, {1008, -16}, {0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{42, 17, -42}, 0, {931, 61}, {0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{50, 17, 50}, 0, {1008, 1008}, {0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{42, 17, 42}, 0, {931, 931}, {0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{-50, 17, 50}, 0, {-16, 1008}, {0xFF, 0xFF, 0xFF, 0xFF}}},
};

Gfx test_map_TestMap_mesh_tri_1[] = {
	gsSPVertex(test_map_TestMap_mesh_vtx_1 + 0, 16, 0),
	gsSP2Triangles(0, 1, 2, 0, 1, 3, 2, 0),
	gsSP2Triangles(1, 4, 3, 0, 4, 5, 3, 0),
	gsSP2Triangles(4, 6, 5, 0, 6, 7, 5, 0),
	gsSP2Triangles(6, 0, 7, 0, 0, 2, 7, 0),
	gsSP2Triangles(8, 9, 10, 0, 9, 11, 10, 0),
	gsSP2Triangles(9, 12, 11, 0, 12, 13, 11, 0),
	gsSP2Triangles(12, 14, 13, 0, 14, 15, 13, 0),
	gsSP2Triangles(14, 8, 15, 0, 8, 10, 15, 0),
	gsSPEndDisplayList(),
};

Gfx mat_test_map_Gray[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPGeometryMode(G_LIGHTING, 0),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPEndDisplayList(),
};

Gfx mat_revert_test_map_Gray[] = {
	gsDPPipeSync(),
	gsSPGeometryMode(0, G_LIGHTING),
	gsSPEndDisplayList(),
};

Gfx mat_test_map_Border_layer1[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(ENVIRONMENT, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, ENVIRONMENT, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsSPGeometryMode(G_LIGHTING, 0),
	gsDPSetRenderMode(G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPEndDisplayList(),
};

Gfx mat_revert_test_map_Border_layer1[] = {
	gsDPPipeSync(),
	gsSPGeometryMode(0, G_LIGHTING),
	gsDPSetRenderMode(G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2),
	gsSPEndDisplayList(),
};

Gfx test_map_TestMap_mesh[] = {
	gsSPDisplayList(mat_test_map_Gray),
	gsSPDisplayList(test_map_TestMap_mesh_tri_0),
	gsSPDisplayList(mat_revert_test_map_Gray),
	gsSPDisplayList(mat_test_map_Border_layer1),
	gsSPDisplayList(test_map_TestMap_mesh_tri_1),
	gsSPDisplayList(mat_revert_test_map_Border_layer1),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsSPEndDisplayList(),
};

