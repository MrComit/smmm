Vtx new_button_Button_002_mesh_layer_1_vtx_cull[8] = {
	{{ {-75, 0, 75}, 0, {-16, -16}, {0, 0, 0, 0} }},
	{{ {-75, 50, 75}, 0, {-16, -16}, {0, 0, 0, 0} }},
	{{ {-75, 50, -75}, 0, {-16, -16}, {0, 0, 0, 0} }},
	{{ {-75, 0, -75}, 0, {-16, -16}, {0, 0, 0, 0} }},
	{{ {75, 0, 75}, 0, {-16, -16}, {0, 0, 0, 0} }},
	{{ {75, 50, 75}, 0, {-16, -16}, {0, 0, 0, 0} }},
	{{ {75, 50, -75}, 0, {-16, -16}, {0, 0, 0, 0} }},
	{{ {75, 0, -75}, 0, {-16, -16}, {0, 0, 0, 0} }},
};

Vtx new_button_Button_002_mesh_layer_1_vtx_0[12] = {
	{{ {75, 50, -75}, 0, {624, 496}, {255, 255, 255, 255} }},
	{{ {-75, 50, -75}, 0, {880, 496}, {255, 255, 255, 255} }},
	{{ {-75, 50, 75}, 0, {880, 240}, {255, 255, 255, 255} }},
	{{ {75, 50, 75}, 0, {624, 240}, {255, 255, 255, 255} }},
	{{ {75, 0, -75}, 0, {470, 496}, {178, 178, 178, 255} }},
	{{ {75, 0, 75}, 0, {470, 240}, {178, 178, 178, 255} }},
	{{ {-75, 50, 75}, 0, {624, -16}, {255, 255, 255, 255} }},
	{{ {-75, 0, 75}, 0, {470, -16}, {178, 178, 178, 255} }},
	{{ {-75, 0, -75}, 0, {470, 752}, {178, 178, 178, 255} }},
	{{ {-75, 50, -75}, 0, {624, 752}, {255, 255, 255, 255} }},
	{{ {-75, 0, 75}, 0, {470, 1008}, {178, 178, 178, 255} }},
	{{ {-75, 50, 75}, 0, {624, 1008}, {255, 255, 255, 255} }},
};

Gfx new_button_Button_002_mesh_layer_1_tri_0[] = {
	gsSPVertex(new_button_Button_002_mesh_layer_1_vtx_0 + 0, 12, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSP2Triangles(4, 0, 3, 0, 4, 3, 5, 0),
	gsSP2Triangles(5, 3, 6, 0, 5, 6, 7, 0),
	gsSP2Triangles(8, 0, 4, 0, 8, 9, 0, 0),
	gsSP2Triangles(10, 9, 8, 0, 10, 11, 9, 0),
	gsSPEndDisplayList(),
};


Gfx mat_new_button_RedButton_002[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(ENVIRONMENT, 0, SHADE, 0, 0, 0, 0, 1, ENVIRONMENT, 0, SHADE, 0, 0, 0, 0, 1),
	gsSPGeometryMode(G_LIGHTING, 0),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetEnvColor(255, 0, 0, 255),
	gsSPEndDisplayList(),
};

Gfx mat_revert_new_button_RedButton_002[] = {
	gsDPPipeSync(),
	gsSPGeometryMode(0, G_LIGHTING),
	gsSPEndDisplayList(),
};

Gfx new_button_Button_002_mesh_layer_1[] = {
	gsSPClearGeometryMode(G_LIGHTING),
	gsSPVertex(new_button_Button_002_mesh_layer_1_vtx_cull + 0, 8, 0),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPCullDisplayList(0, 7),
	gsSPDisplayList(mat_new_button_RedButton_002),
	gsSPDisplayList(new_button_Button_002_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_new_button_RedButton_002),
	gsSPEndDisplayList(),
};

Gfx new_button_material_revert_render_settings[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};

