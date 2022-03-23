#include <PR/ultratypes.h>

#include "sm64.h"
#include "actors/common1.h"
#include "gfx_dimensions.h"
#include "game_init.h"
#include "level_update.h"
#include "camera.h"
#include "print.h"
#include "ingame_menu.h"
#include "hud.h"
#include "segment2.h"
#include "area.h"
#include "save_file.h"
#include "print.h"
#include "engine/surface_load.h"
#include "game/object_helpers.h"
//#include "src/s2d_engine/init.h"
#include "!COMIT_LIBRARY.h"
//#include "s2d_engine/s2d_draw.h"
//#include "s2d_engine/s2d_print.h"
#include "object_list_processor.h"
#include "puppyprint.h"
#include "include/config.h"

/* @file hud.c
 * This file implements HUD rendering and power meter animations.
 * That includes stars, lives, coins, camera status, power meter, timer
 * cannon reticle, and the unused keys.
 **/



// ------------- FPS COUNTER ---------------
// To use it, call print_fps(x,y); every frame.
#define FRAMETIME_COUNT 30

OSTime frameTimes[FRAMETIME_COUNT];
u8 curFrameTimeIndex = 0;

#include "PR/os_convert.h"

// Call once per frame
f32 calculate_and_update_fps() {
    OSTime newTime = osGetTime();
    OSTime oldTime = frameTimes[curFrameTimeIndex];
    frameTimes[curFrameTimeIndex] = newTime;

    curFrameTimeIndex++;
    if (curFrameTimeIndex >= FRAMETIME_COUNT) {
        curFrameTimeIndex = 0;
    }
    return ((f32)FRAMETIME_COUNT * 1000000.0f) / (s32)OS_CYCLES_TO_USEC(newTime - oldTime);
}

void print_fps(s32 x, s32 y) {
    f32 fps = calculate_and_update_fps();
    char text[14];

    sprintf(text, "FPS %2.2f", fps);
    #ifdef PUPPYPRINT
    print_small_text(x, y, text, PRINT_TEXT_ALIGN_LEFT, PRINT_ALL, FONT_OUTLINE);
    #else
    print_text(x, y, text);
    #endif

}

// ------------ END OF FPS COUNER -----------------



struct UnusedHUDStruct {
    u32 unused1;
    u16 unused2;
    u16 unused3;
};

struct CameraHUD {
    s16 status;
};

// Stores health segmented value defined by numHealthWedges
// When the HUD is rendered this value is 8, full health.
static s16 sPowerMeterStoredHealth;

struct PowerMeterHUD sPowerMeterHUD = {
    POWER_METER_HIDDEN,
    40,
    166,
    1.0,
};

// Power Meter timer that keeps counting when it's visible.
// Gets reset when the health is filled and stops counting
// when the power meter is hidden.
s32 sPowerMeterVisibleTimer = 0;

s32 gHudTopY = 209; // default 209, high is 225
s32 gHudStarsX = 22;
// s32 gHuds2dX = 0;
//UNUSED static struct UnusedHUDStruct sUnusedHUDValues = { 0x00, 0x0A, 0x00 };

static struct CameraHUD sCameraHUD = { CAM_STATUS_NONE };






