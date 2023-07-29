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
#include "levels/sl/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_sl_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _sl_segment_7SegmentRomStart, _sl_segment_7SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _snow_yay0SegmentRomStart, _snow_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0B, _effect_yay0SegmentRomStart, _effect_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0A, _cloud_floor_skybox_yay0SegmentRomStart, _cloud_floor_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group9_yay0SegmentRomStart, _group9_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group9_geoSegmentRomStart, _group9_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group16_yay0SegmentRomStart, _group16_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group16_geoSegmentRomStart, _group16_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_10), 
	JUMP_LINK(script_func_global_17), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_CASTLE_DOOR, castle_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_L10_THIN_BOOK, thin_book_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_L10_PRESSURE_PLATE, l10_pressure_plate_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_PURPLE_CUSHION, purple_cushion_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_L10_GRAVITY_BUTTON, l10_gravity_button_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_L10_BOUNCE_BOX, l10_bounce_box_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_END_STAR, end_star_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BOO_BUBBLE, boo_bubble_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_NEW_TV_STATIC, new_tv_static_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_NEW_REMOTE, new_remote_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_NEW_SHYGUY_GROUP, new_shyguy_group_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_NEW_CHASE_PIECES, new_chase_pieces_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, sl_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0B, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_SL, 0x01, 0x0B, WARP_NO_CHECKPOINT),
		INSTANT_WARP(0, 0x01, 0, 0, 22639),
		OBJECT(MODEL_NONE, 0, 192, 9115, 0, -180, 0, 0x000B0000, bhvAirborneDeathWarp),
		OBJECT(MODEL_NONE, 0, 192, 9115, 0, -180, 0, 0x000A0000, bhvFlyingWarp),
		MARIO_POS(0x01, -180, 0, 192, 9115),
		OBJECT(MODEL_BOO_BUBBLE, -1874, 0, 5012, 0, 0, 0, (19 << 16), bhvBooBubble),
		OBJECT(MODEL_BOO_BUBBLE, 1628, 0, 4793, 0, 0, 0, (18 << 16), bhvBooBubble),
		OBJECT(MODEL_BOO_BUBBLE, 2458, 0, 7654, 0, 0, 0, (17 << 16), bhvBooBubble),
		OBJECT(MODEL_BOO_BUBBLE, 2664, 0, 8668, 0, 0, 0, (16 << 16), bhvBooBubble),
		OBJECT(MODEL_BOO_BUBBLE, 2033, 0, 7276, 0, 0, 0, (15 << 16), bhvBooBubble),
		OBJECT(MODEL_BOO_BUBBLE, 1419, 0, 6661, 0, 0, 0, (14 << 16), bhvBooBubble),
		OBJECT(MODEL_BOO_BUBBLE, -2069, 0, 8038, 0, 0, 0, (13 << 16), bhvBooBubble),
		OBJECT(MODEL_BOO_BUBBLE, -2669, 0, 9502, 0, 0, 0, (12 << 16), bhvBooBubble),
		OBJECT(MODEL_BOO_BUBBLE, -2301, 0, 9896, 0, 0, 0, (11 << 16), bhvBooBubble),
		OBJECT(MODEL_BOO_BUBBLE, -2043, 0, 8888, 0, 0, 0, (10 << 16), bhvBooBubble),
		OBJECT(MODEL_BOO_BUBBLE, -2491, 0, 8452, 0, 0, 0, (9 << 16), bhvBooBubble),
		OBJECT(MODEL_BOO_BUBBLE, 2247, 0, 5832, 0, 0, 0, (8 << 16), bhvBooBubble),
		OBJECT(MODEL_BOO_BUBBLE, -1011, 0, 5443, 0, 0, 0, (7 << 16), bhvBooBubble),
		OBJECT(MODEL_BOO_BUBBLE, 1428, 0, 9915, 0, 0, 0, (6 << 16), bhvBooBubble),
		OBJECT(MODEL_BOO_BUBBLE, -1252, 0, 9299, 0, 0, 0, (5 << 16), bhvBooBubble),
		OBJECT(MODEL_BOO_BUBBLE, 1643, 0, 8904, 0, 0, 0, (4 << 16), bhvBooBubble),
		OBJECT(MODEL_BOO_BUBBLE, -1423, 0, 8552, 0, 0, 0, (3 << 16), bhvBooBubble),
		OBJECT(MODEL_BOO_BUBBLE, 2462, 0, 9699, 0, 0, 0, (2 << 16), bhvBooBubble),
		OBJECT(MODEL_BOO_BUBBLE, 2263, 0, 8279, 0, 0, 0, (1 << 16), bhvBooBubble),
		OBJECT(MODEL_BOO_BUBBLE, -1055, 0, 7869, 0, 0, 0, 0x00000000, bhvBooBubble),
		OBJECT(MODEL_NONE, -75, 350, 4447, 0, 0, 0, (7 << 24), bhvEndCoinCount),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, -3050, 0, 5297, 0, 90, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, 3050, 0, 5297, 0, -90, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_END_STAR, -2900, 680, 6797, 0, 90, 0, 0x00000000, bhvEndStar),
		OBJECT(MODEL_END_STAR, -2900, 530, 7147, 0, 90, 0, (1 << 24), bhvEndStar),
		OBJECT(MODEL_END_STAR, -2900, 530, 6447, 0, 90, 0, (2 << 24), bhvEndStar),
		OBJECT(MODEL_END_STAR, -2900, 380, 7497, 0, 90, 0, (3 << 24), bhvEndStar),
		OBJECT(MODEL_END_STAR, -2900, 380, 6097, 0, 90, 0, (4 << 24), bhvEndStar),
		OBJECT(MODEL_END_STAR, -2900, 1000, 6797, 0, 90, 0, (5 << 24), bhvEndStar),
		OBJECT(MODEL_END_STAR, -2900, 850, 7147, 0, 90, 0, (6 << 24), bhvEndStar),
		OBJECT(MODEL_END_STAR, -2900, 850, 6447, 0, 90, 0, (7 << 24), bhvEndStar),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, -4150, 0, 5297, 0, 90, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, 4150, 0, 5297, 0, -90, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, 2088, 0, 2247, 0, 0, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, -2088, 0, 2247, 0, 0, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, -250, 2500, -3428, 0, 90, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, 3050, -2500, 11597, 0, 90, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_NEW_REMOTE, 8102, 200, 3618, 0, 0, 0, 0x00000000, bhvNewRemote),
		OBJECT(MODEL_L10_THIN_BOOK, 4522, 659, 7125, 0, 0, 0, 0x00000000, bhvSpinningBook),
		OBJECT(MODEL_L10_THIN_BOOK, 5084, 457, 7833, 0, 0, 0, 0x00000000, bhvSpinningBook),
		OBJECT(MODEL_L10_THIN_BOOK, 5426, 792, 7046, 0, 0, 0, 0x00000000, bhvSpinningBook),
		OBJECT(MODEL_L10_THIN_BOOK, 5182, 1155, 6162, 0, 0, 0, 0x00000000, bhvSpinningBook),
		OBJECT(MODEL_L10_THIN_BOOK, 5302, 1055, 4905, 0, 0, 0, 0x00000000, bhvSpinningBook),
		OBJECT(MODEL_L10_THIN_BOOK, 4815, 1355, 4412, 0, 0, 0, 0x00000000, bhvSpinningBook),
		OBJECT(MODEL_L10_THIN_BOOK, 4890, 1455, 3445, 0, 0, 0, 0x00000000, bhvSpinningBook),
		OBJECT(MODEL_L10_THIN_BOOK, 5808, 1505, 3359, 0, 0, 0, 0x00000000, bhvSpinningBook),
		OBJECT(MODEL_L10_THIN_BOOK, 6817, 1405, 4390, 0, 0, 0, 0x00000000, bhvSpinningBook),
		OBJECT(MODEL_L10_THIN_BOOK, 7019, 1755, 4903, 0, 0, 0, 0x00000000, bhvSpinningBook),
		OBJECT(MODEL_L10_THIN_BOOK, 7349, 1555, 5773, 0, -38, 0, 0x00000000, bhvSpinningBook),
		OBJECT(MODEL_L10_THIN_BOOK, 6994, 1405, 6462, 0, -38, 0, 0x00000000, bhvSpinningBook),
		OBJECT(MODEL_L10_THIN_BOOK, 6178, 1105, 6628, 0, -38, 0, 0x00000000, bhvSpinningBook),
		OBJECT(MODEL_NEW_TV_STATIC, 8848, 500, 3618, 0, -90, 0, 0x00000000, bhvNewTVStatic),
		OBJECT(MODEL_L10_BOUNCE_BOX, 2828, -2, -2703, 0, -90, 0, (4 << 24) | (13 << 16), bhvBounceBoxes),
		OBJECT(MODEL_WOODEN_SIGNPOST, 965, 0, -1329, 0, 90, 0, (DIALOG_085 << 16), bhvJukeBox),
		OBJECT(MODEL_NONE, 4946, 1841, -717, 0, 0, 0, 0x00100000, bhvHorizontalPole),
		OBJECT(MODEL_NONE, 4046, 2143, 1009, 0, -90, 0, 0x00100000, bhvHorizontalPole),
		OBJECT(MODEL_L10_THIN_BOOK, 1672, 2289, -3342, 0, 0, 0, 0x00000000, bhvSpinningBook),
		OBJECT(MODEL_L10_THIN_BOOK, 1744, 2639, -3823, 0, 0, 0, 0x00000000, bhvSpinningBook),
		OBJECT(MODEL_L10_THIN_BOOK, 2091, 2919, -4420, 0, 0, 0, 0x00000000, bhvSpinningBook),
		OBJECT(MODEL_L10_THIN_BOOK, 2821, 3156, -3958, 0, 0, 0, 0x00000000, bhvSpinningBook),
		OBJECT(MODEL_L10_THIN_BOOK, 4887, 1906, 1031, 0, 0, 0, 0x00000000, bhvSpinningBook),
		OBJECT(MODEL_NONE, 7993, 135, 6812, 0, -90, 0, (DIALOG_084 << 16), bhvSignOnWall),
		OBJECT(MODEL_CANNON_BASE, -5187, 315, -1115, 0, 0, 0, (0x40 << 16), bhvCannon),
		OBJECT(MODEL_NONE, -5187, 937, -3383, 0, 0, 0, (0x40 << 16), bhvNewShootingGalleryHandler),
		OBJECT(MODEL_L10_GRAVITY_BUTTON, 3000, -2350, 11022, 0, -90, 0, 0x00000000, bhvGravityButton),
		OBJECT(MODEL_NONE, 558, -2907, 11006, 0, -180, 0, 0x00000000, bhvNewJSShyguyManager),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, -3170, 2500, -2903, 0, 90, 0, 0x00000000, bhvDresserDoor),
		OBJECT(MODEL_L10_PRESSURE_PLATE, -952, 2500, -4824, 0, 0, 0, 0x00000000, bhvL10PressurePlate),
		OBJECT(MODEL_PURPLE_CUSHION, -2499, 2500, -1759, 0, 53, 0, (2 << 16), bhvCushion),
		OBJECT(MODEL_PURPLE_CUSHION, -837, 2500, -1749, 0, 125, 0, (2 << 16), bhvCushion),
		OBJECT(MODEL_PURPLE_CUSHION, -1868, 2500, -4657, 0, -55, 0, (2 << 16), bhvCushion),
		OBJECT(MODEL_ENV_FLAME, -383, 3004, -4638, 0, -90, 0, 0x00000000, bhvServantsFlame),
		OBJECT(MODEL_ENV_FLAME, -1455, 3004, -5342, 0, 0, 0, 0x00000000, bhvServantsFlame),
		OBJECT(MODEL_ENV_FLAME, -383, 3004, -2307, 0, -90, 0, 0x00000000, bhvServantsFlame),
		OBJECT(MODEL_ENV_FLAME, -1109, 3004, -1508, 0, 180, 0, 0x00000000, bhvServantsFlame),
		OBJECT(MODEL_ENV_FLAME, -2491, 3004, -1508, 0, 180, 0, 0x00000000, bhvServantsFlame),
		TERRAIN(sl_area_1_collision),
		ROOMS(sl_area_1_collision_rooms),
		MACRO_OBJECTS(sl_area_1_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_STONE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, -180, 0, 192, 9115),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
