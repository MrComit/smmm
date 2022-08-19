void fade_channel_volume_scale(u8 player, u8 channelId, u8 targetScale, u16 fadeTimer);

static struct ObjectHitbox sChaseHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 2,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 80,
    /* height:            */ 100,
    /* hurtboxRadius:     */ 80,
    /* hurtboxHeight:     */ 100,
};


static void const *sInstsCollision[] = {
    violin_col_collision,
    drums_col_collision,
    piano_col_collision,
    guitar_col_collision,
};

s16 sInstPos[4][2] = {0};

s32 sInstDist[4] = {0};



s8 sMusicRoomVol[4] = {0, 0, 0, 0};


s8 sMusicInstsChecked = 0;

// Vec3s sPeepaColors[2] = {
// {0xE8, 0x82, 0xFF},
// {0x87, 0x7E, 0xFF},
// };

struct ShadowCopy {
    Vec3f pos;
    u16 faceAngle;
    u16 filler;
};

#define CHASE_SIZE 70
struct ShadowCopy sMusicChase[CHASE_SIZE] = {
0, /*{{0, 0, 0}, 0, 0}, {{0, 0, 0}, 0, 0}, {{0, 0, 0}, 0, 0},
{{0, 0, 0}, 0, 0}, {{0, 0, 0}, 0, 0}, {{0, 0, 0}, 0, 0},
{{0, 0, 0}, 0, 0}, {{0, 0, 0}, 0, 0}, {{0, 0, 0}, 0, 0},
{{0, 0, 0}, 0, 0}, {{0, 0, 0}, 0, 0}, {{0, 0, 0}, 0, 0},
{{0, 0, 0}, 0, 0}, {{0, 0, 0}, 0, 0}, {{0, 0, 0}, 0, 0},
{{0, 0, 0}, 0, 0}, {{0, 0, 0}, 0, 0}, {{0, 0, 0}, 0, 0},
{{0, 0, 0}, 0, 0}, {{0, 0, 0}, 0, 0}, {{0, 0, 0}, 0, 0},
{{0, 0, 0}, 0, 0}, {{0, 0, 0}, 0, 0}, {{0, 0, 0}, 0, 0},
{{0, 0, 0}, 0, 0}, {{0, 0, 0}, 0, 0}, {{0, 0, 0}, 0, 0},
{{0, 0, 0}, 0, 0}, {{0, 0, 0}, 0, 0}, {{0, 0, 0}, 0, 0},
{{0, 0, 0}, 0, 0}, {{0, 0, 0}, 0, 0}, {{0, 0, 0}, 0, 0},
{{0, 0, 0}, 0, 0}, {{0, 0, 0}, 0, 0}, {{0, 0, 0}, 0, 0},
{{0, 0, 0}, 0, 0}, {{0, 0, 0}, 0, 0}, {{0, 0, 0}, 0, 0},
{{0, 0, 0}, 0, 0}, {{0, 0, 0}, 0, 0}, {{0, 0, 0}, 0, 0},
{{0, 0, 0}, 0, 0}, {{0, 0, 0}, 0, 0}, {{0, 0, 0}, 0, 0},*/
};


void music_room_chase(void) {
    f32 dist;
    s16 pitch, yaw;
    if (o->oFC != sMusicInstsChecked) {
        o->o100 -= 12;
        if (o->o100 < 0)
            o->o100 += CHASE_SIZE;
    }
    o->oFC = sMusicInstsChecked;
    vec3f_copy(sMusicChase[o->o100].pos, gMarioState->pos);
    sMusicChase[o->o100].faceAngle = gMarioState->faceAngle[1];

    if (o->oTimer > CHASE_SIZE) {
        // vec3f_copy(&o->oPosX, sMusicChase[o->o104].pos);
        vec3f_get_dist_and_angle(&o->oPosX, sMusicChase[o->o104].pos, &dist, &pitch, &yaw);
        o->oMoveAngleYaw = yaw;
        if (dist < 100.0f) {
            vec3f_copy(&o->oPosX, sMusicChase[o->o104].pos);
        } else {
            CL_Move();
            o->oPosY = approach_f32_symmetric(o->oPosY, sMusicChase[o->o104].pos[1], 30.0f);
        }
        o->oFaceAngleYaw = sMusicChase[o->o104].faceAngle;
    }

    if (++o->o100 > CHASE_SIZE - 1)
        o->o100 = 0;
    if (++o->o104 > CHASE_SIZE - 1)
        o->o104 = 0;

}




void bhv_music_chase_init(void) {
    // s32 index = 0;
    // if (o->oBehParams2ndByte == 2) {
    //     index = 1;
    // }
    // vec3s_copy(&o->os16F4, sPeepaColors[index]);
    obj_set_hitbox(o, &sChairHitbox);
    // o->oOpacity = 170;
    o->oPosY -= 200.0f;
    o->oForwardVel = 30.0f;
}


