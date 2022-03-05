void fade_channel_volume_scale(u8 player, u8 channelId, u8 targetScale, u16 fadeTimer);
static void const *sInstsCollision[] = {
    violin_col_collision,
    drums_col_collision,
    piano_col_collision,
    guitar_col_collision,
};

s16 sInstPos[4][2] = {
    0
};



s8 sMusicRoomVol[4] = {0, 0, 0, 0};


void control_music_room(void) {
    fade_channel_volume_scale(0, 0, sMusicRoomVol[0], 1);
    fade_channel_volume_scale(0, 6, sMusicRoomVol[1], 1);
    fade_channel_volume_scale(0, 7, sMusicRoomVol[2], 1);
    fade_channel_volume_scale(0, 8, sMusicRoomVol[3], 1);
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
}

void bhv_music_insts_loop(void) {
    switch (o->oAction) {
        case 0:
            if (o->oDistanceToMario < 1000.0f) {
                o->oAction = 1;
                sMusicRoomVol[o->oBehParams2ndByte] = 127;
            }
            break;
        case 1:
            o->oOpacity = approach_s16_symmetric(o->oOpacity, 255, 0x8);
            break;
    }
}