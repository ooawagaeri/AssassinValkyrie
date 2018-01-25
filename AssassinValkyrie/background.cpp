// Module			: Gameplay Programming
// Assignment2		: Assassin Valkyrie
// Student Number	: Daniel Lee Min Qiang
// Student Number	: S10162739H

#include "background.h"

Background::Background() : Entity()
{
	spriteData.width = backgroundNS::WIDTH;           // size of Ship1
	spriteData.height = backgroundNS::HEIGHT;
	spriteData.rect.bottom = backgroundNS::HEIGHT;    // rectangle to select parts of an image
	spriteData.rect.right = backgroundNS::WIDTH;
	spriteData.y = -720;
	i = 0;
	centre = false;
	velocity.x = 0;
	currentFrame = startFrame;
	edge = RECT{ (long)(-backgroundNS::WIDTH*backgroundNS::SCALE / 2), (long)(-backgroundNS::HEIGHT*backgroundNS::SCALE / 2), (long)(backgroundNS::WIDTH*backgroundNS::SCALE / 2), (long)(backgroundNS::HEIGHT*backgroundNS::SCALE / 2) };
	collisionType = entityNS::BOX;
}

bool Background::initialize(Game *gamePtr, int width, int height, int ncols, TextureManager *textureM)
{
	//health = new HealthComponent();
	//move = new MovementComponent(&(spriteData.x), &(spriteData.y), trooperNS::SPEED, 0);
	return(Entity::initialize(gamePtr, width, height, ncols, textureM));
}

void Background::update(float frameTime, Entity *player, StageGenerator *stageGen)
{
	bool leftSide = (player->getX() - spriteData.x) > (GAME_WIDTH / 2);
	bool rightSide = (player->getX() - spriteData.x) < (backgroundNS::WIDTH - (GAME_WIDTH / 2));
	bool bottom = (player->getY() - spriteData.y) < (GAME_HEIGHT + (GAME_HEIGHT/2));
	bool top = (player->getY() - spriteData.y ) > ( GAME_HEIGHT- (GAME_HEIGHT / 2));
	if (top && bottom && leftSide && rightSide) 
	{
		player->setVelocity(VECTOR2(0, 0));
		velocity.y = 100;
		velocity.x = 100;
		if (input->isKeyDown(SHIP_UP_KEY))
		{
			spriteData.y += frameTime * velocity.y;         // move ship along X 
			stageGen->update(frameTime, false);
		}

		else if (input->isKeyDown(SHIP_DOWN_KEY))
		{
			spriteData.y += frameTime * (-velocity.y);         // move ship along X 
			stageGen->update(frameTime, false);
		}
		else if (input->isKeyDown(SHIP_UP_KEY))
		{
			spriteData.y += frameTime * velocity.y;         // move ship along X 
			stageGen->update(frameTime, false);
		}

		else if (input->isKeyDown(SHIP_DOWN_KEY))
		{
			spriteData.y += frameTime * (-velocity.y);         // move ship along X 
			stageGen->update(frameTime, false);
		}
	}
	else if (top && bottom) 
	{
		if (player->getVelocity() == VECTOR2(100, 0) || player->getVelocity() == VECTOR2(100, 100))
			player->setVelocity(VECTOR2(100, 0));
		else
			player->setVelocity(VECTOR2(0, 0));
		velocity.y = 100;
		if (spriteData.y > 0)
			spriteData.y = 0;
		if (input->isKeyDown(SHIP_UP_KEY))
		{
			spriteData.y += frameTime * velocity.y;         // move ship along X 
			stageGen->update(frameTime, false);
		}

		else if (input->isKeyDown(SHIP_DOWN_KEY))
		{
			spriteData.y += frameTime * (-velocity.y);         // move ship along X 
			stageGen->update(frameTime, false);
		}
	}
	else if (leftSide && rightSide)
	{
		if (player->getVelocity() == VECTOR2(0, 100) || player->getVelocity() == VECTOR2(100, 100))
			player->setVelocity(VECTOR2(0, 100));
		else
			player->setVelocity(VECTOR2(0, 0));		
		velocity.x = 100;
		if (spriteData.x > 0)
			spriteData.x = 0;
		if (input->isKeyDown(SHIP_LEFT_KEY))
		{
			spriteData.x += frameTime * velocity.x;         // move ship along X 
			stageGen->update(frameTime, true);
		}

		else if (input->isKeyDown(SHIP_RIGHT_KEY))
		{
			spriteData.x += frameTime * (-velocity.x);         // move ship along X 
			stageGen->update(frameTime, true);
		}
	}
	else {
		velocity.x = 0;
		velocity.y = 0;
		player->setVelocity(VECTOR2(100, 100));
	}
	

	/*
	if (!centre)
		player->setVelocity(VECTOR2(100, 0));
	else
		player->setVelocity(VECTOR2(0, 0));
	if ((player->getX() > ((GAME_WIDTH) / 2)))
	{
		centre = true;
	}
	if (centre){
		if (input->isKeyDown(SHIP_LEFT_KEY))
		{
			spriteData.x += frameTime * velocity.x;         // move ship along X 
			stageGen->update(frameTime);
		}

		else if (input->isKeyDown(SHIP_RIGHT_KEY))
		{
			spriteData.x += frameTime * (-velocity.x);         // move ship along X 
			stageGen->update(frameTime);
		}
	}
	if (centre && ((spriteData.x < -160) || (spriteData.x > 0))) {
		centre = false;
		velocity.x = 0;
	}
	*/

	/*
	if (((player->getX() > ((GAME_WIDTH) / 2)) && (spriteData.x <= 0) && (spriteData.x > -160)) || i==1)
	{
		player->setVelocity(VECTOR2(0, 0));
		velocity.x = 100;
		if (input->isKeyDown(SHIP_LEFT_KEY))
		{
			spriteData.x += frameTime * velocity.x;         // move ship along X 
			stageGen->update(frameTime);
		}

		else if (input->isKeyDown(SHIP_RIGHT_KEY))
		{
			spriteData.x += frameTime * (-velocity.x);         // move ship along X 
			stageGen->update(frameTime);
		}
	}
	if ((spriteData.x > 0) && (player->getX() >((GAME_WIDTH) / 2))){
		i = 0;
		player->setVelocity(VECTOR2(100, 0));
		velocity.x = 0;
	}
	if ((spriteData.x <= -160) && (player->getX() >((GAME_WIDTH) / 2))) {
		player->setVelocity(VECTOR2(100, 0));
		velocity.x = 0;
		i = 1;
	}
	*/
	Entity::update(frameTime);


	//move->update(frameTime);
}


void Background::draw()
{
	Image::draw();              // draw ship
}