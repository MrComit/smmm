#include <PR/ultratypes.h>

#include "sm64.h"
#include "area.h"
#include "audio/external.h"
#include "behavior_data.h"
#include "camera.h"
#include "engine/math_util.h"
#include "interaction.h"
#include "level_update.h"
#include "mario.h"
#include "mario_actions_stationary.h"
#include "mario_step.h"
#include "memory.h"
#include "save_file.h"
#include "sound_init.h"
#include "surface_terrains.h"
#include "rumble_init.h"
#include "object_list_processor.h"
#include "game_init.h"

s32 check_common_idle_cancels(struct MarioState *m) {
    mario_drop_held_object(m);
    if (m->floor->normal.y < 0.29237169f) {
        return mario_push_off_steep_floor(m, ACT_FREEFALL, 0);
    }

    if (m->input & INPUT_STOMPED) {
        return set_mario_action(m, ACT_SHOCKWAVE_BOUNCE, 0);
    }

    if (m->input & INPUT_A_PRESSED) {
        return set_jumping_action(m, ACT_JUMP, 0);
    }

    if (m->input & INPUT_OFF_FLOOR) {
        return set_mario_action(m, ACT_FREEFALL, 0);
    }

    if (m->input & INPUT_ABOVE_SLIDE) {
        return set_mario_action(m, ACT_BEGIN_SLIDING, 0);
    }

    if (m->input & INPUT_FIRST_PERSON) {
        return set_mario_action(m, ACT_FIRST_PERSON, 0);
    }

    if (m->input & INPUT_NONZERO_ANALOG) {
        m->faceAngle[1] = (s16) m->intendedYaw;
        return set_mario_action(m, ACT_WALKING, 0);
    }

    if (m->input & INPUT_B_PRESSED) {
        return set_mario_action(m, ACT_PUNCHING, 0);
    }

    if (m->input & INPUT_Z_DOWN) {
        return set_mario_action(m, ACT_START_CROUCHING, 0);
    }

    return FALSE;
}

s32 check_common_hold_idle_cancels(struct MarioState *m) {
    if (m->floor->normal.y < 0.29237169f) {
        return mario_push_off_steep_floor(m, ACT_HOLD_FREEFALL, 0);
    }

    if (m->heldObj->oInteractionSubtype & INT_SUBTYPE_DROP_IMMEDIATELY) {
        m->heldObj->oInteractionSubtype =
            (s32)(m->heldObj->oInteractionSubtype & ~INT_SUBTYPE_DROP_IMMEDIATELY);
        return set_mario_action(m, ACT_PLACING_DOWN, 0);
    }

    if (m->input & INPUT_STOMPED) {
        return drop_and_set_mario_action(m, ACT_SHOCKWAVE_BOUNCE, 0);
    }

    if (m->input & INPUT_A_PRESSED) {
        return set_jumping_action(m, ACT_HOLD_JUMP, 0);
    }

    if (m->input & INPUT_OFF_FLOOR) {
        return set_mario_action(m, ACT_HOLD_FREEFALL, 0);
    }

    if (m->input & INPUT_ABOVE_SLIDE) {
        return set_mario_action(m, ACT_HOLD_BEGIN_SLIDING, 0);
    }

    if (m->input & INPUT_NONZERO_ANALOG) {
        m->faceAngle[1] = (s16) m->intendedYaw;
        return set_mario_action(m, ACT_HOLD_WALKING, 0);
    }

    if (m->input & INPUT_B_PRESSED) {
        return set_mario_action(m, ACT_THROWING, 0);
    }

    if (m->input & INPUT_Z_DOWN) {
        return drop_and_set_mario_action(m, ACT_START_CROUCHING, 0);
    }

    return FALSE;
}

s32 act_idle(struct MarioState *m) {
    if (m->quicksandDepth > 30.0f) {
        return set_mario_action(m, ACT_IN_QUICKSAND, 0);
    }

    if (m->input & INPUT_IN_POISON_GAS) {
        return set_mario_action(m, ACT_COUGHING, 0);
    }

    if (!(m->actionArg & 1) && m->health < 0x300) {
        return set_mario_action(m, ACT_PANTING, 0);
    }

    if (check_common_idle_cancels(m)) {
        return TRUE;
    }

    if (m->actionState == 3) {
        if ((m->area->terrainType & TERRAIN_MASK) == TERRAIN_SNOW) {
            return set_mario_action(m, ACT_SHIVERING, 0);
        } else {
            return set_mario_action(m, ACT_START_SLEEPING, 0);
        }
    }

    if (m->actionArg & 1) {
        set_mario_animation(m, MARIO_ANIM_STAND_AGAINST_WALL);
    } else {
        switch (m->actionState) {
            case 0:
                set_mario_animation(m, MARIO_ANIM_IDLE_HEAD_LEFT);
                break;

            case 1:
                set_mario_animation(m, MARIO_ANIM_IDLE_HEAD_RIGHT);
                break;

            case 2:
                set_mario_animation(m, MARIO_ANIM_IDLE_HEAD_CENTER);
                break;
        }

        if (is_anim_at_end(m)) {
            // Fall asleep after 10 head turning cycles.
            // act_start_sleeping is triggered earlier in the function
            // when actionState == 3. This happens when Mario's done
            // turning his head back and forth. However, we do some checks
            // here to make sure that Mario would be able to sleep here,
            // and that he's gone through 10 cycles before sleeping.
            // actionTimer is used to track how many cycles have passed.
            if (++m->actionState == 3) {
                f32 deltaYOfFloorBehindMario = m->pos[1] - find_floor_height_relative_polar(m, -0x8000, 60.0f);
                if (deltaYOfFloorBehindMario < -24.0f || 24.0f < deltaYOfFloorBehindMario || m->floor->flags & SURFACE_FLAG_DYNAMIC) {
                    m->actionState = 0;
                } else {
                    // If Mario hasn't turned his head 10 times yet, stay idle instead of going to sleep.
                    m->actionTimer++;
                    if (m->actionTimer < 10) {
                        m->actionState = 0;
                    }
                }
            }
        }
    }

    stationary_ground_step(m);

    return FALSE;
}

void play_anim_sound(struct MarioState *m, u32 actionState, s32 animFrame, u32 sound) {
    if (m->actionState == actionState && m->marioObj->header.gfx.animInfo.animFrame == animFrame) {
        play_sound(sound, m->marioObj->header.gfx.cameraToObject);
    }
}

