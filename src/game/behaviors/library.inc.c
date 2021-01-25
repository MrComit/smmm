#include "game/camera.h"

struct ObjectHitbox sFlamingBookHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 100,
    /* height:            */ 100,
    /* hurtboxRadius:     */ 100,
    /* hurtboxHeight:     */ 100,
};

Vec3f sKFlamePos[2] = {
{-6824.33f, 1943.89f, 18688.9f},
{-6824.33f, 1943.89f, 15308.9f},
};

Vec3f sKFlameXPos[2] = {
{-7324.33f, -6924.33f, -6524.33f},
{-7124.33f, -6724.33f, -6324.33f},
};


void koopa_boss_multiplier_loop(void) {
    s32 action = FALSE;
    if (gMarioCurrentRoom == o->oRoom)
        gHudDisplay.flags |= (HUD_DISPLAY_FLAG_LOWER);
    //print_text(168+30, 189, "+"); // 'Coin' glyph
    //print_text(184+30, 189, "*"); // 'X' glyph
    //print_text_fmt_int(198+30, 189, "%d", gHudDisplay.booCoins);

    print_text_fmt_int(168+30, 169+20, "%d", (s32)o->oFloat98);
    print_text(184+30, 169+20, ".");
    print_text_fmt_int(198+30, 169+20, "%d", o->o148);
    print_text(212+30, 169+20, "*"); // 'X' glyph

    if (gMarioState->action == ACT_BURNING_FALL || gMarioState->action == ACT_BURNING_JUMP 
        || gMarioState->action == ACT_BURNING_GROUND) {
        if (o->oKleptoTimeUntilTargetChange == 0) {
            action = TRUE;
            o->oKleptoTimeUntilTargetChange = 1;
        }
    } else {
        o->oKleptoTimeUntilTargetChange = 0;
        action = FALSE;
    }
    if (((gMarioState->hurtCounter > 0 && o->o14A == 0) || action) && o->oFloat98 > 0) {
        if (o->o148 == 0) {
            o->oFloat98 -= 1.0f;
            o->o148 = 5;
        } else {
            o->o148 = 0;
        }
        o->o14A = 1;
    } else if (gMarioState->hurtCounter <= 0) {
        o->o14A = 0;
    }


}


void koopa_boss_move(void) {
    o->oF8 += 0x180;
    o->oPosZ = 17400.0f + (sins(o->oF8 & ~1) * 1300.0f);
}

void koopa_boss_clamp_mario(void) {
    struct MarioState *m = gMarioState;
    if (gMarioCurrentRoom != o->oRoom) {
        return;
    }
    switch (o->oF8 & 1) {
        case 0:
            if (m->pos[2] > 15630.0f) {
                m->pos[2] = 15630.0f;
            }
            if (m->pos[0] > -7300.0f)
                o->oF8 |= 1;
            break;
        case 1:
            if (m->pos[0] < -7300.0f) {
                m->pos[0] = -7300.0f;
            }
            break;
    }
}

void bhv_koopa_boss_init(void) {
    o->oHealth = 2;
    o->oFloat98 = 5.0f;
}


