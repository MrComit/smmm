#include "src/game/envfx_snow.h"

const GeoLayout controller_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, controller_Controller_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, controller_Controller_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, controller_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, controller_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
