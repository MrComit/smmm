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
#include "levels/jrb/header.h"

const LevelScript level_jrb_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _jrb_segment_7SegmentRomStart, _jrb_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x0B, _effect_yay0SegmentRomStart, _effect_yay0SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _water_yay0SegmentRomStart, _water_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0A, _bbh_skybox_yay0SegmentRomStart, _bbh_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group4_yay0SegmentRomStart, _group4_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group4_geoSegmentRomStart, _group4_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group14_yay0SegmentRomStart, _group14_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group14_geoSegmentRomStart, _group14_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_5), 
	JUMP_LINK(script_func_global_15), 
	LOAD_MODEL_FROM_GEO(MODEL_SUNFLOWER, sunflower_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_DIRT_MOUND, dirt_mound_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BOUNCE_BOX, bounce_box_geo), 

	AREA(1, jrb_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		INSTANT_WARP(0, 0x01, 0, 40, -8000),
		OBJECT(MODEL_DIRT_MOUND, 776, -488, -1265, 0, 0, 0, 0x00000000, bhvDirtMound),
		OBJECT(MODEL_DIRT_MOUND, 3208, -488, 3931, 0, 0, 0, 0x00000000, bhvDirtMound),
		OBJECT(MODEL_DIRT_MOUND, -1528, -488, 3343, 0, 0, 0, 0x00000000, bhvDirtMound),
		OBJECT(MODEL_DIRT_MOUND, -4637, -488, 2082, 0, 0, 0, 0x00000000, bhvDirtMound),
		OBJECT(MODEL_DIRT_MOUND, -3964, -488, 1100, 0, 0, 0, 0x00000000, bhvDirtMound),
		OBJECT(MODEL_DIRT_MOUND, 3719, -488, 1605, 0, 0, 0, 0x00000000, bhvDirtMound),
		OBJECT(MODEL_NONE, 0, -230, 0, 0, -180, 0, 0x000A0000, bhvFlyingWarp),
		MARIO_POS(0x01, -180, 0, -230, 0),
		OBJECT(MODEL_SUNFLOWER, -6480, -488, 2215, 0, 0, 0, 0x00000000, bhvSunflower),
		OBJECT(MODEL_SUNFLOWER, -1503, -488, -1749, 0, -60, 0, 0x00000000, bhvSunflower),
		OBJECT(MODEL_SUNFLOWER, 3043, -539, 23, 0, 145, 0, 0x00000000, bhvSunflower),
		OBJECT(MODEL_BLUE_COIN, -2004, -3776, -2372, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, -1167, -3776, -2955, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, -2696, -3872, -4061, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, -1566, -3840, -4841, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, -1979, -3872, -3784, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, -897, -3797, -5413, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN_SWITCH, -1681, -3726, -1157, 0, 0, 0, 0x0A021000, bhvBlueCoinSwitch),
		OBJECT(MODEL_BOUNCE_BOX, 4137, -2196, -1727, 0, -129, 0, 0x00000000, bhvBounceBoxes),
		OBJECT(MODEL_BOUNCE_BOX, 568, -2196, 3085, 0, -24, 0, 0x00000000, bhvBounceBoxes),
		OBJECT(MODEL_BOUNCE_BOX, -5380, -3726, 2074, 0, -24, 0, 0x00000000, bhvBounceBoxes),
		OBJECT(MODEL_BOUNCE_BOX, -5540, -2196, -1107, 0, -46, 0, 0x00000000, bhvBounceBoxes),
		TERRAIN(jrb_area_1_collision),
		ROOMS(jrb_area_1_collision_rooms),
		MACRO_OBJECTS(jrb_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_SPOOKY),
		TERRAIN_TYPE(TERRAIN_STONE),
	END_AREA(),

	AREA(2, jrb_area_2),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xAB, LEVEL_JRB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, 0, 15000, 0, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		MARIO_POS(0x01, 0, 0, 15000, 0),
		OBJECT(MODEL_BLUE_COIN, 0, 14176, 0, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, -364, 7822, 420, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, -64, 12820, 473, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, -438, 12073, 322, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, -364, 7672, 420, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, -530, 11036, -209, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, 550, 9984, 304, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, 43, 9280, -508, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, -364, 7972, 420, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, -259, 12463, 436, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_NONE, 4893, 16171, -4411, 0, 0, 0, 0x0C020F00, bhvBlueCoinSwitchAuto),
		TERRAIN(jrb_area_2_collision),
		ROOMS(jrb_area_2_collision_rooms),
		MACRO_OBJECTS(jrb_area_2_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_SPOOKY),
		TERRAIN_TYPE(TERRAIN_STONE),
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, 0, 15000, 0),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
