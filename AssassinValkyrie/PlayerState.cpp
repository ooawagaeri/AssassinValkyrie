


#include "RunningState.h"
#include "StandingState.h"
#include "CrouchingState.h"
#include "MeleeAttackState.h"
#include "CrouchWalkingState.h"
#include "JumpingState.h"
#include "RangeAttackState.h"

PlayerState* StandState::handleInput(Entity& player, Input* input, Game *gamePtr, TextureManager *textureM)
{
	if (input->isKeyDown(RUNNING_RIGHT_KEY))
	{
		player.initialize(gamePtr, RUNNING_STATE::WIDTH, RUNNING_STATE::HEIGHT, RUNNING_STATE::TEXTURE_COLS, textureM);
		player.setFrames(RUNNING_STATE::START_FRAME, RUNNING_STATE::END_FRAME);
		player.setCurrentFrame(RUNNING_STATE::START_FRAME);
		player.setFrameDelay(0.2);
		player.flipHorizontal(false);
		player.setVelocity(VECTOR2(RUNNING_STATE::RUNNING_SPEED, RUNNING_STATE::RUNNING_SPEED));
		return new RunningState();
	}

	else if (input->isKeyDown(RUNNING_LEFT_KEY))
	{
		player.initialize(gamePtr, RUNNING_STATE::WIDTH, RUNNING_STATE::HEIGHT, RUNNING_STATE::TEXTURE_COLS, textureM);
		player.flipHorizontal(true);
		player.setFrames(RUNNING_STATE::START_FRAME, RUNNING_STATE::END_FRAME);
		player.setCurrentFrame(RUNNING_STATE::START_FRAME);
		player.setFrameDelay(0.2);
	
		player.setVelocity(VECTOR2(-RUNNING_STATE::RUNNING_SPEED, -RUNNING_STATE::RUNNING_SPEED));
		return new RunningState();
	}

	else if (input->isKeyDown(CROUCHING_KEY))
	{
		player.initialize(gamePtr, CROUCHING_STATE::WIDTH, CROUCHING_STATE::HEIGHT, CROUCHING_STATE::TEXTURE_COLS, textureM);
		player.setFrames(CROUCHING_STATE::START_FRAME, CROUCHING_STATE::END_FRAME);
		player.setCurrentFrame(CROUCHING_STATE::START_FRAME);
		return new CrouchingState();
		
	}

	else if (input->isKeyDown(MELEE_ATTACK_KEY))
	{
		player.initialize(gamePtr, MELEE_ATTACK_STATE::WIDTH, MELEE_ATTACK_STATE::HEIGHT, MELEE_ATTACK_STATE::TEXTURE_COLS, textureM);
		player.setFrames(MELEE_ATTACK_STATE::START_FRAME, MELEE_ATTACK_STATE::END_FRAME);
		player.setCurrentFrame(MELEE_ATTACK_STATE::START_FRAME);
		player.setFrameDelay(0.1);
		player.setLoop(false);
		return new MeleeAttackState();

	}

	else if (input->isKeyDown(RANGE_ATTACK_KEY))
	{
		player.initialize(gamePtr, RANGE_ATTACK_STATE::WIDTH, RANGE_ATTACK_STATE::HEIGHT, RANGE_ATTACK_STATE::TEXTURE_COLS, textureM);
		player.setFrames(RANGE_ATTACK_STATE::START_FRAME, RANGE_ATTACK_STATE::END_FRAME);
		player.setCurrentFrame(RANGE_ATTACK_STATE::START_FRAME);
		player.setFrameDelay(0.1);
		player.setLoop(false);
		return new RangeAttackState();

	}

	
	return NULL;
}

PlayerState* RunningState::handleInput(Entity& player, Input* input, Game *gamePtr, TextureManager *textureM)
{
	if (!input->isKeyDown(RUNNING_RIGHT_KEY)&& !input->isKeyDown(RUNNING_LEFT_KEY))
	{
		player.initialize(gamePtr, STANDING_STATE::WIDTH, STANDING_STATE::HEIGHT, STANDING_STATE::TEXTURE_COLS, textureM);
		player.setFrames(0, 0);
		player.setCurrentFrame(0);
		return new StandState();
	}

	else if (input->isKeyDown(JUMPING_KEY) && input->isKeyDown(RUNNING_RIGHT_KEY))
	{
		player.initialize(gamePtr, JUMPING_STATE::WIDTH, JUMPING_STATE::HEIGHT, JUMPING_STATE::TEXTURE_COLS, textureM);
		player.setFrames(JUMPING_STATE::START_FRAME, JUMPING_STATE::END_FRAME);
		player.setCurrentFrame(JUMPING_STATE::START_FRAME);
		player.setFrameDelay(0.2);
		player.flipHorizontal(false);
		player.setLoop(false);
		player.setJumpRight(true);
	
		return new JumpingState();
	}

	else if (input->isKeyDown(JUMPING_KEY) && input->isKeyDown(RUNNING_LEFT_KEY))
	{
		player.initialize(gamePtr, JUMPING_STATE::WIDTH, JUMPING_STATE::HEIGHT, JUMPING_STATE::TEXTURE_COLS, textureM);
		player.setFrames(JUMPING_STATE::START_FRAME, JUMPING_STATE::END_FRAME);
		player.setCurrentFrame(JUMPING_STATE::START_FRAME);
		player.setFrameDelay(0.2);
		player.flipHorizontal(true);
		player.setLoop(false);
		player.setJumpLeft(true);
		return new JumpingState();
	}
	return NULL;
}

