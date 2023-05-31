static struct ObjectHitbox sTheControllerHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 180,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 255,
    /* numLootCoins:      */ 0,
    /* radius:            */ 300,
    /* height:            */ 300,
    /* hurtboxRadius:     */ 300,
    /* hurtboxHeight:     */ 300,
};

struct ObjectHitbox sEndFistHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 2,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 180,
    /* height:            */ 850,
    /* hurtboxRadius:     */ 180,
    /* hurtboxHeight:     */ 850,
};


struct ObjectHitbox sEndBubbleHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 100,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 0,
    /* numLootCoins:      */ 1,
    /* radius:            */ 80,
    /* height:            */ 180,
    /* hurtboxRadius:     */ 80,
    /* hurtboxHeight:     */ 180,
};



static struct ObjectHitbox sEndLogHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 0,
    /* numLootCoins:      */ 1,
    /* radius:            */ 80,
    /* height:            */ 54,
    /* hurtboxRadius:     */ 80,
    /* hurtboxHeight:     */ 54,
};

static struct ObjectHitbox sEndSpikeHitbox = {
    /* interactType:      */ INTERACT_BOUNCE_TOP,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 0,
    /* numLootCoins:      */ 3,
    /* radius:            */ 90,
    /* height:            */ 90,
    /* hurtboxRadius:     */ 90,
    /* hurtboxHeight:     */ 90,
};



enum FinalBossAttacks {
    FBA_BUBBLES,     // 0
    FBA_CAGE,        // 1
    FBA_LASER,       // 2
    FBA_LOGS,        // 3
    FBA_WALL,        // 4
    FBA_DROPPER,     // 5
    FBA_BOWSER,      // 6
};







void bhv_end_log_init(void) {
    o->oForwardVel = 20.0f;
    o->oFloatF8 = 45.0f;
    obj_set_hitbox(o, &sEndLogHitbox);
    // o->hitboxDownOffset = -50.0f;
    cur_obj_become_intangible();
}


void bhv_end_log_loop(void) {
    switch (o->oAction) {
        case 0:
            if ((o->parentObj->oBehParams >> 24) != 2) {
                o->oFloatF4 = approach_f32_symmetric(o->oFloatF4, 1.0f * 2.5f, 0.033f * 2.5f);
                o->oGraphYOffset = approach_f32_symmetric(o->oGraphYOffset, 30.0f * 2.5f, 1.0f * 2.5f);
            } else {
                o->oFloatF4 = approach_f32_symmetric(o->oFloatF4, 1.0f * 2.5f, 0.033f * 2.0f * 2.5f);
                o->oGraphYOffset = approach_f32_symmetric(o->oGraphYOffset, 30.0f * 2.5f, 2.0f * 2.5f);
            }
            cur_obj_scale(o->oFloatF4);
            if (o->parentObj->header.gfx.animInfo.animFrame == 50) {
                o->oAction = 1;
                o->parentObj->oInteractType = INTERACT_BOUNCE_TOP;
                cur_obj_become_tangible();
                cur_obj_play_sound_1(SOUND_OBJ_UNKNOWN4);
            }
            if (o->parentObj->activeFlags == 0) {
                o->activeFlags = 0;
            }
            break;
        case 1:
            o->oFloatF8 = approach_f32_symmetric(o->oFloatF8, 0.0f, 0.06f);
            o->oFaceAnglePitch += 0x600;
            cur_obj_update_floor_and_walls();
            cur_obj_move_standard(0);
            if (o->oMoveFlags & OBJ_MOVE_ON_GROUND) {
                o->oVelY = o->oFloatF8;
                cur_obj_play_sound_1(SOUND_GENERAL_POUND_ROCK);
            }
            if (o->oMoveFlags & OBJ_MOVE_HIT_WALL) {
                obj_explode_and_spawn_coins(46.0f, 0);
                create_sound_spawner(SOUND_GENERAL_BREAK_BOX);
                o->activeFlags = 0;
                o->parentObj->oObjF4 = NULL;
            }
            break;
    }
    o->oInteractStatus = 0;
}


