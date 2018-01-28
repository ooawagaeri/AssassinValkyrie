// Module			: Gameplay Programming
// Assignment2		: Assassin Valkyrie
// Student Number	: Chua Wei Jie Timothy
// Student Number	: S10165581F

#include "enemy.h"

Enemy::Enemy(Entity *play) : Entity()
{
	collisionType = entityNS::BOX;
	health = new HealthComponent();
	move = new MovementComponent(this);
	state_ = new PatrollingState();
	
	player = play;
	vision = new Ray();
}

Enemy::~Enemy()
{
	SAFE_DELETE(health);
	SAFE_DELETE(move);
	SAFE_DELETE(state_);
	SAFE_DELETE(attack);
	SAFE_DELETE(vision);
}

bool Enemy::initialize(Game *gamePtr, int width, int height, int ncols,
	TextureManager *textureM)
{
	move->setOrigin(*getCenter());
	return(Entity::initialize(gamePtr, width, height, ncols, textureM));
}

void Enemy::handleInput(PLATFORM p)
{
	EnemyState* state = state_->handleInput(this, player,p);
	if (state != NULL)
	{
		SAFE_DELETE(state_);
		state_ = state;
	}
}

void Enemy::update(float frameTime, PLATFORM p)
{
	handleInput(p);
	state_->update(this, player);

	move->update(frameTime);
	attack->update(frameTime);

	vision->setDirection(move->getCurrentVelocity());
	vision->updateVision(p);

	Entity::update(frameTime);
}

void Enemy::ai()
{
}

void Enemy::draw(Graphics *g)
{
	if (move->getCurrentVelocity() > 0)
		flipHorizontal(false);
	else
		flipHorizontal(true);

	// Stops Sprite rendering so that primatives can render
	g->spriteEnd();
	vision->render(g);
	g->spriteBegin();

	Image::draw();
	attack->draw(this);
}

bool Enemy::sameSign(int x, int y)
{
	return (x >= 0) ^ (y < 0);
}