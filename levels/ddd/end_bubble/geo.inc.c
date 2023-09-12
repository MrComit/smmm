#include "src/game/envfx_snow.h"

const GeoLayout end_bubble_geo[] = {
	GEO_SHADOW(SHADOW_CIRCLE_4_VERTS, 0x96, 190),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, end_bubble_Bubble_mesh),
		// GEO_DISPLAY_LIST(LAYER_OPAQUE, end_bubble_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
