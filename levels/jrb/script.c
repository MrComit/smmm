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
#include "levels/jrb/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_jrb_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _jrb_segment_7SegmentRomStart, _jrb_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x0B, _effect_yay0SegmentRomStart, _effect_yay0SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _water_yay0SegmentRomStart, _water_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0A, _bbh_skybox_yay0SegmentRomStart, _bbh_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group4_yay0SegmentRomStart, _group4_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group4_geoSegmentRomStart, _group4_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group14_yay0SegmentRomStart, _group14_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group14_geoSegmentRomStart, _group14_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_5), 
	JUMP_LINK(script_func_global_15), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_CASTLE_DOOR, castle_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_SUNFLOWER, sunflower_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_DIRT_MOUND, dirt_mound_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BOUNCE_BOX, bounce_box_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_POOCHY, poochy_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_FLOWER_WALL, flower_wall_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_L3_SUN, l3_sun_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_SUNBLOCK, sunblock_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_DARK_PIRANHA, dark_piranha_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_STANDING_SUNFLOWER, standing_sunflower_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_SUNFLOWER_PELLET, sunflower_pellet_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_SUNBLOCK_BIG, sunblock_big_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_GARDEN_GATE, garden_gate_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_EXIT_WALL, exit_wall_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_GARDEN_HOLES, garden_holes_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BUCKET_TOP, bucket_top_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, jrb_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		INSTANT_WARP(0, 0x01, 0, 40, -7880),
		INSTANT_WARP(1, 0x01, 0, 0, 8000),
		WARP_NODE(0x0B, LEVEL_JRB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_JRB, 0x01, 0x0B, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0D, LEVEL_BOB, 0x01, 0x72, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0C, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x77, LEVEL_JRB, 0x01, 0x78, WARP_NO_CHECKPOINT),
		WARP_NODE(0x78, LEVEL_JRB, 0x01, 0x77, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, 0, 192, 28972, 0, -180, 0, 0x000B0000, bhvAirborneDeathWarp),
		OBJECT(MODEL_NONE, 0, -230, 0, 0, -180, 0, 0x000A0000, bhvFlyingWarp),
		OBJECT(MODEL_NONE, 2098, -230, 3789, 0, -180, 0, 0x000C0000, bhvFlyingWarp),
		MARIO_POS(0x01, -180, 0, -230, 0),
		OBJECT(MODEL_BUCKET_TOP, -6137, -478, 1162, 0, -110, 0, (2 << 16), bhvBucketTop),
		OBJECT(MODEL_BUCKET_TOP, -662, -478, 3168, 0, 17, 0, (3 << 16), bhvBucketTop),
		OBJECT(MODEL_BUCKET_TOP, -2281, -478, -2120, 0, 17, 0, (4 << 16), bhvBucketTop),
		OBJECT(MODEL_BUCKET_TOP, 2657, -478, -2171, 0, 90, 0, 0x00000000, bhvBucketTop),
		OBJECT(MODEL_BUCKET_TOP, 822, -478, -2171, 0, 116, 0, (1 << 16), bhvBucketTop),
		OBJECT(MODEL_DIRT_MOUND, 776, -488, -1265, 0, 0, 0, 0x00000000, bhvDirtMound),
		OBJECT(MODEL_DIRT_MOUND, 3208, -488, 3931, 0, 0, 0, 0x00000000, bhvDirtMound),
		OBJECT(MODEL_DIRT_MOUND, -1528, -488, 3343, 0, 0, 0, 0x00000000, bhvDirtMound),
		OBJECT(MODEL_DIRT_MOUND, -4637, -488, 2082, 0, 0, 0, 0x00000000, bhvDirtMound),
		OBJECT(MODEL_DIRT_MOUND, -3964, -488, 1100, 0, 0, 0, 0x00000000, bhvDirtMound),
		OBJECT(MODEL_DIRT_MOUND, 3719, -488, 1605, 0, 0, 0, 0x00000000, bhvDirtMound),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, -3630, -488, 4439, 0, -180, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_EXIT_WALL, 2098, -488, 4289, 0, 0, 0, 0x00000000, bhvExitWall),
		OBJECT(MODEL_FLOWER_WALL, -3630, -488, 4289, 0, 0, 0, 0x00000000, bhvFlowerWall),
		OBJECT(MODEL_POOCHY, 1132, 3509, 1206, 0, -90, 0, 0x00000000, bhvPoochyBoss),
		OBJECT(MODEL_SUNFLOWER, -6480, -488, 2215, 0, 0, 0, 0x00000000, bhvSunflower),
		OBJECT(MODEL_SUNFLOWER, -1503, -488, -1749, 0, -60, 0, 0x00000000, bhvSunflower),
		OBJECT(MODEL_SUNFLOWER, 3043, -539, 23, 0, 145, 0, 0x00000000, bhvSunflower),
		OBJECT(MODEL_BROKEN_KEY, -5840, -478, -9469, -90, 12, 0, 0x01080000, bhvBrokenKey),
		OBJECT(MODEL_TELEPORTER, -5016, -488, -8898, 0, 0, 0, 0x00770500, bhvFadingWarp),
		OBJECT(MODEL_NONE, -4159, -288, -126, 0, 59, 0, 0x00780000, bhvFadingWarp),
		OBJECT(MODEL_HEART, -5083, -438, -9680, 0, 0, 0, 0x01080000, bhvRecoveryHeart),
		OBJECT(MODEL_BLUE_COIN, -2004, -3776, -2372, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, -1167, -3776, -2955, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, -2696, -3872, -4061, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, -1566, -3840, -4841, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, -1979, -3872, -3784, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, -897, -3797, -5413, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN_SWITCH, -1681, -3726, -1157, 0, 0, 0, 0x09021000, bhvBlueCoinSwitch),
		OBJECT(MODEL_BOUNCE_BOX, 4137, -2196, -1727, 0, -129, 0, 0x00000000, bhvBounceBoxes),
		OBJECT(MODEL_BOUNCE_BOX, 568, -2196, 3085, 0, -24, 0, 0x00000000, bhvBounceBoxes),
		OBJECT(MODEL_BOUNCE_BOX, -5380, -3726, 2074, 0, -24, 0, 0x00000000, bhvBounceBoxes),
		OBJECT(MODEL_BOUNCE_BOX, -5540, -2196, -1107, 0, -46, 0, 0x00000000, bhvBounceBoxes),
		OBJECT(MODEL_TOKEN, 2785, -2120, -456, 0, 90, 0, 0x00001700, bhvToken),
		OBJECT(MODEL_BREAKABLE_BOX, -6030, -288, 9638, 0, 0, 0, 0x00000000, bhvBreakableBox),
		OBJECT(MODEL_BREAKABLE_BOX, -5830, -288, 9638, 0, 0, 0, 0x00000000, bhvBreakableBox),
		OBJECT(MODEL_BREAKABLE_BOX, -6030, -488, 9638, 0, 0, 0, 0x00000000, bhvBreakableBox),
		OBJECT(MODEL_BREAKABLE_BOX, -5830, -488, 9638, 0, 0, 0, 0x00000000, bhvBreakableBox),
		OBJECT(MODEL_GARDEN_GATE, -3630, -488, 4479, 0, 0, 0, 0x00000000, bhvGardenGate),
		OBJECT(MODEL_NONE, -5619, 782, 6228, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_DARK_PIRANHA, -5193, 782, 9648, 0, 0, 0, 0x00000000, bhvDarkPiranha),
		OBJECT(MODEL_DARK_PIRANHA, -1742, -488, 5962, 0, 0, 0, 0x00000000, bhvDarkPiranha),
		OBJECT(MODEL_DARK_PIRANHA, -2287, -488, 5080, 0, 0, 0, 0x00000000, bhvDarkPiranha),
		OBJECT(MODEL_DARK_PIRANHA, -2507, -488, 5697, 0, 0, 0, 0x00000000, bhvDarkPiranha),
		OBJECT(MODEL_DARK_PIRANHA, -1593, -488, 9993, 0, 0, 0, 0x00000000, bhvDarkPiranha),
		OBJECT(MODEL_DARK_PIRANHA, -4303, -488, 8570, 0, 0, 0, 0x00000000, bhvDarkPiranha),
		OBJECT(MODEL_DARK_PIRANHA, -5032, -488, 10253, 0, 0, 0, 0x00000000, bhvDarkPiranha),
		OBJECT(MODEL_BOO, -1329, -488, 7502, 0, 0, 0, 0x00070000, bhvRoomBoo),
		OBJECT(MODEL_STANDING_SUNFLOWER, -4714, -432, 6034, 0, 71, 0, 0x00000000, bhvStandingSunflower),
		OBJECT(MODEL_STANDING_SUNFLOWER, -4573, -432, 5689, 0, 71, 0, 0x00000000, bhvStandingSunflower),
		OBJECT(MODEL_STANDING_SUNFLOWER, -4461, -432, 5405, 0, 71, 0, 0x00000000, bhvStandingSunflower),
		OBJECT(MODEL_STANDING_SUNFLOWER, -5878, 839, 4852, 0, 8, 0, 0x00000000, bhvStandingSunflower),
		OBJECT(MODEL_STANDING_SUNFLOWER, -4830, 839, 4815, 0, -15, 0, 0x00000000, bhvStandingSunflower),
		OBJECT(MODEL_L3_SUN, -2528, -271, 10126, 0, 0, 0, 0x00000000, bhvL3Sun),
		OBJECT(MODEL_NONE, -3933, -708, 9439, 0, 0, 0, 0x00000000, bhvSunblockBigCol),
		OBJECT(MODEL_NONE, -5143, -708, 8603, 0, 90, 0, 0x00000000, bhvSunblockBigCol),
		OBJECT(MODEL_NONE, -5125, 542, 8148, 0, 0, 0, 0x00000000, bhvSunblockBigCol),
		OBJECT(MODEL_NONE, -4446, -708, 9062, 0, 65, 0, 0x00000000, bhvSunblockBigCol),
		OBJECT(MODEL_NONE, -4742, -728, 7692, 0, 0, 0, 0x00000000, bhvSunblockBigCol),
		OBJECT(MODEL_NONE, -4737, -548, 10369, 0, 0, 0, 0x00000000, bhvSunblockCol),
		OBJECT(MODEL_NONE, -4737, -548, 10129, 0, 0, 0, 0x00000000, bhvSunblockCol),
		OBJECT(MODEL_NONE, -4737, -308, 10369, 0, 0, 0, 0x00000000, bhvSunblockCol),
		OBJECT(MODEL_NONE, -4737, -308, 10129, 0, 0, 0, 0x00000000, bhvSunblockCol),
		OBJECT(MODEL_NONE, -4737, -68, 10369, 0, 0, 0, 0x00000000, bhvSunblockCol),
		OBJECT(MODEL_NONE, -4737, -68, 10129, 0, 0, 0, 0x00000000, bhvSunblockCol),
		OBJECT(MODEL_NONE, -2129, -248, 8505, 0, 0, 0, 0x00000000, bhvSunblockCol),
		OBJECT(MODEL_NONE, -6250, -238, 8655, 0, 0, 0, 0x00000000, bhvSunblockCol),
		OBJECT(MODEL_NONE, -6250, 2, 8655, 0, 0, 0, 0x00000000, bhvSunblockCol),
		OBJECT(MODEL_NONE, -5715, -708, 9282, 0, 0, 0, 0x00000000, bhvSunblockCol),
		OBJECT(MODEL_NONE, -2129, -488, 8505, 0, 0, 0, 0x00000000, bhvSunblockCol),
		OBJECT(MODEL_NONE, -2129, -8, 8505, 0, 0, 0, 0x00000000, bhvSunblockCol),
		OBJECT(MODEL_NONE, -5955, -708, 9282, 0, 0, 0, 0x00000000, bhvSunblockCol),
		OBJECT(MODEL_NONE, -5560, -728, 10247, 0, 0, 0, 0x00000000, bhvSunblockCol),
		OBJECT(MODEL_NONE, -5738, -98, 7952, 0, 0, 0, 0x00000000, bhvSunblockCol),
		OBJECT(MODEL_NONE, -5498, -338, 7952, 0, 0, 0, 0x00000000, bhvSunblockCol),
		OBJECT(MODEL_NONE, -5258, -578, 7952, 0, 0, 0, 0x00000000, bhvSunblockCol),
		OBJECT(MODEL_NONE, -5024, 542, 7544, 0, 0, 0, 0x00000000, bhvSunblockCol),
		OBJECT(MODEL_NONE, -4607, 542, 8840, 0, 0, 0, 0x00000000, bhvSunblockCol),
		OBJECT(MODEL_NONE, -4820, 542, 9140, 0, -26, 0, 0x00000000, bhvSunblockCol),
		OBJECT(MODEL_TOKEN, -6512, -188, 8655, 0, 90, 0, 0x00011100, bhvToken),
		TERRAIN(jrb_area_1_collision),
		ROOMS(jrb_area_1_collision_rooms),
		MACRO_OBJECTS(jrb_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_SPOOKY),
		TERRAIN_TYPE(TERRAIN_STONE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(2, jrb_area_2),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xAB, LEVEL_JRB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, 0, 15000, 0, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		MARIO_POS(0x01, 0, 0, 15000, 0),
		OBJECT(MODEL_BLUE_COIN, 0, 14176, 0, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, -364, 7822, 420, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, -64, 12820, 473, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, -438, 12073, 322, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, -364, 7672, 420, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, -530, 11036, -209, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, 550, 9984, 304, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, 43, 9280, -508, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, -364, 7972, 420, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, -259, 12463, 436, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_NONE, 4893, 16171, -4411, 0, 0, 0, 0x0C020F00, bhvBlueCoinSwitchAuto),
		TERRAIN(jrb_area_2_collision),
		ROOMS(jrb_area_2_collision_rooms),
		MACRO_OBJECTS(jrb_area_2_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_SPOOKY),
		TERRAIN_TYPE(TERRAIN_STONE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, 0, 15000, 0),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
