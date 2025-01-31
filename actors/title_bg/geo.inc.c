#include "src/game/envfx_snow.h"

const GeoLayout title_bg_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BILLBOARD_WITH_PARAMS_AND_DL(LAYER_OPAQUE, 0, 0, 0, title_bg_Plane_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_BILLBOARD_WITH_PARAMS_AND_DL(LAYER_TRANSPARENT, 0, 0, 0, title_bg_Plane_mesh_layer_5),
			GEO_BILLBOARD_WITH_PARAMS_AND_DL(LAYER_ALPHA, 0, 0, 0, title_bg_Plane_mesh_layer_4),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
