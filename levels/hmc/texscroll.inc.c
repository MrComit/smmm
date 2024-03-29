void scroll_sts_mat_hmc_dl_Wall_002_layer1() {
	static int intervalTex1 = 2;
	static int curInterval1 = 2;
	Gfx *mat = segmented_to_virtual(mat_hmc_dl_Wall_002_layer1);

	if (--curInterval1 <= 0) {
		shift_s(mat, 15, PACK_TILESIZE(0, 1));
		curInterval1 = intervalTex1;
	}
};

void scroll_sts_mat_hmc_dl_WoodFloor_002_layer1() {
	static int intervalTex1 = 3;
	static int curInterval1 = 3;
	Gfx *mat = segmented_to_virtual(mat_hmc_dl_WoodFloor_002_layer1);

	if (--curInterval1 <= 0) {
		shift_s(mat, 15, PACK_TILESIZE(0, 1));
		shift_t(mat, 15, PACK_TILESIZE(0, 2));
		curInterval1 = intervalTex1;
	}
};

void scroll_sts_mat_hmc_dl_FlowerPetal_002_v4_002_layer1() {
	Gfx *mat = segmented_to_virtual(mat_hmc_dl_FlowerPetal_002_v4_002_layer1);
	shift_t_down(mat, 15, PACK_TILESIZE(0, 2));
};

void scroll_sts_mat_hmc_dl_Vase_v4_003_layer1() {
	Gfx *mat = segmented_to_virtual(mat_hmc_dl_Vase_v4_003_layer1);
	shift_s(mat, 10, PACK_TILESIZE(0, 4));
};

void scroll_sts_mat_hmc_dl_WoodFloorTrophyRoom_002_layer1() {
	static int intervalTex1 = 3;
	static int curInterval1 = 3;
	Gfx *mat = segmented_to_virtual(mat_hmc_dl_WoodFloorTrophyRoom_002_layer1);

	if (--curInterval1 <= 0) {
		shift_s(mat, 16, PACK_TILESIZE(0, 1));
		shift_t(mat, 16, PACK_TILESIZE(0, 2));
		curInterval1 = intervalTex1;
	}
};

void scroll_sts_mat_hmc_dl_RedWall_002_layer1() {
	static int intervalTex1 = 2;
	static int curInterval1 = 2;
	Gfx *mat = segmented_to_virtual(mat_hmc_dl_RedWall_002_layer1);

	if (--curInterval1 <= 0) {
		shift_s(mat, 15, PACK_TILESIZE(0, 2));
		shift_t(mat, 15, PACK_TILESIZE(0, 1));
		curInterval1 = intervalTex1;
	}
};

void scroll_hmc_dl_TrophyRoom_017_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 4;
	int width = 64 * 0x20;
	int height = 128 * 0x20;

	static int currentX = 0;
	int deltaX;
	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(hmc_dl_TrophyRoom_017_mesh_layer_1_vtx_0);

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
		shift_s(mat, 10, PACK_TILESIZE(0, 13));
		shift_t(mat, 10, PACK_TILESIZE(0, 2));
		curInterval0 = intervalTex0;
	}
	shift_s(mat, 15, PACK_TILESIZE(0, 1));
	shift_t(mat, 15, PACK_TILESIZE(0, 6));
};

void scroll_sts_mat_hmc_dl_GhostPainting_layer1() {
	static int intervalTex1 = 2;
	static int curInterval1 = 2;
	Gfx *mat = segmented_to_virtual(mat_hmc_dl_GhostPainting_layer1);
	shift_s(mat, 10, PACK_TILESIZE(0, 1));

	if (--curInterval1 <= 0) {
		shift_s(mat, 15, PACK_TILESIZE(0, 1));
		shift_t(mat, 15, PACK_TILESIZE(0, 1));
		curInterval1 = intervalTex1;
	}
};

void scroll_sts_mat_hmc_dl_Cons3_layer1() {
	Gfx *mat = segmented_to_virtual(mat_hmc_dl_Cons3_layer1);
	shift_t(mat, 10, PACK_TILESIZE(0, 6));
	shift_t(mat, 15, PACK_TILESIZE(0, 7));
};

void scroll_hmc_dl_TrophyRoom_017_mesh_layer_6_vtx_0() {
	int i = 0;
	int count = 4;
	int height = 128 * 0x20;

	static int currentY = 0;
	int deltaY;
	static int timeY;
	float amplitudeY = 5.0;
	float frequencyY = 0.20000000298023224;
	float offsetY = 0.0;
	Vtx *vertices = segmented_to_virtual(hmc_dl_TrophyRoom_017_mesh_layer_6_vtx_0);

	deltaY = (int)(amplitudeY * frequencyY * coss((frequencyY * timeY + offsetY) * (1024 * 16 - 1) / 6.28318530718) * 0x20);

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;	timeY += 1;
}

