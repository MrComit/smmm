#include "src/game/envfx_snow.h"

const GeoLayout dirt_mound_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(1, dirt_mound_DirtMound_mesh_layer_1),
		GEO_DISPLAY_LIST(4, dirt_mound_DirtMound_mesh_layer_4),
		GEO_DISPLAY_LIST(1, dirt_mound_material_revert_render_settings),
		GEO_DISPLAY_LIST(4, dirt_mound_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
