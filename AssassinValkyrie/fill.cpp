// Module			: Gameplay Programming
// Assignment2		: Assassin Valkyrie
// Student Number	: Daniel Lee Min Qiang
// Student Number	: S10162739H

#include "fill.h"

Fill::Fill() : Image()
{
	spriteData.width = fillNS::WIDTH;           // size of Ship1
	spriteData.height = fillNS::HEIGHT;
	spriteData.rect.bottom = fillNS::HEIGHT;    // rectangle to select parts of an image
	spriteData.rect.right = fillNS::WIDTH;

	currentFrame = startFrame;
	//edge = RECT{ (long)(-fillNS::WIDTH*fillNS::SCALE / 2), (long)(-fillNS::HEIGHT*fillNS::SCALE / 2), (long)(fillNS::WIDTH*fillNS::SCALE / 2), (long)(fillNS::HEIGHT*fillNS::SCALE / 2) };
	//collisionType = entityNS::BOX;
}

bool Fill::initialize(Game *gamePtr, int width, int height, int ncols, TextureManager *textureM)
{
	//health = new HealthComponent();
	//move = new MovementComponent(&(spriteData.x), &(spriteData.y), trooperNS::SPEED, 0);
	return(Image::initialize(gamePtr->getGraphics(), width, height, ncols, textureM));
}

void Fill::update(float frameTime)
{
	Image::update(frameTime);

	//move->update(frameTime);
}


void Fill::draw()
{
	Image::draw();              // draw ship
}