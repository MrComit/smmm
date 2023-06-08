#include "src/game/envfx_snow.h"

const GeoLayout nice_face_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, nice_face_NiceFace_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_ALPHA, nice_face_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
