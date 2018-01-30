// Module			: Gameplay Programming
// Assignment2		: Assassin Valkyrie
// Student Number	: Chua Wei Jie Timothy
// Student Number	: S10165581F

#ifndef _HEALTH_COMPONENT_H
#define _HEALTH_COMPONENT_H
#define WIN32_LEAN_AND_MEAN

#include "healthBar.h"

class HealthComponent
{
private:
	int curr_health;
	bool isAlive;
	Bar healthbar;

public:
	bool initialize(Graphics *graphics, TextureManager *textureM, int max) 
	{
		curr_health = max;
		isAlive = true;
		healthbar.initialize(graphics, textureM, max);
		return true;
	}
	void update(float frameTime, VECTOR2 pos)
	{
		healthbar.update(frameTime, pos);
	}
	void draw() 
	{ 
		healthbar.draw(graphicsNS::MAROON); 
	}
	void damage(int hitPoint) 
	{
		curr_health -= hitPoint;
		healthbar.setSize(curr_health);
		if (curr_health <= 0)
			isAlive = false;
	}
	bool getAlive() { return isAlive; }
};

#endif
