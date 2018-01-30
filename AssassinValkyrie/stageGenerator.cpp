// Module			: Gameplay Programming
// Assignment2		: Assassin Valkyrie
// Student Number	: Daniel Lee Min Qiang
// Student Number	: S10162739H

#include "stageGenerator.h"
StageGenerator::StageGenerator() 
{
	stageHorizontalLoad = new HorizontalLoader();
	stageVerticalLoad = new VerticalLoader();
	edge = true;
}

bool StageGenerator::initialize(Game *gamePtr, TextureManager *textureM, int *stageNo, TextureManager *ladderTextures, EnemyManager *ent)
{
	bool success = true;
	//stageLoad->clear();

	stageHorizontalLoad->initialize();
	stageHorizontalLoad->loadStage(stageNo);
	totalElements = stageHorizontalLoad->elementSize();
	horizontalElement horizontalElement;
	for (int i = 0; i <= totalElements; i++)
	{
		if (!stageHorizontalLoad->elementEmpty())
		{
			horizontalElement = stageHorizontalLoad->getElement();
			if (horizontalElement.element == "FLOOR") {
				int count = (horizontalElement.xEnd - horizontalElement.xStart) / floorNS::WIDTH;
				if (count == 0)
					count = 1;
				for (int j = 0; j < count; j++) {
					floorCollection.emplace_back(new Floor());
					success = floorCollection.back()->initialize(gamePtr, floorNS::WIDTH, floorNS::HEIGHT, 2, textureM);
					floorCollection.back()->setCurrentFrame(0);
					floorCollection.back()->setX(horizontalElement.xStart + (floorNS::WIDTH * j));
					floorCollection.back()->setStartX(horizontalElement.xStart + (floorNS::WIDTH * j));
					floorCollection.back()->setY(GAME_HEIGHT - floorNS::HEIGHT - horizontalElement.y);
					floorCollection.back()->setStartY(GAME_HEIGHT - floorNS::HEIGHT - horizontalElement.y);
					floorCollection.back()->setEdge(RECT{ (long)(-floorNS::WIDTH/2), (long)(-floorNS::HEIGHT/2), (long)(floorNS::WIDTH / 2), (long)(floorNS::HEIGHT/2)});
					floorCollection.back()->setCollisionType(entityNS::ROTATED_BOX);
				}
				if (!success)
					return success;
			}
			if (horizontalElement.element == "FILL") {
				int count = (horizontalElement.xEnd - horizontalElement.xStart) / fillNS::WIDTH;
				if (count == 0)
					count = 1;
				for (int j = 0; j < count; j++) {
					fillCollection.emplace_back(new Fill());
					success = fillCollection.back()->initialize(gamePtr, fillNS::WIDTH, fillNS::HEIGHT, 2, textureM);
					fillCollection.back()->setCurrentFrame(1);
					fillCollection.back()->setX(horizontalElement.xStart + (fillNS::WIDTH * j));
					fillCollection.back()->setStartX(horizontalElement.xStart + (fillNS::WIDTH * j));
					fillCollection.back()->setY(GAME_HEIGHT - fillNS::HEIGHT - horizontalElement.y);
					fillCollection.back()->setStartY(GAME_HEIGHT - fillNS::HEIGHT - horizontalElement.y);
					fillCollection.back()->setEdge(RECT{ (long)(-fillNS::WIDTH / 2), (long)(-fillNS::HEIGHT / 2), (long)(fillNS::WIDTH / 2), (long)(fillNS::HEIGHT / 2) });
					fillCollection.back()->setCollisionType(entityNS::ROTATED_BOX);
				}
				if (!success)
					return success;
			}
			if (horizontalElement.element == "HIDEOUT") {
				int count = (horizontalElement.xEnd - horizontalElement.xStart) / hideoutNS::WIDTH;
				if (count == 0)
					count = 1;
				for (int j = 0; j < count; j++) {
					hideoutCollection.emplace_back(new Hideout());
					success = hideoutCollection.back()->initialize(gamePtr, hideoutNS::WIDTH, hideoutNS::HEIGHT, 5, textureM);
					hideoutCollection.back()->setCurrentFrame(4);
					hideoutCollection.back()->setX(horizontalElement.xStart + (hideoutNS::WIDTH * j));
					hideoutCollection.back()->setY(GAME_HEIGHT - hideoutNS::HEIGHT - horizontalElement.y);
					hideoutCollection.back()->setEdge(RECT{ (long)(-hideoutNS::WIDTH / 2), (long)(-hideoutNS::HEIGHT / 2), (long)(hideoutNS::WIDTH / 2), (long)(hideoutNS::HEIGHT / 2) });
					hideoutCollection.back()->setCollisionType(entityNS::ROTATED_BOX);
				}
				if (!success)
					return success;
			}
			if (horizontalElement.element == "TROOPER")
				trooperPos.emplace_back(VECTOR2{ (float)horizontalElement.xStart, GAME_HEIGHT - (float)horizontalElement.y });
			if (horizontalElement.element == "GUNNER")
				gunnerPos.emplace_back(VECTOR2{ (float)horizontalElement.xStart, GAME_HEIGHT - (float)horizontalElement.y });
			if (horizontalElement.element == "SERPANT")
				serpantPos.emplace_back(VECTOR2{ (float)horizontalElement.xStart, GAME_HEIGHT - (float)horizontalElement.y });
			}
		}
	
	ent->loadTrooper(trooperPos);
	ent->loadGunner(gunnerPos);
	ent->loadSerpant(serpantPos);

	stageVerticalLoad->initialize();
	stageVerticalLoad->loadStage(stageNo);
	totalElements = stageVerticalLoad->elementSize();
	verticalElement verticalElement;

	for (int i = 0; i <= totalElements; i++)
	{
		if (!stageVerticalLoad->elementEmpty()) 
		{
			verticalElement = stageVerticalLoad->getElement();
			if (verticalElement.element == "LADDER") {
				int count = (verticalElement.yEnd - verticalElement.yStart) / ladderNS::HEIGHT_BTM;
				if (count < 3)
					count = 3;
				for (int j = 0; j < count; j++) {
					ladderCollection.emplace_back(new Ladder());
					if (j == 0) {
						success = ladderCollection.back()->initialize(gamePtr, ladderNS::WIDTH, ladderNS::HEIGHT_BTM, 3, ladderTextures);
						ladderCollection.back()->setCurrentFrame(ladderNS::FRAME_BTM);
						ladderCollection.back()->setY(GAME_HEIGHT - (ladderNS::HEIGHT_BTM) - verticalElement.yStart);
						ladderCollection.back()->setStartY(GAME_HEIGHT - (ladderNS::HEIGHT_BTM) - verticalElement.yStart);
					}
					else if (j == (count - 1)) {
						success = ladderCollection.back()->initialize(gamePtr, ladderNS::WIDTH, ladderNS::HEIGHT_TOP, 3, ladderTextures);
						ladderCollection.back()->setCurrentFrame(ladderNS::FRAME_TOP);
						ladderCollection.back()->setY(GAME_HEIGHT - (ladderNS::HEIGHT_BTM + (ladderNS::HEIGHT_MID * (j-1)) + ladderNS::HEIGHT_TOP) - verticalElement.yStart);
						ladderCollection.back()->setStartY(GAME_HEIGHT - (ladderNS::HEIGHT_BTM + (ladderNS::HEIGHT_MID * (j - 1)) + ladderNS::HEIGHT_TOP) - verticalElement.yStart);
					}
					else {
						success = ladderCollection.back()->initialize(gamePtr, ladderNS::WIDTH, ladderNS::HEIGHT_MID, 3, ladderTextures);
						ladderCollection.back()->setCurrentFrame(ladderNS::FRAME_MID);
						ladderCollection.back()->setY(GAME_HEIGHT - (ladderNS::HEIGHT_BTM + (ladderNS::HEIGHT_MID * j) ) - verticalElement.yStart);
						ladderCollection.back()->setStartY(GAME_HEIGHT - (ladderNS::HEIGHT_BTM + (ladderNS::HEIGHT_MID * j)) - verticalElement.yStart);
					}
					ladderCollection.back()->setX(verticalElement.x + (ladderNS::WIDTH));
					ladderCollection.back()->setStartX(verticalElement.x + ladderNS::WIDTH);
				}
				if (!success)
					return success;
			}
		}
	}
}

