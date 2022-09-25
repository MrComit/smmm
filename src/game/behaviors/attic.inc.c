static struct ObjectHitbox sAtticBullyHitbox = {
    /* interactType:      */ INTERACT_BULLY,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 3,
    /* numLootCoins:      */ 0,
    /* radius:            */ 115,
    /* height:            */ 235,
    /* hurtboxRadius:     */ 105,
    /* hurtboxHeight:     */ 225,
};

void bhv_ghost_barrier_init(void) {
    if (gCurrLevelNum == LEVEL_BOB && save_file_get_boos() & (1 << 0x12)) {
        o->activeFlags = 0;
    }
}

void bhv_ghost_barrier_loop(void) {
    if (gCurrLevelNum != LEVEL_HMC) {
        return;
    }
    switch (o->oAction) {
        case 0:
            if (save_file_get_boos() & (1 << 0x12) && set_mario_npc_dialog(1)) {
                o->oAction = 1;
                play_transition(WARP_TRANSITION_FADE_INTO_COLOR, 10, 0x00, 0x00, 0x00);
                vec3f_copy(gComitCutsceneFocVec, &o->oPosX);
                vec3f_set(gComitCutscenePosVec, o->oPosX - 1000.0f, o->oPosY + 350.0f, o->oPosZ - 300.0f);
            }
            break;
        case 1:
            o->header.gfx.node.flags |= GRAPH_RENDER_ACTIVE;
            if (o->oTimer > 5) {
                gCamera->comitCutscene = 0xFF;
            }
            if (o->oTimer > 20) {
                play_transition(WARP_TRANSITION_FADE_FROM_COLOR, 8, 0x00, 0x00, 0x00);
                o->oAction = 2;
            }
            break;
        case 2:
            o->header.gfx.node.flags |= GRAPH_RENDER_ACTIVE;
            gCamera->comitCutscene = 0xFF;
            if (o->oTimer > 25) {
                o->oOpacity = approach_s16_symmetric(o->oOpacity, 0, 0x8);
                if (o->oOpacity == 0) {
                    play_puzzle_jingle();
                    o->oAction = 3;
                }
            }
            break;
        case 3:
            o->header.gfx.node.flags |= GRAPH_RENDER_ACTIVE;
            gCamera->comitCutscene = 0xFF;
            if (o->oTimer > 60) {
                play_transition(WARP_TRANSITION_FADE_INTO_COLOR, 8, 0x00, 0x00, 0x00);
                o->oAction = 4;
            }
            break;
        case 4:
            o->header.gfx.node.flags |= GRAPH_RENDER_ACTIVE;
            if (o->oTimer <= 10) {
                gCamera->comitCutscene = 0xFF;
            }
            if (o->oTimer > 20) {
                o->activeFlags = 0;
                play_transition(WARP_TRANSITION_FADE_FROM_COLOR, 12, 0x00, 0x00, 0x00);
                set_mario_npc_dialog(0);
            }
            break;
    }
}


s32 attic_bounds(void) {
    if (o->oPosX > -79.0f) {
        o->oPosX = -79.0f;
        return TRUE;
    }

    if (o->oPosX < -5079.0f) {
        o->oPosX = -5079.0f;
        return TRUE;
    }

    if (o->oPosZ > 13388.0f) {
        o->oPosZ = 13388.0f;
        return TRUE;
    }

    if (o->oPosZ < 8388.0f) {
        o->oPosZ = 8388.0f;
        return TRUE;
    }
    return FALSE;
}

s32 attic_bounds_flame(void) {
    if (o->oPosX > -579.0f) {
        o->oPosX = -579.0f;
        return TRUE;
    }

    if (o->oPosX < -4579.0f) {
        o->oPosX = -4579.0f;
        return TRUE;
    }

    if (o->oPosZ > 12888.0f) {
        o->oPosZ = 12888.0f;
        return TRUE;
    }

    if (o->oPosZ < 8888.0f) {
        o->oPosZ = 8888.0f;
        return TRUE;
    }
    return FALSE;
}


