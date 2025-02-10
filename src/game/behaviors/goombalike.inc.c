//Switch object properties with SET_INT in behavior_data.c
/**
 * Hitbox for goomba-like enemies.
 */
static struct ObjectHitbox sGoombalikeHitbox = {
    /* interactType:      */ INTERACT_COMBAT_ENEMY,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 5,
    /* numLootCoins:      */ 1,
    /* radius:            */ 72,
    /* height:            */ 50,
    /* hurtboxRadius:     */ 42,
    /* hurtboxHeight:     */ 40,
};

/**
 * Properties that vary based on goomba size.
 */
struct GoombalikeProperties {
    u32 deathSound;
    u32 alertSound;
    u32 walkSound;
    s8 damage;
};

/**
 * Properties for enemy types.
 */
static struct GoombalikeProperties sGoombalikeProperties[] = {
    {SOUND_OBJ_ENEMY_DEATH_HIGH, SOUND_OBJ_GOOMBA_ALERT, SOUND_OBJ_GOOMBA_WALK, 1 },
};

/**
 * Attack handlers for goombas.
 */
static u8 sGoombalikeAttackHandlers[6] = {
    /* ATTACK_PUNCH:                 */ ATTACK_HANDLER_KNOCKBACK,
    /* ATTACK_KICK_OR_TRIP:          */ ATTACK_HANDLER_KNOCKBACK,
    /* ATTACK_FROM_ABOVE:            */ ATTACK_HANDLER_NOP,
    /* ATTACK_GROUND_POUND_OR_TWIRL: */ ATTACK_HANDLER_KNOCKBACK,
    /* ATTACK_FAST_ATTACK:           */ ATTACK_HANDLER_KNOCKBACK,
    /* ATTACK_SPIN_SAW:              */ ATTACK_HANDLER_KNOCKBACK,
};

/**
 * Initialization function for goomba.
 */
void bhv_goombalike_init(void) {
    cur_obj_scale(1.5f);
    o->oInvFrames=0;
    o->oHitstopFrames=0;
    o->oDeathSound = sGoombalikeProperties[o->oGoombalikeType].deathSound;
    o->oDamageOrCoinValue = sGoombalikeProperties[o->oGoombalikeType].damage;
}

/**
 * Enter the jump action and set initial y velocity.
 */
static void goombalike_begin_jump(void) {
    cur_obj_play_sound_2(sGoombalikeProperties[o->oGoombalikeType].alertSound);

    o->oAction = GOOMBA_ACT_JUMP;
    o->oForwardVel = 0.0f;
    o->oVelY = 25;
}

/**
 * Walk around randomly occasionally jumping. If mario comes within range,
 * chase him.
 */
