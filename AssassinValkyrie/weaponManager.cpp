
#include "weaponManager.h"
#include "distractedState.h"

WeaponManager::WeaponManager()
{
	Tick = GetTickCount();
	Tick2 = GetTickCount();
}

bool WeaponManager::initializeArrow(Game *gamePtr, int width, int height, int ncols,
	TextureManager *textureM, float X, float Y, Entity &player)
{
	bool is_initialised_arrow = true;
	Arrow *arrow = arrow_collection.back();
	
	is_initialised_arrow = (arrow)->initialize(gamePtr, width, height, ncols, textureM);	
	(arrow)->setFrames(arrowNS::ARROW_START_FRAME, arrowNS::ARROW_END_FRAME);
	(arrow)->setCurrentFrame(arrowNS::ARROW_START_FRAME);
	

	if (player.isFlipHorizontal())
	{
		(arrow)->flipHorizontal(true);
		(arrow)->setVelocity(VECTOR2(-arrowNS::SPEED, arrowNS::SPEED));
		

	}

	else
	{
		(arrow)->flipHorizontal(false);
		(arrow)->setVelocity(VECTOR2(arrowNS::SPEED, arrowNS::SPEED));
		
	}

	(arrow)->setX(X);
	(arrow)->setY(Y);

	if (!is_initialised_arrow)
		return is_initialised_arrow;

	return is_initialised_arrow;

	
}

bool WeaponManager::initializeStone(Game *gamePtr, int width, int height, int ncols,
	TextureManager *textureM, float X, float Y, Entity &player)
{
	
	bool is_initialised_stone = true;
	Stone *stone = stone_collection.back();

	
	is_initialised_stone = (stone)->initialize(gamePtr, width, height, ncols, textureM);
	
	(stone)->setFrames(stoneNS::STONE_START_FRAME, stoneNS::STONE_END_FRAME);
	(stone)->setCurrentFrame(stoneNS::STONE_START_FRAME);

	if (player.isFlipHorizontal())
	{
		
		(stone)->setThrowingRight(false);

	}
	else
	{
	
		(stone)->setThrowingRight(true);

	}

	
	(stone)->setX(X);
	(stone)->setY(Y);


	if (!is_initialised_stone)
		return is_initialised_stone;

	return is_initialised_stone;


}


void WeaponManager::update(float frameTime, Input *input, Game *gamePtr, int width, int height, int arrowcols, int stonecols,
	TextureManager *textureM, float X, float Y, Entity &player)
{

	if (input->isKeyDown(RANGE_ATTACK_KEY))
	{
		if (GetTickCount() - Tick > 500)
		{
			Tick = GetTickCount();
			arrow_collection.push_back(new Arrow());
			initializeArrow(gamePtr, width, height, arrowcols, textureM, X, Y, player);

		}


	}

	else if (input->isKeyDown(DISTRACT_KEY) )
	{
		if (GetTickCount() - Tick2 > 500)
		{
			Tick2 = GetTickCount();
			stone_collection.push_back(new Stone());
			initializeStone(gamePtr, width, height,stonecols, textureM, X, Y, player);

		}
	}
	for (std::vector<Arrow *>::iterator arrow = arrow_collection.begin(); arrow < arrow_collection.end(); ++arrow)
	{
		(*arrow)->update(frameTime);
	}

	for (std::vector<Stone *>::iterator stone = stone_collection.begin(); stone < stone_collection.end(); ++stone)
	{
		(*stone)->update(frameTime);
	}


}

void WeaponManager::ai() {}


void WeaponManager::collisions(EnemyManager *enemyList, PLATFORM floor)
{
	VECTOR2 collisionVector;
	GUNNERLIST *gunnerCollection = enemyList->getGunners();

	ARROWLIST::iterator it = arrow_collection.begin();
	while (it != arrow_collection.end())
	{
		for (GUNNERLIST::iterator gunner = (gunnerCollection->begin()); gunner != gunnerCollection->end(); gunner++)
		{
			if ((*gunner)->collidesWith(**it, collisionVector))
			{

				(*it)->setVisible(false);
				(*it)->setActive(false);
				break;
			}
		}


		if (!(*it)->getActive())
			it = arrow_collection.erase(it);
		else
			it++;
	}

	STONELIST::iterator stone = stone_collection.begin();
	while (stone != stone_collection.end())
	{
		bool floorCollision = false;
		for (Entity *f : floor)
			if ((*stone)->collidesWith(*f, collisionVector))
			{
				floorCollision = true;
				break;
			}
		if (floorCollision)
		{
			vector<Enemy *> tempList;
			for (Enemy *e : *enemyList->getTroopers())
				tempList.emplace_back(e);
			for (Enemy *e : *enemyList->getGunners())
				tempList.emplace_back(e);
			for (Enemy *e : *enemyList->getSerpants())
				tempList.emplace_back(e);

			for (Enemy *e : tempList)
			{
				VECTOR2 unit = *e->getCenter() - *(*stone)->getCenter();
				if (D3DXVec2Length(&unit) < 400)	// Range of stone distraction
					e->setState(new DistractedState(*(*stone)->getCenter()));
			}
			stone = stone_collection.erase(stone);
		}
		else
			stone++;
	}
}

void WeaponManager::render()
{

	for (std::vector<Arrow *>::iterator it = arrow_collection.begin(); it < arrow_collection.end(); ++it)
	{

		(*it)->draw();

	}

	for (std::vector<Stone *>::iterator stone = stone_collection.begin(); stone <stone_collection.end(); ++stone)
	{

		(*stone)->draw();

	}
}