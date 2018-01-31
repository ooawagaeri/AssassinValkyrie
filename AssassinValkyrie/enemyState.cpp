// Module			: Gameplay Programming
// Assignment2		: Assassin Valkyrie
// Student Number	: Chua Wei Jie Timothy
// Student Number	: S10165581F

#include "enemy.h"
#include "Player.h"
#include "stone.h"
#include "enemyState.h"
#include "alertState.h"
#include "standState.h"
#include "patrolState.h"
#include "returnState.h"
#include "distractedState.h"

void EnemyState::update(Enemy *enemy, Entity *target)
{
	enemy->getRay()->setColor(graphicsNS::WHITE);
	enemy->getMove()->setVelocity(enemy->getMove()->getCurrentVelocity());
}

PatrollingState::PatrollingState() : EnemyState()
{
	maxTime = 8000;
}

EnemyState* PatrollingState::handleInput(Enemy *enemy, Entity *target, PLATFORM p)
{
	if (enemy->getRay()->inSight(*target->getCenter(), p))
		return new AlertedState();
	return NULL;
}

void PatrollingState::update(Enemy *enemy, Entity *target)
{
	enemy->getRay()->setColor(graphicsNS::WHITE);
	if (GetTickCount() - timer > maxTime)
	{
		enemy->getMove()->setVelocity(-enemy->getMove()->getCurrentVelocity());
		timer = GetTickCount();
	}
}

AlertedState::AlertedState() : EnemyState()
{
	maxTime = 5000;
}

EnemyState* AlertedState::handleInput(Enemy *enemy, Entity *target, PLATFORM p)
{
	if (GetTickCount() - timer > maxTime)
		if (!(enemy->getRay()->inSight(*target->getCenter(), p)))
			return new StandingState();
		else
			timer = GetTickCount();
	return NULL;
}

bool sameSign(int x, int y)
{
	return (x >= 0) ^ (y < 0);
}

void AlertedState::update(Enemy *enemy, Entity *target)
{
	enemy->getRay()->setColor(graphicsNS::YELLOW);
	VECTOR2 direction = VECTOR2(target->getX() - enemy->getX(), target->getY() - enemy->getY());
	direction = *D3DXVec2Normalize(&direction, &direction);
	enemy->getMove()->setVelocity(direction.x * enemy->getMove()->getInitialVelocity());
	VECTOR2 pos1 = *enemy->getCenter() - *target->getCenter();

	if (D3DXVec2Length(&pos1) < enemy->getRange() && !enemy->getAttack()->getAnimation())
	{
		enemy->getAttack()->setAnimation(true);
		enemy->getAnimation()->setCurrentFrame(enemy->getAttackFrame());
	}
}

StandingState::StandingState() : EnemyState()
{
	maxTime = 3000;
}

EnemyState* StandingState::handleInput(Enemy *enemy, Entity *target, PLATFORM p)
{
	enemy->getMove()->setVelocity(0);
	if (GetTickCount() - timer > maxTime)
	{
		enemy->getMove()->setVelocity(enemy->getMove()->getInitialVelocity());
		return new ReturningState();
	}
	return NULL;
}

ReturningState::ReturningState()
{
}

EnemyState* ReturningState::handleInput(Enemy *enemy, Entity *target, PLATFORM p)
{
	if (enemy->getMove()->returnOrigin())
	{
		enemy->getMove()->setVelocity(enemy->getMove()->getInitialVelocity());
		return new PatrollingState();
	}
	if (enemy->getRay()->inSight(*target->getCenter(), p))
	{
		enemy->getRay()->setColor(graphicsNS::YELLOW);
		return new AlertedState();
	}
	for (Entity *e : p)
		if (enemy->collidesWith(*e, VECTOR2{}))
		{
			enemy->getMove()->setVelocity(-enemy->getMove()->getCurrentVelocity());
			enemy->setOriginalPos({ enemy->getX(), enemy->getY() });
			return new PatrollingState();
		}
	return NULL;
}

DistractedState::DistractedState(VECTOR2 pos) : EnemyState()
{
	distractionPos = pos;
	maxTime = 8000;
}

EnemyState* DistractedState::handleInput(Enemy *enemy, Entity *target, PLATFORM p)
{
	if (enemy->getRay()->inSight(*target->getCenter(), p))
		return new AlertedState();
	if (GetTickCount() - timer > maxTime)
		return new ReturningState();
	return NULL;
}

void DistractedState::update(Enemy *enemy, Entity *target)
{
	enemy->getRay()->setColor(graphicsNS::TEAL);
	if (enemy->getCenterX() < distractionPos.x - 5)
		enemy->getMove()->setVelocity(enemy->getMove()->getInitialVelocity());
	else if (enemy->getCenterX() > distractionPos.x + 5)
		enemy->getMove()->setVelocity(-enemy->getMove()->getInitialVelocity());
	else
		enemy->getMove()->setVelocity(0);
}