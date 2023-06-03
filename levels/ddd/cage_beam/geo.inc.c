#include "src/game/envfx_snow.h"

const GeoLayout cage_beam_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, cage_beam_CageBeam_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, cage_beam_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
