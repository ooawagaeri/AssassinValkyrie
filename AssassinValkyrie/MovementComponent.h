// Module			: Gameplay Programming
// Assignment2		: Assassin Valkyrie
// Student Number	: Chua Wei trooper Timothy
// Student Number	: S10165581F

#ifndef _MOVE_COMPONENT_H
#define _MOVE_COMPONENT_H
#define WIN32_LEAN_AND_MEAN

class MovementComponent
{
private:
	Entity *object;
	VECTOR2 origin;
	int initialVelocity = 0;
	int currentVelocity;

public:
	MovementComponent(Entity* ent)
	{
		object = ent;
	}

	void setVelocity(int speed) {
		if (initialVelocity == 0)
			initialVelocity = speed;
		currentVelocity = speed;
	}
	int getInitialVelocity() { return initialVelocity; }
	int getCurrentVelocity() { return currentVelocity; }
	void setOrigin(VECTOR2 pos) { origin = pos; }

	bool returnOrigin()
	{
		if (object->getCenter()->x > origin.x + 1)
			currentVelocity = -initialVelocity;
		else if (object->getCenter()->x < origin.x - 1)
			currentVelocity = initialVelocity;
		else
			return true;
		return false;
	}
	void update(float frameTime)
	{
		object->setX(object->getX() + currentVelocity *frameTime);
	}
};
#endif
