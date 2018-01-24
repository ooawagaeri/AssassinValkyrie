// Module			: Gameplay Programming
// Assignment2		: Assassin Valkyrie
// Student Number	: Daniel Lee Min Qiang
// Student Number	: S10162739H

#include "stageLoader.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

StageLoader::StageLoader()
{
}

bool StageLoader::initialize() {
	clear();
	return true;
}

void StageLoader::loadStage(int *i) {
	try {
		string fileName = to_string(*i);
		string line = "";
		ifstream stageFile(fileName + ".txt");
		if (stageFile.is_open()) {
			while (getline(stageFile, line)) {
				string type = line.substr(0, line.find('|'));
				int xStart = atoi(line.substr(line.find('|')+1, line.find(',') - line.find('|')).c_str());
				int xEnd = atoi(line.substr(line.find(',') + 1, line.find('-') - line.find(',')).c_str());
				int y = atoi(line.substr(line.find('-')+1, line.find('\n') - line.find('-')).c_str());
				elementSpawn.push(stageElement{ type, xStart, xEnd, y });
			}
		}
	}
	catch (...){
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing stage"));
	}
}

stageElement StageLoader::getElement() {
	stageElement pos = elementSpawn.front();
	elementSpawn.pop();
	return pos;
}

void StageLoader::clear() {
	//elementAdd = std::queue<string>();
	elementSpawn = std::queue<stageElement>();
}