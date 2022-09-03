#ifndef _!COMIT_LIBRARY_H
#define _!COMIT_LIBRARY_H


u16 CL_RandomMinMaxU16(u16 min, u16 max);
void CL_kill_mario();
u8 CL_run_timer(u16 time);
void CL_Move();
void CL_Move_3d();
struct Object *CL_Create_Star_Ptr(f32 sp20, f32 sp24, f32 sp28);
struct Object *CL_Create_Star_Helper(struct Object *sp30, f32 sp34, f32 sp38, f32 sp3C);
s16 CL_object_to_point(struct Object *o, Vec3f point);
s16 CL_angle_between_points(Vec3f point1, Vec3f point2);
void CL_set_camera_pos(Vec3f pos, Vec3f pos2);
struct Object *CL_obj_nearest_object_behavior_params(const BehaviorScript *behavior, u32 params);
void CL_dist_between_points(Vec3f from, Vec3f to, f32 *dist);
void CL_lateral_dist_between_points(Vec3f from, Vec3f to, f32 *dist);
u32 CL_count_bits(u32 b);
void CL_drop_to_floor(void);
s32 CL_NPC_Dialog(s32 dialogId);
s32 CL_NPC_Dialog_Options(s32 dialogId);
s32 CL_respawn(s16 *timer, Vec3f pos, s16 faceAngle, s16 damage);
Vec3f *CL_nearest_point(Vec3f *list, Vec3f source, s16 listcount);
s16 CL_obj_pitch_to_mario(void);
void CL_get_hit(struct MarioState *m, struct Object *o, u32 damage);
void CL_explode_object(struct Object *obj, s16 noDamage);
void CL_scramble_array(u8 *array[], s16 size);
void CL_Lava_Boost(void);
struct Object *CL_nearest_object_with_behavior_and_field(const BehaviorScript *behavior, u32 field, u32 param);
struct Object *CL_objptr_nearest_object_behavior(struct Object *obj2, const BehaviorScript *behavior);
s32 CL_get_room_from_point(Vec3f point);
struct Object *CL_obj_find_nearest_object_with_behavior_room(struct Object *curObj, const BehaviorScript *behavior, s32 room);
s32 CL_cur_obj_get_obj_collision(struct Object *obj);
f32 CL_objptr_dist_to_nearest_object_with_behavior(struct Object *obj2, const BehaviorScript *behavior);
void CL_instantly_warp(f32 x, f32 y, f32 z);

#endif