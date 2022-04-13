#include "src/game/envfx_snow.h"

const GeoLayout sauna_grate_switch_opt1[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, sauna_grate_number_mesh_layer_4_mat_override_Clown1_0),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout sauna_grate_switch_opt2[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, sauna_grate_number_mesh_layer_4_mat_override_Clown2_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout sauna_grate_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_NODE_START(),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_ALPHA, sauna_grate_grate_mesh_layer_4),
			GEO_SWITCH_CASE(3, geo_switch_anim_state),
			GEO_OPEN_NODE(),
				GEO_NODE_START(),
				GEO_OPEN_NODE(),
					GEO_DISPLAY_LIST(LAYER_ALPHA, sauna_grate_number_mesh_layer_4),
				GEO_CLOSE_NODE(),
				GEO_BRANCH(1, sauna_grate_switch_opt1),
				GEO_BRANCH(1, sauna_grate_switch_opt2),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, sauna_grate_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