static u8 sEndSpikeAttackHandler[6] = {
    /* ATTACK_PUNCH:                 */ ATTACK_HANDLER_KNOCKBACK,
    /* ATTACK_KICK_OR_TRIP:          */ ATTACK_HANDLER_KNOCKBACK,
    /* ATTACK_FROM_ABOVE:            */ ATTACK_HANDLER_SQUISHED,
    /* ATTACK_GROUND_POUND_OR_TWIRL: */ ATTACK_HANDLER_SQUISHED,
    /* ATTACK_FAST_ATTACK:           */ ATTACK_HANDLER_KNOCKBACK,
    /* ATTACK_FROM_BELOW:            */ ATTACK_HANDLER_KNOCKBACK,
};

void bhv_end_spike_init(void) {
    // obj_set_hitbox(o, &sEndSpikeHitbox);
    o->header.gfx.scale[1] = 0.0f;
}


void bhv_end_spike_loop(void) {
    struct Object *obj;
    f32 x, z, x2, z2;
    switch (o->oAction) {
        case 0:
            if (o->header.gfx.scale[1] < 1.25f) {
                o->header.gfx.scale[1] = approach_f32_symmetric(o->header.gfx.scale[1], 1.25f, 0.1f);
            }
            // if (o->oBehParams2ndByte && o->oDistanceToMario < 2750.0f) {
            //     o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x300);
            // }
            // x = absf((gMarioState->pos[0] - o->oPosX) * sins(o->oMoveAngleYaw + 0x4000));
            // z = absf((gMarioState->pos[2] - o->oPosZ) * coss(o->oMoveAngleYaw + 0x4000));
            // x2 = (gMarioState->pos[0] - o->oPosX) * sins(o->oMoveAngleYaw);
            // z2 = (gMarioState->pos[2] - o->oPosZ) * coss(o->oMoveAngleYaw);
            // if (x + z < 500.0f && x2 + z2 > 200.0f) {
                if (o->oDistanceToMario > 600.0f && (cur_obj_check_if_at_animation_end() || o->oTimer > 20)) {
                    if ((o->oBehParams >> 24) == 2) {
                        cur_obj_init_animation_with_accel_and_sound(1, 2.0f);
                    } else {
                        cur_obj_init_animation_with_sound(1);
                    }
                    o->oAction = 1;

                }
            // }
            break;
        case 1:
            // if (x + z >= 300.0f || x2 + z2 <= 180) {
            //     o->oAction = 0;
            // }

            if (cur_obj_check_anim_frame(20)) {
                o->oObjF4 = spawn_object(o, MODEL_END_LOG, bhvEndLog);
                // o->prevObj->oPosY += 100.0f;
                o->oInteractType = INTERACT_DAMAGE;
            }
            if (cur_obj_check_if_at_animation_end()) {
                o->oAction = 0;
                if ((o->oBehParams >> 24) == 2) {
                    cur_obj_init_animation_with_accel_and_sound(0, 2.0f);
                } else {
                    cur_obj_init_animation_with_sound(0);
                }
            }
            break;
    }


    // if (obj_handle_attacks(&sEndSpikeHitbox, o->oAction, sEndSpikeAttackHandler)) {
    //     mark_goomba_as_dead();
    // }
    obj_handle_attacks(&sEndSpikeHitbox, o->oAction, sEndSpikeAttackHandler);
    obj_update_standard_actions(1.0f);

    if (o->activeFlags == 0) {
        o->parentObj->os16100++;
    }
    // o->header.gfx.scale[1] = 0.5f;
    // print_text_fmt_int(80, 80, "%x", (s32)o->prevObj, 0);
    // if (o->activeFlags == 0 && (o->oBehParams >> 24) & 0xFF) {
    //     obj = spawn_object(o, MODEL_ENV_FLAME, bhvTreehouseFlame);
    //     obj->oBehParams2ndByte = (o->oBehParams >> 24) - 1;
    // }
    o->oInteractStatus = 0;

}


















void bhv_end_bubble_init(void) {
    obj_set_hitbox(o, &sEndBubbleHitbox);
    // o->oForwardVel = 10.0f;
}


