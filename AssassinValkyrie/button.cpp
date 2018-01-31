#include "button.h"

Button::Button() : Entity()
{
	spriteData.width = buttonNS::BUTTON_WIDTH;
	spriteData.height = buttonNS::BUTTON_HEIGHT;
	spriteData.x = getX();
	spriteData.y = getY();
	spriteData.rect.right = spriteData.x + buttonNS::BUTTON_WIDTH;
	spriteData.rect.bottom = spriteData.y + buttonNS::BUTTON_HEIGHT;

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

	//setCurrentFrame(endFrame);
	//Image::update(frameTime);
}

/*void Button::update()
{
	VECTOR2 collisionVector;
	if (collidesWith(mouse, collisionVector))
	{
		setCurrentFrame()
	}
}*/

void Button::draw()
{
	Image::draw();
}

/*bool Button::click(Input *input, int x, int y)
{
	return;
}*/

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