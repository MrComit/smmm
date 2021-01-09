#include "src/game/envfx_snow.h"

const GeoLayout key_small_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, key_small_Small_Key_mesh),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, key_small_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
