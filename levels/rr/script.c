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
#include "levels/rr/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_rr_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _rr_segment_7SegmentRomStart, _rr_segment_7SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _sky_yay0SegmentRomStart, _sky_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0A, _CUSTOM_L8_skybox_yay0SegmentRomStart, _CUSTOM_L8_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group11_yay0SegmentRomStart, _group11_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group11_geoSegmentRomStart, _group11_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_12), 
	JUMP_LINK(script_func_global_1), 
	LOAD_MODEL_FROM_GEO(MODEL_C5_CHANDELIER, c5_chandelier_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_C5_SPINNING_PLAT, c5_spinning_plat_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, rr_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0B, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_RR, 0x01, 0x0B, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, -78, -1097, 28900, 0, -180, 0, 0x000B0000, bhvAirborneDeathWarp),
		OBJECT(MODEL_NONE, -78, -1097, 28900, 0, -180, 0, 0x000A0000, bhvFlyingWarp),
		MARIO_POS(0x01, -180, -78, -1097, 28900),
		OBJECT(MODEL_C5_SPINNING_PLAT, 2712, 1015, 12504, 0, 0, 0, 0x00000000, bhvC5SpinningPlat),
		OBJECT(MODEL_C5_SPINNING_PLAT, -1610, 2210, 7947, 0, 0, 0, 0x00000000, bhvC5SpinningPlat),
		OBJECT(MODEL_C5_SPINNING_PLAT, -2859, 2210, 8338, 0, -41, 0, 0x00000000, bhvC5SpinningPlat),
		OBJECT(MODEL_C5_SPINNING_PLAT, -12091, 3642, 8074, 0, 42, 0, 0x00000000, bhvC5SpinningPlat),
		OBJECT(MODEL_C5_SPINNING_PLAT, 4921, 865, 15734, 0, 0, 0, 0x00000000, bhvC5SpinningPlat),
		OBJECT(MODEL_C5_CHANDELIER, -10786, 4183, 386, 0, 90, 0, 0x00000000, bhvMindChandelier),
		OBJECT(MODEL_C5_CHANDELIER, -11726, 3848, 4948, 0, 0, 0, 0x00000000, bhvMindChandelier),
		OBJECT(MODEL_C5_CHANDELIER, -11824, 4581, -2515, 0, 0, 0, 0x00000000, bhvMindChandelier),
		OBJECT(MODEL_C5_CHANDELIER, -8600, 5070, -8537, 0, -23, 0, 0x00000000, bhvMindChandelier),
		OBJECT(MODEL_C5_CHANDELIER, -5818, 5096, -10249, 0, 90, 0, 0x00000000, bhvMindChandelier),
		OBJECT(MODEL_C5_CHANDELIER, 2428, 5766, -8243, 0, 144, 0, 0x00000000, bhvMindChandelier),
		OBJECT(MODEL_C5_SPINNING_PLAT, 1924, 5683, -7353, 0, 90, 0, 0x00000000, bhvC5SpinningPlat),
		OBJECT(MODEL_C5_SPINNING_PLAT, 2932, 5683, -9134, 0, 90, 0, 0x00000000, bhvC5SpinningPlat),
		TERRAIN(rr_area_1_collision),
		ROOMS(rr_area_1_collision_rooms),
		MACRO_OBJECTS(rr_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_CHALLENGE),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, -180, -78, -1097, 28900),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
