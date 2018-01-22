// Module			: Gameplay Programming
// Assignment2		: Assassin Valkyrie
// Student Number	: Chua Wei Jit Timothy
// Student Number	: S10165581F

#include "assassinValkyrie.h"

// Constructor
AssassinValkyrie::AssassinValkyrie()
{ 
	trooper1 = new Enemy();
}

// Destructor
AssassinValkyrie::~AssassinValkyrie()
{
    releaseAll();
}

// Initializes the game
void AssassinValkyrie::initialize(Game &gamePtr, HWND *hwndM, HRESULT *hrM, LARGE_INTEGER *timeStartM, LARGE_INTEGER *timeEndM,
	LARGE_INTEGER *timerFreqM, float *frameTimeM)
{
	graphics = gamePtr.getGraphics();
	input = gamePtr.getInput();
	audio = gamePtr.getAudio();
	hwnd = *hwndM;
	hr = *hrM;
	timeStart = *timeStartM;
	timeEnd = *timeEndM;
	timerFreq = *timerFreqM;
	frameTime = *frameTimeM;
	
	if (!enemyTextures.initialize(graphics, ENEMY_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Enemy Textures"));
	
	if (!trooper1->initialize(this, trooperNS::WIDTH, trooperNS::HEIGHT, trooperNS::TEXTURE_COLS, &enemyTextures))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing enemy trooper"));

    return;
}

// Update all game items
void AssassinValkyrie::update()
{
	trooper1->update(frameTime);
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
	trooper1->draw();
}

// Release all reserved video memory so graphics device may be reset.
void AssassinValkyrie::releaseAll()
{
	enemyTextures.onLostDevice();
    Game::releaseAll();
    return;
}

// Recreate all surfaces.
void AssassinValkyrie::resetAll()
{
	enemyTextures.onResetDevice();
    Game::resetAll();
    return;
}