#include "src/game/envfx_snow.h"

const GeoLayout remote_Switch_opt1[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, remote_Remote_mesh_mat_override_GrayRemote_0),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout remote_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_SWITCH_CASE(2, geo_switch_anim_state),
		GEO_OPEN_NODE(),
			GEO_NODE_START(),
			GEO_OPEN_NODE(),
				GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, remote_Remote_mesh),
			GEO_CLOSE_NODE(),
			GEO_BRANCH(1, remote_Switch_opt1),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, remote_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
