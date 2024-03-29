#include <PR/ultratypes.h>

#include "sm64.h"
#include "area.h"
#include "behaviors/behavior_actions.h"
#include "behavior_data.h"
#include "camera.h"
#include "sm_debug.h"
#include "dialog_ids.h"
#include "engine/behavior_script.h"
#include "engine/geo_layout.h"
#include "engine/math_util.h"
#include "engine/surface_collision.h"
#include "game_init.h"
#include "helper_macros.h"
#include "ingame_menu.h"
#include "interaction.h"
#include "level_table.h"
#include "level_update.h"
#include "mario.h"
#include "mario_actions_cutscene.h"
#include "memory.h"
#include "obj_behaviors.h"
#include "object_helpers.h"
#include "object_list_processor.h"
#include "rendering_graph_node.h"
#include "spawn_object.h"
#include "spawn_sound.h"
#include "actors/group0.h"
#include "include/course_table.h"
#include "levels/hmc/header.inc.h"
#include "levels/bbh/header.h"
#include "levels/jrb/header.inc.h"
#include "levels/lll/header.h"
#include "levels/ssl/header.h"
#include "levels/ttc/header.h"
#include "save_file.h"
#include "src/game/tile_scroll.h"
#include "actors/common0.h"
#include "print.h"
#include "levels/ssl/yoshi_head/geo_header.h"

extern s8 sLevelRoomOffsets[];

extern Mtx *gMatStackFixed[32];
extern s16 gMatStackIndex;
extern Mat4 gMatStack[32];

s32 sBooColors[] = {
    {0x7864FFff}, //garage
    {0xCBFF74ff}, //dining room
    {0xA5A5FFff}, //kitchen
    {0xd54b1cff}, //living room
    {0xFF0000ff}, //library
    {0x22a82fff},
    {0xffdc47ff},
    {0xffffffff},
    {0x966900ff},
    {0x80A592ff}, //office - old: 0x9D65E1ff
    {0x55009Bff},
    {0x7D5B00ff}, //cave mole room
    {0x64A5FFff}, //ice castle
    {0xffffffff}, //shooting gallery
    {0xffffffff}, //ch3 boss
    {0x1fafffff}, //game room
    {0x3A2BC3ff}, //treehouse
    {0xFF85F9ff}, //theater
    {0x005900ff}, //attic
    {0xD38C00ff}, //laundry room
    {0xffffffff},
};

s8 sBooColorsDark[][3] = {
    {0x78 / 2, 0x64 / 2, 0xFF / 2}, //garage
    {0xCB / 2, 0xFF / 2, 0x74 / 2}, //dining room
    {0xA5 / 2, 0xA5 / 2, 0xFF / 2}, //kitchen
    {0xd5 / 2, 0x4b / 2, 0x1c / 2}, //living room
    {0xFF / 2, 0x00 / 2, 0x00 / 2}, //library
    {0x22 / 2, 0xa8 / 2, 0x2f / 2},
    {0xff / 2, 0xdc / 2, 0x47 / 2},
    {0xff / 2, 0xff / 2, 0xff / 2},
    {0x96 / 2, 0x69 / 2, 0x00 / 2},
    {0x80 / 2, 0xA5 / 2, 0x92 / 2}, //office
    {0x55 / 2, 0x00 / 2, 0x9B / 2},
    {0x7D / 2, 0x5B / 2, 0x00 / 2}, //cave mole room
    {0x64 / 2, 0xA5 / 2, 0xFF / 2}, //ice castle
    {0xff / 2, 0xff / 2, 0xff / 2}, //shooting gallery
    {0xff / 2, 0xff / 2, 0xff / 2}, //ch3 boss
    {0x1f / 2, 0xaf / 2, 0xff / 2}, //game room
    {0x3A / 2, 0x2B / 2, 0xC3 / 2}, //treehouse
    {0xFF / 2, 0x85 / 2, 0xF9 / 2}, //theater
    {0x00 / 2, 0x59 / 2, 0x00 / 2}, //attic
    {0xD3 / 2, 0x8C / 2, 0x00 / 2}, //laundry room
    {0xff, 0xff, 0xff},
};

static s8 sBbhStairJiggleOffsets[] = { -8, 8, -4, 4 };
static s16 sPowersOfTwo[] = { 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80 };
static s8 sLevelsWithRooms[] = { LEVEL_BOB, LEVEL_BBH, LEVEL_CASTLE, LEVEL_HMC, -1 };

static s32 clear_move_flag(u32 *, s32);

#define o gCurrentObject



void *sBackdrops[] = {
a3_sky_ZZSky_mesh,
};


Gfx *background_translate(s32 callContext, struct GraphNode *node, UNUSED f32 b[4][4]) {
    Mat4 mat;
    Vec3f translation;
    Mtx *mtx = alloc_display_list(sizeof(*mtx));
    struct GraphNodeGenerated *currentGraphNode;
    if (callContext == GEO_CONTEXT_RENDER) {
#define FARAWAYNESS .99f // the closer to 1 the further away
        currentGraphNode = (struct GraphNodeGenerated *) node;
        translation[0] = gLakituState.curPos[0] * FARAWAYNESS;
        translation[1] = gLakituState.curPos[1] * FARAWAYNESS;
        translation[2] = gLakituState.curPos[2] * FARAWAYNESS;
        mtxf_translate(mat, translation);
        mtxf_mul(gMatStack[gMatStackIndex + 1], mat, gMatStack[gMatStackIndex]);
        gMatStackIndex++;
        mtxf_to_mtx(mtx, gMatStack[gMatStackIndex]);
        gMatStackFixed[gMatStackIndex] = mtx;
        geo_append_display_list(sBackdrops[currentGraphNode->parameter], 0); //DL pointer
        gMatStackIndex--;
    }
    return 0;
}




Gfx *geo_update_spike_log(s32 callContext, UNUSED struct GraphNode *node, Mat4 mtx) {
    // Mat4 sp20;
    struct Object *sp1C;

    if (callContext == GEO_CONTEXT_RENDER) {
        sp1C = (struct Object *) gCurGraphNodeObject; // TODO: change global type to Object pointer
        if (sp1C->oObjF4 && sp1C->oObjF4->oAction == 0) {
            // create_transformation_from_matrices(sp20, mtx, *gCurGraphNodeCamera->matrixPtr);
            obj_update_pos_from_parent_transformation(mtx, sp1C->oObjF4);
            obj_set_gfx_pos_from_pos(sp1C->oObjF4);
        }
    }
    return NULL;
}



Gfx *geo_update_projectile_pos_and_angle_from_parent(s32 callContext, UNUSED struct GraphNode *node, Mat4 mtx) {
    struct Object *sp1C;

    if (callContext == GEO_CONTEXT_RENDER) {
        sp1C = (struct Object *) gCurGraphNodeObject; // TODO: change global type to Object pointer
        if (sp1C->prevObj) {
            // create_transformation_from_matrices(sp1C->prevObj->transform, mtx, *gCurGraphNodeCamera->matrixPtr);
            mtxf_copy(sp1C->prevObj->transform, mtx);
            sp1C->prevObj->header.gfx.throwMatrix = &sp1C->prevObj->transform;
        }
    }
    return NULL;
}


Gfx *geo_update_projectile_pos_from_parent(s32 callContext, UNUSED struct GraphNode *node, Mat4 mtx) {
    struct Object *sp1C;

    if (callContext == GEO_CONTEXT_RENDER) {
        sp1C = (struct Object *) gCurGraphNodeObject; // TODO: change global type to Object pointer
        if (sp1C->prevObj) {
            obj_update_pos_from_parent_transformation(mtx, sp1C->prevObj);
            obj_set_gfx_pos_from_pos(sp1C->prevObj);
        }
    }
    return NULL;
}


Gfx *geo_update_layer_transparency_layer(s32 callContext, struct GraphNode *node, UNUSED void *context) {
    Gfx *dlStart, *dlHead;
    struct Object *objectGraphNode;
    struct GraphNodeGenerated *currentGraphNode;
    s32 objectOpacity;

    dlStart = NULL;

    if (callContext == GEO_CONTEXT_RENDER) {
        objectGraphNode = (struct Object *) gCurGraphNodeObject; // TODO: change this to object pointer?
        currentGraphNode = (struct GraphNodeGenerated *) node;

        if (gCurGraphNodeHeldObject != NULL) {
            objectGraphNode = gCurGraphNodeHeldObject->objNode;
        }

        objectOpacity = objectGraphNode->oOpacity;
        dlStart = alloc_display_list(sizeof(Gfx) * 3);

        dlHead = dlStart;

        currentGraphNode->fnNode.node.flags = (currentGraphNode->parameter << 8) | (currentGraphNode->fnNode.node.flags & 0xFF);
            if (currentGraphNode->parameter != 10) {
                if (objectGraphNode->activeFlags & ACTIVE_FLAG_DITHERED_ALPHA) {
                    gDPSetAlphaCompare(dlHead++, G_AC_DITHER);
                }
            }

        gDPSetEnvColor(dlHead++, 255, 255, 255, objectOpacity);
        gSPEndDisplayList(dlHead);
    }

    return dlStart;
}


Gfx *geo_update_layer_transparency_cutout(s32 callContext, struct GraphNode *node, UNUSED void *context) {
    Gfx *dlStart, *dlHead;
    struct Object *objectGraphNode;
    struct GraphNodeGenerated *currentGraphNode;
    s32 objectOpacity;

    dlStart = NULL;

    if (callContext == GEO_CONTEXT_RENDER) {
        objectGraphNode = (struct Object *) gCurGraphNodeObject; // TODO: change this to object pointer?
        currentGraphNode = (struct GraphNodeGenerated *) node;

        if (gCurGraphNodeHeldObject != NULL) {
            objectGraphNode = gCurGraphNodeHeldObject->objNode;
        }

        objectOpacity = objectGraphNode->oOpacity;
        dlStart = alloc_display_list(sizeof(Gfx) * 3);

        dlHead = dlStart;

        currentGraphNode->fnNode.node.flags = 0x400 | (currentGraphNode->fnNode.node.flags & 0xFF);
            if (currentGraphNode->parameter != 10) {
                if (objectGraphNode->activeFlags & ACTIVE_FLAG_DITHERED_ALPHA) {
                    gDPSetAlphaCompare(dlHead++, G_AC_DITHER);
                }
            }

        gDPSetEnvColor(dlHead++, 255, 255, 255, objectOpacity);
        gSPEndDisplayList(dlHead);
    }

    return dlStart;
}





Gfx *geo_update_layer_transparency_cutout2(s32 callContext, struct GraphNode *node, UNUSED void *context) {
    Gfx *dlStart, *dlHead;
    struct Object *objectGraphNode;
    struct GraphNodeGenerated *currentGraphNode;
    s32 objectOpacity;

    dlStart = NULL;

    if (callContext == GEO_CONTEXT_RENDER) {
        objectGraphNode = (struct Object *) gCurGraphNodeObject; // TODO: change this to object pointer?
        currentGraphNode = (struct GraphNodeGenerated *) node;

        if (gCurGraphNodeHeldObject != NULL) {
            objectGraphNode = gCurGraphNodeHeldObject->objNode;
        }

        objectOpacity = objectGraphNode->oOpacity;
        dlStart = alloc_display_list(sizeof(Gfx) * 3);

        dlHead = dlStart;
        if (objectOpacity == 0xFF) {
            objectGraphNode->oAnimState = 0;
            currentGraphNode->fnNode.node.flags = 0x400 | (currentGraphNode->fnNode.node.flags & 0xFF);
        } else {
            objectGraphNode->oAnimState = 1;
            currentGraphNode->fnNode.node.flags = 0x500 | (currentGraphNode->fnNode.node.flags & 0xFF);
        }
            if (currentGraphNode->parameter != 10) {
                if (objectGraphNode->activeFlags & ACTIVE_FLAG_DITHERED_ALPHA) {
                    gDPSetAlphaCompare(dlHead++, G_AC_DITHER);
                }
            }

        gDPSetEnvColor(dlHead++, 255, 255, 255, objectOpacity);
        gSPEndDisplayList(dlHead);
    }

    return dlStart;
}




Gfx *geo_update_layer_transparency_and_color(s32 callContext, struct GraphNode *node, UNUSED void *context) {
    Gfx *dlStart, *dlHead;
    struct Object *objectGraphNode;
    struct GraphNodeGenerated *currentGraphNode;
    s32 objectOpacity;

    dlStart = NULL;

    if (callContext == GEO_CONTEXT_RENDER) {
        objectGraphNode = (struct Object *) gCurGraphNodeObject; // TODO: change this to object pointer?
        currentGraphNode = (struct GraphNodeGenerated *) node;

        if (gCurGraphNodeHeldObject != NULL) {
            objectGraphNode = gCurGraphNodeHeldObject->objNode;
        }

        objectOpacity = objectGraphNode->oOpacity;
        dlStart = alloc_display_list(sizeof(Gfx) * 3);

        dlHead = dlStart;

        if (objectOpacity == 0xFF) {
            if (currentGraphNode->parameter == 20) {
                currentGraphNode->fnNode.node.flags =
                0x600 | (currentGraphNode->fnNode.node.flags & 0xFF);
            } else {
                currentGraphNode->fnNode.node.flags =
                0x100 | (currentGraphNode->fnNode.node.flags & 0xFF);
            }

            objectGraphNode->oAnimState = 0;
        } else {
            if (currentGraphNode->parameter == 20) {
                currentGraphNode->fnNode.node.flags =
                0x600 | (currentGraphNode->fnNode.node.flags & 0xFF);
            } else {
                currentGraphNode->fnNode.node.flags =
                0x500 | (currentGraphNode->fnNode.node.flags & 0xFF);
            }

            objectGraphNode->oAnimState = 1;

            // the debug info check was removed in US. so we need to
            // perform the only necessary check instead of the debuginfo
            // one.
            if (currentGraphNode->parameter != 10) {
                if (objectGraphNode->activeFlags & ACTIVE_FLAG_DITHERED_ALPHA) {
                    gDPSetAlphaCompare(dlHead++, G_AC_DITHER);
                }
            }
        }

        gDPSetEnvColor(dlHead++, objectGraphNode->os16F4, objectGraphNode->os16F6, objectGraphNode->os16F8, objectOpacity);
        gSPEndDisplayList(dlHead);
    }

    return dlStart;
}


Gfx *geo_update_opacity_and_color(s32 callContext, struct GraphNode *node, UNUSED void *context) {
    Gfx *dlStart, *dlHead;
    struct Object *objectGraphNode;
    struct GraphNodeGenerated *currentGraphNode;
    s32 objectOpacity;

    dlStart = NULL;

    if (callContext == GEO_CONTEXT_RENDER) {
        objectGraphNode = (struct Object *) gCurGraphNodeObject; // TODO: change this to object pointer?
        currentGraphNode = (struct GraphNodeGenerated *) node;

        if (gCurGraphNodeHeldObject != NULL) {
            objectGraphNode = gCurGraphNodeHeldObject->objNode;
        }

        objectOpacity = objectGraphNode->oOpacity;
        dlStart = alloc_display_list(sizeof(Gfx) * 3);

        dlHead = dlStart;

        currentGraphNode->fnNode.node.flags = (currentGraphNode->parameter << 8) | (currentGraphNode->fnNode.node.flags & 0xFF);

        gDPSetEnvColor(dlHead++, objectGraphNode->os16F4, objectGraphNode->os16F6, objectGraphNode->os16F8, objectOpacity);
        gSPEndDisplayList(dlHead);
    }

    return dlStart;
}

Vec3s sBooGooColors[5] = {
    {0x9F, 0x00, 0x00},
    {0xCC, 0x29, 0x7A},
    {0x1E, 0x1E, 0x99},
    // {0x5B, 0x28, 0x73},
    {0x49, 0x0D, 0x7F},
    {0x9F, 0x9F, 0x00},
};


s32 get_l8_boogoo_index(void) {
    s32 index = 0;
        switch (gMarioCurrentRoom) {
            case 1:
            case 2:
                index = 0;
                break;
            case 3:
                index = 1;
                break;
            case 6:
                index = 2;
                break;
            case 10:
                index = 3;
                break;
            case 11:
                index = 4;
                break;
        }
    return index;
}


Gfx *geo_update_boogoo_color(s32 callContext, struct GraphNode *node, UNUSED void *context) {
    Gfx *dlStart, *dlHead;
    struct Object *objectGraphNode;
    struct GraphNodeGenerated *currentGraphNode;
    s32 index = 0;

    dlStart = NULL;

    if (callContext == GEO_CONTEXT_RENDER) {
        objectGraphNode = (struct Object *) gCurGraphNodeObject;
        currentGraphNode = (struct GraphNodeGenerated *) node;

        if (((objectGraphNode->oBehParams >> 8) & 0xFF) == 0) {
            index = get_l8_boogoo_index();
        } else {
            index = ((objectGraphNode->oBehParams >> 8) & 0xFF) - 1;
        }

        dlStart = alloc_display_list(sizeof(Gfx) * 3);
        dlHead = dlStart;

        currentGraphNode->fnNode.node.flags = (1 /*currentGraphNode->parameter*/ << 8) | (currentGraphNode->fnNode.node.flags & 0xFF);

        gDPSetEnvColor(dlHead++, sBooGooColors[index][0], sBooGooColors[index][1], sBooGooColors[index][2], 255);
        gSPEndDisplayList(dlHead);
    }

    return dlStart;
}



Gfx *geo_update_boogoo_object(s32 callContext, struct GraphNode *node, UNUSED void *context) {
    Gfx *dlStart, *dlHead;
    struct Object *objectGraphNode;
    struct GraphNodeGenerated *currentGraphNode;
    s32 index = 0;

    dlStart = NULL;

    if (callContext == GEO_CONTEXT_RENDER) {
        objectGraphNode = (struct Object *) gCurGraphNodeObject;
        currentGraphNode = (struct GraphNodeGenerated *) node;

        if (gCurGraphNodeHeldObject != NULL) {
            objectGraphNode = gCurGraphNodeHeldObject->objNode;
        }

        if (((objectGraphNode->oBehParams >> 8) & 0xFF) == 0) {
            index = get_l8_boogoo_index();
        } else {
            index = ((objectGraphNode->oBehParams >> 8) & 0xFF) - 1;
        }

        dlStart = alloc_display_list(sizeof(Gfx) * 3);
        dlHead = dlStart;


        if (objectGraphNode->oOpacity == 0xFF) {
            currentGraphNode->fnNode.node.flags = 0x100 | (currentGraphNode->fnNode.node.flags & 0xFF);
            objectGraphNode->oAnimState = 0;
        } else {
            currentGraphNode->fnNode.node.flags = 0x500 | (currentGraphNode->fnNode.node.flags & 0xFF);
            objectGraphNode->oAnimState = 1;
        }

        gDPSetEnvColor(dlHead++, sBooGooColors[index][0], sBooGooColors[index][1], sBooGooColors[index][2], objectGraphNode->oOpacity);
        gSPEndDisplayList(dlHead);
    }

    return dlStart;
}


Gfx *geo_update_layer_transparency(s32 callContext, struct GraphNode *node, UNUSED void *context) {
    Gfx *dlStart, *dlHead;
    struct Object *objectGraphNode;
    struct GraphNodeGenerated *currentGraphNode;
    UNUSED struct GraphNodeGenerated *sp2C;
    s32 objectOpacity;

    dlStart = NULL;

    if (callContext == GEO_CONTEXT_RENDER) {
        objectGraphNode = (struct Object *) gCurGraphNodeObject; // TODO: change this to object pointer?
        currentGraphNode = (struct GraphNodeGenerated *) node;
        sp2C = (struct GraphNodeGenerated *) node;

        if (gCurGraphNodeHeldObject != NULL) {
            objectGraphNode = gCurGraphNodeHeldObject->objNode;
        }

        objectOpacity = objectGraphNode->oOpacity;
        dlStart = alloc_display_list(sizeof(Gfx) * 3);

        dlHead = dlStart;

        if (objectOpacity == 0xFF) {
            if (currentGraphNode->parameter == 20) {
                currentGraphNode->fnNode.node.flags =
                0x600 | (currentGraphNode->fnNode.node.flags & 0xFF);
            } else {
                currentGraphNode->fnNode.node.flags =
                0x100 | (currentGraphNode->fnNode.node.flags & 0xFF);
            }

            objectGraphNode->oAnimState = 0;
        } else {
            if (currentGraphNode->parameter == 20) {
                currentGraphNode->fnNode.node.flags =
                0x600 | (currentGraphNode->fnNode.node.flags & 0xFF);
            } else {
                currentGraphNode->fnNode.node.flags =
                0x500 | (currentGraphNode->fnNode.node.flags & 0xFF);
            }

            objectGraphNode->oAnimState = 1;

            if (objectOpacity == 0 && segmented_to_virtual(bhvBowser) == objectGraphNode->behavior) {
                objectGraphNode->oAnimState = 2;
            }
            // the debug info check was removed in US. so we need to
            // perform the only necessary check instead of the debuginfo
            // one.
            if (currentGraphNode->parameter != 10) {
                if (objectGraphNode->activeFlags & ACTIVE_FLAG_DITHERED_ALPHA) {
                    gDPSetAlphaCompare(dlHead++, G_AC_DITHER);
                }
            }
        }

        gDPSetEnvColor(dlHead++, 255, 255, 255, objectOpacity);
        gSPEndDisplayList(dlHead);
    }

    return dlStart;
}


s32 gMusicFloorDistance;
extern s16 sInstPos[4][2];
extern s32 sInstDist[4];

Gfx *geo_update_music_floor(s32 callContext, struct GraphNode *node, UNUSED void *context) {
    s32 i, k;
    s32 dist;
    Vtx *vert;
    Vec3s marioPos;
    if (callContext == GEO_CONTEXT_RENDER) {
        vec3f_to_vec3s(marioPos, gMarioState->pos);
        marioPos[0] -= 8796;
        marioPos[2] -= 14423;
        if (gMarioState->floor != NULL && gMarioState->floor->type == SURFACE_MUSIC_PLATE) {
            gMusicFloorDistance = approach_s32(gMusicFloorDistance, 3000*3000*2, 0x80000, 0x80000);
        } else {
            gMusicFloorDistance = approach_s32(gMusicFloorDistance, 1000*1000*2, 0x40000, 0x40000);
        }
        vert = segmented_to_virtual(&hmc_dl_MUSICFLOOR_mesh_layer_1_vtx_0);
        for (i = 0; i < sizeof(hmc_dl_MUSICFLOOR_mesh_layer_1_vtx_0) / sizeof(hmc_dl_MUSICFLOOR_mesh_layer_1_vtx_0[0]); i++) {
            dist = absi((marioPos[0] - vert[i].v.ob[0]) * (marioPos[0] - vert[i].v.ob[0]) + 
                    (marioPos[2] - vert[i].v.ob[2]) * (marioPos[2] - vert[i].v.ob[2]));
            if (dist <= gMusicFloorDistance) {
                vert[i].v.cn[3] = (f32)(gMusicFloorDistance - dist) / (f32)(gMusicFloorDistance) * 255;
                    // approach_s16_symmetric(vert[i].v.cn[3], (((f32)(gMusicFloorDistance - dist) / (f32)gMusicFloorDistance) * 255), 0x8);
            } else if (vert[i].v.cn[3] != 0) {
                vert[i].v.cn[3] = 0;
            }
            // UV generating code
            // vert[i].v.tc[0] = (gMarioState->pos[0] - vert[i].v.ob[0]) * 2;
            // vert[i].v.tc[1] = (gMarioState->pos[2] - vert[i].v.ob[2]) * 2;
        }
        // Code for additional points
        for (k = 0; k < 4; k++) {
            if (sInstDist[k] == 0) {
                continue;
            }
            for (i = 0; i < sizeof(hmc_dl_MUSICFLOOR_mesh_layer_1_vtx_0) / sizeof(hmc_dl_MUSICFLOOR_mesh_layer_1_vtx_0[0]); i++) {
                dist = absi((sInstPos[k][0] - vert[i].v.ob[0]) * (sInstPos[k][0] - vert[i].v.ob[0]) + 
                        (sInstPos[k][1] - vert[i].v.ob[2]) * (sInstPos[k][1] - vert[i].v.ob[2]));
                if (dist <= sInstDist[k]) {
                    s16 add = (1.0f - (f32)(dist) / sInstDist[k]) * 255;
                    vert[i].v.cn[3] += add;
                    if (vert[i].v.cn[3] < add) {
                        vert[i].v.cn[3] = 255;
                    }
                }
            }
        }

    }
    return NULL;
}


Vtx *sVanishVerts[] = {
    &hmc_dl_MUSICFLOOR_Hall_mesh_layer_1_vtx_0,
    &hmc_dl_MUSICFLOOR_Trophy_mesh_layer_1_vtx_0,
    &hmc_dl_Maze_mesh_layer_1_vtx_0,
    &hmc_dl_Maze_mesh_layer_1_vtx_1,
    &hmc_dl_MazeNoCol_mesh_layer_1_vtx_0,
    &hmc_dl_MazeNoCol_mesh_layer_1_vtx_1,
    &hmc_dl_BelowMaze_mesh_layer_1_vtx_0,
    &hmc_dl_BelowMaze_mesh_layer_1_vtx_1,
    &lll_dl_MUSICFLOOR_Chamber_mesh_layer_1_vtx_0,
    &lll_dl_MUSICFLOOR_Cellar_mesh_layer_1_vtx_0,
    &ssl_dl_BGMuiscFloor_mesh_layer_1_vtx_0,
    &ssl_dl_MUSICFLOOR_Palace_mesh_layer_1_vtx_0,
};

s16 sVanishVertCounts[] = {
    sizeof(hmc_dl_MUSICFLOOR_Hall_mesh_layer_1_vtx_0) / 16,
    sizeof(hmc_dl_MUSICFLOOR_Trophy_mesh_layer_1_vtx_0) / 16,
    sizeof(hmc_dl_Maze_mesh_layer_1_vtx_0) / 16,
    sizeof(hmc_dl_Maze_mesh_layer_1_vtx_1) / 16,
    sizeof(hmc_dl_MazeNoCol_mesh_layer_1_vtx_0) / 16,
    sizeof(hmc_dl_MazeNoCol_mesh_layer_1_vtx_1) / 16,
    sizeof(hmc_dl_BelowMaze_mesh_layer_1_vtx_0) / 16,
    sizeof(hmc_dl_BelowMaze_mesh_layer_1_vtx_1) / 16,
    sizeof(lll_dl_MUSICFLOOR_Chamber_mesh_layer_1_vtx_0) / 16,
    sizeof(lll_dl_MUSICFLOOR_Cellar_mesh_layer_1_vtx_0) / 16,
    sizeof(ssl_dl_BGMuiscFloor_mesh_layer_1_vtx_0) / 16,
    sizeof(ssl_dl_MUSICFLOOR_Palace_mesh_layer_1_vtx_0) / 16,
};

s16 sVanishVertDists[] = {
    1000,
    1000,
    1000,
    2500,
    1000,
    2500,
    2500,
    2500,
    1000,
    1000,
    7000,
    1000,
};

Gfx *geo_update_vanish_floor(s32 callContext, struct GraphNode *node, UNUSED void *context) {
    s32 i;
    s32 dist, distDefault;
    Vtx *vert;
    Vec3s marioPos;
    struct GraphNodeGenerated *currentGraphNode;
    if (callContext == GEO_CONTEXT_RENDER) {
        currentGraphNode = (struct GraphNodeGenerated *) node;
        vec3f_to_vec3s(marioPos, gMarioState->pos);
        // marioPos[0] -= 8796;
        // marioPos[2] -= 14423;
        vert = segmented_to_virtual(sVanishVerts[currentGraphNode->parameter]);
        distDefault = sVanishVertDists[currentGraphNode->parameter];
        for (i = 0; i < sVanishVertCounts[currentGraphNode->parameter]; i++) {
            dist = absi((marioPos[0] - vert[i].v.ob[0]) * (marioPos[0] - vert[i].v.ob[0]) + 
                    (marioPos[2] - vert[i].v.ob[2]) * (marioPos[2] - vert[i].v.ob[2]));
            if (dist <= distDefault*distDefault*2) {
                vert[i].v.cn[3] = (f32)(distDefault*distDefault*2 - dist) / (f32)(distDefault*distDefault*2) * 255;
            } else if (vert[i].v.cn[3] != 0) {
                vert[i].v.cn[3] = 0;
            }
        }
    }
    return NULL;
}


Gfx *geo_update_bgrock_floor(s32 callContext, struct GraphNode *node, UNUSED void *context) {
    s32 i;
    s32 dist, distDefault;
    Vtx *vert;
    Vec3s marioPos;
    struct GraphNodeGenerated *currentGraphNode;
    if (callContext == GEO_CONTEXT_RENDER) {
        currentGraphNode = (struct GraphNodeGenerated *) node;
        vec3f_to_vec3s(marioPos, gMarioState->pos);
        // marioPos[0] -= 8796;
        // marioPos[2] -= 14423;
        vert = segmented_to_virtual(sVanishVerts[currentGraphNode->parameter]);
        distDefault = sVanishVertDists[currentGraphNode->parameter];
        distDefault *= distDefault * 2;
        for (i = 0; i < sVanishVertCounts[currentGraphNode->parameter]; i++) {
            dist = absi((marioPos[0] - vert[i].v.ob[0]) * (marioPos[0] - vert[i].v.ob[0]) + 
                    (marioPos[2] - vert[i].v.ob[2]) * (marioPos[2] - vert[i].v.ob[2]));
            if (dist <= distDefault) {
                if (distDefault - dist >= distDefault - 82000000) {
                    vert[i].v.cn[3] = 255;
                } else {
                    vert[i].v.cn[3] = (f32)((distDefault - dist)) / (f32)(distDefault - 82000000) * 255;
                }
            } else if (vert[i].v.cn[3] != 0) {
                vert[i].v.cn[3] = 0;
            }
        }
        // print_text_fmt_int(80, 80, "%d", (s32)dist, 0);
    }
    return NULL;
}


Gfx *geo_update_plathall_floor(s32 callContext, struct GraphNode *node, UNUSED void *context) {
    s32 i;
    s32 dist;
    Vtx *vert;
    Vec3s marioPos;
    struct GraphNodeGenerated *currentGraphNode;
    if (callContext == GEO_CONTEXT_RENDER) {
        currentGraphNode = (struct GraphNodeGenerated *) node;
        vec3f_to_vec3s(marioPos, gMarioState->pos);
        // marioPos[0] -= 8796;
        // marioPos[2] -= 14423;
        vert = segmented_to_virtual(sVanishVerts[currentGraphNode->parameter]);
        for (i = 0; i < sVanishVertCounts[currentGraphNode->parameter]; i++) {
            dist = absi((marioPos[0] - vert[i].v.ob[0]) * (marioPos[0] - vert[i].v.ob[0]) + 
                    (marioPos[2] - vert[i].v.ob[2]) * (marioPos[2] - vert[i].v.ob[2]));
            if (dist <= 2500*2500*2) {
                vert[i].v.cn[3] = ((f32)(2500*2500*2 - dist) / (f32)(2500*2500*2) * 73);
            } else if (vert[i].v.cn[3] != 0) {
                vert[i].v.cn[3] = 0;
            }
        }
    }
    return NULL;
}




Gfx *geo_update_golden_crate(s32 callContext, struct GraphNode *node, UNUSED void *context) {
    s32 i;
    s32 dist;
    s32 baseDist;
    Vtx *vert;
    Vec3s marioPos;
    struct Object *obj;
    struct GraphNodeGenerated *currentGraphNode;
    if (callContext == GEO_CONTEXT_RENDER) {
        currentGraphNode = (struct GraphNodeGenerated *) node;
        obj = (struct Object *) gCurGraphNodeObject;
        vec3f_to_vec3s(marioPos, gMarioState->pos);
        marioPos[0] -= obj->oPosX;
        marioPos[2] -= obj->oPosZ;
        vert = segmented_to_virtual(&golden_crate_crate_mesh_layer_1_vtx_0);
        for (i = 0; i < 24; i++) {
            dist = absi((marioPos[0] - vert[i].v.ob[0]) * (marioPos[0] - vert[i].v.ob[0]) + 
                    (marioPos[2] - vert[i].v.ob[2]) * (marioPos[2] - vert[i].v.ob[2]));
            if (((obj->oBehParams >> 8) & 0xFF) == 10 || ((obj->oBehParams >> 8) & 0xFF) == 11) {
                dist = 0;
            }

            if (gCurrLevelNum == LEVEL_WF) {
                baseDist = 900*900*2;
            } else {
                baseDist = 400*400*2;
            }

            if (dist <= baseDist) {
                vert[i].v.cn[3] = ((f32)(baseDist - dist) / (f32)(baseDist) * 255);
            } else if (vert[i].v.cn[3] != 0) {
                vert[i].v.cn[3] = 0;
            }
        }
    }
    return NULL;
}








extern Vtx opening_wall_openingwall_mesh_layer_5_vtx_0[4];

Vtx *sOHVerts[] = {
    &hmc_dl_OpeningHall_001_mesh_layer_1_vtx_0,
    &hmc_dl_OpeningHall_001_mesh_layer_1_vtx_1,
    &hmc_dl_OpeningHall_001_mesh_layer_1_vtx_2,
    &hmc_dl_OpeningHall_001_mesh_layer_1_vtx_3,
    &hmc_dl_OpeningHallObjects_mesh_layer_1_vtx_0,
    &hmc_dl_OpeningHallObjects_mesh_layer_1_vtx_1,
    &hmc_dl_OpeningHallObjects_mesh_layer_1_vtx_2,
    &hmc_dl_OpeningHallObjects_mesh_layer_1_vtx_3,
    &hmc_dl_OpeningHallObjects_mesh_layer_4_vtx_0,
    &hmc_dl_OpeningHallPlants_mesh_layer_1_vtx_0,
    &hmc_dl_OpeningHallPlants_mesh_layer_1_vtx_1,
    &hmc_dl_OpeningHallPlants_mesh_layer_1_vtx_2,
    &hmc_dl_OpeningHallPlants_mesh_layer_1_vtx_3,
    &hmc_dl_OpeningHallPlants_mesh_layer_1_vtx_4,
    &hmc_dl_OpeningHallPlants_mesh_layer_4_vtx_0,
    &hmc_dl_OpeningHallPlants_mesh_layer_4_vtx_1,
    &hmc_dl_OpeningHallCushions_mesh_layer_1_vtx_0,
    &opening_wall_openingwall_mesh_layer_5_vtx_0,
};

