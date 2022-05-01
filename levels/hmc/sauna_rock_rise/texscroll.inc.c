void scroll_sauna_rock_rise_SaunaRockRise_mesh_layer_1_vtx_1() {
	int i = 0;
	int count = 14;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(sauna_rock_rise_SaunaRockRise_mesh_layer_1_vtx_1);

	deltaY = (int)(-0.5 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_sts_mat_sauna_rock_rise_SaunaLavaDyn_layer1() {
	static int intervalTex0 = 2;
	static int curInterval0 = 2;
	Gfx *mat = segmented_to_virtual(mat_sauna_rock_rise_SaunaLavaDyn_layer1);

	if (--curInterval0 <= 0) {
		shift_t(mat, 13, PACK_TILESIZE(0, 1));
		curInterval0 = intervalTex0;
	}
	shift_t(mat, 21, PACK_TILESIZE(0, 1));
};

void scroll_hmc_level_geo_sauna_rock_rise() {
	scroll_sauna_rock_rise_SaunaRockRise_mesh_layer_1_vtx_1();
	scroll_sts_mat_sauna_rock_rise_SaunaLavaDyn_layer1();
}
