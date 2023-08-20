#include "src/game/envfx_snow.h"

const GeoLayout c4_trophy_octogon_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, c4_trophy_octogon_TrophyOctogon_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, c4_trophy_octogon_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
