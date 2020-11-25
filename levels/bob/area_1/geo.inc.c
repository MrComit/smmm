#include "src/game/envfx_snow.h"

const GeoLayout bob_area_1_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SWITCH_CASE(6, geo_switch_area),
		GEO_OPEN_NODE(),
			GEO_BRANCH(1, bob_dl_Room1A_geo),
			GEO_BRANCH(1, bob_dl_Room1B_geo),
			GEO_BRANCH(1, bob_dl_Room1C_geo),
			GEO_BRANCH(1, bob_dl_Room1D_geo),
			GEO_BRANCH(1, bob_dl_Room1E_geo),
			GEO_BRANCH(1, bob_dl_Room1F_geo),
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
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 5593, 280, 12883, bob_dl_Bookshelf_001_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 4278, 365, 13935, bob_dl_Parlor_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 4706, 66, 13833, bob_dl_Simple_Table_001_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 4707, 71, 13631, bob_dl_chair_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 4708, 71, 14033, bob_dl_chair_001_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 4506, 71, 13832, bob_dl_chair_002_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 4909, 71, 13831, bob_dl_chair_003_mesh),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bob_dl_Room1D_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 4800, 373, 16403, bob_dl_Garage_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 4987, 142, 18023, bob_dl_Truck_mesh),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bob_dl_Room1E_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 4555, 375, 10154, bob_dl_Hallway_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 4893, 0, 10462, bob_dl_Vase_mesh),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bob_dl_Room1F_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 8655, 81, 3787, bob_dl_Cabinet_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 8979, 81, 3787, bob_dl_Cabinet_001_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 8331, 81, 3787, bob_dl_Cabinet_002_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 6793, 81, 3787, bob_dl_Cabinet_003_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 6469, 204, 3787, bob_dl_Cabinet_004_mesh),
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
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, bob_dl_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
