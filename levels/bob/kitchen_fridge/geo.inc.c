#include "src/game/envfx_snow.h"

const GeoLayout kitchen_fridge_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, kitchen_fridge_Fridge_mesh),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, kitchen_fridge_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
