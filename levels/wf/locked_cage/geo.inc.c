#include "src/game/envfx_snow.h"

const GeoLayout locked_cage_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(1, locked_cage_Jail_mesh_layer_1),
		GEO_DISPLAY_LIST(4, locked_cage_Jail_mesh_layer_4),
		GEO_DISPLAY_LIST(1, locked_cage_material_revert_render_settings),
		GEO_DISPLAY_LIST(4, locked_cage_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
