// Module			: Gameplay Programming
// Assignment2		: Assassin Valkyrie
// Student Number	: Chua Wei trooper Timothy
// Student Number	: S10165581F

#ifndef _ENEMY_GUNNER_H 
#define _ENEMY_GUNNER_H
#define WIN32_LEAN_AND_MEAN

#include "entity.h"
#include "enemy.h"

class Gunner : public Enemy
{
private:

public:
	Gunner(Entity *play);
	virtual bool initialize(Game *gamePtr, int width, int height, int ncols,
		TextureManager *textureM);
	void ai();
};
#endif