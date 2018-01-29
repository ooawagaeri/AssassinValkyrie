
#include "arrowManager.h"

ArrowManager::ArrowManager()
{
	Tick = GetTickCount();
}

bool ArrowManager::initialize(Game *gamePtr, int width, int height, int ncols,
	TextureManager *textureM, float X, float Y, Entity &player)
{
	bool is_initialised = true;		//this verifies if all ships are successfully generated
	Arrow *it = arrow_collection.back();

	is_initialised = (it)->initialize(gamePtr, width, height, ncols, textureM);
	(it)->setFrames(arrowNS::ARROW_START_FRAME,arrowNS::ARROW_END_FRAME);
	(it)->setCurrentFrame(arrowNS::ARROW_START_FRAME);

	if (player.isFlipHorizontal())
	{
		(it)->flipHorizontal(true);
		(it)->setVelocity(VECTOR2(-arrowNS::SPEED, arrowNS::SPEED));
		
	}

	else
	{
		(it)->flipHorizontal(false);
		(it)->setVelocity(VECTOR2(arrowNS::SPEED, arrowNS::SPEED));
		
	}

	(it)->setX(X);
	(it)->setY(Y);


	if (!is_initialised)
		return is_initialised;

	return is_initialised;
}

void ArrowManager::update(float frameTime, Input *input, Game *gamePtr, int width, int height, int ncols,
	TextureManager *textureM, float X, float Y, Entity &player)
{

	if (input->isKeyDown(RANGE_ATTACK_KEY))
	{
		if (GetTickCount() - Tick > 500)
		{
			Tick = GetTickCount();
			arrow_collection.push_back(new Arrow());
			initialize(gamePtr, width, height, ncols, textureM, X, Y,player);

		}


	}
	for (std::vector<Arrow *>::iterator it = arrow_collection.begin(); it < arrow_collection.end(); ++it)
	{
		(*it)->update(frameTime);
	}


}

void ArrowManager::ai() {}




void ArrowManager::render()
{

	for (std::vector<Arrow *>::iterator it = arrow_collection.begin(); it < arrow_collection.end(); ++it)
	{

		(*it)->draw();

	}
}