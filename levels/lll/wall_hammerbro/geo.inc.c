#include "src/game/envfx_snow.h"

const GeoLayout wall_hammerbro_switch_opt1[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, wall_hammerbro_hbro_mesh_layer_6_mat_override_HammerBroHammer_0),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout wall_hammerbro_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_NODE_START(),
		GEO_OPEN_NODE(),
			GEO_SWITCH_CASE(2, geo_switch_anim_state),
			GEO_OPEN_NODE(),
				GEO_NODE_START(),
				GEO_OPEN_NODE(),
					GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, wall_hammerbro_hbro_mesh_layer_6),
				GEO_CLOSE_NODE(),
				GEO_BRANCH(1, wall_hammerbro_switch_opt1),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, wall_hammerbro_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
