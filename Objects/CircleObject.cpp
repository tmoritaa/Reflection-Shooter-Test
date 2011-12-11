#include "CircleObject.h"
#include "RectObject.h"
#include <cassert>

CircleObject::CircleObject()
:	Object(),
	m_shape()
{}

CircleObject::CircleObject(Circle _c, SpriteID** _pAnimationList, int* _pAnimationListSize) 
:	Object(_pAnimationList, _pAnimationListSize),
	m_shape(_c)
{}

float CircleObject::GetCenterX() const
{
	return m_shape.x;
}

float CircleObject::GetCenterY() const
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

Circle CircleObject::GetShape() const
{
	return m_shape;
}

bool CircleObject::CheckCollision(const CircleObject* obj) const
{
	Circle c = obj->GetShape();

	if (distance(m_shape.x, m_shape.y, c.x, c.y) < (m_shape.r + c.r))
	{
		return true;
	}

	return false;
}

bool CircleObject::CheckCollision(const RectObject* obj) const
{
	Rect r = obj->GetShape();
	float x, y;
	
	if (m_shape.x < r.x)
	{
		x = r.x;
	}	
	else if (m_shape.x > r.x + r.w)
	{
		x = r.x + r.w;
	}
	else
	{
		x = m_shape.x;
	}

	if (m_shape.y < r.y)
	{
		y = r.y;
	} 
	else if (m_shape.y > r.y + r.h)
	{
		y = r.y + r.h;
	}
	else
	{
		y = m_shape.y;
	}

	if (distance(m_shape.x, m_shape.y, x, y) < m_shape.r)
	{
		return true;
	}

	return false;
}

bool CircleObject::CheckCollision(Object* obj) const
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
