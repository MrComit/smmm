#include <ultra64.h>

#include "actors/common1.h"
#include "area.h"
#include "audio/external.h"
#include "camera.h"
#include "course_table.h"
#include "dialog_ids.h"
#include "engine/math_util.h"
#include "eu_translation.h"
#include "game_init.h"
#include "gfx_dimensions.h"
#include "ingame_menu.h"
#include "level_update.h"
#include "levels/castle_grounds/header.h"
#include "memory.h"
#include "print.h"
#include "save_file.h"
#include "segment2.h"
#include "segment7.h"
#include "seq_ids.h"
#include "sm64.h"
#include "text_strings.h"
#include "types.h"
#include "object_list_processor.h"
#include "config.h"
#include "main.h"
#include "puppyprint.h"
#include "actors/common0.h"
#include "behavior_data.h"
#include "actors/boocoin/geo_header.h"
#include "levels/wf/header.h"
#include "levels/jrb/header.h"
#include "levels/ccm/header.h"
#include "levels/bbh/header.h"
#include "levels/hmc/header.h"
#include "levels/lll/header.h"

#ifdef VERSION_EU
#undef LANGUAGE_FUNCTION
#define LANGUAGE_FUNCTION gInGameLanguage
#endif

u16 gDialogColorFadeTimer;
s8 gLastDialogLineNum;
s32 gDialogVariable;
u16 gDialogTextAlpha;
#if defined(VERSION_EU)
s16 gDialogX;
s16 gDialogY;
#endif
s16 gCutsceneMsgXOffset;
s16 gCutsceneMsgYOffset;
s8 gRedCoinsCollected;
s8 gGreenCoinsCollected;

#if defined(WIDE)
u8 textCurrRatio43[] = { TEXT_HUD_CURRENT_RATIO_43 };
u8 textCurrRatio169[] = { TEXT_HUD_CURRENT_RATIO_169 };
u8 textPressL[] = { TEXT_HUD_PRESS_L };
#endif
u8 textLRoomManager[] = { TEXT_HUD_L_MAP };
u8 textROptions[] = { TEXT_HUD_R_OPTIONS };
u8 textRBack[] = { TEXT_HUD_R_BACK };
u8 textAButton[] = { TEXT_A_BUTTON };
u8 textCurrObj[] = { TEXT_CURR_OBJ };

extern u8 gLastCompletedCourseNum;
extern u8 gLastCompletedStarNum;

enum DialogBoxState {
    DIALOG_STATE_OPENING,
    DIALOG_STATE_VERTICAL,
    DIALOG_STATE_HORIZONTAL,
    DIALOG_STATE_CLOSING
};

enum DialogBoxPageState {
    DIALOG_PAGE_STATE_NONE,
    DIALOG_PAGE_STATE_SCROLL,
    DIALOG_PAGE_STATE_END
};

enum DialogBoxType {
    DIALOG_TYPE_ROTATE, // used in NPCs and level messages
    DIALOG_TYPE_ZOOM    // used in signposts and wall signs and etc
};

#define DEFAULT_DIALOG_BOX_ANGLE 90.0f
#define DEFAULT_DIALOG_BOX_SCALE 19.0f

#if defined(VERSION_US) || defined(VERSION_EU)
u8 gDialogCharWidths[256] = { // TODO: Is there a way to auto generate this?
    7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  6,  6,  6,  6,  6,  6,
    6,  6,  5,  6,  6,  5,  8,  8,  6,  6,  6,  6,  6,  5,  6,  6,
    8,  7,  6,  6,  6,  5,  5,  6,  5,  5,  6,  5,  4,  5,  5,  3,
    7,  5,  5,  5,  6,  5,  5,  5,  5,  5,  7,  7,  5,  5,  4,  4,
    8,  6,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    8,  8,  8,  8,  7,  7,  6,  7,  7,  0,  0,  0,  0,  0,  0,  0,
#ifdef VERSION_EU
    6,  6,  6,  0,  6,  6,  6,  0,  0,  0,  0,  0,  0,  0,  0,  4,
    5,  5,  5,  5,  6,  6,  6,  6,  0,  0,  0,  0,  0,  0,  0,  0,
    5,  5,  5,  0,  6,  6,  6,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  5,  5,  0,  0,  6,  6,  0,  0,  0,  0,  0,  0,  0,  5,  6,
    0,  4,  4,  0,  0,  5,  5,  0,  0,  0,  0,  0,  0,  0,  0,  0,
#else
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  4,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  5,  6,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
#endif
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
#ifdef VERSION_EU
    7,  5, 10,  5,  9,  8,  4,  0,  0,  0,  0,  5,  5,  6,  5,  0,
#else
    7,  5, 10,  5,  9,  8,  4,  0,  0,  0,  0,  0,  0,  0,  0,  0,
#endif
    0,  0,  5,  7,  7,  6,  6,  8,  0,  8, 10,  6,  4, 10,  0,  0
};
#endif

s8 gDialogBoxState = DIALOG_STATE_OPENING;
f32 gDialogBoxOpenTimer = DEFAULT_DIALOG_BOX_ANGLE;
f32 gDialogBoxScale = DEFAULT_DIALOG_BOX_SCALE;
s16 gDialogScrollOffsetY = 0;
s8 gDialogBoxType = DIALOG_TYPE_ROTATE;
s16 gDialogID = DIALOG_NONE;
s16 gLastDialogPageStrPos = 0;
s16 gDialogTextPos = 0;
#ifdef VERSION_EU
s32 gInGameLanguage = LANGUAGE_ENGLISH;
#endif
s8 gDialogLineNum = 1;
s8 gLastDialogResponse = 0;
u8 gMenuHoldKeyIndex = 0;
u8 gMenuHoldKeyTimer = 0;
s32 gDialogResponse = DIALOG_RESPONSE_NONE;



void init_map(void);



