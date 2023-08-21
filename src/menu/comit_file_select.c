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
#include "seq_ids.h"
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
extern f32 sCursorPos[];
extern s8 sSelectedFileNum;


static unsigned char sCSelectFile[] = { TEXT_SELECT_FILE };
static unsigned char sCMarioA[] = { TEXT_FILE_MARIO_A };
static unsigned char sCMarioB[] = { TEXT_FILE_MARIO_B };
static unsigned char sCMarioC[] = { TEXT_FILE_MARIO_C };
static u8 sCTextBaseAlpha = 0;

s16 sFileHeights[3] = {80, 32, -18};
s16 sCFMode = 0;

s16 sOptionsHeights[3] = {90, 35, -20};

s16 sChallengeHeights[5] = {90, 50, 20, -15, -45};

enum CFModes {
    CF_NORMAL = 0,
    CF_ERASE  = 1,
    CF_COPY1 = 2,
    CF_COPY2 = 3,
    CF_OPTIONS = 4,
    CF_CHALLENGES = 5
};


s32 C_check_clicked_button(s16 maxX, s16 minX, s16 y, f32 yScale, f32 depth) {
    s32 yRange = (40 * yScale);

    if (sClickPos[0] < maxX  && minX < sClickPos[0] && sClickPos[1] < y && (y - yRange) < sClickPos[1]) {
        return TRUE;
    }
    return FALSE;
}



// s32 C_check_clicked_file_button(s16 y, f32 depth) {
//     f32 a = 52.4213;
//     // f32 newX = ((f32) x * 160.0) / (a * depth);
//     f32 newY = ((f32) y * 120.0) / (a * 3 / 4 * depth);
//     // s16 maxX = newX + 78.0f;
//     // s16 minX = newX - 78.0f;
//     s16 maxY = newY + 21.0f;
//     s16 minY = newY - 21.0f;

//     if (sClickPos[0] < 22  && -135 < sClickPos[0] && sClickPos[1] < y && (y - 40) < sClickPos[1]) {
//         return TRUE;
//     }
//     return FALSE;
// }

extern s32 sShouldRenderCursor;
extern s32 gIsChallenge;


void bhv_cs_challenge_button_loop(void) {
    s32 sensitivity;

    // if (!o->oBehParams2ndByte) {
    //     print_text_fmt_int(20, 90, "%d", sClickPos[0], 0);
    //     print_text_fmt_int(120, 90, "%d", sClickPos[1], 0);
    // }

    if (sCursorPos[0] < 80 && sCursorPos[0] > -132 && sCursorPos[1] < sChallengeHeights[o->oBehParams2ndByte]
        && sCursorPos[1] > sChallengeHeights[o->oBehParams2ndByte] - 30) {
            o->header.gfx.scale[0] = approach_f32_symmetric(o->header.gfx.scale[0], 1.575f, 0.009375f);
            o->header.gfx.scale[1] = approach_f32_symmetric(o->header.gfx.scale[1], 0.735f, 0.004375f);
        } else {
            o->header.gfx.scale[0] = approach_f32_symmetric(o->header.gfx.scale[0], 1.5f, 0.009375f);
            o->header.gfx.scale[1] = approach_f32_symmetric(o->header.gfx.scale[1], 0.7f, 0.004375f);
        }

    if (C_check_clicked_button(80, -132, sChallengeHeights[o->oBehParams2ndByte], o->header.gfx.scale[1], 200.0f)) {
        // play_puzzle_jingle();
        // sSelectedFileNum = o->oBehParams2ndByte + 1;
        play_sound(SOUND_MENU_CLICK_FILE_SELECT, gGlobalSoundSource);
        sSelectedFileNum = 1;
        play_sound(SOUND_MENU_STAR_SOUND, gGlobalSoundSource);
        sShouldRenderCursor = FALSE;
        gIsChallenge = o->oBehParams2ndByte + 1;


        sClickPos[0] = -10000;
        sClickPos[1] = -10000;
    }
}


void bhv_cs_options_button_init(void) {

}


void bhv_cs_options_button_loop(void) {
    s32 sensitivity;
    if (sCursorPos[0] < 32 && sCursorPos[0] > -92 && sCursorPos[1] < sOptionsHeights[o->oBehParams2ndByte]
        && sCursorPos[1] > sOptionsHeights[o->oBehParams2ndByte] - 45) {
            o->header.gfx.scale[0] = approach_f32_symmetric(o->header.gfx.scale[0], 0.84f, 0.005f);
            o->header.gfx.scale[1] = approach_f32_symmetric(o->header.gfx.scale[1], 1.26f, 0.0075f);
        } else {
            o->header.gfx.scale[0] = approach_f32_symmetric(o->header.gfx.scale[0], 0.8f, 0.005f);
            o->header.gfx.scale[1] = approach_f32_symmetric(o->header.gfx.scale[1], 1.2f, 0.0075f);
        }

    if (C_check_clicked_button(32, -92, sOptionsHeights[o->oBehParams2ndByte], o->header.gfx.scale[1], 200.0f)) {
        // play_puzzle_jingle();
        // sSelectedFileNum = o->oBehParams2ndByte + 1;
        play_sound(SOUND_MENU_CLICK_FILE_SELECT, gGlobalSoundSource);
        switch (o->oBehParams2ndByte) {
            case 0:
                save_file_set_options(SAVE_OPTION_MUSIC);
                break;
            case 1:
                save_file_set_options(SAVE_OPTION_TRACKER);
                break;
            case 2:
                sensitivity = save_file_get_sensitivity();
                if (sensitivity < 5) {
                    sensitivity++;
                } else {
                    sensitivity = 1;
                }
                save_file_set_sensitivity(sensitivity);
                break;
        }


        sClickPos[0] = -10000;
        sClickPos[1] = -10000;
    }
}


