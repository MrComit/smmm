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
#include "levels/bob/header.h"

const LevelScript level_bob_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _bob_segment_7SegmentRomStart, _bob_segment_7SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _generic_yay0SegmentRomStart, _generic_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0A, _water_skybox_yay0SegmentRomStart, _water_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group3_yay0SegmentRomStart, _group3_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group3_geoSegmentRomStart, _group3_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group14_yay0SegmentRomStart, _group14_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group14_geoSegmentRomStart, _group14_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_YAY0(0x7, _bob_segment_7SegmentRomStart, _bob_segment_7SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_4), 
	JUMP_LINK(script_func_global_15), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_CASTLE_DOOR, castle_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_KEY_DOOR, key_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_LAND_CHUNK, landchunk_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CHANDELIER, chandelier_geo), 

	AREA(1, bob_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, 2151, 192, 14013, 0, -180, 0, 0x000A0000, bhvFlyingWarp),
		OBJECT(MODEL_CASTLE_KEY_DOOR, -75, 0, 12706, 0, 0, 0, 0x00000100, bhvDoor),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, -75, 0, 27143, 0, 0, 0, 0x00000100, bhvDoor),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, 75, 0, 27143, 0, -180, 0, 0x00000100, bhvDoor),
		OBJECT(MODEL_CASTLE_KEY_DOOR, 75, 0, 12706, 0, -180, 0, 0x00000100, bhvDoor),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, 3350, 0, 13733, 0, -90, 0, 0x00000300, bhvDoor),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, 3350, 0, 13883, 0, 90, 0, 0x00000300, bhvDoor),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, 4630, 0, 15003, 0, 180, 0, 0x00000400, bhvDoor),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, 4480, 0, 15003, 0, 0, 0, 0x00000400, bhvDoor),
		OBJECT(MODEL_BLUE_COIN, -1572, -191, 19564, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, -1988, -177, 19963, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, -1877, -144, 20657, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, -597, -144, 21071, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, -403, -166, 21762, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN_SWITCH, -1885, -84, 19060, 0, 0, 0, 0x05020000, bhvBlueCoinSwitch),
		OBJECT(MODEL_CHANDELIER, 741, 685, 17689, 0, 0, 0, 0x00000000, bhvChandelier),
		OBJECT(MODEL_LAND_CHUNK, -2431, -200, 23982, 0, 0, 0, 0x021E0000, bhvLandChunk),
		OBJECT(MODEL_LAND_CHUNK, -2101, -200, 23213, 0, 28, 0, 0x021E0000, bhvLandChunk),
		OBJECT(MODEL_LAND_CHUNK, -1210, -200, 23651, 0, 82, 0, 0x021E0000, bhvLandChunk),
		OBJECT(MODEL_LAND_CHUNK, -952, -200, 22797, 0, -135, 0, 0x021E0000, bhvLandChunk),
		TERRAIN(bob_area_1_collision),
		ROOMS(bob_area_1_collision_rooms),
		MACRO_OBJECTS(bob_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_SPOOKY),
		TERRAIN_TYPE(TERRAIN_STONE),
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(1, 0, 0, 0, 0),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