void bhv_end_bubble_loop(void) {
    o->os16F4 += 0x300;
    o->oGraphYOffset = 10.0f * sins(o->os16F4);
    CL_Move_3d();
    // print_text_fmt_int(80, 80, "%d", (s16)o->oForwardVel, 0);
    if (o->oTimer > o->os16F6) {
        CL_explode_object(o, 0);
        o->oFaceAnglePitch = o->oFaceAngleYaw = 0;
        switch (CL_RandomMinMaxU16(0, 8)) {
            case 0:
                obj_force_spawn_loot_coins(o, 1, 20.0f, bhvSingleCoinGetsSpawned, 0, MODEL_YELLOW_COIN);
                break;
            case 1:
                o->oObjF8 = spawn_object(o, MODEL_END_GOOMBA, bhvGoomba);
                o->oObjF8->parentObj = o->oObjF8;
                break;
            case 2:
                spawn_object(o, MODEL_END_SHYGUY, bhvShyguy);
                break;
            case 3:
                spawn_object(o, MODEL_END_BOO, bhvEndBoo);
                break;
        }
        return;
    }
    if (o->oInteractStatus) {
        CL_explode_object(o, 0);
    }
}



void bhv_end_fist_init(void) {
    obj_set_hitbox(o, &sEndFistHitbox);
}


void bhv_end_fist_loop(void) {
    switch (o->oAction) {
        case 0:
            o->oPosY = approach_f32_symmetric(o->oPosY, 7406.0f, 50.0f);
            if (o->oPosY == 7406.0f) {
                o->oAction = 1;
            }
            break;
        case 1:
            if (o->oTimer > 25) {
                o->oPosY = approach_f32_symmetric(o->oPosY, 6400.0f, 65.0f);
                if (o->oPosY == 6400.0f) {
                    o->activeFlags = 0;
                }
            }
            break;
    }
}



void bhv_end_cage_init(void) {
    o->oPosY = 6500.0f;
    o->oFaceAngleYaw = 0x4000 * CL_RandomMinMaxU16(0, 3);
}


void bhv_end_cage_loop(void) {
    switch (o->oAction) {
        case 0:
            o->oPosX = gMarioState->pos[0];
            o->oPosZ = gMarioState->pos[2];
            o->oPosY = approach_f32_symmetric(o->oPosY, 6806.0f, 15.0f);
            if (o->oPosY == 6806.0f) {
                o->oAction = 1;
                o->oFloatF4 = 5.0f;
            }
            break;
        case 1:
            if (o->oTimer < 60) {
                o->oPosY += o->oFloatF4;
                o->oFloatF4 *= -1.0f;
                o->oPosX = gMarioState->pos[0];
                o->oPosZ = gMarioState->pos[2];
            } else if (o->oTimer <= 90) {
                o->oPosY = approach_f32_symmetric(o->oPosY, o->oHomeY, 40.0f);
                // if (o->oPosY == o->oHomeY) {
                // }
            } 
            if (o->oTimer == 80) {
                o->oObjF8 = spawn_object(o, MODEL_END_FIST, bhvEndFist);
                o->oObjF8->oPosY = 6400.0f;
                o->oAction = 2;
                // o->oObjF8->oHomeY = 7406.0f;
            }
            break;
        case 2:
            if (o->oTimer > 60) {
                o->oPosY = approach_f32_symmetric(o->oPosY, 6500.0f, 35.0f);
                if (o->oPosY == 6500.0f) {
                    o->parentObj->oObjF4 = NULL;
                    o->activeFlags = 0;
                }
            }
            break;
    }

}




void controller_bubble_attack(void) {
    if (o->os16F8 < 20) {
        if (o->oTimer > 20) {
            o->oObjF4 = spawn_object(o, MODEL_END_BUBBLE, bhvEndBubble);
            o->oObjF4->oMoveAngleYaw = CL_RandomMinMaxU16(0, 0x2800) - 0x1400;
            o->oObjF4->oMoveAnglePitch = CL_RandomMinMaxU16(0, 0x800);
            o->oObjF4->oForwardVel = CL_RandomMinMaxU16(8, 15);
            o->oObjF4->os16F6 = (CL_RandomMinMaxU16(480, 520) * 10.0f) / o->oObjF4->oForwardVel;
            o->oTimer = 0;
            o->os16F8++;
        }
    } else {
        o->activeFlags = 0;
        o->parentObj->oObjF4 = NULL;
    }
}

