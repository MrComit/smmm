#include "src/game/envfx_snow.h"

const GeoLayout crate_geo[] = {
	GEO_CULLING_RADIUS(0x1000),
	GEO_OPEN_NODE(),
    	GEO_SHADOW(SHADOW_SQUARE_PERMANENT, 0xB4, 240),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, crate_Crate_mesh),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, crate_material_revert_render_settings),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
