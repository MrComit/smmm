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
#include "levels/bbh/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_bbh_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _bbh_segment_7SegmentRomStart, _bbh_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x0A, _cloud_floor_skybox_yay0SegmentRomStart, _cloud_floor_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _spooky_yay0SegmentRomStart, _spooky_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group6_yay0SegmentRomStart, _group6_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group6_geoSegmentRomStart, _group6_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group17_yay0SegmentRomStart, _group17_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group17_geoSegmentRomStart, _group17_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_YAY0(0xb, _effect_yay0SegmentRomStart, _effect_yay0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_7), 
	JUMP_LINK(script_func_global_18), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_WARP_PIPE, warp_pipe_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_CASTLE_DOOR, castle_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_FAKE_WALL, fake_dirt_wall_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BOMB_ROCK, bomb_rock_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_UNSTABLE_ROCK, unstable_rock_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_UNSTABLE_ROCK_YELLOW, unstable_rock_yellow_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_SNOWFLAKE, snowflake_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_STALACTITE, stalactite_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_SAND_MOUND, sand_mound_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_SAND_CRAB, sand_crab_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_SNOW_BOX, snow_box_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_SNOW_PILE, snow_pile_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_ICE_CUBE, ice_cube_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_ICE_CUBE_CRACKED, ice_cube_cracked_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_ICE_CUBE_CHUNK, bbh_ice_chunk_geo_000378), 
	LOAD_MODEL_FROM_GEO(MODEL_BOMB_CHAIN, bomb_chain_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

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
		OBJECT(MODEL_SAND_CRAB, 4035, 0, -4875, 0, -40, 0, (2 << 16), bhvSandCrab),
		OBJECT(MODEL_SAND_CRAB, 4485, 0, -4488, 0, -40, 0, (12 << 16), bhvSandCrab),
		OBJECT(MODEL_STAR_CURRENCY, -4768, 2539, -3297, 0, 0, 0, 0x06000000, bhvStar),
		OBJECT(MODEL_STAR_CURRENCY, -934, 4057, -7156, 0, 0, 0, 0x07000000, bhvStar),
		OBJECT(MODEL_STAR_CURRENCY, 2310, -275, -1450, 0, 0, 0, 0x09000000, bhvStar),
		OBJECT(MODEL_FAKE_WALL, 5591, 0, 3381, 0, -112, 0, 0x00000000, bhvFakeWall),
		OBJECT(MODEL_NONE, -1185, 0, -934, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, -1790, 2239, -5520, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, 2279, 1500, 4368, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
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
		OBJECT(MODEL_SAND_MOUND, 3959, 0, -3856, 0, -40, 0, (6 << 16), bhvSandMound),
		OBJECT(MODEL_SAND_MOUND, 3193, 0, -4499, 0, -40, 0, (1 << 24) | (4 << 16), bhvSandMound),
		OBJECT(MODEL_SAND_MOUND, 3897, 0, -4561, 0, -40, 0, (1 << 24) | (1 << 16), bhvSandMound),
		OBJECT(MODEL_SAND_MOUND, 3576, 0, -4178, 0, -40, 0, (1 << 24) | (5 << 16), bhvSandMound),
		OBJECT(MODEL_SAND_MOUND, 4280, 0, -4239, 0, -40, 0, (1 << 24) | (2 << 16), bhvSandMound),
		OBJECT(MODEL_SAND_MOUND, 3514, 0, -4882, 0, -40, 0, (1 << 24), bhvSandMound),
		OBJECT(MODEL_SAND_MOUND, 3255, 0, -3795, 0, -40, 0, (9 << 16), bhvSandMound),
		OBJECT(MODEL_SAND_MOUND, 3638, 0, -3473, 0, -40, 0, (1 << 24) | (10 << 16), bhvSandMound),
		OBJECT(MODEL_SAND_MOUND, 2872, 0, -4116, 0, -40, 0, (1 << 24) | (8 << 16), bhvSandMound),
		OBJECT(MODEL_SAND_MOUND, 4342, 0, -3535, 0, -40, 0, (1 << 24) | (7 << 16), bhvSandMound),
		OBJECT(MODEL_SAND_MOUND, 4663, 0, -3918, 0, -40, 0, (1 << 24) | (3 << 16), bhvSandMound),
		OBJECT(MODEL_SAND_MOUND, 4021, 0, -3152, 0, -40, 0, (1 << 24) | (11 << 16), bhvSandMound),
		OBJECT(MODEL_SAND_MOUND, 2933, 0, -3412, 0, -40, 0, (1 << 24) | (13 << 16), bhvSandMound),
		OBJECT(MODEL_SAND_MOUND, 3316, 0, -3090, 0, -40, 0, (1 << 24) | (14 << 16), bhvSandMound),
		OBJECT(MODEL_SAND_MOUND, 2550, 0, -3733, 0, -40, 0, (1 << 24) | (12 << 16), bhvSandMound),
		OBJECT(MODEL_SAND_MOUND, 3699, 0, -2769, 0, -40, 0, (1 << 24) | (15 << 16), bhvSandMound),
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
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(2, bbh_area_2),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0B, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BBH, 0x02, 0x0B, WARP_NO_CHECKPOINT),
		WARP_NODE(0x80, LEVEL_BBH, 0x01, 0x0C, WARP_NO_CHECKPOINT),
		WARP_NODE(0x8F, LEVEL_BBH, 0x03, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0F, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, -10684, 6200, 0, 0, 90, 0, 0x000B0000, bhvAirborneDeathWarp),
		OBJECT(MODEL_NONE, -10684, 6200, 0, 0, 90, 0, 0x000A0000, bhvFlyingWarp),
		OBJECT(MODEL_NONE, 12668, 4852, 0, 0, -90, 0, 0x000F0000, bhvFlyingWarp),
		OBJECT(MODEL_STAR_CURRENCY, 8318, 6970, 0, 0, 0, 0, 0x0C000000, bhvStar),
		OBJECT(MODEL_MONTY_MOLE, -6394, 1320, 0, 0, 0, 0, 0x00000000, bhvMontyMole),
		OBJECT(MODEL_MONTY_MOLE, -4785, 39, 0, 0, 0, 0, 0x00000000, bhvMontyMole),
		OBJECT(MODEL_MONTY_MOLE, -4467, 1570, 0, 0, 0, 0, 0x00000000, bhvMontyMole),
		OBJECT(MODEL_MONTY_MOLE, -8021, 476, 0, 0, 0, 0, 0x00000000, bhvMontyMole),
		OBJECT(MODEL_MONTY_MOLE, -4350, 592, 0, 0, 0, 0, 0x00000000, bhvMontyMole),
		OBJECT(MODEL_BOO, -5584, 409, 0, 0, 0, 0, 0x050B0B00, bhvRoomBoo),
		OBJECT(MODEL_STALACTITE, -7931, 3671, 0, 0, -36, 0, 0x00000000, bhvStalactite),
		OBJECT(MODEL_STALACTITE, -3000, 4284, 0, 0, 0, 0, 0x00000000, bhvStalactite),
		OBJECT(MODEL_STALACTITE, -6004, 3671, 0, 0, -36, 0, 0x00000000, bhvStalactite),
		OBJECT(MODEL_STALACTITE, 636, 3671, 0, 0, 0, 0, 0x00000000, bhvStalactite),
		OBJECT(MODEL_STALACTITE, 1223, 3671, 0, 0, 0, 0, 0x00000000, bhvStalactite),
		OBJECT(MODEL_STALACTITE, 1815, 3671, 0, 0, 0, 0, 0x00000000, bhvStalactite),
		OBJECT(MODEL_STALACTITE, 7579, 3971, 0, 0, 0, 0, 0x00000000, bhvStalactite),
		OBJECT(MODEL_STALACTITE, 8390, 3971, 0, 0, 0, 0, 0x00000000, bhvStalactite),
		OBJECT(MODEL_STALACTITE, -8920, 5171, 0, 0, -36, 0, 0x00000000, bhvStalactite),
		OBJECT(MODEL_STALACTITE, -9808, 5171, 0, 0, -36, 0, 0x00000000, bhvStalactite),
		OBJECT(MODEL_STALACTITE, 5021, 7389, 0, 0, 0, 0, 0x00000000, bhvStalactite),
		OBJECT(MODEL_STALACTITE, 2942, 7389, 0, 0, 0, 0, 0x00000000, bhvStalactite),
		OBJECT(MODEL_TOKEN, -9704, 1692, 0, 0, 10, 0, 0x00011C00, bhvToken),
		OBJECT(MODEL_UNSTABLE_ROCK_YELLOW, 2033, 6335, 0, 0, -36, 0, 0x00000000, bhvUnstableRock),
		OBJECT(MODEL_UNSTABLE_ROCK_YELLOW, 2672, 6335, 0, 0, -36, 0, 0x00000000, bhvUnstableRock),
		OBJECT(MODEL_UNSTABLE_ROCK_YELLOW, 3479, 6335, 0, 0, -36, 0, 0x00000000, bhvUnstableRock),
		OBJECT(MODEL_UNSTABLE_ROCK_YELLOW, 4833, 6335, 0, 0, 19, 0, 0x00000000, bhvUnstableRock),
		OBJECT(MODEL_UNSTABLE_ROCK_YELLOW, 5671, 6335, 0, 0, -34, 0, 0x00000000, bhvUnstableRock),
		TERRAIN(bbh_area_2_collision),
		ROOMS(bbh_area_2_collision_rooms),
		MACRO_OBJECTS(bbh_area_2_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_STONE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(3, bbh_area_3),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0B, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BBH, 0x03, 0x0B, WARP_NO_CHECKPOINT),
		WARP_NODE(0x88, LEVEL_BBH, 0x02, 0x0F, WARP_NO_CHECKPOINT),
		WARP_NODE(0x91, LEVEL_BBH, 0x03, 0x92, WARP_NO_CHECKPOINT),
		WARP_NODE(0x92, LEVEL_BBH, 0x03, 0x91, WARP_NO_CHECKPOINT),
		WARP_NODE(0x93, LEVEL_BBH, 0x03, 0x94, WARP_NO_CHECKPOINT),
		WARP_NODE(0x94, LEVEL_BBH, 0x03, 0x93, WARP_NO_CHECKPOINT),
		INSTANT_WARP(0x1, 0x03, 0, 10000, 0),
		INSTANT_WARP(0x2, 0x03, 0, -10000, 0),
		OBJECT(MODEL_NONE, 2408, -300, 1559, 0, -110, 0, 0x000B0000, bhvAirborneDeathWarp),
		OBJECT(MODEL_NONE, 2408, -300, 1559, 0, -110, 0, 0x000A0000, bhvFlyingWarp),
		OBJECT(MODEL_GREEN_COIN, 2358, 737, -1251, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, 2316, 570, -1098, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, -4311, 4796, -7768, 0, 0, 0, 0x00000000, bhvGreenCoin),
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
		OBJECT(MODEL_GREEN_COIN, 6172, 269, 5177, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, 2233, 237, -792, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, 2191, 70, -639, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, -5765, 4697, -6969, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, -5976, 4649, -6706, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, -6187, 4602, -6443, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, -4791, 3723, -2941, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, 6483, 529, 4960, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, 6850, 701, 4662, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, 7405, 1245, 4318, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, 311, 2728, -376, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, 4914, 1867, 3866, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, 4798, 1841, 4174, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, 4681, 1815, 4481, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, -29, 1422, 5880, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, -627, 1374, 6449, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, -926, 1350, 6733, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, -1475, 1319, 7267, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, -5149, 1175, 7452, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, -5475, 1166, 7261, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, -8481, 121, 3012, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, -8760, 36, 2238, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, -9040, -49, 1463, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, -9746, -387, -802, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, -9982, -500, -1558, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, 7128, 973, 4490, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, -2356, -335, -5087, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, -1643, -142, -5598, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, -2190, 44, -6213, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, -3079, 232, -6194, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, -3328, 561, -5452, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, -2496, 741, -4693, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, -1421, 861, -4902, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, -1651, 1228, -5607, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, -2433, 1400, -6300, 0, 7, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, -2940, 1400, -6241, 0, 7, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, 404, 1500, -5476, 0, -25, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, 557, 1500, -5805, 0, -25, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, -5572, 2019, -5896, 0, -25, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, -5444, 2019, -5366, 0, -25, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, -5669, 2019, -4832, 0, -25, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, -5960, 2019, -5529, 0, -25, 0, 0x00000000, bhvGreenCoin),
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
		OBJECT(MODEL_BLUE_COIN, 6642, 1888, -1393, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, 6883, 1926, -2861, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, 6864, 2248, -3996, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, 5056, 2625, -4548, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, 6012, 3220, -5447, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN_SWITCH, 7790, 2202, 471, 0, 0, 0, 0x0B021B00, bhvBlueCoinSwitch),
		OBJECT(MODEL_STAR_CURRENCY, -518, 1178, 15884, 0, 0, 0, 0x0D000000, bhvStar),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, 2289, 1500, -4483, 0, -25, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_TELEPORTER, -301, 878, 16464, 0, 0, 0, 0x00910000, bhvFadingWarp),
		OBJECT(MODEL_NONE, -7164, -200, -3090, 0, -175, 0, 0x00940000, bhvFadingWarp),
		OBJECT(MODEL_NONE, 4933, 639, 6448, 0, 90, 0, 0x00920000, bhvFadingWarp),
		OBJECT(MODEL_NONE, -314, -500, 3509, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, -57, 1500, -2874, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, -4123, 1817, -4394, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, 7542, 1849, -2332, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, -1146, -200, 2160, 0, 0, 0, 0x11000000, bhvHiddenGreenCoinStar),
		OBJECT(MODEL_SNOW_BOX, -2685, 2230, -8541, 0, 20, 0, (1 << 24) | (16 << 16), bhvBounceBoxes),
		OBJECT(MODEL_SNOWFLAKE, 4430, 462, 7376, 0, -27, 0, 0x01000000, bhvSnowflake),
		OBJECT(MODEL_SNOWFLAKE, 3970, 562, 8264, 0, -27, 0, 0x00000000, bhvSnowflake),
		OBJECT(MODEL_SNOWFLAKE, 3082, 562, 7804, 0, -27, 0, 0x00010000, bhvSnowflake),
		OBJECT(MODEL_SNOWFLAKE, 3477, 862, 11388, 0, -27, 0, 0x00010000, bhvSnowflake),
		OBJECT(MODEL_SNOWFLAKE, 2589, 862, 10928, 0, -27, 0, 0x00010000, bhvSnowflake),
		OBJECT(MODEL_SNOWFLAKE, 1702, 862, 10468, 0, -27, 0, 0x00000000, bhvSnowflake),
		OBJECT(MODEL_SNOWFLAKE, 814, 862, 10008, 0, -27, 0, 0x00010000, bhvSnowflake),
		OBJECT(MODEL_SNOWFLAKE, 2925, 862, 12453, 0, -27, 0, 0x00000000, bhvSnowflake),
		OBJECT(MODEL_SNOWFLAKE, 2037, 862, 11993, 0, -27, 0, 0x00000000, bhvSnowflake),
		OBJECT(MODEL_SNOWFLAKE, 1150, 862, 11533, 0, -27, 0, 0x00010000, bhvSnowflake),
		OBJECT(MODEL_SNOWFLAKE, 262, 862, 11073, 0, -27, 0, 0x00010000, bhvSnowflake),
		OBJECT(MODEL_SNOWFLAKE, 2373, 862, 13519, 0, -27, 0, 0x00000000, bhvSnowflake),
		OBJECT(MODEL_SNOWFLAKE, 1485, 862, 13059, 0, -27, 0, 0x00010000, bhvSnowflake),
		OBJECT(MODEL_SNOWFLAKE, 597, 862, 12599, 0, -27, 0, 0x00000000, bhvSnowflake),
		OBJECT(MODEL_SNOWFLAKE, -290, 862, 12138, 0, -27, 0, 0x00000000, bhvSnowflake),
		OBJECT(MODEL_SNOWFLAKE, 1821, 862, 14584, 0, -27, 0, 0x00010000, bhvSnowflake),
		OBJECT(MODEL_SNOWFLAKE, 933, 862, 14124, 0, -27, 0, 0x00010000, bhvSnowflake),
		OBJECT(MODEL_SNOWFLAKE, 45, 862, 13664, 0, -27, 0, 0x00010000, bhvSnowflake),
		OBJECT(MODEL_SNOWFLAKE, -843, 862, 13204, 0, -27, 0, 0x00000000, bhvSnowflake),
		OBJECT(MODEL_SNOWFLAKE, 1269, 862, 15650, 0, -27, 0, 0x00010000, bhvSnowflake),
		OBJECT(MODEL_SNOWFLAKE, 381, 862, 15190, 0, -27, 0, 0x00000000, bhvSnowflake),
		OBJECT(MODEL_SNOWFLAKE, -507, 862, 14729, 0, -27, 0, 0x00000000, bhvSnowflake),
		OBJECT(MODEL_SNOWFLAKE, -1395, 862, 14269, 0, -27, 0, 0x00010000, bhvSnowflake),
		OBJECT(MODEL_SNOWFLAKE, 3050, 762, 10040, 0, -27, 0, 0x00010000, bhvSnowflake),
		OBJECT(MODEL_SNOWFLAKE, 2162, 762, 9580, 0, -27, 0, 0x00000000, bhvSnowflake),
		OBJECT(MODEL_SNOWFLAKE, 1274, 762, 9120, 0, -27, 0, 0x00000000, bhvSnowflake),
		OBJECT(MODEL_SNOWFLAKE, 3510, 662, 9152, 0, -27, 0, 0x00010000, bhvSnowflake),
		OBJECT(MODEL_SNOWFLAKE, 2622, 662, 8692, 0, -27, 0, 0x00000000, bhvSnowflake),
		OBJECT(MODEL_SNOW_PILE, -2081, 1500, -2905, 0, -109, 0, (1 << 24) | (15 << 16), bhvSnowPile),
		OBJECT(MODEL_TOKEN, 3678, 4203, -4392, 0, 60, 0, 0x00011A00, bhvToken),
		OBJECT(MODEL_STAR_CURRENCY, -233, -3070, 1861, 0, 0, 0, 0x0E000000, bhvStar),
		OBJECT(MODEL_TELEPORTER, -655, -3370, 2198, 0, 0, 0, 0x00930000, bhvFadingWarp),
		OBJECT(MODEL_BOMB_CHAIN, 2671, 14852, -10540, 0, 90, 0, 0x00000000, bhvBombChain),
		OBJECT(MODEL_BOMB_CHAIN, 4471, 14852, -10540, 0, -90, 0, (4 << 16), bhvBombChain),
		OBJECT(MODEL_BOMB_CHAIN, 3271, 14852, -10540, 0, 90, 0, (4 << 16), bhvBombChain),
		OBJECT(MODEL_BOMB_CHAIN, 3871, 14852, -10540, 0, 90, 0, (8 << 16), bhvBombChain),
		OBJECT(MODEL_BOMB_CHAIN, 5071, 14852, -10540, 0, 90, 0, (0 << 16), bhvBombChain),
		OBJECT(MODEL_BOMB_CHAIN, 5671, 14852, -10540, 0, -90, 0, (4 << 16), bhvBombChain),
		OBJECT(MODEL_BOMB_CHAIN, 1315, 15450, -13240, 0, 90, 0, (4 << 16), bhvBombChain),
		OBJECT(MODEL_BOMB_CHAIN, 1765, 15450, -13240, 0, 90, 0, (0 << 16), bhvBombChain),
		OBJECT(MODEL_BOMB_CHAIN, 2665, 15450, -13240, 0, -90, 0, (4 << 16), bhvBombChain),
		OBJECT(MODEL_BOMB_CHAIN, 3565, 15450, -13240, 0, 90, 0, (8 << 16), bhvBombChain),
		OBJECT(MODEL_BOMB_CHAIN, 4015, 15450, -13240, 0, -90, 0, (4 << 16), bhvBombChain),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, 2310, 11500, -4529, 0, -25, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_ICE_CUBE, 5178, 11470, -11585, 0, 0, 0, 0x00000000, bhvIceCube),
		OBJECT(MODEL_ICE_CUBE, 2487, 11470, -9956, 0, 0, 0, 0x00000000, bhvIceCube),
		OBJECT(MODEL_ICE_CUBE, 5177, 11470, -9036, 0, 0, 0, 0x00000000, bhvIceCube),
		OBJECT(MODEL_ICE_CUBE, 3452, 11470, -9036, 0, 0, 0, 0x00000000, bhvIceCube),
		OBJECT(MODEL_ICE_CUBE_CRACKED, 195, 11950, -8282, 0, 0, 0, 0x00000000, bhvIceCubeCracked),
		OBJECT(MODEL_ICE_CUBE_CRACKED, -79, 12000, -10540, 0, 0, 0, 0x00000000, bhvIceCubeCracked),
		OBJECT(MODEL_ICE_CUBE_CRACKED, 195, 11950, -7382, 0, 0, 0, 0x00000000, bhvIceCubeCracked),
		OBJECT(MODEL_ICE_CUBE_CRACKED, 195, 11950, -7832, 0, 0, 0, 0x00000000, bhvIceCubeCracked),
		OBJECT(MODEL_ICE_CUBE_CRACKED, -529, 12000, -10540, 0, 0, 0, 0x00000000, bhvIceCubeCracked),
		OBJECT(MODEL_ICE_CUBE_CRACKED, 6265, 12550, -10990, 0, 0, 0, 0x00000000, bhvIceCubeCracked),
		OBJECT(MODEL_ICE_CUBE_CRACKED, 6265, 12700, -11890, 0, 0, 0, 0x00000000, bhvIceCubeCracked),
		OBJECT(MODEL_ICE_CUBE_CRACKED, 6265, 12700, -12790, 0, 0, 0, 0x00000000, bhvIceCubeCracked),
		OBJECT(MODEL_ICE_CUBE_CRACKED, 3565, 13000, -13240, 0, 0, 0, 0x00000000, bhvIceCubeCracked),
		OBJECT(MODEL_ICE_CUBE_CRACKED, 3115, 13000, -13240, 0, 0, 0, 0x00000000, bhvIceCubeCracked),
		OBJECT(MODEL_ICE_CUBE_CRACKED, 2215, 13000, -13240, 0, 0, 0, 0x00000000, bhvIceCubeCracked),
		OBJECT(MODEL_ICE_CUBE_CRACKED, 1315, 13000, -13240, 0, 0, 0, 0x00000000, bhvIceCubeCracked),
		OBJECT(MODEL_BOO, 2742, 11993, -16735, 0, 0, 0, (5 << 24) | (0xC << 16) | (0x10 << 8), bhvRoomBoo),
		TERRAIN(bbh_area_3_collision),
		ROOMS(bbh_area_3_collision_rooms),
		MACRO_OBJECTS(bbh_area_3_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_SNOW),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 90, -5159, 200, 123),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
