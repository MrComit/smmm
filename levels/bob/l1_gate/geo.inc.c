#include "src/game/envfx_snow.h"

const GeoLayout l1_gate_geo[] = {
	GEO_CULLING_RADIUS(0x1000),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, l1_gate_Gate_mesh),
		GEO_DISPLAY_LIST(LAYER_ALPHA, l1_gate_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
