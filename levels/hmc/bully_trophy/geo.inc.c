#include "src/game/envfx_snow.h"

const GeoLayout bully_trophy_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bully_trophy_KingBullyTrophy_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, bully_trophy_KingBullyTrophy_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bully_trophy_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_ALPHA, bully_trophy_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
