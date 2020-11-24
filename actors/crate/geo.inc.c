#include "src/game/envfx_snow.h"

const GeoLayout crate_shadow_geo[] = {
    GEO_SHADOW(SHADOW_SQUARE_PERMANENT, 0xB4, 240),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, crate_Crate_mesh),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, crate_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};

const GeoLayout crate_noshadow_geo[] = {
    GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, crate_Crate_mesh),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, crate_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};


const GeoLayout crate_geo[] = {
	GEO_CULLING_RADIUS(0x1000),
	GEO_OPEN_NODE(),
		GEO_SWITCH_CASE(2, geo_switch_anim_state),
		GEO_OPEN_NODE(),
			GEO_BRANCH(1, crate_shadow_geo),
			GEO_BRANCH(1, crate_noshadow_geo),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