void bhv_cs_challenges_button_loop(void) {
    struct Object *obj;
    if (cur_obj_nearest_object_with_behavior(bhvCSErasePrompt) != NULL) {
        return;
    }
    if (sCFMode == CF_OPTIONS) {
        cur_obj_hide();
        return;
    } else {
        cur_obj_unhide();
    }

    if (sCursorPos[0] < 0 && sCursorPos[1] < -70) {
            o->header.gfx.scale[0] = approach_f32_symmetric(o->header.gfx.scale[0], 1.05f, 0.00625);
            o->header.gfx.scale[1] = approach_f32_symmetric(o->header.gfx.scale[1], o->oFloatF8 * 1.15f, o->oFloatFC);
        } else {
            o->header.gfx.scale[0] = approach_f32_symmetric(o->header.gfx.scale[0], 1.0f, 0.00625f);
            o->header.gfx.scale[1] = approach_f32_symmetric(o->header.gfx.scale[1], o->oFloatF8, o->oFloatFC);
        }

    if (sClickPos[0] < 0 && sClickPos[0] > -500 && sClickPos[1] < -70) {
        // play_puzzle_jingle();
        // sSelectedFileNum = o->oBehParams2ndByte + 1;
        play_sound(SOUND_MENU_CLICK_FILE_SELECT, gGlobalSoundSource);
        if (sCFMode != CF_CHALLENGES) {
            sCFMode = CF_CHALLENGES;
            obj = spawn_object_abs_with_rot(o, 0, MODEL_FILE_BUTTON, bhvCSChallengeButton, -100, 240, 0, 0, 0, 0);
            obj->header.gfx.scale[0] = 1.5f;
            obj->header.gfx.scale[1] = 0.7f;
            obj = spawn_object_abs_with_rot(o, 0, MODEL_FILE_BUTTON, bhvCSChallengeButton, -100, 125, 0, 0, 0, 0);
            obj->header.gfx.scale[0] = 1.5f;
            obj->header.gfx.scale[1] = 0.7f;
            obj->oBehParams2ndByte = 1;
            obj = spawn_object_abs_with_rot(o, 0, MODEL_FILE_BUTTON, bhvCSChallengeButton, -100, 10, 0, 0, 0, 0);
            obj->header.gfx.scale[0] = 1.5f;
            obj->header.gfx.scale[1] = 0.7f;
            obj->oBehParams2ndByte = 2;
            obj = spawn_object_abs_with_rot(o, 0, MODEL_FILE_BUTTON, bhvCSChallengeButton, -100, -105, 0, 0, 0, 0);
            obj->header.gfx.scale[0] = 1.5f;
            obj->header.gfx.scale[1] = 0.7f;
            obj->oBehParams2ndByte = 3;
            obj = spawn_object_abs_with_rot(o, 0, MODEL_FILE_BUTTON, bhvCSChallengeButton, -100, -220, 0, 0, 0, 0);
            obj->header.gfx.scale[0] = 1.5f;
            obj->header.gfx.scale[1] = 0.7f;
            obj->oBehParams2ndByte = 4;
        } else {
            sCFMode = CF_NORMAL;
            while ((obj = cur_obj_nearest_object_with_behavior(bhvCSChallengeButton)) != NULL) {
                obj->activeFlags = 0;
            }
        }


        sClickPos[0] = -10000;
        sClickPos[1] = -10000;
    }

    if (o->oBehParams2ndByte == 0) {
        if (sCFMode == CF_COPY1) {

        }
    }


}








void bhv_cs_side_button_loop(void) {
    struct Object *obj;
    s32 subtract = (40 - (40 * o->header.gfx.scale[1])) / 2; 
    s32 minX = o->oBehParams2ndByte == 2 ? 125 : 85;
    if (cur_obj_nearest_object_with_behavior(bhvCSErasePrompt) != NULL) {
        return;
    }
    if (sCFMode >= CF_OPTIONS && o->oBehParams2ndByte != 2) {
        cur_obj_hide();
        return;
    } else if (o->oBehParams2ndByte == 2 && sCFMode == CF_CHALLENGES) {
        cur_obj_hide();
        return;
    } else {
        cur_obj_unhide();
    }

    if (sCursorPos[0] < 200 && sCursorPos[0] > minX && sCursorPos[1] < sFileHeights[o->oBehParams2ndByte] - subtract
        && sCursorPos[1] > sFileHeights[o->oBehParams2ndByte] - (40 - o->header.gfx.scale[1])) {
            o->header.gfx.scale[0] = approach_f32_symmetric(o->header.gfx.scale[0], 1.05f, 0.00625);
            o->header.gfx.scale[1] = approach_f32_symmetric(o->header.gfx.scale[1], o->oFloatF8 * 1.15f, o->oFloatFC);
        } else {
            o->header.gfx.scale[0] = approach_f32_symmetric(o->header.gfx.scale[0], 1.0f, 0.00625f);
            o->header.gfx.scale[1] = approach_f32_symmetric(o->header.gfx.scale[1], o->oFloatF8, o->oFloatFC);
        }

    if (C_check_clicked_button(200, minX, sFileHeights[o->oBehParams2ndByte] - subtract, o->header.gfx.scale[1], 200.0f)) {
        // play_puzzle_jingle();
        // sSelectedFileNum = o->oBehParams2ndByte + 1;
        play_sound(SOUND_MENU_CLICK_FILE_SELECT, gGlobalSoundSource);
        switch (o->oBehParams2ndByte) {
            case 0:
                if (sCFMode != CF_COPY1 && sCFMode != CF_COPY2) {
                    sCFMode = CF_COPY1;
                } else {
                    sCFMode = CF_NORMAL;
                }
                break;
            case 1:
                if (sCFMode != CF_ERASE) {
                    sCFMode = CF_ERASE;
                } else {
                    sCFMode = CF_NORMAL;
                }
                break;
            case 2:
                if (sCFMode != CF_OPTIONS) {
                    sCFMode = CF_OPTIONS;
                    obj = spawn_object_abs_with_rot(o, 0, MODEL_FILE_BUTTON, bhvCSOptionsButton, -100, 210, 0, 0, 0, 0);
                    obj->header.gfx.scale[0] = 0.8f;
                    obj->header.gfx.scale[1] = 1.2f;
                    obj = spawn_object_abs_with_rot(o, 0, MODEL_FILE_BUTTON, bhvCSOptionsButton, -100, 25, 0, 0, 0, 0);
                    obj->header.gfx.scale[0] = 0.8f;
                    obj->header.gfx.scale[1] = 1.2f;
                    obj->oBehParams2ndByte = 1;
                    obj = spawn_object_abs_with_rot(o, 0, MODEL_FILE_BUTTON, bhvCSOptionsButton, -100, -160, 0, 0, 0, 0);
                    obj->header.gfx.scale[0] = 0.8f;
                    obj->header.gfx.scale[1] = 1.2f;
                    obj->oBehParams2ndByte = 2;
                } else {
                    sCFMode = CF_NORMAL;
                    while ((obj = cur_obj_nearest_object_with_behavior(bhvCSOptionsButton)) != NULL) {
                        obj->activeFlags = 0;
                    }
                }
                break;
        }


        sClickPos[0] = -10000;
        sClickPos[1] = -10000;
    }

    if (o->oBehParams2ndByte == 0) {
        if (sCFMode == CF_COPY1) {

        }
    }


}

