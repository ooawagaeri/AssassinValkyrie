// Module			: Gameplay Programming
// Assignment2		: Assassin Valkyrie
// Student Number	: Chua Wei Jie Timothy
// Student Number	: S10165581F

#ifndef _FIREBALL_H                 
#define _FIREBALL_H 
#define WIN32_LEAN_AND_MEAN

#include "bullet.h"
#include "entity.h"

namespace fireNS
{
	const float	WIDTH = 36;
	const float	HEIGHT = 15;
	const float SCALE = 1.0f;
	const int	X = GAME_WIDTH / 2 - WIDTH / 2;
	const int	Y = GAME_HEIGHT / 2 - HEIGHT / 2;
	const float SPEED = 100;
	const float MASS = 300.0f;
	const int   TEXTURE_COLS = 1;
	const float START_FRAME = 1;
	const float END_FRAME = 1;
	const float ANIMATION_DELAY = 0.2f;
}

class Fireball : public Bullet
{
public:
	Fireball(float dist);

	virtual bool initialize(Game *gamePtr, int width, int height, int ncols,
		TextureManager *textureM);
};
#endif