s32 act_start_sleeping(struct MarioState *m) {
#ifndef VERSION_JP
    s32 animFrame;
#endif

    if (check_common_idle_cancels(m)) {
        return TRUE;
    }

    if (m->quicksandDepth > 30.0f) {
        return set_mario_action(m, ACT_IN_QUICKSAND, 0);
    }

    if (m->actionState == 4) {
        return set_mario_action(m, ACT_SLEEPING, 0);
    }

    switch (m->actionState) {
        case 0:
#ifndef VERSION_JP
            animFrame =
#endif
            set_mario_animation(m, MARIO_ANIM_START_SLEEP_IDLE);
            break;

        case 1:
#ifndef VERSION_JP
            animFrame =
#endif
            set_mario_animation(m, MARIO_ANIM_START_SLEEP_SCRATCH);
            break;

        case 2:
#ifndef VERSION_JP
            animFrame =
#endif
            set_mario_animation(m, MARIO_ANIM_START_SLEEP_YAWN);
            m->marioBodyState->eyeState = MARIO_EYES_HALF_CLOSED;
            break;

        case 3:
#ifndef VERSION_JP
            animFrame =
#endif
            set_mario_animation(m, MARIO_ANIM_START_SLEEP_SITTING);
            m->marioBodyState->eyeState = MARIO_EYES_HALF_CLOSED;
            break;
    }

    play_anim_sound(m, 1, 41, SOUND_ACTION_PAT_BACK);
    play_anim_sound(m, 1, 49, SOUND_ACTION_PAT_BACK);
    play_anim_sound(m, 3, 15, m->terrainSoundAddend + SOUND_ACTION_TERRAIN_BODY_HIT_GROUND);

    if (is_anim_at_end(m)) {
        m->actionState++;
    }

#ifndef VERSION_JP
    if (m->actionState == 2 && animFrame == -1) {
        play_sound(SOUND_MARIO_YAWNING, m->marioObj->header.gfx.cameraToObject);
    }

    if (m->actionState == 1 && animFrame == -1) {
        play_sound(SOUND_MARIO_IMA_TIRED, m->marioObj->header.gfx.cameraToObject);
    }
#else
    if (m->actionState == 2) {
        play_sound_if_no_flag(m, SOUND_MARIO_YAWNING, MARIO_MARIO_SOUND_PLAYED);
    }
#endif

    stationary_ground_step(m);
    return FALSE;
}

s32 act_sleeping(struct MarioState *m) {
    s32 animFrame;
    if (m->input
        & (INPUT_NONZERO_ANALOG | INPUT_A_PRESSED | INPUT_OFF_FLOOR | INPUT_ABOVE_SLIDE
           | INPUT_FIRST_PERSON | INPUT_STOMPED | INPUT_B_PRESSED | INPUT_Z_PRESSED)) {
        return set_mario_action(m, ACT_WAKING_UP, m->actionState);
    }

    if (m->quicksandDepth > 30.0f) {
        return set_mario_action(m, ACT_WAKING_UP, m->actionState);
    }

    if (m->pos[1] - find_floor_height_relative_polar(m, -0x8000, 60.0f) > 24.0f) {
        return set_mario_action(m, ACT_WAKING_UP, m->actionState);
    }

    m->marioBodyState->eyeState = MARIO_EYES_CLOSED;
    stationary_ground_step(m);
    switch (m->actionState) {
        case 0:
            animFrame = set_mario_animation(m, MARIO_ANIM_SLEEP_IDLE);

            if (animFrame == -1 && !m->actionTimer) {
                lower_background_noise(2);
            }

            if (animFrame == 2) {
                play_sound(SOUND_MARIO_SNORING1, m->marioObj->header.gfx.cameraToObject);
            }

            if (animFrame == 20) {
                play_sound(SOUND_MARIO_SNORING2, m->marioObj->header.gfx.cameraToObject);
            }

            if (is_anim_at_end(m)) {
                m->actionTimer++;
                if (m->actionTimer > 45) {
                    m->actionState++;
                }
            }
            break;

        case 1:
            if (set_mario_animation(m, MARIO_ANIM_SLEEP_START_LYING) == 18) {
                play_mario_heavy_landing_sound(m, SOUND_ACTION_TERRAIN_BODY_HIT_GROUND);
            }

            if (is_anim_at_end(m)) {
                m->actionState++;
            }
            break;

        case 2:
            animFrame = set_mario_animation(m, MARIO_ANIM_SLEEP_LYING);
#ifndef VERSION_JP
            play_sound_if_no_flag(m, SOUND_MARIO_SNORING3, MARIO_ACTION_SOUND_PLAYED);
#else
            if (animFrame == 2) {
                play_sound(SOUND_MARIO_SNORING2, m->marioObj->header.gfx.cameraToObject);
            }

            if (animFrame == 25) {
                play_sound(SOUND_MARIO_SNORING1, m->marioObj->header.gfx.cameraToObject);
            }
#endif
            break;
    }
    return FALSE;
}

s32 act_waking_up(struct MarioState *m) {
    if (!m->actionTimer) {
        stop_sound(SOUND_MARIO_SNORING1, m->marioObj->header.gfx.cameraToObject);
        stop_sound(SOUND_MARIO_SNORING2, m->marioObj->header.gfx.cameraToObject);
#ifndef VERSION_JP
        stop_sound(SOUND_MARIO_SNORING3, m->marioObj->header.gfx.cameraToObject);
#endif
        raise_background_noise(2);
    }

    if (m->input & INPUT_STOMPED) {
        return set_mario_action(m, ACT_SHOCKWAVE_BOUNCE, 0);
    }

    if (m->input & INPUT_OFF_FLOOR) {
        return set_mario_action(m, ACT_FREEFALL, 0);
    }

    if (m->input & INPUT_ABOVE_SLIDE) {
        return set_mario_action(m, ACT_BEGIN_SLIDING, 0);
    }

    m->actionTimer++;

    if (m->actionTimer > 20) {
        return set_mario_action(m, ACT_IDLE, 0);
    }

    stationary_ground_step(m);

    set_mario_animation(m, !m->actionArg ? MARIO_ANIM_WAKE_FROM_SLEEP : MARIO_ANIM_WAKE_FROM_LYING);

    return FALSE;
}

