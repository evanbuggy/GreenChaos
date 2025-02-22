static struct ObjectHitbox sElectroLuigiHitbox = {
    /* interactType:      */ INTERACT_COMBAT_ENEMY,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 5,
    /* numLootCoins:      */ 1,
    /* radius:            */ 300,
    /* height:            */ 500,
    /* hurtboxRadius:     */ 200,
    /* hurtboxHeight:     */ 300,   
};

static u8 sElectroLuigiAttackHandlers[6] = {
    /* ATTACK_PUNCH:                 */ ATTACK_HANDLER_KNOCKBACK,
    /* ATTACK_KICK_OR_TRIP:          */ ATTACK_HANDLER_KNOCKBACK,
    /* ATTACK_FROM_ABOVE:            */ ATTACK_HANDLER_SQUISHED,
    /* ATTACK_GROUND_POUND_OR_TWIRL: */ ATTACK_HANDLER_KNOCKBACK,
    /* ATTACK_FAST_ATTACK:           */ ATTACK_HANDLER_KNOCKBACK,
    /* ATTACK_SPIN_SAW:              */ ATTACK_HANDLER_KNOCKBACK,
};

// These structs were all stolen from Goomba
void bhv_electro_luigi_init(void) {
    o->oInvFrames=0;
    o->oHitstopFrames=0;
}
void bhv_electro_luigi_loop(void) {

    if (o->oAction & OBJ_ACT_SPIN_SAWED) {
        obj_act_spin_sawed();
    }

    switch (o->oTimer % 200) {
        case 30:
            cur_obj_play_sound_2(SOUND_GENERAL_WING_FLAP);
            cur_obj_init_animation(1);
            break;
        
        case 50:
            cur_obj_play_sound_2(SOUND_OBJ_THWOMP);
            spawn_object(o, MODEL_BOWSER_WAVE, bhvBowserShockWave);
            break;

        case 70:
            cur_obj_init_animation(0);
            break;

        default:
            break;
    }
    

    cur_obj_update_floor_and_walls();
    if (obj_handle_attacks(&sElectroLuigiHitbox, o->oAction, sElectroLuigiAttackHandlers) == ATTACK_KICK_OR_TRIP) {
        play_sound(SOUND_GENERAL_BIG_POUND, gGlobalSoundSource);
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
        o->oInvFrames = 60; 

        o->oHitstopFrames = 3;

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

    if (o->oMoveFlags & OBJ_MOVE_BOUNCE) {
        if (o->oMoveFlags & OBJ_MOVE_ABOVE_DEATH_BARRIER) {
            obj_mark_for_deletion(o);
        }
        cur_obj_init_animation(0);
        o->oForwardVel = 0.0f;
        cur_obj_play_sound_2(SOUND_OBJ_POUNDING_LOUD);
    }

    // Movement functions, commented out ones were used for testing and may be used later
    cur_obj_move_standard(-78);
    //obj_act_knockback(0.0f);

    //cur_obj_move_using_vel_and_gravity();
}