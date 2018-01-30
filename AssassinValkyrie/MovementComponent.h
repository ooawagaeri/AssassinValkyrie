// Module			: Gameplay Programming
// Assignment2		: Assassin Valkyrie
// Student Number	: Chua Wei Jie Timothy
// Student Number	: S10165581F

#ifndef _MOVE_COMPONENT_H
#define _MOVE_COMPONENT_H
#define WIN32_LEAN_AND_MEAN

class MovementComponent
{
protected:
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
	virtual void update(float frameTime)
	{
		object->setX(object->getX() + currentVelocity *frameTime);
	}
};

class PatrolMovement : public MovementComponent
{
private:
	bool onFloor;
	bool onFill;

public:
	PatrolMovement(Entity* ent) : MovementComponent(ent) {}
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
		MovementComponent::update(frameTime);
		if (!onFloor)
			object->setY(object->getY() + GRAVITY / 2);
	}
	void setFloor(bool value) { onFloor = value; }
	void setFill(bool value) { onFill = value; }
};

class ProjectileMovement : public MovementComponent
{
public:
	ProjectileMovement(Entity* ent) : MovementComponent(ent) {}
	void update(float frameTime)
	{
		object->setX(object->getX() + currentVelocity *frameTime);
	}
};

#endif
