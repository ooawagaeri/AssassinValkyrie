// Module			: Gameplay Programming
// Assignment2		: Assassin Valkyrie
// Student Number	: Daniel Lee Min Qiang
// Student Number	: S10162739H
#ifndef _HORIZONTALLOADER_H 
#define _HORIZONTALLOADER_H
#define WIN32_LEAN_AND_MEAN
#include "gameError.h"
#include <queue>
#include <string>

struct horizontalElement {
	std::string element;
	int xStart;
	int xEnd;
	int y;
};

class HorizontalLoader
{
private:
	int currentStage;
	std::queue<horizontalElement> elementSpawn;
	//::queue<std::string> elementAdd;
public:
	HorizontalLoader();
	~HorizontalLoader();

	bool initialize();
	void loadStage(int *i);
	void clear();

	int elementSize() { return elementSpawn.size(); }
	bool elementEmpty() { return elementSpawn.empty(); }

	horizontalElement getElement();
};
#endif