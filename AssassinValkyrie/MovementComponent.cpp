
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

ProjectileMovement::ProjectileMovement(Entity* ent, Entity *play) : MovementComponent(ent)
{
	player = play;
	t = 0;

	VECTOR2 unit = *player->getCenter() - *object->getCenter();
	D3DXVec2Normalize(&velocity, &unit);
	velocity *= 500;
	timeInterval = (D3DXVec2Length(&unit) / velocity.x) / 50;
}
void ProjectileMovement::update(float frameTime)
{
	velocity.y += GRAVITY*t*frameTime;
	object->setX(object->getX() + velocity.x *frameTime);
	object->setY(object->getY() + velocity.y *frameTime);
	t += timeInterval;
}