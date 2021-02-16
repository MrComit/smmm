Lights1 lightning_Lightning_001_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFE, 0xFE, 0xFE, 0x28, 0x28, 0x28);

Lights1 lightning_Spinner_001_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFE, 0xFE, 0xFE, 0x28, 0x28, 0x28);

Gfx lightning_burn_smoke_ia8_aligner[] = {gsSPEndDisplayList()};
u8 lightning_burn_smoke_ia8[] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x22, 0x22, 0x11, 0x00, 0x00, 0x00, 0x00, 0x11, 
	0x55, 0x88, 0x66, 0x22, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x44, 
	0x88, 0x99, 0x77, 0x44, 0x22, 0x55, 0x66, 0x88, 
	0xdd, 0xff, 0xff, 0xbb, 0x22, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x33, 0x99, 
	0xcc, 0xbb, 0xaa, 0x88, 0x99, 0xbb, 0xaa, 0xbb, 
	0xdd, 0xee, 0xff, 0xff, 0xcc, 0x44, 0x11, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x44, 0xaa, 
	0xbb, 0x99, 0x99, 0xaa, 0xbb, 0xbb, 0xaa, 0xaa, 
	0xcc, 0xee, 0xee, 0xee, 0xff, 0xcc, 0x99, 0x44, 
	0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x44, 0xaa, 
	0xaa, 0x99, 0xbb, 0xbb, 0xbb, 0xaa, 0xaa, 0xaa, 
	0xbb, 0xcc, 0xbb, 0xbb, 0xdd, 0xee, 0xdd, 0xcc, 
	0x44, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x33, 0x99, 
	0xaa, 0xbb, 0xdd, 0xcc, 0xbb, 0xaa, 0xaa, 0xaa, 
	0x99, 0x99, 0x99, 0x99, 0xbb, 0xee, 0xcc, 0xdd, 
	0x88, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x77, 
	0xbb, 0xdd, 0xcc, 0xaa, 0x88, 0x77, 0x99, 0x99, 
	0x88, 0x88, 0x88, 0x99, 0xcc, 0xdd, 0xcc, 0xcc, 
	0xaa, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x55, 
	0xcc, 0xdd, 0xcc, 0x88, 0x66, 0x55, 0x77, 0x99, 
	0x88, 0x88, 0x99, 0xbb, 0xdd, 0xcc, 0xaa, 0xbb, 
	0xbb, 0x33, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x55, 
	0xbb, 0xcc, 0xbb, 0x88, 0x55, 0x55, 0x66, 0x88, 
	0x99, 0x99, 0xaa, 0xcc, 0xbb, 0x99, 0x88, 0xaa, 
	0xcc, 0x66, 0x22, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x11, 0x55, 0x99, 0xbb, 
	0xcc, 0xbb, 0xbb, 0x99, 0x77, 0x66, 0x77, 0x99, 
	0xbb, 0xbb, 0xaa, 0xaa, 0x99, 0x77, 0x77, 0x99, 
	0xbb, 0x88, 0x55, 0x22, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x66, 0xee, 0xff, 0xdd, 
	0xdd, 0xcc, 0xcc, 0xaa, 0x99, 0x88, 0x77, 0x99, 
	0xbb, 0xcc, 0xbb, 0xaa, 0x77, 0x66, 0x88, 0xaa, 
	0xcc, 0xaa, 0x77, 0x66, 0x22, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x22, 0xcc, 0xff, 0xdd, 0xcc, 
	0xdd, 0xdd, 0xcc, 0xbb, 0xaa, 0x88, 0x88, 0xaa, 
	0xaa, 0xaa, 0xaa, 0x88, 0x77, 0x77, 0x99, 0xbb, 
	0xdd, 0xbb, 0x99, 0x99, 0x55, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x55, 0xee, 0xee, 0xdd, 0xbb, 
	0xaa, 0xaa, 0xbb, 0xbb, 0xaa, 0x88, 0x99, 0xbb, 
	0xbb, 0x99, 0x88, 0x77, 0x88, 0xaa, 0xcc, 0xcc, 
	0xdd, 0xcc, 0xcc, 0xbb, 0x88, 0x11, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x33, 0xdd, 0xee, 0xdd, 0xaa, 
	0x77, 0x66, 0x88, 0x99, 0x99, 0x88, 0x88, 0xaa, 
	0xaa, 0x99, 0x88, 0x88, 0xaa, 0xcc, 0xcc, 0xcc, 
	0xcc, 0xdd, 0xdd, 0xcc, 0xbb, 0x22, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x11, 0xaa, 0xee, 0xdd, 0xaa, 
	0x77, 0x66, 0x88, 0xaa, 0xbb, 0x99, 0x66, 0x77, 
	0x77, 0x77, 0x88, 0x88, 0x99, 0xaa, 0xaa, 0xaa, 
	0xbb, 0xcc, 0xdd, 0xdd, 0xcc, 0x22, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x22, 0x99, 0xdd, 0xcc, 0xbb, 
	0x99, 0x99, 0xaa, 0xcc, 0xdd, 0xaa, 0x66, 0x44, 
	0x44, 0x55, 0x77, 0x88, 0x88, 0x88, 0x77, 0x77, 
	0x99, 0xcc, 0xee, 0xee, 0xcc, 0x11, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x77, 0xdd, 0xdd, 0xbb, 0xaa, 
	0x99, 0xaa, 0xcc, 0xdd, 0xcc, 0x99, 0x66, 0x44, 
	0x44, 0x66, 0x77, 0x88, 0x77, 0x66, 0x66, 0x66, 
	0x99, 0xcc, 0xee, 0xee, 0xaa, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x22, 0xcc, 0xee, 0xcc, 0x99, 0x77, 
	0x66, 0x99, 0xcc, 0xcc, 0xaa, 0x88, 0x66, 0x55, 
	0x55, 0x77, 0x88, 0x99, 0x88, 0x77, 0x77, 0x77, 
	0x99, 0xcc, 0xdd, 0xdd, 0x66, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x44, 0xee, 0xee, 0xbb, 0x77, 0x55, 
	0x55, 0x99, 0xcc, 0xcc, 0x99, 0x77, 0x66, 0x66, 
	0x77, 0x99, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 
	0xbb, 0xcc, 0xcc, 0xaa, 0x22, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x33, 0xdd, 0xee, 0xcc, 0x88, 0x55, 
	0x66, 0xbb, 0xee, 0xdd, 0xbb, 0x99, 0x88, 0x88, 
	0x88, 0x77, 0x77, 0x88, 0xaa, 0xcc, 0xdd, 0xcc, 
	0xcc, 0xcc, 0xbb, 0x44, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x88, 0xee, 0xdd, 0xaa, 0x88, 
	0x77, 0xaa, 0xdd, 0xee, 0xdd, 0xbb, 0xaa, 0x77, 
	0x33, 0x11, 0x00, 0x22, 0x66, 0x99, 0xbb, 0xbb, 
	0xbb, 0x88, 0x44, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x11, 0x66, 0x99, 0x88, 0x55, 
	0x22, 0x11, 0x22, 0x66, 0x77, 0x88, 0x66, 0x11, 
	0x00, 0x00, 0x00, 0x00, 0x11, 0x33, 0x44, 0x55, 
	0x44, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	
};

