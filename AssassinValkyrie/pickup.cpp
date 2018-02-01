// Module			: Gameplay Programming
// Assignment2		: Assassin Valkyrie
// Student Number	: Daniel Lee Min Qiang
// Student Number	: S10162739H

#include "pickup.h"

Pickup::Pickup() : Entity()
{
	spriteData.width = pickupNS::WIDTH;           // size of Ship1
	spriteData.height = pickupNS::HEIGHT;
	spriteData.rect.bottom = pickupNS::HEIGHT;    // rectangle to select parts of an image
	spriteData.rect.right = pickupNS::WIDTH;
	velocity.x = 100;
	velocity.y = 100;
	currentFrame = startFrame;
	//edge = RECT{ (long)(-fillNS::WIDTH*fillNS::SCALE / 2), (long)(-fillNS::HEIGHT*fillNS::SCALE / 2), (long)(fillNS::WIDTH*fillNS::SCALE / 2), (long)(fillNS::HEIGHT*fillNS::SCALE / 2) };
	//collisionType = entityNS::BOX;
}

bool Pickup::initialize(Game *gamePtr, int width, int height, int ncols, TextureManager *textureM)
{
	move = new MovementComponent(this);

	//health = new HealthComponent();
	//move = new MovementComponent(&(spriteData.x), &(spriteData.y), trooperNS::SPEED, 0);
	return(Entity::initialize(gamePtr, width, height, ncols, textureM));
}

void Pickup::update(float frameTime, int direction)
{
	Entity::update(frameTime);
	move->movementWithDirection(frameTime, direction);
	//move->update(frameTime);
}


void Pickup::draw()
{
	Image::draw();              // draw ship
}
