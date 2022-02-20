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

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, hmc_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x1A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_HMC, 0x01, 0x1A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x50, LEVEL_WF, 0x01, 0x0F, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, -10581, 200, 2363, 0, 0, 0, 0x001A0000, bhvAirborneDeathWarp),
		OBJECT(MODEL_NONE, 3082, 200, 8273, 0, 90, 0, 0x001A0000, bhvAirborneDeathWarp),
		OBJECT(MODEL_NONE, -10581, 200, 2363, 0, 0, 0, 0x000A0000, bhvFlyingWarp),
		OBJECT(MODEL_NONE, 3082, 200, 8273, 0, 90, 0, 0x000A0000, bhvFlyingWarp),
		MARIO_POS(0x01, 0, -10581, 200, 2363),
		MARIO_POS(0x01, 90, 3082, 200, 8273),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, -9031, 0, 11348, 0, 90, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, 2146, 0, 11348, 0, 90, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_STAR_PIECE, -4159, -100, 10712, 0, 0, 0, (0x10 << 24), bhvStarPiece),
		OBJECT(MODEL_STAR_PIECE, -4159, -100, 10968, 0, 0, 0, (0x11 << 24), bhvStarPiece),
		OBJECT(MODEL_STAR_PIECE, -4159, -100, 10396, 0, 0, 0, (0xF << 24), bhvStarPiece),
		OBJECT(MODEL_STAR_PIECE, -4159, -100, 11225, 0, 0, 0, (0x12 << 24), bhvStarPiece),
		OBJECT(MODEL_STAR_PIECE, -4159, -100, 11500, 0, 0, 0, (0x13 << 24), bhvStarPiece),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, 3746, 0, 14423, 0, 90, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, 3746, 0, 8273, 0, 90, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_POOL_BARRIER, 5608, 0, 7118, 0, 0, 0, 0x00000000, bhvPoolBarrier),
		OBJECT(MODEL_DICE_ENEMY, 7184, 0, 7169, 0, -90, 0, (0 << 16), bhvDiceEnemy),
		OBJECT(MODEL_DICE_ENEMY, 7186, 0, 7302, 0, -90, 0, (1 << 16), bhvDiceEnemy),
		OBJECT(MODEL_DICE_ENEMY, 7181, 0, 7419, 0, -90, 0, (2 << 16), bhvDiceEnemy),
		OBJECT(MODEL_DICE_ENEMY, 7173, 0, 7557, 0, -90, 0, (3 << 16), bhvDiceEnemy),
		OBJECT(MODEL_DICE_ENEMY, 7171, 0, 7700, 0, -90, 0, (4 << 16), bhvDiceEnemy),
		OBJECT(MODEL_DICE_ENEMY, 7180, 0, 7836, 0, -90, 0, (5 << 16), bhvDiceEnemy),
		OBJECT(MODEL_POOL_FLOOR, 4842, 0, 8273, 0, 0, 0, 0x00000000, bhvPoolFloor),
		OBJECT(MODEL_KOOPA, 7036, 1875, 4042, 0, -90, 0, (0 << 16), bhvKoopa),
		OBJECT(MODEL_KOOPA, 7339, 1875, 4786, 0, -90, 0, (1 << 16), bhvKoopa),
		OBJECT(MODEL_KOOPA, 7062, 2250, 6056, 0, -90, 0, (2 << 16), bhvKoopa),
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
		TERRAIN(hmc_area_1_collision),
		ROOMS(hmc_area_1_collision_rooms),
		MACRO_OBJECTS(hmc_area_1_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_STONE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 90, 3082, 200, 8273),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
