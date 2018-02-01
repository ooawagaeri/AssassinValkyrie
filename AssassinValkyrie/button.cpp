#include "button.h"

Button::Button() : Entity()
{
	spriteData.width = buttonNS::BUTTON_WIDTH;
	spriteData.height = buttonNS::BUTTON_HEIGHT;
	spriteData.rect.bottom = buttonNS::BUTTON_HEIGHT;
	spriteData.rect.right = buttonNS::BUTTON_WIDTH;
	spriteData.x = getX();
	spriteData.y = getY();
	edge = RECT{ (long)(-buttonNS::BUTTON_WIDTH / 2), (long)(-buttonNS::BUTTON_HEIGHT / 2), (long)(buttonNS::BUTTON_WIDTH / 2), (long)(buttonNS::BUTTON_HEIGHT / 2) };
	collisionType = entityNS::BOX;
}

Button::~Button()
{
	releaseAll();
}

bool Button::initialize(Graphics *g, int width, int height, int ncols, TextureManager *textureM, Cursor *cursor)
{
	mouse = *cursor;
	return(Image::initialize(g, width, height, ncols, textureM));
}

void Button::update(int endFrame)
{
	setCurrentFrame(endFrame);
}

void Button::draw()
{
	Image::draw();
}

void Button::collisions(int startFrame, int endFrame)
{
	update(endFrame);
}

void Button::releaseAll()
{
}

void Button::resetAll() 
{
}

bool Button::collideButton(Entity &ent)
{
	if ((getCenterX() + edge.right*getScale() < ent.getCenterX() + ent.getEdge().left*ent.getScale()) ||
		(getCenterX() + edge.left*getScale() > ent.getCenterX() + ent.getEdge().right*ent.getScale()) ||
		(getCenterY() + edge.bottom*getScale() < ent.getCenterY() + ent.getEdge().top*ent.getScale()) ||
		(getCenterY() + edge.top*getScale() > ent.getCenterY() + ent.getEdge().bottom*ent.getScale()))
	{
		return false;
	}
	return true;
}