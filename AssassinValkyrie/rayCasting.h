// Module			: Gameplay Programming
// Assignment2		: Assassin Valkyrie
// Student Number	: Chua Wei Jit Timothy
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

class Ray
{
private:
	float *x;
	float *y;
	float *facing;
	float direction;
	float visibilityAngle;
	int viewDistance;
	VECTOR2 pos;
	std::queue<CUSTOMVERTEX> vision;

public:
	Ray();
	void init(float *x, float *y, float *direction, float angle, int dist);
	VECTOR2 Ray::maxDist(VECTOR2 cast);
	VECTOR2 castRayVector(VECTOR2 target, const PLATFORM &walls);
	void updateVision(const PLATFORM &walls);
	void render(Graphics *g);
};
#endif