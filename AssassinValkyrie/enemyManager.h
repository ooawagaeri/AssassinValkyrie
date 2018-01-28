//  Module:             Gameplay Programming
//  Assignment1:        LET IT RAIN
//  Student Name:       Timothy Chua
//  Student Number:     10165581F

#include "trooper.h"
#include "gunner.h"
#include <vector>

typedef std::vector<Trooper*> TROOPERLIST;
typedef std::vector<Gunner*> GUNNERLIST;
 
class EnemyManager
{
private:
	TROOPERLIST trooperCollection;
	GUNNERLIST gunnerCollection;

	TROOPERLIST::iterator trooper;
	GUNNERLIST::iterator gunner;
	int trooperSize;
	int gunnerSize;

public:
	EnemyManager();
	~EnemyManager();

	bool initialize(Game *gamePtr, TextureManager *textureTrooper, TextureManager *textureGunner, Entity *play);
	void update(float frameTime, PLATFORM p);
	void ai();
	void collisions(Entity *play);
	void render(Graphics *g);
	GUNNERLIST *getGunners() { return &gunnerCollection; }
};