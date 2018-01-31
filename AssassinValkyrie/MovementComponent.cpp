
#include "MovementComponent.h"

MovementComponent::MovementComponent(Entity* ent)
{
	object = ent;
};
void MovementComponent::setVelocity(int speed) {
	if (initialVelocity == 0)
		initialVelocity = speed;
	currentVelocity = speed;
};
void MovementComponent::update(float frameTime)
{
	object->setX(object->getX() + currentVelocity *frameTime);
};
void MovementComponent::movementWithDirection(float frameTime, int direction)
{
	if (direction == 1)
	{
		object->setX(object->getX() + MovementComponentNS::cameraVelocity *frameTime);
	}
	else if (direction == 2)
	{
		object->setX(object->getX() + (-MovementComponentNS::cameraVelocity) * frameTime);
	}
	else if (direction == 3)
	{
		object->setY(object->getY() + MovementComponentNS::cameraVelocity * frameTime);
	}
	else if (direction == 4)
	{
		object->setY(object->getY() + (-MovementComponentNS::cameraVelocity) * frameTime);
	}
}

PatrolMovement::PatrolMovement(Entity* ent) : MovementComponent(ent) {}
bool PatrolMovement::returnOrigin()
{
	if (object->getCenter()->x > origin.x + 1)
		currentVelocity = -initialVelocity;
	else if (object->getCenter()->x < origin.x - 1)
		currentVelocity = initialVelocity;
	else
		return true;
	return false;
}
void PatrolMovement::update(float frameTime)
{
	MovementComponent::update(frameTime);
	if (!onFloor)
		object->setY(object->getY() + GRAVITY / 2);
}

ProjectileMovement::ProjectileMovement(Entity *ent, Entity *play) : MovementComponent(ent)
{
	player = play;
	t = 0;
	initialized = false;
	angle = 50 * PI / 180;
}
void ProjectileMovement::update(float frameTime)
{
	if (velocity.x != (float)(currentVelocity * cos(angle)))
	{
		VECTOR2 unit = *player->getCenter() - *object->getCenter();
		velocity = { (float)(currentVelocity * cos(angle)), -(float)(currentVelocity * sin(angle)) };
		if (velocity.y > 0) velocity.y = -velocity.y;
		timeInterval = (unit.x / velocity.x) / 2;
		if (timeInterval < 0) 
			timeInterval = -timeInterval;
	}
	else
	{
		velocity.y += GRAVITY*t*frameTime;
		t = t + timeInterval;
		object->setX(object->getX() + velocity.x *frameTime);
		object->setY(object->getY() + velocity.y *frameTime);
		double rotate = atan2(velocity.y, velocity.x);
		object->setRadians(rotate);
		if (currentVelocity < 0)
			object->setRadians(rotate + PI);
	}
}
