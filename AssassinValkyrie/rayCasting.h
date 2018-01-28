// Module			: Gameplay Programming
// Assignment2		: Assassin Valkyrie
// Student Number	: Chua Wei Jie Timothy
// Student Number	: S10165581F

#ifndef _RAY_H
#define _RAY_H
#define WIN32_LEAN_AND_MEAN

#include <vector>
#include <queue>
#include <math.h>
#include "entity.h"
#include "constants.h"

typedef std::vector<Entity *> PLATFORM;
const COLOR_ARGB ALPHA10 = D3DCOLOR_ARGB(0, 255, 255, 255);  // AND with color to get 10% alpha

class Ray
{
private:
	float *x;
	float *y;
	float direction;
	float visibilityAngle;
	int viewDistance;
	int viewHeight;		// from center
	VECTOR2 pos;
	COLOR_ARGB color;
	std::queue<CUSTOMVERTEX> vision;

public:
	Ray();
	~Ray();

	void init(float *x, float *y, float angle, int dist, int height);
	VECTOR2 Ray::maxDist(VECTOR2 cast);
	VECTOR2 castRayVector(VECTOR2 target, const PLATFORM &walls);
	void updateVision(const PLATFORM &walls);
	void render(Graphics *g);
	bool inSight(VECTOR2 entity, const PLATFORM &walls);

	void setDirection(int d) 
	{
		if ( d > 0)
			direction = 0;
		else
			direction = PI;
	}
	void setColor(COLOR_ARGB c) { color = c; }
};
#endif