#ifndef SAVE_FILE_H
#define SAVE_FILE_H

#include <PR/ultratypes.h>

#include "types.h"
#include "area.h"

#include "course_table.h"

#if defined(SRAM)
    #define EEPROM_SIZE 0x8000
#elif defined(EEP16K)
    #define EEPROM_SIZE 0x800
#else
    #define EEPROM_SIZE 0x200
#endif

#define NUM_SAVE_FILES 3

struct SaveBlockSignature {
    u16 magic;
    u16 chksum;
};

struct SaveFile
{
    u8 spawnLevel;
    u8 spawnArea;
    Vec3s spawnPos;
    s16 spawnAngle;
    u32 newFlags[2];
    u32 ingameTime;
    u32 gpFlags;
    //u8 courseStars[COURSE_COUNT];
    u32 roomsCleared[3];
    u32 miscChallenges[2];
    u16 keys[2];
    u32 boosCaptured;
    u32 currencyStars;
    u32 starPieces;
    s32 coinCount;
    u16 goldenGoombas;
    s8 finalRank;

    struct SaveBlockSignature signature;
};

enum SaveFileIndex {
    SAVE_FILE_A,
    SAVE_FILE_B,
    SAVE_FILE_C//,
    //SAVE_FILE_D
};

struct MainMenuSaveData {
    // Each save file has a 2 bit "age" for each course. The higher this value,
    // the older the high score is. This is used for tie-breaking when displaying
    // on the high score screen.
    // u32 coinScoreAges[NUM_SAVE_FILES]; - 96 bits
    u16 menuRNG;
    u8 options;
    u8 camSens;
    u8 challenges;
    u8 soundMode: 2;
    u8 tvPeepaScore;
    u16 galleryScore;
    u16 chaseScore;
    u16 challengeTimes[5];
    // s8 finalRankA: 3;
    // s8 finalRankB: 3;
    // s8 finalRankC: 3;

#ifdef WIDE
    u8 wideMode: 1;
#endif

#ifdef VERSION_EU
    u8 language: 2;
#define SUBTRAHEND 8
#else
#define SUBTRAHEND 6
#endif

    // Pad to match the EEPROM size of 0x200 (10 bytes on JP/US, 8 bytes on EU)
    //u8 filler[EEPROM_SIZE / 2 - SUBTRAHEND - NUM_SAVE_FILES * (4 + sizeof(struct SaveFile))];

    struct SaveBlockSignature signature;
};

struct SaveBuffer {
    // Each of the four save files has two copies. If one is bad, the other is used as a backup.
    struct SaveFile files[NUM_SAVE_FILES][2];
    // The main menu data has two copies. If one is bad, the other is used as a backup.
    struct MainMenuSaveData menuData[2];
};

STATIC_ASSERT(sizeof(struct SaveBuffer) <= EEPROM_SIZE, "ERROR: Save struct too big for specified save type");

extern u8 gLastCompletedCourseNum;
extern u8 gLastCompletedStarNum;
extern s8 sUnusedGotGlobalCoinHiScore;
extern u8 gGotFileCoinHiScore;
extern u8 gCurrCourseStarFlags;
extern u8 gSpecialTripleJump;
extern s8 gLevelToCourseNumTable[];



/*
 * !!!!!!!!!!!!!!!!!!!!!!!!!
 *       OPTIONS FLAGS
 * !!!!!!!!!!!!!!!!!!!!!!!!!
 */
#define SAVE_OPTION_MUSIC                /* 0x00000001 */ (1 << 0)
#define SAVE_OPTION_TRACKER              /* 0x00000001 */ (1 << 1)
#define SAVE_OPTION_SKIP_OPENING         /* 0x00000001 */ (1 << 2)
#define SAVE_OPTION_SKIP_MHALL           /* 0x00000001 */ (1 << 3)

/*
 * !!!!!!!!!!!!!!!!!!!!!!!!!
 *       NEW FLAGS
 * !!!!!!!!!!!!!!!!!!!!!!!!!
 */
