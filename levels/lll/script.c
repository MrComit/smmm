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
#include "levels/lll/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_lll_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _lll_segment_7SegmentRomStart, _lll_segment_7SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _fire_yay0SegmentRomStart, _fire_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0A, _bitfs_skybox_yay0SegmentRomStart, _bitfs_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0B, _effect_yay0SegmentRomStart, _effect_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group2_yay0SegmentRomStart, _group2_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group2_geoSegmentRomStart, _group2_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group15_yay0SegmentRomStart, _group15_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group15_geoSegmentRomStart, _group15_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_3), 
	JUMP_LINK(script_func_global_16), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_WARP_PIPE, warp_pipe_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_CASTLE_DOOR, castle_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CELLAR_BLOCKADE, cellar_blockade_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CHAMPAGNE, champagne_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_SECURITY_CAM, security_cam_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BASEMENT_SWITCH, basement_switch_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BASEMENT_WASHER, basement_washer_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BASEMENT_DRYER, basement_dryer_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CLOTHES_BALL, clothes_ball_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_LAUNDRY_BOUNCE_BOX, laundry_bounce_box_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_DUST_BUNNY, dust_bunny_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_SHIRTS1, laundry_shirts1_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_SHIRTS2, laundry_shirts2_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_SHIRTS3, laundry_shirts3_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_GRAVITY_BUTTON, gravity_button_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_THWOMP_BLOCK, thwomp_block_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_ENGINE_GEAR, engine_gear_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_POWER_DOOR, power_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_ENGINE_GATE, engine_gate_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_ENGINE_LEVER, engine_lever_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_HEAVY_WEIGHT, heavy_weight_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_LEG_PRESS, leg_press_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_EXERCISE_BIKE, exercise_bike_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_SWINGING_PLAT, swinging_plat_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_SAWBLADE, sawblade_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BIG_SWINGING_PLAT, big_swinging_plat_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, lll_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x74, LEVEL_BOB, 0x01, 0x75, WARP_NO_CHECKPOINT),
		WARP_NODE(0x1A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_LLL, 0x01, 0x1A, WARP_NO_CHECKPOINT),
		INSTANT_WARP(0, 0x01, -9987, 610, 3923),
		INSTANT_WARP(1, 0x01, -9004, 610, 10747),
		INSTANT_WARP(2, 0x01, -11120, 214, 10244),
		INSTANT_WARP(3, 0x01, 10187, -552, -3923),
		INSTANT_WARP(4, 0x01, 9004, -552, -11004),
		INSTANT_WARP(5, 0x01, 11109, -155, -10502),
		WARP_NODE(0x31, LEVEL_LLL, 0x01, 0x32, WARP_NO_CHECKPOINT),
		WARP_NODE(0x32, LEVEL_LLL, 0x01, 0x31, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, 812, 84, -4763, 0, -180, 0, (0x1A << 16), bhvAirborneDeathWarp),
		OBJECT(MODEL_NONE, 812, 84, -4763, 0, -180, 0, (0xA << 16), bhvFlyingWarp),
		MARIO_POS(0x01, -180, 812, 84, -4763),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, -429, 0, 8932, 0, 90, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, 3229, 0, 5963, 0, -90, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, -429, 0, 1813, 0, 90, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, 1429, 0, -1187, 0, -90, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, 1429, 0, -5187, 0, -90, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_BASEMENT_SWITCH, 3079, 0, 408, 0, 0, 0, (2 << 16), bhvBasementSwitch),
		OBJECT(MODEL_BASEMENT_SWITCH, 13050, 1180, 7121, 0, -90, 0, (0 << 16), bhvBasementSwitch),
		OBJECT(MODEL_BASEMENT_DRYER, 7949, 0, 13525, 0, -180, 0, (1 << 16), bhvBasementDryer),
		OBJECT(MODEL_BASEMENT_DRYER, 13126, 1131, 11520, 0, -180, 0, (3 << 16), bhvBasementDryer),
		OBJECT(MODEL_BASEMENT_DRYER, 9751, 0, 4244, 0, 90, 0, (2 << 16), bhvBasementDryer),
		OBJECT(MODEL_GOOMBA, 10145, 610, 6453, 0, -180, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_GOOMBA, 9717, 610, 5629, 0, -180, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_GOOMBA, 5187, 0, 11429, 0, -180, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_BOO, 8086, 0, 8516, 0, 0, 0, (0x13 << 16), bhvRoomBoo),
		OBJECT(MODEL_TOKEN, 12746, 448, 7132, 0, -103, 0, (0 << 16) | (0x26 << 8), bhvToken),
		OBJECT(MODEL_BASEMENT_WASHER, 4213, 0, 5460, 0, 0, 0, 0x00000000, bhvBasementWasher),
		OBJECT(MODEL_BASEMENT_DRYER, 3814, 0, 7909, 0, 171, 0, 0x00000000, bhvBasementDryer),
		OBJECT(MODEL_BASEMENT_WASHER, 5365, 0, 13469, 0, 90, 0, (1 << 16), bhvBasementWasher),
		OBJECT(MODEL_BASEMENT_WASHER, 13109, 1131, 11961, 0, 0, 0, (3 << 16), bhvBasementWasher),
		OBJECT(MODEL_BASEMENT_WASHER, 11128, 0, 6466, 0, -90, 0, (2 << 16), bhvBasementWasher),
		OBJECT(MODEL_LAUNDRY_BOUNCE_BOX, 713, -271, 16372, 0, -90, 0, (2 << 24) | (10 << 16), bhvBounceBoxes),
		OBJECT(MODEL_LAUNDRY_BOUNCE_BOX, 1908, -271, 18442, 0, -90, 0, (2 << 24) | (10 << 16), bhvBounceBoxes),
		OBJECT(MODEL_LAUNDRY_BOUNCE_BOX, -4902, -271, 16329, 0, -180, 0, (2 << 24) | (10 << 16), bhvBounceBoxes),
		OBJECT(MODEL_DUST_BUNNY, -5178, -271, 17012, 0, -180, 0, 0x00000000, bhvDustBunny),
		OBJECT(MODEL_DUST_BUNNY, -4758, -271, 15559, 0, -180, 0, 0x00000000, bhvDustBunny),
		OBJECT(MODEL_DUST_BUNNY, 1327, -271, 15883, 0, -180, 0, (1 << 16), bhvDustBunny),
		OBJECT(MODEL_DUST_BUNNY, 126, -271, 16701, 0, -180, 0, (1 << 16), bhvDustBunny),
		OBJECT(MODEL_GOOMBA, -4030, -271, 16750, 0, -180, 0, (1 << 16), bhvGoomba),
		OBJECT(MODEL_GOOMBA, -33, -271, 15800, 0, -180, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_SHYGUY, -12868, 1943, -10595, 0, -90, 0, 0x00000000, bhvBikeShyguy),
		OBJECT(MODEL_EXERCISE_BIKE, -12917, 1700, -10597, 0, 0, 0, 0x00000000, bhvExerciseBike),
		OBJECT(MODEL_TELEPORTER, -13586, 1700, -10665, 0, -90, 0, (0x31 << 16), bhvFadingWarp),
		OBJECT(MODEL_NONE, -2681, 181, 368, 0, 90, 0, (0x32 << 16), bhvFadingWarp),
		OBJECT(MODEL_HEAVY_WEIGHT, -11983, 1242, -6199, 0, 0, 0, 0x00000000, bhvHeavyWeight),
		OBJECT(MODEL_HEAVY_WEIGHT, -14312, -58, 1350, 0, -180, 0, 0x00000000, bhvHeavyWeight),
		OBJECT(MODEL_HEAVY_WEIGHT, -8323, 42, 515, 0, -180, 0, 0x00000000, bhvHeavyWeight),
		OBJECT(MODEL_HEAVY_WEIGHT, -6252, 792, 1599, 0, -180, 0, 0x00000000, bhvHeavyWeight),
		OBJECT(MODEL_NONE, -4867, 733, -6007, 0, 0, 0, 0x00000000, bhvHorizontalPoleNoCol),
		OBJECT(MODEL_NONE, -4867, 1042, -6649, 0, -180, 0, 0x00000000, bhvHorizontalPoleNoCol),
		OBJECT(MODEL_NONE, -4867, 1754, -6649, 0, -180, 0, 0x00000000, bhvHorizontalPoleNoCol),
		OBJECT(MODEL_LEG_PRESS, -1482, 0, 2216, 0, 90, 0, 0x00000000, bhvLegPress),
		OBJECT(MODEL_LEG_PRESS, -11329, 500, 767, 0, 90, 0, (1 << 16), bhvLegPress),
		OBJECT(MODEL_LEG_PRESS, -5807, 2000, -8012, 0, 0, 0, (1 << 24), bhvLegPress),
		OBJECT(MODEL_LEG_PRESS, -10529, 500, 1679, 0, 90, 0, 0x00000000, bhvLegPress),
		OBJECT(MODEL_LEG_PRESS, -5807, 2000, -8462, 0, 0, 0, (1 << 24), bhvLegPress),
		OBJECT(MODEL_LEG_PRESS, -9463, 500, 1477, 0, 0, 0, (1 << 16), bhvLegPress),
		OBJECT(MODEL_LEG_PRESS, -5807, 2000, -8912, 0, 0, 0, (1 << 24), bhvLegPress),
		OBJECT(MODEL_LEG_PRESS, -12394, 500, 1274, 0, 0, 0, 0x00000000, bhvLegPress),
		OBJECT(MODEL_LEG_PRESS, -5807, 2000, -9363, 0, 0, 0, (1 << 24) | (1 << 16), bhvLegPress),
		OBJECT(MODEL_LEG_PRESS, -5807, 2000, -9813, 0, 0, 0, (1 << 24) | (1 << 16), bhvLegPress),
		OBJECT(MODEL_LEG_PRESS, -5807, 2000, -10263, 0, 0, 0, (1 << 24) | (1 << 16), bhvLegPress),
		OBJECT(MODEL_LEG_PRESS, -3475, 0, 2216, 0, 90, 0, (1 << 16), bhvLegPress),
		OBJECT(MODEL_POWER_DOOR, -4529, 2000, 1173, 0, 0, 0, 0x00000000, bhvButtonDoor),
		OBJECT(MODEL_BASEMENT_SWITCH, -4829, 2000, 1173, 0, -90, 0, (1 << 16), bhvBasementSwitch),
		OBJECT(MODEL_TOKEN, -5807, 2211, -10853, 0, 0, 0, (1 << 16) | (0x28 << 8), bhvToken),
		OBJECT(MODEL_TOKEN, -3922, 2256, -4183, 0, 0, 0, (1 << 16) | (0x29 << 8), bhvToken),
		OBJECT(MODEL_CELLAR_BLOCKADE, -2223, 140, 6944, 0, 0, 0, 0x00000000, bhvCellarBlockade),
		OBJECT(MODEL_CHAMPAGNE, -2084, 1536, 7203, 0, -180, 0, 0x00000000, bhvChampagne),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, -2229, 0, 6882, 0, 0, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_ENV_FLAME, -2500, 276, 7071, 0, 90, 0, (42 << 16), bhvFlame),
		OBJECT(MODEL_SECURITY_CAM, -1856, 2466, 6932, 0, 0, 0, 0x00000000, bhvSecurityCam),
		OBJECT(MODEL_SECURITY_CAM, -4729, 866, 11182, 0, -180, 0, (1 << 16), bhvSecurityCam),
		OBJECT(MODEL_SECURITY_CAM, -679, 2266, 3482, 0, 0, 0, (2 << 16), bhvSecurityCam),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, -4279, 0, 4832, 0, 90, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_BASEMENT_SWITCH, -3929, 1729, 6532, 0, 90, 0, (3 << 16), bhvBasementSwitch),
		OBJECT(MODEL_BOO_COIN, -5954, 877, 7957, 0, 90, 0, 0x00000000, bhvBooCoin),
		OBJECT(MODEL_BOO_COIN, -4704, 1500, 6582, 0, 90, 0, 0x00000000, bhvBooCoin),
		OBJECT(MODEL_BOO_COIN, -5880, 0, 4754, 0, 90, 0, 0x00000000, bhvBooCoin),
		OBJECT(MODEL_BOO_COIN, -8213, 0, 2928, 0, 90, 0, 0x00000000, bhvBooCoin),
		OBJECT(MODEL_BOO_COIN, -4979, 0, 6232, 0, 90, 0, 0x00000000, bhvBooCoin),
		OBJECT(MODEL_HAUNTED_CAGE, -4984, 250, 2832, 0, 90, 0, (2 << 16) | (0x13 << 8), bhvBooCoinCage),
		OBJECT(MODEL_BREAKABLE_BOX, -4979, 0, 6232, 0, 90, 0, 0x00000000, bhvBreakableBox),
		OBJECT(MODEL_BREAKABLE_BOX, -4979, 250, 6232, 0, 90, 0, 0x00000000, bhvBreakableBox),
		OBJECT(MODEL_BREAKABLE_BOX, -4979, 0, 6082, 0, 90, 0, 0x00000000, bhvBreakableBox),
		OBJECT(MODEL_BREAKABLE_BOX, -8479, 0, 6232, 0, 90, 0, 0x00000000, bhvBreakableBox),
		OBJECT(MODEL_BREAKABLE_BOX, -6229, 0, 6732, 0, 90, 0, 0x00000000, bhvBreakableBox),
		OBJECT(MODEL_BREAKABLE_BOX, -6229, 200, 6732, 0, 90, 0, 0x00000000, bhvBreakableBox),
		OBJECT(MODEL_BREAKABLE_BOX, -5179, 0, 6732, 0, 90, 0, 0x00000000, bhvBreakableBox),
		OBJECT(MODEL_NONE, -8305, 520, 5647, 0, 90, 0, (100 << 16), bhvPoleGrabbing),
		OBJECT(MODEL_ENGINE_GATE, 2289, 0, -212, 0, 0, 0, 0x00000000, bhvEngineGate),
		OBJECT(MODEL_ENGINE_LEVER, 1629, 200, 1913, 0, -45, 0, 0x00000000, bhvEngineLever),
		OBJECT(MODEL_GLOBAL_GATE, 1469, 0, -1187, 0, 90, 0, 0x00000000, bhvEngineSmallGate),
		OBJECT(MODEL_ENGINE_GEAR, 10213, 346, 1381, 0, 0, 0, (6 << 16), bhvEngineGear),
		OBJECT(MODEL_ENGINE_GEAR, 9825, 313, 2284, 0, 0, 0, (4 << 16), bhvEngineGear),
		OBJECT(MODEL_ENGINE_GEAR, 6575, 402, 1308, 0, 0, 0, (6 << 16), bhvEngineGear),
		OBJECT(MODEL_ENGINE_GEAR, 5906, 305, 2274, 0, 0, 0, (6 << 16), bhvEngineGear),
		OBJECT(MODEL_ENGINE_GEAR, 5249, 228, 1182, 0, 0, 0, (6 << 16), bhvEngineGear),
		OBJECT(MODEL_ENGINE_GEAR, 4304, 0, 1812, 0, 0, 0, (6 << 16), bhvEngineGear),
		OBJECT(MODEL_GRAVITY_BUTTON, 1979, 150, -2062, 0, 0, 0, 0x00000000, bhvGravityButton),
		OBJECT(MODEL_GRAVITY_BUTTON, 9624, 500, -312, 0, -180, 0, 0x00000000, bhvGravityButton),
		OBJECT(MODEL_GRAVITY_BUTTON, 14374, 500, 3488, 0, -180, 0, 0x00000000, bhvGravityButton),
		OBJECT(MODEL_GRAVITY_BUTTON, 8324, 500, 3113, 0, 90, 0, 0x00000000, bhvGravityButton),
		OBJECT(MODEL_GRAVITY_BUTTON, 15124, 500, -1187, 0, -90, 0, 0x00000000, bhvGravityButton),
		OBJECT(MODEL_GRAVITY_BUTTON, 8324, 800, 263, 0, 90, 0, 0x00000000, bhvGravityButton),
		OBJECT(MODEL_GRAVITY_BUTTON, 7824, 800, 2988, 0, -180, 0, 0x00000000, bhvGravityButton),
		OBJECT(MODEL_POWER_DOOR, 5449, 350, -1187, 0, 0, 0, 0x00000000, bhvPowerDoor),
		OBJECT(MODEL_POWER_DOOR, 14374, 350, -212, 0, -90, 0, 0x00000000, bhvPowerDoor),
		OBJECT(MODEL_POWER_DOOR, 8424, 650, 1688, 0, 180, 0, (1 << 16), bhvPowerDoor),
		OBJECT(MODEL_THWOMP_BLOCK, 10374, -400, -1187, 0, 0, 0, (15 << 16), bhvThwompBlock),
		OBJECT(MODEL_THWOMP_BLOCK, 7374, 350, -1187, 0, 0, 0, (1 << 24) | (7 << 16), bhvThwompBlock),
		OBJECT(MODEL_THWOMP_BLOCK, 11124, -400, -1187, 0, 0, 0, (15 << 16), bhvThwompBlock),
		OBJECT(MODEL_THWOMP_BLOCK, 11874, -400, -1187, 0, 0, 0, (15 << 16), bhvThwompBlock),
		OBJECT(MODEL_THWOMP_BLOCK, 13249, -400, 3113, 0, -180, 0, (18 << 16), bhvThwompBlock),
		OBJECT(MODEL_THWOMP_BLOCK, 8874, -400, -1187, 0, 0, 0, (15 << 16), bhvThwompBlock),
		OBJECT(MODEL_THWOMP_BLOCK, 8999, -400, 3113, 0, -180, 0, (1 << 24) | (7 << 16), bhvThwompBlock),
		OBJECT(MODEL_THWOMP_BLOCK, 13249, -400, 1013, 0, -180, 0, (18 << 16), bhvThwompBlock),
		OBJECT(MODEL_THWOMP_BLOCK, 12499, -400, 3113, 0, -180, 0, (18 << 16), bhvThwompBlock),
		OBJECT(MODEL_THWOMP_BLOCK, 12624, -400, -1187, 0, 0, 0, (15 << 16), bhvThwompBlock),
		OBJECT(MODEL_THWOMP_BLOCK, 8999, 650, 1688, 0, -180, 0, (1 << 24) | (7 << 16), bhvThwompBlock),
		OBJECT(MODEL_THWOMP_BLOCK, 11749, -400, 3113, 0, -180, 0, (18 << 16), bhvThwompBlock),
		OBJECT(MODEL_THWOMP_BLOCK, 8999, 650, 263, 0, -180, 0, (1 << 24) | (7 << 16), bhvThwompBlock),
		OBJECT(MODEL_THWOMP_BLOCK, 10999, -400, 3113, 0, -180, 0, (18 << 16), bhvThwompBlock),
		OBJECT(MODEL_THWOMP_BLOCK, 12499, -400, 263, 0, -180, 0, (18 << 16), bhvThwompBlock),
		OBJECT(MODEL_ENGINE_GEAR, 9977, 452, 439, 0, 0, 0, (7 << 16), bhvEngineGear),
		OBJECT(MODEL_TOKEN, 2829, 1442, -462, 0, -180, 0, (1 << 16) | (0x27 << 8), bhvToken),
		OBJECT(MODEL_BIG_SWINGING_PLAT, 11819, 1127, -5757, 0, 0, 0, 0x00000000, bhvBigSwingingPlat),
		OBJECT(MODEL_SWINGING_PLAT, 3966, 382, -4263, 0, 90, 0, 0x00000000, bhvSwingingPlat),
		OBJECT(MODEL_SWINGING_PLAT, 5651, 412, -4774, 0, 0, 0, 0x00000000, bhvSwingingPlat),
		OBJECT(MODEL_SWINGING_PLAT, 7987, 482, -11569, 0, -180, 0, 0x00000000, bhvSwingingPlat),
		OBJECT(MODEL_SWINGING_PLAT, 8012, 482, -9790, 0, -90, 0, 0x00000000, bhvSwingingPlat),
		OBJECT(MODEL_SWINGING_PLAT, 9106, 482, -8844, 0, 90, 0, 0x00000000, bhvSwingingPlat),
		OBJECT(MODEL_SAWBLADE, 6669, 100, -12638, 0, 31, 0, (50 << 24) | (1 << 16) | (0x33 << 8), bhvSawbladeLine),
		OBJECT(MODEL_SAWBLADE, 3487, 107, -11011, 0, -27, 0, (25 << 24) | (0x20 << 8), bhvSawbladeLine),
		OBJECT(MODEL_NONE, 9168, 816, -9508, 0, -90, 0, 0x00000000, bhvSawbladeSpawn),
		OBJECT(MODEL_NONE, 9168, 816, -11376, 0, -90, 0, 0x00000000, bhvSawbladeSpawn),
		OBJECT(MODEL_BASEMENT_SWITCH, 8948, 100, -2722, 0, -180, 0, (4 << 16), bhvBasementSwitch),
		OBJECT(MODEL_TOKEN, 13959, 1234, -6757, 0, 0, 0, (1 << 16) | (0x28 << 8), bhvToken),
		OBJECT(MODEL_SAWBLADE, 6662, 100, -7114, 0, 90, 0, 0x00000000, bhvSawbladeMove),
		OBJECT(MODEL_SAWBLADE, 5016, 100, -7227, 0, 51, 0, (1 << 16), bhvSawbladeMove),
		OBJECT(MODEL_SAWBLADE, 5822, 300, -7378, 0, 6, 0, (50 << 24) | (1 << 16), bhvSawbladeMove),
		OBJECT(MODEL_SAWBLADE, 3321, 250, -10403, 0, -54, 0, (1 << 16), bhvSawbladeMove),
		OBJECT(MODEL_SAWBLADE, 11681, 1705, -8940, 0, 6, 0, (40 << 24) | (1 << 16) | (0x20 << 8), bhvSawbladeMove),
		OBJECT(MODEL_SAWBLADE, 6314, 250, -13232, 0, 6, 0, (30 << 24), bhvSawbladeMove),
		TERRAIN(lll_area_1_collision),
		ROOMS(lll_area_1_collision_rooms),
		MACRO_OBJECTS(lll_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_BASEMENT),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, -180, 812, 84, -4763),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
