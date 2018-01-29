//  Module:             Gameplay Programming
//  Assignment1:        LET IT RAIN
//  Student Name:       Timothy Chua
//  Student Number:     10165581F

#include "trooper.h"
#include "gunner.h"
#include "serpant.h"
#include <vector>

typedef std::vector<Trooper*> TROOPERLIST;
typedef std::vector<Gunner*> GUNNERLIST;
typedef std::vector<Serpant*> SERPANTLIST;
 
class EnemyManager
{
private:
	TROOPERLIST trooperCollection;
	GUNNERLIST gunnerCollection;
	SERPANTLIST serpantCollection;

	TROOPERLIST::iterator trooper;
	GUNNERLIST::iterator gunner;
	SERPANTLIST::iterator serpant;
	int trooperSize;
	int gunnerSize;
	int serpantSize;

public:
	EnemyManager();
	~EnemyManager();

	bool initialize(Game *gamePtr, TextureManager *textureTrooper, TextureManager *textureGunner, TextureManager *textureSerpant, TextureManager *textureHealth, Entity *play);
	void update(float frameTime, PLATFORM p);
	void ai();
	void collisions(Entity *play);
	void render(Graphics *g);
	GUNNERLIST *getGunners() { return &gunnerCollection; }
	SERPANTLIST *getSerpant() { return &serpantCollection; }
};