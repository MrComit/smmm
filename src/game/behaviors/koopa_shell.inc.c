// koopa_shell.inc.c

struct ObjectHitbox sKoopaShellHitbox = {
    /* interactType:      */ INTERACT_KOOPA_SHELL,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 4,
    /* health:            */ 1,
    /* numLootCoins:      */ 1,
    /* radius:            */ 50,
    /* height:            */ 50,
    /* hurtboxRadius:     */ 50,
    /* hurtboxHeight:     */ 50,
};

void koopa_shell_spawn_water_drop(void) {
    UNUSED u8 filler[4];

    spawn_object(o, MODEL_WAVE_TRAIL, bhvObjectWaveTrail);

    if (gMarioStates[0].forwardVel > 10.0f) {
        struct Object *drop = spawn_object_with_scale(o, MODEL_WHITE_PARTICLE_SMALL,
                                                      bhvWaterDroplet, 1.5f);
        drop->oVelY = random_float() * 30.0f;
        obj_translate_xz_random(drop, 110.0f);
    }
}

void bhv_koopa_shell_flame_loop(void) {
    if (o->oTimer == 0) {
        o->oMoveAngleYaw = random_u16();
        o->oVelY = random_float() * 30.0f;
        o->oGravity = -4.0f;
        o->oAnimState = random_float() * 10.0f;
        obj_translate_xz_random(o, 110.0f);
        o->oKoopaShellFlameScale = 4.0f;
    }

    cur_obj_update_floor_height();
    cur_obj_move_using_fvel_and_gravity();

    if (o->oFloorHeight > o->oPosY || o->oTimer > 10) {
        obj_mark_for_deletion(o);
    }

    o->oKoopaShellFlameScale += -0.3;
    cur_obj_scale(o->oKoopaShellFlameScale);
}

void bhv_koopa_shell_flame_spawn(void) {
    s32 i;
    for (i = 0; i < 2; i++) {
        spawn_object(o, MODEL_RED_FLAME, bhvKoopaShellFlame);
    }
}

void koopa_shell_spawn_sparkles(f32 a) {
    struct Object *sp1C = spawn_object(o, MODEL_NONE, bhvSparkleSpawn);
    sp1C->oPosY += a;
}

void bhv_koopa_shell_loop(void) {
    struct Surface *sp34;

    obj_set_hitbox(o, &sKoopaShellHitbox);
    cur_obj_scale(1.0f);

    switch (o->oAction) {
        case 0:
            cur_obj_update_floor_and_walls();
            cur_obj_if_hit_wall_bounce_away();

            if (o->oInteractStatus & INT_STATUS_INTERACTED) {
                o->oAction++;
            }

            o->oFaceAngleYaw += 0x1000;
            cur_obj_move_standard(-20);
            koopa_shell_spawn_sparkles(10.0f);
            break;

        case 1:
            obj_copy_pos(o, gMarioObject);
            sp34 = cur_obj_update_floor_height_and_get_floor();

            if (absf(find_water_level(o->oPosX, o->oPosZ) - o->oPosY) < 10.0f) {
                koopa_shell_spawn_water_drop();
            } else if (absf(o->oPosY - o->oFloorHeight) < 5.0f) {
                if (sp34 != NULL && sp34->type == 1) {
                    bhv_koopa_shell_flame_spawn();
                } else {
                    koopa_shell_spawn_sparkles(10.0f);
                }
            } else {
                koopa_shell_spawn_sparkles(10.0f);
            }

            o->oFaceAngleYaw = gMarioObject->oMoveAngleYaw;

            if (o->oInteractStatus & INT_STATUS_STOP_RIDING) {
                obj_mark_for_deletion(o);
                spawn_mist_particles();
                o->oAction = 0;
            }
            break;
    }

    o->oInteractStatus = 0;
}





void bhv_cushion_shell_loop(void) {
    struct Object *obj;
    struct MarioState *m = gMarioState;
    s32 dialogId;

    obj_set_hitbox(o, &sKoopaShellHitbox);
    if (save_file_get_newflags(1) & SAVE_TOAD_FLAG_TROPHY_TWO) {
       dialogId = DIALOG_103;
    } else {
       dialogId = DIALOG_042;
    }

    switch (o->oAction) {
        case 0:
            if (o->os16104) {
                o->oAction = 2;
            }
            if (o->oDistanceToMario < 500.0f) {
                o->oInteractType = INTERACT_IGLOO_BARRIER;
                o->oAction = 1;
            }
            break;
        case 1:
            if (CL_NPC_Dialog(dialogId)) {
                o->oAction = 2;
                o->oInteractType = INTERACT_KOOPA_SHELL;
            }
            break;
        case 2:
            cur_obj_update_floor_and_walls();

            if (o->oInteractStatus & INT_STATUS_INTERACTED) {
                o->oAction = 3;
            }

            cur_obj_move_standard(-20);
            if (o->oTimer & 1) {
                koopa_shell_spawn_sparkles(10.0f);
            }
            break;

        case 3:
            obj_copy_pos(o, gMarioObject);
            cur_obj_update_floor_height_and_get_floor();

            o->oFaceAngleYaw = gMarioObject->oMoveAngleYaw;

            if (o->oInteractStatus & INT_STATUS_STOP_RIDING) {
                o->activeFlags = 0;
                spawn_mist_particles();
                obj = spawn_object(o, MODEL_CUSHION_FRIEND, bhvCushionShell);
                obj->oFlags &= ~OBJ_FLAG_DISABLE_ON_ROOM_EXIT;
                obj->os16104 = 1;
                vec3f_copy(&obj->oPosX, &o->oHomeX);
                obj->oFaceAngleYaw = 0;
                if (m->action == ACT_STAR_DANCE_WATER || m->action == ACT_STAR_DANCE_NO_EXIT) {
                    vec3f_set(&obj->oPosX, m->pos[0] + 300.0f, m->pos[1], m->pos[2]);
                    gMarioPreviousRoom = 0;
                }
            }

            if (m->pos[0] > -9000.0f && m->pos[2] > -2000.0f && m->pos[1] <= m->floorHeight) {
                o->oAction = 4;
                gMarioPreviousRoom = 0;
                mario_stop_riding_object(m);
                set_mario_action(m, ACT_JUMP, 0);
                o->oInteractType = INTERACT_IGLOO_BARRIER;
                if (cur_obj_dist_to_nearest_object_with_behavior(bhvDoor) < 200.0f) {
                    o->oPosX -= 50.0f;
                    o->oPosZ -= 150.0f;
                }
            }
            break;
        case 4:
            if (o->oDistanceToMario > 5000.0f) {
                o->activeFlags = 0;
                spawn_mist_particles();
                obj = spawn_object(o, MODEL_CUSHION_FRIEND, bhvCushionShell);
                obj->oFlags &= ~OBJ_FLAG_DISABLE_ON_ROOM_EXIT;
                // obj->os16104 = 1;
                vec3f_copy(&obj->oPosX, &o->oHomeX);
                obj->oFaceAngleYaw = 0;
            }
            break;
    }

    o->oInteractStatus = 0;
}

