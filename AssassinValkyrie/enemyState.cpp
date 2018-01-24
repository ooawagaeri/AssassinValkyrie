// Module			: Gameplay Programming
// Assignment2		: Assassin Valkyrie
// Student Number	: Chua Wei Jie Timothy
// Student Number	: S10165581F

#include "enemy.h"
#include "alertState.h"
#include "standState.h"
#include "patrolState.h"

PatrollingState::PatrollingState()
{
	walkingTime = GetTickCount();
	maxTimeWalk = 8000;
}

EnemyState* PatrollingState::handleInput(Entity& enemy, Input* input)
{
	if (input->isKeyDown('R'))
	{
		return new AlertedState();
	}
	return NULL;
}

void PatrollingState::update(Entity *enemy, Entity *target)
{
	if (GetTickCount() - walkingTime > maxTimeWalk)
	{
		if (enemy->getVelocity().x == 0)
			enemy->setVelocity(VECTOR2(trooperNS::SPEED, 0));
		else
			enemy->setVelocity(-enemy->getVelocity());
		walkingTime = GetTickCount();
	}
}

AlertedState::AlertedState()
{
	alertedTime = GetTickCount();
	maxTimeAlert = 5000;
}

EnemyState* AlertedState::handleInput(Entity& enemy, Input* input)
{
	if (GetTickCount() - alertedTime > maxTimeAlert)
	{
		return new StandingState();
	}
	return NULL;
}

void AlertedState::update(Entity *enemy, Entity *target)
{
	VECTOR2 direction = VECTOR2(target->getX() - enemy->getX(), target->getY() - enemy->getY());
	direction = *D3DXVec2Normalize(&direction, &direction);
	enemy->setVelocity(VECTOR2(direction.x * trooperNS::SPEED, 0));
}

StandingState::StandingState()
{
	standTime = GetTickCount();
	maxTimeStand = 3000;
}

EnemyState* StandingState::handleInput(Entity& enemy, Input* input)
{
	if (GetTickCount() - standTime > maxTimeStand)
	{
		return new PatrollingState();
	}
	return NULL;
}
void StandingState::update(Entity *enemy, Entity *target)
{
	enemy->setVelocity(VECTOR2(0, 0));
}