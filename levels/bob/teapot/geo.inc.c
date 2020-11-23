#include "src/game/envfx_snow.h"

const GeoLayout teapot_geo[] = {
	GEO_CULLING_RADIUS(0x1000),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, teapot_Teapot_mesh),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, teapot_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
