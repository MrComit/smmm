#include "levels/ccm/header.h"
s32 obj_check_attacks(struct ObjectHitbox *hitbox, s32 attackedMarioAction);
void obj_compute_vel_from_move_pitch(f32 speed);
extern Vec3f gComitCutscenePosVec;

static struct ObjectHitbox sLevelEntranceHitbox = {
    /* interactType: */ INTERACT_BBH_ENTRANCE,
    /* downOffset: */ 0,
    /* damageOrCoinValue: */ 0,
    /* health: */ 0,
    /* numLootCoins: */ 0,
    /* radius: */ 120,
    /* height: */ 300,
    /* hurtboxRadius: */ 0,
    /* hurtboxHeight: */ 0,
};

struct ObjectHitbox sCannonBallHitbox = {
    /* interactType:      */ INTERACT_SNUFIT_BULLET,
    /* downOffset:        */ 50,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 100,
    /* height:            */ 50,
    /* hurtboxRadius:     */ 100,
    /* hurtboxHeight:     */ 50,
};

struct ObjectHitbox sGalleryGoombaHitbox = {
    /* interactType:      */ INTERACT_BOUNCE_TOP,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 0,
    /* numLootCoins:      */ 1,
    /* radius:            */ 72,
    /* height:            */ 50,
    /* hurtboxRadius:     */ 42,
    /* hurtboxHeight:     */ 40,
};

struct ObjectHitbox sGallerySnufitHitbox = {
    /* interactType:      */ INTERACT_HIT_FROM_BELOW,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 100,
    /* height:            */ 60,
    /* hurtboxRadius:     */ 70,
    /* hurtboxHeight:     */ 50,
};

struct ObjectHitbox sShyguyBossHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 3,
    /* numLootCoins:      */ 2,
    /* radius:            */ 72 * 40,
    /* height:            */ 50 * 100,
    /* hurtboxRadius:     */ 42 * 40,
    /* hurtboxHeight:     */ 40 * 100,
};

struct ObjectHitbox sBlockBombHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 3,
    /* numLootCoins:      */ 2,
    /* radius:            */ 200,
    /* height:            */ 50,
    /* hurtboxRadius:     */ 200,
    /* hurtboxHeight:     */ 50,
};


Vec3s sLegoColors[] = {
{0xFF, 0xFF, 0xFF},
{0x19, 0x6A, 0x19},
{0xB9, 0x00, 0x03},
{0x21, 0x72, 0xB5},
{0xB5, 0x5E, 0x1E},
};


static void const *sCardboardCollision[] = {
    cardboard_wall_collision,
    cardboard_wall_alt_collision,
};


void bhv_star_piece_holder_loop(void) {
    s32 i;
    switch (o->oAction) {
        case 0:
            if (gMarioCurrentRoom != o->oRoom) {
                return;
            }
            o->o108 = 5 - CL_count_bits((save_file_get_star_piece() >> 10) & 0x1F);
            for (i = 0; i < o->o108; i++) {
                o->rawData.asObject[0x1B + i] = spawn_object_relative_with_scale(0, (i*50) - 100, 0, 15, 1.25f,
                                                                                 o, MODEL_STAR_PIECE, bhvStaticObject);
                o->rawData.asObject[0x1B + i]->oFaceAngleYaw = 0x1555;
                o->rawData.asObject[0x1B + i]->oFaceAnglePitch = 0x800;
                o->rawData.asObject[0x1B + i]->oFlags &= ~OBJ_FLAG_DISABLE_ON_ROOM_EXIT;
            }
            o->oAction = 1;
            break;
        case 1:
            if (o->o108 != 5 - CL_count_bits((save_file_get_star_piece() >> 10) & 0x1F)) {
                for (i = 0; i < o->o108; i++) {
                    o->rawData.asObject[0x1B + i]->activeFlags = 0;
                    o->rawData.asObject[0x1B + i] = NULL;
                }
                o->oAction = 0;
            }
            break;
    }
}



