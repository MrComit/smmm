/**
--------------Puppyprint 1.0 by Fazana--------------
Includes a few printing functions to fit any purpose.
print_small_text is intended to replace print_generic_string in use, as it uses a far more optimised way of doing things,
supports real time ascii conversion, and also supports many fun effects to spice up the text.
Any usage of gDPSetEnvColor should ideally be replaced with print_set_envcolour because it helps with some optimisations.
render_multi_image can be used to draw large texture rectangles consisting of multiple images on the screen.
You only need have the single image in its full form, with no need for splitting it, and simply just load it.

As for the profiler, you can hold dpad up, and press L to toggle the display.
Inside this display, if you press up on the dpad again, you can switch between performance, and memory view.
If you press dpad down, you can toggle the benchmarking display.
You can press dpad left or right to change which option, and you can measure game thread or audio thread performance by default.
There's also a custom option that's left blank. It runs benchmark_custom which can contain anything of your choice.
You can press dpad right to cycle between collision visuals, from surface collision, hitbox collision, both, or neither.
dpad left will toggle the logging view, which will display a number of strings you've sent through for debugging purposes, like
a modern game engine's developer's console.

- Collision marks the time it takes to generate and process collision.
- Behaviour marks the time it takes for objects to perform their behaviours. This excludes collision.
- Graph measures the time it takes to process the node graphs, which is all the 3D geometry and rendering.
- Audio measures the time it takes to process the audio samples, this excludes time spent loading.
- DMA measures the time it takes to load things. In Vanilla, Mario's animations and audio samples are loaded from ROM as needed.
**/

#include <ultra64.h>

#ifdef PUPPYPRINT

#include "config.h"
#include "game_init.h"
#include "memory.h"
#include "print.h"
#include "string.h"
#include "stdarg.h"
#include "printf.h"
#include "engine/math_util.h"
#include "engine/behavior_script.h"
#include "camera.h"
#include "puppyprint.h"
#include "level_update.h"
#include "object_list_processor.h"
#include "engine/surface_load.h"
#include "audio/data.h"
#include "hud.h"
#include "debug_box.h"

ColorRGBA currEnv;
u8 fDebug = FALSE;

#if PUPPYPRINT_DEBUG
s8 benchViewer = FALSE;
u8 benchOption = 0;
s8 logViewer = FALSE;
// Profiler values
s8  perfIteration = 0;
s16 benchmarkLoop = 0;
s32 benchmarkTimer = 0;
s32 benchmarkProgramTimer = 0;
s8  benchmarkType = 0;
// General
OSTime cpuTime = 0;
OSTime rspTime = 0;
OSTime rdpTime = 0;
OSTime ramTime = 0;
OSTime loadTime = 0;
OSTime gLastOSTime = 0;
OSTime rspDelta = 0;
s32       benchMark[NUM_BENCH_ITERATIONS + 2];
// CPU
OSTime collisionTime[NUM_PERF_ITERATIONS + 1];
OSTime behaviourTime[NUM_PERF_ITERATIONS + 1];
OSTime    scriptTime[NUM_PERF_ITERATIONS + 1];
OSTime     graphTime[NUM_PERF_ITERATIONS + 1];
OSTime     audioTime[NUM_PERF_ITERATIONS + 1];
OSTime       dmaTime[NUM_PERF_ITERATIONS + 1];
OSTime  dmaAudioTime[NUM_PERF_ITERATIONS + 1];
OSTime     faultTime[NUM_PERF_ITERATIONS + 1];
OSTime      taskTime[NUM_PERF_ITERATIONS + 1];
OSTime  profilerTime[NUM_PERF_ITERATIONS + 1];
OSTime profilerTime2[NUM_PERF_ITERATIONS + 1];
// RSP
OSTime     audioTime[NUM_PERF_ITERATIONS + 1];
OSTime    rspGenTime[NUM_PERF_ITERATIONS + 1];
// RDP
OSTime    bufferTime[NUM_PERF_ITERATIONS + 1];
OSTime      tmemTime[NUM_PERF_ITERATIONS + 1];
OSTime       busTime[NUM_PERF_ITERATIONS + 1];
// RAM
s8  ramViewer = FALSE;
s32 ramsizeSegment[33] = { 0, 0, 0,
                           0, 0, 0,
                           0, 0, 0,
                           0, 0, 0,
                           0, 0, 0,
                           0, 0, 0,
                           0, 0, 0,
                           0, 0, 0,
                           0, 0, 0,
                           0, 0, 0,
                           0, 0, 0 };
s32 audioPool[12];
s32 mempool;

extern u8 _mainSegmentStart[];
extern u8 _mainSegmentEnd[];
extern u8 _engineSegmentStart[];
extern u8 _engineSegmentEnd[];
extern u8 _framebuffersSegmentBssStart[];
extern u8 _framebuffersSegmentBssEnd[];
extern u8 _buffersSegmentBssStart[];
extern u8 _buffersSegmentBssEnd[];
extern u8 _goddardSegmentStart[];
extern u8 _goddardSegmentEnd[];

// Here is stored the rom addresses of the global code segments. If you get rid of any, it's best to just write them as NULL.
s32 ramP[5][2] = {
    {(u32)&_buffersSegmentBssStart,      (u32)&_buffersSegmentBssEnd},
    {(u32)&_mainSegmentStart,            (u32)&_mainSegmentEnd},
    {(u32)&_engineSegmentStart,          (u32)&_engineSegmentEnd},
    {(u32)&_framebuffersSegmentBssStart, (u32)&_framebuffersSegmentBssEnd},
    {(u32)&_goddardSegmentStart,         (u32)&_goddardSegmentEnd},
};