#define SAVE_NEW_FLAG_MUDROOM_GATE       /* 0x00000001 */ (1 << 0)
#define SAVE_NEW_FLAG_MAINHALL_SCENE     /* 0x00000002 */ (1 << 1)
#define SAVE_NEW_FLAG_PARLOR_GATE        /* 0x00000004 */ (1 << 2)
#define SAVE_NEW_FLAG_PRE_STUDY_GATE     /* 0x00000008 */ (1 << 3)
#define SAVE_NEW_FLAG_STUDY_GATE         /* 0x00000010 */ (1 << 4)
#define SAVE_NEW_FLAG_LIBRARY_MAIN_GATE  /* 0x00000020 */ (1 << 5)
#define SAVE_NEW_FLAG_FOG_KILLED         /* 0x00000040 */ (1 << 6)
#define SAVE_NEW_FLAG_BROKEN1            /* 0x00000100 */ (1 << 7)
#define SAVE_NEW_FLAG_BROKEN2            /* 0x00000200 */ (1 << 8)
#define SAVE_NEW_FLAG_BROKEN3            /* 0x00000400 */ (1 << 9)
#define SAVE_NEW_FLAG_FLOWER_DOOR        /* 0x00000080 */ (1 << 10)
#define SAVE_NEW_FLAG_EXIT_DOOR          /* 0x00000800 */ (1 << 11)
#define SAVE_NEW_FLAG_FAKE_WALL          /* 0x00001000 */ (1 << 12)
#define SAVE_NEW_FLAG_UNLOCKED_PLAYSET   /* 0x00002000 */ (1 << 13)
#define SAVE_NEW_FLAG_PUSHED_SNOWPILE    /* 0x00004000 */ (1 << 14)
#define SAVE_NEW_FLAG_CITY_POLE_OPEN     /* 0x00008000 */ (1 << 15)
#define SAVE_NEW_FLAG_CITY_BAND_BOUGHT   /* 0x00010000 */ (1 << 16)
#define SAVE_NEW_FLAG_CITY_BRIDGE_BOUGHT /* 0x00020000 */ (1 << 17)
#define SAVE_NEW_FLAG_CITY_TOAD_SAVED    /* 0x00040000 */ (1 << 18)
#define SAVE_NEW_FLAG_FOREROOM_WINDOW    /* 0x00080000 */ (1 << 19)
#define SAVE_NEW_FLAG_SAUNA_BULLY_GATE   /* 0x00100000 */ (1 << 20)
#define SAVE_NEW_FLAG_BASEMENT_SWITCH1   /* 0x00200000 */ (1 << 21)
#define SAVE_NEW_FLAG_BASEMENT_SWITCH2   /* 0x00400000 */ (1 << 22)
#define SAVE_NEW_FLAG_BASEMENT_SWITCH3   /* 0x00800000 */ (1 << 23)
#define SAVE_NEW_FLAG_BASEMENT_SWITCH4   /* 0x01000000 */ (1 << 24)
#define SAVE_NEW_FLAG_BASEMENT_SWITCH5   /* 0x02000000 */ (1 << 25)
#define SAVE_NEW_FLAG_ENGINE_GATE_OPEN   /* 0x04000000 */ (1 << 26)
#define SAVE_NEW_FLAG_ENGINE_GATE_OPEN2  /* 0x08000000 */ (1 << 27)
#define SAVE_NEW_FLAG_ELEVATOR_BOSS      /* 0x10000000 */ (1 << 28)
#define SAVE_NEW_FLAG_FLOATING_PLANT     /* 0x20000000 */ (1 << 29)
#define SAVE_NEW_FLAG_BAR_CUTSCENE       /* 0x40000000 */ (1 << 30)
#define SAVE_NEW_FLAG_KEY_CUTSCENE       /* 0x80000000 */ (1 << 31)


/*
 * !!!!!!!!!!!!!!!!!!!!!!!!!
 *       TOAD FLAGS
 * !!!!!!!!!!!!!!!!!!!!!!!!!
 */
