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
	LOAD_YAY0(0x06, _group15_yay0SegmentRomStart, _group15_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group15_geoSegmentRomStart, _group15_geoSegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_YAY0(0xb, _effect_yay0SegmentRomStart, _effect_yay0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_10), 
	JUMP_LINK(script_func_global_16), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_CASTLE_DOOR, castle_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_KEY_DOOR, key_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_PAINTING_ENEMY, painting_enemy_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BG_GOOMBA, boogoo_goomba_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BG_KOOPA, boogoo_koopa_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BG_SHYGUY, boogoo_shyguy_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_PAINTBRUSH, paintbrush_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_PAINTING_BRICK, painting_brick_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CAGE_GOO, cage_goo_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_AG_BOOGOO, ag_boogoo_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BG_ASTEROID, bg_asteroid_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_O2_BOOGOO, o2_boogoo_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_SPINNING_PLAT, spinning_plat_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BIG_SPINNING_PLAT, big_spinning_plat_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_ANTENNA_BALL, antenna_ball_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_SUNCUBE, suncube_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_LAB_BOOGOO, lab_bg_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_O1_BOOGOO, o1_bg_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_MIND_MOUND, mind_mound_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_MIND_MOUND_BLOCK, mind_mound_block_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_MIND_MIPS, mind_mips_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_L8_LOCKED_CAGE, l8_locked_cage_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_MIND_LEVER, mind_lever_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_MP_BOOGOO, mp_boogoo_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_MIND_2D_GOOMBA, mind_2d_goomba_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_MIND_2D_GATE, mind_2d_gate_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_MIND_BUTTON, mind_button_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_MAZE_WINS, maze_wins_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_YOSHI_HEAD, yoshi_head_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_OBSERVATORY_SPLAT, observatory_splat_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_JENGA_PLAT, jenga_plat_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, ssl_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x1A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_SSL, 0x01, 0x1A, WARP_NO_CHECKPOINT),
		INSTANT_WARP(0, 0x02, -22500, 0, 10000),
		OBJECT(MODEL_NONE, -1358, 6347, -11675, 0, 90, 0, (0x1A << 16), bhvAirborneDeathWarp),
		OBJECT(MODEL_NONE, -1358, 6347, -11675, 0, 90, 0, (0xA << 16), bhvFlyingWarp),
		MARIO_POS(0x01, 90, -1358, 6347, -11675),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, -19963, 2068, 7128, 0, 0, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_O1_BOOGOO, -20163, 157, 25243, 0, 0, 0, (3 << 16), bhvBoogooObjectNoCage),
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
		OBJECT(MODEL_STAR_PIECE, -20200, 157, 25259, 0, 0, 0, (0x14 << 24), bhvStarPiece),
		OBJECT(MODEL_STAR_PIECE, -22234, 150, 25775, 0, 0, 0, (0x17 << 24), bhvStarPiece),
		OBJECT(MODEL_STAR_PIECE, -22589, 150, 25775, 0, 0, 0, (0x18 << 24), bhvStarPiece),
		OBJECT(MODEL_AG_BOOGOO, -19732, 2274, 4079, 0, 0, 0, 0x00000000, bhvBoogooObject),
		OBJECT(MODEL_HAUNTED_CAGE, -19321, 2068, 1313, 0, 180, 0, (20 << 16), bhvBoogooCage),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, -19321, 2068, 728, 0, 0, 0, 0x00000000, bhvDoor),
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
		OBJECT(MODEL_TOKEN, -19948, 2018, 4299, 0, 0, 0, (0x37 << 8), bhvToken),
		OBJECT(MODEL_BG_ASTEROID, -19949, 2884, -11665, 0, 124, 0, (10 << 16), bhvBGAsteroid),
		OBJECT(MODEL_BG_ASTEROID, -15468, 4803, -8033, 0, 101, 0, (45 << 16), bhvBGAsteroid),
		OBJECT(MODEL_BG_ASTEROID, -15369, 5003, -5297, 0, -97, 0, (50 << 16), bhvBGAsteroid),
		OBJECT(MODEL_BG_ASTEROID, -17339, 5581, -8801, 0, -97, 0, (35 << 16), bhvBGAsteroid),
		OBJECT(MODEL_BG_ASTEROID, -17755, 5581, -9732, 0, 90, 0, (35 << 16), bhvBGAsteroid),
		OBJECT(MODEL_BG_ASTEROID, -19170, 6115, -8689, 0, -162, 0, (30 << 16), bhvBGAsteroid),
		OBJECT(MODEL_BG_ASTEROID, -20429, 6291, -9177, 0, 5, 0, (40 << 16), bhvBGAsteroid),
		OBJECT(MODEL_BG_ASTEROID, -22114, 6448, -10376, 0, -120, 0, (45 << 16), bhvBGAsteroid),
		OBJECT(MODEL_BG_ASTEROID, -18302, 7538, -22118, 0, 0, 0, (40 << 16), bhvBGAsteroid),
		OBJECT(MODEL_BG_ASTEROID, -19214, 7538, -20661, 0, 103, 0, (40 << 16), bhvBGAsteroid),
		OBJECT(MODEL_BG_ASTEROID, -18253, 7856, -18089, 0, 126, 0, (60 << 16), bhvBGAsteroid),
		OBJECT(MODEL_BG_ASTEROID, -17870, 7856, -17565, 0, -54, 0, (60 << 16), bhvBGAsteroid),
		OBJECT(MODEL_BG_ASTEROID, -8093, 5510, -13310, 0, 114, 0, (1 << 16), bhvBGAsteroid),
		OBJECT(MODEL_BG_ASTEROID, -9448, 5126, -11991, 0, 19, 0, 0x00000000, bhvBGAsteroidGrow),
		OBJECT(MODEL_BG_ASTEROID, -9250, 4941, -10462, 0, -75, 0, 0x00000000, bhvBGAsteroidGrow),
		OBJECT(MODEL_BG_ASTEROID, -9448, 5166, -14611, 0, 19, 0, 0x00000000, bhvBGAsteroidGrow),
		OBJECT(MODEL_HAUNTED_CAGE, -16283, 4876, -13517, 0, 180, 0, (21 << 16), bhvBoogooCage),
		OBJECT(MODEL_O2_BOOGOO, -15732, 6503, -21987, 0, 0, 0, (1 << 16), bhvBoogooObject),
		OBJECT(MODEL_BG_GOOMBA, -19954, 6792, -12199, 0, 180, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_BG_GOOMBA, -8381, 4021, -9448, 0, 180, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_BG_GOOMBA, -17417, 7353, -16833, 0, 180, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_PEEPA, -19707, 2858, -5636, 0, -90, 0, (1 << 24), bhvFloorPeepa),
		OBJECT(MODEL_PEEPA, -19707, 2658, -5636, 0, -90, 0, (1 << 16), bhvFloorPeepa),
		OBJECT(MODEL_PEEPA, -19707, 2458, -5636, 0, -90, 0, (2 << 16), bhvFloorPeepa),
		OBJECT(MODEL_PEEPA, -17245, 5492, -6877, 0, -90, 0, 0x00000000, bhvFloorPeepa),
		OBJECT(MODEL_PEEPA, -17245, 5292, -6877, 0, -90, 0, (1 << 16), bhvFloorPeepa),
		OBJECT(MODEL_PEEPA, -17245, 5092, -6877, 0, -90, 0, (2 << 16), bhvFloorPeepa),
		OBJECT(MODEL_PEEPA, -21848, 6595, -8922, 0, -90, 0, 0x00000000, bhvFloorPeepa),
		OBJECT(MODEL_PEEPA, -21848, 6395, -8922, 0, -90, 0, (1 << 16), bhvFloorPeepa),
		OBJECT(MODEL_PEEPA, -21848, 6195, -8922, 0, -90, 0, (2 << 16), bhvFloorPeepa),
		TERRAIN(ssl_area_1_collision),
		ROOMS(ssl_area_1_collision_rooms),
		MACRO_OBJECTS(ssl_area_1_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_STONE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(2, ssl_area_2),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x1A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_SSL, 0x02, 0x1A, WARP_NO_CHECKPOINT),
		INSTANT_WARP(0, 0x01, 22500, 0, -10000),
		WARP_NODE(0x40, LEVEL_SSL, 0x02, 0x41, WARP_NO_CHECKPOINT),
		WARP_NODE(0x41, LEVEL_SSL, 0x02, 0x40, WARP_NO_CHECKPOINT),
		INSTANT_WARP(3, 0x02, 0, -10000, 0),
		INSTANT_WARP(4, 0x02, 0, 10000, 0),
		OBJECT(MODEL_NONE, -22687, 6347, -1694, 0, 90, 0, (0x1A << 16), bhvAirborneDeathWarp),
		OBJECT(MODEL_NONE, -22687, 6347, -1694, 0, 90, 0, (0xA << 16), bhvFlyingWarp),
		OBJECT(MODEL_MIND_MOUND_BLOCK, -14394, 7337, -1639, 0, 0, 0, (3 << 16), bhvMindMoundBlock),
		OBJECT(MODEL_MP_BOOGOO, -17138, 5687, -1654, 0, 0, 0, (2 << 24) | (4 << 16), bhvBoogooObjectNoCage),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, -19265, 5687, -4800, 0, 0, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, -16765, 7187, -4550, 0, 0, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, -19265, 5687, 1450, 0, 180, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, -16765, 7187, 1201, 0, -180, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_GLOBAL_GATE, -19265, 5687, 1410, 0, 180, 0, 0x00000000, bhvMindGate),
		OBJECT(MODEL_MIND_LEVER, -17121, 5687, -1675, 0, -90, 0, 0x00000000, bhvMindLever),
		OBJECT(MODEL_L8_LOCKED_CAGE, -14280, 5687, -781, 0, 90, 0, (11 << 16), bhvLockedCage),
		OBJECT(MODEL_MIND_MIPS, -15049, 5637, -2587, 0, 0, 0, (3 << 16), bhvMindMips),
		OBJECT(MODEL_MIND_MOUND, -14394, 5637, -4088, 0, 0, 0, (1 << 24), bhvMindMound),
		OBJECT(MODEL_MIND_MOUND, -14394, 5637, -3463, 0, 0, 0, (1 << 16), bhvMindMound),
		OBJECT(MODEL_MIND_MOUND, -14394, 5637, -2838, 0, 0, 0, (1 << 24) | (2 << 16), bhvMindMound),
		OBJECT(MODEL_MIND_MOUND, -14394, 5637, -2213, 0, 0, 0, (1 << 24) | (3 << 16), bhvMindMound),
		OBJECT(MODEL_MIND_MOUND, -15019, 5637, -3463, 0, 0, 0, (1 << 24) | (5 << 16), bhvMindMound),
		OBJECT(MODEL_MIND_MOUND, -15019, 5637, -2838, 0, 0, 0, (6 << 16), bhvMindMound),
		OBJECT(MODEL_MIND_MOUND, -15019, 5637, -2213, 0, 0, 0, (1 << 24) | (7 << 16), bhvMindMound),
		OBJECT(MODEL_MIND_MOUND, -15644, 5637, -3463, 0, 0, 0, (1 << 24) | (9 << 16), bhvMindMound),
		OBJECT(MODEL_MIND_MOUND, -15644, 5637, -2838, 0, 0, 0, (1 << 24) | (10 << 16), bhvMindMound),
		OBJECT(MODEL_MIND_MOUND, -16269, 5637, -4088, 0, 0, 0, (1 << 24) | (12 << 16), bhvMindMound),
		OBJECT(MODEL_MIND_MOUND, -16269, 5637, -3463, 0, 0, 0, (1 << 24) | (13 << 16), bhvMindMound),
		OBJECT(MODEL_STAR_PIECE, -14280, 5787, -781, 0, 0, 0, (0x15 << 24), bhvStarPiece),
		OBJECT(MODEL_BIG_SPINNING_PLAT, -5382, 6737, -9688, 0, 0, 0, 0x00000000, bhvBigSpinningPlat),
		OBJECT(MODEL_BLUE_COIN, -3742, 6837, -9792, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, -4296, 6837, -11069, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, -4175, 6837, -12845, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, -5393, 6837, -12691, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, -5740, 6837, -11348, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, -3865, 6837, -8500, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, -5068, 6837, -10043, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, -5391, 6837, -8796, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, -5066, 6837, -7771, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, -4817, 6837, -6431, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN_SWITCH, -3667, 6787, -7428, 0, -180, 0, 0x13023600, bhvBlueCoinSwitch),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, 6243, 7311, -11707, 0, -90, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, 19343, 7311, -11707, 0, -90, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_SMALL_KEY, -16684, 7287, -8703, 0, 0, 0, (1 << 24) | (12 << 16), bhvSmallKey),
		OBJECT(MODEL_SPINNING_PLAT, -17725, 5759, -10961, 0, 0, 0, 0x00000000, bhvSpinningPlat),
		OBJECT(MODEL_SPINNING_PLAT, -14605, 6243, -9337, 0, 0, 0, 0x00000000, bhvSpinningPlat),
		OBJECT(MODEL_SPINNING_PLAT, -13916, 6243, -8073, 0, 0, 0, 0x00000000, bhvSpinningPlat),
		OBJECT(MODEL_SPINNING_PLAT, -12425, 6243, -8125, 0, 0, 0, 0x00000000, bhvSpinningPlat),
		OBJECT(MODEL_SPINNING_PLAT, 1296, 7111, -9177, 0, 0, 0, 0x00000000, bhvSpinningPlat),
		OBJECT(MODEL_SPINNING_PLAT, 2250, 7111, -12248, 0, 0, 0, 0x00000000, bhvSpinningPlat),
		OBJECT(MODEL_TELEPORTER, 20246, 7311, -11707, 0, -90, 0, (0x40 << 16), bhvFadingWarp),
		OBJECT(MODEL_NONE, -19265, 5987, -5703, 0, 0, 0, (0x41 << 16), bhvFadingWarp),
		OBJECT(MODEL_ANTENNA_BALL, 11330, 7809, -10638, 0, 0, 0, 0x00000000, bhvAntennaBall),
		OBJECT(MODEL_ANTENNA_BALL, 17697, 7809, -9838, 0, 0, 0, 0x00000000, bhvAntennaBall),
		OBJECT(MODEL_ANTENNA_BALL, 17697, 7809, -13576, 0, 0, 0, 0x00000000, bhvAntennaBall),
		OBJECT(MODEL_HAUNTED_CAGE, 18724, 7311, -11707, 0, 0, 0, (22 << 16), bhvBoogooCage),
		OBJECT(MODEL_ANTENNA_BALL, 11330, 7809, -12776, 0, 0, 0, (1 << 16), bhvAntennaBall),
		OBJECT(MODEL_BG_GOOMBA, 15957, 7311, -8830, 0, -90, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_BG_GOOMBA, 12372, 7311, -14732, 0, -90, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_HEART, 14420, 7361, -12371, 0, -90, 0, 0x00000000, bhvRecoveryHeart),
		OBJECT(MODEL_HEART, 16762, 7361, -10305, 0, -90, 0, 0x00000000, bhvRecoveryHeart),
		OBJECT(MODEL_BG_GOOMBA, 15591, 7311, -12666, 0, -90, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_LAB_BOOGOO, 10483, 7665, -12500, 0, 0, 0, (2 << 16), bhvBoogooObject),
		OBJECT(MODEL_MR_I, 7603, 7311, -12007, 0, -90, 0, 0x00000000, bhvMrI),
		OBJECT(MODEL_MR_I, 14932, 7311, -14363, 0, -90, 0, 0x00000000, bhvMrI),
		OBJECT(MODEL_MR_I, 16981, 7311, -15688, 0, -90, 0, 0x00000000, bhvMrI),
		OBJECT(MODEL_MR_I, 16981, 7311, -7726, 0, -90, 0, 0x00000000, bhvMrI),
		OBJECT(MODEL_MR_I, 14932, 7311, -10229, 0, -90, 0, 0x00000000, bhvMrI),
		OBJECT(MODEL_SUNCUBE, 14493, 7311, -15838, 0, 0, 0, 0x00000000, bhvSuncube),
		OBJECT(MODEL_SUNCUBE, 14493, 7311, -7576, 0, 0, 0, (1 << 16), bhvSuncube),
		OBJECT(MODEL_MIND_2D_GATE, -8493, 9452, 9383, 0, 0, 0, 0x00000000, bhvMind2DGate),
		OBJECT(MODEL_MIND_2D_GATE, -8493, 8252, 10583, 0, 0, 0, (1 << 16), bhvMind2DGate),
		OBJECT(MODEL_MIND_2D_GATE, -8493, 8252, 8283, 0, 0, 0, (3 << 16), bhvMind2DGate),
		OBJECT(MODEL_MIND_2D_GATE, -8493, 9052, 7083, 0, 0, 0, (4 << 16), bhvMind2DGate),
		OBJECT(MODEL_MIND_2D_GATE, -8493, 9402, 7633, -90, 0, 0, (1 << 16), bhvMind2DGate),
		OBJECT(MODEL_MIND_2D_GATE, -8493, 9002, 9833, -90, 0, 0, (3 << 16), bhvMind2DGate),
		OBJECT(MODEL_MIND_2D_GATE, -11743, 9402, 5883, -90, 90, 0, (3 << 16), bhvMind2DGate),
		OBJECT(MODEL_MIND_2D_GATE, -11143, 9402, 5883, -90, 90, 0, (4 << 16), bhvMind2DGate),
		OBJECT(MODEL_MIND_2D_GATE, -11093, 9052, 5883, 0, 90, 0, 0x00000000, bhvMind2DGate),
		OBJECT(MODEL_MIND_2D_GATE, -11093, 8652, 5883, 0, 90, 0, (3 << 16), bhvMind2DGate),
		OBJECT(MODEL_MIND_2D_GATE, -11143, 8602, 5883, -90, 90, 0, (4 << 16), bhvMind2DGate),
		OBJECT(MODEL_MIND_2D_GATE, -9743, 8602, 5883, -90, 90, 0, 0x00000000, bhvMind2DGate),
		OBJECT(MODEL_MIND_2D_GATE, -12743, 8202, 5883, -90, 90, 0, 0x00000000, bhvMind2DGate),
		OBJECT(MODEL_MIND_2D_GATE, -11343, 8702, 11383, -90, -90, 0, 0x00000000, bhvMind2DGate),
		OBJECT(MODEL_MIND_2D_GATE, -10743, 8702, 11383, -90, -90, 0, (1 << 16), bhvMind2DGate),
		OBJECT(MODEL_MIND_2D_GATE, -12093, 9052, 11383, 0, -90, 0, (1 << 16), bhvMind2DGate),
		OBJECT(MODEL_MIND_2D_GATE, -12593, 8752, 11383, 0, -90, 0, (2 << 16), bhvMind2DGate),
		OBJECT(MODEL_MIND_2D_GATE, -10743, 9402, 11383, -90, -90, 0, (2 << 16), bhvMind2DGate),
		OBJECT(MODEL_MIND_MOUND_BLOCK, -9870, 8052, 8985, 0, 0, 0, (3 << 16), bhvOutsideMoundBlock),
		OBJECT(MODEL_MIND_BUTTON, -9711, 8052, 8733, 0, 0, 0, 0x00000000, bhvMindButton),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, -8541, 7599, 17066, 0, -90, 0, (12 << 16), bhvSmallKeyDoor),
		OBJECT(MODEL_GLOBAL_GATE, -16765, 7187, 1241, 0, 0, 0, 0x00000000, bhvMazeGate),
		OBJECT(MODEL_MIND_MOUND, -10405, 8052, 7695, 0, 0, 0, (1 << 24), bhvOutsideMound),
		OBJECT(MODEL_MIND_MOUND, -10405, 8052, 8320, 0, 0, 0, (1 << 16), bhvOutsideMound),
		OBJECT(MODEL_MIND_MOUND, -10405, 8052, 8945, 0, 0, 0, (1 << 24) | (2 << 16), bhvOutsideMound),
		OBJECT(MODEL_MIND_MOUND, -10405, 8052, 9570, 0, 0, 0, (1 << 24) | (3 << 16), bhvOutsideMound),
		OBJECT(MODEL_MIND_MOUND, -11030, 8052, 8320, 0, 0, 0, (1 << 24) | (5 << 16), bhvOutsideMound),
		OBJECT(MODEL_MIND_MOUND, -11030, 8052, 8945, 0, 0, 0, (6 << 16), bhvOutsideMound),
		OBJECT(MODEL_MIND_MOUND, -11030, 8052, 9570, 0, 0, 0, (1 << 24) | (7 << 16), bhvOutsideMound),
		OBJECT(MODEL_MIND_MOUND, -11655, 8052, 8320, 0, 0, 0, (1 << 24) | (9 << 16), bhvOutsideMound),
		OBJECT(MODEL_MIND_MOUND, -11655, 8052, 8945, 0, 0, 0, (1 << 24) | (10 << 16), bhvOutsideMound),
		OBJECT(MODEL_MIND_MOUND, -12280, 8052, 7695, 0, 0, 0, (1 << 24) | (12 << 16), bhvOutsideMound),
		OBJECT(MODEL_MIND_MOUND, -12280, 8052, 8320, 0, 0, 0, (1 << 24) | (13 << 16), bhvOutsideMound),
		OBJECT(MODEL_MIND_MOUND, -11030, 8052, 7695, 0, 0, 0, (1 << 24) | (4 << 16), bhvOutsideMound),
		OBJECT(MODEL_MIND_MOUND, -11655, 8052, 7695, 0, 0, 0, (1 << 24) | (8 << 16), bhvOutsideMound),
		OBJECT(MODEL_MIND_MOUND, -11655, 8052, 9570, 0, 0, 0, (1 << 24) | (11 << 16), bhvOutsideMound),
		OBJECT(MODEL_MIND_MOUND, -12280, 8052, 8945, 0, 0, 0, (1 << 24) | (14 << 16), bhvOutsideMound),
		OBJECT(MODEL_MIND_MOUND, -12280, 8052, 9570, 0, 0, 0, (1 << 24) | (15 << 16), bhvOutsideMound),
		OBJECT(MODEL_PEEPA, -17826, 6287, 5520, 0, -90, 0, (1 << 24), bhvFloorPeepa),
		OBJECT(MODEL_PEEPA, -17826, 6087, 5520, 0, -90, 0, (1 << 16), bhvFloorPeepa),
		OBJECT(MODEL_PEEPA, -17826, 5887, 5520, 0, -90, 0, (2 << 16), bhvFloorPeepa),
		OBJECT(MODEL_PEEPA, -12899, 7599, 14986, 0, -90, 0, 0x00000000, bhvFloorPeepa),
		OBJECT(MODEL_PEEPA, -12899, 7399, 14986, 0, -90, 0, (1 << 16), bhvFloorPeepa),
		OBJECT(MODEL_PEEPA, -12899, 7199, 14986, 0, -90, 0, (2 << 16), bhvFloorPeepa),
		OBJECT(MODEL_SPINNING_PLAT, -17811, 5895, 7985, 0, 0, 0, (1 << 16), bhvSpinningPlat),
		OBJECT(MODEL_SPINNING_PLAT, -15611, 7299, 13819, 0, 0, 0, (1 << 16), bhvSpinningPlat),
		OBJECT(MODEL_SPINNING_PLAT, 8815, 8596, 17851, 0, 0, 0, (1 << 16), bhvSpinningPlat),
		OBJECT(MODEL_SPINNING_PLAT, 8815, -1404, 17851, 0, 0, 0, (1 << 24) | (1 << 16), bhvSpinningPlat),
		OBJECT(MODEL_YOSHI_HEAD, -2439, 2950, 20573, 0, 180, 0, (70 << 16), bhvYoshiHeadLine),
		OBJECT(MODEL_YOSHI_HEAD, -3026, 2950, 19173, 0, 0, 0, (70 << 16), bhvYoshiHeadLine),
		OBJECT(MODEL_YOSHI_HEAD, -3598, 2950, 20573, 0, 180, 0, (70 << 16), bhvYoshiHeadLine),
		OBJECT(MODEL_YOSHI_HEAD, -4149, 2950, 19173, 0, 0, 0, (70 << 16), bhvYoshiHeadLine),
		OBJECT(MODEL_YOSHI_HEAD, -8073, 2992, 13948, 0, 0, 0, (14 << 24) | (11 << 16), bhvYoshiHeadRectangle),
		OBJECT(MODEL_YOSHI_HEAD, -8073, 2992, 13948, 0, -180, 0, (14 << 24) | (11 << 16) | (2 << 8), bhvYoshiHeadRectangle),
		OBJECT(MODEL_YOSHI_HEAD, -4532, 2992, 16240, 0, 0, 0, (1 << 16), bhvYoshiHeadSpin),
		OBJECT(MODEL_YOSHI_HEAD, -3939, 2992, 14564, 0, 0, 0, 0x00000000, bhvYoshiHeadSpin),
		OBJECT(MODEL_YOSHI_HEAD, -2771, 2992, 14564, 0, -180, 0, 0x00000000, bhvYoshiHeadSpin),
		OBJECT(MODEL_YOSHI_HEAD, -3091, 18799, 13637, 0, -90, 0, (90 << 16), bhvYoshiHeadLine),
		OBJECT(MODEL_YOSHI_HEAD, -7491, 18799, 14558, 0, 0, 0, (12 << 24) | (14 << 16), bhvYoshiHeadRectangle),
		OBJECT(MODEL_YOSHI_HEAD, -7491, 18799, 14558, 0, -180, 0, (12 << 24) | (14 << 16) | (2 << 8), bhvYoshiHeadRectangle),
		OBJECT(MODEL_YOSHI_HEAD, -1641, 18799, 15538, 0, 0, 0, 0x00000000, bhvYoshiHeadSpin),
		OBJECT(MODEL_NONE, -6633, 18599, 15237, 0, 0, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -5533, 18599, 13637, 0, 90, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -5693, 2769, 13905, 0, 90, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -4637, 2769, 18847, 0, -180, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -3691, 12599, 19466, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -1641, 18599, 15538, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, -441, 7599, 17066, 0, 90, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_GLOBAL_GATE, -8501, 7599, 17066, 0, 90, 0, 0x00000000, bhvGlobalGate),
		OBJECT(MODEL_GLOBAL_GATE, -481, 7599, 17066, 0, -90, 0, 0x00000000, bhvGlobalGate),
		OBJECT(MODEL_PENGUIN, -1579, 18699, 19963, 0, 180, 0, (1 << 16), bhvDreamPenguin),
		OBJECT(MODEL_PENGUIN, -1508, 2812, 16267, 0, 180, 0, (2 << 16), bhvDreamPenguin),
		OBJECT(MODEL_STAR_PIECE, -3163, 7799, 20636, 0, 0, 0, (0x16 << 24), bhvStarPiece),
		OBJECT(MODEL_TOKEN, -2799, 18649, 20866, 0, 0, 0, (0x38 << 8), bhvToken),
		OBJECT(MODEL_YOSHI, -2891, 13099, 15466, 0, 180, 0, 0x00000000, bhvDreamYoshi),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, 13519, 8596, 17964, 0, 90, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, 13519, -1404, 17964, 0, 90, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_GLOBAL_GATE, 13559, -1404, 17964, 0, 90, 0, 0x00000000, bhvGlobalGate),
		OBJECT(MODEL_JENGA_PLAT, 15784, 2875, 19335, 0, 0, 0, (1 << 24) | (10 << 16), bhvJengaPlat),
		OBJECT(MODEL_JENGA_PLAT, 16052, 5375, 17082, 0, -176, 0, (1 << 24) | (8 << 16), bhvJengaPlat),
		OBJECT(MODEL_JENGA_PLAT, 15416, 6875, 18234, 0, -155, 0, (2 << 24) | (5 << 16), bhvJengaPlat),
		OBJECT(MODEL_JENGA_PLAT, 17004, 7975, 17518, 0, 120, 0, (1 << 24) | (10 << 16), bhvJengaPlat),
		OBJECT(MODEL_JENGA_PLAT, 14735, 8375, 17297, 0, -116, 0, (3 << 24) | (5 << 16), bhvJengaPlat),
		OBJECT(MODEL_JENGA_PLAT, 16869, 10375, 18596, 0, 63, 0, (1 << 24) | (10 << 16), bhvJengaPlat),
		OBJECT(MODEL_OBSERVATORY_SPLAT, 15940, -1454, 17964, 0, 0, 0, 0x00000000, bhvObservatorySpinningPlat),
		TERRAIN(ssl_area_2_collision),
		ROOMS(ssl_area_2_collision_rooms),
		MACRO_OBJECTS(ssl_area_2_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_STONE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 90, -1358, 6347, -11675),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
