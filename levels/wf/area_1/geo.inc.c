#include "src/game/envfx_snow.h"

const GeoLayout wf_area_1_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SWITCH_CASE(19, geo_switch_area),
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
			GEO_BRANCH(1, wf_dl_18__Pool_Room_geo),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout wf_dl_01__Lounge_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_Bookshelf_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_Bookshelf_004_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, wf_dl_Bottle_007_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_Bottle_007_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, wf_dl_Bottle_008_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_Bottle_008_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, wf_dl_Bottle_009_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_Bottle_009_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, wf_dl_Bottle_010_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_Bottle_010_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_Chair_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_Chair_002_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_Chair_003_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_Chair_004_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_Couch_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_Couch_003_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_Gate_Indicator_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_Gate_Indicator_002_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_Gate_Indicator_003_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_Gate_Indicator_005_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE_DECAL, wf_dl_Gate_Indicator_005_mesh_layer_2),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_HalfPillar_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_Hallway_002_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_Hallway_004_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_Hallway_005_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, wf_dl_Hallway_007_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_ALPHA, wf_dl_Hallway_008_mesh_layer_4),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, 2000, wf_dl_Plant_001_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_ALPHA, wf_dl_Plant_001_mesh_layer_4),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_Simple_Table_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_Simple_Table_002_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_Simple_Table_003_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_ToFloor1_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_ToFloor1_001_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, 2000, wf_dl_ToFloor1_004_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, 2000, wf_dl_ToFloor1_005_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, 2000, wf_dl_TokenScreen_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout wf_dl_02__Bar_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT, 0, 0, -2000, wf_dl_Bottle_001_mesh_layer_5),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT, 0, 0, -2000, wf_dl_Bottle_002_mesh_layer_5),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT, 0, 0, -2000, wf_dl_Bottle_003_mesh_layer_5),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT, 0, 0, -2000, wf_dl_Bottle_004_mesh_layer_5),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT, 0, 0, -2000, wf_dl_Bottle_005_mesh_layer_5),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_ALPHA, wf_dl_Bottle_005_mesh_layer_4),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_Hallway_003_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, -2000, wf_dl_Plat_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, -2000, wf_dl_Plat_001_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, -2000, wf_dl_Plat_002_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, -2000, wf_dl_Plat_003_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, -2000, wf_dl_Plat_004_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, -2000, wf_dl_Plat_005_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, -2000, wf_dl_Plat_006_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, -2000, wf_dl_Plat_007_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, -2000, wf_dl_Plat_008_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, -2000, wf_dl_Shelf_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, -2000, wf_dl_Shelf_001_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, -2000, wf_dl_Straw_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, -2000, wf_dl_Straw_001_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, -2000, wf_dl_Straw_002_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, -2000, wf_dl_Straw_003_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, -2000, wf_dl_Straw_004_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout wf_dl_03__Balcony_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, 0, 0, 2000, wf_dl_2dvine_mesh_layer_4),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, 0, 0, 2000, wf_dl_2dvine_001_mesh_layer_4),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, 0, 0, 2000, wf_dl_2dvine_002_mesh_layer_4),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, -2000, wf_dl_Cloud_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, -2000, wf_dl_Cloud_015_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, -2000, wf_dl_Cloud_016_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, -2000, wf_dl_Cloud_017_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, -2000, wf_dl_Cloud_018_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, -2000, wf_dl_Cloud_019_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, -2000, wf_dl_Cloud_020_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, -2000, wf_dl_Cloud_021_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, -2000, wf_dl_Cloud_022_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, -2000, wf_dl_Cloud_023_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, -2000, wf_dl_Cloud_024_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, -2000, wf_dl_Cloud_025_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, -2000, wf_dl_Cloud_026_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, -2000, wf_dl_Cloud_027_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, -2000, wf_dl_Cloud_028_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, 2000, wf_dl_Hallway_001_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_ALPHA, wf_dl_Hallway_001_mesh_layer_4),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, wf_dl_Hallway_006_mesh_layer_4),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, 2000, wf_dl_Leaf_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, 2000, wf_dl_Leaf_001_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, 2000, wf_dl_Leaf_002_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, 0, 0, -2000, wf_dl_Moon_mesh_layer_4),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, -2000, wf_dl_PlantPlatform_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, wf_dl_PlantPlatform_mesh_layer_6),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, -2000, wf_dl_PlantPlatform_001_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, wf_dl_PlantPlatform_001_mesh_layer_6),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, -2000, wf_dl_PlantPlatform_002_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, wf_dl_PlantPlatform_002_mesh_layer_6),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, -2000, wf_dl_PlantPlatform_003_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, wf_dl_PlantPlatform_003_mesh_layer_6),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, -2000, wf_dl_PlantPlatform_004_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, wf_dl_PlantPlatform_004_mesh_layer_6),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, -2000, wf_dl_PlantPlatform_005_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, wf_dl_PlantPlatform_005_mesh_layer_6),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, -2000, wf_dl_PlantPlatform_006_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, wf_dl_PlantPlatform_006_mesh_layer_6),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, -2000, wf_dl_PlantPlatform_007_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, wf_dl_PlantPlatform_007_mesh_layer_6),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, -2000, wf_dl_PlantPlatform_008_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, wf_dl_PlantPlatform_008_mesh_layer_6),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, -2000, wf_dl_PlantPlatform_009_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, wf_dl_PlantPlatform_009_mesh_layer_6),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, -2000, wf_dl_PlantPlatform_010_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, wf_dl_PlantPlatform_010_mesh_layer_6),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, -2000, wf_dl_PlantPlatform_011_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, wf_dl_PlantPlatform_011_mesh_layer_6),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, -2000, wf_dl_PlantPlatform_012_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, wf_dl_PlantPlatform_012_mesh_layer_6),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, -2000, wf_dl_PlantPlatform_013_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, wf_dl_PlantPlatform_013_mesh_layer_6),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, -2000, wf_dl_PlantPlatform_014_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, wf_dl_PlantPlatform_014_mesh_layer_6),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, -2000, wf_dl_PlantPlatform_016_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, wf_dl_PlantPlatform_016_mesh_layer_6),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, -2000, wf_dl_Skybox_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, 2000, wf_dl_Tree_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, 0, 0, 2000, wf_dl_Tree_001_mesh_layer_4),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, -2000, wf_dl_WeatherVane_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout wf_dl_04__Bathroom_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_Bathroom_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, wf_dl_Bathroom_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_ALPHA, wf_dl_Bathroom_001_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_Bathroom_002_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT_DECAL, 0, 0, 2000, wf_dl_OilFloor_mesh_layer_6),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, -2000, wf_dl_Pipes_002_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_Platforms_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, 0, 0, -2000, wf_dl_Scaffolding_001_mesh_layer_4),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, -2000, wf_dl_Shelf_003_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, -2000, wf_dl_Sink_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, -2000, wf_dl_Sink_001_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT, wf_dl_Sink_001_mesh_layer_5),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, 2000, wf_dl_Soap_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, 2000, wf_dl_Soap_001_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT, 0, 0, -2000, wf_dl_Steam_mesh_layer_5),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, -2000, wf_dl_Toilet_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT, wf_dl_Toilet_mesh_layer_5),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout wf_dl_05__Den_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE_DECAL, 0, 0, -2000, wf_dl_Carpet_001_mesh_layer_2),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, -2000, wf_dl_Couch_008_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_Den_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, -2000, wf_dl_FancyChair_002_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_LightWindow_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, -2000, wf_dl_Plant_002_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_ALPHA, wf_dl_Plant_002_mesh_layer_4),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, 2000, wf_dl_Shelf_004_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_Skybox_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_WindowFrame_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout wf_dl_06__Mirror_Room_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_Crate_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_Crate_002_mesh_layer_1),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, 0, 0, -2000),
		GEO_OPEN_NODE(),
			GEO_ASM(0, geo_render_mirror_mario),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_FunctionNode_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, 2000, wf_dl_LightButton_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, 2000, wf_dl_LightButton_003_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, 2000, wf_dl_LightButton_005_mesh_layer_1),
		GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, wf_dl_Mirror_Room_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT, wf_dl_Mirror_Room_mesh_layer_5),
		GEO_CLOSE_NODE(),
		GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, wf_dl_Mirror_Room_001_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout wf_dl_07__Bedroom_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ASM(0, geo_set_room_color_env),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_AAA_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, 2000, wf_dl_Bed_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_Bedroom_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, 2000, wf_dl_Box_001_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, 2000, wf_dl_Box_002_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, 2000, wf_dl_Box_003_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, 2000, wf_dl_Box_004_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, 2000, wf_dl_Box_005_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, 2000, wf_dl_Box_006_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, 2000, wf_dl_Box_007_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, 2000, wf_dl_Box_008_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, 2000, wf_dl_Box_010_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, 2000, wf_dl_Dresser_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, 2000, wf_dl_Dresser_001_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, 2000, wf_dl_Skateboard_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout wf_dl_08__Bedroom2_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ASM(1, geo_set_room_color_env),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_AAA_001_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, 2000, wf_dl_Ball_003_mesh),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_Bed_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_Bedroom_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_Bedroom_004_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, 2000, wf_dl_Chest_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, 2000, wf_dl_Chest_001_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, 2000, wf_dl_Chest_002_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_Dresser_005_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, 2000, wf_dl_Mirror_002_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout wf_dl_09__Wardrobe_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_Bedroom_005_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, 2000, wf_dl_Rack_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, 2000, wf_dl_Rack_001_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, 0, 0, 2000, wf_dl_Shirt_mesh_layer_4),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, 2000, wf_dl_Shoes_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, 2000, wf_dl_Shoes_001_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout wf_dl_10__Bedroom3_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ASM(3, geo_set_room_color_env),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_AAA_002_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_Bedroom_002_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, 2000, wf_dl_Car_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, 2000, wf_dl_Car_001_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, 2000, wf_dl_Crib_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_Dresser_002_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, 2000, wf_dl_LetterBlock_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, 2000, wf_dl_LetterBlock_001_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, 2000, wf_dl_LetterBlock_002_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, 2000, wf_dl_LetterBlock_003_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, 2000, wf_dl_LetterBlock_005_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, 2000, wf_dl_LetterBlock_006_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, 2000, wf_dl_LetterBlock_007_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, 2000, wf_dl_LetterBlock_008_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout wf_dl_11__Bedroom4_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ASM(4, geo_set_room_color_env),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_AAA_003_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, 2000, wf_dl_Bed_003_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, 2000, wf_dl_Bed_004_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_Bedroom_003_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, 2000, wf_dl_Book_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, 2000, wf_dl_Book_004_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, 2000, wf_dl_Book_008_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, 2000, wf_dl_Book_014_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, 2000, wf_dl_Book_015_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, 2000, wf_dl_Book_017_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, 2000, wf_dl_Book_018_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, 2000, wf_dl_Book_019_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, 2000, wf_dl_Bookshelf_001_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, 2000, wf_dl_Bookshelf_002_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, 2000, wf_dl_Dresser_003_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout wf_dl_B_geo[] = {
	GEO_TRANSLATE_NODE(LAYER_OPAQUE, 12662, 1029, -2960),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -12662, -1029, 4960, wf_dl_B_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout wf_dl_C_geo[] = {
	GEO_TRANSLATE_NODE(LAYER_OPAQUE, 12662, 1029, -2960),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -12662, -1029, 4960, wf_dl_C_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout wf_dl_BB_geo[] = {
	GEO_TRANSLATE_NODE(LAYER_OPAQUE, 12662, 1029, -2960),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -12662, -1029, 4960, wf_dl_BB_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout wf_dl_CC_geo[] = {
	GEO_TRANSLATE_NODE(LAYER_OPAQUE, 12662, 1029, -2960),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -12662, -1029, 4960, wf_dl_CC_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout wf_dl_12__Servant_s_Quarters_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, 0, 0, 2000),
		GEO_OPEN_NODE(),
			GEO_ASM(5, geo_set_room_color_env),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_AAA_004_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, 2000, wf_dl_Light_002_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, 2000, wf_dl_Light_003_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, 2000, wf_dl_Light_004_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, 2000, wf_dl_Light_005_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, 2000, wf_dl_Light_006_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, 2000, wf_dl_Light_007_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, 2000, wf_dl_Light_008_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, 2000, wf_dl_Light_009_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, 2000, wf_dl_Platform_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, 2000, wf_dl_Platform_005_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_Servant_s_Quarters_mesh_layer_1),
		GEO_SWITCH_CASE(2, geo_switch_servants_wall),
		GEO_OPEN_NODE(),
			GEO_BRANCH(1, wf_dl_B_geo),
			GEO_BRANCH(1, wf_dl_C_geo),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -12662, -1029, 4960, wf_dl_A_mesh_layer_1),
		GEO_SWITCH_CASE(2, geo_switch_servants_wall_2),
		GEO_OPEN_NODE(),
			GEO_BRANCH(1, wf_dl_BB_geo),
			GEO_BRANCH(1, wf_dl_CC_geo),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -12662, -1029, 4960, wf_dl_AA_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout wf_dl_13__Office_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, 2000, wf_dl_Chair_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_Desk_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_Dresser_004_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_Dresser_006_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_Dresser_007_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_Office_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, 2000, wf_dl_Paper_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, 2000, wf_dl_Paper_001_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, 2000, wf_dl_Paper_002_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, 2000, wf_dl_Phone_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, 2000, wf_dl_Simple_Table_001_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, 2000, wf_dl_Stapler_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout wf_dl_14__Master_Bedroom_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, 0, 0, 2000),
		GEO_OPEN_NODE(),
			GEO_ASM(7, geo_set_room_color_env),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_AAA_005_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_Bed_002_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, 2000, wf_dl_Bookshelf_003_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, 2000, wf_dl_Couch_001_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, 2000, wf_dl_Crate_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, 2000, wf_dl_Dresser_009_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_Light_010_mesh),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_Light_011_mesh),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_Light_012_mesh),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_Light_013_mesh),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_Light_014_mesh),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_Master_Bedroom_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout wf_dl_15__Hallway_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_Master_Bedroom_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_ToFloor1_002_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout wf_dl_16__Hallway_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_Hallway_010_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout wf_dl_17__Play_Room_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, 2000, wf_dl_Block_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_Hallway_011_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, 2000, wf_dl_Playset_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT, wf_dl_Playset_mesh_layer_5),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, 2000, wf_dl_Table_001_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout wf_dl_18__Pool_Room_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_Hallway_012_mesh_layer_1),
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
