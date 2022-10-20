static const s16 basement_dryer_anim_stay_values[] = {
	0x0000, 0x0000, 0x0000, 0xFFFF, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x0000, 
	0x44D8, 0xFFFF, 0xFFFF, 
};

static const u16 basement_dryer_anim_stay_indices[] = {
	0x0001, 0x0000, 0x0001, 0x0001, 0x0001, 0x0002, 0x0001, 0x0003, 0x0001, 
	0x0004, 0x0001, 0x0005, 0x0001, 0x0006, 0x0001, 0x0007, 0x0001, 0x0008, 
	0x0001, 0x0009, 0x0001, 0x000A, 0x0001, 0x000B, 
};

static const struct Animation basement_dryer_anim_stay = {
	1,
	0,
	0,
	1,
	2,
	ANIMINDEX_NUMPARTS(basement_dryer_anim_stay_indices),
	basement_dryer_anim_stay_values,
	basement_dryer_anim_stay_indices,
	0,
};

