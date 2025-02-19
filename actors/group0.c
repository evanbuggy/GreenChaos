#include <ultra64.h>
#include "sm64.h"
#include "surface_terrains.h"
#include "geo_commands.h"

#include "make_const_nonconst.h"

// Note: This bin does not use bin IDs, unlike the other segmented bins.
#include "mario/model.inc.c"

#include "bubble/model.inc.c"

#include "walk_smoke/model.inc.c"

#include "burn_smoke/model.inc.c"

#include "small_water_splash/model.inc.c"

#include "water_wave/model.inc.c"

#include "sparkle/model.inc.c"

#include "water_splash/model.inc.c"

#include "white_particle_small/model.inc.c"

#include "sparkle_animation/model.inc.c"

#ifdef S2DEX_TEXT_ENGINE
#include "src/s2d_engine/s2d_config.h"
#include FONT_C_FILE
#endif

#include "star_ring/model.inc.c"
#include "shadow_mario_title/model.inc.c"
#include "title_bg/model.inc.c"
#include "title_logo/model.inc.c"
#include "simpleflips_npc/model.inc.c"
#include "simpleflips/anims/data.inc.c"
#include "simpleflips/anims/table.inc.c"
#include "void_tree/model.inc.c"
#include "electro_luigi/model.inc.c"
#include "electro_luigi/anims/data.inc.c"
#include "electro_luigi/anims/table.inc.c"
#include "starselectbg/model.inc.c"
#include "luigi_doll/model.inc.c"
#include "GreenSpring/model.inc.c"
#include "RingBox/model.inc.c"
#include "LifeBox/model.inc.c"