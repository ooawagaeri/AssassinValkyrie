// Module			: Gameplay Programming
// Assignment2		: Assassin Valkyrie
// Student Number	: Chua Wei Jie Timothy
// Student Number	: S10165581F

#include "assassinValkyrie.h"

static PLATFORM pCollection;

// Constructor
AssassinValkyrie::AssassinValkyrie()
{
	ShowCursor(false);
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

	mouse = new Cursor();
	trooper1 = new Trooper(mouse);
	gunner1 = new Gunner(mouse);

	// Mouse
	if (!mouseTextures.initialize(graphics, MOUSE_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Enemy Textures"));

	if (!mouse->initialize(this, cursorNS::WIDTH, cursorNS::HEIGHT, cursorNS::TEXTURE_COLS, &mouseTextures))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing enemy trooper"));
	
	/////////////////////////////////////////
	//				Enemy
	/////////////////////////////////////////
	// Trooper
	if (!trooperTexture.initialize(graphics, ENEMY_TROOPER_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Enemy Textures"));
	
	if (!trooper1->initialize(this, trooperNS::WIDTH, trooperNS::HEIGHT, trooperNS::TEXTURE_COLS, &trooperTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing enemy trooper"));

	// Gunner
	if (!gunnerTexture.initialize(graphics, ENEMY_GUNNER_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Enemy Textures"));

	if (!gunner1->initialize(this, gunnerNS::WIDTH, gunnerNS::HEIGHT, gunnerNS::TEXTURE_COLS, &gunnerTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing enemy gunner"));

	// Bullet
	if (!bulletTextures.initialize(graphics, BULLET_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing weaspon texture"));

	Entity *e = new Entity();
	e->initialize(this, cursorNS::WIDTH, cursorNS::HEIGHT, cursorNS::TEXTURE_COLS, &mouseTextures);
	e->setX(GAME_WIDTH / 2);
	e->setY(GAME_HEIGHT / 3 + 60);
	e->setEdge(RECT{ (long)(-40), (long)(-40), (long)(40), (long)(40) });
	e->setCollisionType(entityNS::ROTATED_BOX);
	e->computeRotatedBox();
	pCollection.emplace_back(e);

	emList.initialize(this, &trooperTexture, mouse);

    return;
}

// Update all game items
void AssassinValkyrie::update()
{
	trooper1->update(frameTime, pCollection);
	gunner1->update(frameTime, pCollection);
	mouse->update();
	emList.update(frameTime, pCollection);
}

// Artificial Intelligence
void AssassinValkyrie::ai()
{
	trooper1->ai();
	gunner1->ai();
	emList.ai();
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
	trooper1->draw(graphics);
	gunner1->draw(graphics);
	mouse->draw();
	emList.render(graphics);

	for (const auto& point : pCollection)
		point->draw();
}

// Release all reserved video memory so graphics device may be reset.
void AssassinValkyrie::releaseAll()
{
	SAFE_DELETE(mouse);
	SAFE_DELETE(trooper1);
	SAFE_DELETE(gunner1);
	trooperTexture.onLostDevice();
	gunnerTexture.onLostDevice();
	bulletTextures.onLostDevice();
	mouseTextures.onLostDevice();
    Game::releaseAll();
    return;
}

// Recreate all surfaces.
void AssassinValkyrie::resetAll()
{
	trooperTexture.onResetDevice();
	gunnerTexture.onResetDevice();
	bulletTextures.onResetDevice();
	mouseTextures.onLostDevice();
    Game::resetAll();
    return;
}