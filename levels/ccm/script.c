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
#include "levels/ccm/header.h"

const LevelScript level_ccm_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _ccm_segment_7SegmentRomStart, _ccm_segment_7SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _snow_yay0SegmentRomStart, _snow_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0B, _effect_yay0SegmentRomStart, _effect_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0A, _cloud_floor_skybox_yay0SegmentRomStart, _cloud_floor_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group7_yay0SegmentRomStart, _group7_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group7_geoSegmentRomStart, _group7_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group16_yay0SegmentRomStart, _group16_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group16_geoSegmentRomStart, _group16_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_8), 
	JUMP_LINK(script_func_global_17), 
	LOAD_MODEL_FROM_GEO(MODEL_RUBBERBAND, rubberband_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_LEGO_PIECE, lego_piece_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_SHAKY_PLAT, shaky_plat_geo),

	AREA(1, ccm_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0B, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_CCM, 0x01, 0x0B, WARP_NO_CHECKPOINT),
		WARP_NODE(0x20, LEVEL_BBH, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, 20295, 200, 8839, 0, 0, 0, 0x000B0000, bhvAirborneDeathWarp),
		OBJECT(MODEL_NONE, 20295, 200, 8839, 0, 0, 0, 0x000A0000, bhvFlyingWarp),
		MARIO_POS(0x01, 0, 20295, 200, 8839),
		OBJECT(MODEL_STAR_CURRENCY, 13426, -461, 8599, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR_CURRENCY, 20261, 221, 3506, 0, 0, 0, 0x02000000, bhvStar),
		OBJECT(MODEL_STAR_CURRENCY, 18657, 305, 4686, 0, 0, 0, 0x01000000, bhvStar),
		OBJECT(MODEL_STAR_CURRENCY, 16882, 139, 2449, 0, 0, 0, 0x03000000, bhvStar),
		OBJECT(MODEL_STAR_CURRENCY, 18783, 139, 1609, 0, 0, 0, 0x04000000, bhvStar),
		OBJECT(MODEL_STAR_CURRENCY, 19854, 1561, 10918, 0, 0, 0, 0x05000000, bhvStar),
		OBJECT(MODEL_RUBBERBAND, 15673, 119, -5812, 0, -180, 0, 0x00000000, bhvRubberband),
		OBJECT(MODEL_LEGO_PIECE, 15566, -159, 1111, 0, 19, 0, 0x00000000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, 17198, -159, 638, 0, 19, 0, 0x00010000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, 18763, -159, 245, 0, 19, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_NONE, 19573, 89, 5537, 0, 0, 0, 0x00100000, bhvHorizontalPole),
		OBJECT(MODEL_NONE, 21682, -161, 14274, 0, 0, 0, 0x00100000, bhvHorizontalPole),
		OBJECT(MODEL_NONE, 19682, 1511, 13874, 0, 0, 0, 0x00100000, bhvHorizontalPole),
		TERRAIN(ccm_area_1_collision),
		ROOMS(ccm_area_1_collision_rooms),
		MACRO_OBJECTS(ccm_area_1_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_STONE),
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, 20295, 200, 8839),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
