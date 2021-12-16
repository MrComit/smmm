#include "config.h"

// Coin

// YELLOW
// 0x030056C0
static const Vtx coin_seg3_vertex_yellow[] = {
    {{{   -32,      0,      0}, 0, {   -16,   4080}, {0xff, 0xff, 0x00, 0xff}}},
    {{{    32,      0,      0}, 0, {  4080,   4080}, {0xff, 0xff, 0x00, 0xff}}},
    {{{    32,     64,      0}, 0, {  4080,    -16}, {0xff, 0xff, 0x00, 0xff}}},
    {{{   -32,     64,      0}, 0, {   -16,    -16}, {0xff, 0xff, 0x00, 0xff}}},
};

// BLUE
// 0x03005700
static const Vtx coin_seg3_vertex_blue[] = {
    {{{   -48,      0,      0}, 0, {   -16,   4080}, {0x80, 0x80, 0xff, 0xff}}},
    {{{    48,      0,      0}, 0, {  4080,   4080}, {0x80, 0x80, 0xff, 0xff}}},
    {{{    48,     96,      0}, 0, {  4080,    -16}, {0x80, 0x80, 0xff, 0xff}}},
    {{{   -48,     96,      0}, 0, {   -16,    -16}, {0x80, 0x80, 0xff, 0xff}}},
};

// RED
// 0x03005740
static const Vtx coin_seg3_vertex_red[] = {
    {{{   -36,      0,      0}, 0, {   -16,   4080}, {0xff, 0x00, 0x00, 0xff}}},
    {{{    36,      0,      0}, 0, {  4080,   4080}, {0xff, 0x00, 0x00, 0xff}}},
    {{{    36,     72,      0}, 0, {  4080,    -16}, {0xff, 0x00, 0x00, 0xff}}},
    {{{   -36,     72,      0}, 0, {   -16,    -16}, {0xff, 0x00, 0x00, 0xff}}},
};

// SECRET
// 0x03005780
static const Vtx coin_seg3_vertex_secret[] = {
    {{{   -36,      0,      0}, 0, {   -16,   4080}, {0xff, 0xff, 0xff, 0xff}}},
    {{{    36,      0,      0}, 0, {  4080,   4080}, {0xff, 0xff, 0xff, 0xff}}},
    {{{    36,     72,      0}, 0, {  4080,    -16}, {0xff, 0xff, 0xff, 0xff}}},
    {{{   -36,     72,      0}, 0, {   -16,    -16}, {0xff, 0xff, 0xff, 0xff}}},
};

static const Vtx coin_seg3_vertex_green[] = {
    {{{   -36,      0,      0}, 0, {   -16,   4080}, {0x00, 0xC0, 0x60, 0xff}}},
    {{{    36,      0,      0}, 0, {  4080,   4080}, {0x00, 0xC0, 0x60, 0xff}}},
    {{{    36,     72,      0}, 0, {  4080,    -16}, {0x00, 0xC0, 0x60, 0xff}}},
    {{{   -36,     72,      0}, 0, {   -16,    -16}, {0x00, 0xC0, 0x60, 0xff}}},
};


// YELLOW REV
// 0x030056C0
static const Vtx coin_seg3_vertex_yellow_r[] = {
    {{{   -32,      0,      0}, 0, {  4080,   4080}, {0xff, 0xff, 0x00, 0xff}}},
    {{{    32,      0,      0}, 0, {   -16,   4080}, {0xff, 0xff, 0x00, 0xff}}},
    {{{    32,     64,      0}, 0, {   -16,    -16}, {0xff, 0xff, 0x00, 0xff}}},
    {{{   -32,     64,      0}, 0, {  4080,    -16}, {0xff, 0xff, 0x00, 0xff}}},
};

// BLUE REV
// 0x03005700
static const Vtx coin_seg3_vertex_blue_r[] = {
    {{{   -48,      0,      0}, 0, {  4080,   4080}, {0x80, 0x80, 0xff, 0xff}}},
    {{{    48,      0,      0}, 0, {   -16,   4080}, {0x80, 0x80, 0xff, 0xff}}},
    {{{    48,     96,      0}, 0, {   -16,    -16}, {0x80, 0x80, 0xff, 0xff}}},
    {{{   -48,     96,      0}, 0, {  4080,    -16}, {0x80, 0x80, 0xff, 0xff}}},
};

