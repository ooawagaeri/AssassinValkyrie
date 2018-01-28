// Module			: Gameplay Programming
// Assignment2		: Assassin Valkyrie
// Student Number	: Chua Wei Jie Timothy
// Student Number	: S10165581F

#include "enemy.h"

Enemy::Enemy(Cursor *mouse) : Entity()
{
	collisionType = entityNS::BOX;
	health = new HealthComponent();
	move = new MovementComponent(this);
	state_ = new PatrollingState();
	
	mouseCursor = mouse;
	vision = new Ray();
}

bool Enemy::initialize(Game *gamePtr, int width, int height, int ncols,
	TextureManager *textureM)
{
	return(Entity::initialize(gamePtr, width, height, ncols, textureM));
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

void Enemy::update(float frameTime, PLATFORM p)
{
	state_->update(this, mouseCursor);
	handleInput(input);

	move->update(frameTime);
	attack->update(frameTime);
	vision->updateVision(p);

	Entity::update(frameTime);
}

void Enemy::ai()
{
}

void Enemy::draw()
{
	if (velocity.x > 0)
		flipHorizontal(false);
	else
		flipHorizontal(true);

	Image::draw();
	attack->draw(this);
}