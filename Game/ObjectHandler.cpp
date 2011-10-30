#include "ObjectHandler.h"
#include "../Definitions/Definitions.h"

ObjectHandler::ObjectHandler()
{
	Circle* c = new Circle;
	c->x = SCREEN_WIDTH/2;
	c->y = SCREEN_HEIGHT/2;
	c->r = 10;

	m_main = new Object(c, SPRITEID_MAINIDLE);
}

Object* ObjectHandler::GetMain()
{
	return m_main;
}