void bhv_erase_prompt_loop(void) {
    if (sClickPos[1] <= 18 && sClickPos[1] >= -8) {
        if (sClickPos[0] <= 80 && sClickPos[0] >= 56) {
            play_sound(SOUND_MARIO_WAAAOOOW, gGlobalSoundSource);
            play_sound(SOUND_MENU_CLICK_FILE_SELECT, gGlobalSoundSource);
            save_file_erase(o->oBehParams2ndByte);
            sCFMode = CF_NORMAL;
            o->activeFlags = 0;
        }

        if (sClickPos[0] <= 122 && sClickPos[0] >= 100) {
            play_sound(SOUND_MENU_CLICK_FILE_SELECT, gGlobalSoundSource);
            o->activeFlags = 0;
        }
    }
}


void bhv_cs_sub_button_loop(void) {
    if (o->oPosX == o->oHomeX) {
        cur_obj_hide();
    } else {
        cur_obj_unhide();
    }
    if (o->oF4 == 0) {
        o->oPosX = approach_f32_symmetric(o->oPosX, o->oHomeX, 20.0f);
    } else {
        o->oPosX = approach_f32_symmetric(o->oPosX, o->oHomeX + 350.0f, 25.0f);
    }
}


void bhv_cs_button_init(void) {
    o->oObjF8 = spawn_object_abs_with_rot(o, 0, MODEL_FILE_BUTTON, bhvCSSubButton, -255, (s16)o->oPosY, -10, 0, 0, 0);
    // o->oObjF8->header.gfx.scale[1] = 0.8f;
    o->oObjF8->header.gfx.scale[0] = 0.7f;
    o->oObjF8->oBehParams2ndByte = o->oBehParams2ndByte;
}

void bhv_cs_button_loop(void) {
    struct Object *obj;
    if (sCFMode >= CF_OPTIONS) {
        cur_obj_hide();
        return;
    } else {
        cur_obj_unhide();
    }
    // if (!o->oBehParams2ndByte) {
    //     print_text_fmt_int(20, 90, "%d", sClickPos[0], 0);
    //     print_text_fmt_int(120, 90, "%d", sClickPos[1], 0);
    // }
    if (cur_obj_nearest_object_with_behavior(bhvCSErasePrompt) != NULL) {
        return;
    }

    // if (sCFMode == CF_NORMAL) {
    if (sCursorPos[0] < -14 && sCursorPos[1] < sFileHeights[o->oBehParams2ndByte] 
        && sCursorPos[1] > sFileHeights[o->oBehParams2ndByte] - 40) {
            if (sCFMode == CF_NORMAL && save_file_exists(o->oBehParams2ndByte)) {
                o->oObjF8->oF4 = 1;
            }
            o->header.gfx.scale[0] = approach_f32_symmetric(o->header.gfx.scale[0], 0.88f, 0.01f);
            o->header.gfx.scale[1] = approach_f32_symmetric(o->header.gfx.scale[1], 1.1f, 0.0125f);
        } else {
            o->oObjF8->oF4 = 0;
            o->header.gfx.scale[0] = approach_f32_symmetric(o->header.gfx.scale[0], 0.8f, 0.01f);
            o->header.gfx.scale[1] = approach_f32_symmetric(o->header.gfx.scale[1], 1.0f, 0.0125f);
        }
    // }

    if (C_check_clicked_button(-14, -135, sFileHeights[o->oBehParams2ndByte], o->header.gfx.scale[1], 200.0f)) {
        // play_puzzle_jingle();
        switch (sCFMode) {
            case CF_NORMAL:
                sSelectedFileNum = o->oBehParams2ndByte + 1;
                play_sound(SOUND_MENU_STAR_SOUND, gGlobalSoundSource);
                sShouldRenderCursor = FALSE;
                break;
            case CF_ERASE:
                if (save_file_exists(o->oBehParams2ndByte)) {
                    obj = spawn_object_abs_with_rot(o, 0, MODEL_FILE_BUTTON, bhvCSErasePrompt, 0, 0, 500, 0, 0, 0);
                    obj->oBehParams2ndByte = o->oBehParams2ndByte;
                    obj->header.gfx.scale[1] = 0.35f;
                    obj->header.gfx.scale[0] = 1.2f;
                    play_sound(SOUND_MENU_CLICK_FILE_SELECT, gGlobalSoundSource);
                } else {
                    play_sound(SOUND_MENU_CAMERA_BUZZ, gGlobalSoundSource);
                }
                break;
            case CF_COPY1:
                if (save_file_exists(o->oBehParams2ndByte)) {
                    obj = CL_nearest_object_with_behavior_and_field(bhvCSSideButton, 0x144, 0);
                    if (obj != NULL) {
                        obj->os16F4 = o->oBehParams2ndByte;
                    }
                    play_sound(SOUND_MENU_CLICK_FILE_SELECT, gGlobalSoundSource);
                    sCFMode = CF_COPY2;
                } else {
                    play_sound(SOUND_MENU_CAMERA_BUZZ, gGlobalSoundSource);
                }
                break;
            case CF_COPY2:
                obj = CL_nearest_object_with_behavior_and_field(bhvCSSideButton, 0x144, 0);
                if (obj != NULL) {
                    play_sound(SOUND_MENU_STAR_SOUND, gGlobalSoundSource);
                    save_file_copy(obj->os16F4, o->oBehParams2ndByte);
                    obj->os16F4 = 0;
                }
                sCFMode = CF_NORMAL;
                break;
        }
        sClickPos[0] = -10000;
        sClickPos[1] = -10000;
    }
    // if (o->oF4) {
    //     print_erase_menu_prompt(90, 190);
    // }
    // print_save_info(o->oBehParams2ndByte);
    // print_text_fmt_int(80, 80, "%d", (s32)o->oPosY, 0);
    // o->oPosX = -180;
    // o->oPosY = 180;
}


