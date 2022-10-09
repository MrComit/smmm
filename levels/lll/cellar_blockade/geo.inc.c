#include "src/game/envfx_snow.h"

const GeoLayout cellar_blockade_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, cellar_blockade_Barracade_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, cellar_blockade_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
