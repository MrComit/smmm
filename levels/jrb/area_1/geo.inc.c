#include "src/game/envfx_snow.h"

const GeoLayout jrb_area_1_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SWITCH_CASE(5, geo_switch_area),
		GEO_OPEN_NODE(),
			GEO_BRANCH(1, jrb_dl_101__Garden_geo),
			GEO_BRANCH(1, jrb_dl_102__Dog_House_geo),
			GEO_BRANCH(1, jrb_dl_103__Underground_geo),
			GEO_BRANCH(1, jrb_dl_104__Conservatory_geo),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout jrb_dl_101__Garden_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(1, -4929, -388, -753, jrb_dl_DogHouseExterior_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -4929, -388, -753, jrb_dl_DogHouseExterior_001_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -1359, 637, 1787, jrb_dl_Ground_001_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(4, jrb_dl_Ground_001_mesh_layer_4),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(1, -1359, 637, 1787, jrb_dl_GroundBounds_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(4, -1097, -388, -1984, jrb_dl_TallGrass_mesh_layer_4),
		GEO_TRANSLATE_NODE_WITH_DL(4, -2031, -388, -1016, jrb_dl_TallGrass_001_mesh_layer_4),
		GEO_TRANSLATE_NODE_WITH_DL(4, 2679, -388, 2189, jrb_dl_TallGrass_002_mesh_layer_4),
		GEO_TRANSLATE_NODE_WITH_DL(4, -5588, -388, 2560, jrb_dl_TallGrass_003_mesh_layer_4),
		GEO_TRANSLATE_NODE_WITH_DL(1, 1777, -488, -11253, jrb_dl_Tree_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(4, jrb_dl_Tree_mesh_layer_4),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout jrb_dl_102__Dog_House_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(1, -4847, 417, -9094, jrb_dl_Black_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -5419, -427, -10335, jrb_dl_Bone_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -5477, -431, -9865, jrb_dl_Bone_001_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -5679, -431, -9594, jrb_dl_Bone_002_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -6335, -359, -9431, jrb_dl_Bone_003_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -4929, -388, -8753, jrb_dl_DogHouseExterior_003_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout jrb_dl_103__Underground_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(1, -2046, -1731, 2958, jrb_dl_Cave_003_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 0, 380, 0, jrb_dl_Ground_002_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 0, 380, 0, jrb_dl_Ground_003_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout jrb_dl_104__Conservatory_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(1, -3630, 1012, 7489, jrb_dl_Conservatory_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(5, jrb_dl_Conservatory_mesh_layer_5),
			GEO_DISPLAY_LIST(6, jrb_dl_Conservatory_mesh_layer_6),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(1, -3618, 1021, 8316, jrb_dl_Conservatory_001_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -4929, -388, -753, jrb_dl_DogHouseExterior_005_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 0, -488, 0, jrb_dl_Ground_004_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(4, jrb_dl_Ground_004_mesh_layer_4),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(1, -4573, -431, 5689, jrb_dl_Pot_001_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -4714, -431, 6034, jrb_dl_Pot_002_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -5878, 840, 4852, jrb_dl_Pot_003_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -4461, -431, 5405, jrb_dl_Pot_004_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -4830, 840, 4815, jrb_dl_Pot_005_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -4773, -431, 7097, jrb_dl_Pot_006_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -5348, 840, 4768, jrb_dl_Pot_007_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -3091, -431, 10214, jrb_dl_Pot_008_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -1492, -431, 4709, jrb_dl_Pot_009_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(4, -1492, -431, 4709, jrb_dl_Pot_010_mesh_layer_4),
		GEO_TRANSLATE_NODE_WITH_DL(4, -4773, -431, 7097, jrb_dl_Pot_011_mesh_layer_4),
		GEO_TRANSLATE_NODE_WITH_DL(4, -5348, 840, 4768, jrb_dl_Pot_012_mesh_layer_4),
		GEO_TRANSLATE_NODE_WITH_DL(4, -3091, -431, 10214, jrb_dl_Pot_013_mesh_layer_4),
		GEO_TRANSLATE_NODE_WITH_DL(1, -2497, -380, 10117, jrb_dl_Table_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout jrb_area_1[] = {
	GEO_NODE_SCREEN_AREA(10, SCREEN_WIDTH/2, SCREEN_HEIGHT/2, SCREEN_WIDTH/2, SCREEN_HEIGHT/2),
	GEO_OPEN_NODE(),
		GEO_ZBUFFER(0),
		GEO_OPEN_NODE(),
			GEO_NODE_ORTHO(100.0000),
			GEO_OPEN_NODE(),
				GEO_BACKGROUND(BACKGROUND_HAUNTED, geo_skybox_main),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_ZBUFFER(1),
		GEO_OPEN_NODE(),
			GEO_CAMERA_FRUSTUM_WITH_FUNC(45.0000, 100, 30000, geo_camera_fov),
			GEO_OPEN_NODE(),
				GEO_CAMERA(CAMERA_MODE_8_DIRECTIONS, 0, 0, 0, 0, -100, 0, geo_camera_main),
				GEO_OPEN_NODE(),
					GEO_BRANCH(1, jrb_area_1_geo),
					GEO_RENDER_OBJ(),
					GEO_ASM(ENVFX_MODE_NONE, geo_envfx_main),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(1, jrb_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(5, jrb_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(4, jrb_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(6, jrb_dl_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
