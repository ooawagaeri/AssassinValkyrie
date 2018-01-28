//  Module:             Gameplay Programming
//  Assignment1:        LET IT RAIN
//  Student Name:       Timothy Chua
//  Student Number:     10165581F

#include "enemyManager.h"

EnemyManager::EnemyManager()
{
	trooperSize = 3;
	gunnerSize = 3;
}

EnemyManager::~EnemyManager()
{
	for (trooper = trooperCollection.begin(); trooper != trooperCollection.end(); ++trooper)
	{
		SAFE_DELETE(*trooper);
	}
	trooperCollection.clear();
	for (gunner = gunnerCollection.begin(); gunner != gunnerCollection.end(); ++gunner)
	{
		SAFE_DELETE(*gunner);
	}
	gunnerCollection.clear();
}

bool EnemyManager::initialize(Game *gamePtr, TextureManager *textureTrooper, TextureManager *textureGunner, Entity *play)
{
	bool isInitialised = true;		//verifies if all enemies are successfully generated

	for (int i = 1; i <= trooperSize + 1; i++)
	{
		Trooper *t_temp = new Trooper(play);
		isInitialised = t_temp->initialize(gamePtr, trooperNS::WIDTH, trooperNS::HEIGHT, trooperNS::TEXTURE_COLS, textureTrooper);
		t_temp->setX(GAME_WIDTH / i - trooperNS::WIDTH * trooperNS::SCALE / 2);
		t_temp->setY(GAME_HEIGHT / 2 - trooperNS::HEIGHT * trooperNS::SCALE);
		trooperCollection.emplace_back(t_temp);
	}
	for (int i = 1; i <= gunnerSize + 1; i++)
	{
		Gunner *t_temp = new Gunner(play);
		isInitialised = t_temp->initialize(gamePtr, gunnerNS::WIDTH, gunnerNS::HEIGHT, gunnerNS::TEXTURE_COLS, textureGunner);
		t_temp->setX(GAME_WIDTH / i - gunnerNS::WIDTH * gunnerNS::SCALE / 2);
		t_temp->setY(GAME_HEIGHT / 2 - gunnerNS::HEIGHT * gunnerNS::SCALE);
		gunnerCollection.emplace_back(t_temp);
	}
	return isInitialised;
}

void EnemyManager::update(float frameTime, PLATFORM p)
{
	for ( Trooper *t : trooperCollection)
		if (t->getActive())
			t->update(frameTime, p);

	for (Gunner *t : gunnerCollection)
		if (t->getActive())
			t->update(frameTime, p);
}

void EnemyManager::ai()
{
	for (Trooper *t : trooperCollection)
		if (t->getActive())
			t->ai();

	for (Gunner *t : gunnerCollection)
		if (t->getActive())
			t->ai();
}

void EnemyManager::collisions(Entity *play)
{
	VECTOR2 collisionVector;

	//trooper = trooperCollection.begin();
	//while (trooper != trooperCollection.end())
	//{
	//	if (trooper->getActive()) {
	//		if (trooper->collidesWith(*play, collisionVector))
	//		{
	//		}
	//		trooper++;
	//	}
	//	else
	//		trooper = trooperCollection.erase(trooper);
	//}
}

void EnemyManager::render(Graphics *g)
{
	for (Trooper *t : trooperCollection)
		if (t->getActive())
			t->draw(g);

	for (Gunner *t : gunnerCollection)
		if (t->getActive())
			t->draw(g);
}