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

bool StageGenerator::initialize(Game *gamePtr, TextureManager *textureM, int *stageNo, TextureManager *ladderTextures, EnemyManager *ent, TextureManager *pickupTextures)
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
				trooperPos.emplace_back(VECTOR2{ (float)horizontalElement2.x, GAME_HEIGHT - (float)horizontalElement2.y });
			else if (horizontalElement2.element == "GUNNER")
				gunnerPos.emplace_back(VECTOR2{ (float)horizontalElement2.x, GAME_HEIGHT - (float)horizontalElement2.y });
			else if (horizontalElement2.element == "SERPANT")
				serpantPos.emplace_back(VECTOR2{ (float)horizontalElement2.x, GAME_HEIGHT - (float)horizontalElement2.y });

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
			else if (horizontalElement2.element == "PICKUPHP")
			{
				hpCollection.emplace_back(new PickupHP());
				success = hpCollection.back()->initialize(gamePtr, pickupHPNS::WIDTH, pickupHPNS::HEIGHT, pickupHPNS::TEXTURE_COLS, pickupTextures);
				hpCollection.back()->setCurrentFrame(pickupHPNS::START_FRAME);
				hpCollection.back()->setY(GAME_HEIGHT - (pickupHPNS::HEIGHT) - horizontalElement2.y);
				hpCollection.back()->setStartY(GAME_HEIGHT - (pickupHPNS::HEIGHT) - horizontalElement2.y);
				hpCollection.back()->setCollisionType(entityNS::ROTATED_BOX);
				hpCollection.back()->setX(horizontalElement2.x + (pickupHPNS::WIDTH));
				hpCollection.back()->setStartX(horizontalElement2.x + pickupHPNS::WIDTH);
			}
			else if (horizontalElement2.element == "PICKUPARROW")
			{
				pickupArrowCollection.emplace_back(new PickupArrow());
				success = pickupArrowCollection.back()->initialize(gamePtr, pickupArrowNS::WIDTH, pickupArrowNS::HEIGHT, pickupArrowNS::TEXTURE_COLS, pickupTextures);
				pickupArrowCollection.back()->setCurrentFrame(pickupArrowNS::START_FRAME);
				pickupArrowCollection.back()->setY(GAME_HEIGHT - (pickupArrowNS::HEIGHT) - horizontalElement2.y);
				pickupArrowCollection.back()->setStartY(GAME_HEIGHT - (pickupArrowNS::HEIGHT) - horizontalElement2.y);
				pickupArrowCollection.back()->setCollisionType(entityNS::ROTATED_BOX);
				pickupArrowCollection.back()->setX(horizontalElement2.x + (pickupArrowNS::WIDTH));
				pickupArrowCollection.back()->setStartX(horizontalElement2.x + pickupArrowNS::WIDTH);
			}
			else if (horizontalElement2.element == "PICKUPSTONE")
			{
				pickupStoneCollection.emplace_back(new PickupStone());
				success = pickupStoneCollection.back()->initialize(gamePtr, pickupStoneNS::WIDTH, pickupStoneNS::HEIGHT, pickupStoneNS::TEXTURE_COLS, pickupTextures);
				pickupStoneCollection.back()->setCurrentFrame(pickupStoneNS::START_FRAME);
				pickupStoneCollection.back()->setY(GAME_HEIGHT - (pickupStoneNS::HEIGHT) - horizontalElement2.y);
				pickupStoneCollection.back()->setStartY(GAME_HEIGHT - (pickupStoneNS::HEIGHT) - horizontalElement2.y);
				pickupStoneCollection.back()->setCollisionType(entityNS::ROTATED_BOX);
				pickupStoneCollection.back()->setX(horizontalElement2.x + (pickupStoneNS::WIDTH));
				pickupStoneCollection.back()->setStartX(horizontalElement2.x + pickupStoneNS::WIDTH);
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

//bool StageGenerator::initialize(Game *gamePtr, TextureManager *textureM, int *stageNo, TextureManager *ladderTextures, EnemyManager *ent)
//{
//	bool success = true;
//	//stageLoad->clear();
//
//	stageHorizontalLoad->initialize();
//	stageHorizontalLoad->loadStage(stageNo);
//	totalElements = stageHorizontalLoad->elementSize();
//	horizontalElement horizontalElement;
//	for (int i = 0; i <= totalElements; i++)
//	{
//		if (!stageHorizontalLoad->elementEmpty())
//		{
//			horizontalElement = stageHorizontalLoad->getElement();
//			if (horizontalElement.element == "FLOOR") {
//				int count = (horizontalElement.xEnd - horizontalElement.xStart) / floorNS::WIDTH;
//				if (count == 0)
//					count = 1;
//				for (int j = 0; j < count; j++) {
//					floorCollection.emplace_back(new Floor());
//					success = floorCollection.back()->initialize(gamePtr, floorNS::WIDTH, floorNS::HEIGHT, 2, textureM);
//					floorCollection.back()->setCurrentFrame(0);
//					floorCollection.back()->setX(horizontalElement.xStart + (floorNS::WIDTH * j));
//					floorCollection.back()->setStartX(horizontalElement.xStart + (floorNS::WIDTH * j));
//					floorCollection.back()->setY(GAME_HEIGHT - floorNS::HEIGHT - horizontalElement.y);
//					floorCollection.back()->setStartY(GAME_HEIGHT - floorNS::HEIGHT - horizontalElement.y);
//					floorCollection.back()->setEdge(RECT{ (long)(-floorNS::WIDTH/2), (long)(-floorNS::HEIGHT/2), (long)(floorNS::WIDTH / 2), (long)(floorNS::HEIGHT/2)});
//					floorCollection.back()->setCollisionType(entityNS::ROTATED_BOX);
//				}
//				if (!success)
//					return success;
//			}
//			if (horizontalElement.element == "FILL") {
//				int count = (horizontalElement.xEnd - horizontalElement.xStart) / fillNS::WIDTH;
//				if (count == 0)
//					count = 1;
//				for (int j = 0; j < count; j++) {
//					fillCollection.emplace_back(new Fill());
//					success = fillCollection.back()->initialize(gamePtr, fillNS::WIDTH, fillNS::HEIGHT, 2, textureM);
//					fillCollection.back()->setCurrentFrame(1);
//					fillCollection.back()->setX(horizontalElement.xStart + (fillNS::WIDTH * j));
//					fillCollection.back()->setStartX(horizontalElement.xStart + (fillNS::WIDTH * j));
//					fillCollection.back()->setY(GAME_HEIGHT - fillNS::HEIGHT - horizontalElement.y);
//					fillCollection.back()->setStartY(GAME_HEIGHT - fillNS::HEIGHT - horizontalElement.y);
//					fillCollection.back()->setEdge(RECT{ (long)(-fillNS::WIDTH / 2), (long)(-fillNS::HEIGHT / 2), (long)(fillNS::WIDTH / 2), (long)(fillNS::HEIGHT / 2) });
//					fillCollection.back()->setCollisionType(entityNS::ROTATED_BOX);
//				}
//				if (!success)
//					return success;
//			}
//			if (horizontalElement.element == "HIDEOUT") {
//				int count = (horizontalElement.xEnd - horizontalElement.xStart) / hideoutNS::WIDTH;
//				if (count == 0)
//					count = 1;
//				for (int j = 0; j < count; j++) {
//					hideoutCollection.emplace_back(new Hideout());
//					success = hideoutCollection.back()->initialize(gamePtr, hideoutNS::WIDTH, hideoutNS::HEIGHT, 5, textureM);
//					hideoutCollection.back()->setCurrentFrame(4);
//					hideoutCollection.back()->setX(horizontalElement.xStart + (hideoutNS::WIDTH * j));
//					hideoutCollection.back()->setY(GAME_HEIGHT - hideoutNS::HEIGHT - horizontalElement.y);
//					hideoutCollection.back()->setEdge(RECT{ (long)(-hideoutNS::WIDTH / 2), (long)(-hideoutNS::HEIGHT / 2), (long)(hideoutNS::WIDTH / 2), (long)(hideoutNS::HEIGHT / 2) });
//					hideoutCollection.back()->setCollisionType(entityNS::ROTATED_BOX);
//				}
//				if (!success)
//					return success;
//			}
//			if (horizontalElement.element == "TROOPER")
//				trooperPos.emplace_back(VECTOR2{ (float)horizontalElement.xStart, GAME_HEIGHT - (float)horizontalElement.y });
//			if (horizontalElement.element == "GUNNER")
//				gunnerPos.emplace_back(VECTOR2{ (float)horizontalElement.xStart, GAME_HEIGHT - (float)horizontalElement.y });
//			if (horizontalElement.element == "SERPANT")
//				serpantPos.emplace_back(VECTOR2{ (float)horizontalElement.xStart, GAME_HEIGHT - (float)horizontalElement.y });
//			}
//		}
//	
//	ent->loadTrooper(trooperPos);
//	ent->loadGunner(gunnerPos);
//	ent->loadSerpant(serpantPos);
//
//	stageVerticalLoad->initialize();
//	stageVerticalLoad->loadStage(stageNo);
//	totalElements = stageVerticalLoad->elementSize();
//	verticalElement verticalElement;
//
//	for (int i = 0; i <= totalElements; i++)
//	{
//		if (!stageVerticalLoad->elementEmpty()) 
//		{
//			verticalElement = stageVerticalLoad->getElement();
//			if (verticalElement.element == "LADDER") {
//				int count = (verticalElement.yEnd - verticalElement.yStart) / ladderNS::HEIGHT_BTM;
//				if (count < 3)
//					count = 3;
//				for (int j = 0; j < count; j++) {
//					ladderCollection.emplace_back(new Ladder());
//					if (j == 0) {
//						success = ladderCollection.back()->initialize(gamePtr, ladderNS::WIDTH, ladderNS::HEIGHT_BTM, 3, ladderTextures);
//						ladderCollection.back()->setCurrentFrame(ladderNS::FRAME_BTM);
//						ladderCollection.back()->setY(GAME_HEIGHT - (ladderNS::HEIGHT_BTM) - verticalElement.yStart);
//						ladderCollection.back()->setStartY(GAME_HEIGHT - (ladderNS::HEIGHT_BTM) - verticalElement.yStart);
//					}
//					else if (j == (count - 1)) {
//						success = ladderCollection.back()->initialize(gamePtr, ladderNS::WIDTH, ladderNS::HEIGHT_TOP, 3, ladderTextures);
//						ladderCollection.back()->setCurrentFrame(ladderNS::FRAME_TOP);
//						ladderCollection.back()->setY(GAME_HEIGHT - (ladderNS::HEIGHT_BTM + (ladderNS::HEIGHT_MID * (j-1)) + ladderNS::HEIGHT_TOP) - verticalElement.yStart);
//						ladderCollection.back()->setStartY(GAME_HEIGHT - (ladderNS::HEIGHT_BTM + (ladderNS::HEIGHT_MID * (j - 1)) + ladderNS::HEIGHT_TOP) - verticalElement.yStart);
//					}
//					else {
//						success = ladderCollection.back()->initialize(gamePtr, ladderNS::WIDTH, ladderNS::HEIGHT_MID, 3, ladderTextures);
//						ladderCollection.back()->setCurrentFrame(ladderNS::FRAME_MID);
//						ladderCollection.back()->setY(GAME_HEIGHT - (ladderNS::HEIGHT_BTM + (ladderNS::HEIGHT_MID * j) ) - verticalElement.yStart);
//						ladderCollection.back()->setStartY(GAME_HEIGHT - (ladderNS::HEIGHT_BTM + (ladderNS::HEIGHT_MID * j)) - verticalElement.yStart);
//					}
//					ladderCollection.back()->setX(verticalElement.x + (ladderNS::WIDTH));
//					ladderCollection.back()->setStartX(verticalElement.x + ladderNS::WIDTH);
//				}
//				if (!success)
//					return success;
//			}
//		}
//	}
//}

void StageGenerator::render()
{
	for (Floor *t : floorCollection)
		if (!t->outOfBounds())
			t->draw();

	for (Fill *t : fillCollection)
		if (!t->outOfBounds())
			t->draw();

	for (Hideout *t : hideoutCollection)
		if (!t->outOfBounds())
			t->draw();

	for (Ladder *t : ladderCollection)
		if (!t->outOfBounds())
			t->draw();
	for (PickupHP *t : hpCollection)
		if (!t->outOfBounds())
			t->draw();
	for (PickupArrow *t : pickupArrowCollection)
		if (!t->outOfBounds())
			t->draw();
	for (PickupStone *t : pickupStoneCollection)
		if (!t->outOfBounds())
			t->draw();
}

void StageGenerator::update(float frametime, int direction, int leftrightupdown, bool moveOn)
{
	for(Floor *floor : floorCollection){
		switch (leftrightupdown) {
		case 1:
			(floor)->setX((floor)->getStartX() - 2560);
			break;
		case 2:
			(floor)->setX((floor)->getStartX());
			break;
		case 3:
			(floor)->setY((floor)->getStartY() + 1264);
			break;
		case 4:
			(floor)->setY((floor)->getStartY());
			break;
		}
		if (moveOn)
			(floor)->update(frametime, direction);
	}
	for (Fill *fill : fillCollection) {
		switch (leftrightupdown) {
		case 1:
			(fill)->setX((fill)->getStartX() - 2560);
			break;
		case 2:
			(fill)->setX((fill)->getStartX());
			break;
		case 3:
			(fill)->setY((fill)->getStartY() + 1264);
			break;
		case 4:
			(fill)->setY((fill)->getStartY());
			break;
		}
		if (moveOn)
			(fill)->update(frametime, direction);
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
	
	for (Ladder *ladder : ladderCollection) {
		switch (leftrightupdown) {
		case 1:
			(ladder)->setX((ladder)->getStartX() - 2560);
			break;
		case 2:
			(ladder)->setX((ladder)->getStartX());
			break;
		case 3:
			(ladder)->setY((ladder)->getStartY() + 1264);
			break;
		case 4:
			(ladder)->setY((ladder)->getStartY());
			break;
		}
		if (moveOn)
			(ladder)->update(frametime, direction);
	}

	for (PickupHP *hp : hpCollection) {
		switch (leftrightupdown) {
		case 1:
			(hp)->setX((hp)->getStartX() - 2560);
			break;
		case 2:
			(hp)->setX((hp)->getStartX());
			break;
		case 3:
			(hp)->setY((hp)->getStartY() + 1264);
			break;
		case 4:
			(hp)->setY((hp)->getStartY());
			break;
		}
		if (moveOn)
			(hp)->update(frametime, direction);
	}

	for (PickupArrow *arrow : pickupArrowCollection) {
		switch (leftrightupdown) {
		case 1:
			(arrow)->setX((arrow)->getStartX() - 2560);
			break;
		case 2:
			(arrow)->setX((arrow)->getStartX());
			break;
		case 3:
			(arrow)->setY((arrow)->getStartY() + 1264);
			break;
		case 4:
			(arrow)->setY((arrow)->getStartY());
			break;
		}
		if (moveOn)
			(arrow)->update(frametime, direction);
	}

	for (PickupStone *stone : pickupStoneCollection) {
		switch (leftrightupdown) {
		case 1:
			(stone)->setX((stone)->getStartX() - 2560);
			break;
		case 2:
			(stone)->setX((stone)->getStartX());
			break;
		case 3:
			(stone)->setY((stone)->getStartY() + 1264);
			break;
		case 4:
			(stone)->setY((stone)->getStartY());
			break;
		}
		if (moveOn)
			(stone)->update(frametime, direction);
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