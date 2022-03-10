#include "src/game/envfx_snow.h"

const GeoLayout foreroom_object_Bookshelf[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, foreroom_object_start_books_mesh_layer_4),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout foreroom_object_Plant[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, foreroom_object_start_plant_mesh_layer_4),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout foreroom_object_Table[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, foreroom_object_start_table_mesh_layer_4),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout foreroom_object_Vase_001[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, foreroom_object_start_vase_mesh_layer_4),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout foreroom_object_Wall[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, foreroom_object_start_wall_mesh_layer_4),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout foreroom_object_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_NODE_START(),
		GEO_OPEN_NODE(),
			GEO_ASM(0, geo_update_layer_transparency_cutout),
			GEO_SWITCH_CASE(6, geo_switch_bparam2),
			GEO_OPEN_NODE(),
				GEO_NODE_START(),
				GEO_OPEN_NODE(),
					GEO_DISPLAY_LIST(LAYER_ALPHA, foreroom_object_chair_mesh_layer_4),
				GEO_CLOSE_NODE(),
				GEO_BRANCH(1, foreroom_object_Bookshelf),
				GEO_BRANCH(1, foreroom_object_Plant),
				GEO_BRANCH(1, foreroom_object_Table),
				GEO_BRANCH(1, foreroom_object_Vase_001),
				GEO_BRANCH(1, foreroom_object_Wall),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, foreroom_object_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
