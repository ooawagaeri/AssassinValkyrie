// Module			: Gameplay Programming
// Assignment2		: Assassin Valkyrie
// Student Number	: Chua Wei trooper Timothy
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
}

bool Gunner::initialize(Game *gamePtr, int width, int height, int ncols,
	TextureManager *textureM)
{
	attackAnimation.initialize(gamePtr->getGraphics(), gunnerNS::SHOOT_WIDTH, gunnerNS::SHOOT_HEIGHT, gunnerNS::SHOOT_TEXTURE_COLS, textureM);
	attackAnimation.setFrames(gunnerNS::SHOOT_START_FRAME, gunnerNS::SHOOT_END_FRAME);
	attackAnimation.setCurrentFrame(gunnerNS::SHOOT_START_FRAME);
	attackAnimation.setFrameDelay(gunnerNS::ANIMATION_DELAY);
	attackAnimation.setLoop(false);

	move->setVelocity(gunnerNS::SPEED);
	attack = new ShootComponent(&attackAnimation);
	vision->init(&center.x, &center.y, gunnerNS::VISION_ANGLE, gunnerNS::VISION_RANGE, gunnerNS::VISION_HEIGHT);

	return(Enemy::initialize(gamePtr, width, height, ncols, textureM));
}

void Gunner::ai()
{
	VECTOR2 pos1 = *getCenter() - *player->getCenter();

	if (D3DXVec2Length(&pos1) < gunnerNS::SHOOT_RANGE && !attack->getAnimation() && !sameSign(velocity.x, pos1.x))
	{
		attack->setAnimation(true);
		attackAnimation.setCurrentFrame(gunnerNS::SHOOT_START_FRAME);
	}
}