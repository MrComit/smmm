#include "src/game/envfx_snow.h"

const GeoLayout pound_lego_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(1, pound_lego_Lego_003_mesh_layer_1),
		GEO_DISPLAY_LIST(1, pound_lego_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
