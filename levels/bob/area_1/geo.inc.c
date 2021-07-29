#include "src/game/envfx_snow.h"

const GeoLayout bob_area_1_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SWITCH_CASE(15, geo_switch_area),
		GEO_OPEN_NODE(),
			GEO_BRANCH(1, bob_dl_Room1A_geo),
			GEO_BRANCH(1, bob_dl_Room1B_geo),
			GEO_BRANCH(1, bob_dl_Room1C_geo),
			GEO_BRANCH(1, bob_dl_Room1D_geo),
			GEO_BRANCH(1, bob_dl_Room1E_geo),
			GEO_BRANCH(1, bob_dl_Room1F_geo),
			GEO_BRANCH(1, bob_dl_Room1G_geo),
			GEO_BRANCH(1, bob_dl_Room1H_geo),
			GEO_BRANCH(1, bob_dl_Room1I_geo),
			GEO_BRANCH(1, bob_dl_Room1J_geo),
			GEO_BRANCH(1, bob_dl_Room1K_geo),
			GEO_BRANCH(1, bob_dl_Room1L_geo),
			GEO_BRANCH(1, bob_dl_Room1M_geo),
			GEO_BRANCH(1, bob_dl_Room1N_geo),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bob_dl_Room1A_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(1, 762, 280, 27350, bob_dl_Bookshelf_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -1242, 89, 28819, bob_dl_Dresser_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -1061, 303, 27499, bob_dl_Lamp_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 0, 338, 28161, bob_dl_Mudroom_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(2, 0, 0, 28206, bob_dl_Mudroom_001_mesh_layer_2),
		GEO_TRANSLATE_NODE_WITH_DL(6, 0, 0, 28206, bob_dl_Mudroom_002_mesh_layer_6),
		GEO_TRANSLATE_NODE_WITH_DL(2, 0, 384, 28220, bob_dl_Mudroom_003_mesh_layer_2),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bob_dl_Room1B_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(1, -150, -129, 21568, bob_dl_MainHall_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 1111, 531, 19291, bob_dl_MainHall_001_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(2, bob_dl_MainHall_001_mesh_layer_2),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(1, 0, -206, 20467, bob_dl_MainHall_003_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 69, -200, 22509, bob_dl_MainHall_004_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -1188, -358, 20812, bob_dl_MainHall_005_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -1904, -284, 19070, bob_dl_MainHall_006_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 1049, -126, 22083, bob_dl_MainHall_007_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 947, 43, 16745, bob_dl_MainHall_008_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 729, -80, 18935, bob_dl_MainHall_009_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 1874, 117, 20844, bob_dl_MainHall_010_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 740, -66, 15598, bob_dl_MainHall_011_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(6, 22, 0, 26440, bob_dl_Mudroom_004_mesh_layer_6),
		GEO_TRANSLATE_NODE_WITH_DL(1, -3276, 745, 22759, bob_dl_Painting_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -3276, 745, 24759, bob_dl_Painting_001_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -3276, 745, 20759, bob_dl_Painting_002_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 3276, 745, 21259, bob_dl_Painting_003_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 3276, 745, 19259, bob_dl_Painting_004_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 3276, 745, 23259, bob_dl_Painting_005_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 3276, 745, 25259, bob_dl_Painting_006_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -3276, 745, 18759, bob_dl_Painting_007_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 3276, 745, 17259, bob_dl_Painting_008_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -3276, 745, 16759, bob_dl_Painting_010_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(6, -3247, 745, 20759, bob_dl_Painting_011_mesh_layer_6),
		GEO_TRANSLATE_NODE_WITH_DL(6, 3276, 745, 21259, bob_dl_Painting_012_mesh_layer_6),
		GEO_TRANSLATE_NODE_WITH_DL(1, -2533, 819, 25962, bob_dl_Pillar_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -1284, -233, 20603, bob_dl_Pillar_Tops_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 2956, 219, 25962, bob_dl_Pillar_001_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -1544, -113, 23059, bob_dl_Pillar_002_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -1336, -113, 22270, bob_dl_Pillar_003_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 1843, -71, 21834, bob_dl_Pillar_004_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 1042, -71, 20600, bob_dl_Pillar_006_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -2375, -40, 22047, bob_dl_Pillar_007_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -2533, 819, 13277, bob_dl_Pillar_008_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 2633, 819, 13277, bob_dl_Pillar_009_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 2604, 47, 21313, bob_dl_Pillar_010_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 61, 82, 22577, bob_dl_Simple_Table_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bob_dl_Room1C_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(1, 5593, 280, 12933, bob_dl_Bookshelf_001_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 5183, 71, 14217, bob_dl_chair_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 5184, 71, 14619, bob_dl_chair_001_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 4983, 71, 14418, bob_dl_chair_002_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 5385, 71, 14417, bob_dl_chair_003_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 4282, 71, 13125, bob_dl_chair_004_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 4283, 71, 13528, bob_dl_chair_005_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 4483, 71, 13326, bob_dl_chair_007_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 4081, 71, 13327, bob_dl_chair_008_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 5705, 436, 13704, bob_dl_Medal_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 5705, 436, 14020, bob_dl_Medal_001_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 5705, 436, 14335, bob_dl_Medal_002_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 3569, 258, 14800, bob_dl_Painting_009_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 4278, 365, 13935, bob_dl_Parlor_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(4, 3575, 267, 12877, bob_dl_Plant_001_mesh_layer_4),
		GEO_TRANSLATE_NODE_WITH_DL(1, 3575, 267, 12877, bob_dl_Plant_002_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 3575, 267, 12877, bob_dl_Plant_003_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 5182, 66, 14419, bob_dl_Simple_Table_001_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 4280, 66, 13328, bob_dl_Simple_Table_002_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bob_dl_Room1D_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(1, 5562, 150, 17252, bob_dl_Canister_001_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 4800, 373, 16403, bob_dl_Garage_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(6, 4607, 0, 16746, bob_dl_OilFloor_mesh_layer_6),
		GEO_TRANSLATE_NODE_WITH_DL(1, 4800, 373, 16403, bob_dl_shelves_001_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 5168, 78, 18234, bob_dl_Tools_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 4321, 142, 17159, bob_dl_Truck_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 3669, 538, 18145, bob_dl_Wrench_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 3669, 538, 16870, bob_dl_Wrench_001_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 3669, 538, 16640, bob_dl_Wrench_002_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 3669, 673, 15443, bob_dl_Wrench_003_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 3669, 673, 15672, bob_dl_Wrench_004_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 3669, 135, 16021, bob_dl_Wrench_005_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 3669, 135, 16250, bob_dl_Wrench_006_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 3669, 269, 18039, bob_dl_Wrench_007_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 3669, 269, 17846, bob_dl_Wrench_008_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 3669, 404, 17229, bob_dl_Wrench_009_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 3669, 404, 17459, bob_dl_Wrench_010_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 3669, 269, 15525, bob_dl_Wrench_011_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 3669, 404, 16428, bob_dl_Wrench_012_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bob_dl_Room1E_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(1, 3364, 343, 9552, bob_dl_Barracade_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(4, -6230, 522, 9552, bob_dl_Bars_mesh_layer_4),
		GEO_TRANSLATE_NODE_WITH_DL(2, 5017, 0, 5678, bob_dl_Bookshelf_Col_003_mesh_layer_2),
		GEO_TRANSLATE_NODE_WITH_DL(2, 4085, 0, 7927, bob_dl_Bookshelf_Col_004_mesh_layer_2),
		GEO_TRANSLATE_NODE_WITH_DL(2, 22, 0, 7187, bob_dl_Bookshelf_Col_005_mesh_layer_2),
		GEO_TRANSLATE_NODE_WITH_DL(2, -3614, 0, 9088, bob_dl_Bookshelf_Col_006_mesh_layer_2),
		GEO_TRANSLATE_NODE_WITH_DL(2, -9871, 0, 3555, bob_dl_Bookshelf_Col_014_mesh_layer_2),
		GEO_TRANSLATE_NODE_WITH_DL(1, 4455, 415, 3822, bob_dl_Bookshelf_003_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -2720, 280, 2650, bob_dl_Bookshelf_004_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -4720, 280, 2650, bob_dl_Bookshelf_005_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -5169, 280, 2650, bob_dl_Bookshelf_006_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -7969, 280, 2650, bob_dl_Bookshelf_007_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -3720, 280, 3526, bob_dl_Bookshelf_008_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -6518, 280, 3526, bob_dl_Bookshelf_009_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -6068, 280, 3526, bob_dl_Bookshelf_010_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -10789, 280, 3088, bob_dl_Bookshelf_011_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -10789, 280, 3088, bob_dl_Bookshelf_013_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -4537, 0, 9140, bob_dl_Clock_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 4555, 375, 10154, bob_dl_Hallway_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 4099, 93, 7176, bob_dl_Side_Table_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 10, 93, 4889, bob_dl_Side_Table_001_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 5013, 93, 10457, bob_dl_Side_Table_002_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -906, 93, 7885, bob_dl_Side_Table_004_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(5, 4112, 80, 4022, bob_dl_SpiderWeb_001_mesh_layer_5),
		GEO_TRANSLATE_NODE_WITH_DL(5, 29, 80, 2626, bob_dl_SpiderWeb_002_mesh_layer_5),
		GEO_TRANSLATE_NODE_WITH_DL(5, 3833, 0, 9422, bob_dl_SpiderWeb_003_mesh_layer_5),
		GEO_TRANSLATE_NODE_WITH_DL(5, -2620, 0, 9664, bob_dl_SpiderWeb_004_mesh_layer_5),
		GEO_TRANSLATE_NODE_WITH_DL(5, -506, 0, 5637, bob_dl_SpiderWeb_005_mesh_layer_5),
		GEO_TRANSLATE_NODE_WITH_DL(1, 5013, 190, 10457, bob_dl_Vase_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -906, 190, 7885, bob_dl_Vase_002_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bob_dl_Room1F_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(1, 8979, 81, 3787, bob_dl_Cabinet_001_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 8331, 81, 3787, bob_dl_Cabinet_002_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 6793, 81, 3787, bob_dl_Cabinet_003_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 6469, 204, 3787, bob_dl_Cabinet_004_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 8655, 81, 3787, bob_dl_Cabinet_005_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 6690, 89, 6729, bob_dl_Dresser_001_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 5205, 431, 5678, bob_dl_Hallway_001_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 5435, 230, 6781, bob_dl_MRoomCrate_007_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 7990, 230, 6781, bob_dl_MRoomCrate_008_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 8911, 230, 6781, bob_dl_MRoomCrate_010_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 7191, 155, 5355, bob_dl_Plate_003_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 7195, 101, 5373, bob_dl_Table_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bob_dl_Room1G_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(1, 3230, 142, 8632, bob_dl_Barrel_Thing_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 2171, 99, 6513, bob_dl_chair_010_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 1674, 99, 6802, bob_dl_chair_011_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(2, 2922, 0, 7973, bob_dl_Grate_mesh_layer_2),
		GEO_TRANSLATE_NODE_WITH_DL(1, 447, 350, 7973, bob_dl_ice1_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 457, 115, 7986, bob_dl_ice2_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 2823, 375, 7681, bob_dl_Kitchen_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 588, 822, 8227, bob_dl_KitchenGround_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 2630, 213, 4941, bob_dl_KitchenGround_001_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 566, 431, 5752, bob_dl_KitchenGround_002_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 2351, 1083, 5535, bob_dl_KitchenGround_003_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 430, 350, 7753, bob_dl_KitchenGround_004_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(5, 2630, 213, 4941, bob_dl_KitchenGround_005_mesh_layer_5),
		GEO_TRANSLATE_NODE_WITH_DL(5, 730, 651, 8677, bob_dl_Loose_Shelf_001_mesh_layer_5),
		GEO_TRANSLATE_NODE_WITH_DL(1, 1922, 92, 6661, bob_dl_Simple_Table_003_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(5, 2922, 148, 7973, bob_dl_Steam_mesh_layer_5),
		GEO_TRANSLATE_NODE_WITH_DL(1, 2995, 0, 4865, bob_dl_Stove_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 2995, 0, 4865, bob_dl_Stove_001_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 2995, 0, 4865, bob_dl_Stove_002_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bob_dl_Room1H_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(1, 2823, 375, 7681, bob_dl_Kitchen_002_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 780, 305, 3995, bob_dl_Kitchen_003_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(5, 403, 87, 3902, bob_dl_SpiderWeb_mesh_layer_5),
		GEO_TRANSLATE_NODE_WITH_DL(5, 1177, 458, 3926, bob_dl_SpiderWeb_006_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bob_dl_Room1I_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(1, -3207, 280, 8677, bob_dl_Bookshelf_002_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(2, -4614, 0, 6798, bob_dl_Carpet_mesh_layer_2),
		GEO_TRANSLATE_NODE_WITH_DL(6, -4614, 0, 6798, bob_dl_CarpetEnd_mesh_layer_6),
		GEO_TRANSLATE_NODE_WITH_DL(1, -3235, 144, 5909, bob_dl_Couch_001_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -3211, 297, 5435, bob_dl_Couch_002_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -6722, -340, 6414, bob_dl_Couch_004_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -7159, -220, 5807, bob_dl_Couch_005_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -3211, 178, 7148, bob_dl_Couch_006_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -5252, 178, 8786, bob_dl_Couch_008_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -3614, 125, 8927, bob_dl_LivingRoom_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -4614, 100, 6798, bob_dl_LTable_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -8283, 775, 7391, bob_dl_Shelf_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -3847, 840, 5429, bob_dl_Shelf_001_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -4614, 100, 5695, bob_dl_TV_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bob_dl_Room1J_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(2, -8801, 163, 5660, bob_dl_Black_mesh_layer_2),
		GEO_TRANSLATE_NODE_WITH_DL(1, -11477, 2945, 11938, bob_dl_Board_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(2, bob_dl_Board_mesh_layer_2),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(1, -11158, 313, 6664, bob_dl_BucketStack_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -11835, 313, 8457, bob_dl_BucketStack_001_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -11198, 228, 8474, bob_dl_FancyChair_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -12179, 250, 7566, bob_dl_Fireplace_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -11775, 3058, 12238, bob_dl_FlipBooks_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -9088, 722, 8936, bob_dl_GBook_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -8801, 0, 4487, bob_dl_HalfPillar_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -8898, 1211, 7481, bob_dl_Light_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -9876, 125, 3763, bob_dl_Study_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bob_dl_Room1K_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(1, -9757, 983, 12805, bob_dl_Library_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(4, -10641, 2941, 17403, bob_dl_Library_001_mesh_layer_4),
		GEO_TRANSLATE_NODE_WITH_DL(1, -9757, 983, 12805, bob_dl_Library_003_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -9757, 983, 12805, bob_dl_Library_004_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(4, -9757, 983, 12805, bob_dl_Library_006_mesh_layer_4),
		GEO_TRANSLATE_NODE_WITH_DL(1, -5783, 1944, 16909, bob_dl_Library_007_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(4, -8258, 2319, 17142, bob_dl_Railing_mesh_layer_4),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bob_dl_Room1L_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(1, -9757, 983, 12805, bob_dl_QuickHall_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -4355, 1263, 17158, bob_dl_QuickHall_001_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bob_dl_Room1M_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(1, 1111, 531, 19291, bob_dl_MainHall_012_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 0, 163, 10414, bob_dl_MainHall_013_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bob_dl_Room1N_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(1, 1111, 531, 19291, bob_dl_MainHall_014_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bob_area_1[] = {
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
					GEO_BRANCH(1, bob_area_1_geo),
					GEO_RENDER_OBJ(),
					GEO_ASM(ENVFX_MODE_NONE, geo_envfx_main),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(1, bob_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(4, bob_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(6, bob_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(5, bob_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(2, bob_dl_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
