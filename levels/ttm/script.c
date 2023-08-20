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
#include "levels/ttm/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_ttm_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _ttm_segment_7SegmentRomStart, _ttm_segment_7SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _mountain_yay0SegmentRomStart, _mountain_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0A, _CUSTOM_L8_skybox_yay0SegmentRomStart, _CUSTOM_L8_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group6_yay0SegmentRomStart, _group6_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group6_geoSegmentRomStart, _group6_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_7), 
	LOAD_MODEL_FROM_GEO(MODEL_C2_LEMON, c2_lemon_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_C2_MOVING_VINE, c2_moving_vine_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_C2_BOUNCY_BED, c2_bouncy_bed_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_C2_LIGHTNING_SPINNER, c2_lightning_spinner_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_C2_LIGHTNING_STRIKE, c2_lightning_strike_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, ttm_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0B, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_TTM, 0x01, 0x0B, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, 0, 192, 26399, 0, -180, 0, 0x000B0000, bhvAirborneDeathWarp),
		OBJECT(MODEL_NONE, 0, 192, 26399, 0, -180, 0, 0x000A0000, bhvFlyingWarp),
		MARIO_POS(0x01, -180, 0, 192, 26399),
		OBJECT(MODEL_C2_LEMON, 3985, -48, 16687, 0, 41, 0, 0x03640000, bhvC2Lemon),
		OBJECT(MODEL_C2_LEMON, 4261, -48, 15894, 0, 41, 0, 0x03640000, bhvC2Lemon),
		OBJECT(MODEL_C2_LEMON, 4668, -48, 14534, 0, -20, 0, 0x03640000, bhvC2Lemon),
		OBJECT(MODEL_NONE, 4438, -48, 13625, 0, 0, 0, 0x00790000, bhvPoleGrabbing),
		OBJECT(MODEL_C2_LIGHTNING_STRIKE, 9984, 1694, 9484, 0, 90, 0, (1 << 24) | (1 << 8), bhvC2Lightning),
		OBJECT(MODEL_C2_LIGHTNING_STRIKE, 10963, 1694, 9672, 0, 90, 0, 0x00010000, bhvC2Lightning),
		OBJECT(MODEL_C2_LIGHTNING_STRIKE, 12082, 1644, 10460, 0, 90, 0, 0x00010000, bhvC2Lightning),
		OBJECT(MODEL_C2_LIGHTNING_STRIKE, 12098, 1694, 9452, 0, 90, 0, 0x00000000, bhvC2Lightning),
		OBJECT(MODEL_C2_LIGHTNING_STRIKE, 13012, 1744, 8774, 0, 90, 0, 0x00010000, bhvC2Lightning),
		OBJECT(MODEL_C2_LIGHTNING_STRIKE, 13043, 1694, 9880, 0, 90, 0, 0x00000000, bhvC2Lightning),
		OBJECT(MODEL_C2_LIGHTNING_STRIKE, 13873, 1694, 9790, 0, 90, 0, 0x00010000, bhvC2Lightning),
		OBJECT(MODEL_C2_LIGHTNING_STRIKE, 13936, 1694, 8640, 0, 90, 0, 0x00000000, bhvC2Lightning),
		OBJECT(MODEL_C2_LIGHTNING_STRIKE, 14894, 1694, 8497, 0, 90, 0, (1 << 24), bhvC2Lightning),
		OBJECT(MODEL_C2_LIGHTNING_STRIKE, 15039, 1694, 9428, 0, 90, 0, 0x00000000, bhvC2Lightning),
		OBJECT(MODEL_C2_LIGHTNING_STRIKE, 14817, 1644, 10541, 0, 90, 0, 0x00010000, bhvC2Lightning),
		OBJECT(MODEL_C2_LIGHTNING_STRIKE, 15572, 1694, 11310, 0, 90, 0, 0x00000000, bhvC2Lightning),
		OBJECT(MODEL_C2_LIGHTNING_STRIKE, 15836, 1694, 10134, 0, 90, 0, 0x00010000, bhvC2Lightning),
		OBJECT(MODEL_C2_LIGHTNING_STRIKE, 16474, 1694, 10881, 0, 90, 0, 0x00010000, bhvC2Lightning),
		OBJECT(MODEL_C2_MOVING_VINE, 15011, 1598, 7374, 0, 90, 0, 0x00000000, bhvMovingVine),
		OBJECT(MODEL_C2_MOVING_VINE, 14460, 1914, 6489, 0, 94, 0, 0x00000000, bhvMovingVine),
		OBJECT(MODEL_C2_MOVING_VINE, 12842, 2880, 5101, 0, 170, 0, 0x00000000, bhvMovingVine),
		OBJECT(MODEL_C2_MOVING_VINE, 14296, 2124, 5412, 0, 47, 0, 0x04000000, bhvMovingVine),
		OBJECT(MODEL_C2_BOUNCY_BED, 16800, 3582, 4985, -3, -55, 3, 0x00000000, bhvC2BouncyBed),
		OBJECT(MODEL_C2_BOUNCY_BED, 23075, 4857, 2849, -1, 7, 1, 0x00000000, bhvC2BouncyBed),
		OBJECT(MODEL_C2_BOUNCY_BED, 20734, 4502, 10950, -1, -17, 2, 0x00000000, bhvC2BouncyBed),
		OBJECT(MODEL_C2_BOUNCY_BED, 22921, 4779, 11513, 0, 49, 0, 0x00000000, bhvC2BouncyBed),
		OBJECT(MODEL_C2_BOUNCY_BED, 17093, 4349, 4153, -3, -55, 3, 0x00000000, bhvC2BouncyBed),
		OBJECT(MODEL_C2_BOUNCY_BED, 17422, 5057, 3496, -3, -55, 3, 0x00000000, bhvC2BouncyBed),
		OBJECT(MODEL_C2_BOUNCY_BED, 18237, 5857, 3387, -3, -55, 3, 0x00000000, bhvC2BouncyBed),
		TERRAIN(ttm_area_1_collision),
		ROOMS(ttm_area_1_collision_rooms),
		MACRO_OBJECTS(ttm_area_1_macro_objs),
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
