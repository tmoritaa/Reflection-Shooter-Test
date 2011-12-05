#include "Logic.h"
#include <list>
#include <stdio.h>

using namespace std;

Logic::Logic(ObjectHandler* _pObjectHandler)
{
	m_pObjectHandler = _pObjectHandler;
}

void Logic::MoveObjects()
{
	// TODO:
	// get Object list from ObjectHandler
	// for now just get pointer to main
	//Object* main = m_pObjectHandler->GetMain();
	list<Object*>* objectList = m_pObjectHandler->GetObjectList();

	for (list<Object*>::iterator i = objectList->begin(); i != objectList->end(); i++)
	{
		(*i)->Move();
	}
}

void Logic::DetectCollision()
{
// objects that must be checked for collision
// main object with enemy objects and enemy bullets
// enemy objects and ally bullets
// For now just implement main object check with enemy objects
// TODO: add rest of collision

	// collision detection for main unit with enemy list
	list<Object*>* enemyObjectList = m_pObjectHandler->GetEnemyObjectList();	
	Object* mainObject = (Object*)m_pObjectHandler->GetMain();
	
	for (list<Object*>::iterator i = enemyObjectList->begin(); i != enemyObjectList->end(); i++)
	{
		if (mainObject->CheckCollision(*i))
		{
			printf("Object has collided\n");	
		}
	}
}
