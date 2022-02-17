static struct ObjectHitbox sDiceEnemyHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 0,
    /* numLootCoins:      */ 1,
    /* radius:            */ 70,
    /* height:            */ 100,
    /* hurtboxRadius:     */ 70,
    /* hurtboxHeight:     */ 100,
};


void dice_enemy_move(void) {
    cur_obj_update_floor_and_walls();
    cur_obj_init_animation_with_accel_and_sound(o->oBehParams2ndByte, 0.6f + o->oAnimState / 3.0f);
    // treat_far_home_as_mario(3000.0f);

    if (o->oGoombaTurningAwayFromWall) {
        o->oGoombaTurningAwayFromWall = obj_resolve_collisions_and_turn(o->oGoombaTargetYaw, 0x200);
    } else {
        if (o->oDistanceToMario >= 25000.0f) {
            o->oGoombaTargetYaw = o->oAngleToMario;
            o->oGoombaWalkTimer = random_linear_offset(20, 30);
        }
        if (!(o->oGoombaTurningAwayFromWall =
                  obj_bounce_off_walls_edges_objects(&o->oGoombaTargetYaw))) {
            if (o->oDistanceToMario < 1000.0f) {
                if (o->oTimer > o->os1610E) {
                    o->os1610C = (random_float() - 0.5f) * 0x2000;
                    o->os1610E = CL_RandomMinMaxU16(20, 90);
                    o->oTimer = 0;
                }
                o->oGoombaTargetYaw = o->oAngleToMario + o->os1610C;
                o->oForwardVel = 5.0f + o->oAnimState * 2.0f;
            } else {
                o->oForwardVel = 4.0f;

                if (o->oGoombaWalkTimer != 0) {
                    o->oGoombaWalkTimer--;
                } else {
                    if (random_u16() & 3) {
                        o->oGoombaTargetYaw = obj_random_fixed_turn(0x2000);
                        o->oGoombaWalkTimer = random_linear_offset(100, 100);
                    } else {
                        o->oGoombaTargetYaw = obj_random_fixed_turn(0x6000);
                    }
                }
            }
        }

        cur_obj_rotate_yaw_toward(o->oGoombaTargetYaw, 0x200 + o->oAnimState * 0x80);
    }
    cur_obj_move_standard(-78);
}

void bhv_dice_enemy_init(void) {
    obj_set_hitbox(o, &sDiceEnemyHitbox);
    o->oAnimState = o->oBehParams2ndByte;
    o->os16F6 = 0;
}


void bhv_dice_enemy_loop(void) {
    struct Object *obj;
    s32 i;
    // o->oAnimState = o->oBehParams2ndByte;
    if (o->oAnimState) {
        o->oInteractType = INTERACT_DAMAGE;
        o->os16F4 = approach_s16_symmetric(o->os16F4, 0xFF, 0x24);
        o->os16F8 = approach_s16_symmetric(o->os16F8, 0, 0x24);
    } else {
        o->oInteractType = INTERACT_BOUNCE_TOP;
        o->os16F8 = approach_s16_symmetric(o->os16F8, 0xFF, 0x24);
        o->os16F4 = approach_s16_symmetric(o->os16F4, 0, 0x24);
        if (o->oInteractStatus & INT_STATUS_WAS_ATTACKED) {
            o->activeFlags = 0;
            obj_spawn_loot_yellow_coins(o, o->oNumLootCoins, 20.0f);
            for (i = 0; i < 6 - o->oBehParams2ndByte; i++) {
                obj = CL_nearest_object_with_behavior_and_field(bhvDiceEnemy, 0x188, (o->oBehParams & 0xFF000000) + (i << 16));
                if (obj != NULL) {
                    obj->oBehParams -= 0x10000;
                    obj->oAnimState -= 1;
                }
            }
        }
    }
    dice_enemy_move();
    o->oInteractStatus = 0;
}