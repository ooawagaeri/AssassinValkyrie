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
	bool attackOn = false;
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
	void draw(Entity *ent, COLOR_ARGB c)
	{ 
		if (animationOn)
		{
			ent->setVisible(false);
			animation->draw(ent->getSpriteInfo(), c);
		}
		else
			ent->setVisible(true);
	};
	virtual void setAnimation(bool toggle) { animationOn = toggle; attackOn = toggle; };
	void offAttack() { attackOn = false; }
	bool getAttack() { return attackOn; }
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
};

class MeleeComponent : public AttackComponent
{
public:
	MeleeComponent(Image *image) : AttackComponent(image)
	{
		hitPoint = 20;
	}
};

class FireComponent : public AttackComponent
{
public:
	int fireTimer;
	int maxTimeFire;
	FireComponent(Image *image) : AttackComponent(image)
	{
		hitPoint = 20;
		fireTimer = GetTickCount();
		maxTimeFire = 1000;
	}
	bool isFire() 
	{ 
		return (animation->getCurrentFrame() == 38);
	}
};

#endif
