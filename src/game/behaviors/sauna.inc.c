extern s16 sLavaBaseLevel;


void bhv_sauna_rock_rise_loop(void) {
    if (sLavaBaseLevel) {
        o->oPosY = approach_f32_symmetric(o->oPosY, o->oHomeY + 1000.0f, 50.0f);
    } else {
        o->oPosY = approach_f32_symmetric(o->oPosY, o->oHomeY, 50.0f);
    }
}


void bhv_bully_gate_init(void) {
    struct Object *obj = NULL;
    if (save_file_get_newflags(0) & SAVE_NEW_FLAG_SAUNA_BULLY_GATE) {
        do {
            obj = cur_obj_nearest_object_with_behavior(bhvSmallBully);
            if (obj != NULL) {
                obj->activeFlags = 0;
            }
        } while (obj != NULL);

        obj = CL_obj_nearest_object_behavior_params(bhvSaunaGrate, 0x00010000);
        if (obj != NULL) {
            obj->oBehParams2ndByte = 0;
        }

        o->activeFlags = 0;
    }
}


void bhv_bully_gate_loop(void) {
    struct Object *obj;
    switch (o->oAction) {
        case 0:
            if (cur_obj_nearest_object_with_behavior(bhvSmallBully) == NULL) {
                obj = CL_obj_nearest_object_behavior_params(bhvSaunaGrate, 0x00010000);
                if (obj != NULL && obj->oAction != 0) {
                    o->oAction = 1;
                    play_puzzle_jingle();
                    save_file_set_newflags(SAVE_NEW_FLAG_SAUNA_BULLY_GATE, 0);
                }
            }
            break;
        case 1:
            cur_obj_play_sound_1(SOUND_ENV_ELEVATOR1);
            o->oPosZ = approach_f32_symmetric(o->oPosZ, o->oHomeZ - 150.0f, 5.0f);
            if (o->oPosZ == o->oHomeZ - 150.0f) {
                o->oPosY = approach_f32_symmetric(o->oPosY, o->oHomeY + 1350.0f, 10.0f);
                if (o->oPosY == o->oHomeY + 1350.0f) {
                    o->activeFlags = 0;
                }
            }
            break;
    }
}



void bhv_sauna_grate_init(void) {
    o->oAnimState = o->os16F4 = 2;
    o->oRoom = 14;
}

void bhv_sauna_grate_loop(void) {
    if (gMarioObject->platform == o && gMarioState->pos[1] <= gMarioState->floorHeight) {
        o->os16F4--;
    }
    if (o->os16F4 < 0) {
        o->os16F4 = 0;
    }


    if (o->oBehParams2ndByte && o->oAction == 0) {
        if (gMarioObject->platform == o) {
            struct Object *obj = spawn_object(o, MODEL_BULLY, bhvSmallBully);
            obj->oPosY += 1000.0f;
            o->oAction = 1;
        }
    }

    switch (o->os16F4) {
        case 0:
            o->oPosY = approach_f32_symmetric(o->oPosY, o->oHomeY - 320.0f, 4.0f);
            break;
        case 1:
            break;
        case 2:
            o->oPosY = approach_f32_symmetric(o->oPosY, o->oHomeY, 2.5f);
            break;
    }
    o->oAnimState = o->os16F4;
    o->os16F4 = 2;
}