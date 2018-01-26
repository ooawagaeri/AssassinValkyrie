// Module			: Gameplay Programming
// Assignment2		: Assassin Valkyrie
// Student Number	: Chua Wei Jie Timothy
// Student Number	: S10165581F

#ifndef _ATTACK_COMPONENT_H
#define _ATTACK_COMPONENT_H
#define WIN32_LEAN_AND_MEAN

#include "entity.h"

class AttackComponent
{
protected:
	int hitPoint;
	bool animationOn = false;
	Image *animation;

public:
	virtual void update(float frameTime) {};
	void draw(Entity *sd)
	{ 
		if (animationOn)
		{
			sd->setVisible(false);
			animation->draw(sd->getSpriteInfo());
		}
		else
			sd->setVisible(true);
	};
	void setAnimation(bool toggle) { animationOn = toggle; };
	bool getAnimation() { return animationOn; };
};

class ShootComponent : public AttackComponent
{
public:
	ShootComponent(Image *image) { hitPoint = 20; }
	virtual void update(float frameTime) {};
};
class MeleeComponent : public AttackComponent
{
public:
	MeleeComponent(Image *image) { hitPoint = 20; animation = image; }
	virtual void update(float frameTime)
	{
		if (animationOn)
		{
			animation->update(frameTime);
			if (animation->getAnimationComplete())
			{
				animationOn = false;
				animation->setAnimationComplete(false);
				return;
			}
		}
	};
};

#endif