void StageGenerator::render()
{
	for (floor = floorCollection.begin(); floor != floorCollection.end(); floor++)
	{
		(*floor)->draw();
	}
	for (fill = fillCollection.begin(); fill != fillCollection.end(); fill++) {
		(*fill)->draw();
	}
	for (hideout = hideoutCollection.begin(); hideout != hideoutCollection.end(); hideout++) {
		(*hideout)->draw();
	}
	for (ladder = ladderCollection.begin(); ladder != ladderCollection.end(); ladder++) {
		(*ladder)->draw();
	}
}

void StageGenerator::update(float frametime, int direction, int leftrightupdown, bool moveOn)
{
	for (floor = floorCollection.begin(); floor != floorCollection.end(); floor++)
	{
		switch (leftrightupdown) {
		case 1:
			(*floor)->setX((*floor)->getStartX() - 160);
			break;
		case 2:
			(*floor)->setX((*floor)->getStartX());
			break;
		case 3:
			(*floor)->setY((*floor)->getStartY() + 720);
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
			(*fill)->setX((*fill)->getStartX() - 160);
			break;
		case 2:
			(*fill)->setX((*fill)->getStartX());
			break;
		case 3:
			(*fill)->setY((*fill)->getStartY() + 720);
			break;
		case 4:
			(*fill)->setY((*fill)->getStartY());
			break;
		}
		if (moveOn)
			(*fill)->update(frametime, direction);
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
			(*ladder)->setX((*ladder)->getStartX() - 160);
			break;
		case 2:
			(*ladder)->setX((*ladder)->getStartX());
			break;
		case 3:
			(*ladder)->setY((*ladder)->getStartY() + 720);
			break;
		case 4:
			(*ladder)->setY((*ladder)->getStartY());
			break;
		}
		if (moveOn)
			(*ladder)->update(frametime, direction);
	}
}

PLATFORM StageGenerator::getFillPlatforms()
{
	PLATFORM p;
	for (Entity *t : fillCollection)
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