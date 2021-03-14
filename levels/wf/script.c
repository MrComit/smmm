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
#include "levels/wf/header.h"

const LevelScript level_wf_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _wf_segment_7SegmentRomStart, _wf_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x0A, _bbh_skybox_yay0SegmentRomStart, _bbh_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _grass_yay0SegmentRomStart, _grass_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group6_yay0SegmentRomStart, _group6_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group6_geoSegmentRomStart, _group6_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group13_yay0SegmentRomStart, _group13_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group13_geoSegmentRomStart, _group13_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_7), 
	JUMP_LINK(script_func_global_14), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_CASTLE_DOOR, castle_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_KEY_DOOR, key_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_WARP_PIPE, warp_pipe_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_HEAVY_OBJECT, heavyobject_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_HEAVY_SWITCH, heavyswitch_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_L2_GATE, l2_gate_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_L2_LAVA, l2_lava_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_LEMON, lemon_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_LIGHTNING, lightning_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_MOVING_VINE, moving_vine_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_LOCKED_CAGE, locked_cage_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_L2_FALLING_FLOOR, l2_falling_floor_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_PIPESEG, pipeseg_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_GUSHING_WATER, gushing_water_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_OCTOPUS, octopus_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_MIRROR_LIGHT, mirror_light_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_MIRROR, mirror_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_MIRROR_SWITCH, mirror_switch_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_LIGHT_BUTTON, light_button_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_L2_FOG, l2_fog_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BLUE_CUSHION, blue_cushion_geo), 

	AREA(1, wf_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x10, LEVEL_BOB, 0x01, 0x0D, WARP_NO_CHECKPOINT),
		WARP_NODE(0x40, LEVEL_WF, 0x01, 0x41, WARP_NO_CHECKPOINT),
		WARP_NODE(0x41, LEVEL_WF, 0x01, 0x40, WARP_NO_CHECKPOINT),
		WARP_NODE(0x11, LEVEL_JRB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, 7647, 200, -17812, 0, 0, 0, 0x000B0000, bhvAirborneDeathWarp),
		OBJECT(MODEL_NONE, 52, 200, -18013, 0, -90, 0, 0x000A0000, bhvFlyingWarp),
		MARIO_POS(0x01, 0, 7647, 200, -17812),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, -4422, 0, -8015, 0, 90, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, 1046, 0, 6589, 0, 180, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, 874, 0, -13084, 0, -90, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, -657, 0, -17953, 0, 90, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, 1031, 0, -4511, 0, 180, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_L2_GATE, 1031, 0, -4811, 0, 180, 0, 0x00020000, bhvL2Gate),
		OBJECT(MODEL_L2_GATE, -42, 0, -11219, 0, 0, 0, 0x00000000, bhvL2Gate),
		OBJECT(MODEL_BREAKABLE_BOX, -1912, 0, -6531, 0, 0, 0, 0x00000000, bhvBreakableBox),
		OBJECT(MODEL_L2_GATE, -4122, 0, -8015, 0, 90, 0, 0x00010000, bhvL2Gate),
		OBJECT(MODEL_L2_GATE, 4546, 387, -5545, 0, -90, 0, 0x00020000, bhvL2Gate),
		OBJECT(MODEL_L2_GATE, 4946, 387, -5545, 0, -90, 0, 0x00000000, bhvL2Gate),
		OBJECT(MODEL_L2_GATE, 574, 0, -13084, 0, -90, 0, 0x00010000, bhvL2Gate),
		OBJECT(MODEL_HEAVY_OBJECT, 3310, -140, -8088, 0, 0, 0, 0x00000000, bhvHeavyObject),
		OBJECT(MODEL_HEAVY_OBJECT, -3337, 50, -5810, 0, 0, 0, 0x00000000, bhvHeavyObject),
		OBJECT(MODEL_HEAVY_OBJECT, 3750, -140, -7787, 0, 0, 0, 0x00000000, bhvHeavyObject),
		OBJECT(MODEL_HEAVY_OBJECT, 3250, -140, -7324, 0, 0, 0, 0x00000000, bhvHeavyObject),
		OBJECT(MODEL_HEAVY_SWITCH, 3310, -190, -8089, 0, 90, 0, 0x00000000, bhvHeavySwitch),
		OBJECT(MODEL_HEAVY_SWITCH, 3735, -190, -7776, 0, 90, 0, 0x00010000, bhvHeavySwitch),
		OBJECT(MODEL_HEAVY_SWITCH, 3245, -190, -7323, 0, 90, 0, 0x00020000, bhvHeavySwitch),
		OBJECT(MODEL_LOCKED_CAGE, -3337, 0, -5810, 0, 0, 0, 0x00020000, bhvLockedCage),
		OBJECT(MODEL_STAR_PIECE, -3141, 307, 11624, 0, 0, 0, 0x05000000, bhvStarPiece),
		OBJECT(MODEL_STAR_PIECE, 5296, 487, -5545, 0, 0, 0, 0x06000000, bhvStarPiece),
		OBJECT(MODEL_L2_LAVA, 1181, -175, 1039, 0, 0, 0, 0x00000000, bhvL2Lava),
		OBJECT(MODEL_LEMON, 1181, -175, 805, 0, 0, 0, 0x01640000, bhvLemon),
		OBJECT(MODEL_LEMON, 1724, -175, 1506, 0, 0, 0, 0x01640000, bhvLemon),
		OBJECT(MODEL_LEMON, 184, -175, 3590, 0, 0, 0, 0x01640000, bhvLemon),
		OBJECT(MODEL_LEMON, 701, -175, 3046, 0, 0, 0, 0x01640000, bhvLemon),
		OBJECT(MODEL_NONE, 1112, -500, 2102, 0, 0, 0, 0x00790000, bhvPoleGrabbing),
		OBJECT(MODEL_NONE, -922, -150, 266, 0, 0, 0, 0x00790000, bhvPoleGrabbing),
		OBJECT(MODEL_NONE, 2734, -500, 5093, 0, 0, 0, 0x00790000, bhvPoleGrabbing),
		OBJECT(MODEL_NONE, 2285, -500, 4397, 0, 0, 0, 0x00790000, bhvPoleGrabbing),
		OBJECT(MODEL_TOKEN, 2573, -230, -1117, 0, 99, 0, 0x00000800, bhvToken),
		OBJECT(MODEL_TOKEN, -1374, 900, 266, 0, 90, 0, 0x00010900, bhvToken),
		OBJECT(MODEL_TOKEN, 2829, 812, 6360, 0, -180, 0, 0x00010A00, bhvToken),
		OBJECT(MODEL_BOO_COIN, -810, 2266, 14226, 0, 0, 0, 0x00000000, bhvBooCoin),
		OBJECT(MODEL_HAUNTED_CAGE, 1738, 2800, 7428, 0, 0, 0, 0x00000200, bhvBooCoinCage),
		OBJECT(MODEL_BOO_COIN, 988, 2266, 15419, 0, 0, 0, 0x00000000, bhvBooCoin),
		OBJECT(MODEL_BOO_COIN, 1073, 2266, 13693, 0, 0, 0, 0x00000000, bhvBooCoin),
		OBJECT(MODEL_BOO_COIN, 1726, 2266, 11666, 0, 0, 0, 0x00000000, bhvBooCoin),
		OBJECT(MODEL_BOO_COIN, 40, 2266, 10736, 0, 0, 0, 0x00000000, bhvBooCoin),
		OBJECT(MODEL_HEART, 3642, 1526, 14263, 0, 0, 0, 0x00000000, bhvRecoveryHeart),
		OBJECT(MODEL_LIGHTNING, 1017, 216, 8638, 0, 0, 0, 0x00000000, bhvLightning),
		OBJECT(MODEL_LIGHTNING, 828, 216, 9617, 0, 0, 0, 0x00010000, bhvLightning),
		OBJECT(MODEL_LIGHTNING, 40, 216, 10736, 0, 0, 0, 0x00010000, bhvLightning),
		OBJECT(MODEL_LIGHTNING, 1049, 216, 10752, 0, 0, 0, 0x00000000, bhvLightning),
		OBJECT(MODEL_LIGHTNING, 1726, 216, 11666, 0, 0, 0, 0x00010000, bhvLightning),
		OBJECT(MODEL_LIGHTNING, 620, 216, 11697, 0, 0, 0, 0x00000000, bhvLightning),
		OBJECT(MODEL_LIGHTNING, 710, 216, 12528, 0, 0, 0, 0x00010000, bhvLightning),
		OBJECT(MODEL_LIGHTNING, 1860, 216, 12591, 0, 0, 0, 0x00000000, bhvLightning),
		OBJECT(MODEL_LIGHTNING, 2003, 216, 13549, 0, 0, 0, 0x00010000, bhvLightning),
		OBJECT(MODEL_LIGHTNING, 1073, 216, 13693, 0, 0, 0, 0x00000000, bhvLightning),
		OBJECT(MODEL_LIGHTNING, -41, 216, 13471, 0, 0, 0, 0x00010000, bhvLightning),
		OBJECT(MODEL_LIGHTNING, -810, 216, 14226, 0, 0, 0, 0x00000000, bhvLightning),
		OBJECT(MODEL_LIGHTNING, 366, 216, 14490, 0, 0, 0, 0x00010000, bhvLightning),
		OBJECT(MODEL_LIGHTNING, -381, 216, 15128, 0, 0, 0, 0x00010000, bhvLightning),
		OBJECT(MODEL_LIGHTNING, 988, 216, 15419, 0, 0, 0, 0x00000000, bhvLightning),
		OBJECT(MODEL_LIGHTNING, -3142, 216, 11631, 0, 0, 0, 0x01010000, bhvLightning),
		OBJECT(MODEL_TOKEN, 3347, 1524, 15780, 0, -180, 0, 0x00000B00, bhvToken),
		OBJECT(MODEL_TOKEN, 3793, 2317, 16781, 90, 0, -180, 0x00020C00, bhvToken),
		OBJECT(MODEL_TOKEN, 4767, 1368, -15298, 90, 0, -180, 0x00010D00, bhvToken),
		OBJECT(MODEL_MOVING_VINE, 1755, 333, 15742, 0, 0, 0, 0x00000000, bhvMovingVine),
		OBJECT(MODEL_MOVING_VINE, 2214, 648, 15222, 0, 4, 0, 0x000A0000, bhvMovingVine),
		OBJECT(MODEL_MOVING_VINE, 3965, 1615, 13222, 0, 80, 0, 0x02070000, bhvMovingVine),
		OBJECT(MODEL_MOVING_VINE, 3717, 859, 15028, 0, -43, 0, 0x04000000, bhvMovingVine),
		OBJECT(MODEL_L2_FALLING_FLOOR, 2073, 0, -13060, 0, 0, 0, 0x00000000, bhvL2FallingFloor),
		OBJECT(MODEL_GOOMBA, 2491, 0, -11969, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_GOOMBA, 4266, 0, -13467, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_GOOMBA, 3231, 0, -13464, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_GOOMBA, 4386, 0, -12214, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_GOOMBA, 4551, 0, -12451, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_OCTOPUS, 3079, 1746, -11509, 0, 0, 0, 0x00000000, bhvOctopus),
		OBJECT(MODEL_OCTOPUS, 924, 285, -14561, 0, -90, 0, 0x00000000, bhvOctopus),
		OBJECT(MODEL_OCTOPUS, 924, 163, -15381, 0, -90, 0, 0x00000000, bhvOctopus),
		OBJECT(MODEL_OCTOPUS, 2557, 334, -16159, 0, 180, 0, 0x00000000, bhvOctopus),
		OBJECT(MODEL_OCTOPUS, 2214, 1250, -16159, 0, 180, 0, 0x00000000, bhvOctopus),
		OBJECT(MODEL_OCTOPUS, 924, 1091, -15633, 0, -90, 0, 0x00000000, bhvOctopus),
		OBJECT(MODEL_OCTOPUS, 3003, 1172, -15167, 90, 0, 0, 0x00000000, bhvOctopus),
		OBJECT(MODEL_PIPESEG, 3424, -2339, -12404, 0, 0, 0, 0x00000000, bhvPipeseg),
		OBJECT(MODEL_L2_FALLING_FLOOR, 2206, 0, -15073, 0, 0, 0, 0x02020000, bhvL2RisingFloor),
		OBJECT(MODEL_L2_FALLING_FLOOR, 4023, 0, -14484, 0, 0, 0, 0x01010000, bhvL2RisingFloor),
		OBJECT(MODEL_L2_FALLING_FLOOR, 3616, 0, -12404, 0, 0, 0, 0x00010000, bhvL2RisingFloor),
		OBJECT(MODEL_BOO, 1404, 139, -13681, 0, 0, 0, 0x01050300, bhvRoomBoo),
		OBJECT(MODEL_SKEETER, 2264, -2456, -13967, 0, -90, 0, 0x00000000, bhvSkeeter),
		OBJECT(MODEL_SKEETER, 1708, -2580, -14363, 0, 90, 0, 0x00000000, bhvSkeeter),
		OBJECT(MODEL_SKEETER, 1139, -2515, -15537, 0, 90, 0, 0x00000000, bhvSkeeter),
		OBJECT(MODEL_SKEETER, 1650, -2515, -14761, 0, -90, 0, 0x00000000, bhvSkeeter),
		OBJECT(MODEL_CASTLE_GROUNDS_WARP_PIPE, 4574, -300, -11870, 0, 0, -180, 0x0A400000, bhvWarpPipe),
		OBJECT(MODEL_NONE, 4574, 1356, -11870, 0, -180, 0, 0x00410100, bhvWarpPipe),
		OBJECT(MODEL_BLUE_CUSHION, -4504, 0, -19682, 0, 23, 0, 0x00010000, bhvCushion),
		OBJECT(MODEL_MIRROR_LIGHT, -5707, 213, -18703, 0, 90, 0, 0x00000000, bhvDenLight),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, -5757, 0, -17953, 0, 90, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_L2_FOG, -3207, 250, -20228, 0, 0, 0, 0x00000000, bhvL2Fog),
		OBJECT(MODEL_NONE, -2524, 107, -18466, 0, 153, 0, 0x00000000, bhvCloud),
		OBJECT(MODEL_NONE, -2846, 107, -19690, 0, 52, 0, 0x00000000, bhvCloud),
		OBJECT(MODEL_NONE, -4478, 107, -19144, 0, 60, 0, 0x00000000, bhvCloud),
		OBJECT(MODEL_NONE, -5050, 0, -18933, 0, -17, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_BOO, -5177, 131, -19810, 0, 0, 0, 0x03060000, bhvRoomBoo),
		OBJECT(MODEL_SWOOP, -5483, 590, -19921, 0, 0, 0, 0x00000000, bhvSwoop),
		OBJECT(MODEL_SWOOP, -5260, 590, -19905, 0, 0, 0, 0x00000000, bhvSwoop),
		OBJECT(MODEL_SWOOP, -5604, 590, -17489, 0, 150, 0, 0x00000000, bhvSwoop),
		OBJECT(MODEL_SWOOP, -1049, 590, -19987, 0, -17, 0, 0x00000000, bhvSwoop),
		OBJECT(MODEL_MIRROR_LIGHT, -9807, 181, -19012, 0, 90, 0, 0x00000000, bhvMirrorLight),
		OBJECT(MODEL_LIGHT_BUTTON, -5807, 213, -18703, 0, -90, 0, 0x00000000, bhvLightButton),
		OBJECT(MODEL_MIRROR, -8415, 0, -19012, 0, 45, 0, 0x00000000, bhvMirror),
		OBJECT(MODEL_MIRROR, -8063, 0, -18773, 0, 90, 0, 0x00020000, bhvMirror),
		OBJECT(MODEL_MIRROR, -9235, 0, -18192, 0, -180, 0, 0x00000000, bhvMirror),
		OBJECT(MODEL_MIRROR, -7482, 0, -18192, 0, -45, 0, 0x00010000, bhvMirror),
		OBJECT(MODEL_MIRROR_SWITCH, -9098, 0, -19644, 0, 0, 0, 0x00010000, bhvMirrorSwitch),
		OBJECT(MODEL_MIRROR_SWITCH, -9448, 0, -19644, 0, 0, 0, 0x00000000, bhvMirrorSwitch),
		OBJECT(MODEL_MIRROR_SWITCH, -8748, 0, -19644, 0, 0, 0, 0x00020000, bhvMirrorSwitch),
		TERRAIN(wf_area_1_collision),
		ROOMS(wf_area_1_collision_rooms),
		MACRO_OBJECTS(wf_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_SPOOKY),
		TERRAIN_TYPE(TERRAIN_STONE),
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, 7647, 200, -17812),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