// RED REV
// 0x03005740
static const Vtx coin_seg3_vertex_red_r[] = {
    {{{   -36,      0,      0}, 0, {  4080,   4080}, {0xff, 0x00, 0x00, 0xff}}},
    {{{    36,      0,      0}, 0, {   -16,   4080}, {0xff, 0x00, 0x00, 0xff}}},
    {{{    36,     72,      0}, 0, {   -16,    -16}, {0xff, 0x00, 0x00, 0xff}}},
    {{{   -36,     72,      0}, 0, {  4080,    -16}, {0xff, 0x00, 0x00, 0xff}}},
};

// SECRET REV
// 0x03005780
static const Vtx coin_seg3_vertex_secret_r[] = {
    {{{   -36,      0,      0}, 0, {  4080,   4080}, {0xff, 0xff, 0xff, 0xff}}},
    {{{    36,      0,      0}, 0, {   -16,   4080}, {0xff, 0xff, 0xff, 0xff}}},
    {{{    36,     72,      0}, 0, {   -16,    -16}, {0xff, 0xff, 0xff, 0xff}}},
    {{{   -36,     72,      0}, 0, {  4080,    -16}, {0xff, 0xff, 0xff, 0xff}}},
};

// GREEN REV
// 0x03005740
static const Vtx coin_seg3_vertex_green_r[] = {
    {{{   -36,      0,      0}, 0, {  4080,   4080}, {0x00, 0xC0, 0x60, 0xff}}},
    {{{    36,      0,      0}, 0, {   -16,   4080}, {0x00, 0xC0, 0x60, 0xff}}},
    {{{    36,     72,      0}, 0, {   -16,    -16}, {0x00, 0xC0, 0x60, 0xff}}},
    {{{   -36,     72,      0}, 0, {  4080,    -16}, {0x00, 0xC0, 0x60, 0xff}}},
};

// 0x03005780
ALIGNED8 static const Texture coin_seg3_texture_0_ia8[] = {
#include "actors/coin/CUSTOM_coin_0.ia8.inc.c"
};

// 0x03005F80
ALIGNED8 static const Texture coin_seg3_texture_22_5_ia8[] = {
#include "actors/coin/CUSTOM_coin_22_5.ia8.inc.c"
};

// 0x03006780
ALIGNED8 static const Texture coin_seg3_texture_45_ia8[] = {
#include "actors/coin/CUSTOM_coin_45.ia8.inc.c"
};

// 0x03006F80
ALIGNED8 static const Texture coin_seg3_texture_67_5_ia8[] = {
#include "actors/coin/CUSTOM_coin_67_5.ia8.inc.c"
};

// 0x03007
ALIGNED8 static const Texture coin_seg3_texture_90_ia8[] = {
#include "actors/coin/CUSTOM_coin_90.ia8.inc.c"
};

// set geo
// 0x03007780 - 0x030077D0
const Gfx coin_seg3_dl_start[] = {
    gsDPPipeSync(),
    gsSPClearGeometryMode(G_LIGHTING),
    gsDPSetCombineMode(G_CC_MODULATEIA, G_CC_MODULATEIA),
    gsSPTexture(32767, 32767, 0, G_TX_RENDERTILE, G_ON),
    gsDPTileSync(),
    gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_8b, 8, 0, G_TX_LOADTILE, 0, (G_TX_CLAMP | G_TX_NOMIRROR), 6, G_TX_NOLOD, (G_TX_CLAMP | G_TX_NOMIRROR), 6, G_TX_NOLOD),
    gsDPLoadSync(),
    gsDPLoadTile(G_TX_LOADTILE, 0, 0, 252, 252),
    gsDPPipeSync(),
    gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_8b, 8, 0, G_TX_RENDERTILE, 0, (G_TX_CLAMP | G_TX_NOMIRROR), 6, G_TX_NOLOD, (G_TX_CLAMP | G_TX_NOMIRROR), 6, G_TX_NOLOD),
    gsDPSetTileSize(0, 0, 0, 252, 252),
    gsSPEndDisplayList(),
};

const Gfx coin_seg3_dl_bluecombiner[] = {
    gsDPPipeSync(),
    gsSPClearGeometryMode(G_LIGHTING),
    gsDPSetCombineMode(G_CC_MODULATEIFADEA, G_CC_MODULATEIFADEA),
    gsSPTexture(32767, 32767, 0, G_TX_RENDERTILE, G_ON),
    gsDPTileSync(),
    gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_8b, 8, 0, G_TX_LOADTILE, 0, (G_TX_CLAMP | G_TX_NOMIRROR), 6, G_TX_NOLOD, (G_TX_CLAMP | G_TX_NOMIRROR), 6, G_TX_NOLOD),
    gsDPLoadSync(),
    gsDPLoadTile(G_TX_LOADTILE, 0, 0, 252, 252),
    gsDPPipeSync(),
    gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_8b, 8, 0, G_TX_RENDERTILE, 0, (G_TX_CLAMP | G_TX_NOMIRROR), 6, G_TX_NOLOD, (G_TX_CLAMP | G_TX_NOMIRROR), 6, G_TX_NOLOD),    gsDPSetTileSize(0, 0, 0, (32 - 1) << G_TEXTURE_IMAGE_FRAC, (32 - 1) << G_TEXTURE_IMAGE_FRAC),
    gsDPSetTileSize(0, 0, 0, 252, 252),
    gsSPEndDisplayList(),
};

