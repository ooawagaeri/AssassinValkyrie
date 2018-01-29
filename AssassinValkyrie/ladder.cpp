// Module			: Gameplay Programming
// Assignment2		: Assassin Valkyrie
// Student Number	: Daniel Lee Min Qiang
// Student Number	: S10162739H

#include "ladder.h"

Ladder::Ladder() : Entity()
{
	spriteData.width = ladderNS::WIDTH;           // size of Ship1
	//spriteData.height = fillNS::HEIGHT;
	//spriteData.rect.bottom = fillNS::HEIGHT;    // rectangle to select parts of an image
	spriteData.rect.right = ladderNS::WIDTH;
	velocity.x = 100;
	velocity.y = 100;
	currentFrame = startFrame;
	//edge = RECT{ (long)(-fillNS::WIDTH*fillNS::SCALE / 2), (long)(-fillNS::HEIGHT*fillNS::SCALE / 2), (long)(fillNS::WIDTH*fillNS::SCALE / 2), (long)(fillNS::HEIGHT*fillNS::SCALE / 2) };
	//collisionType = entityNS::BOX;
}

bool Ladder::initialize(Game *gamePtr, int width, int height, int ncols, TextureManager *textureM)
{
	move = new MovementComponent(this);

	//health = new HealthComponent();
	//move = new MovementComponent(&(spriteData.x), &(spriteData.y), trooperNS::SPEED, 0);
	return(Entity::initialize(gamePtr, width, height, ncols, textureM));
}

void Ladder::update(float frameTime, int direction)
{
	Entity::update(frameTime);
	move->movementWithDirection(frameTime, direction);
	//move->update(frameTime);
}


void Ladder::draw()
{
	Image::draw();              // draw ship
}

void Ladder::setStartX(int i)
{
	startX = i;
}

void Ladder::setStartY(int i)
{
	startY = i;
}
