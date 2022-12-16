#include "src/game/envfx_snow.h"

const GeoLayout sawblade_SawbladeNoBlood_001[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, sawblade_start_blade2_mesh_layer_4),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout sawblade_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_NODE_START(),
		GEO_OPEN_NODE(),
			GEO_SWITCH_CASE(2, geo_switch_bparam2),
			GEO_OPEN_NODE(),
				GEO_NODE_START(),
				GEO_OPEN_NODE(),
					GEO_DISPLAY_LIST(LAYER_ALPHA, sawblade_blade_mesh_layer_4),
				GEO_CLOSE_NODE(),
				GEO_BRANCH(1, sawblade_SawbladeNoBlood_001),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, sawblade_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