void bhv_cs_button_manager_init(void) {
    struct Object *obj;
    obj = spawn_object_abs_with_rot(o, 0, MODEL_FILE_BUTTON, bhvCSButton, -255, 190, 0, 0, 0, 0);
    obj->header.gfx.scale[0] = 0.8f;
    obj = spawn_object_abs_with_rot(o, 0, MODEL_FILE_BUTTON, bhvCSButton, -255, 25, 0, 0, 0, 0);
    obj->header.gfx.scale[0] = 0.8f;
    obj->oBehParams2ndByte = 1;
    obj = spawn_object_abs_with_rot(o, 0, MODEL_FILE_BUTTON, bhvCSButton, -255, -140, 0, 0, 0, 0);
    obj->header.gfx.scale[0] = 0.8f;
    obj->oBehParams2ndByte = 2;

    obj = spawn_object_abs_with_rot(o, 0, MODEL_FILE_BUTTON, bhvCSSideButton, 560, 190, 0, 0, 0, 0);
    obj->header.gfx.scale[1] = 0.8f;
    obj->oFloatF8 = obj->header.gfx.scale[1];
    obj->oFloatFC = ((obj->oFloatF8 * 1.15f) - obj->oFloatF8) / 8.0f;
    obj = spawn_object_abs_with_rot(o, 0, MODEL_FILE_BUTTON, bhvCSSideButton, 560, 25, 0, 0, 0, 0);
    obj->oBehParams2ndByte = 1;
    obj->header.gfx.scale[1] = 0.8f;
    obj->oFloatF8 = obj->header.gfx.scale[1];
    obj->oFloatFC = ((obj->oFloatF8 * 1.15f) - obj->oFloatF8) / 8.0f;
    obj = spawn_object_abs_with_rot(o, 0, MODEL_FILE_BUTTON, bhvCSSideButton, 708, -140, 0, 0, 0, 0);
    obj->oBehParams2ndByte = 2;
    obj->header.gfx.scale[1] = 0.6f;
    obj->oFloatF8 = obj->header.gfx.scale[1];
    obj->oFloatFC = ((obj->oFloatF8 * 1.15f) - obj->oFloatF8) / 8.0f;


    obj = spawn_object_abs_with_rot(o, 0, MODEL_FILE_BUTTON, bhvCSChallenges, -245, -355, 0, 0, 0, 0);
    obj->oBehParams2ndByte = 3;
    obj->header.gfx.scale[1] = 0.9f;
    // obj->header.gfx.scale[0] = 1.1f;
    obj->oFloatF8 = obj->header.gfx.scale[1];
    obj->oFloatFC = ((obj->oFloatF8 * 1.15f) - obj->oFloatF8) / 8.0f;
}


s16 sSubInfoAlpha[3] = {0, 0, 0};



void print_play_time(s8 file, s16 x, s16 y) {
    unsigned char hoursText[10];
    unsigned char minsText[3];
    unsigned char secsText[3];
    unsigned char milisText[3];
    unsigned char timeSting[25];
    s32 i = 0;
    s32 time = gSaveBuffer.files[file][0].ingameTime;
    s32 hours, minutes, seconds;
    hours = time / 108000;
    time %= 108000;
    minutes = time / 1800;
    time %= 1800;
    seconds = time / 30;
    time = (f32)((time % 30) / 30.0f) * 100;


    int_to_str(hours, hoursText);
    int_to_str(minutes, minsText);
    int_to_str(seconds, secsText);
    int_to_str(time, milisText);

    while (hoursText[i] != 0xFF) {
        timeSting[i] = hoursText[i];
        i++;
    }

    timeSting[i++] = 0xE6;

    if (minsText[1] == 0xFF) {
        timeSting[i++] = 0;
        timeSting[i++] = minsText[0];
    } else {
        timeSting[i++] = minsText[0];
        timeSting[i++] = minsText[1];
    }

    timeSting[i++] = 0xE6;

    if (secsText[1] == 0xFF) {
        timeSting[i++] = 0;
        timeSting[i++] = secsText[0];
    } else {
        timeSting[i++] = secsText[0];
        timeSting[i++] = secsText[1];
    }

    timeSting[i++] = 0x3F;

    if (milisText[1] == 0xFF) {
        timeSting[i++] = 0;
        timeSting[i++] = milisText[0];
    } else {
        timeSting[i++] = milisText[0];
        timeSting[i++] = milisText[1];
    }
    timeSting[i] = 0xFF;

    print_generic_string(x, y, timeSting);
    // print_generic_string(x + 40, y - 16, minsText);
    // print_generic_string(x + 40, y - 32, secsText);
    // print_generic_string(x + 40, y - 48, milisText);
    // print_text_fmt_int(80, 80, "%x", (s16)secsText[0], 1);
    // print_text_fmt_int(80, 50, "%x", (s16)secsText[1], 1);
    // print_text_fmt_int(80, 20, "%x", (s16)secsText[2], 1);
}

