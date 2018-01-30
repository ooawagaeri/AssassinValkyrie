// Programming 2D Games
// Copyright (c) 2011 by: 
// Charles Kelly
// Chapter 6 constants.h v1.0

#ifndef _CONSTANTS_H            // Prevent multiple definitions if this 
#define _CONSTANTS_H            // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include <windows.h>

//-----------------------------------------------
// Useful macros
//-----------------------------------------------
// Safely delete pointer referenced item
#define SAFE_DELETE(ptr)       { if (ptr) { delete (ptr); (ptr)=NULL; } }
// Safely release pointer referenced item
#define SAFE_RELEASE(ptr)      { if(ptr) { (ptr)->Release(); (ptr)=NULL; } }
// Safely delete pointer referenced array
#define SAFE_DELETE_ARRAY(ptr) { if(ptr) { delete [](ptr); (ptr)=NULL; } }
// Safely call onLostDevice
#define SAFE_ON_LOST_DEVICE(ptr)    { if(ptr) { ptr->onLostDevice(); } }
// Safely call onResetDevice
#define SAFE_ON_RESET_DEVICE(ptr)   { if(ptr) { ptr->onResetDevice(); } }
#define TRANSCOLOR  SETCOLOR_ARGB(0,255,0,255)  // transparent color (magenta)

//-----------------------------------------------
//                  Constants
//-----------------------------------------------

// window
const char CLASS_NAME[] = "AssassinValkyrie";
const char GAME_TITLE[] = "Assassin Valkyrie";
const bool FULLSCREEN = false;              // windowed or fullscreen
const UINT GAME_WIDTH = 1280;               // width of game in pixels
const UINT GAME_HEIGHT = 720;               // height of game in pixels

// game
const double PI = 3.14159265;
const float FRAME_RATE = 120.0f;                // the target frame rate (frames/sec)
const float MIN_FRAME_RATE = 60.0f;             // the minimum frame rate
const float MIN_FRAME_TIME = 1.0f/FRAME_RATE;   // minimum desired time for 1 frame
const float MAX_FRAME_TIME = 1.0f/MIN_FRAME_RATE; // maximum time used in calculations
const float GRAVITY = 9.81f;

// graphic images
const char MMBACKGROUND_IMAGE[] = "pictures\\mainMenuBackground.png";
const char MOUSE_IMAGE[] = "pictures\\mouse.png";
const char ENEMY_IMAGE[] = "pictures\\enemyTexture.png";
const char PLAYER_IMAGE[] = "pictures\\Player.png";
const char FLOOR_IMAGE[] = "pictures\\testElement.png";
const char BACKGROUND_IMAGE[] = "pictures\\tempbg.png";
const char LADDER_IMAGE[] = "pictures\\ladderbig.png";

const char ENEMY_TROOPER_IMAGE[] = "pictures\\enemyTexture.png";
const char ENEMY_GUNNER_IMAGE[] = "pictures\\enemyTexture_gunner.png";
const char ENEMY_SERPANT_IMAGE[] = "pictures\\enemyTexture_serpant.png";
const char BULLET_IMAGE[] = "pictures\\bullets.png";
const char HEALTH_IMAGE[] = "pictures\\healthTexture.png";

// WAVE_BANK must be location of .xwb file.
const char WAVE_BANK[] = "audio\\Win\\Wave Bank.xwb";
// SOUND_BANK must be location of .xsb file.
const char SOUND_BANK[] = "audio\\Win\\Sound Bank.xsb";

// audio cues
const char TITLE[] = "Title";

// key mappings
// In this game simple constants are used for key mappings. If variables were used
// it would be possible to save and restore key mappings from a data file.
const UCHAR ESC_KEY      = VK_ESCAPE;       // escape key
const UCHAR ALT_KEY      = VK_MENU;         // Alt key
const UCHAR ENTER_KEY    = VK_RETURN;       // Enter key


//control key for player ship
const UCHAR RUNNING_RIGHT_KEY = 'D';
const UCHAR RUNNING_LEFT_KEY = 'A';
const UCHAR CROUCHING_KEY = 'S';
const UCHAR MELEE_ATTACK_KEY = 'G';
const UCHAR RANGE_ATTACK_KEY = 'F';
const UCHAR JUMPING_KEY = VK_SPACE;

//temp controls based off old naming of controls
const UCHAR SHIP_UP_KEY = 'W';
const UCHAR SHIP_DOWN_KEY = 'S';
const UCHAR SHIP_LEFT_KEY = 'A';
const UCHAR SHIP_RIGHT_KEY = 'D';
// weapon types
enum WEAPON { BULLET, MISSILE, LASER, SHIP };

#endif
