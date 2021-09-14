// Module			: Gameplay Programming
// Assignment2		: Assassin Valkyrie
// Student Number	: Chua Wei Jie Timothy
// Student Number	: S10165581F

#include "fireBall.h"

Fireball::Fireball(float dist)
{
	spriteData.width = fireNS::WIDTH;
	spriteData.height = fireNS::HEIGHT;
	spriteData.x = fireNS::X;
	spriteData.y = fireNS::Y;
	spriteData.rect.bottom = fireNS::HEIGHT;
	spriteData.rect.right = fireNS::WIDTH;
	frameDelay = fireNS::ANIMATION_DELAY;
	startFrame = fireNS::START_FRAME; 
	endFrame = fireNS::END_FRAME; 
	currentFrame = startFrame;
	edge = RECT{ (long)(-fireNS::WIDTH*fireNS::SCALE / 2), (long)(-fireNS::HEIGHT*fireNS::SCALE / 2), (long)(fireNS::WIDTH*fireNS::SCALE / 2), (long)(fireNS::HEIGHT*fireNS::SCALE / 2) };
	collisionType = entityNS::BOX;
	move = new ProjectileMovement(this, dist);
}

bool Fireball::initialize(Game *gamePtr, int width, int height, int ncols, TextureManager *textureM)
{
	return(Entity::initialize(gamePtr, width, height, ncols, textureM));
}