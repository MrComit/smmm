#include "src/game/envfx_snow.h"

const GeoLayout key_broken_BrokenKeyGeo2[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, key_broken_Start_key2_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout key_broken_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_NODE_START(),
		GEO_OPEN_NODE(),
			GEO_SWITCH_CASE(2, geo_switch_anim_state),
			GEO_OPEN_NODE(),
				GEO_NODE_START(),
				GEO_OPEN_NODE(),
					GEO_DISPLAY_LIST(LAYER_OPAQUE, key_broken_key1_mesh_layer_1),
					GEO_DISPLAY_LIST(LAYER_OPAQUE, key_broken_gem1_mesh_layer_1),
				GEO_CLOSE_NODE(),
				GEO_BRANCH(1, key_broken_BrokenKeyGeo2),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, key_broken_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