// clear geo
// 0x030077D0 - 0x03007800
const Gfx coin_seg3_dl_end[] = {
    gsSP2Triangles( 0,  1,  2, 0x0,  0,  2,  3, 0x0),
    gsSPTexture(0x0001, 0x0001, 0, G_TX_RENDERTILE, G_OFF),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPEndDisplayList(),
};

// YELLOW
const Gfx coin_seg3_dl_yellow_0[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b, 64, coin_seg3_texture_0_ia8),
    gsSPDisplayList(coin_seg3_dl_start),
    gsSPVertex(coin_seg3_vertex_yellow, 4, 0),
    gsSPBranchList(coin_seg3_dl_end),
};

const Gfx coin_seg3_dl_yellow_22_5[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b, 64, coin_seg3_texture_22_5_ia8),
    gsSPDisplayList(coin_seg3_dl_start),
    gsSPVertex(coin_seg3_vertex_yellow, 4, 0),
    gsSPBranchList(coin_seg3_dl_end),
};

const Gfx coin_seg3_dl_yellow_45[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b, 64, coin_seg3_texture_45_ia8),
    gsSPDisplayList(coin_seg3_dl_start),
    gsSPVertex(coin_seg3_vertex_yellow, 4, 0),
    gsSPBranchList(coin_seg3_dl_end),
};

const Gfx coin_seg3_dl_yellow_67_5[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b, 64, coin_seg3_texture_67_5_ia8),
    gsSPDisplayList(coin_seg3_dl_start),
    gsSPVertex(coin_seg3_vertex_yellow, 4, 0),
    gsSPBranchList(coin_seg3_dl_end),
};

const Gfx coin_seg3_dl_yellow_90[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b, 64, coin_seg3_texture_90_ia8),
    gsSPDisplayList(coin_seg3_dl_start),
    gsSPVertex(coin_seg3_vertex_yellow, 4, 0),
    gsSPBranchList(coin_seg3_dl_end),
};

const Gfx coin_seg3_dl_yellow_67_5_r[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b, 64, coin_seg3_texture_67_5_ia8),
    gsSPDisplayList(coin_seg3_dl_start),
    gsSPVertex(coin_seg3_vertex_yellow_r, 4, 0),
    gsSPBranchList(coin_seg3_dl_end),
};

const Gfx coin_seg3_dl_yellow_45_r[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b, 64, coin_seg3_texture_45_ia8),
    gsSPDisplayList(coin_seg3_dl_start),
    gsSPVertex(coin_seg3_vertex_yellow_r, 4, 0),
    gsSPBranchList(coin_seg3_dl_end),
};

const Gfx coin_seg3_dl_yellow_22_5_r[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b, 64, coin_seg3_texture_22_5_ia8),
    gsSPDisplayList(coin_seg3_dl_start),
    gsSPVertex(coin_seg3_vertex_yellow_r, 4, 0),
    gsSPBranchList(coin_seg3_dl_end),
};

// BLUE
const Gfx coin_seg3_dl_blue_0[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b, 64, coin_seg3_texture_0_ia8),
    gsSPDisplayList(coin_seg3_dl_bluecombiner),
    gsSPVertex(coin_seg3_vertex_blue, 4, 0),
    gsSPBranchList(coin_seg3_dl_end),
};

const Gfx coin_seg3_dl_blue_22_5[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b, 64, coin_seg3_texture_22_5_ia8),
    gsSPDisplayList(coin_seg3_dl_bluecombiner),
    gsSPVertex(coin_seg3_vertex_blue, 4, 0),
    gsSPBranchList(coin_seg3_dl_end),
};

const Gfx coin_seg3_dl_blue_45[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b, 64, coin_seg3_texture_45_ia8),
    gsSPDisplayList(coin_seg3_dl_bluecombiner),
    gsSPVertex(coin_seg3_vertex_blue, 4, 0),
    gsSPBranchList(coin_seg3_dl_end),
};

