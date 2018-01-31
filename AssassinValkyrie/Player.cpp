// Module			: Gameplay Programming
// Assignment2		: Assassin Valkyrie
// Student Number	: Zhuang yuteng
// Student Number	: S10163964C

#include "Player.h"

Player::Player() : Entity()
{
	state_ = new StandState();
	spriteData.width = playerNS::WIDTH;           // size of Ship1
	spriteData.height = playerNS::HEIGHT;
	spriteData.x = playerNS::X;                   // location on screen
	spriteData.y = playerNS::Y;
	spriteData.rect.bottom = playerNS::HEIGHT;    // rectangle to select parts of an image
	spriteData.rect.right = playerNS::WIDTH;
	spriteData.angle = playerNS::ROTATION;
	spriteData.scale = playerNS::SCALE;

	frameDelay = playerNS::ANIMATION_DELAY;
	startFrame = playerNS::START_FRAME;     // first frame of ship animation
	endFrame = playerNS::END_FRAME;     // last frame of ship animation
	currentFrame = startFrame;
	edge = RECT{ (long)(-playerNS::WIDTH*playerNS::SCALE / 2), (long)(-playerNS::HEIGHT*playerNS::SCALE / 2), (long)(playerNS::WIDTH*playerNS::SCALE / 2), (long)(playerNS::HEIGHT*playerNS::SCALE / 2) };
	collisionType = entityNS::BOX;
	totalXP = 0;
	totalLevels = playerNS::TOTAL_LEVELS;
	speedLevel = playerNS::START_LEVEL;
	rangeLevel = playerNS::START_LEVEL;
	armorLevel = playerNS::START_LEVEL;
	currentTotalLevel = speedLevel + rangeLevel + armorLevel - 2;
	skillPointAvailable = 0;
}

bool Player::initialize(Game *gamePtr, int width, int height, int ncols, TextureManager *textureM)
{
	
	return(Entity::initialize(gamePtr, width, height, ncols, textureM));
}

void Player::update(float frameTime, Game *gamePtr, TextureManager *textureM, StageGenerator *stagegenerator,EnemyManager *enemyList, PLATFORM p)
{
	if (totalXP > ((currentTotalLevel - 2) * 50)) {
		currentTotalLevel++;
		skillPointAvailable++;
	}
	
	handleInput(input,gamePtr,textureM,stagegenerator,enemyList,p);
	state_->update(*this, frameTime);

	
	Entity::update(frameTime);

	//move->update(frameTime);
}

void Player::handleInput(Input* input, Game *gamePtr, TextureManager *textureM, StageGenerator *stagegenerator, EnemyManager *enemyList, PLATFORM p)
{
    PlayerState* state = state_->handleInput(*this, input,gamePtr,textureM,stagegenerator,enemyList,p);
	if (state != NULL)
	{
		delete state_;
		state_ = state;
	}
}

void Player::collisions(EnemyManager *enemyList)
{
	VECTOR2 collisionVector;
	GUNNERLIST *gunnerCollection = enemyList->getGunners();
	TROOPERLIST *trooperCollection = enemyList->getTroopers();
	SERPANTLIST *serpantCollection = enemyList->getSerpant();

	
	for (GUNNERLIST::iterator gunner = (gunnerCollection->begin()); gunner != gunnerCollection->end(); gunner++)
	{
		if (collidesWith(**gunner,collisionVector))
		{
			
			if (isMeleeAttacking == true)
			{
				(*gunner)->getHealth()->damage(gunnerNS::HEALTH);
				isMeleeAttacking = false;
				if (!(*gunner)->getHealth()->getAlive() && (currentTotalLevel < totalLevels))
					totalXP += 50;
				break;
			}

			if (isAssassinating == true)
			{
				(*gunner)->getHealth()->damage(trooperNS::HEALTH);
				isAssassinating = false;
				if (!(*gunner)->getHealth()->getAlive() && (currentTotalLevel < totalLevels))
					totalXP += 50;
				break;
			}
		}
	}
	for (TROOPERLIST::iterator trooper = (trooperCollection->begin()); trooper != trooperCollection->end(); trooper++)
	{
		if (collidesWith(**trooper, collisionVector))
		{
			if (isMeleeAttacking == true)
			{
				(*trooper)->getHealth()->damage(trooperNS::HEALTH);
				isMeleeAttacking = false;
				if (!(*trooper)->getHealth()->getAlive() && (currentTotalLevel < totalLevels))
					totalXP += 50;
				break;
			}

			if (isAssassinating == true)
			{
				(*trooper)->getHealth()->damage(trooperNS::HEALTH);
				isAssassinating = false;
				if (!(*trooper)->getHealth()->getAlive() && (currentTotalLevel < totalLevels))
					totalXP += 50;
				break;
			}
		}
	}
	for (SERPANTLIST::iterator serpant = (serpantCollection->begin()); serpant != serpantCollection->end(); serpant++)
	{
		if (collidesWith(**serpant, collisionVector))
		{
			if (isMeleeAttacking == true)
			{
				(*serpant)->getHealth()->damage(serpantNS::HEALTH/2);
				isMeleeAttacking = false;
				if (!(*serpant)->getHealth()->getAlive() && (currentTotalLevel < totalLevels))
					totalXP += 100;
				break;
			}
			if (isAssassinating == true)
			{
				(*serpant)->getHealth()->damage(trooperNS::HEALTH);
				isAssassinating = false;
				if (!(*serpant)->getHealth()->getAlive() && (currentTotalLevel < totalLevels))
					totalXP += 50;
				break;
			}
		}
	}
	
}

// To find closest ship vector position
void Player::ai(Entity &ship1, Entity &ship2)
{
}

void Player::draw()
{
	
	Image::draw();              // draw ship
}
