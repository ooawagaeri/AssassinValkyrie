// Module			: Gameplay Programming
// Assignment2		: Assassin Valkyrie
// Student Number	: Daniel Lee Min Qiang
// Student Number	: S10162739H

#include "floor.h"

Floor::Floor() : Entity()
{
	spriteData.width = floorNS::WIDTH;           // size of Ship1
	spriteData.height = floorNS::HEIGHT;
	spriteData.rect.bottom = floorNS::HEIGHT;    // rectangle to select parts of an image
	spriteData.rect.right = floorNS::WIDTH;

	currentFrame = startFrame;
	edge = RECT{ (long)(-floorNS::WIDTH*floorNS::SCALE / 2), (long)(-floorNS::HEIGHT*floorNS::SCALE / 2), (long)(floorNS::WIDTH*floorNS::SCALE / 2), (long)(floorNS::HEIGHT*floorNS::SCALE / 2) };
	collisionType = entityNS::BOX;
}

bool Floor ::initialize(Game *gamePtr, int width, int height, int ncols, TextureManager *textureM)
{
	//health = new HealthComponent();
	//move = new MovementComponent(&(spriteData.x), &(spriteData.y), trooperNS::SPEED, 0);
	return(Entity::initialize(gamePtr, width, height, ncols, textureM));
}

void Floor::update(float frameTime)
{
	Entity::update(frameTime);

	//move->update(frameTime);
}


void Floor::draw()
{
	Image::draw();              // draw ship
}