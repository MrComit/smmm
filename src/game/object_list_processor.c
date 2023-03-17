#include <PR/ultratypes.h>

#include "sm64.h"
#include "area.h"
#include "behavior_data.h"
#include "camera.h"
#include "sm_debug.h"
#include "engine/behavior_script.h"
#include "engine/graph_node.h"
#include "engine/surface_collision.h"
#include "engine/surface_load.h"
#include "interaction.h"
#include "level_update.h"
#include "mario.h"
#include "memory.h"
#include "object_collision.h"
#include "object_helpers.h"
#include "object_list_processor.h"
#include "platform_displacement.h"
#include "profiler.h"
#include "spawn_object.h"
#include "save_file.h"
#include "puppyprint.h"
#include "include/config.h"
#include "dialog_ids.h"
#include "print.h"
#include "seq_ids.h"
#include "game_init.h"
#include "audio/external.h"


/**
 * Flags controlling what debug info is displayed.
 */
s32 gDebugInfoFlags;

/**
 * The number of times per frame find_floor found no floor beneath an
 * object, and therefore either returned a dynamic floor or NULL.
 */
s32 gNumFindFloorMisses;

UNUSED s32 unused_8033BEF8;

/**
 * An unused debug counter with the label "WALL".
 */
s32 gUnknownWallCount;

/**
 * Roughly the number of objects that have been processed this frame so far.
 * A bug in update_terrain_objects makes this count inaccurate.
 */
u32 gObjectCounter;

/**
 * The number of times find_floor, find_ceil, and find_wall_collisions have been called respectively.
 */
struct NumTimesCalled gNumCalls;

/**
 * An array of debug controls that could be used to tweak in-game parameters.
 * The only used rows are [4] and [5] (effectinfo and enemyinfo).
 */
s16 gDebugInfo[16][8];
s16 gDebugInfoOverwrite[16][8];

/**
 * A set of flags to control which objects are updated on a given frame.
 * This is used during dialog and cutscenes to freeze most objects in place.
 */
u32 gTimeStopState;

/**
 * The pool that objects are allocated from.
 */
struct Object gObjectPool[OBJECT_POOL_CAPACITY];

/**
 * A special object whose purpose is to act as a parent for macro objects.
 */
struct Object gMacroObjectDefaultParent;

/**
 * A pointer to gObjectListArray.
 * Given an object list index idx, gObjectLists[idx] is the head of a doubly
 * linked list of all currently spawned objects in the list.
 */
struct ObjectNode *gObjectLists;

/**
 * A singly linked list of available slots in the object pool.
 */
struct ObjectNode gFreeObjectList;

/**
 * The object representing Mario.
 */
struct Object *gMarioObject;

/**
 * An object variable that may have been used to represent the planned
 * second player. This is speculation, based on its position and its usage in
 * shadow.c.
 */
struct Object *gLuigiObject;

/**
 * The object whose behavior script is currently being updated.
 * This object is used frequently in object behavior code, and so is often
 * aliased as "o".
 */
struct Object *gCurrentObject;

/**
 * The next object behavior command to be executed.
 */
const BehaviorScript *gCurBhvCommand;

/**
 * The number of objects that were processed last frame, which may miss some
 * objects that were spawned last frame and all objects that were spawned this
 * frame. It also includes objects that were unloaded last frame.
 * Besides this, a bug in update_terrain_objects makes this count inaccurate.
 */
s16 gPrevFrameObjectCount;

/**
 * The total number of surface nodes allocated (a node is allocated for each
 * spatial partition cell that a surface intersects).
 */
s32 gSurfaceNodesAllocated;

/**
 * The total number of surfaces allocated.
 */
s32 gSurfacesAllocated;

/**
 * The number of nodes that have been created for surfaces.
 */
s32 gNumStaticSurfaceNodes;

/**
 * The number of surfaces in the pool.
 */
s32 gNumStaticSurfaces;

/**
 * A pool used by chain chomp and wiggler to allocate their body parts.
 */
struct MemoryPool *gObjectMemoryPool;


s16 gCheckingSurfaceCollisionsForCamera;
s16 gFindFloorIncludeSurfaceIntangible;
s16 *gEnvironmentRegions;
s32 gEnvironmentLevels[20];
s8 gDoorAdjacentRooms[60][2];
s16 gMarioCurrentRoom;
s16 gMarioPreviousRoom;
s16 gMarioPreviousRoom2;
s16 D_8035FEE2;
s16 D_8035FEE4;
s16 gTHIWaterDrained;
s16 gTTCSpeedSetting;
s16 gMarioShotFromCannon;
s16 gCCMEnteredSlide;
s16 gNumRoomedObjectsInMarioRoom;
s16 gNumRoomedObjectsNotInMarioRoom;
s16 gWDWWaterLevelChanging;
s16 gMarioOnMerryGoRound;

/**
 * Nodes used to represent the doubly linked object lists.
 */
struct ObjectNode gObjectListArray[16];

/**
 * The order that object lists are processed in a frame.
 */
s8 sObjectListUpdateOrder[] = { OBJ_LIST_SPAWNER,
                                OBJ_LIST_SURFACE,
                                OBJ_LIST_POLELIKE,
                                OBJ_LIST_PLAYER,
                                OBJ_LIST_PUSHABLE,
                                OBJ_LIST_GENACTOR,
                                OBJ_LIST_DESTRUCTIVE,
                                OBJ_LIST_LEVEL,
                                OBJ_LIST_DOORS,
                                OBJ_LIST_DEFAULT,
                                OBJ_LIST_UNIMPORTANT,
                                -1 };