void puppyprint_calculate_ram_usage(void) {
    s32 temp[2];
    s32 i = 0;

    for (i = 0; i < 5; i++) {
        if (!ramP[i][0] || !ramP[i][1]) {
            continue;
        }
        temp[0] = ramP[i][0];
        temp[1] = ramP[i][1];
        ramsizeSegment[i] = temp[1] - temp[0];
    }

    // These are a bit hacky, but what can ye do eh?
    // gEffectsMemoryPool is 0x4000, gObjectsMemoryPool is 0x800. Epic C limitations mean I can't just sizeof their values :)
    ramsizeSegment[5] = 0x4000 + 0x800 + 0x4000 + 0x800;
    ramsizeSegment[6] = (SURFACE_NODE_POOL_SIZE * sizeof(struct SurfaceNode)) + (SURFACE_POOL_SIZE * sizeof(struct Surface));
    ramsizeSegment[7] = gAudioHeapSize + gAudioInitPoolSize;
    ramsizeSegment[8] = audioPool[0] + audioPool[1] + audioPool[2] + audioPool[3] + audioPool[4] + audioPool[5] +
                        audioPool[6] + audioPool[7] + audioPool[8] + audioPool[9] + audioPool[10] + audioPool[11];
}

void puppyprint_profiler_finished(void) {
    s32 i = 0;
    benchMark[NUM_BENCH_ITERATIONS] = 0;
    benchMark[NUM_BENCH_ITERATIONS+1] = 0;
    benchmarkTimer = 300;
    benchViewer = FALSE;
    for (i = 0; i < NUM_BENCH_ITERATIONS - 2; i++) {
        benchMark[NUM_BENCH_ITERATIONS] += benchMark[i];
        if (benchMark[i] > benchMark[NUM_BENCH_ITERATIONS + 1]) {
            benchMark[NUM_BENCH_ITERATIONS + 1] = benchMark[i];
        }
    }
    benchMark[NUM_BENCH_ITERATIONS] /= NUM_BENCH_ITERATIONS;
    benchmarkProgramTimer = OS_CYCLES_TO_USEC(osGetTime() - benchmarkProgramTimer);
}

// RGB colour lookup table for colouring all the funny ram prints.
u8 colourChart[33][3] = {
    { 255,   0,   0 },
    {   0,   0, 255 },
    {   0, 255,   0 },
    { 255, 255,   0 },
    { 255,   0, 255 },
    { 255, 127,   0 },
    {   0, 255, 255 },
    {  51, 255,  51 },
    { 255, 153, 153 },
    { 204,   0, 102 },
    {   0, 153, 153 },
    { 153, 255, 153 },
    {   0,   0, 128 },
    { 128,   0, 128 },
    { 218, 165,  32 },
    { 107, 142,  35 },
    { 188, 143, 143 },
    { 210, 105,  30 },
    { 154, 205,  50 },
    { 165,  42,  42 },
    { 255, 105, 180 },
    { 139,  69,  19 },
    { 250, 240, 230 },
    {  95, 158, 160 },
    {  60, 179, 113 },
    { 255,  69,   0 },
    { 128,   0,   0 },
    { 216, 191, 216 },
    { 244, 164,  96 },
    { 176, 196, 222 },
    { 255, 255, 255 }};

// Change this to alter the width of the bar at the bottom.
#define BAR_LENGTH 200

void print_ram_bar(void) {
    s32 i = 0;
    f32 perfPercentage;
    s32 graphPos = 0;
    s32 prevGraph = (SCREEN_WIDTH/2) - (BAR_LENGTH / 2);
    s32 ramsize = osGetMemSize();

    prepare_blank_box();

    for (i = 0; i < 32; i++) {
        if (ramsizeSegment[i] == 0) {
            continue;
        }
        perfPercentage = (f32)ramsizeSegment[i]/ramsize;
        graphPos = prevGraph + CLAMP((BAR_LENGTH * perfPercentage), 1, (SCREEN_WIDTH/2) + (BAR_LENGTH / 2));
        render_blank_box(prevGraph, SCREEN_HEIGHT-30, graphPos, SCREEN_HEIGHT-22, colourChart[i][0], colourChart[i][1], colourChart[i][2], 255);
        prevGraph = graphPos;
    }
    perfPercentage = (f32)ramsizeSegment[32]/ramsize;
    graphPos = prevGraph + CLAMP((BAR_LENGTH * perfPercentage), 1, (SCREEN_WIDTH/2) + (BAR_LENGTH / 2));
    render_blank_box(prevGraph, SCREEN_HEIGHT-30, graphPos, SCREEN_HEIGHT-22, 255, 255, 255, 255);
    prevGraph = graphPos;

    render_blank_box(prevGraph, SCREEN_HEIGHT-30, (SCREEN_WIDTH/2)+(BAR_LENGTH / 2), SCREEN_HEIGHT-22, 0, 0, 0, 255);

    finish_blank_box();
}

// Another epic lookup table, for text this time.
const char ramNames[9][32] = {
    "Buffers",
    "Main",
    "Engine",
    "Framebuffers",
    "Goddard",
    "Pools",
    "Collision",
    "Audio Heap",
    "Audio Pools",
};

s8 nameTable = sizeof(ramNames) / 32;

void print_ram_overview(void) {
    s32 i = 0;
    char textBytes[32];
    s32 x = 80;
    s32 y = 16;
    s32 drawn = 0;
    prepare_blank_box();
    render_blank_box(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0, 0, 192);
    finish_blank_box();

    for (i = 0; i < 33; i++) {
        if (drawn == 16) {
            x = 240;
            y = 16;
        }
        if (ramsizeSegment[i] == 0) {
            continue;
        }
        if (i < 9) {
            sprintf(textBytes, "%s: %X", ramNames[i], ramsizeSegment[i]);
        } else {
            sprintf(textBytes, "Segment %02X: %X", i - nameTable + 2, ramsizeSegment[i]);
        }
        print_set_envcolour(colourChart[i][0], colourChart[i][1], colourChart[i][2], 255);
        print_small_text(x, y, textBytes, PRINT_TEXT_ALIGN_CENTRE, PRINT_ALL, FONT_DEFAULT);
        y += 12;
        drawn++;
    }
}

void benchmark_custom(void) {
    if (benchmarkLoop == 0 || benchOption != 2) {
        return;
    }
    OSTime lastTime;
    while (TRUE) {
        lastTime = osGetTime();
        // Insert your function here!

        if (benchmarkLoop > 0 && benchOption == 2) {
            benchmarkLoop--;
            benchMark[benchmarkLoop] = osGetTime() - lastTime;
            if (benchmarkLoop == 0) {
                puppyprint_profiler_finished();
                break;
            }
        } else {
            break;
        }
    }
}

