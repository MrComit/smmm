#include "src/game/envfx_snow.h"

const GeoLayout champagne_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, champagne_CharvaarghChampagne_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_INTER, champagne_CharvaarghChampagne_mesh_layer_7),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, champagne_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_INTER, champagne_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