/**
 * Info needed to spawn particles and keep track of which have been spawned for
 * an object.
 */
struct ParticleProperties {
    u32 particleFlag;
    u32 activeParticleFlag;
    u8 model;
    const BehaviorScript *behavior;
};

/**
 * A table mapping particle flags to various properties use when spawning a particle.
 */
struct ParticleProperties sParticleTypes[] = {
    { PARTICLE_DUST,                 ACTIVE_PARTICLE_DUST,                 MODEL_MIST,                 bhvMistParticleSpawner },
    { PARTICLE_VERTICAL_STAR,        ACTIVE_PARTICLE_V_STAR,               MODEL_NONE,                 bhvVertStarParticleSpawner },
    { PARTICLE_HORIZONTAL_STAR,      ACTIVE_PARTICLE_H_STAR,               MODEL_NONE,                 bhvHorStarParticleSpawner },
    { PARTICLE_SPARKLES,             ACTIVE_PARTICLE_SPARKLES,             MODEL_SPARKLES,             bhvSparkleParticleSpawner },
    { PARTICLE_BUBBLE,               ACTIVE_PARTICLE_BUBBLE,               MODEL_BUBBLE,               bhvBubbleParticleSpawner },
    { PARTICLE_WATER_SPLASH,         ACTIVE_PARTICLE_WATER_SPLASH,         MODEL_WATER_SPLASH,         bhvWaterSplash },
    { PARTICLE_IDLE_WATER_WAVE,      ACTIVE_PARTICLE_IDLE_WATER_WAVE,      MODEL_IDLE_WATER_WAVE,      bhvIdleWaterWave },
    { PARTICLE_PLUNGE_BUBBLE,        ACTIVE_PARTICLE_PLUNGE_BUBBLE,        MODEL_WHITE_PARTICLE_SMALL, bhvPlungeBubble },
    { PARTICLE_WAVE_TRAIL,           ACTIVE_PARTICLE_WAVE_TRAIL,           MODEL_WAVE_TRAIL,           bhvWaveTrail },
    { PARTICLE_FIRE,                 ACTIVE_PARTICLE_FIRE,                 MODEL_RED_FLAME,            bhvFireParticleSpawner },
    { PARTICLE_SHALLOW_WATER_WAVE,   ACTIVE_PARTICLE_SHALLOW_WATER_WAVE,   MODEL_NONE,                 bhvShallowWaterWave },
    { PARTICLE_SHALLOW_WATER_SPLASH, ACTIVE_PARTICLE_SHALLOW_WATER_SPLASH, MODEL_NONE,                 bhvShallowWaterSplash },
    { PARTICLE_LEAF,                 ACTIVE_PARTICLE_LEAF,                 MODEL_NONE,                 bhvLeafParticleSpawner },
    { PARTICLE_SNOW,                 ACTIVE_PARTICLE_SNOW,                 MODEL_NONE,                 bhvSnowParticleSpawner },
    { PARTICLE_BREATH,               ACTIVE_PARTICLE_BREATH,               MODEL_NONE,                 bhvBreathParticleSpawner },
    { PARTICLE_DIRT,                 ACTIVE_PARTICLE_DIRT,                 MODEL_NONE,                 bhvDirtParticleSpawner },
    { PARTICLE_MIST_CIRCLE,          ACTIVE_PARTICLE_MIST_CIRCLE,          MODEL_NONE,                 bhvMistCircParticleSpawner },
    { PARTICLE_TRIANGLE,             ACTIVE_PARTICLE_TRIANGLE,             MODEL_NONE,                 bhvTriangleParticleSpawner },
    { PARTICLE_GP_MIST_CIRCLE,       ACTIVE_PARTICLE_GP_MIST_CIRCLE,       MODEL_NONE,                 bhvGPMistParticleSpawner },
    { 0, 0, MODEL_NONE, NULL },
};

/**
 * Copy position, velocity, and angle variables from MarioState to the Mario
 * object.
 */
void copy_mario_state_to_object(void) {
    s32 i = 0;
    // L is real
    if (gCurrentObject != gMarioObject) {
        i++;
    }

    gCurrentObject->oVelX = gMarioStates[i].vel[0];
    gCurrentObject->oVelY = gMarioStates[i].vel[1];
    gCurrentObject->oVelZ = gMarioStates[i].vel[2];

    gCurrentObject->oPosX = gMarioStates[i].pos[0];
    gCurrentObject->oPosY = gMarioStates[i].pos[1];
    gCurrentObject->oPosZ = gMarioStates[i].pos[2];

    gCurrentObject->oMoveAnglePitch = gCurrentObject->header.gfx.angle[0];
    gCurrentObject->oMoveAngleYaw = gCurrentObject->header.gfx.angle[1];
    gCurrentObject->oMoveAngleRoll = gCurrentObject->header.gfx.angle[2];

    gCurrentObject->oFaceAnglePitch = gCurrentObject->header.gfx.angle[0];
    gCurrentObject->oFaceAngleYaw = gCurrentObject->header.gfx.angle[1];
    gCurrentObject->oFaceAngleRoll = gCurrentObject->header.gfx.angle[2];

    gCurrentObject->oAngleVelPitch = gMarioStates[i].angleVel[0];
    gCurrentObject->oAngleVelYaw = gMarioStates[i].angleVel[1];
    gCurrentObject->oAngleVelRoll = gMarioStates[i].angleVel[2];
}

/**
 * Spawn a particle at gCurrentObject's location.
 */
