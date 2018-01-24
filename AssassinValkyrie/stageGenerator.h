// Module			: Gameplay Programming
// Assignment2		: Assassin Valkyrie
// Student Number	: Daniel Lee Min Qiang
// Student Number	: S10162739H

#include "stageLoader.h"
#include "floor.h"
#include "fill.h"
#include <queue>
#include <string>
#include <vector>

typedef std::vector<Floor *> FLOORS;
typedef std::vector<Fill *> FILLS;
//enum STAGEELEMENTS {FLOOR};

class StageGenerator
{
private:
	int currentStage;
	FLOORS floorCollection;
	FLOORS::iterator floor;

	FILLS fillCollection;
	FILLS::iterator fill;

	StageLoader *stageLoad;
	int totalElements;

public:
	StageGenerator();
	~StageGenerator();

	bool initialize(Game *gamePtr, TextureManager *textureM, int *stageNo);
	//void loadStage(int i);
	//void clearField();
	void render();
};