void create_dl_identity_matrix(void) {
    Mtx *matrix = (Mtx *) alloc_display_list(sizeof(Mtx));
    Gfx* dlhead = gDisplayListHead;

    if (matrix == NULL) {
        return;
    }

#ifndef GBI_FLOATS
    matrix->m[0][0] = 0x00010000;    matrix->m[1][0] = 0x00000000;    matrix->m[2][0] = 0x00000000;    matrix->m[3][0] = 0x00000000;
    matrix->m[0][1] = 0x00000000;    matrix->m[1][1] = 0x00010000;    matrix->m[2][1] = 0x00000000;    matrix->m[3][1] = 0x00000000;
    matrix->m[0][2] = 0x00000001;    matrix->m[1][2] = 0x00000000;    matrix->m[2][2] = 0x00000000;    matrix->m[3][2] = 0x00000000;
    matrix->m[0][3] = 0x00000000;    matrix->m[1][3] = 0x00000001;    matrix->m[2][3] = 0x00000000;    matrix->m[3][3] = 0x00000000;
#else
    guMtxIdent(matrix);
#endif

    gSPMatrix(dlhead++, VIRTUAL_TO_PHYSICAL(matrix), G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
    gSPMatrix(dlhead++, VIRTUAL_TO_PHYSICAL(matrix), G_MTX_PROJECTION | G_MTX_LOAD | G_MTX_NOPUSH);
    gDisplayListHead = dlhead;
}

void create_dl_translation_matrix(s8 pushOp, f32 x, f32 y, f32 z) {
    Mtx *matrix = (Mtx *) alloc_display_list(sizeof(Mtx));
    Gfx* dlhead = gDisplayListHead;
    if (matrix == NULL) {
        return;
    }

    guTranslate(matrix, x, y, z);

    if (pushOp == MENU_MTX_PUSH) {
        gSPMatrix(dlhead++, VIRTUAL_TO_PHYSICAL(matrix), G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_PUSH);
    }

    if (pushOp == MENU_MTX_NOPUSH) {
        gSPMatrix(dlhead++, VIRTUAL_TO_PHYSICAL(matrix), G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_NOPUSH);
    }
    gDisplayListHead = dlhead;
}

void create_dl_rotation_matrix(s8 pushOp, f32 a, f32 x, f32 y, f32 z) {
    Mtx *matrix = (Mtx *) alloc_display_list(sizeof(Mtx));

    if (matrix == NULL) {
        return;
    }

    guRotate(matrix, a, x, y, z);

    if (pushOp == MENU_MTX_PUSH) {
        gSPMatrix(gDisplayListHead++, VIRTUAL_TO_PHYSICAL(matrix), G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_PUSH);
    }

    if (pushOp == MENU_MTX_NOPUSH) {
        gSPMatrix(gDisplayListHead++, VIRTUAL_TO_PHYSICAL(matrix), G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_NOPUSH);
    }
}

void create_dl_scale_matrix(s8 pushOp, f32 x, f32 y, f32 z) {
    Mtx *matrix = (Mtx *) alloc_display_list(sizeof(Mtx));

    if (matrix == NULL) {
        return;
    }

    guScale(matrix, x, y, z);

    if (pushOp == MENU_MTX_PUSH) {
        gSPMatrix(gDisplayListHead++, VIRTUAL_TO_PHYSICAL(matrix), G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_PUSH);
    }

    if (pushOp == MENU_MTX_NOPUSH) {
        gSPMatrix(gDisplayListHead++, VIRTUAL_TO_PHYSICAL(matrix), G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_NOPUSH);
    }
}

void create_dl_ortho_matrix(void) {
    Mtx *matrix = (Mtx *) alloc_display_list(sizeof(Mtx));
    if (matrix == NULL) {
        return;
    }

    create_dl_identity_matrix();

    guOrtho(matrix, 0.0f, SCREEN_WIDTH, 0.0f, SCREEN_HEIGHT, -10.0f, 10.0f, 1.0f);

    Gfx* dlhead = gDisplayListHead;
    // Should produce G_RDPHALF_1 in Fast3D
    gSPPerspNormalize(dlhead++, 0xFFFF);

    gSPMatrix(dlhead++, VIRTUAL_TO_PHYSICAL(matrix), G_MTX_PROJECTION | G_MTX_MUL | G_MTX_NOPUSH)
    gDisplayListHead = dlhead;
}

#if defined(VERSION_US) || defined(VERSION_EU)
UNUSED
#endif
static u8 *alloc_ia8_text_from_i1(u16 *in, s16 width, s16 height) {
    s32 inPos;
    u16 bitMask;
    u8 *out;
    s16 outPos = 0;

    out = (u8 *) alloc_display_list((u32) width * (u32) height);

    if (out == NULL) {
        return NULL;
    }

    for (inPos = 0; inPos < (width * height) / 16; inPos++) {
        bitMask = 0x8000;

        while (bitMask != 0) {
            if (in[inPos] & bitMask) {
                out[outPos] = 0xFF;
            } else {
                out[outPos] = 0x00;
            }

            bitMask /= 2;
            outPos++;
        }
    }

    return out;
}

void render_generic_char(u8 c) {
    void **fontLUT = segmented_to_virtual(main_font_lut);
    void *packedTexture = segmented_to_virtual(fontLUT[c]);
#if defined(VERSION_JP) || defined(VERSION_SH)
    void *unpackedTexture = alloc_ia8_text_from_i1(packedTexture, 8, 16);
#endif
    Gfx* dlhead = gDisplayListHead;

#ifndef VERSION_EU
    gDPPipeSync(dlhead++);
#endif
#if defined(VERSION_JP) || defined(VERSION_SH)
    gDPSetTextureImage(dlhead++, G_IM_FMT_IA, G_IM_SIZ_8b, 1, VIRTUAL_TO_PHYSICAL(unpackedTexture));
#else
    gDPSetTextureImage(dlhead++, G_IM_FMT_IA, G_IM_SIZ_16b, 1, VIRTUAL_TO_PHYSICAL(packedTexture));
#endif
    gSPDisplayList(dlhead++, dl_ia_text_tex_settings);
#ifdef VERSION_EU
    gSPTextureRectangleFlip(dlhead++, gDialogX << 2, (gDialogY - 16) << 2,
                            (gDialogX + 8) << 2, gDialogY << 2, G_TX_RENDERTILE, 8 << 6, 4 << 6, 1 << 10, 1 << 10);
#endif
    gDisplayListHead = dlhead;
}

#ifdef VERSION_EU
u8 *alloc_ia4_tex_from_i1(u8 *in, s16 width, s16 height) {
    u32 size = (u32) width * (u32) height;
    u8 *out;
    s32 inPos;
    s16 outPos = 0;
    u8 bitMask;

    out = (u8 *) alloc_display_list(size);

    if (out == NULL) {
        return NULL;
    }

    for (inPos = 0; inPos < (width * height) / 4; inPos++) {
        bitMask = 0x80;

        while (bitMask != 0) {
            out[outPos] = (in[inPos] & bitMask) ? 0xF0 : 0x00;
            bitMask /= 2;
            out[outPos] = (in[inPos] & bitMask) ? out[outPos] + 0x0F : out[outPos];
            bitMask /= 2;
            outPos++;
        }
    }

    return out;
}

void render_generic_char_at_pos(s16 xPos, s16 yPos, u8 c) {
    void **fontLUT = segmented_to_virtual(main_font_lut);
    void *packedTexture = segmented_to_virtual(fontLUT[c]);
    void *unpackedTexture = alloc_ia4_tex_from_i1(packedTexture, 8, 8);

    gDPPipeSync(gDisplayListHead++);
    gDPSetTextureImage(gDisplayListHead++, G_IM_FMT_IA, G_IM_SIZ_16b, 1, VIRTUAL_TO_PHYSICAL(unpackedTexture));
    gSPDisplayList(gDisplayListHead++, dl_ia_text_tex_settings);
    gSPTextureRectangleFlip(gDisplayListHead++, xPos << 2, (yPos - 16) << 2, (xPos + 8) << 2, yPos << 2,
                            G_TX_RENDERTILE, 8 << 6, 4 << 6, 1 << 10, 1 << 10);
}

void render_lowercase_diacritic(s16 *xPos, s16 *yPos, u8 letter, u8 diacritic) {
    render_generic_char_at_pos(*xPos, *yPos, letter);
    render_generic_char_at_pos(*xPos, *yPos, diacritic + 0xE7);
    *xPos += gDialogCharWidths[letter];
}

void render_uppercase_diacritic(s16 *xPos, s16 *yPos, u8 letter, u8 diacritic) {
    render_generic_char_at_pos(*xPos, *yPos, letter);
    render_generic_char_at_pos(*xPos, *yPos - 4, diacritic + 0xE3);
    *xPos += gDialogCharWidths[letter];
}
#endif // VERSION_EU

#if defined(VERSION_US) || defined(VERSION_EU)
struct MultiTextEntry {
    u8 length;
    u8 str[4];
};

#define TEXT_THE_RAW ASCII_TO_DIALOG('t'), ASCII_TO_DIALOG('h'), ASCII_TO_DIALOG('e'), 0x00
#define TEXT_YOU_RAW ASCII_TO_DIALOG('y'), ASCII_TO_DIALOG('o'), ASCII_TO_DIALOG('u'), 0x00

enum MultiStringIDs { STRING_THE, STRING_YOU };

/*
 * Place the multi-text string according to the ID passed. (US, EU)
 * 0: 'the'
 * 1: 'you'
 */
#if defined(VERSION_US)
void render_multi_text_string(s8 multiTextID)
#elif defined(VERSION_EU)
void render_multi_text_string(s16 *xPos, s16 *yPos, s8 multiTextID)
#endif
{
    s8 i;
    struct MultiTextEntry textLengths[2] = {
        { 3, { TEXT_THE_RAW } },
        { 3, { TEXT_YOU_RAW } },
    };

    for (i = 0; i < textLengths[multiTextID].length; i++) {
#if defined(VERSION_US)
        render_generic_char(textLengths[multiTextID].str[i]);
        create_dl_translation_matrix(
            MENU_MTX_NOPUSH, (f32)(gDialogCharWidths[textLengths[multiTextID].str[i]]), 0.0f, 0.0f);
#elif defined(VERSION_EU)
        render_generic_char_at_pos(*xPos, *yPos, textLengths[multiTextID].str[i]);
        *xPos += gDialogCharWidths[textLengths[multiTextID].str[i]];
#endif
    }
}
#endif

#if defined(VERSION_JP) || defined(VERSION_SH)
    #define MAX_STRING_WIDTH 18
    #define CHAR_WIDTH_SPACE 5.0f
    #define CHAR_WIDTH_DEFAULT 10.0f
#else
    #define MAX_STRING_WIDTH 16
    #define CHAR_WIDTH_SPACE (f32)(gDialogCharWidths[DIALOG_CHAR_SPACE])
    #define CHAR_WIDTH_DEFAULT (f32)(gDialogCharWidths[str[strPos]])
#endif

/**
 * Prints a generic white string.
 * In JP/EU a IA1 texture is used but in US a IA4 texture is used.
 */
void print_generic_string(s16 x, s16 y, const u8 *str) {
    UNUSED s8 mark = DIALOG_MARK_NONE; // unused in EU
    s32 strPos = 0;
    u8 lineNum = 1;

#ifndef VERSION_EU
    create_dl_translation_matrix(MENU_MTX_PUSH, x, y, 0.0f);
#endif

    while (str[strPos] != DIALOG_CHAR_TERMINATOR) {
        switch (str[strPos]) {
            case DIALOG_CHAR_DAKUTEN:
                mark = DIALOG_MARK_DAKUTEN;
                break;
            case DIALOG_CHAR_PERIOD_OR_HANDAKUTEN:
                mark = DIALOG_MARK_HANDAKUTEN;
                break;
            case DIALOG_CHAR_NEWLINE:
                gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
                create_dl_translation_matrix(MENU_MTX_PUSH, x, y - (lineNum * MAX_STRING_WIDTH), 0.0f);
                lineNum++;
                break;
            case DIALOG_CHAR_PERIOD:
                create_dl_translation_matrix(MENU_MTX_PUSH, -2.0f, -5.0f, 0.0f);
                render_generic_char(DIALOG_CHAR_PERIOD_OR_HANDAKUTEN);
                gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
                break;

#if defined(VERSION_US) || defined(VERSION_EU)
            case DIALOG_CHAR_SLASH:
                create_dl_translation_matrix(
                    MENU_MTX_NOPUSH, (f32)(gDialogCharWidths[DIALOG_CHAR_SPACE] * 2), 0.0f, 0.0f);
                break;
            case DIALOG_CHAR_MULTI_THE:
                render_multi_text_string(STRING_THE);
                break;
            case DIALOG_CHAR_MULTI_YOU:
                render_multi_text_string(STRING_YOU);
                break;
#endif

#ifndef VERSION_EU
            case DIALOG_CHAR_SPACE:
                create_dl_translation_matrix(MENU_MTX_NOPUSH, CHAR_WIDTH_SPACE, 0.0f, 0.0f);
                break;
#endif

            default:
                render_generic_char(str[strPos]);
                if (mark != DIALOG_MARK_NONE) {
                    create_dl_translation_matrix(MENU_MTX_PUSH, 5.0f, 5.0f, 0.0f);
                    render_generic_char(DIALOG_CHAR_MARK_START + mark);
                    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
                    mark = DIALOG_MARK_NONE;
                }

                create_dl_translation_matrix(MENU_MTX_NOPUSH, CHAR_WIDTH_DEFAULT, 0.0f, 0.0f);
#ifndef VERSION_JP
                break; // what an odd difference. US (and probably later) versions added a useless break here.
#endif
        }

        strPos++;
    }

#ifndef VERSION_EU
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
#endif
}

#ifdef VERSION_EU
void print_hud_char_umlaut(s16 x, s16 y, u8 chr) {
    void **fontLUT = segmented_to_virtual(main_hud_lut);

    gDPPipeSync(gDisplayListHead++);
    gDPSetTextureImage(gDisplayListHead++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, fontLUT[chr]);
    gSPDisplayList(gDisplayListHead++, dl_rgba16_load_tex_block);
    gSPTextureRectangle(gDisplayListHead++, x << 2, y << 2, (x + 16) << 2, (y + 16) << 2, G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10);

    gDPSetTextureImage(gDisplayListHead++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, fontLUT[GLYPH_UMLAUT]);
    gSPDisplayList(gDisplayListHead++, dl_rgba16_load_tex_block);
    gSPTextureRectangle(gDisplayListHead++, x << 2, (y - 4) << 2, (x + 16) << 2, (y + 12) << 2, G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10);
}
#endif

/**
 * Prints a hud string depending of the hud table list defined.
 */
void print_hud_lut_string(s8 hudLUT, s16 x, s16 y, const u8 *str) {
    s32 strPos = 0;
    void **hudLUT1 = segmented_to_virtual(menu_hud_lut); // Japanese Menu HUD Color font
    void **hudLUT2 = segmented_to_virtual(main_hud_lut); // 0-9 A-Z HUD Color Font
    u32 curX = x;
    u32 curY = y;

    u32 xStride; // X separation

    if (hudLUT == HUD_LUT_JPMENU) {
        xStride = 16;
    } else { // HUD_LUT_GLOBAL
#ifdef VERSION_JP
        xStride = 14;
#else
        xStride = 12; //? Shindou uses this.
#endif
    }

    while (str[strPos] != GLOBAR_CHAR_TERMINATOR) {
#ifndef VERSION_JP
        switch (str[strPos]) {
#ifdef VERSION_EU
            case GLOBAL_CHAR_SPACE:
                curX += xStride / 2;
                break;
            case HUD_CHAR_A_UMLAUT:
                print_hud_char_umlaut(curX, curY, ASCII_TO_DIALOG('A'));
                curX += xStride;
                break;
            case HUD_CHAR_O_UMLAUT:
                print_hud_char_umlaut(curX, curY, ASCII_TO_DIALOG('O'));
                curX += xStride;
                break;
            case HUD_CHAR_U_UMLAUT:
                print_hud_char_umlaut(curX, curY, ASCII_TO_DIALOG('U'));
                curX += xStride;
                break;
#else
            case GLOBAL_CHAR_SPACE:
                curX += 8;
                break;
#endif
            default:
#endif
                gDPPipeSync(gDisplayListHead++);

                if (hudLUT == HUD_LUT_JPMENU) {
                    gDPSetTextureImage(gDisplayListHead++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, hudLUT1[str[strPos]]);
                }

                if (hudLUT == HUD_LUT_GLOBAL) {
                    gDPSetTextureImage(gDisplayListHead++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, hudLUT2[str[strPos]]);
                }

                gSPDisplayList(gDisplayListHead++, dl_rgba16_load_tex_block);
                gSPTextureRectangle(gDisplayListHead++, curX << 2, curY << 2, (curX + 16) << 2,
                                    (curY + 16) << 2, G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10);

                curX += xStride;
#ifndef VERSION_JP
        }
#endif
        strPos++;
    }
}

#ifdef VERSION_EU
void print_menu_char_umlaut(s16 x, s16 y, u8 chr) {
    void **fontLUT = segmented_to_virtual(menu_font_lut);

    gDPSetTextureImage(gDisplayListHead++, G_IM_FMT_IA, G_IM_SIZ_8b, 1, fontLUT[chr]);
    gDPLoadSync(gDisplayListHead++);
    gDPLoadBlock(gDisplayListHead++, G_TX_LOADTILE, 0, 0, 8 * 8 - 1, CALC_DXT(8, G_IM_SIZ_8b_BYTES));
    gSPTextureRectangle(gDisplayListHead++, x << 2, y << 2, (x + 8) << 2, (y + 8) << 2, G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10);

    gDPSetTextureImage(gDisplayListHead++, G_IM_FMT_IA, G_IM_SIZ_8b, 1, fontLUT[DIALOG_CHAR_UMLAUT]);
    gDPLoadSync(gDisplayListHead++);
    gDPLoadBlock(gDisplayListHead++, G_TX_LOADTILE, 0, 0, 8 * 8 - 1, CALC_DXT(8, G_IM_SIZ_8b_BYTES));
    gSPTextureRectangle(gDisplayListHead++, x << 2, (y - 4) << 2, (x + 8) << 2, (y + 4) << 2, G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10);
}
#endif

void print_menu_generic_string(s16 x, s16 y, const u8 *str) {
    UNUSED s8 mark = DIALOG_MARK_NONE; // unused in EU
    s32 strPos = 0;
    u32 curX = x;
    u32 curY = y;
    void **fontLUT = segmented_to_virtual(menu_font_lut);

    while (str[strPos] != DIALOG_CHAR_TERMINATOR) {
        switch (str[strPos]) {
#ifdef VERSION_EU
            case DIALOG_CHAR_UPPER_A_UMLAUT:
                print_menu_char_umlaut(curX, curY, ASCII_TO_DIALOG('A'));
                curX += gDialogCharWidths[str[strPos]];
                break;
            case DIALOG_CHAR_UPPER_U_UMLAUT:
                print_menu_char_umlaut(curX, curY, ASCII_TO_DIALOG('U'));
                curX += gDialogCharWidths[str[strPos]];
                break;
            case DIALOG_CHAR_UPPER_O_UMLAUT:
                print_menu_char_umlaut(curX, curY, ASCII_TO_DIALOG('O'));
                curX += gDialogCharWidths[str[strPos]];
                break;
#else
            case DIALOG_CHAR_DAKUTEN:
                mark = DIALOG_MARK_DAKUTEN;
                break;
            case DIALOG_CHAR_PERIOD_OR_HANDAKUTEN:
                mark = DIALOG_MARK_HANDAKUTEN;
                break;
#endif
            case DIALOG_CHAR_SPACE:
                curX += 4;
                break;
            default:
                gDPSetTextureImage(gDisplayListHead++, G_IM_FMT_IA, G_IM_SIZ_8b, 1, fontLUT[str[strPos]]);
                gDPLoadSync(gDisplayListHead++);
                gDPLoadBlock(gDisplayListHead++, G_TX_LOADTILE, 0, 0, 8 * 8 - 1, CALC_DXT(8, G_IM_SIZ_8b_BYTES));
                gSPTextureRectangle(gDisplayListHead++, curX << 2, curY << 2, (curX + 8) << 2,
                                    (curY + 8) << 2, G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10);

#ifndef VERSION_EU
                if (mark != DIALOG_MARK_NONE) {
                    gDPSetTextureImage(gDisplayListHead++, G_IM_FMT_IA, G_IM_SIZ_8b, 1, fontLUT[DIALOG_CHAR_MARK_START + mark]);
                    gDPLoadSync(gDisplayListHead++);
                    gDPLoadBlock(gDisplayListHead++, G_TX_LOADTILE, 0, 0, 8 * 8 - 1, CALC_DXT(8, G_IM_SIZ_8b_BYTES));
                    gSPTextureRectangle(gDisplayListHead++, (curX + 6) << 2, (curY - 7) << 2,
                                        (curX + 6 + 8) << 2, (curY - 7 + 8) << 2, G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10);

                    mark = DIALOG_MARK_NONE;
                }
#endif
#if defined(VERSION_JP) || defined(VERSION_SH)
                curX += 9;
#else
                curX += gDialogCharWidths[str[strPos]];
#endif
        }
        strPos++;
    }
}

void print_credits_string(s16 x, s16 y, const u8 *str) {
    s32 strPos = 0;
    void **fontLUT = segmented_to_virtual(main_credits_font_lut);
    u32 curX = x;
    u32 curY = y;

    gDPSetTile(gDisplayListHead++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0,
                G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD);
    gDPTileSync(gDisplayListHead++);
    gDPSetTile(gDisplayListHead++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 2, 0, G_TX_RENDERTILE, 0,
                G_TX_CLAMP, 3, G_TX_NOLOD, G_TX_CLAMP, 3, G_TX_NOLOD);
    gDPSetTileSize(gDisplayListHead++, G_TX_RENDERTILE, 0, 0, (8 - 1) << G_TEXTURE_IMAGE_FRAC, (8 - 1) << G_TEXTURE_IMAGE_FRAC);

    while (str[strPos] != GLOBAR_CHAR_TERMINATOR) {
        switch (str[strPos]) {
            case GLOBAL_CHAR_SPACE:
                curX += 4;
                break;
            default:
                gDPPipeSync(gDisplayListHead++);
                gDPSetTextureImage(gDisplayListHead++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, fontLUT[str[strPos]]);
                gDPLoadSync(gDisplayListHead++);
                gDPLoadBlock(gDisplayListHead++, G_TX_LOADTILE, 0, 0, 8 * 8 - 1, CALC_DXT(8, G_IM_SIZ_16b_BYTES));
                gSPTextureRectangle(gDisplayListHead++, curX << 2, curY << 2, (curX + 8) << 2,
                                    (curY + 8) << 2, G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10);
                curX += 7;
                break;
        }
        strPos++;
    }
}

void handle_menu_scrolling(s8 scrollDirection, s8 *currentIndex, s8 minIndex, s8 maxIndex) {
    u8 index = 0;

    if (scrollDirection == MENU_SCROLL_VERTICAL) {
        if (gPlayer3Controller->rawStickY > 60) {
            index++;
        }

        if (gPlayer3Controller->rawStickY < -60) {
            index += 2;
        }
    } else if (scrollDirection == MENU_SCROLL_HORIZONTAL) {
        if (gPlayer3Controller->rawStickX > 60) {
            index += 2;
        }

        if (gPlayer3Controller->rawStickX < -60) {
            index++;
        }
    }

    if (((index ^ gMenuHoldKeyIndex) & index) == 2) {
        if (*currentIndex == maxIndex) {
            //! Probably originally a >=, but later replaced with an == and an else statement.
            *currentIndex = maxIndex;
        } else {
            play_sound(SOUND_MENU_CHANGE_SELECT, gGlobalSoundSource);
            (*currentIndex)++;
        }
    }

    if (((index ^ gMenuHoldKeyIndex) & index) == 1) {
        if (*currentIndex == minIndex) {
            // Same applies to here as above
        } else {
            play_sound(SOUND_MENU_CHANGE_SELECT, gGlobalSoundSource);
            (*currentIndex)--;
        }
    }

    if (gMenuHoldKeyTimer == 10) {
        gMenuHoldKeyTimer = 8;
        gMenuHoldKeyIndex = 0;
    } else {
        gMenuHoldKeyTimer++;
        gMenuHoldKeyIndex = index;
    }

    if ((index & 3) == 0) {
        gMenuHoldKeyTimer = 0;
    }
}

// EU has both get_str_x_pos_from_center and get_str_x_pos_from_center_scale
// JP, US and Shindou only implement one or the other
#if defined(VERSION_US) || defined(VERSION_EU)
s16 get_str_x_pos_from_center(s16 centerPos, u8 *str, UNUSED f32 scale) {
    s16 strPos = 0;
    f32 spacesWidth = 0.0f;

    while (str[strPos] != DIALOG_CHAR_TERMINATOR) {
        spacesWidth += gDialogCharWidths[str[strPos]];
        strPos++;
    }
    // return the x position of where the string starts as half the string's
    // length from the position of the provided center.
    return (s16)(centerPos - (s16)(spacesWidth / 2.0));
}
#endif

#if defined(VERSION_JP) || defined(VERSION_EU) || defined(VERSION_SH)
s16 get_str_x_pos_from_center_scale(s16 centerPos, u8 *str, f32 scale) {
    s16 strPos = 0;
    f32 charsWidth = 0.0f;
    f32 spacesWidth = 0.0f;

    while (str[strPos] != DIALOG_CHAR_TERMINATOR) {
        //! EU checks for dakuten and handakuten despite dialog code unable to handle it
        if (str[strPos] == DIALOG_CHAR_SPACE) {
            spacesWidth += 1.0;
        } else if (str[strPos] != DIALOG_CHAR_DAKUTEN
                   && str[strPos] != DIALOG_CHAR_PERIOD_OR_HANDAKUTEN) {
            charsWidth += 1.0;
        }
        strPos++;
    }
    // return the x position of where the string starts as half the string's
    // length from the position of the provided center.
    return (f32) centerPos - (scale * (charsWidth / 2.0)) - ((scale / 2.0) * (spacesWidth / 2.0));
}
#endif

#if defined(VERSION_US) || defined(VERSION_EU)
s16 get_string_width(u8 *str) {
    s16 strPos = 0;
    s16 width = 0;

    while (str[strPos] != DIALOG_CHAR_TERMINATOR) {
        width += gDialogCharWidths[str[strPos]];
        strPos++;
    }
    return width;
}
#endif

u8 gHudSymCoin[] = { GLYPH_COIN, GLYPH_SPACE };
u8 gHudSymX[] = { GLYPH_MULTIPLY, GLYPH_SPACE };

void print_hud_my_score_coins(s32 useCourseCoinScore, s8 fileIndex, s8 courseIndex, s16 x, s16 y) {
    u8 strNumCoins[4];
    s16 numCoins;

    if (!useCourseCoinScore) {
        numCoins = (u16)(save_file_get_max_coin_score(courseIndex) & 0xFFFF);
    } else {
        numCoins = save_file_get_course_coin_score(fileIndex, courseIndex);
    }

    if (numCoins != 0) {
        print_hud_lut_string(HUD_LUT_GLOBAL, x, y, gHudSymCoin);
        print_hud_lut_string(HUD_LUT_GLOBAL, x + 16, y, gHudSymX);
        int_to_str(numCoins, strNumCoins);
        print_hud_lut_string(HUD_LUT_GLOBAL, x + 32, y, strNumCoins);
    }
}

void print_hud_my_score_stars(s8 fileIndex, s8 courseIndex, s16 x, s16 y) {
    u8 strStarCount[4];
    s16 starCount;
    u8 textSymStar[] = { GLYPH_STAR, GLYPH_SPACE };
    UNUSED u16 unused;
    u8 textSymX[] = { GLYPH_MULTIPLY, GLYPH_SPACE };

    starCount = save_file_get_course_star_count(fileIndex, courseIndex);

    if (starCount != 0) {
        print_hud_lut_string(HUD_LUT_GLOBAL, x, y, textSymStar);
        print_hud_lut_string(HUD_LUT_GLOBAL, x + 16, y, textSymX);
        int_to_str(starCount, strStarCount);
        print_hud_lut_string(HUD_LUT_GLOBAL, x + 32, y, strStarCount);
    }
}

void int_to_str(s32 num, u8 *dst) {
    s32 digit1;
    s32 digit2;
    s32 digit3;

    s8 pos = 0;

    if (num > 999) {
        dst[0] = 0x00; dst[1] = DIALOG_CHAR_TERMINATOR;
        return;
    }

    digit1 = num / 100;
    digit2 = (num - digit1 * 100) / 10;
    digit3 = (num - digit1 * 100) - (digit2 * 10);

    if (digit1 != 0) {
        dst[pos++] = digit1;
    }

    if (digit2 != 0 || digit1 != 0) {
        dst[pos++] = digit2;
    }

    dst[pos++] = digit3;
    dst[pos] = DIALOG_CHAR_TERMINATOR;
}

s16 get_dialog_id(void) {
    return gDialogID;
}

void create_dialog_box(s16 dialog) {
    if (gDialogID == DIALOG_NONE) {
        gDialogID = dialog;
        gDialogBoxType = DIALOG_TYPE_ROTATE;
    }
}

void create_dialog_box_with_var(s16 dialog, s32 dialogVar) {
    if (gDialogID == DIALOG_NONE) {
        gDialogID = dialog;
        gDialogVariable = dialogVar;
        gDialogBoxType = DIALOG_TYPE_ROTATE;
    }
}

void create_dialog_inverted_box(s16 dialog) {
    if (gDialogID == DIALOG_NONE) {
        gDialogID = dialog;
        gDialogBoxType = DIALOG_TYPE_ZOOM;
    }
}

void create_dialog_box_with_response(s16 dialog) {
    if (gDialogID == DIALOG_NONE) {
        gDialogID = dialog;
        gDialogBoxType = DIALOG_TYPE_ROTATE;
        gLastDialogResponse = 1;
    }
}

void reset_dialog_render_state(void) {
    level_set_transition(0, NULL);

    if (gDialogBoxType == DIALOG_TYPE_ZOOM) {
        trigger_cutscene_dialog(2);
    }

    gDialogBoxScale = 19.0f;
    gDialogBoxOpenTimer = 90.0f;
    gDialogBoxState = DIALOG_STATE_OPENING;
    gDialogID = DIALOG_NONE;
    gDialogTextPos = 0;
    gLastDialogResponse = 0;
    gLastDialogPageStrPos = 0;
    gDialogResponse = DIALOG_RESPONSE_NONE;
}

#if defined(VERSION_JP) || defined(VERSION_SH)
    #define X_VAL1 -5.0f
    #define Y_VAL1 2.0
    #define Y_VAL2 4
#else
    #define X_VAL1 -7.0f
    #define Y_VAL1 5.0
    #define Y_VAL2 5.0f
#endif

void render_dialog_box_type(struct DialogEntry *dialog, s8 linesPerBox) {
    UNUSED u8 filler[4];

    create_dl_translation_matrix(MENU_MTX_NOPUSH, dialog->leftOffset, dialog->width, 0);

    switch (gDialogBoxType) {
        case DIALOG_TYPE_ROTATE: // Renders a dialog black box with zoom and rotation
            if (gDialogBoxState == DIALOG_STATE_OPENING || gDialogBoxState == DIALOG_STATE_CLOSING) {
                create_dl_scale_matrix(MENU_MTX_NOPUSH, 1.0 / gDialogBoxScale, 1.0 / gDialogBoxScale, 1.0f);
                // convert the speed into angle
                create_dl_rotation_matrix(MENU_MTX_NOPUSH, gDialogBoxOpenTimer * 4.0f, 0, 0, 1.0f);
            }
            gDPSetEnvColor(gDisplayListHead++, 0, 0x18, 0x18, 150);
            break;
        case DIALOG_TYPE_ZOOM: // Renders a dialog white box with zoom
            if (gDialogBoxState == DIALOG_STATE_OPENING || gDialogBoxState == DIALOG_STATE_CLOSING) {
                create_dl_translation_matrix(MENU_MTX_NOPUSH, 65.0 - (65.0 / gDialogBoxScale),
                                              (40.0 / gDialogBoxScale) - 40, 0);
                create_dl_scale_matrix(MENU_MTX_NOPUSH, 1.0 / gDialogBoxScale, 1.0 / gDialogBoxScale, 1.0f);
            }
            // gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, 150);
            gDPSetEnvColor(gDisplayListHead++, 0, 0x18, 0x18, 150);
            break;
    }

    create_dl_translation_matrix(MENU_MTX_PUSH, X_VAL1, Y_VAL1, 0);
    create_dl_scale_matrix(MENU_MTX_NOPUSH, 1.3f, ((f32) linesPerBox / Y_VAL2) + 0.1, 1.0f);

    gSPDisplayList(gDisplayListHead++, dl_draw_text_green_bg_box);
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
}

void change_and_flash_dialog_text_color_lines(s8 colorMode, s8 lineNum) {
    u8 colorFade;

    if (colorMode == 1) {
        if (lineNum == 1) {
            gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, 255);
        } else {
            if (lineNum == gDialogLineNum) {
                colorFade = (gSineTable[gDialogColorFadeTimer >> 4] * 50.0f) + 200.0f;
                gDPSetEnvColor(gDisplayListHead++, colorFade, colorFade, colorFade, 255);
            } else {
                gDPSetEnvColor(gDisplayListHead++, 200, 200, 200, 255);
            }
        }
    } else {
        switch (gDialogBoxType) {
            case DIALOG_TYPE_ROTATE:
                break;
            case DIALOG_TYPE_ZOOM:
                // gDPSetEnvColor(gDisplayListHead++, 0, 0, 0, 255);
                break;
        }
    }
}

#ifdef VERSION_EU
void render_generic_dialog_char_at_pos(struct DialogEntry *dialog, s16 x, s16 y, u8 c) {
    s16 width = (8.0 - (gDialogBoxScale * 0.8));
    s16 height = (16.0 - (gDialogBoxScale * 0.8));
    s16 tmpX = (dialog->leftOffset + (65.0 - (65.0 / gDialogBoxScale)));
    s16 tmpY = ((240 - dialog->width) - ((40.0 / gDialogBoxScale) - 40));
    s16 xCoord = (tmpX + (x / gDialogBoxScale));
    s16 yCoord = (tmpY + (y / gDialogBoxScale));

    void **fontLUT = segmented_to_virtual(main_font_lut);
    void *packedTexture = segmented_to_virtual(fontLUT[c]);
    void *unpackedTexture = alloc_ia4_tex_from_i1(packedTexture, 8, 8);

    gDPSetTextureImage(gDisplayListHead++, G_IM_FMT_IA, G_IM_SIZ_16b, 1, VIRTUAL_TO_PHYSICAL(unpackedTexture));
    gSPDisplayList(gDisplayListHead++, dl_ia_text_tex_settings);
    gSPTextureRectangleFlip(gDisplayListHead++, xCoord << 2, (yCoord - height) << 2,
                            (xCoord + width) << 2, yCoord << 2, G_TX_RENDERTILE, 8 << 6, 4 << 6, 1 << 10, 1 << 10);
}
#endif

#if defined(VERSION_JP) || defined(VERSION_SH)
    #define X_VAL3 5.0f
    #define Y_VAL3 20
#else
    #define X_VAL3 0.0f
    #define Y_VAL3 16
#endif

#ifdef VERSION_EU
void handle_dialog_scroll_page_state(s8 lineNum, s8 totalLines, s8 *pageState, s8 *xMatrix)
#else
void handle_dialog_scroll_page_state(s8 lineNum, s8 totalLines, s8 *pageState, s8 *xMatrix, s16 *linePos)
#endif
{
#ifndef VERSION_EU
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
#endif

    if (lineNum == totalLines) {
        *pageState = DIALOG_PAGE_STATE_SCROLL;
        return;
    }
#ifdef VERSION_EU
    gDialogY += 16;
#else
    create_dl_translation_matrix(MENU_MTX_PUSH, X_VAL3, 2 - (lineNum * Y_VAL3), 0);

    *linePos = 0;
#endif
    *xMatrix = 1;
}

#if defined(VERSION_JP) || defined(VERSION_SH)
void adjust_pos_and_print_period_char(s8 *xMatrix, s16 *linePos) {
    if (*linePos != 0) {
        create_dl_translation_matrix(MENU_MTX_NOPUSH, 10 * *xMatrix, 0, 0);
    }

    create_dl_translation_matrix(MENU_MTX_PUSH, -2.0f, -5.0f, 0);
    render_generic_char(DIALOG_CHAR_PERIOD_OR_HANDAKUTEN);

    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);

    (*linePos)++;
    *xMatrix = 1;
}
#endif


/*void render_star_count_dialog_text(s8 *xMatrix, s16 *linePos)
{
    s8 tensDigit = gDialogVariable / 10;
    s8 onesDigit = gDialogVariable - (tensDigit * 10); // remainder

    if (tensDigit != 0) {
        if (*xMatrix != 1) {
            create_dl_translation_matrix(
                MENU_MTX_NOPUSH, (f32)(gDialogCharWidths[DIALOG_CHAR_SPACE] * *xMatrix), 0, 0);
        }

        render_generic_char(tensDigit);
        create_dl_translation_matrix(MENU_MTX_NOPUSH, (f32) gDialogCharWidths[tensDigit], 0, 0);
        *xMatrix = 1;
        (*linePos)++;
    }
    else {
    }

    if (*xMatrix != 1) {
        create_dl_translation_matrix(
            MENU_MTX_NOPUSH, (f32)(gDialogCharWidths[DIALOG_CHAR_SPACE] * (*xMatrix - 1)), 0, 0);
    }

    render_generic_char(onesDigit);
    create_dl_translation_matrix(MENU_MTX_NOPUSH, (f32) gDialogCharWidths[onesDigit], 0, 0);
    (*linePos)++;
    *xMatrix = 1;
}*/



void render_star_count_dialog_text(s8 *xMatrix, s16 *linePos)
{
    s8 onesDigit = 5 - CL_count_bits((save_file_get_star_piece() >> 10) & 0x1F);//gDialogVariable - (tensDigit * 10); // remainder


    if (*xMatrix != 1) {
        create_dl_translation_matrix(
            MENU_MTX_NOPUSH, (f32)(gDialogCharWidths[DIALOG_CHAR_SPACE] * (*xMatrix - 1)), 0, 0);
    }

    render_generic_char(onesDigit);
    create_dl_translation_matrix(MENU_MTX_NOPUSH, (f32) gDialogCharWidths[onesDigit], 0, 0);
    (*linePos)++;
    *xMatrix = 1;
}



