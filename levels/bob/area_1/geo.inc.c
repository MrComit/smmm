#include "src/game/envfx_snow.h"

const GeoLayout bob_area_1_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SWITCH_CASE(15, geo_switch_area),
		GEO_OPEN_NODE(),
			GEO_BRANCH(1, bob_dl_101__Mudroom_geo),
			GEO_BRANCH(1, bob_dl_102__Main_Hall_geo),
			GEO_BRANCH(1, bob_dl_103__Parlor_geo),
			GEO_BRANCH(1, bob_dl_104__Garage_geo),
			GEO_BRANCH(1, bob_dl_105__Hallways_geo),
			GEO_BRANCH(1, bob_dl_106__Dining_Room_geo),
			GEO_BRANCH(1, bob_dl_107__Kitchen_geo),
			GEO_BRANCH(1, bob_dl_108__Pantry_geo),
			GEO_BRANCH(1, bob_dl_109__Living_Room_geo),
			GEO_BRANCH(1, bob_dl_110__Study_geo),
			GEO_BRANCH(1, bob_dl_111__Library_geo),
			GEO_BRANCH(1, bob_dl_112__Hallway_2_geo),
			GEO_BRANCH(1, bob_dl_113__Hallway_3_geo),
			GEO_BRANCH(1, bob_dl_114__Treasury_geo),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bob_dl_101__Mudroom_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Bookshelf_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Dresser_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Lamp_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Mudroom_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE_DECAL, bob_dl_Mudroom_001_mesh_layer_2),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, bob_dl_Mudroom_002_mesh_layer_6),
		GEO_DISPLAY_LIST(LAYER_OPAQUE_DECAL, bob_dl_Mudroom_003_mesh_layer_2),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bob_dl_102__Main_Hall_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, bob_dl_Mudroom_004_mesh_layer_6),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Pillar_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Pillar_Tops_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Pillar_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Pillar_002_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Simple_Table_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Z82MainHall_004_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Z85Pillar_010_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Z87Pillar_006_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Z91MainHall_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Z92Pillar_009_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, bob_dl_Z93Paintings_mesh_layer_6),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Z94Painting_002_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Z94Painting_010_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, bob_dl_Z94Painting_014_mesh_layer_6),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Z99MainHall_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Z99MainHall_003_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bob_dl_103__Parlor_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Bookshelf_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_chair_002_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_chair_008_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Medal_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Medal_002_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Painting_009_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Parlor_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, bob_dl_Plant_001_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Plant_002_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Plant_003_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Simple_Table_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Simple_Table_002_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bob_dl_104__Garage_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_BasementStairs_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Canister_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Garage_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, bob_dl_OilFloor_mesh_layer_6),
		GEO_ASM(0x7, geo_set_red_painting),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Painting_002_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_shelves_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Tools_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Truck_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Wrench_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Wrench_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Wrench_002_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Wrench_003_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Wrench_004_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Wrench_005_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Wrench_006_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Wrench_007_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Wrench_008_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Wrench_009_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Wrench_010_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Wrench_011_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Wrench_012_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bob_dl_105__Hallways_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Barracade_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, bob_dl_Bars_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Bookshelf_004_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Bookshelf_005_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Bookshelf_006_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Bookshelf_007_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Bookshelf_008_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Bookshelf_009_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Bookshelf_010_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Bookshelf_011_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Bookshelf_013_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Clock_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE_DECAL, bob_dl_FloorMats_mesh_layer_2),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Hallway_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Hallway_002_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, bob_dl_Hallway_002_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Hallway_003_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Side_Table_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Side_Table_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Side_Table_002_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Side_Table_004_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, bob_dl_SpiderWeb_005_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Vase_004_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bob_dl_106__Dining_Room_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Cabinet_004_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, bob_dl_Cabinet_004_mesh_layer_6),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Dresser_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Hallway_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_MRoomCrate_007_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_MRoomCrate_008_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_MRoomCrate_010_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Plate_003_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Table_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bob_dl_107__Kitchen_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Barrel_Thing_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Castle_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_chair_010_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_chair_011_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE_DECAL, bob_dl_Grate_mesh_layer_2),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_ice1_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_ice2_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Kitchen_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_KitchenGround_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_KitchenGround_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_KitchenGround_002_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_KitchenGround_003_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_KitchenGround_004_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, bob_dl_KitchenGround_005_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, bob_dl_Loose_Shelf_001_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Simple_Table_003_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, bob_dl_Steam_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Stove_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Stove_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Stove_002_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bob_dl_108__Pantry_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Kitchen_002_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Kitchen_003_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, bob_dl_SpiderWeb_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bob_dl_109__Living_Room_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Bookshelf_002_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE_DECAL, bob_dl_Carpet_mesh_layer_2),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, bob_dl_CarpetEnd_mesh_layer_6),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Couch_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_LivingRoom_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_LTable_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Shelf_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Shelf_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_TV_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bob_dl_bb_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_bb_001_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bob_dl_cc_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_cc_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bob_dl_bb_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_bb_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bob_dl_cc_001_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_cc_001_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bob_dl_110__Study_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SWITCH_CASE(2, geo_switch_study1),
		GEO_OPEN_NODE(),
			GEO_BRANCH(1, bob_dl_bb_001_geo),
			GEO_BRANCH(1, bob_dl_cc_geo),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_aa_mesh_layer_1),
		GEO_SWITCH_CASE(2, geo_switch_study2),
		GEO_OPEN_NODE(),
			GEO_BRANCH(1, bob_dl_bb_geo),
			GEO_BRANCH(1, bob_dl_cc_001_geo),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_aa_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE_DECAL, bob_dl_Black_mesh_layer_2),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Board_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_BucketStack_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_BucketStack_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_FancyChair_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Fireplace_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_GBook_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_HalfPillar_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Light_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Study_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bob_dl_bb_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Books_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_FancyChair_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Painting_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Simple_Table_004_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bob_dl_cc_002_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_cc_002_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bob_dl_bb_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_LibraryLowerFloor_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bob_dl_cc_003_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_cc_003_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bob_dl_111__Library_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Library_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, bob_dl_Library_001_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Library_003_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Library_004_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, bob_dl_Library_006_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Library_007_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, bob_dl_Railing_mesh_layer_4),
		GEO_SWITCH_CASE(2, geo_switch_library),
		GEO_OPEN_NODE(),
			GEO_BRANCH(1, bob_dl_bb_002_geo),
			GEO_BRANCH(1, bob_dl_cc_002_geo),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_aa_002_mesh_layer_1),
		GEO_SWITCH_CASE(2, geo_switch_library2),
		GEO_OPEN_NODE(),
			GEO_BRANCH(1, bob_dl_bb_003_geo),
			GEO_BRANCH(1, bob_dl_cc_003_geo),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_aa_003_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bob_dl_112__Hallway_2_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_QuickHall_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_QuickHall_001_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bob_dl_113__Hallway_3_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_MainHall_012_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_MainHall_013_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bob_dl_114__Treasury_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_CoinStack_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, bob_dl_CoinStack_mesh_layer_6),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Crystals_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Treasury_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bob_area_1[] = {
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
					GEO_BRANCH(1, bob_area_1_geo),
					GEO_RENDER_OBJ(),
					GEO_ASM(ENVFX_LAVA_BUBBLES, geo_envfx_main),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_OPAQUE_DECAL, bob_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_ALPHA, bob_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, bob_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, bob_dl_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
