// Programming 2D Games
// Copyright (c) 2011 by: 
// Charles Kelly
// Chapter 6 spacewar.h v1.0

#ifndef _LETITRAIN_H             // Prevent multiple definitions if this 
#define _LETITRAIN_H             // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#pragma once
#include "game.h"
#include "textureManager.h"
#include "image.h"
#include "trooper.h"
#include "gunner.h"
#include "cursor.h"
#include "rayCasting.h"
#include "enemyManager.h"

class AssassinValkyrie : public Game
{
private:
	TextureManager trooperTexture;
	TextureManager gunnerTexture;
	TextureManager mouseTextures;
	TextureManager bulletTextures;
	Cursor *mouse;
	Trooper *trooper1;
	Gunner *gunner1;
	EnemyManager emList;

public:
    AssassinValkyrie();
    virtual ~AssassinValkyrie();

	void initialize(Game &gamePtr, HWND *hwndM, HRESULT *hrM, LARGE_INTEGER *timeStartM, LARGE_INTEGER *timeEndM,
		LARGE_INTEGER *timerFreqM, float *frameTimeM);
    void update();      
    void ai();
    void collisions();
    void render();
    void releaseAll();
    void resetAll();
};

#endif
