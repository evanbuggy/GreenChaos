#include "src/game/envfx_snow.h"

const GeoLayout char_title_intro_Frame2[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, char_title_intro_000_switch_001_displaylist_mesh_layer_4),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout char_title_intro_Frame3[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, char_title_intro_000_switch_002_displaylist_mesh_layer_4),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout char_title_intro_Frame4[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, char_title_intro_000_switch_003_displaylist_mesh_layer_4),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout char_title_intro_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SHADOW(0, 180, 50),
		GEO_OPEN_NODE(),
			GEO_SWITCH_CASE(5, geo_switch_anim_state),
			GEO_OPEN_NODE(),
				GEO_NODE_START(),
				GEO_OPEN_NODE(),
					GEO_DISPLAY_LIST(LAYER_ALPHA, char_title_intro_000_displaylist_mesh_layer_4),
				GEO_CLOSE_NODE(),
				GEO_BRANCH(1, char_title_intro_Frame2),
				GEO_BRANCH(1, char_title_intro_Frame2),
				GEO_BRANCH(1, char_title_intro_Frame3),
				GEO_BRANCH(1, char_title_intro_Frame3),
				GEO_BRANCH(1, char_title_intro_Frame4),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
