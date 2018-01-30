// Module			: Gameplay Programming
// Assignment2		: Assassin Valkyrie
// Student Number	: Chua Wei Jie Timothy
// Student Number	: S10165581F

#include "gunner.h"

Gunner::Gunner(Entity *play) : Enemy(play)
{
	spriteData.width = gunnerNS::WIDTH;
	spriteData.height = gunnerNS::HEIGHT;
	spriteData.x = gunnerNS::X;
	spriteData.y = gunnerNS::Y;
	spriteData.rect.bottom = gunnerNS::HEIGHT;
	spriteData.rect.right = gunnerNS::WIDTH;
	spriteData.angle = gunnerNS::ROTATION;
	spriteData.scale = gunnerNS::SCALE;
	frameDelay = gunnerNS::ANIMATION_DELAY;
	startFrame = gunnerNS::START_FRAME; 
	endFrame = gunnerNS::END_FRAME;
	currentFrame = startFrame;
	edge = RECT{ (long)(-gunnerNS::WIDTH*gunnerNS::SCALE / 2), (long)(-gunnerNS::HEIGHT*gunnerNS::SCALE / 2), (long)(gunnerNS::WIDTH*gunnerNS::SCALE / 2), (long)(gunnerNS::HEIGHT*gunnerNS::SCALE / 2) };
	range = gunnerNS::SHOOT_RANGE;
	attackFrame = gunnerNS::SHOOT_START_FRAME;
}

bool Gunner::initialize(Game *gamePtr, int width, int height, int ncols,
	TextureManager *textureM, TextureManager *textureHealth)
{
	attackAnimation.initialize(gamePtr->getGraphics(), gunnerNS::SHOOT_WIDTH, gunnerNS::SHOOT_HEIGHT, gunnerNS::SHOOT_TEXTURE_COLS, textureM);
	attackAnimation.setFrames(gunnerNS::SHOOT_START_FRAME, gunnerNS::SHOOT_END_FRAME);
	attackAnimation.setCurrentFrame(gunnerNS::SHOOT_START_FRAME);
	attackAnimation.setFrameDelay(gunnerNS::ANIMATION_DELAY);
	attackAnimation.setLoop(false);

	move->setVelocity(gunnerNS::SPEED);
	attack = new ShootComponent(&attackAnimation);
	health->initialize(gamePtr->getGraphics(), textureHealth, gunnerNS::HEALTH);
	vision->init(this, gunnerNS::VISION_ANGLE, gunnerNS::VISION_RANGE, gunnerNS::VISION_HEIGHT);

	return(Enemy::initialize(gamePtr, width, height, ncols, textureM));
}