// Module			: Gameplay Programming
// Assignment2		: Assassin Valkyrie
// Student Number	: Chua Wei trooper Timothy
// Student Number	: S10165581F

#include "cursor.h"

Cursor::Cursor() : Entity()
{
	spriteData.width = cursorNS::WIDTH;           // size of Ship1
	spriteData.height = cursorNS::HEIGHT;
	spriteData.x = cursorNS::X;                   // location on screen
	spriteData.y = cursorNS::Y;
	spriteData.rect.bottom = cursorNS::HEIGHT;    // rectangle to select parts of an image
	spriteData.rect.right = cursorNS::WIDTH;
	spriteData.angle = cursorNS::ROTATION;
	spriteData.scale = cursorNS::SCALE;

	frameDelay = cursorNS::ANIMATION_DELAY;
	startFrame = cursorNS::START_FRAME;     // first frame of ship animation
	endFrame = cursorNS::END_FRAME;     // last frame of ship animation
	currentFrame = startFrame;

	edge = RECT{ (long)(-cursorNS::WIDTH*cursorNS::SCALE / 2), (long)(-cursorNS::HEIGHT*cursorNS::SCALE / 2), (long)(cursorNS::WIDTH*cursorNS::SCALE / 2), (long)(cursorNS::HEIGHT*cursorNS::SCALE / 2) };
	collisionType = entityNS::BOX;
}

void Cursor::update()
{
	spriteData.x = input->getMouseX() - spriteData.width / 2;
	spriteData.y = input->getMouseY() - spriteData.height / 2;
	
	if (spriteData.x < 0)
		spriteData.x = 0;
	if (spriteData.x + spriteData.width > GAME_WIDTH)
		spriteData.x = GAME_WIDTH;
	if (spriteData.y > GAME_HEIGHT)
		spriteData.y = GAME_HEIGHT;
	if (spriteData.y + spriteData.height < 0)
		spriteData.y = 0;
}