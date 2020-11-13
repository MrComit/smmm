#include "src/game/envfx_snow.h"

const GeoLayout landchunk_geo[] = {
	GEO_CULLING_RADIUS(0x1000),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, landchunk_LandChunk_mesh),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, landchunk_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