void controller_cage_attack(void) {
    switch (o->oAction) {
        case 0:
            o->oObjF4 = spawn_object(o, MODEL_END_CAGE, bhvEndCage);
            o->oObjF4->oPosY = 7406.0f;
            o->oObjF4->oHomeY = 7406.0f;
            o->oAction = 1;
            break;
        case 1:
            if (o->oObjF4 == NULL) {
                o->os16F8++;
                if (o->os16F8 > 3) {
                    o->activeFlags = 0;
                    o->parentObj->oObjF4 = NULL;
                }
                o->oAction = 0;
            }
            break;
    }
}

void controller_laser_attack(void) {

}

void controller_log_attack(void) {
    switch (o->oAction) {
        case 0:
            o->oObjF4 = spawn_object(o, MODEL_END_SPIKE, bhvEndSpike);
            vec3f_set(&o->oObjF4->oPosX, -937.0f, 7406.0f, -8110.0f);
            o->oObjF8 = spawn_object(o, MODEL_END_SPIKE, bhvEndSpike);
            vec3f_set(&o->oObjF8->oPosX, 1063.0f, 7406.0f, -8110.0f);
            o->oObjFC = spawn_object(o, MODEL_END_SPIKE, bhvEndSpike);
            vec3f_set(&o->oObjFC->oPosX, 3063.0f, 7406.0f, -8110.0f);

            o->oAction = 1;
            break;
        case 1:
            if (o->oTimer > 500) {
                if (o->oObjF4 != NULL && o->oObjF4->oAction == 0) {
                    o->oObjF4->activeFlags = 0;
                    o->oObjF4 = NULL;
                    o->os16100++;
                }
                if (o->oObjF8 != NULL && o->oObjF8->oAction == 0) {
                    o->oObjF8->activeFlags = 0;
                    o->oObjF8 = NULL;
                    o->os16100++;
                }
                if (o->oObjFC != NULL && o->oObjFC->oAction == 0) {
                    o->oObjFC->activeFlags = 0;
                    o->oObjFC = NULL;
                    o->os16100++;
                }
            }

            if (o->os16100 >= 3) {
                o->activeFlags = 0;
                o->parentObj->oObjF4 = NULL;
            }
            break;
    }
}

void controller_wall_attack(void) {

}

void controller_dropper_attack(void) {

}

void controller_bowser_attack(void) {

}


void bhv_attack_manager_init(void) {
    
}


void bhv_attack_manager_loop(void) {
    switch (o->oBehParams2ndByte) {
        case FBA_BUBBLES:
            controller_bubble_attack();
            break;
        case FBA_CAGE:
            controller_cage_attack();
            break;
        case FBA_LASER:
            controller_laser_attack();
            break;
        case FBA_LOGS:
            controller_log_attack();
            break;
        case FBA_WALL:
            controller_wall_attack();
            break;
        case FBA_DROPPER:
            controller_dropper_attack();
            break;
        case FBA_BOWSER:
            controller_bowser_attack();
            break;
    }
}


void bhv_the_controller_init(void) {
    struct Object *obj;
    o->oObjF4 = spawn_object(o, MODEL_NONE, bhvFinalBossAttacks);
    o->oObjF4->oBehParams2ndByte = FBA_LOGS;

    obj_set_hitbox(o, &sTheControllerHitbox);
}



/*
BOSS STRUCTURE PLAN:

in one act: he decides which attack(s) to use
in the next act: he waits for those attacks to end

    -a separate entity should carry out the attacks.
        -a generic attack handler bhv, with a bparam2 switch case?


*/

void bhv_the_controller_loop(void) {
    o->oInteractStatus = 0;
}