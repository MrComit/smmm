#include "src/game/envfx_snow.h"

const GeoLayout snow_pile_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, snow_pile_snow_pile_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, snow_pile_snow_pile_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, snow_pile_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, snow_pile_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
