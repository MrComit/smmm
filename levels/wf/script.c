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
#include "levels/wf/header.h"

const LevelScript level_wf_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _wf_segment_7SegmentRomStart, _wf_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x0A, _bbh_skybox_yay0SegmentRomStart, _bbh_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _grass_yay0SegmentRomStart, _grass_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group1_yay0SegmentRomStart, _group1_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group1_geoSegmentRomStart, _group1_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group14_yay0SegmentRomStart, _group14_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group14_geoSegmentRomStart, _group14_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_2), 
	JUMP_LINK(script_func_global_15), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_CASTLE_DOOR, castle_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_KEY_DOOR, key_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_HEAVY_OBJECT, heavyobject_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_HEAVY_SWITCH, heavyswitch_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_L2_GATE, l2_gate_geo), 

	AREA(1, wf_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x10, LEVEL_BOB, 0x01, 0x0D, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, -4422, 0, -8015, 0, 90, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, 1031, 0, -4511, 0, 180, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_L2_GATE, 1031, 0, -4811, 0, 180, 0, 0x00020000, bhvL2Gate),
		OBJECT(MODEL_L2_GATE, -42, 0, -11219, 0, 0, 0, 0x00000000, bhvL2Gate),
		OBJECT(MODEL_BREAKABLE_BOX, -1912, 0, -6531, 0, 0, 0, 0x00000000, bhvBreakableBox),
		OBJECT(MODEL_L2_GATE, -4122, 0, -8015, 0, 90, 0, 0x00010000, bhvL2Gate),
		OBJECT(MODEL_L2_GATE, 4546, 387, -5545, 0, -90, 0, 0x00020000, bhvL2Gate),
		OBJECT(MODEL_L2_GATE, 4946, 387, -5545, 0, -90, 0, 0x00000000, bhvL2Gate),
		OBJECT(MODEL_HEAVY_OBJECT, 3310, -140, -8088, 0, 0, 0, 0x00000000, bhvHeavyObject),
		OBJECT(MODEL_HEAVY_OBJECT, -3337, 50, -5810, 0, 0, 0, 0x00000000, bhvHeavyObject),
		OBJECT(MODEL_HEAVY_SWITCH, 3310, -190, -8089, 0, 90, 0, 0x00000000, bhvHeavySwitch),
		OBJECT(MODEL_HEAVY_SWITCH, 3735, -190, -7776, 0, 90, 0, 0x00010000, bhvHeavySwitch),
		OBJECT(MODEL_HEAVY_SWITCH, 3245, -190, -7323, 0, 90, 0, 0x00020000, bhvHeavySwitch),
		OBJECT(MODEL_STAR_PIECE, 5296, 387, -5545, 0, 0, 0, 0x05000000, bhvStarPiece),
		OBJECT(MODEL_NONE, 7647, 200, -17971, 0, 0, 0, 0x000B0000, bhvAirborneDeathWarp),
		OBJECT(MODEL_NONE, 7647, 200, -17971, 0, 0, 0, 0x000A0000, bhvFlyingWarp),
		MARIO_POS(0x01, 0, 7647, 200, -17971),
		TERRAIN(wf_area_1_collision),
		ROOMS(wf_area_1_collision_rooms),
		MACRO_OBJECTS(wf_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_SPOOKY),
		TERRAIN_TYPE(TERRAIN_STONE),
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, 7647, 200, -17971),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
