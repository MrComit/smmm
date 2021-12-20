#include "levels/ccm/header.h"
s32 obj_check_attacks(struct ObjectHitbox *hitbox, s32 attackedMarioAction);
void obj_compute_vel_from_move_pitch(f32 speed);
static struct ObjectHitbox sLevelEntranceHitbox = {
    /* interactType: */ INTERACT_BBH_ENTRANCE,
    /* downOffset: */ 0,
    /* damageOrCoinValue: */ 0,
    /* health: */ 0,
    /* numLootCoins: */ 0,
    /* radius: */ 120,
    /* height: */ 300,
    /* hurtboxRadius: */ 0,
    /* hurtboxHeight: */ 0,
};

struct ObjectHitbox sCannonBallHitbox = {
    /* interactType:      */ INTERACT_SNUFIT_BULLET,
    /* downOffset:        */ 50,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 100,
    /* height:            */ 50,
    /* hurtboxRadius:     */ 100,
    /* hurtboxHeight:     */ 50,
};

Vec3s sLegoColors[] = {
{0xFF, 0xFF, 0xFF},
{0x19, 0x6A, 0x19},
{0xB9, 0x00, 0x03},
{0x21, 0x72, 0xB5},
{0xB5, 0x5E, 0x1E},
};


static void const *sCardboardCollision[] = {
    cardboard_wall_collision,
    cardboard_wall_alt_collision,
};


void bhv_cannon_balls_loop(void) {
    if (o->oTimer > 180) {
        o->activeFlags = 0;
    }

    if (o->oGravity == 0.0f) {
        cur_obj_update_floor_and_walls();

        obj_compute_vel_from_move_pitch(80.0f);
        if (obj_check_attacks(&sCannonBallHitbox, 1) != 0) {
            // We hit Mario while he is metal!
            // Bounce off, and fall until the first check is true.
            o->oMoveAngleYaw += 0x8000;
            o->oForwardVel *= 0.05f;
            o->oVelY = 30.0f;
            o->oGravity = -4.0f;

            cur_obj_become_intangible();
        } else if (o->oAction == 1 
                || (o->oMoveFlags & (OBJ_MOVE_MASK_ON_GROUND | OBJ_MOVE_HIT_WALL))) {
            o->oDeathSound = -1;
            obj_die_if_health_non_positive();
        }

        cur_obj_move_standard(78);
    } else {
        cur_obj_move_using_fvel_and_gravity();
    }
}



void bhv_shyguy_boss_init(void) {
    obj_set_hitbox(o, &sShyguyHitbox);
    o->oOpacity = 0xFF;
}

void bhv_shyguy_boss_loop(void) {


}



void bhv_racecar_init(void) {
    o->oForwardVel = 25.0f;
    o->oF4 = o->oFaceAngleYaw;
    o->oFloatF8 = (o->oBehParams >> 24) * 100.0f;
}


void bhv_racecar_loop(void) {
    cur_obj_update_floor_and_walls();
    cur_obj_move_standard(78);
    //CL_Move();
    if (cur_obj_lateral_dist_to_home() > o->oFloatF8) {
        o->oF4 = o->oMoveAngleYaw + 0x8000;
        vec3f_copy(&o->oHomeX, &o->oPosX);
    }
    o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oF4, 0x400);
}




void bhv_cardboard_wall_init(void) {
    o->collisionData = segmented_to_virtual(sCardboardCollision[o->oBehParams2ndByte]);
}


void bhv_cardboard_wall_loop(void) {
    struct Object *obj;
    switch (o->oAction) {
        case 0:
            obj = cur_obj_nearest_object_with_behavior(bhvGenericSwitch);
            if (obj == NULL || obj->oF4) {
                if (o->oBehParams >> 24)
                    o->oAction = 2;
                else
                    o->oAction = 3;

            }
            break;
        case 1:
            o->os16F4 += 4;
            o->os16F4 = approach_s16_symmetric(o->os16F4, 0x800, o->os16F4 / 10);
            o->oFaceAngleRoll = approach_s16_symmetric(o->oFaceAngleRoll, 0xC000, o->os16F4);
            if ((s16)o->oFaceAngleRoll == -0x4000) {
                if (o->oBehParams >> 24) {
                    //cur_obj_shake_screen(1);
                    set_camera_shake_from_point(1, gCamera->pos[0], gCamera->pos[1], gCamera->pos[2]);
                    play_puzzle_jingle();
                    o->oAction = 4;
                } else {
                    o->oAction = 5;
                }
            }
            break;
        case 2:
            set_mario_npc_dialog(1);
            gCamera->comitCutscene = 15;
            if (o->oTimer > 25)
                o->oAction = 1;
            break;
        case 3:
            if (o->oTimer > 25)
                o->oAction = 1;
            break;
        case 4:
            if (o->oTimer > 30) {
                set_mario_npc_dialog(0);
                gCamera->comitCutscene = 0;
                o->oAction = 5;
            }
            break;
    }
}



