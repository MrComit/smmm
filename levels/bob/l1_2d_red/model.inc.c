Gfx l1_2d_red__2d_red_coin_ci4_aligner[] = {gsSPEndDisplayList()};
u8 l1_2d_red__2d_red_coin_ci4[] = {
	0x00, 0x00, 0x00, 0x12, 0x32, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x45, 0x67, 0x88, 0x79, 0x00, 0x00, 
	0x00, 0x04, 0xa6, 0x78, 0x88, 0x87, 0xb0, 0x00, 
	0x00, 0x44, 0x68, 0x88, 0xc5, 0x88, 0x7b, 0x00, 
	0x00, 0x4d, 0x76, 0x77, 0xda, 0x77, 0x77, 0x00, 
	0x04, 0x46, 0x66, 0xd7, 0x84, 0x57, 0x77, 0xb0, 
	0x04, 0xc6, 0x5e, 0xd7, 0x7d, 0xca, 0xcd, 0x70, 
	0x04, 0xd6, 0x86, 0x77, 0x77, 0x77, 0x68, 0x60, 
	0x04, 0xdd, 0x68, 0x66, 0x77, 0x79, 0x86, 0x60, 
	0x04, 0xd9, 0xd7, 0x66, 0x66, 0x5d, 0x66, 0x60, 
	0x04, 0xfb, 0xdd, 0x66, 0x66, 0xef, 0x96, 0x60, 
	0x04, 0x46, 0xdd, 0x67, 0x86, 0x5c, 0xd9, 0x60, 
	0x00, 0x49, 0xdd, 0x68, 0x77, 0x7c, 0xd6, 0x00, 
	0x00, 0x44, 0x79, 0x8d, 0xdd, 0xd6, 0xd7, 0x00, 
	0x00, 0x04, 0x47, 0x6d, 0xdd, 0xd7, 0x70, 0x00, 
	0x00, 0x00, 0x04, 0x58, 0x77, 0x70, 0x00, 0x00, 
	
};

Gfx l1_2d_red__2d_red_coin_ci4_pal_rgba16_aligner[] = {gsSPEndDisplayList()};
u8 l1_2d_red__2d_red_coin_ci4_pal_rgba16[] = {
	0x00, 0x00, 0x58, 0x43, 0x78, 0x43, 0xa8, 0x85, 
	0x18, 0x01, 0x68, 0x43, 0xb0, 0x85, 0xc0, 0x85, 
	0xe0, 0xc7, 0xa0, 0x85, 0x28, 0x01, 0x90, 0x85, 
	0x30, 0x43, 0x88, 0x85, 0x48, 0x43, 0x50, 0x43, 
	
};

Vtx l1_2d_red_2DRedCoin_mesh_layer_4_vtx_cull[8] = {
	{{ {-35, -35, 0}, 0, {-16, -16}, {0, 0, 0, 0} }},
	{{ {-35, 35, 0}, 0, {-16, -16}, {0, 0, 0, 0} }},
	{{ {-35, 35, 0}, 0, {-16, -16}, {0, 0, 0, 0} }},
	{{ {-35, -35, 0}, 0, {-16, -16}, {0, 0, 0, 0} }},
	{{ {35, -35, 0}, 0, {-16, -16}, {0, 0, 0, 0} }},
	{{ {35, 35, 0}, 0, {-16, -16}, {0, 0, 0, 0} }},
	{{ {35, 35, 0}, 0, {-16, -16}, {0, 0, 0, 0} }},
	{{ {35, -35, 0}, 0, {-16, -16}, {0, 0, 0, 0} }},
};

Vtx l1_2d_red_2DRedCoin_mesh_layer_4_vtx_0[4] = {
	{{ {-35, -35, 0}, 0, {0, 512}, {255, 255, 255, 126} }},
	{{ {35, -35, 0}, 0, {512, 512}, {255, 255, 255, 126} }},
	{{ {35, 35, 0}, 0, {512, 0}, {255, 255, 255, 126} }},
	{{ {-35, 35, 0}, 0, {0, 0}, {255, 255, 255, 126} }},
};

Gfx l1_2d_red_2DRedCoin_mesh_layer_4_tri_0[] = {
	gsSPVertex(l1_2d_red_2DRedCoin_mesh_layer_4_vtx_0 + 0, 4, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSPEndDisplayList(),
};


Gfx mat_l1_2d_red__2DRed[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, TEXEL0, TEXEL0, 0, SHADE, 0, 0, 0, 0, TEXEL0),
	gsSPGeometryMode(G_LIGHTING, 0),
	gsDPSetTextureFilter(G_TF_POINT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetTextureLUT(G_TT_RGBA16),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, l1_2d_red__2d_red_coin_ci4_pal_rgba16),
	gsDPSetTile(0, 0, 0, 256, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadTLUTCmd(7, 15),
	gsDPLoadSync(),
	gsDPSetTextureImage(G_IM_FMT_CI, G_IM_SIZ_16b, 1, l1_2d_red__2d_red_coin_ci4),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_16b, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 4, 0, G_TX_WRAP | G_TX_NOMIRROR, 4, 0),
	gsDPLoadBlock(7, 0, 0, 63, 2048),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_4b, 1, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 4, 0, G_TX_WRAP | G_TX_NOMIRROR, 4, 0),
	gsDPSetTileSize(0, 0, 0, 60, 60),
	gsSPEndDisplayList(),
};

Gfx mat_revert_l1_2d_red__2DRed[] = {
	gsDPPipeSync(),
	gsSPGeometryMode(0, G_LIGHTING),
	gsDPSetTextureFilter(G_TF_BILERP),
	gsDPSetTextureLUT(G_TT_NONE),
	gsSPEndDisplayList(),
};

Gfx l1_2d_red_2DRedCoin_mesh_layer_4[] = {
	gsSPClearGeometryMode(G_LIGHTING),
	gsSPVertex(l1_2d_red_2DRedCoin_mesh_layer_4_vtx_cull + 0, 8, 0),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPCullDisplayList(0, 7),
	gsSPDisplayList(mat_l1_2d_red__2DRed),
	gsSPDisplayList(l1_2d_red_2DRedCoin_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_l1_2d_red__2DRed),
	gsSPEndDisplayList(),
};

Gfx l1_2d_red_material_revert_render_settings[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};

