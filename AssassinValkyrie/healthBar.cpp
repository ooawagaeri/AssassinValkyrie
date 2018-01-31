// Module			: Gameplay Programming
// Assignment2		: Assassin Valkyrie
// Student Number	: Chua Wei Jie Timothy
// Student Number	: S10165581F

#include "healthBar.h"

bool Bar::initialize(Graphics *graphics, TextureManager *textureM, int total_health)
{
    try {
        Image::initialize(graphics, healthBarNS::WIDTH, healthBarNS::HEIGHT,
                          healthBarNS::TEXTURE_COLS, textureM);
        setCurrentFrame(healthBarNS::BAR_FRAME);
        spriteData.scale = healthBarNS::SCALE;
        originalHealth = total_health;
    }
    catch(...)
    {
        return false;
    }
    return true;
}

void Bar::update(float frameTime, VECTOR2 pos)
{
	spriteData.x = pos.x - healthBarNS::WIDTH / 2;
	spriteData.y = pos.y - healthBarNS::HEIGHT * 2;
}

void Bar::setSize(int health)
{
    if (health < 0)
        health = 0;
    else if(health > originalHealth)
		health = originalHealth;
	spriteData.rect.right = spriteData.rect.left + (LONG)(spriteData.width * health / originalHealth);
}
