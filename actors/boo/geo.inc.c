// 0x0C000224

const GeoLayout boo_opaque_geo[] = {
   GEO_NODE_START(),
   GEO_OPEN_NODE(),
      GEO_ASM(1, geo_set_boo_shade),
      GEO_DISPLAY_LIST(LAYER_OPAQUE, boo_dl_color),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};



const GeoLayout boo_trans_geo[] = {
   GEO_NODE_START(),
   GEO_OPEN_NODE(),
      GEO_ASM(5, geo_set_boo_shade),
      GEO_DISPLAY_LIST(LAYER_TRANSPARENT, boo_dl_color),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};



const GeoLayout boo_geo[] = {
   GEO_SHADOW(SHADOW_CIRCLE_4_VERTS, 0x96, 70),
   GEO_OPEN_NODE(),
      GEO_SCALE(0x00, 26214),
      GEO_OPEN_NODE(),
         GEO_ASM(0, geo_update_layer_transparency),
         GEO_SWITCH_CASE(2, geo_switch_anim_state),
         GEO_OPEN_NODE(),
            GEO_BRANCH(1, boo_opaque_geo),
            GEO_BRANCH(1, boo_trans_geo),
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
GEO_CLOSE_NODE(), //! more close than open nodes
GEO_END(),
};
