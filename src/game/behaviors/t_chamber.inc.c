static struct ObjectHitbox sSawbladeHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 0,
    /* numLootCoins:      */ 2,
    /* radius:            */ 90,
    /* height:            */ 90,
    /* hurtboxRadius:     */ 90,
    /* hurtboxHeight:     */ 90,
};


void bhv_sawblade_spawn_loop(void) {
    f32 m = coss(o->oFaceAngleYaw) / sins(o->oFaceAngleYaw);
    f32 b = o->oPosZ - (o->oPosX * m);
    f32 e1 = absf((m * gMarioState->pos[0]) - gMarioState->pos[2] + b);
    f32 d = e1 / sqrtf(m*m + 1);
    f32 yDif = absf(gMarioState->pos[1] - o->oPosY);
    if (d < 500.0f && yDif < 500.0f) {
        if (o->oTimer > 60) {
            spawn_object(o, MODEL_SAWBLADE, bhvSawbladeShoot);
            o->oTimer = 0;
        }
    } else {
        o->oTimer = 0;
    }
}



void bhv_sawblade_shoot_init(void) {
    obj_set_hitbox(o, &sSawbladeHitbox);
    o->oForwardVel = 50.0f;
    o->oFaceAnglePitch = 0x4000;
    o->oBehParams2ndByte = 1;
}


void bhv_sawblade_shoot_loop(void) {
    CL_Move();
    cur_obj_update_floor_and_walls();
    if (o->oInteractStatus || o->oMoveFlags & OBJ_MOVE_HIT_WALL || o->oTimer > 180) {
        spawn_mist_particles();
        o->activeFlags = 0;
    }
}


void bhv_sawblade_move_init(void) {
    s16 param = ((o->oBehParams >> 8) & 0xFF);
    obj_set_hitbox(o, &sSawbladeHitbox);
    o->oFloatF8 = (o->oBehParams >> 24) * 10.0f;
    if (param) {
        o->os16F6 = param << 4;
    } else {
        o->os16F6 = 0x100;
    }
    CL_drop_to_floor();
    o->oBehParams2ndByte = CL_RandomMinMaxU16(0, 1);
}


void bhv_sawblade_move_loop(void) {
    // o->oFaceAngleRoll -= 0x400;
    o->os16F4 += o->os16F6;
    o->oPosX = o->oHomeX + (sins(o->os16F4) * o->oFloatF8);
    o->oPosZ = o->oHomeZ + (coss(o->os16F4) * o->oFloatF8);
    if (o->oBehParams >> 24) {
        o->oFaceAngleYaw = cur_obj_angle_to_home();
        CL_drop_to_floor();
    }

    o->oInteractStatus = 0;
}



void bhv_sawblade_line_loop(void) {
    o->os16F4 += o->os16F6;
    o->oPosX = o->oHomeX + (sins(o->os16F4) * o->oFloatF8) * sins(o->oFaceAngleYaw + 0x4000);
    o->oPosZ = o->oHomeZ + (sins(o->os16F4) * o->oFloatF8) * coss(o->oFaceAngleYaw + 0x4000);
    CL_drop_to_floor();

    o->oInteractStatus = 0;
}



void bhv_swinging_plat_loop(void) {
    o->os16F4 += 0x200;
    o->oFaceAnglePitch = -sins(o->os16F4) * 0x320;
    o->oFloatF8 = -sins(o->os16F4) * 500.0f;
    o->oPosX = o->oHomeX + (sins(o->os16F4) * 500.0f) * sins(o->oFaceAngleYaw);
    o->oPosZ = o->oHomeZ + (sins(o->os16F4) * 500.0f) * coss(o->oFaceAngleYaw);
    f32 homeD = o->oHomeX * sins(o->oFaceAngleYaw) + o->oHomeZ * coss(o->oFaceAngleYaw);
    f32 posD = o->oPosX * sins(o->oFaceAngleYaw) + o->oPosZ * coss(o->oFaceAngleYaw);
    f32 riseSqr = (homeD - posD) * (homeD - posD);
    f32 yRise = sqrtf(1440000 - riseSqr);
    o->oPosY = o->oHomeY + (1200.0f - yRise);
}




s32 f32_oscillate_toward(f32 *value, f32 *vel, f32 target, f32 velCloseToZero, f32 accel,
                            f32 slowdown) {
    f32 startValue = *value;
    *value +=  *vel;

    if (absf(*value - target) <= 10.0f
        || ((*value - target) * (startValue - target) < 0 && *vel > -velCloseToZero
            && *vel < velCloseToZero)) {
        *value = target;
        *vel = 0.0f;
        return TRUE;
    } else {
        if (*value >= target) {
            accel = -accel;
        }
        if (*vel * accel < 0.0f) {
            accel *= slowdown;
        }

        *vel += accel;
    }

    return FALSE;
}




