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

Vec3s sLegoColors[] = {
{0xFF, 0xFF, 0xFF},
{0x19, 0x6A, 0x19},
{0xB9, 0x00, 0x03},
};


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
                count = count_objects_with_behavior(bhvPoundLego);
                if (count != 1) {
                    spawn_orange_number(6 - count, 0, 50, 0);
                } else {
                    spawn_default_star(13610.0f, -460.0f, 8520.0f);
                }
                play_sound(SOUND_MENU_COLLECT_SECRET + (((u8) 6 - count) << 16),
                    gGlobalSoundSource);
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
    o->os16F4 = sLegoColors[o->oBehParams2ndByte][0];
    o->os16F6 = sLegoColors[o->oBehParams2ndByte][1];
    o->os16F8 = sLegoColors[o->oBehParams2ndByte][2];

    o->oPosX += 1000.0f;
    o->oPosY += 1000.0f;
    o->oPosZ += 1000.0f;
    vec3f_copy(&o->oFloatFC, &o->oPosX);
}

void bhv_lego_piece_loop(void) {
    f32 dist;
    s16 pitch, yaw;
    switch (o->oAction) {
        case 0:
            o->oFaceAngleYaw += 0x200;
            o->oFaceAngleRoll += 0x200;
            o->oFaceAnglePitch += 0x200;

            CL_dist_between_points(&o->oHomeX, gMarioState->pos, &dist);
            if (dist < 1500.0f) {
                o->oAction = 1;
                o->oForwardVel = 100.0f;
            }
            break;
        case 1:
            o->oFaceAngleYaw = approach_s16_symmetric(o->oFaceAngleYaw, 0, 0x800);
            o->oFaceAngleRoll = approach_s16_symmetric(o->oFaceAngleRoll, 0, 0x800);
            o->oFaceAnglePitch = approach_s16_symmetric(o->oFaceAnglePitch, 0, 0x800);

            vec3f_get_dist_and_angle(&o->oPosX, &o->oHomeX, &dist, &pitch, &yaw);
            o->oMoveAnglePitch = pitch;
            o->oMoveAngleYaw = yaw;
            CL_Move_3d();
            if (dist < 100.0f) {
                vec3f_copy(&o->oPosX, &o->oHomeX);
                o->oFaceAngleYaw = (o->oFaceAngleRoll = (o->oFaceAnglePitch = 0));
                o->oMoveAngleYaw = (o->oMoveAngleRoll = (o->oMoveAnglePitch = 0));
                o->oAction = 2;
                o->oForwardVel = 0; 
                o->oVelX = (o->oVelZ = 0);
            }
            break;
        case 2:
            if (o->oDistanceToMario > 2000.0f && gMarioObject->platform != o) {
                o->oAction = 3;
                o->oForwardVel = 100.0f;
            }
            load_object_collision_model();
            break;
        case 3:
            o->oFaceAngleYaw += 0x200;
            o->oFaceAngleRoll += 0x200;
            o->oFaceAnglePitch += 0x200;

            vec3f_get_dist_and_angle(&o->oPosX, &o->oFloatFC, &dist, &pitch, &yaw);
            o->oMoveAnglePitch = pitch;
            o->oMoveAngleYaw = yaw;
            CL_Move_3d();
            if (dist < 100.0f) {
                vec3f_copy(&o->oPosX, &o->oFloatFC);
                o->oAction = 0;
                o->oForwardVel = 0;
                o->oVelX = (o->oVelZ = 0);
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