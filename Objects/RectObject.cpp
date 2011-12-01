#include "RectObject.h"

RectObject::RectObject(Rect _r, SpriteID** _pAnimationList, int* _pAnimationListSize) 
:	Object(_pAnimationList, _pAnimationListSize),
	m_shape(_r)
{}

inline float RectObject::GetX()
{
	return m_shape.x;
}

inline float RectObject::GetY()
{
	return m_shape.y;
}

void RectObject::Move()
{
	m_shape.x += m_velX;
	m_shape.y += m_velY;
	
	m_animationIndex++;
	if (m_pAnimationListSize[m_animationState] ==  m_animationIndex)
	{
		m_animationIndex = 0;
	}
}

bool RectObject::checkCollision(CircleObject& obj)
{

}

bool RectObject::checkCollision(RectObject& obj)
{

}