void toy_toad_starpiece_loop(u32 starPieces) {
    s32 dialogResponse = CL_NPC_Dialog_Options(DIALOG_016);
    if (dialogResponse) {
        if (dialogResponse == 1) {
#ifdef SMMM_DEBUG
            if (gMarioState->numStars >= -20) {
#else
            if (gMarioState->numStars >= 2) {
#endif
                if (starPieces < 5) {
                    o->oObj108 = spawn_object(gMarioObject, MODEL_NONE, bhvStarPiece);
                    o->oObj108->oBehParams = (10 + starPieces) << 24;
                    o->oAction = 3;
                } else {
                    o->oAction = 2;
                    o->oBehParams = DIALOG_012 << 24;
                }
            } else {
                o->oBehParams = DIALOG_011 << 24;
                o->oAction = 2;
            }
        } else {
            o->oAction = 3;
        }
    } else {
        o->os16100 += 0x800;
        o->oFaceAnglePitch = 0xC00 + (coss(o->os16100) * 0x1000);
        o->oGraphYOffset = 30.0f + (sins(o->os16100) * 25.0f);
        o->oPosX = o->oHomeX - 35.0f * sins(o->oFaceAngleYaw) + (15.0f * sins(o->oFaceAngleYaw) * coss(o->os16100));
        o->oPosZ = o->oHomeZ - 35.0f * coss(o->oFaceAngleYaw) + (15.0f * coss(o->oFaceAngleYaw) * coss(o->os16100));
        o->oFloatFC = 0.75f + (0.05f * sins(o->os16100));
        obj_scale(o, o->oFloatFC);
    }
}



void toy_toad_bridge_loop(void) {
    s32 dialogResponse = CL_NPC_Dialog_Options(DIALOG_033);
    if (dialogResponse) {
        if (dialogResponse == 1) {
#ifdef SMMM_DEBUG
            if (gMarioState->numStars >= -20) {
#else
            if (gMarioState->numStars >= 8) {
#endif
                cur_obj_shake_screen(SHAKE_POS_SMALL);
                create_sound_spawner(SOUND_GENERAL2_BOBOMB_EXPLOSION);
                play_transition(WARP_TRANSITION_FADE_INTO_COLOR, 0xC, 0x00, 0x00, 0x00);
                o->oBehParams = DIALOG_012 << 24;
                o->oAction = 7;
            } else {
                o->oBehParams = DIALOG_011 << 24;
                o->oAction = 2;
            }
        } else {
            o->oAction = 3;
        }
    } else {
        o->os16100 += 0x800;
        o->oFaceAnglePitch = 0xC00 + (coss(o->os16100) * 0x1000);
        o->oGraphYOffset = 30.0f + (sins(o->os16100) * 25.0f);
        o->oPosX = o->oHomeX - 35.0f * sins(o->oFaceAngleYaw) + (15.0f * sins(o->oFaceAngleYaw) * coss(o->os16100));
        o->oPosZ = o->oHomeZ - 35.0f * coss(o->oFaceAngleYaw) + (15.0f * coss(o->oFaceAngleYaw) * coss(o->os16100));
        o->oFloatFC = 0.75f + (0.05f * sins(o->os16100));
        obj_scale(o, o->oFloatFC);
    }
}





void toy_toad_rubberband_loop(void) {
    s32 dialogResponse = CL_NPC_Dialog_Options(DIALOG_010);
    if (dialogResponse) {
        if (dialogResponse == 1) {
            if (gMarioState->numStars >= 2) {
                save_file_set_newflags(SAVE_NEW_FLAG_CITY_BAND_BOUGHT, 0);
                o->oBehParams2ndByte = 0;
                o->oBehParams = DIALOG_012 << 24;
                o->oAction = 2;
            } else {
                o->oBehParams = DIALOG_011 << 24;
                o->oAction = 2;
            }
        } else {
            o->oAction = 3;
        }
    } else {
        o->os16100 += 0x800;
        o->oFaceAnglePitch = 0xC00 + (coss(o->os16100) * 0x1000);
        o->oGraphYOffset = 30.0f + (sins(o->os16100) * 25.0f);
        o->oPosX = o->oHomeX - 35.0f * sins(o->oFaceAngleYaw) + (15.0f * sins(o->oFaceAngleYaw) * coss(o->os16100));
        o->oPosZ = o->oHomeZ - 35.0f * coss(o->oFaceAngleYaw) + (15.0f * coss(o->oFaceAngleYaw) * coss(o->os16100));
        o->oFloatFC = 0.75f + (0.05f * sins(o->os16100));
        obj_scale(o, o->oFloatFC);
    }
}

void bhv_toy_toad_init(void) {
    s32 flags = save_file_get_newflags(0);
    o->oInteractionSubtype = INT_SUBTYPE_NPC;

    if (o->oBehParams2ndByte == 4) {
        if (flags & SAVE_NEW_FLAG_CITY_BRIDGE_BOUGHT /*|| !(flags & SAVE_NEW_FLAG_CITY_TOAD_SAVED)*/) {
            o->activeFlags = 0;
        }
    }
}

void bhv_toy_toad_loop(void) {
    u32 starPieces;
    switch (o->oAction) {
        case 0:
            if (o->oInteractStatus == INT_STATUS_INTERACTED) {
                o->oAction = 1;
                o->os16F4 = o->oMoveAngleYaw;
                if (o->oAngleToMario - o->oMoveAngleYaw > 0) {
                    o->os16F8 = 0x600;
                } else {
                    o->os16F8 = -0x600;
                }
                if (o->oBehParams2ndByte == 2 && save_file_get_newflags(0) & SAVE_NEW_FLAG_CITY_BRIDGE_BOUGHT) {
                    o->oBehParams = 9 << 24;
                }
            }
            break;
        case 1:
            if (!(o->os16F6)) {
                o->oMoveAngleYaw += o->os16F8;
                if (absi(o->oMoveAngleYaw - o->os16F4) >= 0x10000) {
                    o->os16F6 = 1;
                }
            } else {
                o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x600);
                if ((s16) o->oMoveAngleYaw == (s16) o->oAngleToMario) {
                    if (o->oBehParams2ndByte == 1 && !(save_file_get_newflags(0) & SAVE_NEW_FLAG_CITY_BAND_BOUGHT)) {
                        o->oAction = 4;
                    } else if (o->oBehParams2ndByte == 3) {
                        o->oAction = 5;
                    } else if (o->oBehParams2ndByte == 4) {
                        o->oAction = 6;
                    } else {
                        o->oAction = 2;
                    }
                }
                cur_obj_play_sound_2(SOUND_ACTION_READ_SIGN);
            }
            break;
        case 2:
            if (CL_NPC_Dialog(o->oBehParams >> 24)) {
                o->oAction = 3;
            } else {
                o->os16100 += 0x800;
                o->oFaceAnglePitch = 0xC00 + (coss(o->os16100) * 0x1000);
                o->oGraphYOffset = 30.0f + (sins(o->os16100) * 25.0f);
                o->oPosX = o->oHomeX - 35.0f * sins(o->oFaceAngleYaw) + (15.0f * sins(o->oFaceAngleYaw) * coss(o->os16100));
                o->oPosZ = o->oHomeZ - 35.0f * coss(o->oFaceAngleYaw) + (15.0f * coss(o->oFaceAngleYaw) * coss(o->os16100));
                o->oFloatFC = 0.75f + (0.05f * sins(o->os16100));
                obj_scale(o, o->oFloatFC);
            }
            break;
        case 3:
            o->oFaceAnglePitch = approach_s16_symmetric(o->oFaceAnglePitch, 0, 0x200);
            o->oPosX = approach_f32_symmetric(o->oPosX, o->oHomeX, 3.0f);
            o->oPosZ = approach_f32_symmetric(o->oPosZ, o->oHomeZ, 3.0f);
            o->oGraphYOffset = approach_f32_symmetric(o->oGraphYOffset, 0, 6.0f);
            if (o->oPosX == o->oHomeX && o->oPosZ == o->oHomeZ) {
                o->oAction = 0;
                o->os16F6 = 0;
                o->os16100 = 0;
                o->oFaceAnglePitch = 0;
                o->oGraphYOffset = 0;
                o->oPosX = o->oHomeX;
                o->oPosZ = o->oHomeZ;
                o->oFloatFC = 0.75f;
                obj_scale(o, o->oFloatFC);
            }
            break;
        case 4:
            toy_toad_rubberband_loop();
            break;
        case 5:
            starPieces = CL_count_bits((save_file_get_star_piece() >> 10) & 0x1F);
            if (starPieces != 5) {
                toy_toad_starpiece_loop(starPieces);
            } else {
                o->oAction = 2;
                starPieces = save_file_get_star_piece();
                if ((starPieces & 0x1F) != 0x1F) {
                    break;
                } else if (((starPieces >> 5) & 0x1F) != 0x1F) {
                    o->oBehParams = DIALOG_019 << 24;
                } else if (((starPieces >> 15) & 0x1F) != 0x1F) {
                    o->oBehParams = DIALOG_021 << 24;
                } else if (((starPieces >> 20) & 0x1F) != 0x1F) {
                    o->oBehParams = DIALOG_025 << 24;
                } else {
                    o->oBehParams = DIALOG_026 << 24;
                }
            }
            break;
        case 6:
            toy_toad_bridge_loop();
            break;
        case 7:
            switch (o->oTimer) {
                case 20:
                    cur_obj_play_sound_2(SOUND_GENERAL2_BOBOMB_EXPLOSION);
                    break;
                case 40:
                    cur_obj_play_sound_2(SOUND_GENERAL_WALL_EXPLOSION);
                    break;
                case 50:
                    play_transition(WARP_TRANSITION_FADE_FROM_COLOR, 0x8, 0x00, 0x00, 0x00);
                    save_file_set_newflags(SAVE_NEW_FLAG_CITY_BRIDGE_BOUGHT, 0);
                    o->oBehParams2ndByte = 0;
                    o->oAction = 2;
                    play_puzzle_jingle();
                    break;
            }
            break;
    }
}


/*
 *    SHOOTING GALLERY START
 */

#define MINIGAME_SECONDS 120

struct Object *sGalleryShyguys[4] = {
    NULL, NULL, NULL, NULL,
};

struct Object *sGalleryGoombas[6] = {
    NULL, NULL, NULL, NULL, NULL, NULL,
};

struct Object *sGallerySnufits[3] = {
    NULL, NULL, NULL,
};

const BehaviorScript *sGalleryEnemies[4] = {
    bhvGalleryShyguy, bhvGalleryGoomba, bhvGallerySnufit, bhvSnufitBalls,
};

Vec3f sShyguyPositions[4] = {
    {7044.0f, 1150.0f, -10352.0f},
    {6811.0f, 1150.0f, -10159.0f},
    {8875.0f, 1450.0f, -10125.0f},
    {8644.0f, 1450.0f, -10321.0f},
};


Vec3f sSnufitPositions[3] = {
    {7805.0f, 1890.0f, -10110.0f},
    {8372.0f, 2000.0f, -10110.0f},
    {6909.0f, 2190.0f, -10110.0f},
};


void bhv_cannon_lid_init(void) {
    o->oPosX -= 300.0f;
    o->oPosY -= 180.0f;
    o->header.gfx.scale[0] = 0.5f;
}

void bhv_cannon_lid_loop(void) {
    switch (o->oAction) {
        case 0:
            o->oPosX = approach_f32_symmetric(o->oPosX, o->oHomeX, 30.0f);
            o->header.gfx.scale[0] = approach_f32_symmetric(o->header.gfx.scale[0], 1.5f, 0.1f);
            if (o->oPosX == o->oHomeX && o->header.gfx.scale[0] == 1.5f) {
                o->oAction = 1;
            }
            break;
        case 1:
            o->oPosY = approach_f32_symmetric(o->oPosY, o->oHomeY, 20.0f);
            if (o->oPosY == o->oHomeY) {
                o->oAction = 2;
            }
            break;
    }
}


void bhv_gallery_snufit_loop(void) {
    f32 dist;
    s16 pitch, yaw;
    obj_set_hitbox(o, &sGallerySnufitHitbox);
    o->oDeathSound = SOUND_OBJ_SNUFIT_SKEETER_DEATH;


    vec3f_get_dist_and_angle(&o->oPosX, gMarioState->pos, &dist, &pitch, &yaw);
    o->oMoveAnglePitch = -pitch;

    cur_obj_rotate_yaw_toward(o->oAngleToMario, 2000);

    o->oFaceAnglePitch = o->oMoveAnglePitch;

    switch (o->oAction) {
        case 0:
            if (o->oTimer > 90) {
                o->oAction = 1;
            }
            o->oSnufitCircularPeriod += 0x20;
            o->oPosX = o->oHomeX + 300.0f * sins(o->oSnufitCircularPeriod);
            break;
        case 1:
            if (o->oTimer > 5) {
                o->oSnufitBullets += 3;
                cur_obj_play_sound_2(SOUND_OBJ_SNUFIT_SHOOT);
                spawn_object_relative(0, 0, -20, 40, o, MODEL_GHOSTSAND_BALL, bhvSnufitBalls);
                o->oSnufitRecoil = -30;
                o->oAction = 2;
            }
            break;
        case 2:
            if (o->oTimer > 5) {
                o->oAction = 0;
            }
            break;
    }

    o->oFloat110 = (o->oHomeY - 400.0f) + 8.0f * coss(4000 * gGlobalTimer);
    o->oPosY = approach_f32_symmetric(o->oPosY, o->oFloat110, 4.0f);

    o->oSnufitYOffset = -0x20;
    o->oSnufitZOffset = o->oSnufitRecoil + 180;
    o->oSnufitBodyScale
        = (s16)(o->oSnufitBodyBaseScale + 666
        + o->oSnufitBodyBaseScale * coss(o->oSnufitBodyScalePeriod));

    if (o->oSnufitBodyScale > 1000) {
        o->oSnufitScale = (o->oSnufitBodyScale - 1000) / 1000.0f + 1.0f;
        o->oSnufitBodyScale = 1000;
    } else {
        o->oSnufitScale = 1.0f;
    }

    cur_obj_scale(o->oSnufitScale);
    if (o->oInteractStatus & INT_STATUS_INTERACTED && o->oInteractStatus & INT_STATUS_WAS_ATTACKED) {
            spawn_mist_particles();
            o->activeFlags = 0;
            sGallerySnufits[o->oBehParams2ndByte] = NULL;
            create_sound_spawner(SOUND_OBJ_DYING_ENEMY1);
            interact_coin(gMarioState, 0, o);
    }
}


void bhv_gallery_goomba_init(void) {
    obj_set_hitbox(o, &sGalleryGoombaHitbox);

    o->oGravity = -5.0f;
    o->oMoveAngleYaw = 0x4000 * random_sign();;
}


void bhv_gallery_goomba_update(void) {
    f32 animSpeed;

    if (obj_update_standard_actions(o->oGoombaScale)) {
        o->oGoombaScale = approach_f32_symmetric(o->oGoombaScale, 1.5f, 0.1f);
        cur_obj_scale(o->oGoombaScale);
        obj_update_blinking(&o->oGoombaBlinkTimer, 30, 50, 5);
        cur_obj_update_floor_and_walls();

        if ((animSpeed = o->oForwardVel / o->oGoombaScale * 0.4f) < 1.0f) {
            animSpeed = 1.0f;
        }

        cur_obj_init_animation_with_accel_and_sound(0, animSpeed);

        //obj_forward_vel_approach(20.0f * o->oGoombaScale, 0.4f);
        o->oForwardVel = 6.0f;// * o->oGoombaScale;
        cur_obj_move_standard(0);

        if (o->oInteractStatus & INT_STATUS_INTERACTED && o->oInteractStatus & INT_STATUS_WAS_ATTACKED) {
                spawn_mist_particles();
                o->activeFlags = 0;
                sGalleryGoombas[o->oBehParams2ndByte] = NULL;
                create_sound_spawner(SOUND_OBJ_DYING_ENEMY1);
                interact_coin(gMarioState, 0, o);
        }

    } else {
        o->oAnimState = 1;
    }

    if (o->oPosY < 1000.0f) {
        o->activeFlags = 0;
        sGalleryGoombas[o->oBehParams2ndByte] = NULL;
    }
}


 void bhv_gallery_shyguy_init(void) {
    obj_set_hitbox(o, &sShyguyHitbox);
    o->oOpacity = 0xFF;
    vec3f_copy(&o->oPosX, sShyguyPositions[o->oBehParams2ndByte]);
}

void bhv_gallery_shyguy_loop(void) {
    switch (o->oAction) {
        case 0:
            o->oPosY = approach_f32_asymptotic(o->oPosY, o->oHomeY, 0.1f);
            if (o->oTimer > 90) {
                o->oAction = 1;
            }
            break;
        case 1:
            o->oPosY = approach_f32_asymptotic(o->oPosY, o->oHomeY + 120.0f, 0.1f);
            if (o->oTimer > 120) {
                o->oAction = 0;
            }

            if (o->oInteractStatus & INT_STATUS_INTERACTED && o->oInteractStatus & INT_STATUS_WAS_ATTACKED) {
                    spawn_mist_particles();
                    o->activeFlags = 0;
                    sGalleryShyguys[o->oBehParams2ndByte] = NULL;
                    create_sound_spawner(SOUND_OBJ_DYING_ENEMY1);
                    interact_coin(gMarioState, 0, o);
            }
            break;
    }
    o->oMoveAngleYaw = o->oAngleToMario;
    o->oInteractStatus = 0;
}

void gallery_spawn_enemies(void) {
    struct Object *obj;

    if (o->oShyguyCount < 12 && o->oShyguyIndex == 0) {
        if (sGalleryShyguys[0] == NULL && sGalleryShyguys[1] == NULL && ++o->oShyguyTimer > 90) {
            sGalleryShyguys[0] = spawn_object(o, MODEL_SHYGUY, bhvGalleryShyguy);
            sGalleryShyguys[1] = spawn_object(o, MODEL_SHYGUY, bhvGalleryShyguy);
            sGalleryShyguys[1]->oBehParams2ndByte = 1;
            o->oShyguyIndex = 1;
            o->oShyguyTimer = 0;
            o->oShyguyCount++;
        }
    } else if (o->oShyguyCount < 12) {
        if (sGalleryShyguys[2] == NULL && sGalleryShyguys[3] == NULL && ++o->oShyguyTimer > 90) {
            sGalleryShyguys[2] = spawn_object(o, MODEL_SHYGUY, bhvGalleryShyguy);
            sGalleryShyguys[3] = spawn_object(o, MODEL_SHYGUY, bhvGalleryShyguy);
            sGalleryShyguys[2]->oBehParams2ndByte = 2;
            sGalleryShyguys[3]->oBehParams2ndByte = 3;
            o->oShyguyIndex = 0;
            o->oShyguyTimer = 0;
            o->oShyguyCount++;
        }
    }

    if (o->oGoombaCount < 7) {
        if (o->oGoombaIndex < 6) {
            if (++o->oGoombaTimer > 75) {
                sGalleryGoombas[o->oGoombaIndex] = spawn_object(o, MODEL_GOOMBA, bhvGalleryGoomba);
                sGalleryGoombas[o->oGoombaIndex]->oBehParams2ndByte = o->oGoombaIndex;
                o->oGoombaIndex++;
                o->oGoombaTimer = 0;
            }
        } else {
            if (cur_obj_nearest_object_with_behavior(bhvGalleryGoomba) == NULL) {
                o->oGoombaIndex = 0;
                o->oGoombaTimer = -120;
                o->oGoombaCount++;
            }
        }
    }

    if (o->oSnufitCount < 5) {
        if (o->oSnufitIndex < 3) {
            if (++o->oSnufitTimer > 120) {
                sGallerySnufits[o->oSnufitIndex] = spawn_object(o, MODEL_SNUFIT, bhvGallerySnufit);
                sGallerySnufits[o->oSnufitIndex]->oBehParams2ndByte = o->oSnufitIndex;
                vec3f_copy(&sGallerySnufits[o->oSnufitIndex]->oPosX, sSnufitPositions[o->oSnufitIndex]);
                o->oSnufitIndex++;
                o->oSnufitTimer = 0;

            }
        } else {
            if (cur_obj_nearest_object_with_behavior(bhvGallerySnufit) == NULL) {
                o->oSnufitIndex = 0;
                o->oSnufitTimer = -210;
                o->oSnufitCount++;
            }
        }
    }
}

void gallery_kill_enemies(void) {
    s32 i;
    struct Object *obj;
    for (i = 0; i < 4; i++) {
        while ((obj = cur_obj_nearest_object_with_behavior(sGalleryEnemies[i])) != NULL) {
            obj->activeFlags = 0;
        }
    }
}


void bhv_gallery_handler_init(void) {
    o->os16F4 = (MINIGAME_SECONDS*30 + 1);

    sGalleryShyguys[0] = NULL; sGalleryShyguys[1] = NULL; sGalleryShyguys[2] = NULL; sGalleryShyguys[3] = NULL;
    sGalleryGoombas[0] = NULL; sGalleryGoombas[1] = NULL; sGalleryGoombas[2] = NULL; 
    sGalleryGoombas[3] = NULL; sGalleryGoombas[4] = NULL; sGalleryGoombas[5] = NULL;
    sGallerySnufits[0] = NULL; sGallerySnufits[1] = NULL; sGallerySnufits[2] = NULL;
}

void bhv_gallery_handler_loop(void) {
    struct Object *obj;
    struct MarioState *m = gMarioState;
    Vec3f pos;
    switch (o->oAction) {
        case 0:
            if (m->action == ACT_IN_CANNON && m->actionState == 2) {
                o->oAction = 1;
            }
            if (m->pos[2] < -8150.0f) {
                m->pos[2] = -8150.0f;
            }
            break;
        case 1:
            gallery_spawn_enemies();

            o->os16F4--;
            if (o->os16F4 > 10*30) {
                if (o->os16F4 % 30 == 0) {
                    play_sound(SOUND_GENERAL2_SWITCH_TICK_SLOW, gGlobalSoundSource);
                }
                o->os16F6 = 209;
                o->os16F8 = 20;
            } else {
                if (o->os16F4 % 30 == 0 || o->os16F4 % 30 == 15) {
                    play_sound(SOUND_GENERAL2_SWITCH_TICK_FAST, gGlobalSoundSource);
                }
                o->os16FA += 0x1000;
                o->os16F6 = 209 + (sins(o->os16FA) * 2);
                o->os16F8 = 20 + (coss(o->os16FA) * 2);
            }

            print_text_fmt_int(o->os16F8, o->os16F6, "TIME  %d", o->os16F4 / 30);
            //print_text_fmt_int(20, 200, "POINTS %d", o->os16F6);
            //print_text_fmt_int(20, 215, "GOAL %d", MINIGAME_GOAL);
            if (o->os16F4 <= 0) {
                o->oAction = 2;
            }
            if (m->health < 0x800) {
                m->health = 0x800;
            }
            break;
        case 2:
            gallery_kill_enemies();
            o->activeFlags = 0;
            break;
    }
}

void bhv_cannon_balls_loop(void) {
    s32 i;
    struct Object *obj;
    if (o->oTimer > 90) {
        o->activeFlags = 0;
    }

    for (i = 0; i < 4; i++) {
        if (cur_obj_dist_to_nearest_object_with_behavior(sGalleryEnemies[i]) < 200.0f) {
            obj = cur_obj_nearest_object_with_behavior(sGalleryEnemies[i]);
            if (i != 3) {
                attack_object(obj, 2);
            } else {
                obj->activeFlags = 0;
                spawn_mist_particles();
            }
            o->activeFlags = 0;
            break;
        }
    }


    cur_obj_update_floor_and_walls();

    obj_compute_vel_from_move_pitch(200.0f);
    if (obj_check_attacks(&sCannonBallHitbox, 1) != 0) {
        // We hit Mario while he is metal!
        // Bounce off, and fall until the first check is true.
        o->oMoveAngleYaw += 0x8000;
        o->oForwardVel *= 0.05f;
        o->oVelY = 30.0f;
        o->oGravity = -4.0f;

        cur_obj_become_intangible();
        o->oDeathSound = -1;
        obj_die_if_health_non_positive();
    } else if (o->oMoveFlags & (OBJ_MOVE_MASK_ON_GROUND | OBJ_MOVE_HIT_WALL)) {
        o->oDeathSound = -1;
        obj_die_if_health_non_positive();
    }

    cur_obj_move_standard(78);
}

/*
 *    SHOOTING GALLERY END
 */


void bhv_city_bridge_init(void) {
    if (!(save_file_get_newflags(0) & SAVE_NEW_FLAG_CITY_BRIDGE_BOUGHT)) {
        o->oAction = 1;
        cur_obj_disable();
    }
}

void bhv_city_bridge_loop(void) {
    switch (o->oAction) {
        case 0:
            load_object_collision_model();
            break;
        case 1:
            if (save_file_get_newflags(0) & SAVE_NEW_FLAG_CITY_BRIDGE_BOUGHT) {
                o->oAction = 0;
                cur_obj_enable();
                spawn_mist_particles();
            }
            break;
    }
}

/*
 *    BOSS START
 */

Vec3f sHoldMario = {0, 0, 0};

Vec3f sShyguyBossCutscenes[3] = {
    // {-8700.0f, 8500.0f, -200.0f},
    {-4000.0f, 6000.0f, -700.0f},
    {-9700.0f, 11800.0f, -7000.0f},
    {-8000.0f, 9400.0f, -2700.0f},
};

Vec3f sBossStarts[2] = {
    {-6839.0f, 5807.0f, -4956.0f},
    {-12639.0f, 8166.0f, -13000.0f},
};

Vec3f sShyguyBossRespawn[3] = {
    {-2489.0f, 4339.16f + 100.0f, -2500.0f},
    {-6839.0f, 5807.0f  + 100.0f, -4956.0f},
    {-12639.0f, 8166.0f + 100.0f, -13000.0f},
};

s16 sShyguyBossAngles[3] = {0xC000, 0x8000, 0x4000};


void bhv_boss_toy_toad_init(void) {
    o->oInteractionSubtype = INT_SUBTYPE_NPC;
    o->oObj108 = cur_obj_nearest_object_with_behavior(bhvShyGuyBoss);
    if (o->oObj108 == NULL) {
        o->activeFlags = 0;
    }
}

void boss_toy_toad_check(s32 param) {
    struct MarioState *m = gMarioState;
    switch (param) {
        case 0:
            if (m->pos[0] < -1600.0f) {
                o->o104 = 1;
            }
            break;
        case 1:
            if (m->pos[0] < -9000.0f && m->pos[2] < -800.0f) {
                o->o104 = 1;
            }
            break;
        case 2:
            if (m->pos[2] > 4000.0f) {
                o->o104 = 1;
            }
            break;
    }
}

void bhv_boss_toy_toad_loop(void) {
    switch (o->o104) {
        case 0:
            if (o->oObj108->oAction) {
                boss_toy_toad_check(o->oBehParams >> 24);
            }
            break;
        case 1:
            o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x300);
            if (CL_NPC_Dialog(o->oBehParams2ndByte)) {
                o->o104 = 2;
            }
            break;
        case 2:
            bhv_toy_toad_loop();
            break;
    }
}

