#include "src/game/envfx_snow.h"

const GeoLayout peepa_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, peepa_Main_mesh),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, peepa_End_mesh),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, peepa_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, peepa_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
