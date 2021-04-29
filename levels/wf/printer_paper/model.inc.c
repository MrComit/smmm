Vtx printer_paper_Paper_mesh_layer_1_vtx_cull[8] = {
	{{{-55, 0, -69},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{-55, 0, 69},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{-55, 0, 69},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{-55, 0, -69},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{55, 0, -69},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{55, 0, 69},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{55, 0, 69},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{55, 0, -69},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
};

Vtx printer_paper_Paper_mesh_layer_1_vtx_0[4] = {
	{{{-55, 0, -69},0, {624, 496},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-55, 0, 69},0, {880, 496},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{55, 0, 69},0, {880, 240},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{55, 0, -69},0, {624, 240},{0x0, 0x7F, 0x0, 0xFF}}},
};

Gfx printer_paper_Paper_mesh_layer_1_tri_0[] = {
	gsSPVertex(printer_paper_Paper_mesh_layer_1_vtx_0 + 0, 4, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSPEndDisplayList(),
};


Gfx mat_printer_paper_Paper[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1),
	gsSPClearGeometryMode(G_CULL_BACK),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPEndDisplayList(),
};

Gfx mat_revert_printer_paper_Paper[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_CULL_BACK),
	gsSPEndDisplayList(),
};

Gfx printer_paper_Paper_mesh_layer_1[] = {
	gsSPClearGeometryMode(G_LIGHTING),
	gsSPVertex(printer_paper_Paper_mesh_layer_1_vtx_cull + 0, 8, 0),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPCullDisplayList(0, 7),
	gsSPDisplayList(mat_printer_paper_Paper),
	gsSPDisplayList(printer_paper_Paper_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_printer_paper_Paper),
	gsSPEndDisplayList(),
};

Gfx printer_paper_material_revert_render_settings[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};