s32 act_shivering(struct MarioState *m) {
    s32 animFrame;

    if (m->input & INPUT_STOMPED) {
        return set_mario_action(m, ACT_SHOCKWAVE_BOUNCE, 0);
    }

    if (m->input & INPUT_OFF_FLOOR) {
        return set_mario_action(m, ACT_FREEFALL, 0);
    }

    if (m->input & INPUT_ABOVE_SLIDE) {
        return set_mario_action(m, ACT_BEGIN_SLIDING, 0);
    }

    if (m->input
        & (INPUT_NONZERO_ANALOG | INPUT_A_PRESSED | INPUT_OFF_FLOOR | INPUT_ABOVE_SLIDE
           | INPUT_FIRST_PERSON | INPUT_STOMPED | INPUT_B_PRESSED | INPUT_Z_PRESSED)) {
        m->actionState = 2;
    }

    stationary_ground_step(m);
    switch (m->actionState) {
        case 0:
            animFrame = set_mario_animation(m, MARIO_ANIM_SHIVERING_WARMING_HAND);
            if (animFrame == 49) {
                m->particleFlags |= PARTICLE_BREATH;
                play_sound(SOUND_MARIO_PANTING_COLD, m->marioObj->header.gfx.cameraToObject);
            }
            if (animFrame == 7 || animFrame == 81) {
                play_sound(SOUND_ACTION_CLAP_HANDS_COLD, m->marioObj->header.gfx.cameraToObject);
            }
            if (is_anim_past_end(m)) {
                m->actionState = 1;
            }
            break;

        case 1:
            animFrame = set_mario_animation(m, MARIO_ANIM_SHIVERING);
            if (animFrame == 9 || animFrame == 25 || animFrame == 44) {
                play_sound(SOUND_ACTION_CLAP_HANDS_COLD, m->marioObj->header.gfx.cameraToObject);
            }
            break;

        case 2:
            set_mario_animation(m, MARIO_ANIM_SHIVERING_RETURN_TO_IDLE);
            if (is_anim_past_end(m)) {
                set_mario_action(m, ACT_IDLE, 0);
            }
            break;
    }
    return FALSE;
}

s32 act_coughing(struct MarioState *m) {
    s32 animFrame;

    if (check_common_idle_cancels(m)) {
        return TRUE;
    }

    stationary_ground_step(m);
    animFrame = set_mario_animation(m, MARIO_ANIM_COUGHING);
    if (animFrame == 25 || animFrame == 35) {
        play_sound(SOUND_MARIO_COUGHING3, m->marioObj->header.gfx.cameraToObject);
    }

    if (animFrame == 50 || animFrame == 58) {
        play_sound(SOUND_MARIO_COUGHING2, m->marioObj->header.gfx.cameraToObject);
    }

    if (animFrame == 71 || animFrame == 80) {
        play_sound(SOUND_MARIO_COUGHING1, m->marioObj->header.gfx.cameraToObject);
    }

    return FALSE;
}

s32 act_hold_idle(struct MarioState *m) {
    if (segmented_to_virtual(&bhvJumpingBox) == m->heldObj->behavior) {
        return set_mario_action(m, ACT_CRAZY_BOX_BOUNCE, 0);
    }

    if (m->marioObj->oInteractStatus & INT_STATUS_MARIO_DROP_OBJECT) {
        return drop_and_set_mario_action(m, ACT_IDLE, 0);
    }

    if (m->quicksandDepth > 30.0f) {
        return drop_and_set_mario_action(m, ACT_IN_QUICKSAND, 0);
    }

    if (check_common_hold_idle_cancels(m)) {
        return TRUE;
    }

    stationary_ground_step(m);
    set_mario_animation(m, MARIO_ANIM_IDLE_WITH_LIGHT_OBJ);
    return FALSE;
}

s32 act_hold_heavy_idle(struct MarioState *m) {
    if (m->input & INPUT_STOMPED) {
        return drop_and_set_mario_action(m, ACT_SHOCKWAVE_BOUNCE, 0);
    }

    if (m->input & INPUT_OFF_FLOOR) {
        return drop_and_set_mario_action(m, ACT_FREEFALL, 0);
    }

    if (m->input & INPUT_ABOVE_SLIDE) {
        return drop_and_set_mario_action(m, ACT_BEGIN_SLIDING, 0);
    }

    if (m->input & INPUT_NONZERO_ANALOG) {
        return set_mario_action(m, ACT_HOLD_HEAVY_WALKING, 0);
    }

    if (m->input & INPUT_B_PRESSED) {
        return set_mario_action(m, ACT_HEAVY_THROW, 0);
    }

    stationary_ground_step(m);
    set_mario_animation(m, MARIO_ANIM_IDLE_HEAVY_OBJ);
    return FALSE;
}

s32 act_standing_against_wall(struct MarioState *m) {
    if (m->input & INPUT_STOMPED) {
        return set_mario_action(m, ACT_SHOCKWAVE_BOUNCE, 0);
    }

    if (m->input & (INPUT_NONZERO_ANALOG | INPUT_A_PRESSED | INPUT_OFF_FLOOR | INPUT_ABOVE_SLIDE)) {
        return check_common_action_exits(m);
    }

    if (m->input & INPUT_FIRST_PERSON) {
        return set_mario_action(m, ACT_FIRST_PERSON, 0);
    }

    if (m->input & INPUT_B_PRESSED) {
        return set_mario_action(m, ACT_PUNCHING, 0);
    }

    set_mario_animation(m, MARIO_ANIM_STAND_AGAINST_WALL);
    stationary_ground_step(m);
    return FALSE;
}

s32 act_in_quicksand(struct MarioState *m) {
    if (m->quicksandDepth < 30.0f) {
        return set_mario_action(m, ACT_IDLE, 0);
    }

    if (check_common_idle_cancels(m)) {
        return TRUE;
    }

    if (m->quicksandDepth > 70.0f) {
        set_mario_animation(m, MARIO_ANIM_DYING_IN_QUICKSAND);
    } else {
        set_mario_animation(m, MARIO_ANIM_IDLE_IN_QUICKSAND);
    }

    stationary_ground_step(m);
    return FALSE;
}

s32 act_crouching(struct MarioState *m) {
    if (m->input & INPUT_STOMPED) {
        return set_mario_action(m, ACT_SHOCKWAVE_BOUNCE, 0);
    }

    if (m->input & INPUT_A_PRESSED) {
        return set_jumping_action(m, ACT_BACKFLIP, 0);
    }

    if (m->input & INPUT_OFF_FLOOR) {
        return set_mario_action(m, ACT_FREEFALL, 0);
    }

    if (m->input & INPUT_ABOVE_SLIDE) {
        return set_mario_action(m, ACT_BEGIN_SLIDING, 0);
    }

    if (m->input & INPUT_FIRST_PERSON) {
        return set_mario_action(m, ACT_STOP_CROUCHING, 0);
    }

    if (!(m->input & INPUT_Z_DOWN)) {
        return set_mario_action(m, ACT_STOP_CROUCHING, 0);
    }

    if (m->input & INPUT_NONZERO_ANALOG) {
        return set_mario_action(m, ACT_START_CRAWLING, 0);
    }

    if (m->input & INPUT_B_PRESSED) {
        return set_mario_action(m, ACT_PUNCHING, 9);
    }

    stationary_ground_step(m);
    set_mario_animation(m, MARIO_ANIM_CROUCHING);
    return FALSE;
}

