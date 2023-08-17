#include "src/game/envfx_snow.h"

const GeoLayout cg_elevator_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, cg_elevator_Z5PlantPlatform_002_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, cg_elevator_Z5PlantPlatform_002_mesh_layer_6),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, cg_elevator_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, cg_elevator_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
