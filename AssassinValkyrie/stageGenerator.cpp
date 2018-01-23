// Module			: Gameplay Programming
// Assignment2		: Assassin Valkyrie
// Student Number	: Daniel Lee Min Qiang
// Student Number	: S10162739H

#include "stageGenerator.h"
StageGenerator::StageGenerator() 
{
	stageLoad = new StageLoader();

}

bool StageGenerator::initialize(Game *gamePtr, TextureManager *textureM, int *stageNo) 
{
	bool success = true;
	stageLoad->clear();
	stageLoad->initialize();
	totalElements = stageLoad->elementSize();
	stageElement positionElement;
	for (int i = 0; i <= totalElements; i++)
	{
		if (!stageLoad->elementEmpty())
		{
			positionElement = stageLoad->getElement();
			if (positionElement.element == "FLOOR") {
				floorCollection.emplace_back(new Floor());
				int floorCount = (positionElement.xEnd - positionElement.xStart) / floorNS::WIDTH;
				if (floorCount = 0)
					floorCount = 1;
				for (int j = 0; i < floorCount; i++) {
					success = floorCollection.back()->initialize(gamePtr, floorNS::WIDTH, floorNS::HEIGHT, 0, textureM);
					floorCollection.back()->setX(positionElement.xStart + (floorNS::WIDTH * i));
					floorCollection.back()->setY(GAME_HEIGHT - floorNS::HEIGHT - positionElement.y);
				}
				if (!success)
					return success;
			}
		}
	}
	
}