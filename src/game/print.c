#include <ultra64.h>

#include "config.h"
#include "game_init.h"
#include "memory.h"
#include "print.h"
#include "segment2.h"
#include "!COMIT_LIBRARY.h"
#include "area.h"
#include "course_table.h"
/**
 * This file handles printing and formatting the colorful text that
 * appears when printing things such as "PRESS START".
 */

struct TextLabel {
    u32 x;
    u32 y;
    s16 length;
    char buffer[50];
    s8 palette;
};

/**
 * Stores the text to be rendered on screen
 * and how they are to be rendered.
 */
struct TextLabel *sTextLabels[52];
s16 sTextLabelsCount = 0;

/**
 * Returns n to the exponent power, only for non-negative powers.
 */
s32 int_pow(s32 n, s32 exponent) {
    s32 result = 1;
    s32 i;

    for (i = 0; i < exponent; i++) {
        result = n * result;
    }

    return result;
}

/**
 * Formats an integer n for print by fitting it to width, prefixing with a negative,
 * and converting the base.
 */
void format_integer(s32 n, s32 base, char *dest, s32 *totalLength, u8 width, s8 zeroPad) {
    u32 powBase;
    s32 numDigits = 0;
    s32 i;
    s32 len = 0;
    s8 digit;
    s8 negative = FALSE;
    char pad;

    if (zeroPad == TRUE) {
        pad = '0';
    } else {
        pad = -1;
    }

    if (n != 0) {
        // Formats a negative number for negative prefix.
        if (n < 0) {
            n = -n;
            negative = TRUE;
        }

        // Increments the number of digits until length is long enough.
        while (TRUE) {
            powBase = int_pow(base, numDigits);

            if (powBase > (u32) n) {
                break;
            }

            numDigits++;
        }

        // Add leading pad to fit width.
        if (width > numDigits) {
            for (len = 0; len < width - numDigits; len++) dest[len] = pad;

            // Needs 1 length to print negative prefix.
            if (negative == TRUE) {
                len--;
            }
        }

        // Use 'M' prefix to indicate negative numbers.
        if (negative == TRUE) {
            dest[len] = 'M';
            len++;
        }

        // Transfer the digits into the proper base.
        for (i = numDigits - 1; i >= 0; i--) {
            powBase = int_pow(base, i);
            digit = n / powBase;

            // FIXME: Why doesn't [] match?
            if (digit < 10) {
                *(dest + len + numDigits - 1 - i) = digit + '0';
            } else {
                *(dest + len + numDigits - 1 - i) = digit + '7';
            }

            n -= digit * powBase;
        }
    } else { // n is zero.
        numDigits = 1;
        if (width > numDigits) {
            for (len = 0; len < width - numDigits; len++) dest[len] = pad;
        }
        dest[len] = '0';
    }

    *totalLength += numDigits + len;
}

/**
 * Determines the width of the number for printing, writing to 'width'.
 * Additionally, this determines if a number should be zero-padded,
 * writing to 'zeroPad'.
 */
void parse_width_field(const char *str, s32 *srcIndex, u8 *width, s8 *zeroPad) {
    s8 digits[12]; // unknown length
    s8 digitsLen = 0;
    s16 i;

    // If first character is 0, then the string should be zero padded.
    if (str[*srcIndex] == '0') {
        *zeroPad = TRUE;
    }

    // Read width digits up until the 'd' or 'x' format specifier.
    while (str[*srcIndex] != 'd' && str[*srcIndex] != 'x') {
        digits[digitsLen] = str[*srcIndex] - '0';

        if (digits[digitsLen] < 0 || digits[digitsLen] >= 10) { // not a valid digit
            *width = 0;
            return;
        }

        digitsLen++;
        (*srcIndex)++;
    }

    // No digits
    if (digitsLen == 0) {
        return;
    }

    // Sum the digits to calculate the total width.
    for (i = 0; i < digitsLen - 1; i++) {
        *width = *width + digits[i] * ((digitsLen - i - 1) * 10);
    }

    *width = *width + digits[digitsLen - 1];
}

