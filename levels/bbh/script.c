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

#include "make_const_nonconst.h"
#include "levels/bbh/header.h"

const LevelScript level_bbh_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _bbh_segment_7SegmentRomStart, _bbh_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x0A, _cloud_floor_skybox_yay0SegmentRomStart, _cloud_floor_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _spooky_yay0SegmentRomStart, _spooky_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group9_yay0SegmentRomStart, _group9_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group9_geoSegmentRomStart, _group9_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group17_yay0SegmentRomStart, _group17_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group17_geoSegmentRomStart, _group17_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_10), 
	JUMP_LINK(script_func_global_18), 

	AREA(1, bbh_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0B, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BBH, 0x01, 0x0B, WARP_NO_CHECKPOINT),
		WARP_NODE(0x20, LEVEL_BBH, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, -5159, 200, 123, 0, 90, 0, 0x000B0000, bhvAirborneDeathWarp),
		OBJECT(MODEL_NONE, -5159, 200, 123, 0, 90, 0, 0x000A0000, bhvFlyingWarp),
		MARIO_POS(0x01, 90, -5159, 200, 123),
		OBJECT(MODEL_CHUCKYA, -1178, 535, -1752, 0, 0, 0, 0x00010000, bhvChuckyaBomb),
		OBJECT(MODEL_STAR_CURRENCY, -4768, 2539, -3297, 0, 0, 0, 0x06000000, bhvStar),
		OBJECT(MODEL_STAR_CURRENCY, -934, 4057, -7156, 0, 0, 0, 0x07000000, bhvStar),
		OBJECT(MODEL_GREEN_COIN, -1341, 0, 1194, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, -1108, 0, 1679, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, -1406, 0, 2063, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, -1701, 0, 1998, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, -1823, 0, 1868, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, -1835, 0, 1721, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, -1582, 0, 1720, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, -1725, 0, 1455, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, -2194, 0, 1600, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, -2092, 0, 2089, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, -1898, 0, 2422, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, -2126, 0, 2619, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, -2363, 0, 2308, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, -2492, 0, 1961, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_NONE, -2022, 300, 859, 0, 0, 0, 0x0A000000, bhvHiddenGreenCoinStar),
		OBJECT(MODEL_NONE, -180, 250, -1689, 0, 0, 0, 0x00100000, bhvHorizontalPole),
		OBJECT(MODEL_NONE, -4100, 2250, 2125, 0, 14, 0, 0x00100000, bhvHorizontalPole),
		OBJECT(MODEL_NONE, 1273, 1750, 4986, 0, 89, 0, 0x00100000, bhvHorizontalPole),
		OBJECT(MODEL_NONE, -1935, 2049, 4433, 0, 67, 0, 0x00100000, bhvHorizontalPole),
		OBJECT(MODEL_NONE, -311, 320, -5575, 0, 0, 0, 0x00000000, bhvWaterfallSoundLoop),
		OBJECT(MODEL_NONE, -793, 2579, -7280, 0, 0, 0, 0x00000000, bhvWaterfallSoundLoop),
		OBJECT(MODEL_GREEN_COIN, -3586, 0, -6494, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, -3164, 0, -6927, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, -2726, 0, -7372, 0, 0, 0, 0x00000000, bhvGreenCoin),
		TERRAIN(bbh_area_1_collision),
		ROOMS(bbh_area_1_collision_rooms),
		MACRO_OBJECTS(bbh_area_1_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_STONE),
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 90, -5159, 200, 123),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
