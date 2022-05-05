void scroll_sts_mat_hmc_dl_Wall_layer1() {
	static int intervalTex1 = 2;
	static int curInterval1 = 2;
	Gfx *mat = segmented_to_virtual(mat_hmc_dl_Wall_layer1);

	if (--curInterval1 <= 0) {
		shift_s(mat, 21, PACK_TILESIZE(0, 1));
		curInterval1 = intervalTex1;
	}
};

void scroll_sts_mat_hmc_dl_WoodFloor_layer1() {
	static int intervalTex1 = 3;
	static int curInterval1 = 3;
	Gfx *mat = segmented_to_virtual(mat_hmc_dl_WoodFloor_layer1);

	if (--curInterval1 <= 0) {
		shift_s(mat, 21, PACK_TILESIZE(0, 1));
		shift_t(mat, 21, PACK_TILESIZE(0, 2));
		curInterval1 = intervalTex1;
	}
};

void scroll_sts_mat_hmc_dl_WoodFloorTrophyRoom_layer1() {
	static int intervalTex1 = 3;
	static int curInterval1 = 3;
	Gfx *mat = segmented_to_virtual(mat_hmc_dl_WoodFloorTrophyRoom_layer1);

	if (--curInterval1 <= 0) {
		shift_s(mat, 22, PACK_TILESIZE(0, 1));
		shift_t(mat, 22, PACK_TILESIZE(0, 2));
		curInterval1 = intervalTex1;
	}
};

void scroll_hmc_dl_TrophyRoom_002_mesh_layer_1_vtx_8() {
	int i = 0;
	int count = 4;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	static int timeX;
	float amplitudeX = 2.0;
	float frequencyX = 0.25;
	float offsetX = 0.0;
	static int currentY = 0;
	int deltaY;
	static int timeY;
	float amplitudeY = 2.0;
	float frequencyY = 0.25;
	float offsetY = 32.0;
	Vtx *vertices = segmented_to_virtual(hmc_dl_TrophyRoom_002_mesh_layer_1_vtx_8);

	deltaX = (int)(amplitudeX * frequencyX * coss((frequencyX * timeX + offsetX) * (1024 * 16 - 1) / 6.28318530718) * 0x20);
	deltaY = (int)(amplitudeY * frequencyY * coss((frequencyY * timeY + offsetY) * (1024 * 16 - 1) / 6.28318530718) * 0x20);

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}
	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
		vertices[i].n.tc[1] += deltaY;
	}
	currentX += deltaX;	timeX += 1;	currentY += deltaY;	timeY += 1;
}

void scroll_sts_mat_hmc_dl_RedWall_layer1() {
	static int intervalTex1 = 2;
	static int curInterval1 = 2;
	Gfx *mat = segmented_to_virtual(mat_hmc_dl_RedWall_layer1);

	if (--curInterval1 <= 0) {
		shift_s(mat, 21, PACK_TILESIZE(0, 2));
		shift_t(mat, 21, PACK_TILESIZE(0, 1));
		curInterval1 = intervalTex1;
	}
};

void scroll_sts_mat_hmc_dl_Study1() {
	Gfx *mat = segmented_to_virtual(mat_hmc_dl_Study1);
	shift_s(mat, 18, PACK_TILESIZE(0, 1));
};

void scroll_sts_mat_hmc_dl_Parlor1_layer1() {
	Gfx *mat = segmented_to_virtual(mat_hmc_dl_Parlor1_layer1);
	shift_t(mat, 21, PACK_TILESIZE(0, 1));
};

void scroll_hmc_dl_TrophyRoom_005_mesh_layer_1_vtx_2() {
	int i = 0;
	int count = 4;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(hmc_dl_TrophyRoom_005_mesh_layer_1_vtx_2);

	deltaX = (int)(7.5 * 0x20 * random_float() * random_sign()) % width;
	deltaY = (int)(10.0 * 0x20 * random_float() * random_sign()) % height;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}
	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
		vertices[i].n.tc[1] += deltaY;
	}
	currentX += deltaX;	currentY += deltaY;
}

void scroll_sts_mat_hmc_dl_CreepyEyes_layer1() {
	static int intervalTex0 = 2;
	static int curInterval0 = 2;
	Gfx *mat = segmented_to_virtual(mat_hmc_dl_CreepyEyes_layer1);

	if (--curInterval0 <= 0) {
		shift_s(mat, 13, PACK_TILESIZE(0, 13));
		shift_t(mat, 13, PACK_TILESIZE(0, 2));
		curInterval0 = intervalTex0;
	}
	shift_s(mat, 21, PACK_TILESIZE(0, 1));
	shift_t(mat, 21, PACK_TILESIZE(0, 6));
};

