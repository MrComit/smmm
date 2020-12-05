#include "src/game/envfx_snow.h"

const GeoLayout frying_pan_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, frying_pan_Frying_Pan_mesh),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, frying_pan_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
