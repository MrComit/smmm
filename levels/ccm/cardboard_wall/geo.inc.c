#include "src/game/envfx_snow.h"

const GeoLayout cardboard_wall_CBWall2[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, cardboard_wall_start_dl2_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout cardboard_wall_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_NODE_START(),
		GEO_OPEN_NODE(),
			GEO_SWITCH_CASE(2, geo_switch_bparam2),
			GEO_OPEN_NODE(),
				GEO_NODE_START(),
				GEO_OPEN_NODE(),
					GEO_DISPLAY_LIST(LAYER_OPAQUE, cardboard_wall_dl_mesh_layer_1),
				GEO_CLOSE_NODE(),
				GEO_BRANCH(1, cardboard_wall_CBWall2),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, cardboard_wall_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
