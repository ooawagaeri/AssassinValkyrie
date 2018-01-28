// Module			: Gameplay Programming
// Assignment2		: Assassin Valkyrie
// Student Number	: Chua Wei Jit Timothy
// Student Number	: S10165581F

#include "assassinValkyrie.h"

// Constructor
AssassinValkyrie::AssassinValkyrie()
{ 
	ShowCursor(false);
	trooper1 = new Enemy();
	mouse = new Cursor();
	player = new Player();
	
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

	// Mouse
	if (!mouseTextures.initialize(graphics, MOUSE_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Enemy Textures"));

	if (!mouse->initialize(this, cursorNS::WIDTH, cursorNS::HEIGHT, cursorNS::TEXTURE_COLS, &mouseTextures))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing enemy trooper"));
	
	// Enemy
	if (!enemyTextures.initialize(graphics, ENEMY_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Enemy Textures"));
	
	if (!trooper1->initialize(this, trooperNS::WIDTH, trooperNS::HEIGHT, trooperNS::TEXTURE_COLS, &enemyTextures))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing enemy trooper"));

	// Player
	if (!playerTextures.initialize(graphics, PLAYER_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing player Textures"));

	if (!player->initialize(this, playerNS::WIDTH, playerNS::HEIGHT, playerNS::TEXTURE_COLS, &playerTextures))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing player"));

	
	
	

    return;
}

// Update all game items
void AssassinValkyrie::update()
{
	trooper1->update(frameTime);
	mouse->update();
	player->update(frameTime,this,&playerTextures);
	arrowList.update(frameTime, input, this, arrowNS::WIDTH, arrowNS::HEIGHT, arrowNS::ARROW_TEXTURE_COLS, &playerTextures, player->getX() + 20, player->getY(),*player);
}


// Artificial Intelligence
void AssassinValkyrie::ai()
{

}

// Handle collisions
void AssassinValkyrie::collisions()
{
    VECTOR2 collisionVector;
	mouse->collidesWith(*trooper1, collisionVector);
}

// Render game items
void AssassinValkyrie::render()
{
	trooper1->draw();
	mouse->draw();
	player->draw();
	arrowList.render();
}

// Release all reserved video memory so graphics device may be reset.
void AssassinValkyrie::releaseAll()
{
	SAFE_DELETE(mouse);
	SAFE_DELETE(trooper1);
	enemyTextures.onLostDevice();
	mouseTextures.onLostDevice();
	playerTextures.onLostDevice();
    Game::releaseAll();
    return;
}

// Recreate all surfaces.
void AssassinValkyrie::resetAll()
{
	enemyTextures.onResetDevice();
	mouseTextures.onLostDevice();
	playerTextures.onResetDevice();
    Game::resetAll();
    return;
}