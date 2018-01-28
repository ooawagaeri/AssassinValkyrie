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
#include "enemyState.h"
#include "patrolState.h"

namespace trooperNS
{
	const int	HEALTH = 20;
	const int	WIDTH = 65;
	const int	HEIGHT = 100;
	const double ROTATION = 0;
	const float SCALE = 1.0f;
	const float	X = GAME_WIDTH / 2 - WIDTH*SCALE;
	const float	Y = GAME_HEIGHT / 2 - HEIGHT*SCALE;
	const float SPEED = 60;
	const float MASS = 300.0f;
	const int   TEXTURE_COLS = 10;
	const int   START_FRAME = 0;
	const int   END_FRAME = 9;
	const float ANIMATION_DELAY = 0.5f;

	const double VISION_ANGLE = PI / 6;
	const int	VISION_RANGE = 200;
	const float	VISION_HEIGHT = HEIGHT*SCALE / 3.5f;

	const int MELEE_RANGE = 100;
	const int MELEE_WIDTH = 92;
	const int MELEE_HEIGHT = 100;
	const int MELEE_TEXTURE_COLS = 5;
	const int MELEE_START_FRAME = 5;
	const int MELEE_END_FRAME = 9;
}

namespace gunnerNS
{
	const int	HEALTH = 20;
	const int	WIDTH = 96;
	const int	HEIGHT = 96;
	const double ROTATION = 0;
	const float SCALE = 1.0f;
	const float	X = GAME_WIDTH / 2 - WIDTH*SCALE + 100;
	const float	Y = GAME_HEIGHT / 2 - HEIGHT*SCALE;
	const float SPEED = 40;
	const float MASS = 300.0f;
	const int   TEXTURE_COLS = 4;
	const int   START_FRAME = 8;
	const int   END_FRAME = 11;
	const float ANIMATION_DELAY = 0.25f;

	const double VISION_ANGLE = PI / 8;
	const int	VISION_RANGE = 250;
	const float	VISION_HEIGHT = HEIGHT*SCALE / 3.5f;

	const int SHOOT_RANGE = 100;
	const int SHOOT_WIDTH = 96;
	const int SHOOT_HEIGHT = 95;
	const int SHOOT_TEXTURE_COLS = 4;
	const int SHOOT_START_FRAME = 21;
	const int SHOOT_END_FRAME = 26;
}

class Enemy : public Entity
{
protected:
	HealthComponent		*health;
	MovementComponent	*move;
	AttackComponent		*attack;
	EnemyState			*state_;
	// player to track
	Entity	*player;
	Ray		*vision;
	Image	attackAnimation;
	bool	sameSign(int x, int y);

public:
	// constructor
	Enemy(Entity *play);
	~Enemy();

	// inherited member functions
	virtual bool initialize(Game *gamePtr, int width, int height, int ncols,
		TextureManager *textureM);
	virtual void handleInput(PLATFORM p);
	void update(float frameTime, PLATFORM p);
	virtual void ai();
	void draw(Graphics *g);

	void setOriginalPos(VECTOR2 pos) 
	{ 
		spriteData.x = pos.x; spriteData.y = pos.y;
		move->setOrigin(pos);
	}
	Ray *getRay() { return vision; }
	MovementComponent *getMove() { return move; }
};

#endif