void scroll_hmc_dl_TrophyRoom_007_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 6;
	int width = 64 * 0x20;
	int height = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(hmc_dl_TrophyRoom_007_mesh_layer_1_vtx_0);

	deltaX = (int)(-0.5 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_hmc_dl_TrophyRoom_007_mesh_layer_1_vtx_1() {
	int i = 0;
	int count = 6;
	int width = 64 * 0x20;
	int height = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(hmc_dl_TrophyRoom_007_mesh_layer_1_vtx_1);

	deltaX = (int)(0.5 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_sts_mat_hmc_dl_Cons3_layer1() {
	Gfx *mat = segmented_to_virtual(mat_hmc_dl_Cons3_layer1);
	shift_t(mat, 13, PACK_TILESIZE(0, 6));
	shift_t(mat, 21, PACK_TILESIZE(0, 7));
};

void scroll_sts_mat_hmc_dl_Cons1_layer1() {
	static int intervalTex0 = 20;
	static int curInterval0 = 20;
	static int intervalTex1 = 20;
	static int curInterval1 = 20;
	Gfx *mat = segmented_to_virtual(mat_hmc_dl_Cons1_layer1);

	if (--curInterval0 <= 0) {
		shift_t(mat, 13, PACK_TILESIZE(0, 16));
		curInterval0 = intervalTex0;
	}

	if (--curInterval1 <= 0) {
		shift_t(mat, 21, PACK_TILESIZE(0, 16));
		curInterval1 = intervalTex1;
	}
};

void scroll_sts_mat_hmc_dl_BooGoo_layer1() {
	Gfx *mat = segmented_to_virtual(mat_hmc_dl_BooGoo_layer1);
	shift_s(mat, 13, PACK_TILESIZE(0, 1));
	shift_s(mat, 21, PACK_TILESIZE(0, 1));
	shift_t(mat, 21, PACK_TILESIZE(0, 1));
};

void scroll_sts_mat_hmc_dl_WoodFloorTransparent_layer1() {
	static int intervalTex1 = 3;
	static int curInterval1 = 3;
	Gfx *mat = segmented_to_virtual(mat_hmc_dl_WoodFloorTransparent_layer1);

	if (--curInterval1 <= 0) {
		shift_s(mat, 23, PACK_TILESIZE(0, 1));
		shift_t(mat, 23, PACK_TILESIZE(0, 2));
		curInterval1 = intervalTex1;
	}
};

void scroll_sts_mat_hmc_dl_WoodFloorOneCycle() {
	static int intervalTex1 = 3;
	static int curInterval1 = 3;
	Gfx *mat = segmented_to_virtual(mat_hmc_dl_WoodFloorOneCycle);

	if (--curInterval1 <= 0) {
		shift_s(mat, -1, PACK_TILESIZE(0, 1));
		shift_t(mat, -1, PACK_TILESIZE(0, 2));
		curInterval1 = intervalTex1;
	}
};

void scroll_sts_mat_hmc_dl_Lava_layer1() {
	static int intervalTex1 = 2;
	static int curInterval1 = 2;
	Gfx *mat = segmented_to_virtual(mat_hmc_dl_Lava_layer1);
	shift_t(mat, 13, PACK_TILESIZE(0, 1));

	if (--curInterval1 <= 0) {
		shift_s(mat, 21, PACK_TILESIZE(0, 1));
		shift_t(mat, 21, PACK_TILESIZE(0, 1));
		curInterval1 = intervalTex1;
	}
};

void scroll_sts_mat_hmc_dl_WallDither_layer4() {
	static int intervalTex1 = 2;
	static int curInterval1 = 2;
	Gfx *mat = segmented_to_virtual(mat_hmc_dl_WallDither_layer4);

	if (--curInterval1 <= 0) {
		shift_s(mat, 22, PACK_TILESIZE(0, 1));
		curInterval1 = intervalTex1;
	}
};

void scroll_sts_mat_hmc_dl_Vase_v4_layer1() {
	Gfx *mat = segmented_to_virtual(mat_hmc_dl_Vase_v4_layer1);
	shift_s(mat, 13, PACK_TILESIZE(0, 4));
};

void scroll_hmc_dl_Hallway_003_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 325;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	static int timeY;
	float amplitudeY = 0.800000011920929;
	float frequencyY = 0.10000000149011612;
	float offsetY = 0.0;
	Vtx *vertices = segmented_to_virtual(hmc_dl_Hallway_003_mesh_layer_1_vtx_0);

	deltaY = (int)(amplitudeY * frequencyY * coss((frequencyY * timeY + offsetY) * (1024 * 16 - 1) / 6.28318530718) * 0x20);

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;	timeY += 1;
}

void scroll_sts_mat_hmc_dl_WallTransition_layer1() {
	static int intervalTex0 = 15;
	static int curInterval0 = 15;
	Gfx *mat = segmented_to_virtual(mat_hmc_dl_WallTransition_layer1);

	if (--curInterval0 <= 0) {
		shift_s_down(mat, 13, PACK_TILESIZE(0, 20));
		curInterval0 = intervalTex0;
	}
	shift_s(mat, 21, PACK_TILESIZE(0, 5));
};

void scroll_hmc_dl_Hallway_004_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 1056;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	static int timeY;
	float amplitudeY = 0.800000011920929;
	float frequencyY = 0.10000000149011612;
	float offsetY = 0.0;
	Vtx *vertices = segmented_to_virtual(hmc_dl_Hallway_004_mesh_layer_1_vtx_0);

	deltaY = (int)(amplitudeY * frequencyY * coss((frequencyY * timeY + offsetY) * (1024 * 16 - 1) / 6.28318530718) * 0x20);

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;	timeY += 1;
}

void scroll_hmc_dl_Hallway_005_mesh_layer_1_vtx_2() {
	int i = 0;
	int count = 711;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	static int timeY;
	float amplitudeY = 0.800000011920929;
	float frequencyY = 0.10000000149011612;
	float offsetY = 0.0;
	Vtx *vertices = segmented_to_virtual(hmc_dl_Hallway_005_mesh_layer_1_vtx_2);

	deltaY = (int)(amplitudeY * frequencyY * coss((frequencyY * timeY + offsetY) * (1024 * 16 - 1) / 6.28318530718) * 0x20);

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;	timeY += 1;
}

void scroll_hmc_dl_Hallway_005_mesh_layer_1_vtx_5() {
	int i = 0;
	int count = 4;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(hmc_dl_Hallway_005_mesh_layer_1_vtx_5);

	deltaX = (int)(7.5 * 0x20 * random_float() * random_sign()) % width;
	deltaY = (int)(10.0 * 0x20 * random_float() * random_sign()) % height;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}
	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
		vertices[i].n.tc[1] += deltaY;
	}
	currentX += deltaX;	currentY += deltaY;
}