void bhv_toy_shyguy_init(void) {
    s16 faceAdd;
    o->oFaceAnglePitch = 0;
    o->oFloatF4 = sBossStarts[o->oBehParams2ndByte][0];
    o->oFloatF8 = sBossStarts[o->oBehParams2ndByte][1];
    o->oFloatFC = sBossStarts[o->oBehParams2ndByte][2];
    o->oFaceAngleYaw = atan2s(o->oFloatFC - gMarioState->pos[2], o->oFloatF4 - gMarioState->pos[0]);

    o->oFloat100 = o->oFloatF8 - gMarioState->pos[1];
    o->oVelX = absf(o->oFloatF4 - gMarioState->pos[0]) / 90.0f; 
    o->oVelZ = absf(o->oFloatFC - gMarioState->pos[2]) / 90.0f; 

    vec3f_copy(&o->oPosX, gMarioState->pos);
    if (o->oBehParams >> 24) {
        faceAdd = -0x4000;
    } else {
        faceAdd = 0x4000;
        vec3f_copy(sHoldMario, gMarioState->pos);
    }
    o->oPosX += sins(o->oFaceAngleYaw + faceAdd) * 50.0f;
    o->oPosZ += coss(o->oFaceAngleYaw + faceAdd) * 50.0f;
    vec3f_copy(&o->oHomeX, &o->oPosX);
    o->oPosY += 1000.0f;
}


