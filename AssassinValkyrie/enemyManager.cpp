//  Module:             Gameplay Programming
//  Assignment1:        LET IT RAIN
//  Student Name:       Timothy Chua
//  Student Number:     10165581F

#include "enemyManager.h"

EnemyManager::EnemyManager()
{
}

bool EnemyManager::initialize(Game *gamePtr, TextureManager *textureM, Entity *play)
{
	bool isInitialised = true;		//verifies if all enemies are successfully generated

	for (int i = 0; i < trooperSize; i++)
	{
		Trooper *t_temp = new Trooper(play);
		isInitialised = t_temp->initialize(gamePtr, trooperNS::WIDTH, trooperNS::HEIGHT, trooperNS::TEXTURE_COLS, textureM);
		t_temp->setX(GAME_WIDTH / (i+1) - trooperNS::WIDTH * trooperNS::SCALE / 2);
		t_temp->setY(GAME_HEIGHT / 2 - trooperNS::HEIGHT * trooperNS::SCALE / 2);
		trooperCollection.emplace_back(t_temp);
	}
	return isInitialised;
}

void EnemyManager::update(float frameTime, PLATFORM p)
{
	for ( Trooper *t : trooperCollection)
		if (t->getActive())
			t->update(frameTime, p);
}

void EnemyManager::ai()
{
	for (Trooper *t : trooperCollection)
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
}