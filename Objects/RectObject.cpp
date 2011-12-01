#include "RectObject.h"
#include "CircleObject.h"

RectObject::RectObject(Rect _r, SpriteID** _pAnimationList, int* _pAnimationListSize) 
:	Object(_pAnimationList, _pAnimationListSize),
	m_shape(_r)
{}

inline float RectObject::GetCenterX()
{
	return (m_shape.x + m_shape.w)/2;
}

inline float RectObject::GetCenterY()
{
	return (m_shape.y + m_shape.h)/2;
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

Rect RectObject::GetShape()
{
	return m_shape;
}

bool RectObject::checkCollision(CircleObject& obj)
{
	Circle c = obj.GetShape();
	float x, y;
	
	if (c.x < m_shape.x)
	{
		x = m_shape.x;
	}	
	else if (c.x > m_shape.x + m_shape.w)
	{
		x = m_shape.x + m_shape.w;
	}
	else 
	{
		x = c.x;
	}

	if (c.y < m_shape.y)
	{
		y = m_shape.y;
	} 
	else if (c.y > m_shape.y + m_shape.h)
	{
		y = m_shape.y + m_shape.h;
	}
	else
	{
		y = c.y;
	}

	if (distance(c.x, c.y, x, y) < c.r)
	{
		return true;
	}

	return false;
}

bool RectObject::checkCollision(RectObject& obj)
{
	Rect r = obj.GetShape();

	if (r.x + r.w >= m_shape.x || m_shape.x + m_shape.w >= r.x ||
		r.y + r.h >= m_shape.y || m_shape.y + m_shape.h >= r.y)
	{
		return true;
	}

	return false;
}
