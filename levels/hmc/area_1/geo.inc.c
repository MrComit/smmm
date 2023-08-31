#include "src/game/envfx_snow.h"

const GeoLayout hmc_area_1_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SWITCH_CASE(17, geo_switch_area),
		GEO_OPEN_NODE(),
			GEO_BRANCH(1, hmc_dl_101__OpeningHall_geo),
			GEO_BRANCH(1, hmc_dl_102__Trophy_Room_geo),
			GEO_BRANCH(1, hmc_dl_103__Hallway_geo),
			GEO_BRANCH(1, hmc_dl_104__Music_Room_geo),
			GEO_BRANCH(1, hmc_dl_105__Game_Room_geo),
			GEO_BRANCH(1, hmc_dl_106__Panic_Room_geo),
			GEO_BRANCH(1, hmc_dl_107__Hallway_geo),
			GEO_BRANCH(1, hmc_dl_108__Morning_Room_geo),
			GEO_BRANCH(1, hmc_dl_109__Theater_geo),
			GEO_BRANCH(1, hmc_dl_110__NULL_geo),
			GEO_BRANCH(1, hmc_dl_111__NULL_geo),
			GEO_BRANCH(1, hmc_dl_112__NULL_geo),
			GEO_BRANCH(1, hmc_dl_113__Hallway_geo),
			GEO_BRANCH(1, hmc_dl_114__Sauna_geo),
			GEO_BRANCH(1, hmc_dl_115__Attic_geo),
			GEO_BRANCH(1, hmc_dl_116__Attic2_geo),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout hmc_dl_101__OpeningHall_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE_DECAL, hmc_dl_FloorMats_002_mesh_layer_2),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_OpeningHall_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_Plant_002_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, hmc_dl_Plant_002_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_Stairs_mesh_layer_1),
		GEO_ASM(0, geo_update_openinghall_floor),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_OpeningHall_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_OpeningHallCushions_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_OpeningHallObjects_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, hmc_dl_OpeningHallObjects_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_OpeningHallPlants_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, hmc_dl_OpeningHallPlants_mesh_layer_4),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, -9087, 5000, 14444),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, -9087, 5000, 5872),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_VisualBlocker_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout hmc_dl_bb_005_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_Attic_003_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, hmc_dl_Attic_003_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_Paintings_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_TrophyRoom_002_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_TrophyRoom_006_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_TrophyRoom_013_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_TrophyRoom_016_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_TrophyRoom_017_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, hmc_dl_TrophyRoom_017_mesh_layer_6),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_TrophyRoom_019_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_TrophyRoom_020_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_TrophyRoom_027_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, hmc_dl_TrophyRoom_027_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout hmc_dl_cc_006_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_cc_006_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout hmc_dl_bb_006_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_BombTrophy_mesh_layer_1),
		GEO_ASM(1, geo_update_vanish_floor),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_MUSICFLOOR_Trophy_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_Paintings_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_Paintings_003_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_TrophyRoom_007_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_TrophyRoom_015_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_TrophyRoom_018_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_TrophyRoom_022_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, hmc_dl_TrophyRoom_022_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_TrophyRoom_024_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_TrophyRoom_025_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, hmc_dl_TrophyRoom_025_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_TrophyRoomFakeWall_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout hmc_dl_cc_005_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_TrophyRoom_003_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout hmc_dl_bb_007_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_bb_007_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, hmc_dl_bb_007_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout hmc_dl_cc_004_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_cc_004_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout hmc_dl_102__Trophy_Room_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SWITCH_CASE(2, geo_switch_trophy_one),
		GEO_OPEN_NODE(),
			GEO_BRANCH(1, hmc_dl_bb_005_geo),
			GEO_BRANCH(1, hmc_dl_cc_006_geo),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_aa_mesh_layer_1),
		GEO_SWITCH_CASE(2, geo_switch_trophy_two),
		GEO_OPEN_NODE(),
			GEO_BRANCH(1, hmc_dl_bb_006_geo),
			GEO_BRANCH(1, hmc_dl_cc_005_geo),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_aa_004_mesh_layer_1),
		GEO_SWITCH_CASE(2, geo_switch_console),
		GEO_OPEN_NODE(),
			GEO_BRANCH(1, hmc_dl_bb_007_geo),
			GEO_BRANCH(1, hmc_dl_cc_004_geo),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_aa_005_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_Paintings_002_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_TrophyRoom_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_TrophyRoom_004_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, hmc_dl_TrophyRoom_004_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_TrophyRoom_005_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_TrophyRoom_026_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout hmc_dl_103__Hallway_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_TrophyRoom_009_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout hmc_dl_104__Music_Room_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, 8796, 0, 14423),
		GEO_OPEN_NODE(),
			GEO_ASM(0, geo_update_music_floor),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_MUSICFLOOR_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_RecordPlayer_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, hmc_dl_RecordPlayer_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_TrophyRoom_010_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout hmc_dl_bb_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_bb_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_bb_003_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout hmc_dl_cc_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_cc_002_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, hmc_dl_WhackAMole_001_mesh_layer_6),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout hmc_dl_bb_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, hmc_dl_bb_mesh_layer_4),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout hmc_dl_cc_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, hmc_dl_cc_001_mesh_layer_4),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout hmc_dl_bb_004_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SWITCH_CASE(2, geo_switch_mole_gate),
		GEO_OPEN_NODE(),
			GEO_BRANCH(1, hmc_dl_bb_geo),
			GEO_BRANCH(1, hmc_dl_cc_001_geo),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_aa_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_Chess_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_Painting_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_PingPongTable_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, hmc_dl_PingPongTable_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_PoolTable_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_ToyBoxes_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_TrophyRoom_023_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_WhackAMole_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, hmc_dl_WhackAMole_mesh_layer_4),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout hmc_dl_cc_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_cc_003_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout hmc_dl_105__Game_Room_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SWITCH_CASE(2, geo_switch_pool_floor),
		GEO_OPEN_NODE(),
			GEO_BRANCH(1, hmc_dl_bb_001_geo),
			GEO_BRANCH(1, hmc_dl_cc_002_geo),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_aa_006_mesh_layer_1),
		GEO_SWITCH_CASE(2, geo_switch_gameroom),
		GEO_OPEN_NODE(),
			GEO_BRANCH(1, hmc_dl_bb_004_geo),
			GEO_BRANCH(1, hmc_dl_cc_003_geo),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_aa_003_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_ToyBoxes_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_TrophyRoom_011_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout hmc_dl_106__Panic_Room_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_TrophyRoom_014_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout hmc_dl_107__Hallway_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_Hallway_003_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_Plant_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, hmc_dl_Plant_001_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_Plant_003_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, hmc_dl_Plant_003_mesh_layer_4),
		GEO_ASM(0, geo_update_hall_fakewall),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_ZHallwayFakeWall_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout hmc_dl_BBOutside_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_BBOutside_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, hmc_dl_BBOutside_mesh_layer_4),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout hmc_dl_CC_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_CC_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout hmc_dl_108__Morning_Room_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_Fan_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_Foreroom_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_Vase_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, hmc_dl_Vase_mesh_layer_4),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 2166, 218, -6663, hmc_dl_Vase_001_mesh_layer_1),
		GEO_SWITCH_CASE(0, geo_switch_foreroom_outside),
		GEO_OPEN_NODE(),
			GEO_BRANCH(1, hmc_dl_BBOutside_geo),
			GEO_BRANCH(1, hmc_dl_CC_geo),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_AA_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout hmc_dl_109__Theater_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_Theater_mesh_layer_1),
		GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, -5104, 250, -11146, 0, -90, 0),
		GEO_OPEN_NODE(),
			GEO_SCALE(LAYER_OPAQUE, 41532),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout hmc_dl_110__NULL_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_NULLTri_009_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout hmc_dl_111__NULL_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_NULLTri_009_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout hmc_dl_112__NULL_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_NULLTri_009_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout hmc_dl_b_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_Repeats_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout hmc_dl_c_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_NULLTri_014_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout hmc_dl_b_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SWITCH_CASE(2, geo_switch_plat_hall_repeats),
		GEO_OPEN_NODE(),
			GEO_BRANCH(1, hmc_dl_b_001_geo),
			GEO_BRANCH(1, hmc_dl_c_001_geo),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_NULLTri_013_mesh_layer_1),
		GEO_ASM(7, geo_update_vanish_floor),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_1BelowMaze_mesh_layer_1),
		GEO_ASM(6, geo_update_plathall_floor),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_BelowMaze_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_Hallway_005_mesh_layer_1),
		GEO_ASM(0, geo_update_vanish_floor),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_MUSICFLOOR_Hall_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout hmc_dl_c_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ASM(3, geo_update_vanish_floor),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_1Maze_mesh_layer_1),
		GEO_ASM(2, geo_update_plathall_floor),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_Maze_mesh_layer_1),
		GEO_ASM(5, geo_update_vanish_floor),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_Maze1NoCol_mesh_layer_1),
		GEO_ASM(4, geo_update_plathall_floor),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_MazeNoCol_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout hmc_dl_113__Hallway_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SWITCH_CASE(2, geo_switch_plat_hall),
		GEO_OPEN_NODE(),
			GEO_BRANCH(1, hmc_dl_b_geo),
			GEO_BRANCH(1, hmc_dl_c_geo),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_NULLTri_012_mesh_layer_1),
		GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, -9943, -200, -18221, 0, 90, 0),
		GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, -15291, 8539, -23929, 0, 90, 0),
		GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, -18170, 8539, -23929, 0, 90, 0),
		GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, -12411, 8539, -23929, 0, 90, 0),
		GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, -18170, 8539, -18170, 0, 90, 0),
		GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, -18170, 8539, -29688, 0, 90, 0),
		GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, -23929, 8539, -23929, 0, 90, 0),
		GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, -23929, 8539, -11491, 0, 90, 0),
		GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, -18582, -2200, -21101, 0, 90, 0),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout hmc_dl_bb_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, hmc_dl_Plants_002_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_Sauna1_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, hmc_dl_Sauna1_001_mesh_layer_6),
		GEO_DISPLAY_LIST(LAYER_ALPHA, hmc_dl_Sauna1_001_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, hmc_dl_Steam_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout hmc_dl_cc_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, hmc_dl_Plants_003_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_Sauna2_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, hmc_dl_Sauna2_001_mesh_layer_4),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout hmc_dl_dd_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, hmc_dl_Plants_002_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_ALPHA, hmc_dl_Plants_003_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_Sauna1_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, hmc_dl_Sauna1_001_mesh_layer_6),
		GEO_DISPLAY_LIST(LAYER_ALPHA, hmc_dl_Sauna1_001_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_Sauna2_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, hmc_dl_Sauna2_001_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, hmc_dl_Steam_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout hmc_dl_114__Sauna_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SWITCH_CASE(2, geo_switch_sauna),
		GEO_OPEN_NODE(),
			GEO_BRANCH(1, hmc_dl_bb_002_geo),
			GEO_BRANCH(1, hmc_dl_cc_geo),
			GEO_BRANCH(1, hmc_dl_dd_geo),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_ASaunaGlobal_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, hmc_dl_ASaunaGlobal_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_Sauna_002_mesh_layer_1),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, -2579, 500, -896),
		GEO_OPEN_NODE(),
			GEO_ASM(0, geo_generate_lava_wave),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_SaunaMat_mesh_layer_1),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout hmc_dl_bb_008_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_Attic_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, hmc_dl_Attic_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_Attic_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_BBOutside_002_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -7579, 4354, 10118, hmc_dl_Garage_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, hmc_dl_Z9_007_mesh_layer_4),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout hmc_dl_cc_008_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_cc_008_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout hmc_dl_115__Attic_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SWITCH_CASE(2, geo_switch_attic),
		GEO_OPEN_NODE(),
			GEO_BRANCH(1, hmc_dl_bb_008_geo),
			GEO_BRANCH(1, hmc_dl_cc_008_geo),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -7579, 4354, 10118, hmc_dl_aa_007_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_Attic_004_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout hmc_dl_116__Attic2_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_Attic_002_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout hmc_area_1[] = {
	GEO_NODE_SCREEN_AREA(10, SCREEN_WIDTH/2, SCREEN_HEIGHT/2, SCREEN_WIDTH/2, SCREEN_HEIGHT/2),
	GEO_OPEN_NODE(),
		GEO_ZBUFFER(0),
		GEO_OPEN_NODE(),
			GEO_NODE_ORTHO(100.0000),
			GEO_OPEN_NODE(),
				GEO_BACKGROUND_COLOR(0x0001),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_ZBUFFER(1),
		GEO_OPEN_NODE(),
			GEO_CAMERA_FRUSTUM_WITH_FUNC(45.0000, 100, 30000, geo_camera_fov),
			GEO_OPEN_NODE(),
				GEO_CAMERA(CAMERA_MODE_8_DIRECTIONS, 0, 0, 0, 0, -100, 0, geo_camera_main),
				GEO_OPEN_NODE(),
					GEO_BRANCH(1, hmc_area_1_geo),
					GEO_RENDER_OBJ(),
					GEO_ASM(ENVFX_LAVA_BUBBLES, geo_envfx_main),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_OPAQUE_DECAL, hmc_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_ALPHA, hmc_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, hmc_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, hmc_dl_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
