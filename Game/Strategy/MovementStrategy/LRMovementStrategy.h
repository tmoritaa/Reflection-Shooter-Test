#ifndef _LRMOVEMENTSTRATEGY_H_
#define _LRMOVEMENTSTRATEGY_H_

#include "MovementStrategy.h"

class LRMovementStrategy : public MovementStrategy
{
public:
	LRMovementStrategy();
	virtual void Execute(float& velX, float& velY);
};

#endif
