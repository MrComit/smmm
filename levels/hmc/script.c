#include <ultra64.h>
#include "sm64.h"
#include "behavior_data.h"
#include "model_ids.h"
#include "seq_ids.h"
#include "dialog_ids.h"
#include "segment_symbols.h"
#include "level_commands.h"

#include "game/level_update.h"

#include "levels/scripts.h"

#include "actors/common1.h"
#include "actors/group0.h"
#include "actors/group0.h"
#include "actors/group0.h"
#include "actors/group0.h"
#include "actors/group0.h"
#include "actors/group0.h"
#include "actors/group0.h"
#include "actors/group0.h"

/* Fast64 begin persistent block [includes] */
#include "actors/group0.h"
/* Fast64 end persistent block [includes] */

#include "make_const_nonconst.h"
#include "levels/hmc/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_hmc_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _hmc_segment_7SegmentRomStart, _hmc_segment_7SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _cave_yay0SegmentRomStart, _cave_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group6_yay0SegmentRomStart, _group6_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group6_geoSegmentRomStart, _group6_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group17_yay0SegmentRomStart, _group17_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group17_geoSegmentRomStart, _group17_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_YAY0(0xa, _bbh_skybox_yay0SegmentRomStart, _bbh_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0(0xb, _effect_yay0SegmentRomStart, _effect_yay0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_7), 
	JUMP_LINK(script_func_global_18), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_WARP_PIPE, warp_pipe_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_CASTLE_DOOR, castle_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_DICE_ENEMY, dice_enemy_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_POOL_BALL, pool_ball_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_POOL_CUE, pool_cue_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_POOL_BARRIER, pool_barrier_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_POOL_FLOOR, pool_floor_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_TOY_MOLE, toy_mole_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_MOLE_CAGE, mole_cage_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_PINGPONG_BALL, pingpong_ball_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_PINGPONG_PADDLE, pingpong_paddle_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_TROPHY_OCTOGON, trophy_octogon_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_TROPHY_RECTANGLE, trophy_rectangle_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_MUSIC_INSTS, music_insts_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_FOREROOM_OBJECT, foreroom_object_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_FOREROOM_LEVER, foreroom_lever_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_FOREROOM_WINDOW, foreroom_window_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_TIGHT_ROPE, tight_rope_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_TREE_LIMB, tree_limb_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BLUE_OWL, blue_owl_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_THEATER_SCREEN, theater_screen_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_GOOMBA_2D, goomba_2d_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_KOOPA_2D, koopa_2d_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BULLETBILL_2D, bulletbill_2d_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_THEATER_ARENA, theater_arena_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BOOMBOOM_2D, boom_boom_2d_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_THEATER_TOMATO, theater_tomato_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_TREEHOUSE_LOG, treehouse_log_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_TREEHOUSE_SPIKE, treehouse_spike_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CUSHION_FRIEND, cushion_friend_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_STATIC_TRI, static_tri_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_STATIC_WALL, static_wall_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_VASE_THROW, vase_throw_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_SAUNA_GRATE, sauna_grate_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BULLY_GATE, bully_gate_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_SAUNA_ROCK, sauna_rock_rise_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_FAN_BLADES, fan_blades_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_ATTIC_GRATE, attic_grate_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_ATTIC_SPIRE, attic_spire_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_ATTIC_ROCK, attic_rock_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_ATTIC_BULLY, attic_bully_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_ATTIC_SPIKE, attic_spike_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_ATTIC_INDICATOR, attic_indicator_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_ATTIC_WALL, attic_wall_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_MUSIC_BARRIER, music_barrier_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_MUSIC_PEEPA, music_peepa_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_OPENING_WALL, opening_wall_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BULLY_TROPHY, bully_trophy_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_TROPHY_ELEVATOR, trophy_elevator_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_PLAT_HALL_WALL, plat_hall_wall_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_RED_VASE, red_vase_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_PROSPECTOR_T, prospector_t_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_L6_2D_RED, l6_2d_red_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, hmc_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x1A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_HMC, 0x01, 0x1A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x50, LEVEL_WF, 0x01, 0x0F, WARP_NO_CHECKPOINT),
		WARP_NODE(0x67, LEVEL_WF, 0x01, 0x05, WARP_NO_CHECKPOINT),
		WARP_NODE(0x69, LEVEL_HMC, 0x02, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0E, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x23, LEVEL_HMC, 0x01, 0x24, WARP_NO_CHECKPOINT),
		WARP_NODE(0x24, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x25, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x26, LEVEL_HMC, 0x01, 0x25, WARP_NO_CHECKPOINT),
		INSTANT_WARP(0, 0x01, -5348, 8739, -5708),
		INSTANT_WARP(1, 0x01, 0, 0, 5759),
		INSTANT_WARP(2, 0x01, 0, 0, -5759),
		INSTANT_WARP(3, 0x01, -5759, 0, 0),
		INSTANT_WARP(4, 0x01, 5759, 0, 0),
		INSTANT_WARP(5, 0x01, 5348, -10739, -9610),
		INSTANT_WARP(6, 0x01, 0, 0, -8571),
		INSTANT_WARP(7, 0x01, 0, 0, 8571),
		WARP_NODE(0x27, LEVEL_HMC, 0x01, 0x28, WARP_NO_CHECKPOINT),
		WARP_NODE(0x28, LEVEL_HMC, 0x01, 0x27, WARP_NO_CHECKPOINT),
		WARP_NODE(0x3E, LEVEL_HMC, 0x01, 0x3F, WARP_NO_CHECKPOINT),
		WARP_NODE(0x3F, LEVEL_HMC, 0x01, 0x3E, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, -10081, 145, 2264, 0, 0, 0, (0x1A << 16), bhvAirborneDeathWarp),
		OBJECT(MODEL_NONE, -10081, 145, 2264, 0, 0, 0, (0xA << 16), bhvFlyingWarp),
		MARIO_POS(0x01, 0, -10081, 145, 2264),
		OBJECT(MODEL_NONE, 1509, 200, -7511, 0, 0, 0, (0xE << 16), bhvFlyingWarp),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, -9031, 0, 11348, 0, 90, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_CUSHION_FRIEND, -9177, 190, 6783, 0, 0, 0, 0x00000000, bhvCushionFriend),
		OBJECT(MODEL_OPENING_WALL, -10081, 5000, 12063, 0, 0, 0, 0x00000000, bhvOpeningWall),
		OBJECT(MODEL_BREAKABLE_BOX, -1381, 27, 6476, 0, 0, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, -1381, 190, 5676, 90, 0, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, -1381, 490, 5676, 90, 0, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, -1381, 790, 5676, 90, 0, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, -1381, 1090, 5676, 90, 0, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, -1381, 927, 6513, 90, 0, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, -1381, 1227, 6513, 90, 0, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, -1381, 1527, 6513, 90, 0, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, -1381, 1390, 5676, 90, 0, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, -1381, 1827, 6513, 90, 0, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, -1381, 1540, 5706, 0, 0, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, -394, 1640, 5442, 0, 16, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, 404, 1740, 4993, 0, 56, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, 568, 1840, 4101, 0, 83, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, 62, 1940, 3454, 0, 97, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, -703, 2040, 3544, 0, 90, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, -1380, 2240, 3520, 0, 90, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, -480, 27, 8235, 0, 0, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, -1017, 27, 9628, 0, 0, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, -1126, -73, 10842, 0, 0, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, -1500, -173, 11824, 0, 0, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, -3714, -113, 12466, 0, 0, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_BULLY_TROPHY, -6584, 125, 3624, 0, 0, 0, 0x00000000, bhvBullyTrophy),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, 2146, 0, 11348, 0, 90, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, 1096, 0, 3063, 0, -180, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, -2579, 5185, 5663, 0, 0, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, -7304, 5185, 11348, 0, -90, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, 2146, 5185, 11348, 0, 90, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_TELEPORTER, -7681, 5185, 11347, 0, 90, 0, (0x27 << 16), bhvFadingWarp),
		OBJECT(MODEL_NONE, -7681, 150, 11347, 0, -90, 0, (0x28 << 16), bhvFadingWarp),
		OBJECT(MODEL_HEART, -2181, 2235, 3663, 0, 0, 0, 0x00000000, bhvRecoveryHeart),
		OBJECT(MODEL_PURPLE_SWITCH, 697, 100, 7489, 0, 90, 0, (18 << 24), bhvFloorSwitchHiddenObjects),
		OBJECT(MODEL_RED_COIN, -1380, 2440, 3520, 0, -180, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -3674, 67, 10626, 0, -180, 0, (1 << 16), bhvRedCoin),
		OBJECT(MODEL_TELEPORTER, -3674, 67, 10273, 0, -180, 0, (0x3E << 16) | (8 << 8), bhvFadingWarp),
		OBJECT(MODEL_NONE, 1558, 300, 11348, 0, -90, 0, (0x3F << 16), bhvFadingWarp),
		OBJECT(MODEL_SAVE_STATION, -6365, 0, 11598, 0, 0, 0, 0x00000000, bhvSaveStation),
		OBJECT(MODEL_STAR_PIECE, -8321, 100, 12170, 0, 0, 0, (0xF << 24), bhvStarPiece),
		OBJECT(MODEL_TOKEN, -2777, 57, 3363, 0, 90, 0, (1 << 16) | (0x23 << 8), bhvToken),
		OBJECT(MODEL_TOKEN, -8131, 5247, 11348, 0, 90, 0, (2 << 16) | (0x24 << 8), bhvToken),
		OBJECT(MODEL_TROPHY_OCTOGON, -2686, 400, 7189, 0, 23, 0, (32 << 24) | (5 << 16), bhvTrophyPlatRise),
		OBJECT(MODEL_TROPHY_OCTOGON, -2686, 400, 8740, 0, 23, 0, (32 << 24) | (5 << 16), bhvTrophyPlatRise),
		OBJECT(MODEL_TROPHY_OCTOGON, -4603, -100, 6876, 0, 0, 0, 0x00000000, bhvTrophyPlatSpin),
		OBJECT(MODEL_TROPHY_OCTOGON, -3413, -100, 5493, 0, 0, 0, 0x00000000, bhvTrophyPlatSpin),
		OBJECT(MODEL_TROPHY_RECTANGLE, -2647, -100, 12454, 0, -150, 0, (32 << 24) | (3 << 16), bhvTrophyRect),
		OBJECT(MODEL_TROPHY_RECTANGLE, -2486, -100, 9671, 0, -180, 0, (32 << 24) | (3 << 16), bhvTrophyRect),
		OBJECT(MODEL_TROPHY_RECTANGLE, -2486, -100, 10917, 0, -90, 0, (32 << 24) | (3 << 16), bhvTrophyRect),
		OBJECT(MODEL_TROPHY_ELEVATOR, -2579, 2085, 4663, 0, 0, 0, 0x00000000, bhvTrophyElevator),
		OBJECT(MODEL_BREAKABLE_BOX, 2496, 0, 14463, 0, 0, 0, 0x00000000, bhvBreakableBox),
		OBJECT(MODEL_BREAKABLE_BOX, 2296, 0, 14463, 0, 0, 0, 0x00000000, bhvBreakableBox),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, 3746, 0, 12498, 0, 90, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, 3746, 0, 8273, 0, 90, 0, (8 << 16), bhvSmallKeyDoor),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, 2946, 0, 6223, 0, -180, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_JOURNAL_BOOK, 2296, 0, 14463, 0, 0, 0, (DIALOG_052 << 16), bhvJournalBook),
		OBJECT(MODEL_PROSPECTOR_LOCK, 2946, 0, 6273, 0, 0, 0, (3 << 16), bhvProspectorLock),
		OBJECT(MODEL_GLOBAL_GATE, 3786, 0, 12498, 0, 90, 0, 0x00000000, bhvGlobalGate),
		OBJECT(MODEL_MUSIC_INSTS, 12796, 0, 18423, 0, -90, 0, (3 << 16), bhvMusicInsts),
		OBJECT(MODEL_MUSIC_INSTS, 6296, 0, 17423, 0, -180, 0, (1 << 16), bhvMusicInsts),
		OBJECT(MODEL_MUSIC_INSTS, 11296, 0, 12423, 0, -90, 0, (2 << 16), bhvMusicInsts),
		OBJECT(MODEL_MUSIC_INSTS, 6796, 0, 9923, 0, -45, 0, 0x00000000, bhvMusicInsts),
		OBJECT(MODEL_SHYGUY, 13167, 115, 14420, 0, -90, 0, (8 << 16), bhvMusicShyguy),
		OBJECT(MODEL_DICE_ENEMY, 8244, 0, 7430, 0, -90, 0, (0 << 16), bhvDiceEnemy),
		OBJECT(MODEL_DICE_ENEMY, 8377, 0, 6662, 0, -90, 0, (1 << 16), bhvDiceEnemy),
		OBJECT(MODEL_DICE_ENEMY, 7625, 0, 6856, 0, -90, 0, (2 << 16), bhvDiceEnemy),
		OBJECT(MODEL_DICE_ENEMY, 6974, 0, 6821, 0, -90, 0, (3 << 16), bhvDiceEnemy),
		OBJECT(MODEL_DICE_ENEMY, 7645, 0, 7522, 0, -90, 0, (4 << 16), bhvDiceEnemy),
		OBJECT(MODEL_DICE_ENEMY, 7180, 0, 7836, 0, -90, 0, (5 << 16), bhvDiceEnemy),
		OBJECT(MODEL_POOL_FLOOR, 4842, 0, 8273, 0, 0, 0, 0x00000000, bhvPoolFloor),
		OBJECT(MODEL_GLOBAL_GATE, 3786, 0, 8273, 0, 90, 0, 0x00000000, bhvGlobalGate),
		OBJECT(MODEL_KOOPA, 7036, 1875, 4042, 0, -90, 0, (0 << 16), bhvKoopa),
		OBJECT(MODEL_KOOPA, 7339, 1875, 4786, 0, -90, 0, (1 << 16), bhvKoopa),
		OBJECT(MODEL_KOOPA, 7062, 2250, 6056, 0, -90, 0, (2 << 16), bhvKoopa),
		OBJECT(MODEL_MOLE_CAGE, 9171, 255, 8073, 0, 0, 0, (9 << 16), bhvMoleCage),
		OBJECT(MODEL_POOL_BARRIER, 5608, 0, 7118, 0, 0, 0, 0x00000000, bhvPoolBarrier),
		OBJECT(MODEL_POOL_BALL, 6733, 247, 8715, 0, 180, 0, (0 << 16), bhvPoolBall),
		OBJECT(MODEL_POOL_BALL, 6746, 247, 8740, 0, 180, 0, (1 << 16), bhvPoolBall),
		OBJECT(MODEL_POOL_BALL, 6733, 247, 8765, 0, 180, 0, (4 << 16), bhvPoolBall),
		OBJECT(MODEL_POOL_BALL, 6746, 247, 8790, 0, 180, 0, (7 << 16), bhvPoolBall),
		OBJECT(MODEL_POOL_BALL, 6733, 247, 8815, 0, 180, 0, (12 << 16), bhvPoolBall),
		OBJECT(MODEL_POOL_BALL, 6758, 247, 8765, 0, 180, 0, (3 << 16), bhvPoolBall),
		OBJECT(MODEL_POOL_BALL, 6758, 247, 8815, 0, 180, 0, (11 << 16), bhvPoolBall),
		OBJECT(MODEL_POOL_BALL, 6708, 247, 8765, 0, 180, 0, (5 << 16), bhvPoolBall),
		OBJECT(MODEL_POOL_BALL, 6708, 247, 8815, 0, 180, 0, (13 << 16), bhvPoolBall),
		OBJECT(MODEL_POOL_BALL, 6683, 247, 8815, 0, 180, 0, (14 << 16), bhvPoolBall),
		OBJECT(MODEL_POOL_BALL, 6783, 247, 8815, 0, 180, 0, (10 << 16), bhvPoolBall),
		OBJECT(MODEL_POOL_BALL, 6721, 247, 8740, 0, 180, 0, (2 << 16), bhvPoolBall),
		OBJECT(MODEL_POOL_BALL, 6721, 247, 8790, 0, 180, 0, (8 << 16), bhvPoolBall),
		OBJECT(MODEL_POOL_BALL, 6696, 247, 8790, 0, 180, 0, (9 << 16), bhvPoolBall),
		OBJECT(MODEL_POOL_BALL, 6771, 247, 8790, 0, 180, 0, (6 << 16), bhvPoolBall),
		OBJECT(MODEL_POOL_BALL, 6733, 247, 8640, 0, 180, 0, (16 << 16), bhvPoolBall),
		OBJECT(MODEL_POOL_CUE, 5419, 427, 8273, 0, 18, 0, 0x00000000, bhvPoolCue),
		OBJECT(MODEL_BOO, 7675, 161, 8494, 0, -180, 0, (0xF << 16), bhvRoomBoo),
		OBJECT(MODEL_SHYGUY, 4302, 160, 4395, 0, 90, 0, (0 << 16), bhvShyguyPingpong),
		OBJECT(MODEL_SHYGUY, 5288, 160, 4395, 0, -90, 0, (1 << 16), bhvShyguyPingpong),
		OBJECT(MODEL_SMALL_KEY, 9608, 1875, 5761, 0, 0, 0, (1 << 24) | (9 << 16), bhvSmallKey),
		OBJECT(MODEL_TOY_MOLE, 9171, 100, 8698, 0, -14, 0, 0x06000000, bhvToyMole),
		OBJECT(MODEL_RED_COIN, 7733, 150, 5011, 0, -180, 0, (2 << 16), bhvWingedRedCoin),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, 1096, 0, -5196, 0, -180, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_L6_2D_RED, -56, 455, -7691, 0, 0, 0, (1 << 24) | (3 << 16), bhv2DRedCoin),
		OBJECT(MODEL_FAN_BLADES, -860, 888, -6295, 0, 0, 0, 0x00000000, bhvFanBlades),
		OBJECT(MODEL_GLOBAL_GATE, -2114, 0, -6496, 0, 90, 0, 0x00000000, bhvGlobalGate),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, -2154, 0, -6496, 0, -90, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, -4754, 250, -11146, 0, -90, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, -4754, 0, -8496, 0, -90, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, -3454, 0, -7346, 0, -180, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_FOREROOM_OBJECT, -2024, 0, -5920, 0, 0, 0, (1 << 16), bhvForeroomObject),
		OBJECT(MODEL_FOREROOM_OBJECT, -176, 0, -6101, 0, 0, 0, 0x00000000, bhvForeroomObject),
		OBJECT(MODEL_FOREROOM_OBJECT, -544, 0, -7488, 0, 0, 0, (2 << 16), bhvForeroomObject),
		OBJECT(MODEL_RED_COIN, -3454, 0, -9221, 0, -180, 0, (4 << 16), bhvFakeRedCoin),
		OBJECT(MODEL_FOREROOM_OBJECT, -1243, 0, -7035, 0, 0, 0, (3 << 16), bhvForeroomObject),
		OBJECT(MODEL_FOREROOM_OBJECT, 2296, 0, -6046, 0, 0, 0, (4 << 16), bhvForeroomObject),
		OBJECT(MODEL_FOREROOM_OBJECT, 2896, 0, -7157, 0, 0, 0, (5 << 16), bhvForeroomObject),
		OBJECT(MODEL_GLOBAL_GATE, -4714, 0, -8496, 0, 90, 0, 0x00000000, bhvGlobalGate),
		OBJECT(MODEL_GLOBAL_GATE, -3454, 0, -7386, 0, -180, 0, 0x00000000, bhvGlobalGate),
		OBJECT(MODEL_GLOBAL_GATE, -2579, 5185, 5703, 0, 0, 0, 0x00000000, bhvGlobalGate),
		OBJECT(MODEL_GLOBAL_GATE, -7264, 5185, 11348, 0, 90, 0, 0x00000000, bhvGlobalGate),
		OBJECT(MODEL_GLOBAL_GATE, 2106, 5185, 11348, 0, -90, 0, 0x00000000, bhvGlobalGate),
		OBJECT(MODEL_FOREROOM_LEVER, 2996, 0, -7157, 0, -90, 0, 0x00000000, bhvForeroomLever),
		OBJECT(MODEL_BOO, -2725, 0, -8496, 0, 0, 0, (0x11 << 16), bhvRoomBoo),
		OBJECT(MODEL_SHYGUY, -4183, 67, -10083, 0, -180, 0, 0x00000000, bhvSittingShyguy),
		OBJECT(MODEL_SHYGUY, -2899, 67, -9683, 0, -180, 0, 0x00000000, bhvSittingShyguy),
		OBJECT(MODEL_SHYGUY, -4357, 67, -9283, 0, -180, 0, 0x00000000, bhvSittingShyguy),
		OBJECT(MODEL_THEATER_SCREEN, -3454, 250, -11386, 0, 0, 0, 0x00000000, bhvTheaterScreen),
		OBJECT(MODEL_NONE, -4954, 300, -13146, 0, 90, 0, (0x24 << 16), bhvFlyingWarp),
		OBJECT(MODEL_NONE, -3454, 300, -10421, 0, 0, 0, (0x25 << 16), bhvFlyingWarp),
		OBJECT(MODEL_FOREROOM_WINDOW, 1997, 250, -7771, 0, 0, 0, 0x00000000, bhvForeroomWindow),
		OBJECT(MODEL_FOREROOM_WINDOW, 1021, 250, -7771, 0, -180, 0, (1 << 16), bhvForeroomWindow),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, -8254, 700, -896, 0, 90, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_NONE, -18170, 8539, -21050, 0, 0, 0, 0x00000000, bhvMazeIndicator),
		OBJECT(MODEL_NONE, -21050, 8539, -18170, 0, 0, 0, (1 << 16), bhvMazeIndicator),
		OBJECT(MODEL_NONE, -23929, 8539, -15291, 0, 0, 0, (2 << 16), bhvMazeIndicator),
		OBJECT(MODEL_NONE, -23929, 8539, -9532, 0, 0, 0, (3 << 16), bhvMazeIndicator),
		OBJECT(MODEL_NONE, -7819, 0, -7246, 0, 0, 0, 0x00000000, bhvPlatHallManage),
		OBJECT(MODEL_PLAT_HALL_WALL, -18582, -2200, -17301, 0, 0, 0, 0x00000000, bhvPlatHallWall),
		OBJECT(MODEL_CUSHION_FRIEND, -7819, 0, -7246, 0, 0, 0, (3 << 16), bhvCushionShell),
		OBJECT(MODEL_STAR_PIECE, -19368, -2150, -6700, 0, 0, 0, (0x12 << 24), bhvStarPiece),
		OBJECT(MODEL_STATIC_TRI, -11851, -200, -8239, 0, 0, 0, 0x00000000, bhvStaticTri),
		OBJECT(MODEL_STATIC_TRI, -11851, -200, -9583, 0, -180, 0, 0x00000000, bhvStaticTri),
		OBJECT(MODEL_STATIC_TRI, -11851, -200, -10927, 0, 0, 0, 0x00000000, bhvStaticTri),
		OBJECT(MODEL_STATIC_TRI, -10643, -200, -7214, 0, 90, 0, 0x00000000, bhvStaticTri),
		OBJECT(MODEL_STATIC_TRI, -18582, -2200, -14006, 0, -180, 0, 0x00000000, bhvStaticTri),
		OBJECT(MODEL_STATIC_TRI, -18382, -2200, -12108, 0, -180, 0, 0x00000000, bhvStaticTri),
		OBJECT(MODEL_STATIC_TRI, -20098, -2200, -3867, 0, -90, 0, 0x00000000, bhvStaticTri),
		OBJECT(MODEL_STATIC_WALL, -9019, -200, -16906, 0, 0, 0, (38 << 16), bhvStaticWall),
		OBJECT(MODEL_STATIC_WALL, -22340, -2700, -7503, 0, -180, 0, (20 << 16), bhvStaticWall),
		OBJECT(MODEL_STATIC_WALL, -22340, -2700, -5198, 0, -180, 0, (27 << 16), bhvStaticWall),
		OBJECT(MODEL_VASE_THROW, -12297, 89, -9286, 0, 0, 0, 0x00000000, bhvVaseThrow),
		OBJECT(MODEL_VASE_THROW, -11230, 89, -10355, 0, 0, 0, 0x00000000, bhvVaseThrow),
		OBJECT(MODEL_VASE_THROW, -12161, 89, -11366, 0, 0, 0, 0x00000000, bhvVaseThrow),
		OBJECT(MODEL_VASE_THROW, -19319, -1911, -13466, 0, 0, 0, 0x00000000, bhvVaseThrow),
		OBJECT(MODEL_VASE_THROW, -18356, -1911, -12689, 0, 0, 0, 0x00000000, bhvVaseThrow),
		OBJECT(MODEL_VASE_THROW, -19015, -1911, -11557, 0, 0, 0, 0x00000000, bhvVaseThrow),
		OBJECT(MODEL_VASE_THROW, -20513, -1911, -9936, 0, 0, 0, 0x00000000, bhvVaseThrow),
		OBJECT(MODEL_VASE_THROW, -19134, -1911, -3518, 0, 0, 0, 0x00000000, bhvVaseThrow),
		OBJECT(MODEL_BULLY, -5455, 800, 106, 0, 0, 0, 0x00000000, bhvSmallBully),
		OBJECT(MODEL_BULLY, -7222, 712, 1278, 0, 0, 0, 0x00000000, bhvSmallBully),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, -2579, 2185, 3063, 0, 0, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_BULLY_GATE, -6379, 804, -4806, 0, 0, 0, 0x00000000, bhvBullyGate),
		OBJECT(MODEL_NONE, -1809, 671, 1892, 0, 0, 0, 0x00000000, bhvRedSparkles),
		OBJECT(MODEL_NONE, -3648, 671, 493, 0, 0, 0, 0x00000000, bhvRedSparkles),
		OBJECT(MODEL_NONE, -2598, 671, -537, 0, 0, 0, 0x00000000, bhvRedSparkles),
		OBJECT(MODEL_NONE, -1412, 671, -1127, 0, 0, 0, 0x00000000, bhvRedSparkles),
		OBJECT(MODEL_NONE, -2888, 671, -3139, 0, 0, 0, (5 << 24) | (1 << 16), bhvRedSparkles),
		OBJECT(MODEL_SAUNA_ROCK, -3926, 500, -1004, 0, 0, 0, (1 << 16), bhvSaunaRockRise),
		OBJECT(MODEL_SAUNA_ROCK, -1919, 500, -2937, 0, -29, 0, 0x00000000, bhvSaunaRockRise),
		OBJECT(MODEL_SAUNA_ROCK, -2639, 500, -1904, 0, 83, 0, 0x00000000, bhvSaunaRockRise),
		OBJECT(MODEL_SAUNA_ROCK, -3162, 500, 1671, 0, 24, 0, (3 << 16), bhvSaunaRockRise),
		OBJECT(MODEL_SAUNA_ROCK, -1435, 500, 157, 0, 118, 0, 0x00000000, bhvSaunaRockRise),
		OBJECT(MODEL_SAUNA_GRATE, -5925, 400, 1607, 0, -90, 0, 0x00000000, bhvSaunaGrate),
		OBJECT(MODEL_SAUNA_GRATE, -5455, 400, 106, 0, -90, 0, 0x00000000, bhvSaunaGrate),
		OBJECT(MODEL_SAUNA_GRATE, -5352, 400, -2482, 0, -90, 0, (1 << 16), bhvSaunaGrate),
		OBJECT(MODEL_SAUNA_GRATE, -5725, 400, -3898, 0, -90, 0, 0x00000000, bhvSaunaGrate),
		OBJECT(MODEL_TOKEN, -6379, 824, -5056, 0, 0, 0, (1 << 16) | (0x25 << 8), bhvToken),
		OBJECT(MODEL_TOKEN, -7082, 2126, -3044, 0, 0, 0, (2 << 16) | (0x26 << 8), bhvToken),
		OBJECT(MODEL_ATTIC_BULLY, -2579, 5912, 10888, 0, -180, 0, 0x00000000, bhvAtticBully),
		OBJECT(MODEL_ATTIC_GRATE, -579, 5185, 12888, 0, -90, 0, 0x00000000, bhvAtticGrate),
		OBJECT(MODEL_ATTIC_ROCK, -3579, 5121, 9888, 0, -90, 0, 0x00000000, bhvAtticRock),
		OBJECT(MODEL_ATTIC_ROCK, -3579, 5121, 11888, 0, -90, 0, 0x00000000, bhvAtticRock),
		OBJECT(MODEL_ATTIC_ROCK, -1579, 5121, 9888, 0, -90, 0, 0x00000000, bhvAtticRock),
		OBJECT(MODEL_ATTIC_SPIRE, -1579, 4185, 9888, 0, -90, 0, (0 << 16), bhvAtticSpire),
		OBJECT(MODEL_ATTIC_SPIRE, -4193, 4185, 12896, 0, -90, 0, (3 << 16), bhvAtticSpire),
		OBJECT(MODEL_ATTIC_SPIRE, -1116, 4185, 12472, 0, -90, 0, (2 << 16), bhvAtticSpire),
		OBJECT(MODEL_ATTIC_SPIRE, -4362, 4185, 9281, 0, -90, 0, (1 << 16), bhvAtticSpire),
		OBJECT(MODEL_BREAKABLE_BOX, -2581, 5185, 13738, 0, 0, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, -3381, 4985, 13538, 0, 0, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, -4181, 4785, 13538, 0, 0, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, -4781, 4485, 13438, 0, 0, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, -4781, 4285, 12638, 0, 0, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, -4781, 4185, 11838, 0, 0, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, -4630, 4185, 11049, 0, -21, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, -3846, 4185, 10212, 0, -66, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, -2548, 4185, 10153, 0, -103, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, -1398, 4185, 10615, 0, -148, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, -1802, 4185, 11706, 0, -112, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, -1774, 4354, 26378, 0, -90, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_GARAGE_WALL, -1838, 4354, 26380, 0, 0, 0, 0x00000000, bhvGhostBarrier),
		OBJECT(MODEL_NONE, -4597, 5185, 7063, 0, 0, 0, (7 << 16), bhvInvisRedCoin),
		OBJECT(MODEL_JOURNAL_BOOK, -3556, 5185, 16409, 0, 0, 0, (DIALOG_048 << 16), bhvJournalBook),
		OBJECT(MODEL_PROSPECTOR_LOCK, 2096, 5185, 11348, 0, -90, 0, (4 << 16), bhvProspectorLock),
		OBJECT(MODEL_PURPLE_SWITCH, -2579, 5185, 14688, 0, 0, 0, (17 << 24), bhvFloorSwitchHiddenObjects),
		OBJECT(MODEL_RED_COIN, -1802, 4385, 11706, 0, -180, 0, (6 << 16), bhvRedCoin),
		OBJECT(MODEL_ATTIC_GRATE, -1579, 5185, 8888, 0, -90, 0, 0x00000000, bhvAtticGrate),
		OBJECT(MODEL_ATTIC_GRATE, -579, 5185, 8888, 0, -90, 0, 0x00000000, bhvAtticGrate),
		OBJECT(MODEL_ATTIC_GRATE, -2579, 5185, 8888, 0, -90, 0, 0x00000000, bhvAtticGrate),
		OBJECT(MODEL_ATTIC_GRATE, -3579, 5185, 8888, 0, -90, 0, 0x00000000, bhvAtticGrate),
		OBJECT(MODEL_ATTIC_GRATE, -4579, 5185, 8888, 0, -90, 0, 0x00000000, bhvAtticGrate),
		OBJECT(MODEL_ATTIC_GRATE, -4579, 5185, 9888, 0, -90, 0, 0x00000000, bhvAtticGrate),
		OBJECT(MODEL_ATTIC_GRATE, -2579, 5185, 9888, 0, -90, 0, 0x00000000, bhvAtticGrate),
		OBJECT(MODEL_ATTIC_GRATE, -579, 5185, 9888, 0, -90, 0, 0x00000000, bhvAtticGrate),
		OBJECT(MODEL_ATTIC_GRATE, -4579, 5185, 10888, 0, -90, 0, 0x00000000, bhvAtticGrate),
		OBJECT(MODEL_ATTIC_GRATE, -3579, 5185, 10888, 0, -90, 0, 0x00000000, bhvAtticGrate),
		OBJECT(MODEL_ATTIC_GRATE, -2579, 5185, 10888, 0, -90, 0, (1 << 16), bhvAtticGrate),
		OBJECT(MODEL_ATTIC_GRATE, -1579, 5185, 10888, 0, -90, 0, 0x00000000, bhvAtticGrate),
		OBJECT(MODEL_ATTIC_GRATE, -579, 5185, 10888, 0, -90, 0, 0x00000000, bhvAtticGrate),
		OBJECT(MODEL_ATTIC_GRATE, -4579, 5185, 11888, 0, -90, 0, 0x00000000, bhvAtticGrate),
		OBJECT(MODEL_ATTIC_GRATE, -2579, 5185, 11888, 0, -90, 0, 0x00000000, bhvAtticGrate),
		OBJECT(MODEL_ATTIC_ROCK, -1579, 5121, 11888, 0, -90, 0, (1 << 16), bhvAtticRock),
		OBJECT(MODEL_ATTIC_GRATE, -579, 5185, 11888, 0, -90, 0, 0x00000000, bhvAtticGrate),
		OBJECT(MODEL_ATTIC_GRATE, -4579, 5185, 12888, 0, -90, 0, 0x00000000, bhvAtticGrate),
		OBJECT(MODEL_ATTIC_GRATE, -3579, 5185, 12888, 0, -90, 0, 0x00000000, bhvAtticGrate),
		OBJECT(MODEL_ATTIC_GRATE, -2579, 5185, 12888, 0, -90, 0, 0x00000000, bhvAtticGrate),
		OBJECT(MODEL_ATTIC_GRATE, -1579, 5185, 12888, 0, -90, 0, 0x00000000, bhvAtticGrate),
		OBJECT(MODEL_PROSPECTOR_T, 2917, 5185, 11348, 0, -90, 0, 0x00000000, bhvProspectorT),
		TERRAIN(hmc_area_1_collision),
		ROOMS(hmc_area_1_collision_rooms),
		MACRO_OBJECTS(hmc_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_FLOOR_3),
		TERRAIN_TYPE(TERRAIN_STONE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(2, hmc_area_2),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x1A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_HMC, 0x02, 0x1A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x6A, LEVEL_HMC, 0x01, 0x0E, WARP_NO_CHECKPOINT),
		WARP_NODE(0x21, LEVEL_HMC, 0x02, 0x20, WARP_NO_CHECKPOINT),
		WARP_NODE(0x20, LEVEL_HMC, 0x02, 0x21, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, 0, -311, 24402, 0, -180, 0, (0x1A << 16), bhvAirborneDeathWarp),
		OBJECT(MODEL_NONE, 0, -311, 24402, 0, -180, 0, (0xA << 16), bhvFlyingWarp),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, -413, -674, 27484, 0, -180, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_TIGHT_ROPE, 0, -524, 23478, 0, 0, 0, 0x00000000, bhvTightRope),
		OBJECT(MODEL_TIGHT_ROPE, 13, -319, 19268, 0, 0, 0, (100 << 16), bhvTightRope),
		OBJECT(MODEL_TIGHT_ROPE, -157, -362, 22188, 0, 0, 0, (20 << 16), bhvTightRope),
		OBJECT(MODEL_TREE_LIMB, 1216, -577, 15539, 0, 90, 0, 0x00000000, bhvTreeLimb),
		OBJECT(MODEL_TREE_LIMB, -784, -577, 11339, 0, -90, 0, 0x00000000, bhvTreeLimb),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, -159, -24, -16670, 0, -180, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_GOLDEN_CRATE, -449, -224, 8369, 0, 0, 0, (5 << 8), bhvGoldenCrate),
		OBJECT(MODEL_BLUE_OWL, -629, 515, 2359, 0, 26, 0, 0x00000000, bhvBlueOwl),
		OBJECT(MODEL_BLUE_OWL, 1359, 515, 5049, 0, -43, 0, 0x00000000, bhvBlueOwl),
		OBJECT(MODEL_BLUE_OWL, 1077, 515, 1825, 0, -43, 0, 0x00000000, bhvBlueOwl),
		OBJECT(MODEL_BLUE_OWL, 1987, 515, -13209, 0, -43, 0, 0x00000000, bhvBlueOwl),
		OBJECT(MODEL_BLUE_OWL, -1030, 515, -13959, 0, 51, 0, 0x00000000, bhvBlueOwl),
		OBJECT(MODEL_TIGHT_ROPE, 487, -74, 3144, 0, 0, 0, (100 << 16), bhvTightRope),
		OBJECT(MODEL_TIGHT_ROPE, 221, -24, -9524, 0, 0, 0, 0x00000000, bhvTightRope),
		OBJECT(MODEL_TIGHT_ROPE, 285, -224, 6106, 0, 0, 0, (40 << 16), bhvTightRope),
		OBJECT(MODEL_TIGHT_ROPE, -45, -24, -10993, 0, 15, 0, 0x00000000, bhvTightRope),
		OBJECT(MODEL_TIGHT_ROPE, -460, -24, -12634, 0, -30, 0, 0x00000000, bhvTightRope),
		OBJECT(MODEL_TIGHT_ROPE, 482, -24, -14041, 0, 15, 0, 0x00000000, bhvTightRope),
		OBJECT(MODEL_TIGHT_ROPE, -159, -24, -15620, 0, 0, 0, 0x00000000, bhvTightRope),
		OBJECT(MODEL_TIGHT_ROPE, 285, -224, 554, 0, 0, 0, (40 << 16), bhvTightRope),
		OBJECT(MODEL_TREE_LIMB, -784, -392, -2563, 0, -90, 0, 0x00000000, bhvTreeLimb),
		OBJECT(MODEL_TREE_LIMB, 1227, -392, -6913, 0, 90, 0, 0x00000000, bhvTreeLimb),
		OBJECT(MODEL_TELEPORTER, -384, -24, -16370, 0, 90, 0, (0x20 << 16) | (3 << 8), bhvFadingWarp),
		OBJECT(MODEL_NONE, 0, -324, 24366, 0, 0, 0, 0x00210000, bhvFadingWarp),
		OBJECT(MODEL_GLOBAL_GATE, -159, -24, -16710, 0, -180, 0, 0x00000000, bhvGlobalGate),
		OBJECT(MODEL_GOOMBA, -22, -24, -22148, 0, 90, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_GOOMBA, 771, -24, -22238, 0, 90, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_GOOMBA, 402, -24, -21698, 0, 90, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_BOO, -837, 317, -21362, 0, 0, 0, (0x10 << 16), bhvRoomBoo),
		OBJECT(MODEL_TREEHOUSE_SPIKE, -4884, 933, -18474, 0, 90, 0, (1 << 24), bhvSpike),
		OBJECT(MODEL_TREEHOUSE_SPIKE, 2291, 2127, -18474, 0, -180, 0, (2 << 24), bhvSpike),
		OBJECT(MODEL_TREEHOUSE_SPIKE, -2524, 933, -21832, 0, -180, 0, (1 << 16), bhvSpike),
		OBJECT(MODEL_STAR_PIECE, -5839, 771, -19754, 0, 0, 0, (0x11 << 24), bhvStarPiece),
		OBJECT(MODEL_NONE, 194, 2835, -19851, 0, -90, 0, (1 << 16), bhvSwoopSpawner),
		OBJECT(MODEL_NONE, 168, 2835, -19396, 0, -90, 0, (1 << 16), bhvSwoopSpawner),
		OBJECT(MODEL_NONE, -2716, 2142, -21657, 0, -90, 0, 0x00000000, bhvSwoopSpawner),
		OBJECT(MODEL_NONE, 283, 2835, -20653, 0, -90, 0, (1 << 16), bhvSwoopSpawner),
		OBJECT(MODEL_TOKEN, -815, 1986, -17599, 0, 97, 0, (0x27 << 8), bhvToken),
		OBJECT(MODEL_BLUE_OWL, -1998, 3144, -17464, 0, 90, 0, 0x00000000, bhvTreehouseOwl),
		OBJECT(MODEL_BLUE_OWL, -2363, 3144, -18096, 0, 90, 0, 0x00000000, bhvTreehouseOwl),
		OBJECT(MODEL_BLUE_OWL, -2755, 3144, -17493, 0, 90, 0, 0x00000000, bhvTreehouseOwl),
		OBJECT(MODEL_BLUE_OWL, 1239, 3144, -17816, 0, 115, 0, (1 << 16), bhvTreehouseOwl),
		OBJECT(MODEL_BLUE_OWL, 554, 3144, -18330, 0, 115, 0, (1 << 16), bhvTreehouseOwl),
		OBJECT(MODEL_BLUE_OWL, 127, 3144, -17382, 0, 115, 0, (1 << 16), bhvTreehouseOwl),
		OBJECT(MODEL_TREE_LIMB, -19, 868, -23142, 0, -180, 0, (1 << 16), bhvTreeLimb),
		TERRAIN(hmc_area_2_collision),
		ROOMS(hmc_area_2_collision_rooms),
		MACRO_OBJECTS(hmc_area_2_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_OUTSIDE),
		TERRAIN_TYPE(TERRAIN_STONE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, -10081, 145, 2264),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
