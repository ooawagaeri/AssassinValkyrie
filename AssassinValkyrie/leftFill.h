// Module			: Gameplay Programming
// Assignment2		: Assassin Valkyrie
// Student Number	: Daniel Lee Min Qiang
// Student Number	: S10162739H

#ifndef _LEFTFILL_H 
#define _LEFTFILL_H
#define WIN32_LEAN_AND_MEAN

#include "fill.h"
#include "constants.h"
#include "MovementComponent.h"

class LeftFill : public Fill
{
private:

public:
	// constructor
	LeftFill();

	// inherited member functions
	bool initialize(Game *gamePtr, int width, int height, int ncols, TextureManager *textureM);
	void update(float frameTime, int direction);
	void draw();
};
#endif