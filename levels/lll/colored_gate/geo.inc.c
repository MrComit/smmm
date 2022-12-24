#include "src/game/envfx_snow.h"

const GeoLayout colored_gate_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_NODE_START(),
		GEO_OPEN_NODE(),
			GEO_ASM(4, geo_set_color_env),
			GEO_DISPLAY_LIST(LAYER_ALPHA, colored_gate_cgate_mesh_layer_4),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, colored_gate_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
