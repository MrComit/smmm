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
	LOAD_MODEL_FROM_GEO(MODEL_THEATER_TOMATO, theater_tomato_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_TREEHOUSE_LOG, treehouse_log_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_TREEHOUSE_SPIKE, treehouse_spike_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CUSHION_FRIEND, cushion_friend_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_STATIC_TRI, static_tri_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_STATIC_WALL, static_wall_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_VASE_THROW, vase_throw_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_SAUNA_GRATE, sauna_grate_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BULLY_GATE, bully_gate_geo), 

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
		INSTANT_WARP(5, 0x01, 5348, -8739, -7651),
		OBJECT(MODEL_NONE, -10581, -2363, 200, 90, 0, 0, (0x1A << 16), bhvAirborneDeathWarp),
		OBJECT(MODEL_NONE, -8848, 3000, -934, 0, 90, 0, (0x1A << 16), bhvAirborneDeathWarp),
		OBJECT(MODEL_NONE, -10581, -2363, 200, 90, 0, 0, (0xA << 16), bhvFlyingWarp),
		OBJECT(MODEL_NONE, -8848, 3000, -934, 0, 90, 0, (0xA << 16), bhvFlyingWarp),
		MARIO_POS(0x01, 0, -10581, -2363, 200),
		MARIO_POS(0x01, 90, -8848, 3000, -934),
		OBJECT(MODEL_NONE, 1509, 200, -7511, 0, 0, 0, (0xE << 16), bhvFlyingWarp),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, -9031, 0, 11348, 0, 90, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, 2146, 0, 11348, 0, 90, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, 1096, 0, 3063, 0, -180, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_STAR_PIECE, -4159, -100, 10968, 0, 0, 0, (0x11 << 24), bhvStarPiece),
		OBJECT(MODEL_STAR_PIECE, -8321, -100, 12170, 0, 0, 0, (0xF << 24), bhvStarPiece),
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
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, -4754, 250, -11146, 0, -90, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, -4754, 0, -8496, 0, -90, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, -3454, 0, -7346, 0, -180, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_FOREROOM_OBJECT, -2024, 0, -5920, 0, 0, 0, (1 << 16), bhvForeroomObject),
		OBJECT(MODEL_FOREROOM_OBJECT, -176, 0, -6101, 0, 0, 0, 0x00000000, bhvForeroomObject),
		OBJECT(MODEL_FOREROOM_OBJECT, -544, 0, -7488, 0, 0, 0, (2 << 16), bhvForeroomObject),
		OBJECT(MODEL_FOREROOM_OBJECT, -1243, 0, -7035, 0, 0, 0, (3 << 16), bhvForeroomObject),
		OBJECT(MODEL_FOREROOM_OBJECT, 2296, 0, -6046, 0, 0, 0, (4 << 16), bhvForeroomObject),
		OBJECT(MODEL_FOREROOM_OBJECT, 2896, 0, -7157, 0, 0, 0, (5 << 16), bhvForeroomObject),
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
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, -8254, 2700, -896, 0, 90, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_NONE, -13791, 2654, -5362, 0, 0, 0, 0x00000000, bhvPlatHallManage),
		OBJECT(MODEL_CUSHION_FRIEND, -9005, 2700, -1332, 0, 0, 0, (3 << 16), bhvCushionShell),
		OBJECT(MODEL_STAR_PIECE, -19368, -150, -6700, 0, 0, 0, (0x12 << 24), bhvStarPiece),
		OBJECT(MODEL_STATIC_TRI, -11851, -200, -8239, 0, 0, 0, 0x00000000, bhvStaticTri),
		OBJECT(MODEL_STATIC_TRI, -11851, -200, -9583, 0, -180, 0, 0x00000000, bhvStaticTri),
		OBJECT(MODEL_STATIC_TRI, -11851, -200, -10927, 0, 0, 0, 0x00000000, bhvStaticTri),
		OBJECT(MODEL_STATIC_TRI, -10643, -200, -7214, 0, 90, 0, 0x00000000, bhvStaticTri),
		OBJECT(MODEL_STATIC_TRI, -18582, -200, -14006, 0, -180, 0, 0x00000000, bhvStaticTri),
		OBJECT(MODEL_STATIC_TRI, -18382, -200, -12108, 0, -180, 0, 0x00000000, bhvStaticTri),
		OBJECT(MODEL_STATIC_TRI, -21097, -200, -3867, 0, -90, 0, 0x00000000, bhvStaticTri),
		OBJECT(MODEL_STATIC_WALL, -9019, -200, -16906, 0, 0, 0, (38 << 16), bhvStaticWall),
		OBJECT(MODEL_STATIC_WALL, -22340, -200, -7503, 0, -180, 0, (40 << 16), bhvStaticWall),
		OBJECT(MODEL_STATIC_WALL, -22340, -200, -5198, 0, -180, 0, (27 << 16), bhvStaticWall),
		OBJECT(MODEL_VASE_THROW, -12297, 89, -9286, 0, 0, 0, 0x00000000, bhvVaseThrow),
		OBJECT(MODEL_VASE_THROW, -11230, 89, -10355, 0, 0, 0, 0x00000000, bhvVaseThrow),
		OBJECT(MODEL_VASE_THROW, -12161, 89, -11366, 0, 0, 0, 0x00000000, bhvVaseThrow),
		OBJECT(MODEL_VASE_THROW, -19319, 89, -13466, 0, 0, 0, 0x00000000, bhvVaseThrow),
		OBJECT(MODEL_VASE_THROW, -18356, 89, -12689, 0, 0, 0, 0x00000000, bhvVaseThrow),
		OBJECT(MODEL_VASE_THROW, -19015, 89, -11557, 0, 0, 0, 0x00000000, bhvVaseThrow),
		OBJECT(MODEL_VASE_THROW, -20513, 89, -9936, 0, 0, 0, 0x00000000, bhvVaseThrow),
		OBJECT(MODEL_VASE_THROW, -19134, 89, -3518, 0, 0, 0, 0x00000000, bhvVaseThrow),
		OBJECT(MODEL_BULLY, -5455, 2800, 106, 0, 0, 0, 0x00000000, bhvSmallBully),
		OBJECT(MODEL_BULLY, -7222, 2712, 1278, 0, 0, 0, 0x00000000, bhvSmallBully),
		OBJECT(MODEL_BULLY_GATE, -6379, 2804, -4806, 0, 0, 0, 0x00000000, bhvBullyGate),
		OBJECT(MODEL_SAUNA_GRATE, -5925, 2400, 1607, 0, -90, 0, 0x00000000, bhvSaunaGrate),
		OBJECT(MODEL_SAUNA_GRATE, -5455, 2400, 106, 0, -90, 0, 0x00000000, bhvSaunaGrate),
		OBJECT(MODEL_SAUNA_GRATE, -5352, 2400, -2482, 0, -90, 0, (1 << 16), bhvSaunaGrate),
		OBJECT(MODEL_SAUNA_GRATE, -5725, 2400, -3898, 0, -90, 0, 0x00000000, bhvSaunaGrate),
		OBJECT(MODEL_TOKEN, -6379, 2824, -5056, 0, 0, 0, (1 << 16) | (0x17 << 8), bhvToken),
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
		OBJECT(MODEL_NONE, -156, 226, -16340, 0, -180, 0, (0x1A << 16), bhvAirborneDeathWarp),
		OBJECT(MODEL_NONE, -156, 226, -16340, 0, -180, 0, (0xA << 16), bhvFlyingWarp),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, -413, -674, 27484, 0, -180, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_TIGHT_ROPE, 0, -524, 23478, 0, 0, 0, 0x00000000, bhvTightRope),
		OBJECT(MODEL_TIGHT_ROPE, 13, -319, 19268, 0, 0, 0, (100 << 16), bhvTightRope),
		OBJECT(MODEL_TIGHT_ROPE, -157, -362, 22188, 0, 0, 0, (20 << 16), bhvTightRope),
		OBJECT(MODEL_TREE_LIMB, 1216, -577, 15539, 0, 90, 0, 0x00000000, bhvTreeLimb),
		OBJECT(MODEL_TREE_LIMB, -784, -577, 11339, 0, -90, 0, 0x00000000, bhvTreeLimb),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, -159, -24, -16670, 0, -180, 0, 0x00000000, bhvDoor),
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
		OBJECT(MODEL_NONE, 1000, -24, -17598, 0, 90, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_BOO, -837, 317, -21362, 0, 0, 0, (0x10 << 16), bhvRoomBoo),
		OBJECT(MODEL_TREEHOUSE_SPIKE, -4884, 933, -18474, 0, 90, 0, 0x00000000, bhvSpike),
		OBJECT(MODEL_TREEHOUSE_SPIKE, 2291, 2127, -18474, 0, -180, 0, 0x00000000, bhvSpike),
		OBJECT(MODEL_TREEHOUSE_SPIKE, -2524, 933, -21832, 0, -180, 0, (1 << 16), bhvSpike),
		OBJECT(MODEL_SWOOP, -3129, 2013, -22720, 0, -90, 0, 0x00000000, bhvSwoop),
		OBJECT(MODEL_SWOOP, -2435, 2013, -21546, 0, -90, 0, 0x00000000, bhvSwoop),
		OBJECT(MODEL_SWOOP, -2785, 2013, -21215, 0, -90, 0, 0x00000000, bhvSwoop),
		OBJECT(MODEL_SWOOP, -2991, 2013, -21746, 0, -90, 0, 0x00000000, bhvSwoop),
		OBJECT(MODEL_SWOOP, 2075, 2658, -19746, 0, -90, 0, 0x00000000, bhvSwoop),
		OBJECT(MODEL_SWOOP, 1725, 2658, -19415, 0, -90, 0, 0x00000000, bhvSwoop),
		OBJECT(MODEL_SWOOP, 1519, 2658, -19947, 0, -90, 0, 0x00000000, bhvSwoop),
		OBJECT(MODEL_SWOOP, 1865, 2658, -21141, 0, -27, 0, 0x00000000, bhvSwoop),
		OBJECT(MODEL_SWOOP, 2004, 2658, -20680, 0, -27, 0, 0x00000000, bhvSwoop),
		OBJECT(MODEL_SWOOP, 1436, 2658, -20735, 0, -27, 0, 0x00000000, bhvSwoop),
		OBJECT(MODEL_TREE_LIMB, -19, 868, -23142, 0, -180, 0, (1 << 16), bhvTreeLimb),
		TERRAIN(hmc_area_2_collision),
		ROOMS(hmc_area_2_collision_rooms),
		MACRO_OBJECTS(hmc_area_2_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_STONE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 90, -8848, 3000, -934),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
