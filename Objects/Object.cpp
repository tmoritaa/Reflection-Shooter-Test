#include "Object.h"
#include <cassert>
#include <cmath>

Object::Object(SpriteID** _pAnimationList, int* _pAnimationListSize)
:	m_pAnimationList(_pAnimationList),
	m_pAnimationListSize(_pAnimationListSize),
	m_velX(0),
	m_velY(0),
	m_animationIndex(0),
	m_animationState(ANIMATIONSTATE_IDLE)
{}

Object::~Object()
{
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

float Object::distance(float x1, float y1, float x2, float y2)
{
	return sqrt(pow(x2-x1, 2) + pow(y2-y1,2));
}

void Object::Move()
{
	assert(0 && "Base Object class Move function should not be called");
}
