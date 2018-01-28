// Module			: Gameplay Programming
// Assignment2		: Assassin Valkyrie
// Student Number	: Chua Wei Jie Timothy
// Student Number	: S10165581F

#pragma once
#include "bullet.h"
#include "enemyManager.h"
#include <vector>

typedef std::vector<Bullet*> BULLETLIST;

class EnemyBulletManager
{
private:
	GUNNERLIST *gunnerList;
	BULLETLIST bulletList;
	GUNNERLIST::iterator gunner; 
	BULLETLIST::iterator bullet;

public:
	EnemyBulletManager();
	~EnemyBulletManager();

	void initialize(EnemyManager *enemyList);
	bool initializeBullet(Game *gamePtr, TextureManager *textureM, Gunner *gunner);
	void update(float frameTime, Game *gamePtr, TextureManager *textureM);
	void collisions(Entity *play);
	void render();
};