#include "Object.h"
#include <cassert>

Object::Object(Circle* _pC, SpriteID** _pAnimationList, int* _pAnimationListSize)
:	m_pAnimationList(_pAnimationList),
	m_pAnimationListSize(_pAnimationListSize),
	m_velX(0),
	m_velY(0),
	m_animationIndex(0),
	m_animationState(ANIMATIONSTATE_IDLE)
{
	m_shape.c = _pC;
	m_shape.r = NULL;
	assert(m_shape.c != NULL ||  m_shape.r != NULL);
}

Object::Object(Rect* _pR, SpriteID** _pAnimationList, int* _pAnimationListSize)
:	m_pAnimationList(_pAnimationList),
	m_pAnimationListSize(_pAnimationListSize),
	m_velX(0),
	m_velY(0),
	m_animationIndex(0),
	m_animationState(ANIMATIONSTATE_IDLE)
{
	m_shape.c = NULL;
	m_shape.r = _pR;
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

	for (int i = 0; i < ANIMATIONSTATE_SIZE; i++)
	{
		if (m_pAnimationList[i] != NULL)
		{
			free(m_pAnimationList[i]);
		}
	}

	free(m_pAnimationList);
	free(m_pAnimationListSize);
}

void Object::SetVelX(float _velX)
{
	m_velX = _velX;
}

void Object::SetVelY(float _velY)
{
	m_velY = _velY;
}

float Object::GetVelX()
{
	return m_velX;
}

float Object::GetVelY()
{
	return m_velY;
}

float Object::GetX()
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

float Object::GetY()
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
	
	m_animationIndex++;
	if (m_pAnimationListSize[m_animationState] ==  m_animationIndex)
	{
		m_animationIndex = 0;
	}
}

SpriteID Object::GetSpriteID()
{
	return m_pAnimationList[m_animationState][m_animationIndex];
}

void Object::SetAnimationState(AnimationState _animationState)
{
	assert(_animationState < ANIMATIONSTATE_SIZE);
	assert(m_pAnimationListSize[_animationState] > 0);

	m_animationState = _animationState;
	m_animationIndex = 0;
}
