#include "src/game/envfx_snow.h"

const GeoLayout L1_burner_geo[] = {
	GEO_CULLING_RADIUS(0x1000),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, L1_burner_Burner_001_mesh),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, L1_burner_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