void bhv_attic_moving_flame_init(void) {
    // o->oForwardVel = 15.0f;
    o->oMoveAngleYaw = CL_RandomMinMaxU16(0, 3) * 0x4000;
    o->oObjFC = cur_obj_nearest_object_with_behavior(bhvAtticBully);
    if (o->oObjFC == NULL) {
        o->activeFlags = 0;
    }
    // o->os16F4 = 0xFF;
    // o->os16F6 = 0;
    // o->os16F8 = 0;
    o->oF4 = 0xFF0000;
    o->oPosY = 5185.0f;
}


//x: -79.0f to -5079.0f
//y: 13388.0f to 8388.0f


void bhv_attic_moving_flame_loop(void) {
    s16 newAngle;
    CL_Move();
    if (cur_obj_lateral_dist_to_home() >= 1000.0f) {
        o->oPosX = o->oHomeX + 1000.0f * sins(o->oMoveAngleYaw);
        o->oPosZ = o->oHomeZ + 1000.0f * coss(o->oMoveAngleYaw);
        vec3f_copy(&o->oHomeX, &o->oPosX);
        do {
            newAngle = CL_RandomMinMaxU16(0, 3) * 0x4000;
        } while (absi(o->oMoveAngleYaw - (u16)newAngle) == 0x8000);
        o->oMoveAngleYaw = newAngle;
    }

    switch (o->oAction) {
        case 0:
            if (o->oTimer < 30) {
                o->os16F4 = approach_s16_symmetric(o->os16F4, 0xFF, 0x7);
                o->os16F6 = approach_s16_symmetric(o->os16F6, 0, 0x6);
                o->os16F8 = approach_s16_symmetric(o->os16F8, 0, 0x8);
                o->oForwardVel = approach_f32_symmetric(o->oForwardVel, 15.0f, 1.0f);
            }
            if (o->oObjFC->oAction == 7) {
                o->oAction = 1;
            }
            break;
        case 1:
            if (o->oTimer < 30) {
                o->os16F4 = approach_s16_symmetric(o->os16F4, 0x20, 0x4);
                o->os16F6 = approach_s16_symmetric(o->os16F6, 0x60, 0x8);
                o->os16F8 = approach_s16_symmetric(o->os16F8, 0xFF, 0x8);
                o->oForwardVel = approach_f32_symmetric(o->oForwardVel, 25.0f, 1.0f);
            }
            if (o->oObjFC->oAction != 7) {
                o->oAction = 0;
            }
            break;
    }

    if (attic_bounds_flame()) {
        o->oMoveAngleYaw = CL_RandomMinMaxU16(0, 3) * 0x4000;
    }
    if (o->oObjFC->activeFlags == 0) {
        o->activeFlags = 0;
    }
}


void bhv_attic_rock_init(void) {
    o->oObj100 = cur_obj_nearest_object_with_behavior(bhvAtticBully);
    if (o->oObj100 == NULL) {
        o->activeFlags = 0;
    }
}