#define SAVE_TOAD_FLAG_INTRODUCTION      /* 0x00000001 */ (1 << 0)
#define SAVE_TOAD_FLAG_FOUND_FIRST_BOO   /* 0x00000002 */ (1 << 1)
#define SAVE_TOAD_FLAG_ENTER_DINING      /* 0x00000004 */ (1 << 2)
#define SAVE_TOAD_FLAG_CLEAR_DINING      /* 0x00000008 */ (1 << 3)
#define SAVE_TOAD_FLAG_ENTER_L6          /* 0x00000010 */ (1 << 4)
#define SAVE_TOAD_FLAG_CLEAR_GAME        /* 0x00000020 */ (1 << 5)
#define SAVE_TOAD_FLAG_SPAWN_PLATS       /* 0x00000040 */ (1 << 6)
#define SAVE_TOAD_FLAG_MORNING_ROOM      /* 0x00000080 */ (1 << 7)
#define SAVE_TOAD_FLAG_CLEAR_THEATER     /* 0x00000100 */ (1 << 8)
#define SAVE_TOAD_FLAG_TROPHY_TWO        /* 0x00000200 */ (1 << 9)
#define SAVE_TOAD_FLAG_MIND_LEVER        /* 0x00000400 */ (1 << 10)
#define SAVE_TOAD_FLAG_MIND_MAZE         /* 0x00000800 */ (1 << 11)
#define SAVE_TOAD_FLAG_MIND_ENTRY        /* 0x00001000 */ (1 << 12)
#define SAVE_TOAD_FLAG_PROF_CAGE_MSG     /* 0x00002000 */ (1 << 13)
#define SAVE_TOAD_FLAG_REDS1             /* 0x00004000 */ (1 << 14)
#define SAVE_TOAD_FLAG_REDS2             /* 0x00008000 */ (1 << 15)
#define SAVE_TOAD_FLAG_REDS3             /* 0x00010000 */ (1 << 16)
#define SAVE_TOAD_FLAG_BRIDGE_TOY_TOAD   /* 0x00020000 */ (1 << 17)
#define SAVE_TOAD_FLAG_WARP_CUTSCENE     /* 0x00040000 */ (1 << 18)
#define SAVE_TOAD_FLAG_BALCONY_ELEVATOR  /* 0x00080000 */ (1 << 19)
#define SAVE_TOAD_FLAG_PLANT_CUTSCENE    /* 0x00100000 */ (1 << 20)
#define SAVE_TOAD_FLAG_022               /* 0x00200000 */ (1 << 21)
#define SAVE_TOAD_FLAG_023               /* 0x00400000 */ (1 << 22)
#define SAVE_TOAD_FLAG_024               /* 0x00800000 */ (1 << 23)
#define SAVE_TOAD_FLAG_025               /* 0x01000000 */ (1 << 24)
#define SAVE_TOAD_FLAG_026               /* 0x02000000 */ (1 << 25)
#define SAVE_TOAD_FLAG_027               /* 0x04000000 */ (1 << 26)
#define SAVE_TOAD_FLAG_028               /* 0x08000000 */ (1 << 27)
#define SAVE_TOAD_FLAG_TRACKER_1         /* 0x10000000 */ (1 << 28)
#define SAVE_TOAD_FLAG_COINS_2           /* 0x20000000 */ (1 << 29)
#define SAVE_TOAD_FLAG_MULTI_3           /* 0x40000000 */ (1 << 30)
#define SAVE_TOAD_FLAG_TREASURE_4        /* 0x80000000 */ (1 << 31)



/*
 * !!!!!!!!!!!!!!!!!!!!!!!!!
 *    GROUND POUND FLAGS
 * !!!!!!!!!!!!!!!!!!!!!!!!!
 */
#define SAVE_FLAG_GP_001                 /* 0x00000001 */ (1 << 0)
#define SAVE_FLAG_GP_002                 /* 0x00000002 */ (1 << 1)
#define SAVE_FLAG_GP_003                 /* 0x00000004 */ (1 << 2)
#define SAVE_FLAG_GP_004                 /* 0x00000008 */ (1 << 3)
#define SAVE_FLAG_GP_005                 /* 0x00000010 */ (1 << 4)
#define SAVE_FLAG_GP_006                 /* 0x00000020 */ (1 << 5)
#define SAVE_FLAG_GP_007                 /* 0x00000040 */ (1 << 6)
#define SAVE_FLAG_GP_008                 /* 0x00000080 */ (1 << 7)
#define SAVE_FLAG_GP_009                 /* 0x00000100 */ (1 << 8)
#define SAVE_FLAG_GP_010                 /* 0x00000200 */ (1 << 9)
#define SAVE_FLAG_GP_011                 /* 0x00000400 */ (1 << 10)
#define SAVE_FLAG_GP_012                 /* 0x00000800 */ (1 << 11)
#define SAVE_FLAG_GP_013                 /* 0x00001000 */ (1 << 12)
#define SAVE_FLAG_GP_014                 /* 0x00002000 */ (1 << 13)
#define SAVE_FLAG_GP_015                 /* 0x00004000 */ (1 << 14)
#define SAVE_FLAG_GP_016                 /* 0x00008000 */ (1 << 15)
#define SAVE_FLAG_GP_017                 /* 0x00010000 */ (1 << 16)
#define SAVE_FLAG_GP_018                 /* 0x00020000 */ (1 << 17)
#define SAVE_FLAG_GP_019                 /* 0x00040000 */ (1 << 18)
#define SAVE_FLAG_GP_020                 /* 0x00080000 */ (1 << 19)
#define SAVE_FLAG_GP_021                 /* 0x00100000 */ (1 << 20)
#define SAVE_FLAG_GP_022                 /* 0x00200000 */ (1 << 21)
#define SAVE_FLAG_GP_023                 /* 0x00400000 */ (1 << 22)
#define SAVE_FLAG_GP_024                 /* 0x00800000 */ (1 << 23)
#define SAVE_FLAG_GP_025                 /* 0x01000000 */ (1 << 24)
#define SAVE_FLAG_GP_026                 /* 0x02000000 */ (1 << 25)
#define SAVE_FLAG_GP_027                 /* 0x04000000 */ (1 << 26)
#define SAVE_FLAG_GP_028                 /* 0x08000000 */ (1 << 27)
#define SAVE_FLAG_GP_029                 /* 0x10000000 */ (1 << 28)
#define SAVE_FLAG_GP_030                 /* 0x20000000 */ (1 << 29)
#define SAVE_FLAG_GP_031                 /* 0x40000000 */ (1 << 30)
#define SAVE_FLAG_GP_032                 /* 0x80000000 */ (1 << 31)


