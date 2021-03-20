#include "src/game/envfx_snow.h"

const GeoLayout bounce_box_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(1, bounce_box_Spring_mesh_layer_1),
		GEO_DISPLAY_LIST(6, bounce_box_Spring_mesh_layer_6),
		GEO_DISPLAY_LIST(4, bounce_box_Spring_mesh_layer_4),
		GEO_DISPLAY_LIST(4, bounce_box_material_revert_render_settings),
		GEO_DISPLAY_LIST(1, bounce_box_material_revert_render_settings),
		GEO_DISPLAY_LIST(6, bounce_box_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