const char benchNames[][32] = {
    "Game Thread",
    "Audio Thread",
    "Custom",
};

void print_which_benchmark(void) {
    char textBytes[40];

    prepare_blank_box();
    render_blank_box((SCREEN_WIDTH/2)-50, 115, (SCREEN_WIDTH/2)+50, 160, 0, 0, 0, 255);
    finish_blank_box();
    sprintf(textBytes, "Select Option#%s#L: Confirm", benchNames[benchOption]);
    print_small_text((SCREEN_WIDTH/2),120, textBytes, PRINT_TEXT_ALIGN_CENTRE, PRINT_ALL, FONT_DEFAULT);
}

char consoleLogTable[LOG_BUFFER_SIZE][255];

static char *write_to_buf(char *buffer, const char *data, size_t size) {
    return (char *) memcpy(buffer, data, size) + size;
}

void append_puppyprint_log(const char *str, ...) {
    s32 i;
    char textBytes[255];

    memset(textBytes, 0, sizeof(textBytes));
    va_list arguments;
    va_start(arguments, str);
    if ((_Printf(write_to_buf, textBytes, str, arguments)) <= 0) {
        va_end(arguments);
        return;
    }
#ifdef UNF
    osSyncPrintf(textBytes);
#endif
    for (i = 0; i < LOG_BUFFER_SIZE-1; i++) {
        memcpy(consoleLogTable[i], consoleLogTable[i + 1], 255);
    }
        memcpy(consoleLogTable[LOG_BUFFER_SIZE - 1], textBytes, 255);
    va_end(arguments);
}

#define LINE_HEIGHT 8 + ((LOG_BUFFER_SIZE - 1) * 12)
void print_console_log(void) {
    s32 i;
    prepare_blank_box();
    render_blank_box(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0, 0, 96);
    finish_blank_box();
    for (i = 0; i < LOG_BUFFER_SIZE; i++) {
        if (consoleLogTable[i] == NULL) {
            continue;
        }
        print_small_text(16, (LINE_HEIGHT) - (i * 12), consoleLogTable[i], PRINT_TEXT_ALIGN_LEFT, PRINT_ALL, FONT_DEFAULT);
    }
}
#undef LINE_HEIGHT

extern void print_fps(s32 x, s32 y);

