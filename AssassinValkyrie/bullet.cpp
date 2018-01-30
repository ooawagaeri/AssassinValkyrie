// Module			: Gameplay Programming
// Assignment2		: Assassin Valkyrie
// Student Number	: Chua Wei Jie Timothy
// Student Number	: S10165581F

#include "bullet.h"

Bullet::Bullet() : Entity()
{
	spriteData.width = bulletNS::WIDTH;
	spriteData.height = bulletNS::HEIGHT;
	spriteData.x = bulletNS::X; 
	spriteData.y = bulletNS::Y;
	spriteData.rect.bottom = bulletNS::HEIGHT;
	spriteData.rect.right = bulletNS::WIDTH;
	frameDelay = bulletNS::ANIMATION_DELAY;
	startFrame = bulletNS::START_FRAME;
	endFrame = bulletNS::END_FRAME;
	currentFrame = startFrame;
	edge = RECT{ (long)(-bulletNS::WIDTH*bulletNS::SCALE / 2), (long)(-bulletNS::HEIGHT*bulletNS::SCALE / 2), (long)(bulletNS::WIDTH*bulletNS::SCALE / 2), (long)(bulletNS::HEIGHT*bulletNS::SCALE / 2) };
	collisionType = entityNS::BOX;
}

bool Bullet::initialize(Game *gamePtr, int width, int height, int ncols, TextureManager *textureM)
{
	move = new MovementComponent(this);
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