//  Module:             Gameplay Programming
//  Assignment1:        LET IT RAIN
//  Student Name:       Timothy Chua
//  Student Number:     10165581F

#pragma once
#include "bullet.h"
#include <vector>

typedef std::vector<Bullet> BULLETLIST;

class EnemyManager;

class EnemyBulletManager
{
private:
	Entity *player;
	EnemyManager *enemyList;
	BULLETLIST bulletList;
	BULLETLIST::iterator bullet;

public:
	EnemyBulletManager();

	bool initialize(EnemyManager *enemyList, Entity *play);
	void update(float frameTime);
	void collisions();
	void render();
};