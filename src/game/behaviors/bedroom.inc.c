Vec3f sBedroomFlamePos[4] = {
{-5472.36f, 100.0f, -10234.8f},
{-5472.36f, 100.0f, -12334.8f},
{-7572.36f, 100.0f, -12334.8f},
{-7572.36f, 100.0f, -10234.8f},
};

u32 sBedroomFlameCol[4] = {0x00802000, 0x96008F00, 0x58009600, 0x96690000};

static void const *sBedroomObjectCol[] = {
    bedroom_object_collision1, bedroom_object_collision2,
    bedroom_object_collision2, bedroom_object_collision3,
};


void bhv_bedroom_trigger_loop(void) {
    if (obj_check_if_collided_with_object(o, gMarioObject) == 1) {
        play_sound(SOUND_MENU_STAR_SOUND, gGlobalSoundSource);
        // o->activeFlags = 0;
        o->oAction = 2;
    }
}

void bhv_bedroom_object_init(void) {
    o->collisionData = segmented_to_virtual(sBedroomObjectCol[o->oBehParams2ndByte]);
    o->oOpacity = 255;
}


void bhv_bedroom_object_loop(void) {
    if (gMarioCurrentRoom != o->oRoom) {
        return;
    }
    switch (o->oAction) {
        case 0:
            if (CL_obj_find_nearest_object_with_behavior_room(o, bhvShyguyFlame, o->oRoom) == NULL) {
                o->oAction = 1;
            }
            load_object_collision_model();
            break;
        case 1:
            o->oOpacity = approach_s16_symmetric(o->oOpacity, 130, 6);
            bhv_bedroom_trigger_loop();
            break;
        case 2:
            o->oOpacity = approach_s16_symmetric(o->oOpacity, 0, 24);
            if (o->oOpacity == 0) {
                o->activeFlags = 0;
            }
            break;

    }
}



void bhv_l2_bedroom_gate_loop(void) {
    struct Object *obj;
    switch (o->oAction) {
        case 0:
            if (gMarioCurrentRoom == o->oRoom) {
                o->oAction = 1;
            }
            break;
        case 1:
            //o->oPosY = approach_f32(o->oPosY, o->oHomeY - 300.0f, 20.0f, 20.0f);
            if (o->oBehParams2ndByte != 3) {
                obj = CL_obj_nearest_object_behavior_params(bhvBedroomObject, o->oBehParams2ndByte << 16);
                if (obj == NULL) {
                    o->oAction = 2;
                }
            } else {
                if (save_file_get_boos() & (1 << 8) && save_file_get_keys(0) & (1 << 4)) {
                    o->oAction = 2;
                }
            }
            break;
        case 2:
            o->oPosY = approach_f32(o->oPosY, o->oHomeY + 300.0f, 20.0f, 20.0f);
            if (o->oPosY == o->oHomeY + 300.0f)
                o->activeFlags = 0;
            break;
    }
}



void bhv_shyguy_flame_init(void) {
    s16 param = o->oBehParams >> 24;
    if (save_file_check_room(o->oRoom + sLevelRoomOffsets[gCurrCourseNum - 1])) {
        return;
    }
    o->oObj110 = spawn_object(o, MODEL_ENV_FLAME, bhvHeldEnvFlame);
    o->oObj110->oFlags &= ~OBJ_FLAG_DISABLE_ON_ROOM_EXIT;
    o->oObj110->oBehParams = sBedroomFlameCol[param];
    //vec3f_copy(&o->oObj110->oPosX, sBedroomFlamePos[param]);
    o->oOpacity = 0;
}


void bhv_shyguy_flame_loop(void) {
    s16 param = o->oBehParams >> 24;
    f32 dist = o->oDistanceToMario;
    if (o->oObj110 == NULL) {
        o->activeFlags = 0;
        return;
    }
    cur_obj_scale(o->oGoombaScale);
    cur_obj_update_floor_and_walls();
    goomba_act_walk();
    cur_obj_move_standard(-78);

    if (dist < 50.0f)
        dist = 50.0f;

    o->oOpacity = 255 * (50.0f / dist);

    o->oObj110->oPosX = o->oPosX + (sins(o->oFaceAngleYaw) * 50.0f);
    o->oObj110->oPosZ = o->oPosZ + (coss(o->oFaceAngleYaw) * 50.0f);
    o->oObj110->oPosY = o->oPosY + 60.0f;

    if (o->oInteractStatus & INT_STATUS_INTERACTED && o->oInteractStatus & INT_STATUS_WAS_ATTACKED) {
        //spawn_mist_particles();
        obj_spawn_loot_yellow_coins(o, o->oNumLootCoins, 20.0f);
        o->activeFlags = 0;
        create_sound_spawner(SOUND_OBJ_DYING_ENEMY1);
        o->oObj110->activeFlags = 0;
        o->oObj110 = spawn_object(o, MODEL_ENV_FLAME, bhvEnvFlame);
        o->oObj110->oFlags &= ~OBJ_FLAG_DISABLE_ON_ROOM_EXIT;
        o->oObj110->oBehParams = sBedroomFlameCol[param];
        vec3f_copy(&o->oObj110->oPosX, sBedroomFlamePos[param]);
    }
    o->oInteractStatus = 0;
}