#include "src/game/envfx_snow.h"

const GeoLayout attic_wall_AtticWallConsole[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ASM(1, geo_update_layer_transparency_layer),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, attic_wall_start_wallC_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout attic_wall_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_NODE_START(),
		GEO_OPEN_NODE(),
			GEO_SWITCH_CASE(2, geo_switch_console),
			GEO_OPEN_NODE(),
				GEO_NODE_START(),
				GEO_OPEN_NODE(),
					GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, NULL),
					GEO_OPEN_NODE(),
						GEO_ASM(0, geo_update_layer_transparency),
						GEO_DISPLAY_LIST(LAYER_TRANSPARENT, attic_wall_wall_mesh_layer_5),
					GEO_CLOSE_NODE(),
				GEO_CLOSE_NODE(),
				GEO_BRANCH(1, attic_wall_AtticWallConsole),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, attic_wall_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, attic_wall_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