Gfx target_target_ci4_aligner[] = {gsSPEndDisplayList()};
u8 target_target_ci4[] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x22, 
	0x32, 0x13, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x02, 0x42, 0x23, 0x11, 
	0x32, 0x21, 0x22, 0x20, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x25, 0x12, 0x12, 0x32, 
	0x22, 0x22, 0x22, 0x21, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x62, 0x32, 0x32, 0x10, 0x00, 
	0x00, 0x02, 0x21, 0x23, 0x62, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x01, 0x32, 0x21, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x22, 0x21, 0x20, 0x00, 0x00, 
	0x00, 0x00, 0x22, 0x12, 0x20, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x01, 0x22, 0x22, 0x00, 0x00, 
	0x00, 0x00, 0x32, 0x26, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x12, 0x22, 0x00, 0x00, 
	0x00, 0x03, 0x63, 0x20, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x02, 0x32, 0x60, 0x00, 
	0x00, 0x12, 0x32, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x22, 0x26, 0x00, 
	0x00, 0x22, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x61, 0x00, 
	0x00, 0x32, 0x20, 0x00, 0x00, 0x00, 0x00, 0x21, 
	0x21, 0x00, 0x00, 0x00, 0x00, 0x02, 0x22, 0x00, 
	0x02, 0x32, 0x20, 0x00, 0x00, 0x00, 0x21, 0x32, 
	0x23, 0x21, 0x00, 0x00, 0x00, 0x01, 0x27, 0x20, 
	0x01, 0x21, 0x00, 0x00, 0x00, 0x00, 0x32, 0x62, 
	0x22, 0x32, 0x00, 0x00, 0x00, 0x00, 0x22, 0x10, 
	0x02, 0x23, 0x00, 0x00, 0x00, 0x02, 0x22, 0x12, 
	0x23, 0x21, 0x60, 0x00, 0x00, 0x00, 0x24, 0x10, 
	0x02, 0x32, 0x00, 0x00, 0x00, 0x05, 0x64, 0x11, 
	0x23, 0x22, 0x10, 0x00, 0x00, 0x00, 0x22, 0x20, 
	0x02, 0x12, 0x00, 0x00, 0x00, 0x02, 0x32, 0x22, 
	0x23, 0x31, 0x10, 0x00, 0x00, 0x00, 0x22, 0x20, 
	0x02, 0x21, 0x00, 0x00, 0x00, 0x02, 0x22, 0x12, 
	0x22, 0x22, 0x40, 0x00, 0x00, 0x00, 0x12, 0x20, 
	0x02, 0x63, 0x00, 0x00, 0x00, 0x00, 0x23, 0x21, 
	0x21, 0x65, 0x00, 0x00, 0x00, 0x00, 0x22, 0x20, 
	0x03, 0x25, 0x20, 0x00, 0x00, 0x00, 0x12, 0x21, 
	0x21, 0x33, 0x00, 0x00, 0x00, 0x02, 0x23, 0x20, 
	0x00, 0x26, 0x30, 0x00, 0x00, 0x00, 0x00, 0x22, 
	0x22, 0x00, 0x00, 0x00, 0x00, 0x02, 0x22, 0x00, 
	0x00, 0x22, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x12, 0x00, 
	0x00, 0x23, 0x22, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x62, 0x12, 0x00, 
	0x00, 0x02, 0x22, 0x30, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x02, 0x22, 0x20, 0x00, 
	0x00, 0x00, 0x12, 0x23, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x12, 0x62, 0x00, 0x00, 
	0x00, 0x00, 0x23, 0x26, 0x30, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x03, 0x22, 0x22, 0x00, 0x00, 
	0x00, 0x00, 0x03, 0x16, 0x14, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x21, 0x32, 0x20, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x12, 0x32, 0x32, 0x40, 0x00, 
	0x00, 0x01, 0x22, 0x22, 0x26, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x22, 0x12, 0x11, 0x62, 
	0x22, 0x22, 0x22, 0x32, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x05, 0x23, 0x22, 0x62, 
	0x23, 0x22, 0x32, 0x20, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x31, 0x11, 
	0x22, 0x33, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	
};

Gfx target_target_ci4_pal_rgba16_aligner[] = {gsSPEndDisplayList()};
u8 target_target_ci4_pal_rgba16[] = {
	0x00, 0x00, 0xb0, 0x01, 0xa8, 0x01, 0xb0, 0x43, 
	0xb8, 0x85, 0xb8, 0x43, 0xa0, 0x01, 0x98, 0x01, 
	
};

Vtx target_rect_mesh_vtx_0[4] = {
	{{{-16, -16, 0},0, {-16, 1008},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{16, -16, 0},0, {1008, 1008},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{16, 16, 0},0, {1008, -16},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-16, 16, 0},0, {-16, -16},{0x0, 0x0, 0x7F, 0xFF}}},
};

Gfx target_rect_mesh_tri_0[] = {
	gsSPVertex(target_rect_mesh_vtx_0 + 0, 4, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 2, 3, 0),
	gsSPEndDisplayList(),
};

