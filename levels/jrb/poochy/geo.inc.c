#include "src/game/envfx_snow.h"

const GeoLayout poochy_geo[] = {
	GEO_CULLING_RADIUS(8192),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(1, poochy_Poochy_mesh_layer_1),
		GEO_DISPLAY_LIST(4, poochy_Poochy_mesh_layer_4),
		GEO_DISPLAY_LIST(1, poochy_material_revert_render_settings),
		GEO_DISPLAY_LIST(4, poochy_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