#if defined(VERSION_US) || defined(VERSION_EU)
#ifdef VERSION_EU
void render_multi_text_string_lines(s8 multiTextId, s8 lineNum, s8 linesPerBox, UNUSED s8 xMatrix, s8 lowerBound, struct DialogEntry *dialog)
#else
void render_multi_text_string_lines(s8 multiTextId, s8 lineNum, s16 *linePos, s8 linesPerBox, s8 xMatrix, s8 lowerBound)
#endif
{
    s8 i;
    struct MultiTextEntry textLengths[2] = {
        { 3, { TEXT_THE_RAW } },
        { 3, { TEXT_YOU_RAW } },
    };

    if (lineNum >= lowerBound && lineNum <= (lowerBound + linesPerBox)) {
#ifdef VERSION_US
        if (*linePos != 0 || xMatrix != 1) {
            create_dl_translation_matrix(
                MENU_MTX_NOPUSH, (gDialogCharWidths[DIALOG_CHAR_SPACE] * (xMatrix - 1)), 0, 0);
        }
#endif
        for (i = 0; i < textLengths[multiTextId].length; i++) {
#ifdef VERSION_EU
            render_generic_dialog_char_at_pos(dialog, gDialogX, gDialogY, textLengths[multiTextId].str[i]);
            gDialogX += gDialogCharWidths[textLengths[multiTextId].str[i]];
#else
            render_generic_char(textLengths[multiTextId].str[i]);
            create_dl_translation_matrix(
                MENU_MTX_NOPUSH, (gDialogCharWidths[textLengths[multiTextId].str[i]]), 0, 0);
#endif
        }
    }

#ifdef VERSION_US
    linePos += textLengths[multiTextId].length;
#endif
}
#endif

#ifdef VERSION_EU
void render_dialog_lowercase_diacritic(struct DialogEntry *dialog, u8 chr, u8 diacritic) {
    render_generic_dialog_char_at_pos(dialog, gDialogX, gDialogY, chr);
    render_generic_dialog_char_at_pos(dialog, gDialogX, gDialogY, diacritic + 0xE7);
    gDialogX += gDialogCharWidths[chr];
}

void render_dialog_uppercase_diacritic(struct DialogEntry *dialog, u8 chr, u8 diacritic) {
    render_generic_dialog_char_at_pos(dialog, gDialogX, gDialogY, chr);
    render_generic_dialog_char_at_pos(dialog, gDialogX, gDialogY - 4, diacritic + 0xE3);
    gDialogX += gDialogCharWidths[chr];
}
#endif

u32 ensure_nonnegative(s16 value) {
    if (value < 0) {
        value = 0;
    }

    return value;
}

//void s2d_print_string(s16 x, s16 y, const char *str);

#if defined(VERSION_JP)
void handle_dialog_text_and_pages(s8 colorMode, struct DialogEntry *dialog)
#else
void handle_dialog_text_and_pages(s8 colorMode, struct DialogEntry *dialog, s8 lowerBound)
#endif
{
    UNUSED u8 filler[8];
#ifdef VERSION_EU
    s16 startY = 14;
#endif
    u8 strChar;
    u8 *str = segmented_to_virtual(dialog->str);
    s8 lineNum = 1;
    s8 totalLines;
    s8 pageState = DIALOG_PAGE_STATE_NONE;
    UNUSED s8 mark = DIALOG_MARK_NONE; // unused in US and EU
    s8 xMatrix = 1;
    s8 linesPerBox = dialog->linesPerBox;
    s16 strIdx;
#ifndef VERSION_EU
    s16 linePos = 0;
#endif

    if (gDialogBoxState == DIALOG_STATE_HORIZONTAL) {
        // If scrolling, consider the number of lines for both
        // the current page and the page being scrolled to.
        totalLines = linesPerBox * 2 + 1;
    } else {
        totalLines = linesPerBox + 1;
    }

    gSPDisplayList(gDisplayListHead++, dl_ia_text_begin);

    strIdx = gDialogTextPos;

#ifdef VERSION_EU
    gDialogX = 0;
    gDialogY = startY;
#endif

    if (gDialogBoxState == DIALOG_STATE_HORIZONTAL) {
#ifdef VERSION_EU
        gDialogY -= gDialogScrollOffsetY;
#else
        create_dl_translation_matrix(MENU_MTX_NOPUSH, 0, (f32) gDialogScrollOffsetY, 0);
#endif
    }

#ifndef VERSION_EU
    create_dl_translation_matrix(MENU_MTX_PUSH, X_VAL3, 2 - lineNum * Y_VAL3, 0);
#endif

    while (pageState == DIALOG_PAGE_STATE_NONE) {
        change_and_flash_dialog_text_color_lines(colorMode, lineNum);
        strChar = str[strIdx];

        switch (strChar) {
            case DIALOG_CHAR_TERMINATOR:
                pageState = DIALOG_PAGE_STATE_END;
#ifndef VERSION_EU
                gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
#endif
                break;
            case DIALOG_CHAR_NEWLINE:
                lineNum++;
#ifdef VERSION_EU
                handle_dialog_scroll_page_state(lineNum, totalLines, &pageState, &xMatrix);
                gDialogX = 0;
#else
                handle_dialog_scroll_page_state(lineNum, totalLines, &pageState, &xMatrix, &linePos);
#ifdef VERSION_SH
                mark = DIALOG_MARK_NONE;
#endif
#endif
                break;

#ifdef VERSION_EU
            case DIALOG_CHAR_LOWER_A_GRAVE:
            case DIALOG_CHAR_LOWER_A_CIRCUMFLEX:
            case DIALOG_CHAR_LOWER_A_UMLAUT:
                render_dialog_lowercase_diacritic(dialog, ASCII_TO_DIALOG('a'), strChar & 0xF);
                break;
            case DIALOG_CHAR_UPPER_A_GRAVE:
            case DIALOG_CHAR_UPPER_A_CIRCUMFLEX:
            case DIALOG_CHAR_UPPER_A_UMLAUT:
                render_dialog_uppercase_diacritic(dialog, ASCII_TO_DIALOG('A'), strChar & 0xF);
                break;
            case DIALOG_CHAR_LOWER_E_GRAVE:
            case DIALOG_CHAR_LOWER_E_CIRCUMFLEX:
            case DIALOG_CHAR_LOWER_E_UMLAUT:
            case DIALOG_CHAR_LOWER_E_ACUTE:
                render_dialog_lowercase_diacritic(dialog, ASCII_TO_DIALOG('e'), strChar & 0xF);
                break;
            case DIALOG_CHAR_UPPER_E_GRAVE:
            case DIALOG_CHAR_UPPER_E_CIRCUMFLEX:
            case DIALOG_CHAR_UPPER_E_UMLAUT:
            case DIALOG_CHAR_UPPER_E_ACUTE:
                render_dialog_uppercase_diacritic(dialog, ASCII_TO_DIALOG('E'), strChar & 0xF);
                break;
            case DIALOG_CHAR_LOWER_U_GRAVE:
            case DIALOG_CHAR_LOWER_U_CIRCUMFLEX:
            case DIALOG_CHAR_LOWER_U_UMLAUT:
                render_dialog_lowercase_diacritic(dialog, ASCII_TO_DIALOG('u'), strChar & 0xF);
                break;
            case DIALOG_CHAR_UPPER_U_GRAVE:
            case DIALOG_CHAR_UPPER_U_CIRCUMFLEX:
            case DIALOG_CHAR_UPPER_U_UMLAUT:
                render_dialog_uppercase_diacritic(dialog, ASCII_TO_DIALOG('U'), strChar & 0xF);
                break;
            case DIALOG_CHAR_LOWER_O_CIRCUMFLEX:
            case DIALOG_CHAR_LOWER_O_UMLAUT:
                render_dialog_lowercase_diacritic(dialog, ASCII_TO_DIALOG('o'), strChar & 0xF);
                break;
            case DIALOG_CHAR_UPPER_O_CIRCUMFLEX:
            case DIALOG_CHAR_UPPER_O_UMLAUT:
                render_dialog_uppercase_diacritic(dialog, ASCII_TO_DIALOG('O'), strChar & 0xF);
                break;
            case DIALOG_CHAR_LOWER_I_CIRCUMFLEX:
            case DIALOG_CHAR_LOWER_I_UMLAUT:
                render_dialog_lowercase_diacritic(dialog, DIALOG_CHAR_I_NO_DIA, strChar & 0xF);
                break;
#else
            case DIALOG_CHAR_DAKUTEN:
                mark = DIALOG_MARK_DAKUTEN;
                break;
            case DIALOG_CHAR_PERIOD_OR_HANDAKUTEN:
                mark = DIALOG_MARK_HANDAKUTEN;
                break;
#endif

            case DIALOG_CHAR_SPACE:
#ifdef VERSION_EU
                gDialogX += gDialogCharWidths[DIALOG_CHAR_SPACE];
#else
#if defined(VERSION_JP) || defined(VERSION_SH)
                if (linePos != 0) {
#endif
                    xMatrix++;
#if defined(VERSION_JP) || defined(VERSION_SH)
                }
#endif
                linePos++;
#endif
                break;

#if defined(VERSION_JP) || defined(VERSION_SH)
            case DIALOG_CHAR_PERIOD:
                adjust_pos_and_print_period_char(&xMatrix, &linePos);
                break;
#else
            case DIALOG_CHAR_SLASH:
#ifdef VERSION_EU
                gDialogX += gDialogCharWidths[DIALOG_CHAR_SPACE] * 2;
#else
                xMatrix += 2;
                linePos += 2;
#endif
                break;
            case DIALOG_CHAR_MULTI_THE:
#ifdef VERSION_EU
                render_multi_text_string_lines(STRING_THE, lineNum, linesPerBox, xMatrix, lowerBound, dialog);
#else
                render_multi_text_string_lines(STRING_THE, lineNum, &linePos, linesPerBox, xMatrix, lowerBound);
#endif
                xMatrix = 1;
                break;
            case DIALOG_CHAR_MULTI_YOU:
#ifdef VERSION_EU
                render_multi_text_string_lines(STRING_YOU, lineNum, linesPerBox, xMatrix, lowerBound, dialog);
#else
                render_multi_text_string_lines(STRING_YOU, lineNum, &linePos, linesPerBox, xMatrix, lowerBound);
#endif
                xMatrix = 1;
                break;
#endif

            case DIALOG_CHAR_STAR_COUNT:
                render_star_count_dialog_text(&xMatrix, &linePos);
                break;

#ifdef VERSION_EU
            case DIALOG_CHAR_DOUBLE_LOW_QUOTE:
                render_generic_dialog_char_at_pos(dialog, gDialogX, gDialogY + 8, 0xF6);
                gDialogX += gDialogCharWidths[0xF6];
                break;
#endif

            default: // any other character
#if defined(VERSION_JP) || defined(VERSION_SH)
#ifdef VERSION_SH
                if (lineNum >= lowerBound && lineNum <= (lowerBound + linesPerBox)) {
#endif
                    if (linePos != 0) {
                        create_dl_translation_matrix(MENU_MTX_NOPUSH, 10 * xMatrix, 0, 0);
                    }

                    render_generic_char(strChar);
                    xMatrix = 1;
                    linePos++;

                    if (mark != DIALOG_MARK_NONE) {
                        create_dl_translation_matrix(MENU_MTX_PUSH, 5.0f, 7.0f, 0);
                        render_generic_char(DIALOG_CHAR_MARK_START + mark);
                        gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
                        mark = DIALOG_MARK_NONE;
                    }
#ifdef VERSION_SH
                }
#endif
#elif defined(VERSION_US)
                if (lineNum >= lowerBound && lineNum <= (lowerBound + linesPerBox)) {
                    if (linePos != 0 || xMatrix != 1) {
                        create_dl_translation_matrix(
                            MENU_MTX_NOPUSH, (f32)(gDialogCharWidths[DIALOG_CHAR_SPACE] * (xMatrix - 1)), 0, 0);
                    }

                    render_generic_char(strChar);
                    create_dl_translation_matrix(MENU_MTX_NOPUSH, (f32)(gDialogCharWidths[strChar]), 0, 0);
                    xMatrix = 1;
                    linePos++;
                }
#else // VERSION_EU
                if (lineNum >= lowerBound && lineNum <= (lowerBound + linesPerBox)) {
                    render_generic_dialog_char_at_pos(dialog, gDialogX, gDialogY, strChar);
                }
                gDialogX += gDialogCharWidths[strChar];
#endif
        }

#ifdef VERSION_JP
        if (linePos == 12) {
            if (str[strIdx + 1] == DIALOG_CHAR_PERIOD) {
                adjust_pos_and_print_period_char(&xMatrix, &linePos);
                strIdx++;
            }

            if (str[strIdx + 1] == DIALOG_CHAR_COMMA) {
                create_dl_translation_matrix(MENU_MTX_NOPUSH, 10 * xMatrix, 0, 0);
                render_generic_char(DIALOG_CHAR_COMMA);
                strIdx++;
            }

            if (str[strIdx + 1] == DIALOG_CHAR_NEWLINE) {
                strIdx++;
            }

            if (str[strIdx + 1] == DIALOG_CHAR_TERMINATOR) {
                pageState = DIALOG_PAGE_STATE_END;
                gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
                break; // exit loop
            } else {
                lineNum++;
                handle_dialog_scroll_page_state(lineNum, totalLines, &pageState, &xMatrix, &linePos);
            }
        }
#endif

        strIdx++;
    }

    gSPDisplayList(gDisplayListHead++, dl_ia_text_end);

    if (gDialogBoxState == DIALOG_STATE_VERTICAL) {
        if (pageState == DIALOG_PAGE_STATE_END) {
            gLastDialogPageStrPos = -1;
        } else {
            gLastDialogPageStrPos = strIdx;
        }
    }

    gLastDialogLineNum = lineNum;
}

#if defined(VERSION_JP) || defined(VERSION_SH)
    #define X_VAL4_1 50
    #define X_VAL4_2 25
    #define Y_VAL4_1 1
    #define Y_VAL4_2 20
#else
    #define X_VAL4_1 56
    #define X_VAL4_2 47
    #define Y_VAL4_1 2
    #define Y_VAL4_2 16
#endif

void render_dialog_triangle_choice(void) {
    if (gDialogBoxState == DIALOG_STATE_VERTICAL) {
        handle_menu_scrolling(MENU_SCROLL_HORIZONTAL, &gDialogLineNum, 1, 2);
    }

    create_dl_translation_matrix(MENU_MTX_NOPUSH, (gDialogLineNum * X_VAL4_1) - X_VAL4_2, Y_VAL4_1 - (gLastDialogLineNum * Y_VAL4_2), 0);

    if (gDialogBoxType == DIALOG_TYPE_ROTATE) {
        gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, 255);
    } else {
        gDPSetEnvColor(gDisplayListHead++, 0, 0, 0, 255);
    }

    gSPDisplayList(gDisplayListHead++, dl_draw_triangle);
}

#if defined(VERSION_JP) || defined(VERSION_SH)
    #define X_VAL5 123.0f
    #define Y_VAL5_1 -20
    #define Y_VAL5_2 2
    #define X_Y_VAL6 0.8f
#elif defined(VERSION_US)
    #define X_VAL5 118.0f
    #define Y_VAL5_1 -16
    #define Y_VAL5_2 5
    #define X_Y_VAL6 0.8f
#elif defined(VERSION_EU)
    #define X_VAL5 122.0f
    #define Y_VAL5_1 -16
    #define Y_VAL5_2 3
    #define X_Y_VAL6 0.5f
#endif

void render_dialog_triangle_next(s8 linesPerBox) {
    s32 globalTimer = gGlobalTimer;

    if (globalTimer & 8) {
        return;
    }

    create_dl_translation_matrix(MENU_MTX_PUSH, X_VAL5 + 30.0f, (linesPerBox * Y_VAL5_1) + Y_VAL5_2, 0);
    create_dl_scale_matrix(MENU_MTX_NOPUSH, X_Y_VAL6, X_Y_VAL6, 1.0f);
    create_dl_rotation_matrix(MENU_MTX_NOPUSH, -DEFAULT_DIALOG_BOX_ANGLE, 0, 0, 1.0f);

    if (gDialogBoxType == DIALOG_TYPE_ROTATE) { // White Text
        gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, 255);
    } else { // Black Text
        gDPSetEnvColor(gDisplayListHead++, 0, 0, 0, 255);
    }

    gSPDisplayList(gDisplayListHead++, dl_draw_triangle);
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
}

void handle_special_dialog_text(s16 dialogID) { // dialog ID tables, in order
    // King Bob-omb (Start), Whomp (Start), King Bob-omb (throw him out), Eyerock (Start), Wiggler (Start)
    s16 dialogBossStart[] = { DIALOG_017, DIALOG_114, DIALOG_128, DIALOG_117, DIALOG_150 };
    // Koopa the Quick (BoB), Koopa the Quick (THI), Penguin Race, Fat Penguin Race (120 stars)
    s16 dialogRaceSound[] = { DIALOG_005, DIALOG_009, DIALOG_055, DIALOG_164 };
    // Red Switch, Green Switch, Blue Switch, 100 coins star, Bowser Red Coin Star
    s16 dialogStarSound[] = { DIALOG_010, DIALOG_011, DIALOG_012, DIALOG_013, DIALOG_014 };
    // King Bob-omb (Start), Whomp (Defeated), King Bob-omb (Defeated, missing in JP), Eyerock (Defeated), Wiggler (Defeated)
#if BUGFIX_KING_BOB_OMB_FADE_MUSIC
    s16 dialogBossStop[] = { DIALOG_017, DIALOG_115, DIALOG_116, DIALOG_118, DIALOG_152 };
#else
    //! @bug JP misses King Bob-omb defeated DIALOG_116, meaning that the boss music will still
    //! play after King Bob-omb is defeated until BoB loads it's music after the star cutscene
    s16 dialogBossStop[] = { DIALOG_017, DIALOG_115, DIALOG_118, DIALOG_152 };
#endif
    s16 i;

    return;
    for (i = 0; i < (s16) ARRAY_COUNT(dialogBossStart); i++) {
        if (dialogBossStart[i] == dialogID) {
            seq_player_unlower_volume(SEQ_PLAYER_LEVEL, 60);
            play_music(SEQ_PLAYER_LEVEL, SEQUENCE_ARGS(4, SEQ_EVENT_BOSS), 0);
            return;
        }
    }

    for (i = 0; i < (s16) ARRAY_COUNT(dialogRaceSound); i++) {
        if (dialogRaceSound[i] == dialogID && gDialogLineNum == 1) {
            play_race_fanfare();
            return;
        }
    }

    for (i = 0; i < (s16) ARRAY_COUNT(dialogStarSound); i++) {
        if (dialogStarSound[i] == dialogID && gDialogLineNum == 1) {
            play_sound(SOUND_MENU_STAR_SOUND, gGlobalSoundSource);
            return;
        }
    }

    for (i = 0; i < (s16) ARRAY_COUNT(dialogBossStop); i++) {
        if (dialogBossStop[i] == dialogID) {
            seq_player_fade_out(SEQ_PLAYER_LEVEL, 1);
            return;
        }
    }
}

s16 gMenuMode = MENU_MODE_NONE;
s16 gMapModeInit = 0;
s16 gMenuROptions = 0;
s8 gDialogOptionsIndex = 1;

u8 gEndCutsceneStrEn0[] = { TEXT_FILE_MARIO_EXCLAMATION };
u8 gEndCutsceneStrEn1[] = { TEXT_POWER_STARS_RESTORED };
u8 gEndCutsceneStrEn2[] = { TEXT_THANKS_TO_YOU };
u8 gEndCutsceneStrEn3[] = { TEXT_THANK_YOU_MARIO };
u8 gEndCutsceneStrEn4[] = { TEXT_SOMETHING_SPECIAL };
u8 gEndCutsceneStrEn5[] = { TEXT_LISTEN_EVERYBODY };
u8 gEndCutsceneStrEn6[] = { TEXT_LETS_HAVE_CAKE };
u8 gEndCutsceneStrEn7[] = { TEXT_FOR_MARIO };
u8 gEndCutsceneStrEn8[] = { TEXT_FILE_MARIO_QUESTION };

u8 *gEndCutsceneStringsEn[] = {
    gEndCutsceneStrEn0,
    gEndCutsceneStrEn1,
    gEndCutsceneStrEn2,
    gEndCutsceneStrEn3,
    gEndCutsceneStrEn4,
    gEndCutsceneStrEn5,
    gEndCutsceneStrEn6,
    gEndCutsceneStrEn7,
    // This [8] string is actually unused. In the cutscene handler, the developers do not
    // set the 8th one, but use the first string again at the very end, so Peach ends up
    // saying "Mario!" twice. It is likely that she was originally meant to say "Mario?" at
    // the end but the developers changed their mind, possibly because the line recorded
    // sounded more like an exclamation than a question.
    gEndCutsceneStrEn8,
    NULL
};

#ifdef VERSION_EU
u8 gEndCutsceneStrFr0[] = { TEXT_FILE_MARIO_EXCLAMATION };
u8 gEndCutsceneStrFr1[] = { TEXT_POWER_STARS_RESTORED_FR };
u8 gEndCutsceneStrFr2[] = { TEXT_THANKS_TO_YOU_FR };
u8 gEndCutsceneStrFr3[] = { TEXT_THANK_YOU_MARIO_FR };
u8 gEndCutsceneStrFr4[] = { TEXT_SOMETHING_SPECIAL_FR };
u8 gEndCutsceneStrFr5[] = { TEXT_COME_ON_EVERYBODY_FR };
u8 gEndCutsceneStrFr6[] = { TEXT_LETS_HAVE_CAKE_FR };
u8 gEndCutsceneStrFr7[] = { TEXT_FOR_MARIO_FR };
u8 gEndCutsceneStrFr8[] = { TEXT_FILE_MARIO_QUESTION };