void bhv_toy_shyguy_loop(void) { //use 3d moving?
    struct MarioState *m = gMarioState;
    switch (o->oAction) {
        case 0:
            if (o->oTimer > 20) {
                o->oAction = 4;
            }
            if (o->oBehParams >> 24 == 0) {
                vec3f_copy(m->pos, sHoldMario);
            }
            break;
        case 1:
            //cur_obj_move_using_vel_and_gravity();
            if (o->oTimer >= 10) {
                o->oPosX = approach_f32_symmetric(o->oPosX, o->oFloatF4, o->oVelX);
                o->oPosZ = approach_f32_symmetric(o->oPosZ, o->oFloatFC, o->oVelZ);
            }
            o->os1610A += 0x8000 / 100;
            o->os16108 += coss(o->os1610A) * (0x8000 / 100);
            o->oFloat104 = o->oFloatF8 + (sins(o->os16108) * o->oFloat100);
            o->oPosY = approach_f32_symmetric(o->oPosY, o->oFloat104, o->oFloat100 / 20);
            if (o->oTimer > 60 && o->oPosY < o->oFloatF8) {
                o->oPosY = o->oFloatF8;
            }
            vec3f_set(m->pos, approach_f32_symmetric(o->oPosX, o->oFloatF4, o->oVelX), o->oPosY,
                     approach_f32_symmetric(o->oPosZ, o->oFloatFC, o->oVelZ));
            m->pos[0] += sins(o->oFaceAngleYaw - 0x4000) * 50.0f;
            m->pos[2] += coss(o->oFaceAngleYaw - 0x4000) * 50.0f;
            if (o->oTimer >= 100) {
                o->oAction = 2;
                o->oHomeY = o->oPosY + 1000.0f;
            }
            set_mario_action(m, ACT_CUTSCENE_JUMP, 0);
            break;
        case 2:
            if (o->oBehParams >> 24 == 0 && o->oTimer == 0) {
                set_mario_action(m, ACT_IDLE, 0);
            }
            o->oPosY = approach_f32_symmetric(o->oPosY, o->oHomeY, 40.0f);
            if (o->oPosY == o->oHomeY) {
                o->activeFlags = 0;
            }
            break;
        case 3:
            vec3f_copy(&o->oPosX, m->pos);
            o->oPosX += sins(o->oFaceAngleYaw - 0x4000) * 50.0f;
            o->oPosZ += coss(o->oFaceAngleYaw - 0x4000) * 50.0f;
            if (o->oTimer >= 100) {
                o->oAction = 2;
                o->oHomeY = o->oPosY + 1000.0f;
            }
            break;
        case 4:
            o->oPosY = approach_f32_symmetric(o->oPosY, o->oHomeY, 30.0f);
            if (o->oPosY == o->oHomeY) {
                if (o->oBehParams >> 24) {
                    o->oAction = 3;
                } else {
                    o->oAction = 1;
                    m->faceAngle[1] = o->oFaceAngleYaw;
                }
            }
            if (o->oBehParams >> 24 == 0) {
                vec3f_copy(m->pos, sHoldMario);
            }
            break;
    }


}


