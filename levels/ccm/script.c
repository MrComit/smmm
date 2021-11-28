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
#include "levels/ccm/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_ccm_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _ccm_segment_7SegmentRomStart, _ccm_segment_7SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _snow_yay0SegmentRomStart, _snow_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0B, _effect_yay0SegmentRomStart, _effect_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0A, _cloud_floor_skybox_yay0SegmentRomStart, _cloud_floor_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group1_yay0SegmentRomStart, _group1_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group1_geoSegmentRomStart, _group1_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group15_yay0SegmentRomStart, _group15_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group15_geoSegmentRomStart, _group15_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_2), 
	JUMP_LINK(script_func_global_16), 
	LOAD_MODEL_FROM_GEO(MODEL_RUBBERBAND, rubberband_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_LEGO_PIECE, lego_piece_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_SHAKY_PLAT, shaky_plat_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_POUND_LEGO, pound_lego_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, ccm_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x1A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_CCM, 0x01, 0x1A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x20, LEVEL_BBH, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0B, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0C, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, 23998, 200, -7093, 0, -90, 0, 0x001A0000, bhvAirborneDeathWarp),
		OBJECT(MODEL_NONE, 23998, 200, -7093, 0, -90, 0, 0x000A0000, bhvFlyingWarp),
		OBJECT(MODEL_NONE, 18257, 119, -11057, 0, 0, 0, 0x000B0000, bhvFlyingWarp),
		OBJECT(MODEL_NONE, 16906, 119, -11094, 0, 0, 0, 0x000C0000, bhvFlyingWarp),
		MARIO_POS(0x01, -90, 23998, 200, -7093),
		OBJECT(MODEL_RUBBERBAND, 17643, 119, -12202, 0, -180, 0, 0x00000000, bhvRubberband),
		OBJECT(MODEL_STAR_CURRENCY, 19854, 1561, 2918, 0, 90, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR_CURRENCY, 9980, 221, -1516, 0, 0, 0, (1 << 24), bhvStar),
		OBJECT(MODEL_STAR_CURRENCY, 4166, 679, 8690, 0, -180, 0, (2 << 24), bhvStar),
		OBJECT(MODEL_STAR_CURRENCY, 5011, 679, -7833, 0, 0, 0, (3 << 24), bhvStar),
		OBJECT(MODEL_STAR_CURRENCY, 23016, 139, -915, 0, 0, 0, (4 << 24), bhvStar),
		OBJECT(MODEL_LEGO_PIECE, 4166, 229, 3629, 0, 90, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, -4184, 229, 8770, 0, -60, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, -2271, 315, 10066, -2, -142, 3, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, 6927, -71, 729, 0, 90, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, 6427, 79, 729, 0, 90, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, 5927, 229, 729, 0, 90, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, 7577, -71, 729, 0, -180, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, 5277, 229, 729, 0, -180, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, 1782, 229, -2814, 0, 90, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, 1282, 229, -2814, 0, 90, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, 6262, 1696, -11662, -90, 90, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, 4166, 229, 4429, 0, 90, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, 6662, 2596, -11662, 0, 90, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, -6962, 529, -2618, 0, -90, 0, (5 << 16), bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, -5906, 529, -2768, 0, 0, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, -8954, 529, 3724, 0, 0, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, 5011, 329, -7433, 90, 0, -180, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, 5011, 829, -7433, 90, 0, -180, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, -168, 229, -2814, 0, -180, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, -818, 229, -2814, 0, 90, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, -1318, 529, -2814, 0, 90, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, 5011, 329, -8233, -90, 0, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, -5473, 529, 8771, 0, 52, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, 5462, 1196, -11662, 90, 90, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, 6262, 2496, -11662, -90, 90, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, 5462, 1996, -11662, 90, 90, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, 5011, 229, -7833, 0, -180, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, 5462, 2796, -11662, 90, 90, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, 4461, 329, -7833, -29, 90, 64, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, 5862, 796, -11662, 0, -90, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, 4461, 829, -7833, -29, 90, 64, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, -10209, 363, -1701, 0, 165, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, 5561, 329, -7833, -38, -90, -51, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, -8745, 413, 2386, 0, 50, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, -9619, 513, 996, 0, 151, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, -9712, 363, -418, 0, -139, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, -9254, 513, -2518, 0, 76, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, -8104, 513, -2681, 0, -170, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, 5561, 829, -7833, -38, -90, -51, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, 5011, 929, -7833, 0, -180, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, -3893, 267, 10071, 0, -43, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, -2864, 529, 8728, 2, -119, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, 6262, 896, -11662, -90, 90, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, -1475, 529, 8800, 2, -56, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, -545, 262, 9543, 0, -141, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, -483, 332, 7579, -2, -141, 3, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, 138, 210, 8576, 2, 155, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, 1502, 105, 8733, 0, 29, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, 2912, 229, 8690, 0, 0, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, -1774, 201, 7270, 0, -54, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_MIPS, 12162, -41, 3182, 0, 0, 0, (1 << 24), bhvGardenMips),
		OBJECT(MODEL_NONE, 21682, -161, 6274, 0, 0, 0, 0x00100000, bhvHorizontalPole),
		OBJECT(MODEL_NONE, 19682, 1511, 5874, 0, 0, 0, 0x00100000, bhvHorizontalPole),
		OBJECT(MODEL_NONE, 5260, 629, -3813, 0, 0, 0, 0x00100000, bhvHorizontalPole),
		OBJECT(MODEL_NONE, 4166, 629, 7410, 0, 0, 0, 0x00100000, bhvHorizontalPole),
		OBJECT(MODEL_POUND_LEGO, 12002, -41, 3124, 0, 0, 0, 0x01000000, bhvPoundLego),
		OBJECT(MODEL_POUND_LEGO, 13967, -281, 1878, 0, 0, 0, 0x01000000, bhvPoundLego),
		OBJECT(MODEL_POUND_LEGO, 14266, -281, -1303, 0, 0, 0, 0x01000000, bhvPoundLego),
		OBJECT(MODEL_POUND_LEGO, 15528, -401, -1170, 0, 0, 0, 0x01000000, bhvPoundLego),
		OBJECT(MODEL_POUND_LEGO, 15479, -281, 530, 0, 0, 0, 0x01000000, bhvPoundLego),
		OBJECT(MODEL_SHAKY_PLAT, 23773, 139, 3574, 0, 0, 0, 0x00000000, bhvShakyPlat),
		OBJECT(MODEL_SHAKY_PLAT, 23773, 1935, 3574, 0, 0, 0, 0x00000000, bhvShakyPlat),
		TERRAIN(ccm_area_1_collision),
		ROOMS(ccm_area_1_collision_rooms),
		MACRO_OBJECTS(ccm_area_1_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_STONE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, -90, 23998, 200, -7093),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
