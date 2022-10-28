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
#include "levels/lll/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_lll_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _lll_segment_7SegmentRomStart, _lll_segment_7SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _fire_yay0SegmentRomStart, _fire_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0A, _bitfs_skybox_yay0SegmentRomStart, _bitfs_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0B, _effect_yay0SegmentRomStart, _effect_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group2_yay0SegmentRomStart, _group2_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group2_geoSegmentRomStart, _group2_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group17_yay0SegmentRomStart, _group17_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group17_geoSegmentRomStart, _group17_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_3), 
	JUMP_LINK(script_func_global_18), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_WARP_PIPE, warp_pipe_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_CASTLE_DOOR, castle_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CELLAR_BLOCKADE, cellar_blockade_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CHAMPAGNE, champagne_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_SECURITY_CAM, security_cam_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BASEMENT_SWITCH, basement_switch_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BASEMENT_WASHER, basement_washer_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BASEMENT_DRYER, basement_dryer_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CLOTHES_BALL, clothes_ball_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, lll_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x74, LEVEL_BOB, 0x01, 0x75, WARP_NO_CHECKPOINT),
		WARP_NODE(0x1A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_LLL, 0x01, 0x1A, WARP_NO_CHECKPOINT),
		INSTANT_WARP(0, 0x01, -187, 296, 3923),
		INSTANT_WARP(1, 0x01, 792, 296, 11119),
		OBJECT(MODEL_NONE, 751, 0, 8764, 0, -180, 0, (0x1A << 16), bhvAirborneDeathWarp),
		OBJECT(MODEL_NONE, 751, 0, 8764, 0, -180, 0, (0xA << 16), bhvFlyingWarp),
		MARIO_POS(0x01, -180, 751, 0, 8764),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, -429, 0, 8932, 0, 90, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, 3229, 0, 5963, 0, -90, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, -429, 0, 1813, 0, 90, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, 1429, 0, -1187, 0, -90, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, 1429, 0, -5187, 0, -90, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_BASEMENT_DRYER, 7949, 0, 13525, 0, -180, 0, 0x00000000, bhvBasementDryer),
		OBJECT(MODEL_BASEMENT_DRYER, 13073, 0, 11410, 0, -180, 0, 0x00000000, bhvBasementDryer),
		OBJECT(MODEL_BASEMENT_DRYER, 9751, 550, 4244, 0, 90, 0, 0x00000000, bhvBasementDryer),
		OBJECT(MODEL_BASEMENT_SWITCH, 651, 0, 5875, 0, 0, 0, (1 << 16), bhvBasementSwitch),
		OBJECT(MODEL_BASEMENT_SWITCH, 1055, 0, 5875, 0, 0, 0, (2 << 16), bhvBasementSwitch),
		OBJECT(MODEL_BASEMENT_SWITCH, 1532, 0, 5875, 0, 0, 0, (3 << 16), bhvBasementSwitch),
		OBJECT(MODEL_BASEMENT_SWITCH, 2051, 0, 5875, 0, 0, 0, (4 << 16), bhvBasementSwitch),
		OBJECT(MODEL_BASEMENT_WASHER, 4213, 0, 5460, 0, 0, 0, 0x00000000, bhvBasementWasher),
		OBJECT(MODEL_BASEMENT_DRYER, 3814, 0, 7909, 0, 171, 0, 0x00000000, bhvBasementDryer),
		OBJECT(MODEL_BASEMENT_WASHER, 5365, 0, 13469, 0, 90, 0, 0x00000000, bhvBasementWasher),
		OBJECT(MODEL_BASEMENT_WASHER, 13073, 0, 12059, 0, 0, 0, 0x00000000, bhvBasementWasher),
		OBJECT(MODEL_BASEMENT_WASHER, 11128, 550, 6466, 0, -90, 0, 0x00000000, bhvBasementWasher),
		OBJECT(MODEL_CELLAR_BLOCKADE, -2223, 140, 6944, 0, 0, 0, 0x00000000, bhvCellarBlockade),
		OBJECT(MODEL_CHAMPAGNE, -2084, 1536, 7203, 0, -180, 0, 0x00000000, bhvChampagne),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, -2229, 0, 6882, 0, 0, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_ENV_FLAME, -2500, 276, 7071, 0, 90, 0, (42 << 16), bhvFlame),
		OBJECT(MODEL_SECURITY_CAM, -1856, 2466, 6932, 0, 0, 0, 0x00000000, bhvSecurityCam),
		OBJECT(MODEL_SECURITY_CAM, -4729, 866, 11182, 0, -180, 0, (1 << 16), bhvSecurityCam),
		OBJECT(MODEL_SECURITY_CAM, -679, 2266, 3482, 0, 0, 0, (2 << 16), bhvSecurityCam),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, -4279, 0, 4832, 0, 90, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_BASEMENT_SWITCH, -3929, 1729, 6532, 0, 90, 0, 0x00000000, bhvBasementSwitch),
		OBJECT(MODEL_BOO_COIN, -5954, 877, 7957, 0, 90, 0, 0x00000000, bhvBooCoin),
		OBJECT(MODEL_BOO_COIN, -4704, 1500, 6582, 0, 90, 0, 0x00000000, bhvBooCoin),
		OBJECT(MODEL_BOO_COIN, -5880, 0, 4754, 0, 90, 0, 0x00000000, bhvBooCoin),
		OBJECT(MODEL_BOO_COIN, -8213, 0, 2928, 0, 90, 0, 0x00000000, bhvBooCoin),
		OBJECT(MODEL_BOO_COIN, -4979, 0, 6232, 0, 90, 0, 0x00000000, bhvBooCoin),
		OBJECT(MODEL_HAUNTED_CAGE, -4984, 250, 2832, 0, 90, 0, (2 << 16) | (0x13 << 8), bhvBooCoinCage),
		OBJECT(MODEL_BREAKABLE_BOX, -4979, 0, 6232, 0, 90, 0, 0x00000000, bhvBreakableBox),
		OBJECT(MODEL_BREAKABLE_BOX, -4979, 250, 6232, 0, 90, 0, 0x00000000, bhvBreakableBox),
		OBJECT(MODEL_BREAKABLE_BOX, -4979, 0, 6082, 0, 90, 0, 0x00000000, bhvBreakableBox),
		OBJECT(MODEL_BREAKABLE_BOX, -8479, 0, 6232, 0, 90, 0, 0x00000000, bhvBreakableBox),
		OBJECT(MODEL_BREAKABLE_BOX, -6229, 0, 6732, 0, 90, 0, 0x00000000, bhvBreakableBox),
		OBJECT(MODEL_BREAKABLE_BOX, -6229, 200, 6732, 0, 90, 0, 0x00000000, bhvBreakableBox),
		OBJECT(MODEL_BREAKABLE_BOX, -5179, 0, 6732, 0, 90, 0, 0x00000000, bhvBreakableBox),
		OBJECT(MODEL_NONE, -8305, 520, 5647, 0, 90, 0, (100 << 16), bhvPoleGrabbing),
		TERRAIN(lll_area_1_collision),
		ROOMS(lll_area_1_collision_rooms),
		MACRO_OBJECTS(lll_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_BASEMENT),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, -180, 751, 0, 8764),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
