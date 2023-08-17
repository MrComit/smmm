#include "src/game/envfx_snow.h"

const GeoLayout balcony_elevator_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, balcony_elevator_Z5PlantPlatform_002_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, balcony_elevator_Z5PlantPlatform_002_mesh_layer_6),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, balcony_elevator_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, balcony_elevator_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
