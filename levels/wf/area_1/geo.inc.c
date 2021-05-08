#include "src/game/envfx_snow.h"

const GeoLayout wf_area_1_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SWITCH_CASE(15, geo_switch_area),
		GEO_OPEN_NODE(),
			GEO_BRANCH(1, wf_dl_01__Lounge_geo),
			GEO_BRANCH(1, wf_dl_02__Bar_geo),
			GEO_BRANCH(1, wf_dl_03__Balcony_geo),
			GEO_BRANCH(1, wf_dl_04__Bathroom_geo),
			GEO_BRANCH(1, wf_dl_05__Den_geo),
			GEO_BRANCH(1, wf_dl_06__Mirror_Room_geo),
			GEO_BRANCH(1, wf_dl_07__Bedroom_geo),
			GEO_BRANCH(1, wf_dl_08__Bedroom2_geo),
			GEO_BRANCH(1, wf_dl_09__Wardrobe_geo),
			GEO_BRANCH(1, wf_dl_10__Bedroom3_geo),
			GEO_BRANCH(1, wf_dl_11__Bedroom4_geo),
			GEO_BRANCH(1, wf_dl_12__Servant_s_Quarters_geo),
			GEO_BRANCH(1, wf_dl_13__Office_geo),
			GEO_BRANCH(1, wf_dl_14__Master_Bedroom_geo),
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
		GEO_TRANSLATE_NODE_WITH_DL(2, -5472, 420, -8870, wf_dl_Gate_Indicator_005_mesh_layer_2),
		GEO_TRANSLATE_NODE_WITH_DL(1, 4496, 2500, -10469, wf_dl_HalfPillar_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(2, 4896, 581, -5545, wf_dl_Hallway_002_mesh_layer_2),
		GEO_TRANSLATE_NODE_WITH_DL(1, -5426, 603, -8207, wf_dl_Hallway_004_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(6, 1021, 333, -9999, wf_dl_Hallway_005_mesh_layer_6),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(1, wf_dl_Hallway_005_mesh_layer_1),
			GEO_DISPLAY_LIST(2, wf_dl_Hallway_005_mesh_layer_2),
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
		GEO_TRANSLATE_NODE_WITH_DL(1, 1709, 244, 136, wf_dl_Hallway_003_mesh_layer_1),
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
		GEO_TRANSLATE_NODE_WITH_DL(4, 2872, 2934, 13552, wf_dl_2dvine_001_mesh_layer_4),
		GEO_TRANSLATE_NODE_WITH_DL(4, 3374, 2819, 13314, wf_dl_2dvine_002_mesh_layer_4),
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
		GEO_TRANSLATE_NODE_WITH_DL(1, 3716, 1453, 14311, wf_dl_Leaf_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 2832, 2152, 13679, wf_dl_Leaf_001_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 3374, 2036, 13321, wf_dl_Leaf_002_mesh_layer_1),
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
		GEO_TRANSLATE_NODE_WITH_DL(4, 4955, 7622, 13630, wf_dl_Tree_001_mesh_layer_4),
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
		GEO_TRANSLATE_NODE_WITH_DL(1, 3809, -2284, -15016, wf_dl_Pipes_002_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 2005, 582, -13493, wf_dl_Platforms_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(4, 2020, -2339, -13093, wf_dl_Scaffolding_001_mesh_layer_4),
		GEO_TRANSLATE_NODE_WITH_DL(1, 2754, 1132, -14760, wf_dl_Shelf_003_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 1408, 34, -13660, wf_dl_Sink_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 1408, 34, -13660, wf_dl_Sink_001_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(5, wf_dl_Sink_001_mesh_layer_5),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(5, 3016, 148, -14191, wf_dl_Steam_mesh_layer_5),
		GEO_TRANSLATE_NODE_WITH_DL(1, 4568, 1250, -11727, wf_dl_Toilet_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(5, wf_dl_Toilet_mesh_layer_5),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout wf_dl_05__Den_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(6, -3207, 0, -18703, wf_dl_Carpet_001_mesh_layer_6),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(2, wf_dl_Carpet_001_mesh_layer_2),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(1, -5178, 178, -19832, wf_dl_Couch_008_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 0, 0, -17911, wf_dl_Den_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -914, 198, -19769, wf_dl_FancyChair_002_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -5707, 213, -18703, wf_dl_LightWindow_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -5483, 267, -17652, wf_dl_Plant_002_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(4, wf_dl_Plant_002_mesh_layer_4),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(1, -5607, 707, -18725, wf_dl_Shelf_004_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -3264, 1984, -21251, wf_dl_Skybox_001_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 0, 0, -17911, wf_dl_WindowFrame_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout wf_dl_06__Mirror_Room_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ASM(0, geo_render_mirror_mario),
		GEO_DISPLAY_LIST(1, wf_dl_FunctionNode_mesh_layer_1),
		GEO_ANIMATED_PART(1, -7514, 604, -18275, wf_dl_Mirror_Room_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(5, wf_dl_Mirror_Room_mesh_layer_5),
		GEO_CLOSE_NODE(),
		GEO_ANIMATED_PART(1, -7514, 604, -21782, wf_dl_Mirror_Room_001_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout wf_dl_07__Bedroom_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, -11244, 604, -9345),
		GEO_OPEN_NODE(),
			GEO_ASM(0, geo_set_room_color_env),
			GEO_DISPLAY_LIST(1, wf_dl_AAA_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(1, -4829, 0, -11059, wf_dl_Bed_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -5472, 604, -10140, wf_dl_Bedroom_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -5995, 95, -11083, wf_dl_Box_001_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -4601, 95, -10568, wf_dl_Box_002_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -4621, 285, -10490, wf_dl_Box_003_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -4769, 95, -9931, wf_dl_Box_004_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -5933, 95, -9547, wf_dl_Box_005_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -5927, 285, -9557, wf_dl_Box_006_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -5964, 475, -9600, wf_dl_Box_007_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -6130, 95, -10415, wf_dl_Box_008_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -6016, 95, -10751, wf_dl_Box_009_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -4695, 86, -9519, wf_dl_Box_010_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -6353, 89, -11067, wf_dl_Dresser_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -6353, 89, -9960, wf_dl_Dresser_001_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -5128, 34, -9592, wf_dl_Skateboard_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout wf_dl_08__Bedroom2_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, -11244, 604, -10683),
		GEO_OPEN_NODE(),
			GEO_ASM(1, geo_set_room_color_env),
			GEO_DISPLAY_LIST(1, wf_dl_AAA_001_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -4689, 78, -12544, wf_dl_Ball_003_mesh),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(1, wf_dl_Ball_003_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(1, -6242, 0, -13033, wf_dl_Bed_001_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -5472, 604, -12264, wf_dl_Bedroom_001_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -4472, 125, -12033, wf_dl_Bedroom_004_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -5174, 0, -13233, wf_dl_Chest_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -4729, 0, -11663, wf_dl_Chest_001_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -6224, 0, -11593, wf_dl_Chest_002_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -4770, 95, -13092, wf_dl_Dresser_005_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -4656, 179, -13207, wf_dl_Mirror_002_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout wf_dl_09__Wardrobe_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(1, -4208, 125, -12033, wf_dl_Bedroom_005_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout wf_dl_10__Bedroom3_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, -10955, 604, -11737),
		GEO_OPEN_NODE(),
			GEO_ASM(3, geo_set_room_color_env),
			GEO_DISPLAY_LIST(1, wf_dl_AAA_002_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(1, -7572, 604, -12264, wf_dl_Bedroom_002_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -8227, 38, -12182, wf_dl_Car_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -8354, 38, -11642, wf_dl_Car_001_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(1, -8359, 209, -13213, wf_dl_Crib_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -6796, 89, -13271, wf_dl_Dresser_002_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -7698, 81, -12592, wf_dl_LetterBlock_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -7627, 81, -11899, wf_dl_LetterBlock_001_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -6868, 244, -11628, wf_dl_LetterBlock_002_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -7018, 81, -12931, wf_dl_LetterBlock_003_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -7074, 244, -12962, wf_dl_LetterBlock_004_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -6844, 81, -11609, wf_dl_LetterBlock_005_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -6778, 81, -12717, wf_dl_LetterBlock_006_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -6903, 406, -11639, wf_dl_LetterBlock_007_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -7352, 81, -12051, wf_dl_LetterBlock_008_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout wf_dl_11__Bedroom4_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, -11297, 604, -13133),
		GEO_OPEN_NODE(),
			GEO_ASM(4, geo_set_room_color_env),
			GEO_DISPLAY_LIST(1, wf_dl_AAA_003_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(1, -8216, 0, -9521, wf_dl_Bed_003_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -6929, 0, -9521, wf_dl_Bed_004_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -7572, 604, -10164, wf_dl_Bedroom_003_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -8231, 129, -10010, wf_dl_Book_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -8252, 190, -11149, wf_dl_Book_004_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -6572, 0, -9812, wf_dl_Book_008_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -7074, 129, -10733, wf_dl_Book_014_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -7247, 11, -10253, wf_dl_Book_015_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -7453, 11, -9959, wf_dl_Book_016_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -7856, 11, -10238, wf_dl_Book_017_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -7722, 11, -10440, wf_dl_Book_018_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -7469, 11, -10419, wf_dl_Book_019_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -6797, 280, -11178, wf_dl_Bookshelf_001_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -8460, 280, -10341, wf_dl_Bookshelf_002_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -8275, 95, -10992, wf_dl_Dresser_003_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout wf_dl_B_geo[] = {
	GEO_TRANSLATE_NODE(LAYER_OPAQUE, 12662, 1029, -2960),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(1, -4293, -129, 999, wf_dl_B_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout wf_dl_C_geo[] = {
	GEO_TRANSLATE_NODE(LAYER_OPAQUE, 12662, 1029, -2960),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(1, -4293, -129, 999, wf_dl_C_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout wf_dl_BB_geo[] = {
	GEO_TRANSLATE_NODE(LAYER_OPAQUE, 12662, 1029, -2960),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(1, -2514, 3, 1351, wf_dl_BB_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout wf_dl_CC_geo[] = {
	GEO_TRANSLATE_NODE(LAYER_OPAQUE, 12662, 1029, -2960),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(1, -1001, 3, 3523, wf_dl_CC_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout wf_dl_12__Servant_s_Quarters_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, -11297, 604, -11133),
		GEO_OPEN_NODE(),
			GEO_ASM(5, geo_set_room_color_env),
			GEO_DISPLAY_LIST(1, wf_dl_AAA_004_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 6035, 1034, -4232, wf_dl_Light_002_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 6035, 634, -1339, wf_dl_Light_003_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 8215, 634, -4232, wf_dl_Light_004_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 8015, 1034, -1339, wf_dl_Light_005_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 9995, 1034, -4232, wf_dl_Light_006_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 9995, 634, -1339, wf_dl_Light_007_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 11975, 634, -4232, wf_dl_Light_008_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 11975, 1034, -1339, wf_dl_Light_009_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(1, 5151, -30, -2802, wf_dl_Platform_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 10226, -139, -2306, wf_dl_Platform_005_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 10006, 316, -2781, wf_dl_Servant_s_Quarters_mesh_layer_1),
		GEO_SWITCH_CASE(2, geo_switch_servants_wall),
		GEO_OPEN_NODE(),
			GEO_BRANCH(1, wf_dl_B_geo),
			GEO_BRANCH(1, wf_dl_C_geo),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(1, -2480, -129, 4068, wf_dl_A_mesh_layer_1),
		GEO_SWITCH_CASE(2, geo_switch_servants_wall_2),
		GEO_OPEN_NODE(),
			GEO_BRANCH(1, wf_dl_BB_geo),
			GEO_BRANCH(1, wf_dl_CC_geo),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(1, -864, 3, 3252, wf_dl_AA_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout wf_dl_13__Office_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(1, 17471, 582, -2918, wf_dl_Chair_001_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 17747, 560, -3348, wf_dl_Desk_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 16437, 560, -1507, wf_dl_Dresser_004_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 16664, 738, -942, wf_dl_Dresser_006_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 16885, 560, -1754, wf_dl_Dresser_007_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 18469, 769, -3417, wf_dl_Office_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 18538, 713, -5023, wf_dl_Simple_Table_001_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout wf_dl_14__Master_Bedroom_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, -11553, 825, -2327),
		GEO_OPEN_NODE(),
			GEO_ASM(7, geo_set_room_color_env),
			GEO_DISPLAY_LIST(1, wf_dl_AAA_005_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(1, -8981, 0, -6514, wf_dl_Bed_002_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -4484, 280, -6800, wf_dl_Bookshelf_003_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -6911, 145, -3033, wf_dl_Couch_001_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -4536, 164, -5309, wf_dl_Crate_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -8196, 95, -6727, wf_dl_Dresser_009_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -9308, 456, -3305, wf_dl_Light_010_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -9308, 456, -3889, wf_dl_Light_011_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -9308, 456, -4474, wf_dl_Light_012_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -9308, 456, -5059, wf_dl_Light_013_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -9308, 456, -5643, wf_dl_Light_014_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(1, -6922, 900, -4991, wf_dl_Master_Bedroom_mesh_layer_1),
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
				GEO_CAMERA(CAMERA_MODE_8_DIRECTIONS, 0, 0, -2000, 0, -100, -2000, geo_camera_main),
				GEO_OPEN_NODE(),
					GEO_BRANCH(1, wf_area_1_geo),
					GEO_RENDER_OBJ(),
					GEO_ASM(ENVFX_MODE_NONE, geo_envfx_main),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(5, wf_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(1, wf_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(4, wf_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(2, wf_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(6, wf_dl_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
