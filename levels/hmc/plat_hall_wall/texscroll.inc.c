void scroll_plat_hall_wall_platwall_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 4;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	static int timeY;
	float amplitudeY = 0.800000011920929;
	float frequencyY = 0.10000000149011612;
	float offsetY = 0.0;
	Vtx *vertices = segmented_to_virtual(plat_hall_wall_platwall_mesh_layer_1_vtx_0);

	deltaY = (int)(amplitudeY * frequencyY * coss((frequencyY * timeY + offsetY) * (1024 * 16 - 1) / 6.28318530718) * 0x20);

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;	timeY += 1;
}

void scroll_sts_mat_plat_hall_wall_PlatWallObj_layer1() {
	static int intervalTex0 = 15;
	static int curInterval0 = 15;
	Gfx *mat = segmented_to_virtual(mat_plat_hall_wall_PlatWallObj_layer1);

	if (--curInterval0 <= 0) {
		shift_s_down(mat, 14, PACK_TILESIZE(0, 20));
		curInterval0 = intervalTex0;
	}
	shift_s(mat, 22, PACK_TILESIZE(0, 5));
};

void scroll_hmc_level_geo_plat_hall_wall() {
	scroll_plat_hall_wall_platwall_mesh_layer_1_vtx_0();
	scroll_sts_mat_plat_hall_wall_PlatWallObj_layer1();
}