void bhv_attic_rock_loop(void) {
    f32 spireHeight;
    struct Object *obj = cur_obj_nearest_object_with_behavior(bhvAtticSpire);
    if (o->oObj100->oAction == 7 /*&& gMarioObject->platform != o*/) {
        o->oFaceAngleRoll = approach_s16_symmetric(o->oFaceAngleRoll, 0x8000, 0x500);
        if ((u16)o->oFaceAngleRoll != 0x8000 && gMarioObject->platform == o) {
            set_mario_action(gMarioState, ACT_FREEFALL, 0);
            gMarioState->vel[1] = 80.0f;
        }
    } else {
        o->oFaceAngleRoll = approach_s16_symmetric(o->oFaceAngleRoll, 0, 0x500);
    }
    switch (o->oAction) {
        case 0:
            if (obj == NULL) {
                return;
            }
            if (lateral_dist_between_objects(o, obj) < 100.0f) {
                o->oAction = 1;
            }
            break;
        case 1:
            if (obj == NULL) {
                o->oAction = 3;
                o->oVelY = 0;
                o->oFloatF4 = 0;
            }
            spireHeight = obj->oPosY + (obj->header.gfx.scale[1] * 1000.0f);
            if (o->oPosY < spireHeight) {
                // o->oPosY = spireHeight;
                o->oFloatF8 = approach_f32_symmetric(o->oFloatF8, 2.5f + (spireHeight - o->oPosY), 0.5f + (spireHeight - o->oPosY) / 2.0f);
                o->oFloatFC = approach_f32_symmetric(o->oFloatFC, 70.0f, o->oFloatF8);
                o->oPosY = approach_f32_symmetric(o->oPosY, spireHeight, o->oFloatFC);

                o->oVelY = 0;
                o->oFloatF4 = 0;
            } else {
                o->oFloatF4 = approach_f32_symmetric(o->oFloatF4, 2.5f, 0.1f);
                o->oVelY = approach_f32_symmetric(o->oVelY, 70.0f, o->oFloatF4);
                o->oPosY = approach_f32_symmetric(o->oPosY, o->oHomeY, o->oVelY);
                o->oFloatF8 = 0;
                o->oFloatFC = 0;
                if (o->oPosY == o->oHomeY) {
                    o->oAction = 0;
                    o->oVelY = 0;
                    o->oFloatF4 = 0;
                }
            }
            break;
        case 3:
            o->oFloatF4 = approach_f32_symmetric(o->oFloatF4, 2.5f, 0.1f);
            o->oVelY = approach_f32_symmetric(o->oVelY, 70.0f, o->oFloatF4);
            o->oPosY = approach_f32_symmetric(o->oPosY, o->oHomeY, o->oVelY);
            if (o->oPosY == o->oHomeY) {
                o->oAction = 0;
                o->oVelY = 0;
            }
            break;
    }
}


void bhv_bully_flame_init(void) {
    o->os16F4 = 0x20;
    o->os16F6 = 0x60;
    o->os16F8 = 0xFF;
    o->oFloat100 = 0.1f;
}


void bhv_bully_flame_loop(void) {
    vec3f_copy(&o->oPosX, &o->oObjFC->oPosX);
    o->oFloat100 = approach_f32_symmetric(o->oFloat100, 15.0f, 0.5f);
    cur_obj_scale(o->oFloat100);
}


s16 sBullyBool = 0;
s16 sBullyFraction = 0;
f32 sBullyMultiplier = 0.0f;


void bully_boss_multiplier_loop(void) {
    s32 action = FALSE;
    if (gMarioCurrentRoom == o->oRoom)
        gHudDisplay.flags |= (HUD_DISPLAY_FLAG_LOWER);

    print_text_fmt_int(168+30, 169+20, "%d", (s32)sBullyMultiplier);
    print_text(184+30, 169+20, ".");
    print_text_fmt_int(198+30, 169+20, "%d", sBullyFraction);
    print_text(212+30, 169+20, "*"); // 'X' glyph

    if (gMarioState->action == ACT_BURNING_FALL || gMarioState->action == ACT_BURNING_JUMP 
        || gMarioState->action == ACT_BURNING_GROUND) {
        if (o->oKleptoTargetNumber == 0) {
            action = TRUE;
            o->oKleptoTargetNumber = 1;
        }
    } else {
        o->oKleptoTargetNumber = 0;
        action = FALSE;
    }
    if (((gMarioState->hurtCounter > 0 && sBullyBool == 0) || action) && sBullyMultiplier > 0) {
        if (sBullyFraction == 0) {
            sBullyMultiplier -= 1.0f;
            sBullyFraction = 5;
        } else {
            sBullyFraction = 0;
        }
        sBullyBool = 1;
    } else if (gMarioState->hurtCounter <= 0) {
        sBullyBool = 0;
    }


}


