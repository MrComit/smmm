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


void bhv_bg_asteroid_init(void) {
    o->oFloatF8 = o->oBehParams2ndByte * 10.0f;
    if (o->oBehParams2ndByte == 0) {
        o->oFloatF8 = 700.0f;
    }
    o->os16F4 = (o->oBehParams >> 24) << 8;
}



void bhv_bg_asteroid_loop(void) {
    struct Object *obj;
    o->os16F4 += 0x100;
    o->oPosX = o->oHomeX + (sins(o->os16F4) * o->oFloatF8 * sins(o->oFaceAngleYaw));
    o->oPosZ = o->oHomeZ + (sins(o->os16F4) * o->oFloatF8 * coss(o->oFaceAngleYaw));

    obj = CL_obj_nearest_object_behavior_params(bhvBoogooObject, 1 << 16);
    if (obj == NULL || obj->oFC) {
        o->oOpacity = approach_s16_symmetric(o->oOpacity, 0, 4);
        if (o->oOpacity == 0) {
            o->activeFlags = 0;
        }
    }
}


void bhv_bg_asteroid_grow_loop(void) {
    struct Object *obj;
    o->os16F4 += 0x100;
    o->header.gfx.scale[0] = 0.8f + (0.4f * sins(o->os16F4));
    cur_obj_scale(o->header.gfx.scale[0]);

    obj = CL_obj_nearest_object_behavior_params(bhvBoogooObject, 1 << 16);
    if (obj == NULL || obj->oFC) {
        o->oOpacity = approach_s16_symmetric(o->oOpacity, 0, 4);
        if (o->oOpacity == 0) {
            o->activeFlags = 0;
        }
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