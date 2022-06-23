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


void bhv_attic_moving_flame_init(void) {
    o->oForwardVel = 15.0f;
    o->oMoveAngleYaw = CL_RandomMinMaxU16(0, 3) * 0x4000;
    o->oObjF4 = cur_obj_nearest_object_with_behavior(bhvAtticBully);
    if (o->oObjF4 == NULL) {
        o->activeFlags = 0;
    }
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

    if (o->oPosX > -79.0f) {
        o->oPosX = -79.0f;
        o->oMoveAngleYaw = CL_RandomMinMaxU16(0, 3) * 0x4000;
    }

    if (o->oPosX < -5079.0f) {
        o->oPosX = -5079.0f;
        o->oMoveAngleYaw = CL_RandomMinMaxU16(0, 3) * 0x4000;
    }

    if (o->oPosZ > 13388.0f) {
        o->oPosZ = 13388.0f;
        o->oMoveAngleYaw = CL_RandomMinMaxU16(0, 3) * 0x4000;
    }

    if (o->oPosZ < 8388.0f) {
        o->oPosZ = 8388.0f;
        o->oMoveAngleYaw = CL_RandomMinMaxU16(0, 3) * 0x4000;
    }
}


void bhv_attic_rock_loop(void) {
    f32 spireHeight;
    struct Object *obj = cur_obj_nearest_object_with_behavior(bhvAtticSpire);
    if (obj == NULL) {
        return;
    }
    switch (o->oAction) {
        case 0:
            if (lateral_dist_between_objects(o, obj) < 100.0f) {
                o->oAction = 1;
            }
            break;
        case 1:
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
    }
}


void bhv_attic_bully_init(void) {
    cur_obj_init_animation(0);

    o->oHomeX = o->oPosX;
    o->oHomeZ = o->oPosZ;
    // o->oBehParams2ndByte = BULLY_BP_SIZE_SMALL;
    o->oGravity = 4.0f;
    o->oFriction = 0.91f;
    o->oBuoyancy = 0.0f;

    obj_set_hitbox(o, &sAtticBullyHitbox);
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
            o->oAction = BULLY_ACT_LAVA_DEATH;
        } else {
            o->oAction = 6;
            cur_obj_play_sound_2(SOUND_OBJ2_LARGE_BULLY_ATTACKED);
            vec3f_get_dist_and_angle(&obj->oPosX, &o->oPosX, &dist, &pitch, &yaw);
            // o->oMoveAnglePitch = -pitch;
            o->oMoveAngleYaw = yaw;
            o->oForwardVel = 50.0f;
            o->oVelY = 80.0f;
            o->oGravity = -4.0f;
        }
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
            if (o->oTimer > 60 && gMarioObject->platform != NULL && !(obj_has_behavior(gMarioObject->platform, bhvAtticRock))) {
                o->oSubAction = 1;
                o->oVelY = 100.0f;
            }
            break;
        case 1:
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
            if (o->oMoveFlags & OBJ_MOVE_MASK_ON_GROUND) {
                if (o->oFloor->object != NULL) {
                    o->oFloor->object->oAction = 1;
                    if (++o->os16F4 > 2) {
                        o->oSubAction = 2;
                        o->oTimer = 0;
                    } else {
                        o->oSubAction = 0;
                        o->oTimer = 0;
                    }
                }
            }
            break;
        case 2:
            break;
    }
}



void bhv_attic_bully_loop(void) {
    o->oBullyPrevX = o->oPosX;
    // o->oBullyPrevY = o->oPosY;
    o->oBullyPrevZ = o->oPosZ;
    //! Because this function runs no matter what, Mario is able to interrupt the bully's
    //  death action by colliding with it. Since the bully hitbox is tall enough to collide
    //  with Mario even when it is under a lava floor, this can get the bully stuck OOB
    //  if there is nothing under the lava floor.
    if (o->oAction != 6 && o->oAction != OBJ_ACT_LAVA_DEATH) {
        bully_check_mario_collision();
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
            if (o->oMoveFlags & OBJ_MOVE_MASK_ON_GROUND) {
                o->oAction = 7;
                // o->oGravity = -o->oGravity;
                o->oFloat10C = gMarioState->pos[0];
                o->oFloat110 = gMarioState->pos[2];
                // o->oVelY = 100.0f;
                // o->oForwardVel = 30.0f;
            }
            break;
        case 7:
            attic_bully_phase_b();
            break;
        case BULLY_ACT_LAVA_DEATH:
            bully_act_level_death();
            break;

        // case BULLY_ACT_DEATH_PLANE_DEATH:
        //     o->activeFlags = ACTIVE_FLAG_DEACTIVATED;
        //     break;
    }
}



s8 sSpireSpots[4][7][2] = {
{{0, 0}, {0, 1}, {1, 0}, {1, 1}, {2, 0}, {0, 2}, {0, 0}},
{{3, 0}, {3, 1}, {4, 0}, {4, 1}, {2, 1}, {4, 2}, {0, 0}},
{{0, 3}, {0, 3}, {1, 4}, {1, 4}, {1, 2}, {2, 4}, {0, 0}},
{{3, 3}, {3, 3}, {4, 4}, {4, 4}, {2, 3}, {3, 2}, {2, 2}},
};
s8 sSpiresReady[2] = {0, 0};

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
    switch (o->oAction) {
        case 0:
            if (o->oTimer > 90) {
                if (o->oBehParams2ndByte != 3) {
                    o->os16F8 = CL_RandomMinMaxU16(0, 5);
                } else {
                    o->os16F8 = CL_RandomMinMaxU16(0, 6);
                }

                o->oFloatFC = -579.0f - (sSpireSpots[o->oBehParams2ndByte][o->os16F8][0] * 1000.0f);
                o->oFloat100 = 12888.0f - (sSpireSpots[o->oBehParams2ndByte][o->os16F8][1] * 1000.0f);
                o->oAction = 1;
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
                sSpiresReady[1] |= 1 << o->oBehParams2ndByte;
                o->oAction = 2;
                if (sSpiresReady[1] == 0b1111) {
                    sSpiresReady[0] = 0;
                    sSpiresReady[1] = 0;
                }
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
            if (/*o->oTimer > 120 || */ o->oObj104->oAction == 7) {
                o->header.gfx.scale[1] = approach_f32_symmetric(o->header.gfx.scale[1], 0.0f, 0.05f);
                o->oPosY += 50.0f;
                if (o->header.gfx.scale[1] == 0.0f) {
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
    }
}


void bhv_attic_grate_loop(void) {
    switch (o->oAction) {
        case 1:
            o->oFloatF4 = 5.0f;
            o->oPosY = approach_f32_symmetric(o->oPosY, o->oHomeY - 1000.0f, 7.5f);
            o->oPosY += (o->oFloatF4 *= -1.0f);
            break;
    }
}