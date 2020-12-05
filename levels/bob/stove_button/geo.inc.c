#include "src/game/envfx_snow.h"

const GeoLayout stove_button_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, stove_button_Stove_001_mesh),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, stove_button_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
