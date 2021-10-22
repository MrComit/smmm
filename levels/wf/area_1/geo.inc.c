#include "src/game/envfx_snow.h"

const GeoLayout wf_area_1_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SWITCH_CASE(18, geo_switch_area),
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
			GEO_BRANCH(1, wf_dl_15__Hallway_geo),
			GEO_BRANCH(1, wf_dl_16__Hallway_geo),
			GEO_BRANCH(1, wf_dl_17__Play_Room_geo),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout wf_dl_01__Lounge_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 1689, 280, -11057, 90, 0, 0, wf_dl_Bookshelf_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 2689, 280, -4973, 90, 0, 180, wf_dl_Bookshelf_004_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_TRANSPARENT, -531, 244, -6923, 90, 0, 0, wf_dl_Bottle_007_mesh_layer_5),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_Bottle_007_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_TRANSPARENT, -484, 244, -7109, 90, 0, 34, wf_dl_Bottle_008_mesh_layer_5),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_Bottle_008_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_TRANSPARENT, -2714, 244, -8793, 90, 0, 63, wf_dl_Bottle_009_mesh_layer_5),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_Bottle_009_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_TRANSPARENT, -2528, 244, -8837, 90, 0, 97, wf_dl_Bottle_010_mesh_layer_5),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_Bottle_010_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -2389, 71, -8963, 90, 0, 56, wf_dl_Chair_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -2820, 71, -8660, 90, 0, -124, wf_dl_Chair_002_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -415, 71, -7265, 90, 0, 19, wf_dl_Chair_003_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -578, 71, -6763, 90, 0, -161, wf_dl_Chair_004_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 3123, 178, -11053, 90, 0, 180, wf_dl_Couch_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 1389, 178, -7481, 90, 0, -71, wf_dl_Couch_003_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 228, 525, -12114, wf_dl_Gate_Indicator_001_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -5472, 420, -8870, wf_dl_Gate_Indicator_002_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 1031, 525, -4886, wf_dl_Gate_Indicator_003_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -5472, 420, -8870, wf_dl_Gate_Indicator_005_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE_DECAL, wf_dl_Gate_Indicator_005_mesh_layer_2),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 4496, 2500, -10469, wf_dl_HalfPillar_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 1178, 399, -15502, wf_dl_Hallway_002_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -5426, 603, -8207, wf_dl_Hallway_004_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 1021, 333, -9999, wf_dl_Hallway_005_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT, -438, 238, -7706, wf_dl_Hallway_007_mesh_layer_5),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, 1021, 333, -9999, wf_dl_Hallway_008_mesh_layer_4),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -231, 267, -4999, 90, 0, 0, wf_dl_Plant_001_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_ALPHA, wf_dl_Plant_001_mesh_layer_4),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -2616, 82, -8816, 90, 0, 56, wf_dl_Simple_Table_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -509, 82, -7011, 90, 0, 19, wf_dl_Simple_Table_002_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -3040, -133, -10229, 90, 0, 36, wf_dl_Simple_Table_003_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 7100, 163, -18730, 0, -180, 0, wf_dl_ToFloor1_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 7100, 163, -18730, 0, -180, 0, wf_dl_ToFloor1_001_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -1831, 177, -5810, wf_dl_TokenScreen_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout wf_dl_02__Bar_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_TRANSPARENT, -397, -333, -699, 0, 131, -30, wf_dl_Bottle_001_mesh_layer_5),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_TRANSPARENT, 3732, 396, 772, 71, -97, 20, wf_dl_Bottle_002_mesh_layer_5),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_TRANSPARENT, -1083, -115, 5351, 14, -2, 151, wf_dl_Bottle_003_mesh_layer_5),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_TRANSPARENT, -842, 360, -3928, 86, -27, 124, wf_dl_Bottle_004_mesh_layer_5),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_TRANSPARENT, 1245, 1572, 630, -90, 0, 0, wf_dl_Bottle_005_mesh_layer_5),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_ALPHA, wf_dl_Bottle_005_mesh_layer_4),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 1709, 244, 136, wf_dl_Hallway_003_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 2485, -500, -3374, wf_dl_Plat_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 326, -500, -3155, wf_dl_Plat_001_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -143, -500, -2096, 0, -151, 0, wf_dl_Plat_002_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 2585, -468, -1066, 0, 87, 0, wf_dl_Plat_003_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 1097, -500, -134, 0, 129, 0, wf_dl_Plat_004_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 864, -468, 4212, 0, 87, 0, wf_dl_Plat_005_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 1560, -468, 4549, 0, 132, 0, wf_dl_Plat_006_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 1458, -468, 5319, 0, 27, 0, wf_dl_Plat_007_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -394, -500, 5968, 0, -62, 0, wf_dl_Plat_008_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -1344, 880, 264, wf_dl_Shelf_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 2817, 792, 6339, 0, 90, 0, wf_dl_Shelf_001_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 1112, 106, 2102, wf_dl_Straw_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 2734, 106, 5093, wf_dl_Straw_001_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -922, -150, 265, wf_dl_Straw_002_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -922, -150, 266, wf_dl_Straw_003_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 2285, 106, 4397, wf_dl_Straw_004_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout wf_dl_03__Balcony_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_ALPHA, 3763, 2235, 14333, 0, 37, -90, wf_dl_2dvine_mesh_layer_4),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_ALPHA, 2872, 2934, 13552, 0, 37, -90, wf_dl_2dvine_001_mesh_layer_4),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_ALPHA, 3374, 2819, 13314, 0, 37, -90, wf_dl_2dvine_002_mesh_layer_4),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 1017, 2226, 8638, wf_dl_Cloud_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 828, 2226, 9617, wf_dl_Cloud_015_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 40, 2226, 10736, wf_dl_Cloud_016_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 1049, 2226, 10752, wf_dl_Cloud_017_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 1726, 2226, 11666, wf_dl_Cloud_018_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 620, 2226, 11697, wf_dl_Cloud_019_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 710, 2226, 12528, wf_dl_Cloud_020_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 1860, 2226, 12591, wf_dl_Cloud_021_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 2003, 2226, 13549, wf_dl_Cloud_022_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 1073, 2226, 13693, wf_dl_Cloud_023_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 366, 2226, 14490, wf_dl_Cloud_024_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -41, 2226, 13471, wf_dl_Cloud_025_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -810, 2226, 14226, wf_dl_Cloud_026_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -381, 2226, 15128, wf_dl_Cloud_027_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 988, 2226, 15419, wf_dl_Cloud_028_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 1039, 109, 7990, wf_dl_Hallway_001_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_ALPHA, wf_dl_Hallway_001_mesh_layer_4),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, 1039, -1239, 11955, wf_dl_Hallway_006_mesh_layer_4),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 3716, 1453, 14311, 0, 60, 0, wf_dl_Leaf_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 2832, 2152, 13679, 0, 157, 0, wf_dl_Leaf_001_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 3374, 2036, 13321, 0, 29, 0, wf_dl_Leaf_002_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_ALPHA, 1039, 2707, 26604, 90, 0, 0, wf_dl_Moon_mesh_layer_4),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 1017, 116, 8638, wf_dl_PlantPlatform_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, wf_dl_PlantPlatform_mesh_layer_6),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 828, 116, 9617, wf_dl_PlantPlatform_001_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, wf_dl_PlantPlatform_001_mesh_layer_6),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 40, 116, 10736, wf_dl_PlantPlatform_002_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, wf_dl_PlantPlatform_002_mesh_layer_6),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 1049, 116, 10752, wf_dl_PlantPlatform_003_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, wf_dl_PlantPlatform_003_mesh_layer_6),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 1726, 116, 11666, wf_dl_PlantPlatform_004_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, wf_dl_PlantPlatform_004_mesh_layer_6),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 620, 116, 11697, wf_dl_PlantPlatform_005_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, wf_dl_PlantPlatform_005_mesh_layer_6),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 710, 116, 12528, wf_dl_PlantPlatform_006_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, wf_dl_PlantPlatform_006_mesh_layer_6),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 1860, 116, 12591, wf_dl_PlantPlatform_007_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, wf_dl_PlantPlatform_007_mesh_layer_6),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 2003, 116, 13549, wf_dl_PlantPlatform_008_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, wf_dl_PlantPlatform_008_mesh_layer_6),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 1073, 116, 13693, wf_dl_PlantPlatform_009_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, wf_dl_PlantPlatform_009_mesh_layer_6),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -41, 116, 13471, wf_dl_PlantPlatform_010_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, wf_dl_PlantPlatform_010_mesh_layer_6),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -810, 116, 14226, wf_dl_PlantPlatform_011_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, wf_dl_PlantPlatform_011_mesh_layer_6),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 366, 116, 14490, wf_dl_PlantPlatform_012_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, wf_dl_PlantPlatform_012_mesh_layer_6),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -381, 116, 15128, wf_dl_PlantPlatform_013_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, wf_dl_PlantPlatform_013_mesh_layer_6),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 988, 116, 15419, wf_dl_PlantPlatform_014_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, wf_dl_PlantPlatform_014_mesh_layer_6),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -3142, 116, 11631, wf_dl_PlantPlatform_016_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, wf_dl_PlantPlatform_016_mesh_layer_6),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 1247, 3011, 23359, 90, 0, 0, wf_dl_Skybox_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 4742, -4000, 16013, wf_dl_Tree_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, 4955, 7622, 13630, wf_dl_Tree_001_mesh_layer_4),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -550, 3764, 7795, 0, -180, 0, wf_dl_WeatherVane_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout wf_dl_04__Bathroom_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 2005, 582, -13493, wf_dl_Bathroom_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT, wf_dl_Bathroom_mesh_layer_5),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, 2072, -2705, -15032, wf_dl_Bathroom_001_mesh_layer_4),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 3243, 142, -15059, wf_dl_Bathroom_002_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_TRANSPARENT_DECAL, 2341, 0, -15223, 90, 0, -64, wf_dl_OilFloor_mesh_layer_6),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 3809, -2284, -15016, 0, 90, -90, wf_dl_Pipes_002_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 2005, 582, -13493, wf_dl_Platforms_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, 2020, -2339, -13093, wf_dl_Scaffolding_001_mesh_layer_4),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 2754, 1132, -14760, 0, 90, 0, wf_dl_Shelf_003_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 1408, 34, -13660, 90, 0, 180, wf_dl_Sink_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 1408, 34, -13660, 90, 0, 180, wf_dl_Sink_001_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT, wf_dl_Sink_001_mesh_layer_5),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 1019, 115, -14139, 0, 0, 26, wf_dl_Soap_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 1105, 890, -14739, 0, -154, -90, wf_dl_Soap_001_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_TRANSPARENT, 3016, 148, -14191, 90, 0, 0, wf_dl_Steam_mesh_layer_5),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 4568, 1250, -11727, 90, 0, 0, wf_dl_Toilet_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT, wf_dl_Toilet_mesh_layer_5),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout wf_dl_05__Den_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE_DECAL, -3207, 0, -18703, wf_dl_Carpet_001_mesh_layer_2),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -5178, 178, -19832, 90, 0, 180, wf_dl_Couch_008_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, -17911, wf_dl_Den_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -914, 198, -19769, 90, 0, -100, wf_dl_FancyChair_002_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -5707, 213, -18703, 0, 0, -90, wf_dl_LightWindow_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -5483, 267, -17652, 90, 0, 0, wf_dl_Plant_002_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_ALPHA, wf_dl_Plant_002_mesh_layer_4),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -5607, 707, -18725, wf_dl_Shelf_004_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -3264, 1984, -21251, 90, 0, 180, wf_dl_Skybox_001_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, -17911, wf_dl_WindowFrame_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout wf_dl_06__Mirror_Room_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -5971, 164, -17542, wf_dl_Crate_001_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -5971, 164, -22449, wf_dl_Crate_002_mesh_layer_1),
		GEO_ROTATION_NODE(LAYER_OPAQUE, 90, 0, -45),
		GEO_OPEN_NODE(),
			GEO_ASM(0, geo_render_mirror_mario),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_FunctionNode_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -9807, 181, -19012, 90, 0, -90, wf_dl_LightButton_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -9807, 181, -21045, 90, 0, -90, wf_dl_LightButton_003_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -5807, 213, -21353, 90, 0, 90, wf_dl_LightButton_005_mesh_layer_1),
		GEO_ANIMATED_PART(LAYER_OPAQUE, -7514, 604, -18275, wf_dl_Mirror_Room_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT, wf_dl_Mirror_Room_mesh_layer_5),
		GEO_CLOSE_NODE(),
		GEO_ANIMATED_PART(LAYER_OPAQUE, -7514, 604, -21782, wf_dl_Mirror_Room_001_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout wf_dl_07__Bedroom_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, -11244, 604, -9345),
		GEO_OPEN_NODE(),
			GEO_ASM(0, geo_set_room_color_env),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_AAA_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -4829, 0, -11059, 90, 0, 90, wf_dl_Bed_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -5472, 604, -10140, wf_dl_Bedroom_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -5995, 95, -11083, 90, 0, 18, wf_dl_Box_001_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -4601, 95, -10568, 90, 0, 18, wf_dl_Box_002_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -4621, 285, -10490, 90, 0, 18, wf_dl_Box_003_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -4769, 95, -9931, 90, 0, -8, wf_dl_Box_004_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -5933, 95, -9547, 90, 0, -8, wf_dl_Box_005_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -5927, 285, -9557, 90, 0, -36, wf_dl_Box_006_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -5964, 475, -9600, 90, 0, -71, wf_dl_Box_007_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -6130, 95, -10415, 90, 0, 67, wf_dl_Box_008_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -4695, 86, -9519, 90, 0, 18, wf_dl_Box_010_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -6353, 89, -11067, wf_dl_Dresser_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -6353, 89, -9960, wf_dl_Dresser_001_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -5128, 34, -9592, 90, 0, -98, wf_dl_Skateboard_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout wf_dl_08__Bedroom2_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, -11244, 604, -10683),
		GEO_OPEN_NODE(),
			GEO_ASM(1, geo_set_room_color_env),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_AAA_001_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -4689, 78, -12544, wf_dl_Ball_003_mesh),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -6242, 0, -13033, 90, 0, 0, wf_dl_Bed_001_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -5472, 604, -12264, wf_dl_Bedroom_001_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -4472, 125, -12033, wf_dl_Bedroom_004_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -5174, 0, -13233, 90, 0, 0, wf_dl_Chest_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -4729, 0, -11663, 90, 0, 90, wf_dl_Chest_001_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -6224, 0, -11593, 90, 0, -131, wf_dl_Chest_002_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -4770, 95, -13092, 0, -90, 0, wf_dl_Dresser_005_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -4656, 179, -13207, 68, -45, -90, wf_dl_Mirror_002_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout wf_dl_09__Wardrobe_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -4208, 125, -12033, wf_dl_Bedroom_005_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -3972, 120, -12198, wf_dl_Rack_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -3972, 120, -11854, wf_dl_Rack_001_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_ALPHA, -3840, 124, -12198, 0, -180, -90, wf_dl_Shirt_mesh_layer_4),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -4313, 7, -11786, 90, 0, 27, wf_dl_Shoes_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -3851, 7, -12290, 90, 0, 163, wf_dl_Shoes_001_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout wf_dl_10__Bedroom3_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, -10955, 604, -11737),
		GEO_OPEN_NODE(),
			GEO_ASM(3, geo_set_room_color_env),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_AAA_002_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -7572, 604, -12264, wf_dl_Bedroom_002_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -8227, 38, -12182, 90, 0, -31, wf_dl_Car_mesh),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -8354, 38, -11642, 90, 0, 44, wf_dl_Car_001_mesh),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -8359, 209, -13213, 90, 0, 0, wf_dl_Crib_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -6796, 89, -13271, 0, -90, 0, wf_dl_Dresser_002_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -7698, 81, -12592, 0, 111, 0, wf_dl_LetterBlock_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -7627, 81, -11899, 0, 13, 0, wf_dl_LetterBlock_001_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -6868, 244, -11628, wf_dl_LetterBlock_002_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -7018, 81, -12931, 0, -58, 0, wf_dl_LetterBlock_003_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -6844, 81, -11609, 0, -75, 0, wf_dl_LetterBlock_005_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -6778, 81, -12717, 0, -167, 0, wf_dl_LetterBlock_006_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -6903, 406, -11639, 0, 36, 0, wf_dl_LetterBlock_007_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -7352, 81, -12051, 0, -48, 0, wf_dl_LetterBlock_008_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout wf_dl_11__Bedroom4_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, -11297, 604, -13133),
		GEO_OPEN_NODE(),
			GEO_ASM(4, geo_set_room_color_env),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_AAA_003_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -8216, 0, -9521, 90, 0, -90, wf_dl_Bed_003_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -6929, 0, -9521, 90, 0, 90, wf_dl_Bed_004_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -7572, 604, -10164, wf_dl_Bedroom_003_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -8231, 129, -10010, 90, 0, -140, wf_dl_Book_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -8252, 190, -11149, 0, -149, -90, wf_dl_Book_004_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -6572, 0, -9812, 180, 0, 0, wf_dl_Book_008_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -7074, 129, -10733, 90, 0, -102, wf_dl_Book_014_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -7247, 11, -10253, 0, -145, -90, wf_dl_Book_015_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -7856, 11, -10238, 0, 16, -90, wf_dl_Book_017_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -7722, 11, -10440, 0, -61, -90, wf_dl_Book_018_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -7469, 11, -10419, 0, 58, -90, wf_dl_Book_019_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -6797, 280, -11178, 90, 0, 0, wf_dl_Bookshelf_001_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -8460, 280, -10341, 90, 0, -90, wf_dl_Bookshelf_002_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -8275, 95, -10992, wf_dl_Dresser_003_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout wf_dl_B_geo[] = {
	GEO_TRANSLATE_NODE(LAYER_OPAQUE, 12662, 1029, -2960),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -4293, -129, 999, wf_dl_B_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout wf_dl_C_geo[] = {
	GEO_TRANSLATE_NODE(LAYER_OPAQUE, 12662, 1029, -2960),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -4293, -129, 999, wf_dl_C_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout wf_dl_BB_geo[] = {
	GEO_TRANSLATE_NODE(LAYER_OPAQUE, 12662, 1029, -2960),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -2514, 3, 1351, wf_dl_BB_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout wf_dl_CC_geo[] = {
	GEO_TRANSLATE_NODE(LAYER_OPAQUE, 12662, 1029, -2960),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -1001, 3, 3523, 0, 90, 0, wf_dl_CC_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout wf_dl_12__Servant_s_Quarters_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, -11297, 604, -11133),
		GEO_OPEN_NODE(),
			GEO_ASM(5, geo_set_room_color_env),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_AAA_004_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 6035, 1034, -4232, 135, 0, -90, wf_dl_Light_002_mesh),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 6035, 634, -1339, 45, 0, 90, wf_dl_Light_003_mesh),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 8215, 634, -4232, 135, 0, -90, wf_dl_Light_004_mesh),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 8015, 1034, -1339, 45, 0, 90, wf_dl_Light_005_mesh),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 9995, 1034, -4232, 135, 0, -90, wf_dl_Light_006_mesh),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 9995, 634, -1339, 45, 0, 90, wf_dl_Light_007_mesh),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 11975, 634, -4232, 135, 0, -90, wf_dl_Light_008_mesh),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 11975, 1034, -1339, 45, 0, 90, wf_dl_Light_009_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 5151, -30, -2802, wf_dl_Platform_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 10226, -139, -2306, 0, -180, 0, wf_dl_Platform_005_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 10006, 316, -2781, wf_dl_Servant_s_Quarters_mesh_layer_1),
		GEO_SWITCH_CASE(2, geo_switch_servants_wall),
		GEO_OPEN_NODE(),
			GEO_BRANCH(1, wf_dl_B_geo),
			GEO_BRANCH(1, wf_dl_C_geo),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -2480, -129, 4068, 0, -90, 0, wf_dl_A_mesh_layer_1),
		GEO_SWITCH_CASE(2, geo_switch_servants_wall_2),
		GEO_OPEN_NODE(),
			GEO_BRANCH(1, wf_dl_BB_geo),
			GEO_BRANCH(1, wf_dl_CC_geo),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -864, 3, 3252, 0, 90, 0, wf_dl_AA_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout wf_dl_13__Office_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 17471, 582, -2918, 90, 0, 180, wf_dl_Chair_001_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 17747, 560, -3348, 0, -90, 0, wf_dl_Desk_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 16437, 560, -1507, wf_dl_Dresser_004_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 16664, 738, -942, 0, 90, 0, wf_dl_Dresser_006_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 16885, 560, -1754, 0, 34, 0, wf_dl_Dresser_007_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 18469, 769, -3417, wf_dl_Office_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 20606, 1087, -2965, 90, 0, 90, wf_dl_Paper_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 19979, 200, -4267, 90, 0, 46, wf_dl_Paper_001_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 16106, 948, -2965, 90, 0, -90, wf_dl_Paper_002_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 16975, 669, -2972, 0, 0, -90, wf_dl_Phone_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 18538, 713, -5023, 90, 0, 0, wf_dl_Simple_Table_001_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 16926, 677, -2724, 0, 90, -90, wf_dl_Stapler_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout wf_dl_14__Master_Bedroom_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, -11553, 825, -2327),
		GEO_OPEN_NODE(),
			GEO_ASM(7, geo_set_room_color_env),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_AAA_005_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -8981, 0, -6514, 90, 0, 0, wf_dl_Bed_002_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -4484, 280, -6800, 90, 0, 90, wf_dl_Bookshelf_003_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -6911, 145, -3033, 90, 0, 0, wf_dl_Couch_001_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -4536, 164, -5309, wf_dl_Crate_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -8196, 95, -6727, wf_dl_Dresser_009_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -9308, 456, -3305, 45, -90, 90, wf_dl_Light_010_mesh),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -9308, 456, -3889, 45, -90, 90, wf_dl_Light_011_mesh),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -9308, 456, -4474, 45, -90, 90, wf_dl_Light_012_mesh),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -9308, 456, -5059, 45, -90, 90, wf_dl_Light_013_mesh),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -9308, 456, -5643, 45, -90, 90, wf_dl_Light_014_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -6922, 900, -4991, wf_dl_Master_Bedroom_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout wf_dl_15__Hallway_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -3449, 1333, -3628, wf_dl_Master_Bedroom_001_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -3389, 465, -2882, 0, -90, 0, wf_dl_ToFloor1_002_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout wf_dl_16__Hallway_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 1021, 333, -9999, wf_dl_Hallway_010_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout wf_dl_17__Play_Room_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 1021, 333, -9999, wf_dl_Hallway_011_mesh_layer_1),
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
		GEO_DISPLAY_LIST(LAYER_OPAQUE_DECAL, wf_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_ALPHA, wf_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, wf_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, wf_dl_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
