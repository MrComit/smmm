struct ObjectHitbox sFallingBombHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 3,
    /* numLootCoins:      */ 2,
    /* radius:            */ 200,
    /* height:            */ 50,
    /* hurtboxRadius:     */ 200,
    /* hurtboxHeight:     */ 50,
};


void bhv_jenga_plat_init(void) {
    o->oObjF4 = cur_obj_nearest_object_with_behavior(bhvObservatorySpinningPlat);
}



void spawn_jenga_object(s32 param) {
    struct Object *obj;
    switch (param) {
        case 1:
            o->oObj100 = spawn_object(o, MODEL_BG_GOOMBA, bhvGoomba);
            o->oObj100->oPosY += 30.0f;
            o->oObj100->oRoom = o->oRoom;
            o->oObj100->oFlags &= ~OBJ_FLAG_DISABLE_ON_ROOM_EXIT;
        case 2:
            o->oObjFC = spawn_object(o, MODEL_BG_GOOMBA, bhvGoomba);
            o->oObjFC->oPosY += 30.0f;
            o->oObjFC->oRoom = o->oRoom;
            o->oObjFC->oFlags &= ~OBJ_FLAG_DISABLE_ON_ROOM_EXIT;
            break;
        case 3:
            o->oObj104 = spawn_object(o, MODEL_GOLDEN_CRATE, bhvGoldenCrate);
            o->oObj104->oPosY += 20.0f;
            o->oObj104->oBehParams = 13 << 8;
            break;
    }
}



void bhv_jenga_plat_loop(void) {
    if (o->oObjF4 == NULL) {
        o->activeFlags = 0;
        return;
    }
    switch (o->oAction) {
        case 0:
            if (o->oObjF4->oAction == 2) {
                o->oAction = 1;
                spawn_jenga_object(o->oBehParams >> 24);
            }
            break;
        case 1:
            o->oPosY -= 2.0f;
            if (o->oPosY <= o->oObjF4->oPosY + 50.0f) {
                o->oAction = 2;
            }
            if (o->oObjFC != NULL && o->oObjFC->activeFlags != 0) {
                vec3f_copy(&o->oObjFC->oPosX, &o->oObjFC->oHomeX);
                o->oObjFC->oPosY = o->oPosY + 20.0f;
            } else {
                o->oObjFC = NULL;
            }
            if (o->oObj100 != NULL && o->oObj100->activeFlags != 0) {
                vec3f_copy(&o->oObj100->oPosX, &o->oObj100->oHomeX);
                o->oObj100->oPosY = o->oPosY + 20.0f;
            } else {
                o->oObj100 = NULL;
            }
            if (o->oObj104 != NULL && o->oObj104->activeFlags != 0) {
                o->oObj104->oPosY = o->oPosY + 20.0f;
            } else {
                o->oObj104 = NULL;
            }
            break;
        case 2:
            if (o->oObj104 != NULL && o->oObj104->activeFlags != 0) {
                o->oObj104->oPosY = o->oPosY + 20.0f;
            } else {
                o->oObj104 = NULL;
            }
            o->oPosY = o->oObjF4->oPosY + 50.0f;
            if (o->oTimer > 30*o->oBehParams2ndByte) {
                o->oObjF8 = spawn_object(o, MODEL_BLACK_BOBOMB, bhvObservatoryBomb);
                obj_scale(o->oObjF8, 2.0f);
                vec3f_set(&o->oObjF8->oPosX, o->oPosX, o->oPosY + 900.0f, o->oPosZ);
                o->oAction = 3;
            }
            break;
        case 3:
            o->oPosY = o->oObjF4->oPosY + 50.0f;
            if (o->oObjF8 == NULL || o->oObjF8->activeFlags == 0) {
                CL_explode_object(o, 1);
                if (o->oObj104 != NULL) {
                    o->oObj104->activeFlags = 0;
                }
            }
            break;
    }
}


void bhv_observatory_bomb_init(void) {
    obj_set_hitbox(o, &sFallingBombHitbox);
    // vec3f_set(&o->oPosX, gMarioState->pos[0], gMarioState->pos[1] + 600.0f, gMarioState->pos[2]);
    o->oFaceAngleYaw = random_u16();
    // vec3f_set(o->header.gfx.scale, 0.25f, 0.35f, 0.6f);
    // o->oGraphYOffset = -35.0f;
}

void bhv_observatory_bomb_loop(void) {
    struct Object *obj;
    o->oF8 += 0x800;
    // o->oFaceAngleRoll = 0x600 * sins(o->oF8);
    o->oFaceAnglePitch += 0x600;
    o->oFloatF4 = approach_f32_symmetric(o->oFloatF4, 30.0f, 1.2f);
    o->oPosY -= o->oFloatF4;
    if (o->oInteractStatus || object_step() & 1 || o->oTimer > 90) {
        obj = spawn_object(o, MODEL_EXPLOSION, bhvExplosion);
        // obj->oGraphYOffset += 100.0f;
        obj->oIntangibleTimer = -1;
        o->activeFlags = 0;
        if (CL_RandomMinMaxU16(0, 11) == 0) {
            obj_force_spawn_loot_coins(o, 1, 20.0f, bhvSingleCoinGetsSpawned, 0, MODEL_YELLOW_COIN);
        }
    }
    // obj = cur_obj_nearest_object_with_behavior(bhvShyGuyBoss);
    // if (obj == NULL || obj->os16F6 == 0) {
    //     o->activeFlags = 0;
    // }
}