void spawn_particle(u32 activeParticleFlag, s16 model, const BehaviorScript *behavior) {
    if (!(gCurrentObject->oActiveParticleFlags & activeParticleFlag)) {
        struct Object *particle;
        gCurrentObject->oActiveParticleFlags |= activeParticleFlag;
        particle = spawn_object_at_origin(gCurrentObject, 0, model, behavior);
        obj_copy_pos_and_angle(particle, gCurrentObject);
    }
}

Vec3f sToadFriendWarp1 = {438.67, 0, 11512.5};
s32 sToadFriendSubAct = 0;

void mario_update_friend_l1_loop(struct MarioState *m) {
    u32 flags = save_file_get_newflags(1) & ~0xF0000000;
    u32 index = CL_count_bits(flags);
    struct Object *obj = CL_objptr_nearest_object_behavior(gMarioObject, bhvToadFriend);
    if (obj == NULL)
        return;
    switch (index) {
        case 0:
            if (gMarioCurrentRoom == 2 && m->pos[2] < 14900.0f && m->pos[1] <= m->floorHeight) {
                if (obj->oF4 == 0) {
                    obj->oF4 = 1;
                    obj->oBehParams2ndByte = 0;
                    obj->oTimer = 0;
                    play_transition(WARP_TRANSITION_FADE_INTO_COLOR, 16, 0, 0, 0);
                }
                if (obj->oF4 == 2) {
                    save_file_set_newflags(SAVE_TOAD_FLAG_INTRODUCTION, 1);
                }
            }
            break;
        case 1:
            if (gMarioCurrentRoom == 4) {
                if (sToadFriendSubAct < 50) {
                    if (!(gTimeStopState & TIME_STOP_ENABLED)) {
                        sToadFriendSubAct++;
                    }
                } else if (sToadFriendSubAct == 50) {
                    play_music(0, SEQUENCE_ARGS(4, SEQ_PROF_T), 0);
                    gHudDisplay.flags |= HUD_DISPLAY_FLAG_CALL;
                    sToadFriendSubAct = 51;
                    set_mario_npc_dialog(1);
                } else if (sToadFriendSubAct == 51) {
                    set_mario_npc_dialog(1);
                    if (gPlayer1Controller->buttonPressed & A_BUTTON) {
                        gHudDisplay.flags &= ~HUD_DISPLAY_FLAG_CALL;
                        sToadFriendSubAct = 52;
                    }
                } else {
                    if (CL_NPC_Dialog(1)) {
                        save_file_set_newflags(SAVE_TOAD_FLAG_FOUND_FIRST_BOO, 1);
                        vec3f_copy(&obj->oPosX, sToadFriendWarp1);
                        obj->oRoom = 13;
                        stop_background_music(SEQUENCE_ARGS(4, SEQ_PROF_T));
                        sToadFriendSubAct = 0;
                    }
                }
            }
            break;
        case 2:
            if (gMarioCurrentRoom == 6) {
                if (sToadFriendSubAct < 20) {
                    if (!(gTimeStopState & TIME_STOP_ENABLED)) {
                        sToadFriendSubAct++;
                    }
                } else if (sToadFriendSubAct == 20) {
                    enable_time_stop();
                    play_music(0, SEQUENCE_ARGS(4, SEQ_PROF_T), 0);
                    gHudDisplay.flags |= HUD_DISPLAY_FLAG_CALL;
                    sToadFriendSubAct = 21;
                    set_mario_npc_dialog(1);
                } else if (sToadFriendSubAct == 21) {
                    set_mario_npc_dialog(1);
                    if (gPlayer1Controller->buttonPressed & A_BUTTON) {
                        gHudDisplay.flags &= ~HUD_DISPLAY_FLAG_CALL;
                        sToadFriendSubAct = 22;
                    }
                } else {                
                    if (CL_NPC_Dialog(2)) {
                        save_file_set_newflags(SAVE_TOAD_FLAG_ENTER_DINING, 1);
                        stop_background_music(SEQUENCE_ARGS(4, SEQ_PROF_T));
                        sToadFriendSubAct = 0;
                        disable_time_stop();
                    }
                }
            }
            break;
        case 3:
            if (gMarioCurrentRoom == 6 && save_file_get_rooms(0) & (1 << 6)) {
                if (sToadFriendSubAct < 100) {
                    if (!(gTimeStopState & TIME_STOP_ENABLED)) {
                        sToadFriendSubAct++;
                    }
                } else if (sToadFriendSubAct == 100) {
                    play_music(0, SEQUENCE_ARGS(4, SEQ_PROF_T), 0);
                    gHudDisplay.flags |= HUD_DISPLAY_FLAG_CALL;
                    sToadFriendSubAct = 101;
                    set_mario_npc_dialog(1);
                } else if (sToadFriendSubAct == 101) {
                    set_mario_npc_dialog(1);
                    if (gPlayer1Controller->buttonPressed & A_BUTTON) {
                        gHudDisplay.flags &= ~HUD_DISPLAY_FLAG_CALL;
                        sToadFriendSubAct = 102;
                    }
                } else {                
                    if (CL_NPC_Dialog(3)) {
                        save_file_set_newflags(SAVE_TOAD_FLAG_CLEAR_DINING, 1);
                        stop_background_music(SEQUENCE_ARGS(4, SEQ_PROF_T));
                        sToadFriendSubAct = 0;
                    }
                }
            }
            break;
        case 4:
            obj->oBehParams2ndByte = 4;
            break;
    }
}



