static const s16 poochy_anim_poochy_intro_values[] = {
	0x0000, 0x0000, 0x0000, 0xFFFF, 0x0000, 0xFFFF, 0x272F, 0x02A7, 0x0ED2, 
	0x2273, 0xFFFF, 0xE7AF, 0x235E, 0xFFFF, 0x0EFA, 0x235E, 0x0000, 0xED25, 
	0xF867, 0xFFFF, 0xFFFF, 0x1F92, 0xFFFF, 0xFFFF, 
};

static const u16 poochy_anim_poochy_intro_indices[] = {
	0x0001, 0x0000, 0x0001, 0x0001, 0x0001, 0x0002, 0x0001, 0x0003, 0x0001, 
	0x0004, 0x0001, 0x0005, 0x0001, 0x0006, 0x0001, 0x0007, 0x0001, 0x0008, 
	0x0001, 0x0009, 0x0001, 0x000A, 0x0001, 0x000B, 0x0001, 0x000C, 0x0001, 
	0x000D, 0x0001, 0x000E, 0x0001, 0x000F, 0x0001, 0x0010, 0x0001, 0x0011, 
	0x0001, 0x0012, 0x0001, 0x0013, 0x0001, 0x0014, 0x0001, 0x0015, 0x0001, 
	0x0016, 0x0001, 0x0017, 
};

static const struct Animation poochy_anim_poochy_intro = {
	1,
	0,
	0,
	0,
	1,
	ANIMINDEX_NUMPARTS(poochy_anim_poochy_intro_indices),
	poochy_anim_poochy_intro_values,
	poochy_anim_poochy_intro_indices,
	0,
};
