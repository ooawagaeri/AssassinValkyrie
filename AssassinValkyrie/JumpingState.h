// Module			: Gameplay Programming
// Assignment2		: Assassin Valkyrie
// Student Number	: Zhuang yuteng, Daniel Lee Min Qiang
// Student Number	: S10163964C

#ifndef _JUMPINGING_STATE_H                // Prevent multiple definitions if this 
#define _JUMPINGING_STATE_H                // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

namespace JUMPING_STATE
{
	const int	WIDTH = 65;
	const int	HEIGHT = 96;
	const int TEXTURE_COLS = 14;
	const int   START_FRAME = 42;
	const int   END_FRAME = 55;
	
}

#include "PlayerState.h"
#include "graphics.h"

class JumpingState : public PlayerState
{

private:
	//float animationTime = 0;
	//float initialX = 150;
	//float initialY = 150;
	//float velocityX = 0;
	//float velocityY = 0;
	float velocityX = 150*cos(45*PI/180);
	float velocityY = -(150*sin(45*PI/180));
	float gravity = 9.81;
	//float DestinationTime = 0;
	float DestinationTime = 500/velocityX;
	float TimeInterval = DestinationTime / 50;
	//float TimeInterval = 0;
	float t = 0;
	float startY;
	float currentX;
	float currentY;
	bool jumping = false;
public:

	JumpingState() :PlayerState() {
	}
	~JumpingState() {}

	virtual PlayerState* handleInput(Entity &player, Input* input, Game *gamePtr, TextureManager *textureM);

	void update(Entity &player, float frameTime)
	{
		player.setVelocityY(velocityY);
		velocityY += gravity*t*frameTime;

		if (player.getJumpRight())
		{
			if (!jumping) {
				startY = player.getY();
				jumping = true;
			}
			player.setX(player.getX() + velocityX*frameTime);
			player.setY(player.getY() + velocityY*frameTime);
			t += TimeInterval;
			if (velocityY > (velocityX * 2))
			{
				velocityY = -(150 * sin(45 * PI / 180));;
				player.setY(startY);
				t = 0;
				player.setJumpComplete(true);
				player.setJumpRight(false);
				jumping = false;
			}
		}
		else if (player.getJumpLeft())
		{
			if (!jumping) {
				startY = player.getY();
				jumping = true;
			}
			player.setX(player.getX() - velocityX*frameTime);
			player.setY(player.getY() + velocityY*frameTime);
			t += TimeInterval;
			if (velocityY > (velocityX * 2))
			{
				velocityY = -(150 * sin(45 * PI / 180));;
				player.setY(startY);
				t = 0;
				player.setJumpComplete(true);
				player.setJumpLeft(false);
				jumping = false;
			}
		}					
	}
};
#endif