void mario_update_friend_l6_loop(struct MarioState *m) {
    u32 flags = (save_file_get_newflags(1) & ~0b1111) & ~0xF0000000;
    u32 index = CL_count_bits(flags);
    struct Object *obj;
    switch (index) {
        case 0:
            if (gMarioCurrentRoom == 1 && (save_file_get_newflags(1) & SAVE_TOAD_FLAG_ENTER_L6) == 0 && gMarioState->pos[2] > 4000.0f) {
                if (sToadFriendSubAct == 0) {
                    play_music(0, SEQUENCE_ARGS(4, SEQ_PROF_T), 0);
                    gHudDisplay.flags |= HUD_DISPLAY_FLAG_CALL;
                    sToadFriendSubAct = 1;
                    set_mario_npc_dialog(1);
                } else if (sToadFriendSubAct == 1) {
                    set_mario_npc_dialog(1);
                    if (gPlayer1Controller->buttonPressed & A_BUTTON) {
                        gHudDisplay.flags &= ~HUD_DISPLAY_FLAG_CALL;
                        sToadFriendSubAct = 2;
                    }
                } else {
                    if (CL_NPC_Dialog(DIALOG_035)) {
                        save_file_set_newflags(SAVE_TOAD_FLAG_ENTER_L6, 1);
                        CL_call_warp(0, 5000.0f, 0);
                        obj = cur_obj_nearest_object_with_behavior(bhvOpeningWall);
                        if (obj != NULL) {
                            obj->os16F4 = 1;
                        }
                        obj = cur_obj_nearest_object_with_behavior(bhvCushionFriend);
                        if (obj != NULL) {
                            obj->oAction = 1;
                            obj->oPosY += 5000.0f;
                        }
                        stop_background_music(SEQUENCE_ARGS(4, SEQ_PROF_T));
                        sToadFriendSubAct = 0;
                    }
                    gCutsceneFocus = gMarioObject;
                }
            }
            // save_file_set_newflags(SAVE_TOAD_FLAG_ENTER_L6, 1);
            break;
        case 1:
            if (save_file_get_rooms(1) & (1 << 21)) {
                if (sToadFriendSubAct < 50) {
                    if (!(gTimeStopState & TIME_STOP_ENABLED) && (cur_obj_nearest_object_with_behavior(bhvBooSavePrompt) == NULL)) {
                        sToadFriendSubAct++;
                    }
                } else if (sToadFriendSubAct == 50) {
                    play_music(0, SEQUENCE_ARGS(4, SEQ_PROF_T), 0);
                    gHudDisplay.flags |= HUD_DISPLAY_FLAG_CALL;
                    sToadFriendSubAct = 51;
                    set_mario_npc_dialog(1);
                } else if (sToadFriendSubAct == 51) {
                    set_mario_npc_dialog(1);
                    if (gPlayer1Controller->buttonPressed & A_BUTTON) {
                        gHudDisplay.flags &= ~HUD_DISPLAY_FLAG_CALL;
                        sToadFriendSubAct = 52;
                    }
                } else {                
                    if (CL_NPC_Dialog(DIALOG_038)) {
                        save_file_set_newflags(SAVE_TOAD_FLAG_CLEAR_GAME, 1);
                        obj = cur_obj_nearest_object_with_behavior(bhvCushionFriend);
                        if (obj != NULL) {
                            vec3f_set(&obj->oPosX, 1500.0f, 0.0f, 12000.0f);
                            obj->oRoom = 2;
                            obj->oFaceAngleYaw = 0xED00;
                            obj->oFC = 1;
                            obj->oAction = 0;
                        }
                        stop_background_music(SEQUENCE_ARGS(4, SEQ_PROF_T));
                        sToadFriendSubAct = 0;
                    }
                }
            }
            break;
        case 3:
            if (gMarioCurrentRoom == 7 || gMarioCurrentRoom == 8) {
                obj = cur_obj_nearest_object_with_behavior(bhvCushionFriend);
                if (obj != NULL && obj->oFC != 2) {
                    vec3f_set(&obj->oPosX, 1630.0f, 0.0f, -5675.0f);
                    obj->oRoom = 8;
                    obj->oFaceAngleYaw = 0x5800;
                    obj->oFC = 2;
                    obj->oAction = 0;
                    obj->oTimer = 0;
                }  
            }
            break;
        case 4:
            if (save_file_get_rooms(1) & (1 << 25)) {
                if (sToadFriendSubAct < 50) {
                    if (!(gTimeStopState & TIME_STOP_ENABLED) && (cur_obj_nearest_object_with_behavior(bhvBooSavePrompt) == NULL)) {
                        sToadFriendSubAct++;
                    }
                } else if (sToadFriendSubAct == 50) {
                    play_music(0, SEQUENCE_ARGS(4, SEQ_PROF_T), 0);
                    gHudDisplay.flags |= HUD_DISPLAY_FLAG_CALL;
                    sToadFriendSubAct = 51;
                    set_mario_npc_dialog(1);
                } else if (sToadFriendSubAct == 51) {
                    set_mario_npc_dialog(1);
                    if (gPlayer1Controller->buttonPressed & A_BUTTON) {
                        gHudDisplay.flags &= ~HUD_DISPLAY_FLAG_CALL;
                        sToadFriendSubAct = 52;
                    }
                } else {       
                    if (CL_NPC_Dialog(DIALOG_041)) {
                        save_file_set_newflags(SAVE_TOAD_FLAG_CLEAR_THEATER, 1);
                        obj = cur_obj_nearest_object_with_behavior(bhvCushionFriend);
                        if (obj != NULL) {
                            obj->header.gfx.node.flags |= GRAPH_RENDER_INVISIBLE;
                            vec3f_set(&obj->oPosX, -2100.0f, 2185.0f, 3800.0f);
                            obj->oRoom = 2;
                            obj->oFaceAngleYaw = 0x8C00;
                            obj->oFC = 3;
                            obj->oAction = 0;
                        }
                        stop_background_music(SEQUENCE_ARGS(4, SEQ_PROF_T));
                        sToadFriendSubAct = 0;
                    }         
                }
            }
            break;
    }
}

