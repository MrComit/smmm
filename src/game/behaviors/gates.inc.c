struct ObjectHitbox sLeverHitbox = {
    /* interactType: */ INTERACT_BREAKABLE,
    /* downOffset: */ 0,
    /* damageOrCoinValue: */ 0,
    /* health: */ 1,
    /* numLootCoins: */ 0,
    /* radius: */ 90,
    /* height: */ 90,
    /* hurtboxRadius: */ 90,
    /* hurtboxHeight: */ 90,
};

Vec3f sStealerPos[6] = {
{5336.97f, 0, 12903.7f},
{4810.03f, 0, 13092.4f},
{3782.88f, 0, 13290.5f},
{4061.87f, 0, 13840.4f},
{4622.21f, 0, 13695.4f},
{5276.90f, 0, 13639.6f},
};


void bhv_lever_loop(void) {
    obj_set_hitbox(o, &sLeverHitbox);

    if (o->oF4 == 0) {
        if (save_file_get_newflags(0) & SAVE_NEW_FLAG_MUDROOM_GATE) {
            o->oF4 = 1;
            cur_obj_init_anim_and_check_if_end(1);
        }
        if (cur_obj_was_attacked_or_ground_pounded() != 0) {
            cur_obj_init_anim_and_check_if_end(1);
            play_puzzle_jingle();
            save_file_set_newflags(SAVE_NEW_FLAG_MUDROOM_GATE, 0);
            o->oF4 = 1;
        }
    }
}


void bhv_l1_gate_loop(void) {
    struct Object *obj;
    switch (o->oAction) {
        case 0:
            switch (o->oBehParams2ndByte) {
                case 0:
                    obj = cur_obj_nearest_object_with_behavior(bhvLever);
                    if (obj == NULL || obj->oF4 == 1) {
                        o->oAction = 1;
                        break;
                    }
                    if (save_file_get_newflags(0) & SAVE_NEW_FLAG_MUDROOM_GATE) {
                        o->activeFlags = 0;
                    }
                    break;
                case 1:
                    if (cur_obj_nearest_object_with_behavior(bhvShyguyBookSteal) == NULL) {
                        o->oAction = 1;
                        save_file_set_newflags(SAVE_NEW_FLAG_PARLOR_GATE, 0);
                        play_puzzle_jingle();
                        break;
                    }
                    if (save_file_get_newflags(0) & SAVE_NEW_FLAG_PARLOR_GATE) {
                        o->activeFlags = 0;
                    }
                    break;
            }
            break;
        case 1:
            o->oPosY = approach_f32(o->oPosY, o->oHomeY + 300.0f, 10.0f, 10.0f);
            if (o->oPosY == o->oHomeY + 300.0f)
                o->activeFlags = 0;
            break;
    }
}




void bhv_l1_book_init(void) {
    struct Object *obj = spawn_object(o, MODEL_SHYGUY, bhvShyguyBookSteal);
    vec3f_copy(&obj->oPosX, sStealerPos[o->oBehParams >> 24]);
}


void bhv_l1_book_loop(void) {
    switch (o->oAction) {
        case 0:
            load_object_collision_model();
            break;
        case 1:
            break;
    }
}



void bhv_shyguy_book_steal_loop(void) {
    switch (o->oAction) {
        case 0:
            cur_obj_disable();
            if (/*save_file_get_boos() & 1*/1) {
                o->oAction = 1;
                cur_obj_enable();
                o->parentObj->oFaceAngleRoll = 0x4000;
                o->parentObj->oAction = 1;
                obj_scale(o->parentObj, 0.7f);
                o->oForwardVel = 20.0f;
                o->oF8 = CL_RandomMinMaxU16(0x200, 0x800);
                o->oFC = CL_RandomMinMaxU16(20, 40);
            }
            break;
        case 1:
            o->parentObj->oPosX = o->oPosX + (100.0f * sins(o->oMoveAngleYaw));
            o->parentObj->oPosZ = o->oPosZ + (100.0f * coss(o->oMoveAngleYaw));
            o->parentObj->oPosY = o->oPosY + 140.0f;
            o->parentObj->oFaceAngleYaw = o->oMoveAngleYaw;

            cur_obj_update_floor_and_walls();
            cur_obj_move_standard(-78);
            o->oMoveAngleYaw += o->oF8;
            if (o->oTimer > o->oFC) {
                o->oF8 = CL_RandomMinMaxU16(0x200, 0x800);
                o->oFC = CL_RandomMinMaxU16(20, 40);
                o->oTimer = 0;
            }
            if (o->oInteractStatus & INT_STATUS_INTERACTED && o->oInteractStatus & INT_STATUS_WAS_ATTACKED) {
                    spawn_mist_particles();
                    obj_spawn_loot_yellow_coins(o, o->oNumLootCoins, 20.0f);
                    o->activeFlags = 0;
                    o->parentObj->activeFlags = 0;
                    create_sound_spawner(SOUND_OBJ_DYING_ENEMY1);
            }
            o->oInteractStatus = 0;
            break;
    }
}