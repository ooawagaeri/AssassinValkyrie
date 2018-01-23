// Module			: Gameplay Programming
// Assignment2		: Assassin Valkyrie
// Student Number	: Chua Wei Jie Timothy
// Student Number	: S10165581F

#include "enemy.h"
#include "alertState.h"
#include "standState.h"
#include "patrolState.h"

EnemyState* PatrollingState::handleInput(Entity& enemy, Input* input)
{
	if (input->isKeyDown('R'))
	{
		return new AlertedState();
	}
}

void PatrollingState::update(Entity *enemy, Entity *target)
{
	if (GetTickCount() - walkingTime > maxTimeWalk)
	{
		enemy->setVelocity(-enemy->getVelocity());
		walkingTime = GetTickCount();
	}
}

EnemyState* AlertedState::handleInput(Entity& enemy, Input* input)
{
	//if (GetTickCount() - alertedTime > maxTimeAlert)
	if (input->isKeyDown('T'))
	{
		return new StandingState();
	}
}

void AlertedState::update(Entity *enemy, Entity *target)
{
	VECTOR2 difference = VECTOR2(target->getX() - enemy->getX(), target->getY() - enemy->getY());
	float angle = atan(difference.y / difference.x);

	VECTOR2 direction = *D3DXVec2Normalize(&difference, &difference);
	enemy->setVelocity(VECTOR2(direction.x * 40, 0));
}

EnemyState* StandingState::handleInput(Entity& enemy, Input* input)
{
	//if (GetTickCount() - standTime > maxTimeStand)
	if (input->isKeyDown('Y'))
	{
		return new PatrollingState();
	}
}
void StandingState::update(Entity *enemy, Entity *target)
{
	enemy->setVelocity(VECTOR2(0, 0));
}