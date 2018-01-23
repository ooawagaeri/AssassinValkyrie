// Module			: Gameplay Programming
// Assignment2		: Assassin Valkyrie
// Student Number	: Chua Wei Jie Timothy
// Student Number	: S10165581F

#ifndef _MOVE_COMPONENT_H
#define _MOVE_COMPONENT_H
#define WIN32_LEAN_AND_MEAN

class MovementComponent
{
private:
	Entity *object;

public:
	MovementComponent(Entity* ent)
	{
		object = ent;
	}
	void update(float frameTime)
	{
		object->setX(object->getX() + object->getVelocity().x *frameTime);
		object->setY(object->getY() + object->getVelocity().y *frameTime);
	}
};
#endif
