static struct ObjectHitbox sBugLuigiHitbox = {
    /* interactType:      */ INTERACT_COMBAT_ENEMY,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 1,
    /* numLootCoins:      */ 1,
    /* radius:            */ 100,
    /* height:            */ 200,
    /* hurtboxRadius:     */ 50,
    /* hurtboxHeight:     */ 50,   
};

static u8 sBugLuigiAttackHandlers[6] = {
    /* ATTACK_PUNCH:                 */ ATTACK_HANDLER_SQUISHED,
    /* ATTACK_KICK_OR_TRIP:          */ ATTACK_HANDLER_SQUISHED,
    /* ATTACK_FROM_ABOVE:            */ ATTACK_HANDLER_SQUISHED,
    /* ATTACK_GROUND_POUND_OR_TWIRL: */ ATTACK_HANDLER_SQUISHED,
    /* ATTACK_FAST_ATTACK:           */ ATTACK_HANDLER_SQUISHED,
    /* ATTACK_SPIN_SAW:              */ ATTACK_HANDLER_KNOCKBACK,
};

void bhv_bug_luigi_loop(void) {

    if (o->oAction & OBJ_ACT_SPIN_SAWED) {
        obj_act_spin_sawed();
    } 

    cur_obj_update_floor_and_walls();
    if (obj_handle_attacks(&sBugLuigiHitbox, o->oAction, sBugLuigiAttackHandlers) == ATTACK_KICK_OR_TRIP) {
        play_sound(SOUND_ACTION_METAL_STEP, gGlobalSoundSource);
        cur_obj_become_intangible();
        enable_time_stop_including_mario();

        // Makes Mario invincible while launching the enemy (for 1 second)
        gMarioState->invincTimer = 30;

        // Allows Mario to cancel his kick into a jump
        gMarioState->jumpTimer = 10;
        
        o->oHealth--;

        obj_die_if_health_non_positive();
    }

    // Movement functions
    cur_obj_move_standard(-78);
}