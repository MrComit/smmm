s32 absi(s32 x);
extern u8 gDreamEnv;

static struct ObjectHitbox sYoshiHeadHitbox = {
    /* interactType:      */ INTERACT_IGLOO_BARRIER,
    /* downOffset:        */ 300,
    /* damageOrCoinValue: */ 0,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 200,
    /* height:            */ 550,
    /* hurtboxRadius:     */ 0,
    /* hurtboxHeight:     */ 0,
};



void bhv_dream_penguin_loop(void) {
    f32 pos;
    switch (o->oAction) {
        case 0:
            cur_obj_update_floor_and_walls();
            cur_obj_move_standard(-78);
            play_penguin_walking_sound(PENGUIN_WALK_BABY);

            if (obj_check_if_collided_with_object(o, gMarioObject) == TRUE) {
                play_sound(SOUND_MENU_COLLECT_SECRET, gGlobalSoundSource);
                o->oAction = 1;
                cur_obj_hide();
                spawn_object(o, MODEL_SPARKLES, bhvGoldenCoinSparkles);
            }
            break;
        case 1:
            set_mario_npc_dialog(1);
            gDreamEnv = approach_s16_symmetric(gDreamEnv, 0, 10);
            if (gDreamEnv == 0) {
                switch (o->oBehParams2ndByte) {
                    case 0:
                        pos = 6000.0f;
                        break;
                    case 1:
                        pos = -15888.0f;
                        break;
                    case 2:
                        pos = 10103.0f;
                        break;
                }
                // CL_instantly_warp(pos);
                CL_call_warp(0, pos, 0);
                o->oAction = 2;
                // set_mario_npc_dialog(0);
            }
            break;
        case 2:
            set_mario_npc_dialog(1);
            gDreamEnv = approach_s16_symmetric(gDreamEnv, 255, 10);
            if (gDreamEnv == 255) {
                o->activeFlags = 0;
                set_mario_npc_dialog(0);
            }
            break;
    }
}


void bhv_dream_yoshi_loop(void) {
    switch (o->oAction) {
        case 0:
            break;
        case 1:
            break;
    }
}


void bhv_yoshi_head_init(void) {
    if (o->oPosY < 5000.0f) {
        o->os16108 = 1200;  // MAX DIST
    } else {
        o->os16108 = 1500;  // MAX DIST
    }
    obj_set_hitbox(o, &sYoshiHeadHitbox);
}


void bhv_yoshi_head_line_init(void) {
    if (o->oPosY < 5000.0f) {
        o->os16108 = 700;  // MAX DIST
        o->os1610A = 700;  // MAX DIST
    } else {
        o->os1610A = 1000;  // MAX DIST
        o->os16108 = 1000;  // MAX DIST
    }
    obj_set_hitbox(o, &sYoshiHeadHitbox);
}

void bhv_yoshi_head_rectangle_init(void) {
    // o->oF4 = 1;
    obj_set_hitbox(o, &sYoshiHeadHitbox);
    if (o->oPosY < 5000.0f) {
        o->os16108 = 1000;  // MAX DIST
    } else {
        o->os16108 = 2000;  // MAX DIST
    }
    o->oFloatFC = o->oPosX;
    o->oFloat100 = o->oPosZ;
    o->oAction = (o->oBehParams >> 8) & 0xFF;
    o->oMoveAngleYaw = o->oFaceAngleYaw = 0x4000 * o->oAction;
    o->o104 = o->oMoveAngleYaw;
    switch (o->oAction) {
        case 1:
            o->oPosZ += (o->oBehParams2ndByte * 100.0f);
            break;
        case 2:
            o->oPosZ += (o->oBehParams2ndByte * 100.0f);
            o->oPosX += (o->oBehParams >> 24) * 100.0f;
            break;
        case 3:
            o->oPosX += (o->oBehParams >> 24) * 100.0f;
            break;
    }
}

