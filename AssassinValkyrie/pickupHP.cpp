// Module			: Gameplay Programming
// Assignment2		: Assassin Valkyrie
// Student Number	: Daniel Lee Min Qiang
// Student Number	: S10162739H

#include "pickupHP.h"

PickupHP::PickupHP() : Pickup()
{
	spriteData.width = pickupHPNS::WIDTH;           // size of Ship1
	spriteData.height = pickupHPNS::HEIGHT;
	spriteData.rect.bottom = pickupHPNS::HEIGHT;    // rectangle to select parts of an image
	spriteData.rect.right = pickupHPNS::WIDTH;
	velocity.x = 100;
	velocity.y = 100;
	currentFrame = startFrame;
	edge = RECT{ (long)(-pickupHPNS::WIDTH*pickupHPNS::SCALE / 2), (long)(-pickupHPNS::HEIGHT*pickupHPNS::SCALE / 2), (long)(pickupHPNS::WIDTH*pickupHPNS::SCALE / 2), (long)(pickupHPNS::HEIGHT*pickupHPNS::SCALE / 2) };
	collisionType = entityNS::BOX;
}

bool PickupHP::initialize(Game *gamePtr, int width, int height, int ncols, TextureManager *textureM)
{

	return(Pickup::initialize(gamePtr, width, height, ncols, textureM));
}

void PickupHP::update(float frameTime, int direction)
{
	Pickup::update(frameTime, direction);
	//move->update(frameTime);
}


void PickupHP::draw()
{
	Pickup::draw();              // draw ship
}