void bhv_block_piece_init(void) {
    o->oObjFC = cur_obj_nearest_object_with_behavior(bhvShyGuyBoss);
    if (o->oObjFC == NULL) {
        o->activeFlags = 0;
    } else {
        o->oFaceAngleYaw = obj_angle_to_object(o, o->oObjFC);
        o->oMoveAngleYaw = o->oFaceAngleYaw + 0x8000;
    }
}

void bhv_block_piece_loop(void) {
    struct MarioState *m = gMarioState;
    switch(o->oAction) {
        case 0:
            o->oForwardVel = 0.0f;
            if (m->wall != NULL && m->wall->object == o && m->wall->type == SURFACE_GENERAL_USE) {
                o->oForwardVel = 4.0f;
                cur_obj_play_sound_1(SOUND_ENV_METAL_BOX_PUSH);
                o->oF8++;
                cur_obj_move_using_fvel_and_gravity();
            }
            if (o->oF8 >= 50) {
                o->oAction = 1;
            }
            break;
        case 1:
            break;
    }
}


void bhv_block_tower_init(void) {
    o->oObjFC = cur_obj_nearest_object_with_behavior(bhvShyGuyBoss);
    if (o->oObjFC == NULL) {
        o->activeFlags = 0;
    } else {
        o->oFaceAngleYaw = obj_angle_to_object(o, o->oObjFC);
    }
}


void bhv_block_tower_loop(void) {
    switch (o->oAction) {
        case 0:
            if (o->prevObj->oF8) {
                o->oFaceAnglePitch = 50 * o->prevObj->oF8;
            } else {
                if (o->oDistanceToMario < 500.0f) {
                    o->os16F6 += 0x400;
                } else {
                    o->os16F6 = approach_s16_symmetric(o->os16F6, 0, 0x100);
                }
                o->oFaceAnglePitch = 0x180 * sins(o->os16F6);
            }
            if (o->prevObj->oAction == 1) {
                o->oAction = 1;
                gCamera->comitCutscene = 17;
                gComitCutsceneObject = o->oObjFC;
                vec3f_copy(gComitCutscenePosVec, sShyguyBossCutscenes[3 - o->oObjFC->oHealth]);
                // set_mario_npc_dialog(1);
            }
            break;
        case 1:
            o->os16F4 = approach_s16_symmetric(o->os16F4, 0x800, 0x40);
            o->oFaceAnglePitch = approach_s16_symmetric(o->oFaceAnglePitch, 0x3000, o->os16F4);
            if (o->oFaceAnglePitch == 0x3000) {
                o->activeFlags = 0;
                set_camera_shake_from_point(3, gCamera->pos[0], gCamera->pos[1], gCamera->pos[2]);
                spawn_triangle_break_particles(30, MODEL_DIRT_ANIMATION, 3.0f, 4);
                create_sound_spawner(SOUND_GENERAL2_BOBOMB_EXPLOSION);
                if (--o->oObjFC->oHealth <= 0) {
                    o->oObjFC->oAction = 2;
                    stop_background_music(SEQUENCE_ARGS(4, SEQ_GENERIC_BOSS));
                } else {
                    o->oObjFC->oAction = 4;
                }
            }
            break;
    }
}


void bhv_boss_bullet_bill_init(void) {
    //o->oFloatFC = absf((gMarioState->pos[1] + 60.0f) - o->oPosY) / 10.0f;
    o->oForwardVel = 100.0f;
}


void bhv_boss_bullet_bill_loop(void) {
    CL_Move();
    switch (o->oAction) {
        case 0:
            if (o->oTimer < 15) {
                o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x400);
                //o->oPosY = approach_f32_symmetric(o->oPosY, gMarioState->pos[1], o->oFloatFC);
            } else {
                o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x40);
                cur_obj_update_floor_and_walls();
            }
            if (o->oDistanceToMario < 5000.0f) {
                o->oForwardVel = approach_f32_symmetric(o->oForwardVel, 50.0f, 5.0f);
            }
            spawn_object(o, MODEL_SMOKE, bhvWhitePuffSmoke);
            if (o->oTimer > 75 || o->oMoveFlags & OBJ_MOVE_HIT_WALL) {
                o->activeFlags = 0;
                spawn_mist_particles();
            }
            if (o->oInteractStatus) {
                o->oAction = 1;
                o->oForwardVel = -30.0f;
                cur_obj_become_intangible();
            }
            break;
        case 1:
            o->oFaceAnglePitch += 0x1000;
            o->oFaceAngleRoll += 0x1000;
            o->oPosY += 20.0f;

            if (o->oTimer > 45) {
                o->activeFlags = 0;
            }
            break;
    }
}


void bhv_boss_bullet_bill_cannon_init(void) {
    o->oObjF4 = cur_obj_nearest_object_with_behavior(bhvShyGuyBoss);
    if (o->oObjF4 == NULL) {
        o->activeFlags = 0;
    }
}


void bhv_boss_bullet_bill_cannon_loop(void) {
    if (o->oObjF4->os16F4 == o->oBehParams2ndByte) {
        if (o->oTimer > 60 + (count_objects_with_behavior(bhvBossBulletBill) * 30)) {
            spawn_object(o, MODEL_BULLET_BILL, bhvBossBulletBill);
            o->oTimer = 0;
        }
    } else {
        o->oTimer = 0;
    }
}


void bhv_block_bomb_init(void) {
    obj_set_hitbox(o, &sBlockBombHitbox);
    vec3f_set(&o->oPosX, gMarioState->pos[0], gMarioState->pos[1] + 600.0f, gMarioState->pos[2]);
    o->oFaceAngleYaw = random_u16();
    vec3f_set(o->header.gfx.scale, 0.25f, 0.35f, 0.6f);
    o->oGraphYOffset = -35.0f;
}

void bhv_block_bomb_loop(void) {
    struct Object *obj;
    o->oF8 += 0x800;
    o->oFaceAngleRoll = 0x600 * sins(o->oF8);
    o->oFloatF4 = approach_f32_symmetric(o->oFloatF4, 30.0f, 1.2f);
    o->oPosY -= o->oFloatF4;
    if (o->oInteractStatus || object_step() & 1 || o->oTimer > 90) {
        obj = spawn_object(o, MODEL_EXPLOSION, bhvExplosion);
        obj->oGraphYOffset += 100.0f;
        obj->oIntangibleTimer = -1;
        o->activeFlags = 0;
    }
    obj = cur_obj_nearest_object_with_behavior(bhvShyGuyBoss);
    if (obj == NULL || obj->os16F6 == 0) {
        o->activeFlags = 0;
    }
}


void shyguy_boss_handle_void_out(void) {
    struct MarioState *m = gMarioState;
    switch (o->oHealth) {
        case 3:
            if (m->pos[1] <= 3000.0f) {
                if (m->health <= 0x280) {
                    level_trigger_warp(m, WARP_OP_WARP_FLOOR);
                    o->oAction = 0;
                } else {
                    o->oAction = 3;
                }
            }
            break;
        case 2:
            if (m->pos[1] <= 4000.0f) {
                if (m->health <= 0x280) {
                    level_trigger_warp(m, WARP_OP_WARP_FLOOR);
                    o->oAction = 0;
                } else {
                    o->oAction = 3;
                }
            }
            break;
        case 1:
            if (m->pos[1] <= 7100.0f) {
                if (m->health <= 0x280) {
                    level_trigger_warp(m, WARP_OP_WARP_FLOOR);
                    o->oAction = 0;
                } else {
                    o->oAction = 3;
                }
            }
            break;
    }
}


void shyguy_boss_handle_bulletlist(void) {
    struct MarioState *m = gMarioState;
    switch (o->oHealth) {
        case 3:
            if (m->pos[0] > -6000.0f) {
                o->os16F4 = 1;
            } else {
                o->os16F4 = 0;
            }
            
            if (m->pos[2] > 1336.0f || (m->pos[2] > -794.0f && o->os16F4 == 0)) {
                o->os16F6 = 1;
            } else {
                o->os16F6 = 0;
            }

            break;
        case 2:
            if (m->pos[1] >= 6300.0f && m->pos[0] <= -9600.0f) {
                o->os16F4 = 2;
            } else {
                o->os16F4 = 0;
            }
            if (CL_objptr_dist_to_nearest_object_with_behavior(gMarioObject, bhvBlockTower) < 1000.0f) {
                o->os16F6 = 0;
            } else {
                o->os16F6 = 1;
            }
            break;
        case 1:
            if (m->pos[2] <= -11900.0f && m->pos[0] <= -8900.0f) {
                o->os16F4 = 3;
            } else {
                o->os16F4 = 0;
            }
            if (m->pos[2] > 4000.0f || CL_objptr_dist_to_nearest_object_with_behavior(gMarioObject, bhvBlockTower) < 1000.0f) {
                o->os16F6 = 0;
            } else {
                o->os16F6 = 1;
            }
            break;
    }
    if (cur_obj_nearest_object_with_behavior(bhvToyShyguy)) {
        o->os16F6 = 0;
    }
}


