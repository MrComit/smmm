#include "src/game/envfx_snow.h"

const GeoLayout hmc_area_1_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SWITCH_CASE(10, geo_switch_area),
		GEO_OPEN_NODE(),
			GEO_BRANCH(1, hmc_dl_101__OpeningHall_geo),
			GEO_BRANCH(1, hmc_dl_102__Trophy_Room_geo),
			GEO_BRANCH(1, hmc_dl_103__Hallway_geo),
			GEO_BRANCH(1, hmc_dl_104__Music_Room_geo),
			GEO_BRANCH(1, hmc_dl_105__Game_Room_geo),
			GEO_BRANCH(1, hmc_dl_106__Panic_Room_geo),
			GEO_BRANCH(1, hmc_dl_107__Hallway_geo),
			GEO_BRANCH(1, hmc_dl_108__Foreroom_geo),
			GEO_BRANCH(1, hmc_dl_109__Theater_geo),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout hmc_dl_101__OpeningHall_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_Floor3_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_OpeningHall_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_Plant_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, hmc_dl_Plant_001_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_Stairs_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout hmc_dl_102__Trophy_Room_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_TrophyRoom_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_TrophyRoom_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_TrophyRoom_002_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_TrophyRoom_003_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_TrophyRoom_004_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_TrophyRoom_004_mesh),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_TrophyRoom_005_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_TrophyRoom_006_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_TrophyRoom_007_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_TrophyRoom_008_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_TrophyRoom_012_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_TrophyRoom_013_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout hmc_dl_103__Hallway_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_TrophyRoom_009_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout hmc_dl_104__Music_Room_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, 8796, 0, 14423),
		GEO_OPEN_NODE(),
			GEO_ASM(0, geo_update_music_floor),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_MUSICFLOOR_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_RecordPlayer_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, hmc_dl_RecordPlayer_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_TrophyRoom_010_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout hmc_dl_bb_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_bb_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_bb_003_mesh),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout hmc_dl_cc_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_cc_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, hmc_dl_WhackAMole_001_mesh_layer_6),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout hmc_dl_bb_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, hmc_dl_bb_mesh_layer_4),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout hmc_dl_cc_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, hmc_dl_cc_001_mesh_layer_4),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout hmc_dl_105__Game_Room_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SWITCH_CASE(2, geo_switch_pool_floor),
		GEO_OPEN_NODE(),
			GEO_BRANCH(1, hmc_dl_bb_001_geo),
			GEO_BRANCH(1, hmc_dl_cc_geo),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_aa_mesh),
		GEO_SWITCH_CASE(2, geo_switch_mole_gate),
		GEO_OPEN_NODE(),
			GEO_BRANCH(1, hmc_dl_bb_geo),
			GEO_BRANCH(1, hmc_dl_cc_001_geo),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_aa_001_mesh),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_Chess_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_Painting_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_PingPongTable_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, hmc_dl_PingPongTable_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_PoolTable_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_ToyBoxes_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_TrophyRoom_011_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_WhackAMole_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, hmc_dl_WhackAMole_mesh_layer_4),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout hmc_dl_106__Panic_Room_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_TrophyRoom_014_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout hmc_dl_107__Hallway_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_Hallway_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, hmc_dl_HallwayFakeWall_mesh_layer_4),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout hmc_dl_BBOutside_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_BBOutside_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, hmc_dl_BBOutside_mesh_layer_4),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout hmc_dl_CC_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_CC_mesh),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout hmc_dl_108__Foreroom_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_Foreroom_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_Vase_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, hmc_dl_Vase_mesh_layer_4),
		GEO_SWITCH_CASE(0, geo_switch_foreroom_outside),
		GEO_OPEN_NODE(),
			GEO_BRANCH(1, hmc_dl_BBOutside_geo),
			GEO_BRANCH(1, hmc_dl_CC_geo),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_AA_mesh),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout hmc_dl_109__Theater_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_Theater_mesh_layer_1),
		GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, -5104, 250, -9146, 0, -90, 0),
		GEO_OPEN_NODE(),
			GEO_SCALE(LAYER_OPAQUE, 41532),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout hmc_area_1[] = {
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
			GEO_CAMERA_FRUSTUM_WITH_FUNC(45.0000, 100, 30000, geo_camera_fov),
			GEO_OPEN_NODE(),
				GEO_CAMERA(CAMERA_MODE_8_DIRECTIONS, 0, 0, 0, 0, -100, 0, geo_camera_main),
				GEO_OPEN_NODE(),
					GEO_BRANCH(1, hmc_area_1_geo),
					GEO_RENDER_OBJ(),
					GEO_ASM(ENVFX_MODE_NONE, geo_envfx_main),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_ALPHA, hmc_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, hmc_dl_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
