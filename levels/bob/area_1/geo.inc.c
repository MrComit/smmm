#include "src/game/envfx_snow.h"

const GeoLayout bob_area_1_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SWITCH_CASE(9, geo_switch_area),
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
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bob_dl_Room1A_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 762, 280, 27350, bob_dl_Bookshelf_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -1242, 89, 28819, bob_dl_Dresser_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -1061, 303, 27499, bob_dl_Lamp_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 338, 28161, bob_dl_Mudroom_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE_DECAL, 0, 0, 28206, bob_dl_Mudroom_001_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT_DECAL, 0, 0, 28206, bob_dl_Mudroom_002_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE_DECAL, 0, 384, 28220, bob_dl_Mudroom_003_mesh),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bob_dl_Room1B_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -150, -129, 21568, bob_dl_MainHall_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 1111, 531, 19291, bob_dl_MainHall_001_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT_DECAL, 0, -206, 20465, bob_dl_MainHall_002_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, -206, 20467, bob_dl_MainHall_003_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 69, -200, 22509, bob_dl_MainHall_004_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -1188, -358, 20812, bob_dl_MainHall_005_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -1904, -284, 19070, bob_dl_MainHall_006_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 1049, -126, 22083, bob_dl_MainHall_007_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 947, 43, 16745, bob_dl_MainHall_008_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 729, -80, 18935, bob_dl_MainHall_009_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 1874, 117, 20844, bob_dl_MainHall_010_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 740, -66, 15598, bob_dl_MainHall_011_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT_DECAL, 22, 0, 26440, bob_dl_Mudroom_004_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -3276, 745, 22759, bob_dl_Painting_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -3276, 745, 24759, bob_dl_Painting_001_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -3276, 745, 20759, bob_dl_Painting_002_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 3276, 745, 21259, bob_dl_Painting_003_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 3276, 745, 19259, bob_dl_Painting_004_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 3276, 745, 23259, bob_dl_Painting_005_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 3276, 745, 25259, bob_dl_Painting_006_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -3276, 745, 18759, bob_dl_Painting_007_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -2533, 819, 25962, bob_dl_Pillar_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -1284, -233, 20603, bob_dl_Pillar_Tops_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 2956, 219, 25962, bob_dl_Pillar_001_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -1544, -113, 23059, bob_dl_Pillar_002_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -1336, -113, 22270, bob_dl_Pillar_003_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 1843, -71, 21834, bob_dl_Pillar_004_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 2604, 47, 21313, bob_dl_Pillar_005_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 1042, -71, 20600, bob_dl_Pillar_006_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -2375, -40, 22047, bob_dl_Pillar_007_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -2533, 819, 13277, bob_dl_Pillar_008_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 2633, 819, 13277, bob_dl_Pillar_009_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 61, 82, 22577, bob_dl_Simple_Table_mesh),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bob_dl_Room1C_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 5593, 280, 12933, bob_dl_Bookshelf_001_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 5705, 436, 13704, bob_dl_Medal_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 5705, 436, 14020, bob_dl_Medal_001_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 5705, 436, 14335, bob_dl_Medal_002_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 3569, 258, 14800, bob_dl_Painting_009_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 4278, 365, 13935, bob_dl_Parlor_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, 3575, 267, 12877, bob_dl_Plant_001_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 3575, 267, 12877, bob_dl_Plant_002_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 3575, 267, 12877, bob_dl_Plant_003_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 5182, 66, 14419, bob_dl_Simple_Table_001_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 4280, 66, 13328, bob_dl_Simple_Table_002_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 5183, 71, 14217, bob_dl_chair_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 5184, 71, 14619, bob_dl_chair_001_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 4983, 71, 14418, bob_dl_chair_002_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 5385, 71, 14417, bob_dl_chair_003_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 4282, 71, 13125, bob_dl_chair_004_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 4283, 71, 13528, bob_dl_chair_005_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 4483, 71, 13326, bob_dl_chair_007_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 4081, 71, 13327, bob_dl_chair_008_mesh),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bob_dl_Room1D_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 5562, 150, 17252, bob_dl_Canister_001_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 4800, 373, 16403, bob_dl_Garage_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT_DECAL, 4607, 0, 16746, bob_dl_OilFloor_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 5168, 78, 18234, bob_dl_Tools_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 4321, 142, 17159, bob_dl_Truck_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 3669, 538, 18145, bob_dl_Wrench_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 3669, 538, 16870, bob_dl_Wrench_001_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 3669, 538, 16640, bob_dl_Wrench_002_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 3669, 673, 15443, bob_dl_Wrench_003_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 3669, 673, 15672, bob_dl_Wrench_004_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 3669, 135, 16021, bob_dl_Wrench_005_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 3669, 135, 16250, bob_dl_Wrench_006_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 3669, 269, 18039, bob_dl_Wrench_007_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 3669, 269, 17846, bob_dl_Wrench_008_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 3669, 404, 17229, bob_dl_Wrench_009_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 3669, 404, 17459, bob_dl_Wrench_010_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 3669, 269, 15525, bob_dl_Wrench_011_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 3669, 404, 16428, bob_dl_Wrench_012_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 4800, 373, 16403, bob_dl_shelves_001_mesh),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bob_dl_Room1E_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 3364, 343, 9552, bob_dl_Barracade_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, -6230, 522, 9552, bob_dl_Bars_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE_DECAL, 5017, 0, 5678, bob_dl_Bookshelf_Col_003_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE_DECAL, 4085, 0, 7927, bob_dl_Bookshelf_Col_004_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE_DECAL, 22, 0, 7187, bob_dl_Bookshelf_Col_005_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE_DECAL, -3614, 0, 9088, bob_dl_Bookshelf_Col_006_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE_DECAL, -8771, 0, 3555, bob_dl_Bookshelf_Col_014_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 4455, 415, 3822, bob_dl_Bookshelf_003_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -1720, 280, 2650, bob_dl_Bookshelf_004_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -3720, 280, 2650, bob_dl_Bookshelf_005_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -4169, 280, 2650, bob_dl_Bookshelf_006_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -6969, 280, 2650, bob_dl_Bookshelf_007_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -2720, 280, 3526, bob_dl_Bookshelf_008_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -5518, 280, 3526, bob_dl_Bookshelf_009_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -5068, 280, 3526, bob_dl_Bookshelf_010_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -9689, 280, 3088, bob_dl_Bookshelf_011_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -4537, 0, 9140, bob_dl_Clock_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 4555, 375, 10154, bob_dl_Hallway_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT_DECAL, 4555, 375, 10154, bob_dl_Hallway_002_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 4099, 93, 7176, bob_dl_Side_Table_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 10, 93, 4889, bob_dl_Side_Table_001_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 5013, 93, 10457, bob_dl_Side_Table_002_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -906, 93, 7885, bob_dl_Side_Table_004_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT, 4112, 80, 4022, bob_dl_SpiderWeb_001_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT, 29, 80, 2626, bob_dl_SpiderWeb_002_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT_DECAL, 3833, 0, 9422, bob_dl_SpiderWeb_003_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT_DECAL, -2620, 0, 9664, bob_dl_SpiderWeb_004_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT_DECAL, -506, 0, 5637, bob_dl_SpiderWeb_005_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 5013, 190, 10457, bob_dl_Vase_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -906, 190, 7885, bob_dl_Vase_002_mesh),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bob_dl_Room1F_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 8979, 81, 3787, bob_dl_Cabinet_001_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 8331, 81, 3787, bob_dl_Cabinet_002_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 6793, 81, 3787, bob_dl_Cabinet_003_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 6469, 204, 3787, bob_dl_Cabinet_004_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 8655, 81, 3787, bob_dl_Cabinet_005_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 6690, 89, 6729, bob_dl_Dresser_001_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 5205, 431, 5678, bob_dl_Hallway_001_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 5435, 230, 6781, bob_dl_MRoomCrate_007_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 7990, 230, 6781, bob_dl_MRoomCrate_008_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 8911, 230, 6781, bob_dl_MRoomCrate_010_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 7191, 155, 5355, bob_dl_Plate_003_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 7195, 101, 5373, bob_dl_Table_mesh),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bob_dl_Room1G_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 3230, 142, 8632, bob_dl_Barrel_Thing_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE_DECAL, 2922, 0, 7973, bob_dl_Grate_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 2823, 375, 7681, bob_dl_Kitchen_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT_DECAL, 2630, -206, 2588, bob_dl_Kitchen_001_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 588, 822, 8227, bob_dl_KitchenGround_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 2630, 213, 4941, bob_dl_KitchenGround_001_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 566, 431, 5752, bob_dl_KitchenGround_002_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 2351, 1083, 5535, bob_dl_KitchenGround_003_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 430, 350, 7753, bob_dl_KitchenGround_004_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT, 2630, 213, 4941, bob_dl_KitchenGround_005_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT, 730, 651, 8677, bob_dl_Loose_Shelf_001_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 1922, 92, 6661, bob_dl_Simple_Table_003_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT, 2922, 148, 7973, bob_dl_Steam_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 2995, 0, 4865, bob_dl_Stove_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 2995, 0, 4865, bob_dl_Stove_001_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 2995, 0, 4865, bob_dl_Stove_002_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 2171, 99, 6513, bob_dl_chair_010_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 1674, 99, 6802, bob_dl_chair_011_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT, 447, 350, 7973, bob_dl_ice1_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT_DECAL, 457, 115, 7986, bob_dl_ice2_mesh),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bob_dl_Room1H_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 2823, 375, 7681, bob_dl_Kitchen_002_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT, 403, 87, 3902, bob_dl_SpiderWeb_mesh),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bob_dl_Room1I_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -3207, 280, 8677, bob_dl_Bookshelf_002_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE_DECAL, -4614, 0, 6798, bob_dl_Carpet_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT_DECAL, -4614, 0, 6798, bob_dl_CarpetEnd_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -3235, 144, 5909, bob_dl_Couch_001_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -3211, 297, 5435, bob_dl_Couch_002_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -6761, -302, 6384, bob_dl_Couch_004_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -7159, -239, 5807, bob_dl_Couch_005_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -3211, 178, 7148, bob_dl_Couch_006_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -5252, 178, 8786, bob_dl_Couch_008_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -4614, 100, 6798, bob_dl_LTable_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -3614, 125, 8927, bob_dl_LivingRoom_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT_DECAL, -7300, -300, 7245, bob_dl_LivingRoom_001_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -8283, 775, 7391, bob_dl_Shelf_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -3847, 840, 5429, bob_dl_Shelf_001_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -4614, 100, 5695, bob_dl_TV_mesh),
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
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_OPAQUE_DECAL, bob_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_ALPHA, bob_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, bob_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, bob_dl_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