void bhv_koopa_boss_loop(void) {
    struct Object *obj;
    koopa_boss_clamp_mario();
    koopa_boss_multiplier_loop();
    switch (o->oAction) {
        case 0:
            cur_obj_hide();
            if (gMarioState->pos[2] > 18000.0f && gMarioCurrentRoom == o->oRoom) {
                o->oAction = 1;
                o->oKleptoStartPosZ = 300.0f;
                cur_obj_unhide();
                set_mario_npc_dialog(1);
            }
            break;
        case 1:
            o->oFloatF4 = approach_f32(o->oFloatF4, 1.1f, 0.015f, 0.015);
            cur_obj_scale(o->oFloatF4);
            set_mario_npc_dialog(1);
            o->oGraphYOffset += 11.34825f;
            if (o->oFloatF4 >= 0.8f) {
                o->header.gfx.scale[0] = 0.8f;
                o->header.gfx.scale[2] = 0.8f;
            }
            if (o->oFloatF4 == 1.1f) {
                o->oAction = 2;
                o->oFC = 120;
                cur_obj_init_animation_with_sound(1);
                set_mario_npc_dialog(0);
            }
            break;
        case 2:
            koopa_boss_move();
            if (o->oTimer > o->oFC - 20) {
                cur_obj_init_animation_with_sound(2);
                o->o108 = 1;
            }
            if (o->oTimer > o->oFC) {
                obj = spawn_object(o, MODEL_L1_THIN_BOOK, bhvFlamingBossBook);
                obj->oPosY += 1800.0f;
                obj->oPosX += 600.0f;
                if (o->oBehParams2ndByte) {
                    obj->o100 = 1;
                }
                if (CL_obj_nearest_object_behavior_params(bhvFlamingBossBook, 0x01000000) == NULL) {
                    o->o100 += 1;
                    if (o->o100 >= 5) {
                        obj->oBehParams |= 1 << 24;
                        o->o100 = 0;
                        o->o104 = 1;
                    }
                }
                o->oFC = CL_RandomMinMaxU16(45, 90);
                o->oTimer = 0;
            }
            if (o->o108 && cur_obj_check_if_near_animation_end()) {
                o->o108 = 0;
                cur_obj_init_animation_with_sound(1);
                o->header.gfx.animInfo.animFrame = 10;
            }
            obj = CL_nearest_object_with_behavior_and_field(bhvFlamingBossBook, 0x14C, 2);
            if (obj == NULL) {
                break;
            }
            o->o104 = 0;
            if (lateral_dist_between_objects(o, obj) < o->oKleptoStartPosZ) {
                CL_explode_object(obj, 1);
                if (o->oBehParams2ndByte) {
                    cur_obj_play_sound_2(SOUND_OBJ_ENEMY_DEATH_LOW);
                    if (--o->oHealth > 0) {
                        o->oAction = 3;
                    } else {
                        o->oAction = 4;
                    }
                }
            }
            break;
        case 3:
            if (cur_obj_init_anim_and_check_if_end(5)) {
                o->oAction = 2;
                cur_obj_init_animation_with_sound(1);
                o->header.gfx.animInfo.animFrame = 10;
            }
            break;
        case 4:
            if (cur_obj_init_anim_check_frame(6, 10)) {
                o->oAction = 8;
            }
            break;
        case 5:
            if (cur_obj_init_anim_check_frame(3, 23)) {
                spawn_object_relative(0, 600, 1800, 0, o, MODEL_RED_FLAME, bhvKoopaBossFlame);
                o->oAction = 2;
                cur_obj_init_animation_with_sound(1);
                o->header.gfx.animInfo.animFrame = 10;
            }
            break;
        case 6:
            if (cur_obj_init_anim_check_frame(3, 23)) {
                spawn_object_relative(1, 600, 1800, 0, o, MODEL_RED_FLAME, bhvKoopaBossFlame);
                o->oAction = 2;
                cur_obj_init_animation_with_sound(1);
                o->header.gfx.animInfo.animFrame = 10;
            }
            break;
        case 7:
            if (o->oBehParams2ndByte) {
                if (cur_obj_init_anim_and_check_if_end(4)) {
                    o->oAction = 2;
                    cur_obj_init_anim_and_check_if_end(1);
                    o->header.gfx.animInfo.animFrame = 10;
                }
            }
            break;
        case 8:
            o->oFloatF4 = approach_f32(o->oFloatF4, 0.3f, 0.02f, 0.02f);
            obj_scale_xyz(o, o->oFloatF4 / 1.38f, o->oFloatF4, o->oFloatF4 / 1.38f);

            if (o->oFloatF4 == 0.3f) {
                gMarioState->numCoins += 100 * (o->oFloat98 + ((f32)o->o148 / 10));
                CL_explode_object(o, 1);
                obj = spawn_object(o, MODEL_BOO, bhvRoomBoo);
                obj->oFlags &= ~OBJ_FLAG_DISABLE_ON_ROOM_EXIT;
                obj->oBehParams2ndByte = 4;
                obj->oBehParams = 0x02040100;
            }
            break;
    }
}

