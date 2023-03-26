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
#include "levels/ssl/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_ssl_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _ssl_segment_7SegmentRomStart, _ssl_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x0A, _CUSTOM_L8_skybox_yay0SegmentRomStart, _CUSTOM_L8_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _generic_yay0SegmentRomStart, _generic_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group9_yay0SegmentRomStart, _group9_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group9_geoSegmentRomStart, _group9_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_YAY0(0xb, _effect_yay0SegmentRomStart, _effect_yay0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_10), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, ssl_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x1A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_SSL, 0x01, 0x1A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, -21859, 385, 24269, 0, -180, 0, (0x1A << 16), bhvAirborneDeathWarp),
		OBJECT(MODEL_NONE, -21859, 385, 24269, 0, -180, 0, (0xA << 16), bhvFlyingWarp),
		MARIO_POS(0x01, -180, -21859, 385, 24269),
		OBJECT(MODEL_PEEPA, -18913, 1307, 19110, 0, -90, 0, 0x00000000, bhvFloorPeepa),
		OBJECT(MODEL_PEEPA, -18913, 1107, 19110, 0, -90, 0, (1 << 16), bhvFloorPeepa),
		OBJECT(MODEL_PEEPA, -18913, 907, 19110, 0, -90, 0, (2 << 16), bhvFloorPeepa),
		OBJECT(MODEL_PEEPA, -19590, 1752, 16965, 0, -90, 0, 0x00000000, bhvFloorPeepa),
		OBJECT(MODEL_PEEPA, -19590, 1552, 16965, 0, -90, 0, (1 << 16), bhvFloorPeepa),
		OBJECT(MODEL_PEEPA, -19590, 1352, 16965, 0, -90, 0, (2 << 16), bhvFloorPeepa),
		OBJECT(MODEL_PEEPA, -21306, 1752, 15347, 0, -90, 0, 0x00000000, bhvFloorPeepa),
		OBJECT(MODEL_PEEPA, -21306, 1552, 15347, 0, -90, 0, (1 << 16), bhvFloorPeepa),
		OBJECT(MODEL_PEEPA, -21306, 1352, 15347, 0, -90, 0, (2 << 16), bhvFloorPeepa),
		OBJECT(MODEL_PEEPA, -19659, 2268, 12723, 0, -90, 0, 0x00000000, bhvFloorPeepa),
		OBJECT(MODEL_PEEPA, -19659, 2068, 12723, 0, -90, 0, (1 << 16), bhvFloorPeepa),
		OBJECT(MODEL_PEEPA, -19659, 1868, 12723, 0, -90, 0, (2 << 16), bhvFloorPeepa),
		OBJECT(MODEL_PEEPA, -19720, 2268, 10759, 0, -90, 0, 0x00000000, bhvFloorPeepa),
		OBJECT(MODEL_PEEPA, -19720, 2068, 10759, 0, -90, 0, (1 << 16), bhvFloorPeepa),
		OBJECT(MODEL_PEEPA, -19720, 1868, 10759, 0, -90, 0, (2 << 16), bhvFloorPeepa),
		TERRAIN(ssl_area_1_collision),
		ROOMS(ssl_area_1_collision_rooms),
		MACRO_OBJECTS(ssl_area_1_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_STONE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, -180, -21859, 385, 24269),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
