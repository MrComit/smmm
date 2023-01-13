

Vtx red_button_RedButton_mesh_layer_1_vtx_0[12] = {
	{{{-50, 0, 50},0, {368, 1008},{0x99, 0x99, 0x99, 0xFF}}},
	{{{-50, 50, 50},0, {624, 1008},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{-50, 50, -50},0, {624, 752},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{-50, 0, -50},0, {368, 752},{0x99, 0x99, 0x99, 0xFF}}},
	{{{50, 50, -50},0, {624, 496},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{50, 0, -50},0, {368, 496},{0x99, 0x99, 0x99, 0xFF}}},
	{{{50, 50, 50},0, {624, 240},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{-50, 50, 50},0, {880, 240},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{-50, 50, -50},0, {880, 496},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{50, 0, 50},0, {368, 240},{0x99, 0x99, 0x99, 0xFF}}},
	{{{-50, 50, 50},0, {624, -16},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{-50, 0, 50},0, {368, -16},{0x99, 0x99, 0x99, 0xFF}}},
};

Gfx red_button_RedButton_mesh_layer_1_tri_0[] = {
	gsSPVertex(red_button_RedButton_mesh_layer_1_vtx_0 + 0, 12, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSP2Triangles(3, 2, 4, 0, 3, 4, 5, 0),
	gsSP2Triangles(5, 4, 6, 0, 4, 7, 6, 0),
	gsSP2Triangles(4, 8, 7, 0, 5, 6, 9, 0),
	gsSP2Triangles(9, 6, 10, 0, 9, 10, 11, 0),
	gsSPEndDisplayList(),
};

Vtx red_button_RedButton_mesh_layer_2_vtx_0[10] = {
	{{{50, 0, 50},0, {368, 240},{0x99, 0x99, 0x99, 0xFF}}},
	{{{-50, 0, 50},0, {368, -16},{0x99, 0x99, 0x99, 0xFF}}},
	{{{-75, 0, 75},0, {368, -16},{0x4D, 0x4D, 0x4D, 0xFF}}},
	{{{75, 0, 75},0, {368, 240},{0x4D, 0x4D, 0x4D, 0xFF}}},
	{{{50, 0, -50},0, {368, 496},{0x99, 0x99, 0x99, 0xFF}}},
	{{{75, 0, -75},0, {368, 496},{0x4D, 0x4D, 0x4D, 0xFF}}},
	{{{-50, 0, -50},0, {368, 752},{0x99, 0x99, 0x99, 0xFF}}},
	{{{-75, 0, -75},0, {368, 752},{0x4D, 0x4D, 0x4D, 0xFF}}},
	{{{-50, 0, 50},0, {368, 1008},{0x99, 0x99, 0x99, 0xFF}}},
	{{{-75, 0, 75},0, {368, 1008},{0x4D, 0x4D, 0x4D, 0xFF}}},
};

Gfx red_button_RedButton_mesh_layer_2_tri_0[] = {
	gsSPVertex(red_button_RedButton_mesh_layer_2_vtx_0 + 0, 10, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSP2Triangles(4, 0, 3, 0, 4, 3, 5, 0),
	gsSP2Triangles(6, 4, 5, 0, 6, 5, 7, 0),
	gsSP2Triangles(8, 6, 7, 0, 8, 7, 9, 0),
	gsSPEndDisplayList(),
};


Gfx mat_red_button_RedButton_002[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(ENVIRONMENT, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, ENVIRONMENT, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsSPClearGeometryMode(G_LIGHTING),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetEnvColor(254, 0, 0, 255),
    gsSPLightColor(LIGHT_1, 0xfefefeff),
    gsSPLightColor(LIGHT_2, 0x7f7f7fff),
	gsSPEndDisplayList(),
};

Gfx mat_revert_red_button_RedButton_002[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPEndDisplayList(),
};

Gfx mat_red_button_ButtonDecal_002[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(ENVIRONMENT, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, ENVIRONMENT, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsSPClearGeometryMode(G_LIGHTING),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetEnvColor(254, 0, 108, 255),
    gsSPLightColor(LIGHT_1, 0xfefefeff),
    gsSPLightColor(LIGHT_2, 0x7f7f7fff),
	gsSPEndDisplayList(),
};

Gfx mat_revert_red_button_ButtonDecal_002[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPEndDisplayList(),
};

Gfx red_button_RedButton_mesh_layer_1[] = {
	gsSPDisplayList(mat_red_button_RedButton_002),
	gsSPDisplayList(red_button_RedButton_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_red_button_RedButton_002),
	gsSPEndDisplayList(),
};

Gfx red_button_RedButton_mesh_layer_2[] = {
	gsSPDisplayList(mat_red_button_ButtonDecal_002),
	gsSPDisplayList(red_button_RedButton_mesh_layer_2_tri_0),
	gsSPDisplayList(mat_revert_red_button_ButtonDecal_002),
	gsSPEndDisplayList(),
};

Gfx red_button_material_revert_render_settings[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};