//ranks
#define SAVE_RANK_NO_RANK           0
#define SAVE_RANK_S_PLUS            8
#define SAVE_RANK_S                 7
#define SAVE_RANK_A                 6
#define SAVE_RANK_B                 5
#define SAVE_RANK_C                 4
#define SAVE_RANK_D                 3
#define SAVE_RANK_E                 2
#define SAVE_RANK_F                 1



// game progress flags
#define SAVE_FLAG_FILE_EXISTS            /* 0x00000001 */ (1 << 0)
#define SAVE_FLAG_HAVE_WING_CAP          /* 0x00000002 */ (1 << 1)
#define SAVE_FLAG_HAVE_METAL_CAP         /* 0x00000004 */ (1 << 2)
#define SAVE_FLAG_HAVE_VANISH_CAP        /* 0x00000008 */ (1 << 3)
#define SAVE_FLAG_HAVE_KEY_1             /* 0x00000010 */ (1 << 4)
#define SAVE_FLAG_HAVE_KEY_2             /* 0x00000020 */ (1 << 5)
#define SAVE_FLAG_UNLOCKED_BASEMENT_DOOR /* 0x00000040 */ (1 << 6)
#define SAVE_FLAG_UNLOCKED_UPSTAIRS_DOOR /* 0x00000080 */ (1 << 7)
#define SAVE_FLAG_DDD_MOVED_BACK         /* 0x00000100 */ (1 << 8)
#define SAVE_FLAG_MOAT_DRAINED           /* 0x00000200 */ (1 << 9)
#define SAVE_FLAG_UNLOCKED_PSS_DOOR      /* 0x00000400 */ (1 << 10)
#define SAVE_FLAG_UNLOCKED_WF_DOOR       /* 0x00000800 */ (1 << 11)
#define SAVE_FLAG_UNLOCKED_CCM_DOOR      /* 0x00001000 */ (1 << 12)
#define SAVE_FLAG_UNLOCKED_JRB_DOOR      /* 0x00002000 */ (1 << 13)
#define SAVE_FLAG_UNLOCKED_BITDW_DOOR    /* 0x00004000 */ (1 << 14)
#define SAVE_FLAG_UNLOCKED_BITFS_DOOR    /* 0x00008000 */ (1 << 15)
#define SAVE_FLAG_CAP_ON_GROUND          /* 0x00010000 */ (1 << 16)
#define SAVE_FLAG_CAP_ON_KLEPTO          /* 0x00020000 */ (1 << 17)
#define SAVE_FLAG_CAP_ON_UKIKI           /* 0x00040000 */ (1 << 18)
#define SAVE_FLAG_CAP_ON_MR_BLIZZARD     /* 0x00080000 */ (1 << 19)
#define SAVE_FLAG_UNLOCKED_50_STAR_DOOR  /* 0x00100000 */ (1 << 20)
#define SAVE_FLAG_COLLECTED_TOAD_STAR_1  /* 0x01000000 */ (1 << 24)
#define SAVE_FLAG_COLLECTED_TOAD_STAR_2  /* 0x02000000 */ (1 << 25)
#define SAVE_FLAG_COLLECTED_TOAD_STAR_3  /* 0x04000000 */ (1 << 26)
#define SAVE_FLAG_COLLECTED_MIPS_STAR_1  /* 0x08000000 */ (1 << 27)
#define SAVE_FLAG_COLLECTED_MIPS_STAR_2  /* 0x10000000 */ (1 << 28)

#define SAVE_FLAG_TO_STAR_FLAG(cmd) (((cmd) >> 24) & 0x7F)
#define STAR_FLAG_TO_SAVE_FLAG(cmd) ((cmd) << 24)

// Variable for setting a warp checkpoint.