s32 sToadUpgradeAct = 0;

s32 mario_update_manager_upgrade_action(struct MarioState *m, s32 dialogId) {
    if (sToadUpgradeAct < 50) {
        if (!(gTimeStopState & TIME_STOP_ENABLED) && (cur_obj_nearest_object_with_behavior(bhvBooSavePrompt) == NULL)) {
            sToadUpgradeAct++;
        }
    } else if (sToadUpgradeAct == 50) {
        play_music(0, SEQUENCE_ARGS(4, SEQ_PROF_T), 0);
        gHudDisplay.flags |= HUD_DISPLAY_FLAG_CALL;
        sToadUpgradeAct = 51;
        set_mario_npc_dialog(1);
    } else if (sToadUpgradeAct == 51) {
        set_mario_npc_dialog(1);
        if (gPlayer1Controller->buttonPressed & A_BUTTON) {
            gHudDisplay.flags &= ~HUD_DISPLAY_FLAG_CALL;
            sToadUpgradeAct = 52;
        }
    } else {                
        if (CL_NPC_Dialog(dialogId)) {
            stop_background_music(SEQUENCE_ARGS(4, SEQ_PROF_T));
            sToadUpgradeAct = 0;
            return TRUE;
        }
    }
    return FALSE;
}


void mario_update_manager_upgrades(struct MarioState *m) {
    struct Object *obj;
    s32 boos = CL_count_bits(save_file_get_boos());
    s32 flags = save_file_get_newflags(1);
    switch (boos) {
        case 5:
            if (!(flags & SAVE_TOAD_FLAG_TRACKER_1)) {
                if (mario_update_manager_upgrade_action(m, DIALOG_068)) {
                    save_file_set_newflags(SAVE_TOAD_FLAG_TRACKER_1, 1);
                }
            }
            break;
        case 10:
            if (!(flags & SAVE_TOAD_FLAG_COINS_2)) {
                if (mario_update_manager_upgrade_action(m, DIALOG_069)) {
                    m->numCoins += 500;
                    save_file_set_newflags(SAVE_TOAD_FLAG_COINS_2, 1);
                }
            }
            break;
        case 15:
            if (!(flags & SAVE_TOAD_FLAG_MULTI_3)) {
                if (mario_update_manager_upgrade_action(m, DIALOG_070)) {
                    save_file_set_newflags(SAVE_TOAD_FLAG_MULTI_3, 1);
                }
            }
            break;
        case 20:
            if (!(flags & SAVE_TOAD_FLAG_TREASURE_4)) {
                if (mario_update_manager_upgrade_action(m, DIALOG_071)) {
                    obj = spawn_object(gMarioObject, MODEL_BIG_KEY, bhvBigKey);
                    obj->oBehParams2ndByte = 15;
                    obj->oFaceAngleRoll = 0xF000;
                    obj->oFaceAngleYaw = 0;
                    obj->oPosX = m->pos[0];
                    obj->oPosZ = m->pos[2];
                    obj->oFlags &= ~OBJ_FLAG_DISABLE_ON_ROOM_EXIT;
                    obj->oAnimState = 1;
                    save_file_set_newflags(SAVE_TOAD_FLAG_TREASURE_4, 1);
                }

            }
            break;
    }
}

extern s32 gLowGrav;

void mario_update_toad_friend(struct MarioState *m) {
    switch (gCurrLevelNum) {
        case LEVEL_BOB:
            mario_update_friend_l1_loop(m);
            break;
        case LEVEL_WF:
            break;
        case LEVEL_HMC:
            mario_update_friend_l6_loop(m);
            break;
#ifdef SMMM_DEBUG
        case LEVEL_LLL:
            //TEMP
            if (gPlayer1Controller->buttonPressed & L_TRIG && gPlayer1Controller->buttonDown & Z_TRIG) {
                gLowGrav ^= 1;
            }
            break;
#endif
    }
    mario_update_manager_upgrades(m);
}

s8 sLevelRoomOffsets[] = {0, 14, 32, 36, 41, 48, 64, 0, 0, 0, 0,};
s8 gGlobalMarioRoom = 0;


void mario_update_room_clear(struct MarioState *m) {
    u32 index = 0;
    u32 room = gGlobalMarioRoom;
    while (room > 32) {
        room -= 32;
        index++;
    }

    if (save_file_get_rooms(index) & (1 << room)) {
        return;
    }

    if (!(count_room_objects_with_flag(OBJ_FLAG_DISABLE_TO_ROOM_CLEAR, gMarioCurrentRoom))) {
        save_file_set_rooms(gGlobalMarioRoom);
    }

}
extern u32 sPoolFreeSpace;
//#include "src/engine/math_util.h"
#include <stdio.h>
// void print_text(s32, s32, char*);

f32 intDist;
Vec3f intersect;


