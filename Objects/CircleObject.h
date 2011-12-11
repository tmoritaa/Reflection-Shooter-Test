#ifndef _CIRCLEOBJECT_H_
#define _CIRCLEOBJECT_H_

#include "Object.h"

class CircleObject : public Object
{
protected:
	Circle m_shape;

public:
	CircleObject();
	CircleObject(Circle _c, SpriteID** _pAnimationList, int* _pAnimationListSize);
	Circle GetShape() const;
	virtual float GetCenterX() const;
	virtual float GetCenterY() const;
	virtual void Move();
	virtual bool CheckCollision(const CircleObject* obj) const;
	virtual bool CheckCollision(const RectObject* obj) const;
	virtual bool CheckCollision(Object* obj) const;
};

#endif