s32 act_panting(struct MarioState *m) {
    if (m->input & INPUT_STOMPED) {
        return set_mario_action(m, ACT_SHOCKWAVE_BOUNCE, 0);
    }

    if (m->health >= 0x500) {
        return set_mario_action(m, ACT_IDLE, 0);
    }

    if (check_common_idle_cancels(m)) {
        return TRUE;
    }

    if (set_mario_animation(m, MARIO_ANIM_WALK_PANTING) == 1) {
        play_sound(SOUND_MARIO_PANTING + ((gAudioRandom % 3U) << 0x10),
                   m->marioObj->header.gfx.cameraToObject);
    }

    stationary_ground_step(m);
    m->marioBodyState->eyeState = MARIO_EYES_HALF_CLOSED;
    return FALSE;
}

s32 act_hold_panting_unused(struct MarioState *m) {
    if (m->marioObj->oInteractStatus & INT_STATUS_MARIO_DROP_OBJECT) {
        return drop_and_set_mario_action(m, ACT_PANTING, 0);
    }

    if (m->input & INPUT_STOMPED) {
        return drop_and_set_mario_action(m, ACT_SHOCKWAVE_BOUNCE, 0);
    }

    if (m->health >= 0x500) {
        return set_mario_action(m, ACT_HOLD_IDLE, 0);
    }

    if (check_common_hold_idle_cancels(m)) {
        return TRUE;
    }

    set_mario_animation(m, MARIO_ANIM_WALK_PANTING);
    stationary_ground_step(m);
    m->marioBodyState->eyeState = MARIO_EYES_HALF_CLOSED;
    return FALSE;
}

void stopping_step(struct MarioState *m, s32 animID, u32 action) {
    stationary_ground_step(m);
    set_mario_animation(m, animID);
    if (is_anim_at_end(m)) {
        set_mario_action(m, action, 0);
    }
}

s32 act_braking_stop(struct MarioState *m) {
    if (m->input & INPUT_STOMPED) {
        return set_mario_action(m, ACT_SHOCKWAVE_BOUNCE, 0);
    }

    if (m->input & INPUT_OFF_FLOOR) {
        return set_mario_action(m, ACT_FREEFALL, 0);
    }

    if (m->input & INPUT_B_PRESSED) {
        return set_mario_action(m, ACT_PUNCHING, 0);
    }

    if (!(m->input & INPUT_FIRST_PERSON)
        && m->input & (INPUT_NONZERO_ANALOG | INPUT_A_PRESSED | INPUT_OFF_FLOOR | INPUT_ABOVE_SLIDE)) {
        return check_common_action_exits(m);
    }

    stopping_step(m, MARIO_ANIM_STOP_SKID, ACT_IDLE);
    return FALSE;
}

s32 act_butt_slide_stop(struct MarioState *m) {
    if (m->input & INPUT_STOMPED) {
        return set_mario_action(m, ACT_SHOCKWAVE_BOUNCE, 0);
    }

    if (m->input & INPUT_NONZERO_ANALOG) {
        return set_mario_action(m, ACT_IDLE, 0);
    }

    if (m->input & (INPUT_NONZERO_ANALOG | INPUT_A_PRESSED | INPUT_OFF_FLOOR | INPUT_ABOVE_SLIDE)) {
        return check_common_action_exits(m);
    }

    stopping_step(m, MARIO_ANIM_STOP_SLIDE, ACT_IDLE);
    if (m->marioObj->header.gfx.animInfo.animFrame == 6) {
        play_mario_landing_sound(m, SOUND_ACTION_TERRAIN_LANDING);
    }

    return FALSE;
}

s32 act_hold_butt_slide_stop(struct MarioState *m) {
    if (m->marioObj->oInteractStatus & INT_STATUS_MARIO_DROP_OBJECT) {
        return drop_and_set_mario_action(m, ACT_IDLE, 0);
    }

    if (m->input & INPUT_STOMPED) {
        return drop_and_set_mario_action(m, ACT_SHOCKWAVE_BOUNCE, 0);
    }

    if (m->input & (INPUT_NONZERO_ANALOG | INPUT_A_PRESSED | INPUT_OFF_FLOOR | INPUT_ABOVE_SLIDE)) {
        return check_common_hold_action_exits(m);
    }

    if (m->input & INPUT_B_PRESSED) {
        return set_mario_action(m, ACT_THROWING, 0);
    }

    stopping_step(m, MARIO_ANIM_STAND_UP_FROM_SLIDING_WITH_LIGHT_OBJ, ACT_HOLD_IDLE);
    return FALSE;
}

s32 act_slide_kick_slide_stop(struct MarioState *m) {
    if (m->input & INPUT_STOMPED) {
        return drop_and_set_mario_action(m, ACT_SHOCKWAVE_BOUNCE, 0);
    }

    if (m->input & INPUT_OFF_FLOOR) {
        return drop_and_set_mario_action(m, ACT_FREEFALL, 0);
    }

    stopping_step(m, MARIO_ANIM_CROUCH_FROM_SLIDE_KICK, ACT_CROUCHING);
    return FALSE;
}

s32 act_start_crouching(struct MarioState *m) {
    if (m->input & INPUT_STOMPED) {
        return set_mario_action(m, ACT_SHOCKWAVE_BOUNCE, 0);
    }

    if (m->input & INPUT_OFF_FLOOR) {
        return set_mario_action(m, ACT_FREEFALL, 0);
    }

    if (m->input & INPUT_A_PRESSED) {
        return set_jumping_action(m, ACT_BACKFLIP, 0);
    }

    if (m->input & INPUT_ABOVE_SLIDE) {
        return set_mario_action(m, ACT_BEGIN_SLIDING, 0);
    }

    stationary_ground_step(m);
    set_mario_animation(m, MARIO_ANIM_START_CROUCHING);
    if (is_anim_past_end(m)) {
        set_mario_action(m, ACT_CROUCHING, 0);
    }
    return FALSE;
}

s32 act_stop_crouching(struct MarioState *m) {
    if (m->input & INPUT_STOMPED) {
        return set_mario_action(m, ACT_SHOCKWAVE_BOUNCE, 0);
    }

    if (m->input & INPUT_OFF_FLOOR) {
        return set_mario_action(m, ACT_FREEFALL, 0);
    }

    if (m->input & INPUT_A_PRESSED) {
        return set_jumping_action(m, ACT_BACKFLIP, 0);
    }

    if (m->input & INPUT_ABOVE_SLIDE) {
        return set_mario_action(m, ACT_BEGIN_SLIDING, 0);
    }

    stationary_ground_step(m);
    set_mario_animation(m, MARIO_ANIM_STOP_CROUCHING);
    if (is_anim_past_end(m)) {
        set_mario_action(m, ACT_IDLE, 0);
    }
    return FALSE;
}