void bhv_garden_mips_init(void) {
    u8 starFlags = save_file_get_currency_flags() & (1 << 1);
    if (!starFlags) {
        o->oBehParams2ndByte = 0;
        o->oMipsForwardVelocity = 50.0f;
    } else {
        o->activeFlags = 0;
    }

    o->oInteractionSubtype = INT_SUBTYPE_HOLDABLE_NPC;
    o->oGravity = -9.0f;
    //o->oFriction = 10.0f;
    //o->oBuoyancy = 1.2f;

    cur_obj_disable();

    cur_obj_init_animation(0);
    o->oObjF4 = cur_obj_nearest_object_with_behavior(bhvPoundLego);
    if (o->oObjF4 == NULL) {
        o->activeFlags = 0;
        return;
    }
    vec3f_copy(&o->oPosX, &o->oObjF4->oPosX);
}

void bhv_garden_mips_run_loop(void) {
    Vec3f pos;
    switch (o->oHeldState) {
        case HELD_FREE:
            if (o->oDistanceToMario > 2000.0f)
                o->oForwardVel = 0;
            else
                o->oForwardVel = 35.0f;
            
            if (o->oTimer > o->os1610A) {
                o->os1610C = CL_RandomMinMaxU16(1, 20);
                o->os1610A = CL_RandomMinMaxU16(30, 120);
            }
            o->os1610E += (0x20 * o->os1610C);
            o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->os1610E - o->oAngleToMario, 0x800);
            cur_obj_update_floor_and_walls();
            pos[1] = o->oPosY;
            pos[0] = o->oPosX + (sins(o->oMoveAngleYaw) * 100.0f);
            pos[2] = o->oPosZ + (coss(o->oMoveAngleYaw) * 100.0f);
            if (f32_find_wall_collision(&pos[0], &pos[1], &pos[2], 10.0f, 50.f)) {
                o->oPosY += 50.0f;
                cur_obj_reflect_move_angle_off_wall();
            }
            cur_obj_move_standard(0);

            if (o->oPosX < 9400.0f) {
                o->oPosX = 9400.0f;
            } else if (o->oPosX > 17600.0f) {
                o->oPosX = 17600.0f;
            }
            if (cur_obj_check_if_near_animation_end() == TRUE) {
                cur_obj_play_sound_2(SOUND_OBJ_MIPS_RABBIT);
            }
            break;
        case HELD_HELD:
            bhv_mips_held();
            break;
        case HELD_THROWN:
            bhv_mips_thrown();
            o->os16FA = 0;
            break;
        case HELD_DROPPED:
            bhv_mips_dropped();
            o->os16FA = 0;
            break;
    }
}