void bhv_attic_bully_init(void) {
    s32 i;
    struct Object *obj;
    cur_obj_init_animation(0);

    o->oHomeX = o->oPosX;
    o->oHomeY = o->oPosY;
    o->oHomeZ = o->oPosZ;
    // o->oBehParams2ndByte = BULLY_BP_SIZE_SMALL;
    o->oGravity = 4.0f;
    o->oFriction = 0.91f;
    o->oBuoyancy = 0.0f;

    obj_set_hitbox(o, &sAtticBullyHitbox);

    o->oAction = 8;
    o->oPosY += 2000.0f;
    sBullyMultiplier = 5.0f;
}


void attic_bully_step(void) {
    struct Object *obj;
    f32 spireHeight, dist;
    s16 pitch, yaw;
    s16 collisionFlags = 0;

    collisionFlags = object_step();
    bully_backup_check(collisionFlags);
    bully_play_stomping_sound();
    // obj_check_floor_death(collisionFlags, sObjFloor);
    if (sObjFloor->type == SURFACE_BURNING) {
        o->oOpacity = approach_s16_symmetric(o->oOpacity, 120, 7);
        o->oGravity = 0.0f;
        o->oVelY = 0.0f;
        if (o->oTimer > 20) {
            o->oAction = BULLY_ACT_CHASE_MARIO;
        } else {
            o->oForwardVel = approach_f32_symmetric(o->oForwardVel, 0.0f, 3.5f);
        }
        cur_obj_become_intangible();
    } else {
        o->oOpacity = approach_s16_symmetric(o->oOpacity, 255, 15);
        o->oGravity = 4.0f;
        cur_obj_become_tangible();
    }

    obj = cur_obj_nearest_object_with_behavior(bhvAtticSpire);
    if (obj == NULL) {
        return;
    }
    spireHeight = obj->oPosY + (obj->header.gfx.scale[1] * 1000.0f);
    if (o->oAction != 6 && lateral_dist_between_objects(o, obj) < 300.0f && o->oPosY < spireHeight && o->oPosY >= obj->oPosY) {
        if (--o->oHealth <= 0) {
            o->oAction = 9;
            stop_background_music(SEQUENCE_ARGS(4, SEQ_GENERIC_BOSS));
        } else {
            o->oAction = 6;
        }
        cur_obj_play_sound_2(SOUND_OBJ2_LARGE_BULLY_ATTACKED);
        vec3f_get_dist_and_angle(&obj->oPosX, &o->oPosX, &dist, &pitch, &yaw);
        // o->oMoveAnglePitch = -pitch;
        o->oMoveAngleYaw = yaw;
        o->oForwardVel = 50.0f;
        o->oVelY = 80.0f;
        o->oGravity = -4.0f;
    }

}