void boss_book_flaming_loop(void) {
    struct Object *obj;
    vec3f_copy(&o->oObjF4->oPosX, &o->oPosX);
    if (o->oTimer > 120 || o->oMoveFlags & OBJ_MOVE_HIT_WALL || (o->oFloor != NULL && absf(o->oFloor->upperY - o->oPosY) < 20.0f)) {
        spawn_mist_particles_variable(0, 0, 25.0f);
        spawn_triangle_break_particles(6, 138, 1.0f, 4);
        create_sound_spawner(SOUND_GENERAL_HAUNTED_CHAIR_MOVE);
        o->activeFlags = 0;
        o->oObjF4->activeFlags = 0;
        //o->parentObj->oAction = 1;
        if (o->o100) {
            obj = spawn_object(o, MODEL_RED_FLAME, bhvKoopaBossMiniFlame);
            obj->oMoveAngleYaw = o->oFaceAngleYaw;
            obj = spawn_object(o, MODEL_RED_FLAME, bhvKoopaBossMiniFlame);
            obj->oMoveAngleYaw = o->oFaceAngleYaw + 0x5555;
            obj = spawn_object(o, MODEL_RED_FLAME, bhvKoopaBossMiniFlame);
            obj->oMoveAngleYaw = o->oFaceAngleYaw + 0xAAAA;
        }
    }
}

void sparkling_book_act_1(void) {
    o->oFaceAngleYaw -= 0x800;
    o->oFaceAngleRoll -= 0x800;
    o->oFaceAnglePitch -= 0x800;
    switch (o->oHeldState) {
        case HELD_FREE:
            if (o->oTimer > 10 && o->oDistanceToMario < 150.0f) {
                o->oHeldState = HELD_HELD;
                set_mario_action(gMarioState, ACT_HOLD_IDLE, 0);
                gMarioState->usedObj = o;
                mario_grab_used_object(gMarioState);
                gMarioState->marioBodyState->grabPos = GRAB_POS_LIGHT_OBJ;
            }
            o->oF8++;
            if (o->oF8 > 120) {
                if (o->oF8 & 1)
                    o->header.gfx.node.flags |= GRAPH_RENDER_INVISIBLE;
                else
                    o->header.gfx.node.flags &= ~GRAPH_RENDER_INVISIBLE;
                if (o->oF8 > 150) {
                    o->activeFlags = 0;
                    o->parentObj->o104 = 0;
                }
            }
            break;

        case HELD_HELD:
            cur_obj_become_intangible();
            o->oF8 = 0;
            o->header.gfx.node.flags |= GRAPH_RENDER_INVISIBLE;
            cur_obj_set_pos_relative(gMarioObject, 0, 60.0f, 60.0f);
            break;

        case HELD_THROWN:
            cur_obj_enable_rendering_2();
            cur_obj_become_tangible();

            o->header.gfx.node.flags &= ~GRAPH_RENDER_INVISIBLE;
            //o->oF4 = 1;
            o->oTimer = 0;
            o->oAction = 2;
            o->oHeldState = 0;
            o->oFlags &= ~0x8; /* bit 3 */
            o->oMoveAnglePitch = 0;
            o->oForwardVel = 90.0f;
            //o->oVelY = 20.0;
            break;

        case HELD_DROPPED:
            cur_obj_get_dropped();
            cur_obj_become_tangible();
            o->header.gfx.node.flags &= ~GRAPH_RENDER_INVISIBLE;
            o->oTimer = 0;
            break;
    }
}


