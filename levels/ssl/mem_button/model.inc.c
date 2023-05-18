Vtx mem_button_RedButton_mesh_layer_1_vtx_0[12] = {
	{{ {-50, 0, 50}, 0, {368, 1008}, {153, 153, 153, 255} }},
	{{ {-50, 50, 50}, 0, {624, 1008}, {255, 255, 255, 255} }},
	{{ {-50, 50, -50}, 0, {624, 752}, {255, 255, 255, 255} }},
	{{ {-50, 0, -50}, 0, {368, 752}, {153, 153, 153, 255} }},
	{{ {50, 50, -50}, 0, {624, 496}, {255, 255, 255, 255} }},
	{{ {50, 0, -50}, 0, {368, 496}, {153, 153, 153, 255} }},
	{{ {50, 50, 50}, 0, {624, 240}, {255, 255, 255, 255} }},
	{{ {-50, 50, 50}, 0, {880, 240}, {255, 255, 255, 255} }},
	{{ {-50, 50, -50}, 0, {880, 496}, {255, 255, 255, 255} }},
	{{ {50, 0, 50}, 0, {368, 240}, {153, 153, 153, 255} }},
	{{ {-50, 50, 50}, 0, {624, -16}, {255, 255, 255, 255} }},
	{{ {-50, 0, 50}, 0, {368, -16}, {153, 153, 153, 255} }},
};

Gfx mem_button_RedButton_mesh_layer_1_tri_0[] = {
	gsSPVertex(mem_button_RedButton_mesh_layer_1_vtx_0 + 0, 12, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSP2Triangles(3, 2, 4, 0, 3, 4, 5, 0),
	gsSP2Triangles(5, 4, 6, 0, 4, 7, 6, 0),
	gsSP2Triangles(4, 8, 7, 0, 5, 6, 9, 0),
	gsSP2Triangles(9, 6, 10, 0, 9, 10, 11, 0),
	gsSPEndDisplayList(),
};

Vtx mem_button_RedButton_mesh_layer_2_vtx_0[10] = {
	{{ {50, 0, 50}, 0, {368, 240}, {153, 153, 153, 255} }},
	{{ {-50, 0, 50}, 0, {368, -16}, {153, 153, 153, 255} }},
	{{ {-75, 0, 75}, 0, {368, -16}, {77, 77, 77, 255} }},
	{{ {75, 0, 75}, 0, {368, 240}, {77, 77, 77, 255} }},
	{{ {50, 0, -50}, 0, {368, 496}, {153, 153, 153, 255} }},
	{{ {75, 0, -75}, 0, {368, 496}, {77, 77, 77, 255} }},
	{{ {-50, 0, -50}, 0, {368, 752}, {153, 153, 153, 255} }},
	{{ {-75, 0, -75}, 0, {368, 752}, {77, 77, 77, 255} }},
	{{ {-50, 0, 50}, 0, {368, 1008}, {153, 153, 153, 255} }},
	{{ {-75, 0, 75}, 0, {368, 1008}, {77, 77, 77, 255} }},
};

Gfx mem_button_RedButton_mesh_layer_2_tri_0[] = {
	gsSPVertex(mem_button_RedButton_mesh_layer_2_vtx_0 + 0, 10, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSP2Triangles(4, 0, 3, 0, 4, 3, 5, 0),
	gsSP2Triangles(6, 4, 5, 0, 6, 5, 7, 0),
	gsSP2Triangles(8, 6, 7, 0, 8, 7, 9, 0),
	gsSPEndDisplayList(),
};


Gfx mat_mem_button_RedButton_003[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(ENVIRONMENT, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, ENVIRONMENT, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsSPGeometryMode(G_LIGHTING, 0),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetEnvColor(255, 0, 0, 255),
	gsSPEndDisplayList(),
};

Gfx mat_revert_mem_button_RedButton_003[] = {
	gsDPPipeSync(),
	gsSPGeometryMode(0, G_LIGHTING),
	gsSPEndDisplayList(),
};

Gfx mat_mem_button_ButtonDecal_002[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(ENVIRONMENT, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, ENVIRONMENT, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsSPGeometryMode(G_LIGHTING, 0),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetEnvColor(255, 0, 108, 255),
	gsSPEndDisplayList(),
};

Gfx mat_revert_mem_button_ButtonDecal_002[] = {
	gsDPPipeSync(),
	gsSPGeometryMode(0, G_LIGHTING),
	gsSPEndDisplayList(),
};

Gfx mem_button_RedButton_mesh_layer_1[] = {
	gsSPDisplayList(mat_mem_button_RedButton_003),
	gsSPDisplayList(mem_button_RedButton_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_mem_button_RedButton_003),
	gsSPEndDisplayList(),
};

Gfx mem_button_RedButton_mesh_layer_2[] = {
	gsSPDisplayList(mat_mem_button_ButtonDecal_002),
	gsSPDisplayList(mem_button_RedButton_mesh_layer_2_tri_0),
	gsSPDisplayList(mat_revert_mem_button_ButtonDecal_002),
	gsSPEndDisplayList(),
};

Gfx mem_button_material_revert_render_settings[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};

