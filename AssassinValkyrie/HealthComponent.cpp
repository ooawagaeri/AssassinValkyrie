// Module			: Gameplay Programming
// Assignment2		: Assassin Valkyrie
// Student Number	: Chua Wei Jie Timothy
// Student Number	: S10165581F

#include "healthComponent.h"

HealthComponent::HealthComponent(Image *image) { animation = image; }
bool HealthComponent::initialize(Graphics *graphics, TextureManager *textureM, int max)
{
	curr_health = max;
	isAlive = true;
	animationOn = false;
	isAnimating = 1;
	healthbar.initialize(graphics, textureM, max);
	return true;
}
void HealthComponent::update(float frameTime, VECTOR2 pos)
{
	healthbar.update(frameTime, pos);

	if (animationOn)
	{
		isAnimating = 2;
		animation->update(frameTime);
		if (animation->getAnimationComplete()) {
			isAnimating = 3;
		}
	}
}
void HealthComponent::draw(Entity *ent)
{
	healthbar.draw(graphicsNS::RED);
	if (damageColor != NULL && (GetTickCount() - damageTimer > 800))
		damageColor = NULL;
	if (animationOn)
	{
		ent->setVisible(false);
		animation->draw(ent->getSpriteInfo());
	}
}
void HealthComponent::damage(int hitPoint)
{
	curr_health -= hitPoint;
	healthbar.setSize(curr_health);
	if (curr_health <= 0)
	{
		animationOn = true;
		isAlive = false;
	}
	else
	{
		damageColor = graphicsNS::ORANGE;
		damageTimer = GetTickCount();
	}
}