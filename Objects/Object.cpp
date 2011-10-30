#include "Object.h"
#include <cassert>

Object::Object(Circle* _pC, SpriteID _spriteID)
{
	m_shape.c = _pC;

	m_shape.r = NULL;

	m_spriteID = _spriteID;

	m_velX = 0;
	m_velY = 0;

	assert(m_spriteID < SPRITEID_SIZE);
	assert(m_shape.c != NULL ||  m_shape.r != NULL);
}

Object::Object(Rect* _pR, SpriteID _spriteID)
{
	m_shape.r = _pR;

	m_shape.c = NULL;

	m_spriteID = _spriteID;

	m_velX = 0;
	m_velY = 0;

	assert(m_spriteID < SPRITEID_SIZE);
	assert(m_shape.c != NULL ||  m_shape.r != NULL);
}

Object::~Object()
{
	if (NULL != m_shape.c)
	{
		delete m_shape.c;
	}

	if (NULL != m_shape.r)
	{
		delete m_shape.r;
	}
}

void Object::SetVelX(int _velX)
{
	m_velX = _velX;
}

void Object::SetVelY(int _velY)
{
	m_velY = _velY;
}

int Object::GetVelX()
{
	return m_velX;
}

int Object::GetVelY()
{
	return m_velY;
}

int Object::GetX()
{
	if (m_shape.c != NULL)
	{
		return m_shape.c->x;
	}
	else 
	{
		return m_shape.r->x;
	}
}

int Object::GetY()
{
	if (m_shape.c != NULL)
	{
		return m_shape.c->y;
	}
	else 
	{
		return m_shape.r->y;
	}
}

void Object::Move()
{
	assert(m_shape.c != NULL ||  m_shape.r != NULL);

	if (m_shape.c != NULL)
	{
		m_shape.c->x += m_velX;
		m_shape.c->y += m_velY;
	}
	else 
	{
		m_shape.r->x += m_velX;
		m_shape.r->y += m_velY;
	}
}

SpriteID Object::GetSpriteID()
{
	return m_spriteID;;
}

void Object::SetSpriteID(SpriteID _spriteID)
{
	m_spriteID = _spriteID;
}
