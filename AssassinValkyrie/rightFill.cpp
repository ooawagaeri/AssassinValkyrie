// Module			: Gameplay Programming
// Assignment2		: Assassin Valkyrie
// Student Number	: Daniel Lee Min Qiang
// Student Number	: S10162739H

#include "rightFill.h"

RightFill::RightFill() : Fill()
{
	spriteData.width = fillNS::WIDTH;           // size of Ship1
	spriteData.height = fillNS::HEIGHT;
	spriteData.rect.bottom = fillNS::HEIGHT;    // rectangle to select parts of an image
	spriteData.rect.right = fillNS::WIDTH;
	velocity.x = 100;
	velocity.y = 100;
	currentFrame = startFrame;
	//edge = RECT{ (long)(-fillNS::WIDTH*fillNS::SCALE / 2), (long)(-fillNS::HEIGHT*fillNS::SCALE / 2), (long)(fillNS::WIDTH*fillNS::SCALE / 2), (long)(fillNS::HEIGHT*fillNS::SCALE / 2) };
	//collisionType = entityNS::BOX;
}

bool RightFill::initialize(Game *gamePtr, int width, int height, int ncols, TextureManager *textureM)
{
	return(Fill::initialize(gamePtr, width, height, ncols, textureM));
}

void RightFill::update(float frameTime, int direction)
{
	Fill::update(frameTime, direction);
}

void RightFill::draw()
{
	Fill::draw();              // draw ship
}