void scroll_sts_mat_hmc_dl_GhostTeeth() {
	Gfx *mat = segmented_to_virtual(mat_hmc_dl_GhostTeeth);
	shift_s_down(mat, 12, PACK_TILESIZE(0, 2));
};

void scroll_sts_mat_hmc_dl_BooGoo_layer1() {
	Gfx *mat = segmented_to_virtual(mat_hmc_dl_BooGoo_layer1);
	shift_s(mat, 10, PACK_TILESIZE(0, 1));
	shift_s(mat, 15, PACK_TILESIZE(0, 1));
	shift_t(mat, 15, PACK_TILESIZE(0, 1));
};

void scroll_sts_mat_hmc_dl_WoodFloorTransparent_002_layer1() {
	static int intervalTex1 = 3;
	static int curInterval1 = 3;
	Gfx *mat = segmented_to_virtual(mat_hmc_dl_WoodFloorTransparent_002_layer1);

	if (--curInterval1 <= 0) {
		shift_s(mat, 17, PACK_TILESIZE(0, 1));
		shift_t(mat, 17, PACK_TILESIZE(0, 2));
		curInterval1 = intervalTex1;
	}
};

void scroll_hmc_dl_Paintings_001_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 6;
	int width = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(hmc_dl_Paintings_001_mesh_layer_1_vtx_0);

	deltaX = (int)(-0.5 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_hmc_dl_Paintings_001_mesh_layer_1_vtx_1() {
	int i = 0;
	int count = 9;
	int width = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(hmc_dl_Paintings_001_mesh_layer_1_vtx_1);

	deltaX = (int)(0.5 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_hmc_dl_Paintings_001_mesh_layer_1_vtx_6() {
	int i = 0;
	int count = 7;
	int width = 128 * 0x20;
	int height = 128 * 0x20;

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
	Vtx *vertices = segmented_to_virtual(hmc_dl_Paintings_001_mesh_layer_1_vtx_6);

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

void scroll_sts_mat_hmc_dl_Cons1_layer1() {
	static int intervalTex0 = 20;
	static int curInterval0 = 20;
	static int intervalTex1 = 20;
	static int curInterval1 = 20;
	Gfx *mat = segmented_to_virtual(mat_hmc_dl_Cons1_layer1);

	if (--curInterval0 <= 0) {
		shift_t(mat, 10, PACK_TILESIZE(0, 16));
		curInterval0 = intervalTex0;
	}

	if (--curInterval1 <= 0) {
		shift_t(mat, 15, PACK_TILESIZE(0, 16));
		curInterval1 = intervalTex1;
	}
};

void scroll_sts_mat_hmc_dl_Study1_002() {
	Gfx *mat = segmented_to_virtual(mat_hmc_dl_Study1_002);
	shift_s(mat, 13, PACK_TILESIZE(0, 1));
};

void scroll_sts_mat_hmc_dl_Parlor1_002_layer1() {
	Gfx *mat = segmented_to_virtual(mat_hmc_dl_Parlor1_002_layer1);
	shift_t(mat, 15, PACK_TILESIZE(0, 1));
};

void scroll_sts_mat_hmc_dl_WoodFloorOneCycle_002() {
	static int intervalTex1 = 3;
	static int curInterval1 = 3;
	Gfx *mat = segmented_to_virtual(mat_hmc_dl_WoodFloorOneCycle_002);

	if (--curInterval1 <= 0) {
		shift_s(mat, -1, PACK_TILESIZE(0, 1));
		shift_t(mat, -1, PACK_TILESIZE(0, 2));
		curInterval1 = intervalTex1;
	}
};

void scroll_sts_mat_hmc_dl_Lava_002_layer1() {
	static int intervalTex1 = 2;
	static int curInterval1 = 2;
	Gfx *mat = segmented_to_virtual(mat_hmc_dl_Lava_002_layer1);
	shift_t(mat, 10, PACK_TILESIZE(0, 1));

	if (--curInterval1 <= 0) {
		shift_s(mat, 15, PACK_TILESIZE(0, 1));
		shift_t(mat, 15, PACK_TILESIZE(0, 1));
		curInterval1 = intervalTex1;
	}
};

void scroll_sts_mat_hmc_dl_WallDither_002_layer1() {
	static int intervalTex1 = 2;
	static int curInterval1 = 2;
	Gfx *mat = segmented_to_virtual(mat_hmc_dl_WallDither_002_layer1);

	if (--curInterval1 <= 0) {
		shift_s(mat, 16, PACK_TILESIZE(0, 1));
		curInterval1 = intervalTex1;
	}
};

void scroll_hmc_dl_Repeats_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 1059;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	static int timeY;
	float amplitudeY = 0.800000011920929;
	float frequencyY = 0.10000000149011612;
	float offsetY = 0.0;
	Vtx *vertices = segmented_to_virtual(hmc_dl_Repeats_mesh_layer_1_vtx_0);

	deltaY = (int)(amplitudeY * frequencyY * coss((frequencyY * timeY + offsetY) * (1024 * 16 - 1) / 6.28318530718) * 0x20);

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;	timeY += 1;
}

void scroll_sts_mat_hmc_dl_WallTransition_002_layer1() {
	static int intervalTex0 = 15;
	static int curInterval0 = 15;
	Gfx *mat = segmented_to_virtual(mat_hmc_dl_WallTransition_002_layer1);

	if (--curInterval0 <= 0) {
		shift_s_down(mat, 10, PACK_TILESIZE(0, 20));
		curInterval0 = intervalTex0;
	}
	shift_s(mat, 15, PACK_TILESIZE(0, 5));
};

void scroll_sts_mat_hmc_dl_MazeBooGoo_layer1() {
	Gfx *mat = segmented_to_virtual(mat_hmc_dl_MazeBooGoo_layer1);
	shift_s(mat, 10, PACK_TILESIZE(0, 1));
	shift_s(mat, 15, PACK_TILESIZE(0, 1));
	shift_t(mat, 15, PACK_TILESIZE(0, 1));
};

void scroll_hmc_dl_BelowMaze_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 270;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	static int timeY;
	float amplitudeY = 0.800000011920929;
	float frequencyY = 0.10000000149011612;
	float offsetY = 0.0;
	Vtx *vertices = segmented_to_virtual(hmc_dl_BelowMaze_mesh_layer_1_vtx_0);

	deltaY = (int)(amplitudeY * frequencyY * coss((frequencyY * timeY + offsetY) * (1024 * 16 - 1) / 6.28318530718) * 0x20);

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;	timeY += 1;
}

void scroll_sts_mat_hmc_dl_MazeWall_layer1() {
	static int intervalTex0 = 15;
	static int curInterval0 = 15;
	Gfx *mat = segmented_to_virtual(mat_hmc_dl_MazeWall_layer1);

	if (--curInterval0 <= 0) {
		shift_s_down(mat, 10, PACK_TILESIZE(0, 20));
		curInterval0 = intervalTex0;
	}
	shift_s(mat, 15, PACK_TILESIZE(0, 5));
};

void scroll_hmc_dl_Hallway_005_mesh_layer_1_vtx_2() {
	int i = 0;
	int count = 734;
	int height = 64 * 0x20;

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

void scroll_hmc_dl_1Maze_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 4;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	static int timeY;
	float amplitudeY = 0.800000011920929;
	float frequencyY = 0.10000000149011612;
	float offsetY = 0.0;
	Vtx *vertices = segmented_to_virtual(hmc_dl_1Maze_mesh_layer_1_vtx_0);

	deltaY = (int)(amplitudeY * frequencyY * coss((frequencyY * timeY + offsetY) * (1024 * 16 - 1) / 6.28318530718) * 0x20);

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;	timeY += 1;
}

void scroll_hmc_dl_Maze_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 624;
	int height = 64 * 0x20;

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

void scroll_hmc_dl_Maze1NoCol_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 4;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	static int timeY;
	float amplitudeY = 0.800000011920929;
	float frequencyY = 0.10000000149011612;
	float offsetY = 0.0;
	Vtx *vertices = segmented_to_virtual(hmc_dl_Maze1NoCol_mesh_layer_1_vtx_0);

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
	int count = 453;
	int height = 64 * 0x20;

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

void scroll_sts_mat_hmc_dl_SaunaLava_001_v5_001_layer1() {
	Gfx *mat = segmented_to_virtual(mat_hmc_dl_SaunaLava_001_v5_001_layer1);
	shift_t(mat, 14, PACK_TILESIZE(0, 1));
};

void scroll_hmc_dl_Sauna1_001_mesh_layer_1_vtx_5() {
	int i = 0;
	int count = 47;
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
	Vtx *vertices = segmented_to_virtual(hmc_dl_Sauna1_001_mesh_layer_1_vtx_5);

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

void scroll_sts_mat_hmc_dl_SaunaLava_002_layer1() {
	Gfx *mat = segmented_to_virtual(mat_hmc_dl_SaunaLava_002_layer1);
	shift_t(mat, 14, PACK_TILESIZE(0, 1));
};

void scroll_hmc_dl_Steam_001_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 16;
	int width = 128 * 0x20;
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

void scroll_sts_mat_hmc_dl_SaunaLavaDyn_001_v5_001_layer1() {
	static int intervalTex0 = 2;
	static int curInterval0 = 2;
	Gfx *mat = segmented_to_virtual(mat_hmc_dl_SaunaLavaDyn_001_v5_001_layer1);

	if (--curInterval0 <= 0) {
		shift_t(mat, 10, PACK_TILESIZE(0, 1));
		curInterval0 = intervalTex0;
	}
	shift_t(mat, 15, PACK_TILESIZE(0, 1));
};

void scroll_hmc_dl_Attic_mesh_layer_1_vtx_3() {
	int i = 0;
	int count = 48;
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
	Vtx *vertices = segmented_to_virtual(hmc_dl_Attic_mesh_layer_1_vtx_3);

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

void scroll_hmc_dl_Attic_004_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 28;
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
	Vtx *vertices = segmented_to_virtual(hmc_dl_Attic_004_mesh_layer_1_vtx_0);

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

void scroll_sts_mat_hmc_dl_Vase_v4_001_layer1() {
	Gfx *mat = segmented_to_virtual(mat_hmc_dl_Vase_v4_001_layer1);
	shift_s(mat, 10, PACK_TILESIZE(0, 4));
};

void scroll_hmc() {
	scroll_sts_mat_hmc_dl_Wall_002_layer1();
	scroll_sts_mat_hmc_dl_WoodFloor_002_layer1();
	scroll_sts_mat_hmc_dl_FlowerPetal_002_v4_002_layer1();
	scroll_sts_mat_hmc_dl_Vase_v4_003_layer1();
	scroll_sts_mat_hmc_dl_WoodFloorTrophyRoom_002_layer1();
	scroll_sts_mat_hmc_dl_RedWall_002_layer1();
	scroll_hmc_dl_TrophyRoom_017_mesh_layer_1_vtx_0();
	scroll_sts_mat_hmc_dl_CreepyEyes_layer1();
	scroll_sts_mat_hmc_dl_GhostPainting_layer1();
	scroll_sts_mat_hmc_dl_Cons3_layer1();
	scroll_hmc_dl_TrophyRoom_017_mesh_layer_6_vtx_0();
	scroll_sts_mat_hmc_dl_GhostTeeth();
	scroll_sts_mat_hmc_dl_BooGoo_layer1();
	scroll_sts_mat_hmc_dl_WoodFloorTransparent_002_layer1();
	scroll_hmc_dl_Paintings_001_mesh_layer_1_vtx_0();
	scroll_hmc_dl_Paintings_001_mesh_layer_1_vtx_1();
	scroll_hmc_dl_Paintings_001_mesh_layer_1_vtx_6();
	scroll_sts_mat_hmc_dl_Cons1_layer1();
	scroll_sts_mat_hmc_dl_Study1_002();
	scroll_sts_mat_hmc_dl_Parlor1_002_layer1();
	scroll_sts_mat_hmc_dl_WoodFloorOneCycle_002();
	scroll_sts_mat_hmc_dl_Lava_002_layer1();
	scroll_sts_mat_hmc_dl_WallDither_002_layer1();
	scroll_hmc_dl_Repeats_mesh_layer_1_vtx_0();
	scroll_sts_mat_hmc_dl_WallTransition_002_layer1();
	scroll_sts_mat_hmc_dl_MazeBooGoo_layer1();
	scroll_hmc_dl_BelowMaze_mesh_layer_1_vtx_0();
	scroll_sts_mat_hmc_dl_MazeWall_layer1();
	scroll_hmc_dl_Hallway_005_mesh_layer_1_vtx_2();
	scroll_hmc_dl_1Maze_mesh_layer_1_vtx_0();
	scroll_hmc_dl_Maze_mesh_layer_1_vtx_0();
	scroll_hmc_dl_Maze1NoCol_mesh_layer_1_vtx_0();
	scroll_hmc_dl_MazeNoCol_mesh_layer_1_vtx_0();
	scroll_hmc_dl_ASaunaGlobal_mesh_layer_1_vtx_3();
	scroll_sts_mat_hmc_dl_SaunaLava_001_v5_001_layer1();
	scroll_hmc_dl_Sauna1_001_mesh_layer_1_vtx_5();
	scroll_sts_mat_hmc_dl_SaunaLava_002_layer1();
	scroll_hmc_dl_Steam_001_mesh_layer_5_vtx_0();
	scroll_hmc_dl_SaunaMat_mesh_layer_1_vtx_0();
	scroll_sts_mat_hmc_dl_SaunaLavaDyn_001_v5_001_layer1();
	scroll_hmc_dl_Attic_mesh_layer_1_vtx_3();
	scroll_hmc_dl_Attic_004_mesh_layer_1_vtx_0();
	scroll_sts_mat_hmc_dl_Vase_v4_001_layer1();
}