void print_file_chapter(s8 file, s16 x, s16 y) {
    unsigned char chapterNum[2];
    unsigned char textChapter[] = { TEXT_CHAPTER };
    unsigned char textComplete[] = { TEXT_COMPLETE };
    if (gSaveBuffer.files[file][0].finalRank) {
        print_generic_string(x, y, textComplete);
    } else {
        // Print "[coin] x"
        print_generic_string(x, y, textChapter);
        // Print coin score
        int_to_str(get_chapter_from_save_data(file), chapterNum);
        print_generic_string(x + 40, y, chapterNum);
    }
}

extern s8 sRankToPalette[7];



const char sFRank[] = {
    'F',
    0xFF
};

const char sERank[] = {
    'E',
    0xFF
};

const char sDRank[] = {
    'D',
    0xFF
};

const char sCRank[] = {
    'C',
    0xFF
};

const char sBRank[] = {
    'B',
    0xFF
};

const char sARank[] = {
    'A',
    0xFF
};

const char sSRank[] = {
    'S',
    0xFF
};

const char *sRanks[14] = {
    sFRank,
    sERank,
    sDRank,
    sCRank,
    sBRank,
    sARank,
    sSRank,
};

void print_file_coin_count(s8 file, s16 x, s16 y) {
    // unsigned char coinScoreText[20];
    // unsigned char textCoin[] = { TEXT_COIN };
    // // Print "[coin] x"
    // print_generic_string(x + 30, y, textCoin);
    // // Print coin score
    // int_to_str(gSaveBuffer.files[file][0].coinCount, coinScoreText);
    // print_generic_string(x + 38, y, coinScoreText);
    s8 rankOffset = 0;
    s8 rank = gSaveBuffer.files[file][0].finalRank;
    s32 coins = gSaveBuffer.files[file][0].coinCount;
    s32 subtract = (coins > 9999 || rank) ? 14 : 0;

    if (rank) {
        rankOffset = 8;
        print_text(x - 14, y + rankOffset, sRanks[rank - 1], sRankToPalette[rank - 1]);
    }


    if (coins < 100000) {
        print_text(x - subtract, y - rankOffset, "+", 0); // 'Coin' glyph
        print_text(x + 16 - subtract, y - rankOffset, "*", 7); // 'X' glyph
        print_text_fmt_int(x + 30 - subtract, y - rankOffset, "%d", coins, 7);
    } else {
        print_text(x - subtract, y - rankOffset, "+", 0); // 'Coin' glyph
        // print_text(x + 16 - subtract, y, "*", 7); // 'X' glyph
        print_text_fmt_int(x + 16 - subtract, y - rankOffset, "%d", coins, 7);
    }
}

//1 star for all boos
//1 star for all star pieces
//1 star for all reds stars
//2 stars for S rank (1 for A)

s32 get_save_file_stars(s32 file) {
    s32 stars = 0;
    s32 rank = gSaveBuffer.files[file][0].finalRank;
    if (rank >= SAVE_RANK_A) {
        stars++;
    }
    if (rank == SAVE_RANK_S) {
        stars++;
    }
    // if (CL_count_bits(0b1111111111111111111111111) >= 25) {
    if (CL_count_bits(gSaveBuffer.files[file][0].boosCaptured) >= 25) {
        stars++;
    }

    if (CL_count_bits(gSaveBuffer.files[file][0].starPieces & 0x1FFFFFF) >= 25) {
        stars++;
    }

    if (CL_count_bits((gSaveBuffer.files[file][0].starPieces & 0xE0000000) >> 29) >= 3) {
        stars++;
    }

    return stars;
}

void print_file_completion_stars(s8 file, s16 x, s16 y) {
    s32 i;
    s32 stars = get_save_file_stars(file);
    s32 xAdd = 68;

    for (i = 0; i < stars; i++, xAdd -= 14) {
        print_text(x + xAdd, y + 8, "[", 7);
    }
}

void print_file_sub_info(s8 file, s16 x, s16 y) {
    struct Object *obj = CL_nearest_object_with_behavior_and_field(bhvCSSubButton, 0x144, file);
    if (obj == NULL) {
        if (cur_obj_has_behavior(bhvCSSubButton)) {
            obj = o;
        }
    }
    if (obj != NULL) {
        if (obj->oF4 == 1 && obj->oPosX >= obj->oHomeX + 200.0f) {
            sSubInfoAlpha[file] = approach_s16_symmetric(sSubInfoAlpha[file], 255, 20);
        } else if (obj->oF4 == 0 && obj->oPosX <= obj->oHomeX + 300.0f){
            sSubInfoAlpha[file] = approach_s16_symmetric(sSubInfoAlpha[file], 0, 75);
        }
        if (sSubInfoAlpha[file] > 10) {
            print_file_chapter(file, x, y + 8);
            print_play_time(file, x, y - 8);
        }
    }
}