Gfx lightning_amp_electricity_ci4_aligner[] = {gsSPEndDisplayList()};
u8 lightning_amp_electricity_ci4[] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x12, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x02, 0x20, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x01, 0x21, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x22, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x02, 0x10, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x02, 0x10, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x22, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x02, 0x21, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x22, 0x10, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x02, 0x21, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x22, 0x10, 0x00, 0x00, 0x13, 0x00, 
	0x00, 0x02, 0x20, 0x00, 0x00, 0x12, 0x22, 0x00, 
	0x00, 0x12, 0x00, 0x00, 0x02, 0x22, 0x22, 0x00, 
	0x00, 0x20, 0x00, 0x02, 0x22, 0x00, 0x21, 0x00, 
	0x01, 0x20, 0x02, 0x22, 0x00, 0x00, 0x20, 0x00, 
	0x01, 0x22, 0x22, 0x00, 0x00, 0x02, 0x10, 0x00, 
	0x00, 0x11, 0x00, 0x00, 0x00, 0x21, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x22, 0x20, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x02, 0x21, 0x22, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x22, 0x10, 0x02, 0x20, 0x00, 
	0x00, 0x00, 0x02, 0x21, 0x00, 0x00, 0x21, 0x00, 
	0x00, 0x00, 0x22, 0x10, 0x00, 0x00, 0x21, 0x00, 
	0x00, 0x01, 0x21, 0x00, 0x00, 0x02, 0x20, 0x00, 
	0x00, 0x01, 0x21, 0x00, 0x00, 0x02, 0x10, 0x00, 
	0x00, 0x00, 0x22, 0x00, 0x00, 0x21, 0x00, 0x00, 
	0x00, 0x00, 0x12, 0x10, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x02, 0x20, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x01, 0x21, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x22, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	
};