Gfx mat_target_target_layer1[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, TEXEL0, TEXEL0, 0, ENVIRONMENT, 0, 0, 0, 0, TEXEL0, TEXEL0, 0, ENVIRONMENT, 0),
	gsSPClearGeometryMode(G_CULL_BACK),
	gsDPSetRenderMode(G_RM_AA_ZB_TEX_EDGE, G_RM_AA_ZB_TEX_EDGE2),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetTextureLUT(G_TT_RGBA16),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, target_target_ci4_pal_rgba16),
	gsDPTileSync(),
	gsDPSetTile(0, 0, 0, 256, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadSync(),
	gsDPLoadTLUTCmd(7, 7),
	gsDPPipeSync(),
	gsDPTileSync(),
	gsDPSetTextureImage(G_IM_FMT_CI, G_IM_SIZ_16b, 1, target_target_ci4),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_16b, 0, 0, 7, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0),
	gsDPLoadSync(),
	gsDPLoadBlock(7, 0, 0, 255, 1024),
	gsDPPipeSync(),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_4b, 2, 0, 0, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPEndDisplayList(),
};

Gfx mat_revert_target_target_layer1[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_CULL_BACK),
	gsDPSetRenderMode(G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2),
	gsDPSetTextureLUT(G_TT_NONE),
	gsSPEndDisplayList(),
};

Gfx target_rect_mesh[] = {
	gsSPDisplayList(mat_target_target_layer1),
	gsSPDisplayList(target_rect_mesh_tri_0),
	gsSPDisplayList(mat_revert_target_target_layer1),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsSPEndDisplayList(),
};



extern struct Object *gTomatoObjs[3];

void render_targets(void) {
    struct Object *obj1 = gTomatoObjs[0];
    struct Object *obj2 = gTomatoObjs[1];
    struct Object *obj3 = gTomatoObjs[2];
    if (obj1 && obj1->os16F8 > 0) {
        render_target(obj1);
        obj1->os16F8--;
    }
    if (obj2 && obj2->os16F8 > 0) {
        render_target(obj2);
        obj2->os16F8--;
    }
    if (obj3 && obj3->os16F8 > 0) {
        render_target(obj3);
        obj3->os16F8--;
    }

}

void create_dl_scale_matrix(s8 pushOp, f32 x, f32 y, f32 z);

void render_target(struct Object *obj) {
    create_dl_translation_matrix(MENU_MTX_PUSH, (f32)obj->os16F4, (f32)obj->os16F6, 0.0f);
    create_dl_scale_matrix(MENU_MTX_NOPUSH, 0.5f, 0.5f, 1.0f);
    gDPSetEnvColor(gDisplayListHead++, 63, 192, 254, 63);
    gSPDisplayList(gDisplayListHead++, &target_rect_mesh);
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
}






/**
 * Renders a rgba16 16x16 glyph texture from a table list.
 */
void render_hud_tex_lut(s32 x, s32 y, u8 *texture) {
    Gfx* dlhead = gDisplayListHead;
    gDPPipeSync(dlhead++);
    gDPSetTextureImage(dlhead++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture);
    gSPDisplayList(dlhead++, &dl_hud_img_load_tex_block);
    gSPTextureRectangle(dlhead++, x << 2, y << 2, (x + 15) << 2, (y + 15) << 2,
                        G_TX_RENDERTILE, 0, 0, 4 << 10, 1 << 10);
    gDisplayListHead = dlhead;
}

/**
 * Renders a rgba16 8x8 glyph texture from a table list.
 */
void render_hud_small_tex_lut(s32 x, s32 y, u8 *texture) {
    Gfx* dlhead = gDisplayListHead;
    gDPSetTile(dlhead++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0,
                G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD);
    gDPTileSync(dlhead++);
    gDPSetTile(dlhead++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 2, 0, G_TX_RENDERTILE, 0,
                G_TX_CLAMP, 3, G_TX_NOLOD, G_TX_CLAMP, 3, G_TX_NOLOD);
    gDPSetTileSize(dlhead++, G_TX_RENDERTILE, 0, 0, (8 - 1) << G_TEXTURE_IMAGE_FRAC, (8 - 1) << G_TEXTURE_IMAGE_FRAC);
    gDPPipeSync(dlhead++);
    gDPSetTextureImage(dlhead++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture);
    gDPLoadSync(dlhead++);
    gDPLoadBlock(dlhead++, G_TX_LOADTILE, 0, 0, 8 * 8 - 1, CALC_DXT(8, G_IM_SIZ_16b_BYTES));
    gSPTextureRectangle(dlhead++, x << 2, y << 2, (x + 7) << 2, (y + 7) << 2, G_TX_RENDERTILE,
                        0, 0, 4 << 10, 1 << 10);
    gDisplayListHead = dlhead;
}

/**
 * Renders power meter health segment texture using a table list.
 */
