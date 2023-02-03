#include "game/hud.h"
struct ObjectHitbox s2DEnemyHitbox = {
    /* interactType:      */ INTERACT_BOUNCE_TOP,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 1,
    /* numLootCoins:      */ 1,
    /* radius:            */ 72,
    /* height:            */ 50,
    /* hurtboxRadius:     */ 42,
    /* hurtboxHeight:     */ 40,
};

struct ObjectHitbox sTomatoHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 1,
    /* numLootCoins:      */ 0,
    /* radius:            */ 72,
    /* height:            */ 50,
    /* hurtboxRadius:     */ 42,
    /* hurtboxHeight:     */ 40,
};

struct ObjectHitbox s2DBoomBoomHitbox = {
    /* interactType:      */ INTERACT_BOUNCE_TOP,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 3,
    /* numLootCoins:      */ 5,
    /* radius:            */ 72*2,
    /* height:            */ 50*2,
    /* hurtboxRadius:     */ 42*2,
    /* hurtboxHeight:     */ 40*2,
};

struct ObjectHitbox s2DBulletBillHitbox = {
    /* interactType:      */ INTERACT_BOUNCE_TOP,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 1,
    /* numLootCoins:      */ 1,
    /* radius:            */ 72,
    /* height:            */ 30,
    /* hurtboxRadius:     */ 72,
    /* hurtboxHeight:     */ 30,
};

static void const *sTheaterArenaCollision[] = {
    theater_arena1_collision,
    theater_arena2_collision,
    theater_arena3_collision,
};


Vec3f sTheaterRespawn[3] = {
{-4954.0f, 300.0f, -13146.0f},
{-3354.0f, 150.0f, -13146.0f},
{-3354.0f, 100.0f, -13146.0f},
};


struct Object *gTomatoObjs[3];
Vec3f sTomatoPos[3] = {
    {-3580.0f, 650.0f, -10200.0f},
    {-3250.0f, 585.0f, -10400.0f},
    {-3420.0f, 665.0f, -10200.0f},
};


#define COMIT_OBJECT(a, b, c, d, e, f, g, h) \
    obj = spawn_object_abs_with_rot(o, 0, a, h, b, c, d, DEGREES(e), DEGREES(f), DEGREES(g)); \
    obj->oRoom = o->oRoom; \
    obj->oFlags &= ~OBJ_FLAG_DISABLE_ON_ROOM_EXIT;


void bhv_tomato_init(void) {
    obj_set_hitbox(o, &sTomatoHitbox);
    o->oForwardVel = 60.0f;
    o->oMoveAngleYaw = o->parentObj->oFaceAngleYaw;
    o->oMoveAnglePitch = -o->parentObj->oFaceAnglePitch;
    o->oPosY += 100.0f;
}

void bhv_tomato_loop(void) {
    CL_Move_3d();
    o->oFaceAngleYaw += 0x200;
    o->oFaceAngleRoll += 0x400;
    if (o->oPosZ < -13200.0f || o->oInteractStatus & INT_STATUS_INTERACTED) {
        o->activeFlags = 0;
        spawn_mist_particles();
    }
}



void set_tomato_target(s32 type) {
    s32 x, y;
    s32 xAdd = 0;
    s32 cond = FALSE;
    // s16 rate = 0x4;
    switch (type) {
        case 0:
            if (gMarioScreenX > 100 && gMarioScreenX < 220) {
                cond = TRUE;
            } else {
                xAdd = 160;
            }
            break;
        case 1:
            if (gMarioScreenX < 120) {
                cond = TRUE;
            } else {
                xAdd = 50;
            }
            break;
        case 2:
            if (gMarioScreenX > 200) {
                cond = TRUE;
            } else {
                xAdd = 270;
            }
            break;
    }

    if (cond) {
        x = gMarioScreenX;
        y = gMarioScreenY;
    } else {
        o->os16FC += CL_RandomMinMaxU16(0x180, 0x280);
        x = xAdd + (sins(o->os16FC) * 50);
        y = 120 + (coss(o->os16FC) * 75);
    }

    o->os16F4 = approach_s16_symmetric(o->os16F4, x, 0x4);
    o->os16F6 = approach_s16_symmetric(o->os16F6, y, 0x4);
}

