// Module			: Gameplay Programming
// Assignment2		: Assassin Valkyrie
// Student Number	: Chua Wei Jie Timothy
// Student Number	: S10165581F

#include "trooper.h"

Trooper::Trooper(Entity *play) : Enemy(play)
{
	spriteData.width = trooperNS::WIDTH; 
	spriteData.height = trooperNS::HEIGHT;
	spriteData.x = trooperNS::X;
	spriteData.y = trooperNS::Y;
	spriteData.rect.bottom = trooperNS::HEIGHT;
	spriteData.rect.right = trooperNS::WIDTH;
	spriteData.angle = trooperNS::ROTATION;
	spriteData.scale = trooperNS::SCALE;
	velocity = VECTOR2(trooperNS::SPEED, 0);
	frameDelay = trooperNS::ANIMATION_DELAY;
	startFrame = trooperNS::START_FRAME;
	endFrame = trooperNS::END_FRAME;
	currentFrame = startFrame;
	edge = RECT{ (long)(-trooperNS::WIDTH*trooperNS::SCALE / 2), (long)(-trooperNS::HEIGHT*trooperNS::SCALE / 2), (long)(trooperNS::WIDTH*trooperNS::SCALE / 2), (long)(trooperNS::HEIGHT*trooperNS::SCALE / 2) };
	range = trooperNS::MELEE_RANGE;
	attackFrame = trooperNS::MELEE_START_FRAME;
}

bool Trooper::initialize(Game *gamePtr, int width, int height, int ncols,
	TextureManager *textureM, TextureManager *textureHealth)
{
	attackAnimation.initialize(gamePtr->getGraphics(), trooperNS::MELEE_WIDTH, trooperNS::MELEE_HEIGHT, trooperNS::MELEE_TEXTURE_COLS, textureM);
	attackAnimation.setFrames(trooperNS::MELEE_START_FRAME, trooperNS::MELEE_END_FRAME);
	attackAnimation.setCurrentFrame(trooperNS::MELEE_START_FRAME);
	attackAnimation.setFrameDelay(trooperNS::ANIMATION_DELAY);
	attackAnimation.setLoop(false);

	move->setVelocity(trooperNS::SPEED);
	attack = new MeleeComponent(&attackAnimation);
	health->initialize(gamePtr->getGraphics(), textureHealth, trooperNS::HEALTH);
	vision->init(this, trooperNS::VISION_ANGLE, trooperNS::VISION_RANGE, trooperNS::VISION_HEIGHT);

	return(Enemy::initialize(gamePtr, width, height, ncols, textureM));
}