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
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_CASTLE_DOOR, castle_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_RUBBERBAND, rubberband_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_LEGO_PIECE, lego_piece_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_SHAKY_PLAT, shaky_plat_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_POUND_LEGO, pound_lego_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CARDBOARD_WALL, cardboard_wall_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_RACECAR, racecar_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CITY_BRIDGE, city_bridge_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_TOY_TOAD, toy_toad_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BOSS_SHYGUY, boss_shyguy_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BLOCK_PIECE, block_piece_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BLOCK_TOWER, block_tower_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, ccm_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x1A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_CCM, 0x01, 0x1A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x20, LEVEL_BBH, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0B, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0C, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x56, LEVEL_CCM, 0x01, 0x55, WARP_NO_CHECKPOINT),
		WARP_NODE(0x55, LEVEL_CCM, 0x01, 0x56, WARP_NO_CHECKPOINT),
		WARP_NODE(0x57, LEVEL_CCM, 0x02, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0D, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, 23998, 200, -5671, 0, -90, 0, 0x001A0000, bhvAirborneDeathWarp),
		OBJECT(MODEL_NONE, 23998, 200, -5671, 0, -90, 0, 0x000A0000, bhvFlyingWarp),
		OBJECT(MODEL_NONE, 18257, 119, -11057, 0, 0, 0, 0x000B0000, bhvFlyingWarp),
		OBJECT(MODEL_NONE, 16906, 119, -11094, 0, 0, 0, 0x000C0000, bhvFlyingWarp),
		OBJECT(MODEL_NONE, 16416, 119, -11928, 0, 90, 0, 0x000D0000, bhvFlyingWarp),
		MARIO_POS(0x01, -90, 23998, 200, -5671),
		OBJECT(MODEL_MIPS, 10560, -161, 2897, 0, 0, 0, (1 << 24), bhvGardenMips),
		OBJECT(MODEL_POUND_LEGO, 10399, -161, 2839, 0, 0, 0, 0x01000000, bhvPoundLego),
		OBJECT(MODEL_POUND_LEGO, 13967, -281, 1878, 0, 0, 0, 0x01000000, bhvPoundLego),
		OBJECT(MODEL_POUND_LEGO, 14266, -281, -1303, 0, 0, 0, 0x01000000, bhvPoundLego),
		OBJECT(MODEL_POUND_LEGO, 15683, -401, -1570, 0, 0, 0, 0x01000000, bhvPoundLego),
		OBJECT(MODEL_POUND_LEGO, 15327, -281, 729, 0, 0, 0, 0x01000000, bhvPoundLego),
		OBJECT(MODEL_POUND_LEGO, 12607, -161, -267, 0, 0, 0, 0x01000000, bhvPoundLego),
		OBJECT(MODEL_POUND_LEGO, 17074, -41, 3016, 0, 0, 0, 0x01000000, bhvPoundLego),
		OBJECT(MODEL_POUND_LEGO, 11248, 79, -64, 0, 0, 0, 0x01000000, bhvPoundLego),
		OBJECT(MODEL_STAR_CURRENCY, 4166, 1179, 8690, 0, -180, 0, (2 << 24), bhvStar),
		OBJECT(MODEL_STAR_CURRENCY, 2743, 679, 729, 0, 0, 0, (3 << 24), bhvStar),
		OBJECT(MODEL_LEGO_PIECE, 4166, 229, 3629, 0, 90, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, -4184, 462, 8770, 0, -60, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, -2271, 548, 10066, -2, -142, 3, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, 6927, -71, 729, 0, 90, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, 6427, 79, 729, 0, 90, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, 5927, 229, 729, 0, 90, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, 7577, -71, 729, 0, -180, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, 5277, 229, 729, 0, -180, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, 1782, 229, -2814, 0, 90, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, 1282, 229, -2814, 0, 90, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, 7283, 2029, -4515, -90, 0, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, 4166, 229, 4429, 0, 90, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, 6991, 2229, -1228, 0, 90, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, 7283, 2929, -4115, 0, 0, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, -6962, 529, -2618, 0, -90, 0, (5 << 16), bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, -5906, 529, -2768, 0, 0, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, -8954, 529, 3724, 0, 0, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, 7491, 2229, -1228, 0, 90, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, 3304, 1629, 729, 90, 90, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, -168, 229, -2814, 0, -180, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, -818, 229, -2814, 0, 90, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, -1318, 529, -2814, 0, 90, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, 9933, 129, -4915, 0, -90, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, -5473, 529, 8771, 0, 52, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, 7283, 1529, -5315, 90, 0, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, 7283, 2829, -4515, -90, 0, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, 7283, 2329, -5315, 90, 0, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, 8783, 129, -4915, 0, -180, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, 7283, 3129, -5315, 90, 0, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, 9433, 129, -4915, 0, -90, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, 7283, 229, -4915, 0, -180, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, 10583, 129, -4915, 0, -180, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, -10209, 363, -1701, 0, 165, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, 7341, 2329, -1778, 90, 0, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, -8745, 413, 2386, 0, 50, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, 7341, 2429, -2178, 0, -180, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, -9619, 513, 996, 0, 151, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, -9712, 363, -418, 0, -139, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, -9254, 513, -2518, 0, 76, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, -8104, 513, -2681, 0, -170, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, 6491, 2229, 1265, 0, 90, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, 6491, 2229, 465, 0, 90, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, 7141, 2529, 1415, 0, -180, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, -3893, 500, 10071, 0, -43, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, -2864, 762, 8728, 0, -119, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, 7283, 1229, -4515, -90, 0, 0, 0x00000000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, -1475, 762, 8800, 2, -56, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, -545, 716, 9543, 0, -141, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, -483, 786, 7579, -2, -141, 3, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, 138, 742, 8576, 2, 155, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, 3304, 629, 729, 90, 90, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, 3304, 1129, 729, 90, 90, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, 6991, 2729, 2687, 0, -90, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, 6191, 2729, 3487, 0, -90, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, 6841, 2729, 3637, 0, 0, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, 5569, 3029, 3487, 0, -90, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, 3554, 2029, 3487, 0, 0, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, 1502, 761, 8733, 0, 29, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, 2912, 729, 8690, 0, 0, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, -1774, 655, 7270, 0, -54, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, 1782, 229, 729, 0, -90, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, 1132, 229, 579, 0, 0, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, 3704, 2029, 2837, 0, 90, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, 12120, 129, -4915, 0, -90, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, 1782, 1429, 3337, 0, -90, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, 2432, 1729, 3487, 0, 0, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, 1782, 1129, 1929, 0, -90, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_HORIZONTAL_POLE, 4166, 1129, 7410, 0, 0, 0, 0x00100000, bhvHorizontalPole),
		OBJECT(MODEL_RUBBERBAND, 17643, 119, -12202, 0, -180, 0, 0x00000000, bhvRubberband),
		OBJECT(MODEL_PURPLE_SWITCH, 23901, -101, 1381, 0, -90, 0, 0x00000000, bhvGenericSwitch),
		OBJECT(MODEL_CARDBOARD_WALL, 24737, 1191, -2411, 0, 0, 0, (1 << 16), bhvCardboardWall),
		OBJECT(MODEL_CARDBOARD_WALL, 24737, -161, 1381, 0, 0, 0, (1 << 24), bhvCardboardWall),
		OBJECT(MODEL_CARDBOARD_WALL, 24737, 2327, -397, 0, 0, 0, (1 << 16), bhvCardboardWall),
		OBJECT(MODEL_CARDBOARD_WALL, 24737, -161, -4189, 0, 0, 0, 0x00000000, bhvCardboardWall),
		OBJECT(MODEL_CITY_BRIDGE, 13028, -67, -12223, 0, 0, 0, 0x00000000, bhvCityBridge),
		OBJECT(MODEL_STAR_CURRENCY, 21743, 750, -5671, 0, 90, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR_CURRENCY, 23016, 139, 507, 0, 0, 0, (4 << 24), bhvStar),
		OBJECT(MODEL_TELEPORTER, 1132, 379, 579, 0, 90, 0, (0x56 << 16), bhvFadingWarp),
		OBJECT(MODEL_NONE, 4177, 579, 729, 0, -90, 0, (0x55 << 16), bhvFadingWarp),
		OBJECT(MODEL_NONE, 21329, -161, 1196, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, 21643, -161, -3639, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, 3896, 379, -2666, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, -8743, 779, 8304, 0, 0, 0, (1 << 16), bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, 23949, 457, -4196, 0, 0, 0, (66 << 16), bhvPoleGrabbing),
		OBJECT(MODEL_HORIZONTAL_POLE, 21682, -161, 6274, 0, 0, 0, 0x00100000, bhvHorizontalPole),
		OBJECT(MODEL_HORIZONTAL_POLE, 19682, 1511, 5874, 0, 0, 0, 0x00100000, bhvHorizontalPole),
		OBJECT(MODEL_HORIZONTAL_POLE, 19759, 1511, 2663, 0, 0, 0, 0x00100000, bhvHorizontalPole),
		OBJECT(MODEL_HORIZONTAL_POLE, 16503, 89, -6738, 0, 90, 0, 0x00100000, bhvHiddenHorizontalPole),
		OBJECT(MODEL_PURPLE_SWITCH, 13370, 279, -6738, 0, -90, 0, 0x00000000, bhvGenericSwitch),
		OBJECT(MODEL_SHAKY_PLAT, 23773, 139, 3574, 0, 0, 0, 0x00000000, bhvShakyPlat),
		OBJECT(MODEL_SHAKY_PLAT, 23773, 1935, 3574, 0, 0, 0, 0x00000000, bhvShakyPlat),
		OBJECT(MODEL_TOKEN, 23234, 164, -1878, 90, 0, 0, 0x00000000, bhvToken),
		OBJECT(MODEL_TOKEN, 19759, 2912, -1404, 0, 0, 0, 0x00000000, bhvToken),
		OBJECT(MODEL_TOY_TOAD, 20985, -161, -6092, 0, 90, 0, (DIALOG_006 << 24), bhvToyToad),
		OBJECT(MODEL_TOY_TOAD, 17623, -161, -11650, 0, 0, 0, (12 << 24) | (1 << 16), bhvToyToad),
		OBJECT(MODEL_TOY_TOAD, 22711, -161, -1628, 0, -180, 0, (DIALOG_007 << 24), bhvToyToad),
		OBJECT(MODEL_TOY_TOAD, 16510, -161, -10388, 0, 90, 0, (DIALOG_008 << 24) | (2 << 16), bhvToyToad),
		OBJECT(MODEL_TOY_TOAD, -4275, 679, -2431, 0, 120, 0, (DIALOG_028 << 24), bhvToyToad),
		OBJECT(MODEL_BLUE_COIN, 3469, 930, -4915, 0, -90, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, 3120, 1063, -4915, 0, -90, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, 4627, 2470, -4915, 0, -90, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, 2332, 1659, -5276, 0, -90, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, 2332, 1409, -5276, 0, -90, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, 2332, 1059, -4504, 0, -90, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, 3672, 813, -4915, 0, -90, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, 3993, 2270, -5376, 0, -90, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, 3193, 2170, -4454, 0, -90, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN_SWITCH, 4277, 399, -4915, 0, 90, 0, (0xB << 24) | (0x2 << 16) | (0x20 << 8), bhvBlueCoinSwitch),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, 4827, 379, -4915, 0, 90, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_HORIZONTAL_POLE, 3877, 649, -4915, 0, -90, 0, 0x00100000, bhvHorizontalPole),
		TERRAIN(ccm_area_1_collision),
		ROOMS(ccm_area_1_collision_rooms),
		MACRO_OBJECTS(ccm_area_1_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_STONE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(2, ccm_area_2),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x1A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_CCM, 0x02, 0x1A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x57, LEVEL_CCM, 0x01, 0x0D, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, 19861, 39, 0, 0, -90, 0, 0x001A0000, bhvAirborneDeathWarp),
		OBJECT(MODEL_NONE, 19861, 39, 0, 0, -90, 0, 0x000A0000, bhvFlyingWarp),
		OBJECT(MODEL_BLOCK_TOWER, -11375, 4339, 23, 0, -90, 0, 0x00000000, bhvBlockTower),
		OBJECT(MODEL_BLOCK_TOWER, -9402, 4339, -3591, 0, -90, 0, 0x00000000, bhvBlockTower),
		OBJECT(MODEL_BLOCK_TOWER, -11994, 4339, -5322, 0, -90, 0, 0x00000000, bhvBlockTower),
		OBJECT(MODEL_STAR_CURRENCY, 16111, 2776, 0, 0, 0, 0, (0x11 << 24), bhvStar),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, 7787, 839, -5050, 0, 0, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, 7937, 839, -5050, 0, -180, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, 7486, 839, 50, 0, -180, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_LEGO_PIECE, -3789, 4189, -2500, 0, 0, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, -4830, 4289, -1897, 0, 90, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, -5082, 4489, -956, 0, -180, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, -5292, 4689, 30, 0, -90, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, -5292, 4689, 1526, 0, -90, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_LEGO_PIECE, -6689, 4889, 1526, 0, 0, 0, 0x00020000, bhvLegoPiece),
		OBJECT(MODEL_HORIZONTAL_POLE, 10111, 1089, 1000, 0, -180, 0, 0x00100000, bhvHorizontalPole),
		OBJECT(MODEL_HORIZONTAL_POLE, 5534, 1023, 6041, 0, -135, 0, 0x00100000, bhvHorizontalPole),
		OBJECT(MODEL_HORIZONTAL_POLE, 13611, 589, -2730, 0, 90, 0, 0x00100000, bhvHorizontalPole),
		OBJECT(MODEL_RACECAR, 15986, -161, 3000, 0, -180, 0, (60 << 24) | (0 << 16), bhvRacecar),
		OBJECT(MODEL_RACECAR, 17236, 487, -2000, 0, 0, 0, (40 << 24) | (1 << 16), bhvRacecar),
		OBJECT(MODEL_RACECAR, 15986, 527, -2000, 0, 0, 0, (40 << 24) | (1 << 16), bhvRacecar),
		OBJECT(MODEL_RACECAR, 17736, -161, -3000, 0, 0, 0, (60 << 24) | (1 << 16), bhvRacecar),
		OBJECT(MODEL_RACECAR, 12661, 839, -5350, 0, -90, 0, (20 << 24) | (1 << 8), bhvRacecar),
		OBJECT(MODEL_BOSS_SHYGUY, -11889, 4339, -2500, 0, 90, 0, 0x00000000, bhvShyGuyBoss),
		OBJECT(MODEL_TOY_TOAD, 15937, -161, 1371, 0, 90, 0, (DIALOG_017 << 24), bhvToyToad),
		OBJECT(MODEL_CANNON_BASE, 7861, 1174, -7537, 0, 0, 0, (0x40 << 16), bhvCannon),
		OBJECT(MODEL_NONE, 7861, 1796, -9805, 0, 0, 0, (0x40 << 16), bhvShootingGalleryHandler),
		OBJECT(MODEL_GLOBAL_GATE, 7861, 859, -5090, 0, -180, 0, 0x00000000, bhvGlobalGate),
		OBJECT(MODEL_BOO, 8961, 1139, -6575, 0, -90, 0, (0x5 << 24) | (0xD << 16) | (0x13 << 8), bhvRoomBoo),
		OBJECT(MODEL_NONE, 7671, 949, 868, 0, -180, 0, 0x00000000, bhvStarPieceHolder),
		OBJECT(MODEL_TOY_TOAD, 7411, 849, 868, 0, -180, 0, (DIALOG_018 << 24) | (3 << 16), bhvToyToad),
		OBJECT(MODEL_TOY_TOAD, 8296, 849, 570, 0, -135, 0, (DIALOG_027 << 24), bhvToyToad),
		TERRAIN(ccm_area_2_collision),
		ROOMS(ccm_area_2_collision_rooms),
		MACRO_OBJECTS(ccm_area_2_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_STONE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, -90, 23998, 200, -5671),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
