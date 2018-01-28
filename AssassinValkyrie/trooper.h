// Module			: Gameplay Programming
// Assignment2		: Assassin Valkyrie
// Student Number	: Chua Wei Jie Timothy
// Student Number	: S10165581F

#ifndef _ENEMY_TROOPER_H 
#define _ENEMY_TROOPER_H
#define WIN32_LEAN_AND_MEAN

#include "entity.h"
#include "enemy.h"

class Trooper : public Enemy
{
private:

public:
	Trooper(Entity *play);
	virtual bool initialize(Game *gamePtr, int width, int height, int ncols,
		TextureManager *textureM);
	void ai();
};
#endif