void puppyprint_render_profiler(void) {
    s32 perfPercentage[5];
    s32 graphPos;
    s32 prevGraph;
#ifdef PUPPYPRINT_DEBUG_CYCLES
    OSTime cpuCount = (cpuTime + audioTime[NUM_PERF_ITERATIONS] + dmaAudioTime[NUM_PERF_ITERATIONS] + faultTime[NUM_PERF_ITERATIONS]
                               + taskTime[NUM_PERF_ITERATIONS] - profilerTime[NUM_PERF_ITERATIONS] - profilerTime2[NUM_PERF_ITERATIONS]);
#else
    OSTime cpuCount = OS_CYCLES_TO_USEC(cpuTime+audioTime[NUM_PERF_ITERATIONS] + dmaAudioTime[NUM_PERF_ITERATIONS] + faultTime[NUM_PERF_ITERATIONS]
                                        + taskTime[NUM_PERF_ITERATIONS] - profilerTime[NUM_PERF_ITERATIONS] - profilerTime2[NUM_PERF_ITERATIONS]);
#endif
    OSTime first = osGetTime();
    char textBytes[80];

    if (!fDebug) {
        profiler_update(profilerTime, first);
        return;
    }

    sprintf(textBytes, "RAM: %06X /%06X (%d_)", main_pool_available(), mempool, (s32)(((f32)main_pool_available() / (f32)mempool) * 100));
    print_small_text((SCREEN_WIDTH/2), SCREEN_HEIGHT-16, textBytes, PRINT_TEXT_ALIGN_CENTRE, PRINT_ALL, FONT_OUTLINE);

    if (!ramViewer && !benchViewer && !logViewer) {
        print_fps(16,40);
#ifdef PUPPYPRINT_DEBUG_CYCLES
        sprintf(textBytes, "CPU: %dc (%d_)#RSP: %dc (%d_)#RDP: %dc (%d_)", (s32)cpuCount, (s32)(cpuCount/333), (s32)(rspTime), (s32)(rspTime)/333, (s32)(rdpTime), (s32)(rdpTime)/333);
#else
        sprintf(textBytes, "CPU: %dus (%d_)#RSP: %dus (%d_)#RDP: %dus (%d_)", (s32)cpuCount, (s32)(cpuCount / 333), (s32)OS_CYCLES_TO_USEC(rspTime), (s32)OS_CYCLES_TO_USEC(rspTime) / 333, (s32)OS_CYCLES_TO_USEC(rdpTime), (s32)OS_CYCLES_TO_USEC(rdpTime) / 333);
#endif
        print_small_text(16, 52, textBytes, PRINT_TEXT_ALIGN_LEFT, PRINT_ALL, FONT_OUTLINE);

        sprintf(textBytes, "OBJ: %d/%d", gObjectCounter, OBJECT_POOL_CAPACITY);
        print_small_text(16, 124, textBytes, PRINT_TEXT_ALIGN_LEFT, PRINT_ALL, FONT_OUTLINE);

        // Very little point printing useless info if Mayro doesn't even exist.
        if (gMarioState->marioObj) {
            sprintf(textBytes, "Mario Pos#X: %d#Y: %d#Z: %d#D: %X", (s32)(gMarioState->pos[0]), (s32)(gMarioState->pos[1]), (s32)(gMarioState->pos[2]), (u16)(gMarioState->faceAngle[1]));
            print_small_text(16, 140, textBytes, PRINT_TEXT_ALIGN_LEFT, PRINT_ALL, FONT_OUTLINE);
        }
        // Same for the camera, especially so because this will crash otherwise.
        if (gCamera) {
            sprintf(textBytes, "Camera Pos#X: %d#Y: %d#Z: %d#D: %X", (s32)(gCamera->pos[0]), (s32)(gCamera->pos[1]), (s32)(gCamera->pos[2]), (u16)(gCamera->yaw));
            print_small_text(SCREEN_WIDTH-16, 140, textBytes, PRINT_TEXT_ALIGN_RIGHT, PRINT_ALL, FONT_OUTLINE);
        }

        if (benchmarkTimer > 0) {
            benchmarkTimer--;
            prepare_blank_box();
#ifdef PUPPYPRINT_DEBUG_CYCLES
            // sprintf(textBytes, "Benchmark: %dus#High: %dc", (s32)(benchMark[NUM_BENCH_ITERATIONS]), (s32)(benchMark[NUM_BENCH_ITERATIONS + 1]));
            sprintf(textBytes, "Done in %0.000f seconds#Benchmark: %dc#High: %dc", (f32)(benchmarkProgramTimer) * 0.000001f, (s32)(benchMark[NUM_BENCH_ITERATIONS]), (s32)(benchMark[NUM_BENCH_ITERATIONS + 1]));
#else
            // sprintf(textBytes, "Benchmark: %dus#High: %dus", (s32)OS_CYCLES_TO_USEC(benchMark[NUM_BENCH_ITERATIONS]), (s32)OS_CYCLES_TO_USEC(benchMark[NUM_BENCH_ITERATIONS+1]));
            sprintf(textBytes, "Done in %0.000f seconds#Benchmark: %dus#High: %dus", (f32)(benchmarkProgramTimer) * 0.000001f, (s32)OS_CYCLES_TO_USEC(benchMark[NUM_BENCH_ITERATIONS]), (s32)OS_CYCLES_TO_USEC(benchMark[NUM_BENCH_ITERATIONS + 1]));
#endif
            render_blank_box((SCREEN_WIDTH/2) - (get_text_width(textBytes, FONT_OUTLINE) / 2) - 4, 158, (SCREEN_WIDTH/2) + (get_text_width(textBytes, FONT_OUTLINE) / 2) + 4, 196, 0, 0, 0, 255);
            print_set_envcolour(255, 255, 255, 255);
            print_small_text((SCREEN_WIDTH/2), 160, textBytes, PRINT_TEXT_ALIGN_CENTRE, PRINT_ALL, FONT_OUTLINE);
            finish_blank_box();
        }

        #define ADDTIMES MAX((collisionTime[NUM_PERF_ITERATIONS] + graphTime[NUM_PERF_ITERATIONS] + behaviourTime[NUM_PERF_ITERATIONS] + audioTime[NUM_PERF_ITERATIONS] + dmaTime[NUM_PERF_ITERATIONS])/80, 1)
        perfPercentage[0] = MAX((collisionTime[NUM_PERF_ITERATIONS] / ADDTIMES), 1);
        perfPercentage[1] = MAX((    graphTime[NUM_PERF_ITERATIONS] / ADDTIMES), 1);
        perfPercentage[2] = MAX((behaviourTime[NUM_PERF_ITERATIONS] / ADDTIMES), 1);
        perfPercentage[3] = MAX((    audioTime[NUM_PERF_ITERATIONS] / ADDTIMES), 1);
        perfPercentage[4] = MAX((      dmaTime[NUM_PERF_ITERATIONS] / ADDTIMES), 1);
        #undef ADDTIMES

#ifdef PUPPYPRINT_DEBUG_CYCLES
        sprintf(textBytes, "Collision: <COL_99505099>%dc", (s32)(collisionTime[NUM_PERF_ITERATIONS]));
        print_small_text(SCREEN_WIDTH-16, 40, textBytes, PRINT_TEXT_ALIGN_RIGHT, PRINT_ALL, FONT_OUTLINE);
        sprintf(textBytes, "Graph: <COL_50509999>%dc", (s32)(graphTime[NUM_PERF_ITERATIONS]));
        print_small_text(SCREEN_WIDTH-16, 52, textBytes, PRINT_TEXT_ALIGN_RIGHT, PRINT_ALL, FONT_OUTLINE);
        sprintf(textBytes, "Behaviour: <COL_50995099>%dc", (s32)(behaviourTime[NUM_PERF_ITERATIONS]));
        print_small_text(SCREEN_WIDTH-16, 64, textBytes, PRINT_TEXT_ALIGN_RIGHT, PRINT_ALL, FONT_OUTLINE);
        sprintf(textBytes, "Audio: <COL_99995099>%dc", (s32)(audioTime[NUM_PERF_ITERATIONS]));
        print_small_text(SCREEN_WIDTH-16, 76, textBytes, PRINT_TEXT_ALIGN_RIGHT, PRINT_ALL, FONT_OUTLINE);
        sprintf(textBytes, "DMA: <COL_99509999>%dc", (s32)(dmaTime[NUM_PERF_ITERATIONS]));
        print_small_text(SCREEN_WIDTH-16, 88, textBytes, PRINT_TEXT_ALIGN_RIGHT, PRINT_ALL, FONT_OUTLINE);
#else
        sprintf(textBytes, "Collision: <COL_99505099>%dus", (s32)OS_CYCLES_TO_USEC(collisionTime[NUM_PERF_ITERATIONS]));
        print_small_text(SCREEN_WIDTH-16, 40, textBytes, PRINT_TEXT_ALIGN_RIGHT, PRINT_ALL, FONT_OUTLINE);
        sprintf(textBytes, "Graph: <COL_50509999>%dus", (s32)OS_CYCLES_TO_USEC(graphTime[NUM_PERF_ITERATIONS]));
        print_small_text(SCREEN_WIDTH-16, 52, textBytes, PRINT_TEXT_ALIGN_RIGHT, PRINT_ALL, FONT_OUTLINE);
        sprintf(textBytes, "Behaviour: <COL_50995099>%dus", (s32)OS_CYCLES_TO_USEC(behaviourTime[NUM_PERF_ITERATIONS]));
        print_small_text(SCREEN_WIDTH-16, 64, textBytes, PRINT_TEXT_ALIGN_RIGHT, PRINT_ALL, FONT_OUTLINE);
        sprintf(textBytes, "Audio: <COL_99995099>%dus", (s32)OS_CYCLES_TO_USEC(audioTime[NUM_PERF_ITERATIONS]));
        print_small_text(SCREEN_WIDTH-16, 76, textBytes, PRINT_TEXT_ALIGN_RIGHT, PRINT_ALL, FONT_OUTLINE);
        sprintf(textBytes, "DMA: <COL_99509999>%dus", (s32)OS_CYCLES_TO_USEC(dmaTime[NUM_PERF_ITERATIONS]));
        print_small_text(SCREEN_WIDTH-16, 88, textBytes, PRINT_TEXT_ALIGN_RIGHT, PRINT_ALL, FONT_OUTLINE);
#endif

        // Render CPU breakdown bar.
        prepare_blank_box();
        graphPos = SCREEN_WIDTH-96 + perfPercentage[0];
        render_blank_box(SCREEN_WIDTH-96, 104, graphPos, 112, 255, 0, 0, 255);
        prevGraph = graphPos;
        graphPos += perfPercentage[1];
        render_blank_box(prevGraph, 104, graphPos, 112, 0, 0, 255, 255);
        prevGraph = graphPos;
        graphPos += perfPercentage[2];
        render_blank_box(prevGraph, 104, graphPos, 112, 0, 255, 0, 255);
        prevGraph = graphPos;
        graphPos += perfPercentage[3];
        render_blank_box(prevGraph, 104, graphPos, 112, 255, 255, 0, 255);
        prevGraph = graphPos;
        graphPos += perfPercentage[4];
        render_blank_box(prevGraph, 104, SCREEN_WIDTH-16, 112, 255, 0, 255, 255);
    } else if (ramViewer) {
        print_ram_overview();
    } else if (logViewer) {
        print_console_log();
    } else if (benchViewer) {
        print_which_benchmark();
    }
    print_ram_bar();
    profiler_update(profilerTime, first);
}