void render_power_meter_health_segment(s16 numHealthWedges) {
    u8 *(*healthLUT)[] = segmented_to_virtual(&power_meter_health_segments_lut);
    Gfx* dlhead = gDisplayListHead;

    gDPPipeSync(dlhead++);
    gDPSetTextureImage(dlhead++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1,
                       (*healthLUT)[numHealthWedges - 1]);
    gDPLoadSync(dlhead++);
    gDPLoadBlock(dlhead++, G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES));
    gSP1Triangle(dlhead++, 0, 1, 2, 0);
    gSP1Triangle(dlhead++, 0, 2, 3, 0);
    gDisplayListHead = dlhead;
}

/**
 * Renders power meter display lists.
 * That includes the "POWER" base and the colored health segment textures.
 */
void render_dl_power_meter(s16 numHealthWedges) {
    Mtx *mtx = alloc_display_list(sizeof(Mtx));

    if (mtx == NULL) {
        return;
    }

    guTranslate(mtx, (f32) sPowerMeterHUD.x, (f32) sPowerMeterHUD.y, 0);

    gSPMatrix(gDisplayListHead++, VIRTUAL_TO_PHYSICAL(mtx++),
              G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_PUSH);
    gSPDisplayList(gDisplayListHead++, &dl_power_meter_base);

    if (numHealthWedges != 0) {
        gSPDisplayList(gDisplayListHead++, &dl_power_meter_health_segments_begin);
        render_power_meter_health_segment(numHealthWedges);
        gSPDisplayList(gDisplayListHead++, &dl_power_meter_health_segments_end);
    }

    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
}

/**
 * Power meter animation called when there's less than 8 health segments
 * Checks its timer to later change into deemphasizing mode.
 */
void animate_power_meter_emphasized(void) {
    s16 hudDisplayFlags = gHudDisplay.flags;

    if (!(hudDisplayFlags & HUD_DISPLAY_FLAG_EMPHASIZE_POWER)) {
        if (sPowerMeterVisibleTimer == 45.0) {
            sPowerMeterHUD.animation = POWER_METER_DEEMPHASIZING;
        }
    } else {
        sPowerMeterVisibleTimer = 0;
    }
}

/**
 * Power meter animation called after emphasized mode.
 * Moves power meter y pos speed until it's at 200 to be visible.
 */
static void animate_power_meter_deemphasizing(void) {
    s16 speed = 5;

    if (sPowerMeterHUD.y > 180) {
        speed = 3;
    }

    if (sPowerMeterHUD.y > 190) {
        speed = 2;
    }

    if (sPowerMeterHUD.y > 195) {
        speed = 1;
    }

    sPowerMeterHUD.y += speed;

    if (sPowerMeterHUD.y > 200) {
        sPowerMeterHUD.y = 200;
        sPowerMeterHUD.animation = POWER_METER_VISIBLE;
    }
}

/**
 * Power meter animation called when there's 8 health segments.
 * Moves power meter y pos quickly until it's at 301 to be hidden.
 */
static void animate_power_meter_hiding(void) {
    sPowerMeterHUD.y += 20;
    if (sPowerMeterHUD.y > 300) {
        sPowerMeterHUD.animation = POWER_METER_HIDDEN;
        sPowerMeterVisibleTimer = 0;
    }
}

/**
 * Handles power meter actions depending of the health segments values.
 */
void handle_power_meter_actions(s16 numHealthWedges) {
    // Show power meter if health is not full, less than 8
    if (numHealthWedges < 8 && sPowerMeterStoredHealth == 8
        && sPowerMeterHUD.animation == POWER_METER_HIDDEN) {
        sPowerMeterHUD.animation = POWER_METER_EMPHASIZED;
        sPowerMeterHUD.y = 166;
    }

    // Show power meter if health is full, has 8
    if (numHealthWedges == 8 && sPowerMeterStoredHealth == 7) {
        sPowerMeterVisibleTimer = 0;
    }

    // After health is full, hide power meter
    if (numHealthWedges == 8 && sPowerMeterVisibleTimer > 45.0) {
        sPowerMeterHUD.animation = POWER_METER_HIDING;
    }

    // Update to match health value
    sPowerMeterStoredHealth = numHealthWedges;

    // If Mario is swimming, keep power meter visible
    if (gPlayerCameraState->action & ACT_FLAG_SWIMMING) {
        if (sPowerMeterHUD.animation == POWER_METER_HIDDEN
            || sPowerMeterHUD.animation == POWER_METER_EMPHASIZED) {
            sPowerMeterHUD.animation = POWER_METER_DEEMPHASIZING;
            sPowerMeterHUD.y = 166;
        }
        sPowerMeterVisibleTimer = 0;
    }
}

