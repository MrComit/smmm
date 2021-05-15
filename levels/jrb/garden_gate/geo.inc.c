#include "src/game/envfx_snow.h"

const GeoLayout garden_gate_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(4, garden_gate_Gate_mesh_layer_4),
		GEO_DISPLAY_LIST(4, garden_gate_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