u8 *gEndCutsceneStringsFr[] = {
    gEndCutsceneStrFr0,
    gEndCutsceneStrFr1,
    gEndCutsceneStrFr2,
    gEndCutsceneStrFr3,
    gEndCutsceneStrFr4,
    gEndCutsceneStrFr5,
    gEndCutsceneStrFr6,
    gEndCutsceneStrFr7,
    gEndCutsceneStrFr8,
    NULL
};

u8 gEndCutsceneStrDe0[] = { TEXT_FILE_MARIO_EXCLAMATION };
u8 gEndCutsceneStrDe1[] = { TEXT_POWER_STARS_RESTORED_DE };
u8 gEndCutsceneStrDe2[] = { TEXT_THANKS_TO_YOU_DE };
u8 gEndCutsceneStrDe3[] = { TEXT_THANK_YOU_MARIO_DE };
u8 gEndCutsceneStrDe4[] = { TEXT_SOMETHING_SPECIAL_DE };
u8 gEndCutsceneStrDe5[] = { TEXT_COME_ON_EVERYBODY_DE };
u8 gEndCutsceneStrDe6[] = { TEXT_LETS_HAVE_CAKE_DE };
u8 gEndCutsceneStrDe7[] = { TEXT_FOR_MARIO_DE };
u8 gEndCutsceneStrDe8[] = { TEXT_FILE_MARIO_QUESTION };

u8 *gEndCutsceneStringsDe[] = {
    gEndCutsceneStrDe0,
    gEndCutsceneStrDe1,
    gEndCutsceneStrDe2,
    gEndCutsceneStrDe3,
    gEndCutsceneStrDe4,
    gEndCutsceneStrDe5,
    gEndCutsceneStrDe6,
    gEndCutsceneStrDe7,
    gEndCutsceneStrDe8,
    NULL
};
#endif

u16 gCutsceneMsgFade = 0;
s16 gCutsceneMsgIndex = -1;
s16 gCutsceneMsgDuration = -1;
s16 gCutsceneMsgTimer = 0;
s8 gDialogCameraAngleIndex = CAM_SELECTION_MARIO;
s8 gDialogCourseActNum = 1;

#if defined(VERSION_JP) || defined(VERSION_SH)
    #define DIAG_VAL1 20
    #define DIAG_VAL2 240
    #define DIAG_VAL3 130
    #define DIAG_VAL4 4
#else
    #define DIAG_VAL1 16
#ifdef VERSION_US
    #define DIAG_VAL2 240
#else
    #define DIAG_VAL2 238
#endif
    #define DIAG_VAL3 132
    #define DIAG_VAL4 5
#endif

void render_dialog_entries(void) {
#ifdef VERSION_EU
    s8 lowerBound;
#endif
    void **dialogTable;
    struct DialogEntry *dialog;
#if defined(VERSION_US) || defined(VERSION_SH)
    s8 lowerBound;
#endif

#ifdef VERSION_EU
    gInGameLanguage = eu_get_language();
    switch (gInGameLanguage) {
        case LANGUAGE_ENGLISH:
            dialogTable = segmented_to_virtual(dialog_table_eu_en);
            break;
        case LANGUAGE_FRENCH:
            dialogTable = segmented_to_virtual(dialog_table_eu_fr);
            break;
        case LANGUAGE_GERMAN:
            dialogTable = segmented_to_virtual(dialog_table_eu_de);
            break;
    }
#else
    dialogTable = segmented_to_virtual(seg2_dialog_table);
#endif
    dialog = segmented_to_virtual(dialogTable[gDialogID]);

    // if the dialog entry is invalid, set the ID to DIALOG_NONE.
    if (segmented_to_virtual(NULL) == dialog) {
        gDialogID = DIALOG_NONE;
        return;
    }

#ifdef VERSION_EU
    gDialogX = 0;
    gDialogY = 0;
#endif

    switch (gDialogBoxState) {
        case DIALOG_STATE_OPENING:
            if (gDialogBoxOpenTimer == DEFAULT_DIALOG_BOX_ANGLE) {
                play_dialog_sound(gDialogID);
                play_sound(SOUND_MENU_MESSAGE_APPEAR, gGlobalSoundSource);
            }

            if (gDialogBoxType == DIALOG_TYPE_ROTATE) {
                gDialogBoxOpenTimer -= 7.5;
                gDialogBoxScale -= 1.5;
            } else {
                gDialogBoxOpenTimer -= 10.0;
                gDialogBoxScale -= 2.0;
            }

            if (gDialogBoxOpenTimer == 0.0f) {
                gDialogBoxState = DIALOG_STATE_VERTICAL;
                gDialogLineNum = 1;
            }
#ifndef VERSION_JP
            lowerBound = 1;
#endif
            break;

        case DIALOG_STATE_VERTICAL:
            gDialogBoxOpenTimer = 0.0f;

            if ((gPlayer3Controller->buttonPressed & A_BUTTON)
                || (gPlayer3Controller->buttonPressed & B_BUTTON)) {
                if (gLastDialogPageStrPos == -1) {
                    handle_special_dialog_text(gDialogID);
                    gDialogBoxState = DIALOG_STATE_CLOSING;
                } else {
                    gDialogBoxState = DIALOG_STATE_HORIZONTAL;
                    play_sound(SOUND_MENU_MESSAGE_NEXT_PAGE, gGlobalSoundSource);
                }
            }
#ifndef VERSION_JP
            lowerBound = 1;
#endif
            break;

        case DIALOG_STATE_HORIZONTAL:
            gDialogScrollOffsetY += dialog->linesPerBox * 2;

            if (gDialogScrollOffsetY >= dialog->linesPerBox * DIAG_VAL1) {
                gDialogTextPos = gLastDialogPageStrPos;
                gDialogBoxState = DIALOG_STATE_VERTICAL;
                gDialogScrollOffsetY = 0;
            }
#ifndef VERSION_JP
            lowerBound = (gDialogScrollOffsetY / DIAG_VAL1) + 1;
#endif
            break;

        case DIALOG_STATE_CLOSING:
            if (gDialogBoxOpenTimer == 20.0f) {
                level_set_transition(0, NULL);
                play_sound(SOUND_MENU_MESSAGE_DISAPPEAR, gGlobalSoundSource);

                if (gDialogBoxType == DIALOG_TYPE_ZOOM) {
                    trigger_cutscene_dialog(2);
                }

                gDialogResponse = gDialogLineNum;
            }

            gDialogBoxOpenTimer = gDialogBoxOpenTimer + 10.0f;
            gDialogBoxScale = gDialogBoxScale + 2.0f;

            if (gDialogBoxOpenTimer == DEFAULT_DIALOG_BOX_ANGLE) {
                gDialogBoxState = DIALOG_STATE_OPENING;
                gDialogID = DIALOG_NONE;
                gDialogTextPos = 0;
                gLastDialogResponse = 0;
                gLastDialogPageStrPos = 0;
                gDialogResponse = DIALOG_RESPONSE_NONE;
            }
#ifndef VERSION_JP
            lowerBound = 1;
#endif
            break;
    }

    render_dialog_box_type(dialog, dialog->linesPerBox);

    gDPSetScissor(gDisplayListHead++, G_SC_NON_INTERLACE, 0, ensure_nonnegative(DIAG_VAL2 - dialog->width),
        SCREEN_WIDTH, ensure_nonnegative(240 + ((dialog->linesPerBox * 80) / DIAG_VAL4) - dialog->width));

    /*gDPSetScissor(gDisplayListHead++, G_SC_NON_INTERLACE,
                  // Horizontal scissoring isn't really required and can potentially mess up widescreen enhancements.
#ifdef WIDESCREEN
        0,
#else
        ensure_nonnegative(dialog->leftOffset),
#endif
        ensure_nonnegative(DIAG_VAL2 - dialog->width),
#ifdef VERSION_EU
#ifdef WIDESCREEN
        SCREEN_WIDTH,
#else
        ensure_nonnegative(dialog->leftOffset + (DIAG_VAL3 / gDialogBoxScale)),
#endif
        ensure_nonnegative((240 - dialog->width) + (dialog->linesPerBox * 80 / DIAG_VAL4 / gDialogBoxScale))
#else
#ifdef WIDESCREEN
        SCREEN_WIDTH,
#else
        ensure_nonnegative(dialog->leftOffset + DIAG_VAL3),
#endif
                  ensure_nonnegative(240 + ((dialog->linesPerBox * 80) / DIAG_VAL4) - dialog->width));
#endif*/
#if defined(VERSION_JP)
    handle_dialog_text_and_pages(0, dialog);
#else
    handle_dialog_text_and_pages(0, dialog, lowerBound);
#endif

    if (gLastDialogPageStrPos == -1 && gLastDialogResponse == 1) {
        render_dialog_triangle_choice();
    }
    gDPSetScissor(gDisplayListHead++, G_SC_NON_INTERLACE, 2, 2, SCREEN_WIDTH - gBorderHeight/2, SCREEN_HEIGHT - gBorderHeight/2);
    if (gLastDialogPageStrPos != -1 && gDialogBoxState == DIALOG_STATE_VERTICAL) {
        render_dialog_triangle_next(dialog->linesPerBox);
    }
}

// Calls a gMenuMode value defined by render_menus_and_dialogs cases
void set_menu_mode(s16 mode) {
    if (gMenuMode == MENU_MODE_NONE) {
        gMenuMode = mode;
    }
}

void reset_cutscene_msg_fade(void) {
    gCutsceneMsgFade = 0;
}

void dl_rgba16_begin_cutscene_msg_fade(void) {
    gSPDisplayList(gDisplayListHead++, dl_rgba16_text_begin);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, gCutsceneMsgFade);
}

void dl_rgba16_stop_cutscene_msg_fade(void) {
    gSPDisplayList(gDisplayListHead++, dl_rgba16_text_end);

    if (gCutsceneMsgFade < 250) {
        gCutsceneMsgFade += 25;
    } else {
        gCutsceneMsgFade = 255;
    }
}

u8 ascii_to_credits_char(u8 c) {
    if (c >= 'A' && c <= 'Z') {
        return (c - ('A' - 0xA));
    }

    if (c >= 'a' && c <= 'z') { // remap lower to upper case
        return (c - ('a' - 0xA));
    }

    if (c == ' ') {
        return GLOBAL_CHAR_SPACE;
    }

    if (c == '.') {
        return 0x24;
    }

    if (c == '3') {
        return ASCII_TO_DIALOG('3');
    }

    if (c == '4') {
        return ASCII_TO_DIALOG('4');
    }

    if (c == '6') {
        return ASCII_TO_DIALOG('6');
    }

    return GLOBAL_CHAR_SPACE;
}

void print_credits_str_ascii(s16 x, s16 y, const char *str) {
    s32 pos = 0;
    u8 c = str[pos];
    u8 creditStr[100];

    while (c != 0) {
        creditStr[pos++] = ascii_to_credits_char(c);
        c = str[pos];
    }

    creditStr[pos] = GLOBAR_CHAR_TERMINATOR;

    print_credits_string(x, y, creditStr);
}

void set_cutscene_message(s16 xOffset, s16 yOffset, s16 msgIndex, s16 msgDuration) {
    // is message done printing?
    if (gCutsceneMsgIndex == -1) {
        gCutsceneMsgIndex = msgIndex;
        gCutsceneMsgDuration = msgDuration;
        gCutsceneMsgTimer = 0;
        gCutsceneMsgXOffset = xOffset;
        gCutsceneMsgYOffset = yOffset;
        gCutsceneMsgFade = 0;
    }
}

void do_cutscene_handler(void) {
    s16 x;

    // is a cutscene playing? do not perform this handler's actions if so.
    if (gCutsceneMsgIndex == -1) {
        return;
    }

    create_dl_ortho_matrix();

    gSPDisplayList(gDisplayListHead++, dl_ia_text_begin);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, gCutsceneMsgFade);

#ifdef VERSION_EU
    switch (eu_get_language()) {
        case LANGUAGE_ENGLISH:
            x = get_str_x_pos_from_center(gCutsceneMsgXOffset, gEndCutsceneStringsEn[gCutsceneMsgIndex], 10.0f);
            print_generic_string(x, 240 - gCutsceneMsgYOffset, gEndCutsceneStringsEn[gCutsceneMsgIndex]);
            break;
        case LANGUAGE_FRENCH:
            x = get_str_x_pos_from_center(gCutsceneMsgXOffset, gEndCutsceneStringsFr[gCutsceneMsgIndex], 10.0f);
            print_generic_string(x, 240 - gCutsceneMsgYOffset, gEndCutsceneStringsFr[gCutsceneMsgIndex]);
            break;
        case LANGUAGE_GERMAN:
            x = get_str_x_pos_from_center(gCutsceneMsgXOffset, gEndCutsceneStringsDe[gCutsceneMsgIndex], 10.0f);
            print_generic_string(x, 240 - gCutsceneMsgYOffset, gEndCutsceneStringsDe[gCutsceneMsgIndex]);
            break;
    }
#else
    // get the x coordinate of where the cutscene string starts.
    x = get_str_x_pos_from_center(gCutsceneMsgXOffset, gEndCutsceneStringsEn[gCutsceneMsgIndex], 10.0f);
    print_generic_string(x, 240 - gCutsceneMsgYOffset, gEndCutsceneStringsEn[gCutsceneMsgIndex]);
#endif

    gSPDisplayList(gDisplayListHead++, dl_ia_text_end);

    // if the timing variable is less than 5, increment
    // the fade until we are at full opacity.
    if (gCutsceneMsgTimer < 5) {
        gCutsceneMsgFade += 50;
    }

    // if the cutscene frame length + the fade-in counter is
    // less than the timer, it means we have exceeded the
    // time that the message is supposed to remain on
    // screen. if (message_duration = 50) and (msg_timer = 55)
    // then after the first 5 frames, the message will remain
    // on screen for another 50 frames until it starts fading.
    if (gCutsceneMsgDuration + 5 < gCutsceneMsgTimer) {
        gCutsceneMsgFade -= 50;
    }

    // like the first check, it takes 5 frames to fade out, so
    // perform a + 10 to account for the earlier check (10-5=5).
    if (gCutsceneMsgDuration + 10 < gCutsceneMsgTimer) {
        gCutsceneMsgIndex = -1;
        gCutsceneMsgFade = 0;
        gCutsceneMsgTimer = 0;
        return;
    }

    gCutsceneMsgTimer++;
}

#ifdef VERSION_JP
    #define PEACH_MESSAGE_TIMER 170
#else
#define PEACH_MESSAGE_TIMER 150
#endif

#if defined(VERSION_JP) || defined(VERSION_SH)
    #define STR_X 53
    #define STR_Y 136
#else
#define STR_X 38
#define STR_Y 147
#endif

// "Dear Mario" message handler
void print_peach_letter_message(void) {
    void **dialogTable;
    struct DialogEntry *dialog;
    u8 *str;

#ifdef VERSION_EU
    gInGameLanguage = eu_get_language();
    switch (gInGameLanguage) {
        case LANGUAGE_ENGLISH:
            dialogTable = segmented_to_virtual(dialog_table_eu_en);
            break;
        case LANGUAGE_FRENCH:
            dialogTable = segmented_to_virtual(dialog_table_eu_fr);
            break;
        case LANGUAGE_GERMAN:
            dialogTable = segmented_to_virtual(dialog_table_eu_de);
            break;
    }
#else
    dialogTable = segmented_to_virtual(seg2_dialog_table);
#endif
    dialog = segmented_to_virtual(dialogTable[gDialogID]);
    str = segmented_to_virtual(dialog->str);

    create_dl_translation_matrix(MENU_MTX_PUSH, 97.0f, 118.0f, 0);

    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, gCutsceneMsgFade);
    gSPDisplayList(gDisplayListHead++, castle_grounds_seg7_dl_0700EA58);
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
    gSPDisplayList(gDisplayListHead++, dl_ia_text_begin);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, gCutsceneMsgFade);

    print_generic_string(STR_X, STR_Y, str);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, 255);
    gSPDisplayList(gDisplayListHead++, dl_ia_text_end);
    //gDPSetEnvColor(gDisplayListHead++, 200, 80, 120, gCutsceneMsgFade);
    gDPSetEnvColor(gDisplayListHead++, 0x6D, 0x33, 0xD5, gCutsceneMsgFade);
    gSPDisplayList(gDisplayListHead++, castle_grounds_seg7_us_dl_0700F2E8);

    // at the start/end of message, reset the fade.
    if (gCutsceneMsgTimer == 0) {
        gCutsceneMsgFade = 0;
    }

    // we're less than 20 increments, so increase the fade.
    if (gCutsceneMsgTimer < 20) {
        gCutsceneMsgFade += 10;
    }

    // we're after PEACH_MESSAGE_TIMER increments, so decrease the fade.
    if (gCutsceneMsgTimer > PEACH_MESSAGE_TIMER) {
        gCutsceneMsgFade -= 18;
    }

    // 20 increments after the start of the decrease, we're
    // back where we are, so reset everything at the end.
    if (gCutsceneMsgTimer > (PEACH_MESSAGE_TIMER + 11)) {
        gCutsceneMsgIndex = -1;
        gCutsceneMsgFade = 0; //! uselessly reset since the next execution will just set it to 0 again.
        gDialogID = DIALOG_NONE;
        gCutsceneMsgTimer = 0;
        return; // return to avoid incrementing the timer
    }

    gCutsceneMsgTimer++;
}

/**
 * Renders the cannon reticle when Mario is inside a cannon.
 * Formed by four triangles.
 */
void render_hud_cannon_reticle(void) {
    create_dl_translation_matrix(MENU_MTX_PUSH, 160.0f, 120.0f, 0);

    gDPSetEnvColor(gDisplayListHead++, 50, 50, 50, 180);
    create_dl_translation_matrix(MENU_MTX_PUSH, -20.0f, -8.0f, 0);
    gSPDisplayList(gDisplayListHead++, dl_draw_triangle);
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);

    create_dl_translation_matrix(MENU_MTX_PUSH, 20.0f, 8.0f, 0);
    create_dl_rotation_matrix(MENU_MTX_NOPUSH, 180.0f, 0, 0, 1.0f);
    gSPDisplayList(gDisplayListHead++, dl_draw_triangle);
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);

    create_dl_translation_matrix(MENU_MTX_PUSH, 8.0f, -20.0f, 0);
    create_dl_rotation_matrix(MENU_MTX_NOPUSH, DEFAULT_DIALOG_BOX_ANGLE, 0, 0, 1.0f);
    gSPDisplayList(gDisplayListHead++, dl_draw_triangle);
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);

    create_dl_translation_matrix(MENU_MTX_PUSH, -8.0f, 20.0f, 0);
    create_dl_rotation_matrix(MENU_MTX_NOPUSH, -DEFAULT_DIALOG_BOX_ANGLE, 0, 0, 1.0f);
    gSPDisplayList(gDisplayListHead++, dl_draw_triangle);
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);

    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
}

void reset_red_coins_collected(void) {
    gRedCoinsCollected = 0;
    gGreenCoinsCollected = 0;
}

void change_dialog_camera_angle(void) {
    if (cam_select_alt_mode(0) == CAM_SELECTION_MARIO) {
        gDialogCameraAngleIndex = CAM_SELECTION_MARIO;
    } else {
        gDialogCameraAngleIndex = CAM_SELECTION_FIXED;
    }
}

void shade_screen(void) {
    create_dl_translation_matrix(MENU_MTX_PUSH, GFX_DIMENSIONS_FROM_LEFT_EDGE(0), SCREEN_HEIGHT, 0);

    // This is a bit weird. It reuses the dialog text box (width 130, height -80),
    // so scale to at least fit the screen.
#ifdef WIDESCREEN
    create_dl_scale_matrix(MENU_MTX_NOPUSH,
                           GFX_DIMENSIONS_ASPECT_RATIO * SCREEN_HEIGHT / 130.0f, 3.0f, 1.0f);
#else
    create_dl_scale_matrix(MENU_MTX_NOPUSH, 2.6f, 3.4f, 1.0f);
#endif

    gDPSetEnvColor(gDisplayListHead++, 0, 0, 0, 110);
    gSPDisplayList(gDisplayListHead++, dl_draw_text_bg_box);
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
}

void print_animated_red_coin(s16 x, s16 y) {
    s32 globalTimer = gGlobalTimer;

    create_dl_translation_matrix(MENU_MTX_PUSH, x, y, 0);
    create_dl_scale_matrix(MENU_MTX_NOPUSH, 0.2f, 0.2f, 1.0f);
    gDPSetRenderMode(gDisplayListHead++, G_RM_TEX_EDGE, G_RM_TEX_EDGE2);

    switch (globalTimer & 7) {
        case 0:
            gSPDisplayList(gDisplayListHead++, coin_seg3_dl_red_0);
            break;
        case 1:
            gSPDisplayList(gDisplayListHead++, coin_seg3_dl_red_22_5);
            break;
        case 2:
            gSPDisplayList(gDisplayListHead++, coin_seg3_dl_red_45);
            break;
        case 3:
            gSPDisplayList(gDisplayListHead++, coin_seg3_dl_red_67_5);
            break;
        case 4:
            gSPDisplayList(gDisplayListHead++, coin_seg3_dl_red_90);
            break;
        case 5:
            gSPDisplayList(gDisplayListHead++, coin_seg3_dl_red_67_5_r);
            break;
        case 6:
            gSPDisplayList(gDisplayListHead++, coin_seg3_dl_red_45_r);
            break;
        case 7:
            gSPDisplayList(gDisplayListHead++, coin_seg3_dl_red_22_5_r);
            break;
    }

    gDPSetRenderMode(gDisplayListHead++, G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2);
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
}

void render_pause_red_coins(void) {
    s8 x;

    for (x = 0; x < gRedCoinsCollected; x++) {
        print_animated_red_coin(GFX_DIMENSIONS_FROM_RIGHT_EDGE(30) - x * 20, 16);
    }
}

#if defined(WIDE)
void render_widescreen_setting(void) {
    gSPDisplayList(gDisplayListHead++, dl_ia_text_begin);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, gDialogTextAlpha);
    if (!gConfig.widescreen) {
        print_generic_string(10, 20, textCurrRatio43);
        print_generic_string(10, 7, textPressL);
    }
    else {
        print_generic_string(10, 20, textCurrRatio169);
        print_generic_string(10, 7, textPressL);
    }
    gSPDisplayList(gDisplayListHead++, dl_ia_text_end);
    if (gPlayer1Controller->buttonPressed & L_TRIG){
        gConfig.widescreen ^= 1;
        save_file_set_widescreen_mode(gConfig.widescreen);
    }
}
#endif