/**
 * Renders the power meter that shows when Mario is in underwater
 * or has taken damage and has less than 8 health segments.
 * And calls a power meter animation function depending of the value defined.
 */
void render_hud_power_meter(void) {
    s16 shownHealthWedges = gHudDisplay.wedges;

    if (sPowerMeterHUD.animation != POWER_METER_HIDING) {
        handle_power_meter_actions(shownHealthWedges);
    }

    if (sPowerMeterHUD.animation == POWER_METER_HIDDEN) {
        return;
    }

    switch (sPowerMeterHUD.animation) {
        case POWER_METER_EMPHASIZED:
            animate_power_meter_emphasized();
            break;
        case POWER_METER_DEEMPHASIZING:
            animate_power_meter_deemphasizing();
            break;
        case POWER_METER_HIDING:
            animate_power_meter_hiding();
            break;
        default:
            break;
    }

    render_dl_power_meter(shownHealthWedges);

    sPowerMeterVisibleTimer++;
}

#ifdef VERSION_JP
#define HUD_TOP_Y 210
#else
#define HUD_TOP_Y 209
#endif

/**
 * Renders the amount of lives Mario has.
 */
void render_hud_mario_lives(void) {
    print_text(GFX_DIMENSIONS_RECT_FROM_LEFT_EDGE(22), HUD_TOP_Y, ","); // 'Mario Head' glyph
    print_text(GFX_DIMENSIONS_RECT_FROM_LEFT_EDGE(38), HUD_TOP_Y, "*"); // 'X' glyph
    print_text_fmt_int(GFX_DIMENSIONS_RECT_FROM_LEFT_EDGE(54), HUD_TOP_Y, "%d", gHudDisplay.lives);
}

/**
 * Renders the amount of coins collected.
 */
void render_hud_coins(void) {
    s32 hudY = gHudTopY;
    print_text(168+30, hudY, "+"); // 'Coin' glyph
    print_text(184+30, hudY, "*"); // 'X' glyph
    print_text_fmt_int(198+30, hudY, "%d", gHudDisplay.coins);
}

#ifdef VERSION_JP
#define HUD_STARS_X 73
#else
#define HUD_STARS_X 78
#endif

/**
 * Renders the amount of stars collected.
 * Disables "X" glyph when Mario has 100 stars or more.
 */
void render_hud_stars(void) {
    s32 hudY = gHudTopY;
    calculate_num_currency();

    print_text(GFX_DIMENSIONS_RECT_FROM_LEFT_EDGE(gHudStarsX), hudY, "-"); // 'Star' glyph

    print_text_fmt_int(GFX_DIMENSIONS_RECT_FROM_LEFT_EDGE(gHudStarsX + 16), hudY, "%d", gMarioState->numStars);
}

/**
 * Renders the amount of keys collected.
 */
void render_hud_keys(void) {
    s16 i;
    s16 keyCount = CL_count_bits(save_file_get_keys(0)) - CL_count_bits(save_file_get_keys(1));
    for (i = 0; i < keyCount; i++) {
        print_text(GFX_DIMENSIONS_RECT_FROM_RIGHT_EDGE(30) - (i * 6), 15, "/"); // unused glyph - beta key
    }
}

/**
 * Renders the timer when Mario start sliding in PSS.
 */
