#include "src/game/envfx_snow.h"

const GeoLayout ttc_area_1_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SWITCH_CASE(2, geo_switch_area),
		GEO_OPEN_NODE(),
			GEO_BRANCH(1, ttc_dl_101__Main_geo),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ttc_dl_101__Main_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ttc_dl_TrophyRoom_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ttc_dl_TrophyRoom_002_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ttc_dl_TrophyRoom_003_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ttc_dl_TrophyRoom_006_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ttc_dl_TrophyRoom_013_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ttc_dl_Chess_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ttc_dl_Clothes_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ttc_dl_ClothesPile_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ttc_dl_PingPongTable_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ttc_dl_Rack_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ttc_dl_Rack_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, ttc_dl_Shirt_mesh_layer_4),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 4530, 4, 5900, ttc_dl_TideToad_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT, ttc_dl_TideToad_mesh_layer_5),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, ttc_dl_Bones_002_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ttc_dl_Bones_003_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ttc_dl_Bones_004_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ttc_dl_Skull_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ttc_dl_TortureChamber_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ttc_dl_TortureChamber_002_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ttc_dl_Treadmill_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ttc_dl_Weights_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ttc_dl_Checkered_Goal_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ttc_area_1[] = {
	GEO_NODE_SCREEN_AREA(10, SCREEN_WIDTH/2, SCREEN_HEIGHT/2, SCREEN_WIDTH/2, SCREEN_HEIGHT/2),
	GEO_OPEN_NODE(),
		GEO_ZBUFFER(0),
		GEO_OPEN_NODE(),
			GEO_NODE_ORTHO(100.0000),
			GEO_OPEN_NODE(),
				GEO_BACKGROUND(BACKGROUND_L8_SKY, geo_skybox_main),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_ZBUFFER(1),
		GEO_OPEN_NODE(),
			GEO_CAMERA_FRUSTUM_WITH_FUNC(45.0000, 100, 30000, geo_camera_fov),
			GEO_OPEN_NODE(),
				GEO_CAMERA(CAMERA_MODE_8_DIRECTIONS, 0, 0, 0, 0, -100, 0, geo_camera_main),
				GEO_OPEN_NODE(),
					GEO_BRANCH(1, ttc_area_1_geo),
					GEO_RENDER_OBJ(),
					GEO_ASM(ENVFX_MODE_NONE, geo_envfx_main),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ttc_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_ALPHA, ttc_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, ttc_dl_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
