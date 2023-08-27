#include "src/game/envfx_snow.h"

const GeoLayout block_piece_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, block_piece_JengaPiece_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, block_piece_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};


const GeoLayout block_piece_shadow_geo[] = {
	GEO_SHADOW(SHADOW_CIRCLE_4_VERTS, 0x96, 1300),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, block_piece_JengaPiece_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, block_piece_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