void render_hud_timer(void) {
    u8 *(*hudLUT)[58] = segmented_to_virtual(&main_hud_lut);
    u16 timerValFrames = gHudDisplay.timer;
    u16 timerMins = timerValFrames / (30 * 60);
    u16 timerSecs = (timerValFrames - (timerMins * 1800)) / 30;
    u16 timerFracSecs = ((timerValFrames - (timerMins * 1800) - (timerSecs * 30)) & 0xFFFF) / 3;

#ifdef VERSION_EU
    switch (eu_get_language()) {
        case LANGUAGE_ENGLISH:
            print_text(GFX_DIMENSIONS_RECT_FROM_RIGHT_EDGE(150), 185, "TIME");
            break;
        case LANGUAGE_FRENCH:
            print_text(GFX_DIMENSIONS_RECT_FROM_RIGHT_EDGE(155), 185, "TEMPS");
            break;
        case LANGUAGE_GERMAN:
            print_text(GFX_DIMENSIONS_RECT_FROM_RIGHT_EDGE(150), 185, "ZEIT");
            break;
    }
#else
    print_text(GFX_DIMENSIONS_RECT_FROM_RIGHT_EDGE(150), 185, "TIME");
#endif

    print_text_fmt_int(GFX_DIMENSIONS_RECT_FROM_RIGHT_EDGE(91), 185, "%0d", timerMins);
    print_text_fmt_int(GFX_DIMENSIONS_RECT_FROM_RIGHT_EDGE(71), 185, "%02d", timerSecs);
    print_text_fmt_int(GFX_DIMENSIONS_RECT_FROM_RIGHT_EDGE(37), 185, "%d", timerFracSecs);

    gSPDisplayList(gDisplayListHead++, dl_hud_img_begin);
    render_hud_tex_lut(GFX_DIMENSIONS_RECT_FROM_RIGHT_EDGE(81), 32, (*hudLUT)[GLYPH_APOSTROPHE]);
    render_hud_tex_lut(GFX_DIMENSIONS_RECT_FROM_RIGHT_EDGE(46), 32, (*hudLUT)[GLYPH_DOUBLE_QUOTE]);
    gSPDisplayList(gDisplayListHead++, dl_hud_img_end);
}

/**
 * Sets HUD status camera value depending of the actions
 * defined in update_camera_status.
 */
void set_hud_camera_status(s16 status) {
    sCameraHUD.status = status;
}

/**
 * Renders camera HUD glyphs using a table list, depending of
 * the camera status called, a defined glyph is rendered.
 */
void render_hud_camera_status(void) {
    u8 *(*cameraLUT)[6] = segmented_to_virtual(&main_hud_camera_lut);
    s32 x = GFX_DIMENSIONS_RECT_FROM_RIGHT_EDGE(54);
    s32 y = 205;

    if (sCameraHUD.status == CAM_STATUS_NONE) {
        return;
    }

    gSPDisplayList(gDisplayListHead++, dl_hud_img_begin);
    render_hud_tex_lut(x, y, (*cameraLUT)[GLYPH_CAM_CAMERA]);

    switch (sCameraHUD.status & CAM_STATUS_MODE_GROUP) {
        case CAM_STATUS_MARIO:
            render_hud_tex_lut(x + 16, y, (*cameraLUT)[GLYPH_CAM_MARIO_HEAD]);
            break;
        case CAM_STATUS_LAKITU:
            render_hud_tex_lut(x + 16, y, (*cameraLUT)[GLYPH_CAM_LAKITU_HEAD]);
            break;
        case CAM_STATUS_FIXED:
            render_hud_tex_lut(x + 16, y, (*cameraLUT)[GLYPH_CAM_FIXED]);
            break;
    }

    switch (sCameraHUD.status & CAM_STATUS_C_MODE_GROUP) {
        case CAM_STATUS_C_DOWN:
            render_hud_small_tex_lut(x + 4, y + 16, (*cameraLUT)[GLYPH_CAM_ARROW_DOWN]);
            break;
        case CAM_STATUS_C_UP:
            render_hud_small_tex_lut(x + 4, y - 8, (*cameraLUT)[GLYPH_CAM_ARROW_UP]);
            break;
    }

    gSPDisplayList(gDisplayListHead++, dl_hud_img_end);
}

extern int gPointLightCompatibilityMode;

/**
 * Render HUD strings using hudDisplayFlags with it's render functions,
 * excluding the cannon reticle which detects a camera preset for it.
 */
