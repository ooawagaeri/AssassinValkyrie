// Module			: Gameplay Programming
// Assignment2		: Assassin Valkyrie
// Student Number	: Chua Wei Jie Timothy
// Student Number	: S10165581F

#include "rayCasting.h"

Ray::Ray()
{
	color = graphicsNS::WHITE;
	direction = PI;
}

Ray::~Ray()
{
	std::queue<CUSTOMVERTEX> empty;
	std::swap(vision, empty);
}
void Ray::init(float *X, float *Y, float angle, int dist, int height)
{
	x = X; 	y = Y;
	visibilityAngle = angle;
	viewDistance = dist;
	viewHeight = height;
}

bool isLeft(VECTOR2 a, VECTOR2 b, VECTOR2 c) {
	return ((b.x - a.x)*(c.y - a.y) - (b.y - a.y)*(c.x - a.x)) > 0;
}

float normalizeAngle(float value)
{
	if (value < 0)
		value += 2 * PI;
	return value;
}
double Dot(const VECTOR2& a, const VECTOR2& b) { return (a.x*b.x) + (a.y*b.y); }
double PerpDot(const VECTOR2& a, const VECTOR2& b) { return (a.y*b.x) - (a.x*b.y); }

bool lineCollision(VECTOR2& A1, VECTOR2& A2, VECTOR2& B1, VECTOR2& B2, double* out = 0)
{
	VECTOR2 a(A2 - A1);
	VECTOR2 b(B2 - B1);

	double f = PerpDot(a, b);
	if (!f)      // lines are parallel
		return false;

	VECTOR2 c(B2 - A2);
	double aa = PerpDot(a, c);
	double bb = PerpDot(b, c);

	if (f < 0)
	{
		if (aa > 0)     return false;
		if (bb > 0)     return false;
		if (aa < f)     return false;
		if (bb < f)     return false;
	}
	else
	{
		if (aa < 0)     return false;
		if (bb < 0)     return false;
		if (aa > f)     return false;
		if (bb > f)     return false;
	}

	if (out)
		*out = 1.0 - (aa / f);
	return true;
}

VECTOR2 Ray::maxDist(VECTOR2 cast)
{
	VECTOR2 unit = cast - pos;
	if (D3DXVec2Length(&unit) > viewDistance)
	{
		unit = *D3DXVec2Normalize(&unit, &unit) * viewDistance + pos;
		return unit;
	}
	return cast;
}

VECTOR2 Ray::castRayVector(VECTOR2 target, const PLATFORM &walls) {
	double out = 100000;
	double check = 0;
	VECTOR2 intersect{ -(float)out,-(float)out };
	VECTOR2 prev{ -1,-1 };
	for (const auto &wall : walls) {
		for (size_t i = 0; i < 4; ++i) {
			VECTOR2 B1 = { *wall->getCorner(i) };
			VECTOR2 B2 = { *wall->getCorner((i + 1) % 4) };
			if (lineCollision(target, pos, B1, B2, &check))
			{
				VECTOR2 t = ((B2 - B1) * check) + B1;
				if ((check < out && check != 0) || (D3DXVec2Length(&VECTOR2{ t.x - pos.x, t.y - pos.y }) < D3DXVec2Length(&VECTOR2{ intersect.x - pos.x, intersect.y - pos.y })))
				{
					out = check;
					prev = intersect;
					intersect = ((B2 - B1) * out) + B1;
				}
			}
			if (prev != VECTOR2{-1,-1} && D3DXVec2Length(&VECTOR2{ prev.x - pos.x, prev.y - pos.y }) < D3DXVec2Length(&VECTOR2{ intersect.x - pos.x, intersect.y - pos.y }))
				intersect = prev;
		}
	}
	if (intersect == VECTOR2{ -100000 ,-100000 })
		return maxDist(target);
	return maxDist(intersect);
}

void Ray::updateVision(const PLATFORM &walls)
{
	pos = { *x, *y - viewHeight };

	// first, let's get all the vertices of all the walls

	std::vector<VECTOR2> points;
	for (const auto &wall : walls)
	{
		for (size_t i = 0; i < 4; ++i)
			points.push_back(*wall->getCorner(i));
	}

	int d = 100000;
	float range1Angle = direction + visibilityAngle;
	float range2Angle = direction - visibilityAngle;

	VECTOR2 range1 = VECTOR2{ cos(range1Angle), sin(range1Angle) } *d;
	VECTOR2 range2 = VECTOR2{ cos(range2Angle), sin(range2Angle) } *d;

	std::vector<VECTOR2> visPoints;

	for (const auto& point : points) {
		float angle = atan2(point.y - pos.y, point.x - pos.x);

		bool c1 = isLeft(pos, range1, point);
		bool c2 = isLeft(pos, range2, point);

		if (!(!c1 && c2))
			continue;

		VECTOR2 rayVector = VECTOR2{ cos(angle + 0.0001f), sin(angle + 0.0001f) } *d;
		visPoints.push_back(castRayVector(rayVector, walls));

		rayVector = VECTOR2{ cos(angle - 0.0001f), sin(angle - 0.0001f) } *d;
		visPoints.push_back(castRayVector(rayVector, walls));

		rayVector = VECTOR2{ cos(angle), sin(angle) } *d;
		visPoints.push_back(castRayVector(rayVector, walls));
	}

	visPoints.push_back(castRayVector(range1, walls));
	visPoints.push_back(castRayVector(range2, walls));

	 //sort the points based on their angle
	std::sort(visPoints.begin(), visPoints.end(),
		[&](const VECTOR2 &p1, const VECTOR2 &p2) {
		return normalizeAngle(atan2(p2.y - pos.y, p2.x - pos.x)) > normalizeAngle(atan2(p1.y - pos.y, p1.x - pos.x));
	});
	
	// Iterator of visPoints 
	std::vector<VECTOR2>::iterator it_visPoints;

	// Vision is used for actual rendering
	it_visPoints = visPoints.begin();
	while (it_visPoints != visPoints.end())
	{
		vision.push({ pos.x, pos.y, 0.5f, 1.0f, color  });
		vision.push({ it_visPoints->x, it_visPoints->y,0.5f,1.0f, color  & ALPHA10 });
		it_visPoints++;
		if (it_visPoints != visPoints.end())
			vision.push({ it_visPoints->x, it_visPoints->y,0.5f,1.0f, color  &  ALPHA10 });
		else
		{
			it_visPoints = visPoints.begin();
			vision.push({ it_visPoints->x, it_visPoints->y,0.5f,1.0f, color  & ALPHA10 });
			break;
		}
	}
}

void Ray::render(Graphics *g)
{
	if (vision.size() >= 3)
	{
		for (int i = 0; i < vision.size()/3; i++)
			g->initGraphics(&vision);
	}
}

bool Ray::inSight(VECTOR2 entity, const PLATFORM &walls)
{
	int d = 100000;
	float range1Angle = direction + visibilityAngle;
	float range2Angle = direction - visibilityAngle;

	VECTOR2 range1 = VECTOR2{ cos(range1Angle), sin(range1Angle) } *d;
	VECTOR2 range2 = VECTOR2{ cos(range2Angle), sin(range2Angle) } *d;
	bool c1 = isLeft(pos, range1, entity);
	bool c2 = isLeft(pos, range2, entity);

	if ((!c1 && c2))
	{
		VECTOR2 collision = castRayVector(entity, walls);
		if (collision == entity)
			return true;
	}
	return false;
}