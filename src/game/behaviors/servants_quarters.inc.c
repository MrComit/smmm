extern Vec3s gRoomColors[];

static struct ObjectHitbox sPaperHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 70,
    /* height:            */ 70,
    /* hurtboxRadius:     */ 70,
    /* hurtboxHeight:     */ 70,
};

s8 sServantsLights = 0;


//void bhv_printer_init(void) {

//}

void bhv_printer_paper_init(void) {
    o->oForwardVel = 60.0f;
    obj_set_hitbox(o, &sPaperHitbox);
}


void bhv_printer_paper_loop(void) {
    CL_Move();
    cur_obj_update_floor_and_walls();
    if (o->oMoveFlags & OBJ_MOVE_HIT_WALL || o->oMoveFlags & OBJ_MOVE_ON_GROUND 
    || o->oInteractStatus & INT_STATUS_INTERACTED || o->oTimer > 90) {
        o->activeFlags = 0;
        spawn_mist_particles();
        create_sound_spawner(SOUND_GENERAL_HAUNTED_CHAIR_MOVE);
    }
}

void bhv_printer_loop(void) {
    struct Object *obj;
    if (cur_obj_is_mario_ground_pounding_platform()) {
        o->oNumLootCoins = -1;
        o->oHealth = 0;
        obj_die_if_health_non_positive();
        obj_explode_and_spawn_coins(46.0f, 1);
        create_sound_spawner(SOUND_GENERAL_BREAK_BOX);
    }

    if (o->oDistanceToMario < 2500.0f && o->oDistanceToMario > 400.0f) {
        o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x60);
        if (o->oTimer > 38) {
            obj = spawn_object(o, MODEL_PRINTER_PAPER, bhvPrinterPaper);
            obj->oMoveAngleYaw = (obj->oFaceAngleYaw = o->oMoveAngleYaw);
            obj->oPosY += 55.0f;
            o->oTimer = 0;
        }
    }
}




void bhv_pressure_plate_init(void) {
   //o->os16F4 = 170;
   //o->os16F6 = 170;
   //o->os16F8 = 170;
   vec3s_set(&o->os16F4, 100, 100, 100);
}

void bhv_pressure_plate_loop(void) {
    switch (o->oAction) {
        case 0:
            o->oPosY = approach_f32(o->oPosY, o->oHomeY, 2.5f, 2.5f);
            if (gMarioObject->platform == o) {
                o->oAction = 1;
                sServantsLights = 1;
            }
            gRoomColors[5][0] = approach_s16_symmetric(gRoomColors[5][0], 16, 0x1);
            gRoomColors[5][2] = (gRoomColors[5][1] = gRoomColors[5][0]);
            o->os16F4 = approach_s16_symmetric(o->os16F4, 100, 0x10);
            o->os16F6 = (o->os16F8 = o->os16F4);
            break;
        case 1:
            o->oPosY = approach_f32(o->oPosY, o->oHomeY - 10.0f, 2.5f, 2.5f);
            gRoomColors[5][0] = approach_s16_symmetric(gRoomColors[5][0], 180, 20);
            gRoomColors[5][2] = (gRoomColors[5][1] = gRoomColors[5][0]);
            o->os16F4 = approach_s16_symmetric(o->os16F4, 255, 0x10);
            o->os16F6 = (o->os16F8 = o->os16F4);
            if (gMarioObject->platform != o) {
                o->oAction = 0;
                sServantsLights = 0;
            }
            break;
    }
}


void bhv_bouncy_bed_init(void) {
   o->oFloatFC = 1.0f;
   o->os16F4 = 255;
   o->os16F6 = 255;
   o->os16F8 = 255;
}

//CBCD9B
//576771
void bhv_bouncy_bed_loop(void) {
    struct MarioState *m = gMarioState;
    o->o100 += 0x200;
    o->os16F4 = 145 + (s8)(sins(o->o100) * 58);
    o->os16F6 = 154 + (s8)(sins(o->o100) * 51);
    o->os16F8 = 134 + (s8)(sins(o->o100) * 21);

    switch (o->oAction) {
        case 0:
            if (gMarioObject->platform == o) {
                play_sound(SOUND_ACTION_BOUNCE_OFF_OBJECT, m->marioObj->header.gfx.cameraToObject);
                m->pos[1] = m->floorHeight + 20.0f;
                m->vel[1] = 80.0f;
                m->flags & MARIO_UNKNOWN_08;
                reset_mario_pitch(m);
                play_sound(SOUND_MARIO_TWIRL_BOUNCE, m->marioObj->header.gfx.cameraToObject);
                drop_and_set_mario_action(m, ACT_TWIRLING, 0);
                o->oAction = 1;
            }
            break;
        case 1:
            o->oFloatFC -= 0.15f;
            o->header.gfx.scale[1] = o->oFloatFC;
            o->header.gfx.scale[0] = approach_f32(o->header.gfx.scale[0], 1.1f, 0.04f, 0.04f);
            o->header.gfx.scale[2] = o->header.gfx.scale[0];
            if (o->oFloatFC <= 0.6f) {
                o->oFloatFC = 0.6f;
                o->oAction = 2;
            }
            break;
        case 2:
            o->oFloatFC += 0.18f;
            o->header.gfx.scale[1] = o->oFloatFC;
            o->header.gfx.scale[0] = approach_f32(o->header.gfx.scale[0], 0.8f, 0.07f, 0.07f);
            o->header.gfx.scale[2] = o->header.gfx.scale[0];
            if (o->oFloatFC >= 1.4f) {
                o->oFloatFC = 1.4f;
                o->oAction = 3;
            }
            break;
        case 3:
            o->oFloatFC -= 0.08f;
            o->header.gfx.scale[0] = approach_f32(o->header.gfx.scale[0], 1.0f, 0.04f, 0.04f);
            o->header.gfx.scale[2] = o->header.gfx.scale[0];
            if (o->oFloatFC <= 1.0f) {
                o->header.gfx.scale[0] = (o->header.gfx.scale[2] = 1.0f);
                o->oFloatFC = 1.0f;
                o->oAction = 0;
            }
            o->header.gfx.scale[1] = o->oFloatFC;
            break;
    }
}






void bhv_servants_flame_init(void) {
    o->os16F4 = 0;
    o->os16F6 = 0;
    o->os16F8 = 0; //alpha = 200?
}


void bhv_servants_flame_loop(void) {
    if (sServantsLights) {
        o->os16F4 = approach_s16_symmetric(o->os16F4, 255, 0x20);
        o->os16F6 = approach_s16_symmetric(o->os16F6, 50, 0x6);
    } else {
        o->os16F4 = approach_s16_symmetric(o->os16F4, 0, 0x20);
        o->os16F6 = approach_s16_symmetric(o->os16F6, 0, 0x6);
    }
}