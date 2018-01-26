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

bool StageGenerator::initialize(Game *gamePtr, TextureManager *textureM, int *stageNo, TextureManager *ladderTextures) 
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
				}
				if (!success)
					return success;
			}
		}
	}
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
				if (count == 0)
					count = 1;
				for (int j = 0; j < count; j++) {
					ladderCollection.emplace_back(new Ladder());
					if (j == 0) {
						success = ladderCollection.back()->initialize(gamePtr, ladderNS::WIDTH, ladderNS::HEIGHT_BTM, 3, ladderTextures);
						ladderCollection.back()->setCurrentFrame(ladderNS::FRAME_BTM);
						ladderCollection.back()->setY(GAME_HEIGHT - (ladderNS::HEIGHT_BTM * (j+1)) - verticalElement.yStart);
					}
					else if (j == (count - 1)) {
						success = ladderCollection.back()->initialize(gamePtr, ladderNS::WIDTH, ladderNS::HEIGHT_TOP, 3, ladderTextures);
						ladderCollection.back()->setCurrentFrame(ladderNS::FRAME_TOP);
						ladderCollection.back()->setY(GAME_HEIGHT - (ladderNS::HEIGHT_TOP * (j+2)) - verticalElement.yStart);
					}
					else {
						success = ladderCollection.back()->initialize(gamePtr, ladderNS::WIDTH, ladderNS::HEIGHT_MID, 3, ladderTextures);
						ladderCollection.back()->setCurrentFrame(ladderNS::FRAME_MID);
						ladderCollection.back()->setY(GAME_HEIGHT - (ladderNS::HEIGHT_MID * (j+1)) - verticalElement.yStart);
					}
					ladderCollection.back()->setX(verticalElement.x + (ladderNS::WIDTH));
					//ladderCollection.back()->setStartX(verticalElement.x + (ladderNS::WIDTH * j));
					//ladderCollection.back()->setStartY(GAME_HEIGHT - (floorNS::HEIGHT * j) - verticalElement.yStart);
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
	/*
	for (hideout = hideoutCollection.begin(); hideout != hideoutCollection.end(); hideout++) {
		(*hideout)->update(frametime);
	}
	*/
	for (floor = floorCollection.begin(); floor != floorCollection.end(); floor++)
	{
		if (leftrightupdown == 1)
			(*floor)->setX((*floor)->getStartX() - 160);
		else if (leftrightupdown == 2)
			(*floor)->setX((*floor)->getStartX());
		else if (leftrightupdown == 3)
			(*floor)->setY((*floor)->getStartY() + 720);
		else if (leftrightupdown == 4)
			(*floor)->setY((*floor)->getStartY());

		if (moveOn)
			(*floor)->update(frametime, direction);
	}
	for (fill = fillCollection.begin(); fill != fillCollection.end(); fill++) {
		if (leftrightupdown == 1)
			(*fill)->setX((*fill)->getStartX() -160);
		else if (leftrightupdown == 2)
			((*fill)->setX((*fill)->getStartX()));
		else if (leftrightupdown == 3)
			(*fill)->setY((*fill)->getStartY() + 720);
		else if (leftrightupdown == 4)
			(*fill)->setY((*fill)->getStartY());
		if (moveOn)
			(*fill)->update(frametime, direction);
	}
}