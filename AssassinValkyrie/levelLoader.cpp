// Module			: Gameplay Programming
// Assignment2		: Assassin Valkyrie
// Student Number	: Chua Wei Jie Timothy
// Student Number	: S10165581F

#include "levelLoader.h"

LevelLoader::LevelLoader()
{
}

bool LevelLoader::initializeStage(int i)
{
	string fileName = to_string(i);
	string line = "";
	//ifstream stageFile(fileName + "-map.txt")
	ifstream stageFile("map.txt");
	int countX = 0;
	int countY = 0;
	if (stageFile.is_open()) 
	{
		while (getline(stageFile, line)) 
		{
			string next;
			for (string::const_iterator it = line.begin(); it != line.end(); it++) 
			{
				if (*it == ' ') 
				{
					if (!next.empty()) 
					{
						layout[countY][countX] = next;
						countX++;
						next.clear();
					}
				}
				else
					next += *it;
			}
			if (!next.empty())
			{
				layout[countY][countX] = next;
				countX++;
			}
			countY++; countX = 0;
		}
	}
	return true;
}

string getType(string v)
{
	int i = stoi(v);
	switch (i)
	{
	case 1:
		return "FILL";
	case 2:
		return "FLOOR";
	case 3:
		return "LADDER";
	case 4:
		return "HIDEOUT";
	case 5:
		return "TROOPER";
	case 6:
		return "GUNNER";
	case 7:
		return "SERPANT";
	default:
		return "";
	}
}

void LevelLoader::loadElements()
{
	for (int y = 0; y < height; y++) 
		for (int x = 0; x < width; x++) 
		{
			string type = getType(layout[y][x]);
			if (type == "")
				continue;
			int posX = x * block_height;
			int posY = (height - y) * block_height;
			elementSpawn.push(horizontalElement2{ type, posX, posY});
		}
}

horizontalElement2 LevelLoader::getElement()
{
	horizontalElement2 pos = elementSpawn.front();
	elementSpawn.pop();
	return pos;
}

void LevelLoader::clear() 
{
	elementSpawn = std::queue<horizontalElement2>();
}