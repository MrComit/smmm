#include "src/game/envfx_snow.h"

const GeoLayout key_big_switch_opt1[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, key_big_gem_mesh_mat_override_Emerald_0),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout key_big_switch_opt2[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, key_big_gem_mesh_mat_override_Sapphire_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout key_big_switch_opt3[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, key_big_gem_mesh_mat_override_Diamond_2),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout key_big_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, key_big_key_mesh),
		GEO_SWITCH_CASE(4, geo_switch_anim_state),
		GEO_OPEN_NODE(),
			GEO_NODE_START(),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, key_big_gem_mesh),
			GEO_CLOSE_NODE(),
			GEO_BRANCH(1, key_big_switch_opt1),
			GEO_BRANCH(1, key_big_switch_opt2),
			GEO_BRANCH(1, key_big_switch_opt3),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, key_big_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
