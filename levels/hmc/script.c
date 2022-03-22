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

/* Fast64 begin persistent block [includes] */
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
		OBJECT(MODEL_NONE, -10581, -2363, 200, 90, 0, 0, (0x1A << 16), bhvAirborneDeathWarp),
		OBJECT(MODEL_NONE, 1096, 200, -4846, 0, -180, 0, (0x1A << 16), bhvAirborneDeathWarp),
		OBJECT(MODEL_NONE, -10581, -2363, 200, 90, 0, 0, (0xA << 16), bhvFlyingWarp),
		OBJECT(MODEL_NONE, 1096, 200, -4846, 0, -180, 0, (0xA << 16), bhvFlyingWarp),
		MARIO_POS(0x01, 0, -10581, -2363, 200),
		MARIO_POS(0x01, -180, 1096, 200, -4846),
		OBJECT(MODEL_NONE, 1509, 200, -7511, 0, 0, 0, (0xE << 16), bhvFlyingWarp),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, -9031, 0, 11348, 0, 90, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, 2146, 0, 11348, 0, 90, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, 1096, 0, 3063, 0, -180, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_STAR_PIECE, -4159, -100, 10968, 0, 0, 0, (0x11 << 24), bhvStarPiece),
		OBJECT(MODEL_STAR_PIECE, -8321, -100, 12170, 0, 0, 0, (0xF << 24), bhvStarPiece),
		OBJECT(MODEL_STAR_PIECE, -4159, -100, 11225, 0, 0, 0, (0x12 << 24), bhvStarPiece),
		OBJECT(MODEL_STAR_PIECE, -4159, -100, 11500, 0, 0, 0, (0x13 << 24), bhvStarPiece),
		OBJECT(MODEL_TROPHY_OCTOGON, -2686, 400, 7189, 0, 23, 0, (32 << 24) | (5 << 16), bhvTrophyPlatRise),
		OBJECT(MODEL_TROPHY_OCTOGON, -4603, -100, 6876, 0, 0, 0, 0x00000000, bhvTrophyPlatSpin),
		OBJECT(MODEL_TROPHY_OCTOGON, -3413, -100, 5493, 0, 0, 0, 0x00000000, bhvTrophyPlatSpin),
		OBJECT(MODEL_TROPHY_RECTANGLE, -2686, -100, 11765, 0, 0, 0, (32 << 24) | (3 << 16), bhvTrophyRect),
		OBJECT(MODEL_TROPHY_RECTANGLE, -2636, -100, 12390, 0, -165, 0, (32 << 24) | (3 << 16), bhvTrophyRect),
		OBJECT(MODEL_TROPHY_RECTANGLE, 988, 0, 9330, 0, 0, 0, (32 << 24) | (3 << 16), bhvTrophyRect),
		OBJECT(MODEL_TROPHY_RECTANGLE, 1072, 0, 8515, 0, -180, 0, (32 << 24) | (3 << 16), bhvTrophyRect),
		OBJECT(MODEL_TROPHY_RECTANGLE, 1460, 0, 7591, 0, -90, 0, (32 << 24) | (3 << 16), bhvTrophyRect),
		OBJECT(MODEL_TROPHY_RECTANGLE, 1002, 0, 6612, 0, 90, 0, (32 << 24) | (3 << 16), bhvTrophyRect),
		OBJECT(MODEL_TROPHY_RECTANGLE, 1132, 0, 5436, 0, -180, 0, (32 << 24) | (3 << 16), bhvTrophyRect),
		OBJECT(MODEL_TROPHY_RECTANGLE, 1172, 0, 4967, 0, -180, 0, (32 << 24) | (3 << 16), bhvTrophyRect),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, 3746, 0, 12498, 0, 90, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, 3746, 0, 8273, 0, 90, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, 2946, 0, 6223, 0, -180, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_MUSIC_INSTS, 12796, 0, 18423, 0, -90, 0, 0x00000000, bhvMusicInsts),
		OBJECT(MODEL_MUSIC_INSTS, 6296, 0, 17423, 0, -180, 0, (1 << 16), bhvMusicInsts),
		OBJECT(MODEL_MUSIC_INSTS, 11296, 0, 12423, 0, -90, 0, (2 << 16), bhvMusicInsts),
		OBJECT(MODEL_MUSIC_INSTS, 6796, 0, 9923, 0, -45, 0, (3 << 16), bhvMusicInsts),
		OBJECT(MODEL_SHYGUY, 13167, 115, 14420, 0, -90, 0, 0x00000000, bhvMusicShyguy),
		OBJECT(MODEL_DICE_ENEMY, 8244, 0, 7430, 0, -90, 0, (0 << 16), bhvDiceEnemy),
		OBJECT(MODEL_DICE_ENEMY, 8377, 0, 6662, 0, -90, 0, (1 << 16), bhvDiceEnemy),
		OBJECT(MODEL_DICE_ENEMY, 7625, 0, 6856, 0, -90, 0, (2 << 16), bhvDiceEnemy),
		OBJECT(MODEL_DICE_ENEMY, 6974, 0, 6821, 0, -90, 0, (3 << 16), bhvDiceEnemy),
		OBJECT(MODEL_DICE_ENEMY, 7645, 0, 7522, 0, -90, 0, (4 << 16), bhvDiceEnemy),
		OBJECT(MODEL_DICE_ENEMY, 7180, 0, 7836, 0, -90, 0, (5 << 16), bhvDiceEnemy),
		OBJECT(MODEL_POOL_FLOOR, 4842, 0, 8273, 0, 0, 0, 0x00000000, bhvPoolFloor),
		OBJECT(MODEL_KOOPA, 7036, 1875, 4042, 0, -90, 0, (0 << 16), bhvKoopa),
		OBJECT(MODEL_KOOPA, 7339, 1875, 4786, 0, -90, 0, (1 << 16), bhvKoopa),
		OBJECT(MODEL_KOOPA, 7062, 2250, 6056, 0, -90, 0, (2 << 16), bhvKoopa),
		OBJECT(MODEL_MOLE_CAGE, 9171, 255, 8073, 0, 0, 0, (8 << 16), bhvMoleCage),
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
		OBJECT(MODEL_BOO, 7675, 161, 8494, 0, -180, 0, (0x1 << 24) | (0xF << 16) | (0x9 << 8), bhvRoomBoo),
		OBJECT(MODEL_SHYGUY, 4302, 160, 4395, 0, 90, 0, (0 << 16), bhvShyguyPingpong),
		OBJECT(MODEL_SHYGUY, 5288, 160, 4395, 0, -90, 0, (1 << 16), bhvShyguyPingpong),
		OBJECT(MODEL_SMALL_KEY, 9608, 1875, 5761, 0, 0, 0, (1 << 24) | (8 << 16), bhvSmallKey),
		OBJECT(MODEL_TOY_MOLE, 9171, 100, 8698, 0, -14, 0, 0x06000000, bhvToyMole),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, 1096, 0, -5196, 0, -180, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, -2154, 0, -6496, 0, -90, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, -4754, 250, -9146, 0, -90, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_FOREROOM_OBJECT, -2024, 0, -5920, 0, 0, 0, (1 << 16), bhvForeroomObject),
		OBJECT(MODEL_FOREROOM_OBJECT, -176, 0, -6101, 0, 0, 0, 0x00000000, bhvForeroomObject),
		OBJECT(MODEL_FOREROOM_OBJECT, -544, 0, -7488, 0, 0, 0, (2 << 16), bhvForeroomObject),
		OBJECT(MODEL_FOREROOM_OBJECT, -1243, 0, -7035, 0, 0, 0, (3 << 16), bhvForeroomObject),
		OBJECT(MODEL_FOREROOM_OBJECT, 2296, 0, -6046, 0, 0, 0, (4 << 16), bhvForeroomObject),
		OBJECT(MODEL_FOREROOM_OBJECT, 2896, 0, -7157, 0, 0, 0, (5 << 16), bhvForeroomObject),
		OBJECT(MODEL_FOREROOM_LEVER, 2996, 0, -7157, 0, -90, 0, 0x00000000, bhvForeroomLever),
		OBJECT(MODEL_BOO, -3454, 0, -5696, 0, 0, 0, (0x11 << 16), bhvRoomBoo),
		OBJECT(MODEL_THEATER_SCREEN, -3454, 250, -9386, 0, 0, 0, 0x00000000, bhvTheaterScreen),
		OBJECT(MODEL_NONE, -4954, 300, -11146, 0, 90, 0, (0x24 << 16), bhvFlyingWarp),
		OBJECT(MODEL_NONE, -3454, 300, -8421, 0, 0, 0, (0x25 << 16), bhvFlyingWarp),
		OBJECT(MODEL_FOREROOM_WINDOW, 1997, 250, -7771, 0, 0, 0, 0x00000000, bhvForeroomWindow),
		OBJECT(MODEL_FOREROOM_WINDOW, 1021, 250, -7771, 0, -180, 0, (1 << 16), bhvForeroomWindow),
		TERRAIN(hmc_area_1_collision),
		ROOMS(hmc_area_1_collision_rooms),
		MACRO_OBJECTS(hmc_area_1_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_STONE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(2, hmc_area_2),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x1A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_HMC, 0x02, 0x1A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x6A, LEVEL_HMC, 0x01, 0x0E, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, 0, -524, 24259, 0, -180, 0, (0x1A << 16), bhvAirborneDeathWarp),
		OBJECT(MODEL_NONE, 0, -524, 24259, 0, -180, 0, (0xA << 16), bhvFlyingWarp),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, -413, -674, 27484, 0, -180, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_TIGHT_ROPE, 0, -524, 23478, 0, 0, 0, 0x00000000, bhvTightRope),
		OBJECT(MODEL_TIGHT_ROPE, 13, -319, 19268, 0, 0, 0, (100 << 16), bhvTightRope),
		OBJECT(MODEL_TIGHT_ROPE, -157, -362, 22188, 0, 0, 0, (20 << 16), bhvTightRope),
		OBJECT(MODEL_TREE_LIMB, 1216, -577, 15539, 0, 90, 0, 0x00000000, bhvTreeLimb),
		OBJECT(MODEL_TREE_LIMB, -784, -577, 11339, 0, -90, 0, 0x00000000, bhvTreeLimb),
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
		OBJECT(MODEL_TREE_LIMB, 1216, -242, -6763, 0, 90, 0, 0x00000000, bhvTreeLimb),
		OBJECT(MODEL_TREE_LIMB, -784, -392, -2563, 0, -90, 0, 0x00000000, bhvTreeLimb),
		TERRAIN(hmc_area_2_collision),
		ROOMS(hmc_area_2_collision_rooms),
		MACRO_OBJECTS(hmc_area_2_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_STONE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, -180, 1096, 200, -4846),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