/**
 * Takes a number, finds the intended base, formats the number, and prints it
 * at the given X & Y coordinates.
 *
 * Warning: this fails on too large numbers, because format_integer has bugs
 * related to overflow. For romhacks, prefer sprintf + print_text.
 */
void print_text_fmt_int(s32 x, s32 y, const char *str, s32 n, s32 palette) {
    char c = 0;
    s8 zeroPad = FALSE;
    u8 width = 0;
    s32 base = 0;
    s32 len = 0;
    s32 srcIndex = 0;

    // Don't continue if there is no memory to do so.
    if ((sTextLabels[sTextLabelsCount] = mem_pool_alloc(gEffectsMemoryPool,
                                                        sizeof(struct TextLabel))) == NULL) {
        return;
    }

    sTextLabels[sTextLabelsCount]->x = x;
    sTextLabels[sTextLabelsCount]->y = y;

    c = str[srcIndex];

    while (c != 0) {
        if (c == '%') {
            srcIndex++;

            parse_width_field(str, &srcIndex, &width, &zeroPad);

            if (str[srcIndex] != 'd' && str[srcIndex] != 'x') {
                break;
            }
            if (str[srcIndex] == 'd') {
                base = 10;
            }
            if (str[srcIndex] == 'x') {
                base = 16;
            }

            srcIndex++;

            format_integer(n, base, sTextLabels[sTextLabelsCount]->buffer + len, &len, width, zeroPad);
        } else { // straight copy
            sTextLabels[sTextLabelsCount]->buffer[len] = c;
            len++;
            srcIndex++;
        }
        c = str[srcIndex];
    }

    sTextLabels[sTextLabelsCount]->length = len;
    sTextLabels[sTextLabelsCount]->palette = palette;
    

    sTextLabelsCount++;
}

/**
 * Prints text in the colorful lettering at given X, Y coordinates.
 */
void print_text(s32 x, s32 y, const char *str, s32 palette) {
    char c = 0;
    s32 length = 0;
    s32 srcIndex = 0;

    // Don't continue if there is no memory to do so.
    if ((sTextLabels[sTextLabelsCount] = mem_pool_alloc(gEffectsMemoryPool,
                                                        sizeof(struct TextLabel))) == NULL) {
        return;
    }

    sTextLabels[sTextLabelsCount]->x = x;
    sTextLabels[sTextLabelsCount]->y = y;

    c = str[srcIndex];

    // Set the array with the text to print while finding length.
    while (c != 0) {
        sTextLabels[sTextLabelsCount]->buffer[length] = c;
        length++;
        srcIndex++;
        c = str[srcIndex];
    }

    sTextLabels[sTextLabelsCount]->length = length;
    sTextLabels[sTextLabelsCount]->palette = palette;
    sTextLabelsCount++;
}

/**
 * Prints text in the colorful lettering centered at given X, Y coordinates.
 */
void print_text_centered(s32 x, s32 y, const char *str, s32 palette) {
    char c = 0;
    UNUSED s8 unused1 = 0;
    UNUSED s32 unused2 = 0;
    s32 length = 0;
    s32 srcIndex = 0;

    // Don't continue if there is no memory to do so.
    if ((sTextLabels[sTextLabelsCount] = mem_pool_alloc(gEffectsMemoryPool,
                                                        sizeof(struct TextLabel))) == NULL) {
        return;
    }

    c = str[srcIndex];

    // Set the array with the text to print while finding length.
    while (c != 0) {
        sTextLabels[sTextLabelsCount]->buffer[length] = c;
        length++;
        srcIndex++;
        c = str[srcIndex];
    }

    sTextLabels[sTextLabelsCount]->length = length;
    sTextLabels[sTextLabelsCount]->x = x - length * 12 / 2;
    sTextLabels[sTextLabelsCount]->y = y;
    sTextLabels[sTextLabelsCount]->palette = palette;
    sTextLabelsCount++;
}

/**
 * Converts a char into the proper colorful glyph for the char.
 */
