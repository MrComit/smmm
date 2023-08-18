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
#include "levels/wdw/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_wdw_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _wdw_segment_7SegmentRomStart, _wdw_segment_7SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _grass_yay0SegmentRomStart, _grass_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0A, _CUSTOM_L8_skybox_yay0SegmentRomStart, _CUSTOM_L8_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group1_yay0SegmentRomStart, _group1_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group1_geoSegmentRomStart, _group1_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group13_yay0SegmentRomStart, _group13_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group13_geoSegmentRomStart, _group13_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_2), 
	JUMP_LINK(script_func_global_14), 
	LOAD_MODEL_FROM_GEO(MODEL_C1_CUSHION, c1_cushion_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_C1_BURNER, c1_burner_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, wdw_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0B, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_WDW, 0x01, 0x0B, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, 0, 192, 26399, 0, -180, 0, 0x000B0000, bhvAirborneDeathWarp),
		OBJECT(MODEL_NONE, 0, 192, 26399, 0, -180, 0, 0x000A0000, bhvFlyingWarp),
		MARIO_POS(0x01, -180, 0, 192, 26399),
		OBJECT(MODEL_C1_BURNER, -3432, 2971, 4587, 0, 0, 0, 0x00010000, bhvOvenBurner),
		OBJECT(MODEL_C1_BURNER, -3232, 2971, 4137, 0, 0, 0, 0x00010000, bhvOvenBurner),
		OBJECT(MODEL_C1_BURNER, -4082, 2971, 2587, 0, 0, 0, 0x00000000, bhvOvenBurner),
		OBJECT(MODEL_C1_BURNER, -2432, 2971, 3437, 0, 0, 0, 0x00000000, bhvOvenBurner),
		OBJECT(MODEL_C1_BURNER, -2782, 2971, 3087, 0, 0, 0, 0x00010000, bhvOvenBurner),
		OBJECT(MODEL_C1_BURNER, -3232, 2971, 2491, 0, 0, 0, 0x00010000, bhvOvenBurner),
		OBJECT(MODEL_C1_BURNER, -2782, 2971, 2687, 0, 0, 0, 0x00000000, bhvOvenBurner),
		OBJECT(MODEL_C1_BURNER, -3232, 2971, 2091, 0, 0, 0, 0x00000000, bhvOvenBurner),
		OBJECT(MODEL_C1_BURNER, -3232, 2971, 1691, 0, 0, 0, 0x00010000, bhvOvenBurner),
		OBJECT(MODEL_C1_BURNER, -2832, 2971, 4137, 0, 0, 0, 0x00000000, bhvOvenBurner),
		OBJECT(MODEL_C1_BURNER, -3032, 2971, 4587, 0, 0, 0, 0x00010000, bhvOvenBurner),
		OBJECT(MODEL_C1_BURNER, -3632, 2971, 4137, 0, 0, 0, 0x00000000, bhvOvenBurner),
		OBJECT(MODEL_C1_BURNER, -3032, 2971, 3637, 0, 0, 0, 0x00000000, bhvOvenBurner),
		OBJECT(MODEL_C1_BURNER, -3632, 2971, 3337, 0, 0, 0, 0x00010000, bhvOvenBurner),
		OBJECT(MODEL_C1_BURNER, -3632, 2971, 2937, 0, 0, 0, 0x00000000, bhvOvenBurner),
		OBJECT(MODEL_C1_CUSHION, -4369, 4649, -4307, 0, 17, 0, (3 << 16), bhvCushion),
		OBJECT(MODEL_C1_CUSHION, -2578, 5410, -5471, 0, -22, 0, (3 << 16), bhvCushion),
		TERRAIN(wdw_area_1_collision),
		ROOMS(wdw_area_1_collision_rooms),
		MACRO_OBJECTS(wdw_area_1_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, -180, 0, 192, 26399),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
