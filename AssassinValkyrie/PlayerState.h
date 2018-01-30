// Module			: Gameplay Programming
// Assignment2		: Assassin Valkyrie
// Student Number	: Zhuang yuteng
// Student Number	: S10163964C

#ifndef _PLAYER_STATE_H                // Prevent multiple definitions if this 
#define _PLAYER_STATE_H                // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "entity.h"
#include "stageGenerator.h"


class PlayerState
{
private:

public:
	PlayerState() {}
	~PlayerState() {}
	virtual PlayerState* handleInput(Entity &player, Input* input, Game *gamePtr, TextureManager *textureM, StageGenerator *floorList)=0;
	virtual void update(Entity &player, float frameTime)=0;

	

};//end of PlayerState class

#endif