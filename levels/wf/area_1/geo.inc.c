#include "src/game/envfx_snow.h"

const GeoLayout wf_area_1_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SWITCH_CASE(3, geo_switch_area),
		GEO_OPEN_NODE(),
			GEO_BRANCH(1, wf_dl_01__Lounge_geo),
			GEO_BRANCH(1, wf_dl_02__Bar_geo),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout wf_dl_01__Lounge_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(1, 1689, 280, -11057, wf_dl_Bookshelf_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 933, 71, -7550, wf_dl_Chair_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 1439, 178, -8026, wf_dl_Couch_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(2, -42, 420, -11149, wf_dl_Gate_Indicator_mesh_layer_2),
		GEO_TRANSLATE_NODE_WITH_DL(2, 1031, 420, -4881, wf_dl_Gate_Indicator_001_mesh_layer_2),
		GEO_TRANSLATE_NODE_WITH_DL(2, -4052, 420, -8015, wf_dl_Gate_Indicator_002_mesh_layer_2),
		GEO_TRANSLATE_NODE_WITH_DL(2, 3559, 420, -5720, wf_dl_Gate_Indicator_003_mesh_layer_2),
		GEO_TRANSLATE_NODE_WITH_DL(1, 4496, 2500, -10469, wf_dl_HalfPillar_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 0, 0, -17911, wf_dl_Hallway_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(2, 4896, 581, -5545, wf_dl_Hallway_002_mesh_layer_2),
		GEO_TRANSLATE_NODE_WITH_DL(1, 0, 0, -17911, wf_dl_Hallway_004_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(6, -443, 238, -7701, wf_dl_Hallway_005_mesh_layer_6),
		GEO_TRANSLATE_NODE_WITH_DL(1, -3337, 175, -5810, wf_dl_Jail_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(4, wf_dl_Jail_mesh_layer_4),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(1, 1142, 82, -7141, wf_dl_Simple_Table_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 7100, 163, -18730, wf_dl_ToFloor1_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout wf_dl_02__Bar_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(5, -397, -333, -699, wf_dl_Bottle_001_mesh_layer_5),
		GEO_TRANSLATE_NODE_WITH_DL(5, 3732, 396, 772, wf_dl_Bottle_002_mesh_layer_5),
		GEO_TRANSLATE_NODE_WITH_DL(5, -1083, -115, 5351, wf_dl_Bottle_003_mesh_layer_5),
		GEO_TRANSLATE_NODE_WITH_DL(5, -842, 360, -3928, wf_dl_Bottle_004_mesh_layer_5),
		GEO_TRANSLATE_NODE_WITH_DL(1, 0, 0, -17911, wf_dl_Hallway_003_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(4, 1120, -132, 1070, wf_dl_Lemon_mesh_layer_4),
		GEO_TRANSLATE_NODE_WITH_DL(1, 2485, -500, -3374, wf_dl_Plat_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 326, -500, -3155, wf_dl_Plat_001_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -143, -500, -2096, wf_dl_Plat_002_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 2585, -468, -1066, wf_dl_Plat_003_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 1097, -500, -134, wf_dl_Plat_004_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -1344, 880, 264, wf_dl_Shelf_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 2817, 792, 6339, wf_dl_Shelf_001_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 1116, 106, 2228, wf_dl_Straw_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 2734, 106, 5093, wf_dl_Straw_001_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -922, -150, 265, wf_dl_Straw_002_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -922, -150, 266, wf_dl_Straw_003_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout wf_area_1[] = {
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
					GEO_BRANCH(1, wf_area_1_geo),
					GEO_RENDER_OBJ(),
					GEO_ASM(ENVFX_MODE_NONE, geo_envfx_main),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(2, wf_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(4, wf_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(1, wf_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(6, wf_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(5, wf_dl_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
