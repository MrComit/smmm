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
		GEO_TRANSLATE_NODE_WITH_DL(1, 787, 1767, -466, bbh_dl_Grass_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(4, bbh_dl_Grass_mesh_layer_4),
			GEO_DISPLAY_LIST(6, bbh_dl_Grass_mesh_layer_6),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(1, 787, 1767, -466, bbh_dl_Grass_001_mesh_layer_1),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, -4100, 2700, 2125),
		GEO_OPEN_NODE(),
			GEO_TRANSLATE_NODE_WITH_DL(1, 0, 265, 0, bbh_dl_Pole1_001_mesh_layer_1),
			GEO_TRANSLATE_NODE_WITH_DL(1, 0, 205, 0, bbh_dl_Pole2_001_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, 1273, 1500, 4986),
		GEO_OPEN_NODE(),
			GEO_TRANSLATE_NODE_WITH_DL(1, 0, 265, 0, bbh_dl_Pole1_002_mesh_layer_1),
			GEO_TRANSLATE_NODE_WITH_DL(1, 0, 205, 0, bbh_dl_Pole2_002_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, -1753, 1849, 4604),
		GEO_OPEN_NODE(),
			GEO_TRANSLATE_NODE_WITH_DL(1, 0, 265, 0, bbh_dl_Pole1_003_mesh_layer_1),
			GEO_TRANSLATE_NODE_WITH_DL(1, 0, 205, 0, bbh_dl_Pole2_003_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, 1321, 2239, -5773),
		GEO_OPEN_NODE(),
			GEO_TRANSLATE_NODE_WITH_DL(1, 0, 265, 0, bbh_dl_Pole1_004_mesh_layer_1),
			GEO_TRANSLATE_NODE_WITH_DL(1, 0, 205, 0, bbh_dl_Pole2_004_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(1, -1867, 390, -1991, bbh_dl_PIllars_001_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 309, 425, 1246, bbh_dl_PIllars_002_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 787, 1767, -466, bbh_dl_Plats_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 871, 857, 1885, bbh_dl_Rope_001_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(5, 2616, -60, -2138, bbh_dl_Water_mesh_layer_5),
		GEO_TRANSLATE_NODE_WITH_DL(5, -380, 1934, -5824, bbh_dl_Waterfall_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bbh_dl_102__Tunnel_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, -1823, 0, -8042),
		GEO_OPEN_NODE(),
			GEO_TRANSLATE_NODE_WITH_DL(1, 0, 265, 0, bbh_dl_Pole1_mesh_layer_1),
			GEO_TRANSLATE_NODE_WITH_DL(1, 0, 205, 0, bbh_dl_Pole2_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(1, -3189, 423, -4607, bbh_dl_Tunnel_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 4965, 1111, -6053, bbh_dl_Void_mesh_layer_1),
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
		GEO_DISPLAY_LIST(6, bbh_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(5, bbh_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(4, bbh_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(1, bbh_dl_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