void print_save_info(s32 file) {
    s16 xBase = 32;
    s16 yBase;
    // create_dl_ortho_matrix();
    // gSPDisplayList(gDisplayListHead++, dl_ia_text_begin);
    // gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, sCTextBaseAlpha);
    switch (file) {
        case 0:
            yBase = 175 - 7;
            print_text(xBase - 2, yBase, "A", 0);
            // print_generic_string(xBase, yBase, sCMarioA);
            break;
        case 1:
            yBase = 127 - 7;
            print_text(xBase - 2, yBase, "B", 3);
            // print_generic_string(xBase, yBase, sCMarioB);
            break;
        case 2:
            yBase = 79 - 7;
            print_text(xBase - 2, yBase, "C", 2);
            // print_generic_string(xBase, yBase, sCMarioC);
            break;
    }
    print_file_coin_count(file, xBase + 30, yBase);
    if (gSaveBuffer.files[file][0].finalRank) {
        print_file_completion_stars(file, xBase + 30, yBase);
    }
    // gSPDisplayList(gDisplayListHead++, dl_menu_ia8_text_end);

    // gSPDisplayList(gDisplayListHead++, dl_ia_text_begin);
    // gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, sCTextBaseAlpha);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, sSubInfoAlpha[file]);
    print_file_sub_info(file, xBase + 125, yBase);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, sCTextBaseAlpha);
    // print_file_chapter(file, xBase, yBase - 16);
    // gSPDisplayList(gDisplayListHead++, dl_ia_text_end);

}


void print_erase_prompt(void) {
    unsigned char areYouSure[] = { TEXT_AREYOUSURE };
    print_generic_string(44, 112, areYouSure);
}


void print_top_text(s32 mode) {
    switch (mode) {
        case CF_NORMAL:
            print_text(90, 225 - 15, "SELECT FILE", 7);
            break;
        case CF_ERASE:
            print_text(40, 225 - 15, "SELECT FILE TO ERASE", 7);
            break;
        case CF_COPY1:
            print_text(45, 225 - 15, "SELECT FILE TO COPY", 7);
            break;
        case CF_COPY2:
            print_text(16, 225 - 15, "SELECT FILE TO OVERWRITE", 7);
            break;
        case CF_OPTIONS:
            print_text(104, 225 - 15, "OPTIONS", 7);
            break;
        case CF_CHALLENGES:
            print_text(98, 225 - 15, "CHALLENGES", 7);
            break;
    }
}


u8 textFileRCAM[20] = { TEXT_RCAM_P2 };


#define OPTIONS_X 130
#define OPTIONS_Y 176


void print_options(void) {
    u8 textMusicOn[] = { TEXT_MUSIC_ON };
    u8 textMusicOff[] = { TEXT_MUSIC_OFF };
    u8 textTrackerOn[] = { TEXT_TRACKER_ON };
    u8 textTrackerOff[] = { TEXT_TRACKER_OFF };
    u8 textFileRCAMP1[30] = { TEXT_RCAM_P1 };
    s16 x;
    s16 y2 = 0;
    s32 flags = save_file_get_options();
    s8 musicCheck = (flags & SAVE_OPTION_MUSIC) != FALSE;
    s8 trackerCheck = (flags & SAVE_OPTION_TRACKER) != FALSE;
    s8 camCheck = save_file_get_sensitivity();

    if (!musicCheck) {
        x = get_str_x_pos_from_center(OPTIONS_X, textMusicOn, 1.0f);
        print_generic_string(x, OPTIONS_Y - y2, textMusicOn);
    } else {
        x = get_str_x_pos_from_center(OPTIONS_X, textMusicOff, 1.0f);
        print_generic_string(x, OPTIONS_Y - y2, textMusicOff);
    }
    y2 += 54;

    if (!trackerCheck) {
        x = get_str_x_pos_from_center(OPTIONS_X, textTrackerOn, 1.0f);
        print_generic_string(x, OPTIONS_Y - y2, textTrackerOn);
    } else {
        x = get_str_x_pos_from_center(OPTIONS_X, textTrackerOff, 1.0f);
        print_generic_string(x, OPTIONS_Y - y2, textTrackerOff);
    }
    y2 += 54;

    textFileRCAM[18] = camCheck;
    textFileRCAM[19] = 0xFF;

    x = get_str_x_pos_from_center(OPTIONS_X, textFileRCAMP1, 1.0f);
    print_generic_string(x, OPTIONS_Y - y2 + 8, textFileRCAMP1);
    x = get_str_x_pos_from_center(OPTIONS_X, textFileRCAM, 1.0f);
    print_generic_string(x, OPTIONS_Y - y2 - 8, textFileRCAM);

}

#define CHALLENGE_TIME_START_X 115

void print_challenge_times(s32 challenge, s32 y) {
    s32 palette = 2;
	s32 highScore = save_file_get_challenge_time(challenge);
	u16 highMins, highSecs, highFracSecs;

	if (highScore == 0 || highScore >= 3600) {
		highScore = 3600;
        palette = 6;
    	print_text(CHALLENGE_TIME_START_X, y, "GOAL", palette);
	} else {
    	print_text(CHALLENGE_TIME_START_X, y, "BEST", palette);
	}

    highMins = highScore / (30 * 60);
    highSecs = (highScore - (highMins * 1800)) / 30;
    highFracSecs = ((highScore - (highMins * 1800) - (highSecs * 30)) & 0xFFFF) / 3;

    print_text_fmt_int(CHALLENGE_TIME_START_X + 59, y, "%0d", highMins, palette);
    print_text_fmt_int(CHALLENGE_TIME_START_X + 79, y, "%02d", highSecs, palette);
    print_text_fmt_int(CHALLENGE_TIME_START_X + 113, y, "%d", highFracSecs, palette);
    print_text(CHALLENGE_TIME_START_X + 69, y, ".", palette);
    print_text(CHALLENGE_TIME_START_X + 102, y, ".", palette);
}


