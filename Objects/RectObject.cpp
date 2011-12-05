#include "RectObject.h"
#include "CircleObject.h"
#include <cassert>

RectObject::RectObject(Rect _r, SpriteID** _pAnimationList, int* _pAnimationListSize) 
:	Object(_pAnimationList, _pAnimationListSize),
	m_shape(_r)
{}

float RectObject::GetCenterX() const
{
	return (m_shape.x + m_shape.w)/2;
}

float RectObject::GetCenterY() const
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

Rect RectObject::GetShape() const
{
	return m_shape;
}

bool RectObject::CheckCollision(const CircleObject* obj) const
{
	Circle c = obj->GetShape();
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

bool RectObject::CheckCollision(const RectObject* obj) const
{
	Rect r = obj->GetShape();

	if ((m_shape.x + m_shape.w) < r.x || m_shape.x > (r.x + r.w) || (m_shape.y + m_shape.h) < r.y || m_shape.y > (r.y + r.w))
	{
		return false;
	}

	return true;
}

bool RectObject::CheckCollision(Object* obj) const
{
	CircleObject* pCircleObj = dynamic_cast<CircleObject*>(obj);
	if (pCircleObj != NULL)
	{
		return CheckCollision(pCircleObj);
	}
	
	RectObject* pRectObj = dynamic_cast<RectObject*>(obj);
	if (pRectObj != NULL)
	{
		return CheckCollision(pRectObj);
	}

	assert(0 && "Collision performed on non-valid object");
	
	return false;
}