void bhv_tomato_thrower_init(void) {
    s16 pitch, yaw;
    f32 dist;
    gTomatoObjs[o->oBehParams2ndByte] = o;
    vec3f_copy(&o->oPosX, sTomatoPos[o->oBehParams2ndByte]);
    vec3f_get_dist_and_angle(&o->oPosX, gMarioState->pos, &dist, &pitch, &yaw);
    o->oFaceAnglePitch = -pitch;
    o->oFaceAngleYaw = yaw;
    o->oHomeY = o->oPosY;
    o->oPosY -= 500.0f;
    o->os16FA = CL_RandomMinMaxU16(40, 60);
}


void bhv_tomato_thrower_loop(void) {
    s16 pitch, yaw;
    f32 dist;
    o->oPosY = approach_f32_symmetric(o->oPosY, o->oHomeY, 12.0f);
    if (o->oTimer > o->os16FA) {
        spawn_object(o, MODEL_THEATER_TOMATO, bhvTomato);
        o->oTimer = 0;
        o->os16FA = CL_RandomMinMaxU16(40, 60);
    } else if (o->oTimer > 20) {
        o->os16F8 = 1;
        set_tomato_target(o->oBehParams2ndByte);
        vec3f_get_dist_and_angle(&o->oPosX, gMarioState->pos, &dist, &pitch, &yaw);
        o->oFaceAnglePitch = -pitch;
        o->oFaceAngleYaw = yaw;
    }
    if (o->parentObj->oOpacity > 100) {
        o->oTimer = 0;
        o->os16F8 = 0;
    }
    if (absi(o->os16F4 - gMarioScreenX) * absi(o->os16F6 - gMarioScreenY) > 15*15) {
        o->oTimer = 20;
    }

}


void bhv_theater_arena_init(void) {
    o->collisionData = segmented_to_virtual(sTheaterArenaCollision[o->oBehParams2ndByte]);
    spawn_theater_arena(o->oBehParams2ndByte);
}



