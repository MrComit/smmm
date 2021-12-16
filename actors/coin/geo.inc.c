// 0x1600013C
const GeoLayout yellow_coin_geo[] = {
   GEO_SHADOW(SHADOW_CIRCLE_4_VERTS, 0xB4, 50),
   GEO_OPEN_NODE(),
      GEO_SWITCH_CASE(8, geo_switch_anim_state),
      GEO_OPEN_NODE(),
         GEO_DISPLAY_LIST(LAYER_ALPHA, coin_seg3_dl_yellow_0),
         GEO_DISPLAY_LIST(LAYER_ALPHA, coin_seg3_dl_yellow_22_5),
         GEO_DISPLAY_LIST(LAYER_ALPHA, coin_seg3_dl_yellow_45),
         GEO_DISPLAY_LIST(LAYER_ALPHA, coin_seg3_dl_yellow_67_5),
         GEO_DISPLAY_LIST(LAYER_ALPHA, coin_seg3_dl_yellow_90),
         GEO_DISPLAY_LIST(LAYER_ALPHA, coin_seg3_dl_yellow_67_5_r),
         GEO_DISPLAY_LIST(LAYER_ALPHA, coin_seg3_dl_yellow_45_r),
         GEO_DISPLAY_LIST(LAYER_ALPHA, coin_seg3_dl_yellow_22_5_r),
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
         GEO_DISPLAY_LIST(LAYER_ALPHA, coin_seg3_dl_yellow_0),
         GEO_DISPLAY_LIST(LAYER_ALPHA, coin_seg3_dl_yellow_22_5),
         GEO_DISPLAY_LIST(LAYER_ALPHA, coin_seg3_dl_yellow_45),
         GEO_DISPLAY_LIST(LAYER_ALPHA, coin_seg3_dl_yellow_67_5),
         GEO_DISPLAY_LIST(LAYER_ALPHA, coin_seg3_dl_yellow_90),
         GEO_DISPLAY_LIST(LAYER_ALPHA, coin_seg3_dl_yellow_67_5_r),
         GEO_DISPLAY_LIST(LAYER_ALPHA, coin_seg3_dl_yellow_45_r),
         GEO_DISPLAY_LIST(LAYER_ALPHA, coin_seg3_dl_yellow_22_5_r),
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
         GEO_DISPLAY_LIST(LAYER_ALPHA, coin_seg3_dl_blue_0),
         GEO_DISPLAY_LIST(LAYER_ALPHA, coin_seg3_dl_blue_22_5),
         GEO_DISPLAY_LIST(LAYER_ALPHA, coin_seg3_dl_blue_45),
         GEO_DISPLAY_LIST(LAYER_ALPHA, coin_seg3_dl_blue_67_5),
         GEO_DISPLAY_LIST(LAYER_ALPHA, coin_seg3_dl_blue_90),
         GEO_DISPLAY_LIST(LAYER_ALPHA, coin_seg3_dl_blue_67_5_r),
         GEO_DISPLAY_LIST(LAYER_ALPHA, coin_seg3_dl_blue_45_r),
         GEO_DISPLAY_LIST(LAYER_ALPHA, coin_seg3_dl_blue_22_5_r),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

const GeoLayout blue_coin_trans_geo[] = {
   GEO_NODE_START(),
   GEO_OPEN_NODE(),
      GEO_SWITCH_CASE(8, geo_switch_bparam2),
      GEO_OPEN_NODE(),
         GEO_DISPLAY_LIST(LAYER_TRANSPARENT, coin_seg3_dl_blue_0),
         GEO_DISPLAY_LIST(LAYER_TRANSPARENT, coin_seg3_dl_blue_22_5),
         GEO_DISPLAY_LIST(LAYER_TRANSPARENT, coin_seg3_dl_blue_45),
         GEO_DISPLAY_LIST(LAYER_TRANSPARENT, coin_seg3_dl_blue_67_5),
         GEO_DISPLAY_LIST(LAYER_TRANSPARENT, coin_seg3_dl_blue_90),
         GEO_DISPLAY_LIST(LAYER_TRANSPARENT, coin_seg3_dl_blue_67_5_r),
         GEO_DISPLAY_LIST(LAYER_TRANSPARENT, coin_seg3_dl_blue_45_r),
         GEO_DISPLAY_LIST(LAYER_TRANSPARENT, coin_seg3_dl_blue_22_5_r),
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
         GEO_DISPLAY_LIST(LAYER_ALPHA, coin_seg3_dl_red_0),
         GEO_DISPLAY_LIST(LAYER_ALPHA, coin_seg3_dl_red_22_5),
         GEO_DISPLAY_LIST(LAYER_ALPHA, coin_seg3_dl_red_45),
         GEO_DISPLAY_LIST(LAYER_ALPHA, coin_seg3_dl_red_67_5),
         GEO_DISPLAY_LIST(LAYER_ALPHA, coin_seg3_dl_red_90),
         GEO_DISPLAY_LIST(LAYER_ALPHA, coin_seg3_dl_red_67_5_r),
         GEO_DISPLAY_LIST(LAYER_ALPHA, coin_seg3_dl_red_45_r),
         GEO_DISPLAY_LIST(LAYER_ALPHA, coin_seg3_dl_red_22_5_r),
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
         GEO_DISPLAY_LIST(LAYER_ALPHA, coin_seg3_dl_red_0),
         GEO_DISPLAY_LIST(LAYER_ALPHA, coin_seg3_dl_red_22_5),
         GEO_DISPLAY_LIST(LAYER_ALPHA, coin_seg3_dl_red_45),
         GEO_DISPLAY_LIST(LAYER_ALPHA, coin_seg3_dl_red_67_5),
         GEO_DISPLAY_LIST(LAYER_ALPHA, coin_seg3_dl_red_90),
         GEO_DISPLAY_LIST(LAYER_ALPHA, coin_seg3_dl_red_67_5_r),
         GEO_DISPLAY_LIST(LAYER_ALPHA, coin_seg3_dl_red_45_r),
         GEO_DISPLAY_LIST(LAYER_ALPHA, coin_seg3_dl_red_22_5_r),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_END(),
};



const GeoLayout green_coin_geo[] = {
   GEO_SHADOW(SHADOW_CIRCLE_4_VERTS, 0xB4, 80),
   GEO_OPEN_NODE(),
      GEO_SWITCH_CASE(8, geo_switch_anim_state),
      GEO_OPEN_NODE(),
         GEO_DISPLAY_LIST(LAYER_ALPHA, coin_seg3_dl_green_0),
         GEO_DISPLAY_LIST(LAYER_ALPHA, coin_seg3_dl_green_22_5),
         GEO_DISPLAY_LIST(LAYER_ALPHA, coin_seg3_dl_green_45),
         GEO_DISPLAY_LIST(LAYER_ALPHA, coin_seg3_dl_green_67_5),
         GEO_DISPLAY_LIST(LAYER_ALPHA, coin_seg3_dl_green_90),
         GEO_DISPLAY_LIST(LAYER_ALPHA, coin_seg3_dl_green_67_5_r),
         GEO_DISPLAY_LIST(LAYER_ALPHA, coin_seg3_dl_green_45_r),
         GEO_DISPLAY_LIST(LAYER_ALPHA, coin_seg3_dl_green_22_5_r),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_END(),
};


const GeoLayout green_coin_no_shadow_geo[] = {
   GEO_NODE_START(),
   GEO_OPEN_NODE(),
      GEO_SWITCH_CASE(8, geo_switch_anim_state),
      GEO_OPEN_NODE(),
         GEO_DISPLAY_LIST(LAYER_ALPHA, coin_seg3_dl_green_0),
         GEO_DISPLAY_LIST(LAYER_ALPHA, coin_seg3_dl_green_22_5),
         GEO_DISPLAY_LIST(LAYER_ALPHA, coin_seg3_dl_green_45),
         GEO_DISPLAY_LIST(LAYER_ALPHA, coin_seg3_dl_green_67_5),
         GEO_DISPLAY_LIST(LAYER_ALPHA, coin_seg3_dl_green_90),
         GEO_DISPLAY_LIST(LAYER_ALPHA, coin_seg3_dl_green_67_5_r),
         GEO_DISPLAY_LIST(LAYER_ALPHA, coin_seg3_dl_green_45_r),
         GEO_DISPLAY_LIST(LAYER_ALPHA, coin_seg3_dl_green_22_5_r),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_END(),
};