s16 sOHVertCounts[] = {
    sizeof(hmc_dl_OpeningHall_001_mesh_layer_1_vtx_0) / 16,
    sizeof(hmc_dl_OpeningHall_001_mesh_layer_1_vtx_1) / 16,
    sizeof(hmc_dl_OpeningHall_001_mesh_layer_1_vtx_2) / 16,
    sizeof(hmc_dl_OpeningHall_001_mesh_layer_1_vtx_3) / 16,
    sizeof(hmc_dl_OpeningHallObjects_mesh_layer_1_vtx_0) / 16,
    sizeof(hmc_dl_OpeningHallObjects_mesh_layer_1_vtx_1) / 16,
    sizeof(hmc_dl_OpeningHallObjects_mesh_layer_1_vtx_2) / 16,
    sizeof(hmc_dl_OpeningHallObjects_mesh_layer_1_vtx_3) / 16,
    sizeof(hmc_dl_OpeningHallObjects_mesh_layer_4_vtx_0) / 16,
    sizeof(hmc_dl_OpeningHallPlants_mesh_layer_1_vtx_0) / 16,
    sizeof(hmc_dl_OpeningHallPlants_mesh_layer_1_vtx_1) / 16,
    sizeof(hmc_dl_OpeningHallPlants_mesh_layer_1_vtx_2) / 16,
    sizeof(hmc_dl_OpeningHallPlants_mesh_layer_1_vtx_3) / 16,
    sizeof(hmc_dl_OpeningHallPlants_mesh_layer_1_vtx_4) / 16,
    sizeof(hmc_dl_OpeningHallPlants_mesh_layer_4_vtx_0) / 16,
    sizeof(hmc_dl_OpeningHallPlants_mesh_layer_4_vtx_1) / 16,
    sizeof(hmc_dl_OpeningHallCushions_mesh_layer_1_vtx_0) / 16,
    sizeof(opening_wall_openingwall_mesh_layer_5_vtx_0) / 16,
};

s32 sOHDist = 15000;
s32 sOHRevert = 0;


Gfx *geo_update_openinghall_floor(s32 callContext, struct GraphNode *node, UNUSED void *context) {
    s32 i, h;
    s32 dist;
    s32 baseDist;
    Vtx *vert;
    Vec3s marioPos;
    struct GraphNodeGenerated *currentGraphNode;
    if (callContext == GEO_CONTEXT_RENDER) {
        currentGraphNode = (struct GraphNodeGenerated *) node;
        vec3f_to_vec3s(marioPos, gMarioState->pos);
        if (sOHRevert) {
            sOHDist = approach_s16_symmetric(sOHDist, 15000, 250);
        } else if (save_file_get_newflags(1) & SAVE_TOAD_FLAG_ENTER_L6) {
            sOHDist = approach_s16_symmetric(sOHDist, 3500, 175);
        }
        baseDist = sOHDist*sOHDist*2;
        for (h = 0; h < 18; h++) {
            vert = segmented_to_virtual(sOHVerts[h]);
            if (h == 17) {
                marioPos[0] -= -10081;
                marioPos[2] -= 12063;
            }
            for (i = 0; i < sOHVertCounts[h]; i++) {
                dist = absi((marioPos[0] - vert[i].v.ob[0]) * (marioPos[0] - vert[i].v.ob[0]) + 
                        (marioPos[2] - vert[i].v.ob[2]) * (marioPos[2] - vert[i].v.ob[2]));
                if (dist <= baseDist) {
                    vert[i].v.cn[0] = ((f32)(baseDist - dist) / (f32)(baseDist) * 255);
                    vert[i].v.cn[2] = vert[i].v.cn[1] = vert[i].v.cn[0];
                } else if (vert[i].v.cn[0] != 0) {
                    vert[i].v.cn[0] = 0;
                    vert[i].v.cn[1] = 0;
                    vert[i].v.cn[2] = 0;
                }
            }
        }
    }
    return NULL;
}

Gfx *geo_update_hall_fakewall(s32 callContext, struct GraphNode *node, UNUSED void *context) {
    Gfx *dlStart, *dlHead;
    struct MarioState *m = gMarioState;
    struct GraphNodeGenerated *currentGraphNode;
    u8 opacity;

    dlStart = NULL;

    if (callContext == GEO_CONTEXT_RENDER) {
        currentGraphNode = (struct GraphNodeGenerated *) node;

        if (m->pos[2] > 2000.0f) {
            opacity = 0xFF;
        } else if (m->pos[2] < -2500.0f) {
            opacity = 0xD0;
        } else {
            opacity = 0xD0 + ((m->pos[2] + 2500.0f) / 4500.0f) * 0x2F;
        }

        currentGraphNode->fnNode.node.flags = 0x100 | (currentGraphNode->fnNode.node.flags & 0xFF);
        dlStart = alloc_display_list(sizeof(Gfx) * 3);

        dlHead = dlStart;

        gDPSetEnvColor(dlHead++, 255, 255, 255, opacity);
        gSPEndDisplayList(dlHead);
    }
    return dlStart;
}




void make_vertex(Vtx *vtx, s32 n, s16 x, s16 y, s16 z, s16 tx, s16 ty, u8 r, u8 g, u8 b, u8 a);


s16 sBeamOffsets[4][2] = {
    {19, 506}, {19, -506},
    {-19, 506}, {-19, -506},
};

void generate_tight_rope_beam_verts(Vtx *vertexBuffer, struct Object *obj, s16 count) {
    s16 height = obj->os16F4;
    s16 heightOffset = -4000 - (s16)obj->oPosX; // vanilla -1000
    s16 xOff = sBeamOffsets[count][0];
    s16 zOff = sBeamOffsets[count][1];
    make_vertex(vertexBuffer, 0, -6 + xOff, height, 6 + zOff, -16, 2032, 0x88, 0xA3, 0xAF, 0xFF);
    make_vertex(vertexBuffer, 1, 6 + xOff,  height, 6 + zOff,  496, 2032, 0x88, 0xA3, 0xAF, 0xFF);
    make_vertex(vertexBuffer, 2, 6 + xOff,  height, -6 + zOff, 496, -16, 0x88, 0xA3, 0xAF, 0xFF);
    make_vertex(vertexBuffer, 3, -6 + xOff, height, -6 + zOff, -16, -16, 0x88, 0xA3, 0xAF, 0xFF);
    make_vertex(vertexBuffer, 4, -6 + xOff, height, 6 + zOff, -528, 135152, 0x88, 0xA3, 0xAF, 0xFF);
    make_vertex(vertexBuffer, 5, -6 + xOff, height + heightOffset, -6 + zOff, -16, -135152, 0x88, 0xA3, 0xAF, 0xFF);
    make_vertex(vertexBuffer, 6, -6 + xOff, height + heightOffset, 6 + zOff, -528, -135152, 0x88, 0xA3, 0xAF, 0xFF);
    make_vertex(vertexBuffer, 7, -6 + xOff, height, -6 + zOff, -16, 135152, 0x88, 0xA3, 0xAF, 0xFF);
    make_vertex(vertexBuffer, 8, 6 + xOff,  height + heightOffset, -6 + zOff, 496, -135152, 0x88, 0xA3, 0xAF, 0xFF);
    make_vertex(vertexBuffer, 9, 6 + xOff,  height, -6 + zOff, -496, 135152, 0x88, 0xA3, 0xAF, 0xFF);
    make_vertex(vertexBuffer, 10, 6 + xOff, height, 6 + zOff, 496, -135152, 0x88, 0xA3, 0xAF, 0xFF);
    make_vertex(vertexBuffer, 11,-6 + xOff, height, 6 + zOff, -16, -135152, 0x88, 0xA3, 0xAF, 0xFF);
    make_vertex(vertexBuffer, 12,-6 + xOff, height + heightOffset, 6 + zOff, -16, 135152, 0x88, 0xA3, 0xAF, 0xFF);
    make_vertex(vertexBuffer, 13, 6 + xOff, height + heightOffset, 6 + zOff, 496, 135152, 0x88, 0xA3, 0xAF, 0xFF);
    make_vertex(vertexBuffer, 14, 6 + xOff, height, -6 + zOff, 1008, -135152, 0x88, 0xA3, 0xAF, 0xFF);
    make_vertex(vertexBuffer, 15, 6 + xOff, height + heightOffset, -6 + zOff, 1008, 135152, 0x88, 0xA3, 0xAF, 0xFF);
}

Gfx *generate_tight_rope_beams(Gfx *dlHead, Vtx *vertexBuffer, s16 var) {
    if (var == 1) {
        gSPDisplayList(dlHead++, mat_hmc_dl_Border);
    }

    gSPVertex(dlHead++, VIRTUAL_TO_PHYSICAL(vertexBuffer), 16, 0);
	gSP2Triangles(dlHead++, 0, 1, 2, 0, 0, 2, 3, 0);
	gSP2Triangles(dlHead++, 4, 5, 6, 0, 4, 7, 5, 0);
	gSP2Triangles(dlHead++, 7, 8, 5, 0, 7, 9, 8, 0);
	gSP2Triangles(dlHead++, 10, 11, 12, 0, 10, 12, 13, 0);
	gSP2Triangles(dlHead++, 14, 10, 13, 0, 14, 13, 15, 0);
    
    if (var == 2) {
        gSPDisplayList(dlHead++, mat_revert_hmc_dl_Border);
    }
    return dlHead;
}

