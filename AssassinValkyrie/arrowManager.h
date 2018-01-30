
#pragma once
#include <vector>
#include "arrow.h"

using std::vector;

typedef std::vector<Arrow *> ARROWLIST;

class ArrowManager
{

private:
	std::vector<Arrow *> arrow_collection;
	DWORD Tick;


public:
	ArrowManager();

	bool initialize(Game *gamePtr, int width, int height, int ncols,
		TextureManager *textureM, float X, float Y, Entity &player);
	void update(float frameTime, Input *input, Game *gamePtr, int width, int height, int ncols,
		TextureManager *textureM, float X, float Y, Entity &player);
	void ai();
	void render();

};