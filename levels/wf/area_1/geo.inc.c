#include "src/game/envfx_snow.h"

const GeoLayout wf_area_1_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SWITCH_CASE(6, geo_switch_area),
		GEO_OPEN_NODE(),
			GEO_BRANCH(1, wf_dl_01__Lounge_geo),
			GEO_BRANCH(1, wf_dl_02__Bar_geo),
			GEO_BRANCH(1, wf_dl_03__Balcony_geo),
			GEO_BRANCH(1, wf_dl_04__Bathroom_geo),
			GEO_BRANCH(1, wf_dl_05__Den_geo),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, 7647, 200, -17812),
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
		GEO_TRANSLATE_NODE_WITH_DL(2, 504, 420, -13084, wf_dl_Gate_Indicator_004_mesh_layer_2),
		GEO_TRANSLATE_NODE_WITH_DL(1, 4496, 2500, -10469, wf_dl_HalfPillar_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 0, 0, -17911, wf_dl_Hallway_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(2, 4896, 581, -5545, wf_dl_Hallway_002_mesh_layer_2),
		GEO_TRANSLATE_NODE_WITH_DL(1, 0, 0, -17911, wf_dl_Hallway_004_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(6, -443, 238, -7701, wf_dl_Hallway_005_mesh_layer_6),
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
		GEO_TRANSLATE_NODE_WITH_DL(1, 2485, -500, -3374, wf_dl_Plat_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 326, -500, -3155, wf_dl_Plat_001_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -143, -500, -2096, wf_dl_Plat_002_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 2585, -468, -1066, wf_dl_Plat_003_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 1097, -500, -134, wf_dl_Plat_004_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 864, -468, 4212, wf_dl_Plat_005_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 1560, -468, 4549, wf_dl_Plat_006_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 1458, -468, 5319, wf_dl_Plat_007_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -1344, 880, 264, wf_dl_Shelf_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 2817, 792, 6339, wf_dl_Shelf_001_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 1112, 106, 2102, wf_dl_Straw_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 2734, 106, 5093, wf_dl_Straw_001_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -922, -150, 265, wf_dl_Straw_002_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -922, -150, 266, wf_dl_Straw_003_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 2285, 106, 4397, wf_dl_Straw_004_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout wf_dl_03__Balcony_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(4, 3763, 2235, 14333, wf_dl_2dvine_mesh_layer_4),
		GEO_TRANSLATE_NODE_WITH_DL(4, 2865, 2934, 13522, wf_dl_2dvine_001_mesh_layer_4),
		GEO_TRANSLATE_NODE_WITH_DL(4, 3381, 2819, 13331, wf_dl_2dvine_002_mesh_layer_4),
		GEO_TRANSLATE_NODE_WITH_DL(1, 1017, 2226, 8638, wf_dl_Cloud_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 828, 2226, 9617, wf_dl_Cloud_015_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 40, 2226, 10736, wf_dl_Cloud_016_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 1049, 2226, 10752, wf_dl_Cloud_017_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 1726, 2226, 11666, wf_dl_Cloud_018_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 620, 2226, 11697, wf_dl_Cloud_019_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 710, 2226, 12528, wf_dl_Cloud_020_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 1860, 2226, 12591, wf_dl_Cloud_021_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 2003, 2226, 13549, wf_dl_Cloud_022_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 1073, 2226, 13693, wf_dl_Cloud_023_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 366, 2226, 14490, wf_dl_Cloud_024_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -41, 2226, 13471, wf_dl_Cloud_025_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -810, 2226, 14226, wf_dl_Cloud_026_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -381, 2226, 15128, wf_dl_Cloud_027_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 988, 2226, 15419, wf_dl_Cloud_028_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 1039, 109, 7990, wf_dl_Hallway_001_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(4, wf_dl_Hallway_001_mesh_layer_4),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(4, 1039, -1239, 11955, wf_dl_Hallway_006_mesh_layer_4),
		GEO_TRANSLATE_NODE_WITH_DL(1, 3726, 1453, 14334, wf_dl_Leaf_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 2827, 2152, 13523, wf_dl_Leaf_001_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 3401, 2036, 13330, wf_dl_Leaf_002_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(4, 1039, 2707, 26604, wf_dl_Moon_mesh_layer_4),
		GEO_TRANSLATE_NODE_WITH_DL(1, 1017, 116, 8638, wf_dl_PlantPlatform_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(6, wf_dl_PlantPlatform_mesh_layer_6),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(1, 828, 116, 9617, wf_dl_PlantPlatform_001_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(6, wf_dl_PlantPlatform_001_mesh_layer_6),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(1, 40, 116, 10736, wf_dl_PlantPlatform_002_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(6, wf_dl_PlantPlatform_002_mesh_layer_6),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(1, 1049, 116, 10752, wf_dl_PlantPlatform_003_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(6, wf_dl_PlantPlatform_003_mesh_layer_6),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(1, 1726, 116, 11666, wf_dl_PlantPlatform_004_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(6, wf_dl_PlantPlatform_004_mesh_layer_6),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(1, 620, 116, 11697, wf_dl_PlantPlatform_005_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(6, wf_dl_PlantPlatform_005_mesh_layer_6),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(1, 710, 116, 12528, wf_dl_PlantPlatform_006_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(6, wf_dl_PlantPlatform_006_mesh_layer_6),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(1, 1860, 116, 12591, wf_dl_PlantPlatform_007_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(6, wf_dl_PlantPlatform_007_mesh_layer_6),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(1, 2003, 116, 13549, wf_dl_PlantPlatform_008_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(6, wf_dl_PlantPlatform_008_mesh_layer_6),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(1, 1073, 116, 13693, wf_dl_PlantPlatform_009_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(6, wf_dl_PlantPlatform_009_mesh_layer_6),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(1, -41, 116, 13471, wf_dl_PlantPlatform_010_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(6, wf_dl_PlantPlatform_010_mesh_layer_6),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(1, -810, 116, 14226, wf_dl_PlantPlatform_011_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(6, wf_dl_PlantPlatform_011_mesh_layer_6),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(1, 366, 116, 14490, wf_dl_PlantPlatform_012_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(6, wf_dl_PlantPlatform_012_mesh_layer_6),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(1, -381, 116, 15128, wf_dl_PlantPlatform_013_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(6, wf_dl_PlantPlatform_013_mesh_layer_6),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(1, 988, 116, 15419, wf_dl_PlantPlatform_014_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(6, wf_dl_PlantPlatform_014_mesh_layer_6),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(1, -3142, 116, 11631, wf_dl_PlantPlatform_016_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(6, wf_dl_PlantPlatform_016_mesh_layer_6),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(1, 1247, 3011, 23359, wf_dl_Skybox_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 4742, -4000, 16013, wf_dl_Tree_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(4, wf_dl_Tree_mesh_layer_4),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(1, -550, 3764, 7795, wf_dl_WeatherVane_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout wf_dl_04__Bathroom_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(1, 2005, 582, -13493, wf_dl_Bathroom_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(5, wf_dl_Bathroom_mesh_layer_5),
			GEO_DISPLAY_LIST(2, wf_dl_Bathroom_mesh_layer_2),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(4, 2072, -2705, -15032, wf_dl_Bathroom_001_mesh_layer_4),
		GEO_TRANSLATE_NODE_WITH_DL(1, 924, -2274, -13081, wf_dl_Pipes_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 4023, -2423, -12959, wf_dl_Pipes_001_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 3616, -2274, -12978, wf_dl_Pipes_004_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 3663, -2777, -15059, wf_dl_Pipes_005_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(4, 2020, -2339, -13093, wf_dl_Scaffolding_001_mesh_layer_4),
		GEO_TRANSLATE_NODE_WITH_DL(1, 4701, 1312, -15299, wf_dl_Shelf_002_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(5, 3016, 148, -14191, wf_dl_Steam_mesh_layer_5),
		GEO_TRANSLATE_NODE_WITH_DL(1, 4568, 1250, -11727, wf_dl_Toilet_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout wf_dl_05__Den_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(1, 0, 0, -17911, wf_dl_Hallway_007_mesh_layer_1),
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
		GEO_DISPLAY_LIST(6, wf_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(4, wf_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(2, wf_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(1, wf_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(5, wf_dl_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
