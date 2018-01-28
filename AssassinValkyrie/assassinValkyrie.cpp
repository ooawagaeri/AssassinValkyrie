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

	// Gunner
	if (!gunnerTexture.initialize(graphics, ENEMY_GUNNER_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Enemy Textures"));

	// Bullet
	if (!bulletTextures.initialize(graphics, BULLET_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing bullet texture"));

	Entity *e = new Entity();
	e->initialize(this, cursorNS::WIDTH, cursorNS::HEIGHT, cursorNS::TEXTURE_COLS, &mouseTextures);
	e->setX(GAME_WIDTH / 2);
	e->setY(GAME_HEIGHT / 3 + 60);
	e->setEdge(RECT{ (long)(-40), (long)(-40), (long)(40), (long)(40) });
	e->setCollisionType(entityNS::ROTATED_BOX);
	e->computeRotatedBox();
	pCollection.emplace_back(e);

	if (!emList.initialize(this, &trooperTexture, &gunnerTexture, mouse))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing enemies texture"));

    return;
}

// Update all game items
void AssassinValkyrie::update()
{
	mouse->update();
	emList.update(frameTime, pCollection);
}

// Artificial Intelligence
void AssassinValkyrie::ai()
{
	emList.ai();
}

// Handle collisions
void AssassinValkyrie::collisions()
{
    VECTOR2 collisionVector;
}

// Render game items
void AssassinValkyrie::render()
{
	mouse->draw();
	emList.render(graphics);

	for (const auto& point : pCollection)
		point->draw();
}

// Release all reserved video memory so graphics device may be reset.
void AssassinValkyrie::releaseAll()
{
	SAFE_DELETE(mouse);
	emList.~EnemyManager();
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