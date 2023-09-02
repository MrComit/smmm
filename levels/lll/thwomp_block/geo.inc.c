#include "src/game/envfx_snow.h"

const GeoLayout thwomp_block_geo[] = {
	GEO_SHADOW(SHADOW_SQUARE_PERMANENT, 0xB4, 800),
	GEO_OPEN_NODE(),
		GEO_NODE_START(),
		GEO_OPEN_NODE(),
			GEO_ASM(1, geo_update_opacity_and_color),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, thwomp_block_tb_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, thwomp_block_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
