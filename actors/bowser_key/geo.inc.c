// 0x16000A84
const GeoLayout bowser_key_geo[] = {
   GEO_SHADOW(SHADOW_CIRCLE_4_VERTS, 0x9B, 300),
   GEO_OPEN_NODE(),
      GEO_SCALE(0x00, 65536),
      GEO_OPEN_NODE(),
         GEO_DISPLAY_LIST(LAYER_OPAQUE, bowser_key_dl),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_END(),
};

#include "actors/key_small/geo_header.h"

const GeoLayout cutscene_key_small_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
      GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 200, -40, -65, 0, 0, 90),
	   GEO_OPEN_NODE(),
         GEO_DISPLAY_LIST(LAYER_OPAQUE, key_small_Small_Key_mesh),
         GEO_DISPLAY_LIST(LAYER_OPAQUE, key_small_material_revert_render_settings),
	   GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

// 0x16000AB0
const GeoLayout bowser_key_cutscene_geo[] = {
   GEO_SCALE(0x00, 16384),
   GEO_OPEN_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, NULL),
      GEO_OPEN_NODE(),
         GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, NULL),
         GEO_OPEN_NODE(),
            GEO_ASM(0, geo_scale_bowser_key),
            GEO_SCALE(0x00, 65536),
            GEO_OPEN_NODE(),
               GEO_SWITCH_CASE(2, geo_switch_bparam2),
               GEO_OPEN_NODE(),
                  GEO_DISPLAY_LIST(LAYER_OPAQUE, bowser_key_dl),
                  GEO_BRANCH(1, cutscene_key_small_geo),
               GEO_CLOSE_NODE(),
            GEO_CLOSE_NODE(),
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_END(),
};
