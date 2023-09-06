#include "src/game/envfx_snow.h"

const GeoLayout bar_barrier_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_NODE_START(),
		GEO_OPEN_NODE(),
			GEO_ASM(1, geo_update_layer_transparency_layer),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, bar_barrier_barrier_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bar_barrier_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
