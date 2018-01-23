// Module			: Gameplay Programming
// Assignment2		: Assassin Valkyrie
// Student Number	: Daniel Lee Min Qiang
// Student Number	: S10162739H

#include "stageLoader.h"
#include <queue>
#include <string>
#include <vector>

struct stageElement {
	std::string element;
	int xStart;
	int xEnd;
	int y;
};
typedef std::vector<Floor *> FLOORS;

//enum STAGEELEMENTS {FLOOR};

class StageGenerator
{
private:
	int currentStage;
	FLOORS floorCollection;
	FLOORS::iterator floor;
	StageLoader *stageLoad;
	int totalElements;

public:
	StageGenerator();
	~StageGenerator();

	bool initialize(Game *gamePtr, TextureManager *textureM, int *stageNo);
	void loadStage(int i);
	void clearField();
};