void yoshi_head_calc(void) {
    s32 i = 0;
    f32 length, sin, cos;
    f32 divisor;
    struct Surface *wall;
    struct MarioState *m = gMarioState;

    // RAYCAST TYPE THING
    o->oHomeY = o->oPosY;
    length = 0;
    sin = sins(o->oMoveAngleYaw);
    cos = coss(o->oMoveAngleYaw);
    while (wall == NULL) {
        length += 50.0f;
        if (length >= o->os16108) {
            length = o->os16108;
            break;
        }
        o->oHomeX = o->oPosX + (length * sin);
        o->oHomeZ = o->oPosZ + (length * cos);
        wall = resolve_and_return_wall_collisions(&o->oHomeX, 0, 90.0f);
        if (wall != NULL) {
            length -= 10.0f;
            while (o->oSurfF8 == NULL) {
                length += 10.0f;
                o->oHomeX = o->oPosX + (length * sin);
                o->oHomeZ = o->oPosZ + (length * cos);
                o->oSurfF8 = resolve_and_return_wall_collisions(&o->oHomeX, 0, 40.0f);
                if (o->oSurfF8 != NULL) {
                    length -= 10.0f;
                    o->oSurfF8 = NULL;
                    break;
                }
                i++;
                if (i >= 20) {
                    return;
                }
            }
            break;
        }

    }
    // LENGTH SET
    o->oF4 = length;


    //MARIO DISTANCE FROM LINE
    // m1 = coss(o->oMoveAngleYaw) / sins(o->oMoveAngleYaw);
    // b = o->oPosZ - (o->oPosX * m1);
    // e1 = absf((m1 * m->pos[0]) - m->pos[2] + b);
    // d = e1 / sqrtf(m1*m1 + 1);
    // yDif = absf(m->pos[1] - o->oPosY);
    // if ((s16)o->oDistanceToMario < o->oF4 && d < (o->oDistanceToMario / 10.0f) && yDif < 500.0f 
    //     && absi(o->oAngleToMario - (s16)o->oMoveAngleYaw) < 0x400) {
    //     if (o->oTimer > 60) {
    //         CL_get_hit(gMarioState, gMarioObject, 0);
    //         // spawn_object(o, MODEL_SAWBLADE, bhvSawbladeShoot);
    //         o->oTimer = 0;
    //     }
    // }

    divisor = (f32)o->oF4 / 1024.0f;
    if (absf(o->oPosY - gMarioState->pos[1]) < 800.0f && (s16)o->oDistanceToMario < o->oF4 && 
        absi(o->oAngleToMario - (s16)o->oMoveAngleYaw) < (o->oDistanceToMario / divisor)) {
        // if (o->oTimer > 60) {
            CL_get_hit(gMarioState, gMarioObject, 0);
            // spawn_object(o, MODEL_SAWBLADE, bhvSawbladeShoot);
            // o->oTimer = 0;
        // }
    }
    // print_text_fmt_int(80, 80, "%x", absi(o->oAngleToMario - (s16)o->oMoveAngleYaw), 0);
    // print_text_fmt_int(80, 40, "%x", (s32)(o->oDistanceToMario / divisor), 0);

    if (gDreamEnv < 200) {
        cur_obj_hide();
    } else {
        cur_obj_unhide();
    }

}

void bhv_yoshi_head_spin_loop(void) {
    if (o->oBehParams2ndByte == 0) {
        o->oMoveAngleYaw += 0x100;
    } else {
        o->os1610A += 0x1C0;
        o->oMoveAngleYaw = (sins(o->os1610A) * 0x4000);
    }

    yoshi_head_calc();
    // if (o->os16112) {
    //     gDreamEnv = approach_s16_symmetric(gDreamEnv, 0, 10);
    // } else {
    //     gDreamEnv = approach_s16_symmetric(gDreamEnv, 255, 10);
    // }
}


void bhv_yoshi_head_rectangle_loop(void) {
    // o->oMoveAngleYaw += 0x100;
    o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->o104, 0x300);

    if ((u16)o->oMoveAngleYaw == o->o104) {
        switch (o->oAction) {
            case 0:
                o->oPosZ = approach_f32_symmetric(o->oPosZ, o->oFloat100 + (o->oBehParams2ndByte * 100.0f), 20.0f);
                if (o->oPosZ == o->oFloat100 + (o->oBehParams2ndByte * 100.0f)) {
                    o->oAction = 1;
                    o->o104 = 0x4000;
                }
                break;
            case 1:
                o->oPosX = approach_f32_symmetric(o->oPosX, o->oFloatFC + ((o->oBehParams >> 24) * 100.0f), 20.0f);
                if (o->oPosX == o->oFloatFC + ((o->oBehParams >> 24) * 100.0f)) {
                    o->oAction = 2;
                    o->o104 = 0x8000;
                }
                break;
            case 2:
                o->oPosZ = approach_f32_symmetric(o->oPosZ, o->oFloat100, 20.0f);
                if (o->oPosZ == o->oFloat100) {
                    o->oAction = 3;
                    o->o104 = 0xC000;
                }
                break;
            case 3:
                o->oPosX = approach_f32_symmetric(o->oPosX, o->oFloatFC, 20.0f);
                if (o->oPosX == o->oFloatFC) {
                    o->oAction = 0;
                    o->o104 = 0;
                }
                break;
        }
    }

    yoshi_head_calc();
}



void bhv_yoshi_head_line_loop(void) {
    // o->oMoveAngleYaw += 0x100;
    // o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->o104, 0x300);

    switch (o->oAction) {
        case 0:
            o->os16108 = approach_s16_symmetric(o->os16108, o->os1610A, 90);
            o->oPosX += 20.0f * sins(o->oMoveAngleYaw);
            o->oPosZ += 20.0f * coss(o->oMoveAngleYaw);
            if (o->oTimer > o->oBehParams2ndByte) {
                o->oAction = 1;
                o->o104 = (u16)(o->oMoveAngleYaw + 0x8000);
            }
            break;
        case 1:
            o->os16108 = approach_s16_symmetric(o->os16108, 200, 70);
            o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->o104, 0x300);
            if ((u16)o->oMoveAngleYaw == o->o104 && o->os16108 == 200) {
                o->oAction = 0;
            }
            break;
    }

    yoshi_head_calc();
}