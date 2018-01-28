// Module			: Gameplay Programming
// Assignment2		: Assassin Valkyrie
// Student Number	: Chua Wei Jie Timothy
// Student Number	: S10165581F

#include "bullet.h"

Bullet::Bullet() : Entity()
{
	spriteData.width = bulletNS::WIDTH;           // size of Ship1
	spriteData.height = bulletNS::HEIGHT;
	spriteData.x = bulletNS::X;                   // location on screen
	spriteData.y = bulletNS::Y;
	spriteData.rect.bottom = bulletNS::HEIGHT;    // rectangle to select parts of an image
	spriteData.rect.right = bulletNS::WIDTH;
	frameDelay = bulletNS::ANIMATION_DELAY;
	startFrame = bulletNS::START_FRAME;     // first frame of ship animation
	endFrame = bulletNS::END_FRAME;     // last frame of ship animation
	currentFrame = startFrame;
	edge = RECT{ (long)(-bulletNS::WIDTH*bulletNS::SCALE / 2), (long)(-bulletNS::HEIGHT*bulletNS::SCALE / 2), (long)(bulletNS::WIDTH*bulletNS::SCALE / 2), (long)(bulletNS::HEIGHT*bulletNS::SCALE / 2) };
	collisionType = entityNS::BOX;

	move = new MovementComponent(this);
}

bool Bullet::initialize(Game *gamePtr, int width, int height, int ncols, TextureManager *textureM)
{
	return(Entity::initialize(gamePtr, width, height, ncols, textureM));
}

void Bullet::draw()
{
	if (move->getCurrentVelocity() > 0)
		flipHorizontal(false);
	else
		flipHorizontal(true);
	Image::draw();
}

void Bullet::update(float frameTime)
{
	if (spriteData.x + spriteData.width < 0 || spriteData.x > GAME_WIDTH || spriteData.y > GAME_HEIGHT || spriteData.y + spriteData.height < 0)
		active = false;

	move->update(frameTime);
	Entity::update(frameTime);
}