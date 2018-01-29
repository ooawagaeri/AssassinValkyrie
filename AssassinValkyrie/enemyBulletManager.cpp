// Module			: Gameplay Programming
// Assignment2		: Assassin Valkyrie
// Student Number	: Chua Wei Jie Timothy
// Student Number	: S10165581F

#include "enemyBulletManager.h"

EnemyBulletManager::EnemyBulletManager()
{
}

EnemyBulletManager::~EnemyBulletManager()
{
	for (bullet = bulletList.begin(); bullet != bulletList.end(); bullet++)
		SAFE_DELETE(*bullet);

	for (fireball = fireList.begin(); fireball != fireList.end(); fireball++)
		SAFE_DELETE(*bullet);
}

void EnemyBulletManager::initialize(EnemyManager *enemyList)
{
	gunnerList = enemyList->getGunners();
	serpantList = enemyList->getSerpant();
}

bool EnemyBulletManager::initializeBullet(Game *gamePtr, TextureManager *textureM, Gunner *gunner)
{
	bool isInitialised = true;

	Bullet *it = new Bullet();
	isInitialised = it->initialize(gamePtr, bulletNS::WIDTH, bulletNS::HEIGHT, bulletNS::TEXTURE_COLS, textureM);
	it->setFrames(bulletNS::START_FRAME, bulletNS::END_FRAME);
	it->setCurrentFrame(bulletNS::START_FRAME);
	float direction = gunner->getMove()->getCurrentVelocity();
	if (direction > 0)
	{
		direction = 1;
		it->flipHorizontal(false);
	}
	else
	{
		direction = -1;
		it->flipHorizontal(true);
	}
	it->getMove()->setVelocity(direction * bulletNS::SPEED);
	it->setX(gunner->getCenterX() - bulletNS::WIDTH / 2);
	it->setY(gunner->getCenterY() - bulletNS::HEIGHT / 2 - gunnerNS::HEIGHT / 6);
	bulletList.emplace_back(it);

	if (!isInitialised)
		return !isInitialised;
	return isInitialised;
}

bool EnemyBulletManager::initializeFire(Game *gamePtr, TextureManager *textureM, Serpant *serpant)
{
	bool isInitialised = true;

	Fireball *it = new Fireball();
	isInitialised = it->initialize(gamePtr, fireNS::WIDTH, fireNS::HEIGHT, fireNS::TEXTURE_COLS, textureM);
	it->setFrames(fireNS::START_FRAME, fireNS::END_FRAME);
	it->setCurrentFrame(fireNS::START_FRAME);
	float direction = serpant->getMove()->getCurrentVelocity();
	if (direction > 0)
	{
		direction = 1;
		it->flipHorizontal(false);
	}
	else
	{
		direction = -1;
		it->flipHorizontal(true);
	}
	it->getMove()->setVelocity(direction * fireNS::SPEED);
	it->setX(serpant->getCenterX() - fireNS::WIDTH / 2);
	it->setY(serpant->getCenterY() - fireNS::HEIGHT / 2 - gunnerNS::HEIGHT / 6);
	fireList.emplace_back(it);

	if (!isInitialised)
		return !isInitialised;
	return isInitialised;
}

void EnemyBulletManager::update(float frameTime, Game *gamePtr, TextureManager *textureM)
{
	for (Gunner *g : *gunnerList)
		if (g->getActive())
		{
			ShootComponent *shot = g->getShoot();
			if (shot->getAnimation() && (GetTickCount() - shot->shootTimer > shot->maxTimeShoot))
			{
				shot->shootTimer = GetTickCount();
				initializeBullet(gamePtr, textureM, g);
			}
		}

	for (Serpant *g : *serpantList)
		if (g->getActive())
		{
			FireComponent *shot = g->getShoot();
			if (shot->getAnimation() && (GetTickCount() - shot->fireTimer > shot->maxTimeFire))
			{
				shot->fireTimer = GetTickCount();
				initializeFire(gamePtr, textureM, g);
			}
		}

	for (Bullet *t : bulletList)
		if (t->getActive())
			t->update(frameTime);

	for (Fireball *t : fireList)
		if (t->getActive())
			t->update(frameTime);
}

void EnemyBulletManager::collisions(Entity *play)
{
	VECTOR2 collisionVector;
	bullet = bulletList.begin();
	while (bullet != bulletList.end())
	{
		if ((*bullet)->getActive()) {
			if ((*bullet)->collidesWith(*play, collisionVector))
			{
			}
			bullet++;
		}
		else
			bullet = bulletList.erase(bullet);
	}

	fireball = fireList.begin();
	while (fireball != fireList.end())
	{
		if ((*fireball)->getActive()) {
			if ((*fireball)->collidesWith(*play, collisionVector))
			{
			}
			fireball++;
		}
		else
			fireball = fireList.erase(fireball);
	}
}

void EnemyBulletManager::render()
{
	for (Bullet *t : bulletList)
		if (t->getActive())
			t->draw();

	for (Fireball *t : fireList)
		if (t->getActive())
			t->draw();
}