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
#include "levels/ssl/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_ssl_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _ssl_segment_7SegmentRomStart, _ssl_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x0A, _CUSTOM_L8_skybox_yay0SegmentRomStart, _CUSTOM_L8_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _generic_yay0SegmentRomStart, _generic_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group9_yay0SegmentRomStart, _group9_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group9_geoSegmentRomStart, _group9_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_YAY0(0xb, _effect_yay0SegmentRomStart, _effect_yay0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_10), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_CASTLE_DOOR, castle_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_KEY_DOOR, key_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_PAINTING_ENEMY, painting_enemy_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BG_GOOMBA, boogoo_goomba_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BG_KOOPA, boogoo_koopa_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BG_SHYGUY, boogoo_shyguy_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_PAINTBRUSH, paintbrush_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_PAINTING_BRICK, painting_brick_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CAGE_GOO, cage_goo_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, ssl_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x1A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_SSL, 0x01, 0x1A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, -19963, 2268, 7480, 0, -180, 0, (0x1A << 16), bhvAirborneDeathWarp),
		OBJECT(MODEL_NONE, -19963, 2268, 7480, 0, -180, 0, (0xA << 16), bhvFlyingWarp),
		MARIO_POS(0x01, -180, -19963, 2268, 7480),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, -19963, 2068, 7128, 0, 0, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_PEEPA, -18913, 1307, 19110, 0, -90, 0, (1 << 24), bhvFloorPeepa),
		OBJECT(MODEL_PEEPA, -18913, 1107, 19110, 0, -90, 0, (1 << 16), bhvFloorPeepa),
		OBJECT(MODEL_PEEPA, -18913, 907, 19110, 0, -90, 0, (2 << 16), bhvFloorPeepa),
		OBJECT(MODEL_PEEPA, -19590, 1752, 16965, 0, -90, 0, 0x00000000, bhvFloorPeepa),
		OBJECT(MODEL_PEEPA, -19590, 1552, 16965, 0, -90, 0, (1 << 16), bhvFloorPeepa),
		OBJECT(MODEL_PEEPA, -19590, 1352, 16965, 0, -90, 0, (2 << 16), bhvFloorPeepa),
		OBJECT(MODEL_PEEPA, -21306, 1752, 15347, 0, -90, 0, 0x00000000, bhvFloorPeepa),
		OBJECT(MODEL_PEEPA, -21306, 1552, 15347, 0, -90, 0, (1 << 16), bhvFloorPeepa),
		OBJECT(MODEL_PEEPA, -21306, 1352, 15347, 0, -90, 0, (2 << 16), bhvFloorPeepa),
		OBJECT(MODEL_PEEPA, -19659, 2268, 12723, 0, -90, 0, 0x00000000, bhvFloorPeepa),
		OBJECT(MODEL_PEEPA, -19659, 2068, 12723, 0, -90, 0, (1 << 16), bhvFloorPeepa),
		OBJECT(MODEL_PEEPA, -19659, 1868, 12723, 0, -90, 0, (2 << 16), bhvFloorPeepa),
		OBJECT(MODEL_PEEPA, -19720, 2268, 10759, 0, -90, 0, 0x00000000, bhvFloorPeepa),
		OBJECT(MODEL_PEEPA, -19720, 2068, 10759, 0, -90, 0, (1 << 16), bhvFloorPeepa),
		OBJECT(MODEL_PEEPA, -19720, 1868, 10759, 0, -90, 0, (2 << 16), bhvFloorPeepa),
		OBJECT(MODEL_STAR_PIECE, -21279, 150, 25775, 0, 0, 0, (0x15 << 24), bhvStarPiece),
		OBJECT(MODEL_STAR_PIECE, -21772, 150, 25775, 0, 0, 0, (0x16 << 24), bhvStarPiece),
		OBJECT(MODEL_STAR_PIECE, -22234, 150, 25775, 0, 0, 0, (0x17 << 24), bhvStarPiece),
		OBJECT(MODEL_STAR_PIECE, -22589, 150, 25775, 0, 0, 0, (0x18 << 24), bhvStarPiece),
		OBJECT(MODEL_HAUNTED_CAGE, -19321, 2068, 1313, 0, 180, 0, (20 << 16), bhvBoogooCage),
		OBJECT(MODEL_PAINTBRUSH, -24339, 2289, 3585, 0, 0, 0, 0x00000000, bhvPaintbrush),
		OBJECT(MODEL_PAINTING_BRICK, -22054, 2672, 617, 0, 0, 0, (80 << 24), bhvPaintingBrick),
		OBJECT(MODEL_PAINTING_BRICK, -21158, 2865, 617, 0, 0, 0, (110 << 24) | (1 << 16), bhvPaintingBrick),
		OBJECT(MODEL_PAINTING_BRICK, -20000, 3159, 1103, 0, 90, 0, (60 << 24) | (2 << 16), bhvPaintingBrick),
		OBJECT(MODEL_PAINTING_BRICK, -18642, 3159, 1103, 0, -90, 0, (105 << 24) | (3 << 16), bhvPaintingBrick),
		OBJECT(MODEL_PAINTING_BRICK, -17471, 3304, 1617, 0, 0, 0, (4 << 16), bhvPaintingBrick),
		OBJECT(MODEL_PAINTING_BRICK, -17002, 3479, 2497, 0, -90, 0, (5 << 16), bhvPaintingBrick),
		OBJECT(MODEL_PAINTING_BRICK, -17002, 3406, 3455, 0, -90, 0, (140 << 24) | (6 << 16), bhvPaintingBrick),
		OBJECT(MODEL_PAINTING_BRICK, -17002, 3726, 3943, 0, -90, 0, (7 << 16), bhvPaintingBrick),
		OBJECT(MODEL_PAINTING_BRICK, -17002, 4239, 4740, 0, -90, 0, (160 << 24) | (8 << 16), bhvPaintingBrick),
		OBJECT(MODEL_PAINTING_BRICK, -17002, 3429, 4810, 0, -90, 0, (140 << 24) | (8 << 16), bhvPaintingBrick),
		OBJECT(MODEL_PAINTING_BRICK, -17002, 3266, 5622, 0, -90, 0, (100 << 24) | (9 << 16), bhvPaintingBrick),
		OBJECT(MODEL_PAINTING_BRICK, -17002, 4079, 4740, 0, -90, 0, (160 << 24) | (8 << 16), bhvPaintingBrick),
		OBJECT(MODEL_PAINTING_ENEMY, -17463, 3955, 7078, 0, 0, 0, 0x00000000, bhvPaintingEnemy),
		OBJECT(MODEL_PAINTING_ENEMY, -17963, 2467, 6290, 0, 90, 0, 0x00000000, bhvPaintingEnemy),
		OBJECT(MODEL_PAINTING_ENEMY, -22963, 2467, 5533, 0, -90, 0, 0x00000000, bhvPaintingEnemy),
		OBJECT(MODEL_PAINTING_ENEMY, -16963, 2467, 2230, 0, 90, 0, (1 << 16), bhvPaintingEnemy),
		OBJECT(MODEL_PAINTING_ENEMY, -16963, 2467, 3767, 0, 90, 0, (1 << 16), bhvPaintingEnemy),
		OBJECT(MODEL_PAINTING_ENEMY, -16963, 2467, 2847, 0, 90, 0, (1 << 16), bhvPaintingEnemy),
		OBJECT(MODEL_PAINTING_ENEMY, -22963, 2467, 6790, 0, -90, 0, 0x00000000, bhvPaintingEnemy),
		OBJECT(MODEL_PAINTING_ENEMY, -24463, 2467, 3413, 0, -90, 0, (2 << 16), bhvPaintingEnemyRespawn),
		OBJECT(MODEL_NONE, -19321, 3289, 628, 0, 0, 0, 0x00000000, bhvPaintingTeleport),
		OBJECT(MODEL_NONE, -21525, 2220, 7228, 0, -180, 0, (1 << 16), bhvPaintingTeleport),
		OBJECT(MODEL_SHYGUY, -24339, 2213, 3630, 0, -180, 0, 0x00000000, bhvShyguyPainter),
		OBJECT(MODEL_STAR_PIECE, -19948, 2018, 4299, 0, 0, 0, (0x14 << 24), bhvStarPiece),
		TERRAIN(ssl_area_1_collision),
		ROOMS(ssl_area_1_collision_rooms),
		MACRO_OBJECTS(ssl_area_1_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_STONE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, -180, -19963, 2268, 7480),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
