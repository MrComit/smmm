#include "src/game/envfx_snow.h"

const GeoLayout winking_moon_switch_opt1[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, winking_moon_moon_mesh_layer_4_mat_override_WinkFaceMoon_0),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, winking_moon_moon_mesh_layer_6_mat_override_WinkFaceMoon_0),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout winking_moon_geo[] = {
	GEO_CULLING_RADIUS(16384),
	GEO_OPEN_NODE(),
		GEO_NODE_START(),
		GEO_OPEN_NODE(),
			GEO_SWITCH_CASE(2, geo_switch_anim_state),
			GEO_OPEN_NODE(),
				GEO_NODE_START(),
				GEO_OPEN_NODE(),
					GEO_DISPLAY_LIST(LAYER_ALPHA, winking_moon_moon_mesh_layer_4),
					GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, winking_moon_moon_mesh_layer_6),
				GEO_CLOSE_NODE(),
				GEO_BRANCH(1, winking_moon_switch_opt1),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, winking_moon_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, winking_moon_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