void scroll_hmc_dl_Maze_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 498;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	static int timeY;
	float amplitudeY = 0.800000011920929;
	float frequencyY = 0.10000000149011612;
	float offsetY = 0.0;
	Vtx *vertices = segmented_to_virtual(hmc_dl_Maze_mesh_layer_1_vtx_0);

	deltaY = (int)(amplitudeY * frequencyY * coss((frequencyY * timeY + offsetY) * (1024 * 16 - 1) / 6.28318530718) * 0x20);

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;	timeY += 1;
}

void scroll_hmc_dl_MazeNoCol_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 472;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	static int timeY;
	float amplitudeY = 0.800000011920929;
	float frequencyY = 0.10000000149011612;
	float offsetY = 0.0;
	Vtx *vertices = segmented_to_virtual(hmc_dl_MazeNoCol_mesh_layer_1_vtx_0);

	deltaY = (int)(amplitudeY * frequencyY * coss((frequencyY * timeY + offsetY) * (1024 * 16 - 1) / 6.28318530718) * 0x20);

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;	timeY += 1;
}

void scroll_hmc_dl_ASaunaGlobal_mesh_layer_1_vtx_3() {
	int i = 0;
	int count = 12;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	static int timeX;
	float amplitudeX = 0.699999988079071;
	float frequencyX = 0.20000000298023224;
	float offsetX = 0.0;
	static int currentY = 0;
	int deltaY;
	static int timeY;
	float amplitudeY = 0.699999988079071;
	float frequencyY = 0.20000000298023224;
	float offsetY = 32.0;
	Vtx *vertices = segmented_to_virtual(hmc_dl_ASaunaGlobal_mesh_layer_1_vtx_3);

	deltaX = (int)(amplitudeX * frequencyX * coss((frequencyX * timeX + offsetX) * (1024 * 16 - 1) / 6.28318530718) * 0x20);
	deltaY = (int)(amplitudeY * frequencyY * coss((frequencyY * timeY + offsetY) * (1024 * 16 - 1) / 6.28318530718) * 0x20);

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}
	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
		vertices[i].n.tc[1] += deltaY;
	}
	currentX += deltaX;	timeX += 1;	currentY += deltaY;	timeY += 1;
}

void scroll_sts_mat_hmc_dl_SaunaLava_layer1() {
	Gfx *mat = segmented_to_virtual(mat_hmc_dl_SaunaLava_layer1);
	shift_t(mat, 20, PACK_TILESIZE(0, 1));
};