void shyguy_boss_multiplier_loop(void) {
    s32 action = FALSE;
    if (gMarioCurrentRoom == o->oRoom)
        gHudDisplay.flags |= (HUD_DISPLAY_FLAG_LOWER);

    print_text_fmt_int(168+30, 169+20, "%d", (s32)o->oFloat10C);
    print_text(184+30, 169+20, ".");
    print_text_fmt_int(198+30, 169+20, "%d", o->os16110);
    print_text(212+30, 169+20, "*"); // 'X' glyph

    if (gMarioState->action == ACT_BURNING_FALL || gMarioState->action == ACT_BURNING_JUMP 
        || gMarioState->action == ACT_BURNING_GROUND) {
        if (o->oKleptoTargetNumber == 0) {
            action = TRUE;
            o->oKleptoTargetNumber = 1;
        }
    } else {
        o->oKleptoTargetNumber = 0;
        action = FALSE;
    }
    if (((gMarioState->hurtCounter > 0 && o->os16112 == 0) || action) && o->oFloat10C > 0) {
        if (o->os16110 == 0) {
            o->oFloat10C -= 1.0f;
            o->os16110 = 5;
        } else {
            o->os16110 = 0;
        }
        o->os16112 = 1;
    } else if (gMarioState->hurtCounter <= 0) {
        o->os16112 = 0;
    }


}


void bhv_shyguy_boss_init(void) {
    obj_set_hitbox(o, &sShyguyBossHitbox);
    o->oOpacity = 0xFF;
    o->oFloat10C = 5.0f;
}

extern s16 s8DirModeBaseYaw;

void bhv_shyguy_boss_loop(void) {
    struct MarioState *m = gMarioState;
    struct Object *obj;
    if (o->oAction) {
        shyguy_boss_multiplier_loop();
    }
    switch (o->oAction) {
        case 0: // PRE FIGHT ACT
            if (o->oDistanceToMario < 11000.0f) {
                o->oAction = 1;
                play_music(0, SEQUENCE_ARGS(4, SEQ_GENERIC_BOSS), 0);
            }
            break;
        case 1: // MAIN LOOP
            shyguy_boss_handle_bulletlist();
            shyguy_boss_handle_void_out();
            if (o->os16F6 == 1) {
                if (++o->os16F8 > 60) {
                    spawn_object(o, MODEL_BLOCK_PIECE, bhvBlockBomb);
                    o->os16F8 = 0;
                }
            }
            break;
        case 2: // DEATH ACT
            if (o->oTimer == 0) {
                cur_obj_play_sound_1(SOUND_GENERAL2_BOWSER_EXPLODE);
            }
            if (o->oTimer == 35) {
                cur_obj_init_animation(3);
            }
            o->oGraphYOffset += 15.0f;
            o->header.gfx.scale[0] = approach_f32_symmetric(o->header.gfx.scale[0], 0.05f, 0.01f);
            cur_obj_scale(o->header.gfx.scale[0]);
            if (o->header.gfx.scale[0] == 0.05f) {
                gMarioState->numCoins += 100 * (o->oFloat10C + ((f32)o->os16110 / 10));
                CL_explode_object(o, 1);
                obj = spawn_object(o, MODEL_BOO, bhvRoomBoo);
                obj->oFlags &= ~OBJ_FLAG_DISABLE_ON_ROOM_EXIT;
                obj->oBehParams2ndByte = 0x0E;
                obj->oBehParams = 0x040E0900;
                gCamera->comitCutscene = 0;
            }
            break;
        case 3:
            switch (o->oTimer) {
                case 0:
                    play_transition(WARP_TRANSITION_FADE_INTO_COLOR, 0xC, 0x00, 0x00, 0x00);
                    break;
                case 9:
                    vec3f_copy(m->pos, sShyguyBossRespawn[3 - o->oHealth]);
                    set_mario_action(m, ACT_JUMP_LAND_STOP, 0);
                    m->faceAngle[1] = sShyguyBossAngles[3 - o->oHealth];
                    set_r_button_camera(gCamera);
                    s8DirModeBaseYaw = gMarioState->faceAngle[1] + 0x8000;
                    m->forwardVel = 0;
                    vec3f_set(m->vel, 0.0f, 0.0f, 0.0f);
                    break;
                case 12:
                    play_transition(WARP_TRANSITION_FADE_FROM_COLOR, 5, 0x00, 0x00, 0x00);
                    m->hurtCounter = 8;
                    o->oAction = 1;
                    break;
            }
            break;
        case 4:
            cur_obj_init_animation(1);
            if (cur_obj_check_if_at_animation_end()) {
                o->oAction = 5;
                cur_obj_init_animation(2);
                obj = spawn_object(o, MODEL_TOY_SHYGUY, bhvToyShyguy);
                obj->oBehParams2ndByte = 2 - o->oHealth;
                obj = spawn_object(o, MODEL_TOY_SHYGUY, bhvToyShyguy);
                obj->oBehParams2ndByte = 2 - o->oHealth;
                obj->oBehParams = 1 << 24;
            }
            break;
        case 5:
            if (cur_obj_check_anim_frame(15)) {
                cur_obj_play_sound_1(SOUND_OBJ2_BOWSER_ROAR);
            }
            if (cur_obj_check_if_at_animation_end()) {
                o->oAction = 1;
                cur_obj_init_animation(0);
                gCamera->comitCutscene = 0;
            }
            break;
    }
    // if (o->oInteractStatus) {
    //     push_mario_out_of_object(gMarioState, o, 0.0f);
    // }
    if (o->oAction != 2) {
        o->os16FA += 0x400;
        o->oGraphYOffset = 20.0f + 20.0f * sins(o->os16FA);
    }
    o->oInteractStatus = 0;
}

/*
 *    BOSS END
 */



void bhv_racecar_init(void) {
    o->oForwardVel = 25.0f;
    o->oF4 = o->oFaceAngleYaw;
    o->oFloatF8 = (o->oBehParams >> 24) * 100.0f;
    if (((o->oBehParams >> 8) & 0xFF) == 1) {
        o->oObjFC = spawn_object(o, MODEL_STAR_CURRENCY, bhvStar);
        o->oObjFC->oBehParams = 0x12 << 24;
        o->oFloat100 = 100.0f;
    } else if (((o->oBehParams >> 8) & 0xFF) == 2) {
        o->oObjFC = cur_obj_nearest_object_with_behavior(bhvToyToad);
        o->oFloat100 = 50.0f;
    } else {
        o->oObjFC = spawn_object(o, MODEL_HEART, bhvCollectHeart);
        o->oObjFC->oF4 = 1;
        o->oFloat100 = 50.0f;
    }
}


void bhv_racecar_loop(void) {
    cur_obj_update_floor_and_walls();
    cur_obj_move_standard(78);
    //CL_Move();
    if (cur_obj_lateral_dist_to_home() > o->oFloatF8) {
        o->oF4 = o->oMoveAngleYaw + 0x8000;
        vec3f_copy(&o->oHomeX, &o->oPosX);
    }
    o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oF4, 0x400);
    if (o->oObjFC != NULL) {
        if (o->oObjFC->activeFlags != 0) {
            vec3f_set(&o->oObjFC->oPosX, o->oPosX, o->oPosY + o->oFloat100, o->oPosZ);
            if (((o->oBehParams >> 8) & 0xFF) == 2) {
                vec3f_copy(&o->oObjFC->oHomeX, &o->oObjFC->oPosX);
                if (o->oObjFC->oAction == 0) {
                    o->oObjFC->oMoveAngleYaw = approach_s16_symmetric(o->oObjFC->oMoveAngleYaw, o->oMoveAngleYaw, 0x300);
                }
            }
        } else {
            o->oObjFC == NULL;
        }
    }
}




void bhv_cardboard_wall_init(void) {
    o->collisionData = segmented_to_virtual(sCardboardCollision[o->oBehParams2ndByte]);
}


