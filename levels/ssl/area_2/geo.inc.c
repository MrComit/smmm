#include "src/game/envfx_snow.h"

const GeoLayout ssl_area_2_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SWITCH_CASE(12, geo_switch_area),
		GEO_OPEN_NODE(),
			GEO_BRANCH(1, ssl_dl_201__NULL_geo),
			GEO_BRANCH(1, ssl_dl_202__NULL_geo),
			GEO_BRANCH(1, ssl_dl_203__NULL_geo),
			GEO_BRANCH(1, ssl_dl_204__The_Mind_Palace_geo),
			GEO_BRANCH(1, ssl_dl_205__Outside3_geo),
			GEO_BRANCH(1, ssl_dl_206__The_Laboratory_geo),
			GEO_BRANCH(1, ssl_dl_207__Outside4_geo),
			GEO_BRANCH(1, ssl_dl_208__Dream_Room_geo),
			GEO_BRANCH(1, ssl_dl_209__Outside5_geo),
			GEO_BRANCH(1, ssl_dl_210__Observatory_geo),
			GEO_BRANCH(1, ssl_dl_211__Memory_Hole_geo),
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
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, -12471, 4087, -2957),
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
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ssl_dl_BGRocks_001_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, -65536, ssl_dl_FancyChair_002_mesh_layer_1),
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
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, 0, 0, -65536),
		GEO_OPEN_NODE(),
			GEO_ASM(10, geo_update_bgrock_floor),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, ssl_dl_BGMuiscFloor_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, -65536, ssl_dl_BGRocks_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, -65536, ssl_dl_Button_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, ssl_dl_Fence_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ssl_dl_OGround_004_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ssl_dl_OGround_005_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ssl_dl_OGround_006_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, ssl_dl_OGround_006_mesh_layer_5),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, 65536, ssl_dl_PalaceWall_002_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ssl_dl_b__Lava_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ssl_dl_Lava_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, ssl_dl_Lava_001_mesh_layer_5),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, -65536, ssl_dl_LavaRockFloor_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ssl_dl_LavaSky_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ssl_dl_Snow_001_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ssl_dl_c__Base_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ssl_dl_Base_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, ssl_dl_Base_002_mesh_layer_5),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, -65536, ssl_dl_LavaRockFloor_001_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, -65536, ssl_dl_Paintings_004_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, -65536, ssl_dl_Paintings_005_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ssl_dl_d__Grass_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ssl_dl_Grass_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, ssl_dl_Grass_001_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ssl_dl_GrassSky_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ssl_dl_e__Snow_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, -65536, ssl_dl_Paintings_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ssl_dl_Snow_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, ssl_dl_Snow_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ssl_dl_SnowSky_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ssl_dl_SnowSky_001_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ssl_dl_208__Dream_Room_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ASM(1, geo_set_dream_env),
		GEO_ASM(5, geo_set_dream_env),
		GEO_SWITCH_CASE(4, geo_switch_dream_layers),
		GEO_OPEN_NODE(),
			GEO_BRANCH(1, ssl_dl_b__Lava_geo),
			GEO_BRANCH(1, ssl_dl_c__Base_geo),
			GEO_BRANCH(1, ssl_dl_d__Grass_geo),
			GEO_BRANCH(1, ssl_dl_e__Snow_geo),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, -65536, ssl_dl_NULLTri_005_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ssl_dl_b_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, -65536, ssl_dl_GameroomBG_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ssl_dl_OGround_007_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, ssl_dl_OGround_008_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ssl_dl_c_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, -65536, ssl_dl_GameroomBG_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ssl_dl_OGround_010_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ssl_dl_209__Outside5_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SWITCH_CASE(2, geo_switch_o5_layers),
		GEO_OPEN_NODE(),
			GEO_BRANCH(1, ssl_dl_b_geo),
			GEO_BRANCH(1, ssl_dl_c_geo),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, -65536, ssl_dl_NULLTri_006_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ssl_dl_210__Observatory_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT, 0, 0, -65536, ssl_dl_Clouds_mesh_layer_5),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, -65536, ssl_dl_Observatory_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, -65536, ssl_dl_Observatory_001_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, 0, 0, -65536, ssl_dl_Observatory_002_mesh_layer_4),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ssl_dl_211__Memory_Hole_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, -65536, ssl_dl_Cabinet_004_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, -65536, ssl_dl_Dresser_001_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, -65536, ssl_dl_Hallway_001_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, -65536, ssl_dl_MRoomCrate_010_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, -65536, ssl_dl_Plate_003_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, -65536, ssl_dl_Table_mesh_layer_1),
		GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, -20571, 7404, -24904, 0, -90, 0),
		GEO_OPEN_NODE(),
			GEO_SCALE(LAYER_OPAQUE, 41532),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, -25089, 7559, -24424, 0, -90, 0),
		GEO_OPEN_NODE(),
			GEO_SCALE(LAYER_OPAQUE, 41532),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, -12627, 7008, -25339, 0, -90, 0),
		GEO_OPEN_NODE(),
			GEO_SCALE(LAYER_OPAQUE, 41532),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, -23018, 7560, -20838, 0, -90, 0),
		GEO_OPEN_NODE(),
			GEO_SCALE(LAYER_OPAQUE, 41532),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, 0, 0, -65536),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, ssl_dl_Hampers_mesh_layer_1),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, ssl_dl_LaundryRoom_mesh_layer_1),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT, ssl_dl_LaundryRoom_mesh_layer_5),
			GEO_DISPLAY_LIST(LAYER_ALPHA, ssl_dl_LaundryRoom_mesh_layer_4),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, ssl_dl_Socks_001_mesh_layer_1),
			GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 4530, 4, 5900, ssl_dl_TideToad_mesh_layer_1),
			GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT, 4530, 4, 5900, ssl_dl_TideToad_002_mesh_layer_5),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, 0, 0, -65536),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, ssl_dl_ClothesPile_mesh_layer_1),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, ssl_dl_HamperInside_mesh_layer_1),
			GEO_DISPLAY_LIST(LAYER_ALPHA, ssl_dl_Shirt_001_mesh_layer_4),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, ssl_dl_Shirts_mesh_layer_6),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, ssl_dl_Socks_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -2862, 0, -63963, ssl_dl_Bathroom_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT, ssl_dl_Bathroom_mesh_layer_5),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -2862, 0, -63963, ssl_dl_Bathroom_002_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -2862, 0, -63963, ssl_dl_Pencil_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -2862, 0, -63963, ssl_dl_Pencil_001_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT, 424, 0, -77922, ssl_dl_ShowerWalCol_mesh_layer_5),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, -2862, 0, -63963),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -2862, 0, -63963, ssl_dl_Soap_mesh_layer_1),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, -2862, 0, -63963),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT, 4530, 4, -59636, ssl_dl_TideToad_001_mesh_layer_5),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -2862, 0, -63963, ssl_dl_Castle_001_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -2862, 0, -63963, ssl_dl_Castle_002_mesh_layer_1),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, -2862, 0, -63963),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -2862, 0, -63963, ssl_dl_Castle_005_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -2862, 0, -63963, ssl_dl_Castle_006_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT_DECAL, -2862, 0, -63963, ssl_dl_Castle_009_mesh_layer_6),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, -2862, 0, -63963),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, -2862, 0, -63963),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, -2862, 0, -63963),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, -2862, 0, -63963),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, -2862, 0, -63963),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, -2862, 0, -63963),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT, -2862, 0, -63963, ssl_dl_IceSlideCol_mesh_layer_5),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -2862, 0, -63963, ssl_dl_icestairs_mesh_layer_1),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, -2862, 0, -63963),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, -2862, 0, -63963),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -2862, 0, -63963, ssl_dl_Platforms_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT, -2862, 0, -63963, ssl_dl_Steam_001_mesh_layer_5),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -2862, 0, -63963, ssl_dl_under_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, -2862, 0, -63963, ssl_dl_BBOutside_mesh_layer_4),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, ssl_dl_BBOutside_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -2862, 0, -63963, ssl_dl_Fan_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -2862, 0, -63963, ssl_dl_Foreroom_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT, ssl_dl_Foreroom_mesh_layer_5),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, ssl_dl_Foreroom_mesh_layer_6),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ssl_dl_Observatory_003_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -2862, 0, -63963, ssl_dl_Vase_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -696, 218, -70626, ssl_dl_Vase_001_mesh_layer_1),
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