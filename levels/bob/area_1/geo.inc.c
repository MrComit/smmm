#include "src/game/envfx_snow.h"

const GeoLayout bob_area_1_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SWITCH_CASE(2, geo_switch_area),
		GEO_OPEN_NODE(),
			GEO_BRANCH(1, bob_dl_Room1A_geo),
			GEO_BRANCH(1, bob_dl_Room1B_geo),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bob_dl_Room1A_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 945, 26, 27248, bob_dl_Bookshelf_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -1271, 89, 28819, bob_dl_Dresser_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -1057, 0, 27507, bob_dl_Lamp_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 1261, 100, 29142, bob_dl_MRoomCrate_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 1061, 100, 29142, bob_dl_MRoomCrate_001_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 861, 100, 29142, bob_dl_MRoomCrate_002_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 1061, 300, 29142, bob_dl_MRoomCrate_003_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -1261, 100, 29142, bob_dl_MRoomCrate_004_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, 28245, bob_dl_Mudroom_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE_DECAL, 0, 0, 28206, bob_dl_Mudroom_001_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT_DECAL, 0, -169, 28206, bob_dl_Mudroom_002_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE_DECAL, 0, 384, 28245, bob_dl_Mudroom_003_mesh),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bob_dl_Room1B_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -3205, 100, 26948, bob_dl_MRoomCrate_005_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -3205, 300, 26948, bob_dl_MRoomCrate_006_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -3205, 500, 26948, bob_dl_MRoomCrate_007_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -3205, 700, 26948, bob_dl_MRoomCrate_008_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -42, -149, 22860, bob_dl_MainHall_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, 28197, bob_dl_MainHall_001_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT_DECAL, 0, 0, 28197, bob_dl_MainHall_002_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -42, -149, 22860, bob_dl_MainHall_003_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 126, 0, 22586, bob_dl_MainHall_004_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -1188, -358, 20812, bob_dl_MainHall_005_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -1988, -284, 19107, bob_dl_MainHall_006_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 809, -207, 21997, bob_dl_MainHall_007_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 755, 389, 17542, bob_dl_MainHall_008_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 755, 494, 19073, bob_dl_MainHall_009_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 1874, 153, 20844, bob_dl_MainHall_010_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT_DECAL, 20, -169, 26559, bob_dl_Mudroom_004_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -3283, 745, 22759, bob_dl_Painting_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -3283, 745, 24759, bob_dl_Painting_001_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -3283, 745, 20759, bob_dl_Painting_002_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 3283, 745, 21259, bob_dl_Painting_003_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 3283, 745, 19259, bob_dl_Painting_004_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 3283, 745, 23259, bob_dl_Painting_005_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 3283, 745, 25259, bob_dl_Painting_006_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -3283, 745, 18759, bob_dl_Painting_007_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -2533, 0, 25962, bob_dl_Pillar_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -1284, -233, 20603, bob_dl_Pillar_Tops_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 2524, -924, 25962, bob_dl_Pillar_001_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -1695, -949, 22654, bob_dl_Pillar_002_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -907, -949, 22316, bob_dl_Pillar_003_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 1843, -1290, 21925, bob_dl_Pillar_004_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 2604, -1174, 21324, bob_dl_Pillar_005_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 1042, -1290, 20485, bob_dl_Pillar_006_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 64, 0, 22575, bob_dl_Simple_Table_mesh),
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