void bhv_garden_mips_loop(void) {
    Vec3f pos;
    struct Surface *floor;
    if (o->os16FA) {
        bhv_garden_mips_run_loop();
        //bhv_mips_act_idle();
        return;
    }
    switch (o->oAction) {
        case 0:
            if (o->oObjF4->activeFlags == 0) {
                if (o->os16110 >= 4) {
                    o->os16FA = 1;
                    o->oAction = 0;
                    o->oForwardVel = 35.0f;
                    o->oInteractType = INTERACT_GRABBABLE;
                    cur_obj_enable();
                    break;
                }
                o->oAction = 1;
                cur_obj_enable();
                cur_obj_init_animation(1);
                o->oForwardVel = 70.0f;
                o->oObjF4 = cur_obj_nearest_object_with_behavior(bhvPoundLego);
                if (o->oObjF4 != NULL)
                    o->oMoveAngleYaw = obj_angle_to_object(o, o->oObjF4);
                break;
            }
            o->os16F8 += 0x400;
            o->oObjF4->oPosX = o->oObjF4->oHomeX + (sins(o->os16F8) * 3.0f);
            o->oObjF4->oPosZ = o->oObjF4->oHomeZ + (coss(o->os16F8 * 4) * 2.0f);
            if ((o->oTimer & 7) == 0)
                spawn_mist_particles_variable(1, -60, 4.0f);
            break;
        case 1:
            cur_obj_update_floor_and_walls();
            pos[1] = o->oPosY;
            pos[0] = o->oPosX + (sins(o->oMoveAngleYaw) * 100.0f);
            pos[2] = o->oPosZ + (coss(o->oMoveAngleYaw) * 100.0f);
            if (f32_find_wall_collision(&pos[0], &pos[1], &pos[2], 10.0f, 50.f)) {
                o->oPosY += 50.0f;
            }
            cur_obj_move_standard(0);
            if (o->oTimer > 60) {
                o->oAction = 2;
                o->oForwardVel = 0;
                o->oVelY = 60.0f;
                o->oGravity = -5.0f;
            }
            break;
        case 2:
            CL_Move();
            if (o->oTimer > 10) {
                o->oAction = 0;
                o->os16110++;
                o->oVelY = 0;
                o->oGravity = -9.0f;

                spawn_mist_particles();
                o->oObjF4 = spawn_object(o, MODEL_POUND_LEGO, bhvPoundLego);
                o->oObjF4->oFaceAngleYaw = 0;
                do {
                    o->oObjF4->oPosX = 9200.0f + (8200.0f * random_float());
                    o->oObjF4->oPosZ = -2000.0f + (5200.0f * random_float());
                    o->oObjF4->oPosY = find_floor(o->oObjF4->oPosX, o->oObjF4->oPosY + 5000.0f, o->oObjF4->oPosZ, &floor);
                    vec3f_copy(&o->oObjF4->oHomeX, &o->oObjF4->oPosX);
                    vec3f_copy(&o->oPosX, &o->oObjF4->oHomeX);
                } while (floor->type == SURFACE_GENERAL_USE || 
                        CL_objptr_dist_to_nearest_object_with_behavior(o->oObjF4, bhvPoundLego) < 500.0f);

                cur_obj_disable();
            }
            break;
        case 4:
            cur_obj_init_animation(0);
            spawn_default_star(10668.0f, 379.0f, 729.0f);
            o->oAction = 5;
            o->oInteractType = INTERACT_IGLOO_BARRIER;
            break;
    }
}


void bhv_level_entrance_init(void) {
    obj_set_hitbox(o, &sLevelEntranceHitbox);
}


void bhv_level_entrance_loop(void) {
    if (o->oBehParams >> 24) {
        if (!(save_file_get_newflags(0) & SAVE_NEW_FLAG_UNLOCKED_PLAYSET)) {
            o->activeFlags = 0;
        }
    }
}


void bhv_pound_lego_loop(void) {
    s16 count;
    switch (o->oAction) {
        case 0:
            if (cur_obj_is_mario_ground_pounding_platform()) {
                o->oAction = 1;
            }
            break;
        case 1:
            o->oPosY -= 20.0f;
            if (o->oPosY < o->oHomeY - 100.0f) {
                spawn_mist_particles();
                o->activeFlags = 0;
                /*count = count_objects_with_behavior(bhvPoundLego);
                if (count != 1) {
                    spawn_orange_number(6 - count, 0, 50, 0);
                } else {
                    spawn_default_star(13610.0f, -460.0f, 8520.0f);
                }
                play_sound(SOUND_MENU_COLLECT_SECRET + (((u8) 6 - count) << 16),
                    gGlobalSoundSource);*/
            }
            break;
    }
}


void bhv_shaky_plat_loop(void) {
    switch (o->oAction) {
        case 0:
            if (gMarioObject->platform == o) {
                o->oAction = 1;
            }
            break;
        case 1:
            o->oFaceAnglePitch += o->oTimer & 1 ? 0x100 : -0x100;
            if (o->oTimer > 20) {
                o->oAction = 2;
                play_sound(SOUND_GENERAL_CLAM_SHELL3, o->header.gfx.cameraToObject);
            } 
            break;
        case 2:
            o->oFaceAnglePitch = approach_s16_symmetric(o->oFaceAnglePitch, 0x4000, 0x800);
            if (o->oTimer > 60) {
                o->oAction = 3;
            }
            break;
        case 3:
            o->oFaceAnglePitch = approach_s16_symmetric(o->oFaceAnglePitch, 0, 0x300);
            if (o->oFaceAnglePitch == 0) {
                o->oAction = 0;
            }
            break;
    }
}