void mario_l_to_levitate(void) {
    if (gMarioState->controller->buttonPressed & L_TRIG) {
         set_mario_action(gMarioState, ACT_DEBUG_FREE_MOVE, 0);
        //  cur_obj_set_model(MODEL_NONE);
        // gMarioObject->header.gfx.sharedChild = gLoadedGraphNodes[0]; //makes mario invisible
    } else if (gMarioState->controller->buttonDown & L_TRIG)
        gMarioState->pos[1] += 20.0f;
}

extern s16 gEdgeLengths[3];
/**
 * Mario's primary behavior update function.
 */
void bhv_mario_update(void) {
    u32 particleFlags = 0;
    s32 i;
    #ifdef SMMM_DEBUG
        mario_l_to_levitate();
    #endif

    //print_text_fmt_int(20, 80, "%x", sPoolFreeSpace, 0);

    particleFlags = execute_mario_action(gCurrentObject);

    gCurrentObject->oMarioParticleFlags = particleFlags;

    // Mario code updates MarioState's versions of position etc, so we need
    // to sync it with the Mario object
    copy_mario_state_to_object();

    i = 0;
    while (sParticleTypes[i].particleFlag != 0) {
        if (particleFlags & sParticleTypes[i].particleFlag) {
            spawn_particle(sParticleTypes[i].activeParticleFlag, sParticleTypes[i].model,
                           sParticleTypes[i].behavior);
        }

        i++;
    }
    // if (gPlayer1Controller->buttonPressed & L_TRIG) {
    //     save_file_erase(0);
    // }
    mario_update_toad_friend(gMarioState);
    mario_update_room_clear(gMarioState);

#ifndef SMMM_DEBUG
    if (!(save_file_get_newflags(0) & SAVE_NEW_FLAG_MAINHALL_SCENE) && gMarioCurrentRoom == 2 && gCurrLevelNum == LEVEL_BOB) {
        gCamera->comitCutscene = 10;
    }
#endif

    // if (gMarioState->controller->buttonDown & Z_TRIG) {
    //     print_text_fmt_int(50, 8*20, "HELLO WORLD", 0, 0);
    //     print_text_fmt_int(50, 7*20, "LOREM IPSUM", 0, 1);
    //     print_text_fmt_int(50, 6*20, "CONGRATULATIONS!", 0, 2);
    //     print_text_fmt_int(50, 5*20, "YOU WIN", 0, 3);
    //     print_text_fmt_int(50, 4*20, "SUPER MARIO AND", 0, 4);
    //     print_text_fmt_int(50, 3*20, "THE MONSTROUS MANOR", 0, 5);
    //     print_text_fmt_int(50, 8*20, "the quick", 0, 0);
    //     print_text_fmt_int(50, 7*20, "red fox", 0, 1);
    //     print_text_fmt_int(50, 6*20, "jumped", 0, 2);
    //     print_text_fmt_int(50, 5*20, "over the", 0, 3);
    //     print_text_fmt_int(50, 4*20, "lazy dog", 0, 4);
    //     print_text_fmt_int(80, 8*20, "ABCDEF", 0, 0);
    //     print_text_fmt_int(80, 7*20, "GHIJKL", 0, 1);
    //     print_text_fmt_int(80, 6*20, "MNOPQR", 0, 2);
    //     print_text_fmt_int(80, 5*20, "STUVWX", 0, 3);
    //     print_text_fmt_int(80, 4*20, "YZ0123", 0, 4);
    //     print_text_fmt_int(80, 3*20, "456789", 0, 5);
    //     print_text_fmt_int(80, 2*20, ".?!", 0, 0);
    // }
}

/**
 * Update every object that occurs after firstObj in the given object list,
 * including firstObj itself. Return the number of objects that were updated.
 */
s32 update_objects_starting_at(struct ObjectNode *objList, struct ObjectNode *firstObj) {
    s32 count = 0;

    while (objList != firstObj) {
        gCurrentObject = (struct Object *) firstObj;

        gCurrentObject->header.gfx.node.flags |= GRAPH_RENDER_HAS_ANIMATION;
        cur_obj_update();

        firstObj = firstObj->next;
        count++;
    }

    return count;
}

/**
 * Update objects in objList starting with firstObj while time stop is active.
 * This means that only certain select objects will be updated, such as Mario,
 * doors, unimportant objects, and the object that initiated time stop.
 * The exact set of objects that are updated depends on which flags are set
 * in gTimeStopState.
 * Return the total number of objects in the list (including those that weren't
 * updated)
 */
s32 update_objects_during_time_stop(struct ObjectNode *objList, struct ObjectNode *firstObj) {
    s32 count = 0;
    s32 unfrozen;

    while (objList != firstObj) {
        gCurrentObject = (struct Object *) firstObj;

        unfrozen = FALSE;

        // Selectively unfreeze certain objects
        if (!(gTimeStopState & TIME_STOP_ALL_OBJECTS)) {
            if (gCurrentObject == gMarioObject && !(gTimeStopState & TIME_STOP_MARIO_AND_DOORS)) {
                unfrozen = TRUE;
            }

            if ((gCurrentObject->oInteractType & (INTERACT_DOOR | INTERACT_WARP_DOOR))
                && !(gTimeStopState & TIME_STOP_MARIO_AND_DOORS)) {
                unfrozen = TRUE;
            }

            if (gCurrentObject->activeFlags
                & (ACTIVE_FLAG_UNIMPORTANT | ACTIVE_FLAG_INITIATED_TIME_STOP)) {
                unfrozen = TRUE;
            }
        }

        // Only update if unfrozen
        if (unfrozen) {
            gCurrentObject->header.gfx.node.flags |= GRAPH_RENDER_HAS_ANIMATION;
            cur_obj_update();
        } else {
            gCurrentObject->header.gfx.node.flags &= ~GRAPH_RENDER_HAS_ANIMATION;
        }

        firstObj = firstObj->next;
        count++;
    }

    return count;
}