void boss_book_sparkling_loop(void) {
    spawn_object(o, MODEL_NONE, bhvSparkleSpawn);
    switch (o->oAction) {
        case 0:

            if (o->oFloor != NULL && absf(o->oFloor->upperY - o->oPosY) < 100.0f) {
                o->oForwardVel = 0;
                o->oVelY = 0;
                o->oMoveAnglePitch = 0;
                o->oAction = 1;
                cur_obj_become_tangible();
            }
            break;
        case 1:
            sparkling_book_act_1();
            break;
        case 2:
            if (o->oTimer > 90 || o->oMoveFlags & OBJ_MOVE_HIT_WALL || o->oInteractStatus & INT_STATUS_INTERACTED) {
                spawn_mist_particles_variable(0, 0, 25.0f);
                spawn_triangle_break_particles(6, 138, 1.0f, 4);
                create_sound_spawner(SOUND_GENERAL_HAUNTED_CHAIR_MOVE);
                o->activeFlags = 0;
                o->parentObj->o104 = 0;
            }
            break;
    }
}



void bhv_flaming_boss_book_loop(void) {
    CL_Move_3d();
    cur_obj_update_floor_and_walls();
    o->oFaceAngleYaw += 0xC00;
    o->oFaceAngleRoll += 0xC00;
    o->oFaceAnglePitch += 0xC00;
    switch (o->oBehParams >> 24) {
        case 0:
            boss_book_flaming_loop();
            break;
        case 1:
            boss_book_sparkling_loop();
            break;
    }
}



void bhv_flaming_boss_book_init(void) {
    s16 pitch, yaw;
    f32 dist;
    Vec3f point;
    obj_set_hitbox(o, &sFlamingBookHitbox);
    if (o->oBehParams >> 24 == 1) {
        o->oInteractType = INTERACT_GRABBABLE;
        cur_obj_become_intangible();
        //o->hitboxDownOffset = 100.0f;
        cur_obj_scale(1.35f);
        o->oForwardVel = 30.0f;
        point[0] = -6824.0f;
        point[1] = 1944.0f;
        if (gMarioState->pos[2] > o->parentObj->oHomeZ)
            point[2] = 16641.0f;
        else
            point[2] = 18177.0f;
    } else {
        vec3f_copy(point, gMarioState->pos);
        point[1] += 15.0f;
        o->oObjF4 = spawn_object(o, MODEL_RED_FLAME, bhvFlameDecoration);
        obj_scale(o->oObjF4, 10.0f);
        o->oForwardVel = 70.0f;
    }
    vec3f_get_dist_and_angle(&o->oPosX, point, &dist, &pitch, &yaw);
    o->oMoveAnglePitch = pitch;
    o->oMoveAngleYaw = yaw;
    o->oBehParams2ndByte = CL_RandomMinMaxU16(0, 2);
}


void bhv_l1_lock_loop(void) {
    struct Object *obj = cur_obj_nearest_object_with_behavior(bhvFlamingBossBook);
    struct Object *obj2 = cur_obj_nearest_object_with_behavior(bhvKoopaBossChandelier);
    if (obj2 == NULL) {
        o->activeFlags = 0;
        return;
    }
    if (obj == NULL) {
        return;
    }
    if (dist_between_objects(o, obj) < 400.0f) {
        obj->activeFlags = 0;
        obj = cur_obj_nearest_object_with_behavior(bhvKoopaBoss);
        obj->o104 = 0;
        obj2->oF4++;
        obj->oAction = 4 + obj2->oF4;
        CL_explode_object(o, 1);
    }

}


void bhv_boss_chandelier_loop(void) {
    struct Object *obj = cur_obj_nearest_object_with_behavior(bhvKoopaBoss);
    if (obj == NULL) {
        o->activeFlags = 0;
        return;
    }
    switch (o->oAction) {
        case 0:
            if (o->oF4 >= 3) {
                o->oAction = 1;
                o->oPosZ = obj->oPosZ;
            }
            break;
        case 1:
            o->oPosY -= 40.0f;
            if (o->oPosY < 2500.0f) {
                CL_explode_object(o, 1);
                obj->oBehParams2ndByte = 1;
                obj->oKleptoStartPosZ = 500.0f;
                cur_obj_play_sound_2(SOUND_OBJ_ENEMY_DEATH_LOW);
                cur_obj_shake_screen(0);
            }
            break;
    }
}


