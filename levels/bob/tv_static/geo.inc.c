#include "src/game/envfx_snow.h"

const GeoLayout tv_static_Switch_opt1[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, tv_static_Static_mesh_mat_override_Black_0),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout tv_static_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_SWITCH_CASE(2, geo_switch_anim_state),
		GEO_OPEN_NODE(),
			GEO_NODE_START(),
			GEO_OPEN_NODE(),
				GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, tv_static_Static_mesh),
			GEO_CLOSE_NODE(),
			GEO_BRANCH(1, tv_static_Switch_opt1),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, tv_static_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