#define GREEN_COINS_HUD_X 240
#define GREEN_COINS_HUD_Y 16


void render_pause_green_coins(void) {
    s32 timer = gGlobalTimer;

    create_dl_translation_matrix(MENU_MTX_PUSH, GREEN_COINS_HUD_X, GREEN_COINS_HUD_Y, 0);
    create_dl_scale_matrix(MENU_MTX_NOPUSH, 0.23f, 0.23f, 1.0f);
    gDPSetRenderMode(gDisplayListHead++, G_RM_TEX_EDGE, G_RM_TEX_EDGE2);

    switch (timer & 7) {
        case 0:
            gSPDisplayList(gDisplayListHead++, coin_seg3_dl_green_0);
            break;
        case 1:
            gSPDisplayList(gDisplayListHead++, coin_seg3_dl_green_22_5);
            break;
        case 2:
            gSPDisplayList(gDisplayListHead++, coin_seg3_dl_green_45);
            break;
        case 3:
            gSPDisplayList(gDisplayListHead++, coin_seg3_dl_green_67_5);
            break;
        case 4:
            gSPDisplayList(gDisplayListHead++, coin_seg3_dl_green_90);
            break;
        case 5:
            gSPDisplayList(gDisplayListHead++, coin_seg3_dl_green_67_5_r);
            break;
        case 6:
            gSPDisplayList(gDisplayListHead++, coin_seg3_dl_green_45_r);
            break;
        case 7:
            gSPDisplayList(gDisplayListHead++, coin_seg3_dl_green_22_5_r);
            break;
    }

    gDPSetRenderMode(gDisplayListHead++, G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2);
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);

    print_text(GREEN_COINS_HUD_X+10, GREEN_COINS_HUD_Y, "*", 0); // 'X' glyph
    print_text_fmt_int(GREEN_COINS_HUD_X+24, GREEN_COINS_HUD_Y, "%d", gGreenCoinsCollected, 0);
}


#ifdef VERSION_EU
u8 gTextCourse[][7] = {
    { TEXT_COURSE },
    { TEXT_COURSE_FR },
    { TEXT_COURSE_DE }
};
#define textCourse gTextCourse
#endif

#if defined(VERSION_JP) || defined(VERSION_SH)
    #define CRS_NUM_X1 93
#elif defined(VERSION_US)
    #define CRS_NUM_X1 100
#elif defined(VERSION_EU)
    #define CRS_NUM_X1 get_string_width(LANGUAGE_ARRAY(textCourse)) + 51
#endif

#ifdef VERSION_EU
    #define TXT_COURSE_X      48
    #define TXT_STAR_X        89
    #define ACT_NAME_X        107
    #define LVL_NAME_X        108
    #define SECRET_LVL_NAME_X get_str_x_pos_from_center(159, &courseName[3], 10.0f)
    #define MYSCORE_X         48
#else
    #define TXT_COURSE_X      63
    #define TXT_STAR_X        98
    #define ACT_NAME_X        116
    #define LVL_NAME_X        117
    #define SECRET_LVL_NAME_X 94
    #define MYSCORE_X         62
#endif


extern s8 sLevelRoomOffsets[];
extern s8 gGlobalMarioRoom;
extern char *sRoomNames[];
extern char sRoomCorrupt[];


static char sLevel1[] = { TEXT_L1 };
static char sLevel2[] = { TEXT_L2 };
static char sLevel3[] = { TEXT_L3 };
static char sLevel4[] = { TEXT_L4 };
static char sLevel5[] = { TEXT_L5 };
static char sLevel6[] = { TEXT_L6 };
static char sLevel7[] = { TEXT_L7 };
static char sLevel8[] = { TEXT_L8 };

char *sLevelNames[] = {
    sLevel1, sLevel2, sLevel3, sLevel4, sLevel5, sLevel6, sLevel7, sLevel8
};



static char sObj1[] = { TEXT_OBJ1 };
static char sObj2[] = { TEXT_OBJ2 };
static char sObj3[] = { TEXT_OBJ3 };
static char sObj4[] = { TEXT_OBJ4 };
static char sObj5[] = { TEXT_OBJ5 };
static char sObj6[] = { TEXT_OBJ6 };
static char sObj7[] = { TEXT_OBJ7 };
static char sObj8[] = { TEXT_OBJ8 };
static char sObj9[] = { TEXT_OBJ9 };
static char sObj10[] = { TEXT_OBJ10 };
static char sObj11[] = { TEXT_OBJ11 };
static char sObj12[] = { TEXT_OBJ12 };
static char sObj13[] = { TEXT_OBJ13 };

char *sObjectives[] = {
    sObj1, sObj2, sObj3, sObj4, sObj5, sObj6, sObj7, sObj8, sObj9, sObj10, sObj11, sObj12, sObj13
};





s32 get_current_objective(void) {
    s32 flags = save_file_get_newflags(0);
    s32 boos = save_file_get_boos();
    if (gCurrLevelNum == LEVEL_LLL) {
        return 9;
    } else if (boos & (1 << 0x12)) {
        return 8;
    } else if (save_file_get_newflags(1) & SAVE_TOAD_FLAG_ENTER_L6) {
        return 7;
    } else if (flags & SAVE_NEW_FLAG_BROKEN1 && flags & SAVE_NEW_FLAG_BROKEN2 && flags & SAVE_NEW_FLAG_BROKEN3) {
        return 6;
    } else if (flags & SAVE_NEW_FLAG_CITY_TOAD_SAVED) {
        return 3;
    } else if (flags & SAVE_NEW_FLAG_CITY_BAND_BOUGHT) {
        return 5;
    } else if (boos & (1 << 0xA)) {
        if (gCurrLevelNum == LEVEL_CCM) {
            return 4;
        } else {
            return 3;
        }
    } else if (flags & SAVE_NEW_FLAG_KEY_CUTSCENE) {
        return 3;
    } else if (boos & (1 << 4)) {
        if (gCurrLevelNum == LEVEL_BOB) {
            return 1;
        } else {
            return 2;
        }
    } else {
        return 0;
    }
}








void render_pause_my_score_coins(void) {
    u8 strCourseNum[4];
    void **courseNameTbl;
    u8 *courseName;
    void **actNameTbl;
    u8 *actName;
    u8 courseIndex;
    s32 centerX;
    s32 objective;

    courseNameTbl = segmented_to_virtual(seg2_course_name_table);
    actNameTbl = segmented_to_virtual(seg2_act_name_table);

    courseIndex = COURSE_NUM_TO_INDEX(gCurrCourseNum);


    gSPDisplayList(gDisplayListHead++, dl_rgba16_text_begin);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, gDialogTextAlpha);

    //if (courseIndex < COURSE_STAGES_COUNT) {
    //    print_hud_my_score_coins(1, gCurrSaveFileNum - 1, courseIndex, 178, 103);
    //    print_hud_my_score_stars(gCurrSaveFileNum - 1, courseIndex, 118, 103);
    //}

    gSPDisplayList(gDisplayListHead++, dl_rgba16_text_end);
    gSPDisplayList(gDisplayListHead++, dl_ia_text_begin);

    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, gDialogTextAlpha);

    // if (courseIndex <= COURSE_NUM_TO_INDEX(COURSE_STAGES_MAX)
    //     && save_file_get_course_star_count(gCurrSaveFileNum - 1, courseIndex) != 0) {
    //     print_generic_string(MYSCORE_X, 121, LANGUAGE_ARRAY(textMyScore));
    // }

    courseName = segmented_to_virtual(courseNameTbl[courseIndex]);

    if (courseIndex < COURSE_STAGES_COUNT) {
/*#ifdef VERSION_EU
        print_generic_string(48, 157, gTextCourseArr[gInGameLanguage]);
#else
        print_generic_string(63, 157, textCourse);
#endif
        int_to_str(gCurrCourseNum, strCourseNum);
        print_generic_string(CRS_NUM_X1, 157, strCourseNum);
#endif*/

        //actName = segmented_to_virtual(sRoomNames[gGlobalMarioRoom - 1]);

        /*if (starFlags & (1 << (gDialogCourseActNum - 1))) {
            print_generic_string(TXT_STAR_X, 140, textStar);
        } else {
            print_generic_string(TXT_STAR_X, 140, textUnfilledStar);
        }*/
        centerX = get_str_x_pos_from_center(160, sLevelNames[gCurrCourseNum - 1], 0.0f);
        print_generic_string(centerX, 156, sLevelNames[gCurrCourseNum - 1]);

        centerX = get_str_x_pos_from_center(160, sRoomNames[gGlobalMarioRoom - 1], 0.0f);
        if (gGlobalMarioRoom == 72) {
            print_generic_string(centerX, 140, sRoomCorrupt);
        }
        print_generic_string(centerX, 140, sRoomNames[gGlobalMarioRoom - 1]);

/*#ifndef VERSION_JP
        print_generic_string(LVL_NAME_X, 157, &courseName[3]);
#endif*/
    }
/*#ifndef VERSION_JP
    else {
#if defined(VERSION_US) || defined(VERSION_SH)
        print_generic_string(94, 157, &courseName[3]);
#elif defined(VERSION_EU)
        print_generic_string(get_str_x_pos_from_center(159, &courseName[3], 10.0f), 157, &courseName[3]);
#endif
    }
#else
    print_generic_string(117, 157, &courseName[3]);
#endif*/
    gSPDisplayList(gDisplayListHead++, dl_ia_text_end);
}

#if defined(VERSION_JP) || defined(VERSION_SH)
    #define TXT1_X 4
    #define TXT2_X 116
    #define Y_VAL7 0
#else
    #define TXT1_X 3
    #define TXT2_X 119
    #define Y_VAL7 2
#endif



#define OPT_X 160
#define OPT_Y 140
#define CENTER_X ((OPT_X + 28) + (OPT_X + 124)) / 2



void render_pause_options(void) {
    u8 textOptions[] = { TEXT_OPTIONS };
    u8 textMusicOn[] = { TEXT_MUSIC_ON };
    u8 textMusicOff[] = { TEXT_MUSIC_OFF };
    // u8 textRCAM[] = { TEXT_RCAM };
    u8 textTrackerOn[] = { TEXT_TRACKER_ON };
    u8 textTrackerOff[] = { TEXT_TRACKER_OFF };
    // u8 textOn[] = { TEXT_ON };
    // u8 textOff[] = { TEXT_OFF };
    s32 x;
    handle_menu_scrolling(MENU_SCROLL_VERTICAL, &gDialogOptionsIndex, 1, 2);

    gSPDisplayList(gDisplayListHead++, dl_ia_text_begin);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, gDialogTextAlpha);

    x = get_str_x_pos_from_center(OPT_X, textOptions, 1.0f);
    print_generic_string(x, OPT_Y + 15, textOptions);
    x = get_str_x_pos_from_center(OPT_X, textMusicOn, 1.0f);
    print_generic_string(x, OPT_Y - 15, textMusicOn);
    // x = get_str_x_pos_from_center(OPT_X, textRCAM, 1.0f);
    // print_generic_string(x, OPT_Y - 30, textRCAM);
    x = get_str_x_pos_from_center(OPT_X, textTrackerOn, 1.0f);
    print_generic_string(x, OPT_Y - 30, textTrackerOn);

    gSPDisplayList(gDisplayListHead++, dl_ia_text_end);

    create_dl_translation_matrix(MENU_MTX_PUSH, OPT_X - 48, OPT_Y + 16 - (gDialogOptionsIndex * 15), 0);
    create_dl_rotation_matrix(MENU_MTX_NOPUSH, 180.0f, 0, 0, 1.0f);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, gDialogTextAlpha);
    gSPDisplayList(gDisplayListHead++, dl_draw_triangle);
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);

    create_dl_translation_matrix(MENU_MTX_PUSH, OPT_X + 48, OPT_Y - (gDialogOptionsIndex * 15), 0);
    gSPDisplayList(gDisplayListHead++, dl_draw_triangle);
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
}








void render_pause_camera_options(s16 x, s16 y, s8 *index, s16 xIndex) {
    u8 textLakituMario[] = { TEXT_LAKITU_MARIO };
    u8 textLakituStop[] = { TEXT_LAKITU_STOP };
#ifdef VERSION_EU
    u8 textNormalUpClose[][20] = {
        { TEXT_NORMAL_UPCLOSE },
        { TEXT_NORMAL_UPCLOSE_FR },
        { TEXT_NORMAL_UPCLOSE_DE }
    };
    u8 textNormalFixed[][17] = {
        { TEXT_NORMAL_FIXED },
        { TEXT_NORMAL_FIXED_FR },
        { TEXT_NORMAL_FIXED_DE },
    };
#else
    u8 textNormalUpClose[] = { TEXT_NORMAL_UPCLOSE };
    u8 textNormalFixed[] = { TEXT_NORMAL_FIXED };
#endif

    handle_menu_scrolling(MENU_SCROLL_HORIZONTAL, index, 1, 2);

    gSPDisplayList(gDisplayListHead++, dl_ia_text_begin);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, gDialogTextAlpha);

    print_generic_string(x + 14, y + 2, textLakituMario);
    print_generic_string(x + TXT1_X, y - 13, LANGUAGE_ARRAY(textNormalUpClose));
    print_generic_string(x + 124, y + 2, textLakituStop);
    print_generic_string(x + TXT2_X, y - 13, LANGUAGE_ARRAY(textNormalFixed));

    gSPDisplayList(gDisplayListHead++, dl_ia_text_end);
    create_dl_translation_matrix(MENU_MTX_PUSH, ((*index - 1) * xIndex) + x, y + Y_VAL7, 0);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, gDialogTextAlpha);
    gSPDisplayList(gDisplayListHead++, dl_draw_triangle);
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);

    switch (*index) {
        case CAM_SELECTION_MARIO:
            cam_select_alt_mode(CAM_SELECTION_MARIO);
            break;
        case CAM_SELECTION_FIXED:
            cam_select_alt_mode(CAM_SELECTION_FIXED);
            break;
    }
}

#if defined(VERSION_JP) || defined(VERSION_SH)
    #define X_VAL8 0
    #define Y_VAL8 4
#else
    #define X_VAL8 4
    #define Y_VAL8 2
#endif

void render_pause_course_options(s16 x, s16 y, s8 *index, s16 yIndex) {
    u8 textContinue[] = { TEXT_CONTINUE };
    u8 textExitCourse[] = { TEXT_EXIT_COURSE };
    u8 textCameraAngleR[] = { TEXT_CAMERA_ANGLE_R };

    handle_menu_scrolling(MENU_SCROLL_VERTICAL, index, 1, 3);

    gSPDisplayList(gDisplayListHead++, dl_ia_text_begin);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, gDialogTextAlpha);

    print_generic_string(x + 10, y - 2, LANGUAGE_ARRAY(textContinue));
    print_generic_string(x + 10, y - 17, LANGUAGE_ARRAY(textExitCourse));

    if (*index != MENU_OPT_CAMERA_ANGLE_R) {
        print_generic_string(x + 10, y - 33, LANGUAGE_ARRAY(textCameraAngleR));
        gSPDisplayList(gDisplayListHead++, dl_ia_text_end);

        create_dl_translation_matrix(MENU_MTX_PUSH, x - X_VAL8, (y - ((*index - 1) * yIndex)) - Y_VAL8, 0);

        gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, gDialogTextAlpha);
        gSPDisplayList(gDisplayListHead++, dl_draw_triangle);
        gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
    }

    // if (*index == MENU_OPT_CAMERA_ANGLE_R) {
    //     render_pause_camera_options(x - 42, y - 42, &gDialogCameraAngleIndex, 110);
    // }
}

void render_pause_castle_menu_box(s16 x, s16 y) {
    create_dl_translation_matrix(MENU_MTX_PUSH, x - 78, y - 32, 0);
    create_dl_scale_matrix(MENU_MTX_NOPUSH, 1.2f, 0.8f, 1.0f);
    gDPSetEnvColor(gDisplayListHead++, 0, 0, 0, 105);
    gSPDisplayList(gDisplayListHead++, dl_draw_text_bg_box);
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);

    create_dl_translation_matrix(MENU_MTX_PUSH, x + 6, y - 28, 0);
    create_dl_rotation_matrix(MENU_MTX_NOPUSH, DEFAULT_DIALOG_BOX_ANGLE, 0, 0, 1.0f);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, gDialogTextAlpha);
    gSPDisplayList(gDisplayListHead++, dl_draw_triangle);
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);

    create_dl_translation_matrix(MENU_MTX_PUSH, x - 9, y - 101, 0);
    create_dl_rotation_matrix(MENU_MTX_NOPUSH, 270.0f, 0, 0, 1.0f);
    gSPDisplayList(gDisplayListHead++, dl_draw_triangle);
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
}

void highlight_last_course_complete_stars(void) {
    u8 doneCourseIndex;

    if (gLastCompletedCourseNum == COURSE_NONE) {
        doneCourseIndex = 0;
    } else {
        doneCourseIndex = COURSE_NUM_TO_INDEX(gLastCompletedCourseNum);

        if (doneCourseIndex >= COURSE_NUM_TO_INDEX(COURSE_BONUS_STAGES)) {
            doneCourseIndex = COURSE_NUM_TO_INDEX(COURSE_BONUS_STAGES);
        }
    }

    gDialogLineNum = doneCourseIndex;
}

#ifdef VERSION_EU
    #define PAUSE_X get_str_x_pos_from_center_scale(SCREEN_WIDTH / 2, textPause, 12.0f)
#else
    #define PAUSE_X 123
#endif

void print_hud_pause_colorful_str(void) {
    u8 textPause[] = { TEXT_PAUSE };

    gSPDisplayList(gDisplayListHead++, dl_rgba16_text_begin);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, gDialogTextAlpha);

    print_hud_lut_string(HUD_LUT_GLOBAL, PAUSE_X, 81, textPause);

    gSPDisplayList(gDisplayListHead++, dl_rgba16_text_end);
}

void render_pause_castle_course_stars(s16 x, s16 y, s16 fileIndex, s16 courseIndex) {
    s16 hasStar = 0;

    u8 str[COURSE_STAGES_COUNT * 2];

    u8 textStar[] = { TEXT_STAR };

    u8 starFlags = save_file_get_star_flags(fileIndex, courseIndex);
    u16 starCount = save_file_get_course_star_count(fileIndex, courseIndex);

    u16 nextStar = 0;

    if (starFlags & (1 << 6)) {
        starCount--;
        print_generic_string(x + 89, y - 5, textStar);
    }

    while (hasStar != starCount) {
        if (starFlags & (1 << nextStar)) {
            str[nextStar * 2] = DIALOG_CHAR_STAR_FILLED;
            hasStar++;
        } else {
            str[nextStar * 2] = DIALOG_CHAR_STAR_OPEN;
        }

        str[nextStar * 2 + 1] = DIALOG_CHAR_SPACE;
        nextStar++;
    }

    if (starCount == nextStar && starCount != 6) {
        str[nextStar * 2] = DIALOG_CHAR_STAR_OPEN;
        str[nextStar * 2 + 1] = DIALOG_CHAR_SPACE;
        nextStar++;
    }

    str[nextStar * 2] = DIALOG_CHAR_TERMINATOR;

    print_generic_string(x + 14, y + 13, str);
}

void render_pause_castle_main_strings(s16 x, s16 y) {
#ifdef VERSION_EU
    void **courseNameTbl;
#else
    void **courseNameTbl = segmented_to_virtual(seg2_course_name_table);
#endif

#ifdef VERSION_EU
    u8 textCoin[] = { TEXT_COIN };
    u8 textX[] = { TEXT_VARIABLE_X };
#else
    u8 textCoin[] = { TEXT_COIN_X };
#endif

    void *courseName;

    u8 strVal[8];
    s16 prevCourseIndex = gDialogLineNum;

#ifdef VERSION_EU
    switch (gInGameLanguage) {
        case LANGUAGE_ENGLISH:
            courseNameTbl = segmented_to_virtual(course_name_table_eu_en);
            break;
        case LANGUAGE_FRENCH:
            courseNameTbl = segmented_to_virtual(course_name_table_eu_fr);
            break;
        case LANGUAGE_GERMAN:
            courseNameTbl = segmented_to_virtual(course_name_table_eu_de);
            break;
    }
#endif

    handle_menu_scrolling(
        MENU_SCROLL_VERTICAL, &gDialogLineNum,
        COURSE_NUM_TO_INDEX(COURSE_MIN) - 1, COURSE_NUM_TO_INDEX(COURSE_BONUS_STAGES) + 1
    );

    if (gDialogLineNum == COURSE_NUM_TO_INDEX(COURSE_BONUS_STAGES) + 1) {
        gDialogLineNum = COURSE_NUM_TO_INDEX(COURSE_MIN); // Exceeded max, set to min
    }

    if (gDialogLineNum == COURSE_NUM_TO_INDEX(COURSE_MIN) - 1) {
        gDialogLineNum = COURSE_NUM_TO_INDEX(COURSE_BONUS_STAGES); // Exceeded min, set to max
    }

    if (gDialogLineNum != COURSE_NUM_TO_INDEX(COURSE_BONUS_STAGES)) {
        while (save_file_get_course_star_count(gCurrSaveFileNum - 1, gDialogLineNum) == 0) {
            if (gDialogLineNum >= prevCourseIndex) {
                gDialogLineNum++;
            } else {
                gDialogLineNum--;
            }

            if (gDialogLineNum == COURSE_NUM_TO_INDEX(COURSE_STAGES_MAX) + 1
                || gDialogLineNum == COURSE_NUM_TO_INDEX(COURSE_MIN) - 1) {
                gDialogLineNum = COURSE_NUM_TO_INDEX(COURSE_BONUS_STAGES);
                break;
            }
        }
    }

    gSPDisplayList(gDisplayListHead++, dl_ia_text_begin);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, gDialogTextAlpha);

    if (gDialogLineNum <= COURSE_NUM_TO_INDEX(COURSE_STAGES_MAX)) { // Main courses
        courseName = segmented_to_virtual(courseNameTbl[gDialogLineNum]);
        render_pause_castle_course_stars(x, y, gCurrSaveFileNum - 1, gDialogLineNum);
        print_generic_string(x + 34, y - 5, textCoin);
#ifdef VERSION_EU
        print_generic_string(x + 44, y - 5, textX);
#endif
        int_to_str(save_file_get_course_coin_score(gCurrSaveFileNum - 1, gDialogLineNum), strVal);
        print_generic_string(x + 54, y - 5, strVal);
#ifdef VERSION_EU
        print_generic_string(x - 17, y + 30, courseName);
#endif
    } else { // Castle secret stars
        u8 textStarX[] = { TEXT_STAR_X };
        courseName = segmented_to_virtual(courseNameTbl[COURSE_MAX]);
        print_generic_string(x + 40, y + 13, textStarX);
        int_to_str(save_file_get_total_star_count(gCurrSaveFileNum - 1, COURSE_BONUS_STAGES - 1, COURSE_MAX - 1), strVal);
        print_generic_string(x + 60, y + 13, strVal);
#ifdef VERSION_EU
        print_generic_string(get_str_x_pos_from_center(x + 51, courseName, 10.0f), y + 30, courseName);
#endif
    }