const Gfx coin_seg3_dl_blue_67_5[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b, 64, coin_seg3_texture_67_5_ia8),
    gsSPDisplayList(coin_seg3_dl_bluecombiner),
    gsSPVertex(coin_seg3_vertex_blue, 4, 0),
    gsSPBranchList(coin_seg3_dl_end),
};

const Gfx coin_seg3_dl_blue_90[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b, 64, coin_seg3_texture_90_ia8),
    gsSPDisplayList(coin_seg3_dl_bluecombiner),
    gsSPVertex(coin_seg3_vertex_blue, 4, 0),
    gsSPBranchList(coin_seg3_dl_end),
};

const Gfx coin_seg3_dl_blue_67_5_r[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b, 64, coin_seg3_texture_67_5_ia8),
    gsSPDisplayList(coin_seg3_dl_bluecombiner),
    gsSPVertex(coin_seg3_vertex_blue_r, 4, 0),
    gsSPBranchList(coin_seg3_dl_end),
};

const Gfx coin_seg3_dl_blue_22_5_r[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b, 64, coin_seg3_texture_22_5_ia8),
    gsSPDisplayList(coin_seg3_dl_bluecombiner),
    gsSPVertex(coin_seg3_vertex_blue_r, 4, 0),
    gsSPBranchList(coin_seg3_dl_end),
};

const Gfx coin_seg3_dl_blue_45_r[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b, 64, coin_seg3_texture_45_ia8),
    gsSPDisplayList(coin_seg3_dl_bluecombiner),
    gsSPVertex(coin_seg3_vertex_blue_r, 4, 0),
    gsSPBranchList(coin_seg3_dl_end),
};

// RED
const Gfx coin_seg3_dl_red_0[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b, 64, coin_seg3_texture_0_ia8),
    gsSPDisplayList(coin_seg3_dl_start),
    gsSPVertex(coin_seg3_vertex_red, 4, 0),
    gsSPBranchList(coin_seg3_dl_end),
};

const Gfx coin_seg3_dl_red_22_5[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b, 64, coin_seg3_texture_22_5_ia8),
    gsSPDisplayList(coin_seg3_dl_start),
    gsSPVertex(coin_seg3_vertex_red, 4, 0),
    gsSPBranchList(coin_seg3_dl_end),
};

const Gfx coin_seg3_dl_red_45[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b, 64, coin_seg3_texture_45_ia8),
    gsSPDisplayList(coin_seg3_dl_start),
    gsSPVertex(coin_seg3_vertex_red, 4, 0),
    gsSPBranchList(coin_seg3_dl_end),
};

const Gfx coin_seg3_dl_red_67_5[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b, 64, coin_seg3_texture_67_5_ia8),
    gsSPDisplayList(coin_seg3_dl_start),
    gsSPVertex(coin_seg3_vertex_red, 4, 0),
    gsSPBranchList(coin_seg3_dl_end),
};

const Gfx coin_seg3_dl_red_90[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b, 64, coin_seg3_texture_90_ia8),
    gsSPDisplayList(coin_seg3_dl_start),
    gsSPVertex(coin_seg3_vertex_red, 4, 0),
    gsSPBranchList(coin_seg3_dl_end),
};

const Gfx coin_seg3_dl_red_67_5_r[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b, 64, coin_seg3_texture_67_5_ia8),
    gsSPDisplayList(coin_seg3_dl_start),
    gsSPVertex(coin_seg3_vertex_red_r, 4, 0),
    gsSPBranchList(coin_seg3_dl_end),
};

const Gfx coin_seg3_dl_red_45_r[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b, 64, coin_seg3_texture_45_ia8),
    gsSPDisplayList(coin_seg3_dl_start),
    gsSPVertex(coin_seg3_vertex_red_r, 4, 0),
    gsSPBranchList(coin_seg3_dl_end),
};


const Gfx coin_seg3_dl_red_22_5_r[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b, 64, coin_seg3_texture_22_5_ia8),
    gsSPDisplayList(coin_seg3_dl_start),
    gsSPVertex(coin_seg3_vertex_red_r, 4, 0),
    gsSPBranchList(coin_seg3_dl_end),
};

// GREEN
const Gfx coin_seg3_dl_green_0[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b, 64, coin_seg3_texture_0_ia8),
    gsSPDisplayList(coin_seg3_dl_start),
    gsSPVertex(coin_seg3_vertex_green, 4, 0),
    gsSPBranchList(coin_seg3_dl_end),
};

