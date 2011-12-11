// TODO:
// Write copy constructor, = operator, and == operator for all object types
	
#include "Object.h"
#include <cassert>
#include <cmath>

static int uniqueID = 0;

inline static int GetUniqueObjectID()
{
	return uniqueID++;
}

Object::Object()
:	m_pAnimationList(NULL),
	m_pAnimationListSize(NULL),
	m_velX(0),
	m_velY(0),
	m_animationIndex(0),
	m_animationState(ANIMATIONSTATE_IDLE),
	m_objectID(GetUniqueObjectID())
{}

Object::Object(SpriteID** _pAnimationList, int* _pAnimationListSize)
:	m_pAnimationList(_pAnimationList),
	m_pAnimationListSize(_pAnimationListSize),
	m_velX(0),
	m_velY(0),
	m_animationIndex(0),
	m_animationState(ANIMATIONSTATE_IDLE),
	m_objectID(GetUniqueObjectID())
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

float Object::GetVelX() const
{
	return m_velX;
}

float Object::GetVelY() const
{
	return m_velY;
}

SpriteID Object::GetSpriteID() const
{
	return m_pAnimationList[m_animationState][m_animationIndex];
}

int Object::GetObjectID() const
{
	return m_objectID;
}

void Object::SetAnimationState(AnimationState _animationState)
{
	assert(_animationState < ANIMATIONSTATE_SIZE);
	assert(m_pAnimationListSize[_animationState] > 0);

	m_animationState = _animationState;
	m_animationIndex = 0;
}

float Object::distance(const float x1, const float y1, const float x2, const float y2) const
{
	return sqrt(pow(x2-x1, 2) + pow(y2-y1,2));
}
