#include "src/game/envfx_snow.h"

const GeoLayout mem_icecube_switch_opt1[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, mem_icecube_cube_mesh_layer_5_mat_override_MetalBox_0),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout mem_icecube_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_NODE_START(),
		GEO_OPEN_NODE(),
			GEO_SWITCH_CASE(2, geo_switch_anim_state),
			GEO_OPEN_NODE(),
				GEO_NODE_START(),
				GEO_OPEN_NODE(),
					GEO_DISPLAY_LIST(LAYER_TRANSPARENT, mem_icecube_cube_mesh_layer_5),
				GEO_CLOSE_NODE(),
				GEO_BRANCH(1, mem_icecube_switch_opt1),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, mem_icecube_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, mem_icecube_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
