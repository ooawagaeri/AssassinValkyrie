#ifndef _BUTTON_H
#define _BUTTON_H
#define WIN32_LEAN_AND_MEAN

#include "Image.h"	
#include "constants.h"
#include "game.h"
#include "input.h"
#include "entity.h"
#include "cursor.h"

namespace buttonNS
{
	const int BUTTON_WIDTH = 249;
	const int BUTTON_HEIGHT = 70;
	const int START_BUTTON_FRAME = 0;
	const int START_HOVER_BUTTON_FRAME = 1;
	const int SETTINGS_BUTTON_FRAME = 2;
	const int SETTINGS_HOVER_BUTTON_FRAME = 3;
	const int EXIT_BUTTON_FRAME = 4;
	const int EXIT_HOVER_BUTTON_FRAME = 5;
	const int CREDITS_BUTTON_FRAME = 6;
	const int CREDITS_HOVER_BUTTON_FRAME = 7;
	const int RESUME_BUTTON_FRAME = 8;
	const int RESUME_HOVER_BUTTON_FRAME = 9;
	const int BUTTON_NCOLS = 2;

	const int SKILL_WIDTH = 50;
	const int SKILL_HEIGHT = 51;
	const int STEALTH_FRAME = 0;
	const int SPEED_FRAME = 1;
	const int RANGE_FRAME = 2;
	const int ARMOUR_FRAME = 3;
}

class Button : public Entity
{
public:
	Button();
	virtual ~Button();

	bool initialize(Graphics *g, int width, int height, int ncols, TextureManager *textureM, Cursor *cursor);
	void update(int endFrame);
	void draw();
	bool click();

	void collisions(int startFrame, int endFrame);
	void releaseAll();
	void resetAll();

	Cursor mouse;
};

#endif