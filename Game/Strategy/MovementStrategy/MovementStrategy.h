#ifndef _MOVEMENTSTRATEGY_H_
#define _MOVEMENTSTRATEGY_H_

#include "../Strategy.h"

class MovementStrategy : public Strategy
{
protected:
	int m_movementState;

public:
	MovementStrategy();
	virtual void Execute(float& velX, float& velY) = 0;
};

#endif
