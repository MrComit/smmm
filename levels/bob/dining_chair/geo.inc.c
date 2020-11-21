#include "src/game/envfx_snow.h"

const GeoLayout dining_chair_geo[] = {
	GEO_CULLING_RADIUS(0x1000),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, dining_chair_chair_005_mesh),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, dining_chair_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
