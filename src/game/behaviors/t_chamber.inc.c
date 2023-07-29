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



void bhv_jumpscare_shyguy_init(void) {
    o->oObjF8 = cur_obj_nearest_object_with_behavior(bhvJSShyguyManager);
    if (o->oObjF8 == NULL) {
        o->activeFlags = 0;
    }
    if (!gIsConsole) {
        o->header.gfx.scale[0] = (random_float() + 0.75f) * 3.0f;
        o->header.gfx.scale[1] = (random_float() + 0.75f) * 3.0f;
        o->header.gfx.scale[2] = (random_float() + 0.75f) * 3.0f;
    } else {
        o->header.gfx.scale[0] = 1.0f;
        o->header.gfx.scale[1] = o->header.gfx.scale[2] = o->header.gfx.scale[0];
    }
    o->header.gfx.animInfo.animFrame = CL_RandomMinMaxU16(0, 10);
    o->os16104 = random_u16();
}

void bhv_jumpscare_shyguy_loop(void) {
    struct Object *obj;
    o->os16104 += 0x5D1;
    o->oFaceAnglePitch = 0x888 + (sins(o->os16104 - 0x4000) * 0x888);
    switch (o->oAction) {
        case 0:
            if (o->oTimer <= 60) {
                o->oOpacity = approach_s16_symmetric(o->oOpacity, 0xFF, 0x10);
            } else {
                o->oFloatF4 = approach_f32_symmetric(o->oFloatF4, 30.0f, 0.6f);
                o->oPosZ -= o->oFloatF4;
                if (gMarioState->pos[2] < -13200.0f) {
                    o->oAction = 1;
                }
                if (o->oBehParams2ndByte) {
                    if (gMarioState->pos[2] > o->oPosZ || gMarioState->pos[1] < -2000.0f) {
                        if (o->oObjF8 != NULL) {
                            o->oObjF8->oAction = 3;
                        }
                        o->oBehParams2ndByte = 0;
                        play_transition(WARP_TRANSITION_FADE_INTO_COLOR, 10, 0x00, 0x00, 0x00);
                    }
                }
                if (o->oObjF8 == NULL || o->oObjF8->os16100) {
                    o->activeFlags = 0;
                }
            }
            break;
        case 1:
            o->oOpacity = approach_s16_symmetric(o->oOpacity, 0, 0x10);
            if (o->oOpacity == 0) {
                o->activeFlags = 0;
            }
            break;
    }
}


void spawn_chamber_shyguys(f32 xPos, f32 yPos, f32 zPos) {
    struct Object *obj;
    s32 i, k;
    for (i = 0; i < 3; i++) {
        if (!gIsConsole) {
            for (k = 0; k < 5; k++) {
                obj = spawn_object(o, MODEL_SHYGUY, bhvJumpscareShyguy);
                obj->oPosX = xPos - (k * 300.0f);
                if (i == 1) {
                    obj->oPosX -= 100.0f;
                }
                if ((i | k) == 0) {
                    obj->oBehParams2ndByte = 1;
                }
                obj->oPosY = yPos + (i * 100.0f);
                obj->oPosZ = zPos + (i * 150.0f);
            }
        } else {
                obj = spawn_object(o, MODEL_SHYGUY_GROUP, bhvJumpscareShyguy);
                // obj->oPosX = xPos - (k * 300.0f);
                if (i == 1) {
                    obj->oPosX -= 100.0f;
                }
                if (i == 0) {
                    obj->oBehParams2ndByte = 1;
                }
                obj->oPosY = yPos + (i * 100.0f);
                obj->oPosZ = zPos + (i * 150.0f);
        }
    }
}


void chamber_contain_mario(struct MarioState *m) {
    if (m->pos[0] < 8100.0f) {
        m->pos[0] = 8100.0f;
    } else if (m->pos[0] > 9400.0f) {
        m->pos[0] = 9400.0f;
    }

    if (m->pos[2] < -14300.0f) {
        m->pos[2] = -14300.0f;
    } else if (m->pos[2] > -13100.0f) {
        m->pos[2] = -13100.0f;
    }
}


void bhv_js_shyguy_manager_init(void) {
    vec3f_set(&o->oFloatF4, 8897.0f, 100.0f, -4122.0f);
    o->oPosY -= 100.0f;
}

