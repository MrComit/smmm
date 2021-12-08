// 0x1600013C
const GeoLayout yellow_coin_geo[] = {
   GEO_SHADOW(SHADOW_CIRCLE_4_VERTS, 0xB4, 50),
   GEO_OPEN_NODE(),
      GEO_SWITCH_CASE(8, geo_switch_anim_state),
      GEO_OPEN_NODE(),
         GEO_DISPLAY_LIST(LAYER_ALPHA, coin_seg3_dl_03007800),
         GEO_DISPLAY_LIST(LAYER_ALPHA, coin_seg3_dl_03007800),
         GEO_DISPLAY_LIST(LAYER_ALPHA, coin_seg3_dl_03007828),
         GEO_DISPLAY_LIST(LAYER_ALPHA, coin_seg3_dl_03007828),
         GEO_DISPLAY_LIST(LAYER_ALPHA, coin_seg3_dl_03007850),
         GEO_DISPLAY_LIST(LAYER_ALPHA, coin_seg3_dl_03007850),
         GEO_DISPLAY_LIST(LAYER_ALPHA, coin_seg3_dl_03007878),
         GEO_DISPLAY_LIST(LAYER_ALPHA, coin_seg3_dl_03007878),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_END(),
};

// 0x160001A0
const GeoLayout yellow_coin_no_shadow_geo[] = {
   GEO_NODE_START(),
   GEO_OPEN_NODE(),
      GEO_SWITCH_CASE(8, geo_switch_anim_state),
      GEO_OPEN_NODE(),
         GEO_DISPLAY_LIST(LAYER_ALPHA, coin_seg3_dl_03007800),
         GEO_DISPLAY_LIST(LAYER_ALPHA, coin_seg3_dl_03007800),
         GEO_DISPLAY_LIST(LAYER_ALPHA, coin_seg3_dl_03007828),
         GEO_DISPLAY_LIST(LAYER_ALPHA, coin_seg3_dl_03007828),
         GEO_DISPLAY_LIST(LAYER_ALPHA, coin_seg3_dl_03007850),
         GEO_DISPLAY_LIST(LAYER_ALPHA, coin_seg3_dl_03007850),
         GEO_DISPLAY_LIST(LAYER_ALPHA, coin_seg3_dl_03007878),
         GEO_DISPLAY_LIST(LAYER_ALPHA, coin_seg3_dl_03007878),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_END(),
};

