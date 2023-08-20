#include "src/game/envfx_snow.h"

const GeoLayout c4_trophy_rectangle_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, c4_trophy_rectangle_TrophyRect_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, c4_trophy_rectangle_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
