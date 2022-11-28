#include "src/game/envfx_snow.h"

const GeoLayout lll_area_1_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SWITCH_CASE(9, geo_switch_area),
		GEO_OPEN_NODE(),
			GEO_BRANCH(1, lll_dl_101__The_Corridor_geo),
			GEO_BRANCH(1, lll_dl_102__Laundry_Room_geo),
			GEO_BRANCH(1, lll_dl_103__Gym_geo),
			GEO_BRANCH(1, lll_dl_104__Wine_Cellar_geo),
			GEO_BRANCH(1, lll_dl_105__Root_Cellar_geo),
			GEO_BRANCH(1, lll_dl_106__Meat_Locker_geo),
			GEO_BRANCH(1, lll_dl_107__Engine_Room_geo),
			GEO_BRANCH(1, lll_dl_108__Torture_Chamber_geo),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout lll_dl_101__The_Corridor_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, lll_dl_BasementStairs_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, lll_dl_Cobwebs_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, lll_dl_Corridor_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, lll_dl_Fog_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout lll_dl_b_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, lll_dl_Basket_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, lll_dl_Baskets_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, lll_dl_Clothes_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, lll_dl_ClothesPile_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, lll_dl_Hampers_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, lll_dl_LaundryRoom_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, lll_dl_LaundryRoom_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, lll_dl_Painting_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, lll_dl_Rack_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, lll_dl_Rack_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, lll_dl_Rack_004_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, lll_dl_Shirt_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, lll_dl_Socks_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, lll_dl_Table_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 4530, 4, 5900, lll_dl_TideToad_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT, lll_dl_TideToad_mesh_layer_5),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout lll_dl_c_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, lll_dl_ClothesPile_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, lll_dl_HamperInside_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, lll_dl_Shirt_001_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, lll_dl_Shirts_mesh_layer_6),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, lll_dl_Socks_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout lll_dl_102__Laundry_Room_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SWITCH_CASE(2, geo_switch_laundry_room),
		GEO_OPEN_NODE(),
			GEO_BRANCH(1, lll_dl_b_002_geo),
			GEO_BRANCH(1, lll_dl_c_002_geo),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, lll_dl_aNULL_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, lll_dl_Border_mesh_layer_1),
		GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 5385, 100, 12406, 0, -180, 0),
		GEO_OPEN_NODE(),
			GEO_SCALE(LAYER_OPAQUE, 41532),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, -4602, 710, 16329, 0, -180, 0),
		GEO_OPEN_NODE(),
			GEO_SCALE(LAYER_OPAQUE, 41532),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 9717, 100, 5325, 0, -180, 0),
		GEO_OPEN_NODE(),
			GEO_SCALE(LAYER_OPAQUE, 41532),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 713, 710, 16072, 0, -180, 0),
		GEO_OPEN_NODE(),
			GEO_SCALE(LAYER_OPAQUE, 41532),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 13028, 497, 7898, 0, -180, 0),
		GEO_OPEN_NODE(),
			GEO_SCALE(LAYER_OPAQUE, 41532),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 1908, 710, 18142, 0, -180, 0),
		GEO_OPEN_NODE(),
			GEO_SCALE(LAYER_OPAQUE, 41532),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, -4802, 860, 16329, 0, -180, 0),
		GEO_OPEN_NODE(),
			GEO_SCALE(LAYER_OPAQUE, 41532),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 5385, 308, 12406, 0, -180, 0),
		GEO_OPEN_NODE(),
			GEO_SCALE(LAYER_OPAQUE, 41532),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 713, 860, 16329, 0, -180, 0),
		GEO_OPEN_NODE(),
			GEO_SCALE(LAYER_OPAQUE, 41532),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 9717, 308, 5325, 0, -180, 0),
		GEO_OPEN_NODE(),
			GEO_SCALE(LAYER_OPAQUE, 41532),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 1908, 860, 18399, 0, -180, 0),
		GEO_OPEN_NODE(),
			GEO_SCALE(LAYER_OPAQUE, 41532),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 13017, 705, 7898, 0, -180, 0),
		GEO_OPEN_NODE(),
			GEO_SCALE(LAYER_OPAQUE, 41532),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout lll_dl_103__Gym_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, lll_dl_Bench_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, lll_dl_BigWeight_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -4034, 105, 547, 90, 0, 0, lll_dl_Dumbbell_001_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -6877, 1917, -4640, 90, 0, 0, lll_dl_DumbbellBridge_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_ALPHA, lll_dl_DumbbellBridge_mesh_layer_4),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -6457, 2486, -2474, 90, 0, 0, lll_dl_DumbbellBridge_001_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_ALPHA, lll_dl_DumbbellBridge_001_mesh_layer_4),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, lll_dl_ExerciseBike_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, lll_dl_Gym_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, lll_dl_LegPress_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, lll_dl_Locker_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -11796, -1999, -6250, lll_dl_Pipes_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -4034, 105, 547, 90, 0, 0, lll_dl_Plates_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 2280, 0, 0, lll_dl_Pullup_Bars_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 2280, 0, 0, lll_dl_Pullup_Bars_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, lll_dl_Treadmill_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, lll_dl_Weights_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout lll_dl_b_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_INTER, lll_dl_Wine_mesh_layer_7),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, lll_dl_Wine_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, lll_dl_WineCellar_003_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, lll_dl_WineCellar_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout lll_dl_c_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, lll_dl_NULL_001_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout lll_dl_104__Wine_Cellar_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SWITCH_CASE(2, geo_switch_wine_cellar),
		GEO_OPEN_NODE(),
			GEO_BRANCH(1, lll_dl_b_001_geo),
			GEO_BRANCH(1, lll_dl_c_001_geo),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, lll_dl_Painting_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, lll_dl_Stairs_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 65042, 1113, -16615, lll_dl_Tower_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_ALPHA, lll_dl_Tower_mesh_layer_4),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, lll_dl_Wine_002_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, lll_dl_WineCellar_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, lll_dl_WineCellar_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, lll_dl_WineCellar_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, lll_dl_WineCellar_002_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_INTER, lll_dl_WineLogos_001_mesh_layer_7),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, lll_dl_WineLogos_001_mesh_layer_6),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_INTER, lll_dl_Z7Bottles_mesh_layer_7),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, lll_dl_Z7Bottles_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, lll_dl_Z7Wine_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, lll_dl_Z7Wine_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_INTER, lll_dl_Z8Bottles_mesh_layer_7),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, lll_dl_Z8Bottles_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, lll_dl_Z8Wine_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, lll_dl_Z8Wine_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_INTER, lll_dl_Z9Bottles_mesh_layer_7),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, lll_dl_Z9Bottles_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, lll_dl_Z9Wine_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, lll_dl_Z9Wine_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout lll_dl_105__Root_Cellar_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, lll_dl_CanYoshi_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, lll_dl_CanYoshi_mesh_layer_6),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, lll_dl_Pantry_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, lll_dl_Pantry_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, lll_dl_RootCellar_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, lll_dl_RootCellar_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, lll_dl_ShelfPlat_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, lll_dl_Shelves_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, lll_dl_Shelves_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, lll_dl_Tomatos_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, lll_dl_Veggies_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, lll_dl_Veggies_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_INTER, lll_dl_Veggies_mesh_layer_7),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout lll_dl_b_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, lll_dl_NULL_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout lll_dl_c_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, lll_dl_LockerFridge_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout lll_dl_106__Meat_Locker_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SWITCH_CASE(2, geo_switch_meat_locker),
		GEO_OPEN_NODE(),
			GEO_BRANCH(1, lll_dl_b_geo),
			GEO_BRANCH(1, lll_dl_c_geo),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, lll_dl_Crate_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, lll_dl_Crate_001_mesh_layer_6),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, lll_dl_Meat_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, lll_dl_Meat_Locker_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, lll_dl_Meat_Locker_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, lll_dl_Meat_001_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, lll_dl_Painting_002_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout lll_dl_107__Engine_Room_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, lll_dl_BoogooZone_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, lll_dl_BoogooZone_mesh_layer_5),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 9977, 452, 439, lll_dl_Pillars_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, lll_dl_EngineRoom_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, lll_dl_EngineRoom_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, lll_dl_EngineRoom_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, lll_dl_EngineRoom_002_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, lll_dl_EngineRoom_002_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout lll_dl_108__Torture_Chamber_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, lll_dl_TortureChamber_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout lll_area_1[] = {
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
					GEO_BRANCH(1, lll_area_1_geo),
					GEO_RENDER_OBJ(),
					GEO_ASM(ENVFX_MODE_NONE, geo_envfx_main),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, lll_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_ALPHA, lll_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, lll_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, lll_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_INTER, lll_dl_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
