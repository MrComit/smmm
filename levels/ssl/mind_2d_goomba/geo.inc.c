#include "src/game/envfx_snow.h"

const GeoLayout mind_2d_goomba_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, mind_2d_goomba_2DGoomba_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_ALPHA, mind_2d_goomba_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
