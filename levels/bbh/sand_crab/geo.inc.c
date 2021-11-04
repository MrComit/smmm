#include "src/game/envfx_snow.h"

const GeoLayout sand_crab_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, sand_crab_crab_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, sand_crab_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
