#include "src/game/envfx_snow.h"

const GeoLayout bbh_area_1_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SWITCH_CASE(3, geo_switch_area),
		GEO_OPEN_NODE(),
			GEO_BRANCH(1, bbh_dl_101__Oasis_geo),
			GEO_BRANCH(1, bbh_dl_102__Tunnel_geo),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bbh_dl_101__Oasis_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 3744, 200, 2615, 0, -112, 0),
		GEO_DISPLAY_LIST(LAYER_ALPHA, bbh_dl_DesertShrubs_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_ALPHA, bbh_dl_Flower_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bbh_dl_Grass_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, bbh_dl_Grass_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, bbh_dl_Grass_mesh_layer_6),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bbh_dl_Grass_001_mesh_layer_1),
		GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, -4100, 2700, 2125, 0, 14, 0),
		GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 1273, 1500, 4986, 0, 89, 0),
		GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, -1753, 1849, 4604, 0, 59, 0),
		GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 1321, 2239, -5773, 0, 89, 0),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bbh_dl_PIllars_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bbh_dl_PIllars_002_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bbh_dl_Plats_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bbh_dl_Rope_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bbh_dl_Sign_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bbh_dl_Slingshot_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bbh_dl_Tunnel_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, bbh_dl_Water_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, bbh_dl_Waterfall_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bbh_dl_102__Tunnel_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, -1823, 0, -8042, 0, -62, 0),
		GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 5424, -143, -11027, 0, -152, 0),
		GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 6711, 340, -8689, 0, -102, 0),
		GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 12009, 682, -6064, 0, -157, 0),
		GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 1022, -487, -9571, 0, -62, 0),
		GEO_OPEN_NODE(),
			GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 0, 265, 0, 0, 0, -90, bbh_dl_Pole1_005_mesh_layer_1),
			GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 0, 205, 0, 0, 0, -90, bbh_dl_Pole2_005_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bbh_dl_PIllars_003_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bbh_dl_Tunnel_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bbh_dl_Tunnel_002_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bbh_dl_Void_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, bbh_dl_Waterfall_003_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bbh_dl_Waterfall_003_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, bbh_dl_Waterfall_003_mesh_layer_4),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bbh_area_1[] = {
	GEO_NODE_SCREEN_AREA(10, SCREEN_WIDTH/2, SCREEN_HEIGHT/2, SCREEN_WIDTH/2, SCREEN_HEIGHT/2),
	GEO_OPEN_NODE(),
		GEO_ZBUFFER(0),
		GEO_OPEN_NODE(),
			GEO_NODE_ORTHO(100.0000),
			GEO_OPEN_NODE(),
				GEO_BACKGROUND(BACKGROUND_BELOW_CLOUDS, geo_skybox_main),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_ZBUFFER(1),
		GEO_OPEN_NODE(),
			GEO_CAMERA_FRUSTUM_WITH_FUNC(45.0000, 100, 30000, geo_camera_fov),
			GEO_OPEN_NODE(),
				GEO_CAMERA(CAMERA_MODE_8_DIRECTIONS, 0, 0, 0, 0, -100, 0, geo_camera_main),
				GEO_OPEN_NODE(),
					GEO_BRANCH(1, bbh_area_1_geo),
					GEO_RENDER_OBJ(),
					GEO_ASM(ENVFX_MODE_NONE, geo_envfx_main),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bbh_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_ALPHA, bbh_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, bbh_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, bbh_dl_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
