// Module			: Gameplay Programming
// Assignment2		: Assassin Valkyrie
// Student Number	: Daniel Lee Min Qiang
// Student Number	: S10162739H

#include "floor.h"
#include <queue>
#include <string>

struct stageElement {
	std::string element;
	int xStart;
	int xEnd;
	int y;
};

class StageLoader
{
private:
	int currentStage;
	std::queue<stageElement> elementSpawn;
	//::queue<std::string> elementAdd;
public:
	StageLoader();
	~StageLoader();

	bool initialize();
	void loadStage(int i);
	void clear();

	int elementSize() { return elementSpawn.size(); }
	bool elementEmpty() { return elementSpawn.empty(); }

	stageElement getElement();
};