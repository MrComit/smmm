#include "src/game/envfx_snow.h"

const GeoLayout fake_dirt_wall_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(1, fake_dirt_wall_Grass_003_mesh_layer_1),
		GEO_DISPLAY_LIST(1, fake_dirt_wall_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
