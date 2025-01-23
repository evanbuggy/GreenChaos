static struct ObjectHitbox sCombatEnmemyHitbox = {
    /* interactType:      */ INTERACT_BOUNCE_TOP,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 5,
    /* numLootCoins:      */ 1,
    /* radius:            */ 150,
    /* height:            */ 500,
    /* hurtboxRadius:     */ 25,
    /* hurtboxHeight:     */ 25,   
};

static u8 sCombatEnemyAttackHandlers[6] = {
    /* ATTACK_PUNCH:                 */ ATTACK_HANDLER_KNOCKBACK,
    /* ATTACK_KICK_OR_TRIP:          */ ATTACK_HANDLER_KNOCKBACK,
    /* ATTACK_FROM_ABOVE:            */ ATTACK_HANDLER_SQUISHED,
    /* ATTACK_GROUND_POUND_OR_TWIRL: */ ATTACK_HANDLER_KNOCKBACK,
    /* ATTACK_FAST_ATTACK:           */ ATTACK_HANDLER_KNOCKBACK,
    /* ATTACK_FROM_BELOW:            */ ATTACK_HANDLER_KNOCKBACK,
};

// These structs were all stolen from Goomba

u8 invFrames = 0;
u8 hitstopFrames = 0;
u8 launched = 0;

void bhv_combat_enemy_loop(void) {
    if (obj_handle_attacks(&sCombatEnmemyHitbox, o->oAction, sCombatEnemyAttackHandlers) == ATTACK_KICK_OR_TRIP) {
        play_sound(SOUND_GENERAL_COIN_DROP, gGlobalSoundSource);
        cur_obj_become_intangible();
        enable_time_stop_including_mario();

        // Makes Mario invincible while launching the enemy (for 2 seconds)
        gMarioState->invincTimer = 30;
        gMarioState->combo++;
        gMarioState->comboTimer = 60;
        
        o->oHealth--;
        o->oForwardVel = 0.0f;
        if (launched == 0) {
            o->oVelY = 70.0f;
            launched = 1;
            // This defines how long Mario has in frames to cancel his kick into a jump after hitting this enemy.
            gMarioState->jumpTimer = 10;
        }
        else {
            o->oVelY = 40.0f;
            gMarioState->airComboCancel = 1;
        }

        // This defines how long the enemy is invincible for in frames before it can be attacked again.
        // This is to prevent attacks like the kick from hitting multiple times.
        invFrames = 6;

        hitstopFrames = 2;

        obj_die_if_health_non_positive();
    }

    if (invFrames > 0) {
        invFrames--;
    }
    else {
        cur_obj_become_tangible();
    }

    if (hitstopFrames > 0) {
        hitstopFrames--;
    }
    else {
        disable_time_stop_including_mario();
    }

    if (o->oMoveFlags & OBJ_MOVE_LANDED) {
        play_sound(SOUND_OBJ_POUNDING_LOUD, gGlobalSoundSource);
        launched = 0;
    }

    // Movement functions, commented out ones were used for testing and may be used later
    cur_obj_move_standard(-78);
    //obj_act_knockback(0.0f);
    //cur_obj_update_floor_and_walls();
    //cur_obj_move_using_vel_and_gravity();
}