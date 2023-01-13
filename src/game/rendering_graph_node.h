#ifndef RENDERING_GRAPH_NODE_H
#define RENDERING_GRAPH_NODE_H

#include <PR/ultratypes.h>

#include "engine/graph_node.h"

extern struct GraphNodeRoot *gCurGraphNodeRoot;
extern struct GraphNodeMasterList *gCurGraphNodeMasterList;
extern struct GraphNodePerspective *gCurGraphNodeCamFrustum;
extern struct GraphNodeCamera *gCurGraphNodeCamera;
extern struct GraphNodeObject *gCurGraphNodeObject;
extern struct GraphNodeHeldObject *gCurGraphNodeHeldObject;
#define gCurGraphNodeObjectNode ((struct Object *)gCurGraphNodeObject)
extern u16 gAreaUpdateCounter;

// after processing an object, the type is reset to this
#define ANIM_TYPE_NONE                  0

// Not all parts have full animation: to save space, some animations only
// have xz, y, or no translation at all. All animations have rotations though
#define ANIM_TYPE_TRANSLATION           1
#define ANIM_TYPE_VERTICAL_TRANSLATION  2
#define ANIM_TYPE_LATERAL_TRANSLATION   3
#define ANIM_TYPE_NO_TRANSLATION        4

// Every animation includes rotation, after processing any of the above
// translation types the type is set to this
#define ANIM_TYPE_ROTATION              5

void geo_process_node_and_siblings(struct GraphNode *firstNode);
void geo_process_root(struct GraphNodeRoot *node, Vp *b, Vp *c, s32 clearColor);

extern s32 gMarioScreenX, gMarioScreenY;
extern Vec3f globalLightDirection;


/**
 * Causes the global light direction to be in world space,
 * this allows you to have a singular light source that doesn't change with the camera's rotation.
 * By modifying `globalLightDirection`, you can choose the direction that points TOWARDS the light,
 * but keep in mind that this direction should be normalized to roughly ~127 if changed.
 */
// #define WORLDSPACE_LIGHTING

#endif // RENDERING_GRAPH_NODE_H