/**
 * Update every object in the given list. Return the total number of objects in
 * the list.
 */
s32 update_objects_in_list(struct ObjectNode *objList) {
    s32 count;
    struct ObjectNode *firstObj = objList->next;

    if (!(gTimeStopState & TIME_STOP_ACTIVE)) {
        count = update_objects_starting_at(objList, firstObj);
    } else {
        count = update_objects_during_time_stop(objList, firstObj);
    }

    return count;
}

/**
 * Unload any objects in the list that have been deactivated.
 */
s32 unload_deactivated_objects_in_list(struct ObjectNode *objList) {
    struct ObjectNode *obj = objList->next;

    while (objList != obj) {
        gCurrentObject = (struct Object *) obj;

        obj = obj->next;

        if ((gCurrentObject->activeFlags & ACTIVE_FLAG_ACTIVE) != ACTIVE_FLAG_ACTIVE) {
            // Prevent object from respawning after exiting and re-entering the
            // area
            if (!(gCurrentObject->oFlags & OBJ_FLAG_PERSISTENT_RESPAWN)) {
                set_object_respawn_info_bits(gCurrentObject, RESPAWN_INFO_DONT_RESPAWN);
            }

            unload_object(gCurrentObject);
        }
    }

    return 0;
}

/**
 * OR the object's respawn info with bits << 8. If bits = 0xFF, this prevents
 * the object from respawning after leaving and re-entering the area.
 * For macro objects, respawnInfo points to the 16 bit entry in the macro object
 * list. For other objects, it points to the 32 bit behaviorArg in the
 * SpawnInfo.
 */
void set_object_respawn_info_bits(struct Object *obj, u8 bits) {
    u32 *info32;
    u16 *info16;

    switch (obj->respawnInfoType) {
        case RESPAWN_INFO_TYPE_32:
            info32 = (u32 *) obj->respawnInfo;
            *info32 |= bits << 8;
            break;

        case RESPAWN_INFO_TYPE_16:
            info16 = (u16 *) obj->respawnInfo;
            *info16 |= bits << 8;
            break;
    }
}

/**
 * Unload all objects whose activeAreaIndex is areaIndex.
 */
void unload_objects_from_area(UNUSED s32 unused, s32 areaIndex) {
    struct Object *obj;
    struct ObjectNode *node;
    struct ObjectNode *list;
    s32 i;
    gObjectLists = gObjectListArray;

    for (i = 0; i < NUM_OBJ_LISTS; i++) {
        list = gObjectLists + i;
        node = list->next;

        while (node != list) {
            obj = (struct Object *) node;
            node = node->next;

            if (obj->header.gfx.activeAreaIndex == areaIndex) {
                unload_object(obj);
            }
        }
    }
}

/**
 * Spawn objects given a list of SpawnInfos. Called when loading an area.
 */
void spawn_objects_from_info(UNUSED s32 unused, struct SpawnInfo *spawnInfo) {
    gObjectLists = gObjectListArray;
    gTimeStopState = 0;

    gWDWWaterLevelChanging = FALSE;
    gMarioOnMerryGoRound = FALSE;

    //! (Spawning Displacement) On the Japanese version, Mario's platform object
    //  isn't cleared when transitioning between areas. This can cause Mario to
    //  receive displacement after spawning.
#ifndef VERSION_JP
    clear_mario_platform();
#endif

    if (gCurrAreaIndex == 2) {
        gCCMEnteredSlide |= 1;
    }

    while (spawnInfo != NULL) {
        struct Object *object;
        UNUSED u8 filler[4];
        const BehaviorScript *script;
        UNUSED s16 arg16 = (s16)(spawnInfo->behaviorArg & 0xFFFF);

        script = segmented_to_virtual(spawnInfo->behaviorScript);

        // If the object was previously killed/collected, don't respawn it
        if ((spawnInfo->behaviorArg & (RESPAWN_INFO_DONT_RESPAWN << 8))
            != (RESPAWN_INFO_DONT_RESPAWN << 8)) {
            object = create_object(script);

            // Behavior parameters are often treated as four separate bytes, but
            // are stored as an s32.
            object->oBehParams = spawnInfo->behaviorArg;
            // The second byte of the behavior parameters is copied over to a special field
            // as it is the most frequently used by objects.
            object->oBehParams2ndByte = ((spawnInfo->behaviorArg) >> 16) & 0xFF;

            object->behavior = script;
            object->unused1 = 0;

            // Record death/collection in the SpawnInfo
            object->respawnInfoType = RESPAWN_INFO_TYPE_32;
            object->respawnInfo = &spawnInfo->behaviorArg;

            if (object->behavior == segmented_to_virtual(bhvMario)) {
                gMarioObject = object;
                geo_make_first_child(&object->header.gfx.node);
            }

            geo_obj_init_spawninfo(&object->header.gfx, spawnInfo);

            object->oPosX = spawnInfo->startPos[0];
            object->oPosY = spawnInfo->startPos[1];
            object->oPosZ = spawnInfo->startPos[2];

            object->oFaceAnglePitch = spawnInfo->startAngle[0];
            object->oFaceAngleYaw = spawnInfo->startAngle[1];
            object->oFaceAngleRoll = spawnInfo->startAngle[2];

            object->oMoveAnglePitch = spawnInfo->startAngle[0];
            object->oMoveAngleYaw = spawnInfo->startAngle[1];
            object->oMoveAngleRoll = spawnInfo->startAngle[2];
            object->oFloorHeight = find_floor(object->oPosX, object->oPosY, object->oPosZ, &object->oFloor);
        }

        spawnInfo = spawnInfo->next;
    }
}