Gfx *geo_generate_tight_rope(s32 callContext, struct GraphNode *node, void *context) {
    Vtx *vertexBuffer;
    Vtx *vertexBuffer1, *vertexBuffer2, *vertexBuffer3, *vertexBuffer4;
    Gfx *dlStart, *dlHead;
    struct Object *obj;
    struct GraphNodeGenerated *currentGraphNode;
    s32 objectHeight;
    s16 firstUVs, secondUVs;
    s16 firstPos, secondPos;
    s16 uvMax;

    currentGraphNode = node;

    if (callContext == GEO_CONTEXT_RENDER) {
        obj = (struct Object *) gCurGraphNodeObject;

        currentGraphNode->fnNode.node.flags = 0x400 | (currentGraphNode->fnNode.node.flags & 0xFF);

        vertexBuffer = alloc_display_list(16 * sizeof(Vtx));

        uvMax = TIGHT_ROPE_MAX * obj->header.gfx.scale[2];
        if (uvMax < 0) {
            uvMax = 0x7FFF;
        }
        firstPos = (500 + obj->os16F6) / 2;
        firstUVs = (s16)((500.0f - (f32)firstPos) / 1000.0f * uvMax);
        secondPos = (obj->os16F6 - 500) / 2;
        secondUVs = (s16)((500.0f - (f32)secondPos) / 1000.0f * uvMax);

        make_vertex(vertexBuffer, 0, -25, obj->os16F4, 500, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
        make_vertex(vertexBuffer, 1, 25, obj->os16F4, 500, 2048, 0, 0xFF, 0xFF, 0xFF, 0xFF);


        make_vertex(vertexBuffer, 2, -25, obj->os16F4 / 3, firstPos, 0, firstUVs, 0xFF, 0xFF, 0xFF, 0xFF);
        make_vertex(vertexBuffer, 3, 25, obj->os16F4 / 3, firstPos, 2048, firstUVs, 0xFF, 0xFF, 0xFF, 0xFF);

        // Central.
        make_vertex(vertexBuffer, 4, -25, 0, obj->os16F6, 0, obj->os16F8, 0xFF, 0xFF, 0xFF, 0xFF);
        make_vertex(vertexBuffer, 5, 25, 0, obj->os16F6, 2048, obj->os16F8, 0xFF, 0xFF, 0xFF, 0xFF);

        make_vertex(vertexBuffer, 6, -25, obj->os16F4 / 3, secondPos, 0, secondUVs, 0xFF, 0xFF, 0xFF, 0xFF);
        make_vertex(vertexBuffer, 7, 25, obj->os16F4 / 3, secondPos, 2048, secondUVs, 0xFF, 0xFF, 0xFF, 0xFF);

        make_vertex(vertexBuffer, 8, -25, obj->os16F4, -500, 0, uvMax, 0xFF, 0xFF, 0xFF, 0xFF);
        make_vertex(vertexBuffer, 9, 25, obj->os16F4, -500, 2048, uvMax, 0xFF, 0xFF, 0xFF, 0xFF);
        

        vertexBuffer1 = alloc_display_list(16 * sizeof(Vtx));
        generate_tight_rope_beam_verts(vertexBuffer1, obj, 0);
        vertexBuffer2 = alloc_display_list(16 * sizeof(Vtx));
        generate_tight_rope_beam_verts(vertexBuffer2, obj, 1);
        vertexBuffer3 = alloc_display_list(16 * sizeof(Vtx));
        generate_tight_rope_beam_verts(vertexBuffer3, obj, 2);
        vertexBuffer4 = alloc_display_list(16 * sizeof(Vtx));
        generate_tight_rope_beam_verts(vertexBuffer4, obj, 3);

        dlHead = alloc_display_list(sizeof(Gfx) * (8 + 26));
        dlStart = dlHead;

        gSPDisplayList(dlHead++, mat_hmc_dl_TightRope_002);

        gSPVertex(dlHead++, VIRTUAL_TO_PHYSICAL(vertexBuffer), 10, 0);
        gSP2Triangles(dlHead++, 0, 1, 2, 0, 1, 2, 3, 0);
        gSP2Triangles(dlHead++, 2, 3, 4, 0, 3, 4, 5, 0);

        gSP2Triangles(dlHead++, 4, 5, 6, 0, 5, 6, 7, 0);
        gSP2Triangles(dlHead++, 6, 7, 8, 0, 7, 8, 9, 0);
        
        gSPDisplayList(dlHead++, mat_revert_hmc_dl_TightRope_002);

        dlHead = generate_tight_rope_beams(dlHead, vertexBuffer1, 1);
        dlHead = generate_tight_rope_beams(dlHead, vertexBuffer2, 0);
        dlHead = generate_tight_rope_beams(dlHead, vertexBuffer3, 0);
        dlHead = generate_tight_rope_beams(dlHead, vertexBuffer4, 2);
        
        gSPEndDisplayList(dlHead++);
    }
    return dlStart;
    
}



s32 sLavaWavePos = 5000;
s32 sLavaWaveHeight = 325;
s16 sLavaSinsTimer = 0;
s16 sLavaHitTimer = 5;
s16 sLavaBaseLevel = 0;
s16 sLavaSpread = 500;
s16 sLavaReverse = 0;
u8 sLavaColor = 0xFF;


void calc_lava_wave_collision(struct MarioState *m) {
    f32 height;
    if (sLavaHitTimer > 0) {
        sLavaHitTimer--;
        return;
    }
    if (m->pos[0] > -2580 - 1875) {
        if (m->pos[1] > 1500.0f && m->floorHeight >= 1500.0f) {
            sLavaBaseLevel = 1;
        } else if (m->pos[1] < 1000.0f && m->floorHeight < 1000.0f) {
            sLavaBaseLevel = 0;
        }
        if (m->pos[2] < -896.0f + (sLavaWavePos + sLavaSpread) && m->pos[2] > -896.0f + (sLavaWavePos - sLavaSpread)) {
            height = 500.0f + (sLavaWaveHeight * ((1000.0f - absf(m->pos[2] - (-896.0f + sLavaWavePos)))/1000.0f));
            if (m->pos[1] < height) {
                CL_Lava_Boost(0);
                sLavaHitTimer = 30;
            }
        }
    } else {
        sLavaBaseLevel = 0;
    }

}

extern f32 gGlobalSoundSource[3];


Gfx *geo_generate_lava_wave(s32 callContext, struct GraphNode *node, void *context) {
    Vtx *vertexBuffer;
    Gfx *dlStart, *dlHead;
    struct GraphNodeGenerated *currentGraphNode;
    s32 objectHeight;
    s16 firstUVs1, secondUVs1, firstUVs2, secondUVs2;
    s16 firstPos1, secondPos1, firstPos2, secondPos2;
    s16 lavabaseheight, baseheightapproach;

    currentGraphNode = node;

    if (callContext == GEO_CONTEXT_RENDER) {

        currentGraphNode->fnNode.node.flags = 0x100 | (currentGraphNode->fnNode.node.flags & 0xFF);

        vertexBuffer = alloc_display_list(16 * sizeof(Vtx));

        if (sCurrPlayMode != 2 && gMarioState->action != ACT_STAR_DANCE_NO_EXIT && gMarioState->action != ACT_STAR_DANCE_WATER
            && CL_objptr_nearest_object_behavior(gMarioObject, bhvStarSpawnCoordinates) == NULL) {
            // sLavaSinsTimer += 0xE0;
            if (!sLavaReverse) {
                sLavaWavePos -= 75;
                if (sLavaWavePos < -5000) {
                    if (sLavaBaseLevel) {
                        sLavaReverse = 1;
                    } else {
                        sLavaWavePos = 5000;
                    }
                }
            } else {
                sLavaWavePos += 75;
                if (sLavaWavePos > 5000) {
                    if (!sLavaBaseLevel) {
                        sLavaReverse = 0;
                    } else {
                        sLavaWavePos = -5000;
                    }
                }
            }

            if (sLavaWavePos < 1000) {
                if (!sLavaReverse) {
                    lavabaseheight = 325;
                } else {
                    lavabaseheight = 1300;
                }
            } else {
                if (!sLavaReverse) {
                    lavabaseheight = 450;
                } else {
                    lavabaseheight = 325;
                }
            }

            if (sLavaBaseLevel) {
                if (!sLavaReverse) {
                    baseheightapproach = 0;
                } else {
                    baseheightapproach = 30;
                }
            } else {
                if (sLavaWaveHeight > 500) {
                    baseheightapproach = 20;
                } else {
                    baseheightapproach = 2;
                }
            }
            sLavaWaveHeight = approach_s16_symmetric(sLavaWaveHeight, lavabaseheight, baseheightapproach);

            if (sLavaBaseLevel) {
                sLavaSpread = approach_s16_symmetric(sLavaSpread, 800, 20);
                sLavaColor = approach_s16_symmetric(sLavaColor, 0, 0x4);
            } else {
                sLavaSpread = approach_s16_symmetric(sLavaSpread, 500, 20);
                sLavaColor = approach_s16_symmetric(sLavaColor, 0xFF, 0x4);
            }
            if (((s32)(random_float() * 16.0f)) == 8) {
                play_sound(SOUND_GENERAL_QUIET_BUBBLE2, gGlobalSoundSource);
            }
        }

        firstPos1 = sLavaWavePos + sLavaSpread;
        secondPos1 = sLavaWavePos - sLavaSpread;
        firstPos2 = sLavaWavePos + (sLavaSpread * 0.6f);
        secondPos2 = sLavaWavePos - (sLavaSpread * 0.6f);
        firstUVs1 = -2500 * ((f32)(firstPos1) / 5000.0f);
        secondUVs1 = -2500 * ((f32)(secondPos1) / 5000.0f);
        firstUVs2 = -2500 * ((f32)(firstPos2) / 5000.0f);
        secondUVs2 = -2500 * ((f32)(secondPos2) / 5000.0f);

        make_vertex(vertexBuffer, 0, 1875, 0, 5000, 0, -2500, 0xFF, 0xFF, 0xFF, 0xFF);
        make_vertex(vertexBuffer, 1, -1875, 0, 5000, 3048, -2500, 0xFF, 0xFF, 0xFF, 0xFF);

        make_vertex(vertexBuffer, 2, 1875, 0, firstPos1, 0, firstUVs1, 0xFF, 0xFF, 0xFF, 0xFF);
        make_vertex(vertexBuffer, 3, -1875, 0, firstPos1, 3048, firstUVs1, 0xFF, 0xFF, 0xFF, 0xFF);

        make_vertex(vertexBuffer, 4, 1875, (sLavaWaveHeight * 0.7), firstPos2, 0, firstUVs2, 0xFF, sLavaColor, sLavaColor, 0xFF);
        make_vertex(vertexBuffer, 5, -1875, (sLavaWaveHeight * 0.7), firstPos2, 3048, firstUVs2, 0xFF, sLavaColor, sLavaColor, 0xFF);

        // Central.
        make_vertex(vertexBuffer, 6, 1875, sLavaWaveHeight, sLavaWavePos, 0, -2500 * ((f32)(sLavaWavePos) / 5000.0f), 0xFF, sLavaColor, sLavaColor, 0xFF);
        make_vertex(vertexBuffer, 7, -1875, sLavaWaveHeight, sLavaWavePos, 3048, -2500 * ((f32)(sLavaWavePos) / 5000.0f), 0xFF, sLavaColor, sLavaColor, 0xFF);

        make_vertex(vertexBuffer, 8, 1875, (sLavaWaveHeight * 0.7), secondPos2, 0, secondUVs2, 0xFF, sLavaColor, sLavaColor, 0xFF);
        make_vertex(vertexBuffer, 9, -1875, (sLavaWaveHeight * 0.7), secondPos2, 3048, secondUVs2, 0xFF, sLavaColor, sLavaColor, 0xFF);

        make_vertex(vertexBuffer, 10, 1875, 0, secondPos1, 0, secondUVs1, 0xFF, 0xFF, 0xFF, 0xFF);
        make_vertex(vertexBuffer, 11, -1875, 0, secondPos1, 3048, secondUVs1, 0xFF, 0xFF, 0xFF, 0xFF);


        make_vertex(vertexBuffer, 12, 1875, 0, -5000, 0, 2500, 0xFF, 0xFF, 0xFF, 0xFF);
        make_vertex(vertexBuffer, 13, -1875, 0, -5000, 3048, 2500, 0xFF, 0xFF, 0xFF, 0xFF);
        
        dlHead = alloc_display_list(sizeof(Gfx) * (11));
        dlStart = dlHead;

        gSPDisplayList(dlHead++, mat_hmc_dl_SaunaLavaDyn_001_v5_001_layer1);

        gSPVertex(dlHead++, VIRTUAL_TO_PHYSICAL(vertexBuffer), 14, 0);
        // gSP2Triangles(dlHead++, 8, 1, 0, 0, 1, 8, 9, 0);
        gSP2Triangles(dlHead++, 2, 1, 0, 0, 1, 2, 3, 0);
        gSP2Triangles(dlHead++, 4, 3, 2, 0, 3, 4, 5, 0);

        gSP2Triangles(dlHead++, 6, 5, 4, 0, 5, 6, 7, 0);
        gSP2Triangles(dlHead++, 8, 7, 6, 0, 7, 8, 9, 0);

        gSP2Triangles(dlHead++, 10, 9, 8, 0, 9, 10, 11, 0);
        gSP2Triangles(dlHead++, 12, 11, 10, 0, 11, 12, 13, 0);
        
        gSPDisplayList(dlHead++, mat_revert_hmc_dl_SaunaLavaDyn_001_v5_001_layer1);

        gSPEndDisplayList(dlHead++);

        calc_lava_wave_collision(gMarioState);
    }
    return dlStart;
    
}


/*
	{{{-1370, -1335, -337}, 0, {-16, 1008}, {0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{-1661, -1335, -169}, 0, {-16, 1008}, {0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{-1661, -1335, 169}, 0, {-16, 1008}, {0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{0, 0, 0}, 0, {-16, 1008}, {0xFF, 0x0, 0x0, 0xFF}}},
	{{{-1078, -1335, -169}, 0, {-16, 1008}, {0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{-1078, -1335, 169}, 0, {-16, 1008}, {0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{-1370, -1335, 337}, 0, {-16, 1008}, {0xFF, 0xFF, 0xFF, 0xFF}}},
*/




Gfx *geo_generate_cam_beam(s32 callContext, struct GraphNode *node, void *context) {
    Vtx *vertexBuffer;
    Gfx *dlStart, *dlHead;
    struct Object *obj;
    struct GraphNodeGenerated *currentGraphNode;
    s16 height;
    s16 baseX, baseZ, dist;


    currentGraphNode = node;

    if (callContext == GEO_CONTEXT_RENDER) {
        obj = (struct Object *) gCurGraphNodeObject;

        currentGraphNode->fnNode.node.flags = 0x500 | (currentGraphNode->fnNode.node.flags & 0xFF);

        vertexBuffer = alloc_display_list(16 * sizeof(Vtx));

        height = obj->os16F4;
        baseX = obj->os16F8;
        baseZ = obj->os16FA;
        dist = obj->os16FC;

        // MAIN VERT
        make_vertex(vertexBuffer, 3, 0, 0, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);

        // 1
        make_vertex(vertexBuffer, 0, baseX + (sins(0x0000) * dist), height, baseZ + (coss(0x0000) * dist), 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
        
        // 5
        make_vertex(vertexBuffer, 4, baseX + (sins(0x2AAA) * dist), height, baseZ + (coss(0x2AAA) * dist), 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
        
        // 6
        make_vertex(vertexBuffer, 5, baseX + (sins(0x5554) * dist), height, baseZ + (coss(0x5554) * dist), 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
        
        // 7
        make_vertex(vertexBuffer, 6, baseX + (sins(0x7FFE) * dist), height, baseZ + (coss(0x7FFE) * dist), 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
        
        // 3
        make_vertex(vertexBuffer, 2, baseX + (sins(0xAAA8) * dist), height, baseZ + (coss(0xAAA8) * dist), 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
        
        // 2
        make_vertex(vertexBuffer, 1, baseX + (sins(0xD552) * dist), height, baseZ + (coss(0xD552) * dist), 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);

        dlHead = alloc_display_list(sizeof(Gfx) * (4));
        dlStart = dlHead;

        gSPVertex(dlHead++, VIRTUAL_TO_PHYSICAL(vertexBuffer), 7, 0);
        gSPDisplayList(dlHead++, lightbeam_LightBeam_mesh);

        // gSPVertex(dlHead++, VIRTUAL_TO_PHYSICAL(vertexBuffer), 10, 0);
        // gSP2Triangles(dlHead++, 0, 1, 2, 0, 1, 2, 3, 0);
        // gSP2Triangles(dlHead++, 2, 3, 4, 0, 3, 4, 5, 0);

        // gSP2Triangles(dlHead++, 4, 5, 6, 0, 5, 6, 7, 0);
        // gSP2Triangles(dlHead++, 6, 7, 8, 0, 7, 8, 9, 0);
        
        // gSPDisplayList(dlHead++, mat_revert_lightbeam_Beam);
        
        gSPEndDisplayList(dlHead++);
    }
    return dlStart;
    
}


#define CHAIN_UV_Y 16384

Gfx *geo_generate_plat_chain(s32 callContext, struct GraphNode *node, void *context) {
    Vtx *vertexBuffer;
    Gfx *dlStart, *dlHead;
    struct Object *obj;
    struct GraphNodeGenerated *currentGraphNode;

    currentGraphNode = node;

    if (callContext == GEO_CONTEXT_RENDER) {
        obj = (struct Object *) gCurGraphNodeObject;

        currentGraphNode->fnNode.node.flags = 0x500 | (currentGraphNode->fnNode.node.flags & 0xFF);

        vertexBuffer = alloc_display_list(16 * sizeof(Vtx));

        s16 homeY = (obj->oHomeY - obj->oPosY);

        //top X
        make_vertex(vertexBuffer, 0, 0 + 10, homeY + 1200, obj->oFloatF8, 0, CHAIN_UV_Y, 0xFF, 0xFF, 0xFF, 0);
        make_vertex(vertexBuffer, 1, 0 - 10, homeY + 1200, obj->oFloatF8, 1024, CHAIN_UV_Y, 0xFF, 0xFF, 0xFF, 0);
        //bottom X
        make_vertex(vertexBuffer, 2, 10, 40, 0, 0, -CHAIN_UV_Y, 0xFF, 0xFF, 0xFF, 0xFF);
        make_vertex(vertexBuffer, 3, -10, 40, 0, 1024, -CHAIN_UV_Y, 0xFF, 0xFF, 0xFF, 0xFF);

        //top Z
        make_vertex(vertexBuffer, 4, 0, homeY + 1200, obj->oFloatF8 + 10, 0, CHAIN_UV_Y, 0xFF, 0xFF, 0xFF, 0);
        make_vertex(vertexBuffer, 5, 0, homeY + 1200, obj->oFloatF8 - 10, 1024, CHAIN_UV_Y, 0xFF, 0xFF, 0xFF, 0);
        //bottom Z
        make_vertex(vertexBuffer, 6, 0, 40, 10, 0, -CHAIN_UV_Y, 0xFF, 0xFF, 0xFF, 0xFF);
        make_vertex(vertexBuffer, 7, 0, 40, -10, 1024, -CHAIN_UV_Y, 0xFF, 0xFF, 0xFF, 0xFF);


        dlHead = alloc_display_list(sizeof(Gfx) * (7));
        dlStart = dlHead;

        if (gCurrLevelNum != LEVEL_TTC) {
            gSPDisplayList(dlHead++, mat_lll_dl_Chain);
        } else {
            gSPDisplayList(dlHead++, mat_ttc_dl_Chain);
        }

        gSPVertex(dlHead++, VIRTUAL_TO_PHYSICAL(vertexBuffer), 8, 0);
        gSP2Triangles(dlHead++, 0, 1, 2, 0, 1, 2, 3, 0);
        gSP2Triangles(dlHead++, 4, 5, 6, 0, 5, 6, 7, 0);
        
        if (gCurrLevelNum != LEVEL_TTC) {
            gSPDisplayList(dlHead++, mat_revert_lll_dl_Chain);
        } else {
            gSPDisplayList(dlHead++, mat_revert_ttc_dl_Chain);
        }
        
        gSPEndDisplayList(dlHead++);
    }
    return dlStart;
    
}


#define BIG_CHAIN_UV_Y 32767


Gfx *geo_generate_big_plat_chain(s32 callContext, struct GraphNode *node, void *context) {
    Vtx *vertexBuffer;
    Gfx *dlStart, *dlHead;
    struct Object *obj;
    struct GraphNodeGenerated *currentGraphNode;

    currentGraphNode = node;

    if (callContext == GEO_CONTEXT_RENDER) {
        obj = (struct Object *) gCurGraphNodeObject;

        currentGraphNode->fnNode.node.flags = 0x500 | (currentGraphNode->fnNode.node.flags & 0xFF);

        vertexBuffer = alloc_display_list(16 * sizeof(Vtx));

        s16 homeY = (obj->oHomeY - obj->oPosY);
        s16 homeZ = (obj->oHomeZ - obj->oPosZ);

        //top X
        make_vertex(vertexBuffer, 0, 0 + 10, homeY + 2400, homeZ, 0, BIG_CHAIN_UV_Y, 0xFF, 0xFF, 0xFF, 0);
        make_vertex(vertexBuffer, 1, 0 - 10, homeY + 2400, homeZ, 1024, BIG_CHAIN_UV_Y, 0xFF, 0xFF, 0xFF, 0);
        //bottom X
        make_vertex(vertexBuffer, 2, 10, 40, 0, 0, -BIG_CHAIN_UV_Y, 0xFF, 0xFF, 0xFF, 0xFF);
        make_vertex(vertexBuffer, 3, -10, 40, 0, 1024, -BIG_CHAIN_UV_Y, 0xFF, 0xFF, 0xFF, 0xFF);

        //top Z
        make_vertex(vertexBuffer, 4, 0, homeY + 2400, homeZ + 10, 0, BIG_CHAIN_UV_Y, 0xFF, 0xFF, 0xFF, 0);
        make_vertex(vertexBuffer, 5, 0, homeY + 2400, homeZ - 10, 1024, BIG_CHAIN_UV_Y, 0xFF, 0xFF, 0xFF, 0);
        //bottom Z
        make_vertex(vertexBuffer, 6, 0, 40, 10, 0, -BIG_CHAIN_UV_Y, 0xFF, 0xFF, 0xFF, 0xFF);
        make_vertex(vertexBuffer, 7, 0, 40, -10, 1024, -BIG_CHAIN_UV_Y, 0xFF, 0xFF, 0xFF, 0xFF);


        dlHead = alloc_display_list(sizeof(Gfx) * (7));
        dlStart = dlHead;

        gSPDisplayList(dlHead++, mat_lll_dl_Chain);

        gSPVertex(dlHead++, VIRTUAL_TO_PHYSICAL(vertexBuffer), 8, 0);
        gSP2Triangles(dlHead++, 0, 1, 2, 0, 1, 2, 3, 0);
        gSP2Triangles(dlHead++, 4, 5, 6, 0, 5, 6, 7, 0);
        
        gSPDisplayList(dlHead++, mat_revert_lll_dl_Chain);
        
        gSPEndDisplayList(dlHead++);
    }
    return dlStart;
    
}


extern Vtx spinning_plat_splat_mesh_layer_1_vtx_0[61];
extern Gfx spinning_plat_tris1[];
extern Gfx spinning_plat_tris2[];
extern Gfx mat_spinning_plat_WoodFloorTrophyRoom_002_v5_layer1[];
extern Gfx mat_revert_spinning_plat_WoodFloorTrophyRoom_002_v5_layer1[];

Gfx *geo_dynamic_spinning_plat(s32 callContext, struct GraphNode *node, void *context) {
    s32 i;
    s16 angle, x, y;
    f32 mag;
    Vtx *verts;
    Vtx *vertexBuffer;
    f32 aSins, aCoss;
    Gfx *dlStart, *dlHead;
    struct Object *obj;
    struct GraphNodeGenerated *currentGraphNode;

    currentGraphNode = node;

    if (callContext == GEO_CONTEXT_RENDER) {
        obj = (struct Object *) gCurGraphNodeObject;

        currentGraphNode->fnNode.node.flags = 0x100 | (currentGraphNode->fnNode.node.flags & 0xFF);

        vertexBuffer = alloc_display_list(61 * sizeof(Vtx));

        // make_vertex(vertexBuffer, 7, 0, 40, -10, 1024, -BIG_CHAIN_UV_Y, 0xFF, 0xFF, 0xFF, 0xFF);

        // make_spinning_plat_verts(vertexBuffer, 0, 32, obj->oFaceAngleYaw);
        // make_spinning_plat_verts(vertexBuffer2, 32, 32 + 14, obj->oFaceAngleYaw);
        
        // aSins = sins(obj->oFaceAngleYaw);
        // aCoss = coss(obj->oFaceAngleYaw);

        verts = segmented_to_virtual(&spinning_plat_splat_mesh_layer_1_vtx_0);

        bcopy(verts, vertexBuffer, 61 * sizeof(Vtx));
        for (i = 0; i < 61; i++) {
            x = vertexBuffer[i].v.tc[0] - 496;
            y = vertexBuffer[i].v.tc[1] - 496;
            angle = atan2s(y, x) + obj->oFaceAngleYaw;
            mag = sqrtf(x * x + y * y);
            vertexBuffer[i].v.tc[0] = mag * sins(angle);
            vertexBuffer[i].v.tc[1] = mag * coss(angle);
            // make_vertex(vertexBuffer, i, verts[i].v.ob[0], verts[i].v.ob[1], verts[i].v.ob[2], x, 
            //             y, verts[i].v.cn[0], verts[i].v.cn[1], verts[i].v.cn[2], verts[i].v.cn[3]);
        }
        dlHead = alloc_display_list(sizeof(Gfx) * (8));
        dlStart = dlHead;




        gSPDisplayList(dlHead++, mat_spinning_plat_WoodFloorTrophyRoom_002_v5_layer1);

        gSPVertex(dlHead++, VIRTUAL_TO_PHYSICAL(vertexBuffer), 31, 0);
        gSPDisplayList(dlHead++, spinning_plat_tris1);
        gSPVertex(dlHead++, vertexBuffer + 31, 30, 0);
        gSPDisplayList(dlHead++, spinning_plat_tris2);
        // gSP2Triangles(dlHead++, 0, 1, 2, 0, 1, 2, 3, 0);
        // gSP2Triangles(dlHead++, 4, 5, 6, 0, 5, 6, 7, 0);
        
        gSPDisplayList(dlHead++, mat_revert_spinning_plat_WoodFloorTrophyRoom_002_v5_layer1);
        
        gSPEndDisplayList(dlHead++);
    }
    return dlStart;
    
}


extern Vtx c5_spinning_plat_splat_mesh_layer_1_vtx_0[61];
extern Gfx rr_spinning_plat_tris1[];
extern Gfx rr_spinning_plat_tris2[];
extern Gfx mat_c5_spinning_plat_WoodFloorTrophyRoom_002_v5_002_layer1[];
extern Gfx mat_revert_c5_spinning_plat_WoodFloorTrophyRoom_002_v5_002_layer1[];

Gfx *geo_dynamic_spinning_plat_rr(s32 callContext, struct GraphNode *node, void *context) {
    s32 i;
    s16 angle, x, y;
    f32 mag;
    Vtx *verts;
    Vtx *vertexBuffer;
    f32 aSins, aCoss;
    Gfx *dlStart, *dlHead;
    struct Object *obj;
    struct GraphNodeGenerated *currentGraphNode;

    currentGraphNode = node;

    if (callContext == GEO_CONTEXT_RENDER) {
        obj = (struct Object *) gCurGraphNodeObject;

        currentGraphNode->fnNode.node.flags = 0x100 | (currentGraphNode->fnNode.node.flags & 0xFF);

        vertexBuffer = alloc_display_list(61 * sizeof(Vtx));

        // make_vertex(vertexBuffer, 7, 0, 40, -10, 1024, -BIG_CHAIN_UV_Y, 0xFF, 0xFF, 0xFF, 0xFF);

        // make_spinning_plat_verts(vertexBuffer, 0, 32, obj->oFaceAngleYaw);
        // make_spinning_plat_verts(vertexBuffer2, 32, 32 + 14, obj->oFaceAngleYaw);
        
        // aSins = sins(obj->oFaceAngleYaw);
        // aCoss = coss(obj->oFaceAngleYaw);

        verts = segmented_to_virtual(&c5_spinning_plat_splat_mesh_layer_1_vtx_0);

        bcopy(verts, vertexBuffer, 61 * sizeof(Vtx));
        for (i = 0; i < 61; i++) {
            x = vertexBuffer[i].v.tc[0] - 496;
            y = vertexBuffer[i].v.tc[1] - 496;
            angle = atan2s(y, x) + obj->oFaceAngleYaw;
            mag = sqrtf(x * x + y * y);
            vertexBuffer[i].v.tc[0] = mag * sins(angle);
            vertexBuffer[i].v.tc[1] = mag * coss(angle);
            // make_vertex(vertexBuffer, i, verts[i].v.ob[0], verts[i].v.ob[1], verts[i].v.ob[2], x, 
            //             y, verts[i].v.cn[0], verts[i].v.cn[1], verts[i].v.cn[2], verts[i].v.cn[3]);
        }
        dlHead = alloc_display_list(sizeof(Gfx) * (8));
        dlStart = dlHead;




        gSPDisplayList(dlHead++, mat_c5_spinning_plat_WoodFloorTrophyRoom_002_v5_002_layer1);

        gSPVertex(dlHead++, VIRTUAL_TO_PHYSICAL(vertexBuffer), 31, 0);
        gSPDisplayList(dlHead++, rr_spinning_plat_tris1);
        gSPVertex(dlHead++, vertexBuffer + 31, 30, 0);
        gSPDisplayList(dlHead++, rr_spinning_plat_tris2);
        // gSP2Triangles(dlHead++, 0, 1, 2, 0, 1, 2, 3, 0);
        // gSP2Triangles(dlHead++, 4, 5, 6, 0, 5, 6, 7, 0);
        
        gSPDisplayList(dlHead++, mat_revert_c5_spinning_plat_WoodFloorTrophyRoom_002_v5_002_layer1);
        
        gSPEndDisplayList(dlHead++);
    }
    return dlStart;
    
}


extern Vtx big_spinning_plat_bsplat_mesh_layer_1_vtx_0[315];
extern Vtx big_spinning_plat_bsplat_mesh_layer_1_vtx_0_copy[315];
extern Gfx big_spinning_plat_bsplat_mesh_layer_1_tri_0[];
// extern Vtx *big_spin_plat_verts[];
// extern Gfx big_spinning_plat_tris1[];
// extern Gfx big_spinning_plat_tris2[];
// s16 sPrevYaw = 0;

Gfx *geo_dynamic_big_spinning_plat(s32 callContext, struct GraphNode *node, void *context) {
    s32 i;
    s16 angle, x, y;
    f32 mag;
    Vtx *verts;
    Vtx *verts2;
    // f32 aSins, aCoss;
    // Gfx *dlStart, *dlHead;
    struct Object *obj;
    struct GraphNodeGenerated *currentGraphNode;

    currentGraphNode = node;

    if (callContext == GEO_CONTEXT_RENDER) {
        obj = (struct Object *) gCurGraphNodeObject;

        verts = segmented_to_virtual(&big_spinning_plat_bsplat_mesh_layer_1_vtx_0);
        verts2 = segmented_to_virtual(&big_spinning_plat_bsplat_mesh_layer_1_vtx_0_copy);
        bcopy(verts, verts2, 315 * sizeof(Vtx));
        for (i = 0; i < 315; i++) {
            x = verts2[i].v.tc[0] - 496;
            y = verts2[i].v.tc[1] - 496;
            angle = atan2s(y, x) + obj->oFaceAngleYaw;
            mag = sqrtf(x * x + y * y);
            verts2[i].v.tc[0] = mag * sins(angle) + 496;
            verts2[i].v.tc[1] = mag * coss(angle) + 496;
            // make_vertex(vertexBuffer, i, verts[i].v.ob[0], verts[i].v.ob[1], verts[i].v.ob[2], x, 
            //             y, verts[i].v.cn[0], verts[i].v.cn[1], verts[i].v.cn[2], verts[i].v.cn[3]);
        }
    }
    return NULL;
    
}


extern Vtx observatory_splat_osplat_mesh_layer_1_vtx_0[201];
extern Vtx observatory_splat_osplat_mesh_layer_1_vtx_0_copy[201];


Gfx *geo_dynamic_observatory_spinning_plat(s32 callContext, struct GraphNode *node, void *context) {
    s32 i;
    s16 angle, x, y, yaw;
    f32 mag;
    Vtx *verts;
    Vtx *verts2;
    // f32 aSins, aCoss;
    // Gfx *dlStart, *dlHead;
    struct Object *obj;
    struct GraphNodeGenerated *currentGraphNode;

    currentGraphNode = node;

    if (callContext == GEO_CONTEXT_RENDER) {
        obj = (struct Object *) gCurGraphNodeObject;

        yaw = obj->oFaceAngleYaw;

        verts = segmented_to_virtual(&observatory_splat_osplat_mesh_layer_1_vtx_0);
        verts2 = segmented_to_virtual(&observatory_splat_osplat_mesh_layer_1_vtx_0_copy);
        // bcopy(verts, verts2, 201 * sizeof(Vtx));
        for (i = 0; i < 201; i++) {
            x = verts[i].v.tc[0] - 496;
            y = verts[i].v.tc[1] - 496;
            angle = atan2s(y, x) + yaw;
            mag = sqrtf(x * x + y * y);
            verts2[i].v.tc[0] = mag * sins(angle) + 496;
            verts2[i].v.tc[1] = mag * coss(angle) + 496;
            // make_vertex(vertexBuffer, i, verts[i].v.ob[0], verts[i].v.ob[1], verts[i].v.ob[2], x, 
            //             y, verts[i].v.cn[0], verts[i].v.cn[1], verts[i].v.cn[2], verts[i].v.cn[3]);
        }
    }
    return NULL;
    
}



/*
Vtx yoshi_head_spotlight_mesh_layer_5_vtx_0[24] = {
	{{ {0, 0, 0}, 0, {-16, 1008}, {125, 0, 234, 255} }},
	{{ {179, 103, 1000}, 0, {-16, 1008}, {125, 0, 234, 255} }},
	{{ {179, -103, 1000}, 0, {-16, 1008}, {125, 0, 234, 255} }},
	{{ {0, -206, 1000}, 0, {-16, 1008}, {193, 148, 234, 255} }},
	{{ {-179, -103, 1000}, 0, {-16, 1008}, {193, 148, 234, 255} }},
	{{ {-179, 103, 1000}, 0, {-16, 1008}, {193, 108, 234, 255} }},
	{{ {0, 206, 1000}, 0, {-16, 1008}, {193, 108, 234, 255} }},
};

0: 0, 3, 6, 9, 12, 15
1: 1, 11, 23
2: 2, 13, 21
3: 4, 14, 22
4: 5, 16, 20
5: 7, 17, 19
6: 8, 10, 18


Gfx yoshi_head_spotlight_mesh_layer_5_tri_0[] = {
	// gsSPVertex(yoshi_head_spotlight_mesh_layer_5_vtx_0 + 0, 24, 0),
	// gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
	// gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
	// gsSP2Triangles(12, 13, 14, 0, 15, 16, 17, 0),
	// gsSP2Triangles(18, 19, 20, 0, 20, 21, 18, 0),
	// gsSP2Triangles(20, 22, 21, 0, 21, 23, 18, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 3, 4, 0),
	gsSP2Triangles(0, 5, 6, 0, 0, 6, 1, 0),
	gsSP2Triangles(0, 2, 3, 0, 0, 4, 5, 0),
	gsSP2Triangles(6, 5, 4, 0, 4, 2, 6, 0),
	gsSP2Triangles(4, 3, 2, 0, 2, 1, 6, 0),
	gsSPEndDisplayList(),
};


*/

Gfx *geo_generate_spotlight(s32 callContext, struct GraphNode *node, void *context) {
    Vtx *vertexBuffer;
    Gfx *dlStart, *dlHead;
    struct Object *obj;
    struct GraphNodeGenerated *currentGraphNode;
    // s16 height;
    // s16 baseX, baseZ, dist;
    s16 dist;


    currentGraphNode = node;

    if (callContext == GEO_CONTEXT_RENDER) {
        obj = (struct Object *) gCurGraphNodeObject;

        currentGraphNode->fnNode.node.flags = 0x500 | (currentGraphNode->fnNode.node.flags & 0xFF);

        vertexBuffer = alloc_display_list(16 * sizeof(Vtx));

        // height = obj->os16F4;
        // baseX = obj->os16F8;
        // baseZ = obj->os16FA;
        // dist = obj->os16FC;


        dist = obj->oF4;


        // {{ {0, 0, 0}, 0, {-16, 1008}, {125, 0, 234, 255} }},
        // {{ {179, 103, 1000}, 0, {-16, 1008}, {125, 0, 234, 255} }},
        // {{ {179, -103, 1000}, 0, {-16, 1008}, {125, 0, 234, 255} }},
        // {{ {0, -206, 1000}, 0, {-16, 1008}, {193, 148, 234, 255} }},
        // {{ {-179, -103, 1000}, 0, {-16, 1008}, {193, 148, 234, 255} }},
        // {{ {-179, 103, 1000}, 0, {-16, 1008}, {193, 108, 234, 255} }},
        // {{ {0, 206, 1000}, 0, {-16, 1008}, {193, 108, 234, 255} }},

        // x values were +/- 179 originally
        // MAIN VERT
        make_vertex(vertexBuffer, 0, 0, 0, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
        // 1
        make_vertex(vertexBuffer, 1, 240, 103, dist, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
        // 2
        make_vertex(vertexBuffer, 2, 240, -103, dist, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
        // 3
        make_vertex(vertexBuffer, 3, 0, -206, dist, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
        // 4
        make_vertex(vertexBuffer, 4, -240, -103, dist, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
        // 5
        make_vertex(vertexBuffer, 5, -240, 103, dist, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
        // 6
        make_vertex(vertexBuffer, 6, 0, 206, dist, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);

        dlHead = alloc_display_list(sizeof(Gfx) * (6));
        dlStart = dlHead;

        gSPDisplayList(dlHead++, mat_yoshi_head_Spotlight);
        gSPVertex(dlHead++, VIRTUAL_TO_PHYSICAL(vertexBuffer), 7, 0);

        // gSPVertex(dlHead++, VIRTUAL_TO_PHYSICAL(vertexBuffer), 10, 0);
        // gSP2Triangles(dlHead++, 0, 1, 2, 0, 1, 2, 3, 0);
        // gSP2Triangles(dlHead++, 2, 3, 4, 0, 3, 4, 5, 0);

        // gSP2Triangles(dlHead++, 4, 5, 6, 0, 5, 6, 7, 0);
        // gSP2Triangles(dlHead++, 6, 7, 8, 0, 7, 8, 9, 0);
        
        gSPDisplayList(dlHead++, yoshi_head_spotlight_mesh_layer_5_tri_0);
        gSPDisplayList(dlHead++, mat_revert_yoshi_head_Spotlight);
        
        gSPEndDisplayList(dlHead++);
    }
    return dlStart;
    
}


s32 sControllerHue = 0;

Gfx *geo_set_controller_env(s32 callContext, struct GraphNode *node, UNUSED void *context) {
    s16 r, g, b;
    f32 opacityPercent;
    f32 valAdd;
    f32 satAdd;
    Gfx *dlStart, *dlHead;
    struct Object *objectGraphNode;
    struct GraphNodeGenerated *currentGraphNode;
    dlStart = NULL;
    if (callContext == GEO_CONTEXT_RENDER) {
        objectGraphNode = (struct Object *) gCurGraphNodeObject; // TODO: change this to object pointer?
        currentGraphNode = (struct GraphNodeGenerated *) node;

        if (gCurGraphNodeHeldObject) {
            objectGraphNode = gCurGraphNodeHeldObject->objNode;
        }
        dlStart = alloc_display_list(sizeof(Gfx) * 3);
        dlHead = dlStart;
        currentGraphNode->fnNode.node.flags = (currentGraphNode->parameter << 8) | (currentGraphNode->fnNode.node.flags & 0xFF);

        sControllerHue += 8;
        if (sControllerHue >= 360) {
            sControllerHue -= 360;
        }

        opacityPercent = ((f32)(objectGraphNode->oOpacity) / 255.0f);
        valAdd = opacityPercent * 0.6f;
        satAdd = opacityPercent * 0.4f;

        if (objectGraphNode->oOpacity) {
            CL_HSVtoRGB(sControllerHue, 0.45f + satAdd, 0.15f + valAdd, &r, &g, &b);
        } else {
            CL_HSVtoRGB(sControllerHue, 0.0f, 0.8f + (0.2f * sins(DEGREES(sControllerHue))), &r, &g, &b);
        }

        gDPSetEnvColor(dlHead++, r, g, b, 255);
        gSPEndDisplayList(dlHead);
    }
    return dlStart;
}








Gfx *geo_set_brightness_env(s32 callContext, struct GraphNode *node, UNUSED void *context) {
    Gfx *dlStart, *dlHead;
    struct Object *objectGraphNode;
    struct GraphNodeGenerated *currentGraphNode;
    s32 objectBrightness;

    dlStart = NULL;

    if (callContext == GEO_CONTEXT_RENDER) {
        objectGraphNode = (struct Object *) gCurGraphNodeObject; // TODO: change this to object pointer?
        currentGraphNode = (struct GraphNodeGenerated *) node;

        if (gCurGraphNodeHeldObject) {
            objectGraphNode = gCurGraphNodeHeldObject->objNode;
        }

        objectBrightness = objectGraphNode->oOpacity;
        dlStart = alloc_display_list(sizeof(Gfx) * 3);

        dlHead = dlStart;
        if (currentGraphNode->parameter == 20) {
            currentGraphNode->fnNode.node.flags =
            0x600 | (currentGraphNode->fnNode.node.flags & 0xFF);
        } else {
            currentGraphNode->fnNode.node.flags =
            0x100 | (currentGraphNode->fnNode.node.flags & 0xFF);
        }

        gDPSetEnvColor(dlHead++, objectBrightness, objectBrightness, objectBrightness, 255);
        gSPEndDisplayList(dlHead);
    }

    return dlStart;
}


Gfx *geo_set_color_env(s32 callContext, struct GraphNode *node, UNUSED void *context) {
    Gfx *dlStart, *dlHead;
    struct Object *objectGraphNode;
    struct GraphNodeGenerated *currentGraphNode;
    dlStart = NULL;
    if (callContext == GEO_CONTEXT_RENDER) {
        objectGraphNode = (struct Object *) gCurGraphNodeObject; // TODO: change this to object pointer?
        currentGraphNode = (struct GraphNodeGenerated *) node;

        if (gCurGraphNodeHeldObject) {
            objectGraphNode = gCurGraphNodeHeldObject->objNode;
        }
        dlStart = alloc_display_list(sizeof(Gfx) * 3);
        dlHead = dlStart;
        currentGraphNode->fnNode.node.flags = (currentGraphNode->parameter << 8) | (currentGraphNode->fnNode.node.flags & 0xFF);

        gDPSetEnvColor(dlHead++, objectGraphNode->os16F4, objectGraphNode->os16F6, objectGraphNode->os16F8, 255);
        gSPEndDisplayList(dlHead);
    }
    return dlStart;
}



Vec3s gRoomColors[] = {
    {0xFF, 0xFF, 0xFF},
    {0xFF, 0xFF, 0xFF},
    {0xFF, 0xFF, 0xFF},
    {0xFF, 0xFF, 0xFF},
    {0xFF, 0xFF, 0xFF},
    {0xFF, 0xFF, 0xFF},
    {0xFF, 0xFF, 0xFF},
    {0xFF, 0xFF, 0xFF},
    {0xFF, 0xFF, 0xFF},
};

Gfx *geo_set_room_color_env(s32 callContext, struct GraphNode *node, UNUSED void *context) {
    Gfx *dlStart, *dlHead;
    struct GraphNodeGenerated *currentGraphNode;
    Vec3s colors;

    dlStart = NULL;

    if (callContext == GEO_CONTEXT_RENDER) {
        currentGraphNode = (struct GraphNodeGenerated *) node;

        dlStart = alloc_display_list(sizeof(Gfx) * 3);

        dlHead = dlStart;
        vec3s_copy(colors, gRoomColors[currentGraphNode->parameter & 0xFF]);

        currentGraphNode->fnNode.node.flags = 0x100 | (currentGraphNode->fnNode.node.flags & 0xFF);

        gDPSetEnvColor(dlHead++, colors[0], colors[1], colors[2], 255);
        gSPEndDisplayList(dlHead);
    }

    return dlStart;
}


Gfx *geo_set_bedroom_fakewall_alpha(s32 callContext, struct GraphNode *node, UNUSED void *context) {
    Gfx *dlStart, *dlHead;
    struct GraphNodeGenerated *currentGraphNode;
    s16 alpha;

    dlStart = NULL;

    if (callContext == GEO_CONTEXT_RENDER) {
        currentGraphNode = (struct GraphNodeGenerated *) node;

        dlStart = alloc_display_list(sizeof(Gfx) * 3);

        dlHead = dlStart;
        if (save_file_check_room(8 + sLevelRoomOffsets[gCurrCourseNum - 1]) 
            && gRoomColors[currentGraphNode->parameter & 0xFF][0] == 0xFF 
            && gRoomColors[currentGraphNode->parameter & 0xFF][1] == 0xFF) {
                alpha = 170;
            } else {
                alpha = 255;
            }

        currentGraphNode->fnNode.node.flags = 0x400 | (currentGraphNode->fnNode.node.flags & 0xFF);

        gDPSetEnvColor(dlHead++, 255, 255, 255, alpha);
        gSPEndDisplayList(dlHead);
    }

    return dlStart;
}


Vec3s sElevatorColor = {0xCB, 0x94, 0x29};

void reverse_scroll_sts_mat_lll_dl_ElevatorPillars() {
	Gfx *mat = segmented_to_virtual(mat_lll_dl_ElevatorPillars);
	shift_s_down(mat, 8, PACK_TILESIZE(0, -45));
};

void reverse_scroll_sts_mat_lll_dl_ElevatorBG() {
	Gfx *mat = segmented_to_virtual(mat_lll_dl_ElevatorBG);
	shift_t_down(mat, 13, PACK_TILESIZE(0, -25));
};





void slow_reverse_scroll_sts_mat_lll_dl_ElevatorPillars() {
	Gfx *mat = segmented_to_virtual(mat_lll_dl_ElevatorPillars);
	shift_s_down(mat, 8, PACK_TILESIZE(0, -22));
};

void slow_reverse_scroll_sts_mat_lll_dl_ElevatorBG() {
	Gfx *mat = segmented_to_virtual(mat_lll_dl_ElevatorBG);
	shift_t_down(mat, 13, PACK_TILESIZE(0, -13));
};





Gfx *geo_set_elevator_color_env(s32 callContext, struct GraphNode *node, UNUSED void *context) {
    Gfx *dlStart, *dlHead;
    struct GraphNodeGenerated *currentGraphNode;
    struct Object *obj, *obj2;

    dlStart = NULL;

    if (callContext == GEO_CONTEXT_RENDER) {
        currentGraphNode = (struct GraphNodeGenerated *) node;

        dlStart = alloc_display_list(sizeof(Gfx) * 3);

        dlHead = dlStart;
        currentGraphNode->fnNode.node.flags = 0x100 | (currentGraphNode->fnNode.node.flags & 0xFF);
        obj2 = gCurrentObject;
        gCurrentObject = gMarioObject;
        obj = cur_obj_nearest_object_with_behavior(bhvGhostBully);
        gCurrentObject = obj2;
        if (obj == NULL || obj->oAction == 0 || obj->oAction == 10 || obj->oAction == 11) {
            sElevatorColor[0] = approach_s16_symmetric(sElevatorColor[0], 0xCB, 0x4);
            sElevatorColor[1] = approach_s16_symmetric(sElevatorColor[1], 0x94, 0x4);
            sElevatorColor[2] = approach_s16_symmetric(sElevatorColor[2], 0x29, 0x4);
            reverse_scroll_sts_mat_lll_dl_ElevatorPillars();
            reverse_scroll_sts_mat_lll_dl_ElevatorBG();
        } else if (obj->oAction == 9) {
            slow_reverse_scroll_sts_mat_lll_dl_ElevatorPillars();
            slow_reverse_scroll_sts_mat_lll_dl_ElevatorBG();
        } else {
            sElevatorColor[0] = approach_s16_symmetric(sElevatorColor[0], 0x8B, 0x4);
            sElevatorColor[1] = approach_s16_symmetric(sElevatorColor[1], 0x30, 0x4);
            sElevatorColor[2] = approach_s16_symmetric(sElevatorColor[2], 0x1C, 0x4);
        }
            gDPSetEnvColor(dlHead++, sElevatorColor[0], sElevatorColor[1], sElevatorColor[2], 255);
        gSPEndDisplayList(dlHead);
    }

    return dlStart;
}




Gfx *geo_set_boo_shade(s32 callContext, struct GraphNode *node, UNUSED void *context) {
    Gfx *dlStart, *dlHead;
    struct Object *objectGraphNode;
    struct GraphNodeGenerated *currentGraphNode;
    s32 param;
    s32 darkColor;
    dlStart = NULL;

    if (callContext == GEO_CONTEXT_RENDER) {
        objectGraphNode = (struct Object *) gCurGraphNodeObject; // TODO: change this to object pointer?
        currentGraphNode = (struct GraphNodeGenerated *) node;
        dlStart = alloc_display_list(sizeof(Gfx) * 5);
        dlHead = dlStart;

        if (gCurGraphNodeHeldObject) {
            objectGraphNode = gCurGraphNodeHeldObject->objNode;
        }
        param = objectGraphNode->oBehParams2ndByte;
        currentGraphNode->fnNode.node.flags = (currentGraphNode->parameter << 8) | (currentGraphNode->fnNode.node.flags & 0xFF);
        darkColor = (sBooColorsDark[param][0] << 24) | (sBooColorsDark[param][1] << 16) | (sBooColorsDark[param][2] << 8) | 0xFF;
        gSPNumLights(dlHead++, NUMLIGHTS_1);
        gSPLightColor(dlHead++, LIGHT_1, sBooColors[param]);
        gSPLightColor(dlHead++, LIGHT_2, darkColor);
        gDPSetEnvColor(dlHead++, 255, 255, 255, objectGraphNode->oOpacity);
    }
    return dlStart;
}



Gfx *geo_city_window_opacity(s32 callContext, struct GraphNode *node, UNUSED void *context) {
    Gfx *dlStart, *dlHead;
    struct GraphNodeGenerated *currentGraphNode;
    dlStart = NULL;

    if (callContext == GEO_CONTEXT_RENDER) {
        currentGraphNode = (struct GraphNodeGenerated *) node;
        dlStart = alloc_display_list(sizeof(Gfx) * 3);
        dlHead = dlStart;
        currentGraphNode->fnNode.node.flags = 0x500 | (currentGraphNode->fnNode.node.flags & 0xFF);

        if (gIsConsole) {
            gDPSetEnvColor(dlHead++, 0x6C, 0xD4, 0xE1, 0xFF);
        } else {
            gDPSetEnvColor(dlHead++, 0x9B, 0xF3, 0xFF, 0x7F);
        }
        gSPEndDisplayList(dlHead);
    }

    return dlStart;
}

extern struct HSV *sTextPalettes[];

Gfx *geo_set_number_palette(s32 callContext, struct GraphNode *node, UNUSED void *context) {
    Gfx *dlStart, *dlHead;
    struct GraphNodeGenerated *currentGraphNode;
    struct Object *obj;
    s32 hue;
    s16 r, g, b;
    dlStart = NULL;

    if (callContext == GEO_CONTEXT_RENDER) {
        obj = (struct Object *) gCurGraphNodeObject;
        currentGraphNode = (struct GraphNodeGenerated *) node;
        dlStart = alloc_display_list(sizeof(Gfx) * 3);
        dlHead = dlStart;
        currentGraphNode->fnNode.node.flags = 0x400 | (currentGraphNode->fnNode.node.flags & 0xFF);

        // r = sTextPalettes[obj->oFC][0] + CL_RandomMinMaxU16Seeded(0, 40, obj->oAnimState + obj->oFC);
        // g = sTextPalettes[obj->oFC][1] + CL_RandomMinMaxU16Seeded(0, 40, obj->oAnimState + obj->oFC + 1);
        // b = sTextPalettes[obj->oFC][2] + CL_RandomMinMaxU16Seeded(0, 40, obj->oAnimState + obj->oFC + 2);
        hue = sTextPalettes[obj->oFC]->hue - 15 + CL_RandomMinMaxU16Seeded(0, 30, obj->oAnimState + obj->oFC);
        CL_HSVtoRGB(hue, sTextPalettes[obj->oFC]->sat, sTextPalettes[obj->oFC]->value, &r, &g, &b);
        gDPSetEnvColor(dlHead++, r, g, b, 0xFF);
        gSPEndDisplayList(dlHead);
    }

    return dlStart;
}

f32 sRedPaintingSat = 0.9059f;
f32 sRedPaintingVal = 0.9176f;

Gfx *geo_set_red_painting(s32 callContext, struct GraphNode *node, UNUSED void *context) {
    Gfx *dlStart, *dlHead;
    struct GraphNodeGenerated *currentGraphNode;
    struct Object *obj;
    s32 challenge;
    s16 r, g, b;
    dlStart = NULL;

    if (callContext == GEO_CONTEXT_RENDER) {
        obj = (struct Object *) gCurGraphNodeObject;
        currentGraphNode = (struct GraphNodeGenerated *) node;
        dlStart = alloc_display_list(sizeof(Gfx) * 3);
        dlHead = dlStart;
        currentGraphNode->fnNode.node.flags = 0x100 | (currentGraphNode->fnNode.node.flags & 0xFF);
        challenge = currentGraphNode->parameter;
        if (save_file_get_challenges(challenge / 32) & (1 << (challenge % 32))) {
            sRedPaintingSat = approach_f32_symmetric(sRedPaintingSat, 0.15f, 0.02f);
            sRedPaintingVal = approach_f32_symmetric(sRedPaintingVal, 0.4f, 0.013f);
        } else {
            sRedPaintingSat = 0.9059f;
            sRedPaintingVal = 0.9176f;
        }

        CL_HSVtoRGB(359, sRedPaintingSat, sRedPaintingVal, &r, &g, &b);
        gDPSetEnvColor(dlHead++, r, g, b, 0xFF);
        gSPEndDisplayList(dlHead);
    }

    return dlStart;
}


u8 gDreamEnv = 0;

Gfx *geo_set_dream_env(s32 callContext, struct GraphNode *node, UNUSED void *context) {
    Gfx *dlStart, *dlHead;
    struct GraphNodeGenerated *currentGraphNode;
    dlStart = NULL;

    if (callContext == GEO_CONTEXT_RENDER) {
        currentGraphNode = (struct GraphNodeGenerated *) node;
        dlStart = alloc_display_list(sizeof(Gfx) * 3);
        dlHead = dlStart;

        if (CL_objptr_nearest_object_behavior(gMarioObject, bhvDreamYoshi) == NULL) {
            gDreamEnv = 255;
        }

        currentGraphNode->fnNode.node.flags = (currentGraphNode->parameter << 8) | (currentGraphNode->fnNode.node.flags & 0xFF);
        gDPSetEnvColor(dlHead++, gDreamEnv, gDreamEnv, gDreamEnv, gDreamEnv);
        gSPEndDisplayList(dlHead);
    }

    return dlStart;
}



s32 gSunblockOpacity = 0x38;

Gfx *geo_sunblock_opacity(s32 callContext, struct GraphNode *node, UNUSED void *context) {
    Vtx *verts;
    s32 i;
    struct Object *obj;
    struct GraphNodeGenerated *currentGraphNode;


    if (callContext == GEO_CONTEXT_RENDER) {
        currentGraphNode = (struct GraphNodeGenerated *) node;
        currentGraphNode->fnNode.node.flags = 0x500 | (currentGraphNode->fnNode.node.flags & 0xFF);

        obj = CL_objptr_nearest_object_behavior(gMarioObject, bhvL3Sun);
        if (obj != NULL && obj->oHeldState == HELD_HELD) {
            gSunblockOpacity = approach_s16_symmetric(gSunblockOpacity, 0xA0, 0xC);
        } else {
            gSunblockOpacity = approach_s16_symmetric(gSunblockOpacity, 0x38, 0xC);
        }

        verts = segmented_to_virtual(&jrb_dl_Sunblock_mesh_layer_5_vtx_0);
        for (i = 0; i < 412; i++) {
            verts[i].v.cn[3] = gSunblockOpacity;
        }
    }

    return NULL;
}


extern u8 ssl_dl_i8_static_i8[];
struct Object *sTempObj;

Gfx *geo_mind_static(s32 callContext, struct GraphNode *node, UNUSED void *context) {
    Gfx *dlStart, *dlHead;
    struct GraphNodeGenerated *currentGraphNode;
    struct Object *obj;
    dlStart = NULL;

    if (callContext == GEO_CONTEXT_RENDER) {
        currentGraphNode = (struct GraphNodeGenerated *) node;
        dlStart = alloc_display_list(sizeof(Gfx) * 3);
        dlHead = dlStart;
        sTempObj = o;
        o = gMarioObject;
        obj = CL_obj_nearest_object_behavior_params(bhvFloorPeepa, 1 << 24);\
        o = sTempObj;
        if (obj == NULL) {
            return NULL;
        }
        currentGraphNode->fnNode.node.flags = 0x600 | (currentGraphNode->fnNode.node.flags & 0xFF);

        u16 *texture = segmented_to_virtual(&ssl_dl_i8_static_i8);
        s32 i;
        for (i = 0; i < 2048; i++) {
            texture[i] = CL_RandomMinMaxU16(0x2000, 0xD000);
            // texture[i] = random_u16();
        }

        gDPSetEnvColor(dlHead++, 255, 255, 255, obj->oOpacity);
        gSPEndDisplayList(dlHead);
    }
    return dlStart;
}

Vec3s sStarColors[8] = {
    {0xFF, 0xFF, 0},
    {0xFF, 0, 0},
    {0, 0xFF, 0},
    {0xFF, 0x95, 0},
    {0xAA, 0, 0xFF},
    {0xFF, 0xFF, 0xFF},
    {0x7F, 0x7F, 0x7F},
    {0, 0, 0},
};


Gfx *geo_star_color(s32 callContext, struct GraphNode *node, UNUSED void *context) {
    Gfx *dlStart, *dlHead;
    s32 index;
    struct GraphNodeGenerated *currentGraphNode;
    struct Object *obj;
    dlStart = NULL;

    if (callContext == GEO_CONTEXT_RENDER) {
        obj = (struct Object *) gCurGraphNodeObject;
        currentGraphNode = (struct GraphNodeGenerated *) node;
        dlStart = alloc_display_list(sizeof(Gfx) * 3);
        dlHead = dlStart;
        currentGraphNode->fnNode.node.flags = (1 << 8) | (currentGraphNode->fnNode.node.flags & 0xFF);

        index = obj->oBehParams >> 24;
        if (currentGraphNode->parameter == 0) {
            index += 5;
        }
        gDPSetEnvColor(dlHead++, sStarColors[index][0], sStarColors[index][1], sStarColors[index][2], 255);
        gSPEndDisplayList(dlHead);
    }

    return dlStart;
}


/**
 * @bug Every geo function declares the 3 parameters of callContext, node, and
 * the matrix array. This one (see also geo_switch_area) doesn't. When executed,
 * the node function executor passes the 3rd argument to a function that doesn't
 * declare it. This is undefined behavior, but harmless in practice due to the
 * o32 calling convention.
 */
#ifdef AVOID_UB
Gfx *geo_switch_anim_state(s32 callContext, struct GraphNode *node, UNUSED void *context) {
#else
Gfx *geo_switch_anim_state(s32 callContext, struct GraphNode *node) {
#endif
    struct Object *obj;
    struct GraphNodeSwitchCase *switchCase;

    if (callContext == GEO_CONTEXT_RENDER) {
        obj = (struct Object *) gCurGraphNodeObject; // TODO: change global type to Object pointer

        // move to a local var because GraphNodes are passed in all geo functions.
        // cast the pointer.
        switchCase = (struct GraphNodeSwitchCase *) node;

        if (gCurGraphNodeHeldObject != NULL) {
            obj = gCurGraphNodeHeldObject->objNode;
        }

        // if the case is greater than the number of cases, set to 0 to avoid overflowing
        // the switch.
        if (obj->oAnimState >= switchCase->numCases) {
            obj->oAnimState = 0;
        }

        // assign the case number for execution.
        switchCase->selectedCase = obj->oAnimState;
    }

    return NULL;
}


#ifdef AVOID_UB
Gfx *geo_switch_bparam2(s32 callContext, struct GraphNode *node, UNUSED void *context) {
#else
Gfx *geo_switch_bparam2(s32 callContext, struct GraphNode *node) {
#endif
    struct Object *obj;
    struct GraphNodeSwitchCase *switchCase;

    if (callContext == GEO_CONTEXT_RENDER) {
        obj = (struct Object *) gCurGraphNodeObject; // TODO: change global type to Object pointer

        // move to a local var because GraphNodes are passed in all geo functions.
        // cast the pointer.
        switchCase = (struct GraphNodeSwitchCase *) node;

        if (gCurGraphNodeHeldObject != NULL) {
            obj = gCurGraphNodeHeldObject->objNode;
        }

        // if the case is greater than the number of cases, set to 0 to avoid overflowing
        // the switch.

        // assign the case number for execution.
        switchCase->selectedCase = obj->oBehParams2ndByte;
    }

    return NULL;
}


#ifdef AVOID_UB
Gfx *geo_switch_112(s32 callContext, struct GraphNode *node, UNUSED void *context) {
#else
Gfx *geo_switch_112(s32 callContext, struct GraphNode *node) {
#endif
    struct Object *obj;
    struct GraphNodeSwitchCase *switchCase;

    if (callContext == GEO_CONTEXT_RENDER) {
        obj = (struct Object *) gCurGraphNodeObject; // TODO: change global type to Object pointer

        // move to a local var because GraphNodes are passed in all geo functions.
        // cast the pointer.
        switchCase = (struct GraphNodeSwitchCase *) node;

        if (gCurGraphNodeHeldObject != NULL) {
            obj = gCurGraphNodeHeldObject->objNode;
        }

        // if the case is greater than the number of cases, set to 0 to avoid overflowing
        // the switch.

        // assign the case number for execution.
        switchCase->selectedCase = obj->os16112;
    }

    return NULL;
}



//[0] = hub
s32 sLevelToChapter[COURSE_MAX] = {
1, 1, 2, 2, 3, 3, 4, 4, 5,
};


#ifdef AVOID_UB
Gfx *geo_switch_get_chapter(s32 callContext, struct GraphNode *node, UNUSED void *context) {
#else
Gfx *geo_switch_get_chapter(s32 callContext, struct GraphNode *node) {
#endif
    struct GraphNodeSwitchCase *switchCase;

    if (callContext == GEO_CONTEXT_RENDER) {
        // move to a local var because GraphNodes are passed in all geo functions.
        // cast the pointer.
        switchCase = (struct GraphNodeSwitchCase *) node;

        // assign the case number for execution.
        switchCase->selectedCase = sLevelToChapter[gCurrCourseNum] - 1;
    }

    return NULL;
}

#ifdef AVOID_UB
Gfx *geo_switch_level(s32 callContext, struct GraphNode *node, UNUSED void *context) {
#else
Gfx *geo_switch_level(s32 callContext, struct GraphNode *node) {
#endif
    struct GraphNodeSwitchCase *switchCase;

    if (callContext == GEO_CONTEXT_RENDER) {

        // move to a local var because GraphNodes are passed in all geo functions.
        // cast the pointer.
        switchCase = (struct GraphNodeSwitchCase *) node;

        // assign the case number for execution.
        switchCase->selectedCase = gCurrCourseNum;
    }

    return NULL;
}

extern s32 gMenuCutscene;

#ifdef AVOID_UB
Gfx *geo_switch_menu(s32 callContext, struct GraphNode *node, UNUSED void *context) {
#else
Gfx *geo_switch_menu(s32 callContext, struct GraphNode *node) {
#endif
    struct GraphNodeSwitchCase *switchCase;

    if (callContext == GEO_CONTEXT_RENDER) {
        switchCase = (struct GraphNodeSwitchCase *) node;

        // assign the case number for execution.
        switchCase->selectedCase = gMenuCutscene;
    }

    return NULL;
}



#ifdef AVOID_UB
Gfx *geo_switch_servants_wall(s32 callContext, struct GraphNode *node, UNUSED void *context) {
#else
Gfx *geo_switch_servants_wall(s32 callContext, struct GraphNode *node) {
#endif
    struct GraphNodeSwitchCase *switchCase;

    if (callContext == GEO_CONTEXT_RENDER) {
        // move to a local var because GraphNodes are passed in all geo functions.
        // cast the pointer.
        switchCase = (struct GraphNodeSwitchCase *) node;


        // if the case is greater than the number of cases, set to 0 to avoid overflowing
        // the switch.

        // assign the case number for execution.
        if (gMarioState->pos[0] > 8500.0f) {
            switchCase->selectedCase = 1;
        } else {
            switchCase->selectedCase = 0;
        }
    }

    return NULL;
}


#ifdef AVOID_UB
Gfx *geo_switch_servants_wall_2(s32 callContext, struct GraphNode *node, UNUSED void *context) {
#else
Gfx *geo_switch_servants_wall_2(s32 callContext, struct GraphNode *node) {
#endif
    struct GraphNodeSwitchCase *switchCase;

    if (callContext == GEO_CONTEXT_RENDER) {
        // move to a local var because GraphNodes are passed in all geo functions.
        // cast the pointer.
        switchCase = (struct GraphNodeSwitchCase *) node;


        // if the case is greater than the number of cases, set to 0 to avoid overflowing
        // the switch.

        // assign the case number for execution.
        if (gMarioState->pos[0] > 10200.0f) {
            switchCase->selectedCase = 1;
        } else {
            switchCase->selectedCase = 0;
        }
    }

    return NULL;
}



#ifdef AVOID_UB
Gfx *geo_switch_ice_reflection(s32 callContext, struct GraphNode *node, UNUSED void *context) {
#else
Gfx *geo_switch_ice_reflection(s32 callContext, struct GraphNode *node) {
#endif
    struct GraphNodeSwitchCase *switchCase;

    if (callContext == GEO_CONTEXT_RENDER) {
        // move to a local var because GraphNodes are passed in all geo functions.
        // cast the pointer.
        switchCase = (struct GraphNodeSwitchCase *) node;


        // if the case is greater than the number of cases, set to 0 to avoid overflowing
        // the switch.

        // assign the case number for execution.
        if (gMarioState->pos[2] > -7500.0f || gMarioState->pos[2] < -13888.0f || 
            gMarioState->pos[0] > 5800.0f || gMarioState->pos[0] < 1000.0f) {
            switchCase->selectedCase = 1;
        } else {
            switchCase->selectedCase = 0;
        }
    }

    return NULL;
}


#ifdef AVOID_UB
Gfx *geo_switch_garden_render(s32 callContext, struct GraphNode *node, UNUSED void *context) {
#else
Gfx *geo_switch_garden_render(s32 callContext, struct GraphNode *node) {
#endif
    struct GraphNodeSwitchCase *switchCase;

    if (callContext == GEO_CONTEXT_RENDER) {
        // move to a local var because GraphNodes are passed in all geo functions.
        // cast the pointer.
        switchCase = (struct GraphNodeSwitchCase *) node;


        // if the case is greater than the number of cases, set to 0 to avoid overflowing
        // the switch.


        //if not console, 0
        //if console, but within bounds, 0
        //if console and not within bounds, 1

        // assign the case number for execution.
        if (!gIsConsole || (gMarioState->pos[0] < 20700.0f && gMarioState->pos[2] > -4000.0f && gMarioState->pos[2] < 4500.0f)
            || (gMarioState->pos[0] >= 20700.0f && gMarioState->pos[2] > 0.0f && gMarioState->pos[2] < 3000.0f)) {
            switchCase->selectedCase = 0;
        } else {
            switchCase->selectedCase = 1;
        }
    }

    return NULL;
}


#ifdef AVOID_UB
Gfx *geo_switch_garden_backface_render(s32 callContext, struct GraphNode *node, UNUSED void *context) {
#else
Gfx *geo_switch_garden_backface_render(s32 callContext, struct GraphNode *node) {
#endif
    struct GraphNodeSwitchCase *switchCase;

    if (callContext == GEO_CONTEXT_RENDER) {
        // move to a local var because GraphNodes are passed in all geo functions.
        // cast the pointer.
        switchCase = (struct GraphNodeSwitchCase *) node;


        // if the case is greater than the number of cases, set to 0 to avoid overflowing
        // the switch.

        // assign the case number for execution.
        if (gMarioState->pos[2] < -2500.0f || gMarioState->pos[2] > 3600.0f) {
            switchCase->selectedCase = 0;
        } else {
            switchCase->selectedCase = 1;
        }
    }

    return NULL;
}

#ifdef AVOID_UB
Gfx *geo_switch_city_render(s32 callContext, struct GraphNode *node, UNUSED void *context) {
#else
Gfx *geo_switch_city_render(s32 callContext, struct GraphNode *node) {
#endif
    struct GraphNodeSwitchCase *switchCase;

    if (callContext == GEO_CONTEXT_RENDER) {
        // move to a local var because GraphNodes are passed in all geo functions.
        // cast the pointer.
        switchCase = (struct GraphNodeSwitchCase *) node;


        // if the case is greater than the number of cases, set to 0 to avoid overflowing
        // the switch.

        // assign the case number for execution.
        if (!gIsConsole || (gMarioState->pos[0] < 20700.0f)) {
            switchCase->selectedCase = 0;
        } else {
            switchCase->selectedCase = 1;
        }
    }

    return NULL;
}

s32 gHideCityGoombas = 0;

#ifdef AVOID_UB
Gfx *geo_switch_city_strip_render(s32 callContext, struct GraphNode *node, UNUSED void *context) {
#else
Gfx *geo_switch_city_strip_render(s32 callContext, struct GraphNode *node) {
#endif
    struct GraphNodeSwitchCase *switchCase;

    if (callContext == GEO_CONTEXT_RENDER) {
        // move to a local var because GraphNodes are passed in all geo functions.
        // cast the pointer.
        switchCase = (struct GraphNodeSwitchCase *) node;


        // if the case is greater than the number of cases, set to 0 to avoid overflowing
        // the switch.

        // assign the case number for execution.
        if (!gIsConsole || gMarioState->pos[0] <= 23050.0f || gMarioState->pos[2] <= -4900.0f) {
            switchCase->selectedCase = 0;
            gHideCityGoombas = 0;
        } else {
            switchCase->selectedCase = 1;
            gHideCityGoombas = 1;
        }
    }

    return NULL;
}

#ifdef AVOID_UB
Gfx *geo_switch_city_walls_render(s32 callContext, struct GraphNode *node, UNUSED void *context) {
#else
Gfx *geo_switch_city_walls_render(s32 callContext, struct GraphNode *node) {
#endif
    struct GraphNodeSwitchCase *switchCase;

    if (callContext == GEO_CONTEXT_RENDER) {
        // move to a local var because GraphNodes are passed in all geo functions.
        // cast the pointer.
        switchCase = (struct GraphNodeSwitchCase *) node;


        // if the case is greater than the number of cases, set to 0 to avoid overflowing
        // the switch.

        // assign the case number for execution.
        if (gMarioState->pos[1] <= 2200.0f && gMarioState->pos[0] <= 24700.0f && gMarioState->pos[0] > 23000.0f && 
            gMarioState->pos[2] >= -4900.0f && gMarioState->pos[2] < 2080.0f) {
            if (gMarioState->pos[2] >= -3300.0f && gMarioState->pos[2] < 500.0f) {
                switchCase->selectedCase = 1;
            } else {
                switchCase->selectedCase = 2;
            }
        } else {
            switchCase->selectedCase = 0;
        }
    }

    return NULL;
}


#ifdef AVOID_UB
Gfx *geo_switch_city_strip(s32 callContext, struct GraphNode *node, UNUSED void *context) {
#else
Gfx *geo_switch_city_strip(s32 callContext, struct GraphNode *node) {
#endif
    struct GraphNodeSwitchCase *switchCase;

    if (callContext == GEO_CONTEXT_RENDER) {
        // move to a local var because GraphNodes are passed in all geo functions.
        // cast the pointer.
        switchCase = (struct GraphNodeSwitchCase *) node;


        // if the case is greater than the number of cases, set to 0 to avoid overflowing
        // the switch.

        // assign the case number for execution.
        if ((gMarioState->pos[0] > 18000.0f && gMarioState->pos[2] < 2150.0f) || !gIsConsole) {
            switchCase->selectedCase = 0;
        } else {
            switchCase->selectedCase = 1;
        }
    }

    return NULL;
}


#ifdef AVOID_UB
Gfx *geo_switch_city_strip_building(s32 callContext, struct GraphNode *node, UNUSED void *context) {
#else
Gfx *geo_switch_city_strip_building(s32 callContext, struct GraphNode *node) {
#endif
    struct GraphNodeSwitchCase *switchCase;

    if (callContext == GEO_CONTEXT_RENDER) {
        // move to a local var because GraphNodes are passed in all geo functions.
        // cast the pointer.
        switchCase = (struct GraphNodeSwitchCase *) node;


        // if the case is greater than the number of cases, set to 0 to avoid overflowing
        // the switch.

        // assign the case number for execution.
        if (gMarioState->pos[0] < 24800.0f || !gIsConsole) {
            switchCase->selectedCase = 0;
        } else {
            switchCase->selectedCase = 1;
        }
    }

    return NULL;
}


#ifdef AVOID_UB
Gfx *geo_switch_city_far_walls(s32 callContext, struct GraphNode *node, UNUSED void *context) {
#else
Gfx *geo_switch_city_far_walls(s32 callContext, struct GraphNode *node) {
#endif
    struct GraphNodeSwitchCase *switchCase;

    if (callContext == GEO_CONTEXT_RENDER) {
        // move to a local var because GraphNodes are passed in all geo functions.
        // cast the pointer.
        switchCase = (struct GraphNodeSwitchCase *) node;


        // if the case is greater than the number of cases, set to 0 to avoid overflowing
        // the switch.

        // assign the case number for execution.
        if (gMarioState->pos[0] > 7000.0f|| !gIsConsole) {
            switchCase->selectedCase = 0;
        } else {
            switchCase->selectedCase = 1;
        }
    }

    return NULL;
}


extern s32 gPoolFloorUp;

#ifdef AVOID_UB
Gfx *geo_switch_pool_floor(s32 callContext, struct GraphNode *node, UNUSED void *context) {
#else
Gfx *geo_switch_pool_floor(s32 callContext, struct GraphNode *node) {
#endif
    struct GraphNodeSwitchCase *switchCase;

    if (callContext == GEO_CONTEXT_RENDER) {
        // move to a local var because GraphNodes are passed in all geo functions.
        // cast the pointer.
        switchCase = (struct GraphNodeSwitchCase *) node;
        struct Object *obj;

        // if the case is greater than the number of cases, set to 0 to avoid overflowing
        // the switch.

        // assign the case number for execution.
        if (gPoolFloorUp) {
            switchCase->selectedCase = 1;
        } else {
            switchCase->selectedCase = 0;
            obj = CL_objptr_nearest_object_behavior(gMarioObject, bhvToyMole);
            if (obj != NULL) {
                obj->header.gfx.node.flags |= GRAPH_RENDER_INVISIBLE;
            }
            obj = CL_objptr_nearest_object_behavior(gMarioObject, bhvMoleCage);
            if (obj != NULL) {
                obj->header.gfx.node.flags |= GRAPH_RENDER_INVISIBLE;
            }
        }
    }

    return NULL;
}

extern s16 s8DirModeBaseYaw;

#ifdef AVOID_UB
Gfx *geo_switch_mole_gate(s32 callContext, struct GraphNode *node, UNUSED void *context) {
#else
Gfx *geo_switch_mole_gate(s32 callContext, struct GraphNode *node) {
#endif
    struct GraphNodeSwitchCase *switchCase;

    if (callContext == GEO_CONTEXT_RENDER) {
        // move to a local var because GraphNodes are passed in all geo functions.
        // cast the pointer.
        switchCase = (struct GraphNodeSwitchCase *) node;

        // if the case is greater than the number of cases, set to 0 to avoid overflowing
        // the switch.

        // assign the case number for execution.
        if ((gMarioState->pos[0] < 8795.0f || gMarioState->pos[2] < 8323.0f) && ((u16)s8DirModeBaseYaw > 0x4000)) {
            switchCase->selectedCase = 0;
        } else {
            switchCase->selectedCase = 1;
        }
    }

    return NULL;
}


#ifdef AVOID_UB
Gfx *geo_switch_gameroom(s32 callContext, struct GraphNode *node, UNUSED void *context) {
#else
Gfx *geo_switch_gameroom(s32 callContext, struct GraphNode *node) {
#endif
    struct GraphNodeSwitchCase *switchCase;
    struct Object *obj;

    if (callContext == GEO_CONTEXT_RENDER) {
        // move to a local var because GraphNodes are passed in all geo functions.
        // cast the pointer.
        switchCase = (struct GraphNodeSwitchCase *) node;

        // if the case is greater than the number of cases, set to 0 to avoid overflowing
        // the switch.
        obj = CL_objptr_nearest_object_behavior(gMarioObject, bhvPoolBarrier);
        // assign the case number for execution.
        if (obj == NULL || obj->oOpacity != 255 || !gIsConsole) {
            switchCase->selectedCase = 0;
        } else {
            switchCase->selectedCase = 1;
        }
    }

    return NULL;
}


#ifdef AVOID_UB
Gfx *geo_switch_attic(s32 callContext, struct GraphNode *node, UNUSED void *context) {
#else
Gfx *geo_switch_attic(s32 callContext, struct GraphNode *node) {
#endif
    struct GraphNodeSwitchCase *switchCase;
    struct Object *obj;

    if (callContext == GEO_CONTEXT_RENDER) {
        // move to a local var because GraphNodes are passed in all geo functions.
        // cast the pointer.
        switchCase = (struct GraphNodeSwitchCase *) node;

        // if the case is greater than the number of cases, set to 0 to avoid overflowing
        // the switch.
        obj = CL_objptr_nearest_object_behavior(gMarioObject, bhvAtticWall);
        // assign the case number for execution.
        if (obj == NULL || obj->oOpacity != 255 || !gIsConsole) {
            switchCase->selectedCase = 0;
        } else {
            switchCase->selectedCase = 1;
        }
    }

    return NULL;
}


#ifdef AVOID_UB
Gfx *geo_switch_foreroom_outside(s32 callContext, struct GraphNode *node, UNUSED void *context) {
#else
Gfx *geo_switch_foreroom_outside(s32 callContext, struct GraphNode *node) {
#endif
    struct GraphNodeSwitchCase *switchCase;

    if (callContext == GEO_CONTEXT_RENDER) {
        // move to a local var because GraphNodes are passed in all geo functions.
        // cast the pointer.
        switchCase = (struct GraphNodeSwitchCase *) node;

        // if the case is greater than the number of cases, set to 0 to avoid overflowing
        // the switch.

        // assign the case number for execution.
        if (gIsConsole && gMarioState->pos[0] < 500.0f) {
            switchCase->selectedCase = 1;
        } else {
            switchCase->selectedCase = 0;
        }
    }

    return NULL;
}


#ifdef AVOID_UB
Gfx *geo_switch_sauna(s32 callContext, struct GraphNode *node, UNUSED void *context) {
#else
Gfx *geo_switch_sauna(s32 callContext, struct GraphNode *node) {
#endif
    struct GraphNodeSwitchCase *switchCase;
    struct MarioState *m = gMarioState;

    if (callContext == GEO_CONTEXT_RENDER) {
        // move to a local var because GraphNodes are passed in all geo functions.
        // cast the pointer.
        switchCase = (struct GraphNodeSwitchCase *) node;

        // if the case is greater than the number of cases, set to 0 to avoid overflowing
        // the switch.

        // assign the case number for execution.
        if ((m->floor != NULL && m->floor->type == SURFACE_GENERAL_USE) || gCamera->pos[2] < -2500.0f || !gIsConsole) {
            switchCase->selectedCase = 2;
        } else if (m->pos[0] > -4500.0f) {
            switchCase->selectedCase = 1;
        } else {
            switchCase->selectedCase = 0;
        }
    }

    return NULL;
}


#ifdef AVOID_UB
Gfx *geo_switch_plat_hall(s32 callContext, struct GraphNode *node, UNUSED void *context) {
#else
Gfx *geo_switch_plat_hall(s32 callContext, struct GraphNode *node) {
#endif
    struct GraphNodeSwitchCase *switchCase;
    struct MarioState *m = gMarioState;

    if (callContext == GEO_CONTEXT_RENDER) {
        // move to a local var because GraphNodes are passed in all geo functions.
        // cast the pointer.
        switchCase = (struct GraphNodeSwitchCase *) node;

        // if the case is greater than the number of cases, set to 0 to avoid overflowing
        // the switch.

        // assign the case number for execution.
        if (m->pos[1] < 8000.0f) {
            switchCase->selectedCase = 0;
        } else {
            switchCase->selectedCase = 1;
        }
    }

    return NULL;
}


#ifdef AVOID_UB
Gfx *geo_switch_meat_locker(s32 callContext, struct GraphNode *node, UNUSED void *context) {
#else
Gfx *geo_switch_meat_locker(s32 callContext, struct GraphNode *node) {
#endif
    struct GraphNodeSwitchCase *switchCase;
    struct MarioState *m = gMarioState;

    if (callContext == GEO_CONTEXT_RENDER) {
        // move to a local var because GraphNodes are passed in all geo functions.
        // cast the pointer.
        switchCase = (struct GraphNodeSwitchCase *) node;

        // if the case is greater than the number of cases, set to 0 to avoid overflowing
        // the switch.

        // assign the case number for execution.
        if (m->pos[0] > -6300.0f && m->pos[2] < 6900.0f) {
            switchCase->selectedCase = 0;
        } else {
            switchCase->selectedCase = 1;
        }
    }

    return NULL;
}


#ifdef AVOID_UB
Gfx *geo_switch_wine_cellar(s32 callContext, struct GraphNode *node, UNUSED void *context) {
#else
Gfx *geo_switch_wine_cellar(s32 callContext, struct GraphNode *node) {
#endif
    struct GraphNodeSwitchCase *switchCase;
    struct MarioState *m = gMarioState;

    if (callContext == GEO_CONTEXT_RENDER) {
        // move to a local var because GraphNodes are passed in all geo functions.
        // cast the pointer.
        switchCase = (struct GraphNodeSwitchCase *) node;

        // if the case is greater than the number of cases, set to 0 to avoid overflowing
        // the switch.

        // assign the case number for execution.
        if (gIsConsole && m->pos[1] > 1300.0f && m->pos[0] > -2200.0f && (u16)gCamera->yaw <= 0x8000) {
            switchCase->selectedCase = 1;
        } else {
            switchCase->selectedCase = 0;
        }
    }

    return NULL;
}


void hide_objects_with_behavior_and_room(const BehaviorScript *behavior, s32 room) {
    uintptr_t *behaviorAddr = segmented_to_virtual(behavior);
    struct Object *closestObj = NULL;
    struct Object *obj;
    struct ObjectNode *listHead;
    listHead = &gObjectLists[get_object_list_from_behavior(behaviorAddr)];
    obj = (struct Object *) listHead->next;

    while (obj != (struct Object *) listHead) {
        if (obj->behavior == behaviorAddr) {
            if (obj->activeFlags != ACTIVE_FLAG_DEACTIVATED && obj->oRoom == room) {
                obj->header.gfx.node.flags |= GRAPH_RENDER_INVISIBLE;
            }
        }
        obj = (struct Object *) obj->header.next;
    }
}

void unhide_objects_with_behavior_and_room(const BehaviorScript *behavior, s32 room) {
    uintptr_t *behaviorAddr = segmented_to_virtual(behavior);
    struct Object *closestObj = NULL;
    struct Object *obj;
    struct ObjectNode *listHead;
    listHead = &gObjectLists[get_object_list_from_behavior(behaviorAddr)];
    obj = (struct Object *) listHead->next;

    while (obj != (struct Object *) listHead) {
        if (obj->behavior == behaviorAddr) {
            if (obj->activeFlags != ACTIVE_FLAG_DEACTIVATED && obj->oRoom == room) {
                obj->header.gfx.node.flags &= ~GRAPH_RENDER_INVISIBLE;
            }
        }
        obj = (struct Object *) obj->header.next;
    }
}



#ifdef AVOID_UB
Gfx *geo_switch_laundry_room(s32 callContext, struct GraphNode *node, UNUSED void *context) {
#else
Gfx *geo_switch_laundry_room(s32 callContext, struct GraphNode *node) {
#endif
    struct GraphNodeSwitchCase *switchCase;
    struct MarioState *m = gMarioState;

    if (callContext == GEO_CONTEXT_RENDER) {
        // move to a local var because GraphNodes are passed in all geo functions.
        // cast the pointer.
        switchCase = (struct GraphNodeSwitchCase *) node;

        // if the case is greater than the number of cases, set to 0 to avoid overflowing
        // the switch.

        // assign the case number for execution.
        if (m->pos[0] < 3000.0f && m->pos[2] > 14000.0f) {
            switchCase->selectedCase = 1;
            unhide_objects_with_behavior_and_room(bhvDustBunny, gMarioCurrentRoom);
            unhide_objects_with_behavior_and_room(bhvBounceBoxes, gMarioCurrentRoom);
        } else {
            hide_objects_with_behavior_and_room(bhvDustBunny, gMarioCurrentRoom);
            hide_objects_with_behavior_and_room(bhvBounceBoxes, gMarioCurrentRoom);
            switchCase->selectedCase = 0;
        }
    }

    return NULL;
}



#ifdef AVOID_UB
Gfx *geo_switch_study1(s32 callContext, struct GraphNode *node, UNUSED void *context) {
#else
Gfx *geo_switch_study1(s32 callContext, struct GraphNode *node) {
#endif
    struct GraphNodeSwitchCase *switchCase;
    struct MarioState *m = gMarioState;

    if (callContext == GEO_CONTEXT_RENDER) {
        // move to a local var because GraphNodes are passed in all geo functions.
        // cast the pointer.
        switchCase = (struct GraphNodeSwitchCase *) node;

        // if the case is greater than the number of cases, set to 0 to avoid overflowing
        // the switch.

        // assign the case number for execution.
        if (m->pos[1] < 1300.0f && m->pos[2] < 8700.0f && gIsConsole) {
            switchCase->selectedCase = 1;
        } else {
            switchCase->selectedCase = 0;
        }
    }

    return NULL;
}



#ifdef AVOID_UB
Gfx *geo_switch_study2(s32 callContext, struct GraphNode *node, UNUSED void *context) {
#else
Gfx *geo_switch_study2(s32 callContext, struct GraphNode *node) {
#endif
    struct GraphNodeSwitchCase *switchCase;
    struct MarioState *m = gMarioState;

    if (callContext == GEO_CONTEXT_RENDER) {
        // move to a local var because GraphNodes are passed in all geo functions.
        // cast the pointer.
        switchCase = (struct GraphNodeSwitchCase *) node;

        // if the case is greater than the number of cases, set to 0 to avoid overflowing
        // the switch.

        // assign the case number for execution.
        if (m->pos[2] > 12000.0f && gIsConsole) {
            switchCase->selectedCase = 1;
        } else {
            switchCase->selectedCase = 0;
        }
    }

    return NULL;
}


#ifdef AVOID_UB
Gfx *geo_switch_library(s32 callContext, struct GraphNode *node, UNUSED void *context) {
#else
Gfx *geo_switch_library(s32 callContext, struct GraphNode *node) {
#endif
    struct GraphNodeSwitchCase *switchCase;
    struct Object *obj;

    if (callContext == GEO_CONTEXT_RENDER) {
        // move to a local var because GraphNodes are passed in all geo functions.
        // cast the pointer.
        switchCase = (struct GraphNodeSwitchCase *) node;

        // if the case is greater than the number of cases, set to 0 to avoid overflowing
        // the switch.
        obj = CL_objptr_nearest_object_behavior(gMarioObject, bhvKoopaBoss);
        // assign the case number for execution.
        if (obj != NULL && gIsConsole) {
            switchCase->selectedCase = 1;
        } else {
            switchCase->selectedCase = 0;
        }
    }

    return NULL;
}




#ifdef AVOID_UB
Gfx *geo_switch_library2(s32 callContext, struct GraphNode *node, UNUSED void *context) {
#else
Gfx *geo_switch_library2(s32 callContext, struct GraphNode *node) {
#endif
    struct GraphNodeSwitchCase *switchCase;
    struct Object *obj;
    if (callContext == GEO_CONTEXT_RENDER) {
        // move to a local var because GraphNodes are passed in all geo functions.
        // cast the pointer.
        switchCase = (struct GraphNodeSwitchCase *) node;

        // if the case is greater than the number of cases, set to 0 to avoid overflowing
        // the switch.
        // assign the case number for execution.
        obj = CL_objptr_nearest_object_behavior(gMarioObject, bhvKoopaBoss);
        if (obj != NULL && gCamera->pos[1] <= 2900.0f && gIsConsole) {
            switchCase->selectedCase = 1;
        } else {
            switchCase->selectedCase = 0;
        }
    }

    return NULL;
}



#ifdef AVOID_UB
Gfx *geo_switch_bathroom(s32 callContext, struct GraphNode *node, UNUSED void *context) {
#else
Gfx *geo_switch_bathroom(s32 callContext, struct GraphNode *node) {
#endif
    struct GraphNodeSwitchCase *switchCase;
    if (callContext == GEO_CONTEXT_RENDER) {
        // move to a local var because GraphNodes are passed in all geo functions.
        // cast the pointer.
        switchCase = (struct GraphNodeSwitchCase *) node;

        // if the case is greater than the number of cases, set to 0 to avoid overflowing
        // the switch.
        // assign the case number for execution.
        if (gMarioState->pos[1] <= -100.0f) {
            switchCase->selectedCase = 1;
        } else {
            switchCase->selectedCase = 0;
        }
    }

    return NULL;
}

// s16 sShowerOpacity[2] = {150, 150};

// #ifdef AVOID_UB
// Gfx *geo_switch_shower(s32 callContext, struct GraphNode *node, UNUSED void *context) {
// #else
// Gfx *geo_switch_shower(s32 callContext, struct GraphNode *node) {
// #endif
//     struct GraphNodeSwitchCase *switchCase;
//     if (callContext == GEO_CONTEXT_RENDER) {
//         // move to a local var because GraphNodes are passed in all geo functions.
//         // cast the pointer.
//         switchCase = (struct GraphNodeSwitchCase *) node;

//         // if the case is greater than the number of cases, set to 0 to avoid overflowing
//         // the switch.
//         // assign the case number for execution.
//         if (gMarioState->pos[1] <= -100.0f) {
//             switchCase->selectedCase = 1;
//         } else {
//             switchCase->selectedCase = 0;
//         }
//     }

//     return NULL;
// }



// Gfx *geo_set_shower_opacity(s32 callContext, struct GraphNode *node, UNUSED void *context) {
//     Gfx *dlStart, *dlHead;
//     struct GraphNodeGenerated *currentGraphNode;
//     s16 param;

//     dlStart = NULL;

//     if (callContext == GEO_CONTEXT_RENDER) {
//         currentGraphNode = (struct GraphNodeGenerated *) node;
//         param = currentGraphNode->parameter;
//         dlStart = alloc_display_list(sizeof(Gfx) * 3);

//         dlHead = dlStart;
//         if (param == 0) {
//             if (gMarioState->pos[0] < 3250.0f && gMarioState->pos[2] < -14000.0f) {
//                 sShowerOpacity[0] = approach_s16_symmetric(sShowerOpacity[0], 255, 0x4);
//                 sShowerOpacity[1] = approach_s16_symmetric(sShowerOpacity[1], 150, 0x4);
//             } else {
//                 sShowerOpacity[0] = approach_s16_symmetric(sShowerOpacity[0], 255, 0x4);
//                 sShowerOpacity[1] = approach_s16_symmetric(sShowerOpacity[1], 150, 0x4);
//             }
//         }
//         if (!gIsConsole) {
//             sShowerOpacity[0] = 150;
//             sShowerOpacity[1] = 150;
//         }

//         if (sShowerOpacity[param] == 255) {
//             currentGraphNode->fnNode.node.flags = 0x100 | (currentGraphNode->fnNode.node.flags & 0xFF);
//         } else {
//             currentGraphNode->fnNode.node.flags = 0x500 | (currentGraphNode->fnNode.node.flags & 0xFF);
//         }

//         gDPSetEnvColor(dlHead++, 0xAE, 0xC8, 0xD2, sShowerOpacity[param]);
//         gSPEndDisplayList(dlHead);
//     }

//     return dlStart;
// }



#ifdef AVOID_UB
Gfx *geo_switch_shower(s32 callContext, struct GraphNode *node, UNUSED void *context) {
#else
Gfx *geo_switch_shower(s32 callContext, struct GraphNode *node) {
#endif
    struct GraphNodeSwitchCase *switchCase;
    if (callContext == GEO_CONTEXT_RENDER) {
        // move to a local var because GraphNodes are passed in all geo functions.
        // cast the pointer.
        switchCase = (struct GraphNodeSwitchCase *) node;

        // if the case is greater than the number of cases, set to 0 to avoid overflowing
        // the switch.
        // assign the case number for execution.
        if (gMarioState->pos[2] > -14000.0f || gMarioState->pos[0] > 3250.0f || !gIsConsole) {
            switchCase->selectedCase = 0;
        } else {
            switchCase->selectedCase = 1;
        }
    }

    return NULL;
}


#ifdef AVOID_UB
Gfx *geo_switch_prebar(s32 callContext, struct GraphNode *node, UNUSED void *context) {
#else
Gfx *geo_switch_prebar(s32 callContext, struct GraphNode *node) {
#endif
    struct GraphNodeSwitchCase *switchCase;
    if (callContext == GEO_CONTEXT_RENDER) {
        // move to a local var because GraphNodes are passed in all geo functions.
        // cast the pointer.
        switchCase = (struct GraphNodeSwitchCase *) node;

        // if the case is greater than the number of cases, set to 0 to avoid overflowing
        // the switch.
        // assign the case number for execution.
        if (!gIsConsole || ((gCamera->comit2dcam == 0) || (gMarioState->pos[0] > 1500.0f || gMarioState->pos[2] < 1350.0f))) {
            switchCase->selectedCase = 0;
        } else {
            switchCase->selectedCase = 1;
        }
    }

    return NULL;
}



#ifdef AVOID_UB
Gfx *geo_switch_postbar(s32 callContext, struct GraphNode *node, UNUSED void *context) {
#else
Gfx *geo_switch_postbar(s32 callContext, struct GraphNode *node) {
#endif
    struct GraphNodeSwitchCase *switchCase;
    if (callContext == GEO_CONTEXT_RENDER) {
        // move to a local var because GraphNodes are passed in all geo functions.
        // cast the pointer.
        switchCase = (struct GraphNodeSwitchCase *) node;

        // if the case is greater than the number of cases, set to 0 to avoid overflowing
        // the switch.
        // assign the case number for execution.
        if (!gIsConsole || gMarioState->pos[2] > 500.0f) {
            switchCase->selectedCase = 0;
        } else {
            switchCase->selectedCase = 1;
        }
    }

    return NULL;
}


#ifdef AVOID_UB
Gfx *geo_switch_bar_wall(s32 callContext, struct GraphNode *node, UNUSED void *context) {
#else
Gfx *geo_switch_bar_wall(s32 callContext, struct GraphNode *node) {
#endif
    struct GraphNodeSwitchCase *switchCase;
    if (callContext == GEO_CONTEXT_RENDER) {
        // move to a local var because GraphNodes are passed in all geo functions.
        // cast the pointer.
        switchCase = (struct GraphNodeSwitchCase *) node;

        // if the case is greater than the number of cases, set to 0 to avoid overflowing
        // the switch.
        // assign the case number for execution.
        if (gCamera->comit2dcam) {
            switchCase->selectedCase = 1;
        } else {
            switchCase->selectedCase = 0;
        }
    }

    return NULL;
}

#ifdef AVOID_UB
Gfx *geo_switch_lounge(s32 callContext, struct GraphNode *node, UNUSED void *context) {
#else
Gfx *geo_switch_lounge(s32 callContext, struct GraphNode *node) {
#endif
    struct GraphNodeSwitchCase *switchCase;
    if (callContext == GEO_CONTEXT_RENDER) {
        // move to a local var because GraphNodes are passed in all geo functions.
        // cast the pointer.
        switchCase = (struct GraphNodeSwitchCase *) node;

        // if the case is greater than the number of cases, set to 0 to avoid overflowing
        // the switch.
        // assign the case number for execution.
        if (gMarioState->pos[2] < -12500.0f && gIsConsole) {
            switchCase->selectedCase = 1;
        } else {
            switchCase->selectedCase = 0;
        }
    }

    return NULL;
}


#ifdef AVOID_UB
Gfx *geo_switch_doghouse(s32 callContext, struct GraphNode *node, UNUSED void *context) {
#else
Gfx *geo_switch_doghouse(s32 callContext, struct GraphNode *node) {
#endif
    struct GraphNodeSwitchCase *switchCase;
    if (callContext == GEO_CONTEXT_RENDER) {
        // move to a local var because GraphNodes are passed in all geo functions.
        // cast the pointer.
        switchCase = (struct GraphNodeSwitchCase *) node;

        // if the case is greater than the number of cases, set to 0 to avoid overflowing
        // the switch.
        // assign the case number for execution.
        if (gMarioState->pos[0] < -3000.0f && gIsConsole) {
            switchCase->selectedCase = 1;
        } else {
            switchCase->selectedCase = 0;
        }
    }

    return NULL;
}

/*
render 1 if 
    x less than -6000
    OR: z less than 9100 and x less than -2000
*/
#ifdef AVOID_UB
Gfx *geo_switch_trophy_one(s32 callContext, struct GraphNode *node, UNUSED void *context) {
#else
Gfx *geo_switch_trophy_one(s32 callContext, struct GraphNode *node) {
#endif
    struct MarioState *m = gMarioState;
    struct GraphNodeSwitchCase *switchCase;
    if (callContext == GEO_CONTEXT_RENDER) {
        // move to a local var because GraphNodes are passed in all geo functions.
        // cast the pointer.
        switchCase = (struct GraphNodeSwitchCase *) node;

        // if the case is greater than the number of cases, set to 0 to avoid overflowing
        // the switch.
        // assign the case number for execution.
        if (m->pos[0] < -6000.0f || (m->pos[0] < -2000.0f && m->pos[2] < 9100.0f) || !gIsConsole) {
            switchCase->selectedCase = 0;
        } else {
            switchCase->selectedCase = 1;
        }
    }

    return NULL;
}

/*
render 2 if
    x greater than -2000 and z less than 7900
    OR: z greater than 11950 and x less than -3250
    OR: x greater than -3250 and z greater than 6600
*/

#ifdef AVOID_UB
Gfx *geo_switch_trophy_two(s32 callContext, struct GraphNode *node, UNUSED void *context) {
#else
Gfx *geo_switch_trophy_two(s32 callContext, struct GraphNode *node) {
#endif
    struct MarioState *m = gMarioState;
    struct GraphNodeSwitchCase *switchCase;
    if (callContext == GEO_CONTEXT_RENDER) {
        // move to a local var because GraphNodes are passed in all geo functions.
        // cast the pointer.
        switchCase = (struct GraphNodeSwitchCase *) node;

        // if the case is greater than the number of cases, set to 0 to avoid overflowing
        // the switch.
        // assign the case number for execution.
        //                                                                  -3250
        if ((((m->pos[0] > -2000.0f && m->pos[2] < 7900.0f) || (m->pos[0] < -4030.0f && m->pos[2] > 11950.0f) ||
            (m->pos[0] >= -4030.0f && m->pos[2] > 6600.0f) || (m->pos[0] > -3000.0f && m->pos[2] < 3600.0f)) && 
            m->pos[1] < 2000.0f) || !gIsConsole) {
            switchCase->selectedCase = 0;
        } else {
            switchCase->selectedCase = 1;
        }
    }

    return NULL;
}


#ifdef AVOID_UB
Gfx *geo_switch_plat_hall_repeats(s32 callContext, struct GraphNode *node, UNUSED void *context) {
#else
Gfx *geo_switch_plat_hall_repeats(s32 callContext, struct GraphNode *node) {
#endif
    struct MarioState *m = gMarioState;
    struct GraphNodeSwitchCase *switchCase;
    if (callContext == GEO_CONTEXT_RENDER) {
        // move to a local var because GraphNodes are passed in all geo functions.
        // cast the pointer.
        switchCase = (struct GraphNodeSwitchCase *) node;

        // if the case is greater than the number of cases, set to 0 to avoid overflowing
        // the switch.
        // assign the case number for execution.
        if (m->pos[2] > -5300.0f || !gIsConsole) {
            switchCase->selectedCase = 0;
        } else {
            switchCase->selectedCase = 1;
        }
    }

    return NULL;
}



#ifdef AVOID_UB
Gfx *geo_switch_laundry_backwall(s32 callContext, struct GraphNode *node, UNUSED void *context) {
#else
Gfx *geo_switch_laundry_backwall(s32 callContext, struct GraphNode *node) {
#endif
    struct MarioState *m = gMarioState;
    struct GraphNodeSwitchCase *switchCase;
    if (callContext == GEO_CONTEXT_RENDER) {
        // move to a local var because GraphNodes are passed in all geo functions.
        // cast the pointer.
        switchCase = (struct GraphNodeSwitchCase *) node;

        // if the case is greater than the number of cases, set to 0 to avoid overflowing
        // the switch.
        // assign the case number for execution.
        if (m->pos[0] > 6000.0f || m->pos[2] > 9000.0f || !gIsConsole) {
            switchCase->selectedCase = 0;
        } else {
            switchCase->selectedCase = 1;
        }
    }

    return NULL;
}


#ifdef AVOID_UB
Gfx *geo_switch_laundry_backwall2(s32 callContext, struct GraphNode *node, UNUSED void *context) {
#else
Gfx *geo_switch_laundry_backwall2(s32 callContext, struct GraphNode *node) {
#endif
    struct MarioState *m = gMarioState;
    struct GraphNodeSwitchCase *switchCase;
    if (callContext == GEO_CONTEXT_RENDER) {
        // move to a local var because GraphNodes are passed in all geo functions.
        // cast the pointer.
        switchCase = (struct GraphNodeSwitchCase *) node;

        // if the case is greater than the number of cases, set to 0 to avoid overflowing
        // the switch.
        // assign the case number for execution.
        if (m->pos[1] > 650.0f || (m->pos[2] < 7000.0f && m->pos[1] > 800.0f) || !gIsConsole) {
            switchCase->selectedCase = 0;
        } else {
            switchCase->selectedCase = 1;
        }
    }

    return NULL;
}


#ifdef AVOID_UB
Gfx *geo_switch_gym_one(s32 callContext, struct GraphNode *node, UNUSED void *context) {
#else
Gfx *geo_switch_gym_one(s32 callContext, struct GraphNode *node) {
#endif
    struct MarioState *m = gMarioState;
    struct GraphNodeSwitchCase *switchCase;
    if (callContext == GEO_CONTEXT_RENDER) {
        // move to a local var because GraphNodes are passed in all geo functions.
        // cast the pointer.
        switchCase = (struct GraphNodeSwitchCase *) node;

        // if the case is greater than the number of cases, set to 0 to avoid overflowing
        // the switch.
        // assign the case number for execution.
        if (m->pos[0] > -7500.0f || !gIsConsole) {
            switchCase->selectedCase = 0;
        } else {
            switchCase->selectedCase = 1;
        }
    }

    return NULL;
}



#ifdef AVOID_UB
Gfx *geo_switch_gym_two(s32 callContext, struct GraphNode *node, UNUSED void *context) {
#else
Gfx *geo_switch_gym_two(s32 callContext, struct GraphNode *node) {
#endif
    struct MarioState *m = gMarioState;
    struct GraphNodeSwitchCase *switchCase;
    if (callContext == GEO_CONTEXT_RENDER) {
        // move to a local var because GraphNodes are passed in all geo functions.
        // cast the pointer.
        switchCase = (struct GraphNodeSwitchCase *) node;

        // if the case is greater than the number of cases, set to 0 to avoid overflowing
        // the switch.
        // assign the case number for execution.
        if (m->pos[0] < -5500.0f || m->pos[1] > 1900.0f || !gIsConsole) {
            switchCase->selectedCase = 0;
        } else {
            switchCase->selectedCase = 1;
        }
    }

    return NULL;
}


#ifdef AVOID_UB
Gfx *geo_switch_gym_three(s32 callContext, struct GraphNode *node, UNUSED void *context) {
#else
Gfx *geo_switch_gym_three(s32 callContext, struct GraphNode *node) {
#endif
    struct MarioState *m = gMarioState;
    struct GraphNodeSwitchCase *switchCase;
    if (callContext == GEO_CONTEXT_RENDER) {
        // move to a local var because GraphNodes are passed in all geo functions.
        // cast the pointer.
        switchCase = (struct GraphNodeSwitchCase *) node;

        // if the case is greater than the number of cases, set to 0 to avoid overflowing
        // the switch.
        // assign the case number for execution.
        if ((m->pos[2] > -4000.0f && (m->pos[0] < -4500.0f || (m->pos[1] > 1800.0f && m->pos[2] > 0.0f))) || !gIsConsole) {
            switchCase->selectedCase = 0;
        } else {
            switchCase->selectedCase = 1;
        }
    }

    return NULL;
}


#ifdef AVOID_UB
Gfx *geo_switch_engine_first(s32 callContext, struct GraphNode *node, UNUSED void *context) {
#else
Gfx *geo_switch_engine_first(s32 callContext, struct GraphNode *node) {
#endif
    struct MarioState *m = gMarioState;
    struct GraphNodeSwitchCase *switchCase;
    if (callContext == GEO_CONTEXT_RENDER) {
        // move to a local var because GraphNodes are passed in all geo functions.
        // cast the pointer.
        switchCase = (struct GraphNodeSwitchCase *) node;

        // if the case is greater than the number of cases, set to 0 to avoid overflowing
        // the switch.
        // assign the case number for execution.
        if (m->pos[0] > 4000.0f || !gIsConsole) {
            switchCase->selectedCase = 0;
        } else {
            switchCase->selectedCase = 1;
        }
    }

    return NULL;
}



#ifdef AVOID_UB
Gfx *geo_switch_engine_middle(s32 callContext, struct GraphNode *node, UNUSED void *context) {
#else
Gfx *geo_switch_engine_middle(s32 callContext, struct GraphNode *node) {
#endif
    struct MarioState *m = gMarioState;
    struct GraphNodeSwitchCase *switchCase;
    if (callContext == GEO_CONTEXT_RENDER) {
        // move to a local var because GraphNodes are passed in all geo functions.
        // cast the pointer.
        switchCase = (struct GraphNodeSwitchCase *) node;

        // if the case is greater than the number of cases, set to 0 to avoid overflowing
        // the switch.
        // assign the case number for execution.
        if (m->pos[2] < -100.0f || m->pos[0] < 10000.0f || !gIsConsole) {
            switchCase->selectedCase = 0;
        } else {
            switchCase->selectedCase = 1;
        }
    }

    return NULL;
}


#ifdef AVOID_UB
Gfx *geo_switch_engine_last(s32 callContext, struct GraphNode *node, UNUSED void *context) {
#else
Gfx *geo_switch_engine_last(s32 callContext, struct GraphNode *node) {
#endif
    struct MarioState *m = gMarioState;
    struct GraphNodeSwitchCase *switchCase;
    if (callContext == GEO_CONTEXT_RENDER) {
        // move to a local var because GraphNodes are passed in all geo functions.
        // cast the pointer.
        switchCase = (struct GraphNodeSwitchCase *) node;

        // if the case is greater than the number of cases, set to 0 to avoid overflowing
        // the switch.
        // assign the case number for execution.
        if (m->pos[0] < 8000.0f || !gIsConsole) {
            switchCase->selectedCase = 0;
        } else {
            switchCase->selectedCase = 1;
        }
    }

    return NULL;
}


#ifdef AVOID_UB
Gfx *geo_switch_engine_wall(s32 callContext, struct GraphNode *node, UNUSED void *context) {
#else
Gfx *geo_switch_engine_wall(s32 callContext, struct GraphNode *node) {
#endif
    struct MarioState *m = gMarioState;
    struct GraphNodeSwitchCase *switchCase;
    if (callContext == GEO_CONTEXT_RENDER) {
        // move to a local var because GraphNodes are passed in all geo functions.
        // cast the pointer.
        switchCase = (struct GraphNodeSwitchCase *) node;

        // if the case is greater than the number of cases, set to 0 to avoid overflowing
        // the switch.
        // assign the case number for execution.
        if (m->pos[0] > 8224.0f) {
            switchCase->selectedCase = 0;
        } else {
            switchCase->selectedCase = 1;
        }
    }

    return NULL;
}


#ifdef AVOID_UB
Gfx *geo_switch_ice_backroom(s32 callContext, struct GraphNode *node, UNUSED void *context) {
#else
Gfx *geo_switch_ice_backroom(s32 callContext, struct GraphNode *node) {
#endif
    struct MarioState *m = gMarioState;
    struct GraphNodeSwitchCase *switchCase;
    if (callContext == GEO_CONTEXT_RENDER) {
        // move to a local var because GraphNodes are passed in all geo functions.
        // cast the pointer.
        switchCase = (struct GraphNodeSwitchCase *) node;

        // if the case is greater than the number of cases, set to 0 to avoid overflowing
        // the switch.
        // assign the case number for execution.
        if (m->pos[2] < -14500.0f || !gIsConsole) {
            switchCase->selectedCase = 0;
        } else {
            switchCase->selectedCase = 1;
        }
    }

    return NULL;
}


#ifdef AVOID_UB
Gfx *geo_switch_ice_somewalls(s32 callContext, struct GraphNode *node, UNUSED void *context) {
#else
Gfx *geo_switch_ice_somewalls(s32 callContext, struct GraphNode *node) {
#endif
    struct MarioState *m = gMarioState;
    struct GraphNodeSwitchCase *switchCase;
    if (callContext == GEO_CONTEXT_RENDER) {
        // move to a local var because GraphNodes are passed in all geo functions.
        // cast the pointer.
        switchCase = (struct GraphNodeSwitchCase *) node;

        // if the case is greater than the number of cases, set to 0 to avoid overflowing
        // the switch.
        // assign the case number for execution.
        if (m->pos[2] > -13500.0f || m->pos[2] < -14500.0f || m->pos[0] < 3000.0f || m->pos[1] < 13000.0f || !gIsConsole) {
            switchCase->selectedCase = 0;
        } else {
            switchCase->selectedCase = 1;
        }
    }

    return NULL;
}

#ifdef AVOID_UB
Gfx *geo_switch_dream_layers(s32 callContext, struct GraphNode *node, UNUSED void *context) {
#else
Gfx *geo_switch_dream_layers(s32 callContext, struct GraphNode *node) {
#endif
    struct MarioState *m = gMarioState;
    struct GraphNodeSwitchCase *switchCase;
    if (callContext == GEO_CONTEXT_RENDER) {
        // move to a local var because GraphNodes are passed in all geo functions.
        // cast the pointer.
        switchCase = (struct GraphNodeSwitchCase *) node;

        // if the case is greater than the number of cases, set to 0 to avoid overflowing
        // the switch.
        // assign the case number for execution.
        if (m->pos[1] < 7000.0f) {
            switchCase->selectedCase = 0;
        } else if (m->pos[1] < 12000.0f) {
            switchCase->selectedCase = 1;
        } else if (m->pos[1] < 15000.0f) {
            switchCase->selectedCase = 2;
        } else {
            switchCase->selectedCase = 3;
        }
    }

    return NULL;
}


#ifdef AVOID_UB
Gfx *geo_switch_o5_layers(s32 callContext, struct GraphNode *node, UNUSED void *context) {
#else
Gfx *geo_switch_o5_layers(s32 callContext, struct GraphNode *node) {
#endif
    struct MarioState *m = gMarioState;
    struct GraphNodeSwitchCase *switchCase;
    if (callContext == GEO_CONTEXT_RENDER) {
        // move to a local var because GraphNodes are passed in all geo functions.
        // cast the pointer.
        switchCase = (struct GraphNodeSwitchCase *) node;

        // if the case is greater than the number of cases, set to 0 to avoid overflowing
        // the switch.
        // assign the case number for execution.
        if (m->pos[1] < 2500.0f) {
            switchCase->selectedCase = 1;
        } else {
            switchCase->selectedCase = 0;
        }
    }

    return NULL;
}


#ifdef AVOID_UB
Gfx *geo_switch_memory_hole(s32 callContext, struct GraphNode *node, UNUSED void *context) {
#else
Gfx *geo_switch_memory_hole(s32 callContext, struct GraphNode *node) {
#endif
    struct MarioState *m = gMarioState;
    struct GraphNodeSwitchCase *switchCase;
    if (callContext == GEO_CONTEXT_RENDER) {
        // move to a local var because GraphNodes are passed in all geo functions.
        // cast the pointer.
        switchCase = (struct GraphNodeSwitchCase *) node;

        // if the case is greater than the number of cases, set to 0 to avoid overflowing
        // the switch.
        // assign the case number for execution.
        if (m->pos[1] > 4000.0f && (m->pos[0] > -21000.0f || m->pos[2] < -26000.0f)) {
            switchCase->selectedCase = 0;
        } else if (m->pos[1] > 4000.0f) {
            switchCase->selectedCase = 1;
        } else if (m->pos[1] > -2400.0f) {
            switchCase->selectedCase = 2;
        } else {
            switchCase->selectedCase = 3;
        }
    }

    return NULL;
}




#ifdef AVOID_UB
Gfx *geo_switch_observatory_top(s32 callContext, struct GraphNode *node, UNUSED void *context) {
#else
Gfx *geo_switch_observatory_top(s32 callContext, struct GraphNode *node) {
#endif
    struct MarioState *m = gMarioState;
    struct GraphNodeSwitchCase *switchCase;
    if (callContext == GEO_CONTEXT_RENDER) {
        // move to a local var because GraphNodes are passed in all geo functions.
        // cast the pointer.
        switchCase = (struct GraphNodeSwitchCase *) node;

        // if the case is greater than the number of cases, set to 0 to avoid overflowing
        // the switch.
        // assign the case number for execution.
        if (m->pos[1] < 9000.0f) {
            switchCase->selectedCase = 0;
        } else {
            switchCase->selectedCase = 1;
        }
    }

    return NULL;
}


#ifdef AVOID_UB
Gfx *geo_switch_palace(s32 callContext, struct GraphNode *node, UNUSED void *context) {
#else
Gfx *geo_switch_palace(s32 callContext, struct GraphNode *node) {
#endif
    struct MarioState *m = gMarioState;
    struct GraphNodeSwitchCase *switchCase;
    if (callContext == GEO_CONTEXT_RENDER) {
        // move to a local var because GraphNodes are passed in all geo functions.
        // cast the pointer.
        switchCase = (struct GraphNodeSwitchCase *) node;

        // if the case is greater than the number of cases, set to 0 to avoid overflowing
        // the switch.
        // assign the case number for execution.
        if (m->pos[0] < -14900.0f) {
            switchCase->selectedCase = 0;
        } else {
            switchCase->selectedCase = 1;
        }
    }

    return NULL;
}



#ifdef AVOID_UB
Gfx *geo_switch_boss_tunnel(s32 callContext, struct GraphNode *node, UNUSED void *context) {
#else
Gfx *geo_switch_boss_tunnel(s32 callContext, struct GraphNode *node) {
#endif
    struct MarioState *m = gMarioState;
    struct Object *obj;
    struct GraphNodeSwitchCase *switchCase;
    if (callContext == GEO_CONTEXT_RENDER) {
        // move to a local var because GraphNodes are passed in all geo functions.
        // cast the pointer.
        switchCase = (struct GraphNodeSwitchCase *) node;

        obj = CL_objptr_nearest_object_behavior(gMarioObject, bhvRoofHole);

        // if the case is greater than the number of cases, set to 0 to avoid overflowing
        // the switch.
        // assign the case number for execution.
        if (obj == NULL || obj->oOpacity != 255 || gMarioState->pos[1] > 13000.0f) {
            switchCase->selectedCase = 0;
        } else {
            switchCase->selectedCase = 1;
        }
    }

    return NULL;
}

extern s32 gCliffTimer;

#ifdef AVOID_UB
Gfx *geo_switch_boss_backwalls(s32 callContext, struct GraphNode *node, UNUSED void *context) {
#else
Gfx *geo_switch_boss_backwalls(s32 callContext, struct GraphNode *node) {
#endif
    struct MarioState *m = gMarioState;
    struct GraphNodeSwitchCase *switchCase;
    if (callContext == GEO_CONTEXT_RENDER) {
        // move to a local var because GraphNodes are passed in all geo functions.
        // cast the pointer.
        switchCase = (struct GraphNodeSwitchCase *) node;

        // if the case is greater than the number of cases, set to 0 to avoid overflowing
        // the switch.
        // assign the case number for execution.
        if (m->pos[2] < -11200.0f || m->pos[1] > 9000.0f || gCliffTimer || gCamera->comitCutscene != 0 || !gIsConsole) {
            switchCase->selectedCase = 0;
        } else {
            switchCase->selectedCase = 1;
        }
    }

    return NULL;
}


#ifdef AVOID_UB
Gfx *geo_switch_boss_startwalls(s32 callContext, struct GraphNode *node, UNUSED void *context) {
#else
Gfx *geo_switch_boss_startwalls(s32 callContext, struct GraphNode *node) {
#endif
    struct MarioState *m = gMarioState;
    struct GraphNodeSwitchCase *switchCase;
    if (callContext == GEO_CONTEXT_RENDER) {
        // move to a local var because GraphNodes are passed in all geo functions.
        // cast the pointer.
        switchCase = (struct GraphNodeSwitchCase *) node;

        // if the case is greater than the number of cases, set to 0 to avoid overflowing
        // the switch.
        // assign the case number for execution.
        if (m->pos[2] > -3500.0f || m->pos[1] > 9000.0f || gCliffTimer || gCamera->comitCutscene != 0  || !gIsConsole) {
            switchCase->selectedCase = 0;
        } else {
            switchCase->selectedCase = 1;
        }
    }

    return NULL;
}


#ifdef AVOID_UB
Gfx *geo_switch_lab_floor(s32 callContext, struct GraphNode *node, UNUSED void *context) {
#else
Gfx *geo_switch_lab_floor(s32 callContext, struct GraphNode *node) {
#endif
    struct MarioState *m = gMarioState;
    struct Object *obj = NULL;
    struct GraphNodeSwitchCase *switchCase;
    if (callContext == GEO_CONTEXT_RENDER) {
        // move to a local var because GraphNodes are passed in all geo functions.
        // cast the pointer.
        switchCase = (struct GraphNodeSwitchCase *) node;

        obj = CL_objptr_nearest_object_with_behavior_and_field(gMarioObject, bhvBoogooObject, 0x144, 2);
        // if the case is greater than the number of cases, set to 0 to avoid overflowing
        // the switch.
        // assign the case number for execution.
        if (obj == NULL || obj->oOpacity != 255) {
            switchCase->selectedCase = 0;
        } else {
            switchCase->selectedCase = 1;
        }
    }

    return NULL;
}

extern s32 gRedCoinMissionActive;
extern s32 gRedCoinLevel;

#ifdef AVOID_UB
Gfx *geo_switch_red_mission(s32 callContext, struct GraphNode *node, UNUSED void *context) {
#else
Gfx *geo_switch_red_mission(s32 callContext, struct GraphNode *node) {
#endif
    struct MarioState *m = gMarioState;
    struct GraphNodeSwitchCase *switchCase;
    if (callContext == GEO_CONTEXT_RENDER) {
        // move to a local var because GraphNodes are passed in all geo functions.
        // cast the pointer.
        switchCase = (struct GraphNodeSwitchCase *) node;

        // if the case is greater than the number of cases, set to 0 to avoid overflowing
        // the switch.
        // assign the case number for execution.
        if (gRedCoinMissionActive && gRedCoinLevel == gCurrLevelNum) {
            switchCase->selectedCase = 1;
        } else {
            switchCase->selectedCase = 0;
        }
    }

    return NULL;
}


extern s8 gGlobalMarioRoom;
extern s32 gMenuCutscene;

s32 sMenuRooms[] = {1, 2, 1, 1, 2, 1};

//! @bug Same issue as geo_switch_anim_state.
#ifdef AVOID_UB
Gfx *geo_switch_area(s32 callContext, struct GraphNode *node, UNUSED void *context) {
#else
Gfx *geo_switch_area(s32 callContext, struct GraphNode *node) {
#endif
    s16 sp26;
    struct Surface *sp20;
    struct Object *obj;
    struct GraphNodeSwitchCase *switchCase = (struct GraphNodeSwitchCase *) node;

    if (callContext == GEO_CONTEXT_RENDER) {
        if (gMarioObject == NULL) {
            switchCase->selectedCase = 0;
        } else {
            gFindFloorIncludeSurfaceIntangible = TRUE;

            find_floor(gMarioObject->oPosX, gMarioObject->oPosY, gMarioObject->oPosZ, &sp20);

            if (sp20) {
                gMarioCurrentRoom = sp20->room;
                if (sp20->object != NULL && sp20->object->oRoom != 0) {
                    gMarioCurrentRoom = sp20->object->oRoom;
                }
                if (gMarioCurrentRoom != gMarioPreviousRoom) {
                    obj = CL_objptr_nearest_object_behavior(gMarioObject, bhvAirborneDeathWarp);
                    if (obj != NULL)
                        obj->oRoom2 = gMarioCurrentRoom;
                }
                sp26 = sp20->room - 1;
                print_debug_top_down_objectinfo("areainfo %d", sp20->room);
                gGlobalMarioRoom = gMarioCurrentRoom + sLevelRoomOffsets[gCurrCourseNum - 1];
                if (sp26 >= 0) {
                    switchCase->selectedCase = sp26;
                }
            }
        }
    } else {
        switchCase->selectedCase = 0;
    }
    if (gCurrDemoInput != NULL) {
        gMarioCurrentRoom = sMenuRooms[gMenuCutscene];
        switchCase->selectedCase = gMarioCurrentRoom - 1;
    }

    return NULL;
}


/**
 *  Uses case 0 on emulator, case 1 on console.
 */
#ifdef AVOID_UB
Gfx *geo_switch_console(s32 callContext, struct GraphNode *node, UNUSED void *context) {
#else
Gfx *geo_switch_console(s32 callContext, struct GraphNode *node) {
#endif
    struct GraphNodeSwitchCase *switchCase;

    if (callContext == GEO_CONTEXT_RENDER) {
        switchCase = (struct GraphNodeSwitchCase *) node;
        switchCase->selectedCase = gIsConsole;
    }

    return NULL;
}

void obj_update_pos_from_parent_transformation(Mat4 a0, struct Object *a1) {
    f32 spC = a1->oParentRelativePosX;
    f32 sp8 = a1->oParentRelativePosY;
    f32 sp4 = a1->oParentRelativePosZ;

    a1->oPosX = spC * a0[0][0] + sp8 * a0[1][0] + sp4 * a0[2][0] + a0[3][0];
    a1->oPosY = spC * a0[0][1] + sp8 * a0[1][1] + sp4 * a0[2][1] + a0[3][1];
    a1->oPosZ = spC * a0[0][2] + sp8 * a0[1][2] + sp4 * a0[2][2] + a0[3][2];
}

void obj_apply_scale_to_matrix(struct Object *obj, Mat4 dst, Mat4 src) {
    dst[0][0] = src[0][0] * obj->header.gfx.scale[0];
    dst[1][0] = src[1][0] * obj->header.gfx.scale[1];
    dst[2][0] = src[2][0] * obj->header.gfx.scale[2];
    dst[3][0] = src[3][0];

    dst[0][1] = src[0][1] * obj->header.gfx.scale[0];
    dst[1][1] = src[1][1] * obj->header.gfx.scale[1];
    dst[2][1] = src[2][1] * obj->header.gfx.scale[2];
    dst[3][1] = src[3][1];

    dst[0][2] = src[0][2] * obj->header.gfx.scale[0];
    dst[1][2] = src[1][2] * obj->header.gfx.scale[1];
    dst[2][2] = src[2][2] * obj->header.gfx.scale[2];
    dst[3][2] = src[3][2];

    dst[0][3] = src[0][3];
    dst[1][3] = src[1][3];
    dst[2][3] = src[2][3];
    dst[3][3] = src[3][3];
}

void create_transformation_from_matrices(Mat4 a0, Mat4 a1, Mat4 a2) {
    f32 spC, sp8, sp4;

    spC = a2[3][0] * a2[0][0] + a2[3][1] * a2[0][1] + a2[3][2] * a2[0][2];
    sp8 = a2[3][0] * a2[1][0] + a2[3][1] * a2[1][1] + a2[3][2] * a2[1][2];
    sp4 = a2[3][0] * a2[2][0] + a2[3][1] * a2[2][1] + a2[3][2] * a2[2][2];

    a0[0][0] = a1[0][0] * a2[0][0] + a1[0][1] * a2[0][1] + a1[0][2] * a2[0][2];
    a0[0][1] = a1[0][0] * a2[1][0] + a1[0][1] * a2[1][1] + a1[0][2] * a2[1][2];
    a0[0][2] = a1[0][0] * a2[2][0] + a1[0][1] * a2[2][1] + a1[0][2] * a2[2][2];

    a0[1][0] = a1[1][0] * a2[0][0] + a1[1][1] * a2[0][1] + a1[1][2] * a2[0][2];
    a0[1][1] = a1[1][0] * a2[1][0] + a1[1][1] * a2[1][1] + a1[1][2] * a2[1][2];
    a0[1][2] = a1[1][0] * a2[2][0] + a1[1][1] * a2[2][1] + a1[1][2] * a2[2][2];

    a0[2][0] = a1[2][0] * a2[0][0] + a1[2][1] * a2[0][1] + a1[2][2] * a2[0][2];
    a0[2][1] = a1[2][0] * a2[1][0] + a1[2][1] * a2[1][1] + a1[2][2] * a2[1][2];
    a0[2][2] = a1[2][0] * a2[2][0] + a1[2][1] * a2[2][1] + a1[2][2] * a2[2][2];

    a0[3][0] = a1[3][0] * a2[0][0] + a1[3][1] * a2[0][1] + a1[3][2] * a2[0][2] - spC;
    a0[3][1] = a1[3][0] * a2[1][0] + a1[3][1] * a2[1][1] + a1[3][2] * a2[1][2] - sp8;
    a0[3][2] = a1[3][0] * a2[2][0] + a1[3][1] * a2[2][1] + a1[3][2] * a2[2][2] - sp4;

    a0[0][3] = 0;
    a0[1][3] = 0;
    a0[2][3] = 0;
    a0[3][3] = 1.0f;
}

void obj_set_held_state(struct Object *obj, const BehaviorScript *heldBehavior) {
    obj->parentObj = o;

    if (obj->oFlags & OBJ_FLAG_HOLDABLE) {
        if (heldBehavior == bhvCarrySomething3) {
            obj->oHeldState = HELD_HELD;
        }

        if (heldBehavior == bhvCarrySomething5) {
            obj->oHeldState = HELD_THROWN;
        }

        if (heldBehavior == bhvCarrySomething4) {
            obj->oHeldState = HELD_DROPPED;
        }
    } else {
        obj->curBhvCommand = segmented_to_virtual(heldBehavior);
        obj->bhvStackIndex = 0;
    }
}

f32 lateral_dist_between_objects(struct Object *obj1, struct Object *obj2) {
    f32 dx = obj1->oPosX - obj2->oPosX;
    f32 dz = obj1->oPosZ - obj2->oPosZ;

    return sqrtf(dx * dx + dz * dz);
}

f32 dist_between_objects(struct Object *obj1, struct Object *obj2) {
    f32 dx = obj1->oPosX - obj2->oPosX;
    f32 dy = obj1->oPosY - obj2->oPosY;
    f32 dz = obj1->oPosZ - obj2->oPosZ;

    return sqrtf(dx * dx + dy * dy + dz * dz);
}

void cur_obj_forward_vel_approach_upward(f32 target, f32 increment) {
    if (o->oForwardVel >= target) {
        o->oForwardVel = target;
    } else {
        o->oForwardVel += increment;
    }
}

s32 approach_f32_signed(f32 *value, f32 target, f32 increment) {
    s32 reachedTarget = FALSE;

    *value += increment;

    if (increment >= 0.0f) {
        if (*value > target) {
            *value = target;
            reachedTarget = TRUE;
        }
    } else {
        if (*value < target) {
            *value = target;
            reachedTarget = TRUE;
        }
    }

    return reachedTarget;
}

f32 approach_f32_symmetric(f32 value, f32 target, f32 increment) {
    f32 dist;

    if ((dist = target - value) >= 0.0f) {
        if (dist > increment) {
            value += increment;
        } else {
            value = target;
        }
    } else {
        if (dist < -increment) {
            value -= increment;
        } else {
            value = target;
        }
    }

    return value;
}

s16 approach_s16_symmetric(s16 value, s16 target, s16 increment) {
    s16 dist = target - value;

    if (dist >= 0) {
        if (dist > increment) {
            value += increment;
        } else {
            value = target;
        }
    } else {
        if (dist < -increment) {
            value -= increment;
        } else {
            value = target;
        }
    }

    return value;
}

s32 cur_obj_rotate_yaw_toward(s16 target, s16 increment) {
    s16 startYaw;

    startYaw = (s16) o->oMoveAngleYaw;
    o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, target, increment);

    if ((o->oAngleVelYaw = (s16)((s16) o->oMoveAngleYaw - startYaw)) == 0) {
        return TRUE;
    } else {
        return FALSE;
    }
}

s16 obj_angle_to_object(struct Object *obj1, struct Object *obj2) {
    f32 z1, x1, z2, x2;
    s16 angle;

    z1 = obj1->oPosZ; z2 = obj2->oPosZ; // ordering of instructions..
    x1 = obj1->oPosX; x2 = obj2->oPosX;

    angle = atan2s(z2 - z1, x2 - x1);
    return angle;
}

s16 obj_turn_toward_object(struct Object *obj, struct Object *target, s16 angleIndex, s16 turnAmount) {
    f32 a, b, c, d;
    UNUSED u8 filler[4];
    s16 targetAngle, startAngle;

    switch (angleIndex) {
        case O_MOVE_ANGLE_PITCH_INDEX:
        case O_FACE_ANGLE_PITCH_INDEX:
            a = target->oPosX - obj->oPosX;
            c = target->oPosZ - obj->oPosZ;
            a = sqrtf(a * a + c * c);

            b = -obj->oPosY;
            d = -target->oPosY;

            targetAngle = atan2s(a, d - b);
            break;

        case O_MOVE_ANGLE_YAW_INDEX:
        case O_FACE_ANGLE_YAW_INDEX:
            a = obj->oPosZ;
            c = target->oPosZ;
            b = obj->oPosX;
            d = target->oPosX;

            targetAngle = atan2s(c - a, d - b);
            break;
    }

    startAngle = o->rawData.asU32[angleIndex];
    o->rawData.asU32[angleIndex] = approach_s16_symmetric(startAngle, targetAngle, turnAmount);
    return targetAngle;
}

void obj_set_parent_relative_pos(struct Object *obj, s16 relX, s16 relY, s16 relZ) {
    obj->oParentRelativePosX = relX;
    obj->oParentRelativePosY = relY;
    obj->oParentRelativePosZ = relZ;
}

void obj_set_pos(struct Object *obj, s16 x, s16 y, s16 z) {
    obj->oPosX = x;
    obj->oPosY = y;
    obj->oPosZ = z;
}

void obj_set_angle(struct Object *obj, s16 pitch, s16 yaw, s16 roll) {
    obj->oFaceAnglePitch = pitch;
    obj->oFaceAngleYaw = yaw;
    obj->oFaceAngleRoll = roll;

    obj->oMoveAnglePitch = pitch;
    obj->oMoveAngleYaw = yaw;
    obj->oMoveAngleRoll = roll;
}

/*
 * Spawns an object at an absolute location with a specified angle.
 */
struct Object *spawn_object_abs_with_rot(struct Object *parent, s16 uselessArg, u32 model,
                                         const BehaviorScript *behavior,
                                         s16 x, s16 y, s16 z, s16 pitch, s16 yaw, s16 roll) {
    // 'uselessArg' is unused in the function spawn_object_at_origin()
    struct Object *newObj = spawn_object_at_origin(parent, uselessArg, model, behavior);
    obj_set_pos(newObj, x, y, z);
    obj_set_angle(newObj, pitch, yaw, roll);

    return newObj;
}

/*
 * Spawns an object relative to the parent with a specified angle... is what it is supposed to do.
 * The roll argument is never used, and the z offset is used for z-rotation instead. This is most likely
 * a copy-paste typo by one of the programmers.
 */
struct Object *spawn_object_rel_with_rot(struct Object *parent, u32 model, const BehaviorScript *behavior,
                                         s16 xOff, s16 yOff, s16 zOff, s16 pitch, s16 yaw, UNUSED s16 roll) {
    struct Object *newObj = spawn_object_at_origin(parent, 0, model, behavior);
    newObj->oFlags |= OBJ_FLAG_TRANSFORM_RELATIVE_TO_PARENT;
    obj_set_parent_relative_pos(newObj, xOff, yOff, zOff);
    obj_set_angle(newObj, pitch, yaw, zOff); // Nice typo you got there Nintendo.

    return newObj;
}

struct Object *spawn_obj_with_transform_flags(struct Object *sp20, s32 model, const BehaviorScript *sp28) {
    struct Object *sp1C = spawn_object(sp20, model, sp28);
    sp1C->oFlags |= OBJ_FLAG_0020 | OBJ_FLAG_SET_THROW_MATRIX_FROM_TRANSFORM;
    return sp1C;
}

struct Object *spawn_water_droplet(struct Object *parent, struct WaterDropletParams *params) {
    f32 randomScale;
    struct Object *newObj = spawn_object(parent, params->model, params->behavior);

    if (params->flags & WATER_DROPLET_FLAG_RAND_ANGLE) {
        newObj->oMoveAngleYaw = random_u16();
    }

    if (params->flags & WATER_DROPLET_FLAG_RAND_ANGLE_INCR_PLUS_8000) {
        newObj->oMoveAngleYaw = (s16)(newObj->oMoveAngleYaw + 0x8000)
                                + (s16) random_f32_around_zero(params->moveAngleRange);
    }

    if (params->flags & WATER_DROPLET_FLAG_RAND_ANGLE_INCR) {
        newObj->oMoveAngleYaw =
            (s16) newObj->oMoveAngleYaw + (s16) random_f32_around_zero(params->moveAngleRange);
    }

    if (params->flags & WATER_DROPLET_FLAG_SET_Y_TO_WATER_LEVEL) {
        newObj->oPosY = find_water_level(newObj->oPosX, newObj->oPosZ);
    }

    if (params->flags & WATER_DROPLET_FLAG_RAND_OFFSET_XZ) {
        obj_translate_xz_random(newObj, params->moveRange);
    }

    if (params->flags & WATER_DROPLET_FLAG_RAND_OFFSET_XYZ) {
        obj_translate_xyz_random(newObj, params->moveRange);
    }

    newObj->oForwardVel = random_float() * params->randForwardVelScale + params->randForwardVelOffset;
    newObj->oVelY = random_float() * params->randYVelScale + params->randYVelOffset;

    randomScale = random_float() * params->randSizeScale + params->randSizeOffset;
    obj_scale(newObj, randomScale);

    return newObj;
}

struct Object *spawn_object_at_origin(struct Object *parent, UNUSED s32 unusedArg, u32 model,
                                      const BehaviorScript *behavior) {
    struct Object *obj;
    const BehaviorScript *behaviorAddr;

    behaviorAddr = segmented_to_virtual(behavior);
    obj = create_object(behaviorAddr);
    obj->oFlags |= OBJ_FLAG_DISABLE_ON_ROOM_EXIT;

    obj->parentObj = parent;
    obj->header.gfx.areaIndex = parent->header.gfx.areaIndex;
    obj->header.gfx.activeAreaIndex = parent->header.gfx.areaIndex;

    geo_obj_init((struct GraphNodeObject *) &obj->header.gfx, gLoadedGraphNodes[model], gVec3fZero,
                 gVec3sZero);

    return obj;
}

struct Object *spawn_object(struct Object *parent, s32 model, const BehaviorScript *behavior) {
    struct Object *obj = spawn_object_at_origin(parent, 0, model, behavior);

    obj_copy_pos_and_angle(obj, parent);

    return obj;
}

struct Object *try_to_spawn_object(s16 offsetY, f32 scale, struct Object *parent, s32 model,
                                   const BehaviorScript *behavior) {
    struct Object *obj;

    if (gFreeObjectList.next != NULL) {
        obj = spawn_object(parent, model, behavior);
        obj->oPosY += offsetY;
        obj_scale(obj, scale);
        return obj;
    } else {
        return NULL;
    }
}

struct Object *spawn_object_with_scale(struct Object *parent, s32 model, const BehaviorScript *behavior, f32 scale) {
    struct Object *obj = spawn_object_at_origin(parent, 0, model, behavior);

    obj_copy_pos_and_angle(obj, parent);
    obj_scale(obj, scale);

    return obj;
}

static void obj_build_relative_transform(struct Object *obj) {
    obj_build_transform_from_pos_and_angle(obj, O_PARENT_RELATIVE_POS_INDEX, O_FACE_ANGLE_INDEX);
    obj_translate_local(obj, O_POS_INDEX, O_PARENT_RELATIVE_POS_INDEX);
}

struct Object *spawn_object_relative(s16 behaviorParam, s16 relativePosX, s16 relativePosY, s16 relativePosZ,
                                     struct Object *parent, s32 model, const BehaviorScript *behavior) {
    struct Object *obj = spawn_object_at_origin(parent, 0, model, behavior);

    obj_copy_pos_and_angle(obj, parent);
    obj_set_parent_relative_pos(obj, relativePosX, relativePosY, relativePosZ);
    obj_build_relative_transform(obj);

    obj->oBehParams2ndByte = behaviorParam;
    obj->oBehParams = (behaviorParam & 0xFF) << 16;

    return obj;
}

struct Object *spawn_object_relative_with_scale(s16 behaviorParam, s16 relativePosX, s16 relativePosY,
                                                s16 relativePosZ, f32 scale, struct Object *parent,
                                                s32 model, const BehaviorScript *behavior) {
    struct Object *obj = spawn_object_relative(behaviorParam, relativePosX, relativePosY, relativePosZ,
                                               parent, model, behavior);
    obj_scale(obj, scale);

    return obj;
}

void cur_obj_move_using_vel(void) {
    o->oPosX += o->oVelX;
    o->oPosY += o->oVelY;
    o->oPosZ += o->oVelZ;
}

void obj_copy_graph_y_offset(struct Object *dst, struct Object *src) {
    dst->oGraphYOffset = src->oGraphYOffset;
}

void obj_copy_pos_and_angle(struct Object *dst, struct Object *src) {
    obj_copy_pos(dst, src);
    obj_copy_angle(dst, src);
}

void obj_copy_pos(struct Object *dst, struct Object *src) {
    dst->oPosX = src->oPosX;
    dst->oPosY = src->oPosY;
    dst->oPosZ = src->oPosZ;
}

void obj_copy_angle(struct Object *dst, struct Object *src) {
    dst->oMoveAnglePitch = src->oMoveAnglePitch;
    dst->oMoveAngleYaw = src->oMoveAngleYaw;
    dst->oMoveAngleRoll = src->oMoveAngleRoll;

    dst->oFaceAnglePitch = src->oFaceAnglePitch;
    dst->oFaceAngleYaw = src->oFaceAngleYaw;
    dst->oFaceAngleRoll = src->oFaceAngleRoll;
}

void obj_set_gfx_pos_from_pos(struct Object *obj) {
    obj->header.gfx.pos[0] = obj->oPosX;
    obj->header.gfx.pos[1] = obj->oPosY;
    obj->header.gfx.pos[2] = obj->oPosZ;
}

void obj_init_animation(struct Object *obj, s32 animIndex) {
    struct Animation **anims = o->oAnimations;
    geo_obj_init_animation(&obj->header.gfx, &anims[animIndex]);
}

/**
 * Multiply a vector by a matrix of the form
 * | ? ? ? 0 |
 * | ? ? ? 0 |
 * | ? ? ? 0 |
 * | 0 0 0 1 |
 * i.e. a matrix representing a linear transformation over 3 space.
 */
void linear_mtxf_mul_vec3f(Mat4 m, Vec3f dst, Vec3f v) {
    s32 i;
    for (i = 0; i < 3; i++) {
        dst[i] = m[0][i] * v[0] + m[1][i] * v[1] + m[2][i] * v[2];
    }
}

/**
 * Multiply a vector by the transpose of a matrix of the form
 * | ? ? ? 0 |
 * | ? ? ? 0 |
 * | ? ? ? 0 |
 * | 0 0 0 1 |
 * i.e. a matrix representing a linear transformation over 3 space.
 */
void linear_mtxf_transpose_mul_vec3f(Mat4 m, Vec3f dst, Vec3f v) {
    s32 i;
    for (i = 0; i < 3; i++) {
        dst[i] = m[i][0] * v[0] + m[i][1] * v[1] + m[i][2] * v[2];
    }
}

void obj_apply_scale_to_transform(struct Object *obj) {
    f32 scaleX = obj->header.gfx.scale[0];
    f32 scaleY = obj->header.gfx.scale[1];
    f32 scaleZ = obj->header.gfx.scale[2];

    obj->transform[0][0] *= scaleX;
    obj->transform[0][1] *= scaleX;
    obj->transform[0][2] *= scaleX;

    obj->transform[1][0] *= scaleY;
    obj->transform[1][1] *= scaleY;
    obj->transform[1][2] *= scaleY;

    obj->transform[2][0] *= scaleZ;
    obj->transform[2][1] *= scaleZ;
    obj->transform[2][2] *= scaleZ;
}

void obj_copy_scale(struct Object *dst, struct Object *src) {
    dst->header.gfx.scale[0] = src->header.gfx.scale[0];
    dst->header.gfx.scale[1] = src->header.gfx.scale[1];
    dst->header.gfx.scale[2] = src->header.gfx.scale[2];
}

void obj_scale_xyz(struct Object *obj, f32 xScale, f32 yScale, f32 zScale) {
    obj->header.gfx.scale[0] = xScale;
    obj->header.gfx.scale[1] = yScale;
    obj->header.gfx.scale[2] = zScale;
}

void obj_scale(struct Object *obj, f32 scale) {
    obj->header.gfx.scale[0] = scale;
    obj->header.gfx.scale[1] = scale;
    obj->header.gfx.scale[2] = scale;
}

void cur_obj_scale(f32 scale) {
    o->header.gfx.scale[0] = scale;
    o->header.gfx.scale[1] = scale;
    o->header.gfx.scale[2] = scale;
}

void cur_obj_init_animation(s32 animIndex) {
    struct Animation **anims = o->oAnimations;
    geo_obj_init_animation(&o->header.gfx, &anims[animIndex]);
}

void cur_obj_init_animation_with_sound(s32 animIndex) {
    struct Animation **anims = o->oAnimations;
    geo_obj_init_animation(&o->header.gfx, &anims[animIndex]);
    o->oSoundStateID = animIndex;
}

void cur_obj_init_animation_with_accel_and_sound(s32 animIndex, f32 accel) {
    struct Animation **anims = o->oAnimations;
    s32 animAccel = (s32)(accel * 65536.0f);
    geo_obj_init_animation_accel(&o->header.gfx, &anims[animIndex], animAccel);
    o->oSoundStateID = animIndex;
}

void obj_init_animation_with_sound(struct Object *obj, const struct Animation * const* animations, s32 animIndex) {
    struct Animation **anims = (struct Animation **)animations;
    obj->oAnimations = (struct Animation **)animations;
    geo_obj_init_animation(&obj->header.gfx, &anims[animIndex]);
    obj->oSoundStateID = animIndex;
}

void cur_obj_enable_rendering_and_become_tangible(struct Object *obj) {
    obj->header.gfx.node.flags |= GRAPH_RENDER_ACTIVE;
    obj->oIntangibleTimer = 0;
}

void cur_obj_enable_rendering(void) {
    o->header.gfx.node.flags |= GRAPH_RENDER_ACTIVE;
}

void cur_obj_disable_rendering_and_become_intangible(struct Object *obj) {
    obj->header.gfx.node.flags &= ~GRAPH_RENDER_ACTIVE;
    obj->oIntangibleTimer = -1;
}

void cur_obj_disable_rendering(void) {
    o->header.gfx.node.flags &= ~GRAPH_RENDER_ACTIVE;
}

void cur_obj_unhide(void) {
    o->header.gfx.node.flags &= ~GRAPH_RENDER_INVISIBLE;
}

void cur_obj_hide(void) {
    o->header.gfx.node.flags |= GRAPH_RENDER_INVISIBLE;
}

void cur_obj_set_pos_relative(struct Object *other, f32 dleft, f32 dy, f32 dforward) {
    f32 facingZ = coss(other->oMoveAngleYaw);
    f32 facingX = sins(other->oMoveAngleYaw);

    f32 dz = dforward * facingZ - dleft * facingX;
    f32 dx = dforward * facingX + dleft * facingZ;

    o->oMoveAngleYaw = other->oMoveAngleYaw;

    o->oPosX = other->oPosX + dx;
    o->oPosY = other->oPosY + dy;
    o->oPosZ = other->oPosZ + dz;
}

void cur_obj_set_pos_relative_to_parent(f32 dleft, f32 dy, f32 dforward) {
    cur_obj_set_pos_relative(o->parentObj, dleft, dy, dforward);
}

void cur_obj_enable_rendering_2(void) {
    cur_obj_enable_rendering();
}

void cur_obj_unused_init_on_floor(void) {
    cur_obj_enable_rendering();

    o->oPosY = find_floor_height(o->oPosX, o->oPosY, o->oPosZ);
    if (o->oPosY < FLOOR_LOWER_LIMIT_MISC) {
        cur_obj_set_pos_relative_to_parent(0, 0, -70);
        o->oPosY = find_floor_height(o->oPosX, o->oPosY, o->oPosZ);
    }
}

void obj_set_face_angle_to_move_angle(struct Object *obj) {
    obj->oFaceAnglePitch = obj->oMoveAnglePitch;
    obj->oFaceAngleYaw = obj->oMoveAngleYaw;
    obj->oFaceAngleRoll = obj->oMoveAngleRoll;
}

u32 get_object_list_from_behavior(const BehaviorScript *behavior) {
    u32 objectList;

    // If the first behavior command is "begin", then get the object list header
    // from there
    if ((behavior[0] >> 24) == 0) {
        objectList = (behavior[0] >> 16) & 0xFFFF;
    } else {
        objectList = OBJ_LIST_DEFAULT;
    }

    return objectList;
}

struct Object *cur_obj_nearest_object_with_behavior(const BehaviorScript *behavior) {
    struct Object *obj;
    f32 dist;

    obj = cur_obj_find_nearest_object_with_behavior(behavior, &dist);

    return obj;
}

f32 cur_obj_dist_to_nearest_object_with_behavior(const BehaviorScript *behavior) {
    struct Object *obj;
    f32 dist;

    obj = cur_obj_find_nearest_object_with_behavior(behavior, &dist);
    if (obj == NULL) {
        dist = 15000.0f;
    }

    return dist;
}

struct Object *cur_obj_find_nearest_object_with_behavior(const BehaviorScript *behavior, f32 *dist) {
    uintptr_t *behaviorAddr = segmented_to_virtual(behavior);
    struct Object *closestObj = NULL;
    struct Object *obj;
    struct ObjectNode *listHead;
    f32 minDist = 0x20000;

    listHead = &gObjectLists[get_object_list_from_behavior(behaviorAddr)];
    obj = (struct Object *) listHead->next;

    while (obj != (struct Object *) listHead) {
        if (obj->behavior == behaviorAddr) {
            if (obj->activeFlags != ACTIVE_FLAG_DEACTIVATED && obj != o) {
                f32 objDist = dist_between_objects(o, obj);
                if (objDist < minDist) {
                    closestObj = obj;
                    minDist = objDist;
                }
            }
        }
        obj = (struct Object *) obj->header.next;
    }

    *dist = minDist;
    return closestObj;
}

struct Object *find_unimportant_object(void) {
    struct ObjectNode *listHead = &gObjectLists[OBJ_LIST_UNIMPORTANT];
    struct ObjectNode *obj = listHead->next;

    if (listHead == obj) {
        obj = NULL;
    }

    return (struct Object *) obj;
}

s32 count_unimportant_objects(void) {
    struct ObjectNode *listHead = &gObjectLists[OBJ_LIST_UNIMPORTANT];
    struct ObjectNode *obj = listHead->next;
    s32 count = 0;

    while (listHead != obj) {
        count++;
        obj = obj->next;
    }

    return count;
}

s32 count_objects_with_behavior(const BehaviorScript *behavior) {
    uintptr_t *behaviorAddr = segmented_to_virtual(behavior);
    struct ObjectNode *listHead = &gObjectLists[get_object_list_from_behavior(behaviorAddr)];
    struct ObjectNode *obj = listHead->next;
    s32 count = 0;

    while (listHead != obj) {
        if (((struct Object *) obj)->behavior == behaviorAddr) {
            count++;
        }

        obj = obj->next;
    }

    return count;
}


s32 count_room_objects_with_behavior(const BehaviorScript *behavior, u32 room) {
    uintptr_t *behaviorAddr = segmented_to_virtual(behavior);
    struct ObjectNode *listHead = &gObjectLists[get_object_list_from_behavior(behaviorAddr)];
    struct ObjectNode *obj = listHead->next;
    s32 count = 0;

    while (listHead != obj) {
        if (((struct Object *) obj)->behavior == behaviorAddr && ((struct Object *) obj)->oRoom == room) {
            count++;
        }

        obj = obj->next;
    }

    return count;
}

struct Object *cur_obj_find_nearby_held_actor(const BehaviorScript *behavior, f32 maxDist) {
    const BehaviorScript *behaviorAddr = segmented_to_virtual(behavior);
    struct ObjectNode *listHead;
    struct Object *obj;
    struct Object *foundObj;

    listHead = &gObjectLists[OBJ_LIST_GENACTOR];
    obj = (struct Object *) listHead->next;
    foundObj = NULL;

    while ((struct Object *) listHead != obj) {
        if (obj->behavior == behaviorAddr) {
            if (obj->activeFlags != ACTIVE_FLAG_DEACTIVATED) {
                // This includes the dropped and thrown states. By combining instant
                // release, this allows us to activate mama penguin remotely
                if (obj->oHeldState != HELD_FREE) {
                    if (dist_between_objects(o, obj) < maxDist) {
                        foundObj = obj;
                        break;
                    }
                }
            }
        }

        obj = (struct Object *) obj->header.next;
    }

    return foundObj;
}

static void cur_obj_reset_timer_and_subaction(void) {
    o->oTimer = 0;
    o->oSubAction = 0;
}

void cur_obj_change_action(s32 action) {
    o->oAction = action;
    o->oPrevAction = action;
    cur_obj_reset_timer_and_subaction();
}

void cur_obj_set_vel_from_mario_vel(f32 f12, f32 f14) {
    f32 sp4 = gMarioStates[0].forwardVel;
    f32 sp0 = f12 * f14;

    if (sp4 < sp0) {
        o->oForwardVel = sp0;
    } else {
        o->oForwardVel = sp4 * f14;
    }
}

BAD_RETURN(s16) cur_obj_reverse_animation(void) {
    if (o->header.gfx.animInfo.animFrame >= 0) {
        o->header.gfx.animInfo.animFrame--;
    }
}

BAD_RETURN(s32) cur_obj_extend_animation_if_at_end(void) {
    s32 sp4 = o->header.gfx.animInfo.animFrame;
    s32 sp0 = o->header.gfx.animInfo.curAnim->loopEnd - 2;

    if (sp4 == sp0) o->header.gfx.animInfo.animFrame--;
}

s32 cur_obj_check_if_near_animation_end(void) {
    u32 animFlags = (s32) o->header.gfx.animInfo.curAnim->flags;
    s32 animFrame = o->header.gfx.animInfo.animFrame;
    s32 nearLoopEnd = o->header.gfx.animInfo.curAnim->loopEnd - 2;
    s32 isNearEnd = FALSE;

    if (animFlags & ANIM_FLAG_NOLOOP && nearLoopEnd + 1 == animFrame) {
        isNearEnd = TRUE;
    }

    if (animFrame == nearLoopEnd) {
        isNearEnd = TRUE;
    }

    return isNearEnd;
}

s32 cur_obj_check_if_at_animation_end(void) {
    s32 animFrame = o->header.gfx.animInfo.animFrame;
    s32 lastFrame = o->header.gfx.animInfo.curAnim->loopEnd - 1;

    if (animFrame == lastFrame) {
        return TRUE;
    } else {
        return FALSE;
    }
}

s32 cur_obj_check_anim_frame(s32 frame) {
    s32 animFrame = o->header.gfx.animInfo.animFrame;

    if (animFrame == frame) {
        return TRUE;
    } else {
        return FALSE;
    }
}

s32 cur_obj_check_anim_frame_in_range(s32 startFrame, s32 rangeLength) {
    s32 animFrame = o->header.gfx.animInfo.animFrame;

    if (animFrame >= startFrame && animFrame < startFrame + rangeLength) {
        return TRUE;
    } else {
        return FALSE;
    }
}

s32 cur_obj_check_frame_prior_current_frame(s16 *a0) {
    s16 sp6 = o->header.gfx.animInfo.animFrame;

    while (*a0 != -1) {
        if (*a0 == sp6) {
            return TRUE;
        }

        a0++;
    }

    return FALSE;
}

s32 mario_is_in_air_action(void) {
    if (gMarioStates[0].action & ACT_FLAG_AIR) {
        return TRUE;
    } else {
        return FALSE;
    }
}

s32 mario_is_dive_sliding(void) {
    if (gMarioStates[0].action == ACT_DIVE_SLIDE) {
        return TRUE;
    } else {
        return FALSE;
    }
}

void cur_obj_set_y_vel_and_animation(f32 yVel, s32 animIndex) {
    o->oVelY = yVel;
    cur_obj_init_animation_with_sound(animIndex);
}

void cur_obj_unrender_set_action_and_anim(s32 animIndex, s32 action) {
    cur_obj_become_intangible();
    cur_obj_disable_rendering();
    
    // only set animation if non-negative value
    if (animIndex >= 0) {
        cur_obj_init_animation_with_sound(animIndex);
    }

    o->oAction = action;
}

static void cur_obj_move_after_thrown_or_dropped(f32 forwardVel, f32 velY) {
    o->oMoveFlags = 0;
    o->oFloorHeight = find_floor_height(o->oPosX, o->oPosY + 160.0f, o->oPosZ);

    if (o->oFloorHeight > o->oPosY) {
        o->oPosY = o->oFloorHeight;
    } else if (o->oFloorHeight < FLOOR_LOWER_LIMIT_MISC) {
        //! OoB failsafe
        obj_copy_pos(o, gMarioObject);
        o->oFloorHeight = find_floor_height(o->oPosX, o->oPosY, o->oPosZ);
    }

    o->oForwardVel = forwardVel;
    o->oVelY = velY;

    if (o->oForwardVel != 0) {
        cur_obj_move_y(/*gravity*/ -4.0f, /*bounciness*/ -0.1f, /*buoyancy*/ 2.0f);
    }
}

void cur_obj_get_thrown_or_placed(f32 forwardVel, f32 velY, s32 thrownAction) {
    if (o->behavior == segmented_to_virtual(bhvBowser)) {
        // Interestingly, when bowser is thrown, he is offset slightly to
        // Mario's right
        cur_obj_set_pos_relative_to_parent(-41.684f, 85.859f, 321.577f);
    } else {
    }

    cur_obj_become_tangible();
    cur_obj_enable_rendering();

    o->oHeldState = HELD_FREE;

    if ((o->oInteractionSubtype & INT_SUBTYPE_HOLDABLE_NPC) || forwardVel == 0.0f) {
        cur_obj_move_after_thrown_or_dropped(0.0f, 0.0f);
    } else {
        o->oAction = thrownAction;
        cur_obj_move_after_thrown_or_dropped(forwardVel, velY);
    }
}

void cur_obj_get_dropped(void) {
    cur_obj_become_tangible();
    cur_obj_enable_rendering();

    o->oHeldState = HELD_FREE;
    cur_obj_move_after_thrown_or_dropped(0.0f, 0.0f);
}

void cur_obj_set_model(s32 modelID) {
    o->header.gfx.sharedChild = gLoadedGraphNodes[modelID];
}

void mario_set_flag(s32 flag) {
    gMarioStates[0].flags |= flag;
}

s32 cur_obj_clear_interact_status_flag(s32 flag) {
    if (o->oInteractStatus & flag) {
        o->oInteractStatus &= flag ^ 0xFFFFFFFF;
        return TRUE;
    }
    return FALSE;
}

/**
 * Mark an object to be unloaded at the end of the frame.
 */
void obj_mark_for_deletion(struct Object *obj) {
    //! This clears all activeFlags. Since some of these flags disable behavior,
    //  setting it to 0 could potentially enable unexpected behavior. After an
    //  object is marked for deletion, it still updates on that frame (I think),
    //  so this is worth looking into.
    obj->activeFlags = ACTIVE_FLAG_DEACTIVATED;
}

void cur_obj_disable(void) {
    cur_obj_disable_rendering();
    cur_obj_hide();
    cur_obj_become_intangible();
}

void cur_obj_enable(void) {
    cur_obj_enable_rendering();
    cur_obj_unhide();
    cur_obj_become_tangible();
}

void cur_obj_become_intangible(void) {
    // When the timer is negative, the object is intangible and the timer
    // doesn't count down
    o->oIntangibleTimer = -1;
}

void cur_obj_become_tangible(void) {
    o->oIntangibleTimer = 0;
}

void obj_become_tangible(struct Object *obj) {
    obj->oIntangibleTimer = 0;
}

void cur_obj_update_floor_height(void) {
    struct Surface *floor;
    o->oFloorHeight = find_floor(o->oPosX, o->oPosY, o->oPosZ, &floor);
}

struct Surface *cur_obj_update_floor_height_and_get_floor(void) {
    struct Surface *floor;
    o->oFloorHeight = find_floor(o->oPosX, o->oPosY, o->oPosZ, &floor);
    return floor;
}

static void apply_drag_to_value(f32 *value, f32 dragStrength) {
    f32 decel;

    if (*value != 0) {
        //! Can overshoot if |*value| > 1/(dragStrength * 0.0001)
        decel = (*value) * (*value) * (dragStrength * 0.0001L);

        if (*value > 0) {
            *value -= decel;
            if (*value < 0.001L) {
                *value = 0;
            }
        } else {
            *value += decel;
            if (*value > -0.001L) {
                *value = 0;
            }
        }
    }
}

void cur_obj_apply_drag_xz(f32 dragStrength) {
    apply_drag_to_value(&o->oVelX, dragStrength);
    apply_drag_to_value(&o->oVelZ, dragStrength);
}

static s32 cur_obj_move_xz(f32 steepSlopeNormalY, s32 careAboutEdgesAndSteepSlopes) {
    struct Surface *intendedFloor;

    f32 intendedX = o->oPosX + o->oVelX;
    f32 intendedZ = o->oPosZ + o->oVelZ;

    f32 intendedFloorHeight = find_floor(intendedX, o->oPosY, intendedZ, &intendedFloor);
    f32 deltaFloorHeight = intendedFloorHeight - o->oFloorHeight;

    UNUSED u8 filler[4];
    UNUSED f32 ny;

    o->oMoveFlags &= ~OBJ_MOVE_HIT_EDGE;

    if (o->oRoom != -1 && intendedFloor != NULL) {
        if (intendedFloor->room != 0 && o->oRoom != intendedFloor->room && intendedFloor->room != 18) {
            // Don't leave native room
            return FALSE;
        }
    }

    if (intendedFloorHeight < FLOOR_LOWER_LIMIT_MISC) {
        // Don't move into OoB
        o->oMoveFlags |= OBJ_MOVE_HIT_EDGE;
        return FALSE;
    } else if (deltaFloorHeight < 5.0f) {
        if (!careAboutEdgesAndSteepSlopes) {
            // If we don't care about edges or steep slopes, okay to move
            o->oPosX = intendedX;
            o->oPosZ = intendedZ;
            return TRUE;
        } else if (deltaFloorHeight < -50.0f && (o->oMoveFlags & OBJ_MOVE_ON_GROUND)) {
            // Don't walk off an edge
            o->oMoveFlags |= OBJ_MOVE_HIT_EDGE;
            return FALSE;
        } else if (intendedFloor->normal.y > steepSlopeNormalY) {
            // Allow movement onto a slope, provided it's not too steep
            o->oPosX = intendedX;
            o->oPosZ = intendedZ;
            return TRUE;
        } else {
            // We are likely trying to move onto a steep downward slope
            o->oMoveFlags |= OBJ_MOVE_HIT_EDGE;
            return FALSE;
        }
    } else if ((ny = intendedFloor->normal.y) > steepSlopeNormalY || o->oPosY > intendedFloorHeight) {
        // Allow movement upward, provided either:
        // - The target floor is flat enough (e.g. walking up stairs)
        // - We are above the target floor (most likely in the air)
        o->oPosX = intendedX;
        o->oPosZ = intendedZ;
        //! Returning FALSE but moving anyway (not exploitable; return value is
        //  never used)
    }

    // We are likely trying to move onto a steep upward slope
    return FALSE;
}

static void cur_obj_move_update_underwater_flags(void) {
    f32 decelY = (f32)(sqrtf(o->oVelY * o->oVelY) * (o->oDragStrength * 7.0f)) / 100.0L;

    if (o->oVelY > 0) {
        o->oVelY -= decelY;
    } else {
        o->oVelY += decelY;
    }

    if (o->oPosY < o->oFloorHeight) {
        o->oPosY = o->oFloorHeight;
        o->oMoveFlags |= OBJ_MOVE_UNDERWATER_ON_GROUND;
    } else {
        o->oMoveFlags |= OBJ_MOVE_UNDERWATER_OFF_GROUND;
    }
}

static void cur_obj_move_update_ground_air_flags(UNUSED f32 gravity, f32 bounciness) {
    o->oMoveFlags &= ~OBJ_MOVE_BOUNCE;

    if (o->oPosY < o->oFloorHeight) {
        // On the first frame that we touch the ground, set OBJ_MOVE_LANDED.
        // On subsequent frames, set OBJ_MOVE_ON_GROUND
        if (!(o->oMoveFlags & OBJ_MOVE_ON_GROUND)) {
            if (clear_move_flag(&o->oMoveFlags, OBJ_MOVE_LANDED)) {
                o->oMoveFlags |= OBJ_MOVE_ON_GROUND;
            } else {
                o->oMoveFlags |= OBJ_MOVE_LANDED;
            }
        }

        o->oPosY = o->oFloorHeight;

        if (o->oVelY < 0.0f) {
            o->oVelY *= bounciness;
        }

        if (o->oVelY > 5.0f) {
            //! This overestimates since velY could be > 5 here
            //! without bounce (e.g. jump into misa).
            o->oMoveFlags |= OBJ_MOVE_BOUNCE;
        }
    } else {
        o->oMoveFlags &= ~OBJ_MOVE_LANDED;
        if (clear_move_flag(&o->oMoveFlags, OBJ_MOVE_ON_GROUND)) {
            o->oMoveFlags |= OBJ_MOVE_LEFT_GROUND;
        }
    }

    o->oMoveFlags &= ~OBJ_MOVE_MASK_IN_WATER;
}

static f32 cur_obj_move_y_and_get_water_level(f32 gravity, f32 buoyancy) {
    f32 waterLevel;

    o->oVelY += gravity + buoyancy;
    if (o->oVelY < -78.0f) {
        o->oVelY = -78.0f;
    }

    o->oPosY += o->oVelY;
    if (o->activeFlags & ACTIVE_FLAG_UNK10) {
        waterLevel = FLOOR_LOWER_LIMIT;
    } else {
        waterLevel = find_water_level(o->oPosX, o->oPosZ);
    }

    return waterLevel;
}

void cur_obj_move_y(f32 gravity, f32 bounciness, f32 buoyancy) {
    f32 waterLevel;

    o->oMoveFlags &= ~OBJ_MOVE_LEFT_GROUND;

    if (o->oMoveFlags & OBJ_MOVE_AT_WATER_SURFACE) {
        if (o->oVelY > 5.0f) {
            o->oMoveFlags &= ~OBJ_MOVE_MASK_IN_WATER;
            o->oMoveFlags |= OBJ_MOVE_LEAVING_WATER;
        }
    }

    if (!(o->oMoveFlags & OBJ_MOVE_MASK_IN_WATER)) {
        waterLevel = cur_obj_move_y_and_get_water_level(gravity, 0.0f);
        if (o->oPosY > waterLevel) {
            //! We only handle floor collision if the object does not enter
            //  water. This allows e.g. coins to clip through floors if they
            //  enter water on the same frame.
            cur_obj_move_update_ground_air_flags(gravity, bounciness);
        } else {
            o->oMoveFlags |= OBJ_MOVE_ENTERED_WATER;
            o->oMoveFlags &= ~OBJ_MOVE_MASK_ON_GROUND;
        }
    } else {
        o->oMoveFlags &= ~OBJ_MOVE_ENTERED_WATER;

        waterLevel = cur_obj_move_y_and_get_water_level(gravity, buoyancy);
        if (o->oPosY < waterLevel) {
            cur_obj_move_update_underwater_flags();
        } else {
            if (o->oPosY < o->oFloorHeight) {
                o->oPosY = o->oFloorHeight;
                o->oMoveFlags &= ~OBJ_MOVE_MASK_IN_WATER;
            } else {
                o->oPosY = waterLevel;
                o->oVelY = 0.0f;
                o->oMoveFlags &= ~(OBJ_MOVE_UNDERWATER_OFF_GROUND | OBJ_MOVE_UNDERWATER_ON_GROUND);
                o->oMoveFlags |= OBJ_MOVE_AT_WATER_SURFACE;
            }
        }
    }

    if (o->oMoveFlags & (OBJ_MOVE_MASK_ON_GROUND | OBJ_MOVE_AT_WATER_SURFACE
        | OBJ_MOVE_UNDERWATER_OFF_GROUND)) {
        o->oMoveFlags &= ~OBJ_MOVE_IN_AIR;
    } else {
        o->oMoveFlags |= OBJ_MOVE_IN_AIR;
    }
}

UNUSED static void stub_obj_helpers_1(void) {
}

static s32 clear_move_flag(u32 *bitSet, s32 flag) {
    if (*bitSet & flag) {
        *bitSet &= flag ^ 0xFFFFFFFF;
        return TRUE;
    } else {
        return FALSE;
    }
}

void cur_obj_unused_resolve_wall_collisions(f32 offsetY, f32 radius) {
    if (radius > 0.1L) {
        f32_find_wall_collision(&o->oPosX, &o->oPosY, &o->oPosZ, offsetY, radius);
    }
}

s16 abs_angle_diff(s16 x0, s16 x1) {
    s16 diff = x1 - x0;

    if (diff == -0x8000) {
        diff = -0x7FFF;
    }

    if (diff < 0) {
        diff = -diff;
    }

    return diff;
}

void cur_obj_move_xz_using_fvel_and_yaw(void) {
    o->oVelX = o->oForwardVel * sins(o->oMoveAngleYaw);
    o->oVelZ = o->oForwardVel * coss(o->oMoveAngleYaw);

    o->oPosX += o->oVelX;
    o->oPosZ += o->oVelZ;
}

void cur_obj_move_y_with_terminal_vel(void) {
    if (o->oVelY < -70.0f) {
        o->oVelY = -70.0f;
    }

    o->oPosY += o->oVelY;
}

void cur_obj_compute_vel_xz(void) {
    o->oVelX = o->oForwardVel * sins(o->oMoveAngleYaw);
    o->oVelZ = o->oForwardVel * coss(o->oMoveAngleYaw);
}

void cur_obj_compute_vel_xyz(void) {
    o->oVelX = o->oForwardVel * sins(o->oMoveAngleYaw) * coss(o->oMoveAnglePitch);
    o->oVelZ = o->oForwardVel * coss(o->oMoveAngleYaw) * coss(o->oMoveAnglePitch);
    o->oVelY = o->oForwardVel * sins(o->oMoveAnglePitch);
}

f32 increment_velocity_toward_range(f32 value, f32 center, f32 zeroThreshold, f32 increment) {
    f32 relative;
    if ((relative = value - center) > 0) {
        if (relative < zeroThreshold) {
            return 0.0f;
        } else {
            return -increment;
        }
    } else {
        if (relative > -zeroThreshold) {
            return 0.0f;
        } else {
            return increment;
        }
    }
}

s32 obj_check_if_collided_with_object(struct Object *obj1, struct Object *obj2) {
    s32 i;
    for (i = 0; i < obj1->numCollidedObjs; i++) {
        if (obj1->collidedObjs[i] == obj2) {
            return TRUE;
        }
    }

    return FALSE;
}

void cur_obj_set_behavior(const BehaviorScript *behavior) {
    o->behavior = segmented_to_virtual(behavior);
}

void obj_set_behavior(struct Object *obj, const BehaviorScript *behavior) {
    obj->behavior = segmented_to_virtual(behavior);
}

s32 cur_obj_has_behavior(const BehaviorScript *behavior) {
    if (o->behavior == segmented_to_virtual(behavior)) {
        return TRUE;
    } else {
        return FALSE;
    }
}

s32 obj_has_behavior(struct Object *obj, const BehaviorScript *behavior) {
    if (obj->behavior == segmented_to_virtual(behavior)) {
        return TRUE;
    } else {
        return FALSE;
    }
}

f32 cur_obj_lateral_dist_from_mario_to_home(void) {
    f32 dist;
    f32 dx = o->oHomeX - gMarioObject->oPosX;
    f32 dz = o->oHomeZ - gMarioObject->oPosZ;

    dist = sqrtf(dx * dx + dz * dz);
    return dist;
}

f32 cur_obj_lateral_dist_to_home(void) {
    f32 dist;
    f32 dx = o->oHomeX - o->oPosX;
    f32 dz = o->oHomeZ - o->oPosZ;

    dist = sqrtf(dx * dx + dz * dz);
    return dist;
}

f32 cur_obj_dist_to_home(void) {
    f32 dist;
    f32 dx = o->oHomeX - o->oPosX;
    f32 dy = o->oHomeY - o->oPosY;
    f32 dz = o->oHomeZ - o->oPosZ;

    dist = sqrtf(dx * dx + dy * dy + dz * dz);
    return dist;
}

s32 cur_obj_outside_home_square(f32 halfLength) {
    if (o->oHomeX - halfLength > o->oPosX) {
        return TRUE;
    }

    if (o->oHomeX + halfLength < o->oPosX) {
        return TRUE;
    }

    if (o->oHomeZ - halfLength > o->oPosZ) {
        return TRUE;
    }

    if (o->oHomeZ + halfLength < o->oPosZ) {
        return TRUE;
    }

    return FALSE;
}

s32 cur_obj_outside_home_rectangle(f32 minX, f32 maxX, f32 minZ, f32 maxZ) {
    if (o->oHomeX + minX > o->oPosX) {
        return TRUE;
    }

    if (o->oHomeX + maxX < o->oPosX) {
        return TRUE;
    }

    if (o->oHomeZ + minZ > o->oPosZ) {
        return TRUE;
    }

    if (o->oHomeZ + maxZ < o->oPosZ) {
        return TRUE;
    }

    return FALSE;
}

void cur_obj_set_pos_to_home(void) {
    o->oPosX = o->oHomeX;
    o->oPosY = o->oHomeY;
    o->oPosZ = o->oHomeZ;
}

void cur_obj_set_pos_to_home_and_stop(void) {
    cur_obj_set_pos_to_home();

    o->oForwardVel = 0;
    o->oVelY = 0;
}

void cur_obj_shake_y(f32 amount) {
    //! Technically could cause a bit of drift, but not much
    if (o->oTimer % 2 == 0) {
        o->oPosY += amount;
    } else {
        o->oPosY -= amount;
    }
}

void cur_obj_start_cam_event(UNUSED struct Object *obj, s32 cameraEvent) {
    gPlayerCameraState->cameraEvent = (s16) cameraEvent;
    gSecondCameraFocus = o;
}

// unused, self explanatory, maybe oInteractStatus originally had TRUE/FALSE statements
void set_mario_interact_true_if_in_range(UNUSED s32 arg0, UNUSED s32 arg1, f32 range) {
    if (o->oDistanceToMario < range) {
        gMarioObject->oInteractStatus = TRUE;
    }
}

void obj_set_billboard(struct Object *obj) {
    obj->header.gfx.node.flags |= GRAPH_RENDER_BILLBOARD;
}

void cur_obj_set_hitbox_radius_and_height(f32 radius, f32 height) {
    o->hitboxRadius = radius;
    o->hitboxHeight = height;
}

void cur_obj_set_hurtbox_radius_and_height(f32 radius, f32 height) {
    o->hurtboxRadius = radius;
    o->hurtboxHeight = height;
}

void obj_spawn_loot_coins(struct Object *obj, s32 numCoins, f32 sp30,
                                    const BehaviorScript *coinBehavior,
                                    s16 posJitter, s16 model) {
    s32 i;
    f32 spawnHeight;
    struct Surface *floor;
    struct Object *coin;

    if (obj_has_behavior(obj, bhvRedCoinGoomba)) {
        coinBehavior = bhvPhysicsRedCoin;
        model = MODEL_RED_COIN;
    } else if (!(gHudDisplay.flags & HUD_DISPLAY_FLAG_BOO) && !(obj_has_behavior(obj, bhvShyguyBookSteal)) &&
        !(gCurrLevelNum == LEVEL_LLL && gMarioCurrentRoom == 9)) {
        coinBehavior = bhvCollectHeart;
        model = MODEL_HEART;
    }

    spawnHeight = find_floor(obj->oPosX, obj->oPosY, obj->oPosZ, &floor);
    if (obj->oPosY - spawnHeight > 100.0f) {
        spawnHeight = obj->oPosY;
    }

    for (i = 0; i < numCoins; i++) {
        if (obj->oNumLootCoins <= 0) {
            break;
        }

        obj->oNumLootCoins--;

        coin = spawn_object(obj, model, coinBehavior);
        obj_translate_xz_random(coin, posJitter);
        coin->oPosY = spawnHeight;
        coin->oCoinUnk110 = sp30;
        if (coinBehavior == bhvPhysicsRedCoin) {
            coin->oVelY = 55.0f;
            coin->oForwardVel = 10.0f;
            coin->oMoveAngleYaw = random_u16();
            coin->oBehParams2ndByte = 3;
        }
    }
}




void obj_force_spawn_loot_coins(struct Object *obj, s32 numCoins, f32 sp30,
                                    const BehaviorScript *coinBehavior,
                                    s16 posJitter, s16 model) {
    s32 i;
    f32 spawnHeight;
    struct Surface *floor;
    struct Object *coin;

    spawnHeight = find_floor(obj->oPosX, obj->oPosY, obj->oPosZ, &floor);
    if (obj->oPosY - spawnHeight > 100.0f) {
        spawnHeight = obj->oPosY;
    }

    for (i = 0; i < numCoins; i++) {
        // if (obj->oNumLootCoins <= 0) {
        //     break;
        // }

        // obj->oNumLootCoins--;

        coin = spawn_object(obj, model, coinBehavior);
        obj_translate_xz_random(coin, posJitter);
        coin->oPosY = spawnHeight;
        coin->oCoinUnk110 = sp30;
    }
}








void obj_spawn_loot_blue_coins(struct Object *obj, s32 numCoins, f32 sp28, s16 posJitter) {
    obj_spawn_loot_coins(obj, numCoins, sp28, bhvBlueCoinJumping, posJitter, MODEL_BLUE_COIN);
}

void obj_spawn_loot_yellow_coins(struct Object *obj, s32 numCoins, f32 sp28) {
    obj_spawn_loot_coins(obj, numCoins, sp28, bhvSingleCoinGetsSpawned, 0, MODEL_YELLOW_COIN);
}

void cur_obj_spawn_loot_coin_at_mario_pos(void) {
    struct Object *coin;
    if (o->oNumLootCoins <= 0) {
        return;
    }

    o->oNumLootCoins--;

    coin = spawn_object(o, MODEL_YELLOW_COIN, bhvSingleCoinGetsSpawned);
    coin->oVelY = 30.0f;

    obj_copy_pos(coin, gMarioObject);
}

f32 cur_obj_abs_y_dist_to_home(void) {
    f32 dist = o->oHomeY - o->oPosY;

    if (dist < 0) {
        dist = -dist;
    }

    return dist;
}

s32 cur_obj_advance_looping_anim(void) {
    s32 animFrame = o->header.gfx.animInfo.animFrame;
    s32 loopEnd = o->header.gfx.animInfo.curAnim->loopEnd;
    s32 result;

    if (animFrame < 0) {
        animFrame = 0;
    } else if (loopEnd - 1 == animFrame) {
        animFrame = 0;
    } else {
        animFrame++;
    }

    result = (animFrame << 16) / loopEnd;

    return result;
}

static s32 cur_obj_detect_steep_floor(s16 steepAngleDegrees) {
    struct Surface *intendedFloor;
    f32 intendedX, intendedFloorHeight, intendedZ;
    f32 deltaFloorHeight;
    f32 steepNormalY = coss((s16)(steepAngleDegrees * (0x10000 / 360)));

    if (o->oForwardVel != 0.0f) {
        intendedX = o->oPosX + o->oVelX;
        intendedZ = o->oPosZ + o->oVelZ;
        intendedFloorHeight = find_floor(intendedX, o->oPosY, intendedZ, &intendedFloor);
        deltaFloorHeight = intendedFloorHeight - o->oFloorHeight;

        if (intendedFloorHeight < FLOOR_LOWER_LIMIT_MISC) {
            o->oWallAngle = o->oMoveAngleYaw + 0x8000;
            return 2;
        } else if (intendedFloor->normal.y < steepNormalY && deltaFloorHeight > 0
                   && intendedFloorHeight > o->oPosY) {
            o->oWallAngle = atan2s(intendedFloor->normal.z, intendedFloor->normal.x);
            return 1;
        } else {
            return 0;
        }
    }

    return 0;
}

s32 cur_obj_resolve_wall_collisions(void) {
    s32 numCollisions;
    struct Surface *wall;
    struct WallCollisionData collisionData;

    f32 offsetY = 10.0f;
    f32 radius = o->oWallHitboxRadius;

    if (radius > 0.1L) {
        collisionData.offsetY = offsetY;
        collisionData.radius = radius;
        collisionData.x = (s16) o->oPosX;
        collisionData.y = (s16) o->oPosY;
        collisionData.z = (s16) o->oPosZ;

        numCollisions = find_wall_collisions(&collisionData);
        if (numCollisions != 0) {
            o->oPosX = collisionData.x;
            o->oPosY = collisionData.y;
            o->oPosZ = collisionData.z;
            wall = collisionData.walls[collisionData.numWalls - 1];

            o->oWallAngle = atan2s(wall->normal.z, wall->normal.x);
            if (abs_angle_diff(o->oWallAngle, o->oMoveAngleYaw) > 0x4000) {
                return TRUE;
            } else {
                return FALSE;
            }
        }
    }

    return FALSE;
}

void cur_obj_update_floor(void) {
    struct Surface *floor = cur_obj_update_floor_height_and_get_floor();
    o->oFloor = floor;

    if (floor != NULL) {
        if (floor->type == SURFACE_BURNING) {
            o->oMoveFlags |= OBJ_MOVE_ABOVE_LAVA;
        }
#ifndef VERSION_JP
        else if (floor->type == SURFACE_DEATH_PLANE || floor->type == SURFACE_INSTANT_QUICKSAND) {
            //! This misses SURFACE_VERTICAL_WIND (and maybe SURFACE_WARP)
            o->oMoveFlags |= OBJ_MOVE_ABOVE_DEATH_BARRIER;
        }
#endif

        o->oFloorType = floor->type;
        o->oFloorRoom = floor->room;
    } else {
        o->oFloorType = 0;
        o->oFloorRoom = 0;
    }
}

static void cur_obj_update_floor_and_resolve_wall_collisions(s16 steepSlopeDegrees) {
#ifdef VERSION_JP
    o->oMoveFlags &= ~OBJ_MOVE_ABOVE_LAVA;
#else
    o->oMoveFlags &= ~(OBJ_MOVE_ABOVE_LAVA | OBJ_MOVE_ABOVE_DEATH_BARRIER);
#endif

    if (o->activeFlags & (ACTIVE_FLAG_FAR_AWAY | ACTIVE_FLAG_IN_DIFFERENT_ROOM)) {
        cur_obj_update_floor();
        o->oMoveFlags &= ~(OBJ_MOVE_HIT_WALL | OBJ_MOVE_MASK_IN_WATER);

        if (o->oPosY > o->oFloorHeight) {
            o->oMoveFlags |= OBJ_MOVE_IN_AIR;
        }
    } else {
        o->oMoveFlags &= ~OBJ_MOVE_HIT_WALL;
        if (cur_obj_resolve_wall_collisions()) {
            o->oMoveFlags |= OBJ_MOVE_HIT_WALL;
        }

        cur_obj_update_floor();

        if (o->oPosY > o->oFloorHeight) {
            o->oMoveFlags |= OBJ_MOVE_IN_AIR;
        }

        if (cur_obj_detect_steep_floor(steepSlopeDegrees)) {
            o->oMoveFlags |= OBJ_MOVE_HIT_WALL;
        }
    }
}

void cur_obj_update_floor_and_walls(void) {
    cur_obj_update_floor_and_resolve_wall_collisions(60);
}

void cur_obj_move_standard(s16 steepSlopeAngleDegrees) {
    f32 gravity = o->oGravity;
    f32 bounciness = o->oBounciness;
    f32 buoyancy = o->oBuoyancy;
    f32 dragStrength = o->oDragStrength;
    f32 steepSlopeNormalY;
    s32 careAboutEdgesAndSteepSlopes = FALSE;
    s32 negativeSpeed = FALSE;

    //! Because some objects allow these active flags to be set but don't
    //  avoid updating when they are, we end up with "partial" updates, where
    //  an object's internal state will be updated, but it doesn't move.
    //  This allows numerous glitches and is typically referred to as
    //  deactivation (though this term has a different meaning in the code).
    //  Objects that do this will be marked with //PARTIAL_UPDATE.
    if (!(o->activeFlags & (ACTIVE_FLAG_FAR_AWAY | ACTIVE_FLAG_IN_DIFFERENT_ROOM))) {
        if (steepSlopeAngleDegrees < 0) {
            // clang-format off
            careAboutEdgesAndSteepSlopes = TRUE; steepSlopeAngleDegrees = -steepSlopeAngleDegrees;
            // clang-format on
        }

        steepSlopeNormalY = coss(steepSlopeAngleDegrees * (0x10000 / 360));

        cur_obj_compute_vel_xz();
        cur_obj_apply_drag_xz(dragStrength);

        cur_obj_move_xz(steepSlopeNormalY, careAboutEdgesAndSteepSlopes);
        cur_obj_move_y(gravity, bounciness, buoyancy);

        if (o->oForwardVel < 0.0f) {
            negativeSpeed = TRUE;
        }
        o->oForwardVel = sqrtf(sqr(o->oVelX) + sqr(o->oVelZ));
        if (negativeSpeed == TRUE) {
            o->oForwardVel = -o->oForwardVel;
        }
    }
}

static s32 cur_obj_within_12k_bounds(void) {
    if (o->oPosX < -12000.0f || 12000.0f < o->oPosX) {
        return FALSE;
    }

    if (o->oPosY < -12000.0f || 12000.0f < o->oPosY) {
        return FALSE;
    }

    if (o->oPosZ < -12000.0f || 12000.0f < o->oPosZ) {
        return FALSE;
    }

    return TRUE;
}

void cur_obj_move_using_vel_and_gravity(void) {
        o->oPosX += o->oVelX;
        o->oPosZ += o->oVelZ;
        o->oVelY += o->oGravity; //! No terminal velocity
        o->oPosY += o->oVelY;
}

void cur_obj_move_using_fvel_and_gravity(void) {
    cur_obj_compute_vel_xz();
    cur_obj_move_using_vel_and_gravity(); //! No terminal velocity
}

void obj_set_pos_relative(struct Object *obj, struct Object *other, f32 dleft, f32 dy,
                             f32 dforward) {
    f32 facingZ = coss(other->oMoveAngleYaw);
    f32 facingX = sins(other->oMoveAngleYaw);

    f32 dz = dforward * facingZ - dleft * facingX;
    f32 dx = dforward * facingX + dleft * facingZ;

    obj->oMoveAngleYaw = other->oMoveAngleYaw;

    obj->oPosX = other->oPosX + dx;
    obj->oPosY = other->oPosY + dy;
    obj->oPosZ = other->oPosZ + dz;
}

s16 cur_obj_angle_to_home(void) {
    s16 angle;
    f32 dx = o->oHomeX - o->oPosX;
    f32 dz = o->oHomeZ - o->oPosZ;

    angle = atan2s(dz, dx);
    return angle;
}

void obj_set_gfx_pos_at_obj_pos(struct Object *obj1, struct Object *obj2) {
    obj1->header.gfx.pos[0] = obj2->oPosX;
    obj1->header.gfx.pos[1] = obj2->oPosY + obj2->oGraphYOffset;
    obj1->header.gfx.pos[2] = obj2->oPosZ;

    obj1->header.gfx.angle[0] = obj2->oMoveAnglePitch & 0xFFFF;
    obj1->header.gfx.angle[1] = obj2->oMoveAngleYaw & 0xFFFF;
    obj1->header.gfx.angle[2] = obj2->oMoveAngleRoll & 0xFFFF;
}

/**
 * Transform the vector at localTranslateIndex into the object's local
 * coordinates, and then add it to the vector at posIndex.
 */
void obj_translate_local(struct Object *obj, s16 posIndex, s16 localTranslateIndex) {
    f32 dx = obj->rawData.asF32[localTranslateIndex + 0];
    f32 dy = obj->rawData.asF32[localTranslateIndex + 1];
    f32 dz = obj->rawData.asF32[localTranslateIndex + 2];

    obj->rawData.asF32[posIndex + 0] +=
        obj->transform[0][0] * dx + obj->transform[1][0] * dy + obj->transform[2][0] * dz;
    obj->rawData.asF32[posIndex + 1] +=
        obj->transform[0][1] * dx + obj->transform[1][1] * dy + obj->transform[2][1] * dz;
    obj->rawData.asF32[posIndex + 2] +=
        obj->transform[0][2] * dx + obj->transform[1][2] * dy + obj->transform[2][2] * dz;
}

void obj_build_transform_from_pos_and_angle(struct Object *obj, s16 posIndex, s16 angleIndex) {
    f32 translate[3];
    s16 rotation[3];

    translate[0] = obj->rawData.asF32[posIndex + 0];
    translate[1] = obj->rawData.asF32[posIndex + 1];
    translate[2] = obj->rawData.asF32[posIndex + 2];

    rotation[0] = obj->rawData.asS32[angleIndex + 0];
    rotation[1] = obj->rawData.asS32[angleIndex + 1];
    rotation[2] = obj->rawData.asS32[angleIndex + 2];

    mtxf_rotate_zxy_and_translate(obj->transform, translate, rotation);
}

void obj_set_throw_matrix_from_transform(struct Object *obj) {
    if (obj->oFlags & OBJ_FLAG_0020) {
        obj_build_transform_from_pos_and_angle(obj, O_POS_INDEX, O_FACE_ANGLE_INDEX);
        obj_apply_scale_to_transform(obj);
    }

    obj->header.gfx.throwMatrix = &obj->transform;

    //! Sets scale of gCurrentObject instead of obj. Not exploitable since this
    //  function is only called with obj = gCurrentObject
    cur_obj_scale(1.0f);
}

void obj_build_transform_relative_to_parent(struct Object *obj) {
    struct Object *parent = obj->parentObj;

    obj_build_transform_from_pos_and_angle(obj, O_PARENT_RELATIVE_POS_INDEX, O_FACE_ANGLE_INDEX);
    obj_apply_scale_to_transform(obj);
    mtxf_mul(obj->transform, obj->transform, parent->transform);

    obj->oPosX = obj->transform[3][0];
    obj->oPosY = obj->transform[3][1];
    obj->oPosZ = obj->transform[3][2];

    obj->header.gfx.throwMatrix = &obj->transform;

    //! Sets scale of gCurrentObject instead of obj. Not exploitable since this
    //  function is only called with obj = gCurrentObject
    cur_obj_scale(1.0f);
}



void cur_obj_set_throw_matrix_from_transform(void) {
    if (o->oFlags & OBJ_FLAG_0020) {
        obj_build_transform_from_pos_and_angle(o, O_POS_INDEX, O_FACE_ANGLE_INDEX);
        obj_apply_scale_to_transform(o);
    }

    o->header.gfx.throwMatrix = &o->transform;

    cur_obj_scale(1.0f);
}

void cur_obj_build_transform_relative_to_parent(void) {
    struct Object *parent = o->parentObj;

    obj_build_transform_from_pos_and_angle(o, O_PARENT_RELATIVE_POS_INDEX, O_FACE_ANGLE_INDEX);
    obj_apply_scale_to_transform(o);
    mtxf_mul(o->transform, o->transform, parent->transform);

    o->oPosX = o->transform[3][0];
    o->oPosY = o->transform[3][1];
    o->oPosZ = o->transform[3][2];

    o->header.gfx.throwMatrix = &o->transform;

    cur_obj_scale(1.0f);
}

void obj_create_transform_from_self(struct Object *obj) {
    obj->oFlags &= ~OBJ_FLAG_TRANSFORM_RELATIVE_TO_PARENT;
    obj->oFlags |= OBJ_FLAG_SET_THROW_MATRIX_FROM_TRANSFORM;

    obj->transform[3][0] = obj->oPosX;
    obj->transform[3][1] = obj->oPosY;
    obj->transform[3][2] = obj->oPosZ;
}

void cur_obj_rotate_move_angle_using_vel(void) {
    o->oMoveAnglePitch += o->oAngleVelPitch;
    o->oMoveAngleYaw += o->oAngleVelYaw;
    o->oMoveAngleRoll += o->oAngleVelRoll;
}

void cur_obj_rotate_face_angle_using_vel(void) {
    o->oFaceAnglePitch += o->oAngleVelPitch;
    o->oFaceAngleYaw += o->oAngleVelYaw;
    o->oFaceAngleRoll += o->oAngleVelRoll;
}

void cur_obj_set_face_angle_to_move_angle(void) {
    o->oFaceAnglePitch = o->oMoveAnglePitch;
    o->oFaceAngleYaw = o->oMoveAngleYaw;
    o->oFaceAngleRoll = o->oMoveAngleRoll;
}

s32 cur_obj_follow_path(UNUSED s32 unusedArg) {
    struct Waypoint *startWaypoint;
    struct Waypoint *lastWaypoint;
    struct Waypoint *targetWaypoint;
    f32 prevToNextX, prevToNextY, prevToNextZ;
    UNUSED u8 filler[4];
    f32 objToNextXZ;
    f32 objToNextX, objToNextY, objToNextZ;

    if (o->oPathedPrevWaypointFlags == 0) {
        o->oPathedPrevWaypoint = o->oPathedStartWaypoint;
        o->oPathedPrevWaypointFlags = WAYPOINT_FLAGS_INITIALIZED;
    }

    startWaypoint = o->oPathedStartWaypoint;
    lastWaypoint = o->oPathedPrevWaypoint;

    if ((lastWaypoint + 1)->flags != WAYPOINT_FLAGS_END) {
        targetWaypoint = lastWaypoint + 1;
    } else {
        targetWaypoint = startWaypoint;
    }

    o->oPathedPrevWaypointFlags = lastWaypoint->flags | WAYPOINT_FLAGS_INITIALIZED;

    prevToNextX = targetWaypoint->pos[0] - lastWaypoint->pos[0];
    prevToNextY = targetWaypoint->pos[1] - lastWaypoint->pos[1];
    prevToNextZ = targetWaypoint->pos[2] - lastWaypoint->pos[2];

    objToNextX = targetWaypoint->pos[0] - o->oPosX;
    objToNextY = targetWaypoint->pos[1] - o->oPosY;
    objToNextZ = targetWaypoint->pos[2] - o->oPosZ;
    objToNextXZ = sqrtf(sqr(objToNextX) + sqr(objToNextZ));

    o->oPathedTargetYaw = atan2s(objToNextZ, objToNextX);
    o->oPathedTargetPitch = atan2s(objToNextXZ, -objToNextY);

    // If dot(prevToNext, objToNext) <= 0 (i.e. reached other side of target waypoint)
    if (prevToNextX * objToNextX + prevToNextY * objToNextY + prevToNextZ * objToNextZ <= 0.0f) {
        o->oPathedPrevWaypoint = targetWaypoint;
        if ((targetWaypoint + 1)->flags == WAYPOINT_FLAGS_END) {
            return PATH_REACHED_END;
        } else {
            return PATH_REACHED_WAYPOINT;
        }
    }

    return PATH_NONE;
}

void chain_segment_init(struct ChainSegment *segment) {
    segment->posX = 0.0f;
    segment->posY = 0.0f;
    segment->posZ = 0.0f;

    segment->pitch = 0;
    segment->yaw = 0;
    segment->roll = 0;
}

f32 random_f32_around_zero(f32 diameter) {
    return random_float() * diameter - diameter / 2;
}

void obj_scale_random(struct Object *obj, f32 rangeLength, f32 minScale) {
    f32 scale = random_float() * rangeLength + minScale;
    obj_scale_xyz(obj, scale, scale, scale);
}

void obj_translate_xyz_random(struct Object *obj, f32 rangeLength) {
    obj->oPosX += random_float() * rangeLength - rangeLength * 0.5f;
    obj->oPosY += random_float() * rangeLength - rangeLength * 0.5f;
    obj->oPosZ += random_float() * rangeLength - rangeLength * 0.5f;
}

void obj_translate_xz_random(struct Object *obj, f32 rangeLength) {
    obj->oPosX += random_float() * rangeLength - rangeLength * 0.5f;
    obj->oPosZ += random_float() * rangeLength - rangeLength * 0.5f;
}

static void obj_build_vel_from_transform(struct Object *obj) {
    f32 up = obj->oUpVel;
    f32 left = obj->oLeftVel;
    f32 forward = obj->oForwardVel;

    //! Typo, up and left should be swapped
    obj->oVelX = obj->transform[0][0] * up + obj->transform[1][0] * left + obj->transform[2][0] * forward;
    obj->oVelY = obj->transform[0][1] * up + obj->transform[1][1] * left + obj->transform[2][1] * forward;
    obj->oVelZ = obj->transform[0][2] * up + obj->transform[1][2] * left + obj->transform[2][2] * forward;
}

void cur_obj_set_pos_via_transform(void) {
    obj_build_transform_from_pos_and_angle(o, O_PARENT_RELATIVE_POS_INDEX, O_MOVE_ANGLE_INDEX);
    obj_build_vel_from_transform(o);
    o->oPosX += o->oVelX;
    o->oPosY += o->oVelY;
    o->oPosZ += o->oVelZ;
}

s16 cur_obj_reflect_move_angle_off_wall(void) {
    s16 angle = o->oWallAngle - ((s16) o->oMoveAngleYaw - (s16) o->oWallAngle) + 0x8000;
    return angle;
}

void cur_obj_spawn_particles(struct SpawnParticlesInfo *info) {
    struct Object *particle;
    s32 i;
    f32 scale;
    s32 numParticles = info->count;

    // If there are a lot of objects already, limit the number of particles
    if ((gPrevFrameObjectCount > (OBJECT_POOL_CAPACITY - 90)) && numParticles > 10) {
        numParticles = 10;
    }

    // We're close to running out of object slots, so don't spawn particles at
    // all
    if (gPrevFrameObjectCount > (OBJECT_POOL_CAPACITY - 30)) {
        numParticles = 0;
    }

    for (i = 0; i < numParticles; i++) {
        scale = random_float() * (info->sizeRange * 0.1f) + info->sizeBase * 0.1f;

        particle = spawn_object(o, info->model, bhvWhitePuffExplosion);

        particle->oBehParams2ndByte = info->behParam;
        particle->oMoveAngleYaw = random_u16();
        particle->oGravity = info->gravity;
        particle->oDragStrength = info->dragStrength;

        particle->oPosY += info->offsetY;
        particle->oForwardVel = random_float() * info->forwardVelRange + info->forwardVelBase;
        particle->oVelY = random_float() * info->velYRange + info->velYBase;

        obj_scale_xyz(particle, scale, scale, scale);
    }
}

void obj_set_hitbox(struct Object *obj, struct ObjectHitbox *hitbox) {
    if (!(obj->oFlags & OBJ_FLAG_30)) {
        obj->oFlags |= OBJ_FLAG_30;

        obj->oInteractType = hitbox->interactType;
        obj->oDamageOrCoinValue = hitbox->damageOrCoinValue;
        obj->oHealth = hitbox->health;
        obj->oNumLootCoins = hitbox->numLootCoins;

        cur_obj_become_tangible();
    }

    obj->hitboxRadius = obj->header.gfx.scale[0] * hitbox->radius;
    obj->hitboxHeight = obj->header.gfx.scale[1] * hitbox->height;
    obj->hurtboxRadius = obj->header.gfx.scale[0] * hitbox->hurtboxRadius;
    obj->hurtboxHeight = obj->header.gfx.scale[1] * hitbox->hurtboxHeight;
    obj->hitboxDownOffset = obj->header.gfx.scale[1] * hitbox->downOffset;
}

s32 signum_positive(s32 x) {
    if (x >= 0) {
        return 1;
    } else {
        return -1;
    }
}

f32 absf(f32 x) {
    if (x >= 0) {
        return x;
    } else {
        return -x;
    }
}

s32 absi(s32 x) {
    if (x >= 0) {
        return x;
    } else {
        return -x;
    }
}

s32 cur_obj_wait_then_blink(s32 timeUntilBlinking, s32 numBlinks) {
    s32 done = FALSE;
    s32 timeBlinking;

    if (o->oTimer >= timeUntilBlinking) {
        if ((timeBlinking = o->oTimer - timeUntilBlinking) % 2 != 0) {
            o->header.gfx.node.flags |= GRAPH_RENDER_INVISIBLE;
            if (timeBlinking / 2 > numBlinks) {
                done = TRUE;
            }
        } else {
            o->header.gfx.node.flags &= ~GRAPH_RENDER_INVISIBLE;
        }
    }

    return done;
}

s32 cur_obj_is_mario_ground_pounding_platform(void) {
    if (gMarioObject->platform == o) {
        if (gMarioStates[0].action == ACT_GROUND_POUND_LAND) {
            return TRUE;
        }
    }

    return FALSE;
}

void spawn_mist_particles(void) {
    if (!gIsConsole) {
        spawn_mist_particles_variable(0, 0, 46.0f);
    } else {
        spawn_mist_particles_variable(4, 0, 33.0f);
    }
}

void spawn_mist_particles_with_sound(u32 sp18) {
    if (!gIsConsole) {
        spawn_mist_particles_variable(0, 0, 46.0f);
    } else {
        spawn_mist_particles_variable(4, 0, 33.0f);
    }
    create_sound_spawner(sp18);
}

void cur_obj_push_mario_away(f32 radius) {
    f32 marioRelX = gMarioObject->oPosX - o->oPosX;
    f32 marioRelZ = gMarioObject->oPosZ - o->oPosZ;
    f32 marioDist = sqrtf(sqr(marioRelX) + sqr(marioRelZ));

    if (marioDist < radius) {
        //! If this function pushes Mario out of bounds, it will trigger Mario's
        //  oob failsafe
        gMarioStates[0].pos[0] += (radius - marioDist) / radius * marioRelX;
        gMarioStates[0].pos[2] += (radius - marioDist) / radius * marioRelZ;
    }
}

void cur_obj_push_mario_away_from_cylinder(f32 radius, f32 extentY) {
    f32 marioRelY = gMarioObject->oPosY - o->oPosY;

    if (marioRelY < 0.0f) {
        marioRelY = -marioRelY;
    }

    if (marioRelY < extentY) {
        cur_obj_push_mario_away(radius);
    }
}

void bhv_dust_smoke_loop(void) {
    o->oPosX += o->oVelX;
    o->oPosY += o->oVelY;
    o->oPosZ += o->oVelZ;

    if (o->oSmokeTimer == 10) {
        obj_mark_for_deletion(o);
    }

    o->oSmokeTimer++;
}

UNUSED static void stub_obj_helpers_2(void) {
}

s32 cur_obj_set_direction_table(s8 *a0) {
    o->oToxBoxMovementPattern = a0;
    o->oToxBoxMovementStep = 0;

    return *(s8 *) o->oToxBoxMovementPattern;
}

s32 cur_obj_progress_direction_table(void) {
    s8 spF;
    s8 *sp8 = o->oToxBoxMovementPattern;
    s32 sp4 = o->oToxBoxMovementStep + 1;

    if (sp8[sp4] != -1) {
        spF = sp8[sp4];
        o->oToxBoxMovementStep++;
    } else {
        spF = sp8[0];
        o->oToxBoxMovementStep = 0;
    }

    return spF;
}

void stub_obj_helpers_3(UNUSED s32 sp0, UNUSED s32 sp4) {
}

void cur_obj_scale_over_time(s32 a0, s32 a1, f32 sp10, f32 sp14) {
    f32 sp4 = sp14 - sp10;
    f32 sp0 = (f32) o->oTimer / a1;

    if (a0 & 0x01) {
        o->header.gfx.scale[0] = sp4 * sp0 + sp10;
    }

    if (a0 & 0x02) {
        o->header.gfx.scale[1] = sp4 * sp0 + sp10;
    }

    if (a0 & 0x04) {
        o->header.gfx.scale[2] = sp4 * sp0 + sp10;
    }
}

void cur_obj_set_pos_to_home_with_debug(void) {
    o->oPosX = o->oHomeX + gDebugInfo[DEBUG_PAGE_ENEMYINFO][0];
    o->oPosY = o->oHomeY + gDebugInfo[DEBUG_PAGE_ENEMYINFO][1];
    o->oPosZ = o->oHomeZ + gDebugInfo[DEBUG_PAGE_ENEMYINFO][2];
    cur_obj_scale(gDebugInfo[DEBUG_PAGE_ENEMYINFO][3] / 100.0f + 1.0l);
}

void stub_obj_helpers_4(void) {
}

s32 cur_obj_is_mario_on_platform(void) {
    if (gMarioObject->platform == o) {
        return TRUE;
    } else {
        return FALSE;
    }
}

s32 cur_obj_shake_y_until(s32 cycles, s32 amount) {
    if (o->oTimer % 2 != 0) {
        o->oPosY -= amount;
    } else {
        o->oPosY += amount;
    }

    if (o->oTimer == cycles * 2) {
        return TRUE;
    } else {
        return FALSE;
    }
}

s32 jiggle_bbh_stair(s32 a0) {
    if (a0 >= 4 || a0 < 0) {
        return TRUE;
    }

    o->oPosY += sBbhStairJiggleOffsets[a0];
    return FALSE;
}

void cur_obj_call_action_function(void (*actionFunctions[])(void)) {
    void (*actionFunction)(void) = actionFunctions[o->oAction];
    actionFunction();
}

static struct Object *spawn_star_with_no_lvl_exit(s32 sp20, s32 sp24) {
    struct Object *sp1C = spawn_object(o, MODEL_STAR, bhvSpawnedStarNoLevelExit);
    sp1C->oSparkleSpawnUnk1B0 = sp24;
    sp1C->oBehParams = o->oBehParams;
    sp1C->oBehParams2ndByte = sp20;

    return sp1C;
}

// old unused initializer for 2d star spawn behavior.
// uses behavior parameters not used in the current sparkle code.
void spawn_base_star_with_no_lvl_exit(void) {
    spawn_star_with_no_lvl_exit(0, 0);
}

s32 bit_shift_left(s32 a0) {
    return sPowersOfTwo[a0];
}

s32 cur_obj_mario_far_away(void) {
    f32 dx = o->oHomeX - gMarioObject->oPosX;
    f32 dy = o->oHomeY - gMarioObject->oPosY;
    f32 dz = o->oHomeZ - gMarioObject->oPosZ;
    f32 marioDistToHome = sqrtf(dx * dx + dy * dy + dz * dz);

    if (o->oDistanceToMario > 2000.0f && marioDistToHome > 2000.0f) {
        return TRUE;
    } else {
        return FALSE;
    }
}

s32 is_mario_moving_fast_or_in_air(s32 speedThreshold) {
    if (gMarioStates[0].forwardVel > speedThreshold) {
        return TRUE;
    }

    if (gMarioStates[0].action & ACT_FLAG_AIR) {
        return TRUE;
    } else {
        return FALSE;
    }
}

s32 is_item_in_array(s8 item, s8 *array) {
    while (*array != -1) {
        if (*array == item) {
            return TRUE;
        }

        array++;
    }

    return FALSE;
}

UNUSED static void stub_obj_helpers_5(void) {
}

void bhv_init_room(void) {
    struct Surface *floor;
    f32 floorHeight = find_floor(o->oPosX, o->oPosY, o->oPosZ, &floor);
    if (floor != NULL) {
        if (floor->room != 0) {
            o->oRoom = floor->room;
        } else {
            // Floor probably belongs to a platform object. Try looking
            // underneath it
            find_floor(o->oPosX, floorHeight - 100.0f, o->oPosZ, &floor);
            if (floor != NULL) {
                //! Technically possible that the room could still be 0 here
                o->oRoom = floor->room;
            }
        }
    }
}

s32 cur_obj_enable_rendering_if_mario_in_room(void) {
    register s32 marioInRoom;

    if (o->oRoom != -1 && gMarioCurrentRoom != 0) {
        if (gMarioCurrentRoom == o->oRoom) {
            marioInRoom = TRUE;
        } else if (o->oFlags & OBJ_FLAG_MULTIROOM && gMarioCurrentRoom == o->oRoom2) {
            marioInRoom = TRUE;
        } else {
            marioInRoom = FALSE;
        }

        if (marioInRoom) {
            //cur_obj_enable_rendering();
            o->activeFlags &= ~ACTIVE_FLAG_IN_DIFFERENT_ROOM;
            gNumRoomedObjectsInMarioRoom++;
        } else {
            //cur_obj_disable_rendering();
            o->activeFlags |= ACTIVE_FLAG_IN_DIFFERENT_ROOM;
            if (cur_obj_has_behavior(bhvCloud)) {
                o->oAction = 0;
            }
            if (o->oFlags & OBJ_FLAG_DISABLE_ON_ROOM_EXIT) {
                if (cur_obj_has_behavior(bhvMirrorLight) && o->oObjF8 != NULL) {
                    o->oObjF8->os16FC = 0;
                }
                o->activeFlags = 0;
            } else {
                gNumRoomedObjectsNotInMarioRoom++;
            }
        }
    }
    return marioInRoom;
}

s32 cur_obj_set_hitbox_and_die_if_attacked(struct ObjectHitbox *hitbox, s32 deathSound, s32 noLootCoins) {
    s32 interacted = FALSE;

    obj_set_hitbox(o, hitbox);

    if (noLootCoins) {
        o->oNumLootCoins = 0;
    }

    if (o->oInteractStatus & INT_STATUS_INTERACTED) {
        if (o->oInteractStatus & INT_STATUS_WAS_ATTACKED) {
            spawn_mist_particles();
            obj_spawn_loot_yellow_coins(o, o->oNumLootCoins, 20.0f);
            obj_mark_for_deletion(o);
            create_sound_spawner(deathSound);
        } else {
            interacted = TRUE;
        }
    }

    o->oInteractStatus = 0;
    return interacted;
}


void obj_explode_and_spawn_coins(f32 sp18, s32 sp1C) {
    spawn_mist_particles_variable(0, 0, sp18);
    spawn_triangle_break_particles(30, MODEL_DIRT_ANIMATION, 3.0f, 4);
    obj_mark_for_deletion(o);

    if (sp1C == 1) {
        obj_spawn_loot_yellow_coins(o, o->oNumLootCoins, 20.0f);
    } else if (sp1C == 2) {
        obj_spawn_loot_blue_coins(o, o->oNumLootCoins, 20.0f, 150);
    }
}

void obj_set_collision_data(struct Object *obj, const void *segAddr) {
    obj->collisionData = segmented_to_virtual(segAddr);
}

void cur_obj_if_hit_wall_bounce_away(void) {
    if (o->oMoveFlags & OBJ_MOVE_HIT_WALL) {
        o->oMoveAngleYaw = o->oWallAngle;
    }
}

s32 cur_obj_hide_if_mario_far_away_y(f32 distY) {
    if (absf(o->oPosY - gMarioObject->oPosY) < distY) {
        cur_obj_unhide();
        return FALSE;
    } else {
        cur_obj_hide();
        return TRUE;
    }
}

Gfx *geo_offset_klepto_held_object(s32 callContext, struct GraphNode *node, UNUSED Mat4 mtx) {
    if (callContext == GEO_CONTEXT_RENDER) {
        ((struct GraphNodeTranslationRotation *) node->next)->translation[0] = 300;
        ((struct GraphNodeTranslationRotation *) node->next)->translation[1] = 300;
        ((struct GraphNodeTranslationRotation *) node->next)->translation[2] = 0;
    }

    return NULL;
}

Gfx *geo_offset_klepto_debug(s32 callContext, struct GraphNode *node, UNUSED Mat4 mtx) {
    if (callContext == GEO_CONTEXT_RENDER) {
        ((struct GraphNodeTranslationRotation *) node->next)->translation[0] = gDebugInfo[DEBUG_PAGE_EFFECTINFO][0];
        ((struct GraphNodeTranslationRotation *) node->next)->translation[1] = gDebugInfo[DEBUG_PAGE_EFFECTINFO][1];
        ((struct GraphNodeTranslationRotation *) node->next)->translation[2] = gDebugInfo[DEBUG_PAGE_EFFECTINFO][2];
        ((struct GraphNodeTranslationRotation *) node->next)->rotation[0]    = gDebugInfo[DEBUG_PAGE_EFFECTINFO][3];
        ((struct GraphNodeTranslationRotation *) node->next)->rotation[1]    = gDebugInfo[DEBUG_PAGE_EFFECTINFO][4];
        ((struct GraphNodeTranslationRotation *) node->next)->rotation[2]    = gDebugInfo[DEBUG_PAGE_EFFECTINFO][5];
    }

    return NULL;
}

s32 obj_is_hidden(struct Object *obj) {
    if (obj->header.gfx.node.flags & GRAPH_RENDER_INVISIBLE) {
        return TRUE;
    } else {
        return FALSE;
    }
}

void enable_time_stop(void) {
    gTimeStopState |= TIME_STOP_ENABLED;
}

void disable_time_stop(void) {
    gTimeStopState &= ~TIME_STOP_ENABLED;
}

void set_time_stop_flags(s32 flags) {
    gTimeStopState |= flags;
}

void clear_time_stop_flags(s32 flags) {
    gTimeStopState = gTimeStopState & (flags ^ 0xFFFFFFFF);
}

s32 cur_obj_can_mario_activate_textbox(f32 radius, f32 height, UNUSED s32 unused) {
    if (o->oDistanceToMario < 1500.0f) {
        f32 latDistToMario = lateral_dist_between_objects(o, gMarioObject);
        UNUSED s16 angleFromMario = obj_angle_to_object(gMarioObject, o);

        if (latDistToMario < radius && o->oPosY < gMarioObject->oPosY + 160.0f
            && gMarioObject->oPosY < o->oPosY + height && !(gMarioStates[0].action & ACT_FLAG_AIR)
            && mario_ready_to_speak()) {
            return TRUE;
        }
    }

    return FALSE;
}

s32 cur_obj_can_mario_activate_textbox_2(f32 radius, f32 height) {
    // The last argument here is unused. When this function is called directly the argument is always set to 0x7FFF.
    return cur_obj_can_mario_activate_textbox(radius, height, 0x1000);
}

static void cur_obj_end_dialog(s32 dialogFlags, s32 dialogResult) {
    o->oDialogResponse = dialogResult;
    o->oDialogState++;

    if (!(dialogFlags & DIALOG_FLAG_TIME_STOP_ENABLED)) {
        set_mario_npc_dialog(MARIO_DIALOG_STOP);
    }
}


s32 cur_obj_update_dialog(s32 actionArg, s32 dialogFlags, s32 dialogID, UNUSED s32 unused) {
    s32 dialogResponse = DIALOG_RESPONSE_NONE;
    UNUSED s32 doneTurning = TRUE;

    switch (o->oDialogState) {
#if BUGFIX_DIALOG_TIME_STOP
        case DIALOG_STATUS_ENABLE_TIME_STOP:
            // Patched :(
            // Wait for Mario to be ready to speak, and then enable time stop
            if (mario_ready_to_speak() || gMarioState->action == ACT_READING_NPC_DIALOG) {
                gTimeStopState |= TIME_STOP_ENABLED;
                o->activeFlags |= ACTIVE_FLAG_INITIATED_TIME_STOP;
                o->oDialogState++;
            } else {
                break;
            }
            // Fall through so that Mario's action is interrupted immediately
            // after time is stopped
#else
        case DIALOG_STATUS_ENABLE_TIME_STOP:
            //! We enable time stop even if Mario is not ready to speak. This
            //  allows us to move during time stop as long as Mario never enters
            //  an action that can be interrupted with text.
            if (gMarioState->health >= 0x100) {
                gTimeStopState |= TIME_STOP_ENABLED;
                o->activeFlags |= ACTIVE_FLAG_INITIATED_TIME_STOP;
                o->oDialogState++;
            }
            break;
#endif
        case DIALOG_STATUS_INTERRUPT:
            // Interrupt until Mario is actually speaking with the NPC
            if (set_mario_npc_dialog(actionArg) == MARIO_DIALOG_STATUS_SPEAK) {
                o->oDialogState++;
            }
            break;

        case DIALOG_STATUS_START_DIALOG:
            // Starts dialog, depending of the flag defined, it calls
            // a default dialog or a dialog with response.
            if (dialogFlags & DIALOG_FLAG_TEXT_RESPONSE) {
                create_dialog_box_with_response(dialogID);
            } else if (dialogFlags & DIALOG_FLAG_TEXT_DEFAULT) {
                create_dialog_box(dialogID);
            }
            o->oDialogState++;
            break;

        case DIALOG_STATUS_STOP_DIALOG:
            // Stops dialog, if the flag dialog response was called
            // then it defines the value to let the object do the rest.
            if (dialogFlags & DIALOG_FLAG_TEXT_RESPONSE) {
                if (gDialogResponse != DIALOG_RESPONSE_NONE) {
                    cur_obj_end_dialog(dialogFlags, gDialogResponse);
                }
            } else if (dialogFlags & DIALOG_FLAG_TEXT_DEFAULT) {
                if (get_dialog_id() == DIALOG_NONE) {
                    cur_obj_end_dialog(dialogFlags, DIALOG_RESPONSE_NOT_DEFINED);
                }
            } else {
                cur_obj_end_dialog(dialogFlags, DIALOG_RESPONSE_NOT_DEFINED);
            }
            break;

        case DIALOG_STATUS_DISABLE_TIME_STOP:
            // We disable time stop for a few seconds when Mario is no longer
            // speaking or the flag is defined, then we enable it again.
            // Usually, an object disables time stop using a separate function
            // after a certain condition is met.
            if (gMarioState->action != ACT_READING_NPC_DIALOG || (dialogFlags & DIALOG_FLAG_TIME_STOP_ENABLED)) {
                gTimeStopState &= ~TIME_STOP_ENABLED;
                o->activeFlags &= ~ACTIVE_FLAG_INITIATED_TIME_STOP;
                dialogResponse = o->oDialogResponse;
                o->oDialogState = DIALOG_STATUS_ENABLE_TIME_STOP;
            }
            break;

        default:
            o->oDialogState = DIALOG_STATUS_ENABLE_TIME_STOP;
            break;
    }

    return dialogResponse;
}

s32 cur_obj_update_dialog_with_cutscene(s32 actionArg, s32 dialogFlags, s32 cutsceneTable, s32 dialogID) {
    s32 dialogResponse = DIALOG_RESPONSE_NONE;
    s32 doneTurning = TRUE;

    switch (o->oDialogState) {
#if BUGFIX_DIALOG_TIME_STOP
        case DIALOG_STATUS_ENABLE_TIME_STOP:
            // Wait for Mario to be ready to speak, and then enable time stop
            if (mario_ready_to_speak() || gMarioState->action == ACT_READING_NPC_DIALOG) {
                gTimeStopState |= TIME_STOP_ENABLED;
                o->activeFlags |= ACTIVE_FLAG_INITIATED_TIME_STOP;
                o->oDialogState++;
                o->oDialogResponse = DIALOG_RESPONSE_NONE;
            } else {
                break;
            }
            // Fall through so that Mario's action is interrupted immediately
            // after time is stopped
#else
        case DIALOG_STATUS_ENABLE_TIME_STOP:
            //! We enable time stop even if Mario is not ready to speak. This
            //  allows us to move during time stop as long as Mario never enters
            //  an action that can be interrupted with text.
            if (gMarioState->health >= 0x0100) {
                gTimeStopState |= TIME_STOP_ENABLED;
                o->activeFlags |= ACTIVE_FLAG_INITIATED_TIME_STOP;
                o->oDialogState++;
                o->oDialogResponse = DIALOG_RESPONSE_NONE;
            }
            break;
#endif
        case DIALOG_STATUS_INTERRUPT:
            // Additional flag that makes the NPC rotate towards to Mario
            if (dialogFlags & DIALOG_FLAG_TURN_TO_MARIO) {
                doneTurning = cur_obj_rotate_yaw_toward(obj_angle_to_object(o, gMarioObject), 0x800);
                // Failsafe just in case it takes more than 33 frames somehow
                if (o->oDialogResponse >= 33) {
                    doneTurning = TRUE;
                }
            }
            // Interrupt status until Mario is actually speaking with the NPC and if the
            // object is done turning to Mario
            if (set_mario_npc_dialog(actionArg) == MARIO_DIALOG_STATUS_SPEAK && doneTurning) {
                o->oDialogResponse = 0;
                o->oDialogState++;
            } else {
                o->oDialogResponse++; // treated as a timer for the failsafe
            }
            break;

        case DIALOG_STATUS_START_DIALOG:
            // Special check for Cap Switch cutscene since the cutscene itself
            // handles what dialog should use
            if (cutsceneTable == CUTSCENE_CAP_SWITCH_PRESS) {
                if ((o->oDialogResponse = cutscene_object_without_dialog(cutsceneTable, o))) {
                    o->oDialogState++;
                }
            } else {
                // General dialog cutscene function, most of the time
                // the "CUTSCENE_DIALOG" cutscene is called
                if ((o->oDialogResponse = cutscene_object_with_dialog(cutsceneTable, o, dialogID))) {
                    o->oDialogState++;
                }
            }
            break;

        case DIALOG_STATUS_STOP_DIALOG:
            // If flag defined, keep time stop enabled until the object
            // decided to disable it independently
            if (dialogFlags & DIALOG_FLAG_TIME_STOP_ENABLED) {
                dialogResponse = o->oDialogResponse;
                o->oDialogState = DIALOG_STATUS_ENABLE_TIME_STOP;
            } else if (gMarioState->action != ACT_READING_NPC_DIALOG) {
                // Disable time stop, then enable time stop for a frame
                // until the set_mario_npc_dialog function disables it
                gTimeStopState &= ~TIME_STOP_ENABLED;
                o->activeFlags &= ~ACTIVE_FLAG_INITIATED_TIME_STOP;
                dialogResponse = o->oDialogResponse;
                o->oDialogState = DIALOG_STATUS_ENABLE_TIME_STOP;
            } else {
                // And finally stop Mario dialog status
                set_mario_npc_dialog(MARIO_DIALOG_STOP);
            }
            break;
    }

    return dialogResponse;
}

s32 cur_obj_has_model(u16 modelID) {
    if (o->header.gfx.sharedChild == gLoadedGraphNodes[modelID]) {
        return TRUE;
    } else {
        return FALSE;
    }
}

void cur_obj_align_gfx_with_floor(void) {
    struct Surface *floor;
    Vec3f floorNormal;
    Vec3f position;

    position[0] = o->oPosX;
    position[1] = o->oPosY;
    position[2] = o->oPosZ;

    find_floor(position[0], position[1], position[2], &floor);
    if (floor != NULL) {
        floorNormal[0] = floor->normal.x;
        floorNormal[1] = floor->normal.y;
        floorNormal[2] = floor->normal.z;

        mtxf_align_terrain_normal(o->transform, floorNormal, position, o->oFaceAngleYaw);
        o->header.gfx.throwMatrix = &o->transform;
    }
}

s32 mario_is_within_rectangle(s16 minX, s16 maxX, s16 minZ, s16 maxZ) {
    if (gMarioObject->oPosX < minX || maxX < gMarioObject->oPosX) {
        return FALSE;
    }

    if (gMarioObject->oPosZ < minZ || maxZ < gMarioObject->oPosZ) {
        return FALSE;
    }

    return TRUE;
}

void cur_obj_shake_screen(s32 shake) {
    set_camera_shake_from_point(shake, o->oPosX, o->oPosY, o->oPosZ);
}

s32 obj_attack_collided_from_other_object(struct Object *obj) {
    s32 numCollidedObjs;
    struct Object *other;
    s32 touchedOtherObject = FALSE;

    numCollidedObjs = obj->numCollidedObjs;
    if (numCollidedObjs != 0) {
        other = obj->collidedObjs[0];

        if (other != gMarioObject) {
            other->oInteractStatus |= ATTACK_PUNCH | INT_STATUS_WAS_ATTACKED | INT_STATUS_INTERACTED
                                      | INT_STATUS_TOUCHED_BOB_OMB;
            touchedOtherObject = TRUE;
        }
    }

    return touchedOtherObject;
}

s32 cur_obj_was_attacked_or_ground_pounded(void) {
    s32 attacked = FALSE;

    if ((o->oInteractStatus & INT_STATUS_INTERACTED)
        && (o->oInteractStatus & INT_STATUS_WAS_ATTACKED)) {
        attacked = TRUE;
    }

    if (cur_obj_is_mario_ground_pounding_platform()) {
        attacked = TRUE;
    }

    o->oInteractStatus = 0;
    return attacked;
}

void obj_copy_behavior_params(struct Object *dst, struct Object *src) {
    dst->oBehParams = src->oBehParams;
    dst->oBehParams2ndByte = src->oBehParams2ndByte;
}

void cur_obj_init_animation_and_anim_frame(s32 animIndex, s32 animFrame) {
    cur_obj_init_animation_with_sound(animIndex);
    o->header.gfx.animInfo.animFrame = animFrame;
}

s32 cur_obj_init_animation_and_check_if_near_end(s32 animIndex) {
    cur_obj_init_animation_with_sound(animIndex);
    return cur_obj_check_if_near_animation_end();
}

void cur_obj_init_animation_and_extend_if_at_end(s32 animIndex) {
    cur_obj_init_animation_with_sound(animIndex);
    cur_obj_extend_animation_if_at_end();
}

s32 cur_obj_check_grabbed_mario(void) {
    if (o->oInteractStatus & INT_STATUS_GRABBED_MARIO) {
        o->oKingBobombUnk88 = 1;
        cur_obj_become_intangible();
        return TRUE;
    }

    return FALSE;
}

s32 player_performed_grab_escape_action(void) {
    static s32 grabReleaseState;
    s32 result = FALSE;

    if (gPlayer1Controller->stickMag < 30.0f) {
        grabReleaseState = 0;
    }

    if (grabReleaseState == 0 && gPlayer1Controller->stickMag > 40.0f) {
        grabReleaseState = 1;
        result = TRUE;
    }

    if (gPlayer1Controller->buttonPressed & A_BUTTON) {
        result = TRUE;
    }

    return result;
}

void cur_obj_unused_play_footstep_sound(s32 animFrame1, s32 animFrame2, s32 sound) {
    if (cur_obj_check_anim_frame(animFrame1) || cur_obj_check_anim_frame(animFrame2)) {
        cur_obj_play_sound_2(sound);
    }
}

void enable_time_stop_including_mario(void) {
    gTimeStopState |= TIME_STOP_ENABLED | TIME_STOP_MARIO_AND_DOORS;
    o->activeFlags |= ACTIVE_FLAG_INITIATED_TIME_STOP;
}

void disable_time_stop_including_mario(void) {
    gTimeStopState &= ~(TIME_STOP_ENABLED | TIME_STOP_MARIO_AND_DOORS);
    o->activeFlags &= ~ACTIVE_FLAG_INITIATED_TIME_STOP;
}

s32 cur_obj_check_interacted(void) {
    if (o->oInteractStatus & INT_STATUS_INTERACTED) {
        o->oInteractStatus = 0;
        return TRUE;
    } else {
        return FALSE;
    }
}

void cur_obj_spawn_loot_blue_coin(void) {
    if (o->oNumLootCoins >= 5) {
        if (!(gHudDisplay.flags & HUD_DISPLAY_FLAG_BOO)) {
            spawn_object(o, MODEL_HEART, bhvCollectHeart);
        } else {
            spawn_object(o, MODEL_BLUE_COIN, bhvMrIBlueCoin);
        }
        o->oNumLootCoins -= 5;
    }
}

#ifndef VERSION_JP
void cur_obj_spawn_star_at_y_offset(f32 targetX, f32 targetY, f32 targetZ, f32 offsetY) {
    f32 objectPosY = o->oPosY;
    o->oPosY += offsetY + gDebugInfo[DEBUG_PAGE_ENEMYINFO][0];
    spawn_default_star(targetX, targetY, targetZ);
    o->oPosY = objectPosY;
}
#endif
