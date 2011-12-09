#include "LRMovementStrategy.h"

LRMovementStrategy::LRMovementStrategy()
:	MovementStrategy()
{}

void LRMovementStrategy::Execute(float& velX, float& velY)
{
	if (m_movementState < 100)
	{
		velX = 1;
	} 
	else 
	{
		velX = -1;
	}
	
	m_movementState++;
	m_movementState %= 200;
}