void bhv_big_swinging_plat_loop(void) {
    // o->os16F4 += 0x200;
    // o->oFaceAnglePitch = -sins(o->os16F4) * 0x320;
    // if (gMarioObject->platform == o) {
    //     f32 x = (gMarioState->pos[0] - o->oPosX);
    //     f32 z = (gMarioState->pos[2] - o->oPosZ);
    //     o->oFloatFC = approach_f32_symmetric(o->oFloatFC, x, 3.0f);
    //     o->oFloat100 = approach_f32_symmetric(o->oFloat100, z, 3.0f);
    //     //mag
    //     o->oFloatF8 = sqrtf(o->oFloatFC*o->oFloatFC + o->oFloat100*o->oFloat100);
    //     //dir
    //     s32 angle = atan2s(o->oFloat100, o->oFloatFC);
    //     o->os16F6 = approach_s16_symmetric(o->os16F6, angle, 0x100);
    //     print_text_fmt_int(80, 50, "atan2s %x", o->os16F6);
    //     print_text_fmt_int(80, 100, "mag %d", (s32)o->oFloatF8);
    //     print_text_fmt_int(80, 140, "x %d", (s32)o->oFloatFC);
    //     print_text_fmt_int(80, 180, "z %d", (s32)o->oFloat100);
    // }
    // f32 dist = approach_f32_symmetric(dist, 1000.0f, (o->oFloatF8 / 30.0f));
    // o->oPosX = o->oHomeX + dist * sins(o->os16F6);
    // o->oPosZ = o->oHomeZ + dist * coss(o->os16F6);
    // f32 homeD = o->oHomeX * sins(o->oFaceAngleYaw) + o->oHomeZ * coss(o->oFaceAngleYaw);
    // f32 posD = o->oPosX * sins(o->oFaceAngleYaw) + o->oPosZ * coss(o->oFaceAngleYaw);
    // f32 riseSqr = (homeD - posD) * (homeD - posD);
    // f32 yRise = sqrtf(1440000 - riseSqr);
    // o->oPosY = o->oHomeY + (1200.0f - yRise);


    //x coord and z coord = angle of movement
    //magnitude that determines speed


    // if (absf(o->oSeesawPlatformPitchVel) > 10.0f) {
    //     cur_obj_play_sound_1(SOUND_ENV_BOAT_ROCKING1);
    // }

    if (gMarioObject->platform == o) {
        // Move toward mario
        f32 zVal = (o->oDistanceToMario / 2) * coss(o->oAngleToMario) * 0.02f + (o->oFloatFC - o->oPosY) * 0.3f;
        f32 xVal = (o->oDistanceToMario / 2) * sins(o->oAngleToMario) * 0.02f + (o->oFloatFC - o->oPosY) * 0.3f;
        

        o->oFloatF4 += xVal;
        o->oFloatF8 += zVal;

        o->oPosX += o->oFloatF4;
        o->oPosZ += o->oFloatF8;
        if (o->oPosX > o->oHomeX + 2000.0f) {
            o->oPosX = o->oHomeX + 2000.0f;
        } else if (o->oPosX < o->oHomeX - 2000.0f) {
            o->oPosX = o->oHomeX - 2000.0f;
        }
        if (o->oPosZ > o->oHomeZ + 2000.0f) {
            o->oPosZ = o->oHomeZ + 2000.0f;
        } else if (o->oPosZ < o->oHomeZ - 2000.0f) {
            o->oPosZ = o->oHomeZ - 2000.0f;
        }
        // clamp_f32(&o->oPosX, o->oHomeX - 2000.0f, o->oHomeX + 2000.0f);
        // clamp_f32(&o->oPosZ, o->oHomeZ - 2000.0f, o->oHomeZ + 2000.0f);
    } else {
        // Move back to 0
        f32_oscillate_toward(
            /* value          */ &o->oPosX,
            /* vel            */ &o->oFloatF4,
            /* target         */ o->oHomeX,
            /* velCloseToZero */ 6.0f,
            /* accel          */ 3.0f,
            /* slowdown       */ 3.0f);

        f32_oscillate_toward(
            /* value          */ &o->oPosZ,
            /* vel            */ &o->oFloatF8,
            /* target         */ o->oHomeZ,
            /* velCloseToZero */ 6.0f,
            /* accel          */ 3.0f,
            /* slowdown       */ 3.0f);
    }

        print_text_fmt_int(80, 140, "x %d", (s32)o->oFloatF4);
        print_text_fmt_int(80, 180, "z %d", (s32)o->oFloatF8);


    // f32 homeD = o->oHomeX * sins(o->oFaceAngleYaw) + o->oHomeZ * coss(o->oFaceAngleYaw);
    // f32 posD = o->oPosX * sins(o->oFaceAngleYaw) + o->oPosZ * coss(o->oFaceAngleYaw);
    // f32 riseSqr = (homeD - posD) * (homeD - posD);
    o->oFloatFC = o->oPosY;
    f32 xD = o->oHomeX - o->oPosX;
    f32 zD = o->oHomeZ - o->oPosZ;
    f32 riseSqr = xD*xD + zD*zD;
    f32 yRise = sqrtf(5760000 - riseSqr);
    o->oPosY = o->oHomeY + (2400.0f - yRise);
}