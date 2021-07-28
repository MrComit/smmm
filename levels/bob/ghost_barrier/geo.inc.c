#include "src/game/envfx_snow.h"

const GeoLayout ghost_barrier_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_NODE_START(),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT, ghost_barrier_Decal_mesh_layer_5),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT, ghost_barrier_Trans_mesh_layer_5),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, ghost_barrier_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