static void goombalike_act_walk(void) {
    treat_far_home_as_mario(1000.0f);

    obj_forward_vel_approach(o->oGoombaRelativeSpeed * 1.5, 0.4f);

    // If walking fast enough, play footstep sounds
    if (o->oGoombaRelativeSpeed > 4.0f / 3.0f) {
        cur_obj_play_sound_at_anim_range(2, 17, sGoombalikeProperties[o->oGoombalikeType].walkSound);
    }

    //! By strategically hitting a wall, steep slope, or another goomba, we can
    //  prevent the goomba from turning back toward home for a while (goomba
    //  chase extension)
    //! It seems theoretically possible to get 2-3 goombas to repeatedly touch
    //  each other and move arbitrarily far from their home, but it's
    //  extremely precise and chaotic in practice, so probably can't be performed
    //  for nontrivial distances
    if (o->oGoombaTurningAwayFromWall) {
        o->oGoombaTurningAwayFromWall = obj_resolve_collisions_and_turn(o->oGoombaTargetYaw, 0x200);
    } else {
        // If far from home, walk toward home.
        if (o->oDistanceToMario >= 25000.0f) {
            o->oGoombaTargetYaw = o->oAngleToMario;
            o->oGoombaWalkTimer = random_linear_offset(20, 30);
        }

        if (!(o->oGoombaTurningAwayFromWall =
                  obj_bounce_off_walls_edges_objects(&o->oGoombaTargetYaw))) {
            if (o->oDistanceToMario < 500.0f) {
                // If close to mario, begin chasing him. If not already chasing
                // him, jump first

                if (o->oGoombaRelativeSpeed <= 2.0f) {
                    goombalike_begin_jump();
                }

                o->oGoombaTargetYaw = o->oAngleToMario;
                o->oGoombaRelativeSpeed = 20.0f;
            } else {
                // If mario is far away, walk at a normal pace, turning randomly
                // and occasionally jumping

                o->oGoombaRelativeSpeed = 4.0f / 3.0f;

                if (o->oGoombaWalkTimer != 0) {
                    o->oGoombaWalkTimer--;
                } else {
                    if (random_u16() & 3) {
                        o->oGoombaTargetYaw = obj_random_fixed_turn(0x2000);
                        o->oGoombaWalkTimer = random_linear_offset(100, 100);
                    } else {
                        goombalike_begin_jump();
                        o->oGoombaTargetYaw = obj_random_fixed_turn(0x6000);
                    }
                }
            }
        }

        cur_obj_rotate_yaw_toward(o->oGoombaTargetYaw, 0x200);
    }
}

/**
 * This action occurs when either the goomba attacks mario normally, or mario
 * attacks a huge goomba with an attack that doesn't kill it.
 */
static void goombalike_act_attacked_mario(void) {
    goombalike_begin_jump();
    o->oGoombaTargetYaw = o->oAngleToMario;
    o->oGoombaTurningAwayFromWall = FALSE;
}

/**
 * Move until landing, and rotate toward target yaw.
 */
static void goombalike_act_jump(void) {
    obj_resolve_object_collisions(NULL);

    //! If we move outside the goomba's drawing radius the frame it enters the
    //  jump action, then it will keep its velY, but it will still be counted
    //  as being on the ground.
    //  Next frame, the jump action will think it has already ended because it is
    //  still on the ground.
    //  This puts the goomba back in the walk action, but the positive velY will
    //  make it hop into the air. We can then trigger another jump.
    if (o->oMoveFlags & OBJ_MOVE_MASK_ON_GROUND) {
        o->oAction = GOOMBA_ACT_WALK;
    } else {
        cur_obj_rotate_yaw_toward(o->oGoombaTargetYaw, 0x800);
    }
}




/**
 * Update function for goomba.
 */
void bhv_goombalike_update(void) {
    // PARTIAL_UPDATE
    f32 animSpeed;  
    if (combat_enemy_standard_actions()) {
        obj_update_blinking(&o->oGoombaBlinkTimer, 30, 50, 5);
        cur_obj_update_floor_and_walls();

        if ( (animSpeed = (o->oForwardVel / 3.75f)) < 1.0f) {
            animSpeed = 1.0f;
        }
        cur_obj_init_animation_with_accel_and_sound(GOOMBA_ANIM_DEFAULT, animSpeed);

        switch (o->oAction) {
            case GOOMBA_ACT_WALK:
                goombalike_act_walk();
                break;
            case GOOMBA_ACT_ATTACKED_MARIO:
                goombalike_act_attacked_mario();
                break;
            case GOOMBA_ACT_JUMP:
                goombalike_act_jump();
                break;
        }

    }
    if (obj_handle_attacks(&sGoombalikeHitbox, GOOMBA_ACT_ATTACKED_MARIO, sGoombalikeAttackHandlers)==ATTACK_KICK_OR_TRIP) {
        play_sound(SOUND_GENERAL_COIN_DROP, gGlobalSoundSource);
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
        o->oForwardVel = 0.0f;
        cur_obj_play_sound_2(SOUND_OBJ_POUNDING_LOUD);
    }
    
    cur_obj_move_standard(-78);
}
