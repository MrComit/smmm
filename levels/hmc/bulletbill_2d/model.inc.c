Gfx bulletbill_2d_bulletbill_sprite_ci4_aligner[] = {gsSPEndDisplayList()};
u8 bulletbill_2d_bulletbill_sprite_ci4[] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x11, 0x11, 0x11, 0x10, 0x11, 
	0x00, 0x00, 0x11, 0x12, 0x22, 0x22, 0x10, 0x22, 
	0x00, 0x01, 0x11, 0x21, 0x11, 0x11, 0x13, 0x11, 
	0x00, 0x12, 0x11, 0x11, 0x11, 0x11, 0x12, 0x11, 
	0x01, 0x22, 0x11, 0x11, 0x11, 0x11, 0x13, 0x11, 
	0x12, 0x12, 0x11, 0x11, 0x13, 0x31, 0x13, 0x11, 
	0x11, 0x21, 0x11, 0x12, 0x12, 0x23, 0x13, 0x11, 
	0x11, 0x11, 0x12, 0x22, 0x22, 0x23, 0x13, 0x11, 
	0x11, 0x11, 0x12, 0x22, 0x22, 0x11, 0x13, 0x11, 
	0x01, 0x11, 0x11, 0x22, 0x21, 0x11, 0x13, 0x11, 
	0x00, 0x11, 0x11, 0x11, 0x11, 0x11, 0x13, 0x11, 
	0x00, 0x01, 0x11, 0x11, 0x11, 0x11, 0x13, 0x11, 
	0x00, 0x00, 0x11, 0x11, 0x11, 0x11, 0x10, 0x11, 
	0x00, 0x00, 0x00, 0x11, 0x11, 0x11, 0x10, 0x11, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	
};

Gfx bulletbill_2d_bulletbill_sprite_ci4_pal_rgba16_aligner[] = {gsSPEndDisplayList()};
u8 bulletbill_2d_bulletbill_sprite_ci4_pal_rgba16[] = {
	0x94, 0xbe, 0x00, 0x01, 0xff, 0xff, 0xad, 0x6b, 
	
};

Vtx bulletbill_2d_BulletBill_mesh_layer_4_vtx_cull[8] = {
	{{{0, 0, 50},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{0, 100, 50},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{0, 100, -50},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{0, 0, -50},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{0, 0, 50},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{0, 100, 50},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{0, 100, -50},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{0, 0, -50},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
};

Vtx bulletbill_2d_BulletBill_mesh_layer_4_vtx_0[4] = {
	{{{0, 100, 50},0, {0, 0},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{0, 0, 50},0, {0, 512},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{0, 0, -50},0, {512, 512},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{0, 100, -50},0, {512, 0},{0x7F, 0x0, 0x0, 0xFF}}},
};

Gfx bulletbill_2d_BulletBill_mesh_layer_4_tri_0[] = {
	gsSPVertex(bulletbill_2d_BulletBill_mesh_layer_4_vtx_0 + 0, 4, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSPEndDisplayList(),
};


Gfx mat_bulletbill_2d_BulletBill[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, TEXEL0, 0, 0, 0, TEXEL0, 0, 0, 0, TEXEL0, 0, 0, 0, TEXEL0),
	gsSPGeometryMode(G_CULL_BACK, 0),
	gsDPSetTextureFilter(G_TF_POINT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetTextureLUT(G_TT_RGBA16),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, bulletbill_2d_bulletbill_sprite_ci4_pal_rgba16),
	gsDPTileSync(),
	gsDPSetTile(0, 0, 0, 256, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadSync(),
	gsDPLoadTLUTCmd(7, 3),
	gsDPPipeSync(),
	gsDPTileSync(),
	gsDPSetTextureImage(G_IM_FMT_CI, G_IM_SIZ_16b, 1, bulletbill_2d_bulletbill_sprite_ci4),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_16b, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 4, 0, G_TX_WRAP | G_TX_NOMIRROR, 4, 0),
	gsDPLoadSync(),
	gsDPLoadBlock(7, 0, 0, 63, 2048),
	gsDPPipeSync(),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_4b, 1, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 4, 0, G_TX_WRAP | G_TX_NOMIRROR, 4, 0),
	gsDPSetTileSize(0, 0, 0, 60, 60),
	gsSPEndDisplayList(),
};

Gfx mat_revert_bulletbill_2d_BulletBill[] = {
	gsDPPipeSync(),
	gsSPGeometryMode(0, G_CULL_BACK),
	gsDPSetTextureFilter(G_TF_BILERP),
	gsDPSetTextureLUT(G_TT_NONE),
	gsSPEndDisplayList(),
};

Gfx bulletbill_2d_BulletBill_mesh_layer_4[] = {
	gsSPClearGeometryMode(G_LIGHTING),
	gsSPVertex(bulletbill_2d_BulletBill_mesh_layer_4_vtx_cull + 0, 8, 0),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPCullDisplayList(0, 7),
	gsSPDisplayList(mat_bulletbill_2d_BulletBill),
	gsSPDisplayList(bulletbill_2d_BulletBill_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_bulletbill_2d_BulletBill),
	gsSPEndDisplayList(),
};

Gfx bulletbill_2d_material_revert_render_settings[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};

