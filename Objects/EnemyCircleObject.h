#ifndef _ENEMYCIRCLEOBJECT_H_
#define _ENEMYCIRCLEOBJECT_H_

#include "CircleObject.h"
#include "../Game/Strategy/MovementStrategy/MovementStrategyHeaders.h"

class EnemyCircleObject : public CircleObject
{
protected: 
	MovementStrategy* m_movementStrategy;

public:
	EnemyCircleObject(Circle _c, SpriteID** _pAnimationList, int* _pAnimationListSize, MovementStrategy* _movementStrategy);
	~EnemyCircleObject();
	virtual void Move();
};

#endif