void bhv_lego_piece_init(void) {
    s16 param = CL_RandomMinMaxU16(0, 4);
    o->os16F4 = sLegoColors[param][0];
    o->os16F6 = sLegoColors[param][1];
    o->os16F8 = sLegoColors[param][2];

    o->oPosX += (random_float() - 0.5f) * 2000.0f;
    o->oPosY += 1000.0f;
    o->oPosZ += (random_float() - 0.5f) * 2000.0f;
    vec3f_copy(&o->oFloatFC, &o->oPosX);

    o->os1610C = o->oFaceAngleYaw;
    o->os16110 = o->oFaceAnglePitch;

    o->oFaceAngleYaw = random_u16();
    o->oFaceAnglePitch = random_u16();
}

void bhv_lego_piece_loop(void) {
    f32 dist;
    s16 pitch, yaw;
    switch (o->oAction) {
        case 0:
            o->oFaceAngleYaw += 0x200;
            o->oFaceAnglePitch += 0x200;

            if (o->oTimer > 60) {
                o->os1610E = CL_RandomMinMaxU16(0x40, 0x100);
                o->oTimer = 0;
            }
            o->os16112 = approach_s16_symmetric(o->os16112, o->os1610E, 0x10);
            o->os16FA += o->os16112;
            o->oPosX = o->oFloatFC + sins(o->os16FA) * 200.0f;
            o->oPosZ = o->oFloat104 + coss(o->os16FA) * 100.0f;


            if (gMarioState->pos[1] > o->oHomeY + 1000.0f)
                o->oFloat100 = o->oHomeY - 1000.0f;
            else
                o->oFloat100 = o->oHomeY + 1000.0f;
            o->oPosY = approach_f32_symmetric(o->oPosY, o->oFloat100, 50.0f);

            CL_dist_between_points(&o->oHomeX, gMarioState->pos, &dist);
            if (dist < 2500.0f) {
                o->oFloatFC = o->oPosX;
                o->oFloat104 = o->oPosZ;
                o->oAction = 1;
                o->os16FA = o->os16112 = 0;
                vec3f_get_dist_and_angle(&o->oPosX, &o->oHomeX, &dist, &pitch, &yaw);
                o->oForwardVel = dist / 15.0f;//100.0f;
            }
            break;
        case 1:
            o->oFaceAngleYaw = approach_s16_symmetric(o->oFaceAngleYaw, o->os1610C, 0x800);
            o->oFaceAnglePitch = approach_s16_symmetric(o->oFaceAnglePitch, o->os16110, 0x800);
            o->oFloat108 = approach_f32_symmetric(o->oFloat108, 1.0f, 0.08f);
            cur_obj_scale(o->oFloat108);

            vec3f_get_dist_and_angle(&o->oPosX, &o->oHomeX, &dist, &pitch, &yaw);
            o->oMoveAnglePitch = pitch;
            o->oMoveAngleYaw = yaw;
            CL_Move_3d();
            if (dist < o->oForwardVel) {
                vec3f_copy(&o->oPosX, &o->oHomeX);
                o->oFaceAngleYaw = (o->oMoveAngleYaw = o->os1610C);
                o->oFaceAnglePitch = (o->oMoveAnglePitch = o->os16110);
                o->oAction = 2;
                o->oForwardVel = 0;
                o->oVelX = (o->oVelZ = 0);
                o->oFloat108 = 1.0f;
                cur_obj_scale(o->oFloat108);
            }
            break;
        case 2:
            if (o->oDistanceToMario > 3000.0f && gMarioObject->platform != o) {
                o->oAction = 3;
                o->oFloatFC = o->oHomeX + (random_float() - 0.5f) * 2000.0f;
                o->oFloat104 = o->oHomeZ + (random_float() - 0.5f) * 2000.0f;
                if (gMarioState->pos[1] > o->oHomeY + 1000.0f)
                    o->oFloat100 = o->oHomeY - 1000.0f;
                else
                    o->oFloat100 = o->oHomeY + 1000.0f;
                vec3f_get_dist_and_angle(&o->oPosX, &o->oFloatFC, &dist, &pitch, &yaw);
                o->oForwardVel = dist / 20.0f;
            }
            load_object_collision_model();
            break;
        case 3:
            o->oFaceAngleYaw += 0x200;
            o->oFaceAnglePitch += 0x200;

            o->oFloat108 = approach_f32_symmetric(o->oFloat108, 0.7f, 0.08f);
            cur_obj_scale(o->oFloat108);

            vec3f_get_dist_and_angle(&o->oPosX, &o->oFloatFC, &dist, &pitch, &yaw);
            o->oMoveAnglePitch = pitch;
            o->oMoveAngleYaw = yaw;
            CL_Move_3d();
            if (dist < o->oForwardVel) {
                vec3f_copy(&o->oPosX, &o->oFloatFC);
                o->oAction = 0;
                o->oForwardVel = 0;
                o->oVelX = (o->oVelZ = 0);
                o->oFloat108 = 0.7f;
                cur_obj_scale(o->oFloat108);
            }
            break;
    }

}


