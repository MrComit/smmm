static const s16 security_cam_anim_idle_values[] = {
	0x0000, 0x0000, 0x0000, 0xFFFF, 0x0000, 0xFFFF, 0x0000, 0x0000, 0x0E39, 
	0xFFFF, 0xFFFF, 0xFFFF, 
};

static const u16 security_cam_anim_idle_indices[] = {
	0x0001, 0x0000, 0x0001, 0x0001, 0x0001, 0x0002, 0x0001, 0x0003, 0x0001, 
	0x0004, 0x0001, 0x0005, 0x0001, 0x0006, 0x0001, 0x0007, 0x0001, 0x0008, 
	0x0001, 0x0009, 0x0001, 0x000A, 0x0001, 0x000B, 
};

static const struct Animation security_cam_anim_idle = {
	1,
	0,
	0,
	1,
	2,
	ANIMINDEX_NUMPARTS(security_cam_anim_idle_indices),
	security_cam_anim_idle_values,
	security_cam_anim_idle_indices,
	0,
};
