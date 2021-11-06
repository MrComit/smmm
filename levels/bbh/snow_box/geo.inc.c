#include "src/game/envfx_snow.h"

const GeoLayout snow_box_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, snow_box_Spring_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, snow_box_Spring_001_mesh_layer_6),
		GEO_DISPLAY_LIST(LAYER_ALPHA, snow_box_Spring_001_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, snow_box_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_ALPHA, snow_box_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, snow_box_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
