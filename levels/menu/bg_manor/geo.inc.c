#include "src/game/envfx_snow.h"

const GeoLayout bg_manor_switch_opt1[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bg_manor_bg_mesh_layer_1_mat_override_BG2_0),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bg_manor_switch_opt2[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bg_manor_bg_mesh_layer_1_mat_override_BG3_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bg_manor_switch_opt3[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bg_manor_bg_mesh_layer_1_mat_override_BG4_2),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bg_manor_switch_opt4[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bg_manor_bg_mesh_layer_1_mat_override_BG5_3),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bg_manor_switch_opt5[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bg_manor_bg_mesh_layer_1_mat_override_BG6_4),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bg_manor_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_NODE_START(),
		GEO_OPEN_NODE(),
			GEO_SWITCH_CASE(6, geo_switch_menu),
			GEO_OPEN_NODE(),
				GEO_NODE_START(),
				GEO_OPEN_NODE(),
					GEO_DISPLAY_LIST(LAYER_OPAQUE, bg_manor_bg_mesh_layer_1),
				GEO_CLOSE_NODE(),
				GEO_BRANCH(1, bg_manor_switch_opt1),
				GEO_BRANCH(1, bg_manor_switch_opt2),
				GEO_BRANCH(1, bg_manor_switch_opt3),
				GEO_BRANCH(1, bg_manor_switch_opt4),
				GEO_BRANCH(1, bg_manor_switch_opt5),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bg_manor_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
