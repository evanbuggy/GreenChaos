#include "src/game/envfx_snow.h"

const GeoLayout red_coin_new_Ring2[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, red_coin_new_000_switch_001_mesh_layer_4),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout red_coin_new_Ring3[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, red_coin_new_000_switch_002_mesh_layer_4),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout red_coin_new_Ring4[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, red_coin_new_000_switch_003_mesh_layer_4),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout red_coin_new_Ring5[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, red_coin_new_000_switch_004_mesh_layer_4),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout red_coin_new_Ring6[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, red_coin_new_000_switch_005_mesh_layer_4),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout red_coin_new_Ring7[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, red_coin_new_000_switch_006_mesh_layer_4),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout red_coin_new_Ring8[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, red_coin_new_000_switch_007_mesh_layer_4),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout red_coin_new_Ring9[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, red_coin_new_000_switch_008_mesh_layer_4),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout red_coin_new_Ring10[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, red_coin_new_000_switch_009_mesh_layer_4),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout red_coin_new_Ring11[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, red_coin_new_000_switch_010_mesh_layer_4),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout red_coin_new_Ring12[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, red_coin_new_000_switch_011_mesh_layer_4),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout red_coin_new_Ring13[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, red_coin_new_000_switch_012_mesh_layer_4),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout red_coin_new_Ring14[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, red_coin_new_000_switch_013_mesh_layer_4),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout red_coin_new_Ring15[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, red_coin_new_000_switch_014_mesh_layer_4),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout red_coin_new_Ring16[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, red_coin_new_000_switch_015_mesh_layer_4),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout red_coin_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SHADOW(0, 50, 400),
		GEO_OPEN_NODE(),
			GEO_SWITCH_CASE(8, geo_switch_anim_state),
			GEO_OPEN_NODE(),
				GEO_NODE_START(),
				GEO_OPEN_NODE(),
					GEO_DISPLAY_LIST(LAYER_ALPHA, red_coin_new_000_displaylist_mesh_layer_4),
				GEO_CLOSE_NODE(),
				GEO_BRANCH(1, red_coin_new_Ring2),
				GEO_BRANCH(1, red_coin_new_Ring3),
				GEO_BRANCH(1, red_coin_new_Ring4),
				GEO_BRANCH(1, red_coin_new_Ring5),
				GEO_BRANCH(1, red_coin_new_Ring6),
				GEO_BRANCH(1, red_coin_new_Ring7),
				GEO_BRANCH(1, red_coin_new_Ring8),
				GEO_BRANCH(1, red_coin_new_Ring9),
				GEO_BRANCH(1, red_coin_new_Ring10),
				GEO_BRANCH(1, red_coin_new_Ring11),
				GEO_BRANCH(1, red_coin_new_Ring12),
				GEO_BRANCH(1, red_coin_new_Ring13),
				GEO_BRANCH(1, red_coin_new_Ring14),
				GEO_BRANCH(1, red_coin_new_Ring15),
				GEO_BRANCH(1, red_coin_new_Ring16),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

const GeoLayout red_coin_no_shadow_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_OPEN_NODE(),
			GEO_SWITCH_CASE(8, geo_switch_anim_state),
			GEO_OPEN_NODE(),
				GEO_NODE_START(),
				GEO_OPEN_NODE(),
					GEO_DISPLAY_LIST(LAYER_ALPHA, red_coin_new_000_displaylist_mesh_layer_4),
				GEO_CLOSE_NODE(),
				GEO_BRANCH(1, red_coin_new_Ring2),
				GEO_BRANCH(1, red_coin_new_Ring3),
				GEO_BRANCH(1, red_coin_new_Ring4),
				GEO_BRANCH(1, red_coin_new_Ring5),
				GEO_BRANCH(1, red_coin_new_Ring6),
				GEO_BRANCH(1, red_coin_new_Ring7),
				GEO_BRANCH(1, red_coin_new_Ring8),
				GEO_BRANCH(1, red_coin_new_Ring9),
				GEO_BRANCH(1, red_coin_new_Ring10),
				GEO_BRANCH(1, red_coin_new_Ring11),
				GEO_BRANCH(1, red_coin_new_Ring12),
				GEO_BRANCH(1, red_coin_new_Ring13),
				GEO_BRANCH(1, red_coin_new_Ring14),
				GEO_BRANCH(1, red_coin_new_Ring15),
				GEO_BRANCH(1, red_coin_new_Ring16),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_END(),
};