// possibly a WarpDest struct where arg is a union. TODO: Check?
struct WarpCheckpoint {
    /*0x00*/ u8 actNum;
    /*0x01*/ u8 courseNum;
    /*0x02*/ u8 levelID;
    /*0x03*/ u8 areaNum;
    /*0x04*/ u8 warpNode;
};

extern struct WarpCheckpoint gWarpCheckpoint;

extern s8 gMainMenuDataModified;
extern s8 gSaveFileModified;

void save_file_do_save(s32 fileIndex);
void save_file_erase(s32 fileIndex);
BAD_RETURN(s32) save_file_copy(s32 srcFileIndex, s32 destFileIndex);
void save_file_load_all(void);
void save_file_reload(void);
void save_file_collect_star_or_key(s16 coinScore, s16 starIndex);
s32 save_file_exists(s32 fileIndex);
u32 save_file_get_max_coin_score(s32 courseIndex);
s32 save_file_get_course_star_count(s32 fileIndex, s32 courseIndex);
s32 save_file_get_total_star_count(s32 fileIndex, s32 minCourse, s32 maxCourse);
// void save_file_set_flags(u32 flags);
// void save_file_clear_flags(u32 flags);
// u32 save_file_get_flags(void);

void save_file_make_complete(s32 file);

s8 save_file_get_final_rank(void);
void save_file_set_final_rank(s8 rank);

u32 save_file_get_star_flags(s32 fileIndex, s32 courseIndex);
void save_file_set_star_flags(s32 fileIndex, s32 courseIndex, u32 starFlags);
s32 save_file_get_course_coin_score(s32 fileIndex, s32 courseIndex);
s32 save_file_is_cannon_unlocked(void);
void save_file_set_cannon_unlocked(void);
void save_file_set_cap_pos(s16 x, s16 y, s16 z);
s32 save_file_get_cap_pos(Vec3s capPos);

u16 save_file_get_challenge_time(u16 challenge);
void save_file_set_challenge_time(u16 time, u16 challenge);
u8 save_file_get_peepa_score(void);
void save_file_set_peepa_score(u8 score);
u8 save_file_get_gallery_score(void);
void save_file_set_gallery_score(u16 score);
u8 save_file_get_chase_score(void);
void save_file_set_chase_score(u8 score);

void save_file_set_sound_mode(u16 mode);
u16 save_file_get_sound_mode(void);
s32 get_chapter_from_save_data(s32 saveFile);
u8 save_file_get_menu_challenges(void);
void save_file_set_menu_challenges(u16 challenge);
u8 save_file_get_sensitivity(void);
void save_file_set_sensitivity(u16 sens);
u8 save_file_get_options(void);
void save_file_set_options(u16 flag);
void save_file_set_options_nontoggle(u16 flag);

#ifdef WIDE
u8 save_file_get_widescreen_mode(void);
void save_file_set_widescreen_mode(u8 mode);
#endif

void save_file_move_cap_to_default_location(void);
u32 save_file_get_heavy_object(void);
void save_file_set_heavy_object(u8 obj, u32 id);
void save_file_set_newflags(u32 flags, u8 index);
void save_file_clear_newflags(u32 flags,  u8 index);
u32 save_file_get_newflags(u8 index);
void save_file_set_gpflags(u32 flags);
void save_file_clear_gpflags(u32 flags);
u32 save_file_get_gpflags(void);
u32 save_file_get_boos(void);
void save_file_set_boos(u32 boo);
u32 save_file_get_golden_goombas(void);
void save_file_set_golden_goombas(u32 goomba);
u32 save_file_get_reds_star(void);
u32 save_file_get_star_piece(void);
void save_file_set_star_piece(u32 piece);
u32 save_file_get_challenges(u8 index);
void save_file_set_challenges(u32 challenge);
u32 save_file_get_keys(u32 page);
void save_file_set_keys(u32 key, u32 page);

u32 save_file_get_rooms(u32 index);
void save_file_set_rooms(u32 room);
s32 save_file_check_room(s32 room);
s32 save_file_check_global_room(void);
u32 save_file_get_currency_flags(void);
void save_file_set_currency_flags(u32 flag);

void disable_warp_checkpoint(void);
void check_if_should_set_warp_checkpoint(struct WarpNode *warpNode);
s32 check_warp_checkpoint(struct WarpNode *warpNode);

#ifdef VERSION_EU
enum EuLanguages {
    LANGUAGE_ENGLISH,
    LANGUAGE_FRENCH,
    LANGUAGE_GERMAN
};

void eu_set_language(u16 language);
u16 eu_get_language(void);
#endif

#endif // SAVE_FILE_H
