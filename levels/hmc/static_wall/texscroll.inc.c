void scroll_static_wall_staticwall_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 62;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(static_wall_staticwall_mesh_layer_1_vtx_0);

	deltaX = (int)(31.630001068115234 * 0x20 * random_float() * random_sign()) % width;
	deltaY = (int)(33.279998779296875 * 0x20 * random_float() * random_sign()) % height;

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

void scroll_sts_mat_static_wall_Obstacle_002() {
	static int intervalTex0 = 2;
	static int curInterval0 = 2;
	Gfx *mat = segmented_to_virtual(mat_static_wall_Obstacle_002);

	if (--curInterval0 <= 0) {
		shift_s(mat, 11, PACK_TILESIZE(0, 12));
		shift_t(mat, 11, PACK_TILESIZE(0, 3));
		curInterval0 = intervalTex0;
	}
};

void scroll_hmc_level_geo_static_wall() {
	scroll_static_wall_staticwall_mesh_layer_1_vtx_0();
	scroll_sts_mat_static_wall_Obstacle_002();
}