Gfx lightning_amp_electricity_ci4_pal_rgba16_aligner[] = {gsSPEndDisplayList()};
u8 lightning_amp_electricity_ci4_pal_rgba16[] = {
	0xaf, 0xb2, 0xaf, 0xb3, 0xff, 0x41, 0xff, 0x40, 
	
};

Vtx lightning_mark_mesh_layer_6_vtx_0[3] = {
	{{{0, 0, 496},0, {496, 1874},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{404, 0, -313},0, {1594, -322},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-404, 0, -313},0, {-602, -322},{0x0, 0x7F, 0x0, 0xFF}}},
};

Gfx lightning_mark_mesh_layer_6_tri_0[] = {
	gsSPVertex(lightning_mark_mesh_layer_6_vtx_0 + 0, 3, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSPEndDisplayList(),
};

Vtx lightning_lightning_mesh_layer_1_vtx_0[59] = {
	{{{5, 90, 0},0, {-16, 962},{0x0, 0x0, 0x81, 0xFF}}},
	{{{25, 0, 0},0, {1008, 1008},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-25, 0, 0},0, {-16, 1008},{0x0, 0x0, 0x81, 0xFF}}},
	{{{55, 90, 0},0, {1008, 962},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-55, 180, 0},0, {-16, 916},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-5, 180, 0},0, {1008, 916},{0x0, 0x0, 0x81, 0xFF}}},
	{{{5, 271, 0},0, {-16, 869},{0x0, 0x0, 0x81, 0xFF}}},
	{{{55, 271, 0},0, {1008, 869},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-55, 361, 0},0, {-16, 823},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-5, 361, 0},0, {1008, 823},{0x0, 0x0, 0x81, 0xFF}}},
	{{{5, 451, 0},0, {-16, 777},{0x0, 0x0, 0x81, 0xFF}}},
	{{{55, 451, 0},0, {1008, 777},{0x0, 0x0, 0x81, 0xFF}}},
	{{{5, 1714, 0},0, {-16, 130},{0x0, 0x0, 0x81, 0xFF}}},
	{{{0, 2000, 0},0, {1008, -16},{0x0, 0x0, 0x81, 0xFF}}},
	{{{55, 1714, 0},0, {1008, 130},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-5, 1624, 0},0, {1008, 176},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-55, 1624, 0},0, {-16, 176},{0x0, 0x0, 0x81, 0xFF}}},
	{{{55, 1534, 0},0, {1008, 223},{0x0, 0x0, 0x81, 0xFF}}},
	{{{5, 1534, 0},0, {-16, 223},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-5, 1444, 0},0, {1008, 269},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-55, 1444, 0},0, {-16, 269},{0x0, 0x0, 0x81, 0xFF}}},
	{{{5, 1173, 0},0, {-16, 407},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-5, 1083, 0},0, {1008, 454},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-55, 1083, 0},0, {-16, 454},{0x0, 0x0, 0x81, 0xFF}}},
	{{{55, 1173, 0},0, {1008, 407},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-55, 1263, 0},0, {-16, 361},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-5, 1263, 0},0, {1008, 361},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-55, 902, 0},0, {-16, 546},{0x0, 0x0, 0x81, 0xFF}}},
	{{{55, 812, 0},0, {1008, 592},{0x0, 0x0, 0x81, 0xFF}}},
	{{{5, 812, 0},0, {-16, 592},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-5, 902, 0},0, {1008, 546},{0x0, 0x0, 0x81, 0xFF}}},
	{{{5, 992, 0},0, {-16, 500},{0x0, 0x0, 0x81, 0xFF}}},
	{{{5, 992, 0},0, {-16, 500},{0x0, 0x0, 0x81, 0xFF}}},
	{{{55, 992, 0},0, {1008, 500},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-5, 902, 0},0, {1008, 546},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-55, 1083, 0},0, {-16, 454},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-5, 1083, 0},0, {1008, 454},{0x0, 0x0, 0x81, 0xFF}}},
	{{{5, 812, 0},0, {-16, 592},{0x0, 0x0, 0x81, 0xFF}}},
	{{{55, 812, 0},0, {1008, 592},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-5, 722, 0},0, {1008, 638},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-55, 722, 0},0, {-16, 638},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-55, 1444, 0},0, {-16, 269},{0x0, 0x0, 0x81, 0xFF}}},
	{{{55, 1353, 0},0, {1008, 315},{0x0, 0x0, 0x81, 0xFF}}},
	{{{5, 1353, 0},0, {-16, 315},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-5, 1444, 0},0, {1008, 269},{0x0, 0x0, 0x81, 0xFF}}},
	{{{5, 1353, 0},0, {-16, 315},{0x0, 0x0, 0x81, 0xFF}}},
	{{{55, 1353, 0},0, {1008, 315},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-5, 1263, 0},0, {1008, 361},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-55, 1263, 0},0, {-16, 361},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-55, 722, 0},0, {-16, 638},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-5, 722, 0},0, {1008, 638},{0x0, 0x0, 0x81, 0xFF}}},
	{{{55, 632, 0},0, {1008, 685},{0x0, 0x0, 0x81, 0xFF}}},
	{{{5, 632, 0},0, {-16, 685},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-5, 541, 0},0, {1008, 731},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-55, 541, 0},0, {-16, 731},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-55, 541, 0},0, {-16, 731},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-5, 541, 0},0, {1008, 731},{0x0, 0x0, 0x81, 0xFF}}},
	{{{55, 451, 0},0, {1008, 777},{0x0, 0x0, 0x81, 0xFF}}},
	{{{5, 451, 0},0, {-16, 777},{0x0, 0x0, 0x81, 0xFF}}},
};