void spawn_theater_arena(s16 arena) {
    struct Object *obj;
    while ((obj = cur_obj_nearest_object_with_behavior(bhvBulletBill2dSpawner)) != NULL) {
        obj->activeFlags = 0;
    }

    while ((obj = cur_obj_nearest_object_with_behavior(bhvBulletBill2d)) != NULL) {
        obj->activeFlags = 0;
    }

    if ((obj = cur_obj_nearest_object_with_behavior(bhvToken)) != NULL) {
        obj->activeFlags = 0;
    }

    // temporary
    while ((obj = cur_obj_nearest_object_with_behavior(bhvCollectHeart)) != NULL) {
        obj->activeFlags = 0;
    }


    switch (arena) {
        case 0:
            COMIT_OBJECT(MODEL_GOOMBA_2D, -3790, 100, -13146, 0, -90, 0, bhv2DEnemy)
            COMIT_OBJECT(MODEL_GOOMBA_2D, -3424, 100, -13146, 0, -90, 0, bhv2DEnemy)
            COMIT_OBJECT(MODEL_GOOMBA_2D, -3126, 100, -13146, 0, -90, 0, bhv2DEnemy)
            COMIT_OBJECT(MODEL_GOOMBA_2D, -5125, 782, -13146, 0, -90, 0, bhv2DEnemy)
            COMIT_OBJECT(MODEL_GOOMBA_2D, -4890, 782, -13146, 0, -90, 0, bhv2DEnemy)
            COMIT_OBJECT(MODEL_KOOPA_2D, -3790, 970, -13146,  0, -90, 0,  bhv2DEnemy)
            COMIT_OBJECT(MODEL_KOOPA_2D, -3485, 970, -13146,  0, -90, 0,  bhv2DEnemy)
            COMIT_OBJECT(MODEL_KOOPA_2D, -3211, 970, -13146,  0, -90, 0,  bhv2DEnemy)
            break;
        case 1:
            COMIT_OBJECT(MODEL_GOOMBA_2D, -4801, 341, -13146, 0, -90, 0, bhv2DEnemy)
            COMIT_OBJECT(MODEL_GOOMBA_2D, -4977, 341, -13146, 0, -90, 0, bhv2DEnemy)
            COMIT_OBJECT(MODEL_GOOMBA_2D, -5137, 341, -13146, 0, -90, 0, bhv2DEnemy)
            COMIT_OBJECT(MODEL_GOOMBA_2D, -2338, 94, -13146, 0, -90, 0, bhv2DEnemy)
            COMIT_OBJECT(MODEL_GOOMBA_2D, -2380, 1064, -13146, 0, -90, 0, bhv2DEnemy)
            COMIT_OBJECT(MODEL_GOOMBA_2D, -2967, 1226, -13146, 0, -90, 0, bhv2DEnemy)
            COMIT_OBJECT(MODEL_GOOMBA_2D, -3247, 1226, -13146, 0, -90, 0, bhv2DEnemy)
            COMIT_OBJECT(MODEL_GOOMBA_2D, -3538, 1226, -13146, 0, -90, 0, bhv2DEnemy)
            COMIT_OBJECT(MODEL_GOOMBA_2D, -3827, 1226, -13146, 0, -90, 0, bhv2DEnemy)
            COMIT_OBJECT(MODEL_GOOMBA_2D, -4117, 1226, -13146, 0, -90, 0, bhv2DEnemy)
            COMIT_OBJECT(MODEL_NONE, -1627, 1591, -13146, 0, -90, 0, bhvBulletBill2dSpawner)
            obj->oBehParams2ndByte = 1;
            COMIT_OBJECT(MODEL_NONE, -4875, 1383, -13146, 0, 90, 0, bhvBulletBill2dSpawner)
            obj->oBehParams2ndByte = 2;
            COMIT_OBJECT(MODEL_NONE, -5485, 518, -13146, 0, 90, 0, bhvBulletBill2dSpawner)
            obj->oBehParams2ndByte = 2;
		    COMIT_OBJECT(MODEL_TOKEN, -3454, 630, -13146, 0, -180, 0, bhvToken)
            obj->oBehParams = 22 << 8;
            break;
        case 2:
            COMIT_OBJECT(MODEL_NONE, -1649, 1270, -13146, 0, -90, 0, bhvBulletBill2dSpawner)
            obj->oBehParams2ndByte = 1;
            COMIT_OBJECT(MODEL_NONE, -4982, 455, -13146, 0, 90, 0, bhvBulletBill2dSpawner)
            obj->oBehParams2ndByte = 2;
            COMIT_OBJECT(MODEL_GOOMBA_2D, -4401, 317, -13146, 0, -90, 0, bhv2DEnemy)
            COMIT_OBJECT(MODEL_GOOMBA_2D, -2508, 952, -13146, 0, -90, 0, bhv2DEnemy)
            COMIT_OBJECT(MODEL_GOOMBA_2D, -2356, 952, -13146, 0, -90, 0, bhv2DEnemy)
            COMIT_OBJECT(MODEL_GOOMBA_2D, -4547, 952, -13146, 0, -90, 0, bhv2DEnemy)
            COMIT_OBJECT(MODEL_GOOMBA_2D, -2512, 317, -13146, 0, -90, 0, bhv2DEnemy)
            COMIT_OBJECT(MODEL_GOOMBA_2D, -3068, 1170, -13146, 0, -90, 0, bhv2DEnemy)
            COMIT_OBJECT(MODEL_GOOMBA_2D, -4553, 317, -13146, 0, -90, 0, bhv2DEnemy)
            COMIT_OBJECT(MODEL_GOOMBA_2D, -1707, 635, -13146, 0, -90, 0, bhv2DEnemy)
            COMIT_OBJECT(MODEL_GOOMBA_2D, -3872, 1170, -13146, 0, -90, 0, bhv2DEnemy)
            COMIT_OBJECT(MODEL_GOOMBA_2D, -3599, 1170, -13146, 0, -90, 0, bhv2DEnemy)
            COMIT_OBJECT(MODEL_KOOPA_2D, -4396, 952, -13146, 0, -90, 0, bhv2DEnemy)
            COMIT_OBJECT(MODEL_KOOPA_2D, -2361, 317, -13146, 0, -90, 0, bhv2DEnemy)
            COMIT_OBJECT(MODEL_KOOPA_2D, -2055, 635, -13146, 0, -90, 0, bhv2DEnemy)
            COMIT_OBJECT(MODEL_KOOPA_2D, -3331, 1170, -13146, 0, -90, 0, bhv2DEnemy)
            COMIT_OBJECT(MODEL_KOOPA_2D, -4932, 635, -13146, 0, -90, 0, bhv2DEnemy)
            COMIT_OBJECT(MODEL_KOOPA_2D, -5132, 635, -13146, 0, -90, 0, bhv2DEnemy)
            break;
    }
}


