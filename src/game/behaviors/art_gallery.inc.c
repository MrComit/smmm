static struct ObjectHitbox sMiniShyguyHitbox = {
    /* interactType:      */ INTERACT_BOUNCE_TOP,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 80,
    /* height:            */ 50,
    /* hurtboxRadius:     */ 100,
    /* hurtboxHeight:     */ 60,
};


// Vec3s sPaintingEnemyCols[2] = {
//     {0xC7, 0xB4, 0xAD}, // h 16, s 0.13, v 0.78
//     {0xA3, 0xCE, 0xA4}, // h 121, s 0.20, v 0.80
// };


void bhv_mini_shyguy_init(void) {
    obj_set_hitbox(o, &sMiniShyguyHitbox);
    o->oOpacity = 0xFF;
}


void bhv_mini_shyguy_loop(void) {
    struct Object *obj;
    // cur_obj_scale(o->oGoombaScale);
    cur_obj_update_floor_and_walls();
    // goomba_act_walk();
    if (o->oDistanceToMario < 1000.0f) {
        o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x600);
        o->oForwardVel = approach_f32_symmetric(o->oForwardVel, 20.0f, 2.0f);
    } else {
        o->oMoveAngleYaw = 0x4000;
        o->oForwardVel = approach_f32_symmetric(o->oForwardVel, 40.0f, 1.0f);
    }
    cur_obj_move_standard(-78);
    if (o->oInteractStatus & INT_STATUS_INTERACTED || o->oTimer > 180) {
            spawn_mist_particles();
            o->activeFlags = 0;
            create_sound_spawner(SOUND_OBJ_DYING_ENEMY1);
    }
    o->oInteractStatus = 0;
}



void bhv_painting_enemy_respawn_loop(void) {
    struct Object *obj;
    f32 m, b, e1, d, yDif;
    switch (o->oAction) {
        case 0:
            m = coss(o->oFaceAngleYaw) / sins(o->oFaceAngleYaw);
            b = o->oPosZ - (o->oPosX * m);
            e1 = absf((m * gMarioState->pos[0]) - gMarioState->pos[2] + b);
            d = e1 / sqrtf(m*m + 1);
            yDif = absf(gMarioState->pos[1] - o->oPosY);
            if (gMarioState->pos[0] < -20000.0f && d < 500.0f && yDif < 500.0f && o->oTimer > 20) {
                o->oAction = 1;
                obj = spawn_object(o, MODEL_BG_SHYGUY, bhvMiniShyguy);
                obj->parentObj = obj;
                obj->oFaceAngleYaw = obj->oMoveAngleYaw += 0x8000;
                // o->oFlags &= ~OBJ_FLAG_DISABLE_TO_ROOM_CLEAR;
            }

            o->oFloatFC = approach_f32_symmetric(o->oFloatFC, 0.16f, 0.01f);
            o->oFloat100 = approach_f32_symmetric(o->oFloat100, 0.8f, 0.05f);

            CL_HSVtoRGB(o->os16FA, o->oFloatFC, o->oFloat100, &o->os16F4, &o->os16F6, &o->os16F8);
            break;
        case 1:
            o->oFloatFC = approach_f32_symmetric(o->oFloatFC, 0.0f, 0.01f);
            o->oFloat100 = approach_f32_symmetric(o->oFloat100, 0.0f, 0.05f);

            CL_HSVtoRGB(o->os16FA, o->oFloatFC, o->oFloat100, &o->os16F4, &o->os16F6, &o->os16F8);

            if (o->oTimer > 25) {
                o->oAction = 0;
            }
            break;
    }
}









void bhv_painting_enemy_init(void) {
    // o->os16F4 = sPaintingEnemyCols[o->oBehParams2ndByte][0];
    // o->os16F6 = sPaintingEnemyCols[o->oBehParams2ndByte][1];
    // o->os16F8 = sPaintingEnemyCols[o->oBehParams2ndByte][2];
    o->oAnimState = o->oBehParams2ndByte;
    o->oOpacity = 255;
    if (o->oBehParams2ndByte == 2) {
        o->os16FA = 0;
    } else if (o->oBehParams2ndByte == 1) {
        o->os16FA = 121;
    } else {
        o->os16FA = 16;
    }
    o->oFloatFC = 0.16f;
    o->oFloat100 = 0.8f;

    CL_HSVtoRGB(o->os16FA, o->oFloatFC, o->oFloat100, &o->os16F4, &o->os16F6, &o->os16F8);
}



void bhv_painting_enemy_loop(void) {
    struct Object *obj;
    switch (o->oAction) {
        case 0:
            if (o->oDistanceToMario < 1000.0f) {
                o->oAction = 1;
                if (o->oBehParams2ndByte == 0) {
                    obj = spawn_object(o, MODEL_BG_GOOMBA, bhvGoomba);
                } else {
                    obj = spawn_object(o, MODEL_BG_KOOPA, bhvKoopa);
                    obj->oPosX += 50.0f;
                    obj->oPosZ += 50.0f;
                    obj->oPosY = o->oPosY;
                }
                obj->oFaceAngleYaw = obj->oMoveAngleYaw += 0x8000;
                o->oFlags &= ~OBJ_FLAG_DISABLE_TO_ROOM_CLEAR;
            }
            break;
        case 1:
            o->oFloatFC = approach_f32_symmetric(o->oFloatFC, 0.0f, 0.01f);
            o->oFloat100 = approach_f32_symmetric(o->oFloat100, 0.0f, 0.05f);

            CL_HSVtoRGB(o->os16FA, o->oFloatFC, o->oFloat100, &o->os16F4, &o->os16F6, &o->os16F8);
            break;
    }
}