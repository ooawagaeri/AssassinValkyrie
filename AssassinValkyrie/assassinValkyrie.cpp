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
	//mouse = new Cursor();
	background = new Background();
	stageGenerator = new StageGenerator();
	tempChar = new Hideout();
	currentStage = 1;
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
	//Background
	if (!backgroundTexture.initialize(graphics, BACKGROUND_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing background texture"));

	if (!background->initialize(this, backgroundNS::WIDTH, backgroundNS::HEIGHT, backgroundNS::TEXTURE_COLS, &backgroundTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing background"));
	
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

	if (!floorTexture.initialize(graphics, FLOOR_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initalizing floor texture"));

	if (!ladderTexture.initialize(graphics, LADDER_IMAGE))
		throw (GameError(gameErrorNS::FATAL_ERROR, "Error initializing ladder texture"));

	if (!stageGenerator->initialize(this, &floorTexture, &currentStage, &ladderTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing floor generation"));
	/*
	if (!tempChar->initialize(this, hideoutNS::WIDTH, hideoutNS::HEIGHT, 5, &floorTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing temp player placeholder"));


	tempChar->setCurrentFrame(4);
	tempChar->setY(576);
	*/
	return;
}

// Update all game items
void AssassinValkyrie::update()
{
	background->update(frameTime, tempChar, stageGenerator);
	//stageGenerator->update(frameTime);
	//tempChar->update(frameTime);
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
	background->draw();
	stageGenerator->render();
	//tempChar->draw();
	mouse->draw();
	emList.render(graphics);

	for (const auto& point : pCollection)
		point->draw();
}

// Release all reserved video memory so graphics device may be reset.
void AssassinValkyrie::releaseAll()
{
	SAFE_DELETE(mouse);
  //SAFE_DELETE(trooper1);
	SAFE_DELETE(background);
	emList.~EnemyManager();
	trooperTexture.onLostDevice();
	gunnerTexture.onLostDevice();
	bulletTextures.onLostDevice();
	mouseTextures.onLostDevice();
	backgroundTexture.onLostDevice();
	floorTexture.onLostDevice();
    Game::releaseAll();
    return;
}

// Recreate all surfaces.
void AssassinValkyrie::resetAll()
{

	mouseTextures.onResetDevice();
	backgroundTexture.onResetDevice();
	floorTexture.onResetDevice();
	trooperTexture.onResetDevice();
	gunnerTexture.onResetDevice();
	bulletTextures.onResetDevice();
    Game::resetAll();
    return;
}