//put the increment at the end of case 1, break; away with there are goombas - have case 0 only check koopas and fall through to case 1

void check_theater_arena(s16 *arena) {
    struct Object *obj;
    s16 count = count_objects_with_behavior(bhv2DEnemy);
    switch (*arena) {
        case 0:
            if (count == 0) {
                *arena = *arena + 1;
                o->oAction = 1;
            } else if (count <= 4) {
                o->os16F6 = 1;
            }
            break;
        case 1:
            if (count == 0) {
                *arena = *arena + 1;
                o->oAction = 1;
            } else if (count <= 5) {
                o->os16F6 = 2;
            }
            break;
        case 2:
            if (count == 0) {
                *arena = *arena + 1;
                COMIT_OBJECT(MODEL_BOOMBOOM_2D, -3454, 2200, -13146, 0, -90, 0, bhv2DBoomBoom)
            } else if (count <= 8) {
                o->os16F6 = 3;
            }
            break;
        case 3:
            if (cur_obj_nearest_object_with_behavior(bhv2DBoomBoom) == NULL) {
                o->oAction = 4;
            }
            break;
    }
}


void bhv_theater_screen_init(void) {
    o->oOpacity = 254;
}


void bhv_theater_screen_loop(void) {
    struct MarioState *m = gMarioState;
    struct Object *obj;
    switch (o->oAction) {
        case 0:
            if (o->oRoom == gMarioCurrentRoom) {
                if (o->oTimer == 1) {
                    // spawn_theater_arena(0);
                    o->oObjF8 = COMIT_OBJECT(MODEL_THEATER_ARENA, -3454, -533, -13396, 0, 0, 0, bhvTheaterArena)
                }
            } else {
                o->oTimer = 0;
            }
            if (m->pos[2] < o->oPosZ) {
                o->oAction = 1;
                gCamera->comit2dcam = 3;
            }
            break;
        case 1:
            gCamera->comit2dcam = 3;
            if (o->oSubAction == 0) {
                cur_obj_unhide();
                o->oOpacity = approach_s16_symmetric(o->oOpacity, 255, 0x10);
                if ((obj = cur_obj_nearest_object_with_behavior(bhvYellowCoin)) != NULL) {
                    vec3f_copy(&obj->oPosX, gMarioState->pos);
                }
                if (o->oOpacity == 255) {
                    if (o->oTimer > 30) {
                        o->oSubAction = 1;
                        vec3f_copy(m->pos, sTheaterRespawn[o->os16F4]);
                        set_mario_action(m, ACT_JUMP_LAND_STOP, 0);
                        if (o->os16F4 != 0) {
                            if (o->oObjF8) {
                                o->oObjF8->activeFlags = 0;
                            }
                            o->oObjF8 = COMIT_OBJECT(MODEL_THEATER_ARENA, -3454, -533, -13396, 0, 0, 0, bhvTheaterArena)
                            o->oObjF8->oBehParams2ndByte = o->os16F4;
                        }
                    }
                } else {
                    o->oTimer = 0;
                }
            } else {
                o->oOpacity = approach_s16_symmetric(o->oOpacity, 0, 0x8);
                if (o->oOpacity == 0) {
                    cur_obj_hide();
                    o->oAction = 2;
                }
            }
            break;
        case 2:
            gCamera->comit2dcam = 3;
            check_theater_arena(&o->os16F4);

            if (o->os16F6 != o->os16FC) {
                obj = spawn_object(o, MODEL_SHYGUY, bhvTomatoThrower);
                obj->oBehParams2ndByte = o->os16FC;
                o->os16FC++;// = o->os16F6;
            }

            if (m->pos[1] < -500.0f) {
                if (m->health < 0x300) {
                    level_trigger_warp(m, WARP_OP_WARP_FLOOR);
                    o->oAction = 4;
                    o->oOpacity = 254;
                    cur_obj_unhide();
                } else {
                    o->oAction = 3;
                }
            }
            break;
        case 3:
            gCamera->comit2dcam = 3;
            switch (o->oTimer) {
                case 0:
                    play_transition(WARP_TRANSITION_FADE_INTO_COLOR, 0xC, 0x00, 0x00, 0x00);
                    break;
                case 9:
                    vec3f_copy(m->pos, sTheaterRespawn[o->os16F4]);
                    // CL_set_camera_pos(sTheaterRespawn[o->os16F4], sTheaterRespawn[o->os16F4]);
                    // angle = (m->faceAngle[1] = mario_angle_to_object(m, o));
                    // s8DirModeYawOffset = (s16)(angle & 0xC000) - 0x4000;
                    set_mario_action(m, ACT_JUMP_LAND_STOP, 0);
                    break;
                case 12:
                        play_transition(WARP_TRANSITION_FADE_FROM_COLOR, 5, 0x00, 0x00, 0x00);
                        m->hurtCounter = 8;
                        o->oAction = 2;
                    break;
            }
            break;
        case 4:
            gCamera->comit2dcam = 3;
            if (o->oTimer == 90) {
                sDelayedWarpOp = 0x10;
                sDelayedWarpTimer = 20;
                sSourceWarpNodeId = 0x26;
                music_changed_through_warp(sSourceWarpNodeId);
                play_transition(WARP_TRANSITION_FADE_INTO_COLOR, 0xC, 0x00, 0x00, 0x00);
            } else if (o->oTimer >= 90) {
                o->oOpacity = approach_s16_symmetric(o->oOpacity, 255, 0x10);
                if (o->oOpacity == 255) {
                    o->activeFlags = 0;
                    obj = spawn_object(o, MODEL_THEATER_SCREEN, bhvTheaterScreenPost);
                    obj->oFlags &= ~OBJ_FLAG_DISABLE_ON_ROOM_EXIT;
                    while ((obj = cur_obj_nearest_object_with_behavior(bhvBulletBill2dSpawner)) != NULL) {
                        obj->activeFlags = 0;
                    }
                    while ((obj = cur_obj_nearest_object_with_behavior(bhvTomato)) != NULL) {
                        obj->activeFlags = 0;
                    }
                    while ((obj = cur_obj_nearest_object_with_behavior(bhvTomatoThrower)) != NULL) {
                        obj->activeFlags = 0;
                    }
                    while ((obj = cur_obj_nearest_object_with_behavior(bhvSittingShyguy)) != NULL) {
                        obj->activeFlags = 0;
                    }
                }
            }
            break;
    }
}


