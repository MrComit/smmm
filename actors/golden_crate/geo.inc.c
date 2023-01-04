#include "src/game/envfx_snow.h"

const GeoLayout golden_crate_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_NODE_START(),
		GEO_OPEN_NODE(),
			GEO_ASM(0, geo_update_golden_crate),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, golden_crate_crate_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, golden_crate_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
