#include "src/game/envfx_snow.h"

const GeoLayout attic_spike_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, attic_spike_AtticSpike_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, attic_spike_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
