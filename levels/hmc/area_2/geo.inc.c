#include "src/game/envfx_snow.h"

const GeoLayout hmc_area_2_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SWITCH_CASE(13, geo_switch_area),
		GEO_OPEN_NODE(),
			GEO_BRANCH(1, hmc_dl_201__NULL_geo),
			GEO_BRANCH(1, hmc_dl_202__NULL_geo),
			GEO_BRANCH(1, hmc_dl_203__NULL_geo),
			GEO_BRANCH(1, hmc_dl_204__NULL_geo),
			GEO_BRANCH(1, hmc_dl_205__NULL_geo),
			GEO_BRANCH(1, hmc_dl_206__NULL_geo),
			GEO_BRANCH(1, hmc_dl_207__NULL_geo),
			GEO_BRANCH(1, hmc_dl_208__NULL_geo),
			GEO_BRANCH(1, hmc_dl_209__NULL_geo),
			GEO_BRANCH(1, hmc_dl_210__PreHouse_geo),
			GEO_BRANCH(1, hmc_dl_211__PreHouse2_geo),
			GEO_BRANCH(1, hmc_dl_212__Tree_House_geo),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout hmc_dl_201__NULL_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_NULLTri_mesh),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout hmc_dl_202__NULL_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_NULLTri_mesh),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout hmc_dl_203__NULL_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_NULLTri_mesh),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout hmc_dl_204__NULL_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_NULLTri_mesh),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout hmc_dl_205__NULL_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_NULLTri_mesh),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout hmc_dl_206__NULL_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_NULLTri_mesh),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout hmc_dl_207__NULL_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_NULLTri_mesh),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout hmc_dl_208__NULL_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_NULLTri_mesh),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout hmc_dl_209__NULL_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_NULLTri_mesh),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout hmc_dl_210__PreHouse_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ROTATION_NODE_WITH_DL(LAYER_OPAQUE, 0, 90, 0, hmc_dl_BBOutside_001_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_ALPHA, hmc_dl_BBOutside_001_mesh_layer_4),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_Foreroom_003_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, hmc_dl_Foreroom_003_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_Window_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, hmc_dl_Window_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, hmc_dl_Window_mesh_layer_6),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -65536, 0, 0, hmc_dl_Z5_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_ALPHA, hmc_dl_Z5_mesh_layer_4),
		GEO_CLOSE_NODE(),
		GEO_ROTATION_NODE_WITH_DL(LAYER_OPAQUE, 0, 90, 0, hmc_dl_Z6_mesh_layer_1),
		GEO_ROTATION_NODE_WITH_DL(LAYER_OPAQUE, 0, 90, 0, hmc_dl_Z7_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_Z8_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, hmc_dl_Z8_001_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_ALPHA, hmc_dl_ZZTallGrass_002_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_ZZTallGrass_002_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout hmc_dl_211__PreHouse2_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ROTATION_NODE_WITH_DL(LAYER_OPAQUE, 0, 90, 0, hmc_dl_Tree_002_mesh_layer_1),
		GEO_ROTATION_NODE_WITH_DL(LAYER_OPAQUE, 0, 90, 0, hmc_dl_Tree_003_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_ALPHA, hmc_dl_Tree_003_mesh_layer_4),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_Z7_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, hmc_dl_Z7_001_mesh_layer_4),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -65536, 0, 0, hmc_dl_Z8_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_ALPHA, hmc_dl_Z8_mesh_layer_4),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -65536, 0, 0, hmc_dl_Z9_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -65536, 0, 0, hmc_dl_Z9_001_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_ALPHA, hmc_dl_Z9_001_mesh_layer_4),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -65536, 0, 0, hmc_dl_Z9_003_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_ALPHA, hmc_dl_Z9_003_mesh_layer_4),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, hmc_dl_Z9_003_mesh_layer_6),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, hmc_dl_ZZTallGrass_001_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_ZZTallGrass_001_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout hmc_dl_212__Tree_House_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -494, 1113, -16615, hmc_dl_Log_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -494, 1113, -16615, hmc_dl_Tower_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_ALPHA, hmc_dl_Tower_mesh_layer_4),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -494, 1113, -16615, hmc_dl_Tower_001_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -494, 1113, -16615, hmc_dl_Tower_002_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_ALPHA, hmc_dl_Tower_002_mesh_layer_4),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -494, 1113, -16615, hmc_dl_Tower_003_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -494, 1113, -16615, hmc_dl_Tower_006_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_Z8_002_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, hmc_dl_Z9_002_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, hmc_dl_Z9_002_mesh_layer_6),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout hmc_area_2[] = {
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
				GEO_CAMERA(CAMERA_MODE_8_DIRECTIONS, 65536, 0, 0, 65536, -100, 0, geo_camera_main),
				GEO_OPEN_NODE(),
					GEO_BRANCH(1, hmc_area_2_geo),
					GEO_RENDER_OBJ(),
					GEO_ASM(ENVFX_MODE_NONE, geo_envfx_main),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_ALPHA, hmc_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, hmc_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, hmc_dl_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
