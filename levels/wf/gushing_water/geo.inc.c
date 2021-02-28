#include "src/game/envfx_snow.h"

const GeoLayout gushing_water_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(5, gushing_water_Water_mesh_layer_5),
		GEO_DISPLAY_LIST(6, gushing_water_Water_mesh_layer_6),
		GEO_DISPLAY_LIST(5, gushing_water_material_revert_render_settings),
		GEO_DISPLAY_LIST(6, gushing_water_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
