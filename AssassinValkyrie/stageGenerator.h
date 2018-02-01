// Module			: Gameplay Programming
// Assignment2		: Assassin Valkyrie
// Student Number	: Daniel Lee Min Qiang
// Student Number	: S10162739H
#ifndef _STAGEGENERATOR_H
#define _STAGEGENERATOR_H
#define WIN32_LEAN_AND_MEAN

#pragma once
#include "horizontalLoader.h"
#include "verticalLoader.h"
#include "levelLoader.h"
#include "floor.h"
#include "fill.h"
#include "hideout.h"
#include "ladder.h"
#include "enemyManager.h"
#include "pickupHP.h"
#include "pickupArrow.h"
#include "pickupStone.h"
#include <queue>
#include <string>
#include <vector>

typedef std::vector<Floor *> FLOORS;
typedef std::vector<Fill *> FILLS;
typedef std::vector<Hideout *> HIDEOUTS;
typedef std::vector<Ladder *> LADDERS;
typedef std::vector<PickupHP *> HPS;
typedef std::vector<PickupArrow *> PICKUPARROWS;
typedef std::vector<PickupStone *> PICKUPSTONES;
//enum STAGEELEMENTS {FLOOR};

class StageGenerator
{
private:
	int currentStage;
	FLOORS floorCollection;

	FILLS fillCollection;

	HIDEOUTS hideoutCollection;

	LADDERS ladderCollection;

	HPS hpCollection;

	PICKUPARROWS pickupArrowCollection;

	PICKUPSTONES pickupStoneCollection;

	HorizontalLoader *stageHorizontalLoad;
	VerticalLoader *stageVerticalLoad;
	LevelLoader level;

	POSITION	trooperPos;
	POSITION	gunnerPos;
	POSITION	serpantPos;

	int totalElements;
	bool edge;

public:
	StageGenerator();
	~StageGenerator();

	bool initialize(Game *gamePtr, TextureManager *textureM, int *stageNo, TextureManager *ladderTextures, EnemyManager *ent, TextureManager *pickupTextures);
	//void loadStage(int i);
	//void clearField();
	void render();
	void update(float frametime, int direction, int leftrightupdown, bool moveOn);

	PLATFORM getFillPlatforms();
	PLATFORM getFloorPlatforms();
	POSITION getTrooper() { return trooperPos; }
	FLOORS *getFloors() { return &floorCollection; }
	FILLS *getFills() { return &fillCollection; }

	HPS *getHP() { return &hpCollection; }
	PICKUPARROWS *getPickupArrows() { return &pickupArrowCollection; }
	PICKUPSTONES *getPickupStones() { return &pickupStoneCollection; }
};
#endif
