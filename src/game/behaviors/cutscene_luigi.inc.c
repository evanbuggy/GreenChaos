void bhv_cutscene_luigi_loop(void) {
    //cur_obj_update_dialog_with_cutscene(MARIO_DIALOG_LOOK_UP, DIALOG_FLAG_TURN_TO_MARIO, CUTSCENE_START_LUIGI, DIALOG_114);
    if (gMarioState->controller->buttonPressed & START_BUTTON ) {
        level_trigger_warp(gMarioState, WARP_OP_STAR_EXIT);
    }

    if (o->oBehParams2ndByte != 1) {
        cutscene_object_with_dialog(CUTSCENE_START_LUIGI, o, DIALOG_063);

        switch (o->oTimer) {
            case 100:
                cur_obj_init_animation(2);
                play_sound(SOUND_MARIO_YAWNING, gGlobalSoundSource);
                break;
    
            case 120:
                cur_obj_init_animation(0);
                break;
            
            case 150:
                cur_obj_init_animation(4);
                play_sound(SOUND_MARIO_COUGHING3, gGlobalSoundSource);
                break;
    
            case 305:
                cur_obj_init_animation(0);
                cur_obj_rotate_yaw_toward(0, 180);
                obj_copy_angle(spawn_object_relative(OBJ_BP_NONE, 0, 900, 300, o, MODEL_LM_STAR_SELECT, bhvCutsceneEmerald), o);
                break;
    
            case 310:
                play_sound(SOUND_MARIO_WHOA, gGlobalSoundSource);
                break;
    
            case 365:
                play_sound(SOUND_MARIO_HAHA, gGlobalSoundSource);
                break;
    
            case 500:
                play_sound(SOUND_MARIO_MAMA_MIA, gGlobalSoundSource);
                break;
    
            case 550:
                cur_obj_init_animation(3);
                play_sound(SOUND_OBJ_THWOMP, gGlobalSoundSource);
                play_sound(SOUND_MARIO_WAAAOOOW, gGlobalSoundSource);
                play_luigi_cutscene_jingle();
                break;

            case 580:
                play_sound(SOUND_GENERAL_WALL_EXPLOSION, gGlobalSoundSource);
                spawn_triangle_break_particles(5, MODEL_CARTOON_STAR, 0.3f, 3);
                spawn_object_relative(0x1, 0, 0, 0, o, MODEL_MR_L, bhvCutsceneLuigi);
                o->oPosX = 0;
                o->oPosY = -500;
                o->oPosZ = 9000;
                break;
            default:
                break;
        }
    }
    else {
        cur_obj_init_animation(0);
    }
}