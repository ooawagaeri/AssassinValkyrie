// Module			: Gameplay Programming
// Assignment2		: Assassin Valkyrie
// Student Number	: Daniel Lee Min Qiang
// Student Number	: S10162739H
#ifndef _STAGEGENERATOR_H 
#define _STAGEGENERATOR_H
#define WIN32_LEAN_AND_MEAN
#include "stageLoader.h"
#include "floor.h"
#include "fill.h"
#include "hideout.h"
#include <queue>
#include <string>
#include <vector>

typedef std::vector<Floor *> FLOORS;
typedef std::vector<Fill *> FILLS;
typedef std::vector<Hideout *> HIDEOUTS;
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

	StageLoader *stageLoad;
	int totalElements;
	bool edge;
public:
	StageGenerator();
	~StageGenerator();

	bool initialize(Game *gamePtr, TextureManager *textureM, int *stageNo);
	//void loadStage(int i);
	//void clearField();
	void render();
	void update(float frametime, bool moveOn);
};
#endif