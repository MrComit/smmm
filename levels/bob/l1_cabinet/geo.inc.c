#include "src/game/envfx_snow.h"

const GeoLayout l1_cabinet_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, l1_cabinet_Cabinet_mesh),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, l1_cabinet_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};