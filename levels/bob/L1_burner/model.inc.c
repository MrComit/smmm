Lights1 L1_burner_Burner_001_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFE, 0xFE, 0xFE, 0x28, 0x28, 0x28);

Gfx L1_burner_oven_i8_aligner[] = {gsSPEndDisplayList()};
u8 L1_burner_oven_i8[] = {
	0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 
	0x4F, 0x4C, 0x3F, 0x31, 0x22, 0x12, 0x3, 0x3, 0x12, 
	0x22, 0x31, 0x3F, 0x4C, 0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 
	0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 
	0x4F, 0x4F, 0x4F, 0x4F, 0x46, 0x31, 0xC, 0x0, 0x0, 
	0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xC, 
	0x31, 0x46, 0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 
	0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 0x4C, 0x35, 
	0x5, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
	0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x5, 0x35, 0x4C, 
	0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 
	0x4F, 0x4F, 0x44, 0x27, 0x0, 0x0, 0x0, 0x0, 0x24, 
	0x39, 0x44, 0x4B, 0x4F, 0x4F, 0x4B, 0x44, 0x39, 0x24, 
	0x0, 0x0, 0x0, 0x0, 0x27, 0x44, 0x4F, 0x4F, 0x4F, 
	0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 0x41, 0x20, 0x0, 
	0x0, 0x0, 0x2C, 0x43, 0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 
	0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 0x43, 0x2C, 0x0, 0x0, 
	0x0, 0x20, 0x41, 0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 
	0x4F, 0x44, 0x20, 0x0, 0x0, 0x16, 0x3C, 0x4F, 0x4F, 
	0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 
	0x4F, 0x4F, 0x4F, 0x3C, 0x16, 0x0, 0x0, 0x20, 0x44, 
	0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 0x4C, 0x27, 0x0, 0x0, 
	0x21, 0x41, 0x4F, 0x4F, 0x4F, 0x4E, 0x3E, 0x2D, 0x19, 
	0x4, 0x4, 0x19, 0x2D, 0x3E, 0x4E, 0x4F, 0x4F, 0x4F, 
	0x41, 0x21, 0x0, 0x0, 0x27, 0x4C, 0x4F, 0x4F, 0x4F, 
	0x4F, 0x35, 0x0, 0x0, 0x16, 0x41, 0x4F, 0x4F, 0x4F, 
	0x3D, 0x1E, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
	0x0, 0x1E, 0x3D, 0x4F, 0x4F, 0x4F, 0x41, 0x16, 0x0, 
	0x0, 0x35, 0x4F, 0x4F, 0x4F, 0x46, 0x5, 0x0, 0x0, 
	0x3C, 0x4F, 0x4F, 0x4C, 0x34, 0x0, 0x0, 0x0, 0x0, 
	0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x34, 
	0x4C, 0x4F, 0x4F, 0x3C, 0x0, 0x0, 0x5, 0x46, 0x4F, 
	0x4F, 0x31, 0x0, 0x0, 0x2C, 0x4F, 0x4F, 0x4F, 0x34, 
	0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
	0x0, 0x0, 0x0, 0x0, 0x0, 0x34, 0x4F, 0x4F, 0x4F, 
	0x2C, 0x0, 0x0, 0x31, 0x4F, 0x4C, 0xC, 0x0, 0x0, 
	0x43, 0x4F, 0x4F, 0x3D, 0x0, 0x0, 0x0, 0x0, 0xC, 
	0x35, 0x46, 0x4E, 0x4E, 0x46, 0x35, 0xC, 0x0, 0x0, 
	0x0, 0x0, 0x3D, 0x4F, 0x4F, 0x43, 0x0, 0x0, 0xC, 
	0x4C, 0x3F, 0x0, 0x0, 0x24, 0x4F, 0x4F, 0x4E, 0x1E, 
	0x0, 0x0, 0x0, 0x26, 0x44, 0x4F, 0x4F, 0x4F, 0x4F, 
	0x4F, 0x4F, 0x44, 0x26, 0x0, 0x0, 0x0, 0x1E, 0x4E, 
	0x4F, 0x4F, 0x24, 0x0, 0x0, 0x3F, 0x31, 0x0, 0x0, 
	0x39, 0x4F, 0x4F, 0x3E, 0x0, 0x0, 0x0, 0xC, 0x44, 
	0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 0x44, 
	0xC, 0x0, 0x0, 0x0, 0x3E, 0x4F, 0x4F, 0x39, 0x0, 
	0x0, 0x31, 0x22, 0x0, 0x0, 0x44, 0x4F, 0x4F, 0x2D, 
	0x0, 0x0, 0x0, 0x35, 0x4F, 0x4F, 0x4A, 0x33, 0x12, 
	0x12, 0x33, 0x4A, 0x4F, 0x4F, 0x35, 0x0, 0x0, 0x0, 
	0x2D, 0x4F, 0x4F, 0x44, 0x0, 0x0, 0x22, 0x12, 0x0, 
	0x0, 0x4B, 0x4F, 0x4F, 0x19, 0x0, 0x0, 0x0, 0x46, 
	0x4F, 0x4F, 0x33, 0x0, 0x0, 0x0, 0x0, 0x33, 0x4F, 
	0x4F, 0x46, 0x0, 0x0, 0x0, 0x19, 0x4F, 0x4F, 0x4B, 
	0x0, 0x0, 0x12, 0x3, 0x0, 0x0, 0x4F, 0x4F, 0x4F, 
	0x4, 0x0, 0x0, 0x0, 0x4E, 0x4F, 0x4F, 0x12, 0x0, 
	0x0, 0x0, 0x0, 0x12, 0x4F, 0x4F, 0x4E, 0x0, 0x0, 
	0x0, 0x4, 0x4F, 0x4F, 0x4F, 0x0, 0x0, 0x3, 0x3, 
	0x0, 0x0, 0x4F, 0x4F, 0x4F, 0x4, 0x0, 0x0, 0x0, 
	0x4E, 0x4F, 0x4F, 0x12, 0x0, 0x0, 0x0, 0x0, 0x12, 
	0x4F, 0x4F, 0x4E, 0x0, 0x0, 0x0, 0x4, 0x4F, 0x4F, 
	0x4F, 0x0, 0x0, 0x3, 0x12, 0x0, 0x0, 0x4B, 0x4F, 
	0x4F, 0x19, 0x0, 0x0, 0x0, 0x46, 0x4F, 0x4F, 0x33, 
	0x0, 0x0, 0x0, 0x0, 0x33, 0x4F, 0x4F, 0x46, 0x0, 
	0x0, 0x0, 0x19, 0x4F, 0x4F, 0x4B, 0x0, 0x0, 0x12, 
	0x22, 0x0, 0x0, 0x44, 0x4F, 0x4F, 0x2D, 0x0, 0x0, 
	0x0, 0x35, 0x4F, 0x4F, 0x4A, 0x33, 0x12, 0x12, 0x33, 
	0x4A, 0x4F, 0x4F, 0x35, 0x0, 0x0, 0x0, 0x2D, 0x4F, 
	0x4F, 0x44, 0x0, 0x0, 0x22, 0x31, 0x0, 0x0, 0x39, 
	0x4F, 0x4F, 0x3E, 0x0, 0x0, 0x0, 0xC, 0x44, 0x4F, 
	0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 0x44, 0xC, 
	0x0, 0x0, 0x0, 0x3E, 0x4F, 0x4F, 0x39, 0x0, 0x0, 
	0x31, 0x3F, 0x0, 0x0, 0x24, 0x4F, 0x4F, 0x4E, 0x1E, 
	0x0, 0x0, 0x0, 0x26, 0x44, 0x4F, 0x4F, 0x4F, 0x4F, 
	0x4F, 0x4F, 0x44, 0x26, 0x0, 0x0, 0x0, 0x1E, 0x4E, 
	0x4F, 0x4F, 0x24, 0x0, 0x0, 0x3F, 0x4C, 0xC, 0x0, 
	0x0, 0x43, 0x4F, 0x4F, 0x3D, 0x0, 0x0, 0x0, 0x0, 
	0xC, 0x35, 0x46, 0x4E, 0x4E, 0x46, 0x35, 0xC, 0x0, 
	0x0, 0x0, 0x0, 0x3D, 0x4F, 0x4F, 0x43, 0x0, 0x0, 
	0xC, 0x4C, 0x4F, 0x31, 0x0, 0x0, 0x2C, 0x4F, 0x4F, 
	0x4F, 0x34, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
	0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x34, 0x4F, 
	0x4F, 0x4F, 0x2C, 0x0, 0x0, 0x31, 0x4F, 0x4F, 0x46, 
	0x5, 0x0, 0x0, 0x3C, 0x4F, 0x4F, 0x4C, 0x34, 0x0, 
	0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
	0x0, 0x0, 0x34, 0x4C, 0x4F, 0x4F, 0x3C, 0x0, 0x0, 
	0x5, 0x46, 0x4F, 0x4F, 0x4F, 0x35, 0x0, 0x0, 0x16, 
	0x41, 0x4F, 0x4F, 0x4F, 0x3D, 0x1E, 0x0, 0x0, 0x0, 
	0x0, 0x0, 0x0, 0x0, 0x0, 0x1E, 0x3D, 0x4F, 0x4F, 
	0x4F, 0x41, 0x16, 0x0, 0x0, 0x35, 0x4F, 0x4F, 0x4F, 
	0x4F, 0x4C, 0x27, 0x0, 0x0, 0x21, 0x41, 0x4F, 0x4F, 
	0x4F, 0x4E, 0x3E, 0x2D, 0x19, 0x4, 0x4, 0x19, 0x2D, 
	0x3E, 0x4E, 0x4F, 0x4F, 0x4F, 0x41, 0x21, 0x0, 0x0, 
	0x27, 0x4C, 0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 0x44, 0x20, 
	0x0, 0x0, 0x16, 0x3C, 0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 
	0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 
	0x3C, 0x16, 0x0, 0x0, 0x20, 0x44, 0x4F, 0x4F, 0x4F, 
	0x4F, 0x4F, 0x4F, 0x4F, 0x41, 0x20, 0x0, 0x0, 0x0, 
	0x2C, 0x43, 0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 
	0x4F, 0x4F, 0x4F, 0x43, 0x2C, 0x0, 0x0, 0x0, 0x20, 
	0x41, 0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 
	0x4F, 0x44, 0x27, 0x0, 0x0, 0x0, 0x0, 0x24, 0x39, 
	0x44, 0x4B, 0x4F, 0x4F, 0x4B, 0x44, 0x39, 0x24, 0x0, 
	0x0, 0x0, 0x0, 0x27, 0x44, 0x4F, 0x4F, 0x4F, 0x4F, 
	0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 0x4C, 0x35, 
	0x5, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
	0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x5, 0x35, 0x4C, 
	0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 
	0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 0x46, 0x31, 0xC, 0x0, 
	0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
	0xC, 0x31, 0x46, 0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 
	0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 
	0x4F, 0x4F, 0x4F, 0x4C, 0x3F, 0x31, 0x22, 0x12, 0x3, 
	0x3, 0x12, 0x22, 0x31, 0x3F, 0x4C, 0x4F, 0x4F, 0x4F, 
	0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 
};

