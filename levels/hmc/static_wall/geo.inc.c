#include "src/game/envfx_snow.h"

const GeoLayout static_wall_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, static_wall_staticwall_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, static_wall_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
