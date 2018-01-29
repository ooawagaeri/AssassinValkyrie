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

EnemyState* PatrollingState::handleInput(Enemy *enemy, Entity *target, PLATFORM p)
{
	if (enemy->getRay()->inSight(*target->getCenter(),p))
	{
		enemy->getRay()->setColor(graphicsNS::YELLOW);
		return new AlertedState();
	}
	return NULL;
}

void PatrollingState::update(Enemy *enemy, Entity *target)
{
	if (GetTickCount() - walkingTime > maxTimeWalk)
	{
		enemy->getMove()->setVelocity(-enemy->getMove()->getCurrentVelocity());
		walkingTime = GetTickCount();
	}
}

AlertedState::AlertedState()
{
	alertedTime = GetTickCount();
	maxTimeAlert = 5000;
}

EnemyState* AlertedState::handleInput(Enemy *enemy, Entity *target, PLATFORM p)
{
	if (GetTickCount() - alertedTime > maxTimeAlert)
	{
		return new StandingState();
	}
	return NULL;
}

void AlertedState::update(Enemy *enemy, Entity *target)
{
	VECTOR2 direction = VECTOR2(target->getX() - enemy->getX(), target->getY() - enemy->getY());
	direction = *D3DXVec2Normalize(&direction, &direction);
	enemy->getMove()->setVelocity(direction.x * enemy->getMove()->getInitialVelocity());
}

StandingState::StandingState()
{
	standTime = GetTickCount();
	maxTimeStand = 3000;
}

EnemyState* StandingState::handleInput(Enemy *enemy, Entity *target, PLATFORM p)
{
	enemy->getMove()->setVelocity(0);
	if (GetTickCount() - standTime > maxTimeStand)
	{
		enemy->getRay()->setColor(graphicsNS::WHITE);
		enemy->getMove()->setVelocity(enemy->getMove()->getInitialVelocity());
		if (enemy->getMove()->returnOrigin())
		{
			enemy->getMove()->setVelocity(enemy->getMove()->getInitialVelocity());
			return new PatrollingState();
		}
	}
	return NULL;
}
void StandingState::update(Enemy *enemy, Entity *target)
{
	enemy->getMove()->setVelocity(enemy->getMove()->getCurrentVelocity());
}