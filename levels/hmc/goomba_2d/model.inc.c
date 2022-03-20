Gfx goomba_2d_goomba_sprite_ci4_aligner[] = {gsSPEndDisplayList()};
u8 goomba_2d_goomba_sprite_ci4[] = {
	0x00, 0x00, 0x00, 0x11, 0x11, 0x22, 0x22, 0x22, 
	0x00, 0x00, 0x01, 0x11, 0x11, 0x12, 0x22, 0x22, 
	0x00, 0x00, 0x11, 0x11, 0x11, 0x11, 0x22, 0x22, 
	0x00, 0x01, 0x11, 0x11, 0x11, 0x11, 0x12, 0x22, 
	0x00, 0x13, 0x31, 0x11, 0x11, 0x13, 0x31, 0x22, 
	0x01, 0x11, 0x43, 0x11, 0x11, 0x34, 0x11, 0x12, 
	0x01, 0x11, 0x43, 0x33, 0x33, 0x34, 0x11, 0x12, 
	0x11, 0x11, 0x43, 0x41, 0x14, 0x34, 0x11, 0x11, 
	0x11, 0x11, 0x44, 0x41, 0x14, 0x44, 0x11, 0x11, 
	0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 
	0x21, 0x11, 0x14, 0x44, 0x44, 0x41, 0x11, 0x12, 
	0x22, 0x22, 0x44, 0x44, 0x44, 0x44, 0x22, 0x22, 
	0x22, 0x22, 0x44, 0x44, 0x44, 0x44, 0x33, 0x22, 
	0x22, 0x23, 0x34, 0x44, 0x44, 0x33, 0x33, 0x32, 
	0x22, 0x23, 0x33, 0x44, 0x43, 0x33, 0x33, 0x32, 
	0x22, 0x22, 0x33, 0x32, 0x23, 0x33, 0x33, 0x22, 
	
};

Gfx goomba_2d_goomba_sprite_ci4_pal_rgba16_aligner[] = {gsSPEndDisplayList()};
u8 goomba_2d_goomba_sprite_ci4_pal_rgba16[] = {
	0xff, 0xfe, 0x9a, 0x41, 0x94, 0xbe, 0x00, 0x01, 
	0xfe, 0x71, 
};

Vtx goomba_2d_goomba_mesh_layer_4_vtx_0[4] = {
	{{{0, 0, 50},0, {512, 512},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{0, 0, -50},0, {1024, 512},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{0, 100, -50},0, {1024, 15},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{0, 100, 50},0, {512, 15},{0x7F, 0x0, 0x0, 0xFF}}},
};

Gfx goomba_2d_goomba_mesh_layer_4_tri_0[] = {
	gsSPVertex(goomba_2d_goomba_mesh_layer_4_vtx_0 + 0, 4, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSPEndDisplayList(),
};


Gfx mat_goomba_2d_Goomba[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, TEXEL0, 0, 0, 0, TEXEL0, 0, 0, 0, TEXEL0, 0, 0, 0, TEXEL0),
	gsDPSetTextureFilter(G_TF_POINT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetTextureLUT(G_TT_RGBA16),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, goomba_2d_goomba_sprite_ci4_pal_rgba16),
	gsDPTileSync(),
	gsDPSetTile(0, 0, 0, 256, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadSync(),
	gsDPLoadTLUTCmd(7, 4),
	gsDPPipeSync(),
	gsDPTileSync(),
	gsDPSetTextureImage(G_IM_FMT_CI, G_IM_SIZ_16b, 1, goomba_2d_goomba_sprite_ci4),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_16b, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 4, 0, G_TX_WRAP | G_TX_NOMIRROR, 4, 0),
	gsDPLoadSync(),
	gsDPLoadBlock(7, 0, 0, 63, 2048),
	gsDPPipeSync(),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_4b, 1, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 4, 0, G_TX_WRAP | G_TX_NOMIRROR, 4, 0),
	gsDPSetTileSize(0, 0, 0, 60, 60),
	gsSPEndDisplayList(),
};

Gfx mat_revert_goomba_2d_Goomba[] = {
	gsDPPipeSync(),
	gsDPSetTextureFilter(G_TF_BILERP),
	gsDPSetTextureLUT(G_TT_NONE),
	gsSPEndDisplayList(),
};

Gfx mat_goomba_2d_Goomba2[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, TEXEL0, 0, 0, 0, TEXEL0, 0, 0, 0, TEXEL0, 0, 0, 0, TEXEL0),
	gsDPSetTextureFilter(G_TF_POINT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetTextureLUT(G_TT_RGBA16),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, goomba_2d_goomba_sprite_ci4_pal_rgba16),
	gsDPTileSync(),
	gsDPSetTile(0, 0, 0, 256, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadSync(),
	gsDPLoadTLUTCmd(7, 4),
	gsDPPipeSync(),
	gsDPTileSync(),
	gsDPSetTextureImage(G_IM_FMT_CI, G_IM_SIZ_16b, 1, goomba_2d_goomba_sprite_ci4),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_16b, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 4, 0, G_TX_WRAP | G_TX_MIRROR, 4, 0),
	gsDPLoadSync(),
	gsDPLoadBlock(7, 0, 0, 63, 2048),
	gsDPPipeSync(),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_4b, 1, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 4, 0, G_TX_WRAP | G_TX_MIRROR, 4, 0),
	gsDPSetTileSize(0, 0, 0, 60, 60),
	gsSPEndDisplayList(),
};

Gfx mat_revert_goomba_2d_Goomba2[] = {
	gsDPPipeSync(),
	gsDPSetTextureFilter(G_TF_BILERP),
	gsDPSetTextureLUT(G_TT_NONE),
	gsSPEndDisplayList(),
};

Gfx goomba_2d_goomba_mesh_layer_4[] = {
	gsSPDisplayList(mat_goomba_2d_Goomba),
	gsSPDisplayList(goomba_2d_goomba_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_goomba_2d_Goomba),
	gsSPEndDisplayList(),
};

Gfx goomba_2d_goomba_mesh_layer_4_mat_override_Goomba2_0[] = {
	gsSPDisplayList(mat_goomba_2d_Goomba2),
	gsSPDisplayList(goomba_2d_goomba_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_goomba_2d_Goomba2),
	gsSPEndDisplayList(),
};

Gfx goomba_2d_material_revert_render_settings[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};

