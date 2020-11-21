static const s16 new_shyguy_anim_shyguy_idle_values[] = {
	0x0000, 0x0050, 0x0000, 0x3C1D, 0x3FFF, 0x3C1D, 0x0000, 0xFFFF, 0x3841, 
	0xFFFF, 0xFFFF, 0xC000, 0xFFFF, 0x0000, 0x945F, 0xFFFF, 0xFFFF, 0xC000, 
	0xFFFF, 0x0000, 0x93F7, 
};

static const u16 new_shyguy_anim_shyguy_idle_indices[] = {
	0x0001, 0x0000, 0x0001, 0x0001, 0x0001, 0x0002, 0x0001, 0x0003, 0x0001, 
	0x0004, 0x0001, 0x0005, 0x0001, 0x0006, 0x0001, 0x0007, 0x0001, 0x0008, 
	0x0001, 0x0009, 0x0001, 0x000A, 0x0001, 0x000B, 0x0001, 0x000C, 0x0001, 
	0x000D, 0x0001, 0x000E, 0x0001, 0x000F, 0x0001, 0x0010, 0x0001, 0x0011, 
	0x0001, 0x0012, 0x0001, 0x0013, 0x0001, 0x0014, 
};

static const struct Animation new_shyguy_anim_shyguy_idle = {
	0,
	0,
	0,
	1,
	1,
	ANIMINDEX_NUMPARTS(new_shyguy_anim_shyguy_idle_indices),
	new_shyguy_anim_shyguy_idle_values,
	new_shyguy_anim_shyguy_idle_indices,
	0,
};

