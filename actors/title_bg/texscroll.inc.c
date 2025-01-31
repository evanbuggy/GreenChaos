void scroll_title_bg_Plane_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 4;
	int width = 128 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(title_bg_Plane_mesh_layer_1_vtx_0);

	deltaX = (int)(-0.5 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_title_bg_Plane_mesh_layer_1_vtx_2() {
	int i = 0;
	int count = 4;
	int width = 128 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(title_bg_Plane_mesh_layer_1_vtx_2);

	deltaX = (int)(-0.5 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_title_bg_Plane_mesh_layer_1_vtx_3() {
	int i = 0;
	int count = 4;
	int width = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(title_bg_Plane_mesh_layer_1_vtx_3);

	deltaX = (int)(0.5 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_title_bg_Plane_mesh_layer_1_vtx_4() {
	int i = 0;
	int count = 4;
	int width = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(title_bg_Plane_mesh_layer_1_vtx_4);

	deltaX = (int)(-0.5 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_title_bg_Plane_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 8;
	int width = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(title_bg_Plane_mesh_layer_5_vtx_0);

	deltaX = (int)(0.0 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_actor_geo_title_bg() {
	scroll_title_bg_Plane_mesh_layer_1_vtx_0();
	scroll_title_bg_Plane_mesh_layer_1_vtx_2();
	scroll_title_bg_Plane_mesh_layer_1_vtx_3();
	scroll_title_bg_Plane_mesh_layer_1_vtx_4();
	scroll_title_bg_Plane_mesh_layer_5_vtx_0();
};
