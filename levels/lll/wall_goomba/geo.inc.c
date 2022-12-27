#include "src/game/envfx_snow.h"

const GeoLayout wall_goomba_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, wall_goomba_WallGoomba_mesh_layer_6),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, wall_goomba_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
