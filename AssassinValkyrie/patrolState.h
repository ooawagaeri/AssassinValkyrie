// Module			: Gameplay Programming
// Assignment2		: Assassin Valkyrie
// Student Number	: Chua Wei trooper Timothy
// Student Number	: S10165581F

#ifndef _ENEMY_PARTROL_STATE_H 
#define _ENEMY_PARTROL_STATE_H
#define WIN32_LEAN_AND_MEAN

#include "enemyState.h"

class PatrollingState : public EnemyState
{
private:
	int maxTimeWalk;
	int walkingTime;

public:
	PatrollingState();
	virtual EnemyState* handleInput(Enemy *enemy, Entity *target, PLATFORM p);
	virtual void update(Enemy *enemy, Entity *target);
};//end of PatrollingState class
#endif