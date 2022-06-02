#include "src/game/envfx_snow.h"

const GeoLayout attic_grate_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, attic_grate_Attic_001_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_ALPHA, attic_grate_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
