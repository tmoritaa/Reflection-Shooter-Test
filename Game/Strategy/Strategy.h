#ifndef _STRATEGY_H_
#define _STRATEGY_H_

class Strategy 
{
public:
	virtual void Execute(float& velX, float& velY) = 0;
};

#endif