void profiler_update(OSTime *time, OSTime time2) {
    time[perfIteration] = osGetTime() - time2;
}

void get_average_perf_time(OSTime *time) {
    // This takes all but the last index of the timer array, and creates an average value, which is written to the last index.
    s32 i = 0;
    s32 total = 0;
    for (i = 0; i < NUM_PERF_ITERATIONS - 1; i++) {
        total += time[i];
    }
    time[NUM_PERF_ITERATIONS] = total / NUM_PERF_ITERATIONS;
}

void puppyprint_profiler_process(void) {
    bufferTime[perfIteration] = (IO_READ(DPC_BUFBUSY_REG));
    tmemTime[perfIteration] = (IO_READ(DPC_TMEM_REG));
    busTime[perfIteration] = (IO_READ(DPC_PIPEBUSY_REG));
    OSTime newTime = osGetTime();

    if ((gGlobalTimer % 15) == 0) {
        get_average_perf_time(scriptTime);
        get_average_perf_time(behaviourTime);
        get_average_perf_time(collisionTime);
        get_average_perf_time(graphTime);
        get_average_perf_time(audioTime);
        get_average_perf_time(dmaTime);
        get_average_perf_time(dmaAudioTime);
        get_average_perf_time(faultTime);
        get_average_perf_time(taskTime);
        get_average_perf_time(profilerTime);
        get_average_perf_time(profilerTime2);

        dmaTime[NUM_PERF_ITERATIONS] += dmaAudioTime[NUM_PERF_ITERATIONS];

        get_average_perf_time(rspGenTime);

        get_average_perf_time(bufferTime);
        get_average_perf_time(tmemTime);
        get_average_perf_time(busTime);

        rdpTime = bufferTime[NUM_PERF_ITERATIONS];
        rdpTime = MAX(rdpTime, tmemTime[NUM_PERF_ITERATIONS]);
        rdpTime = MAX(rdpTime, busTime[NUM_PERF_ITERATIONS]);
        cpuTime = scriptTime[NUM_PERF_ITERATIONS];
        rspTime = rspGenTime[NUM_PERF_ITERATIONS];
        puppyprint_calculate_ram_usage();
    }

    gLastOSTime = newTime;
    if (gGlobalTimer > 5) {
        IO_WRITE(DPC_STATUS_REG, DPC_CLR_CLOCK_CTR | DPC_CLR_CMD_CTR | DPC_CLR_PIPE_CTR | DPC_CLR_TMEM_CTR);
    }
    if (fDebug) {
        if (gPlayer1Controller->buttonPressed & D_JPAD) {
            benchViewer ^= TRUE;
            ramViewer = FALSE;
            logViewer = FALSE;
        } else if (gPlayer1Controller->buttonPressed & U_JPAD) {
            ramViewer ^= TRUE;
            benchViewer = FALSE;
            logViewer = FALSE;
        } else if (gPlayer1Controller->buttonPressed & L_JPAD) {
            logViewer ^= TRUE;
            ramViewer = FALSE;
            benchViewer = FALSE;
        }
#ifdef VISUAL_DEBUG
        else if (!benchViewer && !ramViewer && !logViewer) {
            debug_box_input();
        }
#endif
        if (benchViewer) {
            if (gPlayer1Controller->buttonPressed & R_JPAD) benchOption++;
            if (gPlayer1Controller->buttonPressed & L_JPAD) benchOption--;
            if (benchOption == 255) benchOption = 2;
            if (benchOption >    2) benchOption = 0;
            if (gPlayer1Controller->buttonPressed & L_TRIG) {
                benchmarkLoop = NUM_BENCH_ITERATIONS;
                benchmarkProgramTimer = osGetTime();
            }
        }
        benchmark_custom();
    }
    if (gPlayer1Controller->buttonDown & U_JPAD && gPlayer1Controller->buttonPressed & L_TRIG) {
        ramViewer = FALSE;
        benchViewer = FALSE;
        fDebug ^= TRUE;
    }


    if (perfIteration++ == NUM_PERF_ITERATIONS - 1) {
        perfIteration = 0;
    }
    profiler_update(profilerTime2, newTime);
}
#endif

void print_set_envcolour(s32 r, s32 g, s32 b, s32 a) {
    if (r != currEnv[0] || g != currEnv[1] || b != currEnv[2] || a != currEnv[3]) {
        gDPSetEnvColor(gDisplayListHead++, (u8)r, (u8)g, (u8)b, (u8)a);
        currEnv[0] = r;
        currEnv[1] = g;
        currEnv[2] = b;
        currEnv[3] = a;
    }
}

