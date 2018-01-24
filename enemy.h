// Module			: Gameplay Programming
// Assignment2		: Assassin Valkyrie
// Student Number	: Chua Wei Jie Timothy
// Student Number	: S10165581F

#ifndef _ENEMY_SHIP_H 
#define _ENEMY_SHIP_H
#define WIN32_LEAN_AND_MEAN

#include "entity.h"
#include "constants.h"
#include "HealthComponet.h"
#include "MovementComponent.h"
#include "cursor.h"
#include "enemyState.h"
#include "patrolState.h"

namespace trooperNS
{
	const int	HEALTH = 20;
	const int	WIDTH = 90;
	const int	HEIGHT = 141;
	const double ROTATION = 0;
	const float SCALE = 1.0f;
	const int	X = GAME_WIDTH / 2 - WIDTH*SCALE;
	const int	Y = GAME_HEIGHT / 2 - HEIGHT*SCALE;
	const float SPEED = 40;
	const float MASS = 300.0f;
	const int   TEXTURE_COLS = 10;
	const int   START_FRAME = 0;
	const int   END_FRAME = 9;
	const float ANIMATION_DELAY = 0.5f;
}

class Enemy : public Entity
{
protected:
	HealthComponent	*health;
	MovementComponent *move;
	EnemyState *state_;

	// player to track (temp for vision)
	Cursor *mouseCursor;

	bool	dyingOn;
	Image	dying;
	Image	damaged;

public:
	// constructor
	Enemy(Cursor *mouse);

	// inherited member functions
	virtual void handleInput(Input* input);
	void update(float frameTime);
	void ai(Entity &ship1, Entity &ship2);
	void draw();
};

#endif