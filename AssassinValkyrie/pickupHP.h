// Module			: Gameplay Programming
// Assignment2		: Assassin Valkyrie
// Student Number	: Daniel Lee Min Qiang
// Student Number	: S10162739H

#ifndef _PICKUPHP_H 
#define _PICKUPHP_H
#define WIN32_LEAN_AND_MEAN

#include "pickup.h"
#include "constants.h"

namespace pickupHPNS
{
	const int	WIDTH = 64;
	const int	HEIGHT = 64;
	const double ROTATION = 0;
	const float SCALE = 1.0f;
	//const int	X = GAME_WIDTH / 2 - WIDTH*SCALE;
	//const int	Y = GAME_HEIGHT / 2 - HEIGHT*SCALE;
	const float SPEED = 100;
	const float MASS = 300.0f;
	const int   TEXTURE_COLS = 3;
	const int   START_FRAME = 0;
}

class PickupHP : public Pickup
{
private:

public:
	// constructor
	PickupHP();

	// inherited member functions
	bool initialize(Game *gamePtr, int width, int height, int ncols, TextureManager *textureM);
	void update(float frameTime, int direction);
	void draw();
};
#endif