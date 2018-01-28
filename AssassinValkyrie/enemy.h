// Module			: Gameplay Programming
// Assignment2		: Assassin Valkyrie
// Student Number	: Chua Wei Jie Timothy
// Student Number	: S10165581F

#ifndef _ENEMY_H 
#define _ENEMY_H
#define WIN32_LEAN_AND_MEAN

#include "entity.h"
#include "constants.h"
#include "HealthComponet.h"
#include "MovementComponent.h"
#include "AttackComponent.h"
#include "rayCasting.h"
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

	const int MELEE_RANGE = 100;

	const int MELEE_WIDTH = 128;
	const int MELEE_HEIGHT = 141;
	const int MELEE_TEXTURE_COLS = 5;
	const int MELEE_START_FRAME = 5;
	const int MELEE_END_FRAME = 9;
}

class Enemy : public Entity
{
protected:
	HealthComponent		*health;
	MovementComponent	*move;
	AttackComponent		*attack;
	EnemyState			*state_;

	// player to track
	Cursor	*mouseCursor;
	Ray		*vision;

	Image	attackAnimation;

public:
	// constructor
	Enemy(Cursor *mouse);

	// inherited member functions
	virtual bool initialize(Game *gamePtr, int width, int height, int ncols,
		TextureManager *textureM);
	virtual void handleInput(Input* input);
	void update(float frameTime, PLATFORM p);
	virtual void ai();
	void draw();

	Ray *getRay() { return vision; }
};

#endif