void bhv_music_chase_loop(void) {
    switch (o->oAction) {
        case 0:
            o->oOpacity = approach_s16_symmetric(o->oOpacity, 210, 6);
            o->oPosY = approach_f32_symmetric(o->oPosY, o->oHomeY, 10.0f);
            if (o->oPosY == o->oHomeY && o->oOpacity == 210) {
                o->oAction = 1;
            }
            break;
        case 1:
            music_room_chase();

            if (sMusicInstsChecked == 4) {
                o->oAction = 2;
            }
            break;
        case 2:
            o->oOpacity = approach_s16_symmetric(o->oOpacity, 0, 5);
            o->oPosY = approach_f32_symmetric(o->oPosY, o->oHomeY - 500.0f, 15.0f);
            if (o->oOpacity == 0 || o->oPosY == o->oHomeY - 500.0f) {
                o->activeFlags = 0;
            }
            break;
    }
    o->oInteractStatus = 0;
}



void control_music_room(void) {
    //strings
    fade_channel_volume_scale(0, 0, sMusicRoomVol[0], 1);

    //guitar
    fade_channel_volume_scale(0, 1, sMusicRoomVol[1], 1);
    fade_channel_volume_scale(0, 4, sMusicRoomVol[1], 1);
    fade_channel_volume_scale(0, 5, sMusicRoomVol[1], 1);

    //piano
    fade_channel_volume_scale(0, 2, sMusicRoomVol[2], 1);

    //guitar
    fade_channel_volume_scale(0, 3, sMusicRoomVol[3], 1);
}

void bhv_music_barrier_loop(void) {
    switch (o->oAction) {
        case 0:
            o->oOpacity = approach_s16_symmetric(o->oOpacity, 150, 4);
            break;
        case 1:
            o->oOpacity = approach_s16_symmetric(o->oOpacity, 0, 6);
            if (o->oOpacity == 0) {
                o->activeFlags = 0;
            }
            break;
    }
}

void bhv_music_shyguy_loop(void) {
    switch (o->oAction) {
        case 0:
            if (o->oTimer > 5) {
                // cur_obj_init_animation_with_sound(2);
                o->oObjF4 = spawn_object(o, MODEL_MUSIC_BARRIER, bhvMusicBarrier);
                o->oObjF4->oFaceAngleYaw = 0;
                vec3f_set(&o->oObjF4->oPosX, 12795.0f, 0.0f, 14423.0f);
                o->oAction = 1;
                seq_player_unlower_volume(0, 60);
                play_music(0, SEQUENCE_ARGS(4, SEQ_MUSIC_ROOM), 0);
                // stop_background_music(SEQUENCE_ARGS(4, SEQ_LEVEL_GRASS));
            }
            break;
        case 1:
            control_music_room();
            if (sMusicInstsChecked == 4) {
                o->oObjF4->oAction = 1;
                o->oOpacity = approach_s16_symmetric(o->oOpacity, 255, 15);
                if (o->oOpacity == 255) {
                    o->activeFlags = 0;
                    o->oObjF8 = spawn_object(o, MODEL_SHYGUY, bhvShyguy);
                    o->oObjF8->os16110 = 1;
                    o->oObjF8->oBehParams2ndByte =  o->oBehParams2ndByte;
                }
            }
            break;
    }
}

void bhv_music_insts_init(void) {
    o->collisionData = segmented_to_virtual(sInstsCollision[o->oBehParams2ndByte]);
    sInstPos[o->oBehParams2ndByte][0] = (s16)o->oPosX - 8796;
    sInstPos[o->oBehParams2ndByte][1] = (s16)o->oPosZ - 14423;
    sMusicInstsChecked = 0;
}

void bhv_music_insts_loop(void) {
    switch (o->oAction) {
        case 0:
            if (o->oDistanceToMario < 500.0f) {
                o->oAction = 1;
            }
            if (o->oDistanceToMario < 5000.0f) {
                sMusicRoomVol[o->oBehParams2ndByte] = ((5000.0f - o->oDistanceToMario) / 5000.0f) * 127;
            }
            break;
        case 1:
            o->oOpacity = approach_s16_symmetric(o->oOpacity, 255, 0x8);
            sInstDist[o->oBehParams2ndByte] = approach_s32(sInstDist[o->oBehParams2ndByte], 720000, 50000, 50000);
            sMusicRoomVol[o->oBehParams2ndByte] = approach_s16_symmetric(sMusicRoomVol[o->oBehParams2ndByte], 127, 3);
            if (o->oOpacity == 255 && sInstDist[o->oBehParams2ndByte] == 720000 && sMusicRoomVol[o->oBehParams2ndByte] == 127) {
                o->oAction = 2;
                sMusicInstsChecked++;
                if (sMusicInstsChecked == 1) {
                    spawn_object(o, MODEL_MUSIC_PEEPA, bhvMusicChase);
                }
            }
            break;
    }
}