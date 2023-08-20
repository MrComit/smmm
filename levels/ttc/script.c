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
#include "levels/ttc/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_ttc_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _ttc_segment_7SegmentRomStart, _ttc_segment_7SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _machine_yay0SegmentRomStart, _machine_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group1_yay0SegmentRomStart, _group1_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group1_geoSegmentRomStart, _group1_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_YAY0(0xa, _CUSTOM_L8_skybox_yay0SegmentRomStart, _CUSTOM_L8_skybox_yay0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_2), 
	LOAD_MODEL_FROM_GEO(MODEL_C4_TROPHY_RECTANGLE, c4_trophy_rectangle_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_C4_TROPHY_OCTOGON, c4_trophy_octogon_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_C4_SWINGING_PLAT, c4_swinging_plat_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, ttc_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0B, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_TTC, 0x01, 0x0B, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, 1904, -573, 26399, 0, -180, 0, 0x000B0000, bhvAirborneDeathWarp),
		OBJECT(MODEL_NONE, 1904, -573, 26399, 0, -180, 0, 0x000A0000, bhvFlyingWarp),
		MARIO_POS(0x01, -180, 1904, -573, 26399),
		OBJECT(MODEL_C4_TROPHY_OCTOGON, 1810, -444, 24719, 0, 23, 0, (32 << 24) | (5 << 16), bhvC4TrophyPlatRise),
		OBJECT(MODEL_C4_TROPHY_RECTANGLE, 237, 1092, 19715, 0, 90, 0, (32 << 24) | (3 << 16), bhvC4TrophyRect),
		OBJECT(MODEL_C4_TROPHY_RECTANGLE, -1369, 1241, 16666, 0, -180, 0, (32 << 24) | (3 << 16), bhvC4TrophyRect),
		OBJECT(MODEL_C4_TROPHY_RECTANGLE, -1369, 1241, 17912, 0, -90, 0, (32 << 24) | (3 << 16), bhvC4TrophyRect),
		OBJECT(MODEL_C4_SWINGING_PLAT, 6279, 3997, -8627, 0, 20, 0, 0x00000000, bhvC4SwingingPlat),
		OBJECT(MODEL_C4_SWINGING_PLAT, 2871, 6020, -16722, 0, 90, 0, 0x00000000, bhvC4SwingingPlat),
		OBJECT(MODEL_C4_SWINGING_PLAT, 1371, 6220, -18222, 0, -180, 0, 0x00000000, bhvC4SwingingPlat),
		OBJECT(MODEL_C4_SWINGING_PLAT, 2871, 6420, -19722, 0, -90, 0, 0x00000000, bhvC4SwingingPlat),
		OBJECT(MODEL_C4_SWINGING_PLAT, 4371, 6620, -21222, 0, -180, 0, 0x00000000, bhvC4SwingingPlat),
		TERRAIN(ttc_area_1_collision),
		ROOMS(ttc_area_1_collision_rooms),
		MACRO_OBJECTS(ttc_area_1_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, -180, 1904, -573, 26399),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
