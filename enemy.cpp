// Module			: Gameplay Programming
// Assignment2		: Assassin Valkyrie
// Student Number	: Chua Wei Jie Timothy
// Student Number	: S10165581F

#include "enemy.h"

Enemy::Enemy(Cursor *mouse) : Entity()
{
	spriteData.width = trooperNS::WIDTH;           // size of Ship1
	spriteData.height = trooperNS::HEIGHT;
	spriteData.x = trooperNS::X;                   // location on screen
	spriteData.y = trooperNS::Y;
	spriteData.rect.bottom = trooperNS::HEIGHT;    // rectangle to select parts of an image
	spriteData.rect.right = trooperNS::WIDTH;
	spriteData.angle = trooperNS::ROTATION;
	spriteData.scale = trooperNS::SCALE;
	velocity = VECTOR2(trooperNS::SPEED, 0);
	frameDelay = trooperNS::ANIMATION_DELAY;
	startFrame = trooperNS::START_FRAME;     // first frame of ship animation
	endFrame = trooperNS::END_FRAME;     // last frame of ship animation
	currentFrame = startFrame;
	edge = RECT{ (long)(-trooperNS::WIDTH*trooperNS::SCALE / 2), (long)(-trooperNS::HEIGHT*trooperNS::SCALE / 2), (long)(trooperNS::WIDTH*trooperNS::SCALE / 2), (long)(trooperNS::HEIGHT*trooperNS::SCALE / 2) };
	collisionType = entityNS::BOX;

	health = new HealthComponent();
	move = new MovementComponent(this);
	mouseCursor = mouse;
	state_ = new PatrollingState();
}

void Enemy::handleInput(Input* input)
{
	EnemyState* state = state_->handleInput(*this, input);
	if (state != NULL)
	{
		SAFE_DELETE(state_);
		state_ = state;
	}
}

void Enemy::update(float frameTime)
{
	handleInput(input);

	state_->update(this, mouseCursor);
	move->update(frameTime);

	Entity::update(frameTime);
}

// To find closest ship vector position
void Enemy::ai(Entity &ship1, Entity &ship2)
{
}

void Enemy::draw()
{
	if (velocity.x > 0)
		flipHorizontal(false);
	else
		flipHorizontal(true);
	Image::draw();
}