void bhv_koopa_boss_flame_init(void) {
    o->header.gfx.scale[0] = 60.0f;
    o->header.gfx.scale[1] = 40.0f;
    o->header.gfx.scale[2] = 60.0f;

    if (o->oBehParams2ndByte) {
        o->oFaceAngleYaw = 0x1000;
    } else {
        o->oFaceAngleYaw = 0x7000;
    }
}


void koopa_boss_flame_act_2(void) {
    if (o->oTimer > o->oFC) {
        struct Object *obj;
        if (CL_RandomMinMaxU16(1, 15) == 5) {
            obj = spawn_object(o, MODEL_YELLOW_COIN, bhvKoopaBossMovingCoin);
        } else {
            obj = spawn_object(o, MODEL_RED_FLAME, bhvKoopaBossMovingFlame);
        }
        obj->oBehParams2ndByte = o->oBehParams2ndByte;
        o->oTimer = 0;
        o->oFC = CL_RandomMinMaxU16(90, 120);
    }
    o->o104++;
    if (o->o104 > 10 && absf(o->oPosZ - gMarioState->pos[2]) < 200.0f && gMarioState->pos[1] < 2500.0f) {
        CL_Lava_Boost();
        o->o104 = 0;
    }    
}



void bhv_koopa_boss_flame_loop(void) {
    s16 pitch, yaw;
    f32 dist;
    switch (o->oAction) {
        case 0:
            //o->oForwardVel = 70.0f;
            //vec3f_get_dist_and_angle(&o->oPosX, sKFlamePos[o->oBehParams2ndByte], &dist, &pitch, &yaw);
            //o->oMoveAnglePitch = pitch;
            //o->oMoveAngleYaw = yaw;
            o->oAction = 1;
            break;
        case 1:
            //CL_Move_3d();
            //cur_obj_update_floor_and_walls();
            o->oPosX = approach_f32(o->oPosX, sKFlamePos[o->oBehParams2ndByte][0], 40.0f, 40.0f);
            o->oPosY = approach_f32(o->oPosY, sKFlamePos[o->oBehParams2ndByte][1], 20.0f, 20.0f);
            o->oPosZ = approach_f32(o->oPosZ, sKFlamePos[o->oBehParams2ndByte][2], 40.0f, 40.0f);
            if (o->oPosX == sKFlamePos[o->oBehParams2ndByte][0] && o->oPosY == sKFlamePos[o->oBehParams2ndByte][1] && 
            o->oPosZ == sKFlamePos[o->oBehParams2ndByte][2]) {
                o->oAction = 2;
                o->oFC = 30;
            }
            break;
        case 2:
            koopa_boss_flame_act_2();
            break;
    }
    if (o->parentObj->oAction == 8) {
        o->activeFlags = 0;
    }  
}


void bhv_koopa_boss_moving_flame_init(void) {
    s16 num = CL_RandomMinMaxU16(0, 2);
    o->oPosX = sKFlameXPos[o->oBehParams2ndByte][num];
}



void bhv_koopa_boss_moving_flame_loop(void) {
    if (o->oBehParams2ndByte) {
        o->oPosZ += 15.0f;
    } else {
        o->oPosZ -= 15.0f;
    }
    if (o->oTimer > 180) {
        o->activeFlags = 0;
    }
}



void bhv_koopa_boss_mini_flame_loop(void) {
    cur_obj_move_standard(-78);
    o->oVelY -= 1.7f;
    if (o->oTimer > 120 || o->oMoveFlags & OBJ_MOVE_HIT_WALL || o->oInteractStatus & INT_STATUS_INTERACTED ||
    o->oPosY <= 1860.0f) {
        o->activeFlags = 0;
    }
}