s32 act_start_crawling(struct MarioState *m) {
    if (m->input & INPUT_FIRST_PERSON) {
        return set_mario_action(m, ACT_STOP_CROUCHING, 0);
    }

    if (m->input & INPUT_OFF_FLOOR) {
        return set_mario_action(m, ACT_FREEFALL, 0);
    }

    if (m->input & INPUT_STOMPED) {
        return set_mario_action(m, ACT_SHOCKWAVE_BOUNCE, 0);
    }

    if (m->input & INPUT_ABOVE_SLIDE) {
        return set_mario_action(m, ACT_BEGIN_SLIDING, 0);
    }

    stationary_ground_step(m);
    set_mario_animation(m, MARIO_ANIM_START_CRAWLING);
    if (is_anim_past_end(m)) {
        set_mario_action(m, ACT_CRAWLING, 0);
    }

    return FALSE;
}

s32 act_stop_crawling(struct MarioState *m) {
    if (m->input & INPUT_STOMPED) {
        return set_mario_action(m, ACT_SHOCKWAVE_BOUNCE, 0);
    }

    if (m->input & INPUT_OFF_FLOOR) {
        return set_mario_action(m, ACT_FREEFALL, 0);
    }

    if (m->input & INPUT_ABOVE_SLIDE) {
        return set_mario_action(m, ACT_BEGIN_SLIDING, 0);
    }

    stationary_ground_step(m);
    set_mario_animation(m, MARIO_ANIM_STOP_CRAWLING);
    if (is_anim_past_end(m)) {
        set_mario_action(m, ACT_CROUCHING, 0);
    }
    return FALSE;
}

s32 act_shockwave_bounce(struct MarioState *m) {
    s16 sp1E;
    f32 sp18;

    if (m->marioObj->oInteractStatus & INT_STATUS_MARIO_SHOCKWAVE) {
#if ENABLE_RUMBLE
        queue_rumble_data(70, 40);
#endif
        return hurt_and_set_mario_action(m, ACT_SHOCKED, 0, 4);
    }

    if (m->actionTimer == 0) {
#if ENABLE_RUMBLE
        queue_rumble_data(70, 40);
#endif
        if (m->marioObj->oInteractStatus & INT_STATUS_MARIO_KNOCKBACK_DMG) {
            return hurt_and_set_mario_action(m, ACT_BACKWARD_GROUND_KB, 0, 0xc);
        }
    }

    if (++m->actionTimer == 48) {
        return set_mario_action(m, ACT_IDLE, 0);
    }

    sp1E = (m->actionTimer % 16) << 12;
    sp18 = (f32)(((f32)(6 - m->actionTimer / 8) * 8.0f) + 4.0f);
    mario_set_forward_vel(m, 0);
    vec3f_set(m->vel, 0.0f, 0.0f, 0.0f);
    if (sins(sp1E) >= 0.0f) {
        m->pos[1] = sins(sp1E) * sp18 + m->floorHeight;
    } else {
        m->pos[1] = m->floorHeight - sins(sp1E) * sp18;
    }

    vec3f_copy(m->marioObj->header.gfx.pos, m->pos);
    vec3s_set(m->marioObj->header.gfx.angle, 0, m->faceAngle[1], 0);
    set_mario_animation(m, MARIO_ANIM_A_POSE);
    return FALSE;
}

s32 landing_step(struct MarioState *m, s32 arg1, u32 action) {
    stationary_ground_step(m);
    set_mario_animation(m, arg1);
    if (is_anim_at_end(m)) {
        return set_mario_action(m, action, 0);
    }
    return FALSE;
}

s32 check_common_landing_cancels(struct MarioState *m, u32 action) {
    if (m->input & INPUT_STOMPED) {
        return set_mario_action(m, ACT_SHOCKWAVE_BOUNCE, 0);
    }

    if (m->input & INPUT_FIRST_PERSON) {
        return set_mario_action(m, ACT_IDLE, 0);
    }

    if (m->input & INPUT_A_PRESSED) {
        if (!action) {
            return set_jump_from_landing(m);
        } else {
            return set_jumping_action(m, action, 0);
        }
    }

    if (m->input & (INPUT_NONZERO_ANALOG | INPUT_A_PRESSED | INPUT_OFF_FLOOR | INPUT_ABOVE_SLIDE)) {
        return check_common_action_exits(m);
    }

    if (m->input & INPUT_B_PRESSED) {
        return set_mario_action(m, ACT_PUNCHING, 0);
    }

    return FALSE;
}

s32 act_jump_land_stop(struct MarioState *m) {
    if (check_common_landing_cancels(m, 0)) {
        return TRUE;
    }

    if (m->prevAction == ACT_CUTSCENE_JUMP && m->floor != NULL && m->floor->type == SURFACE_RISE_STUCK_DIRT) {
        drop_and_set_mario_action(m, ACT_FEET_STUCK_IN_GROUND, 0);
        return TRUE;
    }

    landing_step(m, MARIO_ANIM_LAND_FROM_SINGLE_JUMP, ACT_IDLE);
    return FALSE;
}

s32 act_double_jump_land_stop(struct MarioState *m) {
    if (check_common_landing_cancels(m, 0)) {
        return TRUE;
    }

    landing_step(m, MARIO_ANIM_LAND_FROM_DOUBLE_JUMP, ACT_IDLE);
    return FALSE;
}

s32 act_side_flip_land_stop(struct MarioState *m) {
    if (check_common_landing_cancels(m, 0)) {
        return TRUE;
    }

    landing_step(m, MARIO_ANIM_SLIDEFLIP_LAND, ACT_IDLE);
    m->marioObj->header.gfx.angle[1] += 0x8000;
    return FALSE;
}

s32 act_freefall_land_stop(struct MarioState *m) {
    if (check_common_landing_cancels(m, 0)) {
        return TRUE;
    }

    landing_step(m, MARIO_ANIM_GENERAL_LAND, ACT_IDLE);
    return FALSE;
}

s32 act_triple_jump_land_stop(struct MarioState *m) {
    /*if (m->input & INPUT_NONZERO_ANALOG) {
        return set_mario_action(m, ACT_IDLE, 0);
    }*/
    if (check_common_landing_cancels(m, ACT_JUMP)) {
        return TRUE;
    }

    landing_step(m, MARIO_ANIM_TRIPLE_JUMP_LAND, ACT_IDLE);
    return FALSE;
}

