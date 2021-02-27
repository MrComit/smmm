#include "src/game/envfx_snow.h"

const GeoLayout l2_falling_floor_switch_opt1[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, l2_falling_floor_top_mesh_layer_1_mat_override_bathroomtiles2_0),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout l2_falling_floor_switch_opt2[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, l2_falling_floor_top_mesh_layer_1_mat_override_bathroomtiles3_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout l2_falling_floor_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_NODE_START(),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, l2_falling_floor_ground_mesh_layer_1),
			GEO_SWITCH_CASE(3, geo_switch_anim_state),
			GEO_OPEN_NODE(),
				GEO_NODE_START(),
				GEO_OPEN_NODE(),
					GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, l2_falling_floor_top_mesh_layer_1),
				GEO_CLOSE_NODE(),
				GEO_BRANCH(1, l2_falling_floor_switch_opt1),
				GEO_BRANCH(1, l2_falling_floor_switch_opt2),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, l2_falling_floor_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
