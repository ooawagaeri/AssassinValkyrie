//  Module:             Gameplay Programming
//  Assignment1:        LET IT RAIN
//  Student Name:       Timothy Chua
//  Student Number:     10165581F

#include "enemyManager.h"

EnemyManager::EnemyManager()
{
	trooperSize = 1;
	gunnerSize = 1;
	serpantSize = 1;
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

bool EnemyManager::initialize(Game *gamePtr, TextureManager *textureTrooper, TextureManager *textureGunner, TextureManager *textureSerpant, TextureManager *textureHealth, Entity *play)
{
	bool isInitialised = true;		//verifies if all enemies are successfully generated

	for (int i = 1; i <= trooperSize; i++)
	{
		Trooper *t_temp = new Trooper(play);
		isInitialised = t_temp->initialize(gamePtr, trooperNS::WIDTH, trooperNS::HEIGHT, trooperNS::TEXTURE_COLS, textureTrooper, textureHealth);
		t_temp->setX(3*GAME_WIDTH / 5 - trooperNS::WIDTH * trooperNS::SCALE / 2);
		t_temp->setY( GAME_HEIGHT - trooperNS::HEIGHT *2.5* trooperNS::SCALE);
		t_temp->setOriginalPos({ t_temp->getX(),t_temp->getY() });
		trooperCollection.emplace_back(t_temp);
		if (!isInitialised)
			return isInitialised;
	}
	for (int i = 1; i <= gunnerSize; i++)
	{
		Gunner *t_temp = new Gunner(play);
		isInitialised = t_temp->initialize(gamePtr, gunnerNS::WIDTH, gunnerNS::HEIGHT, gunnerNS::TEXTURE_COLS, textureGunner, textureHealth);
		t_temp->setX(GAME_WIDTH / (i+2) - gunnerNS::WIDTH * gunnerNS::SCALE / 2);
		t_temp->setY(GAME_HEIGHT - gunnerNS::HEIGHT * 2 * gunnerNS::SCALE);
		t_temp->setOriginalPos({ t_temp->getX(),t_temp->getY() });
		gunnerCollection.emplace_back(t_temp);
		if (!isInitialised)
			return isInitialised;
	}
	for (int i = 1; i <= serpantSize; i++)
	{
		Serpant *t_temp = new Serpant(play);
		isInitialised = t_temp->initialize(gamePtr, serpantNS::WIDTH, serpantNS::HEIGHT, serpantNS::TEXTURE_COLS, textureSerpant, textureHealth);
		t_temp->setX(3 * GAME_WIDTH / 5 - serpantNS::WIDTH * serpantNS::SCALE / 2);
		t_temp->setY(GAME_HEIGHT - serpantNS::HEIGHT *2.5* serpantNS::SCALE);
		t_temp->setOriginalPos({ t_temp->getX(),t_temp->getY() });
		serpantCollection.emplace_back(t_temp);
		if (!isInitialised)
			return isInitialised;
	}
	return isInitialised;
}

void EnemyManager::update(float frameTime, PLATFORM p)
{
	for ( Trooper *t : trooperCollection)
		if (t->isAlive())
			t->update(frameTime, p);

	for (Gunner *t : gunnerCollection)
		if (t->isAlive())
			t->update(frameTime, p);

	for (Serpant *t : serpantCollection)
		if (t->isAlive())
			t->update(frameTime, p);
}

void EnemyManager::ai()
{
	for (Trooper *t : trooperCollection)
		if (t->isAlive())
			t->ai();

	for (Gunner *t : gunnerCollection)
		if (t->isAlive())
			t->ai();

	for (Serpant *t : serpantCollection)
		if (t->isAlive())
			t->ai();
}

void EnemyManager::collisions(Entity *play)
{
	VECTOR2 collisionVector;

	trooper = trooperCollection.begin();
	while (trooper != trooperCollection.end())
	{
		if ((*trooper)->isAlive()) {
			if ((*trooper)->collidesWith(*play, collisionVector))
			{
				//(*trooper)->getHealth()->damage(10);
			}
			trooper++;
		}
		else
			trooper = trooperCollection.erase(trooper);
	}

	gunner = gunnerCollection.begin();
	while (gunner != gunnerCollection.end())
	{
		if ((*gunner)->isAlive()) {
			if ((*gunner)->collidesWith(*play, collisionVector))
			{
				//(*gunner)->getHealth()->damage(10);
			}
			gunner++;
		}
		else
			gunner = gunnerCollection.erase(gunner);
	}

	serpant = serpantCollection.begin();
	while (serpant != serpantCollection.end())
	{
		if ((*serpant)->isAlive()) {
			if ((*serpant)->collidesWith(*play, collisionVector))
			{
				//(*serpant)->getHealth()->damage(10);
			}
			serpant++;
		}
		else
			serpant = serpantCollection.erase(serpant);
	}
}

void EnemyManager::render(Graphics *g)
{
	for (Trooper *t : trooperCollection)
		if (t->isAlive())
			t->draw(g);

	for (Gunner *t : gunnerCollection)
		if (t->isAlive())
			t->draw(g);

	for (Serpant *t : serpantCollection)
		if (t->isAlive())
			t->draw(g);
}