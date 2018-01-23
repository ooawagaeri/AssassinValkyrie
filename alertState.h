// Module			: Gameplay Programming
// Assignment2		: Assassin Valkyrie
// Student Number	: Chua Wei Jie Timothy
// Student Number	: S10165581F

#ifndef _ENEMY_ALERT_STATE_H 
#define _ENEMY_ALERT_STATE_H
#define WIN32_LEAN_AND_MEAN

#include "enemyState.h"

class AlertedState : public EnemyState
{
private:
	int maxTimeAlert = 10000;
	int alertedTime;
	Entity lastSeen;
public:
	AlertedState() { alertedTime = GetTickCount(); }
	virtual EnemyState* handleInput(Entity& enemy, Input* input);
	virtual void update(Entity *enemy, Entity *target);
};//end of AlertedState class
#endif