void observatory_spawn_bombs(void) {
    struct Object *obj;
    Vec3f pos;
    if (++o->os16F4 > o->os16F6) {
        o->os16F4 = 0;
        o->os16F6 = CL_RandomMinMaxU16(o->os16100, o->os16100 + 50);
        obj = spawn_object(o, MODEL_BLACK_BOBOMB, bhvObservatoryBomb);
        vec3f_set(&obj->oPosX, gMarioState->pos[0], gMarioState->pos[1] + 800.0f, gMarioState->pos[2]);
    }


    if (++o->os16F8 > o->os16FA) {
        o->os16F8 = 0;
        o->os16FA = CL_RandomMinMaxU16(o->os16102, o->os16104);
        obj = spawn_object(o, MODEL_BLACK_BOBOMB, bhvObservatoryBomb);
        pos[1] = o->oPosY + 900.0f;

        pos[0] = o->oPosX + (1500.0f * random_float()) - 750.0f;
        pos[2] = o->oPosZ + (1500.0f * random_float()) - 750.0f;

        vec3f_copy(&obj->oPosX, pos);
    }

}



void update_observatory_time(void) {
    if (o->oTimer < 500) {
        o->os16FE = 0x80;
        o->os16100 = 70;
        o->os16102 = 15;
        o->os16104 = 35;
    } else if (o->oTimer < 1300) {
        o->os16FE = 0xA0;
        o->os16100 = 65;
        o->os16102 = 13;
        o->os16104 = 30;
    } else if (o->oTimer < 2000) {
        o->os16FE = 0x100;
        o->os16100 = 55;
        o->os16102 = 10;
        o->os16104 = 28;
    } else {
        o->os16FE = 0x180;
        o->os16100 = 40;
        o->os16102 = 8;
        o->os16104 = 23;
    }
}

extern s16 gCutsceneTimer;
extern s16 s8DirModeBaseYaw;

void observatory_respawn_handler(void) {
    struct MarioState *m = gMarioState;
    struct Object *obj;
    if (o->os16106 > 0) {
        switch (o->os16106++) {
            case 1:
                play_transition(WARP_TRANSITION_FADE_INTO_COLOR, 0xC, 0x00, 0x00, 0x00);
                break;
            case 19:
                o->oFaceAngleYaw = 0xE000;
                m->faceAngle[1] = 0x4000;
                // set_r_button_camera(gCamera);
                warp_camera((o->oPosX - 1000.0f) - m->pos[0], (o->oPosY + 500.0f) - m->pos[1], (o->oPosZ) - m->pos[2]);
                // vec3f_copy(m->pos, &obj->oPosX);
                vec3f_set(m->pos, o->oPosX - 1000.0f, o->oPosY + 500.0f, o->oPosZ);
                s8DirModeBaseYaw = (m->faceAngle[1] + 0x8000) >> 8;
                m->forwardVel = 0;
                vec3f_set(m->vel, 0.0f, 0.0f, 0.0f);
                play_transition(WARP_TRANSITION_FADE_FROM_COLOR, 0xC, 0x00, 0x00, 0x00);
                m->hurtCounter = 8;
                gCamera->cutscene = 0;
                gCutsceneTimer = CUTSCENE_STOP;
                o->os16106 = 0;
                return set_mario_action(m, ACT_FREEFALL, 0);
        }
    } else if (m->pos[1] < o->oPosY - 2048.0f) {
        if (o->os16106 < 0 && m->health >= 0x300) {
            o->os16106 = 0;
        }
        if (m->health < 0x300 && o->os16106 >= 0) {
            obj = cur_obj_nearest_object_with_behavior(bhvAirborneDeathWarp);
            if (obj == NULL) {
                return;
            }
            o->oFaceAngleYaw = 0xE000;
            m->faceAngle[1] = 0x4000;
            vec3f_set(&obj->oPosX, o->oPosX - 1000.0f, o->oPosY + 500.0f, o->oPosZ);
            if (level_trigger_warp(m, WARP_OP_WARP_FLOOR_OBJECT) == 20 && !(m->flags & MARIO_UNKNOWN_18)) {
                play_sound(SOUND_MARIO_WAAAOOOW, m->marioObj->header.gfx.cameraToObject);
            }
            o->os16106 = -1;
        } else if (o->os16106 == 0) {
            o->os16106 = 1;
        }
    }
}


void bhv_observatory_spinning_plat_init(void) {
    o->os16F6 = 90;
    o->os16FA = 20;
}

void bhv_observatory_spinning_plat_loop(void) {
    // return;
    switch (o->oAction) {
        case 0:
            if (gMarioObject->platform == o) {
                o->oAction = 1;
            }
            break;
        case 1:
            if (o->oTimer > 50) {
                o->oAction = 2;
                o->oVelY = 5.0f;
            }
            break;
        case 2:
            update_observatory_time();
            observatory_respawn_handler();
            observatory_spawn_bombs();
            o->os16FC = approach_s16_symmetric(o->os16FC, o->os16FE, 0x8);
            o->oFaceAngleYaw += o->os16FC;
            o->oPosY += 5.0f;
            // if (gMarioObject->platform == o) {
            //     gMarioState->pos[1] += 10.0f;
            //     if (gMarioState->vel[1] > 0.0f) {
            //         gMarioState->vel[1] += 10.0f;
            //     }
            // }
            break;
    }
    //     if (gMarioObject->platform == o) {
    //         o->oPosY = approach_f32_symmetric(o->oPosY, o->oHomeY - 20.0f, 2.0f);
    //     } else {
    //         o->oPosY = approach_f32_symmetric(o->oPosY, o->oHomeY, 2.0f);
    //     }
}
