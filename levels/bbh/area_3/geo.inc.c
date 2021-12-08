#include "src/game/envfx_snow.h"

const GeoLayout bbh_area_3_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SWITCH_CASE(8, geo_switch_area),
		GEO_OPEN_NODE(),
			GEO_BRANCH(1, bbh_dl_301__NOP_geo),
			GEO_BRANCH(1, bbh_dl_302__NOP_geo),
			GEO_BRANCH(1, bbh_dl_303__NOP_geo),
			GEO_BRANCH(1, bbh_dl_304__NOP_geo),
			GEO_BRANCH(1, bbh_dl_305__SnowGlobe_geo),
			GEO_BRANCH(1, bbh_dl_306__UnderGlobe_geo),
			GEO_BRANCH(1, bbh_dl_307__Ice_Castle_geo),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bbh_dl_301__NOP_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bbh_dl_Snow_008_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bbh_dl_302__NOP_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bbh_dl_Snow_007_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bbh_dl_303__NOP_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bbh_dl_Snow_006_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bbh_dl_304__NOP_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bbh_dl_Snow_005_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bbh_dl_BB_geo[] = {
	GEO_TRANSLATE_NODE(LAYER_OPAQUE, -131072, 0, 0),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT_DECAL, 131072, 0, 0, bbh_dl_BB_mesh_layer_6),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT, bbh_dl_BB_mesh_layer_5),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bbh_dl_CC_geo[] = {
	GEO_TRANSLATE_NODE(LAYER_OPAQUE, -131072, 0, 0),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 131072, 0, 0, bbh_dl_CC_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bbh_dl_305__SnowGlobe_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SWITCH_CASE(2, geo_switch_console),
		GEO_OPEN_NODE(),
			GEO_BRANCH(1, bbh_dl_BB_geo),
			GEO_BRANCH(1, bbh_dl_CC_geo),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 131072, 0, 0, bbh_dl_AA_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bbh_dl_PitPlatforms_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, bbh_dl_PitPlatforms_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bbh_dl_Castle_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bbh_dl_CastleRuins_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bbh_dl_CastleRuins_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bbh_dl_CastleRuins_003_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bbh_dl_IcePlatforms_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bbh_dl_IceSlide_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, bbh_dl_IceSlide_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_ALPHA, bbh_dl_IceSlide_002_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bbh_dl_Platform_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, bbh_dl_Platform_mesh_layer_6),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bbh_dl_Slingshot_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bbh_dl_Snow_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bbh_dl_Snow_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bbh_dl_Snow_003_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bbh_dl_SnowMountain_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bbh_dl_UnderglobeFake_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bbh_dl_ZSkybox_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bbh_dl_306__UnderGlobe_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bbh_dl_BooGoo_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, bbh_dl_Chain_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bbh_dl_IceSlide_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bbh_dl_Room2Skybox_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bbh_dl_Underglobe_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, bbh_dl_Underglobe_001_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, bbh_dl_Waterfall_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bbh_dl_2ref_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bbh_dl_2ref_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bbh_dl_3Ref_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bbh_dl_3Ref_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bbh_dl_307__Ice_Castle_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bbh_dl_Castle_002_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, bbh_dl_Castle_002_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_ALPHA, bbh_dl_Castle_004_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bbh_dl_Castle_005_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bbh_dl_Castle_006_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, bbh_dl_Castle_007_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, bbh_dl_Castle_009_mesh_layer_6),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bbh_dl_Crown_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bbh_dl_FancyChair_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bbh_dl_FloorPaintings_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bbh_dl_FloorPaintings_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bbh_dl_iceplats1_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE_DECAL, bbh_dl_iceplats1_mesh_layer_2),
		GEO_DISPLAY_LIST(LAYER_ALPHA, bbh_dl_iceplats1_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bbh_dl_iceplats2_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE_DECAL, bbh_dl_iceplats2_mesh_layer_2),
		GEO_DISPLAY_LIST(LAYER_ALPHA, bbh_dl_iceplats2_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bbh_dl_icestairs_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bbh_dl_Paintings_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bbh_dl_Paintings_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bbh_dl_Paintings_002_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bbh_dl_Platforms_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, bbh_dl_Steam_mesh_layer_5),
		GEO_SWITCH_CASE(2, geo_switch_ice_reflection),
		GEO_OPEN_NODE(),
			GEO_BRANCH(1, bbh_dl_2ref_geo),
			GEO_BRANCH(1, bbh_dl_3Ref_geo),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bbh_dl_1Ref_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bbh_dl_under_mesh_layer_1),
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
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bbh_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_OPAQUE_DECAL, bbh_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_ALPHA, bbh_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, bbh_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, bbh_dl_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