void bhv_cardboard_wall_loop(void) {
    struct Object *obj;
    switch (o->oAction) {
        case 0:
            obj = cur_obj_nearest_object_with_behavior(bhvGenericSwitch);
            if (obj == NULL || obj->oF4) {
                if (o->oBehParams >> 24)
                    o->oAction = 2;
                else
                    o->oAction = 3;

            }
            break;
        case 1:
            o->os16F4 += 4;
            o->os16F4 = approach_s16_symmetric(o->os16F4, 0x800, o->os16F4 / 10);
            o->oFaceAngleRoll = approach_s16_symmetric(o->oFaceAngleRoll, 0xC000, o->os16F4);
            if ((s16)o->oFaceAngleRoll == -0x4000) {
                if (o->oBehParams >> 24) {
                    //cur_obj_shake_screen(1);
                    set_camera_shake_from_point(1, gCamera->pos[0], gCamera->pos[1], gCamera->pos[2]);
                    play_puzzle_jingle();
                    o->oAction = 4;
                } else {
                    o->oAction = 5;
                }
            }
            break;
        case 2:
            set_mario_npc_dialog(1);
            gCamera->comitCutscene = 15;
            if (o->oTimer > 25)
                o->oAction = 1;
            break;
        case 3:
            if (o->oTimer > 25)
                o->oAction = 1;
            break;
        case 4:
            if (o->oTimer > 30) {
                set_mario_npc_dialog(0);
                gCamera->comitCutscene = 0;
                o->oAction = 5;
            }
            break;
    }
}



void bhv_garden_mips_init(void) {
    u8 starFlags = save_file_get_currency_flags() & (1 << 1);
    if (!starFlags) {
        o->oBehParams2ndByte = 0;
        o->oMipsForwardVelocity = 50.0f;
    } else {
        o->activeFlags = 0;
    }

    o->oInteractionSubtype = INT_SUBTYPE_HOLDABLE_NPC;
    o->oGravity = -9.0f;
    //o->oFriction = 10.0f;
    //o->oBuoyancy = 1.2f;

    cur_obj_disable();

    cur_obj_init_animation(0);
    o->oObjF4 = cur_obj_nearest_object_with_behavior(bhvPoundLego);
    if (o->oObjF4 == NULL) {
        o->activeFlags = 0;
        return;
    }
    vec3f_copy(&o->oPosX, &o->oObjF4->oPosX);
}

void bhv_garden_mips_run_loop(void) {
    Vec3f pos;
    switch (o->oHeldState) {
        case HELD_FREE:
            if (o->oDistanceToMario > 2000.0f)
                o->oForwardVel = 0;
            else
                o->oForwardVel = 35.0f;
            
            if (o->oTimer > o->os1610A) {
                o->os1610C = CL_RandomMinMaxU16(1, 20);
                o->os1610A = CL_RandomMinMaxU16(30, 120);
            }
            o->os1610E += (0x20 * o->os1610C);
            o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->os1610E - o->oAngleToMario, 0x800);
            cur_obj_update_floor_and_walls();
            pos[1] = o->oPosY;
            pos[0] = o->oPosX + (sins(o->oMoveAngleYaw) * 100.0f);
            pos[2] = o->oPosZ + (coss(o->oMoveAngleYaw) * 100.0f);
            if (f32_find_wall_collision(&pos[0], &pos[1], &pos[2], 10.0f, 50.f)) {
                o->oPosY += 50.0f;
                cur_obj_reflect_move_angle_off_wall();
            }
            cur_obj_move_standard(0);

            if (o->oPosX < 9400.0f) {
                o->oPosX = 9400.0f;
            } else if (o->oPosX > 17600.0f) {
                o->oPosX = 17600.0f;
            }
            if (cur_obj_check_if_near_animation_end() == TRUE) {
                cur_obj_play_sound_2(SOUND_OBJ_MIPS_RABBIT);
            }
            break;
        case HELD_HELD:
            bhv_mips_held();
            break;
        case HELD_THROWN:
            bhv_mips_thrown();
            o->os16FA = 0;
            break;
        case HELD_DROPPED:
            bhv_mips_dropped();
            o->os16FA = 0;
            break;
    }
}


void bhv_garden_mips_loop(void) {
    Vec3f pos;
    struct Surface *floor;
    if (o->os16FA) {
        bhv_garden_mips_run_loop();
        //bhv_mips_act_idle();
        return;
    }
    switch (o->oAction) {
        case 0:
            if (o->oObjF4->activeFlags == 0) {
                if (o->os16110 >= 4) {
                    o->os16FA = 1;
                    o->oAction = 0;
                    o->oForwardVel = 35.0f;
                    o->oInteractType = INTERACT_GRABBABLE;
                    cur_obj_enable();
                    break;
                }
                o->oAction = 1;
                cur_obj_enable();
                cur_obj_init_animation(1);
                o->oForwardVel = 70.0f;
                o->oObjF4 = cur_obj_nearest_object_with_behavior(bhvPoundLego);
                if (o->oObjF4 != NULL)
                    o->oMoveAngleYaw = obj_angle_to_object(o, o->oObjF4);
                break;
            }
            o->os16F8 += 0x400;
            o->oObjF4->oPosX = o->oObjF4->oHomeX + (sins(o->os16F8) * 3.0f);
            o->oObjF4->oPosZ = o->oObjF4->oHomeZ + (coss(o->os16F8 * 4) * 2.0f);
            if ((o->oTimer & 7) == 0)
                spawn_mist_particles_variable(1, -60, 4.0f);
            break;
        case 1:
            cur_obj_update_floor_and_walls();
            pos[1] = o->oPosY;
            pos[0] = o->oPosX + (sins(o->oMoveAngleYaw) * 100.0f);
            pos[2] = o->oPosZ + (coss(o->oMoveAngleYaw) * 100.0f);
            if (f32_find_wall_collision(&pos[0], &pos[1], &pos[2], 10.0f, 50.f)) {
                o->oPosY += 50.0f;
            }
            cur_obj_move_standard(0);
            if (o->oTimer > 60) {
                o->oAction = 2;
                o->oForwardVel = 0;
                o->oVelY = 60.0f;
                o->oGravity = -5.0f;
            }
            break;
        case 2:
            CL_Move();
            if (o->oTimer > 10) {
                o->oAction = 0;
                o->os16110++;
                o->oVelY = 0;
                o->oGravity = -9.0f;

                spawn_mist_particles();
                o->oObjF4 = spawn_object(o, MODEL_POUND_LEGO, bhvPoundLego);
                o->oObjF4->oFaceAngleYaw = 0;
                do {
                    o->oObjF4->oPosX = 9200.0f + (8200.0f * random_float());
                    o->oObjF4->oPosZ = -2000.0f + (5200.0f * random_float());
                    o->oObjF4->oPosY = find_floor(o->oObjF4->oPosX, o->oObjF4->oPosY + 5000.0f, o->oObjF4->oPosZ, &floor);
                    vec3f_copy(&o->oObjF4->oHomeX, &o->oObjF4->oPosX);
                    vec3f_copy(&o->oPosX, &o->oObjF4->oHomeX);
                } while (floor->type == SURFACE_GENERAL_USE || 
                        CL_objptr_dist_to_nearest_object_with_behavior(o->oObjF4, bhvPoundLego) < 500.0f);

                cur_obj_disable();
            }
            break;
        case 4:
            cur_obj_init_animation(0);
            spawn_default_star(10668.0f, 379.0f, 729.0f);
            o->oAction = 5;
            o->oInteractType = INTERACT_IGLOO_BARRIER;
            break;
    }
}


void bhv_level_entrance_init(void) {
    obj_set_hitbox(o, &sLevelEntranceHitbox);
}


void bhv_level_entrance_loop(void) {
    if (o->oBehParams >> 24) {
        if (!(save_file_get_newflags(0) & SAVE_NEW_FLAG_UNLOCKED_PLAYSET)) {
            o->activeFlags = 0;
        }
    }
}


void bhv_pound_lego_loop(void) {
    s16 count;
    switch (o->oAction) {
        case 0:
            if (cur_obj_is_mario_ground_pounding_platform()) {
                o->oAction = 1;
            }
            break;
        case 1:
            o->oPosY -= 20.0f;
            if (o->oPosY < o->oHomeY - 100.0f) {
                spawn_mist_particles();
                o->activeFlags = 0;
                /*count = count_objects_with_behavior(bhvPoundLego);
                if (count != 1) {
                    spawn_orange_number(6 - count, 0, 50, 0);
                } else {
                    spawn_default_star(13610.0f, -460.0f, 8520.0f);
                }
                play_sound(SOUND_MENU_COLLECT_SECRET + (((u8) 6 - count) << 16),
                    gGlobalSoundSource);*/
            }
            break;
    }
}