void bhv_bulletbill_2d_init(void) {
    obj_set_hitbox(o, &s2DBulletBillHitbox);
    o->oForwardVel = 20.0f;
    o->hitboxDownOffset = -50.0f;
}

void bhv_bulletbill_2d_loop(void) {
    switch (o->oAction) {
        case 0:
            cur_obj_update_floor_and_walls();
            cur_obj_move_standard(-78);
            if (o->oMoveFlags & OBJ_MOVE_HIT_WALL || o->oInteractStatus & INT_STATUS_INTERACTED || o->oTimer > 180) {
                if (o->oInteractStatus & INT_STATUS_WAS_ATTACKED) {
                    o->oAction = 1;
                    o->oVelY = 7.0f;
                } else {
                    o->activeFlags = 0;
                    spawn_mist_particles();
                }
            }
            break;
        case 1:
            o->oFloatF4 += 0.4f;
            o->oFaceAnglePitch += 0x40;
            o->oVelY = approach_f32_symmetric(o->oVelY, -40.0f, o->oFloatF4);
            o->oPosZ = approach_f32_asymptotic(o->oPosZ, -13145.0f + 150.0f, 0.1f);
            o->oForwardVel = approach_f32_asymptotic(o->oForwardVel, 0.0f, 0.1f);
            CL_Move();
            if (o->oPosY < -800.0f) {
                o->activeFlags = 0;
            }
            break;
    }
}


void bhv_bulletbill_2d_spawner_loop(void) {
    if (absf(o->oPosY - gMarioState->pos[1]) < 500.0f) {
        if (o->oTimer > 45 * o->oBehParams2ndByte) {
            spawn_object(o, MODEL_BULLETBILL_2D, bhvBulletBill2d);
            o->oTimer = 0;
        }
    } else {
        o->oTimer = 0;
    }
}


void bhv_2d_boomboom_init(void) {
    obj_set_hitbox(o, &s2DBoomBoomHitbox);
    o->oForwardVel = 5.0f;
    if (gMarioState->pos[0] > -3450.0f) {
        o->oPosX = -4000.0f;
    } else {
        o->oPosX = -2900.0f;
    }
}

