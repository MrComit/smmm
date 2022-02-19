#include "src/game/envfx_snow.h"

const GeoLayout pool_barrier_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_NODE_START(),
		GEO_OPEN_NODE(),
			GEO_ASM(0, geo_update_layer_transparency),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT, pool_barrier_barrier_mesh_layer_5),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, pool_barrier_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
