#include "src/game/envfx_snow.h"

const GeoLayout ssl_area_1_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SWITCH_CASE(6, geo_switch_area),
		GEO_OPEN_NODE(),
			GEO_BRANCH(1, ssl_dl_101__Opening_geo),
			GEO_BRANCH(1, ssl_dl_102__Art_Gallery_geo),
			GEO_BRANCH(1, ssl_dl_103__Outside2_geo),
			GEO_BRANCH(1, ssl_dl_104__The_Mind_Palace_geo),
			GEO_BRANCH(1, ssl_dl_105__Outside3_NULL_geo),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, -21859, 385, 24269, 0, -180, 0),
		GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, -21859, 385, 24269, 0, -180, 0),
		GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, -21859, 385, 24269, 0, -180, 0),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ssl_dl_101__Opening_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ssl_dl_BG1_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE_DECAL, ssl_dl_BG2_mesh_layer_2),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ssl_dl_BG2_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ssl_dl_Cube_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ssl_dl_OpeningGround_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ssl_dl_Pillar_003_mesh_layer_1),
		GEO_ASM(0, geo_mind_static),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, ssl_dl_Static_mesh_layer_6),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, ssl_dl_Z93Paintings_mesh_layer_6),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ssl_dl_Z93Paintings_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ssl_dl_102__Art_Gallery_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ssl_dl_ArtGallery_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -22054, 2672, 1117, ssl_dl_BlackBox_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ssl_dl_Brushes_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, ssl_dl_Brushes_mesh_layer_6),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ssl_dl_Buckets_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ssl_dl_MovingBlocks_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ssl_dl_Paintings_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ssl_dl_Paintings_002_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ssl_dl_Paintings_003_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ssl_dl_103__Outside2_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, -676, 6047, -11675, 0, -90, 0),
		GEO_OPEN_NODE(),
			GEO_SCALE(LAYER_OPAQUE, 41532),
		GEO_CLOSE_NODE(),
		GEO_ASM(0, geo_mind_static),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, ssl_dl_2Static_001_mesh_layer_6),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ssl_dl_ArtWall_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ssl_dl_ArtWall_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ssl_dl_BGPieces_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 3093, 5687, -11834, ssl_dl_Cage_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ssl_dl_GardenCircle_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, ssl_dl_GardenCircle_001_mesh_layer_6),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ssl_dl_GardenCircle_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, ssl_dl_GardenCircle_001_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ssl_dl_MindPalace_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ssl_dl_OGround_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, ssl_dl_TallGrass_001_mesh_layer_4),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ssl_dl_104__The_Mind_Palace_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ssl_dl_NULLTri_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ssl_dl_105__Outside3_NULL_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ssl_dl_NULLTri_001_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ssl_area_1[] = {
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
					GEO_BRANCH(1, ssl_area_1_geo),
					GEO_RENDER_OBJ(),
					GEO_ASM(ENVFX_LAVA_BUBBLES, geo_envfx_main),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ssl_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_OPAQUE_DECAL, ssl_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_ALPHA, ssl_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, ssl_dl_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
