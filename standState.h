// Module			: Gameplay Programming
// Assignment2		: Assassin Valkyrie
// Student Number	: Chua Wei Jie Timothy
// Student Number	: S10165581F

#ifndef _ENEMY_STAND_STATE_H 
#define _ENEMY_STAND_STATE_H
#define WIN32_LEAN_AND_MEAN

#include "enemyState.h"

class StandingState : public EnemyState
{
private:
	int maxTimeStand = 4000;
	int standTime;

public:
	StandingState() { standTime = GetTickCount(); }
	virtual EnemyState* handleInput(Entity& enemy, Input* input);
	virtual void update(Entity *enemy, Entity *target);
};//end of StandingState class
#endif