#include "src/game/envfx_snow.h"

const GeoLayout dblock_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, dblock_DBlock_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, dblock_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