Gfx lightning_lightning_mesh_layer_1_tri_0[] = {
	gsSPVertex(lightning_lightning_mesh_layer_1_vtx_0 + 0, 32, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
	gsSP2Triangles(4, 3, 0, 0, 4, 5, 3, 0),
	gsSP2Triangles(6, 5, 4, 0, 6, 7, 5, 0),
	gsSP2Triangles(8, 7, 6, 0, 8, 9, 7, 0),
	gsSP2Triangles(10, 9, 8, 0, 10, 11, 9, 0),
	gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
	gsSP2Triangles(12, 15, 16, 0, 16, 15, 17, 0),
	gsSP2Triangles(16, 17, 18, 0, 18, 17, 19, 0),
	gsSP2Triangles(18, 19, 20, 0, 21, 22, 23, 0),
	gsSP2Triangles(21, 24, 22, 0, 25, 24, 21, 0),
	gsSP2Triangles(25, 26, 24, 0, 27, 28, 29, 0),
	gsSP2Triangles(27, 30, 28, 0, 31, 30, 27, 0),
	gsSPVertex(lightning_lightning_mesh_layer_1_vtx_0 + 32, 27, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 1, 0, 0),
	gsSP2Triangles(3, 4, 1, 0, 5, 6, 7, 0),
	gsSP2Triangles(5, 7, 8, 0, 9, 10, 11, 0),
	gsSP2Triangles(9, 12, 10, 0, 13, 14, 15, 0),
	gsSP2Triangles(13, 15, 16, 0, 17, 18, 19, 0),
	gsSP2Triangles(17, 19, 20, 0, 20, 19, 21, 0),
	gsSP2Triangles(20, 21, 22, 0, 23, 24, 25, 0),
	gsSP1Triangle(23, 25, 26, 0),
	gsSPEndDisplayList(),
};

Vtx lightning_lightning_mesh_layer_4_vtx_0[24] = {
	{{{-299, 2052, 299},0, {2242, -1059},{0xAE, 0x33, 0x52, 0x8C}}},
	{{{-269, 1969, 269},0, {2127, -1844},{0xC5, 0xA1, 0x3B, 0x8C}}},
	{{{269, 1969, 269},0, {-161, -510},{0x3B, 0xA1, 0x3B, 0x8C}}},
	{{{299, 2052, 299},0, {-47, 275},{0x52, 0x33, 0x52, 0x8C}}},
	{{{-269, 1969, -269},0, {126, 108},{0x0, 0x81, 0x0, 0x8C}}},
	{{{269, 1969, 269},0, {2959, -2863},{0x0, 0x81, 0x0, 0x8C}}},
	{{{-269, 1969, 269},0, {800, -4210},{0x0, 0x81, 0x0, 0x8C}}},
	{{{269, 1969, -269},0, {2285, 1455},{0x0, 0x81, 0x0, 0x8C}}},
	{{{-299, 2052, 299},0, {1218, -1059},{0xAE, 0x33, 0x52, 0x8C}}},
	{{{-269, 1969, -269},0, {1944, 1000},{0xC5, 0xA1, 0xC5, 0x8C}}},
	{{{-269, 1969, 269},0, {1611, -1289},{0xC5, 0xA1, 0x3B, 0x8C}}},
	{{{-299, 2052, -299},0, {1551, 1229},{0xAE, 0x33, 0xAE, 0x8C}}},
	{{{299, 2052, -299},0, {286, 1539},{0x0, 0x7F, 0x0, 0x8C}}},
	{{{-299, 2052, -299},0, {2575, 205},{0x0, 0x7F, 0x0, 0x8C}}},
	{{{-299, 2052, 299},0, {2242, -2083},{0x0, 0x7F, 0x0, 0x8C}}},
	{{{299, 2052, 299},0, {-47, -749},{0x0, 0x7F, 0x0, 0x8C}}},
	{{{299, 2052, -299},0, {-226, 515},{0x52, 0x33, 0xAE, 0x8C}}},
	{{{269, 1969, -269},0, {-111, 1300},{0x3B, 0xA1, 0xC5, 0x8C}}},
	{{{-269, 1969, -269},0, {2177, -34},{0xC5, 0xA1, 0xC5, 0x8C}}},
	{{{-299, 2052, -299},0, {2063, -819},{0xAE, 0x33, 0xAE, 0x8C}}},
	{{{299, 2052, 299},0, {-47, -749},{0x52, 0x33, 0x52, 0x8C}}},
	{{{269, 1969, 269},0, {-440, -520},{0x3B, 0xA1, 0x3B, 0x8C}}},
	{{{269, 1969, -269},0, {-107, 1769},{0x3B, 0xA1, 0xC5, 0x8C}}},
	{{{299, 2052, -299},0, {286, 1539},{0x52, 0x33, 0xAE, 0x8C}}},
};

Gfx lightning_lightning_mesh_layer_4_tri_0[] = {
	gsSPVertex(lightning_lightning_mesh_layer_4_vtx_0 + 0, 24, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSP2Triangles(4, 5, 6, 0, 4, 7, 5, 0),
	gsSP2Triangles(8, 9, 10, 0, 8, 11, 9, 0),
	gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
	gsSP2Triangles(16, 17, 18, 0, 16, 18, 19, 0),
	gsSP2Triangles(20, 21, 22, 0, 20, 22, 23, 0),
	gsSPEndDisplayList(),
};

Vtx lightning_spinner_mesh_layer_1_vtx_0[32] = {
	{{{-174, -321, 62},0, {-16, 1008},{0x0, 0x8A, 0x2E, 0xFF}}},
	{{{-247, -351, 3},0, {-16, 1008},{0x0, 0x8A, 0x2E, 0xFF}}},
	{{{-174, -368, -60},0, {-16, 1008},{0x0, 0x8A, 0x2E, 0xFF}}},
	{{{-4, -351, 3},0, {-16, 1008},{0x0, 0x8A, 0x2E, 0xFF}}},
	{{{-174, -306, 58},0, {-16, 1008},{0x0, 0x76, 0xD2, 0xFF}}},
	{{{-174, -353, -64},0, {-16, 1008},{0x0, 0x76, 0xD2, 0xFF}}},
	{{{-247, -336, -1},0, {-16, 1008},{0x0, 0x76, 0xD2, 0xFF}}},
	{{{-4, -336, -1},0, {-16, 1008},{0x0, 0x76, 0xD2, 0xFF}}},
	{{{174, -321, -62},0, {-16, 1008},{0x0, 0x8A, 0xD2, 0xFF}}},
	{{{247, -351, -3},0, {-16, 1008},{0x0, 0x8A, 0xD2, 0xFF}}},
	{{{174, -368, 60},0, {-16, 1008},{0x0, 0x8A, 0xD2, 0xFF}}},
	{{{4, -351, -3},0, {-16, 1008},{0x0, 0x8A, 0xD2, 0xFF}}},
	{{{174, -306, -58},0, {-16, 1008},{0x0, 0x76, 0x2E, 0xFF}}},
	{{{174, -353, 64},0, {-16, 1008},{0x0, 0x76, 0x2E, 0xFF}}},
	{{{247, -336, 1},0, {-16, 1008},{0x0, 0x76, 0x2E, 0xFF}}},
	{{{4, -336, 1},0, {-16, 1008},{0x0, 0x76, 0x2E, 0xFF}}},
	{{{-174, -368, -60},0, {-16, 1008},{0xED, 0x99, 0xB8, 0xFF}}},
	{{{-247, -351, 3},0, {-16, 1008},{0x99, 0xB9, 0x15, 0xFF}}},
	{{{-247, -336, -1},0, {-16, 1008},{0x96, 0x43, 0xEC, 0xFF}}},
	{{{-174, -306, 58},0, {-16, 1008},{0xEF, 0x69, 0x45, 0xFF}}},
	{{{-174, -321, 62},0, {-16, 1008},{0xED, 0xD8, 0x77, 0xFF}}},
	{{{-4, -336, -1},0, {-16, 1008},{0x6B, 0x42, 0xEE, 0xFF}}},
	{{{-4, -351, 3},0, {-16, 1008},{0x6A, 0xBC, 0x13, 0xFF}}},
	{{{-174, -353, -64},0, {-16, 1008},{0xEF, 0x2C, 0x8A, 0xFF}}},
	{{{174, -368, 60},0, {-16, 1008},{0x13, 0x99, 0x48, 0xFF}}},
	{{{247, -351, -3},0, {-16, 1008},{0x67, 0xB9, 0xEB, 0xFF}}},
	{{{247, -336, 1},0, {-16, 1008},{0x6A, 0x43, 0x14, 0xFF}}},
	{{{174, -306, -58},0, {-16, 1008},{0x11, 0x69, 0xBB, 0xFF}}},
	{{{174, -321, -62},0, {-16, 1008},{0x13, 0xD8, 0x89, 0xFF}}},
	{{{4, -336, 1},0, {-16, 1008},{0x95, 0x42, 0x12, 0xFF}}},
	{{{4, -351, -3},0, {-16, 1008},{0x96, 0xBC, 0xED, 0xFF}}},
	{{{174, -353, 64},0, {-16, 1008},{0x11, 0x2C, 0x76, 0xFF}}},
};

Gfx lightning_spinner_mesh_layer_1_tri_0[] = {
	gsSPVertex(lightning_spinner_mesh_layer_1_vtx_0 + 0, 32, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSP2Triangles(4, 5, 6, 0, 4, 7, 5, 0),
	gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
	gsSP2Triangles(12, 13, 14, 0, 12, 15, 13, 0),
	gsSP2Triangles(16, 17, 18, 0, 17, 19, 18, 0),
	gsSP2Triangles(17, 20, 19, 0, 20, 21, 19, 0),
	gsSP2Triangles(20, 22, 21, 0, 22, 23, 21, 0),
	gsSP2Triangles(22, 16, 23, 0, 16, 18, 23, 0),
	gsSP2Triangles(24, 25, 26, 0, 25, 27, 26, 0),
	gsSP2Triangles(25, 28, 27, 0, 28, 29, 27, 0),
	gsSP2Triangles(28, 30, 29, 0, 30, 31, 29, 0),
	gsSP2Triangles(30, 24, 31, 0, 24, 26, 31, 0),
	gsSPEndDisplayList(),
};


Gfx mat_lightning_Smoke_001[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, 0, TEXEL0, 0, ENVIRONMENT, 0, 0, 0, 0, 0, TEXEL0, 0, ENVIRONMENT, 0),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPTileSync(),
	gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b, 32, lightning_burn_smoke_ia8),
	gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_8b, 4, 0, 7, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0),
	gsDPLoadSync(),
	gsDPLoadTile(7, 0, 0, 124, 124),
	gsDPPipeSync(),
	gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_8b, 4, 0, 0, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPEndDisplayList(),
};