void attic_bully_phase_b(void) {
    f32 dist;
    f32 dx, dz;
    switch (o->oSubAction) {
        case 0:
            cur_obj_init_animation(1);
            o->os16F6 = atan2s(gMarioState->pos[2] - o->oPosZ, gMarioState->pos[0] - o->oPosX);
            o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->os16F6, 0x400);
            if (o->oTimer > 60 /*&& gMarioObject->platform != NULL && !(obj_has_behavior(gMarioObject->platform, bhvAtticRock))*/) {
                o->oSubAction = 1;
                o->oTimer = 0;
                o->oVelY = 100.0f;
                cur_obj_play_sound_2(SOUND_OBJ_KING_BOBOMB_JUMP);
            }
            break;
        case 1:
            if (o->oOpacity != 255) {
                o->oOpacity = approach_s16_symmetric(o->oOpacity, 255, 9);
            }
            o->oMoveAngleYaw = o->os16F6;
            dx = absf(gMarioState->pos[0] - o->oPosX);
            dz = absf(gMarioState->pos[2] - o->oPosZ);
            o->oFloatFC = sqrtf(dx * dx + dz * dz);
            if (o->oFloatFC < 50.0f) {
                o->oForwardVel = 0.0f;
            } else {
                o->oForwardVel = o->oFloatFC / 30;
            }
            cur_obj_update_floor_and_walls();
            cur_obj_move_standard(-78);
            if (o->oPosY < 5184.0f) {
                o->oSubAction = 5;
                o->oGravity = 0;
                o->oVelY = 0;
            }
            if (o->oMoveFlags & OBJ_MOVE_MASK_ON_GROUND) {
                if (o->oFloor->object != NULL) {
                    if (obj_has_behavior(o->oFloor->object, bhvAtticRock)) {
                        o->oSubAction = 4;
                        o->oTimer = 0;
                        o->os16F4 = 0;
                        cur_obj_init_animation(3);
                        o->oMoveAngleYaw = cur_obj_angle_to_home();
                        o->oVelY = 100.0f;
                    } else {
                        o->os16F4++;
                        if (o->oFloor->object->oBehParams2ndByte != 1) {
                            o->oFloor->object->oAction = 1;
                            o->oFloor->object->oObjF8 = o;
                        }
                        o->oSubAction = 2;
                        o->oTimer = 0;
                    }
                    cur_obj_play_sound_2(SOUND_OBJ2_LARGE_BULLY_ATTACKED);
                }
            }
            break;
        case 2:
            if (o->oTimer > 15) {
                o->oSubAction = 0;
                o->oTimer = 0;
                if (o->os16F4 > 2) {
                    o->oSubAction = 4;
                    o->os16F4 = 0;
                    o->oMoveAngleYaw = cur_obj_angle_to_home();
                    o->oVelY = 100.0f;
                }
            }
            break;
        case 3:
            o->prevObj->activeFlags = 0;
            o->oAction = 0;
            o->oSubAction = 0;
            break;
        case 4: // HITS SPIKE /  GOES HOME
            dx = absf(o->oHomeX - o->oPosX);
            dz = absf(o->oHomeZ - o->oPosZ);
            o->oFloatFC = sqrtf(dx * dx + dz * dz);
            if (o->oFloatFC < 50.0f) {
                o->oForwardVel = 0.0f;
            } else {
                o->oForwardVel = o->oFloatFC / 30;
            }
            cur_obj_update_floor_and_walls();
            cur_obj_move_standard(-78);
            if (o->oMoveFlags & OBJ_MOVE_MASK_ON_GROUND) {
                o->oSubAction = 3;
                o->oTimer = 0;
                cur_obj_init_animation(1);
            }
            break;
        case 5:
            o->oOpacity = approach_s16_symmetric(o->oOpacity, 120, 7);
            o->oPosY = approach_f32_symmetric(o->oPosY, 5225.0f, 2.0f);
            o->oMoveAngleYaw = cur_obj_angle_to_home();
            o->oForwardVel = 35.0f;
            CL_Move();
            if (cur_obj_lateral_dist_to_home() < 150.0f) {
                o->oSubAction = 0;
                o->oForwardVel = 0;
                o->oTimer = 0;
                o->oGravity = -4.0f;
            }
            break;
    }
}