void bhv_rubber_band_loop(void) {
    struct MarioState *m = gMarioState;
    switch (o->oAction) {
        case 0:
            if (o->oDistanceToMario < 250.0f) {
                o->oAction = 1; 
                m->faceAngle[1] = o->oMoveAngleYaw; 
                set_mario_action(m, ACT_GRABBED, 0);
            }
            break;
        case 1:
            m->usedObj = o;
            m->interactObj = o;
            vec3f_copy(m->pos, &o->oPosX);
            m->pos[0] += -180.0f * sins(o->oMoveAngleYaw) * o->header.gfx.scale[2];
            m->pos[2] += -180.0f * coss(o->oMoveAngleYaw) * o->header.gfx.scale[2];
            o->header.gfx.scale[2] = approach_f32_asymptotic(o->header.gfx.scale[2], 4.0f, 0.05f);
            vec3f_copy(m->marioObj->header.gfx.pos, m->pos);
            vec3s_set(m->marioObj->header.gfx.angle, 0, m->faceAngle[1], 0);
            if (m->input & INPUT_A_PRESSED) {
                o->oAction = 2;
                //m->faceAngle[0] = 0xF500;
                m->forwardVel = 80.0f;
                m->vel[1] = 30.0f;
                set_mario_action(m, ACT_SHOT_FROM_CANNON, 0);
            }
            if (m->input & INPUT_B_PRESSED) {
                m->vel[1] = 0;
                set_mario_action(m, ACT_THROWN_FORWARD, 0);
                o->oAction = 3;
            }
            break;
        case 2:
            if (o->oTimer > 45) {
                o->oAction = 4;
                sDelayedWarpOp = 0x10;
                sDelayedWarpTimer = 12;
                sSourceWarpNodeId = 0x20;
                music_changed_through_warp(sSourceWarpNodeId);
                play_transition(WARP_TRANSITION_FADE_INTO_COLOR, 0xC, 0x00, 0x00, 0x00);
                if (!(save_file_get_newflags(0) & SAVE_NEW_FLAG_UNLOCKED_PLAYSET)) {
                    save_file_set_newflags(SAVE_NEW_FLAG_UNLOCKED_PLAYSET, 0);
                }
                break;
            }
        case 3:
            if (o->oTimer < 10) {
                //o->header.gfx.scale[2] = approach_f32_asymptotic(o->header.gfx.scale[2], -3.0f, 0.7f);
                o->header.gfx.scale[2] = approach_f32(o->header.gfx.scale[2], -3.0f, 1.0f, 1.0f);
            } else if (o->oTimer < 20) {
                //o->header.gfx.scale[2] = approach_f32_asymptotic(o->header.gfx.scale[2], 1.5f, 0.5f);
                o->header.gfx.scale[2] = approach_f32(o->header.gfx.scale[2], 1.5f, 0.5f, 0.5f);
            } else if (o->oTimer < 45) {
                o->header.gfx.scale[2] = approach_f32_asymptotic(o->header.gfx.scale[2], 1.0f, 0.5f);
            } else if (o->oTimer > 50) {
                o->oAction = 0;
            }
            break;
    }
}