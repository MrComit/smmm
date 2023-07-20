#include "src/game/envfx_snow.h"

const GeoLayout gold_medal_switch_opt1[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, gold_medal_medal_mesh_layer_1_mat_override_MedalRed_0),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout gold_medal_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_NODE_START(),
		GEO_OPEN_NODE(),
			GEO_SWITCH_CASE(2, geo_switch_red_mission),
			GEO_OPEN_NODE(),
				GEO_NODE_START(),
				GEO_OPEN_NODE(),
					GEO_DISPLAY_LIST(LAYER_OPAQUE, gold_medal_medal_mesh_layer_1),
				GEO_CLOSE_NODE(),
				GEO_BRANCH(1, gold_medal_switch_opt1),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, gold_medal_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