s8 char_to_glyph_index(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c - 55;
    }

    if (c >= 'a' && c <= 'z') {
        return c - 87;
    }

    if (c >= '0' && c <= '9') {
        return c - 48;
    }

    if (c == ' ') {
        return GLYPH_SPACE;
    }

    if (c == '!') {
        return GLYPH_EXCLAMATION_PNT; // !, JP only
    }

    if (c == '#') {
        return GLYPH_TWO_EXCLAMATION; // !!, JP only
    }

    if (c == '?') {
        return GLYPH_QUESTION_MARK; // ?, JP only
    }

    if (c == '&') {
        return GLYPH_AMPERSAND; // &, JP only
    }

    if (c == '%') {
        return GLYPH_PERCENT; // %, JP only
    }

    if (c == '*') {
        return GLYPH_MULTIPLY; // x
    }

    if (c == '+') {
        return GLYPH_COIN; // coin
    }

    if (c == ',') {
        return GLYPH_MARIO_HEAD; // Imagine I drew Mario's head
    }
    

    if (c == '-') {
        return GLYPH_STAR; // star
    }

    if (c == '.') {
        return GLYPH_PERIOD; // large shaded dot, JP only
    }

    if (c == '/') {
        return GLYPH_BETA_KEY; // beta key, JP only. Reused for Ü in EU.
    }

    if (c == '{') {
        return GLYPH_GEAR;
    }

    if (c == '}') {
        return GLYPH_BOO;
    }

    if (c == '[') {
        return GLYPH_WHITE_STAR;
    }
    if (c == ']') {
        return GLYPH_PLUS_SIGN;
    }

    return GLYPH_SPACE;
}

/**
 * Adds an individual glyph to be rendered.
 */
void add_glyph_texture(s8 glyphIndex) {
    const u8 *const *glyphs = segmented_to_virtual(main_hud_lut);
    Gfx* dlhead = gDisplayListHead;

    gDPPipeSync(dlhead++);
    gDPSetTextureImage(dlhead++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, glyphs[glyphIndex]);
    gSPDisplayList(dlhead++, dl_hud_img_load_tex_block);
    gDisplayListHead = dlhead;
}

#ifndef WIDESCREEN
/**
 * Clips textrect into the boundaries defined.
 */
void clip_to_bounds(s32 *x, s32 *y) {
    if (*x < TEXRECT_MIN_X) {
        *x = TEXRECT_MIN_X;
    }

    if (*x > TEXRECT_MAX_X) {
        *x = TEXRECT_MAX_X;
    }

    if (*y < TEXRECT_MIN_Y) {
        *y = TEXRECT_MIN_Y;
    }

    if (*y > TEXRECT_MAX_Y) {
        *y = TEXRECT_MAX_Y;
    }
}
#endif

/**
 * Renders the glyph that's set at the given position.
 */
void render_textrect(s32 x, s32 y, s32 pos) {
    s32 rectBaseX = x + pos * 12;
    s32 rectBaseY = 224 - y;
    s32 rectX;
    s32 rectY;

//#ifndef WIDESCREEN
    // For widescreen we must allow drawing outside the usual area
    //clip_to_bounds(&rectBaseX, &rectBaseY);
//#endif
    rectX = rectBaseX;
    rectY = rectBaseY;
    gSPTextureRectangle(gDisplayListHead++, rectX << 2, rectY << 2, (rectX + 15) << 2,
                        (rectY + 15) << 2, G_TX_RENDERTILE, 0, 0, 4 << 10, 1 << 10);
}





struct HSV sTextPaletteGreen = {120, 0.667f, 0.706f};
struct HSV sTextPaletteRed = {0, 0.767f, 0.843f};
struct HSV sTextPaletteBlue = {240, 0.667f, 0.706f};
struct HSV sTextPaletteTeal = {185, 0.667f, 0.706f};
struct HSV sTextPaletteOrange = {24, 0.907f, 0.843f};
struct HSV sTextPalettePink = {309, 0.667f, 0.706f};
struct HSV sTextPaletteYellow = {60, 0.907f, 0.843f};
struct HSV sTextPaletteWhite = {0, 0.0f, 1.0f};
struct HSV sTextPaletteBrown = {30, 0.881f, 0.548f};

struct HSV *sTextPalettes[] = {
    &sTextPaletteGreen,
    &sTextPaletteRed,
    &sTextPaletteBlue,
    &sTextPaletteTeal,
    &sTextPaletteOrange,
    &sTextPalettePink,
    &sTextPaletteYellow,
    &sTextPaletteWhite,
    &sTextPaletteBrown,
};


