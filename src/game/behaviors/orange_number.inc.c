// orange_number.inc.c


void bhv_orange_number_stay_loop(void) {
    if (o->oF4) {
        vec3f_set(&o->oHomeX, o->parentObj->oPosX, o->parentObj->oPosY + 175.0f, o->parentObj->oPosZ);
        o->oPosY = o->oHomeY;
    } else {
        vec3f_set(&o->oPosX, o->parentObj->oPosX, o->parentObj->oPosY + 175.0f, o->parentObj->oPosZ);
    }

    if (o->oTimer >= 10) {
        o->activeFlags = 0;
    }
    if (o->oF4 == 1) {
        o->oPosX = o->oHomeX + (sins(gCamera->yaw + 0x4000) * o->oFloatF8);
        o->oPosZ = o->oHomeZ + (coss(gCamera->yaw + 0x4000) * o->oFloatF8);
    } else if (o->oF4 == 2) {
        o->oPosX = o->oHomeX + (sins(gCamera->yaw - 0x4000) * o->oFloatF8);
        o->oPosZ = o->oHomeZ + (coss(gCamera->yaw - 0x4000) * o->oFloatF8);
    } else if (o->oF4 == 3) {
        o->oPosX = o->oHomeX + (sins(gCamera->yaw) * o->oFloatF8);
        o->oPosZ = o->oHomeZ + (coss(gCamera->yaw) * o->oFloatF8);
    }
}


void bhv_orange_number_init(void) {
    o->oAnimState = o->oBehParams2ndByte;
    o->oVelY = 26.0f;
}

void bhv_orange_number_loop(void) {
    o->oPosY += o->oVelY;
    o->oVelY -= 2.0f;

    if (o->oVelY < -21.0f) {
        o->oVelY = 14.0;
    }

    if (o->oTimer == 35) {
        struct Object *sp1C = spawn_object(o, MODEL_SPARKLES, bhvGoldenCoinSparkles);
        sp1C->oPosY -= 30.0f;
        o->activeFlags = ACTIVE_FLAG_DEACTIVATED;
    }
    if (o->oF4 == 1) {
        o->oPosX = o->oHomeX + (sins(gCamera->yaw + 0x4000) * o->oFloatF8);
        o->oPosZ = o->oHomeZ + (coss(gCamera->yaw + 0x4000) * o->oFloatF8);
    } else if (o->oF4 == 2) {
        o->oPosX = o->oHomeX + (sins(gCamera->yaw - 0x4000) * o->oFloatF8);
        o->oPosZ = o->oHomeZ + (coss(gCamera->yaw - 0x4000) * o->oFloatF8);
    } else if (o->oF4 == 3) {
        o->oPosX = o->oHomeX + (sins(gCamera->yaw) * o->oFloatF8);
        o->oPosZ = o->oHomeZ + (coss(gCamera->yaw) * o->oFloatF8);
    }
}
