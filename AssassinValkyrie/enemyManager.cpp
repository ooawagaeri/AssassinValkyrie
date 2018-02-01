//  Module:             Gameplay Programming
//  Assignment1:        LET IT RAIN
//  Student Name:       Timothy Chua
//  Student Number:     10165581F

#include "enemyManager.h"
#include "leftFill.h"
#include "rightFill.h"
#include "alertState.h"
#include "returnState.h"

EnemyManager::EnemyManager()
{
	alertRange = 300;
}

EnemyManager::~EnemyManager()
{
	for (world = worldCollection.begin(); world != worldCollection.end(); ++world)
		SAFE_DELETE(*world);

	worldCollection.clear();
	trooperCollection.clear();
	gunnerCollection.clear();
	serpantCollection.clear();
}

bool EnemyManager::initialize(Game *gamePtr, TextureManager *textureTrooper, TextureManager *textureGunner, TextureManager *textureSerpant, TextureManager *textureHealth, Entity *play)
{
	bool isInitialised = true;		//verifies if all enemies are successfully generated

	for (VECTOR2 loc : trooperPos)
	{
		Trooper *t_temp = new Trooper(play);
		isInitialised = t_temp->initialize(gamePtr, trooperNS::WIDTH, trooperNS::HEIGHT, trooperNS::TEXTURE_COLS, textureTrooper, textureHealth);
		t_temp->setX(loc.x - trooperNS::WIDTH * trooperNS::SCALE / 2);
		t_temp->setY(loc.y - trooperNS::HEIGHT * trooperNS::SCALE);
		t_temp->setOriginalPos({ t_temp->getX(), t_temp->getY() });
		trooperCollection.emplace_back(t_temp);
		worldCollection.emplace_back(t_temp);
		if (!isInitialised)
			return isInitialised;
	}
	for (VECTOR2 loc : gunnerPos)
	{
		Gunner *t_temp = new Gunner(play);
		isInitialised = t_temp->initialize(gamePtr, gunnerNS::WIDTH, gunnerNS::HEIGHT, gunnerNS::TEXTURE_COLS, textureGunner, textureHealth);
		t_temp->setX(loc.x - gunnerNS::WIDTH * gunnerNS::SCALE / 2);
		t_temp->setY(loc.y - gunnerNS::HEIGHT * gunnerNS::SCALE);
		t_temp->setOriginalPos({ t_temp->getX(), t_temp->getY() });
		gunnerCollection.emplace_back(t_temp);
		worldCollection.emplace_back(t_temp);
		if (!isInitialised)
			return isInitialised;
	}
	for (VECTOR2 loc : serpantPos)
	{
		Serpant *t_temp = new Serpant(play);
		isInitialised = t_temp->initialize(gamePtr, serpantNS::WIDTH, serpantNS::HEIGHT, serpantNS::TEXTURE_COLS, textureSerpant, textureHealth);
		t_temp->setX(loc.x - serpantNS::WIDTH * serpantNS::SCALE / 2);
		t_temp->setY(loc.y - serpantNS::HEIGHT * serpantNS::SCALE);
		t_temp->setOriginalPos({ t_temp->getX(), t_temp->getY() });
		serpantCollection.emplace_back(t_temp);
		worldCollection.emplace_back(t_temp);
		if (!isInitialised)
			return isInitialised;
	}
	return isInitialised;
}

void EnemyManager::update(float frameTime, PLATFORM p)
{
	for ( Enemy *t : worldCollection)
		if (!t->outOfBounds())
			t->update(frameTime, p);
}

void EnemyManager::ai()
{
	std::vector<VECTOR2*> posAlertList;
	std::vector<Enemy*> posNotList;
	for (Enemy *t : worldCollection)
		if (!t->outOfBounds())
			if (AlertedState *a = dynamic_cast<AlertedState*>(t->getState()))
				posAlertList.emplace_back(&VECTOR2{ t->getCenterX(), t->getCenterY() });
			else
				posNotList.emplace_back(t);

	if (!posAlertList.empty())
		for (VECTOR2 *v1 : posAlertList)
			for (Enemy *v2 : posNotList)
			{
				VECTOR2 unit = *v1 - *v2->getCenter();
				if (D3DXVec2Length(&unit) < alertRange)
					v2->setState(new AlertedState());
			}
}

void EnemyManager::collisions(Entity *play, PLATFORM floor, PLATFORM fill)
{
	VECTOR2 collisionVector;

	world = worldCollection.begin();
	while (world != worldCollection.end())
	{
		if ((*world)->isAlive()) {
			if ((*world)->collidesWith(*play, collisionVector))
			{
				(*world)->getHealth()->damage(10);
			}
			world++;
		}
		else if ((*world)->outOfBounds())
			world++;
		else
			world = worldCollection.erase(world);
	}

	for (Enemy *t : worldCollection)
		if (!t->outOfBounds())
			unCollide(t, floor, fill);
}

void EnemyManager::unCollide(Enemy *t, PLATFORM floor, PLATFORM fill)
{
	VECTOR2 collisionVector;
	// Check floor collisions
	for (Entity *e : floor)
	{
		if (t->collidesWith(*e, collisionVector))
		{
			t->getMove()->setFloor(true);
			break;
		}
		else
			t->getMove()->setFloor(false);
	}
	// Check wall collisions
	bool collided = true;
	for (Entity *e : fill)
	{
		if (t->collidesWith(*e, VECTOR2{})) {
			if (AlertedState *a = dynamic_cast<AlertedState*>(t->getState()))
			{
				collided = false;
				break;
			}
			else
			{
				if (LeftFill *left = dynamic_cast<LeftFill*>(e))
					t->getMove()->setVelocity(-t->getMove()->getInitialVelocity());
				else if (RightFill *right = dynamic_cast<RightFill*>(e))
					t->getMove()->setVelocity(t->getMove()->getInitialVelocity());
				break;
			}
		}
	}
	t->getMove()->setEnable(collided);
}

void EnemyManager::render()
{
	for (Enemy *t : worldCollection)
		if (!t->outOfBounds())
			t->draw();
}

void EnemyManager::renderRay(Graphics *g)
{
	for (Enemy *t : worldCollection)
		if (!t->outOfBounds())
			t->drawRay(g);
}

void EnemyManager::camera(float frameTime, int direction) 
{
	for (Enemy *t : worldCollection)
		t->getMove()->movementWithDirection(frameTime, direction);
}
