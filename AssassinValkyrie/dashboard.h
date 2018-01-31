#ifndef _DASHBOARD_H
#define _DASHBOARD_H
#define WIN32_LEAN_AND_MEAN

#include "game.h"
#include "textureManager.h"
#include "textDX.h"
#include "constants.h"
#include "graphics.h"
#include "button.h"

namespace dashboardNS
{
	const COLOR_ARGB fontColor = D3DCOLOR_ARGB(255, 141, 214, 233);
	const int PAUSE_WIDTH = 100;
	const int PAUSE_HEIGHT = 50;
	const int PAUSE_NCOLS = 0;
	const int PAUSE_FRAME = 0;
	const int PAUSE_HOVER_FRAME = 1;
}

class Dashboard
{
private:
	TextureManager skillTexture;
	TextureManager dashboardTexture;
	//TextDX *timer;
	Button stealthIcon;
	Button speedIcon;
	Button rangeIcon;
	Button armorIcon;
	Cursor *mouse;
	Image dashboard;


public:
	Dashboard();
	virtual ~Dashboard();
	bool initialize(Graphics *g, Cursor *cursor);
	void draw();
	void update();
	void collisions();

	int mins;
	int secs;
};

#endif