#include "src/game/envfx_snow.h"

const GeoLayout l1_barrel_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, l1_barrel_Barrel_mesh),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, l1_barrel_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
