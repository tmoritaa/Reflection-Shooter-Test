#include "EnemyCircleObject.h"

EnemyCircleObject::EnemyCircleObject(Circle _c, SpriteID** _pAnimationList, int* _pAnimationListSize, MovementStrategy* _movementStrategy)
:	CircleObject(_c, _pAnimationList, _pAnimationListSize),
	m_movementStrategy(_movementStrategy)
{}

EnemyCircleObject::~EnemyCircleObject()
{
	delete m_movementStrategy;
}


void EnemyCircleObject::Move()
{
	m_movementStrategy->Execute(m_velX, m_velY);

	CircleObject::Move();
}

