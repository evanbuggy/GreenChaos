#include "src/game/envfx_snow.h"

const GeoLayout bug_luigi_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, bug_luigi_Body_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_ALPHA, bug_luigi_Body_mesh_layer_4),
			GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 0, 100, 0, -90, 0, 0),
			GEO_OPEN_NODE(),
				GEO_ANIMATED_PART(LAYER_ALPHA, 0, 0, 0, bug_luigi_WingL_mesh_layer_4),
			GEO_CLOSE_NODE(),
			GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 0, 100, 0, 90, 0, 0),
			GEO_OPEN_NODE(),
				GEO_ANIMATED_PART(LAYER_ALPHA, 0, 0, 0, bug_luigi_WingR_mesh_layer_4),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
