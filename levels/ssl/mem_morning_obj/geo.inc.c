#include "src/game/envfx_snow.h"

const GeoLayout mem_morning_obj_Bookshelf[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, mem_morning_obj_start_books_mesh_layer_4),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout mem_morning_obj_Plant[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, mem_morning_obj_start_plant_mesh_layer_4),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout mem_morning_obj_Table_002[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, mem_morning_obj_start_table_mesh_layer_4),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout mem_morning_obj_Vase_003[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, mem_morning_obj_start_vase_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout mem_morning_obj_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_NODE_START(),
		GEO_OPEN_NODE(),
			GEO_ASM(0, geo_update_layer_transparency_cutout),
			GEO_SWITCH_CASE(6, geo_switch_bparam2),
			GEO_OPEN_NODE(),
				GEO_NODE_START(),
				GEO_OPEN_NODE(),
					GEO_DISPLAY_LIST(LAYER_OPAQUE, mem_morning_obj_chair_mesh_layer_1),
				GEO_CLOSE_NODE(),
				GEO_BRANCH(1, mem_morning_obj_Bookshelf),
				GEO_BRANCH(1, mem_morning_obj_Plant),
				GEO_BRANCH(1, mem_morning_obj_Table_002),
				GEO_BRANCH(1, mem_morning_obj_Vase_003),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, mem_morning_obj_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_ALPHA, mem_morning_obj_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
