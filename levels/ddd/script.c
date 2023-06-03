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
#include "levels/ddd/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_ddd_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _ddd_segment_7SegmentRomStart, _ddd_segment_7SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _water_yay0SegmentRomStart, _water_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0B, _effect_yay0SegmentRomStart, _effect_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0A, _bbh_skybox_yay0SegmentRomStart, _bbh_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group4_yay0SegmentRomStart, _group4_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group4_geoSegmentRomStart, _group4_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group12_yay0SegmentRomStart, _group12_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group12_geoSegmentRomStart, _group12_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_5), 
	JUMP_LINK(script_func_global_13), 
	LOAD_MODEL_FROM_GEO(MODEL_THE_CONTROLLER, controller_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_END_GOOMBA, end_goomba_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_END_SHYGUY, end_shyguy_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_END_BOO, end_boo_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_END_CAGE, end_cage_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_END_FIST, end_fist_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_END_BUBBLE, end_bubble_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_END_LOG, end_log_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_END_SPIKE, end_spike_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_END_LASER, end_laser_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_HOLE_WALL, hole_wall_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_ROOF_HOLE, roof_hole_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_HOLE_WALL_GROUND, hole_wall_ground_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BG_GROUND, bg_ground_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, ddd_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0B, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_DDD, 0x01, 0x0B, WARP_NO_CHECKPOINT),
		INSTANT_WARP(0, 0x01, 26526, 14154, -2516),
		INSTANT_WARP(1, 0x01, 1425, 25915, 9124),
		INSTANT_WARP(2, 0x01, -27950, 27214, -6608),
		OBJECT(MODEL_NONE, 1083, 7706, -3448, 0, -180, 0, 0x000B0000, bhvAirborneDeathWarp),
		OBJECT(MODEL_NONE, 1083, 7706, -3448, 0, -180, 0, 0x000A0000, bhvFlyingWarp),
		MARIO_POS(0x01, -180, 1083, 7706, -3448),
		OBJECT(MODEL_THE_CONTROLLER, 1083, 7706, -10281, 0, 0, 0, 0x00000000, bhvTheController),
		OBJECT(MODEL_TOAD_FRIEND, -2126, 7416, -1593, 0, 140, 0, 0x00000000, bhvToadFriend),
		OBJECT(MODEL_ROOF_HOLE, 1081, 7406, -7477, 0, 0, 0, 0x00000000, bhvRoofHole),
		TERRAIN(ddd_area_1_collision),
		ROOMS(ddd_area_1_collision_rooms),
		MACRO_OBJECTS(ddd_area_1_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_STONE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, -180, 1083, 7706, -3448),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
