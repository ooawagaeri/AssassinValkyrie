// Module			: Gameplay Programming
// Assignment2		: Assassin Valkyrie
// Student Number	: Daniel Lee Min Qiang
// Student Number	: S10162739H

#include "verticalLoader.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

VerticalLoader::VerticalLoader()
{
}

bool VerticalLoader::initialize() {
	clear();
	return true;
}

void VerticalLoader::loadStage(int *i) {
	try {
		string fileName = to_string(*i);
		string line = "";
		ifstream stageFile(fileName + "-vertical.txt");
		if (stageFile.is_open()) {
			while (getline(stageFile, line)) {
				string type = line.substr(0, line.find('|'));
				int x = atoi(line.substr(line.find('|') + 1, line.find('-') - line.find('|')).c_str());
				int yStart = atoi(line.substr(line.find('-') + 1, line.find(',') - line.find('-')).c_str());
				int yEnd = atoi(line.substr(line.find(',') + 1, line.find('\n') - line.find(',')).c_str());
				verticalSpawn.push(verticalElement{ type, x, yStart, yEnd });
			}
		}
	}
	catch (...) {
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing vertical stage elements"));
	}
}

verticalElement VerticalLoader::getElement() {
	verticalElement pos = verticalSpawn.front();
	verticalSpawn.pop();
	return pos;
}

void VerticalLoader::clear() {
	//elementAdd = std::queue<string>();
	verticalSpawn = std::queue<verticalElement>();
}