s32 act_backflip_land_stop(struct MarioState *m) {
    if (!(m->input & INPUT_Z_DOWN) || m->marioObj->header.gfx.animInfo.animFrame >= 6) {
        m->input &= ~INPUT_A_PRESSED;
    }

    if (check_common_landing_cancels(m, ACT_BACKFLIP)) {
        return TRUE;
    }

    landing_step(m, MARIO_ANIM_TRIPLE_JUMP_LAND, ACT_IDLE);
    return FALSE;
}

s32 act_lava_boost_land(struct MarioState *m) {
    m->input &= ~(INPUT_FIRST_PERSON | INPUT_B_PRESSED);

    if (check_common_landing_cancels(m, 0)) {
        return TRUE;
    }

    landing_step(m, MARIO_ANIM_STAND_UP_FROM_LAVA_BOOST, ACT_IDLE);
    return FALSE;
}

s32 act_long_jump_land_stop(struct MarioState *m) {
    m->input &= ~INPUT_B_PRESSED;
    if (check_common_landing_cancels(m, ACT_JUMP)) {
        return TRUE;
    }

    landing_step(m, !m->marioObj->oMarioLongJumpIsSlow ? MARIO_ANIM_CROUCH_FROM_FAST_LONGJUMP
                                                       : MARIO_ANIM_CROUCH_FROM_SLOW_LONGJUMP,
                 ACT_CROUCHING);
    return FALSE;
}

s32 act_hold_jump_land_stop(struct MarioState *m) {
    if (m->marioObj->oInteractStatus & INT_STATUS_MARIO_DROP_OBJECT) {
        return drop_and_set_mario_action(m, ACT_IDLE, 0);
    }

    if (m->input & INPUT_STOMPED) {
        return drop_and_set_mario_action(m, ACT_SHOCKWAVE_BOUNCE, 0);
    }

    if (m->input & (INPUT_NONZERO_ANALOG | INPUT_A_PRESSED | INPUT_OFF_FLOOR | INPUT_ABOVE_SLIDE)) {
        return check_common_hold_action_exits(m);
    }

    if (m->input & INPUT_B_PRESSED) {
        return set_mario_action(m, ACT_THROWING, 0);
    }

    landing_step(m, MARIO_ANIM_JUMP_LAND_WITH_LIGHT_OBJ, ACT_HOLD_IDLE);
    return FALSE;
}

s32 act_hold_freefall_land_stop(struct MarioState *m) {
    if (m->marioObj->oInteractStatus & INT_STATUS_MARIO_DROP_OBJECT) {
        return drop_and_set_mario_action(m, ACT_IDLE, 0);
    }

    if (m->input & INPUT_STOMPED) {
        return drop_and_set_mario_action(m, ACT_SHOCKWAVE_BOUNCE, 0);
    }

    if (m->input & (INPUT_NONZERO_ANALOG | INPUT_A_PRESSED | INPUT_OFF_FLOOR | INPUT_ABOVE_SLIDE)) {
        return check_common_hold_action_exits(m);
    }

    if (m->input & INPUT_B_PRESSED) {
        return set_mario_action(m, ACT_THROWING, 0);
    }
    landing_step(m, MARIO_ANIM_FALL_LAND_WITH_LIGHT_OBJ, ACT_HOLD_IDLE);
    return FALSE;
}

s32 act_air_throw_land(struct MarioState *m) {
    if (m->input & INPUT_STOMPED) {
        return set_mario_action(m, ACT_SHOCKWAVE_BOUNCE, 0);
    }

    if (m->input & INPUT_OFF_FLOOR) {
        return set_mario_action(m, ACT_FREEFALL, 0);
    }

    if (++m->actionTimer == 4) {
        mario_throw_held_object(m);
    }

    landing_step(m, MARIO_ANIM_THROW_LIGHT_OBJECT, ACT_IDLE);
    return FALSE;
}

s32 act_twirl_land(struct MarioState *m) {
    m->actionState = 1;
    if (m->input & INPUT_STOMPED) {
        return set_mario_action(m, ACT_SHOCKWAVE_BOUNCE, 0);
    }

    if (m->input & INPUT_OFF_FLOOR) {
        return set_mario_action(m, ACT_FREEFALL, 0);
    }

    stationary_ground_step(m);
    set_mario_animation(m, MARIO_ANIM_TWIRL_LAND);
    if (m->angleVel[1] > 0) {
        m->angleVel[1] -= 0x400;
        if (m->angleVel[1] < 0) {
            m->angleVel[1] = 0;
        }

        m->twirlYaw += m->angleVel[1];
    }

    m->marioObj->header.gfx.angle[1] += m->twirlYaw;
    if (is_anim_at_end(m) && m->angleVel[1] == 0) {
        m->faceAngle[1] += m->twirlYaw;
        set_mario_action(m, ACT_IDLE, 0);
    }

    return FALSE;
}

Vec3f sSpawnedTokens[] = {
{-1831.0f, 80.0f, -6211.0f},
{-1214.25f, 46.13f, -150.62f},
{-108.0f, 11838.0f, -16714.0f},
{-5850.0f, 160.0f, 5280.0f},
{3690.0f, 683.0f, 16950.0f},
{2683.0f, 555.0f, -4934.0f},
{16240.0f, -130.0f, 0.0f},
{-2350.0f, -335.0f, -5075.0f},
{-20658.0f, 3975.0f, -15649.0f},
{0.0f, 0.0f, 0.0f},
{0.0f, 0.0f, 0.0f},
};

void spawn_token(u8 type, u8 index, Vec3f pos, s16 yaw, s16 pitch) {
    struct Object *obj = spawn_object(gMarioObject, MODEL_TOKEN, bhvToken);
    obj->oBehParams = (type << 16) | (index << 8);
    obj->oBehParams2ndByte = type;
    obj->oFaceAnglePitch = pitch;
    obj->oFaceAngleYaw = yaw;
    obj->oFaceAngleRoll = 0;
    vec3f_copy(&obj->oPosX, pos);
    spawn_object(obj, MODEL_NONE, bhvSparkleSpawn);
    play_sound(SOUND_GENERAL2_RIGHT_ANSWER, gGlobalSoundSource);
}

extern s16 gComitCutsceneTimer;
extern Vec3f gComitCutscenePosVec;
extern Vec3f gComitCutsceneFocVec;