void print_challenge_text(void) {
    unsigned char textChallenge1[] = { TEXT_CHALLENGE1 };
    unsigned char textChallenge2[] = { TEXT_CHALLENGE2 };
    unsigned char textChallenge3[] = { TEXT_CHALLENGE3 };
    unsigned char textChallenge4[] = { TEXT_CHALLENGE4 };
    unsigned char textChallenge5[] = { TEXT_CHALLENGE5 };


    print_generic_string(27, 181, textChallenge1);
    print_generic_string(27, 148, textChallenge2);
    print_generic_string(27, 115, textChallenge3);
    print_generic_string(27, 82, textChallenge4);
    print_generic_string(27, 49, textChallenge5);

    print_challenge_times(0, 181);
    print_challenge_times(1, 148);
    print_challenge_times(2, 115);
    print_challenge_times(3, 82);
    print_challenge_times(4, 49);

}


void print_CF_strings(void) {
    // Print "SELECT FILE" text
    // unsigned char textNewFile[] = { TEXT_NEWFILE };
    unsigned char textMadeBy[] = { TEXT_MADEBY };
    unsigned char text2023[] = { TEXT_2023 };
    unsigned char textArrow[] = { TEXT_ARROW };
    print_top_text(sCFMode);
    create_dl_ortho_matrix();
    // gSPDisplayList(gDisplayListHead++, dl_rgba16_text_begin);
    // gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, sCTextBaseAlpha);
    // print_hud_lut_string(HUD_LUT_DIFF, 93, 15, sCSelectFile);
    // print_text(93, 20, sCSelectFile, 0);


    // Print file star counts
    // print_save_file_star_count(SAVE_FILE_A, SAVEFILE_X1, 78);
    // print_save_file_star_count(SAVE_FILE_B, SAVEFILE_X2, 78);
    // print_save_file_star_count(SAVE_FILE_C, SAVEFILE_X1, 118);
    // print_save_file_star_count(SAVE_FILE_A, SAVEFILE_X2, 118);
    // gSPDisplayList(gDisplayListHead++, dl_rgba16_text_end);


    // create_dl_ortho_matrix();
    gSPDisplayList(gDisplayListHead++, dl_ia_text_begin);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, sCTextBaseAlpha);

    if (sCFMode < CF_OPTIONS) {
        if (save_file_exists(SAVE_FILE_A) == TRUE) {
            print_save_info(0);
        } else {
            // create_dl_scale_matrix(MENU_MTX_NOPUSH, 2.0f, 2.0f, 1.0f);
            // print_generic_string(80, 175 - 6, textNewFile);
            print_text(37, 175 - 6, "NEW FILE", 0);
        }

        if (cur_obj_nearest_object_with_behavior(bhvCSErasePrompt) == NULL && !cur_obj_has_behavior(bhvCSErasePrompt)) {
            if (save_file_exists(SAVE_FILE_B) == TRUE) {
                print_save_info(1);
            } else {
                // create_dl_scale_matrix(MENU_MTX_NOPUSH, 2.0f, 2.0f, 1.0f);
                // print_generic_string(80, 175 - 6, textNewFile);
                print_text(37, 127 - 6, "NEW FILE", 3);
            }
        }

        if (save_file_exists(SAVE_FILE_C) == TRUE) {
            print_save_info(2);
        } else {
            // create_dl_scale_matrix(MENU_MTX_NOPUSH, 2.0f, 2.0f, 1.0f);
            // print_generic_string(80, 175 - 6, textNewFile);
            print_text(37, 79 - 6, "NEW FILE", 2);
        }
        


        if (sCFMode != CF_COPY1 && sCFMode != CF_COPY2) {
            print_text(253, 175 - 6 - 1, "COPY", 6);
        } else {
            print_text(253, 175 - 6 - 1, "BACK", 7);
        }

        if (sCFMode != CF_ERASE) {
            print_text(252, 127 - 6 - 1, "ERASE", 1);
        } else {
            if (cur_obj_nearest_object_with_behavior(bhvCSErasePrompt) == NULL && !cur_obj_has_behavior(bhvCSErasePrompt)) {
                print_text(252, 127 - 6 - 1, "BACK", 7);
            }
        }

        //options
        print_text(294, 79 - 6 - 1, "{", 5);
        if (cur_obj_nearest_object_with_behavior(bhvCSErasePrompt) != NULL || cur_obj_has_behavior(bhvCSErasePrompt)) {
            print_erase_prompt();
        }

        if (sCFMode != CF_CHALLENGES) {
            print_text(25, 13, "CHALLENGES", 4);
        } else {
            print_text(25, 13, "BACK", 7);
        }


    } else if (sCFMode != CF_CHALLENGES) {
        print_options();
        //options
        gDPSetEnvColor(gDisplayListHead++, 0, 0, 0, sCTextBaseAlpha);
        print_generic_string(294 + 6 + 1, 79 - 6 - 1 - 1, textArrow);
        gDPSetEnvColor(gDisplayListHead++, 0x52, 0x52, 0x52, sCTextBaseAlpha);
        print_generic_string(294 + 6, 79 - 6 - 1, textArrow);
        gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, sCTextBaseAlpha);
    } else {
        print_text(25, 13, "BACK", 7);
        print_challenge_text();    
    }

    if (sCFMode != CF_CHALLENGES) {
        gDPSetEnvColor(gDisplayListHead++, 0, 0, 0, sCTextBaseAlpha);
        print_generic_string(220 - 1, 30 - 1, textMadeBy);
        print_generic_string(276 - 1, 16 - 1, text2023);

        gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, sCTextBaseAlpha);

        print_generic_string(220, 30, textMadeBy);
        print_generic_string(276, 16, text2023);
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


