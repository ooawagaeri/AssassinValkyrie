// Module			: Gameplay Programming
// Assignment2		: Assassin Valkyrie
// Student Number	: Chua Wei Jie Timothy
// Student Number	: S10165581F

#ifndef _MAP_LOADER_H 
#define _MAP_LOADER_H
#define WIN32_LEAN_AND_MEAN

#include <queue>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int width = 60;
const int height = 31;
const int block_height = 64;

struct horizontalElement2 {
	string element;
	int x;
	int y;
};

class LevelLoader
{
private:
	string layout[height][width];
	std::queue<horizontalElement2> elementSpawn;

public:
	~LevelLoader();
	bool initializeStage(int i);
	void loadElements();

	horizontalElement2 getElement();
	int elementSize() { return elementSpawn.size(); }
	bool elementEmpty() { return elementSpawn.empty(); }
};
#endif