void handle_ground_pound_floor(struct MarioState *m) {
    struct Object *obj;
    s32 index = m->floor->force;
    if (save_file_get_gpflags() & (1 << index)) {
        return;
    }
    switch (index) {
        case 0:
            spawn_token(1, 0x16, sSpawnedTokens[0], 0, 0);
            break;
        case 1:
            spawn_token(2, 0x22, sSpawnedTokens[1], 0x4000, 0); // WAS 0x18
            break;
        case 2:
            spawn_token(0, 0x1D, sSpawnedTokens[2], 0x2000, 0);
            break;
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 10:
            // obj_spawn_loot_coins(gMarioObject, 1, 20.0f, bhvSingleCoinGetsSpawned, 0, MODEL_YELLOW_COIN);
            obj = spawn_object(gMarioObject, MODEL_YELLOW_COIN, bhvSingleCoinGetsSpawned);
            // obj->oPosY += 200.0f;
            break;
        case 11:
            // obj_spawn_loot_coins(gMarioObject, 1, 20.0f, bhvSingleCoinGetsSpawned, 0, MODEL_YELLOW_COIN);
            obj = spawn_object(gMarioObject, MODEL_BLUE_COIN, bhvMrIBlueCoin);
            // obj->oPosY += 200.0f;
            break;
        case 8:
            spawn_token(2, 0x2E, sSpawnedTokens[3], 0, 0); // WAS 0x25
            break;
        case 9:
            spawn_token(1, 0x07, sSpawnedTokens[4], 0, 0xC000);
            break;
        case 12:
            spawn_token(1, 0x15, sSpawnedTokens[5], 0, 0xC000);
            break;
        case 13:
            if (!(save_file_get_golden_goombas() & (1 << 6))) {
                save_file_set_golden_goombas(6);
                play_puzzle_jingle();
                obj = spawn_object(gMarioObject, MODEL_GOLDEN_GOOMBA, bhvGoldenGoomba);
                vec3f_set(&obj->oPosX, 1000.0f, 800.0f, -4000.0f);
                gCamera->comitCutscene = 0xFF;
                gComitCutsceneTimer = 45;
                obj->os16110 = 3045;
                vec3f_set(gComitCutscenePosVec, gMarioState->pos[0], gMarioState->pos[1] + 1000.0f, gMarioState->pos[2]);
                vec3f_copy(gComitCutsceneFocVec, &obj->oPosX);
            }
            break;
        case 14:
            if (!(save_file_get_golden_goombas() & (1 << 9))) {
                save_file_set_golden_goombas(9);
                play_puzzle_jingle();
                obj = spawn_object(gMarioObject, MODEL_GOLDEN_GOOMBA, bhvGoldenGoomba);
                vec3f_set(&obj->oPosX, 4800.0f, 800.0f, -2000.0f);
                gCamera->comitCutscene = 0xFF;
                gComitCutsceneTimer = 45;
                obj->os16110 = 3045;
                vec3f_set(gComitCutscenePosVec, gMarioState->pos[0] + 500.0f, gMarioState->pos[1] + 700.0f, gMarioState->pos[2] + 1200.0f);
                vec3f_copy(gComitCutsceneFocVec, &obj->oPosX);
            }
            break;
        case 15:
            spawn_token(2, 0x2D, sSpawnedTokens[7], 0, 0x0000);
            break;
        case 16:
            spawn_object(gMarioObject, MODEL_NONE, bhvTenBlueCoinsSpawn);
            break;
        case 17:
            spawn_object(gMarioObject, MODEL_NONE, bhvTenBlueCoinsSpawn);
            break;
        case 18:
            if (!(save_file_get_golden_goombas() & (1 << 12))) {
                save_file_set_golden_goombas(12);
                play_puzzle_jingle();
                obj = spawn_object(gMarioObject, MODEL_GOLDEN_GOOMBA, bhvGoldenGoomba);
                vec3f_set(&obj->oPosX, 12000.0f, 7800.0f, -9000.0f);
                gCamera->comitCutscene = 0xFF;
                gComitCutsceneTimer = 45;
                obj->os16110 = 3045;
                vec3f_set(gComitCutscenePosVec, gMarioState->pos[0] + 500.0f, gMarioState->pos[1] + 700.0f, gMarioState->pos[2] - 1200.0f);
                vec3f_copy(gComitCutsceneFocVec, &obj->oPosX);
            }
            break;
        case 19:
        case 20:
        case 21:
            obj = spawn_object(gMarioObject, MODEL_BLUE_COIN, bhvMrIBlueCoinNoSpeed);
            break;
        case 22:
            spawn_token(1, 0x3B, sSpawnedTokens[8], 0, 0x0000);
            break;
        // 23, 24, 25, 26, and 27 are taken by dirt mounds in entrance
        case 28:
            obj = spawn_object(gMarioObject, MODEL_BLUE_COIN, bhvMrIBlueCoinNoSpeed);
            break;
    }
    save_file_set_gpflags(1 << index);
}


s32 act_ground_pound_land(struct MarioState *m) {
    m->actionState = 1;

    if (m->floor != NULL && m->floor->type == SURFACE_GP_FLOOR) {
        handle_ground_pound_floor(m);
    }

    if (m->input & INPUT_STOMPED) {
        return drop_and_set_mario_action(m, ACT_SHOCKWAVE_BOUNCE, 0);
    }

    if (m->input & INPUT_OFF_FLOOR) {
        return set_mario_action(m, ACT_FREEFALL, 0);
    }

    if (m->input & INPUT_ABOVE_SLIDE) {
        return set_mario_action(m, ACT_BUTT_SLIDE, 0);
    }

    landing_step(m, MARIO_ANIM_GROUND_POUND_LANDING, ACT_BUTT_SLIDE_STOP);
    return FALSE;
}

s32 act_first_person(struct MarioState *m) {
    s32 sp1C = (m->input & (INPUT_OFF_FLOOR | INPUT_ABOVE_SLIDE | INPUT_STOMPED)) != 0;

    if (m->actionState == 0) {
        lower_background_noise(2);
        set_camera_mode(m->area->camera, CAMERA_MODE_C_UP, 0x10);
        m->actionState = 1;
    } else if (!(m->input & INPUT_FIRST_PERSON) || sp1C) {
        raise_background_noise(2);
        // Go back to the last camera mode
        set_camera_mode(m->area->camera, -1, 1);
        return set_mario_action(m, ACT_IDLE, 0);
    }

    if (m->floor->type == SURFACE_LOOK_UP_WARP
        && save_file_get_total_star_count(gCurrSaveFileNum - 1, COURSE_MIN - 1, COURSE_MAX - 1) >= 10) {
        s16 sp1A = m->statusForCamera->headRotation[0];
        s16 sp18 = ((m->statusForCamera->headRotation[1] * 4) / 3) + m->faceAngle[1];
        if (sp1A == -0x1800 && (sp18 < -0x6FFF || sp18 >= 0x7000)) {
            level_trigger_warp(m, WARP_OP_UNKNOWN_01);
        }
    }

    stationary_ground_step(m);
    set_mario_animation(m, MARIO_ANIM_FIRST_PERSON);
    return FALSE;
}



