// Module			: Gameplay Programming
// Assignment2		: Assassin Valkyrie
// Student Number	: Daniel Lee Min Qiang
// Student Number	: S10162739H

#include "stageGenerator.h"
StageGenerator::StageGenerator() 
{
	edge = true;
}

StageGenerator::~StageGenerator() 
{
	for (floor = floorCollection.begin(); floor != floorCollection.end(); ++floor)
		SAFE_DELETE(*floor);
	floorCollection.clear();

	for (fill = fillCollection.begin(); fill != fillCollection.end(); ++fill)
		SAFE_DELETE(*fill);
	fillCollection.clear();

	for (side = sideCollection.begin(); side != sideCollection.end(); ++side)
		SAFE_DELETE(*side);
	sideCollection.clear();

	for (hideout = hideoutCollection.begin(); hideout != hideoutCollection.end(); ++hideout)
		SAFE_DELETE(*hideout);
	hideoutCollection.clear();

	for (ladder = ladderCollection.begin(); ladder != ladderCollection.end(); ++ladder)
		SAFE_DELETE(*ladder);
	ladderCollection.clear();
}

bool StageGenerator::initialize(Game *gamePtr, TextureManager *textureM, int *stageNo, TextureManager *ladderTextures, EnemyManager *ent)
{
	bool success = true;
	
	level.initializeStage(*stageNo);
	level.loadElements();
	totalElements = level.elementSize();
	horizontalElement2 horizontalElement2;
	for (int i = 0; i <= totalElements; i++)
	{
		if (!level.elementEmpty())
		{
			horizontalElement2 = level.getElement();
			if (horizontalElement2.element == "FLOOR")
			{
				floorCollection.emplace_back(new Floor());
				success = floorCollection.back()->initialize(gamePtr, floorNS::WIDTH, floorNS::HEIGHT, 2, textureM);
				floorCollection.back()->setCurrentFrame(0);
				floorCollection.back()->setX(horizontalElement2.x);
				floorCollection.back()->setStartX(horizontalElement2.x);
				floorCollection.back()->setY(GAME_HEIGHT - horizontalElement2.y + block_height - floorNS::HEIGHT);
				floorCollection.back()->setStartY(GAME_HEIGHT - horizontalElement2.y + block_height - floorNS::HEIGHT);
				floorCollection.back()->setEdge(RECT{ (long)(-floorNS::WIDTH / 2), (long)(-floorNS::HEIGHT / 2), (long)(floorNS::WIDTH / 2), (long)(floorNS::HEIGHT / 2) });
				floorCollection.back()->setCollisionType(entityNS::ROTATED_BOX);
				if (!success)
					return success;
			}

			else if (horizontalElement2.element == "FILL")
			{
				fillCollection.emplace_back(new Fill());
				success = fillCollection.back()->initialize(gamePtr, fillNS::WIDTH, fillNS::HEIGHT, 2, textureM);
				fillCollection.back()->setCurrentFrame(1);
				fillCollection.back()->setX(horizontalElement2.x);
				fillCollection.back()->setStartX(horizontalElement2.x);
				fillCollection.back()->setY(GAME_HEIGHT - horizontalElement2.y);
				fillCollection.back()->setStartY(GAME_HEIGHT - horizontalElement2.y);
				fillCollection.back()->setEdge(RECT{ (long)(-fillNS::WIDTH / 2), (long)(-fillNS::HEIGHT / 2), (long)(fillNS::WIDTH / 2), (long)(fillNS::HEIGHT / 2) });
				fillCollection.back()->setCollisionType(entityNS::ROTATED_BOX);
				if (!success)
					return success;
			}

			else if (horizontalElement2.element == "LEFT")
			{
				sideCollection.emplace_back(new LeftFill());
				success = sideCollection.back()->initialize(gamePtr, fillNS::WIDTH, fillNS::HEIGHT, 3, textureM);
				sideCollection.back()->setCurrentFrame(2);
				sideCollection.back()->setX(horizontalElement2.x);
				sideCollection.back()->setStartX(horizontalElement2.x);
				sideCollection.back()->setY(GAME_HEIGHT - horizontalElement2.y);
				sideCollection.back()->setStartY(GAME_HEIGHT - horizontalElement2.y);
				sideCollection.back()->setEdge(RECT{ (long)(-fillNS::WIDTH / 2), (long)(-fillNS::HEIGHT / 2), (long)(fillNS::WIDTH / 2), (long)(fillNS::HEIGHT / 2) });
				sideCollection.back()->setCollisionType(entityNS::ROTATED_BOX);
				if (!success)
					return success;
			}

			else if (horizontalElement2.element == "RIGHT")
			{
				sideCollection.emplace_back(new RightFill());
				success = sideCollection.back()->initialize(gamePtr, fillNS::WIDTH, fillNS::HEIGHT, 4, textureM);
				sideCollection.back()->setCurrentFrame(3);
				sideCollection.back()->setX(horizontalElement2.x);
				sideCollection.back()->setStartX(horizontalElement2.x);
				sideCollection.back()->setY(GAME_HEIGHT - horizontalElement2.y);
				sideCollection.back()->setStartY(GAME_HEIGHT - horizontalElement2.y);
				sideCollection.back()->setEdge(RECT{ (long)(-fillNS::WIDTH / 2), (long)(-fillNS::HEIGHT / 2), (long)(fillNS::WIDTH / 2), (long)(fillNS::HEIGHT / 2) });
				sideCollection.back()->setCollisionType(entityNS::ROTATED_BOX);
				if (!success)
					return success;
			}

			else if (horizontalElement2.element == "HIDEOUT")
			{
				hideoutCollection.emplace_back(new Hideout());
				success = hideoutCollection.back()->initialize(gamePtr, hideoutNS::WIDTH, hideoutNS::HEIGHT, 2, textureM);
				hideoutCollection.back()->setCurrentFrame(4);
				hideoutCollection.back()->setX(horizontalElement2.x);
				hideoutCollection.back()->setStartX(horizontalElement2.x);
				hideoutCollection.back()->setY(GAME_HEIGHT - horizontalElement2.y);
				hideoutCollection.back()->setStartY(GAME_HEIGHT - horizontalElement2.y);
				hideoutCollection.back()->setEdge(RECT{ (long)(-hideoutNS::WIDTH / 2), (long)(-hideoutNS::HEIGHT / 2), (long)(hideoutNS::WIDTH / 2), (long)(hideoutNS::HEIGHT / 2) });
				hideoutCollection.back()->setCollisionType(entityNS::ROTATED_BOX);
				if (!success)
					return success;
			}

			else if (horizontalElement2.element == "TROOPER")
				trooperPos.emplace_back(VECTOR2{ (float)horizontalElement2.x + fillNS::WIDTH/2, GAME_HEIGHT - (float)horizontalElement2.y + fillNS::HEIGHT });
			else if (horizontalElement2.element == "GUNNER")
				gunnerPos.emplace_back(VECTOR2{ (float)horizontalElement2.x + fillNS::WIDTH / 2, GAME_HEIGHT - (float)horizontalElement2.y + fillNS::HEIGHT });
			else if (horizontalElement2.element == "SERPANT")
				serpantPos.emplace_back(VECTOR2{ (float)horizontalElement2.x + fillNS::WIDTH / 2, GAME_HEIGHT - (float)horizontalElement2.y + fillNS::HEIGHT });

			else if (horizontalElement2.element == "LADDER")
			{
				ladderCollection.emplace_back(new Ladder());
				success = ladderCollection.back()->initialize(gamePtr, ladderNS::WIDTH, ladderNS::HEIGHT_BTM, 3, ladderTextures);
				ladderCollection.back()->setCurrentFrame(ladderNS::FRAME_BTM);
				ladderCollection.back()->setY(GAME_HEIGHT - (ladderNS::HEIGHT_BTM) - horizontalElement2.y);
				ladderCollection.back()->setStartY(GAME_HEIGHT - (ladderNS::HEIGHT_BTM) - horizontalElement2.y);
				ladderCollection.back()->setCollisionType(entityNS::ROTATED_BOX);
				ladderCollection.back()->setX(horizontalElement2.x + (ladderNS::WIDTH));
				ladderCollection.back()->setStartX(horizontalElement2.x + ladderNS::WIDTH);
			}

		}

		ent->loadTrooper(trooperPos);
		ent->loadGunner(gunnerPos);
		ent->loadSerpant(serpantPos);
	}
	int firstX = 0;
	for (Ladder *t : ladderCollection)
	{
		if (firstX == 0)
		{
			t->setCurrentFrame(ladderNS::FRAME_TOP);
			firstX = t->getX();
			continue;
		}
		if (firstX == t->getX())
		{
			t->setCurrentFrame(ladderNS::FRAME_MID);
		} else
		{
			firstX = 0;
		}
	}
}

