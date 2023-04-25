#include "src/game/envfx_snow.h"

const GeoLayout mind_button_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, mind_button_Button_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, mind_button_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
