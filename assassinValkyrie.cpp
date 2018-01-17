// Module			: Gameplay Programming
// Assignment2		: Assassin Valkyrie
// Student Number	: Chua Wei Jit Timothy
// Student Number	: S10165581F

#include "assassinValkyrie.h"

// Constructor
AssassinValkyrie::AssassinValkyrie()
{ 
}

// Destructor
AssassinValkyrie::~AssassinValkyrie()
{
    releaseAll();
}

// Initializes the game
void AssassinValkyrie::initialize(HWND hwnd)
{
	Game::initialize(hwnd);

    return;
}

// Update all game items
void AssassinValkyrie::update()
{
	
}


// Artificial Intelligence
void AssassinValkyrie::ai()
{

}

// Handle collisions
void AssassinValkyrie::collisions()
{
    VECTOR2 collisionVector;
	
}

// Render game items
void AssassinValkyrie::render()
{

}

// Release all reserved video memory so graphics device may be reset.
void AssassinValkyrie::releaseAll()
{

    Game::releaseAll();
    return;
}

// Recreate all surfaces.
void AssassinValkyrie::resetAll()
{

    Game::resetAll();
    return;
}