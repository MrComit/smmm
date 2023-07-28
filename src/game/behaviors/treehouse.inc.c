
// s32 obj_update_standard_actions(f32 scale);
extern Vec3f gComitCutscenePosVec;
extern Vec3f gComitCutsceneFocVec;

static struct ObjectHitbox sOwlHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 0,
    /* numLootCoins:      */ 1,
    /* radius:            */ 120,
    /* height:            */ 150,
    /* hurtboxRadius:     */ 120,
    /* hurtboxHeight:     */ 150,
};


static struct ObjectHitbox sTreehouseOwlHitbox = {
    /* interactType:      */ INTERACT_BOUNCE_TOP,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 0,
    /* numLootCoins:      */ 1,
    /* radius:            */ 75,
    /* height:            */ 100,
    /* hurtboxRadius:     */ 75,
    /* hurtboxHeight:     */ 100,
};


static struct ObjectHitbox sTreehouseLogHitbox = {
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

static struct ObjectHitbox sTreehouseSpikeHitbox = {
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

static struct ObjectHitbox sTreehouseSwoopHitbox = {
    /* interactType:      */ INTERACT_HIT_FROM_BELOW,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 0,
    /* numLootCoins:      */ 1,
    /* radius:            */ 100,
    /* height:            */ 80,
    /* hurtboxRadius:     */ 70,
    /* hurtboxHeight:     */ 70,
};

static u8 sSpikeAttackHandler[6] = {
    /* ATTACK_PUNCH:                 */ ATTACK_HANDLER_KNOCKBACK,
    /* ATTACK_KICK_OR_TRIP:          */ ATTACK_HANDLER_KNOCKBACK,
    /* ATTACK_FROM_ABOVE:            */ ATTACK_HANDLER_SQUISHED,
    /* ATTACK_GROUND_POUND_OR_TWIRL: */ ATTACK_HANDLER_SQUISHED,
    /* ATTACK_FAST_ATTACK:           */ ATTACK_HANDLER_KNOCKBACK,
    /* ATTACK_FROM_BELOW:            */ ATTACK_HANDLER_KNOCKBACK,
};


Vec3f sTreehouseFlames[2] = {
{-4829.0f, 425.0f, -17642.0f},
{1628.0f, 425.0f, -17251.0f},
};

void bhv_treehouse_flame_init(void) {
    o->os16F4 = 0x3A;
    o->os16F6 = 0x2B;
    o->os16F8 = 0xC3;
    o->oFloat100 = 0.1f;
    vec3f_copy(&o->oPosX, sTreehouseFlames[o->oBehParams2ndByte]);
}


void bhv_treehouse_flame_loop(void) {
    struct Object *obj;
    switch (o->oAction) {
        case 0:
            o->oFloat100 = approach_f32_symmetric(o->oFloat100, 10.0f, 0.3f);
            cur_obj_scale(o->oFloat100);
            if (o->oFloat100 == 10.0f) {
                o->oAction = 1;
                play_sound(SOUND_GENERAL2_RIGHT_ANSWER, gGlobalSoundSource);
            }
            break;
        case 1:
            if (o->oTimer > 30) {
                o->oAction = 2;
            }
            break;
        case 2:
            set_mario_npc_dialog(1);
            obj = cur_obj_nearest_object_with_behavior(bhvTreehouseOwl);
            if (obj != NULL) {
                vec3f_copy(gComitCutsceneFocVec, &obj->oPosX);
                // vec3f_copy(gComitCutscenePosVec, gComitCutsceneFocVec);
                // gComitCutscenePosVec[1] += 1000.0f;
                vec3f_set_dist_and_angle(&obj->oPosX, gComitCutscenePosVec, 1500.0f, 0, obj->oFaceAngleYaw);
            }
            gCamera->comitCutscene = 0xFF;
            if (o->oTimer > 75) {
                o->oAction = 3;
                set_mario_npc_dialog(0);
            }
            break;
    }
}



void bhv_treehouse_swoop_update(void) {
    f32 dist;
    s16 pitch, yaw;
    switch (o->oAction) {
        case 0:
            obj_set_hitbox(o, &sTreehouseSwoopHitbox);
            vec3f_get_dist_and_angle(&o->oPosX, gMarioState->pos, &dist, &pitch, &yaw);
            o->oForwardVel = 40.0f;
            o->oMoveAngleYaw = yaw;
            o->oMoveAnglePitch = pitch;
            o->oAction = 1;
            break;
        case 1:
            CL_Move_3d();
            cur_obj_update_floor_and_walls();

            if (o->oTimer > 120 || o->oInteractStatus || o->oMoveFlags & OBJ_MOVE_HIT_WALL || o->oPosY <= o->oFloorHeight) {
                spawn_mist_particles();
                // obj_spawn_loot_yellow_coins(o, o->oNumLootCoins, 20.0f);
                o->activeFlags = 0;
                // create_sound_spawner(SOUND_OBJ_DYING_ENEMY1);
            }
            break;
    }
}

void bhv_swoop_spawner_init(void) {
    o->os16F4 = CL_RandomMinMaxU16(70, 110);
}

void bhv_swoop_spawner_loop(void) {
    struct MarioState *m = gMarioState;
    struct Object *swoop;
    if (o->oAction == 0) {
        if (o->oBehParams2ndByte) {
            if (o->oTimer > o->os16F4 - 25 && m->pos[1] > 1200.0f && m->pos[0] < 1964.0f && m->pos[0] > 0.0f) {
                swoop = spawn_object(o, MODEL_SWOOP, bhvTreehouseSwoop);
                o->oAction = 1;
            }
        } else {
            if (o->oTimer > o->os16F4 && lateral_dist_between_objects(o, gMarioObject) < 2250.0f) {
                swoop = spawn_object(o, MODEL_SWOOP, bhvTreehouseSwoop);
                o->oAction = 1;
            }
        }
    } else {
        // o->oScuttlebugSpawnerUnk88 = 0;
        o->oAction = 0;
        o->os16F4 = CL_RandomMinMaxU16(70, 110);
    }
}


void bhv_treehouse_log_init(void) {
    o->oForwardVel = 20.0f;
    o->oFloatF8 = 45.0f;
    obj_set_hitbox(o, &sTreehouseLogHitbox);
    // o->hitboxDownOffset = -50.0f;
    cur_obj_become_intangible();
}


void bhv_treehouse_log_loop(void) {
    switch (o->oAction) {
        case 0:
            if ((o->parentObj->oBehParams >> 24) != 2) {
                o->oFloatF4 = approach_f32_symmetric(o->oFloatF4, 1.0f, 0.033f);
                o->oGraphYOffset = approach_f32_symmetric(o->oGraphYOffset, 30.0f, 1.0f);
            } else {
                o->oFloatF4 = approach_f32_symmetric(o->oFloatF4, 1.0f, 0.033f * 2.0f);
                o->oGraphYOffset = approach_f32_symmetric(o->oGraphYOffset, 30.0f, 2.0f);
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

void bhv_spike_init(void) {
    // obj_set_hitbox(o, &sTreehouseSpikeHitbox);
}


void bhv_spike_loop(void) {
    struct Object *obj;
    f32 x, z, x2, z2;
    switch (o->oAction) {
        case 0:
            if (o->oBehParams2ndByte && o->oDistanceToMario < 2750.0f) {
                o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x300);
            }
            x = absf((gMarioState->pos[0] - o->oPosX) * sins(o->oMoveAngleYaw + 0x4000));
            z = absf((gMarioState->pos[2] - o->oPosZ) * coss(o->oMoveAngleYaw + 0x4000));
            x2 = (gMarioState->pos[0] - o->oPosX) * sins(o->oMoveAngleYaw);
            z2 = (gMarioState->pos[2] - o->oPosZ) * coss(o->oMoveAngleYaw);
            if (x + z < 500.0f && x2 + z2 > 200.0f) {
                if (cur_obj_check_if_at_animation_end() || o->oTimer > 20) {
                    if ((o->oBehParams >> 24) == 2) {
                        cur_obj_init_animation_with_accel_and_sound(1, 2.0f);
                    } else {
                        cur_obj_init_animation_with_sound(1);
                    }
                    o->oAction = 1;

                }
            }
            break;
        case 1:
            // if (x + z >= 300.0f || x2 + z2 <= 180) {
            //     o->oAction = 0;
            // }

            if (cur_obj_check_anim_frame(20)) {
                o->oObjF4 = spawn_object(o, MODEL_TREEHOUSE_LOG, bhvTreehouseLog);
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


    // if (obj_handle_attacks(&sTreehouseSpikeHitbox, o->oAction, sSpikeAttackHandler)) {
    //     mark_goomba_as_dead();
    // }
    obj_handle_attacks(&sTreehouseSpikeHitbox, o->oAction, sSpikeAttackHandler);
    obj_update_standard_actions(1.0f);
    // o->header.gfx.scale[1] = 0.5f;
    // print_text_fmt_int(80, 80, "%x", (s32)o->prevObj, 0);
    if (o->activeFlags == 0 && (o->oBehParams >> 24) & 0xFF) {
        obj = spawn_object(o, MODEL_ENV_FLAME, bhvTreehouseFlame);
        obj->oBehParams2ndByte = (o->oBehParams >> 24) - 1;
    }
    o->oInteractStatus = 0;

}

void treehouse_owl_hiding(void) {
    switch (o->oSubAction) {
        case 0:
            cur_obj_disable();
            if (CL_nearest_object_with_behavior_and_field(bhvTreehouseFlame, 0x144, o->oBehParams2ndByte)) {
                o->oSubAction = 1;
                o->oGraphYOffset = -120.0f;
                cur_obj_enable();
                o->oMoveAngleYaw = random_u16();
            }
            break;
        case 1:
            cur_obj_update_floor_and_walls();
            o->oPosY = approach_f32_symmetric(o->oPosY, o->oFloorHeight, 20.0f);
            if (o->oPosY == o->oFloorHeight) {
                o->oAction = 1;
                obj_set_hitbox(o, &sTreehouseOwlHitbox);
                cur_obj_init_animation_with_sound(2);
                o->oForwardVel = 8.5f;
            }
            break;
    }
}

/*
            cur_obj_update_floor_and_walls();
            goomba_act_walk();
            cur_obj_move_standard(-78);
            if (o->oInteractStatus & INT_STATUS_INTERACTED && o->oInteractStatus & INT_STATUS_WAS_ATTACKED) {
                spawn_mist_particles();
                obj_spawn_loot_yellow_coins(o, o->oNumLootCoins, 20.0f);
                o->activeFlags = 0;
                create_sound_spawner(SOUND_OBJ_DYING_ENEMY1);
            }
            o->oInteractStatus = 0;
*/

void bhv_treehouse_owl_loop(void) {
    if (o->oAction != 0) {
        cur_obj_update_floor_and_walls();
        cur_obj_move_standard(-78);
        if (o->oFloor != NULL && o->oFloor->type == SURFACE_INSTANT_QUICKSAND && o->oPosY - o->oFloorHeight < 300.0f) {
            o->oInteractStatus |= INT_STATUS_INTERACTED | INT_STATUS_WAS_ATTACKED;
        }
        if (o->oInteractStatus & INT_STATUS_INTERACTED && o->oInteractStatus & INT_STATUS_WAS_ATTACKED) {
            spawn_mist_particles();
            obj_spawn_loot_yellow_coins(o, o->oNumLootCoins, 20.0f);
            o->activeFlags = 0;
            create_sound_spawner(SOUND_OBJ_DYING_ENEMY1);
        }
    }
    switch (o->oAction) {
        case 0:
            treehouse_owl_hiding();
            break;
        case 1: // IDLE
            o->oMoveAngleYaw += 0x280;
            if (absf(o->oPosY - gMarioState->pos[1]) < 500.0f) {
                if (++o->os16F4 > 45) {
                    o->oAction = 2;
                    o->oForwardVel = 15.0f;
                    o->oVelY = 15.0f;
                    o->os16F4 = 0;
                    o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0xC00);
                    cur_obj_play_sound_2(SOUND_OBJ_GOOMBA_ALERT);
                }
            } else {
                o->os16F4 = 0;
            }
            break;
        case 2: // CHASE MARIO
            o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x300);
            if (o->oTimer > 45 && absi(o->oMoveAngleYaw - o->oAngleToMario) < 0x2000) {
                if (cur_obj_check_if_at_animation_end()) {
                    cur_obj_init_animation_with_sound(1);
                    o->oAction = 3;
                    obj_set_hitbox(o, &sOwlHitbox);
                    o->oForwardVel = 0.0f;
                    o->oVelY = 30.0f;
                    o->oGravity = 0.0f;
                }
            }
            if (absf(o->oPosY - gMarioState->pos[1]) > 750.0f) {
                if (++o->os16F4 > 45) {
                    o->oAction = 1;
                    o->oForwardVel = 8.5f;
                    o->oMoveAngleYaw += 0xC00;
                    o->os16F4 = 0;
                }
            } else {
                o->os16F4 = 0;
            }
            break;
        case 3: // SWOOP ATTACK
            if (o->oTimer < 10) {
                o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x600);
            }
            o->oForwardVel = approach_f32_symmetric(o->oForwardVel, 60.0f, 1.2f);
            o->oVelY = approach_f32_symmetric(o->oVelY, -5.0f, 2.8f);

            if (o->oTimer > 120 || o->oInteractStatus || o->oMoveFlags & OBJ_MOVE_HIT_WALL || o->oPosY <= o->oFloorHeight) {
                o->oGravity = -4.0f;
                o->oForwardVel = 8.5f;
                o->oAction = 1;
                cur_obj_init_animation_with_sound(2);
                obj_set_hitbox(o, &sTreehouseOwlHitbox);
            }
            break;
    }
    o->oInteractStatus = 0;
}




void bhv_blue_owl_init(void) {
    obj_set_hitbox(o, &sOwlHitbox);
}


void bhv_blue_owl_loop(void) {
    if (o->oDistanceToMario > o->oDrawingDistance && gIsConsole) {
        o->header.gfx.node.flags &= ~GRAPH_RENDER_ACTIVE;
    } else {
        o->header.gfx.node.flags |= GRAPH_RENDER_ACTIVE;
    }
    if (o->header.gfx.animInfo.animFrame == 0) {
        cur_obj_play_sound_2(SOUND_GENERAL_SWISH_WATER);
    }
    switch (o->oAction) {
        case 0:
            if (o->oDistanceToMario < 2000.0f) {
                o->oFaceAngleYaw = o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x800);
                if (cur_obj_check_if_at_animation_end()) {
                    cur_obj_init_animation_with_sound(1);
                    o->oAction = 1;
                }
            }
            break;
        case 1:
            o->oForwardVel = approach_f32_symmetric(o->oForwardVel, 50.0f, 2.0f);
            CL_Move();
            if (o->oTimer < 20) {
                o->oFaceAngleYaw = o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x800);
                o->oFloatF4 = gMarioState->pos[1] + 20.0f;
                if (o->oFloatF4 > o->oHomeY) {
                    o->oFloatF4 = o->oHomeY;
                }
            }

            // if (o->oTimer > 20) {
            //     cur_obj_play_sound_1(SOUND_GENERAL_SWISH_AIR_2);
            // }
            o->oPosY = approach_f32_symmetric(o->oPosY, o->oFloatF4, 20.0f);
            if (o->oTimer > 90 && o->oDistanceToMario > 1000.0f) {
                o->oAction = 2;
                cur_obj_init_animation_with_sound(0);
                o->oMoveAngleYaw = cur_obj_angle_to_home();
                o->oForwardVel = 30.0f;
            }
            break;
        case 2:
            o->oFaceAngleYaw = approach_s16_symmetric(o->oFaceAngleYaw, o->oMoveAngleYaw, 0x400);
            CL_Move();
            o->oPosY = approach_f32_symmetric(o->oPosY, o->oHomeY, 20.0f);
            if (o->oTimer > 120) {
                vec3f_copy(&o->oHomeX, &o->oPosX);
                o->oForwardVel = 0;
                o->oAction = 0;
            }
            break;
    }
    o->oInteractStatus = 0;
}




void bhv_tree_limb_col_loop(void) {
    o->header.gfx.throwMatrix = &o->transform;
    vec3f_copy(&o->oPosX, o->transform[3]);
}


void bhv_tree_limb_init(void) {
    if (o->oBehParams2ndByte) {
        // cur_obj_scale(0.8f);
        // obj_scale(o->prevObj, 1.0f);
    }
}


void bhv_tree_limb_loop(void) {
    Vec3f pos;
    if (cur_obj_check_if_at_animation_end()) {
        o->header.gfx.animInfo.animFrame = 0;
        o->oTimer = 0;
    }

}


void bhv_tight_rope_init(void) {
    o->header.gfx.scale[2] += (f32)o->oBehParams2ndByte * 0.02f;
    o->os16F8 = TIGHT_ROPE_HALF * o->header.gfx.scale[2];
}

//os16F4 = vert ycoord
//os16F6 = vert zcoord
//os16F8 = uv coord
void bhv_tight_rope_loop(void) {
    struct MarioState *m = gMarioState;
    switch (o->oAction) {
        case 0:
            o->oFloatFC -= (o->oHomeY - o->oPosY) / 10.0f;
            o->oPosY -= o->oFloatFC;
            o->oFloatFC = approach_f32_symmetric(o->oFloatFC, 0.0f, 2.0f);
            o->os16F4 = o->oHomeY - o->oPosY;
            // o->os16F8 = approach_s16_symmetric(o->os16F8, 2560, 320);
            if (gMarioObject->platform == o) {
                cur_obj_play_sound_2(SOUND_ACTION_BOUNCE_OFF_OBJECT);
                o->oAction = 1;
                if (m->vel[1] >= 0) {
                    o->oFloatFC = 15.0f;
                } else {
                    o->oFloatFC = -m->vel[1];
                }
                o->oFloat100 = 15.0f;
            }
            if (o->os16F6 != 0 && o->os16F4 == 0) {
                o->os16F6 = 0;
                o->os16F8 = TIGHT_ROPE_HALF * o->header.gfx.scale[2];
            }
            break;
        case 1:
            o->oFloatFC -= (o->oHomeY - o->oPosY) / 10.0f;
            o->oPosY -= o->oFloatFC;
            o->oFloatFC = approach_f32_symmetric(o->oFloatFC, 0.0f, 2.0f);
            if (-o->oFloatFC > o->oFloat100) {
                o->oFloat100 = -o->oFloatFC;
            } else {
                o->oFloat100 = approach_f32_symmetric(o->oFloat100, -o->oFloatFC, 0.5f);
            }
            if (o->oFloat100 > 40.0f) {
                o->oFloat100 = 40.0f;
            }
            o->os16F4 = o->oHomeY - o->oPosY;
            o->os16F6 = (m->pos[2] - o->oPosZ) * coss(o->oFaceAngleYaw) + (m->pos[0] - o->oPosX) * sins(o->oFaceAngleYaw);
            m->pos[2] = o->oPosZ + o->os16F6 * coss(o->oFaceAngleYaw);
            m->pos[0] = o->oPosX + o->os16F6 * sins(o->oFaceAngleYaw);
            o->os16F6 /= o->header.gfx.scale[2];
            o->os16F8 = (s16)((500.0f - (f32)o->os16F6) / 1000.0f * TIGHT_ROPE_MAX * o->header.gfx.scale[2]);
            if (gMarioObject->platform != o) {
                o->oAction = 0;
                cur_obj_play_sound_2(SOUND_ACTION_BOUNCE_OFF_OBJECT);
                o->oFloat100 = 0.0f;
            }
            break;
    }
}