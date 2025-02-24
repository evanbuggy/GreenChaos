static struct ObjectHitbox sBossLuigiHitbox = {
    /* interactType:      */ INTERACT_COMBAT_ENEMY,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 50,
    /* numLootCoins:      */ 1,
    /* radius:            */ 150,
    /* height:            */ 250,
    /* hurtboxRadius:     */ 100,
    /* hurtboxHeight:     */ 200,   
};

static u8 sBossLuigiHandlers[6] = {
    /* ATTACK_PUNCH:                 */ ATTACK_HANDLER_KNOCKBACK,
    /* ATTACK_KICK_OR_TRIP:          */ ATTACK_HANDLER_KNOCKBACK,
    /* ATTACK_FROM_ABOVE:            */ ATTACK_HANDLER_SQUISHED,
    /* ATTACK_GROUND_POUND_OR_TWIRL: */ ATTACK_HANDLER_KNOCKBACK,
    /* ATTACK_FAST_ATTACK:           */ ATTACK_HANDLER_KNOCKBACK,
    /* ATTACK_SPIN_SAW:              */ ATTACK_HANDLER_KNOCKBACK,
};

void bhv_boss_luigi_init(void) {
    o->oInvFrames = 0;
    o->oHitstopFrames = 0;
    o->oTimer = 550;
}

u8 begin = 0;

void boss_luigi(void)  {
    begin = 1;
    //osSyncPrintf("%d", o->oTimer);
    osSyncPrintf("%d", o->oInvFrames);

    if (o->oMoveFlags & OBJ_MOVE_LANDED) {
        if (o->oMoveFlags & OBJ_MOVE_ABOVE_DEATH_BARRIER) {
            o->oPosX = gMarioState->pos[0];
            o->oPosY = gMarioState->pos[1] + 1000;
            o->oPosZ = gMarioState->pos[2];
            play_sound(SOUND_ACTION_TELEPORT, gGlobalSoundSource);
        }
        else {
            // Luigi lands and becomes tangible
            o->oForwardVel = 0.0f;
            cur_obj_play_sound_2(SOUND_MARIO_OOOF2);
            cur_obj_init_animation(6);
        }
    }

    if (o->oMoveFlags & OBJ_MOVE_ON_GROUND) {
        if (o->oTimer >= 570) {
            o->oTimer = 0;
            // Luigi will be invincible until he lands from flying
            o->oInvFrames = 430;
            cur_obj_become_intangible();
        }

        // Jump up and start flying in a circle while intangible
        switch (o->oTimer) {
            case 15:
                // start flying anim
                cur_obj_init_animation(4);
                o->oVelY = 80.0f;
                break;

            default:
                break;
        }
    }
    else {
        if (o->oMoveFlags & OBJ_MOVE_IN_AIR) {
            o->oMoveAngleYaw += 0x100;
            obj_forward_vel_approach(100, 0.4f);
            if (o->oTimer > 420) {
                // Once Luigi has flown after Mario for long enough, make him
                // fall back down
                o->oForwardVel = 0.0f;
                cur_obj_init_animation(5);
            }
            else {
                if (o->oTimer > 22) {
                    cur_obj_init_animation(3);
                    o->oVelY = 8.0f;
                    if (o->oTimer > 300) {
                        cur_obj_rotate_yaw_toward(o->oAngleToMario, 0x400);
                    }
                }
            }
         }
    }

    if (obj_handle_attacks(&sBossLuigiHitbox, o->oAction, sBossLuigiHandlers) == ATTACK_KICK_OR_TRIP) {
        play_sound(SOUND_ACTION_HIT_2, gGlobalSoundSource);
        cur_obj_init_animation(2);
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
            //spawn_default_star(0, 1000, 0);
            spawn_mist_particles_variable(0, 0, 200.0f);
            spawn_triangle_break_particles(20, MODEL_DIRT_ANIMATION, 3.0f, 4);
            cur_obj_shake_screen(SHAKE_POS_SMALL);
            cur_obj_play_sound_2(SOUND_MARIO_WAAAOOOW);
        } 

        obj_die_if_health_non_positive();
    }

    if (o->oInvFrames > 0) {
        osSyncPrintf("Decreasing Inv Frames Reached!");
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

    // Movement functions
    cur_obj_move_standard(-78);
    cur_obj_update_floor_and_walls();
}

void bhv_boss_luigi_loop(void) {
    if (begin == 0) {
        if (cur_obj_update_dialog_with_cutscene(MARIO_DIALOG_LOOK_UP, 
            DIALOG_FLAG_TURN_TO_MARIO, CUTSCENE_DIALOG, DIALOG_112)) {
            if (gMarioState->actionArg != MARIO_DIALOG_LOOK_UP) {
                boss_luigi();
            }
        }
    }
    else {
        boss_luigi();
    }
}