Gfx mat_lightning_Lightning_001[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(ENVIRONMENT, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, ENVIRONMENT, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsSPClearGeometryMode(G_CULL_BACK),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetEnvColor(254, 254, 0, 255),
	gsSPSetLights1(lightning_Lightning_001_lights),
	gsSPEndDisplayList(),
};

Gfx mat_revert_lightning_Lightning_001[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_CULL_BACK),
	gsSPEndDisplayList(),
};

Gfx mat_lightning_Electric_001[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, TEXEL0, 0, 0, 0, TEXEL0, 0, 0, 0, TEXEL0, 0, 0, 0, TEXEL0),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetTextureLUT(G_TT_RGBA16),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, lightning_amp_electricity_ci4_pal_rgba16),
	gsDPTileSync(),
	gsDPSetTile(0, 0, 0, 256, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadSync(),
	gsDPLoadTLUTCmd(7, 3),
	gsDPPipeSync(),
	gsDPTileSync(),
	gsDPSetTextureImage(G_IM_FMT_CI, G_IM_SIZ_8b, 8, lightning_amp_electricity_ci4),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_8b, 1, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 4, 0),
	gsDPLoadSync(),
	gsDPLoadTile(7, 0, 0, 30, 124),
	gsDPPipeSync(),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_4b, 1, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 4, 0),
	gsDPSetTileSize(0, 0, 0, 60, 124),
	gsSPEndDisplayList(),
};