void bhv_shaky_plat_loop(void) {
    switch (o->oAction) {
        case 0:
            if (gMarioObject->platform == o) {
                o->oAction = 1;
            }
            break;
        case 1:
            o->oFaceAnglePitch += o->oTimer & 1 ? 0x100 : -0x100;
            if (o->oTimer > 20) {
                o->oAction = 2;
                play_sound(SOUND_GENERAL_CLAM_SHELL3, o->header.gfx.cameraToObject);
            } 
            break;
        case 2:
            o->oFaceAnglePitch = approach_s16_symmetric(o->oFaceAnglePitch, 0x4000, 0x800);
            if (o->oTimer > 60) {
                o->oAction = 3;
            }
            break;
        case 3:
            o->oFaceAnglePitch = approach_s16_symmetric(o->oFaceAnglePitch, 0, 0x300);
            if (o->oFaceAnglePitch == 0) {
                o->oAction = 0;
            }
            break;
    }
}



void bhv_lego_piece_init(void) {
    s16 param = CL_RandomMinMaxU16(0, 4);
    o->os16F4 = sLegoColors[param][0];
    o->os16F6 = sLegoColors[param][1];
    o->os16F8 = sLegoColors[param][2];

    o->oPosX += (random_float() - 0.5f) * 2000.0f;
    o->oPosY += 1000.0f;
    o->oPosZ += (random_float() - 0.5f) * 2000.0f;
    vec3f_copy(&o->oFloatFC, &o->oPosX);

    o->os1610C = o->oFaceAngleYaw;
    o->os16110 = o->oFaceAnglePitch;

    o->oFaceAngleYaw = random_u16();
    o->oFaceAnglePitch = random_u16();
}

void bhv_lego_piece_loop(void) {
    f32 dist;
    s16 pitch, yaw;
    switch (o->oAction) {
        case 0:
            o->oFaceAngleYaw += 0x200;
            o->oFaceAnglePitch += 0x200;

            if (o->oTimer > 60) {
                o->os1610E = CL_RandomMinMaxU16(0x40, 0x100);
                o->oTimer = 0;
            }
            o->os16112 = approach_s16_symmetric(o->os16112, o->os1610E, 0x10);
            o->os16FA += o->os16112;
            o->oPosX = o->oFloatFC + sins(o->os16FA) * 200.0f;
            o->oPosZ = o->oFloat104 + coss(o->os16FA) * 100.0f;


            if (gMarioState->pos[1] > o->oHomeY + 1000.0f)
                o->oFloat100 = o->oHomeY - 1000.0f;
            else
                o->oFloat100 = o->oHomeY + 1000.0f;
            o->oPosY = approach_f32_symmetric(o->oPosY, o->oFloat100, 50.0f);

            CL_dist_between_points(&o->oHomeX, gMarioState->pos, &dist);
            if (dist < 2500.0f) {
                o->oFloatFC = o->oPosX;
                o->oFloat104 = o->oPosZ;
                o->oAction = 1;
                o->os16FA = o->os16112 = 0;
                vec3f_get_dist_and_angle(&o->oPosX, &o->oHomeX, &dist, &pitch, &yaw);
                o->oForwardVel = dist / 15.0f;//100.0f;
            }
            break;
        case 1:
            o->oFaceAngleYaw = approach_s16_symmetric(o->oFaceAngleYaw, o->os1610C, 0x800);
            o->oFaceAnglePitch = approach_s16_symmetric(o->oFaceAnglePitch, o->os16110, 0x800);
            o->oFloat108 = approach_f32_symmetric(o->oFloat108, 1.0f, 0.08f);
            cur_obj_scale(o->oFloat108);

            vec3f_get_dist_and_angle(&o->oPosX, &o->oHomeX, &dist, &pitch, &yaw);
            o->oMoveAnglePitch = pitch;
            o->oMoveAngleYaw = yaw;
            CL_Move_3d();
            if (dist < o->oForwardVel) {
                vec3f_copy(&o->oPosX, &o->oHomeX);
                o->oFaceAngleYaw = (o->oMoveAngleYaw = o->os1610C);
                o->oFaceAnglePitch = (o->oMoveAnglePitch = o->os16110);
                o->oAction = 2;
                o->oForwardVel = 0;
                o->oVelX = (o->oVelZ = 0);
                o->oFloat108 = 1.0f;
                cur_obj_scale(o->oFloat108);
            }
            break;
        case 2:
            if (o->oDistanceToMario > 3000.0f && gMarioObject->platform != o) {
                o->oAction = 3;
                o->oFloatFC = o->oHomeX + (random_float() - 0.5f) * 2000.0f;
                o->oFloat104 = o->oHomeZ + (random_float() - 0.5f) * 2000.0f;
                if (gMarioState->pos[1] > o->oHomeY + 1000.0f)
                    o->oFloat100 = o->oHomeY - 1000.0f;
                else
                    o->oFloat100 = o->oHomeY + 1000.0f;
                vec3f_get_dist_and_angle(&o->oPosX, &o->oFloatFC, &dist, &pitch, &yaw);
                o->oForwardVel = dist / 20.0f;
            }
            load_object_collision_model();
            break;
        case 3:
            o->oFaceAngleYaw += 0x200;
            o->oFaceAnglePitch += 0x200;

            o->oFloat108 = approach_f32_symmetric(o->oFloat108, 0.7f, 0.08f);
            cur_obj_scale(o->oFloat108);

            vec3f_get_dist_and_angle(&o->oPosX, &o->oFloatFC, &dist, &pitch, &yaw);
            o->oMoveAnglePitch = pitch;
            o->oMoveAngleYaw = yaw;
            CL_Move_3d();
            if (dist < o->oForwardVel) {
                vec3f_copy(&o->oPosX, &o->oFloatFC);
                o->oAction = 0;
                o->oForwardVel = 0;
                o->oVelX = (o->oVelZ = 0);
                o->oFloat108 = 0.7f;
                cur_obj_scale(o->oFloat108);
            }
            break;
    }

}


void bhv_rubber_band_loop(void) {
    struct MarioState *m = gMarioState;
    switch (o->oAction) {
        case 0:
            if (o->oDistanceToMario < 250.0f && 
                (gCurrLevelNum != LEVEL_CCM || save_file_get_newflags(0) & SAVE_NEW_FLAG_CITY_BAND_BOUGHT)) {
                o->oAction = 1; 
                m->faceAngle[1] = o->oMoveAngleYaw; 
                set_mario_action(m, ACT_GRABBED, 0);
            }
            break;
        case 1:
            m->usedObj = o;
            m->interactObj = o;
            vec3f_copy(m->pos, &o->oPosX);
            m->pos[0] += -180.0f * sins(o->oMoveAngleYaw) * o->header.gfx.scale[2];
            m->pos[2] += -180.0f * coss(o->oMoveAngleYaw) * o->header.gfx.scale[2];
            o->header.gfx.scale[2] = approach_f32_asymptotic(o->header.gfx.scale[2], 4.0f, 0.05f);
            vec3f_copy(m->marioObj->header.gfx.pos, m->pos);
            vec3s_set(m->marioObj->header.gfx.angle, 0, m->faceAngle[1], 0);
            if (m->input & INPUT_A_PRESSED) {
                o->oAction = 2;
                //m->faceAngle[0] = 0xF500;
                m->forwardVel = 80.0f;
                m->vel[1] = 30.0f;
                set_mario_action(m, ACT_SHOT_FROM_CANNON, 0);
            }
            if (m->input & INPUT_B_PRESSED) {
                m->vel[1] = 0;
                set_mario_action(m, ACT_THROWN_FORWARD, 0);
                o->oAction = 3;
            }
            break;
        case 2:
            if (o->oTimer > 45) {
                o->oAction = 4;
                sDelayedWarpOp = 0x10;
                sDelayedWarpTimer = 12;
                sSourceWarpNodeId = 0x20;
                music_changed_through_warp(sSourceWarpNodeId);
                play_transition(WARP_TRANSITION_FADE_INTO_COLOR, 0xC, 0x00, 0x00, 0x00);
                if (!(save_file_get_newflags(0) & SAVE_NEW_FLAG_UNLOCKED_PLAYSET)) {
                    save_file_set_newflags(SAVE_NEW_FLAG_UNLOCKED_PLAYSET, 0);
                }
                break;
            }
        case 3:
            if (o->oTimer < 10) {
                //o->header.gfx.scale[2] = approach_f32_asymptotic(o->header.gfx.scale[2], -3.0f, 0.7f);
                o->header.gfx.scale[2] = approach_f32(o->header.gfx.scale[2], -3.0f, 1.0f, 1.0f);
            } else if (o->oTimer < 20) {
                //o->header.gfx.scale[2] = approach_f32_asymptotic(o->header.gfx.scale[2], 1.5f, 0.5f);
                o->header.gfx.scale[2] = approach_f32(o->header.gfx.scale[2], 1.5f, 0.5f, 0.5f);
            } else if (o->oTimer < 45) {
                o->header.gfx.scale[2] = approach_f32_asymptotic(o->header.gfx.scale[2], 1.0f, 0.5f);
            } else if (o->oTimer > 50) {
                o->oAction = 0;
            }
            break;
    }
}