void bhv_attic_bully_loop(void) {
    struct Object *obj;
    s32 i;
    o->oBullyPrevX = o->oPosX;
    // o->oBullyPrevY = o->oPosY;
    o->oBullyPrevZ = o->oPosZ;
    attic_bounds();
    //! Because this function runs no matter what, Mario is able to interrupt the bully's
    //  death action by colliding with it. Since the bully hitbox is tall enough to collide
    //  with Mario even when it is under a lava floor, this can get the bully stuck OOB
    //  if there is nothing under the lava floor.
    if (o->oAction != 8) {
        bully_boss_multiplier_loop();
    }
    if (o->oAction < 6) {
        bully_check_mario_collision();
        if (o->oPosY < 5184.0f) {
            o->oPosY = 5185.0f;
        }
    }
    switch (o->oAction) {
        case BULLY_ACT_PATROL:
            cur_obj_init_animation(1);
            o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x300);
            if (o->oDistanceToMario < 1500.0f) {
                o->oAction = BULLY_ACT_CHASE_MARIO;
            }
            attic_bully_step();
            break;
        case BULLY_ACT_CHASE_MARIO:
            if (o->oTimer < 10) {
                o->oForwardVel = 3.0f;
                obj_turn_toward_object(o, gMarioObject, 16, 0x1000);
            } else {
                o->oForwardVel = 30.0f;
                if (o->oTimer > 35) {
                    o->oTimer = 0;
                }
            }

            if (o->oDistanceToMario > 2000.0f) {
                o->oAction = BULLY_ACT_PATROL;
                o->oForwardVel = 12.0f;
                cur_obj_init_animation(0);
            }
                // o->oAction = BULLY_ACT_PATROL;
                // cur_obj_init_animation(0);
            attic_bully_step();
            break;

        case BULLY_ACT_KNOCKBACK:
            bully_act_knockback();
            attic_bully_step();
            break;

        case BULLY_ACT_BACK_UP:
            bully_act_back_up();
            if (o->oAction == BULLY_ACT_PATROL) {
                o->oForwardVel = 12.0f;
            }
            attic_bully_step();
            break;
        case 6:
            // attic_bully_step();
            cur_obj_move_standard(-78);
            o->oForwardVel = approach_f32_symmetric(o->oForwardVel, 0.0f, 2.0f);
            // o->oForwardVel = approach_f32_symmetric(o->oForwardVel, 0.0f, 1.5f);
            if (o->oMoveFlags & OBJ_MOVE_MASK_ON_GROUND || o->oPosY <= 5185.0f) {
                o->oAction = 7;
                // o->oGravity = -o->oGravity;
                o->prevObj = spawn_object(o, MODEL_ENV_FLAME, bhvBullyFlame);
                o->prevObj->oObjFC = o;
                o->oFloat10C = gMarioState->pos[0];
                o->oFloat110 = gMarioState->pos[2];
                for (i = 0; i < 3; i++) {
                    obj = spawn_object(o, MODEL_ENV_FLAME, bhvAtticMovingFlame);
                    obj->oPosX = o->oHomeX + (1000.0f * random_sign());
                    obj->oPosZ = o->oHomeZ + (1000.0f * random_sign());
                    obj->oBehParams2ndByte = o->os16F6++;
                }
                // o->oVelY = 100.0f;
                // o->oForwardVel = 30.0f;
            }
            break;
        case 7:
            attic_bully_phase_b();
            break;
        case 8:
            if (lateral_dist_between_objects(o, gMarioObject) < 1500.0f) {
                o->oAction = 0;
                spawn_object_relative(0, 1000, 0, 1000, o, MODEL_ENV_FLAME, bhvAtticMovingFlame);
                spawn_object_relative(1, -1000, 0, 1000, o, MODEL_ENV_FLAME, bhvAtticMovingFlame);
                spawn_object_relative(2, 1000, 0, -1000, o, MODEL_ENV_FLAME, bhvAtticMovingFlame);
                spawn_object_relative(3, -1000, 0, -1000, o, MODEL_ENV_FLAME, bhvAtticMovingFlame);
                o->os16F6 = 4;
                obj = spawn_object(o, MODEL_ATTIC_WALL, bhvAtticWall);
                vec3f_copy(&obj->oPosX, &o->oHomeX);
                obj->oObjF4 = o;
                play_music(0, SEQUENCE_ARGS(4, SEQ_GENERIC_BOSS), 0);
            }
            break;
        case 9:
            cur_obj_move_standard(-78);
            o->oForwardVel = approach_f32_symmetric(o->oForwardVel, 0.0f, 2.0f);
            // o->oForwardVel = approach_f32_symmetric(o->oForwardVel, 0.0f, 1.5f);
            if (o->oMoveFlags & OBJ_MOVE_MASK_ON_GROUND || o->oPosY <= 5185.0f) {
                o->header.gfx.scale[0] = approach_f32_symmetric(o->header.gfx.scale[0], 0.0f, 0.2f);
                cur_obj_scale(o->header.gfx.scale[0]);
                if (o->header.gfx.scale[0] == 0.0f) {
                    gMarioState->numCoins += 100 * (sBullyMultiplier + ((f32)sBullyFraction / 10));
                    CL_explode_object(o, 1);
                    obj = spawn_object(o, MODEL_BOO, bhvRoomBoo);
                    obj->oFlags &= ~OBJ_FLAG_DISABLE_ON_ROOM_EXIT;
                    obj->oBehParams2ndByte = 0x12;
                    obj->oBehParams = 0x00120000;
                }
            }
            break;
        // case BULLY_ACT_LAVA_DEATH:
        //     bully_act_level_death();
        //     break;

        // case BULLY_ACT_DEATH_PLANE_DEATH:
        //     o->activeFlags = ACTIVE_FLAG_DEACTIVATED;
        //     break;
    }
}