s16 sCursorButtonPos[3][2][2] = {
    { {-73, 60}, {108, 60}, },
    { {-73, 12}, {108, 12}, },
    { {-73, -38}, {128, -38}, },
};


s16 sCursorButtonOptionsPos[3][2][2] = {
    { {-46, 66}, {128, -38}, },
    { {-46, 12}, {128, -38}, },
    { {-46, -42}, {128, -38}, },
};

s8 sDPADCursorLocation[2] = {-1, -1}; 



void bhv_cs_bg_init(void) {
    gCurrentObject->oFaceAngleYaw = 0x8000;
    gCurrentObject->oMenuButtonScale = 9.0f;
    // o->oAnimState = 1;
    cur_obj_scale(9.0f);

    // play_music(0, SEQUENCE_ARGS(4, SEQ_MAIN_MENU), 0);
    // if (get_current_background_music() == SEQUENCE_ARGS(0, SEQ_MAIN_MENU)) {
        set_background_music(0, SEQ_MAIN_MENU, 0);
    // }
}

/**
 * Yellow Background Menu Loop Action
 * Properly scales the background in the main menu.
 */
void bhv_cs_bg_loop(void) {
    if (sDPADCursorLocation[0] == -1 || sDPADCursorLocation[1] == -1) {
        if (gPlayer1Controller->buttonPressed & (R_JPAD | L_JPAD | D_JPAD | U_JPAD)) {
            sDPADCursorLocation[0] = 0;
            sDPADCursorLocation[1] = 0;
            if (sCFMode != CF_OPTIONS) {
                sCursorPos[0] = sCursorButtonPos[sDPADCursorLocation[1]][sDPADCursorLocation[0]][0];
                sCursorPos[1] = sCursorButtonPos[sDPADCursorLocation[1]][sDPADCursorLocation[0]][1];
            } else {
                sCursorPos[0] = sCursorButtonOptionsPos[sDPADCursorLocation[1]][sDPADCursorLocation[0]][0];
                sCursorPos[1] = sCursorButtonOptionsPos[sDPADCursorLocation[1]][sDPADCursorLocation[0]][1];
            }
        }
    } else {
        if (gPlayer1Controller->buttonPressed & R_JPAD) {
            if (sDPADCursorLocation[0] != 1) {
                sDPADCursorLocation[0] = 1;
                if (sCFMode != CF_OPTIONS) {
                    sCursorPos[0] = sCursorButtonPos[sDPADCursorLocation[1]][sDPADCursorLocation[0]][0];
                    sCursorPos[1] = sCursorButtonPos[sDPADCursorLocation[1]][sDPADCursorLocation[0]][1];
                } else {
                    sCursorPos[0] = sCursorButtonOptionsPos[sDPADCursorLocation[1]][sDPADCursorLocation[0]][0];
                    sCursorPos[1] = sCursorButtonOptionsPos[sDPADCursorLocation[1]][sDPADCursorLocation[0]][1];
                }
            }
        } else if (gPlayer1Controller->buttonPressed & L_JPAD) {
            if (sDPADCursorLocation[0] != 0) {
                sDPADCursorLocation[0] = 0;
                if (sCFMode != CF_OPTIONS) {
                    sCursorPos[0] = sCursorButtonPos[sDPADCursorLocation[1]][sDPADCursorLocation[0]][0];
                    sCursorPos[1] = sCursorButtonPos[sDPADCursorLocation[1]][sDPADCursorLocation[0]][1];
                } else {
                    sCursorPos[0] = sCursorButtonOptionsPos[sDPADCursorLocation[1]][sDPADCursorLocation[0]][0];
                    sCursorPos[1] = sCursorButtonOptionsPos[sDPADCursorLocation[1]][sDPADCursorLocation[0]][1];
                }
            }
        }

        if (gPlayer1Controller->buttonPressed & D_JPAD) {
            if (sDPADCursorLocation[1] != 2) {
                sDPADCursorLocation[1]++;
                if (sCFMode != CF_OPTIONS) {
                    sCursorPos[0] = sCursorButtonPos[sDPADCursorLocation[1]][sDPADCursorLocation[0]][0];
                    sCursorPos[1] = sCursorButtonPos[sDPADCursorLocation[1]][sDPADCursorLocation[0]][1];
                } else {
                    sCursorPos[0] = sCursorButtonOptionsPos[sDPADCursorLocation[1]][sDPADCursorLocation[0]][0];
                    sCursorPos[1] = sCursorButtonOptionsPos[sDPADCursorLocation[1]][sDPADCursorLocation[0]][1];
                }
            }
        } else if (gPlayer1Controller->buttonPressed & U_JPAD) {
            if (sDPADCursorLocation[1] != 0) {
                sDPADCursorLocation[1]--;
                if (sCFMode != CF_OPTIONS) {
                    sCursorPos[0] = sCursorButtonPos[sDPADCursorLocation[1]][sDPADCursorLocation[0]][0];
                    sCursorPos[1] = sCursorButtonPos[sDPADCursorLocation[1]][sDPADCursorLocation[0]][1];
                } else {
                    sCursorPos[0] = sCursorButtonOptionsPos[sDPADCursorLocation[1]][sDPADCursorLocation[0]][0];
                    sCursorPos[1] = sCursorButtonOptionsPos[sDPADCursorLocation[1]][sDPADCursorLocation[0]][1];
                }
            }
        }
    }
}



