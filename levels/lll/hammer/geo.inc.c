#include "src/game/envfx_snow.h"

const GeoLayout hammer_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_SHADOW(1, 153, 60),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, hammer_ham_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hammer_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
