#include "src/game/envfx_snow.h"

const GeoLayout utencils_SpoonArma_001[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, utencils_root_spoon_mesh),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout utencils_KnifeArma_002[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, utencils_root_knife_mesh),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout utencils_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_NODE_START(),
		GEO_OPEN_NODE(),
			GEO_SWITCH_CASE(3, geo_switch_bparam2),
			GEO_OPEN_NODE(),
				GEO_NODE_START(),
				GEO_OPEN_NODE(),
					GEO_DISPLAY_LIST(LAYER_OPAQUE, utencils_fork_mesh),
				GEO_CLOSE_NODE(),
				GEO_BRANCH(1, utencils_SpoonArma_001),
				GEO_BRANCH(1, utencils_KnifeArma_002),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, utencils_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