const Gfx coin_seg3_dl_green_22_5[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b, 64, coin_seg3_texture_22_5_ia8),
    gsSPDisplayList(coin_seg3_dl_start),
    gsSPVertex(coin_seg3_vertex_green, 4, 0),
    gsSPBranchList(coin_seg3_dl_end),
};

const Gfx coin_seg3_dl_green_45[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b, 64, coin_seg3_texture_45_ia8),
    gsSPDisplayList(coin_seg3_dl_start),
    gsSPVertex(coin_seg3_vertex_green, 4, 0),
    gsSPBranchList(coin_seg3_dl_end),
};

const Gfx coin_seg3_dl_green_67_5[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b, 64, coin_seg3_texture_67_5_ia8),
    gsSPDisplayList(coin_seg3_dl_start),
    gsSPVertex(coin_seg3_vertex_green, 4, 0),
    gsSPBranchList(coin_seg3_dl_end),
};

const Gfx coin_seg3_dl_green_90[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b, 64, coin_seg3_texture_90_ia8),
    gsSPDisplayList(coin_seg3_dl_start),
    gsSPVertex(coin_seg3_vertex_green, 4, 0),
    gsSPBranchList(coin_seg3_dl_end),
};

const Gfx coin_seg3_dl_green_67_5_r[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b, 64, coin_seg3_texture_67_5_ia8),
    gsSPDisplayList(coin_seg3_dl_start),
    gsSPVertex(coin_seg3_vertex_green_r, 4, 0),
    gsSPBranchList(coin_seg3_dl_end),
};

const Gfx coin_seg3_dl_green_45_r[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b, 64, coin_seg3_texture_45_ia8),
    gsSPDisplayList(coin_seg3_dl_start),
    gsSPVertex(coin_seg3_vertex_green_r, 4, 0),
    gsSPBranchList(coin_seg3_dl_end),
};


const Gfx coin_seg3_dl_green_22_5_r[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b, 64, coin_seg3_texture_22_5_ia8),
    gsSPDisplayList(coin_seg3_dl_start),
    gsSPVertex(coin_seg3_vertex_green_r, 4, 0),
    gsSPBranchList(coin_seg3_dl_end),
};


// SECRET
const Gfx coin_seg3_dl_secret_0[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b, 64, coin_seg3_texture_0_ia8),
    gsSPDisplayList(coin_seg3_dl_start),
    gsSPVertex(coin_seg3_vertex_secret, 4, 0),
    gsSPBranchList(coin_seg3_dl_end),
};

const Gfx coin_seg3_dl_secret_22_5[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b, 64, coin_seg3_texture_22_5_ia8),
    gsSPDisplayList(coin_seg3_dl_start),
    gsSPVertex(coin_seg3_vertex_secret, 4, 0),
    gsSPBranchList(coin_seg3_dl_end),
};

const Gfx coin_seg3_dl_secret_45[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b, 64, coin_seg3_texture_45_ia8),
    gsSPDisplayList(coin_seg3_dl_start),
    gsSPVertex(coin_seg3_vertex_secret, 4, 0),
    gsSPBranchList(coin_seg3_dl_end),
};

const Gfx coin_seg3_dl_secret_67_5[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b, 64, coin_seg3_texture_67_5_ia8),
    gsSPDisplayList(coin_seg3_dl_start),
    gsSPVertex(coin_seg3_vertex_secret, 4, 0),
    gsSPBranchList(coin_seg3_dl_end),
};

const Gfx coin_seg3_dl_secret_90[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b, 64, coin_seg3_texture_90_ia8),
    gsSPDisplayList(coin_seg3_dl_start),
    gsSPVertex(coin_seg3_vertex_secret, 4, 0),
    gsSPBranchList(coin_seg3_dl_end),
};

const Gfx coin_seg3_dl_secret_67_5_r[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b, 64, coin_seg3_texture_67_5_ia8),
    gsSPDisplayList(coin_seg3_dl_start),
    gsSPVertex(coin_seg3_vertex_secret_r, 4, 0),
    gsSPBranchList(coin_seg3_dl_end),
};

const Gfx coin_seg3_dl_secret_45_r[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b, 64, coin_seg3_texture_45_ia8),
    gsSPDisplayList(coin_seg3_dl_start),
    gsSPVertex(coin_seg3_vertex_secret_r, 4, 0),
    gsSPBranchList(coin_seg3_dl_end),
};


const Gfx coin_seg3_dl_secret_22_5_r[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b, 64, coin_seg3_texture_22_5_ia8),
    gsSPDisplayList(coin_seg3_dl_start),
    gsSPVertex(coin_seg3_vertex_secret_r, 4, 0),
    gsSPBranchList(coin_seg3_dl_end),
};