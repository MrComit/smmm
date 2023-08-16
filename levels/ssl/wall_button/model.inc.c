Vtx wall_button_button_mesh_layer_1_vtx_0[8] = {
	{{ {-100, 100, 0}, 0, {155, 155}, {178, 178, 178, 178} }},
	{{ {-100, -100, 0}, 0, {155, 837}, {178, 178, 178, 178} }},
	{{ {-100, -100, 50}, 0, {155, 837}, {255, 255, 255, 255} }},
	{{ {100, -100, 50}, 0, {837, 837}, {255, 255, 255, 255} }},
	{{ {100, -100, 0}, 0, {837, 837}, {178, 178, 178, 178} }},
	{{ {100, 100, 50}, 0, {837, 155}, {255, 255, 255, 255} }},
	{{ {100, 100, 0}, 0, {837, 155}, {178, 178, 178, 178} }},
	{{ {-100, 100, 50}, 0, {155, 155}, {255, 255, 255, 255} }},
};

Gfx wall_button_button_mesh_layer_1_tri_0[] = {
	gsSPVertex(wall_button_button_mesh_layer_1_vtx_0 + 0, 8, 0),
	gsSP2Triangles(0, 1, 2, 0, 1, 3, 2, 0),
	gsSP2Triangles(1, 4, 3, 0, 4, 5, 3, 0),
	gsSP2Triangles(4, 6, 5, 0, 6, 7, 5, 0),
	gsSP2Triangles(6, 0, 7, 0, 0, 2, 7, 0),
	gsSP2Triangles(2, 5, 7, 0, 2, 3, 5, 0),
	gsSPEndDisplayList(),
};


Gfx mat_wall_button_Button[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(ENVIRONMENT, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, ENVIRONMENT, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsSPGeometryMode(G_LIGHTING, 0),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPEndDisplayList(),
};

Gfx mat_revert_wall_button_Button[] = {
	gsDPPipeSync(),
	gsSPGeometryMode(0, G_LIGHTING),
	gsSPEndDisplayList(),
};

Gfx wall_button_button_mesh_layer_1[] = {
	gsSPDisplayList(mat_wall_button_Button),
	gsSPDisplayList(wall_button_button_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_wall_button_Button),
	gsSPEndDisplayList(),
};

Gfx wall_button_material_revert_render_settings[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};

