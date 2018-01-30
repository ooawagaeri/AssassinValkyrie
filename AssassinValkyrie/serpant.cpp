// Module			: Gameplay Programming
// Assignment2		: Assassin Valkyrie
// Student Number	: Chua Wei Jie Timothy
// Student Number	: S10165581F

#include "serpant.h"

Serpant::Serpant(Entity *play) : Enemy(play)
{
	spriteData.width = serpantNS::WIDTH;
	spriteData.height = serpantNS::HEIGHT;
	spriteData.x = serpantNS::X;
	spriteData.y = serpantNS::Y;
	spriteData.rect.bottom = serpantNS::HEIGHT;
	spriteData.rect.right = serpantNS::WIDTH;
	spriteData.angle = serpantNS::ROTATION;
	spriteData.scale = serpantNS::SCALE;
	frameDelay = serpantNS::ANIMATION_DELAY;
	startFrame = serpantNS::START_FRAME;
	endFrame = serpantNS::END_FRAME;
	currentFrame = startFrame;
	edge = RECT{ (long)(-serpantNS::WIDTH*serpantNS::SCALE / 2), (long)(-serpantNS::HEIGHT*serpantNS::SCALE / 2), (long)(serpantNS::WIDTH*serpantNS::SCALE / 2), (long)(serpantNS::HEIGHT*serpantNS::SCALE / 2) };
	range = serpantNS::FIRE_RANGE;
	attackFrame = serpantNS::FIRE_START_FRAME;
}

bool Serpant::initialize(Game *gamePtr, int width, int height, int ncols,
	TextureManager *textureM, TextureManager *textureHealth)
{
	attackAnimation.initialize(gamePtr->getGraphics(), serpantNS::FIRE_WIDTH, serpantNS::FIRE_HEIGHT, serpantNS::FIRE_TEXTURE_COLS, textureM);
	attackAnimation.setFrames(serpantNS::FIRE_START_FRAME, serpantNS::FIRE_END_FRAME);
	attackAnimation.setCurrentFrame(serpantNS::FIRE_START_FRAME);
	attackAnimation.setFrameDelay(serpantNS::ANIMATION_DELAY);
	attackAnimation.setLoop(false);

	move->setVelocity(serpantNS::SPEED);
	attack = new FireComponent(&attackAnimation);
	health->initialize(gamePtr->getGraphics(), textureHealth, serpantNS::HEALTH);
	vision->init(this, serpantNS::VISION_ANGLE, serpantNS::VISION_RANGE, serpantNS::VISION_HEIGHT);

	return(Enemy::initialize(gamePtr, width, height, ncols, textureM));
}