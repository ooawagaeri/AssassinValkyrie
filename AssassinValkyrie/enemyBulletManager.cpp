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
	for (bullet = bulletList.begin(); bullet != bulletList.end(); ++bullet)
	{
		SAFE_DELETE(*bullet);
	}
}

void EnemyBulletManager::initialize(EnemyManager *enemyList)
{
	gunnerList = enemyList->getGunners();
}

bool EnemyBulletManager::initializeBullet(Game *gamePtr, TextureManager *textureM, Gunner *gunner)
{
	bool isInitialised = true;

	Bullet *it = new Bullet();
	isInitialised = it->initialize(gamePtr, bulletNS::WIDTH, bulletNS::HEIGHT, bulletNS::TEXTURE_COLS, textureM);
	it->setFrames(bulletNS::START_FRAME, bulletNS::END_FRAME);
	it->setCurrentFrame(bulletNS::START_FRAME);
	it->setVelocity(gunner->getMove()->getCurrentVelocity()/ gunner->getMove()->getInitialVelocity() * bulletNS::SPEED);
	it->setX(gunner->getCenterX() - bulletNS::WIDTH / 2);
	it->setY(gunner->getCenterY() - bulletNS::HEIGHT / 2);
	bulletList.emplace_back(it);

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
			if (shot->getAnimation() && shot->shootTimer >= shot->maxTimeShoot)
			{
				shot->shootTimer = GetTickCount();
				initializeBullet(gamePtr, textureM, g);
			}

		}

	for (Bullet *t : bulletList)
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
}

void EnemyBulletManager::render()
{
	for (Bullet *t : bulletList)
		if (t->getActive())
			t->draw();
}