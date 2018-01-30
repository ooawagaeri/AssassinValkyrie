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
#include <queue>
#include <string>
#include <vector>

typedef std::vector<Floor *> FLOORS;
typedef std::vector<Fill *> FILLS;
typedef std::vector<Hideout *> HIDEOUTS;
typedef std::vector<Ladder *> LADDERS;
//enum STAGEELEMENTS {FLOOR};

class StageGenerator
{
private:
	int currentStage;
	FLOORS floorCollection;
	FLOORS::iterator floor;

	FILLS fillCollection;
	FILLS::iterator fill;

	HIDEOUTS hideoutCollection;
	HIDEOUTS::iterator hideout;

	LADDERS ladderCollection;
	LADDERS::iterator ladder;

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

	bool initialize(Game *gamePtr, TextureManager *textureM, int *stageNo, TextureManager *ladderTextures, EnemyManager *ent);
	//void loadStage(int i);
	//void clearField();
	void render();
	void update(float frametime, int direction, int leftrightupdown, bool moveOn);

	PLATFORM getFillPlatforms();
	PLATFORM getFloorPlatforms();
	POSITION getTrooper() { return trooperPos; }
};
#endif