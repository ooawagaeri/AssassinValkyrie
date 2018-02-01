// Module			: Gameplay Programming
// Assignment2		: Assassin Valkyrie
// Student Number	: Daniel Lee Min Qiang
// Student Number	: S10162739H

#include "pickupStone.h"

PickupStone::PickupStone() : Pickup()
{
	spriteData.width = pickupStoneNS::WIDTH;           // size of Ship1
	spriteData.height = pickupStoneNS::HEIGHT;
	spriteData.rect.bottom = pickupStoneNS::HEIGHT;    // rectangle to select parts of an image
	spriteData.rect.right = pickupStoneNS::WIDTH;
	velocity.x = 100;
	velocity.y = 100;
	currentFrame = startFrame;
	edge = RECT{ (long)(-pickupStoneNS::WIDTH*pickupStoneNS::SCALE / 2), (long)(-pickupStoneNS::HEIGHT*pickupStoneNS::SCALE / 2), (long)(pickupStoneNS::WIDTH*pickupStoneNS::SCALE / 2), (long)(pickupStoneNS::HEIGHT*pickupStoneNS::SCALE / 2) };
	collisionType = entityNS::BOX;
}

bool PickupStone::initialize(Game *gamePtr, int width, int height, int ncols, TextureManager *textureM)
{

	return(Pickup::initialize(gamePtr, width, height, ncols, textureM));
}

void PickupStone::update(float frameTime, int direction)
{
	Pickup::update(frameTime, direction);
}


void PickupStone::draw()
{
	Pickup::draw();              // draw ship
}
