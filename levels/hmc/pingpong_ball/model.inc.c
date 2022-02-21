Lights1 pingpong_ball_Ball_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFE, 0xFE, 0xFE, 0x28, 0x28, 0x28);

Vtx pingpong_ball_Ball_002_mesh_layer_1_vtx_cull[8] = {
	{{{-9, 0, 11},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{-9, 18, 11},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{-9, 18, -11},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{-9, 0, -11},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{9, 0, 11},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{9, 18, 11},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{9, 18, -11},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{9, 0, -11},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
};

Vtx pingpong_ball_Ball_002_mesh_layer_1_vtx_0[28] = {
	{{{8, 15, 5},0, {-1382, -165},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{3, 18, -5},0, {-855, -999},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{-3, 18, 5},0, {-1859, -1050},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{3, 18, -5},0, {-919, -615},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{-8, 15, -5},0, {-1377, -1499},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{-3, 18, 5},0, {-1923, -666},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{9, 9, -5},0, {-429, 409},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{3, 18, -5},0, {-1077, -488},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{8, 15, 5},0, {-1439, 12},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{8, 3, 5},0, {-723, 1126},{0xE6, 0xE6, 0xE6, 0xFF}}},
	{{{3, 0, -5},0, {231, 1315},{0xCC, 0xCC, 0xCC, 0xFF}}},
	{{{0, 9, -11},0, {524, 408},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{-8, 3, -5},0, {1296, 968},{0xE6, 0xE6, 0xE6, 0xFF}}},
	{{{-8, 15, -5},0, {1295, -153},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{-9, 9, 5},0, {2067, 647},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{-3, 0, 5},0, {2215, 1476},{0xCC, 0xCC, 0xCC, 0xFF}}},
	{{{-3, 18, 5},0, {2214, -367},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{3, 18, -5},0, {229, -498},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{3, 0, -5},0, {1068, 2093},{0xCC, 0xCC, 0xCC, 0xFF}}},
	{{{-3, 0, 5},0, {1986, 1728},{0xCC, 0xCC, 0xCC, 0xFF}}},
	{{{-8, 3, -5},0, {1168, 1111},{0xE6, 0xE6, 0xE6, 0xFF}}},
	{{{8, 3, 5},0, {1851, 2724},{0xE6, 0xE6, 0xE6, 0xFF}}},
	{{{-3, 0, 5},0, {215, 1492},{0xCC, 0xCC, 0xCC, 0xFF}}},
	{{{0, 9, 11},0, {500, 582},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{-9, 9, 5},0, {-453, 592},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{8, 3, 5},0, {1277, 1135},{0xE6, 0xE6, 0xE6, 0xFF}}},
	{{{8, 15, 5},0, {1266, 14},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{-3, 18, 5},0, {196, -321},{0xFF, 0xFF, 0xFF, 0xFF}}},
};

Gfx pingpong_ball_Ball_002_mesh_layer_1_tri_0[] = {
	gsSPVertex(pingpong_ball_Ball_002_mesh_layer_1_vtx_0 + 0, 28, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
	gsSP2Triangles(6, 7, 8, 0, 9, 6, 8, 0),
	gsSP2Triangles(10, 6, 9, 0, 6, 10, 11, 0),
	gsSP2Triangles(10, 12, 11, 0, 11, 12, 13, 0),
	gsSP2Triangles(12, 14, 13, 0, 12, 15, 14, 0),
	gsSP2Triangles(13, 14, 16, 0, 11, 13, 17, 0),
	gsSP2Triangles(6, 11, 17, 0, 18, 19, 20, 0),
	gsSP2Triangles(18, 21, 19, 0, 22, 23, 24, 0),
	gsSP2Triangles(22, 25, 23, 0, 25, 26, 23, 0),
	gsSP2Triangles(23, 26, 27, 0, 24, 23, 27, 0),
	gsSPEndDisplayList(),
};


Gfx mat_pingpong_ball_Ball[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(ENVIRONMENT, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, ENVIRONMENT, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsSPClearGeometryMode(G_LIGHTING),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetEnvColor(254, 169, 0, 255),
	gsSPSetLights1(pingpong_ball_Ball_lights),
	gsSPEndDisplayList(),
};

Gfx mat_revert_pingpong_ball_Ball[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPEndDisplayList(),
};

Gfx pingpong_ball_Ball_002_mesh_layer_1[] = {
	gsSPClearGeometryMode(G_LIGHTING),
	gsSPVertex(pingpong_ball_Ball_002_mesh_layer_1_vtx_cull + 0, 8, 0),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPCullDisplayList(0, 7),
	gsSPDisplayList(mat_pingpong_ball_Ball),
	gsSPDisplayList(pingpong_ball_Ball_002_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_pingpong_ball_Ball),
	gsSPEndDisplayList(),
};

Gfx pingpong_ball_material_revert_render_settings[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};

