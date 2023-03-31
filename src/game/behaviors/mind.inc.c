static struct ObjectHitbox sFloorPeepaHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 0,
    /* numLootCoins:      */ 1,
    /* radius:            */ 90,
    /* height:            */ 60,
    /* hurtboxRadius:     */ 70,
    /* hurtboxHeight:     */ 50,
};


// Vec3s sPaintingEnemyCols[2] = {
//     {0xC7, 0xB4, 0xAD}, // h 16, s 0.13, v 0.78
//     {0xA3, 0xCE, 0xA4}, // h 121, s 0.20, v 0.80
// };


void bhv_painting_enemy_init(void) {
    // o->os16F4 = sPaintingEnemyCols[o->oBehParams2ndByte][0];
    // o->os16F6 = sPaintingEnemyCols[o->oBehParams2ndByte][1];
    // o->os16F8 = sPaintingEnemyCols[o->oBehParams2ndByte][2];
    // o->oAnimState = 1;//o->oBehParams2ndByte;
    if (o->oBehParams2ndByte) {
        o->oOpacity = 254;
        o->os16FA = 121;
    } else {
        o->oOpacity = 255;
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
                    spawn_object(o, MODEL_GOOMBA, bhvGoomba);
                } else {
                    obj = spawn_object(o, MODEL_KOOPA, bhvKoopa);
                    obj->oPosX += 50.0f;
                    obj->oPosZ += 50.0f;
                    obj->oPosY = o->oPosY;
                }
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






void bhv_floor_peepa_init(void) {
    o->oFaceAnglePitch = CL_RandomMinMaxU16(0, 0x400);
    o->oPosY -= 50.0f;

    if ((o->oBehParams >> 24) == 0) {
        o->oObjFC = CL_obj_nearest_object_behavior_params(bhvFloorPeepa, 1 << 24);
        if (o->oObjFC == NULL) {
            o->activeFlags = 0;
        }
    }
}


void bhv_floor_peepa_loop(void) {
    s32 val, val2;
    obj_set_hitbox(o, &sFloorPeepaHitbox);
    if (o->oBehParams >> 24) {
        val = o->os16F4 += 0x180;
        val2 = o->os16F6 += 0x3C0;
        // print_text_fmt_int(80, 80, "%x", (u16)o->os16F4, 0);
        if ((u16)o->os16F4 >= 0xB000 || (u16)o->os16F4 <= 0x6800) {
            o->oOpacity = approach_s16_symmetric(o->oOpacity, 255, 5);
        } else {
            o->oOpacity = approach_s16_symmetric(o->oOpacity, 100, 4);
        }
        // o->oOpacity = 180 + (sins(o->os16F4 + 0x2000) * 75);
    } else if (o->oObjFC == NULL) {
        o->activeFlags = 0;
        return;
    } else {
        val = o->oObjFC->os16F4;
        val2 = o->oObjFC->os16F6;
    }

    o->oPosY = o->oHomeY + (sins(val) * 350.0f);
    o->oFaceAnglePitch = sins(val2) * 0x400;
    o->oFaceAngleYaw += 0x500;

    if (o->oPosY <= o->oHomeY - 300.0f + (100.0f * o->oBehParams2ndByte)) {
        cur_obj_hide();
    } else {
        cur_obj_unhide();
    }

    o->oInteractStatus = 0;
}