void bhv_2d_boomboom_loop(void) {
    cur_obj_update_floor_and_walls();
    cur_obj_move_standard(-78);
    switch (o->oAction) {
        case 0:
            if (o->oPosX - gMarioState->pos[0] > 0) {
                o->oMoveAngleYaw = 0xC000;
                if (o->os16F4 == 0) {
                    o->os16F4 = 1;
                    o->oForwardVel = 5.0f;
                    o->oFloatF8 = 0.0f;
                }
            } else {
                o->oMoveAngleYaw = 0x4000;
                if (o->os16F4) {
                    o->os16F4 = 0;
                    o->oForwardVel = 5.0f;
                    o->oFloatF8 = 0.0f;
                }
            }
            if (o->oMoveFlags & OBJ_MOVE_LEFT_GROUND) {
                if (o->oPosX - o->oHomeX > 0) {
                    o->oMoveAngleYaw = 0xC000;
                } else {
                    o->oMoveAngleYaw = 0x4000;
                }
            }
            o->oFloatF8 = approach_f32_symmetric(o->oFloatF8, 1.0f, 0.08f);
            o->oForwardVel = approach_f32_symmetric(o->oForwardVel, 13.0f, o->oFloatF8);

            if (o->oTimer & 0x8) {
                o->oAnimState = (o->oAnimState & 1) ^ 1;
                o->oTimer = 0;
            }

            if (o->oHealth < 3) {
                if (o->oDistanceToMario > 500.0f) {
                    if (++o->os16F6 > 25) {
                        o->oAction = 1;
                        o->oAnimState = 2;
                        o->oInteractType = INTERACT_DAMAGE;
                        o->oForwardVel = 0.0f;
                        o->os16F6 = 0;
                    }
                } else {
                    o->os16F6 = 0;
                }
            }

            if (o->oInteractStatus & INT_STATUS_INTERACTED && o->oInteractStatus & INT_STATUS_WAS_ATTACKED) {
                if (--o->oHealth <= 0) {
                    spawn_mist_particles();
                    obj_spawn_loot_yellow_coins(o, o->oNumLootCoins, 20.0f);
                    o->activeFlags = 0;
                    create_sound_spawner(SOUND_OBJ_DYING_ENEMY1);
                } else {
                    o->oAction = 1;
                    o->oAnimState = 2;
                    o->oInteractType = INTERACT_DAMAGE;
                    o->oForwardVel = 0.0f;
                    o->os16F6 = 0;
                }
            }

            break;
        case 1:
            if (o->oAnimState < 4) {
                if (o->oTimer & 0x4) {
                    o->oAnimState++;
                    o->oTimer = 0;
                }
            }
            if (o->oTimer > 20) {
                o->oVelY = 48.0f;
                o->oForwardVel = 25.0f;
                o->oAction = 0;
                o->oAnimState = 2;
                o->oFloatF8 = 0.0f;
                o->oInteractType = INTERACT_BOUNCE_TOP;
            }
            break;
    }
    if (o->oPosX > -2900.0f) {
        o->oPosX = -2900.0f;
    } else if (o->oPosX < -4000.0f) {
        o->oPosX = -4000.0f;
    }
    o->oInteractStatus = 0;
}


void bhv_2d_enemy_init(void) {
    obj_set_hitbox(o, &s2DEnemyHitbox);
    o->oForwardVel = 8.0f;

    // o->oRoom = o->parentObj->oRoom;
}

void bhv_2d_enemy_loop(void) {
    cur_obj_update_floor_and_walls();
    cur_obj_move_standard(-78);
    if (o->oMoveFlags & OBJ_MOVE_HIT_EDGE || cur_obj_dist_to_nearest_object_with_behavior(bhv2DEnemy) < 100.0f) {
        o->oForwardVel *= -1;
        if (cur_obj_has_model(MODEL_KOOPA_2D)) {
            o->oFaceAngleYaw += 0x8000;
        }
        cur_obj_move_standard(-78);
    }
    if (o->oTimer & 0x10) {
        o->oAnimState ^= 1;
        o->oTimer = 0;
    }
    if (o->oInteractStatus & INT_STATUS_INTERACTED && o->oInteractStatus & INT_STATUS_WAS_ATTACKED) {
            spawn_mist_particles();
            obj_spawn_loot_yellow_coins(o, o->oNumLootCoins, 20.0f);
            o->activeFlags = 0;
            create_sound_spawner(SOUND_OBJ_DYING_ENEMY1);
    }
    o->oInteractStatus = 0;
}