// Vec3s sTextPalettes[] = {
//     {60, 180, 60}, // green
//     {215, 50, 50}, // red
//     {60, 60, 180}, // blue (purple)
//     {60, 170, 180}, // teal
//     {215, 98, 20}, // orange db620d (180, 115, 60)
//     {180, 60, 163}, // pink
// };

Vec3s sChapterStarPieceColors[5] = {
 {254, 254, 0},
 {254, 0, 0},
 {0, 254, 0},
 {254, 148, 0},
 {169, 0, 254},
};

extern s32 sLevelToChapter[COURSE_MAX];

s32 glyph_handle_special_palette(s8 glyphIndex, s16 *r, s16 *g, s16 *b) {
    s32 index;
    if ((glyphIndex >= GLYPH_COIN && glyphIndex <= GLYPH_BETA_KEY && glyphIndex != GLYPH_PERIOD) 
        || glyphIndex == GLYPH_GEAR || glyphIndex == GLYPH_BOO) {
        if (glyphIndex == GLYPH_COIN || glyphIndex == GLYPH_STAR) { // old: || glyphIndex == GLYPH_MARIO_HEAD
            *r = 255;
            *g = 205;
            *b = 70;
        } else if (glyphIndex == GLYPH_BETA_KEY) {
            *r = 210;
            *g = 210;
            *b = 210;  
        } else {
            *r = 255;
            *g = 255;
            *b = 255;
        }
        return TRUE;
    } else if (glyphIndex == GLYPH_TWO_EXCLAMATION) {
        index = sLevelToChapter[gCurrCourseNum] - 1;
        *r = sChapterStarPieceColors[index][0];
        *g = sChapterStarPieceColors[index][1];
        *b = sChapterStarPieceColors[index][2];
        return TRUE;
    } else {
        return FALSE;
    }
}

/**
 * Renders the text in sTextLabels on screen at the proper locations by iterating
 * a for loop.
 */
void render_text_labels(void) {
    s32 i;
    s32 j;
    s32 hue, palette;
    s16 r, g, b;
    s8 glyphIndex;
    Mtx *mtx;
    Gfx* dlhead = gDisplayListHead;

    if (sTextLabelsCount == 0) {
        return;
    }

    mtx = alloc_display_list(sizeof(*mtx));

    if (mtx == NULL) {
        sTextLabelsCount = 0;
        return;
    }

    guOrtho(mtx, 0.0f, SCREEN_WIDTH, 0.0f, SCREEN_HEIGHT, -10.0f, 10.0f, 1.0f);
    gSPPerspNormalize((Gfx *) (dlhead++), 0xFFFF);
    gSPMatrix(dlhead++, VIRTUAL_TO_PHYSICAL(mtx), G_MTX_PROJECTION | G_MTX_LOAD | G_MTX_NOPUSH);
    gSPDisplayList(dlhead++, dl_rgba16_text_begin);
    gDisplayListHead = dlhead;
    for (i = 0; i < sTextLabelsCount; i++) {
        palette = sTextLabels[i]->palette;
        for (j = 0; j < sTextLabels[i]->length; j++) {
            glyphIndex = char_to_glyph_index(sTextLabels[i]->buffer[j]);
            if (glyph_handle_special_palette(glyphIndex, &r, &g, &b)) {
                // gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, 255);
            } else {
                hue = sTextPalettes[palette]->hue - 12 + CL_RandomMinMaxU16Seeded(0, 24, j + palette);
                CL_HSVtoRGB(hue, sTextPalettes[palette]->sat, sTextPalettes[palette]->value, &r, &g, &b);
            }
            gDPSetEnvColor(gDisplayListHead++, r, g, b, 255);
            if (glyphIndex != GLYPH_SPACE) {
                add_glyph_texture(glyphIndex);
                render_textrect(sTextLabels[i]->x, sTextLabels[i]->y, j);
            }
        }

        mem_pool_free(gEffectsMemoryPool, sTextLabels[i]);
    }

    gSPDisplayList(gDisplayListHead++, dl_rgba16_text_end);

    sTextLabelsCount = 0;
}
