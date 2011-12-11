// TODO
// Add reflection logic later
// for now just make moveable object

#ifndef _OBJECT_H_
#define _OBJECT_H_

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "../Definitions/Definitions.h"
#include "Shapes.h"

class CircleObject;
class RectObject;

class Object
{	
private:
	Object(const Object& copy) {}
	Object& operator= (const Object& rhs) {}

protected:
	float m_velX, m_velY;
	SpriteID** m_pAnimationList;
	int* m_pAnimationListSize;
	int m_animationIndex;
	AnimationState m_animationState;
	int m_objectID;
	
	float distance(const float x1, const float y1, const float x2, const float y2) const;

public:
	Object();
	Object(SpriteID** _pAnimationList, int* _pAnimationListSize);
	~Object();

	void SetVelX(const float _velX);
	void SetVelY(const float _velY);
	void SetAnimationState(AnimationState _animationState);
	float GetVelX() const;
	float GetVelY() const;
	SpriteID GetSpriteID() const;
	int GetObjectID() const;

	virtual float GetCenterX() const = 0;
	virtual float GetCenterY() const = 0;
	virtual void Move() = 0;
	virtual bool CheckCollision(const CircleObject* obj) const = 0;
	virtual bool CheckCollision(const RectObject* obj) const = 0;
	virtual bool CheckCollision(Object* obj) const = 0;
};

inline bool operator==(const Object& lhs, const Object& rhs)
{
	return (lhs.GetObjectID() == rhs.GetObjectID());
}

#endif
