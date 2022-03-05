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
    if (o->oFC != sMusicInstsChecked) {
        o->oF4 -= 12;
        if (o->oF4 < 0)
            o->oF4 += CHASE_SIZE;
    }
    o->oFC = sMusicInstsChecked;
    vec3f_copy(sMusicChase[o->oF4].pos, gMarioState->pos);
    sMusicChase[o->oF4].faceAngle = gMarioState->faceAngle[1];

    if (o->oTimer > CHASE_SIZE) {
        vec3f_copy(&o->oPosX, sMusicChase[o->oF8].pos);
        o->oFaceAngleYaw = sMusicChase[o->oF8].faceAngle;
    }

    if (++o->oF4 > CHASE_SIZE - 1)
        o->oF4 = 0;
    if (++o->oF8 > CHASE_SIZE - 1)
        o->oF8 = 0;

}


void bhv_music_chase_init(void) {
    obj_set_hitbox(o, &sChairHitbox);
    o->oOpacity = 170;
}


void bhv_music_chase_loop(void) {
    music_room_chase();
    o->oInteractStatus = 0;
}



void control_music_room(void) {
    fade_channel_volume_scale(0, 0, sMusicRoomVol[0], 1);
    fade_channel_volume_scale(0, 9, sMusicRoomVol[1], 1);
    fade_channel_volume_scale(0, 7, sMusicRoomVol[2], 1);
    fade_channel_volume_scale(0, 6, sMusicRoomVol[3], 1);
}


void bhv_music_shyguy_loop(void) {
    switch (o->oAction) {
        case 0:
            if (o->oTimer > 5) {
                o->oAction = 1;
                seq_player_unlower_volume(0, 60);
                play_music(0, SEQUENCE_ARGS(4, SEQ_LEVEL_GRASS), 0);
                // stop_background_music(SEQUENCE_ARGS(4, SEQ_LEVEL_GRASS));
            }
            break;
        case 1:
            control_music_room();
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
                    spawn_object(o, MODEL_BOO, bhvMusicChase);
                }
            }
            break;
    }
}