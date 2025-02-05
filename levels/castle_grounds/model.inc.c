Vtx castle_grounds_dl_Cube_mesh_layer_1_vtx_cull[8] = {
	{{ {-14173, 100, 14173}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {-14173, 100, 14173}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {-14173, 100, -14173}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {-14173, 100, -14173}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {14173, 100, 14173}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {14173, 100, 14173}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {14173, 100, -14173}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {14173, 100, -14173}, 0, {0, 0}, {0, 0, 0, 0} }},
};

Vtx castle_grounds_dl_Cube_mesh_layer_1_vtx_0[4] = {
	{{ {14173, 100, -14173}, 0, {624, 496}, {0, 127, 0, 0} }},
	{{ {-14173, 100, -14173}, 0, {880, 496}, {0, 127, 0, 0} }},
	{{ {-14173, 100, 14173}, 0, {880, 240}, {0, 127, 0, 0} }},
	{{ {14173, 100, 14173}, 0, {624, 240}, {0, 127, 0, 0} }},
};

Gfx castle_grounds_dl_Cube_mesh_layer_1_tri_0[] = {
	gsSPVertex(castle_grounds_dl_Cube_mesh_layer_1_vtx_0 + 0, 4, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSPEndDisplayList(),
};

Gfx mat_castle_grounds_dl_sm64_material_001[] = {
	gsSPLightColor(LIGHT_1, 0xFFFFFFFF),
	gsSPLightColor(LIGHT_2, 0x7F7F7FFF),
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPEndDisplayList(),
};

Gfx mat_revert_castle_grounds_dl_sm64_material_001[] = {
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsSPEndDisplayList(),
};

Gfx castle_grounds_dl_Cube_mesh_layer_1[] = {
	gsSPClearGeometryMode(G_LIGHTING),
	gsSPVertex(castle_grounds_dl_Cube_mesh_layer_1_vtx_cull + 0, 8, 0),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPCullDisplayList(0, 7),
	gsSPDisplayList(mat_castle_grounds_dl_sm64_material_001),
	gsSPDisplayList(castle_grounds_dl_Cube_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_castle_grounds_dl_sm64_material_001),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};