void StageGenerator::render()
{
	for (Floor *t : floorCollection)
		if (!t->outOfBounds())
			t->draw();

	for (Fill *t : fillCollection)
		if (!t->outOfBounds())
			t->draw();

	for (Fill *t : sideCollection)
		if (!t->outOfBounds())
			t->draw();

	for (Hideout *t : hideoutCollection)
		if (!t->outOfBounds())
			t->draw();

	for (Ladder *t : ladderCollection)
		if (!t->outOfBounds())
			t->draw();
}

void StageGenerator::update(float frametime, int direction, int leftrightupdown, bool moveOn)
{
	for (floor = floorCollection.begin(); floor != floorCollection.end(); floor++)
	{
		switch (leftrightupdown) {
		case 1:
			(*floor)->setX((*floor)->getStartX() - 2560);
			break;
		case 2:
			(*floor)->setX((*floor)->getStartX());
			break;
		case 3:
			(*floor)->setY((*floor)->getStartY() + 1264);
			break;
		case 4:
			(*floor)->setY((*floor)->getStartY());
			break;
		}
		if (moveOn)
			(*floor)->update(frametime, direction);
	}
	for (fill = fillCollection.begin(); fill != fillCollection.end(); fill++) {
		switch (leftrightupdown) {
		case 1:
			(*fill)->setX((*fill)->getStartX() - 2560);
			break;
		case 2:
			(*fill)->setX((*fill)->getStartX());
			break;
		case 3:
			(*fill)->setY((*fill)->getStartY() + 1264);
			break;
		case 4:
			(*fill)->setY((*fill)->getStartY());
			break;
		}
		if (moveOn)
			(*fill)->update(frametime, direction);
	}
	for (side = sideCollection.begin(); side != sideCollection.end(); side++) {
		switch (leftrightupdown) {
		case 1:
			(*side)->setX((*side)->getStartX() - 2560);
			break;
		case 2:
			(*side)->setX((*side)->getStartX());
			break;
		case 3:
			(*side)->setY((*side)->getStartY() + 1264);
			break;
		case 4:
			(*side)->setY((*side)->getStartY());
			break;
		}
		if (moveOn)
			(*side)->update(frametime, direction);
	}
	/* to be uncommented and fixed on hideout.cpp AFTER player is merged in
	for (hideout = hideoutCollection.begin(); hideout != hideoutCollection.end(); hideout++) {
		switch (leftrightupdown) {
		case 1:
			(*hideout)->setX((*hideout)->getStartX() - 160);
			break;
		case 2:
			((*hideout)->setX((*hideout)->getStartX()));
			break;
		case 3:
			(*hideout)->setY((*hideout)->getStartY() + 720);
			break;
		case 4:
			(*hideout)->setY((*hideout)->getStartY());
			break;
		}
		if (moveOn)
			(*hideout)->update(frametime, direction);
	}
	*/
	
	for (ladder = ladderCollection.begin(); ladder != ladderCollection.end(); ladder++) {
		switch (leftrightupdown) {
		case 1:
			(*ladder)->setX((*ladder)->getStartX() - 2560);
			break;
		case 2:
			(*ladder)->setX((*ladder)->getStartX());
			break;
		case 3:
			(*ladder)->setY((*ladder)->getStartY() + 1264);
			break;
		case 4:
			(*ladder)->setY((*ladder)->getStartY());
			break;
		}
		if (moveOn)
			(*ladder)->update(frametime, direction);
	}
}

PLATFORM StageGenerator::getVisionPlatforms()
{
	PLATFORM p;
	for (Entity *t : floorCollection)
		p.emplace_back(t);
	for (Entity *t : sideCollection)
		p.emplace_back(t);
	return p;
}

PLATFORM StageGenerator::getSidePlatforms()
{
	PLATFORM p;
	for (Entity *t : sideCollection)
		p.emplace_back(t);
	return p;
}

PLATFORM StageGenerator::getFloorPlatforms()
{
	PLATFORM p;
	for (Entity *t : floorCollection)
		p.emplace_back(t);
	return p;
}