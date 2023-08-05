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
#include "actors/group0.h"
#include "actors/group0.h"
#include "actors/group0.h"
#include "actors/group0.h"
#include "actors/group0.h"
#include "actors/group0.h"
#include "actors/group0.h"
#include "actors/group0.h"
#include "actors/group0.h"
#include "actors/group0.h"
#include "actors/group0.h"
#include "actors/group0.h"
#include "actors/group0.h"

/* Fast64 begin persistent block [includes] */
extern const GeoLayout ice_bobomb_geo[];
#include "actors/group0.h"
/* Fast64 end persistent block [includes] */

#include "make_const_nonconst.h"
#include "levels/bob/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_bob_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _bob_segment_7SegmentRomStart, _bob_segment_7SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _generic_yay0SegmentRomStart, _generic_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0A, _water_skybox_yay0SegmentRomStart, _water_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group9_yay0SegmentRomStart, _group9_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group9_geoSegmentRomStart, _group9_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group14_yay0SegmentRomStart, _group14_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group14_geoSegmentRomStart, _group14_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_YAY0(0xb, _effect_yay0SegmentRomStart, _effect_yay0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_10), 
	JUMP_LINK(script_func_global_15), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_CASTLE_DOOR, castle_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_KEY_DOOR, key_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_LAND_CHUNK, landchunk_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CHANDELIER, chandelier_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_PLATE, plate_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_DINING_CHAIR, dining_chair_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_TEAPOT, teapot_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_L1_GATE, l1_gate_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVER, lever_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_L1_BOOK, l1_book_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_L1_BURNER, L1_burner_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_L1_CABINET, l1_cabinet_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_L1_BARREL, l1_barrel_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_L1_SHELF, l1_loose_shelf_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_KITCHEN_FRIDGE, kitchen_fridge_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_STOVE_BUTTON, stove_button_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_FRYING_PAN, frying_pan_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_REMOTE, remote_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_TV_STATIC, tv_static_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CUSHION, cushion_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_L1_THIN_BOOK, l1_thin_book_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_WATER_BUCKET, water_bucket_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_L1_FLIP_BOOK, l1_flip_book_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_KOOPA_BOSS, boss_koopa_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_L1_LOCK, l1_lock_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_GHOST_BARRIER, ghost_barrier_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BIG_BOOKSHELF, big_bookshelf_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_TABLE_BARRIER, table_barrier_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_ICE_BOMB, ice_bobomb_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_HALLWAY_FAKEWALL, hallway_fakewall_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_GOLDEN_PILLAR, golden_pillar_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_GOLD_MEDAL, gold_medal_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_RED_SPOT, red_spot_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_PROSPECTOR_T, prospector_t_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_L1_2D_RED, l1_2d_red_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, bob_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		INSTANT_WARP(0, 0x01, 2020, -944, -3350),
		INSTANT_WARP(1, 0x01, -2020, 944, 3350),
		WARP_NODE(0x0B, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0x0B, WARP_NO_CHECKPOINT),
		WARP_NODE(0x10, LEVEL_WF, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x72, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x90, LEVEL_CASTLE_GROUNDS, 0x01, 0x90, WARP_NO_CHECKPOINT),
		WARP_NODE(0x91, LEVEL_CASTLE_GROUNDS, 0x01, 0x91, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0D, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x33, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x74, LEVEL_LLL, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x75, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x27, LEVEL_JRB, 0x01, 0x0C, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, 0, 192, 28972, 0, -180, 0, 0x000B0000, bhvAirborneDeathWarp),
		OBJECT(MODEL_NONE, 0, 192, 28972, 0, -180, 0, 0x000A0000, bhvFlyingWarp),
		OBJECT(MODEL_NONE, 0, 150, 10940, 0, 0, 0, 0x000D0000, bhvFlyingWarp),
		OBJECT(MODEL_NONE, 4584, 261, 4163, 0, 0, 0, 0x00720000, bhvFlyingWarp),
		MARIO_POS(0x01, -180, 0, 192, 28972),
		OBJECT(MODEL_NONE, 5446, 161, 16260, 0, -90, 0, 0x00750000, bhvFlyingWarp),
		OBJECT(MODEL_TOAD_FRIEND, 446, 0, 13173, 0, -20, 0, 0x00000000, bhvToadFriend),
		OBJECT(MODEL_BREAKABLE_BOX, 861, 0, 29142, 0, 0, 0, 0x00000000, bhvBreakableBox),
		OBJECT(MODEL_BREAKABLE_BOX, 1061, 0, 29142, 0, 0, 0, 0x00000000, bhvBreakableBox),
		OBJECT(MODEL_BREAKABLE_BOX, 1061, 200, 29142, 0, 0, 0, 0x00000000, bhvBreakableBox),
		OBJECT(MODEL_BREAKABLE_BOX, 1261, 0, 29142, 0, 0, 0, 0x00000000, bhvBreakableBox),
		OBJECT(MODEL_BREAKABLE_BOX, -1261, 0, 29142, 0, 90, 0, 0x00000000, bhvBreakableBox),
		OBJECT(MODEL_CASTLE_KEY_DOOR, -75, 0, 12706, 0, 0, 0, 0x00010000, bhvBigKeyDoor),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, -75, 0, 27148, 0, 0, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, 75, 0, 27148, 0, -180, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_CASTLE_KEY_DOOR, 75, 0, 12706, 0, -180, 0, 0x00010000, bhvBigKeyDoor),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, 3355, 0, 13733, 0, -90, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, 3355, 0, 13883, 0, 90, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, 4555, 0, 15008, 0, 180, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, 5805, 0, 16260, 0, -90, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, 4555, 0, 12608, 0, 0, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, 3955, 0, 7927, 0, -90, 0, 0x00000000, bhvSmallKeyDoor),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, 5155, 0, 5678, 0, -90, 0, 0x00000000, bhvBlockedDoor),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, 155, 0, 7198, 0, 90, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, 855, 0, 5007, 0, 0, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, -3614, 0, 8952, 0, 0, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, -8155, 0, 8952, 0, 0, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, -9876, 0, 3738, 0, 180, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, -9726, 2944, 12759, 0, 180, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, 490, 690, 3760, 0, 0, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_L1_GATE, 0, 0, 27228, 0, 0, 0, 0x00000000, bhvL1Gate),
		OBJECT(MODEL_L1_GATE, 4555, 0, 12698, 0, 0, 0, 0x00010000, bhvL1Gate),
		OBJECT(MODEL_L1_GATE, -9876, 0, 3648, 0, -180, 0, 0x00020000, bhvL1Gate),
		OBJECT(MODEL_L1_GATE, -9726, 2944, 12669, 0, -180, 0, 0x00030000, bhvL1Gate),
		OBJECT(MODEL_L1_GATE, -3315, 0, 13808, 0, 90, 0, 0x00040000, bhvL1Gate),
		OBJECT(MODEL_LEVER, 1061, 0, 29142, 0, 0, 0, 0x00000000, bhvLever),
		OBJECT(MODEL_PROSPECTOR_LOCK, 4005, 0, 7927, 0, 90, 0, 0x00000000, bhvProspectorLock),
		OBJECT(MODEL_PROSPECTOR_LOCK, 3905, 0, 7927, 0, -90, 0, 0x00000000, bhvProspectorLock),
		OBJECT(MODEL_PROSPECTOR_LOCK, 105, 0, 7198, 0, -90, 0, 0x00000000, bhvProspectorLock),
		OBJECT(MODEL_PROSPECTOR_LOCK, 205, 0, 7198, 0, 90, 0, 0x00000000, bhvProspectorLock),
		OBJECT(MODEL_PROSPECTOR_LOCK, 490, 690, 3810, 0, 0, 0, (1 << 16), bhvProspectorLock),
		OBJECT(MODEL_CASTLE_GROUNDS_CASTLE_DOOR, 75, 0, 29332, 0, -180, 0, 0x00910000, bhvDoorWarp),
		OBJECT(MODEL_CASTLE_GROUNDS_CASTLE_DOOR, -75, 0, 29332, 0, 0, 0, 0x00900000, bhvDoorWarp),
		OBJECT(MODEL_BLUE_COIN, -1988, -177, 19963, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, -1877, -144, 20657, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, -597, -144, 21071, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, -403, -166, 21762, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, -1572, -191, 19564, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN_SWITCH, -1885, -84, 19060, 0, 0, 0, 0x05020000, bhvBlueCoinSwitch),
		OBJECT(MODEL_BREAKABLE_BOX, 1150, -83, 25388, 0, 0, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, 1315, 69, 24403, 0, 0, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, 1267, 216, 23460, 0, 0, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, 999, 400, 22773, 0, 18, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, 681, 598, 22138, 0, 14, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, -134, 955, 20439, 0, 22, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, -526, 956, 19361, 0, 0, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, -1056, 950, 18186, 0, 18, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, -1200, 1150, 16194, 0, 0, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, -790, 1250, 14962, 0, -40, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, 39, 1300, 13437, 0, 0, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, -1454, 1035, 17209, 0, -4, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, 233, 1300, 14444, 0, 15, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, 346, 948, 21436, 0, 30, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_CHANDELIER, 741, 685, 17689, 0, 0, 0, 0x00000000, bhvChandelier),
		OBJECT(MODEL_GOLDEN_PILLAR, -2587, -206, 16608, 0, 0, 0, (1 << 8), bhvGoldenPillar),
		OBJECT(MODEL_PROSPECTOR_T, 1005, 690, 2956, 0, -41, 0, 0x00000000, bhvProspectorT),
		OBJECT(MODEL_PURPLE_SWITCH, 1017, 0, 26555, 0, 0, 0, (23 << 24), bhvFloorSwitchHiddenObjects),
		OBJECT(MODEL_RED_COIN, 39, 1500, 13437, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_SPOT, 1016, -7, 22064, 0, 0, 0, (1 << 16), bhvRedSpot),
		OBJECT(MODEL_LAND_CHUNK, -2431, -200, 23982, 0, 0, 0, 0x021E0000, bhvLandChunk),
		OBJECT(MODEL_LAND_CHUNK, -2101, -200, 23213, 0, 28, 0, 0x021E0000, bhvLandChunk),
		OBJECT(MODEL_LAND_CHUNK, -1210, -200, 23651, 0, 82, 0, 0x021E0000, bhvLandChunk),
		OBJECT(MODEL_LAND_CHUNK, -952, -200, 22797, 0, -135, 0, 0x021E0000, bhvLandChunk),
		OBJECT(MODEL_STAR_PIECE, 4147, 546, 21248, 0, 0, 0, 0x00000000, bhvStarPiece),
		OBJECT(MODEL_TOKEN, -1320, 0, 29139, 0, 0, 0, 0x00000200, bhvToken),
		OBJECT(MODEL_TOKEN, 1396, 244, 16612, 0, 118, 0, 0x00000500, bhvToken),
		OBJECT(MODEL_TOKEN, -2330, 468, 22044, 0, 90, 0, 0x00000300, bhvToken),
		OBJECT(MODEL_TOKEN, -2528, 1714, 25981, 90, 0, 0, 0x00020400, bhvToken),
		OBJECT(MODEL_L1_BOOK, 5617, 186, 13060, 0, -90, 0, 0x05020000, bhvL1Book),
		OBJECT(MODEL_L1_BOOK, 5617, 186, 13010, 0, -90, 0, 0x04000000, bhvL1Book),
		OBJECT(MODEL_L1_BOOK, 5617, 186, 12959, 0, -90, 0, 0x03020000, bhvL1Book),
		OBJECT(MODEL_L1_BOOK, 5617, 288, 13060, 0, -90, 0, 0x02010000, bhvL1Book),
		OBJECT(MODEL_L1_BOOK, 5617, 288, 13010, 0, -90, 0, 0x01010000, bhvL1Book),
		OBJECT(MODEL_L1_BOOK, 5617, 288, 12959, 0, -90, 0, 0x00000000, bhvL1Book),
		OBJECT(MODEL_GOLD_MEDAL, 5695, 436, 13704, 0, 0, 0, (2 << 16), bhvGoldMedal),
		OBJECT(MODEL_STAR_PIECE, 5650, 210, 12959, 100, 0, 0, 0x01010000, bhvStarPiece),
		OBJECT(MODEL_GARAGE_WALL, 5741, 0, 16261, 0, 0, 0, 0x00000000, bhvGhostBarrier),
		OBJECT(MODEL_BOO, 4316, 179, 17006, 0, -180, 0, 0x00000000, bhvRoomBoo),
		OBJECT(MODEL_NONE, -2720, 277, 2698, 0, 0, 0, 0x00000000, bhvBookThrower),
		OBJECT(MODEL_NONE, -5169, 277, 2698, 0, 0, 0, 0x00000000, bhvBookThrower),
		OBJECT(MODEL_NONE, -4720, 277, 2698, 0, 0, 0, 0x00000000, bhvBookThrower),
		OBJECT(MODEL_NONE, -7969, 277, 2698, 0, 0, 0, 0x00010000, bhvBookThrower),
		OBJECT(MODEL_NONE, -3720, 277, 3479, 0, -180, 0, 0x00000000, bhvBookThrower),
		OBJECT(MODEL_NONE, -6068, 277, 3479, 0, -180, 0, 0x00000000, bhvBookThrower),
		OBJECT(MODEL_NONE, -6518, 277, 3479, 0, -180, 0, 0x00000000, bhvBookThrower),
		OBJECT(MODEL_BREAKABLE_BOX, 5005, 0, 3810, 0, 0, 0, 0x00000000, bhvBreakableBox),
		OBJECT(MODEL_BREAKABLE_BOX, 5005, 200, 3810, 0, 0, 0, 0x00000000, bhvBreakableBox),
		OBJECT(MODEL_BIG_BOOKSHELF, 4005, 0, 3910, 0, 0, 0, 0x00000000, bhvBigBookshelf),
		OBJECT(MODEL_GOLDEN_CRATE, 5230, 0, 8859, 0, 0, 0, 0x00000000, bhvGoldenCrate),
		OBJECT(MODEL_HALLWAY_FAKEWALL, 5105, 0, 8859, 0, 0, 0, 0x00000000, bhvHallwayFakeWall),
		OBJECT(MODEL_RED_COIN, -995, 150, 3088, 0, -90, 0, 0x00050000, bhvWingedRedCoin),
		OBJECT(MODEL_STAR_PIECE, -6718, 100, 9556, 0, 0, 0, 0x03000000, bhvStarPiece),
		OBJECT(MODEL_L1_2D_RED, 7582, 348, 3755, 0, 0, 0, (3 << 16), bhv2DRedCoin),
		OBJECT(MODEL_DINING_CHAIR, 7773, 0, 5120, 0, -60, 0, 0x00010000, bhvDiningChair),
		OBJECT(MODEL_DINING_CHAIR, 7195, 0, 4781, 0, 0, 0, 0x00000000, bhvDiningChair),
		OBJECT(MODEL_DINING_CHAIR, 6776, 0, 5792, 0, 135, 0, 0x00030000, bhvDiningChair),
		OBJECT(MODEL_DINING_CHAIR, 6616, 0, 5120, 0, 60, 0, 0x00040000, bhvDiningChair),
		OBJECT(MODEL_DINING_CHAIR, 5279, 0, 5683, -20, 90, 0, 0x00040000, bhvBlockingChair),
		OBJECT(MODEL_DINING_CHAIR, 7613, 0, 5792, 0, -135, 0, 0x00020000, bhvDiningChair),
		OBJECT(MODEL_GOOMBA, 8186, 0, 4468, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_KOOPA, 5960, 0, 4634, 0, 0, 0, 0x00020000, bhvKoopa),
		OBJECT(MODEL_KOOPA, 6343, 0, 4994, 0, 0, 0, 0x00010000, bhvKoopa),
		OBJECT(MODEL_KOOPA, 5704, 0, 5370, 0, 0, 0, 0x00000000, bhvKoopa),
		OBJECT(MODEL_SHYGUY, 5424, 1381, 6615, 0, 90, 0, 0x00000000, bhvShyguyPlate),
		OBJECT(MODEL_SHYGUY, 7195, 362, 5373, 0, 90, 0, 0x00000000, bhvShyguyChair),
		OBJECT(MODEL_NONE, 8331, 263, 3816, 0, 0, 0, 0x00020000, bhvTeapotSpawner),
		OBJECT(MODEL_NONE, 8979, 263, 3816, 0, 0, 0, 0x00020000, bhvTeapotSpawner),
		OBJECT(MODEL_NONE, 8655, 263, 3816, 0, 0, 0, 0x00020000, bhvTeapotSpawner),
		OBJECT(MODEL_NONE, 6793, 263, 3816, 0, 0, 0, 0x00020000, bhvTeapotSpawner),
		OBJECT(MODEL_NONE, 6469, 263, 3816, 0, 0, 0, 0x00020000, bhvTeapotSpawner),
		OBJECT(MODEL_GOOMBA, 8804, 0, 4760, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_GOOMBA, 8307, 0, 4039, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_GOOMBA, 8790, 0, 4141, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_BOO, 6690, 179, 6799, 0, -180, 0, 0x01010000, bhvRoomBoo),
		OBJECT(MODEL_L1_GATE, 5195, 0, 3810, 0, 90, 0, 0x00000000, bhvL1RoomGate),
		OBJECT(MODEL_L1_BURNER, 3102, -9, 1675, 0, 0, 0, 0x00000000, bhvOvenBurner),
		OBJECT(MODEL_L1_BURNER, 2652, -9, 1080, 0, 0, 0, 0x00000000, bhvOvenBurner),
		OBJECT(MODEL_L1_BURNER, 2652, -9, 680, 0, 0, 0, 0x00010000, bhvOvenBurner),
		OBJECT(MODEL_L1_BURNER, 3052, -9, 3125, 0, 0, 0, 0x00000000, bhvOvenBurner),
		OBJECT(MODEL_L1_BURNER, 2852, -9, 3575, 0, 0, 0, 0x00010000, bhvOvenBurner),
		OBJECT(MODEL_L1_BURNER, 2252, -9, 3125, 0, 0, 0, 0x00000000, bhvOvenBurner),
		OBJECT(MODEL_L1_BURNER, 2852, -9, 2625, 0, 0, 0, 0x00000000, bhvOvenBurner),
		OBJECT(MODEL_L1_BURNER, 2252, -9, 2325, 0, 0, 0, 0x00010000, bhvOvenBurner),
		OBJECT(MODEL_L1_BURNER, 2252, -9, 1925, 0, 0, 0, 0x00000000, bhvOvenBurner),
		OBJECT(MODEL_L1_CABINET, 506, 471, 6112, 0, 0, 0, 0x00010000, bhvL1Cabinet),
		OBJECT(MODEL_L1_CABINET, 506, 471, 5772, 0, 0, 0, (1 << 16), bhvL1Cabinet),
		OBJECT(MODEL_L1_CABINET, 506, 471, 5092, 0, 0, 0, 0x00010000, bhvL1Cabinet),
		OBJECT(MODEL_L1_CABINET, 506, 170, 5432, 0, 0, 0, 0x00000000, bhvL1Cabinet),
		OBJECT(MODEL_L1_CABINET, 506, 170, 5092, 0, 0, 0, 0x00000000, bhvL1Cabinet),
		OBJECT(MODEL_L1_BURNER, 2452, -9, 3575, 0, 0, 0, 0x00010000, bhvOvenBurner),
		OBJECT(MODEL_L1_BURNER, 2652, -9, 3125, 0, 0, 0, 0x00010000, bhvOvenBurner),
		OBJECT(MODEL_L1_BURNER, 1802, -9, 1575, 0, 0, 0, 0x00000000, bhvOvenBurner),
		OBJECT(MODEL_L1_BURNER, 3452, -9, 2425, 0, 0, 0, 0x00000000, bhvOvenBurner),
		OBJECT(MODEL_L1_BURNER, 3102, -9, 2075, 0, 0, 0, 0x00010000, bhvOvenBurner),
		OBJECT(MODEL_L1_BURNER, 2652, -9, 1480, 0, 0, 0, 0x00010000, bhvOvenBurner),
		OBJECT(MODEL_L1_BARREL, 2993, 236, 8691, 0, 0, 0, 0x00010000, bhvL1Barrel),
		OBJECT(MODEL_KITCHEN_FRIDGE, 676, 350, 7753, 0, 0, 0, 0x00000000, bhvFridgeDoor),
		OBJECT(MODEL_NONE, 592, 283, 7973, 0, 0, 0, 0x00000000, bhvFridgeSpawner),
		OBJECT(MODEL_L1_SHELF, 655, 733, 8452, 0, 0, 0, 0x00000000, bhvL1Shelf),
		OBJECT(MODEL_NONE, 762, 150, 7973, 0, 90, 0, (0x33 << 16), bhvFlyingWarp),
		OBJECT(MODEL_NONE, 1802, 121, 1575, 0, 0, 0, 0x00000000, bhvRedSparkles),
		OBJECT(MODEL_NONE, 2252, 121, 2325, 0, 0, 0, 0x00000000, bhvRedSparkles),
		OBJECT(MODEL_NONE, 2652, 121, 1480, 0, 0, 0, 0x00000000, bhvRedSparkles),
		OBJECT(MODEL_NONE, 2852, 121, 2625, 0, 0, 0, 0x00000000, bhvRedSparkles),
		OBJECT(MODEL_NONE, 2621, 0, 19, 0, 0, 0, 0x04010000, bhvRedSparkles),
		OBJECT(MODEL_BOO, 1917, 197, 6668, 0, -180, 0, 0x00020000, bhvRoomBoo),
		OBJECT(MODEL_L1_GATE, 3915, 0, 7927, 0, -90, 0, 0x00000000, bhvL1RoomGate),
		OBJECT(MODEL_L1_GATE, 195, 0, 7198, 0, 90, 0, 0x00000000, bhvL1RoomGate),
		OBJECT(MODEL_L1_GATE, 855, 0, 5047, 0, 0, 0, 0x00000000, bhvL1RoomGate),
		OBJECT(MODEL_SHYGUY, 2621, 0, 19, 0, 0, 0, 0x00000000, bhvShyguy),
		OBJECT(MODEL_STAR_PIECE, 748, 833, 8677, 0, 0, 0, 0x02000000, bhvStarPiece),
		OBJECT(MODEL_STOVE_BUTTON, 2992, 131, 5062, 0, 0, 0, 0x00000000, bhvStoveButton),
		OBJECT(MODEL_FRYING_PAN, 3071, 269, 4990, 0, 0, 0, 0x00000000, bhvFryingPan),
		OBJECT(MODEL_TOKEN, 354, 40, 5593, 0, 90, 0, 0x00000800, bhvToken),
		OBJECT(MODEL_TOKEN, 1166, 1210, 4891, 0, -135, 0, 0x00010600, bhvToken),
		OBJECT(MODEL_GOOMBA, -6135, 0, 6820, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_GOOMBA, -5748, 0, 7372, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_GOOMBA, -5546, 0, 6425, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_GOOMBA, -5224, 0, 7804, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_REMOTE, -3614, 0, 7902, 0, 0, 0, 0x00000000, bhvRemote),
		OBJECT(MODEL_REMOTE, -4614, 1100, 5695, 0, 0, 0, 0x00000000, bhvRemote),
		OBJECT(MODEL_REMOTE, -7211, 19, 5679, 0, 0, 0, 0x00000000, bhvRemote),
		OBJECT(MODEL_REMOTE, -8293, 808, 7384, 0, 0, 0, 0x00000000, bhvRemote),
		OBJECT(MODEL_CUSHION, -6321, 0, 7750, 0, 17, 0, 0x00000000, bhvCushion),
		OBJECT(MODEL_CUSHION, -8490, 0, 8440, 0, -14, 0, 0x00000000, bhvCushion),
		OBJECT(MODEL_BOO, -5237, 0, 8483, 0, -180, 0, 0x00030000, bhvRoomBoo),
		OBJECT(MODEL_L1_GATE, -3614, 0, 8912, 0, 180, 0, 0x00000000, bhvL1RoomGate),
		OBJECT(MODEL_L1_GATE, -8155, 0, 8912, 0, 180, 0, 0x00000000, bhvL1RoomGate),
		OBJECT(MODEL_TV_STATIC, -4614, 500, 6053, 0, 0, 0, 0x00000000, bhvTVStatic),
		OBJECT(MODEL_L1_BOOK, -8771, 26, 5397, 180, 0, -90, 0x00000000, bhvAppearingBook),
		OBJECT(MODEL_L1_BOOK, -8771, 91, 5917, 180, 0, -90, 0x00010000, bhvAppearingBook),
		OBJECT(MODEL_L1_BOOK, -8771, 156, 6437, 180, 0, -90, 0x00020000, bhvAppearingBook),
		OBJECT(MODEL_BLUE_COIN, -10425, 339, 8244, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, -9856, 642, 8361, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, -9342, 750, 7933, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, -9040, 944, 8382, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN_SWITCH, -11556, 250, 8213, 0, 0, 0, 0x05020100, bhvBlueCoinSwitch),
		OBJECT(MODEL_RED_FLAME, -12179, 250, 7566, 0, 0, 0, 0x00000000, bhvL1Fireplace),
		OBJECT(MODEL_L1_FLIP_BOOK, -11777, 3067, 11638, 0, -90, 0, 0x00000000, bhvFlipBook),
		OBJECT(MODEL_L1_FLIP_BOOK, -11777, 3067, 11938, 0, -90, 0, 0x00000000, bhvFlipBook),
		OBJECT(MODEL_HEART, -10101, 2994, 12459, 0, 0, 0, 0x00000000, bhvRecoveryHeart),
		OBJECT(MODEL_L1_THIN_BOOK, -10230, 208, 6949, 0, 0, 0, 0x00000000, bhvSpinningBook),
		OBJECT(MODEL_L1_THIN_BOOK, -9626, 156, 7068, 0, 0, 0, 0x00000000, bhvSpinningBook),
		OBJECT(MODEL_L1_THIN_BOOK, -9086, 156, 7115, 0, 0, 0, 0x00000000, bhvSpinningBook),
		OBJECT(MODEL_L1_THIN_BOOK, -10425, 285, 8244, 0, 0, 0, 0x00000000, bhvSpinningBook),
		OBJECT(MODEL_L1_THIN_BOOK, -10298, 471, 8862, 0, 0, 0, 0x00000000, bhvSpinningBook),
		OBJECT(MODEL_L1_THIN_BOOK, -9856, 588, 8361, 0, 0, 0, 0x00000000, bhvSpinningBook),
		OBJECT(MODEL_L1_THIN_BOOK, -9342, 697, 7933, 0, 0, 0, 0x00000000, bhvSpinningBook),
		OBJECT(MODEL_L1_THIN_BOOK, -9040, 890, 8382, 0, 0, 0, 0x00000000, bhvSpinningBook),
		OBJECT(MODEL_BLUE_COIN, -10298, 524, 8862, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_L1_BOOK, -9567, 1971, 10688, 180, 0, -90, 0x40000000, bhvSineBook),
		OBJECT(MODEL_L1_BOOK, -9279, 2245, 11189, -90, 0, -90, 0x00020000, bhvSineBook),
		OBJECT(MODEL_L1_BOOK, -10285, 1475, 10027, -90, 0, 0, 0x00010000, bhvSineBook),
		OBJECT(MODEL_L1_FLIP_BOOK, -11177, 3067, 12238, 0, -90, 0, 0x00000000, bhvFlipBook),
		OBJECT(MODEL_L1_FLIP_BOOK, -11477, 3067, 11638, 0, -90, 0, 0x00000000, bhvFlipBook),
		OBJECT(MODEL_STAR_PIECE, -12273, 350, 7567, 0, 0, 0, 0x04000000, bhvStarPiece),
		OBJECT(MODEL_WATER_BUCKET, -9002, 2944, 12545, 0, 0, 0, 0x00000000, bhvWaterBucket),
		OBJECT(MODEL_CHANDELIER, -9070, 3292, 17409, 0, 0, 0, 0x00000000, bhvKoopaBossChandelier),
		OBJECT(MODEL_RED_FLAME, -10961, 1208, 17409, 0, 90, 0, 0x00000000, bhvFlameDecorationBig),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, -7474, 944, 17158, 0, -90, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_KOOPA_BOSS, -9070, 947, 17409, 0, 90, 0, 0x00000000, bhvKoopaBoss),
		OBJECT(MODEL_L1_LOCK, -10652, 2152, 18177, 0, 0, 0, 0x00000000, bhvL1Lock),
		OBJECT(MODEL_L1_LOCK, -10652, 2152, 16641, 0, 0, 0, 0x00000000, bhvL1Lock),
		OBJECT(MODEL_L1_LOCK, -10652, 2452, 17409, 0, 0, 0, 0x00000000, bhvL1Lock),
		OBJECT(MODEL_JOURNAL_BOOK, 5184, 140, 14418, 0, 0, 0, (DIALOG_054 << 16), bhvJournalBook),
		OBJECT(MODEL_JOURNAL_BOOK, -8582, 1081, 16199, 0, 0, 0, (DIALOG_050 << 16), bhvJournalBook),
		OBJECT(MODEL_NONE, -9001, 1081, 15809, 0, 0, 0, (DIALOG_044 << 16), bhvSignOnWall),
		OBJECT(MODEL_NONE, -9429, 1081, 15809, 0, 0, 0, (DIALOG_045 << 16), bhvSignOnWall),
		OBJECT(MODEL_NONE, -9856, 1081, 15809, 0, 0, 0, (DIALOG_046 << 16), bhvSignOnWall),
		OBJECT(MODEL_BREAKABLE_BOX, -9795, 1944, 16041, 0, 0, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, -9814, 2137, 16616, 0, 0, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, -9823, 2271, 17255, 0, 0, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, -9123, 2381, 17093, 0, 0, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, -7934, 2581, 17499, 0, 0, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, -7877, 2681, 18419, 0, 0, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, -10478, 3141, 17409, 0, 0, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, -8354, 2481, 16763, 0, 0, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, -8795, 2781, 18331, 0, 0, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, -9747, 2881, 18332, 0, 0, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, -9770, 3081, 17492, 0, 0, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_NONE, -8509, 946, 17939, 0, 0, 0, 0x00070000, bhvInvisRedCoin),
		OBJECT(MODEL_PURPLE_SWITCH, -10320, 1944, 15200, 0, -180, 0, 0x00000000, bhvFloorSwitchHiddenObjects),
		OBJECT(MODEL_RED_COIN, -10478, 3341, 17409, 0, 0, 0, 0x00060000, bhvRedCoin),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, -5374, 944, 17158, 0, -90, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, -3355, 0, 13808, 0, -90, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, -5455, 0, 13808, 0, -90, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_CASTLE_KEY_DOOR, -1400, 0, 11581, 0, -90, 0, 0x030F0000, bhvBigKeyDoor),
		OBJECT(MODEL_CASTLE_KEY_DOOR, -1400, 0, 11731, 0, 90, 0, 0x030F0000, bhvBigKeyDoor),
		OBJECT(MODEL_SAVE_STATION, -911, 0, 11099, 0, 0, 0, 0x00000000, bhvSaveStation),
		OBJECT(MODEL_BLUE_COIN, -3906, 0, 12269, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, -3906, 0, 11043, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, -4700, 0, 11646, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, -4320, 0, 11646, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, -4700, 0, 11061, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, -4700, 0, 12231, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, -3623, 280, 11656, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, -2397, 0, 11687, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, -1897, 0, 11687, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, -1897, 0, 12299, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, -1897, 0, 11013, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, -2889, 0, 11143, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, -2889, 0, 12169, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, -3623, 380, 11656, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, -3623, 480, 11656, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN_SWITCH, -2958, 0, 11656, 0, 90, 0, 0x30023500, bhvBlueCoinSwitch),
		OBJECT(MODEL_GOLDEN_CRATE, -4320, 25, 12156, 0, 0, 0, (10 << 8), bhvGoldenCrate),
		OBJECT(MODEL_GOLDEN_CRATE, -4320, 25, 11136, 0, 0, 0, (11 << 8), bhvGoldenCrate),
		OBJECT(MODEL_TOKEN, -2493, 320, 12169, 0, 90, 0, 0x00023300, bhvToken),
		OBJECT(MODEL_TOKEN, -3276, 520, 11043, 0, 90, 0, 0x00023400, bhvToken),
		TERRAIN(bob_area_1_collision),
		ROOMS(bob_area_1_collision_rooms),
		MACRO_OBJECTS(bob_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_MANOR),
		TERRAIN_TYPE(TERRAIN_STONE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, -180, 0, 192, 28972),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
