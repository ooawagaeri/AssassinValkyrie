// Module			: Gameplay Programming
// Assignment2		: Assassin Valkyrie
// Student Number	: Daniel Lee Min Qiang
// Student Number	: S10162739H

#include "pickupArrow.h"

PickupArrow::PickupArrow() : Pickup()
{
	spriteData.width = pickupArrowNS::WIDTH;           // size of Ship1
	spriteData.height = pickupArrowNS::HEIGHT;
	spriteData.rect.bottom = pickupArrowNS::HEIGHT;    // rectangle to select parts of an image
	spriteData.rect.right = pickupArrowNS::WIDTH;
	velocity.x = 100;
	velocity.y = 100;
	currentFrame = startFrame;
	edge = RECT{ (long)(-pickupArrowNS::WIDTH*pickupArrowNS::SCALE / 2), (long)(-pickupArrowNS::HEIGHT*pickupArrowNS::SCALE / 2), (long)(pickupArrowNS::WIDTH*pickupArrowNS::SCALE / 2), (long)(pickupArrowNS::HEIGHT*pickupArrowNS::SCALE / 2) };
	collisionType = entityNS::BOX;
}

bool PickupArrow::initialize(Game *gamePtr, int width, int height, int ncols, TextureManager *textureM)
{

	return(Pickup::initialize(gamePtr, width, height, ncols, textureM));
}

void PickupArrow::update(float frameTime, int direction)
{
	Pickup::update(frameTime, direction);
}


void PickupArrow::draw()
{
	Pickup::draw();              // draw ship
}
