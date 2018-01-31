//  Module:             Gameplay Programming
//  Assignment2:        LET IT RAIN
//  Student Name:       Timothy Chua
//  Student Number:     10165581F

#include "healthBar.h"

bool Bar::initialize(Graphics *graphics, TextureManager *textureM, int left, int top, float scale, int total_health)
{
    try {
        Image::initialize(graphics, healthBarNS::WIDTH, healthBarNS::HEIGHT,
                          healthBarNS::TEXTURE_COLS, textureM);
        setCurrentFrame(healthBarNS::BAR_FRAME);
        spriteData.x = (float)left - healthBarNS::WIDTH / 2;
        spriteData.y = (float)top;
        spriteData.scale = scale;

        originalHealth = total_health;
    }
    catch(...)
    {
        return false;
    }
    return true;
}

void Bar::setSize(int health)
{
    if (health < 0)
        health = 0;
    else if(health > originalHealth)
		health = originalHealth;
	spriteData.rect.right = spriteData.rect.left + (LONG)(spriteData.width * health / originalHealth);
}

