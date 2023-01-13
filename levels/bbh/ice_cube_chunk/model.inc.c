// 0x0700A910 - 0x0700A928

// 0x0700A928 - 0x0700A958
static const Vtx bbh_ice_chunk_vertex_0700A928[] = {
    {{{    -8,      0,      5}, 0, {     0,      0}, {0x00, 0x7f, 0x00, 0x64}}},
    {{{     9,      0,      5}, 0, {     0,      0}, {0x00, 0x7f, 0x00, 0x64}}},
    {{{     0,      0,     -9}, 0, {     0,      0}, {0x00, 0x7f, 0x00, 0x64}}},
};

// 0x0700A958 - 0x0700A980
static const Gfx bbh_ice_chunk_dl_0700A958[] = {
    gsSPLightColor(LIGHT_1, 0xffffffff),
    gsSPLightColor(LIGHT_2, 0x7f7f7fff),
    gsSPVertex(bbh_ice_chunk_vertex_0700A928, 3, 0),
    gsSP1Triangle( 0,  1,  2, 0x0),
    gsSPEndDisplayList(),
};

// 0x0700A980 - 0x0700A9B0
const Gfx bbh_ice_chunk_dl_0700A980[] = {
    gsDPPipeSync(),
    gsSPClearGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPDisplayList(bbh_ice_chunk_dl_0700A958),
    gsDPPipeSync(),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};
