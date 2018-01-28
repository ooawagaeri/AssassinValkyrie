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
	AttackComponent(Image *image){ animation = image; }
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
	virtual void setAnimation(bool toggle) { animationOn = toggle; };
	bool getAnimation() { return animationOn; };
};

class ShootComponent : public AttackComponent
{
public:
	int shootTimer;
	int maxTimeShoot;
	ShootComponent(Image *image) : AttackComponent(image) 
	{ 
		hitPoint = 20; 
		shootTimer = GetTickCount();
		maxTimeShoot = 800;
	}
	void setAnimation(bool toggle) 
	{ 

		AttackComponent::setAnimation(toggle);
	};
};
class MeleeComponent : public AttackComponent
{
public:
	MeleeComponent(Image *image) : AttackComponent(image)
	{
		hitPoint = 20;
	}
};

#endif
