Vtx lightbeam_LightBeam_mesh_vtx_0[7] = {
	{{{-1370, -1335, -337}, 0, {-16, 1008}, {0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{-1661, -1335, -169}, 0, {-16, 1008}, {0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{-1661, -1335, 169}, 0, {-16, 1008}, {0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{0, 0, 0}, 0, {-16, 1008}, {0xFF, 0x0, 0x0, 0xFF}}},
	{{{-1078, -1335, -169}, 0, {-16, 1008}, {0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{-1078, -1335, 169}, 0, {-16, 1008}, {0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{-1370, -1335, 337}, 0, {-16, 1008}, {0xFF, 0xFF, 0xFF, 0xFF}}},
};

Gfx lightbeam_LightBeam_mesh_tri_0[] = {
	// gsSPVertex(lightbeam_LightBeam_mesh_vtx_0 + 0, 7, 0),
	gsSP2Triangles(0, 4, 3, 0, 1, 0, 3, 0),
	gsSP2Triangles(6, 2, 3, 0, 2, 1, 3, 0),
	gsSP2Triangles(5, 6, 3, 0, 4, 5, 3, 0),
	gsSPEndDisplayList(),
};

Gfx lightbeam_LightBeam_mesh_tri_1[] = {
	gsSP2Triangles(2, 5, 0, 0, 2, 6, 5, 0),
	gsSP2Triangles(0, 1, 2, 0, 5, 4, 0, 0),
	gsSPEndDisplayList(),
};

Gfx mat_lightbeam_Beam[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT),
	gsSPGeometryMode(G_CULL_BACK | G_LIGHTING, 0),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetEnvColor(255, 255, 0, 102),
	gsSPEndDisplayList(),
};

Gfx mat_revert_lightbeam_Beam[] = {
	gsDPPipeSync(),
	gsSPGeometryMode(0, G_CULL_BACK | G_LIGHTING),
	gsDPSetRenderMode(G_RM_AA_ZB_XLU_SURF, G_RM_AA_ZB_XLU_SURF2),
	gsSPEndDisplayList(),
};

Gfx lightbeam_LightBeam_mesh[] = {
	gsSPDisplayList(mat_lightbeam_Beam),
	gsSPDisplayList(lightbeam_LightBeam_mesh_tri_0),
	gsDPSetRenderMode(G_RM_AA_ZB_XLU_DECAL, G_RM_AA_ZB_XLU_DECAL2),
	gsDPSetEnvColor(255, 255, 140, 102),
	gsSPDisplayList(lightbeam_LightBeam_mesh_tri_1),
	gsSPDisplayList(mat_revert_lightbeam_Beam),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsSPEndDisplayList(),
};