s32 act_tight_rope(struct MarioState *m) {
    f32 addedVel = 0.0f;
    if (m->faceAngle[1] != m->intendedYaw) {
        m->faceAngle[1] = m->intendedYaw;
        gRopeCamera = 1;
    }

    if (m->input & INPUT_A_PRESSED) {
        gRopeCamera = 1;
        if (m->marioObj->platform != NULL) {
            addedVel = m->marioObj->platform->oFloat100;
        }
        if (addedVel < 10.0f) {
            set_jumping_action(m, ACT_JUMP, 0);
        } else {
            set_jumping_action(m, ACT_TRIPLE_JUMP, 0);
        }
        m->vel[1] = 40.0f + (addedVel * 1.4f);
        m->pos[1] += m->vel[1];
        return TRUE;
    }

    if (m->input & INPUT_OFF_FLOOR) {
        return set_mario_action(m, ACT_FREEFALL, 0);
    }
    if (m->floor == NULL || m->floor->type != SURFACE_TIGHT_ROPE) {
        return set_mario_action(m, ACT_FREEFALL, 0);
    }

    if (m->input & INPUT_NONZERO_ANALOG) {
        m->faceAngle[1] = (s16) m->intendedYaw;
        set_mario_action(m, ACT_TIGHT_ROPE_WALKING, 0);
        return TRUE;
    }
    set_mario_anim_with_accel(m, MARIO_ANIM_TIGHTROPE_WALK, 0);
    // m->marioObj->header.gfx.animInfo.animFrame = 0;

    stationary_ground_step(m);

    if (gPlayer1Controller->buttonDown & (L_JPAD | R_JPAD) || 
        gPlayer1Controller->buttonPressed & (R_TRIG | U_JPAD | D_JPAD | R_CBUTTONS | L_CBUTTONS)) {
            gRopeCamera = 1;
    }

    return FALSE;
}




s32 check_common_stationary_cancels(struct MarioState *m) {
    if (m->pos[1] < m->waterLevel - 100) {
        if (m->action == ACT_SPAWN_SPIN_LANDING) {
            load_level_init_text(0);
        }
        update_mario_sound_and_camera(m);
        return set_water_plunge_action(m);
    }

    if (m->input & INPUT_SQUISHED) {
        update_mario_sound_and_camera(m);
        return drop_and_set_mario_action(m, ACT_SQUISHED, 0);
    }

    if (m->action != ACT_UNKNOWN_0002020E) {
        if (m->health < 0x100) {
            update_mario_sound_and_camera(m);
            return drop_and_set_mario_action(m, ACT_STANDING_DEATH, 0);
        }
    }
    return FALSE;
}

s32 mario_execute_stationary_action(struct MarioState *m) {
    s32 cancel;

    if (check_common_stationary_cancels(m)) {
        return TRUE;
    }

    if (mario_update_quicksand(m, 0.5f)) {
        return TRUE;
    }

    /* clang-format off */
    switch (m->action) {
        case ACT_IDLE:                    cancel = act_idle(m);                             break;
        case ACT_START_SLEEPING:          cancel = act_start_sleeping(m);                   break;
        case ACT_SLEEPING:                cancel = act_sleeping(m);                         break;
        case ACT_WAKING_UP:               cancel = act_waking_up(m);                        break;
        case ACT_PANTING:                 cancel = act_panting(m);                          break;
        case ACT_HOLD_PANTING_UNUSED:     cancel = act_hold_panting_unused(m);              break;
        case ACT_HOLD_IDLE:               cancel = act_hold_idle(m);                        break;
        case ACT_HOLD_HEAVY_IDLE:         cancel = act_hold_heavy_idle(m);                  break;
        case ACT_IN_QUICKSAND:            cancel = act_in_quicksand(m);                     break;
        case ACT_STANDING_AGAINST_WALL:   cancel = act_standing_against_wall(m);            break;
        case ACT_COUGHING:                cancel = act_coughing(m);                         break;
        case ACT_SHIVERING:               cancel = act_shivering(m);                        break;
        case ACT_CROUCHING:               cancel = act_crouching(m);                        break;
        case ACT_START_CROUCHING:         cancel = act_start_crouching(m);                  break;
        case ACT_STOP_CROUCHING:          cancel = act_stop_crouching(m);                   break;
        case ACT_START_CRAWLING:          cancel = act_start_crawling(m);                   break;
        case ACT_STOP_CRAWLING:           cancel = act_stop_crawling(m);                    break;
        case ACT_SLIDE_KICK_SLIDE_STOP:   cancel = act_slide_kick_slide_stop(m);            break;
        case ACT_SHOCKWAVE_BOUNCE:        cancel = act_shockwave_bounce(m);                 break;
        case ACT_FIRST_PERSON:            cancel = act_first_person(m);                     break;
        case ACT_TIGHT_ROPE:              cancel = act_tight_rope(m);                       break;
        case ACT_JUMP_LAND_STOP:          cancel = act_jump_land_stop(m);                   break;
        case ACT_DOUBLE_JUMP_LAND_STOP:   cancel = act_double_jump_land_stop(m);            break;
        case ACT_FREEFALL_LAND_STOP:      cancel = act_freefall_land_stop(m);               break;
        case ACT_SIDE_FLIP_LAND_STOP:     cancel = act_side_flip_land_stop(m);              break;
        case ACT_HOLD_JUMP_LAND_STOP:     cancel = act_hold_jump_land_stop(m);              break;
        case ACT_HOLD_FREEFALL_LAND_STOP: cancel = act_hold_freefall_land_stop(m);          break;
        case ACT_AIR_THROW_LAND:          cancel = act_air_throw_land(m);                   break;
        case ACT_LAVA_BOOST_LAND:         cancel = act_lava_boost_land(m);                  break;
        case ACT_TWIRL_LAND:              cancel = act_twirl_land(m);                       break;
        case ACT_TRIPLE_JUMP_LAND_STOP:   cancel = act_triple_jump_land_stop(m);            break;
        case ACT_BACKFLIP_LAND_STOP:      cancel = act_backflip_land_stop(m);               break;
        case ACT_LONG_JUMP_LAND_STOP:     cancel = act_long_jump_land_stop(m);              break;
        case ACT_GROUND_POUND_LAND:       cancel = act_ground_pound_land(m);                break;
        case ACT_BRAKING_STOP:            cancel = act_braking_stop(m);                     break;
        case ACT_BUTT_SLIDE_STOP:         cancel = act_butt_slide_stop(m);                  break;
        case ACT_HOLD_BUTT_SLIDE_STOP:    cancel = act_hold_butt_slide_stop(m);             break;
    }
    /* clang-format on */

    if (!cancel && (m->input & INPUT_IN_WATER)) {
        m->particleFlags |= PARTICLE_IDLE_WATER_WAVE;
    }

    return cancel;
}
