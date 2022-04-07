#include "src/game/envfx_snow.h"

const GeoLayout static_tri_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, static_tri_statictri_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, static_tri_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
