#include "dashboard.h"

Dashboard::Dashboard()
{
	//timer = new TextDX();
	mouse = new Cursor();
	mins = 0;
	secs = 0;
}

Dashboard::~Dashboard()
{
	//SAFE_DELETE(timer);
}

bool Dashboard::initialize(Graphics *g, Cursor *cursor)
{
	if (!skillTexture.initialize(g, SKILL_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing skill icon texture"));

	if (!stealthIcon.initialize(g, buttonNS::SKILL_WIDTH, buttonNS::SKILL_HEIGHT, 0, &skillTexture, mouse))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializng stealth icon"));

	stealthIcon.setCurrentFrame(buttonNS::STEALTH_FRAME);
	stealthIcon.setX(((GAME_WIDTH / 2) - 150 - stealthIcon.getWidth())*stealthIcon.getScale());
	stealthIcon.setY((GAME_HEIGHT - 15 - stealthIcon.getHeight())*stealthIcon.getScale());

	if (!speedIcon.initialize(g, buttonNS::SKILL_WIDTH, buttonNS::SKILL_HEIGHT, 0, &skillTexture, mouse))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializng stealth icon"));

	speedIcon.setCurrentFrame(buttonNS::SPEED_FRAME);
	speedIcon.setX(((GAME_WIDTH / 2) - 50 - speedIcon.getWidth())*speedIcon.getScale());
	speedIcon.setY((GAME_HEIGHT - 15 - speedIcon.getHeight())*speedIcon.getScale());

	if (!rangeIcon.initialize(g, buttonNS::SKILL_WIDTH, buttonNS::SKILL_HEIGHT, 0, &skillTexture, mouse))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializng stealth icon"));

	rangeIcon.setCurrentFrame(buttonNS::RANGE_FRAME);
	rangeIcon.setX(((GAME_WIDTH / 2) + 50)*rangeIcon.getScale());
	rangeIcon.setY((GAME_HEIGHT - 15 - rangeIcon.getHeight())*rangeIcon.getScale());

	if (!armorIcon.initialize(g, buttonNS::SKILL_WIDTH, buttonNS::SKILL_HEIGHT, 0, &skillTexture, mouse))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializng stealth icon"));

	armorIcon.setCurrentFrame(buttonNS::ARMOUR_FRAME);
	armorIcon.setX(((GAME_WIDTH / 2) + 150)*armorIcon.getScale());
	armorIcon.setY((GAME_HEIGHT - 15 - armorIcon.getHeight())*armorIcon.getScale());

	if (!dashboardTexture.initialize(g,DASHBOARD_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing dashboard"));

	if (!dashboard.initialize(g, GAME_WIDTH, GAME_HEIGHT, 0, &dashboardTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing dashboard"));

	

}

void Dashboard::draw()
{
	dashboard.draw();


	stealthIcon.draw();
	speedIcon.draw();
	rangeIcon.draw();
	armorIcon.draw();

	

}

void Dashboard::update()
{

}

void Dashboard::collisions()
{

}