// 0x16000200
const GeoLayout blue_coin_alpha_geo[] = {
   GEO_NODE_START(),
   GEO_OPEN_NODE(),
      GEO_SWITCH_CASE(8, geo_switch_bparam2),
      GEO_OPEN_NODE(),
         GEO_DISPLAY_LIST(LAYER_ALPHA, coin_seg3_dl_030078A0),
         GEO_DISPLAY_LIST(LAYER_ALPHA, coin_seg3_dl_030078A0),
         GEO_DISPLAY_LIST(LAYER_ALPHA, coin_seg3_dl_030078C8),
         GEO_DISPLAY_LIST(LAYER_ALPHA, coin_seg3_dl_030078C8),
         GEO_DISPLAY_LIST(LAYER_ALPHA, coin_seg3_dl_030078F0),
         GEO_DISPLAY_LIST(LAYER_ALPHA, coin_seg3_dl_030078F0),
         GEO_DISPLAY_LIST(LAYER_ALPHA, coin_seg3_dl_03007918),
         GEO_DISPLAY_LIST(LAYER_ALPHA, coin_seg3_dl_03007918),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

const GeoLayout blue_coin_trans_geo[] = {
   GEO_NODE_START(),
   GEO_OPEN_NODE(),
      GEO_SWITCH_CASE(8, geo_switch_bparam2),
      GEO_OPEN_NODE(),
         GEO_DISPLAY_LIST(LAYER_TRANSPARENT, coin_seg3_dl_030078A0),
         GEO_DISPLAY_LIST(LAYER_TRANSPARENT, coin_seg3_dl_030078A0),
         GEO_DISPLAY_LIST(LAYER_TRANSPARENT, coin_seg3_dl_030078C8),
         GEO_DISPLAY_LIST(LAYER_TRANSPARENT, coin_seg3_dl_030078C8),
         GEO_DISPLAY_LIST(LAYER_TRANSPARENT, coin_seg3_dl_030078F0),
         GEO_DISPLAY_LIST(LAYER_TRANSPARENT, coin_seg3_dl_030078F0),
         GEO_DISPLAY_LIST(LAYER_TRANSPARENT, coin_seg3_dl_03007918),
         GEO_DISPLAY_LIST(LAYER_TRANSPARENT, coin_seg3_dl_03007918),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

const GeoLayout blue_coin_geo[] = {
   GEO_SHADOW(SHADOW_CIRCLE_4_VERTS, 0xB4, 80),
   GEO_OPEN_NODE(),
      GEO_ASM(0, geo_update_layer_transparency),
      GEO_OPEN_NODE(),
         GEO_SWITCH_CASE(2, geo_switch_anim_state),
         GEO_OPEN_NODE(),
            GEO_BRANCH(1, blue_coin_alpha_geo),
            GEO_BRANCH(1, blue_coin_trans_geo),
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_END(),
};


// 0x16000264
const GeoLayout blue_coin_no_shadow_geo[] = {
   GEO_NODE_START(),
   GEO_OPEN_NODE(),
      GEO_ASM(0, geo_update_layer_transparency),
      GEO_OPEN_NODE(),
         GEO_SWITCH_CASE(2, geo_switch_anim_state),
         GEO_OPEN_NODE(),
            GEO_BRANCH(1, blue_coin_alpha_geo),
            GEO_BRANCH(1, blue_coin_trans_geo),
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_END(),
};

// 0x160002C4
const GeoLayout red_coin_geo[] = {
   GEO_SHADOW(SHADOW_CIRCLE_4_VERTS, 0xB4, 80),
   GEO_OPEN_NODE(),
      GEO_SWITCH_CASE(8, geo_switch_anim_state),
      GEO_OPEN_NODE(),
         GEO_DISPLAY_LIST(LAYER_ALPHA, coin_seg3_dl_03007940),
         GEO_DISPLAY_LIST(LAYER_ALPHA, coin_seg3_dl_03007940),
         GEO_DISPLAY_LIST(LAYER_ALPHA, coin_seg3_dl_03007968),
         GEO_DISPLAY_LIST(LAYER_ALPHA, coin_seg3_dl_03007968),
         GEO_DISPLAY_LIST(LAYER_ALPHA, coin_seg3_dl_03007990),
         GEO_DISPLAY_LIST(LAYER_ALPHA, coin_seg3_dl_03007990),
         GEO_DISPLAY_LIST(LAYER_ALPHA, coin_seg3_dl_030079B8),
         GEO_DISPLAY_LIST(LAYER_ALPHA, coin_seg3_dl_030079B8),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_END(),
};

// 0x16000328
const GeoLayout red_coin_no_shadow_geo[] = {
   GEO_NODE_START(),
   GEO_OPEN_NODE(),
      GEO_SWITCH_CASE(8, geo_switch_anim_state),
      GEO_OPEN_NODE(),
         GEO_DISPLAY_LIST(LAYER_ALPHA, coin_seg3_dl_03007940),
         GEO_DISPLAY_LIST(LAYER_ALPHA, coin_seg3_dl_03007940),
         GEO_DISPLAY_LIST(LAYER_ALPHA, coin_seg3_dl_03007968),
         GEO_DISPLAY_LIST(LAYER_ALPHA, coin_seg3_dl_03007968),
         GEO_DISPLAY_LIST(LAYER_ALPHA, coin_seg3_dl_03007990),
         GEO_DISPLAY_LIST(LAYER_ALPHA, coin_seg3_dl_03007990),
         GEO_DISPLAY_LIST(LAYER_ALPHA, coin_seg3_dl_030079B8),
         GEO_DISPLAY_LIST(LAYER_ALPHA, coin_seg3_dl_030079B8),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_END(),
};



const GeoLayout green_coin_geo[] = {
   GEO_SHADOW(SHADOW_CIRCLE_4_VERTS, 0xB4, 80),
   GEO_OPEN_NODE(),
      GEO_SWITCH_CASE(8, geo_switch_anim_state),
      GEO_OPEN_NODE(),
         GEO_DISPLAY_LIST(LAYER_ALPHA, green_coin_dl_1),
         GEO_DISPLAY_LIST(LAYER_ALPHA, green_coin_dl_1),
         GEO_DISPLAY_LIST(LAYER_ALPHA, green_coin_dl_2),
         GEO_DISPLAY_LIST(LAYER_ALPHA, green_coin_dl_2),
         GEO_DISPLAY_LIST(LAYER_ALPHA, green_coin_dl_3),
         GEO_DISPLAY_LIST(LAYER_ALPHA, green_coin_dl_3),
         GEO_DISPLAY_LIST(LAYER_ALPHA, green_coin_dl_4),
         GEO_DISPLAY_LIST(LAYER_ALPHA, green_coin_dl_4),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_END(),
};


const GeoLayout green_coin_no_shadow_geo[] = {
   GEO_NODE_START(),
   GEO_OPEN_NODE(),
      GEO_SWITCH_CASE(8, geo_switch_anim_state),
      GEO_OPEN_NODE(),
         GEO_DISPLAY_LIST(LAYER_ALPHA, green_coin_dl_1),
         GEO_DISPLAY_LIST(LAYER_ALPHA, green_coin_dl_1),
         GEO_DISPLAY_LIST(LAYER_ALPHA, green_coin_dl_2),
         GEO_DISPLAY_LIST(LAYER_ALPHA, green_coin_dl_2),
         GEO_DISPLAY_LIST(LAYER_ALPHA, green_coin_dl_3),
         GEO_DISPLAY_LIST(LAYER_ALPHA, green_coin_dl_3),
         GEO_DISPLAY_LIST(LAYER_ALPHA, green_coin_dl_4),
         GEO_DISPLAY_LIST(LAYER_ALPHA, green_coin_dl_4),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_END(),
};