#ifndef VERSION_EU
    print_generic_string(x - 9, y + 30, courseName);
#endif

    gSPDisplayList(gDisplayListHead++, dl_ia_text_end);
}

s8 gCourseCompleteCoinsEqual = FALSE;
s32 gCourseDoneMenuTimer = 0;
s32 gCourseCompleteCoins = 0;
s8 gHudFlash = 0;

s16 render_pause_courses_and_castle(void) {
    s16 index;
    s16 saveFlag;

#ifdef VERSION_EU
    gInGameLanguage = eu_get_language();
#endif

    switch (gDialogBoxState) {
        case DIALOG_STATE_OPENING:
            gDialogLineNum = MENU_OPT_DEFAULT;
            gDialogTextAlpha = 0;
            level_set_transition(-1, NULL);
            play_sound(SOUND_MENU_PAUSE, gGlobalSoundSource);

            if (gCurrCourseNum >= COURSE_MIN && gCurrCourseNum <= COURSE_MAX) {
                change_dialog_camera_angle();
                gDialogBoxState = DIALOG_STATE_VERTICAL;
            } else {
                highlight_last_course_complete_stars();
                gDialogBoxState = DIALOG_STATE_HORIZONTAL;
            }
            break;

        case DIALOG_STATE_VERTICAL:
            shade_screen();
            if (gMenuROptions) {
                render_pause_options();
            } else {
                render_pause_my_score_coins();
            }
            
            render_pause_red_coins();
            if (gGreenCoinsCollected) {
                render_pause_green_coins();
            }

            // if (gMarioStates[0].action & ACT_FLAG_PAUSE_EXIT) {
            //     render_pause_course_options(99, 93, &gDialogLineNum, 15);
            // }

            create_dl_translation_matrix(MENU_MTX_PUSH, GFX_DIMENSIONS_FROM_LEFT_EDGE(0), SCREEN_HEIGHT, 0);
            // create_dl_scale_matrix(MENU_MTX_NOPUSH, 2.6f, 3.4f, 1.0f);
            gSPDisplayList(gDisplayListHead++, map_overlay_Overlay_mesh);
            gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);

            render_hud_starpieces();
            render_hud_coins();

            if (gPlayer3Controller->buttonPressed & A_BUTTON
                || gPlayer3Controller->buttonPressed & START_BUTTON)
            {
                level_set_transition(0, NULL);
                play_sound(SOUND_MENU_PAUSE_2, gGlobalSoundSource);
                gDialogBoxState = DIALOG_STATE_OPENING;
                gMenuMode = MENU_MODE_NONE;

                if (gDialogLineNum == MENU_OPT_EXIT_COURSE) {
                    index = gDialogLineNum;
                } else { // MENU_OPT_CONTINUE or MENU_OPT_CAMERA_ANGLE_R
                    index = MENU_OPT_DEFAULT;
                }

                return index;
            }
            break;

        case DIALOG_STATE_HORIZONTAL:
            shade_screen();
            print_hud_pause_colorful_str();
            render_pause_castle_menu_box(160, 143);
            render_pause_castle_main_strings(104, 60);

#ifdef VERSION_EU
            if (gPlayer3Controller->buttonPressed & (A_BUTTON | Z_TRIG | START_BUTTON))
#else
            if (gPlayer3Controller->buttonPressed & A_BUTTON
                || gPlayer3Controller->buttonPressed & START_BUTTON)
#endif
            {
                level_set_transition(0, NULL);
                play_sound(SOUND_MENU_PAUSE_2, gGlobalSoundSource);
                gMenuMode = MENU_MODE_NONE;
                gDialogBoxState = DIALOG_STATE_OPENING;

                return MENU_OPT_DEFAULT;
            }
            break;
    }

    // #if defined(WIDE)
    //     render_widescreen_setting();
    // #endif
    saveFlag = save_file_get_newflags(1) & SAVE_TOAD_FLAG_INTRODUCTION;
#ifdef SMMM_DEBUG
    saveFlag = 1;
#endif
    gSPDisplayList(gDisplayListHead++, dl_ia_text_begin);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, gDialogTextAlpha);
    if (gMenuROptions) {
        print_generic_string(243, 190, textRBack);
    } else {
        print_generic_string(243, 190, textROptions);
    }
    if (gCurrCourseNum > 0 && gCurrCourseNum <= 8 && saveFlag) {
        print_generic_string(24, 206, textLRoomManager);

        if (gPlayer1Controller->buttonPressed & L_TRIG) {
            gMenuMode = MENU_MODE_MAP;
            gMapModeInit = 0;
            init_map();
        }
    }
    if (gPlayer1Controller->buttonPressed & R_TRIG) {
        gMenuROptions ^= 1;
        gDialogOptionsIndex = 1;
    }
    gSPDisplayList(gDisplayListHead++, dl_ia_text_end);

    if (gDialogTextAlpha < 250) {
        gDialogTextAlpha += 25;
    }

    return MENU_OPT_NONE;
}

#if defined(VERSION_JP)
    #define TXT_HISCORE_X 112
    #define TXT_HISCORE_Y 48
    #define TXT_CONGRATS_X 60
#elif defined(VERSION_US)
    #define TXT_HISCORE_X 109
    #define TXT_HISCORE_Y 36
    #define TXT_CONGRATS_X 70
#elif defined(VERSION_EU)
    #define TXT_HISCORE_X get_str_x_pos_from_center_scale(160, LANGUAGE_ARRAY(textHiScore), 12.0f)
    #define TXT_HISCORE_Y 36
    #define TXT_CONGRATS_X get_str_x_pos_from_center_scale(160, LANGUAGE_ARRAY(textCongratulations), 12.0f)
#elif defined(VERSION_SH)
    #define TXT_HISCORE_X 118
    #define TXT_HISCORE_Y 48
    #define TXT_CONGRATS_X 70
#endif

#define HUD_PRINT_HISCORE         0
#define HUD_PRINT_CONGRATULATIONS 1

void print_hud_course_complete_string(s8 str) {
#ifdef VERSION_EU
    u8 textHiScore[][15] = {
        { TEXT_HUD_HI_SCORE },
        { TEXT_HUD_HI_SCORE_FR },
        { TEXT_HUD_HI_SCORE_DE }
    };
    u8 textCongratulations[][16] = {
        { TEXT_HUD_CONGRATULATIONS },
        { TEXT_HUD_CONGRATULATIONS_FR },
        { TEXT_HUD_CONGRATULATIONS_DE }
    };
#else
    u8 textHiScore[] = { TEXT_HUD_HI_SCORE };
    u8 textCongratulations[] = { TEXT_HUD_CONGRATULATIONS };
#endif

    u8 colorFade = sins(gDialogColorFadeTimer) * 50.0f + 200.0f;

    gSPDisplayList(gDisplayListHead++, dl_rgba16_text_begin);
    gDPSetEnvColor(gDisplayListHead++, colorFade, colorFade, colorFade, 255);

    if (str == HUD_PRINT_HISCORE) {
        print_hud_lut_string(HUD_LUT_GLOBAL, TXT_HISCORE_X, TXT_HISCORE_Y, LANGUAGE_ARRAY(textHiScore));
    } else { // HUD_PRINT_CONGRATULATIONS
        print_hud_lut_string(HUD_LUT_GLOBAL, TXT_CONGRATS_X, 67, LANGUAGE_ARRAY(textCongratulations));
    }

    gSPDisplayList(gDisplayListHead++, dl_rgba16_text_end);
}

void print_hud_course_complete_coins(s16 x, s16 y) {
    u8 courseCompleteCoinsStr[4];
    u8 hudTextSymCoin[] = { GLYPH_COIN, GLYPH_SPACE };
    u8 hudTextSymX[] = { GLYPH_MULTIPLY, GLYPH_SPACE };

    gSPDisplayList(gDisplayListHead++, dl_rgba16_text_begin);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, 255);

    print_hud_lut_string(HUD_LUT_GLOBAL, x, y, hudTextSymCoin);
    print_hud_lut_string(HUD_LUT_GLOBAL, x + 16, y, hudTextSymX);

    int_to_str(gCourseCompleteCoins, courseCompleteCoinsStr);
    print_hud_lut_string(HUD_LUT_GLOBAL, x + 32, y, courseCompleteCoinsStr);

    gSPDisplayList(gDisplayListHead++, dl_rgba16_text_end);

    if (gCourseCompleteCoins >= gHudDisplay.coins) {
        gCourseCompleteCoinsEqual = TRUE;
        gCourseCompleteCoins = gHudDisplay.coins;

        if (gGotFileCoinHiScore) {
            print_hud_course_complete_string(HUD_PRINT_HISCORE);
        }
    } else {
        if ((gCourseDoneMenuTimer & 1) || gHudDisplay.coins > 70) {
            gCourseCompleteCoins++;
            play_sound(SOUND_MENU_YOSHI_GAIN_LIVES, gGlobalSoundSource);

            if (gCourseCompleteCoins == 50 || gCourseCompleteCoins == 100 || gCourseCompleteCoins == 150) {
                play_sound(SOUND_GENERAL_COLLECT_1UP, gGlobalSoundSource);
                //gMarioState->numLives++;
            }
        }

        if (gHudDisplay.coins == gCourseCompleteCoins && gGotFileCoinHiScore) {
            play_sound(SOUND_MENU_MARIO_CASTLE_WARP2, gGlobalSoundSource);
        }
    }
}

void play_star_fanfare_and_flash_hud(s32 arg, u8 starNum) {
    if (gHudDisplay.coins == gCourseCompleteCoins && (gCurrCourseStarFlags & starNum) == 0 && gHudFlash == 0) {
        play_star_fanfare();
        gHudFlash = arg;
    }
}

#ifdef VERSION_EU
    #define TXT_NAME_X1 centerX
    #define TXT_NAME_X2 centerX - 1
#else
    #define TXT_NAME_X1 71
    #define TXT_NAME_X2 TXT_NAME_X1 - 2
#endif

#if defined(VERSION_JP) || defined(VERSION_SH)
    #define CRS_NUM_X2 95
    #define CRS_NUM_X3 CRS_NUM_X2 - 2
    #define TXT_CLEAR_X1 205
    #define TXT_CLEAR_X2 TXT_CLEAR_X1 - 2
#else
    #define CRS_NUM_X2 104
    #define CRS_NUM_X3 CRS_NUM_X2 - 2
    #define TXT_CLEAR_X1 get_string_width(name) + 81
    #define TXT_CLEAR_X2 TXT_CLEAR_X1 - 2
#endif

void render_course_complete_lvl_info_and_hud_str(void) {
#if defined(VERSION_JP)
    u8 textSymStar[] = { GLYPH_STAR, GLYPH_SPACE };
    u8 textCourse[] = { TEXT_COURSE };
    u8 textCatch[] = { TEXT_CATCH };
    u8 textClear[] = { TEXT_CLEAR };
#elif defined(VERSION_EU)
    UNUSED u8 textCatch[] = { TEXT_CATCH }; // unused in EU
    u8 textSymStar[] = { GLYPH_STAR, GLYPH_SPACE };
#else
    u8 textCourse[] = { TEXT_COURSE };
    UNUSED u8 textCatch[] = { TEXT_CATCH }; // unused in US
    UNUSED u8 textClear[] = { TEXT_CLEAR };
    u8 textSymStar[] = { GLYPH_STAR, GLYPH_SPACE };
#endif

    void **actNameTbl;
    void **courseNameTbl;
    u8 *name;

    u8 strCourseNum[4];

#ifdef VERSION_EU
    s16 centerX;
    switch (gInGameLanguage) {
        case LANGUAGE_ENGLISH:
            actNameTbl = segmented_to_virtual(act_name_table_eu_en);
            courseNameTbl = segmented_to_virtual(course_name_table_eu_en);
            break;
        case LANGUAGE_FRENCH:
            actNameTbl = segmented_to_virtual(act_name_table_eu_fr);
            courseNameTbl = segmented_to_virtual(course_name_table_eu_fr);
            break;
        case LANGUAGE_GERMAN:
            actNameTbl = segmented_to_virtual(act_name_table_eu_de);
            courseNameTbl = segmented_to_virtual(course_name_table_eu_de);
            break;
    }
#else
    actNameTbl = segmented_to_virtual(seg2_act_name_table);
    courseNameTbl = segmented_to_virtual(seg2_course_name_table);
#endif

    if (gLastCompletedCourseNum <= COURSE_STAGES_MAX) { // Main courses
        print_hud_course_complete_coins(118, 103);
        play_star_fanfare_and_flash_hud(1, 1 << (gLastCompletedStarNum - 1));

        if (gLastCompletedStarNum == 7) {
            name = segmented_to_virtual(actNameTbl[COURSE_STAGES_MAX * 6 + 1]);
        } else {
            name = segmented_to_virtual(actNameTbl[COURSE_NUM_TO_INDEX(gLastCompletedCourseNum) * 6 + gLastCompletedStarNum - 1]);
        }

        // Print course number
        gSPDisplayList(gDisplayListHead++, dl_ia_text_begin);

        int_to_str(gLastCompletedCourseNum, strCourseNum);

        gDPSetEnvColor(gDisplayListHead++, 0, 0, 0, gDialogTextAlpha);
        print_generic_string(65, 165, LANGUAGE_ARRAY(textCourse));
        print_generic_string(CRS_NUM_X2, 165, strCourseNum);

        gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, gDialogTextAlpha);
        print_generic_string(63, 167, LANGUAGE_ARRAY(textCourse));
        print_generic_string(CRS_NUM_X3, 167, strCourseNum);

        gSPDisplayList(gDisplayListHead++, dl_ia_text_end);
    } else if (gLastCompletedCourseNum == COURSE_BITDW || gLastCompletedCourseNum == COURSE_BITFS) { // Bowser courses
        name = segmented_to_virtual(courseNameTbl[COURSE_NUM_TO_INDEX(gLastCompletedCourseNum)]);

        // Print course name and clear text
        gSPDisplayList(gDisplayListHead++, dl_ia_text_begin);

        gDPSetEnvColor(gDisplayListHead++, 0, 0, 0, gDialogTextAlpha);
#ifdef VERSION_EU
        centerX = get_str_x_pos_from_center(153, name, 12.0f);
#endif
        print_generic_string(TXT_NAME_X1, 130, name);
#ifndef VERSION_EU
        print_generic_string(TXT_CLEAR_X1, 130, textClear);
#endif

        gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, gDialogTextAlpha);
        print_generic_string(TXT_NAME_X2, 132, name);
#ifndef VERSION_EU
        print_generic_string(TXT_CLEAR_X2, 132, textClear);
#endif

        gSPDisplayList(gDisplayListHead++, dl_ia_text_end);

        print_hud_course_complete_string(HUD_PRINT_CONGRATULATIONS);
        print_hud_course_complete_coins(118, 111);
        play_star_fanfare_and_flash_hud(2, 0); //! 2 isn't defined, originally for key hud?

        return;
    } else { // Castle secret stars
        name = segmented_to_virtual(actNameTbl[COURSE_STAGES_MAX * 6]);

        print_hud_course_complete_coins(118, 103);
        play_star_fanfare_and_flash_hud(1, 1 << (gLastCompletedStarNum - 1));
    }

    // Print star glyph
    gSPDisplayList(gDisplayListHead++, dl_rgba16_text_begin);

    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, gDialogTextAlpha);
    print_hud_lut_string(HUD_LUT_GLOBAL, 55, 77, textSymStar);

    gSPDisplayList(gDisplayListHead++, dl_rgba16_text_end);

    // Print act name and catch text
    gSPDisplayList(gDisplayListHead++, dl_ia_text_begin);

    gDPSetEnvColor(gDisplayListHead++, 0, 0, 0, gDialogTextAlpha);
    print_generic_string(76, 145, name);
#if defined(VERSION_JP) || defined(VERSION_SH)
    print_generic_string(220, 145, textCatch);
#endif

    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, gDialogTextAlpha);
    print_generic_string(74, 147, name);
#if defined(VERSION_JP) || defined(VERSION_SH)
    print_generic_string(218, 147, textCatch);
#endif

    gSPDisplayList(gDisplayListHead++, dl_ia_text_end);
}

#if defined(VERSION_JP) || defined(VERSION_SH)
    #define X_VAL9 x
    #define TXT_SAVEOPTIONS_X x + 10
    #define TXT_SAVECONT_Y 2
    #define TXT_SAVEQUIT_Y 18
    #define TXT_CONTNOSAVE_Y 38
#else
#ifdef VERSION_EU
    #define X_VAL9 xOffset - 12
    #define TXT_SAVEOPTIONS_X xOffset
#else
    #define X_VAL9 x
    #define TXT_SAVEOPTIONS_X x + 12
#endif
    #define TXT_SAVECONT_Y 0
    #define TXT_SAVEQUIT_Y 20
    #define TXT_CONTNOSAVE_Y 40
#endif

#ifdef VERSION_EU
void render_save_confirmation(s16 y, s8 *index, s16 sp6e)
#else
void render_save_confirmation(s16 x, s16 y, s8 *index, s16 sp6e)
#endif
{
#ifdef VERSION_EU
    u8 textSaveAndContinue[][24] = {
        { TEXT_SAVE_AND_CONTINUE },
        { TEXT_SAVE_AND_CONTINUE_FR },
        { TEXT_SAVE_AND_CONTINUE_DE }
    };
    u8 textSaveAndQuit[][22] = {
        { TEXT_SAVE_AND_QUIT },
        { TEXT_SAVE_AND_QUIT_FR },
        { TEXT_SAVE_AND_QUIT_DE }
    };
    u8 textContinueWithoutSave[][27] = {
        { TEXT_CONTINUE_WITHOUT_SAVING },
        { TEXT_CONTINUE_WITHOUT_SAVING_FR },
        { TEXT_CONTINUE_WITHOUT_SAVING_DE }
    };
    s16 xOffset = get_str_x_pos_from_center(160, LANGUAGE_ARRAY(textContinueWithoutSave), 12.0f);
#else
    u8 textSaveAndContinue[] = { TEXT_SAVE_AND_CONTINUE };
    u8 textSaveAndQuit[] = { TEXT_SAVE_AND_QUIT };
    u8 textContinueWithoutSave[] = { TEXT_CONTINUE_WITHOUT_SAVING };
#endif

    handle_menu_scrolling(MENU_SCROLL_VERTICAL, index, 1, 3);

    gSPDisplayList(gDisplayListHead++, dl_ia_text_begin);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, gDialogTextAlpha);

    print_generic_string(TXT_SAVEOPTIONS_X, y + TXT_SAVECONT_Y, LANGUAGE_ARRAY(textSaveAndContinue));
    print_generic_string(TXT_SAVEOPTIONS_X, y - TXT_SAVEQUIT_Y, LANGUAGE_ARRAY(textSaveAndQuit));
    print_generic_string(TXT_SAVEOPTIONS_X, y - TXT_CONTNOSAVE_Y, LANGUAGE_ARRAY(textContinueWithoutSave));

    gSPDisplayList(gDisplayListHead++, dl_ia_text_end);

    create_dl_translation_matrix(MENU_MTX_PUSH, X_VAL9, y - ((*index - 1) * sp6e), 0);

    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, gDialogTextAlpha);
    gSPDisplayList(gDisplayListHead++, dl_draw_triangle);

    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
}

s16 render_course_complete_screen(void) {
    s16 index;
#ifdef VERSION_EU
    gInGameLanguage = eu_get_language();
#endif

    switch (gDialogBoxState) {
        case DIALOG_STATE_OPENING:
            render_course_complete_lvl_info_and_hud_str();
            if (gCourseDoneMenuTimer > 100 && gCourseCompleteCoinsEqual == TRUE) {
                gDialogBoxState = DIALOG_STATE_VERTICAL;
                level_set_transition(-1, NULL);
                gDialogTextAlpha = 0;
                gDialogLineNum = MENU_OPT_DEFAULT;
            }
            break;

        case DIALOG_STATE_VERTICAL:
            shade_screen();
            render_course_complete_lvl_info_and_hud_str();
#ifdef VERSION_EU
            render_save_confirmation(86, &gDialogLineNum, 20);
#else
            render_save_confirmation(100, 86, &gDialogLineNum, 20);
#endif

            if (gCourseDoneMenuTimer > 110
                && (gPlayer3Controller->buttonPressed & A_BUTTON
                 || gPlayer3Controller->buttonPressed & START_BUTTON
#ifdef VERSION_EU
                 || gPlayer3Controller->buttonPressed & Z_TRIG
#endif
                )) {
                level_set_transition(0, NULL);
                play_sound(SOUND_MENU_STAR_SOUND, gGlobalSoundSource);
                gDialogBoxState = DIALOG_STATE_OPENING;
                gMenuMode = MENU_MODE_NONE;
                index = gDialogLineNum;
                gCourseDoneMenuTimer = 0;
                gCourseCompleteCoins = 0;
                gCourseCompleteCoinsEqual = FALSE;
                gHudFlash = 0;

                return index;
            }
            break;
    }

    if (gDialogTextAlpha < 250) {
        gDialogTextAlpha += 25;
    }

    gCourseDoneMenuTimer++;

    return MENU_OPT_NONE;
}