void bhv_attic_wall_loop(void) {
    switch (o->oAction) {
        case 0:
            if (o->oOpacity != 255) {
                o->oOpacity = approach_s16_symmetric(o->oOpacity, 255, 10);
            }
            if (o->oObjF4->activeFlags == 0) {
                o->oAction = 1;
            }
            break;
        case 1:
            o->oOpacity = approach_s16_symmetric(o->oOpacity, 0, 6);
            if (o->oOpacity == 0) {
                o->activeFlags = 0;
            }
            break;
    }
}


s8 sSpireSpots[4][6][2] = {
{{0, 0}, {0, 1}, {1, 0}, {1, 1}, {2, 0}, {2, 1}},
{{3, 0}, {3, 1}, {3, 2}, {4, 0}, {4, 1}, {4, 2}},
{{0, 2}, {1, 2}, {0, 3}, {1, 3}, {0, 4}, {1, 4}},
{{2, 3}, {2, 4}, {3, 3}, {3, 4}, {4, 3}, {4, 4}},
};
s8 sSpiresReady[2] = {0, 0};


void bhv_attic_indicator_loop(void) {
    switch (o->oAction) {
        case 0:
            o->oPosX = o->oObjF4->oPosX;
            o->oPosZ = o->oObjF4->oPosZ;
            if (sSpiresReady[0] == 0b1111) {
                o->header.gfx.scale[1] = approach_f32_symmetric(o->header.gfx.scale[1], 1.2f, 0.025f);
            } else {
                o->header.gfx.scale[1] = approach_f32_symmetric(o->header.gfx.scale[1], 0.25f, 0.025f);
            }
            break;
        case 1:
            o->header.gfx.scale[1] = approach_f32_symmetric(o->header.gfx.scale[1], 0.0f, 0.075f);
            if (o->header.gfx.scale[1] == 0.0f) {
                o->activeFlags = 0;
            }
            break;
    }
}


void bhv_attic_spire_init(void) {
    o->header.gfx.scale[1] = 0.0f;
    o->oObj104 = cur_obj_nearest_object_with_behavior(bhvAtticBully);
    if (o->oObj104 == NULL) {
        o->activeFlags = 0;
    }
}