void scroll_hmc_dl_Sauna1_001_mesh_layer_1_vtx_4() {
	int i = 0;
	int count = 30;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	static int timeX;
	float amplitudeX = 0.699999988079071;
	float frequencyX = 0.20000000298023224;
	float offsetX = 0.0;
	static int currentY = 0;
	int deltaY;
	static int timeY;
	float amplitudeY = 0.699999988079071;
	float frequencyY = 0.20000000298023224;
	float offsetY = 32.0;
	Vtx *vertices = segmented_to_virtual(hmc_dl_Sauna1_001_mesh_layer_1_vtx_4);

	deltaX = (int)(amplitudeX * frequencyX * coss((frequencyX * timeX + offsetX) * (1024 * 16 - 1) / 6.28318530718) * 0x20);
	deltaY = (int)(amplitudeY * frequencyY * coss((frequencyY * timeY + offsetY) * (1024 * 16 - 1) / 6.28318530718) * 0x20);

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}
	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
		vertices[i].n.tc[1] += deltaY;
	}
	currentX += deltaX;	timeX += 1;	currentY += deltaY;	timeY += 1;
}

void scroll_hmc_dl_Steam_001_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 32;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	static int timeX;
	float amplitudeX = 0.30000001192092896;
	float frequencyX = 0.10000000149011612;
	float offsetX = 0.0;
	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(hmc_dl_Steam_001_mesh_layer_5_vtx_0);

	deltaX = (int)(amplitudeX * frequencyX * coss((frequencyX * timeX + offsetX) * (1024 * 16 - 1) / 6.28318530718) * 0x20);
	deltaY = (int)(0.30000001192092896 * 0x20) % height;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}
	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
		vertices[i].n.tc[1] += deltaY;
	}
	currentX += deltaX;	timeX += 1;	currentY += deltaY;
}

void scroll_hmc_dl_SaunaMat_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 4;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(hmc_dl_SaunaMat_mesh_layer_1_vtx_0);

	deltaY = (int)(-0.5 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_sts_mat_hmc_dl_SaunaLavaDyn_layer1() {
	static int intervalTex0 = 2;
	static int curInterval0 = 2;
	Gfx *mat = segmented_to_virtual(mat_hmc_dl_SaunaLavaDyn_layer1);

	if (--curInterval0 <= 0) {
		shift_t(mat, 13, PACK_TILESIZE(0, 1));
		curInterval0 = intervalTex0;
	}
	shift_t(mat, 21, PACK_TILESIZE(0, 1));
};

void scroll_hmc() {
	scroll_sts_mat_hmc_dl_Wall_layer1();
	scroll_sts_mat_hmc_dl_WoodFloor_layer1();
	scroll_sts_mat_hmc_dl_WoodFloorTrophyRoom_layer1();
	scroll_hmc_dl_TrophyRoom_002_mesh_layer_1_vtx_8();
	scroll_sts_mat_hmc_dl_RedWall_layer1();
	scroll_sts_mat_hmc_dl_Study1();
	scroll_sts_mat_hmc_dl_Parlor1_layer1();
	scroll_hmc_dl_TrophyRoom_005_mesh_layer_1_vtx_2();
	scroll_sts_mat_hmc_dl_CreepyEyes_layer1();
	scroll_hmc_dl_TrophyRoom_007_mesh_layer_1_vtx_0();
	scroll_hmc_dl_TrophyRoom_007_mesh_layer_1_vtx_1();
	scroll_sts_mat_hmc_dl_Cons3_layer1();
	scroll_sts_mat_hmc_dl_Cons1_layer1();
	scroll_sts_mat_hmc_dl_BooGoo_layer1();
	scroll_sts_mat_hmc_dl_WoodFloorTransparent_layer1();
	scroll_sts_mat_hmc_dl_WoodFloorOneCycle();
	scroll_sts_mat_hmc_dl_Lava_layer1();
	scroll_sts_mat_hmc_dl_WallDither_layer4();
	scroll_sts_mat_hmc_dl_Vase_v4_layer1();
	scroll_hmc_dl_Hallway_003_mesh_layer_1_vtx_0();
	scroll_sts_mat_hmc_dl_WallTransition_layer1();
	scroll_hmc_dl_Hallway_004_mesh_layer_1_vtx_0();
	scroll_hmc_dl_Hallway_005_mesh_layer_1_vtx_2();
	scroll_hmc_dl_Hallway_005_mesh_layer_1_vtx_5();
	scroll_hmc_dl_Maze_mesh_layer_1_vtx_0();
	scroll_hmc_dl_MazeNoCol_mesh_layer_1_vtx_0();
	scroll_hmc_dl_ASaunaGlobal_mesh_layer_1_vtx_3();
	scroll_sts_mat_hmc_dl_SaunaLava_layer1();
	scroll_hmc_dl_Sauna1_001_mesh_layer_1_vtx_4();
	scroll_hmc_dl_Steam_001_mesh_layer_5_vtx_0();
	scroll_hmc_dl_SaunaMat_mesh_layer_1_vtx_0();
	scroll_sts_mat_hmc_dl_SaunaLavaDyn_layer1();
}
