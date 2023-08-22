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
#include "levels/thi/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_thi_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _thi_segment_7SegmentRomStart, _thi_segment_7SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _grass_yay0SegmentRomStart, _grass_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0A, _CUSTOM_L8_skybox_yay0SegmentRomStart, _CUSTOM_L8_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group11_yay0SegmentRomStart, _group11_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group11_geoSegmentRomStart, _group11_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group14_yay0SegmentRomStart, _group14_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group14_geoSegmentRomStart, _group14_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_12), 
	JUMP_LINK(script_func_global_15), 
	LOAD_MODEL_FROM_GEO(MODEL_C3_LEGO_PIECE, c3_lego_piece_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_C3_UNSTABLE_ROCK, c3_unstable_rock_yellow_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, thi_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0B, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_THI, 0x01, 0x0B, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, 0, 192, 26399, 0, -180, 0, 0x000B0000, bhvAirborneDeathWarp),
		OBJECT(MODEL_NONE, 0, 192, 26399, 0, -180, 0, 0x000A0000, bhvFlyingWarp),
		MARIO_POS(0x01, -180, 0, 192, 26399),
		OBJECT(MODEL_C3_LEGO_PIECE, -3294, 251, 8863, 0, 41, 0, 0x00020000, bhvC3LegoPiece),
		OBJECT(MODEL_C3_LEGO_PIECE, -2890, 55, 10088, 0, -60, 0, 0x00020000, bhvC3LegoPiece),
		OBJECT(MODEL_C3_LEGO_PIECE, 6684, 548, 28080, -2, -142, 3, 0x00020000, bhvC3LegoPiece),
		OBJECT(MODEL_C3_LEGO_PIECE, -4922, 251, 9303, 0, -14, 0, 0x00020000, bhvC3LegoPiece),
		OBJECT(MODEL_C3_LEGO_PIECE, -5886, 511, 9567, 0, -60, 0, 0x00020000, bhvC3LegoPiece),
		OBJECT(MODEL_C3_LEGO_PIECE, -6810, 770, 10266, 0, 0, 0, 0x00020000, bhvC3LegoPiece),
		OBJECT(MODEL_C3_LEGO_PIECE, -8109, 770, 10578, 0, 0, 0, 0x00020000, bhvC3LegoPiece),
		OBJECT(MODEL_C3_LEGO_PIECE, -8659, 1545, 10578, 0, 0, -90, 0x00020000, bhvC3LegoPiece),
		OBJECT(MODEL_C3_LEGO_PIECE, -7609, 1838, 10578, 0, 0, -90, 0x00020000, bhvC3LegoPiece),
		OBJECT(MODEL_C3_LEGO_PIECE, -8659, 2345, 10578, 0, 0, -90, 0x00020000, bhvC3LegoPiece),
		OBJECT(MODEL_C3_LEGO_PIECE, -6955, 2848, 10578, 0, 0, 0, 0x00020000, bhvC3LegoPiece),
		OBJECT(MODEL_C3_LEGO_PIECE, -6073, 2843, 9593, 0, -73, 0, 0x00020000, bhvC3LegoPiece),
		OBJECT(MODEL_C3_LEGO_PIECE, -5106, 2888, 8517, 0, 166, 0, 0x00020000, bhvC3LegoPiece),
		OBJECT(MODEL_C3_LEGO_PIECE, -4007, 2955, 7783, 0, 63, 0, 0x00020000, bhvC3LegoPiece),
		OBJECT(MODEL_C3_LEGO_PIECE, 1975, 3512, 6213, 0, 90, 0, 0x00020000, bhvC3LegoPiece),
		OBJECT(MODEL_C3_LEGO_PIECE, 1475, 3212, 6213, 0, 90, 0, 0x00020000, bhvC3LegoPiece),
		OBJECT(MODEL_C3_LEGO_PIECE, 1, -100, 21738, 0, 51, 0, 0x00020000, bhvC3LegoPiece),
		OBJECT(MODEL_C3_LEGO_PIECE, -7609, 2638, 10578, 0, 0, -90, 0x00020000, bhvC3LegoPiece),
		OBJECT(MODEL_C3_LEGO_PIECE, -8659, 3145, 10578, 0, 0, -90, 0x00020000, bhvC3LegoPiece),
		OBJECT(MODEL_C3_LEGO_PIECE, -2742, -95, 13297, 0, 139, 0, 0x00020000, bhvC3LegoPiece),
		OBJECT(MODEL_C3_LEGO_PIECE, 210, -120, 20400, 0, 125, 0, 0x00020000, bhvC3LegoPiece),
		OBJECT(MODEL_C3_LEGO_PIECE, -664, -159, 19011, 0, 123, 0, 0x00020000, bhvC3LegoPiece),
		OBJECT(MODEL_C3_LEGO_PIECE, -939, -147, 17433, 0, -104, 0, 0x00020000, bhvC3LegoPiece),
		OBJECT(MODEL_C3_LEGO_PIECE, 6091, 762, 26742, 0, -119, 0, 0x00020000, bhvC3LegoPiece),
		OBJECT(MODEL_C3_LEGO_PIECE, 7479, 762, 26814, 2, -56, 0, 0x00020000, bhvC3LegoPiece),
		OBJECT(MODEL_C3_LEGO_PIECE, 8410, 716, 27558, 0, -141, 0, 0x00020000, bhvC3LegoPiece),
		OBJECT(MODEL_C3_LEGO_PIECE, 7180, 655, 25284, 0, -54, 0, 0x00020000, bhvC3LegoPiece),
		OBJECT(MODEL_HORIZONTAL_POLE, 2936, 4212, 5752, 0, -180, 0, 0x00100000, bhvHorizontalPole),
		OBJECT(MODEL_HORIZONTAL_POLE, -1366, 3574, 6213, 0, 90, 0, 0x00100000, bhvHorizontalPole),
		OBJECT(MODEL_C3_UNSTABLE_ROCK, 5160, 7228, -2397, 0, -36, 0, 0x00000000, bhvC3UnstableRock),
		OBJECT(MODEL_C3_UNSTABLE_ROCK, 5811, 7228, -1723, 0, -36, 0, 0x00000000, bhvC3UnstableRock),
		OBJECT(MODEL_C3_UNSTABLE_ROCK, 6449, 7228, -1155, 0, -36, 0, 0x00000000, bhvC3UnstableRock),
		OBJECT(MODEL_C3_UNSTABLE_ROCK, 7844, 7228, -1381, 0, 19, 0, 0x00000000, bhvC3UnstableRock),
		OBJECT(MODEL_C3_UNSTABLE_ROCK, 8500, 7228, -426, 0, -34, 0, 0x00000000, bhvC3UnstableRock),
		TERRAIN(thi_area_1_collision),
		ROOMS(thi_area_1_collision_rooms),
		MACRO_OBJECTS(thi_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_CHALLENGE),
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
