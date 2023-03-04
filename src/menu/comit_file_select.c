#include <PR/ultratypes.h>
#include <PR/gbi.h>

#include "audio/external.h"
#include "behavior_data.h"
#include "dialog_ids.h"
#include "engine/behavior_script.h"
#include "engine/graph_node.h"
#include "engine/math_util.h"
#include "file_select.h"
#include "game/area.h"
#include "game/game_init.h"
#include "game/ingame_menu.h"
#include "game/object_helpers.h"
#include "game/object_list_processor.h"
#include "game/print.h"
#include "game/save_file.h"
#include "game/segment2.h"
#include "game/segment7.h"
#include "game/spawn_object.h"
#include "game/rumble_init.h"
#include "sm64.h"
#include "text_strings.h"
#define o gCurrentObject

/* 

INITIAL STATE
    TOP TEXT: CHOOSE A FILE

    Display 3 Files Vertically
        Display Info on files:
            CHAPTER
            COINS
            PROGRESS %
            *MAYBE* PLAYTIME
            STARS ON FILE DENOTING COMPLETION (UP TO 5)
        Click file to load game
    
    COPY BUTTON

    ERASE BUTTON

    OPTIONS BUTTON

    CHALLENGES BUTTON


COPY STATE:
    COPY BUTTON GRAY OUT
    TOP TEXT CHANGES
    ASKS YOU TO PICK A FILE TO COPY
    TOP TEXT CHANGE AGAIN
    ASKS YOU TO PICK A FILE TO COPY TO
    SFX PLAYS, INITIAL STATE RETURNED


ERASE STATE:
    ERASE BUTTON FADE OUT
    TOP TEXT CHANGES
    PICK A FILE TO ERASE
    SFX PLAYS, INITIAL STATE RETURNED


OPTIONS STATE:
    FILES AND BUTTONS DISAPPEAR
    OPTIONS BUTTONS AND BACK BUTTON APPEAR

CHALLENGES STATE:
    ONLY APPEARS IF 1 CHALLENGE UNLOCKED
    FILES AND BUTTONS DISAPPEAR
    LIST OF CHALLENGE BUTTONS AND BACK BUTTON APPEAR


*/

extern struct SaveBuffer gSaveBuffer;
extern s16 sClickPos[];
extern s8 sSelectedFileNum;


static unsigned char sCSelectFile[] = { TEXT_SELECT_FILE };
static unsigned char sCMarioA[] = { TEXT_FILE_MARIO_A };
static unsigned char sCMarioB[] = { TEXT_FILE_MARIO_B };
static unsigned char sCMarioC[] = { TEXT_FILE_MARIO_C };
static u8 sCTextBaseAlpha = 0;

s16 sFileHeights[3] = {80, 32, -18};


s32 C_check_clicked_button(s16 x, s16 y, f32 depth) {
    f32 a = 52.4213;
    f32 newX = ((f32) x * 160.0) / (a * depth);
    f32 newY = ((f32) y * 120.0) / (a * 3 / 4 * depth);
    s16 maxX = newX + 25.0f;
    s16 minX = newX - 25.0f;
    s16 maxY = newY + 21.0f;
    s16 minY = newY - 21.0f;

    if (sClickPos[0] < maxX && minX < sClickPos[0] && sClickPos[1] < maxY && minY < sClickPos[1]) {
        return TRUE;
    }
    return FALSE;
}



s32 C_check_clicked_file_button(s16 y, f32 depth) {
    f32 a = 52.4213;
    // f32 newX = ((f32) x * 160.0) / (a * depth);
    f32 newY = ((f32) y * 120.0) / (a * 3 / 4 * depth);
    // s16 maxX = newX + 78.0f;
    // s16 minX = newX - 78.0f;
    s16 maxY = newY + 21.0f;
    s16 minY = newY - 21.0f;

    if (sClickPos[0] < 22  && -135 < sClickPos[0] && sClickPos[1] < y && (y - 40) < sClickPos[1]) {
        return TRUE;
    }
    return FALSE;
}


void bhv_cs_button_loop(void) {
    // if (!o->oBehParams2ndByte) {
    //     print_text_fmt_int(20, 80, "%d", sClickPos[0], 0);
    //     print_text_fmt_int(120, 80, "%d", sClickPos[1], 0);
    // }
    if (C_check_clicked_file_button(sFileHeights[o->oBehParams2ndByte], 200.0f)) {
        // play_puzzle_jingle();
        sSelectedFileNum = o->oBehParams2ndByte + 1;
        sClickPos[0] = -10000;
        sClickPos[1] = -10000;
    }
    // print_save_info(o->oBehParams2ndByte);
    // print_text_fmt_int(80, 80, "%d", (s32)o->oPosY, 0);
    // o->oPosX = -180;
    // o->oPosY = 180;
}


void bhv_cs_button_manager_init(void) {
    struct Object *obj;
    obj = spawn_object_abs_with_rot(o, 0, MODEL_FILE_BUTTON, bhvCSButton, -200, 190, 0, 0, 0, 0);
    obj = spawn_object_abs_with_rot(o, 0, MODEL_FILE_BUTTON, bhvCSButton, -200, 25, 0, 0, 0, 0);
    obj->oBehParams2ndByte = 1;
    obj = spawn_object_abs_with_rot(o, 0, MODEL_FILE_BUTTON, bhvCSButton, -200, -140, 0, 0, 0, 0);
    obj->oBehParams2ndByte = 2;
}

void print_file_chapter(s8 file, s16 x, s16 y) {
    unsigned char chapterNum[2];
    unsigned char textChapter[] = { TEXT_CHAPTER };
    // Print "[coin] x"
    print_generic_string(x, y, textChapter);
    // Print coin score
    int_to_str(get_chapter_from_save_data(file), chapterNum);
    print_generic_string(x + 40, y, chapterNum);
}


