#include "src/game/envfx_snow.h"

const GeoLayout ssl_area_2_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SWITCH_CASE(9, geo_switch_area),
		GEO_OPEN_NODE(),
			GEO_BRANCH(1, ssl_dl_201__NULL_geo),
			GEO_BRANCH(1, ssl_dl_202__NULL_geo),
			GEO_BRANCH(1, ssl_dl_203__NULL_geo),
			GEO_BRANCH(1, ssl_dl_204__The_Mind_Palace_geo),
			GEO_BRANCH(1, ssl_dl_205__Outside3_geo),
			GEO_BRANCH(1, ssl_dl_206__The_Laboratory_geo),
			GEO_BRANCH(1, ssl_dl_207__Outside4_geo),
			GEO_BRANCH(1, ssl_dl_208__Dream_Room_geo),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ssl_dl_201__NULL_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, -65536, ssl_dl_NULLTri_002_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ssl_dl_202__NULL_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, -65536, ssl_dl_NULLTri_003_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ssl_dl_203__NULL_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, -65536, ssl_dl_NULLTri_004_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ssl_dl_204__The_Mind_Palace_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, -23176, 6047, -67211, 0, -90, 0),
		GEO_OPEN_NODE(),
			GEO_SCALE(LAYER_OPAQUE, 41532),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 3093, 5687, -11834, ssl_dl_Cage_003_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ssl_dl_Debris_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ssl_dl_MindPalace_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, ssl_dl_MindPalace_001_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, ssl_dl_MindPalace_001_mesh_layer_6),
		GEO_DISPLAY_LIST(LAYER_ALPHA, ssl_dl_MindPalace_002_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_ALPHA, ssl_dl_MindPalace_003_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, ssl_dl_MindPalace_004_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ssl_dl_OGround_002_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, ssl_dl_SpookyFaces_mesh_layer_6),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ssl_dl_205__Outside3_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ssl_dl_ArtWall_002_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ssl_dl_BGRocks_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ssl_dl_Lab_003_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ssl_dl_OGround_003_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ssl_dl_PalaceWall_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ssl_dl_206__The_Laboratory_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, -65536, ssl_dl_Antenna_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, ssl_dl_Antenna_mesh_layer_6),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ssl_dl_Lab_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, ssl_dl_Lab_mesh_layer_5),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 13133, 7774, -10212, ssl_dl_Lab_001_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT, ssl_dl_Lab_001_mesh_layer_5),
			GEO_DISPLAY_LIST(LAYER_OPAQUE_DECAL, ssl_dl_Lab_001_mesh_layer_2),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 13133, 7774, -10212, ssl_dl_Lab_002_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ssl_dl_207__Outside4_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ASM(0, geo_mind_static),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, ssl_dl_2Static_002_mesh_layer_6),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, 65536, ssl_dl_ArtWall_003_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, -65536, ssl_dl_Button_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ssl_dl_OGround_004_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ssl_dl_OGround_005_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ssl_dl_PalaceWall_001_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ssl_dl_208__Dream_Room_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ssl_dl_DreamRoom_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ssl_area_2[] = {
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
				GEO_CAMERA(CAMERA_MODE_8_DIRECTIONS, 0, 0, 65536, 0, -100, 65536, geo_camera_main),
				GEO_OPEN_NODE(),
					GEO_BRANCH(1, ssl_area_2_geo),
					GEO_RENDER_OBJ(),
					GEO_ASM(ENVFX_LAVA_BUBBLES, geo_envfx_main),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ssl_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_OPAQUE_DECAL, ssl_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_ALPHA, ssl_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, ssl_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, ssl_dl_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