void stub_obj_list_processor_1(void) {
}

/**
 * Clear objects, dynamic surfaces, and some miscellaneous level data used by objects.
 */
void clear_objects(void) {
    s32 i;

    gTHIWaterDrained = 0;
    gTimeStopState = 0;
    gMarioObject = NULL;
    gMarioCurrentRoom = 0;
    gGlobalMarioRoom = 0;

    for (i = 0; i < 60; i++) {
        gDoorAdjacentRooms[i][0] = 0;
        gDoorAdjacentRooms[i][1] = 0;
    }

    debug_unknown_level_select_check();

    init_free_object_list();
    clear_object_lists(gObjectListArray);

    stub_behavior_script_2();
    stub_obj_list_processor_1();

    for (i = 0; i < OBJECT_POOL_CAPACITY; i++) {
        gObjectPool[i].activeFlags = ACTIVE_FLAG_DEACTIVATED;
        geo_reset_object_node(&gObjectPool[i].header.gfx);
    }

    gObjectMemoryPool = mem_pool_init(0x800, MEMORY_POOL_LEFT);
    gObjectLists = gObjectListArray;

    clear_dynamic_surfaces();
}

/**
 * Update spawner and surface objects.
 */
void update_terrain_objects(void) {
    gObjectCounter = update_objects_in_list(&gObjectLists[OBJ_LIST_SPAWNER]);
    //! This was meant to be +=
    gObjectCounter = update_objects_in_list(&gObjectLists[OBJ_LIST_SURFACE]);
    gObjectCounter += update_objects_in_list(&gObjectLists[OBJ_LIST_DOORS]);


    // If the dynamic surface pool has overflowed, throw an error.
    // assert((uintptr_t)gDynamicSurfacePoolEnd <= (uintptr_t)gDynamicSurfacePool + DYNAMIC_SURFACE_POOL_SIZE, "Dynamic surface pool size exceeded");
}

/**
 * Update all other object lists besides spawner and surface objects, using
 * the order specified by sObjectListUpdateOrder.
 */
void update_non_terrain_objects(void) {
    UNUSED u8 filler[4];
    s32 listIndex;

    s32 i = 2;
    while ((listIndex = sObjectListUpdateOrder[i]) != -1) {
        gObjectCounter += update_objects_in_list(&gObjectLists[listIndex]);
        i++;
    }
}

/**
 * Unload deactivated objects in any object list.
 */
void unload_deactivated_objects(void) {
    UNUSED u8 filler[4];
    s32 listIndex;

    s32 i = 0;
    while ((listIndex = sObjectListUpdateOrder[i]) != -1) {
        unload_deactivated_objects_in_list(&gObjectLists[listIndex]);
        i++;
    }

    // TIME_STOP_UNKNOWN_0 was most likely intended to be used to track whether
    // any objects had been deactivated
    gTimeStopState &= ~TIME_STOP_UNKNOWN_0;
}

/**
 * Unused profiling function.
 */
UNUSED static u16 unused_get_elapsed_time(u64 *cycleCounts, s32 index) {
    u16 time;
    f64 cycles;

    cycles = cycleCounts[index] - cycleCounts[index - 1];
    if (cycles < 0) {
        cycles = 0;
    }

    time = (u16)(((u64) cycles * 1000000 / osClockRate) / 16667.0 * 1000.0);
    if (time > 999) {
        time = 999;
    }

    return time;
}

/**
 * Update all objects. This includes script execution, object collision detection,
 * and object surface management.
 */
void update_objects() {
#if PUPPYPRINT_DEBUG
    OSTime first = osGetTime();
    OSTime colTime = collisionTime[perfIteration];
#endif


    gTimeStopState &= ~TIME_STOP_MARIO_OPENED_DOOR;

    gNumRoomedObjectsInMarioRoom = 0;
    gNumRoomedObjectsNotInMarioRoom = 0;
    gCheckingSurfaceCollisionsForCamera = FALSE;

    reset_debug_objectinfo();
    stub_debug_5();

    gObjectLists = gObjectListArray;

    // If time stop is not active, unload object surfaces
    clear_dynamic_surfaces();

    // Update spawners and objects with surfaces
    update_terrain_objects();

    // If Mario was touching a moving platform at the end of last frame, apply
    // displacement now
    //! If the platform object unloaded and a different object took its place,
    //  displacement could be applied incorrectly
    apply_mario_platform_displacement();

    // Detect which objects are intersecting
    detect_object_collisions();

    // Update all other objects that haven't been updated yet
    update_non_terrain_objects();

    // Unload any objects that have been deactivated
    unload_deactivated_objects();

    // Check if Mario is on a platform object and save this object
    update_mario_platform();

    try_print_debug_mario_object_info();

    // If time stop was enabled this frame, activate it now so that it will
    // take effect next frame
    if (gTimeStopState & TIME_STOP_ENABLED) {
        gTimeStopState |= TIME_STOP_ACTIVE;
    } else {
        gTimeStopState &= ~TIME_STOP_ACTIVE;
    }

    gPrevFrameObjectCount = gObjectCounter;
#if PUPPYPRINT_DEBUG
    profiler_update(behaviourTime, first);
    behaviourTime[perfIteration] -= collisionTime[perfIteration]+colTime;
#endif
}