Vtx L1_burner_Burner_001_mesh_vtx_0[16] = {
	{{{-150, -26, -150},0, {-16, 1008},{0xFF, 0x5F, 0x66, 0xFF}}},
	{{{150, -26, -150},0, {1008, 1008},{0xFF, 0x5F, 0x66, 0xFF}}},
	{{{150, -26, 150},0, {1008, -16},{0xFF, 0x5F, 0x66, 0xFF}}},
	{{{-150, -26, 150},0, {-16, -16},{0xFF, 0x5F, 0x66, 0xFF}}},
	{{{150, 26, -150},0, {-16, 1008},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{-150, 26, -150},0, {1008, 1008},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{-150, 26, 150},0, {1008, -16},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{150, 26, 150},0, {-16, -16},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{-150, -26, 150},0, {937, 939},{0xFF, 0x5F, 0x66, 0xFF}}},
	{{{-150, 26, 150},0, {937, 939},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{-150, 26, -150},0, {937, 939},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{150, -26, 150},0, {937, 939},{0xFF, 0x5F, 0x66, 0xFF}}},
	{{{150, 26, 150},0, {937, 939},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{150, -26, -150},0, {937, 939},{0xFF, 0x5F, 0x66, 0xFF}}},
	{{{150, 26, -150},0, {937, 939},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{-150, -26, -150},0, {937, 939},{0xFF, 0x5F, 0x66, 0xFF}}},
};

