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


Vec3f sTheaterRespawn[3] = {
{-4954.0f, 300.0f, -11146.0f},
{-4954.0f, 300.0f, -11146.0f},
{-4954.0f, 300.0f, -11146.0f},
};


void bhv_theater_screen_init(void) {
    o->oOpacity = 254;
}


void bhv_theater_screen_loop(void) {
    struct MarioState *m = gMarioState;
    switch (o->oAction) {
        case 0:
            if (m->pos[2] < o->oPosZ) {
                o->oAction = 1;
                gCamera->comit2dcam = 3;
            }
            break;
        case 1:
            gCamera->comit2dcam = 3;
            o->oOpacity = approach_s16_symmetric(o->oOpacity, 0, 0x8);
            if (o->oOpacity == 0) {
                cur_obj_hide();
                o->oAction = 2;
            }
            break;
        case 2:
            gCamera->comit2dcam = 3;

            if (m->pos[1] < -500.0f) {
                if (m->health <= 0x280) {
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
                    // CL_set_camera_pos(sTheaterRespawn[o->os16F4]);
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
    }
}


void bhv_2d_enemy_init(void) {
    obj_set_hitbox(o, &s2DEnemyHitbox);
    o->oForwardVel = 12.0f;
}

void bhv_2d_enemy_loop(void) {
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