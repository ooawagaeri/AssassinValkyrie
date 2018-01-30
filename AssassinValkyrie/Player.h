// Module			: Gameplay Programming
// Assignment2		: Assassin Valkyrie
// Student Number	: Zhuang yuteng
// Student Number	: S10163964C

#ifndef _PLAYER_H 
#define _PLAYER_H
#define WIN32_LEAN_AND_MEAN

#include "entity.h"
#include "constants.h"
#include "PlayerState.h"
#include "StandingState.h"
#include "enemyManager.h"
#include "stageGenerator.h"

namespace playerNS
{
	const int	HEALTH = 20;
	const int	WIDTH = 57.15;
	const int	HEIGHT = 96;
	const double ROTATION = 0;
	const float SCALE = 1.0f;
	const int	X = GAME_WIDTH / 4 ;
	const int	Y = GAME_HEIGHT/2-100 ;
	const float SPEED = 100;
	const float MASS = 300.0f;
	const int   TEXTURE_COLS = 1;
	const int   START_FRAME =0;
	const int   END_FRAME = 0;
	const float ANIMATION_DELAY = 0.5f;
}



class Player : public Entity
{
protected:
	
	PlayerState* state_;
	
public:
	// constructor
	Player();
	

	// inherited member functions
	bool initialize(Game *gamePtr, int width, int height, int ncols, TextureManager *textureM);
	void update(float frameTime, Game *gamePtr, TextureManager *textureM, StageGenerator *floorList);
	void handleInput(Input* input, Game *gamePtr, TextureManager *textureM);
	void ai(Entity &ship1, Entity &ship2);
	void collisions(EnemyManager *enemyList,StageGenerator *floorList);
	void draw();


};
#endif