Gfx L1_burner_Burner_001_mesh_tri_0[] = {
	gsSPVertex(L1_burner_Burner_001_mesh_vtx_0 + 0, 16, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
	gsSP2Triangles(8, 9, 10, 0, 11, 9, 8, 0),
	gsSP2Triangles(11, 12, 9, 0, 13, 12, 11, 0),
	gsSP2Triangles(13, 14, 12, 0, 15, 14, 13, 0),
	gsSP2Triangles(15, 10, 14, 0, 8, 10, 15, 0),
	gsSPEndDisplayList(),
};


Gfx mat_L1_burner_Burner_001[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, ENVIRONMENT, 0, SHADE, 0, TEXEL0, 0, SHADE, 0, ENVIRONMENT, 0, SHADE, 0),
	gsSPClearGeometryMode(G_LIGHTING),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPTileSync(),
	gsDPSetTextureImage(G_IM_FMT_I, G_IM_SIZ_8b, 32, L1_burner_oven_i8),
	gsDPSetTile(G_IM_FMT_I, G_IM_SIZ_8b, 4, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPLoadSync(),
	gsDPLoadTile(7, 0, 0, 124, 124),
	gsDPPipeSync(),
	gsDPSetTile(G_IM_FMT_I, G_IM_SIZ_8b, 4, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPSetLights1(L1_burner_Burner_001_lights),
	gsSPEndDisplayList(),
};

Gfx mat_revert_L1_burner_Burner_001[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPEndDisplayList(),
};


Gfx L1_burner_Burner_001_mesh[] = {
	gsSPDisplayList(mat_L1_burner_Burner_001),
	gsSPDisplayList(L1_burner_Burner_001_mesh_tri_0),
	gsSPDisplayList(mat_revert_L1_burner_Burner_001),
	gsSPEndDisplayList(),
};



Gfx L1_burner_material_revert_render_settings[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};
