#include "src/game/envfx_snow.h"

const GeoLayout chandelier_geo[] = {
	GEO_CULLING_RADIUS(0x1000),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, chandelier_DL_ALPHA_mesh),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, chandelier_DL_OP_mesh),
		GEO_RENDER_RANGE(-2048, 5000),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, chandelier_DL_OP_RANGE_mesh),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, chandelier_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_ALPHA, chandelier_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
