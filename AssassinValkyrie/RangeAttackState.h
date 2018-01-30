// Module			: Gameplay Programming
// Assignment2		: Assassin Valkyrie
// Student Number	: Zhuang yuteng
// Student Number	: S10163964C

#ifndef _RANGE_ATTACK_STATE_H                // Prevent multiple definitions if this 
#define _RANGE_ATTACK_STATE_H                // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

namespace RANGE_ATTACK_STATE
{
	const int	WIDTH = 79;
	const int	HEIGHT = 96;
	const int TEXTURE_COLS = 4;
	const int   START_FRAME = 20;
	const int   END_FRAME = 23;

}

#include "PlayerState.h"

class RangeAttackState : public PlayerState
{

private:


public:

	RangeAttackState() :PlayerState() {}
	~RangeAttackState() {}

	virtual PlayerState* handleInput(Entity &player, Input* input, Game *gamePtr, TextureManager *textureM);

	void update(Entity &player, float frameTime)
	{

	}
};
#endif