void render_hud(void) {
    s16 hudDisplayFlags = gHudDisplay.flags;

    if (hudDisplayFlags == HUD_DISPLAY_NONE) {
        sPowerMeterHUD.animation = POWER_METER_HIDDEN;
        sPowerMeterStoredHealth = 8;
        sPowerMeterVisibleTimer = 0;
    } else {
        create_dl_ortho_matrix();

        if (gCurrentArea != NULL && gCurrentArea->camera->mode == CAMERA_MODE_INSIDE_CANNON) {
            render_hud_cannon_reticle();
        }
        if (sCurrPlayMode == 2) {
            gHudTopY = 209;
        }

        if (gHudTopY < 225 && gCamera->cutscene != CUTSCENE_OPENING) {
            render_hud_coins();
        }

        render_hud_keys();

        if (gHudTopY < 225 && (gCurrLevelNum == LEVEL_CCM || gCurrLevelNum == LEVEL_BBH)) {
            render_hud_stars();
        }

        if (hudDisplayFlags & HUD_DISPLAY_FLAG_CAMERA_AND_POWER) {
            render_hud_power_meter();
            //render_hud_camera_status();
        }

        if (hudDisplayFlags & HUD_DISPLAY_FLAG_TIMER) {
            render_hud_timer();
        }


        if (gCurrLevelNum == LEVEL_HMC && sCurrPlayMode == 0) {
            render_targets();
        }


        if (gSurfacePoolError & NOT_ENOUGH_ROOM_FOR_SURFACES)
        {
            print_text(10, 40, "SURFACE POOL FULL");
        }
        if (gSurfacePoolError & NOT_ENOUGH_ROOM_FOR_NODES)
        {
            print_text(10, 60, "SURFACE NODE POOL FULL");
        }
        //print_text_fmt_int(10, 10, "%d", gPointLightCompatibilityMode);
    }
}

// ...
/*void print_s2d_string(s16 x, s16 y, char *str) {
	s2d_init();
	uObjMtx *buffer;
	buffer = alloc_display_list(0x200 * sizeof(uObjMtx));
	s2d_print(x, y, str, buffer);
	s2d_stop();
}*/

//#include "src/s2d_engine/sprites/room_names.c"

//extern s8 sLevelRoomOffsets[];
//s32 gRoomEntryTimer = -1;

void render_s2d_room_names(void) {
    /*s16 y;
    if (gMarioCurrentRoom != gMarioPreviousRoom2) {
        gRoomEntryTimer = 0;

    }
    gMarioPreviousRoom2 = gMarioCurrentRoom;

    if (gRoomEntryTimer >= 0) {
        gRoomEntryTimer++;
        y = 290;
        if (gRoomEntryTimer < 20) {
            y = 290 - (gRoomEntryTimer * 4);
        } else if (gRoomEntryTimer < 70) {
            y = 210;
        } else {
            y = 210 + ((gRoomEntryTimer - 70) * 4);
        }

        print_s2d_string(40, y, roomNames[(gMarioCurrentRoom - 1) + sLevelRoomOffsets[gCurrCourseNum - 1]]);
        if (gRoomEntryTimer > 90) {
            gRoomEntryTimer = -1;
        }
    }
    //print_text_fmt_int(20, 20, "%d", (gMarioCurrentRoom - 1) + sLevelRoomOffsets[gCurrCourseNum - 1]);*/
}


#include "src/s2d_engine/sprites/starpiece/starpiece.c"
#include "src/s2d_engine/sprites/starpiece_chart/starpiece_chart.c"

uObjMtx starpiecebuf[0x8];

/*void s2d_print_starpiece(s16 x, s16 y, s16 idx) {
	s2d_init();
    call_starpiece_sprite_dl(idx, x, y, &starpiecebuf[idx], idx);
	s2d_stop();
}*/

/*void render_s2d_hud(void) {
    s16 i, h;
    //print_text_fmt_int(20, 20, "%d", main_pool_available());
    if (gHudDisplay.flags & HUD_DISPLAY_FLAG_STAR_PIECE) {
        starpiece_chart_bg.b.frameX = approach_s16_symmetric(starpiece_chart_bg.b.frameX, 0<<2, 4<<2);
    } else {
        starpiece_chart_bg.b.frameX = approach_s16_symmetric(starpiece_chart_bg.b.frameX, -120, 4<<2);
    }
    if (sCurrPlayMode == 2) {
        starpiece_chart_bg.b.frameX = 0;
    }
    if (starpiece_chart_bg.b.frameX != -120) {
        s2d_init();
        gSPDisplayList(gDisplayListHead++, starpiece_chart_bg_dl);
        s2d_stop();
        //h = save_file_get_star_piece();
        //render_s2d_star_pieces();
        s2d_print_starpiece(-20, -20, 0);
        h = save_file_get_star_piece();
        for (i = 0; i < 5; i++) {
            if (h & (1 << i)) {
                s2d_print_starpiece((starpiece_chart_bg.b.frameX / 5) + 4, 70 + (i * 21), i+1);
            }
        }
    }
    //render_s2d_room_names();
}*/