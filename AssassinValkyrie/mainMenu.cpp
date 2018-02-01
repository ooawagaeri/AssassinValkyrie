// Module			: Gameplay Programming
// Assignment2		: Assassin Valkyrie
// Student Number	: Chua Wei Jie Timothy
// Student Number	: S10165581F

#include "MainMenu.h"

MainMenu::MainMenu()
{
	cursor = new Cursor();
	assValk = new AssassinValkyrie();
	gameStart = false;
}

MainMenu::~MainMenu()
{
	ShowCursor(false);
	releaseAll();
}

void MainMenu::initialize(HWND hwnd)
{
	Game::initialize(hwnd);
	// Mouse
	if (!mouseTextures.initialize(graphics, MOUSE_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Enemy Textures"));

	if (!cursor->initialize(this, cursorNS::WIDTH, cursorNS::HEIGHT, cursorNS::TEXTURE_COLS, &mouseTextures))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing enemy trooper"));

	if (!mmBackgroundTexture.initialize(graphics, MMBACKGROUND_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Main Menu Background"));

	if (!mmBackground.initialize(graphics, 1280, 720, 1, &mmBackgroundTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Main Menu Background"));

	// Buttons Texture
	if (!buttonsTexture.initialize(graphics, BUTTON_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Buttons Texture"));

	// Start Button
	if (!startButton.initialize(graphics, buttonNS::BUTTON_WIDTH, buttonNS::BUTTON_HEIGHT, buttonNS::BUTTON_NCOLS, &buttonsTexture, cursor))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Start button"));
	startButton.setCurrentFrame(buttonNS::START_BUTTON_FRAME);
	startButton.setX(GAME_WIDTH/4 - ((startButton.getWidth()/2)*startButton.getScale()));
	startButton.setY(GAME_HEIGHT / 4);

	// Settings Button
	if (!settingsButton.initialize(graphics, buttonNS::BUTTON_WIDTH, buttonNS::BUTTON_HEIGHT, buttonNS::BUTTON_NCOLS, &buttonsTexture, cursor))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Settings button"));
	settingsButton.setCurrentFrame(buttonNS::SETTINGS_BUTTON_FRAME);
	settingsButton.setX(startButton.getX());
	settingsButton.setY(startButton.getY() + startButton.getHeight() + (5*startButton.getScale()));

	// Credits Button
	if (!creditsButton.initialize(graphics, buttonNS::BUTTON_WIDTH, buttonNS::BUTTON_HEIGHT, buttonNS::BUTTON_NCOLS, &buttonsTexture, cursor))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Credits button"));
	creditsButton.setCurrentFrame(buttonNS::CREDITS_BUTTON_FRAME);
	creditsButton.setX(settingsButton.getX());
	creditsButton.setY(settingsButton.getY() + settingsButton.getHeight() + (5 * settingsButton.getScale()));

	// Exit Button
	if (!exitButton.initialize(graphics, buttonNS::BUTTON_WIDTH, buttonNS::BUTTON_HEIGHT, buttonNS::BUTTON_NCOLS, &buttonsTexture, cursor))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Exit button"));
	exitButton.setCurrentFrame(buttonNS::EXIT_BUTTON_FRAME);
	exitButton.setX(creditsButton.getX());
	exitButton.setY(creditsButton.getY() + creditsButton.getHeight() + (5 * creditsButton.getScale()));

	// Resume Button
	if (!resumeButton.initialize(graphics, buttonNS::BUTTON_WIDTH, buttonNS::BUTTON_HEIGHT, buttonNS::BUTTON_NCOLS, &buttonsTexture, cursor))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Resume button"));
	resumeButton.setCurrentFrame(buttonNS::RESUME_BUTTON_FRAME);
	resumeButton.setX(GAME_WIDTH / 2 - buttonNS::BUTTON_WIDTH / 2);
	resumeButton.setY(GAME_HEIGHT / 3);

	if (!pauseTexture.initialize(graphics, PAUSE_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Pause"));

	if (!pauseButton.initialize(graphics, dashboardNS::PAUSE_WIDTH, dashboardNS::PAUSE_HEIGHT, dashboardNS::PAUSE_NCOLS, &pauseTexture, cursor))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing pause"));
	pauseButton.setCurrentFrame(dashboardNS::PAUSE_FRAME);
	pauseButton.setX(GAME_WIDTH - pauseButton.getWidth());
	pauseButton.setY(0);

	return;
}

void MainMenu::update()
{
	cursor->update();

	VECTOR2 collisionVector;

	if (!gameStart)
	{

		// Start Button
		//if (startButton.collidesWith(*cursor, collisionVector) && input->getMouseLButton())
		//if (input->isKeyDown(ENTER_KEY))
		//if(startButton.click() && input->getMouseLButton() )
		if(startButton.collideButton(*cursor) && input->getMouseLButton())
		{
			gameStart = true;
			assValk->initialize(*this, &hwnd, &hr, &timeStart, &timeEnd, &timerFreq, &frameTime, &paused, cursor);
		}

		// Exit Button
		if (input->isKeyDown(ESC_KEY) || (exitButton.collideButton(*cursor) && input->getMouseLButton()))
		{
			Game::exitGame();
		}


	}



	if (gameStart && !assValk->getPause())
	{
		if (pauseButton.collideButton(*cursor) && input->getMouseLButton())
			assValk->setPause(true);

		assValk->update();

	}


}

void MainMenu::ai()
{
	if (gameStart)
		assValk->ai();
}

void MainMenu::collisions()
{
	VECTOR2 collisionVector;
	if (!gameStart)
	{
		/*if (!startButton.collideButton(*cursor))
			startButton.collisions(buttonNS::START_BUTTON_FRAME, buttonNS::START_HOVER_BUTTON_FRAME);
		if (startButton.collideButton(*cursor))
			startButton.setCurrentFrame(buttonNS::START_BUTTON_FRAME);

		if (startButton.collidesWith(*cursor,collisionVector))
			startButton.collisions(buttonNS::START_BUTTON_FRAME, buttonNS::START_HOVER_BUTTON_FRAME);
		if (!startButton.collidesWith(*cursor, collisionVector))
			startButton.setCurrentFrame(buttonNS::START_BUTTON_FRAME);
		if (settingsButton.collidesWith(*cursor, collisionVector))
			settingsButton.collisions(buttonNS::SETTINGS_BUTTON_FRAME, buttonNS::SETTINGS_HOVER_BUTTON_FRAME);
		if (!settingsButton.collidesWith(*cursor, collisionVector))
			settingsButton.setCurrentFrame(buttonNS::SETTINGS_BUTTON_FRAME);
		if (creditsButton.collidesWith(*cursor, collisionVector))
			creditsButton.collisions(buttonNS::CREDITS_BUTTON_FRAME, buttonNS::CREDITS_HOVER_BUTTON_FRAME);
		if (!creditsButton.collidesWith(*cursor, collisionVector))
			creditsButton.setCurrentFrame(buttonNS::CREDITS_BUTTON_FRAME);
		if (exitButton.collidesWith(*cursor, collisionVector))
			exitButton.collisions(buttonNS::EXIT_BUTTON_FRAME, buttonNS::EXIT_HOVER_BUTTON_FRAME);
		if (!exitButton.collidesWith(*cursor, collisionVector))
			exitButton.setCurrentFrame(buttonNS::EXIT_BUTTON_FRAME);*/

		startButton.collisions(*cursor, buttonNS::START_BUTTON_FRAME, buttonNS::START_HOVER_BUTTON_FRAME);
		settingsButton.collisions(*cursor, buttonNS::SETTINGS_BUTTON_FRAME, buttonNS::SETTINGS_HOVER_BUTTON_FRAME);
		creditsButton.collisions(*cursor, buttonNS::CREDITS_BUTTON_FRAME, buttonNS::CREDITS_HOVER_BUTTON_FRAME);
		exitButton.collisions(*cursor, buttonNS::EXIT_BUTTON_FRAME, buttonNS::EXIT_HOVER_BUTTON_FRAME);


	}
	if (gameStart)
	{
		assValk->collisions();
		pauseButton.collisions(*cursor, dashboardNS::PAUSE_FRAME, dashboardNS::PAUSE_HOVER_FRAME);

	}
}

void MainMenu::render()
{
	graphics->spriteBegin();


	if (gameStart)
	{
		assValk->render();
		pauseButton.draw();
	}

	else
	{
		mmBackground.draw();
		startButton.draw();
		settingsButton.draw();
		creditsButton.draw();
		exitButton.draw();
	}

	cursor->draw();


	graphics->spriteEnd();
}

void MainMenu::releaseAll()
{
	if (gameStart)
		assValk->releaseAll();
	else
	{
		mmBackgroundTexture.onLostDevice();
		buttonsTexture.onLostDevice();

	}
	mouseTextures.onLostDevice();

}

void MainMenu::resetAll()
{
	if (gameStart)
		assValk->resetAll();
	else
	{
		mmBackgroundTexture.onResetDevice();
		buttonsTexture.onResetDevice();

	}
	mouseTextures.onResetDevice();

}
