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
	dashboard = new Dashboard();
	text = new TextDX();
	displayTimer = new TextDX();
	mins = 0;
	secs = 0;
	milliSec = 0;
}

// Destructor
AssassinValkyrie::~AssassinValkyrie()
{
    releaseAll();
}

// Initializes the game
void AssassinValkyrie::initialize(Game &gamePtr, HWND *hwndM, HRESULT *hrM, LARGE_INTEGER *timeStartM, LARGE_INTEGER *timeEndM,
	LARGE_INTEGER *timerFreqM, float *frameTimeM, bool *pausedM, Cursor *cursor)
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
	paused = *pausedM;
	mouse = cursor;

	/*
	// Mouse
	if (!mouseTextures.initialize(graphics, MOUSE_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Enemy Textures"));

	if (!mouse->initialize(this, cursorNS::WIDTH, cursorNS::HEIGHT, cursorNS::TEXTURE_COLS, &mouseTextures))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing enemy trooper"));*/
	
	// Enemy
	if (!enemyTextures.initialize(graphics, ENEMY_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Enemy Textures"));
	
	if (!trooper1->initialize(this, trooperNS::WIDTH, trooperNS::HEIGHT, trooperNS::TEXTURE_COLS, &enemyTextures))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing enemy trooper"));

	dashboard->initialize(graphics, mouse);

	if (!displayTimer->initialize(graphics, 30, false, false, "Spectre 007"))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Dashboard Text"));

	if (!text->initialize(graphics, 30, false, false, "Spectre 007"))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing text"));

    return;
}

// Update all game items
void AssassinValkyrie::update()
{
	milliSec++;
	if (milliSec >= FRAME_RATE)
	{
		secs++;
		milliSec = 0;
		if (secs >= 60)
		{
			mins++;
			secs = 0;
		}
	}

	trooper1->update(frameTime);
	//mouse->update();
	dashboard->update();

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
	//mouse->collidesWith(button, collisonVector);


}

// Render game items
void AssassinValkyrie::render()
{
	trooper1->draw();
	dashboard->draw();

	const int bufferSize = 20;
	static char buffer[bufferSize];

	// Timer text
	_snprintf(buffer, bufferSize, "Time \n %d : %02d", (int)mins, (int)secs);
	displayTimer->setFontColor(graphicsNS::WHITE);
	displayTimer->print(buffer, (GAME_WIDTH / 2) - 30, 0);
	//mouse->draw();
}

// Release all reserved video memory so graphics device may be reset.
void AssassinValkyrie::releaseAll()
{
	SAFE_DELETE(mouse);
	SAFE_DELETE(trooper1);
	SAFE_DELETE(dashboard);
	SAFE_DELETE(text);
	SAFE_DELETE(displayTimer);
	enemyTextures.onLostDevice();
	mouseTextures.onLostDevice();
    Game::releaseAll();
    return;
}

// Recreate all surfaces.
void AssassinValkyrie::resetAll()
{
	enemyTextures.onResetDevice();
	mouseTextures.onLostDevice();
    Game::resetAll();
    return;
}