void bhv_js_shyguy_manager_loop(void) {
    struct Object *obj;
    struct MarioState *m = gMarioState;
    f32 dist;
    switch (o->oAction) {
        case 0:
            if (m->pos[1] < 1000.0f && lateral_dist_between_objects(o, gMarioObject) < 300.0f) {
                o->oAction = 1;
                cur_obj_play_sound_2(SOUND_OBJ_BOO_LAUGH_LONG);
                cur_obj_play_sound_2(SOUND_ACTION_BOUNCE_OFF_OBJECT);
            } else if (m->pos[1] < -300.0f && cur_obj_nearest_object_with_behavior(bhvCrumbleFloor) == NULL) {
                o->oAction = 2;
                o->os16100 = 0;
                spawn_chamber_shyguys(o->oPosX + 600.0f, o->oHomeY - 1700.0f, o->oPosZ);
            }
            break;
        case 1:
            o->oOpacity = approach_s16_symmetric(o->oOpacity, 255, 0x18);
            o->oPosY = approach_f32_symmetric(o->oPosY, o->oHomeY, 30.0f);

            m->pos[0] = approach_f32_symmetric(m->pos[0], o->oFloatF4, 80.0f);
            m->pos[1] = approach_f32_symmetric(m->pos[1], o->oFloatF8, 40.0f);
            m->pos[2] = approach_f32_symmetric(m->pos[2], o->oFloatFC, 80.0f);
            CL_dist_between_points(m->pos, &o->oFloatF4, &dist);
            if (dist < 200.0f) {
                obj = cur_obj_nearest_object_with_behavior(bhvCrumbleFloor);
                if (obj != NULL) {
                    obj->oAction = 1;
                }
                o->oAction = 2;
                o->os16100 = 0;
                spawn_chamber_shyguys(o->oPosX + 600.0f, o->oPosY - 1700.0f, o->oPosZ);
            }
            break;
        case 2:
            if (o->oTimer < 30) {
                m->pos[0] = approach_f32_symmetric(m->pos[0], o->oFloatF4, 80.0f);
                m->pos[2] = approach_f32_symmetric(m->pos[2], o->oFloatFC, 80.0f);
            }
            if (m->pos[1] < -300.0f) {
                gCamera->comitCutscene = 18;
                if ((o->oTimer & 0xF) == 0) {
                    cur_obj_play_sound_1(SOUND_OBJ_MAD_PIANO_CHOMPING);
                }
            }
            if (m->pos[2] < -13200.0f) {
                o->oAction = 4;
            }
            break;
        case 3:
            if (o->oTimer > 13) {
                m->hurtCounter = 4;
                vec3f_set(m->pos, 10709.0f, 1705.0f, -3420.0f);
                m->faceAngle[1] = 0xC000;
                set_r_button_camera(gCamera);
                s8DirModeBaseYaw = m->faceAngle[1] + 0x8000;
                gCamera->comitCutscene = 0;
                play_transition(WARP_TRANSITION_FADE_FROM_COLOR, 5, 0x00, 0x00, 0x00);
                o->oAction = 0;
                o->os16100 = 1;
                o->oOpacity = 0;
                o->oPosY -= 100.0f;
            }
            break;
        case 4:
            chamber_contain_mario(m);
            if (m->action == ACT_TELEPORT_FADE_OUT) {
                o->activeFlags = 0;
            }
            break;
    }
}




