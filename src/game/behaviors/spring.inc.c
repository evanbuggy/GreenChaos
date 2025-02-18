static struct ObjectHitbox sSpringHitbox = {
    /* interactType:      */ INTERACT_BOUNCE_TOP,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 5,
    /* numLootCoins:      */ 1,
    /* radius:            */ 100,
    /* height:            */ 100,
    /* hurtboxRadius:     */ 1,
    /* hurtboxHeight:     */ 1,   
};

static u8 sSpringAttackHandlers[6] = {
    /* ATTACK_PUNCH:                 */ ATTACK_HANDLER_KNOCKBACK,
    /* ATTACK_KICK_OR_TRIP:          */ ATTACK_HANDLER_KNOCKBACK,
    /* ATTACK_FROM_ABOVE:            */ ATTACK_HANDLER_NOP,
    /* ATTACK_GROUND_POUND_OR_TWIRL: */ ATTACK_HANDLER_KNOCKBACK,
    /* ATTACK_FAST_ATTACK:           */ ATTACK_HANDLER_KNOCKBACK,
    /* ATTACK_SPIN_SAW:              */ ATTACK_HANDLER_KNOCKBACK,
};

void bhv_spring_loop(void) {
    if (obj_handle_attacks(&sSpringHitbox, o->oAction, sSpringAttackHandlers)) {
        play_sound(SOUND_OBJ_WIGGLER_JUMP, gGlobalSoundSource);
        gMarioState->action = ACT_LONG_JUMP;
        gMarioState->faceAngle[1] = o->oFaceAngleYaw;
        gMarioState->vel[1] = (o->oBehParams >> 24) * 10; // 1st param: Upward vel in 10s
        gMarioState->forwardVel = (o->oBehParams2ndByte) * 10; // 2nd param: Forward vel in 10s
    }
}