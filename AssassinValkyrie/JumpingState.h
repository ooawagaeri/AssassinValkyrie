// Module			: Gameplay Programming
// Assignment2		: Assassin Valkyrie
// Student Number	: Zhuang yuteng
// Student Number	: S10163964C

#ifndef _JUMPINGING_STATE_H                // Prevent multiple definitions if this 
#define _JUMPINGING_STATE_H                // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

namespace JUMPING_STATE
{
	const int	WIDTH = 64;
	const int	HEIGHT = 95;
	const int TEXTURE_COLS = 14;
	const int   START_FRAME = 42;
	const int   END_FRAME = 55;

}

#include "PlayerState.h"
#include "graphics.h"

class JumpingState : public PlayerState
{

private:

	float velocityX = 150 * cos(45 * PI / 180);
	float velocityY = -(150 * sin(45 * PI / 180));
	float gravity = 9.81;
	float DestinationTime =2293 / velocityX;
	float TimeInterval = DestinationTime /150;
	float t = 0;
public:

	JumpingState() :PlayerState() {}
	~JumpingState() {}

	virtual PlayerState* handleInput(Player &player, Input* input, Game *gamePtr, TextureManager *textureM, StageGenerator *floorList, EnemyManager *enemyList, PLATFORM p, Audio *a);

	void update(Player &player, float frameTime)
	{
		
		velocityY += gravity*t*frameTime;
		player.setVelocityY(velocityY);
		if (player.getJumpRight())
		{

			player.setX(player.getX() + velocityX*frameTime);
			player.setY(player.getY() + velocityY*frameTime);
			t += TimeInterval;
			

		}

		else if (player.getJumpLeft())
		{
			player.setX(player.getX() - velocityX*frameTime);
			player.setY(player.getY() + velocityY*frameTime);
			t += TimeInterval;

		}



	}


};
#endif