void bhv_crumble_floor_loop(void) {
    struct Object *explosion;
    switch (o->oAction) {
        case 0:
            if (gMarioObject->platform == o) {
                o->oPosY += o->oFloatF4;
                o->oFloatF4 *= -1;
            }
            break;
        case 1:
            // CL_explode_object(o, 1);
            explosion = spawn_object(o, MODEL_EXPLOSION, bhvExplosion);
            explosion->oIntangibleTimer = -1;
            o->activeFlags = 0;
            break;
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


void bhv_big_swinging_plat_init(void) {
    o->oPosZ += -1500.0f;
    o->os16F4 = 0xC000;
}


void bhv_big_swinging_plat_loop(void) {
    switch (o->oAction) {
        case 0:
            if (gMarioObject->platform == o) {
                if (o->oTimer > 20) {
                    o->oAction = 1;
                    cur_obj_play_sound_1(SOUND_ENV_BOAT_ROCKING1);
                }
            } else {
                o->oTimer = 0;
            }
            break;
        case 1:
            o->os16F4 += 0x100;
            // o->oFaceAnglePitch = -sins(o->os16F4) * 0x640;
            o->oPosZ = o->oHomeZ + sins(o->os16F4) * 1500.0f;
            break;
    }
    f32 zD = o->oHomeZ - o->oPosZ;
    f32 riseSqr = zD * zD;
    f32 yRise = sqrtf(5760000 - riseSqr);
    o->oPosY = o->oHomeY + (2400.0f - yRise);
}






// s32 f32_oscillate_toward(f32 *value, f32 *vel, f32 target, f32 velCloseToZero, f32 accel,
//                             f32 slowdown) {
//     f32 startValue = *value;
//     *value +=  *vel;

//     if (absf(*value - target) <= 10.0f
//         || ((*value - target) * (startValue - target) < 0 && *vel > -velCloseToZero
//             && *vel < velCloseToZero)) {
//         *value = target;
//         *vel = 0.0f;
//         return TRUE;
//     } else {
//         if (*value >= target) {
//             accel = -accel;
//         }
//         if (*vel * accel < 0.0f) {
//             accel *= slowdown;
//         }

//         *vel += accel;
//     }

//     return FALSE;
// }


// void bhv_big_swinging_plat_loop(void) {
//     // o->os16F4 += 0x200;
//     // o->oFaceAnglePitch = -sins(o->os16F4) * 0x320;
//     // if (gMarioObject->platform == o) {
//     //     f32 x = (gMarioState->pos[0] - o->oPosX);
//     //     f32 z = (gMarioState->pos[2] - o->oPosZ);
//     //     o->oFloatFC = approach_f32_symmetric(o->oFloatFC, x, 3.0f);
//     //     o->oFloat100 = approach_f32_symmetric(o->oFloat100, z, 3.0f);
//     //     //mag
//     //     o->oFloatF8 = sqrtf(o->oFloatFC*o->oFloatFC + o->oFloat100*o->oFloat100);
//     //     //dir
//     //     s32 angle = atan2s(o->oFloat100, o->oFloatFC);
//     //     o->os16F6 = approach_s16_symmetric(o->os16F6, angle, 0x100);
//     //     print_text_fmt_int(80, 50, "atan2s %x", o->os16F6, 0);
//     //     print_text_fmt_int(80, 100, "mag %d", (s32)o->oFloatF8, 0);
//     //     print_text_fmt_int(80, 140, "x %d", (s32)o->oFloatFC, 0);
//     //     print_text_fmt_int(80, 180, "z %d", (s32)o->oFloat100, 0);
//     // }
//     // f32 dist = approach_f32_symmetric(dist, 1000.0f, (o->oFloatF8 / 30.0f));
//     // o->oPosX = o->oHomeX + dist * sins(o->os16F6);
//     // o->oPosZ = o->oHomeZ + dist * coss(o->os16F6);
//     // f32 homeD = o->oHomeX * sins(o->oFaceAngleYaw) + o->oHomeZ * coss(o->oFaceAngleYaw);
//     // f32 posD = o->oPosX * sins(o->oFaceAngleYaw) + o->oPosZ * coss(o->oFaceAngleYaw);
//     // f32 riseSqr = (homeD - posD) * (homeD - posD);
//     // f32 yRise = sqrtf(1440000 - riseSqr);
//     // o->oPosY = o->oHomeY + (1200.0f - yRise);


//     //x coord and z coord = angle of movement
//     //magnitude that determines speed


//     // if (absf(o->oSeesawPlatformPitchVel) > 10.0f) {
//     //     cur_obj_play_sound_1(SOUND_ENV_BOAT_ROCKING1);
//     // }

//     if (gMarioObject->platform == o) {
//         // Move toward mario
//         f32 zVal = (o->oDistanceToMario / 2) * coss(o->oAngleToMario) * 0.02f + (o->oFloatFC - o->oPosY) * 0.3f;
//         f32 xVal = (o->oDistanceToMario / 2) * sins(o->oAngleToMario) * 0.02f + (o->oFloatFC - o->oPosY) * 0.3f;
        

//         o->oFloatF4 += xVal;
//         o->oFloatF8 += zVal;

//         o->oPosX += o->oFloatF4;
//         o->oPosZ += o->oFloatF8;
//         if (o->oPosX > o->oHomeX + 2000.0f) {
//             o->oPosX = o->oHomeX + 2000.0f;
//         } else if (o->oPosX < o->oHomeX - 2000.0f) {
//             o->oPosX = o->oHomeX - 2000.0f;
//         }
//         if (o->oPosZ > o->oHomeZ + 2000.0f) {
//             o->oPosZ = o->oHomeZ + 2000.0f;
//         } else if (o->oPosZ < o->oHomeZ - 2000.0f) {
//             o->oPosZ = o->oHomeZ - 2000.0f;
//         }
//         // clamp_f32(&o->oPosX, o->oHomeX - 2000.0f, o->oHomeX + 2000.0f);
//         // clamp_f32(&o->oPosZ, o->oHomeZ - 2000.0f, o->oHomeZ + 2000.0f);
//     } else {
//         // Move back to 0
//         f32_oscillate_toward(
//             /* value          */ &o->oPosX,
//             /* vel            */ &o->oFloatF4,
//             /* target         */ o->oHomeX,
//             /* velCloseToZero */ 6.0f,
//             /* accel          */ 3.0f,
//             /* slowdown       */ 3.0f);

//         f32_oscillate_toward(
//             /* value          */ &o->oPosZ,
//             /* vel            */ &o->oFloatF8,
//             /* target         */ o->oHomeZ,
//             /* velCloseToZero */ 6.0f,
//             /* accel          */ 3.0f,
//             /* slowdown       */ 3.0f);
//     }

//         print_text_fmt_int(80, 140, "x %d", (s32)o->oFloatF4, 0);
//         print_text_fmt_int(80, 180, "z %d", (s32)o->oFloatF8, 0);


//     // f32 homeD = o->oHomeX * sins(o->oFaceAngleYaw) + o->oHomeZ * coss(o->oFaceAngleYaw);
//     // f32 posD = o->oPosX * sins(o->oFaceAngleYaw) + o->oPosZ * coss(o->oFaceAngleYaw);
//     // f32 riseSqr = (homeD - posD) * (homeD - posD);
//     o->oFloatFC = o->oPosY;
//     f32 xD = o->oHomeX - o->oPosX;
//     f32 zD = o->oHomeZ - o->oPosZ;
//     f32 riseSqr = xD*xD + zD*zD;
//     f32 yRise = sqrtf(5760000 - riseSqr);
//     o->oPosY = o->oHomeY + (2400.0f - yRise);
// }