PlayerState* CrouchingState::handleInput(Entity& player, Input* input, Game *gamePtr, TextureManager *textureM)
{
	if (!input->isKeyDown(CROUCHING_KEY))
	{
		player.initialize(gamePtr, STANDING_STATE::WIDTH, STANDING_STATE::HEIGHT, STANDING_STATE::TEXTURE_COLS, textureM);
		player.setFrames(STANDING_STATE::START_FRAME, STANDING_STATE::END_FRAME);
		player.setCurrentFrame(STANDING_STATE::START_FRAME);
		return new StandState();
	}

	else if (input->isKeyDown(RUNNING_RIGHT_KEY))
	{
		player.initialize(gamePtr, CROUCH_WALKING_STATE::WIDTH, CROUCH_WALKING_STATE::HEIGHT, CROUCH_WALKING_STATE::TEXTURE_COLS, textureM);
		player.setFrames(CROUCH_WALKING_STATE::START_FRAME, CROUCH_WALKING_STATE::END_FRAME);
		player.setCurrentFrame(CROUCH_WALKING_STATE::START_FRAME);
		player.setFrameDelay(0.2);
		player.flipHorizontal(false);
		player.setVelocity(VECTOR2(CROUCH_WALKING_STATE::CROUCH_WALKING_SPEED, CROUCH_WALKING_STATE::CROUCH_WALKING_SPEED));
		return new CrouchWalkingState();
	}

	else if (input->isKeyDown(RUNNING_LEFT_KEY))
	{
		player.initialize(gamePtr, CROUCH_WALKING_STATE::WIDTH, CROUCH_WALKING_STATE::HEIGHT, CROUCH_WALKING_STATE::TEXTURE_COLS, textureM);
		player.setFrames(CROUCH_WALKING_STATE::START_FRAME, CROUCH_WALKING_STATE::END_FRAME);
		player.setCurrentFrame(CROUCH_WALKING_STATE::START_FRAME);
		player.setFrameDelay(0.2);
		player.flipHorizontal(true);
		player.setVelocity(VECTOR2(-CROUCH_WALKING_STATE::CROUCH_WALKING_SPEED, -CROUCH_WALKING_STATE::CROUCH_WALKING_SPEED));
		return new CrouchWalkingState();
	}


	return NULL;
}

PlayerState* MeleeAttackState::handleInput(Entity& player, Input* input, Game *gamePtr, TextureManager *textureM)
{
	if (player.getAnimationComplete())
	{
		
			player.initialize(gamePtr, STANDING_STATE::WIDTH, STANDING_STATE::HEIGHT, STANDING_STATE::TEXTURE_COLS, textureM);
			player.setFrames(STANDING_STATE::START_FRAME, STANDING_STATE::END_FRAME);
			player.setCurrentFrame(STANDING_STATE::START_FRAME);
			player.setLoop(true);
			return new StandState();
		
	}
	return NULL;
}

PlayerState* RangeAttackState::handleInput(Entity& player, Input* input, Game *gamePtr, TextureManager *textureM)
{
	if (player.getAnimationComplete())
	{

		player.initialize(gamePtr, STANDING_STATE::WIDTH, STANDING_STATE::HEIGHT, STANDING_STATE::TEXTURE_COLS, textureM);
		player.setFrames(STANDING_STATE::START_FRAME, STANDING_STATE::END_FRAME);
		player.setCurrentFrame(STANDING_STATE::START_FRAME);
		player.setLoop(true);
		return new StandState();

	}
	return NULL;
}

PlayerState* CrouchWalkingState::handleInput(Entity& player, Input* input, Game *gamePtr, TextureManager *textureM)
{
	if (!input->isKeyDown(RUNNING_RIGHT_KEY) && !input->isKeyDown(RUNNING_LEFT_KEY) || !input->isKeyDown(CROUCHING_KEY))
	{

		player.initialize(gamePtr, STANDING_STATE::WIDTH, STANDING_STATE::HEIGHT, STANDING_STATE::TEXTURE_COLS, textureM);
		player.setFrames(STANDING_STATE::START_FRAME, STANDING_STATE::END_FRAME);
		player.setCurrentFrame(STANDING_STATE::START_FRAME);
		return new StandState();

	}
	return NULL;
}

PlayerState* JumpingState::handleInput(Entity& player, Input* input, Game *gamePtr, TextureManager *textureM)
{
	
	
	if (player.getJumpComplete())
	{
		player.initialize(gamePtr, STANDING_STATE::WIDTH, STANDING_STATE::HEIGHT, STANDING_STATE::TEXTURE_COLS, textureM);
		player.setFrames(STANDING_STATE::START_FRAME, STANDING_STATE::END_FRAME);
		player.setCurrentFrame(STANDING_STATE::START_FRAME);
		player.setLoop(true);
		player.setJumpComplete(false);
		return new StandState();
	}

	return NULL;
}