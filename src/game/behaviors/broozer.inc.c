static struct ObjectHitbox sBroozerHitbox = {
    /* interactType:      */ INTERACT_COMBAT_ENEMY,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 20,
    /* numLootCoins:      */ 1,
    /* radius:            */ 150,
    /* height:            */ 250,
    /* hurtboxRadius:     */ 100,
    /* hurtboxHeight:     */ 200,   
};

static u8 sBroozerAttackHandlers[6] = {
    /* ATTACK_PUNCH:                 */ ATTACK_HANDLER_KNOCKBACK,
    /* ATTACK_KICK_OR_TRIP:          */ ATTACK_HANDLER_KNOCKBACK,
    /* ATTACK_FROM_ABOVE:            */ ATTACK_HANDLER_SQUISHED,
    /* ATTACK_GROUND_POUND_OR_TWIRL: */ ATTACK_HANDLER_KNOCKBACK,
    /* ATTACK_FAST_ATTACK:           */ ATTACK_HANDLER_KNOCKBACK,
    /* ATTACK_SPIN_SAW:              */ ATTACK_HANDLER_KNOCKBACK,
};

u8 start = 0;

void bhv_broozer_init(void) {
    o->oInvFrames = 0;
    o->oHitstopFrames = 0;
    start = 0;
}

void broozer(void) {
    start = 1;
    cur_obj_update_floor_and_walls();
    if (o->oMoveFlags & OBJ_MOVE_BOUNCE) {
        if (o->oMoveFlags & OBJ_MOVE_ABOVE_DEATH_BARRIER) {
            o->oPosX = 0;
            o->oPosY = 1000;
            o->oPosZ = 0;
            play_sound(SOUND_ACTION_TELEPORT, gGlobalSoundSource);
        }
        else {
            cur_obj_play_sound_2(SOUND_OBJ_POUNDING_LOUD);
            cur_obj_init_animation(3);
        }
    }

    if (o->oMoveFlags & OBJ_MOVE_ON_GROUND) {
        cur_obj_rotate_yaw_toward(o->oAngleToMario, 0x800);
        obj_forward_vel_approach(100, 0.4f);
        if (o->oDistanceToMario < 600) {
            if (o->oTimer >= 30) {
                o->oTimer = 0;
            }
            switch (o->oTimer) {
                case 0:
                    if (random_float() >= 0.5f) {
                        cur_obj_play_sound_2(SOUND_OBJ_WIGGLER_JUMP);
                        o->oVelY = 80.0f;
                    }
                    else {
                        cur_obj_init_animation(2);
                    }
                    break;
        
                case 8:
                    spawn_object_relative_with_scale(OBJ_BP_NONE, 100, 200, 400, 3, o, MODEL_NONE, bhvExplosion);
                    o->oForwardVel = 200.0f;
                    break;
        
                case 15:
                    cur_obj_init_animation(3);
                    break;
        
                default:
                    break;
            }
        }
        else {
            cur_obj_init_animation(3);
        }
    }

    if (obj_handle_attacks(&sBroozerHitbox, o->oAction, sBroozerAttackHandlers) == ATTACK_KICK_OR_TRIP) {
        play_sound(SOUND_GENERAL_BIG_POUND, gGlobalSoundSource);
        cur_obj_init_animation(1);
        cur_obj_become_intangible();
        enable_time_stop_including_mario();

        // Makes Mario invincible while launching the enemy (for 2 seconds)
        gMarioState->invincTimer = 30;
        
        o->oHealth--;
        o->oForwardVel = 0.0f;
        if ((o->oMoveFlags & OBJ_MOVE_LANDED) || (o->oMoveFlags & OBJ_MOVE_ON_GROUND)) {
            o->oVelY = 100.0f;
            // This defines how long Mario has in frames to cancel his kick into a jump after hitting this enemy.
            gMarioState->jumpTimer = 10;
        }
        else {
            o->oVelY = 60.0f;
            gMarioState->airComboCancel = 1;
        }

        // This defines how long the enemy is invincible for in frames before it can be attacked again.
        // This is to prevent attacks like the kick from hitting multiple times.
        o->oInvFrames = 6; 

        o->oHitstopFrames = 3;

        if (o->oHealth <= 0) {
            spawn_default_star(0, 0, 0);
            spawn_mist_particles_variable(0, 0, 200.0f);
            spawn_triangle_break_particles(20, MODEL_DIRT_ANIMATION, 3.0f, 4);
            cur_obj_shake_screen(SHAKE_POS_SMALL);
            cur_obj_play_sound_2(SOUND_OBJ_KING_WHOMP_DEATH);
        } 

        obj_die_if_health_non_positive();
    }

    if (o->oInvFrames > 0) {
        o->oInvFrames--;
    }
    else {
        cur_obj_become_tangible();
    }

    if (o->oHitstopFrames > 0) {
        o->oHitstopFrames--;
    }
    else {
        disable_time_stop_including_mario();
    }

    // Movement functions, commented out ones were used for testing and may be used later
    cur_obj_move_standard(-78);
    //obj_act_knockback(0.0f);

    //cur_obj_move_using_vel_and_gravity();
}

void bhv_broozer_loop(void) {
    if (start == 0) {
        if (cur_obj_update_dialog_with_cutscene(MARIO_DIALOG_LOOK_UP, 
            DIALOG_FLAG_TURN_TO_MARIO, CUTSCENE_DIALOG, DIALOG_114)) {
            if (gMarioState->actionArg != MARIO_DIALOG_LOOK_UP) {
                broozer();
            }
        }
    }
    else {
        broozer();
    }
}