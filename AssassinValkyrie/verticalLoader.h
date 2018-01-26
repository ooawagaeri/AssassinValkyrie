// Module			: Gameplay Programming
// Assignment2		: Assassin Valkyrie
// Student Number	: Daniel Lee Min Qiang
// Student Number	: S10162739H
#ifndef _VERTICALLOADER_H 
#define _VERTICALLOADER_H
#define WIN32_LEAN_AND_MEAN
#include "gameError.h"
#include <queue>
#include <string>

struct verticalElement {
	std::string element;
	int x;
	int yStart;
	int yEnd;
};

class VerticalLoader
{
private:
	int currentStage;
	std::queue<verticalElement> verticalSpawn;
	//::queue<std::string> elementAdd;
public:
	VerticalLoader();
	~VerticalLoader();

	bool initialize();
	void loadStage(int *i);
	void clear();

	int elementSize() { return verticalSpawn.size(); }
	bool elementEmpty() { return verticalSpawn.empty(); }

	verticalElement getElement();
};
#endif