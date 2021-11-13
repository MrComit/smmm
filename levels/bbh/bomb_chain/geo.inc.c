#include "src/game/envfx_snow.h"

const GeoLayout bomb_chain_geo[] = {
	GEO_CULLING_RADIUS(8192),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, bomb_chain_Chain_001_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_ALPHA, bomb_chain_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
