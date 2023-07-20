
Vtx red_spot_RedSpot_mesh_layer_6_vtx_cull[8] = {
	{{ {-64, 0, 68}, 0, {-16, -16}, {0, 0, 0, 0} }},
	{{ {-64, 0, 68}, 0, {-16, -16}, {0, 0, 0, 0} }},
	{{ {-64, 0, -99}, 0, {-16, -16}, {0, 0, 0, 0} }},
	{{ {-64, 0, -99}, 0, {-16, -16}, {0, 0, 0, 0} }},
	{{ {65, 0, 68}, 0, {-16, -16}, {0, 0, 0, 0} }},
	{{ {65, 0, 68}, 0, {-16, -16}, {0, 0, 0, 0} }},
	{{ {65, 0, -99}, 0, {-16, -16}, {0, 0, 0, 0} }},
	{{ {65, 0, -99}, 0, {-16, -16}, {0, 0, 0, 0} }},
};

Vtx red_spot_RedSpot_mesh_layer_6_vtx_0[8] = {
	{{ {65, 0, 60}, 0, {14693, 10290}, {0, 127, 0, 0} }},
	{{ {18, 0, -99}, 0, {13902, 9860}, {0, 127, 0, 0} }},
	{{ {10, 0, -3}, 0, {14176, 10345}, {0, 127, 0, 255} }},
	{{ {18, 0, -99}, 0, {13902, 9860}, {0, 127, 0, 0} }},
	{{ {-64, 0, -25}, 0, {13772, 10361}, {0, 127, 0, 0} }},
	{{ {10, 0, -3}, 0, {14176, 10345}, {0, 127, 0, 255} }},
	{{ {-29, 0, 68}, 0, {14501, 10722}, {0, 127, 0, 0} }},
	{{ {65, 0, 60}, 0, {14693, 10290}, {0, 127, 0, 0} }},
};

Gfx red_spot_RedSpot_mesh_layer_6_tri_0[] = {
	gsSPVertex(red_spot_RedSpot_mesh_layer_6_vtx_0 + 0, 8, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
	gsSP2Triangles(4, 6, 5, 0, 7, 5, 6, 0),
	gsSPEndDisplayList(),
};


Gfx mat_red_spot_RedSpot[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetEnvColor(185, 0, 0, 255),
    gsSPLightColor(LIGHT_1, 0xffffffff),
    gsSPLightColor(LIGHT_2, 0x7f7f7fff),
	gsSPEndDisplayList(),
};

Gfx red_spot_RedSpot_mesh_layer_6[] = {
	gsSPClearGeometryMode(G_LIGHTING),
	gsSPVertex(red_spot_RedSpot_mesh_layer_6_vtx_cull + 0, 8, 0),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPCullDisplayList(0, 7),
	gsSPDisplayList(mat_red_spot_RedSpot),
	gsSPDisplayList(red_spot_RedSpot_mesh_layer_6_tri_0),
	gsSPEndDisplayList(),
};

Gfx red_spot_material_revert_render_settings[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};

