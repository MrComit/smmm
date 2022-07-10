#ifndef SURFACE_LOAD_H
#define SURFACE_LOAD_H

#include <PR/ultratypes.h>

#include "surface_collision.h"
#include "types.h"
#include "engine/extended_bounds.h"


/**
 * The size of the dynamic surface pool, in bytes.
 */
#define DYNAMIC_SURFACE_POOL_SIZE 0x8000

//#define NUM_CELLS       (2 * LEVEL_BOUNDARY_MAX / CELL_SIZE)
//#define NUM_CELLS_INDEX (NUM_CELLS - 1)

struct SurfaceNode {
    struct SurfaceNode *next;
    struct Surface *surface;
};

enum {
    SPATIAL_PARTITION_FLOORS,
    SPATIAL_PARTITION_CEILS,
    SPATIAL_PARTITION_WALLS,
    SPATIAL_PARTITION_WATER,
    NUM_SPATIAL_PARTITIONS
};

typedef struct SurfaceNode SpatialPartitionCell[4];

// Needed for bs bss reordering memes.
extern s32 unused8038BE90;

extern SpatialPartitionCell gStaticSurfacePartition[NUM_CELLS][NUM_CELLS];
extern SpatialPartitionCell gDynamicSurfacePartition[NUM_CELLS][NUM_CELLS];
extern void *gCurrStaticSurfacePool;
extern void *gDynamicSurfacePool;
extern void *gCurrStaticSurfacePoolEnd;
extern void *gDynamicSurfacePoolEnd;
extern u32 gTotalStaticSurfaceData;

void alloc_surface_pools(void);
#ifdef NO_SEGMENTED_MEMORY
u32 get_area_terrain_size(s16 *data);
#endif
void load_area_terrain(s16 index, s16 *data, s8 *surfaceRooms, s16 *macroObjects);
void clear_dynamic_surfaces(void);
void load_object_collision_model(void);
void load_object_static_model(void);
s16 min_3(s16 a0, s16 a1, s16 a2);
s16 max_3(s16 a0, s16 a1, s16 a2);

#endif // SURFACE_LOAD_H