#include "map_data/model.inc.c"



extern s16 gMatStackIndex;
extern Mat4 gMatStack[32];

f32 gMapCamOffset[3] = {0.0f, 0.0f, 0.0f};


struct MapObject {
    s8 levelRoom;
    s8 globalRoom;
    s16 flags; // 0x1 = cleared, 0x2 = current quest/goal room, 0x4 = has unkilled boo, 0x8 = has keys, 0x10 = boss room
    // s8 items; // 
    f32 x;
    f32 z;
    Gfx *dl;
    struct MapObject *prev;
};

struct MapKey {
    f32 x;
    f32 z;
    s8 id;
    s8 alive;
};

struct MapKey gMapKeyPool[10];
struct MapObject gMapObjectPool[30];
struct MapObject *gCurrentMapObject;
struct MapKey *gCurrentMapKey;

s32 sCurrGoalLevel;
s32 sCurrGoalRoom;

#define mo gCurrentMapObject


s32 check_map_boss(void) {
    switch (mo->globalRoom) {
        case 11:
            if (save_file_get_boos() & (1 << 4)) {
                return FALSE;
            } else {
                return TRUE;
            }
            break;
        case 28:
            if (save_file_get_boos() & (1 << 0xA)) {
                return FALSE;
            } else {
                return TRUE;
            }
            break;
        case 39:
            if (save_file_get_boos() & (1 << 0xE)) {
                return FALSE;
            } else {
                return TRUE;
            }
            break;
        case 63:
            if (save_file_get_boos() & (1 << 0x12)) {
                return FALSE;
            } else {
                return TRUE;
            }
            break;
        case 73:
            if (save_file_get_newflags(0) & SAVE_NEW_FLAG_ELEVATOR_BOSS) {
                return FALSE;
            } else {
                return TRUE;
            }
            break;
    }

    return FALSE;
}

s32 get_map_from_level(void) {
    switch (gCurrLevelNum) {
        case LEVEL_BOB:
            return 0;
        case LEVEL_WF:
            return 1;
        case LEVEL_JRB:
            return 2;
        case LEVEL_CCM:
            return 3;
        case LEVEL_BBH:
            return 4;
        case LEVEL_HMC:
            return 5;
        case LEVEL_LLL:
            return 6;
        case LEVEL_SSL:
            return 7;
    }
    return 0;
}


struct MapObject *spawn_map_object(f32 x, f32 z, Gfx *dl, s32 room) {
    s32 i;
    for (i = 0; i < 30; i++) {
        if (gMapObjectPool[i].dl == NULL) {
            if (mo != NULL) {
                gMapObjectPool[i].prev = mo;
            } else {
                gMapObjectPool[i].prev = &gMapObjectPool[i];
            }
            mo = &gMapObjectPool[i];
            mo->x = x;
            mo->z = z;
            if (room == gMarioCurrentRoom) {
                gMapCamOffset[0] = x;
                gMapCamOffset[2] = z;
            }

            mo->levelRoom = room;
            mo->globalRoom = room + sLevelRoomOffsets[gCurrCourseNum - 1];
            mo->dl = dl;

            // 0x1 = cleared, 0x2 = current quest/goal room, 0x4 = has unkilled boo, 0x8 = has keys, 0x10 = boss room
            if (save_file_check_room(mo->globalRoom)) {
                mo->flags |= 1;
            }
            //current quest/goal room:
            if (gCurrLevelNum == sCurrGoalLevel && sCurrGoalRoom == room) {
                mo->flags |= 2;
            }

            //has unkilled boo:
            if (CL_obj_find_nearest_object_with_behavior_room(gCurrentObject, bhvRoomBoo, room)) {
                mo->flags |= 4;
            }
            //has keys:

            //boss room:
            if (check_map_boss()) {
                    mo->flags |= 0x10;
                } 
            break;
        }
    }
}


void spawn_map_key(f32 x, f32 z, s8 id) {
    s32 i;
    if (save_file_get_keys(1) & (1 << id)) {
        return;
    }

    for (i = 0; i < 10; i++) {
        if (gMapKeyPool[i].alive == 0) {
            gCurrentMapKey = &gMapKeyPool[i];
            gCurrentMapKey->alive = 1;
            gCurrentMapKey->id = id;
            gCurrentMapKey->x = x;
            gCurrentMapKey->z = z;
            break;
        }
    }
}


void spawn_map_1(void) {
    spawn_map_object(0, 2824, map_l1_1MUDROOM_mesh_layer_1, 1);
    spawn_map_object(0, 1993, map_l1_2MAINHALL_mesh_layer_1, 2);
    spawn_map_object(455, 1383,  map_l1_3PARLOR_mesh_layer_1, 3);
    spawn_map_object(465, 1665,  map_l1_4GARAGE_mesh_layer_1, 4);
    spawn_map_object(-145, 685,  map_l1_5HALLWAYS_mesh_layer_1, 5);
    spawn_map_object(717, 536, map_l1_6DINING_mesh_layer_1, 6);
    spawn_map_object(230, 449, map_l1_7KITCHEN_mesh_layer_1, 7);
    spawn_map_object(78, 438, map_l1_8PANTRY_mesh_layer_1, 8);
    spawn_map_object(-569, 723,  map_l1_9LIVING_mesh_layer_1, 9);
    spawn_map_object(-1021, 865, map_l1_10STUDY_mesh_layer_1, 10);
    spawn_map_object(-844, 1475, map_l1_11LIBRARY_mesh_layer_1, 11);
    spawn_map_object(-471, 1381, map_l1_12HALLWAY2_mesh_layer_1, 12);
    spawn_map_object(15, 1166, map_l1_13HALLWAY3_mesh_layer_1, 13);
    spawn_map_object(-238, 1166, map_l1_14TREASURY_mesh_layer_1, 14);

    spawn_map_key(395, 793, 0);
    spawn_map_key(0, 1271, 1);
    spawn_map_key(-140, 1166, 31);
}



void spawn_map_2(void) {
    spawn_map_object(21, -802, map_l2_1LOUNGE_mesh_layer_1, 1);
    spawn_map_object(46, 137, map_l2_2BAR_mesh_layer_1, 2);
    spawn_map_object(104, 1434, map_l2_3BALCONY_mesh_layer_1, 3);
    spawn_map_object(292, -1383, map_l2_4BATHROOM_mesh_layer_1, 4);
    spawn_map_object(-321, -1870, map_l2_5DEN_mesh_layer_1, 5);
    spawn_map_object(-781, -1870, map_l2_6MIRROR_mesh_layer_1, 6);
    spawn_map_object(-547, -1029, map_l2_7BED1_mesh_layer_1, 7);
    spawn_map_object(-547, -1239, map_l2_8BED2_mesh_layer_1, 8);
    spawn_map_object(-397, -1203, map_l2_9WARDROBE_mesh_layer_1, 9);
    spawn_map_object(-757, -1239, map_l2_10BED3_mesh_layer_1, 10);
    spawn_map_object(-757, -1029, map_l2_11BED4_mesh_layer_1, 11);
    spawn_map_object(1001, -278, map_l2_12SERV_mesh_layer_1, 12);
    spawn_map_object(1810, -313, map_l2_13OFFICE_mesh_layer_1, 13);
    spawn_map_object(-692, -496, map_l2_14MASTERBED_mesh_layer_1, 14);
    spawn_map_object(-352, -362, map_l2_15HALL_mesh_layer_1, 15);
    spawn_map_object(610, -1031, map_l2_16HALL2_mesh_layer_1, 16);
    spawn_map_object(662, -780, map_l2_17PLAY_mesh_layer_1, 17);
    spawn_map_object(662, -1238, map_l2_18POOL_mesh_layer_1, 18);

    spawn_map_key(-324, -577, 2);
    spawn_map_key(-66, -1795, 3);
    spawn_map_key(396, -283, 4);
    spawn_map_key(-547, -708, 5);
    spawn_map_key(455, -1031, 6);
    spawn_map_key(-4, -1918, 7);
}

void spawn_map_3(void) {
    spawn_map_object(-136, 77, map_l3_1GARDEN_mesh_layer_1, 1);
    spawn_map_object(-809, -363, map_l3_2DOG_mesh_layer_1, 2);
    spawn_map_object(391, 965, map_l3_3UNDER_mesh_layer_1, 3);
    spawn_map_object(-363, 749, map_l3_4CONS_mesh_layer_1, 4);
}


void spawn_map_4(void) {
    spawn_map_object(519, 1464, map_l4_1CITY_mesh_layer_1, 1);
    spawn_map_object(674, 345, map_l4_2BCH_mesh_layer_1, 2);
    spawn_map_object(1689, -1227, map_l4_3CITY2_mesh_layer_1, 3);
    spawn_map_object(2352, -449, map_l4_4BOO_mesh_layer_1, 4);
    spawn_map_object(1250, -487, map_l4_5STAR_mesh_layer_1, 5);
}

void spawn_map_5(void) {
    spawn_map_object(-584, 527, map_l5_1OASIS_mesh_layer_1, 1);
    spawn_map_object(-1111, 231, map_l5_2TUNNEL_mesh_layer_1, 2);
    spawn_map_object(608, 1106, map_l5_3CAVE_mesh_layer_1, 3);
    spawn_map_object(304, 1446, map_l5_4CBOO_mesh_layer_1, 4);
    spawn_map_object(762, -660, map_l5_5SNOW_mesh_layer_1, 5);
    spawn_map_object(525, 359, map_l5_6UNDER_mesh_layer_1, 6);
    spawn_map_object(1942, -1452, map_l5_7CASTLE_mesh_layer_1, 7);
}

void spawn_map_6(void) {
    spawn_map_object( -1473, 390, map_l6_1OPEN_mesh_layer_1, 1);
    spawn_map_object( -757, 608, map_l6_2TROPHY_mesh_layer_1, 2);
    spawn_map_object( -170, 726, map_l6_3HALL_mesh_layer_1, 3);
    spawn_map_object( 415, 1126, map_l6_4MUSIC_mesh_layer_1, 4);
    spawn_map_object( 215, 316, map_l6_5GAME_mesh_layer_1, 5);
    spawn_map_object( -170, 226, map_l6_6PANIC_mesh_layer_1, 6);
    spawn_map_object( -355, -423, map_l6_7HALL2_mesh_layer_1, 7);
    spawn_map_object( -425, -965, map_l6_8MORNING_mesh_layer_1, 8);
    spawn_map_object( -810, -1255, map_l6_9THEATER_mesh_layer_1, 9);
    spawn_map_object( 1711, 1209, map_l6_10PRE1_mesh_layer_1, 10);
    spawn_map_object( 1711, 2, map_l6_11PRE2_mesh_layer_1, 11);
    spawn_map_object( 1744, -984,  map_l6_12TREE_mesh_layer_1, 12);
    spawn_map_object( -1872, -999, map_l6_13HALL3_mesh_layer_1, 13);
    spawn_map_object( -910, -406, map_l6_14SAUNA_mesh_layer_1, 14);
    spawn_map_object( -723, 1781, map_l6_15ATTIC_mesh_layer_1, 15);
    spawn_map_object( -195, 1802, map_l6_16ATTIC2_mesh_layer_1, 16);

    spawn_map_key(-90, 511, 8);
    spawn_map_key(423, 502, 9);
}


void spawn_map_7(void) {
    spawn_map_object(75, 41, map_l7_1CORRIDOR_mesh_layer_1, 1);
    spawn_map_object(828, 879, map_l7_2LAUNDRY_mesh_layer_1, 2);
    spawn_map_object(-874, -354, map_l7_3GYM_mesh_layer_1, 3);
    spawn_map_object(-260, 906, map_l7_4WINE_mesh_layer_1, 4);
    spawn_map_object(-245, 486, map_l7_5ROOT_mesh_layer_1, 5);
    spawn_map_object(-645, 471, map_l7_6MEAT_mesh_layer_1, 6);
    spawn_map_object(813, 34, map_l7_7ENGINE_mesh_layer_1, 7);
    spawn_map_object(885, -923, map_l7_8CHAMBER_mesh_layer_1, 8);
    spawn_map_object(50, -1194, map_l7_9ELEVATOR_mesh_layer_1, 9);
    spawn_map_object(-331, -1053, map_l7_10LAB_mesh_layer_1, 10);

    spawn_map_key(-428, 483, 0xA);
}
void spawn_map_8(void) {
}

static void (*MapObjectsSpawnTable[])(void) = {
    spawn_map_1,
    spawn_map_2,
    spawn_map_3,
    spawn_map_4,
    spawn_map_5,
    spawn_map_6,
    spawn_map_7,
    spawn_map_8,
};


void spawn_map_objects(s32 map) {
    // spawn_map_object(0.0f, -500.0f, test_map_TestMap_mesh, 1);
    // spawn_map_object(0.0f, 500.0f, test_map_TestMap_mesh, 2);
    // spawn_map_object(-500.0f, 0.0f, test_map_TestMap_mesh, 3);
    // spawn_map_object(500.0f, 0.0f, test_map_TestMap_mesh, 4);
    MapObjectsSpawnTable[map]();
}


void despawn_map_objects(void) {
    s32 i;
    for (i = 0; i < 30; i++) {
        if (gMapObjectPool[i].dl != NULL) {
            gMapObjectPool[i].dl = NULL;
            gMapObjectPool[i].x = 0;
            gMapObjectPool[i].z = 0;
            gMapObjectPool[i].flags = 0;
        }
    }
}

void despawn_map_keys(void) {
    s32 i;
    for (i = 0; i < 10; i++) {
        if (gMapKeyPool[i].alive != 0) {
            gMapKeyPool[i].alive = 0;
            gMapKeyPool[i].x = 0;
            gMapKeyPool[i].z = 0;
            gMapKeyPool[i].id = 0;
        }
    }
}


void set_goal_level_and_room(void) {
    s32 flags = save_file_get_newflags(0);
    s32 boos = save_file_get_boos();
    if (flags & SAVE_NEW_FLAG_ELEVATOR_BOSS) {
        sCurrGoalLevel = LEVEL_LLL;
        sCurrGoalRoom = 10;
    } else if (gCurrLevelNum == LEVEL_LLL) {
        sCurrGoalLevel = LEVEL_LLL;
        sCurrGoalRoom = 9;
    } else if (boos & (1 << 0x12)) {
        sCurrGoalLevel = LEVEL_BOB;
        sCurrGoalRoom = 4;
    } else if (save_file_get_rooms(1) & (1 << 25)) {
        sCurrGoalLevel = LEVEL_HMC;
        sCurrGoalRoom = 15;
    } else if (save_file_get_rooms(1) & (1 << 21)) {
        sCurrGoalLevel = LEVEL_HMC;
        sCurrGoalRoom = 9;
    } else if (save_file_get_newflags(1) & SAVE_TOAD_FLAG_ENTER_L6) {
        sCurrGoalLevel = LEVEL_HMC;
        sCurrGoalRoom = 5;
    } else if (flags & SAVE_NEW_FLAG_BROKEN1 && flags & SAVE_NEW_FLAG_BROKEN3) {
        if (flags & SAVE_NEW_FLAG_BROKEN2) {
            sCurrGoalLevel = LEVEL_WF;
            sCurrGoalRoom = 1;
        } else {
            if (gCurrLevelNum == LEVEL_WF) {
                sCurrGoalLevel = LEVEL_WF;
                sCurrGoalRoom = 5;
            } else {
                sCurrGoalLevel = LEVEL_JRB;
                sCurrGoalRoom = 1;
            }
        }
    } else if (flags & SAVE_NEW_FLAG_CITY_TOAD_SAVED) {
        sCurrGoalLevel = LEVEL_CCM;
        sCurrGoalRoom = 3;
    } else if (save_file_get_rooms(1) & (1 << 16)) {
        sCurrGoalLevel = LEVEL_BBH;
        sCurrGoalRoom = 7;
    } else if (flags & SAVE_NEW_FLAG_CITY_BAND_BOUGHT) {
        if (gCurrLevelNum == LEVEL_CCM) {
            sCurrGoalLevel = LEVEL_CCM;
            sCurrGoalRoom = 1;
        } else {
            sCurrGoalLevel = LEVEL_BBH;
            sCurrGoalRoom = 7;
        }
    } else if (boos & (1 << 0xA)) {
        if (gCurrLevelNum == LEVEL_CCM) {
            sCurrGoalLevel = LEVEL_CCM;
            sCurrGoalRoom = 1;
        } else {
            sCurrGoalLevel = LEVEL_WF;
            sCurrGoalRoom = 17;
        }
    } else if (flags & SAVE_NEW_FLAG_KEY_CUTSCENE) {
        sCurrGoalLevel = LEVEL_WF;
        sCurrGoalRoom = 14;
    } else if (boos & (1 << 4)) {
        if (gCurrLevelNum == LEVEL_BOB) {
            sCurrGoalLevel = LEVEL_BOB;
            sCurrGoalRoom = 13;
        } else {
            sCurrGoalLevel = LEVEL_WF;
            sCurrGoalRoom = 1;
        }
    } else {
        sCurrGoalLevel = LEVEL_BOB;
        sCurrGoalRoom = 11;
    }
}



void init_map(void) {
    s32 map = get_map_from_level();
    // map = 0;
    set_goal_level_and_room();
    gMapCamOffset[0] = 0.0f;
    gMapCamOffset[1] = 0.0f;
    gMapCamOffset[2] = 0.0f;
    spawn_map_objects(map);
}