#define BLANK 0, 0, 0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT

void prepare_blank_box(void) {
    gDPSetCombineMode(gDisplayListHead++, BLANK, BLANK);
}

void finish_blank_box(void) {
    print_set_envcolour(255, 255, 255, 255);
    gSPDisplayList(gDisplayListHead++,dl_hud_img_end);
}

// This does some epic shenanigans to figure out the optimal way to draw this.
// If the width is a multiple of 4, then use fillmode (fastest)
// Otherwise, if there's transparency, it uses that rendermode, which is slower than using opaque rendermodes.
void render_blank_box(s32 x1, s32 y1, s32 x2, s32 y2, s32 r, s32 g, s32 b, s32 a) {
    s32 cycleadd = 0;
    if (ABS(x1 - x2) % 4 == 0 && a == 255) {
        gDPSetCycleType(gDisplayListHead++, G_CYC_FILL);
        gDPSetRenderMode(gDisplayListHead++, G_RM_NOOP, G_RM_NOOP);
        cycleadd = 1;
    } else {
        gDPSetCycleType(gDisplayListHead++, G_CYC_1CYCLE);
        if (a == 255) {
            gDPSetRenderMode(gDisplayListHead++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
        } else {
            gDPSetRenderMode(gDisplayListHead++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
        }
        cycleadd = 0;
    }
    gDPPipeSync(gDisplayListHead++);
    gDPSetFillColor(gDisplayListHead++, GPACK_RGBA5551(r, g, b, 1) << 16 | GPACK_RGBA5551(r, g, b, 1));
    print_set_envcolour(r, g, b, a);
    gDPFillRectangle(gDisplayListHead++, x1, y1, x2-cycleadd, y2-cycleadd);
}

#include "level_update.h"

void get_char_from_byte(u8 letter, s32 *textX, s32 *textY, s32 *spaceX, s32 *offsetY, s32 font) {
    *offsetY = 0;
    u8 **textKern = segmented_to_virtual(puppyprint_kerning_lut);
    u8 *textLen = segmented_to_virtual(textKern[font]);
    if (letter >= '0' && letter <= '9') { // Line 1
        *textX = (letter - '0') * 4;
        *textY = 0;
        *spaceX = textLen[letter - '0'];
    } else if (letter >= 'A' && letter <= 'P') { // Line 2
        *textX = ((letter - 'A') * 4);
        *textY = 6;
        *spaceX = textLen[letter - 'A' + 16];
    } else if (letter >= 'Q' && letter <= 'Z') { // Line 3
        *textX = ((letter - 'Q') * 4);
        *textY = 12;
        *spaceX = textLen[letter - 'Q' + 32];
    } else if (letter >= 'a' && letter <= 'p') { // Line 4
        *textX = ((letter - 'a') * 4);
        *textY = 18;
        *spaceX = textLen[letter - 'a' + 48];
    } else if (letter >= 'q' && letter <= 'z') { // Line 5
        *textX = ((letter - 'q') * 4);
        *textY = 24;
        *spaceX = textLen[letter - 'q' + 64];
    } else { // Space, the final frontier.
        *textX = 128;
        *textY = 12;
        *spaceX = 2;
    }

    switch (letter) {
        case '-': *textX = 40; *textY = 0; *spaceX = textLen[10]; break; // Hyphen
        case '+': *textX = 44; *textY = 0; *spaceX = textLen[11]; break; // Plus
        case '(': *textX = 48; *textY = 0; *spaceX = textLen[12]; break; // Open Bracket
        case ')': *textX = 52; *textY = 0; *spaceX = textLen[13]; break; // Close Bracket
        case '!': *textX = 56; *textY = 0; *spaceX = textLen[14]; break; // Exclamation mark
        case '?': *textX = 60; *textY = 0; *spaceX = textLen[15]; break; // Question mark

        case '"': *textX = 40; *textY = 12; *spaceX = textLen[42]; break; // Speech mark
        case'\'': *textX = 44; *textY = 12; *spaceX = textLen[43]; break; // Apostrophe
        case ':': *textX = 48; *textY = 12; *spaceX = textLen[44]; break; // Colon
        case ';': *textX = 52; *textY = 12; *spaceX = textLen[45]; break; // Semicolon
        case '.': *textX = 56; *textY = 12; *spaceX = textLen[46]; break; // Full stop
        case ',': *textX = 60; *textY = 12; *spaceX = textLen[47]; break; // Comma

        case '~': *textX = 40; *textY = 24; *spaceX = textLen[74]; break; // Tilde
        case '@': *textX = 44; *textY = 24; *spaceX = textLen[75]; break; // Umlaut
        case '^': *textX = 48; *textY = 24; *spaceX = textLen[76]; break; // Caret
        case '/': *textX = 52; *textY = 24; *spaceX = textLen[77]; break; // Slash
        case '_': *textX = 56; *textY = 24; *spaceX = textLen[78]; break; // Percent
        case '&': *textX = 60; *textY = 24; *spaceX = textLen[79]; break; // Ampersand

        // This is for the letters that sit differently on the line. It just moves them down a bit.
        case 'g': *offsetY = 1; break;
        case 'q': *offsetY = 1; break;
        case 'p': if (font == FONT_DEFAULT) *offsetY = 3; break;
        case 'y': if (font == FONT_DEFAULT) *offsetY = 1; break;
    }
}

s8 shakeToggle = 0;
s8 waveToggle = 0;

s32 text_iterate_command(const char *str, s32 i, s32 runCMD) {
    s32 len = 0;
    while (str[i+len] != '>' && i+len < (signed)strlen(str)) len++;
    len++;

    if (runCMD) {
        if (strncmp(str+i, "<COL_xxxxxxxx>", 5) == 0) { // Simple text colour effect. goes up to 99 for each, so 99000000 is red.
            s32 r, g, b, a;
            // Each value is taken from the strong. The first is multiplied by 10, because it's a larger significant value, then it adds the next digit onto it.
            r  = ((str[i +  5] - '0') * 10);
            r +=   str[i +  6] - '0';
            g  = ((str[i +  7] - '0') * 10);
            g +=   str[i +  8] - '0';
            b  = ((str[i +  9] - '0') * 10);
            b +=   str[i + 10] - '0';
            a  = ((str[i + 11] - '0') * 10);
            a +=   str[i + 12] - '0';
            // Multiply each value afterwards by 2.575f to make 255.
            print_set_envcolour((r * 2.575f), (g * 2.575f), (b * 2.575f), (a * 2.575f));
        } else if (strncmp(str+i, "<FADE_xxxxxxxx,xxxxxxxx,xx>", 6) == 0) { // Same as above, except it fades between two colours. The third set of numbers is the speed it fades.
            s32 r, g, b, a, r2, g2, b2, a2, spd, r3, g3, b3, a3, r4, g4, b4, a4;
            r    = ((str[i +  6] - '0') * 10);
            r   +=   str[i +  7] - '0';
            g    = ((str[i +  8] - '0') * 10);
            g   +=   str[i +  9] - '0';
            b    = ((str[i + 10] - '0') * 10);
            b   +=   str[i + 11] - '0';
            a    = ((str[i + 12] - '0') * 10);
            a   +=   str[i + 13] - '0';
            r2   = ((str[i + 15] - '0') * 10);
            r2  +=   str[i + 16] - '0';
            g2   = ((str[i + 17] - '0') * 10);
            g2  +=   str[i + 18] - '0';
            b2   = ((str[i + 19] - '0') * 10);
            b2  +=   str[i + 20] - '0';
            a2   = ((str[i + 21] - '0') * 10);
            a2  +=   str[i + 22] - '0';
            spd  = ((str[i + 24] - '0') * 10);
            spd +=   str[i + 25] - '0';

            // Find the median.
            r3 = (r + r2) * 1.2875f;
            g3 = (g + g2) * 1.2875f;
            b3 = (b + b2) * 1.2875f;
            a3 = (a + a2) * 1.2875f;
            // Find the difference.
            r4 = (r - r2) * 1.2875f;
            g4 = (g - g2) * 1.2875f;
            b4 = (b - b2) * 1.2875f;
            a4 = (a - a2) * 1.2875f;
            // Now start from the median, and wave from end to end with the difference, to create the fading effect.
            print_set_envcolour(r3 + ((sins(gGlobalTimer * spd * 50)) * r4), g3 + ((sins(gGlobalTimer * spd * 50)) * g4), b3 + ((sins(gGlobalTimer * spd * 50)) * b4), a3 + ((sins(gGlobalTimer * spd * 50)) * a4));
        }
        else
        if (strncmp(str+i, "<RAINBOW>", 8) == 0) { // Toggles the happy colours :o) Do it again to disable it.
            s32 r = (coss(gGlobalTimer * 600) + 1) * 127;
            s32 g = (coss((gGlobalTimer * 600) + 21845) + 1) * 127;
            s32 b = (coss((gGlobalTimer * 600) - 21845) + 1) * 127;
            print_set_envcolour(r, g, b, 255);
        } else if (strncmp(str + i, "<SHAKE>", 7) == 0) { // Toggles text that shakes on the spot. Do it again to disable it.
            shakeToggle ^= 1;
        } else if (strncmp(str + i, "<WAVE>", 6) == 0) { // Toggles text that waves around. Do it again to disable it.
            waveToggle ^= 1;
        }
    }
    return len;
}

s32 get_text_width(const char *str, s32 font) {
    s32 i= 0;
    s32 textPos = 0;
    s32 wideX = 0;
    s32 textX, textY, offsetY, spaceX;

    for (i = 0; i < (signed)strlen(str); i++) {
        if (str[i] == '#') {
            i++;
            textPos = 0;
        }
        if (str[i] == '<') {
            i += text_iterate_command(str, i, FALSE);
        }
        get_char_from_byte(str[i], &textX, &textY, &spaceX, &offsetY, font);
        textPos += spaceX + 1;
        wideX = MAX(textPos, wideX);
    }
    return wideX;
}

s32 get_text_height(const char *str) {
    s32 i= 0;
    s32 textPos = 0;

    for (i = 0; i < (signed)strlen(str); i++) {
        if (str[i] == '#') {
            i++;
            textPos += 12;
        }
    }
    return textPos;
}

void print_small_text(s32 x, s32 y, const char *str, s32 align, s32 amount, s32 font)
{
    s32 textX = 0;
    s32 textY = 0;
    s32 offsetY = 0;
    s32 i = 0;
    s32 textPos[2] = {0,0};
    s32 spaceX = 0;
    s32 wideX[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
    s32 tx = amount;
    s32 shakePos[2];
    s32 wavePos;
    s32 lines = 0;
    s32 xlu = currEnv[3];
    s32 prevxlu = 256; //Set out of bounds, so it will *always* be different at first.
    Texture *(*fontTex)[] = segmented_to_virtual(&puppyprint_font_lut);

    shakeToggle = 0;
    waveToggle = 0;

    if (amount == PRINT_ALL)
        tx = (signed)strlen(str);
    gDPSetCycleType(gDisplayListHead++, G_CYC_1CYCLE);
    gDPSetTexturePersp(gDisplayListHead++, G_TP_NONE);
    gDPSetCombineMode(gDisplayListHead++, G_CC_FADEA, G_CC_FADEA);
    gDPSetTextureFilter(gDisplayListHead++, G_TF_POINT);
    if (align == PRINT_TEXT_ALIGN_CENTRE) {
        for (i = 0; i < (signed)strlen(str); i++) {
            if (str[i] == '#') {
                i++;
                textPos[0] = 0;
                lines++;
            }
            if (str[i] == '<') {
                i += text_iterate_command(str, i, FALSE);
            }
            get_char_from_byte(str[i], &textX, &textY, &spaceX, &offsetY, font);
            textPos[0] += spaceX + 1;
            wideX[lines] = MAX(textPos[0], wideX[lines]);
        }
        textPos[0] = -(wideX[0] / 2);
    } else if (align == PRINT_TEXT_ALIGN_RIGHT) {
        for (i = 0; i < (signed)strlen(str); i++) {
            if (str[i] == '#') {
                i++;
                textPos[0] = 0;
                lines++;
            } else {
                textPos[0]+=spaceX+1;
            }
            if (str[i] == '<') {
                i += text_iterate_command(str, i, FALSE);
            }
            get_char_from_byte(str[i], &textX, &textY, &spaceX, &offsetY, font);

            wideX[lines] = MAX(textPos[0], wideX[lines]);
        }
        textPos[0] = -wideX[0];
    }
    lines = 0;
    gDPLoadTextureBlock_4b(gDisplayListHead++, (*fontTex)[font], G_IM_FMT_I, 128, 60, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, 0, 0, 0, 0, 0);
    for (i = 0; i < tx; i++) {
        if (str[i] == '#') {
            i++;
            lines++;
            if (align == PRINT_TEXT_ALIGN_RIGHT) {
                textPos[0] = -(wideX[lines]);
            } else {
                textPos[0] = -(wideX[lines]/2);
            }
            textPos[1] += 12;
        }
        if (str[i] == '<') {
            i += text_iterate_command(str, i, TRUE);
        }
        if (shakeToggle) {
            shakePos[0] = -1 + (random_u16() % 2);
            shakePos[1] = -1 + (random_u16() % 2);
        } else {
            shakePos[0] = 0;
            shakePos[1] = 0;
        }
        if (waveToggle) {
            wavePos = (sins((gGlobalTimer * 3000) + (i * 10000))) * 2;
        } else {
            wavePos = 0;
        }
        get_char_from_byte(str[i], &textX, &textY, &spaceX, &offsetY, font);
        if (xlu != prevxlu) {
            prevxlu = xlu;
            if (xlu > 250) {
                gDPSetRenderMode(gDisplayListHead++, G_RM_TEX_EDGE, G_RM_TEX_EDGE2);
            } else {
                gDPSetRenderMode(gDisplayListHead++, G_RM_XLU_SURF, G_RM_XLU_SURF);
            }
        }
        gSPScisTextureRectangle(gDisplayListHead++, (x+shakePos[0]+textPos[0]) << 2, (y+shakePos[1]+offsetY+textPos[1]+wavePos) << 2, (x+textPos[0]+shakePos[0]+8) << 2, (y+wavePos+offsetY+shakePos[1]+12+textPos[1]) << 2, G_TX_RENDERTILE, textX << 6, textY << 6, 1 << 10, 1 << 10);
        textPos[0]+=spaceX+1;
    }
    gSPDisplayList(gDisplayListHead++, dl_rgba16_text_end);
}

void render_multi_image(Texture *image, s32 x, s32 y, s32 width, s32 height, UNUSED s32 scaleX, UNUSED s32 scaleY, s32 mode) {
    s32 posW, posH, imW, imH, peakH, maskW, maskH, cycles, num, i, modeSC, mOne;
    i = 0;
    num = 256;
    maskW = 1;
    maskH = 1;

    if (mode == G_CYC_COPY) {
        gDPSetCycleType(gDisplayListHead++, mode);
        gDPSetRenderMode(gDisplayListHead++, G_RM_NOOP, G_RM_NOOP2);
        modeSC = 4;
        mOne = 1;
    } else {
        gDPSetCycleType(gDisplayListHead++, mode);
        gDPSetRenderMode(gDisplayListHead++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
        modeSC = 1;
        mOne = 0;
    }


    // Find how best to seperate the horizontal. Keep going until it finds a whole value.
    while (TRUE) {
        f32 val =  (f32)width / (f32)num;

        if ((s32)val == val && (s32) val >= 1) {
            imW = num;
            break;
        }
        num /= 2;
        if (num == 1) {
            print_text(32, 32, "IMAGE WIDTH FAILURE");
            return;
        }
    }
    // Find the tile height
    imH = 64 / (imW / 32); // This gets the vertical amount.

    num = 2;
    // Find the width mask
    while (TRUE) {
        if ((s32) num == imW) {
            break;
        }
        num *= 2;
        maskW++;
        if (maskW == 9) {
            print_text(32, 32, "WIDTH MASK FAILURE");
            return;
        }
    }
    num = 2;
    // Find the height mask
    while (TRUE) {
        if ((s32) num == imH) {
            break;
        }
        num *= 2;
        maskH++;
        if (maskH == 9) {
            print_text(32, 32, "HEIGHT MASK FAILURE");
            return;
        }
    }
    num = height;
    // Find the height remainder
    peakH = height - (height % imH);
    cycles = (width * peakH) / (imW * imH);

    // Pass 1
    for (i = 0; i < cycles; i++) {
        posW = 0;
        posH = (i*imH);
        while (posH >= peakH) {
            posW += imW;
            posH -= peakH;
        }
        gDPLoadSync(gDisplayListHead++);
        gDPLoadTextureTile(gDisplayListHead++, image, G_IM_FMT_RGBA, G_IM_SIZ_16b, width, height, posW, posH, posW+imW-1, posH+imH-1, 0,  G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, maskW, maskH, 0, 0);
        gSPScisTextureRectangle(gDisplayListHead++, (x + posW) << 2, (y + posH) << 2, (x + posW+imW-mOne) << 2,(y + posH + imH-mOne) << 2, G_TX_RENDERTILE, 0, 0, modeSC << 10, 1 << 10);
    }
    // If there's a remainder on the vertical side, then it will cycle through that too.
    if (height-peakH != 0) {
        posW = 0;
        posH = peakH;
        for (i = 0; i < (width / imW); i++) {
            posW = i * imW;
            gDPLoadSync(gDisplayListHead++);
            gDPLoadTextureTile(gDisplayListHead++, image, G_IM_FMT_RGBA, G_IM_SIZ_16b, width, height, posW, posH, posW+imW-1, height-1, 0,  G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, maskW, maskH, 0, 0);
            gSPScisTextureRectangle(gDisplayListHead++, (x + posW) << 2, (y + posH) << 2, (x + posW+imW-mOne) << 2,(y + posH + imH-mOne) << 2, G_TX_RENDERTILE, 0, 0, modeSC << 10, 1 << 10);
        }
    }
}

#endif
