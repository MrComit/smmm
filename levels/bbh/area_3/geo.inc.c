#include "src/game/envfx_snow.h"

const GeoLayout bbh_area_3_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SWITCH_CASE(3, geo_switch_area),
		GEO_OPEN_NODE(),
			GEO_BRANCH(1, bbh_dl_301__SnowGlobe_geo),
			GEO_BRANCH(1, bbh_dl_302__UnderGlobe_geo),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bbh_dl_BB_geo[] = {
	GEO_TRANSLATE_NODE(LAYER_OPAQUE, -131072, 0, 0),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(6, 128458, -675, 1543, bbh_dl_BB_mesh_layer_6),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(5, bbh_dl_BB_mesh_layer_5),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bbh_dl_CC_geo[] = {
	GEO_TRANSLATE_NODE(LAYER_OPAQUE, -131072, 0, 0),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(1, 130159, -11425, -1335, bbh_dl_CC_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bbh_dl_301__SnowGlobe_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SWITCH_CASE(2, geo_switch_console),
		GEO_OPEN_NODE(),
			GEO_BRANCH(1, bbh_dl_BB_geo),
			GEO_BRANCH(1, bbh_dl_CC_geo),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(1, 130159, -11425, -1335, bbh_dl_AA_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 3, -1500, 0, bbh_dl_PitPlatforms_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(4, bbh_dl_PitPlatforms_mesh_layer_4),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(1, 3031, 2305, -6076, bbh_dl_Castle_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 6586, 2349, -3428, bbh_dl_CastleRuins_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 5089, 1615, -2106, bbh_dl_CastleRuins_001_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -2284, 320, -5459, bbh_dl_IcePlatforms_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -4696, 1503, -4946, bbh_dl_IceSlide_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(4, bbh_dl_IceSlide_mesh_layer_4),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(1, 4933, 185, 6448, bbh_dl_Platform_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(6, bbh_dl_Platform_mesh_layer_6),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(1, bbh_dl_Skybox_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 3, -1500, 0, bbh_dl_Snow_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 2525, 1000, -1866, bbh_dl_Snow_001_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -546, -875, 16143, bbh_dl_Snow_003_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 7085, 550, 4623, bbh_dl_SnowMountain_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -1608, -3191, -3596, bbh_dl_UnderglobeFake_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bbh_dl_302__UnderGlobe_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(1, -2678, -2469, -4948, bbh_dl_BooGoo_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(4, -1951, -3379, -4234, bbh_dl_Chain_mesh_layer_4),
		GEO_TRANSLATE_NODE_WITH_DL(1, -8065, -2281, -5398, bbh_dl_IceSlide_001_mesh_layer_1),
		GEO_DISPLAY_LIST(1, bbh_dl_Room2Skybox_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -2678, -2469, -4948, bbh_dl_Underglobe_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(5, bbh_dl_Underglobe_mesh_layer_5),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(5, 1648, -2585, -7804, bbh_dl_Waterfall_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bbh_area_3[] = {
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
			GEO_CAMERA_FRUSTUM_WITH_FUNC(45.0000, 150, 45000, geo_camera_fov),
			GEO_OPEN_NODE(),
				GEO_CAMERA(CAMERA_MODE_8_DIRECTIONS, 131072, 0, 0, 131072, -100, 0, geo_camera_main),
				GEO_OPEN_NODE(),
					GEO_BRANCH(1, bbh_area_3_geo),
					GEO_RENDER_OBJ(),
					GEO_ASM(ENVFX_SNOW_NORMAL, geo_envfx_main),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(4, bbh_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(1, bbh_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(5, bbh_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(6, bbh_dl_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
