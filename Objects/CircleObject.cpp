#include "CircleObject.h"

CircleObject::CircleObject(Circle _c, SpriteID** _pAnimationList, int* _pAnimationListSize) 
:	Object(_pAnimationList, _pAnimationListSize),
	m_shape(_c)
{}

inline float CircleObject::GetX()
{
	return m_shape.x;
}

inline float CircleObject::GetY()
{
	return m_shape.y;
}

void CircleObject::Move()
{
	m_shape.x += m_velX;
	m_shape.y += m_velY;
	
	m_animationIndex++;
	if (m_pAnimationListSize[m_animationState] ==  m_animationIndex)
	{
		m_animationIndex = 0;
	}
}

bool CircleObject::checkCollision(CircleObject& obj)
{

}

bool CircleObject::checkCollision(RectObject& obj)
{

}