void bhv_attic_spire_loop(void) {
    if (--o->os16F6 <= 0 && gMarioState->pos[1] >= o->oPosY && gMarioState->pos[1] <= o->oPosY + (o->header.gfx.scale[1] * 1000.0f)) {
        if (lateral_dist_between_objects(o, gMarioObject) < 160.0f) {
            CL_Lava_Boost();
            o->os16F6 = 30;
        }
    }
    if (o->oObj104->activeFlags == 0) {
        o->oAction = 5;
        if (o->oObj108 != NULL) {
            o->oObj108->oAction = 1;
        }
    } else if (o->oObj104->oAction == 8) {
        return;
    }
    switch (o->oAction) {
        case 0:
            if (o->oObj104->oAction == 7) {
                o->oTimer = 0;
            }
            if (o->oTimer > 90) {
                o->os16F8 = CL_RandomMinMaxU16(0, 5);

                o->oFloatFC = -579.0f - (sSpireSpots[o->oBehParams2ndByte][o->os16F8][0] * 1000.0f);
                o->oFloat100 = 12888.0f - (sSpireSpots[o->oBehParams2ndByte][o->os16F8][1] * 1000.0f);
                o->oAction = 1;
                o->oObj108 = spawn_object(o, MODEL_ATTIC_INDICATOR, bhvAtticIndicator);
                o->oObj108->oObjF4 = o;
            }
            break;
        case 1:
            o->oPosX = approach_f32_symmetric(o->oPosX, o->oFloatFC, 30.0f);
            if (o->oPosX == o->oFloatFC) {
                o->oPosZ = approach_f32_symmetric(o->oPosZ, o->oFloat100, 30.0f);
                if (o->oPosZ == o->oFloat100) {
                    sSpiresReady[0] |= 1 << o->oBehParams2ndByte;
                }
            }
            if (sSpiresReady[0] == 0b1111) {
                if (o->oTimer > 90) {
                    sSpiresReady[1] |= 1 << o->oBehParams2ndByte;
                    o->oAction = 2;
                    if (sSpiresReady[1] == 0b1111) {
                        sSpiresReady[0] = 0;
                        sSpiresReady[1] = 0;
                    }
                }
            } else {
                o->oTimer = 0;
            }
            break;
        case 2:
            o->header.gfx.scale[1] = approach_f32_symmetric(o->header.gfx.scale[1], 2.0f, 0.05f);

            if (o->header.gfx.scale[1] == 2.0f) {
                o->oAction = 3;
            }
            break;
        case 3:
            // o->oGraphYOffset = approach_f32_symmetric(o->oGraphYOffset, 500.0f, 20.0f);
            // break;
            if (o->oTimer > 120 || o->oObj104->oAction == 7) {
                o->header.gfx.scale[1] = approach_f32_symmetric(o->header.gfx.scale[1], 0.0f, 0.05f);
                o->oPosY += 50.0f;
                if (o->header.gfx.scale[1] == 0.0f) {
                    if (o->oObj108 != NULL) {
                        o->oObj108->oAction = 1;
                        o->oObj108 = NULL;
                    }
                    o->oAction = 4;
                    o->oPosY = o->oHomeY;
                }
            }
                o->os16F4 += 0x600;
                o->header.gfx.scale[1] += (sins(o->os16F4) * 0.0075f);
            break;
        case 4:
            if (o->oTimer > 60) {
                o->oAction = 0;
                o->os16F4 = 0;
            }
            break;
        case 5:
            o->header.gfx.scale[1] = approach_f32_symmetric(o->header.gfx.scale[1], 0.0f, 0.05f);
            o->oPosY += 50.0f;
            if (o->header.gfx.scale[1] == 0.0f) {
                o->activeFlags = 0;
            }
            break;
    }
}


void bhv_attic_grate_loop(void) {
    switch (o->oAction) {
        case 1:
            o->oPosY += o->oFloatF4;
            o->oFloatF4 *= -1;
            if (o->oObjF8 == NULL || o->oObjF8->oSubAction == 1 || o->oObjF8->oAction != 7) {
                o->oAction = 2;
            }
            break;
        case 2:
            o->oPosY = approach_f32_symmetric(o->oPosY, o->oHomeY - 1200.0f, 7.5f);
            o->oPosY += o->oFloatF4;
            o->oFloatF4 *= -1;
            if (o->oPosY == o->oHomeY - 1200.0f) {
                o->activeFlags = 0;
            }
            break;
    }
}