Gfx mat_revert_lightning_Electric_001[] = {
	gsDPPipeSync(),
	gsDPSetTextureLUT(G_TT_NONE),
	gsSPEndDisplayList(),
};

Gfx mat_lightning_Blank[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPEndDisplayList(),
};

Gfx mat_lightning_Spinner_001[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(ENVIRONMENT, 0, SHADE, 0, 0, 0, 0, 1, ENVIRONMENT, 0, SHADE, 0, 0, 0, 0, 1),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetEnvColor(173, 87, 0, 255),
	gsSPSetLights1(lightning_Spinner_001_lights),
	gsSPEndDisplayList(),
};

Gfx lightning_mark_mesh_layer_6[] = {
	gsSPDisplayList(mat_lightning_Smoke_001),
	gsSPDisplayList(lightning_mark_mesh_layer_6_tri_0),
	gsSPEndDisplayList(),
};

Gfx lightning_lightning_mesh_layer_1[] = {
	gsSPDisplayList(mat_lightning_Lightning_001),
	gsSPDisplayList(lightning_lightning_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_lightning_Lightning_001),
	gsSPEndDisplayList(),
};

Gfx lightning_lightning_mesh_layer_1_mat_override_Blank_0[] = {
	gsSPDisplayList(mat_lightning_Blank),
	gsSPDisplayList(lightning_lightning_mesh_layer_1_tri_0),
	gsSPEndDisplayList(),
};

Gfx lightning_lightning_mesh_layer_4[] = {
	gsSPDisplayList(mat_lightning_Electric_001),
	gsSPDisplayList(lightning_lightning_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_lightning_Electric_001),
	gsSPEndDisplayList(),
};

Gfx lightning_lightning_mesh_layer_4_mat_override_Blank_0[] = {
	gsSPDisplayList(mat_lightning_Blank),
	gsSPDisplayList(lightning_lightning_mesh_layer_4_tri_0),
	gsSPEndDisplayList(),
};

Gfx lightning_spinner_mesh_layer_1[] = {
	gsSPDisplayList(mat_lightning_Spinner_001),
	gsSPDisplayList(lightning_spinner_mesh_layer_1_tri_0),
	gsSPEndDisplayList(),
};

Gfx lightning_material_revert_render_settings[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};

