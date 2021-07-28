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
#include "levels/bbh/header.h"

const LevelScript level_bbh_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _bbh_segment_7SegmentRomStart, _bbh_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x0A, _cloud_floor_skybox_yay0SegmentRomStart, _cloud_floor_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _spooky_yay0SegmentRomStart, _spooky_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group9_yay0SegmentRomStart, _group9_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group9_geoSegmentRomStart, _group9_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group17_yay0SegmentRomStart, _group17_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group17_geoSegmentRomStart, _group17_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_YAY0(0xb, _effect_yay0SegmentRomStart, _effect_yay0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_10), 
	JUMP_LINK(script_func_global_18), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_WARP_PIPE, warp_pipe_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_FAKE_WALL, fake_dirt_wall_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BOMB_ROCK, bomb_rock_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_UNSTABLE_ROCK, unstable_rock_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_SNOWFLAKE, snowflake_geo), 

	AREA(1, bbh_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0B, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BBH, 0x01, 0x0B, WARP_NO_CHECKPOINT),
		WARP_NODE(0x20, LEVEL_BBH, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x80, LEVEL_BBH, 0x02, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x81, LEVEL_BBH, 0x03, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0C, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, -5159, 200, 123, 0, 90, 0, 0x000B0000, bhvAirborneDeathWarp),
		OBJECT(MODEL_NONE, -5159, 200, 123, 0, 90, 0, 0x000A0000, bhvFlyingWarp),
		OBJECT(MODEL_NONE, 5267, 150, 3272, 0, -112, 0, 0x000C0000, bhvFlyingWarp),
		MARIO_POS(0x01, 90, -5159, 200, 123),
		OBJECT(MODEL_BOMB_ROCK, -2215, 0, 2564, 0, 0, 0, 0x00000000, bhvBombRock),
		OBJECT(MODEL_BOMB_ROCK, 5586, 0, 1689, 0, 72, 0, 0x00000000, bhvBombRock),
		OBJECT(MODEL_BOMB_ROCK, 2356, -405, -1413, 0, 162, 0, 0x00010000, bhvBombRock),
		OBJECT(MODEL_CHUCKYA, -1178, 909, -1752, 0, 0, 0, 0x00010000, bhvChuckyaBomb),
		OBJECT(MODEL_CHUCKYA, -38, 1350, -3435, 0, 0, 0, 0x00010000, bhvChuckyaBomb),
		OBJECT(MODEL_CHUCKYA, -1132, 0, 2203, 0, 0, 0, 0x00000000, bhvChuckyaBomb),
		OBJECT(MODEL_CHUCKYA, 3836, 0, 1059, 0, 0, 0, 0x00000000, bhvChuckyaBomb),
		OBJECT(MODEL_STAR_CURRENCY, -4768, 2539, -3297, 0, 0, 0, 0x06000000, bhvStar),
		OBJECT(MODEL_STAR_CURRENCY, -934, 4057, -7156, 0, 0, 0, 0x07000000, bhvStar),
		OBJECT(MODEL_STAR_CURRENCY, 2310, -275, -1450, 0, 0, 0, 0x09000000, bhvStar),
		OBJECT(MODEL_FAKE_WALL, 5591, 0, 3381, 0, -112, 0, 0x00000000, bhvFakeWall),
		OBJECT(MODEL_GREEN_COIN, -1040, 400, 602, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, 518, 1000, 1754, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, 1775, 1300, 2706, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, -3977, 215, -2508, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, -5147, 1839, -1437, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, -1144, 1799, 5038, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, -5305, 2039, -2122, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, -1089, 1799, 4795, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, -24, 700, -94, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, -3557, 2000, 3309, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, -5430, 1839, -1493, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, -5146, 2450, 2833, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, -4698, 2200, 3937, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, -1034, 1799, 4553, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, -5022, 2039, -2066, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, -3291, 338, -2345, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, -2674, 480, -1950, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, -2223, 662, -2273, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, -2020, 728, -2403, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, -1817, 794, -2532, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, -1614, 859, -2662, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, -1112, 1074, -2972, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, -508, 1220, -2279, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, 125, 1380, -2828, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, 357, 1380, -3104, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, 588, 1380, -3380, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, 203, 1528, -4111, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, -266, 1675, -4009, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, -1520, 2035, -4135, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, -712, 2089, -5948, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, -465, 2089, -6051, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, -218, 2089, -6153, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, 209, 3689, -6720, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, 1412, 3586, -6615, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, 2494, 3385, -6497, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, 3342, 3057, -6417, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, 3830, 2420, -6327, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, 4355, 2757, -6060, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, -2355, 0, 2463, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, 5586, 0, 1689, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, 5501, 0, 1973, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, 5666, 0, 1395, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, 5790, 0, 1747, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, 5389, 0, 1592, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, -2125, 0, 2703, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_NONE, -2022, 300, 859, 0, 0, 0, 0x0A000000, bhvHiddenGreenCoinStar),
		OBJECT(MODEL_NONE, -4100, 2950, 2125, 0, 14, 0, 0x00100000, bhvHorizontalPole),
		OBJECT(MODEL_NONE, 1273, 1750, 4986, 0, 89, 0, 0x00100000, bhvHorizontalPole),
		OBJECT(MODEL_NONE, -1753, 2099, 4604, 0, 59, 0, 0x00100000, bhvHorizontalPole),
		OBJECT(MODEL_NONE, 1321, 2489, -5773, 0, 89, 0, 0x00100000, bhvHorizontalPole),
		OBJECT(MODEL_CASTLE_GROUNDS_WARP_PIPE, -4095, 0, -431, 0, 0, 0, 0x00800000, bhvWarpPipe),
		OBJECT(MODEL_CASTLE_GROUNDS_WARP_PIPE, -4028, 0, 136, 0, 0, 0, 0x00810000, bhvWarpPipe),
		OBJECT(MODEL_PURPLE_SWITCH, 6211, 2089, -564, 0, 111, 0, 0x01000000, bhvGenericSwitch),
		OBJECT(MODEL_TOKEN, -1171, 809, 5156, 0, -14, 0, 0x00001900, bhvToken),
		OBJECT(MODEL_NONE, -311, 320, -5575, 0, 0, 0, 0x00000000, bhvWaterfallSoundLoop),
		OBJECT(MODEL_NONE, -793, 2579, -7280, 0, 0, 0, 0x00000000, bhvWaterfallSoundLoop),
		OBJECT(MODEL_GREEN_COIN, -3586, 0, -6494, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, -3164, 0, -6927, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, -2726, 0, -7372, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, 12253, 844, -3587, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, 11578, 985, -3894, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, 10895, 1219, -4205, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, 10439, 1352, -3696, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, 11067, 1241, -2487, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, 10378, 1295, -2128, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, 9711, 1385, -1781, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, 9155, 1536, -2473, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, 8057, 1867, -1328, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, 7674, 1929, -1173, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, 7289, 1992, -1000, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, 10514, 674, -7700, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_NONE, -1823, 250, -8042, 0, -62, 0, 0x00100000, bhvHorizontalPole),
		OBJECT(MODEL_NONE, 1022, -237, -9571, 0, -62, 0, 0x00100000, bhvHorizontalPole),
		OBJECT(MODEL_NONE, 5424, 107, -11027, 0, -152, 0, 0x00100000, bhvHorizontalPole),
		OBJECT(MODEL_NONE, 6711, 590, -8689, 0, -102, 0, 0x00100000, bhvHorizontalPole),
		OBJECT(MODEL_NONE, 12009, 932, -6064, 0, -157, 0, 0x00100000, bhvHorizontalPole),
		TERRAIN(bbh_area_1_collision),
		ROOMS(bbh_area_1_collision_rooms),
		MACRO_OBJECTS(bbh_area_1_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_STONE),
	END_AREA(),

	AREA(2, bbh_area_2),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0B, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BBH, 0x02, 0x0B, WARP_NO_CHECKPOINT),
		WARP_NODE(0x80, LEVEL_BBH, 0x01, 0x0C, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, -684, 200, 0, 0, 90, 0, 0x000B0000, bhvAirborneDeathWarp),
		OBJECT(MODEL_NONE, -684, 200, 0, 0, 90, 0, 0x000A0000, bhvFlyingWarp),
		OBJECT(MODEL_STAR_CURRENCY, 721, 300, 0, 0, 0, 0, 0x0B000000, bhvStar),
		OBJECT(MODEL_STAR_CURRENCY, 1263, 300, 0, 0, 0, 0, 0x0C000000, bhvStar),
		TERRAIN(bbh_area_2_collision),
		ROOMS(bbh_area_2_collision_rooms),
		MACRO_OBJECTS(bbh_area_2_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_STONE),
	END_AREA(),

	AREA(3, bbh_area_3),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0B, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BBH, 0x03, 0x0B, WARP_NO_CHECKPOINT),
		WARP_NODE(0x88, LEVEL_BBH, 0x02, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, 2408, -300, 1559, 0, -110, 0, 0x000B0000, bhvAirborneDeathWarp),
		OBJECT(MODEL_NONE, 2408, -300, 1559, 0, -110, 0, 0x000A0000, bhvFlyingWarp),
		OBJECT(MODEL_GREEN_COIN, 2358, 737, -1251, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, 2316, 570, -1098, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, -2415, -500, 2514, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, -3302, -625, 3537, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, -3068, -625, 3739, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, -3806, -625, 4616, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, -4223, -625, 3337, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, -4143, -625, 2987, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, -5275, -623, 2560, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, -5351, -625, 4259, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, -6863, -625, 1670, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, -5970, -636, 486, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, -4711, -538, 217, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, -5862, -652, 1797, 0, -36, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, -3863, -652, 3775, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, -4898, -584, 390, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, -5055, -610, 675, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, 2275, 404, -945, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, -1787, -500, 2851, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, 2233, 237, -792, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, 2191, 70, -639, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_BOO_COIN, -6981, -635, 516, 0, 0, 0, 0x00000000, bhvBooCoin),
		OBJECT(MODEL_HAUNTED_CAGE, -3054, -500, 2385, 0, 0, 0, 0x00010F00, bhvBooCoinCage),
		OBJECT(MODEL_BOO_COIN, -4930, -652, 1919, 0, -36, 0, 0x00000000, bhvBooCoin),
		OBJECT(MODEL_BOO_COIN, -4624, -652, 4359, 0, 0, 0, 0x00000000, bhvBooCoin),
		OBJECT(MODEL_BOO_COIN, -2990, -625, 4531, 0, -36, 0, 0x00000000, bhvBooCoin),
		OBJECT(MODEL_BOO_COIN, -5118, -525, 3412, 0, 0, 0, 0x00000000, bhvBooCoin),
		OBJECT(MODEL_UNSTABLE_ROCK, -4929, -892, 1919, 0, -36, 0, 0x00000000, bhvUnstableRock),
		OBJECT(MODEL_UNSTABLE_ROCK, -4624, -892, 4359, 0, 0, 0, 0x00000000, bhvUnstableRock),
		OBJECT(MODEL_UNSTABLE_ROCK, -3863, -892, 3775, 0, 0, 0, 0x00000000, bhvUnstableRock),
		OBJECT(MODEL_UNSTABLE_ROCK, -5862, -892, 1797, 0, -36, 0, 0x00000000, bhvUnstableRock),
		OBJECT(MODEL_BLUE_COIN, 7543, 2368, 151, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, 7320, 1941, -857, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, 6642, 1830, -1393, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, 6883, 1926, -2861, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, 6864, 2248, -3996, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, 5056, 2625, -4548, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, 6012, 3220, -5447, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN_SWITCH, 7790, 2202, 471, 0, 0, 0, 0x0B021B00, bhvBlueCoinSwitch),
		OBJECT(MODEL_STAR_CURRENCY, -2041, -200, -632, 0, 0, 0, 0x0D000000, bhvStar),
		OBJECT(MODEL_STAR_CURRENCY, -1738, -200, -50, 0, 0, 0, 0x0E000000, bhvStar),
		OBJECT(MODEL_STAR_CURRENCY, -1845, -200, 677, 0, 0, 0, 0x10000000, bhvStar),
		OBJECT(MODEL_NONE, -1146, -200, 2160, 0, 0, 0, 0x11000000, bhvHiddenGreenCoinStar),
		OBJECT(MODEL_SNOWFLAKE, 3997, 459, 7780, 0, 0, 0, 0x00000000, bhvSnowflake),
		OBJECT(MODEL_SNOWFLAKE, 3343, 573, 7440, 0, 0, 0, 0x00000000, bhvSnowflake),
		OBJECT(MODEL_TOKEN, 3678, 4203, -4392, 0, 60, 0, 0x00011A00, bhvToken),
		TERRAIN(bbh_area_3_collision),
		ROOMS(bbh_area_3_collision_rooms),
		MACRO_OBJECTS(bbh_area_3_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_SNOW),
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 90, -5159, 200, 123),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
