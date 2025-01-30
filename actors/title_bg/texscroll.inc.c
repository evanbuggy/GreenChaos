void scroll_title_bg_Plane_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 14;
	int width = 32 * 0x20;

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

void scroll_title_bg_Plane_mesh_layer_1_vtx_1() {
	int i = 0;
	int count = 14;
	int width = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(title_bg_Plane_mesh_layer_1_vtx_1);

	deltaX = (int)(-0.5 * 0x20) % width;

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
	scroll_title_bg_Plane_mesh_layer_1_vtx_1();
};