void print_file_coin_count(s8 file, s16 x, s16 y) {
    unsigned char coinScoreText[20];
    unsigned char textCoin[] = { TEXT_COIN };
    // Print "[coin] x"
    print_generic_string(x + 30, y, textCoin);
    // Print coin score
    int_to_str(gSaveBuffer.files[file][0].coinCount, coinScoreText);
    print_generic_string(x + 38, y, coinScoreText);
}



void print_save_info(s32 file) {
    unsigned char textMadeBy[] = { TEXT_MADEBY };
    unsigned char text2023[] = { TEXT_2023 };
    s16 xBase = 32;
    s16 yBase;
    // create_dl_ortho_matrix();
    // gSPDisplayList(gDisplayListHead++, dl_ia_text_begin);
    // gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, sCTextBaseAlpha);
    switch (file) {
        case 0:
            yBase = 175;
            print_generic_string(xBase, yBase, sCMarioA);
            break;
        case 1:
            yBase = 127;
            print_generic_string(xBase, yBase, sCMarioB);
            break;
        case 2:
            yBase = 79;
            print_generic_string(xBase, yBase, sCMarioC);
            break;
    }
    print_file_coin_count(file, xBase + 20, yBase);
    // gSPDisplayList(gDisplayListHead++, dl_menu_ia8_text_end);

    // gSPDisplayList(gDisplayListHead++, dl_ia_text_begin);
    // gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, sCTextBaseAlpha);
    print_file_chapter(file, xBase, yBase - 16);
    if (file == 0) {
        print_generic_string(220, 30, textMadeBy);
        print_generic_string(276, 16, text2023);
    }
    // gSPDisplayList(gDisplayListHead++, dl_ia_text_end);

}




void print_CF_strings(void) {
    // Print "SELECT FILE" text
    unsigned char textNewFile[] = { TEXT_NEWFILE };
    create_dl_ortho_matrix();
    gSPDisplayList(gDisplayListHead++, dl_rgba16_text_begin);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, sCTextBaseAlpha);
    print_hud_lut_string(HUD_LUT_DIFF, 93, 15, sCSelectFile);
    // print_text(93, 20, sCSelectFile, 0);

    // Print file star counts
    // print_save_file_star_count(SAVE_FILE_A, SAVEFILE_X1, 78);
    // print_save_file_star_count(SAVE_FILE_B, SAVEFILE_X2, 78);
    // print_save_file_star_count(SAVE_FILE_C, SAVEFILE_X1, 118);
    // print_save_file_star_count(SAVE_FILE_A, SAVEFILE_X2, 118);
    gSPDisplayList(gDisplayListHead++, dl_rgba16_text_end);


    // create_dl_ortho_matrix();
    gSPDisplayList(gDisplayListHead++, dl_ia_text_begin);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, sCTextBaseAlpha);
    if (save_file_exists(SAVE_FILE_A) == TRUE) {
        print_save_info(0);
    } else {
        // create_dl_scale_matrix(MENU_MTX_NOPUSH, 2.0f, 2.0f, 1.0f);
        // print_generic_string(80, 175 - 6, textNewFile);
        print_text(53, 175 - 6, "NEW FILE", 0);
    }

    if (save_file_exists(SAVE_FILE_B) == TRUE) {
        print_save_info(1);
    } else {
        // create_dl_scale_matrix(MENU_MTX_NOPUSH, 2.0f, 2.0f, 1.0f);
        // print_generic_string(80, 175 - 6, textNewFile);
        print_text(53, 127 - 6, "NEW FILE", 3);
    }

    if (save_file_exists(SAVE_FILE_C) == TRUE) {
        print_save_info(2);
    } else {
        // create_dl_scale_matrix(MENU_MTX_NOPUSH, 2.0f, 2.0f, 1.0f);
        // print_generic_string(80, 175 - 6, textNewFile);
        print_text(53, 79 - 6, "NEW FILE", 2);
    }

    gSPDisplayList(gDisplayListHead++, dl_ia_text_end);
    // Print menu names
    // gSPDisplayList(gDisplayListHead++, dl_ia_text_begin);
    // gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, sCTextBaseAlpha);
    // print_generic_string(SCORE_X, 39, textScore);
    // print_generic_string(COPY_X, 39, textCopy);
    // print_generic_string(ERASE_X, 39, textErase);
    // sSoundTextX = get_str_x_pos_from_center(254, textSoundModes[sSoundMode], 10.0f);
    // print_generic_string(SOUNDMODE_X1, 39, textSoundModes[sSoundMode]);
    // gSPDisplayList(gDisplayListHead++, dl_ia_text_end);

    // // Print file names
    // gSPDisplayList(gDisplayListHead++, dl_menu_ia8_text_begin);
    // gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, sCTextBaseAlpha);
    // print_menu_generic_string(32, 52, sCMarioA);
    // print_menu_generic_string(32, 100, sCMarioB);
    // print_menu_generic_string(32, 148, sCMarioC);
    // // print_menu_generic_string(MARIOTEXT_X2, 105, textMarioD);
    // gSPDisplayList(gDisplayListHead++, dl_menu_ia8_text_end);

    if (sCTextBaseAlpha < 250) {
        sCTextBaseAlpha += 10;
    }
}









void bhv_cs_bg_init(void) {
    gCurrentObject->oFaceAngleYaw = 0x8000;
    gCurrentObject->oMenuButtonScale = 9.0f;
}

/**
 * Yellow Background Menu Loop Action
 * Properly scales the background in the main menu.
 */
void bhv_cs_bg_loop(void) {
    cur_obj_scale(9.0f);
}



