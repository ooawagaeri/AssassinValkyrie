// Module			: Gameplay Programming
// Assignment2		: Assassin Valkyrie
// Student Number	: Chua Wei Jie Timothy
// Student Number	: S10165581F

#ifndef _HEALTHBAR_H
#define _HEALTHBAR_H
#define WIN32_LEAN_AND_MEAN

#include "image.h"
#include "entity.h"
#include "constants.h"

class Bar : public Image
{
private:
	int originalHealth;

public:
    bool initialize(Graphics *graphics, TextureManager *textureM, int total_health);
	void update(float frameTime, VECTOR2 pos);
	// Set Bar Size
    void setSize(int health);
};

#endif
