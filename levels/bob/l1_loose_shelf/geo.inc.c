#include "src/game/envfx_snow.h"

const GeoLayout l1_loose_shelf_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, l1_loose_shelf_Loose_Shelf_mesh),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, l1_loose_shelf_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
