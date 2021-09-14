// Module			: Gameplay Programming
// Assignment2		: Assassin Valkyrie
// Student Number	: Chua Wei Jie Timothy
// Student Number	: S10165581F

#ifndef _BULLET_H                 
#define _BULLET_H 
#define WIN32_LEAN_AND_MEAN

#include "entity.h"
#include "constants.h"
#include "MovementComponent.h"

namespace bulletNS
{
	const float	WIDTH = 19;                   
	const float	HEIGHT = 11;
	const float SCALE = 1.0f;
	const int	X = GAME_WIDTH / 2 - WIDTH / 2;  
	const int	Y = GAME_HEIGHT / 2 - HEIGHT / 2;
	const float SPEED = 200;
	const float MASS = 300.0f;
	const int   TEXTURE_COLS = 1;
	const float START_FRAME = 0;
	const float END_FRAME = 0;
	const float ANIMATION_DELAY = 0.2f;
}

class Bullet : public Entity
{
protected:
	MovementComponent	*move;
public:
	Bullet();

	virtual bool initialize(Game *gamePtr, int width, int height, int ncols,
		TextureManager *textureM);
	virtual void update(float frameTime);
	virtual void draw();

	void setVelocity(int velocity) { move->setVelocity(velocity); }
	MovementComponent *getMove() { return move; }
};
#endif

