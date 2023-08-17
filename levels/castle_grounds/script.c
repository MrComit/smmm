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
#include "levels/castle_grounds/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_castle_grounds_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _castle_grounds_segment_7SegmentRomStart, _castle_grounds_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x0A, _bbh_skybox_yay0SegmentRomStart, _bbh_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _outside_yay0SegmentRomStart, _outside_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group10_yay0SegmentRomStart, _group10_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group10_geoSegmentRomStart, _group10_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group15_yay0SegmentRomStart, _group15_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group15_geoSegmentRomStart, _group15_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_11), 
	JUMP_LINK(script_func_global_16), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_WARP_PIPE, warp_pipe_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_CASTLE_DOOR, castle_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_PLANT_GROW, plant_grow_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_DIRT_PILE, dirt_pile_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CG_ELEVATOR, cg_elevator_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CG_SPINNER, cg_spinner_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, castle_grounds_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x82, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x83, LEVEL_WF, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x84, LEVEL_JRB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x85, LEVEL_CCM, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x86, LEVEL_BBH, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x90, LEVEL_BOB, 0x01, 0x90, WARP_NO_CHECKPOINT),
		WARP_NODE(0x91, LEVEL_BOB, 0x01, 0x91, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0C, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xBA, LEVEL_WF, 0x01, 0xBB, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, 530, -2573, -4789, 0, -180, 0, 0x000A0000, bhvFlyingWarp),
		OBJECT(MODEL_NONE, -1119, -2561, -16607, 0, -180, 0, 0x000C0000, bhvFlyingWarp),
		MARIO_POS(0x01, -180, 530, -2573, -4789),
		OBJECT(MODEL_CG_ELEVATOR, -1092, -2656, -17528, 0, 0, 0, (1 << 16), bhvBalconyElevator),
		OBJECT(MODEL_DIRT_PILE, -2299, -2761, -12148, 0, 0, 0, 0x00000000, bhvDirtPile),
		OBJECT(MODEL_DIRT_PILE, -2760, -2761, -8262, 0, 0, 0, 0x00000000, bhvDirtPile),
		OBJECT(MODEL_DIRT_PILE, -1389, -2719, -5849, 0, 0, 0, 0x00000000, bhvDirtPile),
		OBJECT(MODEL_DIRT_PILE, 3592, -2761, -15381, 0, 0, 0, 0x00000000, bhvDirtPile),
		OBJECT(MODEL_DIRT_PILE, 2423, -2761, -12961, 0, 0, 0, 0x00000000, bhvDirtPile),
		OBJECT(MODEL_DIRT_PILE, -2979, -2761, -16419, 0, 0, 0, 0x00000000, bhvDirtPile),
		OBJECT(MODEL_CASTLE_GROUNDS_CASTLE_DOOR, 952, -2425, -19598, 0, 0, 0, 0x00900000, bhvDoorWarp),
		OBJECT(MODEL_CASTLE_GROUNDS_CASTLE_DOOR, 1102, -2425, -19598, 0, -180, 0, 0x00910000, bhvDoorWarp),
		OBJECT(MODEL_PLANT_GROW, -2302, -3163, -12160, 0, 0, 0, 0x00000000, bhvCastlePlant),
		TERRAIN(castle_grounds_area_1_collision),
		ROOMS(castle_grounds_area_1_collision_rooms),
		MACRO_OBJECTS(castle_grounds_area_1_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, -180, 530, -2573, -4789),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
