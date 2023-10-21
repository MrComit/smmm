#include "src/game/envfx_snow.h"

const GeoLayout sl_area_1_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SWITCH_CASE(10, geo_switch_area),
		GEO_OPEN_NODE(),
			GEO_BRANCH(1, sl_dl_101__Outside_geo),
			GEO_BRANCH(1, sl_dl_102__Main_Hall_001_geo),
			GEO_BRANCH(1, sl_dl_103__Hallway_geo),
			GEO_BRANCH(1, sl_dl_104__Living_Room_geo),
			GEO_BRANCH(1, sl_dl_105__Kitchen_geo),
			GEO_BRANCH(1, sl_dl_106__Lounge_geo),
			GEO_BRANCH(1, sl_dl_107__Entertainment_Room_geo),
			GEO_BRANCH(1, sl_dl_108__Basement_geo),
			GEO_BRANCH(1, sl_dl_109__Bedroom_geo),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout sl_dl_101__Outside_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, sl_dl_Mansion_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, sl_dl_Mansion_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, sl_dl_Mansion_001_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, sl_dl_Mansion_002_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -835, 3681, -9088, sl_dl_MountainExterior_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, sl_dl_Tree_Leaves_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, sl_dl_Trees_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout sl_dl_102__Main_Hall_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, sl_dl_Chandelier_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, sl_dl_Chandelier_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, sl_dl_CoinPaintings_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, sl_dl_ConceptArtMainHall_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, sl_dl_MainHall_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, sl_dl_OpeningHallPlants_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, sl_dl_OpeningHallPlants_001_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, sl_dl_Painting_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -2900, 680, 6797, 0, 90, 0, sl_dl_StarPlaque_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -2900, 680, 6797, 0, 90, 0, sl_dl_StarPlaque_001_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout sl_dl_103__Hallway_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, sl_dl_Bookshelf_004_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, sl_dl_ConceptArtHallway_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, sl_dl_Hallway_002_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, sl_dl_Hallway_003_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, sl_dl_Hallway_004_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, sl_dl_OpeningHallPlants_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, sl_dl_OpeningHallPlants_mesh_layer_4),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout sl_dl_104__Living_Room_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, sl_dl_Books_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, sl_dl_Books_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE_DECAL, sl_dl_Carpet_mesh_layer_2),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, sl_dl_CarpetEnd_mesh_layer_6),
		GEO_DISPLAY_LIST(LAYER_ALPHA, sl_dl_ConceptArtLivingRoom_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, sl_dl_ConceptArtLivingRoom_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, sl_dl_Couch_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, sl_dl_FancyChair_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, sl_dl_LivingRoom_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, sl_dl_LivingRoom_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, sl_dl_LTable_mesh_layer_1),
		GEO_ROTATION_NODE_WITH_DL(LAYER_OPAQUE, 90, 0, 0, sl_dl_MarioTrophyKitchen_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, sl_dl_TV_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout sl_dl_105__Kitchen_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, sl_dl_chair_011_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, sl_dl_ConceptArtKitchen_mesh_layer_6),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, sl_dl_Kitchen_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, sl_dl_KitchenGround_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, sl_dl_KitchenGround_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, sl_dl_KitchenGround_004_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, sl_dl_KitchenGround_005_mesh_layer_5),
		GEO_ROTATION_NODE_WITH_DL(LAYER_OPAQUE, 90, 0, 0, sl_dl_MarioTrophyKitchen_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, sl_dl_Plate_003_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, sl_dl_Stove_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, sl_dl_Stove_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, sl_dl_Stove_002_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, sl_dl_Table_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout sl_dl_106__Lounge_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, sl_dl_ConceptArtLounge_mesh_layer_6),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, sl_dl_Cushion_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, sl_dl_CushionCol_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, sl_dl_Lounge_mesh_layer_1),
		GEO_ROTATION_NODE_WITH_DL(LAYER_OPAQUE, 90, 0, 0, sl_dl_MarioTrophy_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, sl_dl_Painting_002_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, sl_dl_Pole1_002_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, sl_dl_RecordPlayer_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, sl_dl_RecordPlayer_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, sl_dl_Simple_Table_003_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, sl_dl_Simple_Table_003_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, sl_dl_Slide_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout sl_dl_107__Entertainment_Room_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, sl_dl_cc_002_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, sl_dl_ConceptArtEntertainment_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, sl_dl_ConceptArtEntertainment_mesh_layer_6),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, sl_dl_EntertainmentRoom_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE_DECAL, sl_dl_EntertainmentRoom_mesh_layer_2),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, sl_dl_EntertainmentRoom_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, sl_dl_Paddle_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, sl_dl_Paddle_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, sl_dl_Paddle_mesh_layer_4),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, -5295, 243, -3358, sl_dl_Tall_Grass_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, sl_dl_ToadToys_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, sl_dl_ToadToys_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, sl_dl_ToyBoxes_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, sl_dl_Toys_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout sl_dl_108__Basement_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, sl_dl_Antenna_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, sl_dl_Basement_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, sl_dl_CanYoshi_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, sl_dl_CanYoshi_mesh_layer_6),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, 358, -4901, -22459),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, 358, -4901, 180),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, sl_dl_ConceptArtBasement_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, sl_dl_ConceptArtBasement_mesh_layer_6),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, sl_dl_Dryer_002_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, sl_dl_Glow_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, sl_dl_Meat_003_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, sl_dl_Tomatos_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, sl_dl_TortureChamberUnder_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, sl_dl_TortureChamberUnder_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, sl_dl_Treadmill_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, sl_dl_Veggies_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, sl_dl_Veggies_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_INTER, sl_dl_Veggies_mesh_layer_7),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, sl_dl_Washer_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout sl_dl_109__Bedroom_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ASM(0, geo_set_room_color_env),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, sl_dl_AAA_005_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, sl_dl_Bed_002_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -1261, 11400, -9811, sl_dl_Bedroom_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, sl_dl_ConceptArtBedroom_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, sl_dl_Dresser_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, sl_dl_Dresser_009_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, sl_dl_Light_005_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, sl_dl_Painting_001_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout sl_area_1[] = {
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
					GEO_BRANCH(1, sl_area_1_geo),
					GEO_RENDER_OBJ(),
					GEO_ASM(ENVFX_MODE_NONE, geo_envfx_main),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, sl_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_OPAQUE_DECAL, sl_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_ALPHA, sl_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, sl_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, sl_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_INTER, sl_dl_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