void render_map_background(void) {
    Vec3f pos;
    Vec3s angle;
    vec3s_set(angle, 0, 0, 0);
    vec3f_set(pos, 0.0f, -26000.0f, 0.0f);
    mtxf_rotate_zxy_and_translate(gMatStack[gMatStackIndex + 1], pos, angle);
    Mtx *mtx = alloc_display_list(sizeof(*mtx));
    mtxf_to_mtx(mtx, gMatStack[gMatStackIndex + 1]);
    gSPMatrix(gDisplayListHead++, mtx, G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
    gDPSetEnvColor(gDisplayListHead++, 0x09, 0x10, 0x13, 255);
    gSPDisplayList(gDisplayListHead++, dl_draw_map_border);
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
}



void render_map_object(f32 x, f32 z, Gfx *dl) {
    Vec3f pos;
    Vec3s angle;
    vec3s_set(angle, 0xFF00, 0, 0xFF00);
    vec3f_set(pos, x, -26000.0f, z);
    mtxf_rotate_zxy_and_translate(gMatStack[gMatStackIndex + 1], pos, angle);
    Mtx *mtx = alloc_display_list(sizeof(*mtx));
    mtxf_to_mtx(mtx, gMatStack[gMatStackIndex + 1]);
    gSPMatrix(gDisplayListHead++, mtx, G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
    gSPDisplayList(gDisplayListHead++, dl);
    if (mo->flags &  0x10) { 
        gSPDisplayList(gDisplayListHead++, boss_icon_dl);
    } else if (mo->flags & 4) {
        gSPDisplayList(gDisplayListHead++, boo_icon_dl);
    }
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
    // print_text(20, 20, ",", 0);
}


void render_map_objects(void) {
    s32 i;
    s32 sameRoom = 0;
    for (i = 0; i < 30; i++) {
        if (gMapObjectPool[i].dl != NULL) {
            mo = &gMapObjectPool[i];
            if (mo->levelRoom == gMarioCurrentRoom) {
                sameRoom = 50;
                gDPSetPrimColor(gDisplayListHead++, 0, 0, 215, 230, 215, 255);
            } else {
                sameRoom = 0;
                gDPSetPrimColor(gDisplayListHead++, 0, 0, 80, 80, 80, 255);
            }
            if (mo->flags & 1) {
                gDPSetEnvColor(gDisplayListHead++, 20 + (sameRoom / 2), 40 + sameRoom, 20 + (sameRoom / 2), 255);
            } else {
                gDPSetEnvColor(gDisplayListHead++, 40 + sameRoom, 40 + sameRoom, 20 + (sameRoom / 2), 255);
            }
            if (mo->flags & 2) {
                gDPSetEnvColor(gDisplayListHead++, 200, 180, 50, 255);
            }

            render_map_object(mo->x, mo->z, mo->dl);
        }
    }
}



void render_map_key(f32 x, f32 z, s8 id) {
    Vec3f pos, scale;
    Vec3s angle;
    vec3s_set(angle, 0xC000, 0, 0);
    vec3f_set(pos, x, -25985.0f, z);
    vec3f_set(scale, 0.5f, 0.5f, 0.5f);
    mtxf_rotate_zxy_and_translate(gMatStack[gMatStackIndex + 1], pos, angle);
    mtxf_scale_vec3f(gMatStack[gMatStackIndex + 1], gMatStack[gMatStackIndex + 1], scale);
    Mtx *mtx = alloc_display_list(sizeof(*mtx));
    mtxf_to_mtx(mtx, gMatStack[gMatStackIndex + 1]);
    gSPMatrix(gDisplayListHead++, mtx, G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);

    if (save_file_get_keys(0) & (1 << id)) {
        gDPSetEnvColor(gDisplayListHead++, 50, 120, 50, 255);
    } else {
        gDPSetEnvColor(gDisplayListHead++, 120, 120, 120, 255);
    }


    gSPDisplayList(gDisplayListHead++, map_key_dl);
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
}


extern Vec3s sBasementSwitchCols[5];

void render_map_switch(f32 x, f32 z, s8 id) {
    Vec3f pos;
    // Vec3f scale;
    Vec3s angle;
    if (save_file_get_newflags(0) & (SAVE_NEW_FLAG_BASEMENT_SWITCH1 << id)) {
        return;
    }

    vec3s_set(angle, 0, 0, 0);
    vec3f_set(pos, x, -25985.0f, z);
    // vec3f_set(scale, 0.5f, 0.5f, 0.5f);
    mtxf_rotate_zxy_and_translate(gMatStack[gMatStackIndex + 1], pos, angle);
    // mtxf_scale_vec3f(gMatStack[gMatStackIndex + 1], gMatStack[gMatStackIndex + 1], scale);
    Mtx *mtx = alloc_display_list(sizeof(*mtx));
    mtxf_to_mtx(mtx, gMatStack[gMatStackIndex + 1]);
    gSPMatrix(gDisplayListHead++, mtx, G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);

    gDPSetEnvColor(gDisplayListHead++, sBasementSwitchCols[id][0], sBasementSwitchCols[id][1], sBasementSwitchCols[id][2], 255);
    gSPDisplayList(gDisplayListHead++, switch_icon_Switch_mesh);
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
}


void render_map_switches(void) {
    render_map_switch(828, 879, 0);
    render_map_switch(325, 24, 1);
    render_map_switch(-494, 80, 2);
    render_map_switch(-373, 633, 3);
    render_map_switch(948, -415, 4);
}


void render_map_keys(void) {
    s32 i;
    for (i = 0; i < 10; i++) {
        if (gMapKeyPool[i].alive != 0) {
            gCurrentMapKey = &gMapKeyPool[i];
            render_map_key(gCurrentMapKey->x, gCurrentMapKey->z, gCurrentMapKey->id);
        }
    }
}


void update_map_screen(void) {
    s32 objective, centerX;
    f32 div = 3.0f;
    if (gPlayer1Controller->buttonDown & (Z_TRIG | R_TRIG)) {
        div = 1.0f;
    }
    if (absf(gPlayer1Controller->stickX) > 10.0f) {
        gMapCamOffset[0] += gPlayer1Controller->stickX / div;
        if (gMapCamOffset[0] > 3000.0f) {
            gMapCamOffset[0] = 3000.0f;
        } else if (gMapCamOffset[0] < -3000.0f) {
            gMapCamOffset[0] = -3000.0f;
        }
    }
    if (absf(gPlayer1Controller->stickY) > 10.0f) {
        gMapCamOffset[2] -= gPlayer1Controller->stickY / div;
        if (gMapCamOffset[2] > 3000.0f) {
            gMapCamOffset[2] = 3000.0f;
        } else if (gMapCamOffset[2] < -3000.0f) {
            gMapCamOffset[2] = -3000.0f;
        }
    }
    if (gPlayer1Controller->buttonDown & (U_JPAD | U_CBUTTONS)) {
        gMapCamOffset[1] -= 50.0f;
        if (gMapCamOffset[1] < -800.0f) {
            gMapCamOffset[1] = -800.0f;
        }
    }
    if (gPlayer1Controller->buttonDown & (D_JPAD | D_CBUTTONS)) {
        gMapCamOffset[1] += 50.0f;
        if (gMapCamOffset[1] > 1600.0f) {
            gMapCamOffset[1] = 1600.0f;
        }
    }


    render_map_background();
    render_map_objects();
    render_map_keys();
    if (gCurrLevelNum == LEVEL_LLL) {
        render_map_switches();
    }


    create_dl_ortho_matrix();
    create_dl_translation_matrix(MENU_MTX_PUSH, GFX_DIMENSIONS_FROM_LEFT_EDGE(0), SCREEN_HEIGHT, 0);
    // create_dl_scale_matrix(MENU_MTX_NOPUSH, 2.6f, 3.4f, 1.0f);

    Gfx* dlhead = gDisplayListHead;
    gSPDisplayList(dlhead++, map_overlay_2_OverlayForMap_mesh);
    gSPPopMatrix(dlhead++, G_MTX_MODELVIEW);
    gDisplayListHead = dlhead;

    gSPDisplayList(gDisplayListHead++, dl_ia_text_begin);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, 255);
    print_generic_string(24 - 8, 216, textCurrObj);
    objective = get_current_objective();
    centerX = get_str_x_pos_from_center(211 - 4 - 4, sObjectives[objective], 0.0f);
    print_generic_string(centerX, 216, sObjectives[objective]);
    gSPDisplayList(gDisplayListHead++, dl_ia_text_end);

    // gDPSetEnvColor(gDisplayListHead++, 0, 255, 0, 255);
    // render_map_object(0.0f, -500.0f, test_map_TestMap_mesh);
    // gDPSetEnvColor(gDisplayListHead++, 0, 255, 255, 255);
    // render_map_object(0.0f, 500.0f, test_map_TestMap_mesh);
    // gDPSetEnvColor(gDisplayListHead++, 255, 0, 0, 255);
    // render_map_object(500.0f, 0.0f, test_map_TestMap_mesh);
    // gDPSetEnvColor(gDisplayListHead++, 255, 0, 255, 255);
    // render_map_object(-500.0f, 0.0f, test_map_TestMap_mesh);
}


void shade_screen_rgba(u8 r, u8 g, u8 b, u8 a) {
    create_dl_translation_matrix(MENU_MTX_PUSH, GFX_DIMENSIONS_FROM_LEFT_EDGE(0), SCREEN_HEIGHT, 0);

    // This is a bit weird. It reuses the dialog text box (width 130, height -80),
    // so scale to at least fit the screen.
    create_dl_scale_matrix(MENU_MTX_NOPUSH, 2.6f, 3.4f, 1.0f);

    Gfx* dlhead = gDisplayListHead;
    gDPSetEnvColor(dlhead++, r, g, b, a);
    gSPDisplayList(dlhead++, dl_draw_text_bg_box);
    gSPPopMatrix(dlhead++, G_MTX_MODELVIEW);
    gDisplayListHead = dlhead;
}

s16 gRoomAlpha = 0x0;

// Only case 1 and 2 are used
s16 render_menus_and_dialogs(void) {
    s16 index = MENU_OPT_NONE;

    create_dl_ortho_matrix();
    // if (gRoomAlpha) {
    //     shade_screen_rgba(0x3, 0xB, 0x3, gRoomAlpha);
    // }
    // if (gMarioCurrentRoom != 0) {
    //     if (!(gHudDisplay.flags & HUD_DISPLAY_FLAG_BOO)) { //save_file_check_global_room()
    //         gRoomAlpha = approach_s16_symmetric(gRoomAlpha, 0x0, 0x4);
    //     } else {
    //         gRoomAlpha = approach_s16_symmetric(gRoomAlpha, 0x90, 0x10);
    //     }
    // }

    if (gMenuMode != MENU_MODE_NONE) {
        switch (gMenuMode) {
            case MENU_MODE_UNUSED_0:
                index = render_pause_courses_and_castle();
                break;
            case MENU_MODE_RENDER_PAUSE_SCREEN:
                index = render_pause_courses_and_castle();
                break;
            case MENU_MODE_RENDER_COURSE_COMPLETE_SCREEN:
                index = render_course_complete_screen();
                break;
            case MENU_MODE_UNUSED_3:
                index = render_course_complete_screen();
                break;
            case MENU_MODE_MAP:
                if (gMapModeInit == 0) {
                    index = render_pause_courses_and_castle();
                    gMapModeInit = 1;
                }
                // render_map_screen();
                // gCamera->pos[0] = 0.0f;
                // gCamera->pos[1] = 0.0f;
                // gCamera->pos[2] = 0.0f;
                // gCamera->focus[0] = 10.0f;
                // gCamera->focus[1] = 10.0f;
                // gCamera->focus[2] = 10.0f;
                if (gPlayer1Controller->buttonPressed & L_TRIG) {
                    index = MENU_OPT_NONE;
                    gMenuMode = MENU_MODE_RENDER_PAUSE_SCREEN;
                    gMapModeInit = 0;
                    despawn_map_objects();
                    despawn_map_keys();
                } else if (gPlayer1Controller->buttonPressed & START_BUTTON) {
                    index = MENU_OPT_DEFAULT;
                    level_set_transition(0, NULL);
                    play_sound(SOUND_MENU_PAUSE_2, gGlobalSoundSource);
                    gMenuMode = MENU_MODE_NONE;
                    gMapModeInit = 0;
                    gDialogBoxState = DIALOG_STATE_OPENING;
                    despawn_map_objects();
                    despawn_map_keys();
                } else {
                    index = MENU_OPT_MAP;
                }
                break;
        }

        gDialogColorFadeTimer = (s16) gDialogColorFadeTimer + 0x1000;
    } else if (gDialogID != DIALOG_NONE) {
        // The Peach "Dear Mario" message needs to be repositioned separately
        if (gDialogID == DIALOG_020) {
            print_peach_letter_message();
            return index;
        }

        render_dialog_entries();
        gDialogColorFadeTimer = (s16) gDialogColorFadeTimer + 0x1000;
    }

    return index;
}






//#include "src/s2d_engine/sprites/room_names.c"

static char sRoom1[] = { TEXT_ROOM1 };
static char sRoom2[] = { TEXT_ROOM2 };
static char sRoom3[] = { TEXT_ROOM3 };
static char sRoom4[] = { TEXT_ROOM4 };
static char sRoom5[] = { TEXT_ROOM5 };
static char sRoom6[] = { TEXT_ROOM6 };
static char sRoom7[] = { TEXT_ROOM7 };
static char sRoom8[] = { TEXT_ROOM8 };
static char sRoom9[] = { TEXT_ROOM9 };
static char sRoom10[] = { TEXT_ROOM10 };
static char sRoom11[] = { TEXT_ROOM11 };
static char sRoom12[] = { TEXT_ROOM12 };
static char sRoom13[] = { TEXT_ROOM13 };
static char sRoom14[] = { TEXT_ROOM14 };
static char sRoom15[] = { TEXT_ROOM15 };
static char sRoom16[] = { TEXT_ROOM16 };
static char sRoom17[] = { TEXT_ROOM17 };
static char sRoom18[] = { TEXT_ROOM18 };
static char sRoom19[] = { TEXT_ROOM19 };
static char sRoom20[] = { TEXT_ROOM20 };
static char sRoom21[] = { TEXT_ROOM21 };
static char sRoom22[] = { TEXT_ROOM22 };
static char sRoom23[] = { TEXT_ROOM23 };
static char sRoom24[] = { TEXT_ROOM24 };
static char sRoom25[] = { TEXT_ROOM25 };
static char sRoom26[] = { TEXT_ROOM26 };
static char sRoom27[] = { TEXT_ROOM27 };
static char sRoom28[] = { TEXT_ROOM28 };
static char sRoom29[] = { TEXT_ROOM29 };
static char sRoom30[] = { TEXT_ROOM30 };
static char sRoom31[] = { TEXT_ROOM31 };
static char sRoom32[] = { TEXT_ROOM32 };
static char sRoom33[] = { TEXT_ROOM33 };
static char sRoom34[] = { TEXT_ROOM34 };
static char sRoom35[] = { TEXT_ROOM35 };
static char sRoom36[] = { TEXT_ROOM36 };
static char sRoom37[] = { TEXT_ROOM37 };
static char sRoom38[] = { TEXT_ROOM38 };
static char sRoom39[] = { TEXT_ROOM39 };
static char sRoom40[] = { TEXT_ROOM40 };
static char sRoom41[] = { TEXT_ROOM41 };
static char sRoom42[] = { TEXT_ROOM42 };
static char sRoom43[] = { TEXT_ROOM43 };
static char sRoom44[] = { TEXT_ROOM44 };
static char sRoom45[] = { TEXT_ROOM45 };
static char sRoom46[] = { TEXT_ROOM46 };
static char sRoom47[] = { TEXT_ROOM47 };
static char sRoom48[] = { TEXT_ROOM48 };
static char sRoom49[] = { TEXT_ROOM49 };
static char sRoom50[] = { TEXT_ROOM50 };
static char sRoom51[] = { TEXT_ROOM51 };
static char sRoom52[] = { TEXT_ROOM52 };
static char sRoom53[] = { TEXT_ROOM53 };
static char sRoom54[] = { TEXT_ROOM54 };
static char sRoom55[] = { TEXT_ROOM55 };
static char sRoom56[] = { TEXT_ROOM56 };
static char sRoom57[] = { TEXT_ROOM57 };
static char sRoom58[] = { TEXT_ROOM58 };
static char sRoom59[] = { TEXT_ROOM59 };
static char sRoom60[] = { TEXT_ROOM60 };
static char sRoom61[] = { TEXT_ROOM61 };
static char sRoom62[] = { TEXT_ROOM62 };
static char sRoom63[] = { TEXT_ROOM63 };
static char sRoom64[] = { TEXT_ROOM64 };
static char sRoom65[] = { TEXT_ROOM65 };
static char sRoom66[] = { TEXT_ROOM66 };
static char sRoom67[] = { TEXT_ROOM67 };
static char sRoom68[] = { TEXT_ROOM68 };
static char sRoom69[] = { TEXT_ROOM69 };
static char sRoom70[] = { TEXT_ROOM70 };
static char sRoom71[] = { TEXT_ROOM71 };
static char sRoom72[] = { TEXT_ROOM72 };
static char sRoom73[] = { TEXT_ROOM73 };
static char sRoom74[] = { TEXT_ROOM74 };



char sRoomCorrupt[] = { TEXT_CORRUPT };

char *sRoomNames[] = {
    sRoom1, sRoom2, sRoom3, sRoom4, sRoom5, sRoom6, sRoom7, sRoom8, sRoom9, sRoom10,
    sRoom11, sRoom12, sRoom13, sRoom14, sRoom15, sRoom16, sRoom17, sRoom18, sRoom19, sRoom20,
    sRoom21, sRoom21, sRoom23, sRoom21, sRoom21, sRoom26, sRoom27, sRoom28, sRoom29, sRoom30,
    sRoom31, sRoom32, sRoom33, sRoom34, sRoom35, sRoom36, sRoom37, sRoom38, sRoom37, sRoom40,
    sRoom41, sRoom42, sRoom42, sRoom44, sRoom44, sRoom46, sRoom46, sRoom48, sRoom49, sRoom50,
    sRoom51, sRoom52, sRoom53, sRoom54, sRoom55, sRoom56, sRoom57, sRoom58, sRoom58, sRoom60,
    sRoom61, sRoom62, sRoom63, sRoom63, sRoom65, sRoom66, sRoom67, sRoom68, sRoom69, sRoom70,
    sRoom71, sRoom72, sRoom73, sRoom74,
};

char *sPrevRoomName;


s32 gRoomEntryTimer = -1;

void print_name_string(s16 x, s16 y, u8 alpha, const u8 *str) {
    f32 scale = 1.5f;
    if (gIsConsole)
        scale = 2.0f;
    create_dl_ortho_matrix();
    create_dl_scale_matrix(MENU_MTX_NOPUSH, scale, scale, 1.0f);
    gSPDisplayList(gDisplayListHead++, dl_ia_text_begin);

    gDPSetEnvColor(gDisplayListHead++, 0, 0, 0, alpha);
    print_generic_string(x + 1, y - 1, str);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, alpha);
    print_generic_string(x, y, str);

    gSPDisplayList(gDisplayListHead++, dl_ia_text_end);
}


void print_room_names(void) {
    s16 y;
    if (gCurrCourseNum > COURSE_MAX || gCurrCourseNum < COURSE_MIN) {
        return;
    }
    if (gMarioCurrentRoom != gMarioPreviousRoom2) {
        gRoomEntryTimer = 0;
    }
    gMarioPreviousRoom2 = gMarioCurrentRoom;

    if (gRoomEntryTimer >= 0) {
        gRoomEntryTimer++;
        y = 255;
        if (gRoomEntryTimer < 25) {
            y = (gRoomEntryTimer * 10) + 5;
        } else if (gRoomEntryTimer < 65) {
            y = 255;
        } else {
            y = 255 - ((gRoomEntryTimer - 65) * 10);
        }

        if (gGlobalMarioRoom == 72) {
            print_name_string(15, 10, y, sRoomCorrupt);
        }
        if (sRoomNames[gGlobalMarioRoom - 1] != sPrevRoomName) {
            print_name_string(15, 10, y, sRoomNames[gGlobalMarioRoom - 1]);
        }
        if (gRoomEntryTimer >= 90) {
            gRoomEntryTimer = -1;
            sPrevRoomName = sRoomNames[gGlobalMarioRoom - 1];
        }
    }
    //print_text_fmt_int(20, 20, "%d", (gMarioCurrentRoom - 1) + sLevelRoomOffsets[gCurrCourseNum - 1], 0);
}


s32 gMultiplierUpper = 5;
s32 gMultiplierLower = 0;
s32 gMultiplierBool = 0;
s32 gMultiplierFlame = 0;
s16 gMultiplierAlpha = 0;
// s16 gMultiplierBool = 0;

void calc_multiplier(void) {
    s32 action = FALSE;
    if (gMarioState->action == ACT_BURNING_FALL || gMarioState->action == ACT_BURNING_JUMP 
        || gMarioState->action == ACT_BURNING_GROUND) {
        if (gMultiplierFlame == 0) {
            action = TRUE;
            gMultiplierFlame = 1;
        }
    } else {
        gMultiplierFlame = 0;
        action = FALSE;
    }
    if (((gMarioState->hurtCounter > 0 && gMultiplierBool == 0) || action) && gMultiplierUpper > 0) {
        if (gMultiplierLower == 0) {
            gMultiplierUpper -= 1;
            gMultiplierLower = 5;
        } else {
            gMultiplierLower = 0;
        }
        gMultiplierBool = 1;
    } else if (gMarioState->hurtCounter <= 0) {
        gMultiplierBool = 0;
    }
}


void print_multiplier_string(s32 boss) {
    u8 str[4];
    s16 x = 290;
    s16 y = 175 - 8;
    if (boss) {
        y += 20;
    }
    if (!gIsConsole) {
        y += 8;
    }
    str[0] = gMultiplierUpper;
    str[1] = 0x3F;
    str[2] = gMultiplierLower;
    str[3] = 0x3B;
    str[4] = 0xFF;

    create_dl_ortho_matrix();
    gSPDisplayList(gDisplayListHead++, dl_ia_text_begin);

    gDPSetEnvColor(gDisplayListHead++, 0, 0, 0, gMultiplierAlpha);
    print_generic_string(x + 1, y - 1, str);
    gDPSetEnvColor(gDisplayListHead++, 0x3b, 0xb3, 0x3b, gMultiplierAlpha);
    print_generic_string(x, y, str);

    gSPDisplayList(gDisplayListHead++, dl_ia_text_end);
}


void print_multiplier(void) {
    if (gHudDisplay.flags & HUD_DISPLAY_FLAG_MULTIPLIER) {
        // if (gMultiplierBool == FALSE) {

        //     gMultiplierBool = TRUE;
        // }
        if (gHudDisplay.flags & HUD_DISPLAY_FLAG_BOO) {
            print_multiplier_string(0);
        } else {
            print_multiplier_string(1);
        }
        gMultiplierAlpha = approach_s16_symmetric(gMultiplierAlpha, 255, 8);
        calc_multiplier();
    } else {
        gMultiplierUpper = 5;
        gMultiplierLower = 0;
        gMultiplierBool = 0;
        gMultiplierFlame = 0;
        // gMultiplierBool = FALSE;
        gMultiplierAlpha = approach_s16_symmetric(gMultiplierAlpha, 0, 8);
    }
}

/* 
    '^' = 0x50
    '|' = 0x51
    '<' = 0x52
    '>' = 0x53
*/

s16 gMirrorAlpha = 0;

void print_mirror_string(void) {
    u8 str1[2];
    u8 str2[2];
    u8 str3[2];
    u8 str4[2];
    s16 col1 = 0xFF, col2 = 0xFF, col3 = 0xFF, col4 = 0xFF;
    s16 x = 290;
    s16 y = 155 - 8;
    // f32 scale = 2.0f;
    if (!gIsConsole) {
        y += 8;
        // scale -= 0.5f;
    }
    str1[0] = 0x50;
    str2[0] = 0x51;
    str3[0] = 0x52;
    str4[0] = 0x53;

    str1[1] = 0xFF;
    str2[1] = 0xFF;
    str3[1] = 0xFF;
    str4[1] = 0xFF;
    create_dl_ortho_matrix();
    // create_dl_scale_matrix(MENU_MTX_NOPUSH, scale, scale, 1.0f);
    gSPDisplayList(gDisplayListHead++, dl_ia_text_begin);

    gDPSetEnvColor(gDisplayListHead++, 0, 0, 0, gMirrorAlpha);
    print_generic_string(x + 1, y - 1, str1);
    print_generic_string(x + 1, y - 20 - 1, str2);
    print_generic_string(x - 10 + 1, y - 10 - 1, str3);
    print_generic_string(x + 10 + 1, y - 10 - 1, str4);


    if (gMarioObject->platform != NULL) {
        if (gPlayer1Controller->buttonDown & U_JPAD || gPlayer1Controller->buttonDown & U_CBUTTONS) {
            col1 = 0;
        }
        if (gPlayer1Controller->buttonDown & D_JPAD || gPlayer1Controller->buttonDown & D_CBUTTONS) {
            col2 = 0;
        }
        if (gPlayer1Controller->buttonDown & L_JPAD || gPlayer1Controller->buttonDown & L_CBUTTONS) {
            col3 = 0;
        }
        if (gPlayer1Controller->buttonDown & R_JPAD || gPlayer1Controller->buttonDown & R_CBUTTONS) {
            col4 = 0;
        }
    }

    gDPSetEnvColor(gDisplayListHead++, col1, 0xFF, col1, gMirrorAlpha);
    print_generic_string(x, y, str1);

    gDPSetEnvColor(gDisplayListHead++, col2, 0xFF, col2, gMirrorAlpha);
    print_generic_string(x, y - 20, str2);

    gDPSetEnvColor(gDisplayListHead++, col3, 0xFF, col3, gMirrorAlpha);
    print_generic_string(x - 10, y - 10, str3);

    gDPSetEnvColor(gDisplayListHead++, col4, 0xFF, col4, gMirrorAlpha);
    print_generic_string(x + 10, y - 10, str4);

    gSPDisplayList(gDisplayListHead++, dl_ia_text_end);
}


void print_mirror_controls(void) {
    if (gCurrLevelNum == LEVEL_WF && gMarioCurrentRoom == 6) {
        if (gCamera->comitCutscene == 3) {
            gMirrorAlpha = approach_s16_symmetric(gMirrorAlpha, 255, 12);
        } else {
            gMirrorAlpha = approach_s16_symmetric(gMirrorAlpha, 0, 8);
        }
        if (gMirrorAlpha) {
            print_mirror_string();
        }
    }
}


void special_print(void) {
    if (gCurrDemoInput == NULL && gMenuOptSelectIndex != MENU_OPT_MAP) {
        print_room_names();
        print_multiplier();
        print_mirror_controls();
    }
}