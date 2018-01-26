// Module			: Gameplay Programming
// Assignment2		: Assassin Valkyrie
// Student Number	: Daniel Lee Min Qiang
// Student Number	: S10162739H

#include "horizontalLoader.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

HorizontalLoader::HorizontalLoader()
{
}

bool HorizontalLoader::initialize() {
	clear();
	return true;
}

void HorizontalLoader::loadStage(int *i) {
	try {
		string fileName = to_string(*i);
		string line = "";
		ifstream stageFile(fileName + "-horizontal.txt");
		if (stageFile.is_open()) {
			while (getline(stageFile, line)) {
				string type = line.substr(0, line.find('|'));
				int xStart = atoi(line.substr(line.find('|')+1, line.find(',') - line.find('|')).c_str());
				int xEnd = atoi(line.substr(line.find(',') + 1, line.find('-') - line.find(',')).c_str());
				int y = atoi(line.substr(line.find('-')+1, line.find('\n') - line.find('-')).c_str());
				elementSpawn.push(horizontalElement{ type, xStart, xEnd, y });
			}
		}
	}
	catch (...){
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing horizontal stage elements"));
	}
}

horizontalElement HorizontalLoader::getElement() {
	horizontalElement pos = elementSpawn.front();
	elementSpawn.pop();
	return pos;
}

void HorizontalLoader::clear() {
	//elementAdd = std::queue<string>();
	elementSpawn = std::queue<horizontalElement>();
}
