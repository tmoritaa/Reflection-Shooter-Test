#include "Logic.h"
#include <list>

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
	std::list<Object*>* objectList = m_pObjectHandler->GetObjectList();

	for (std::list<Object*>::iterator i = objectList->begin(); i != objectList->end(); i++)
	{
		(*i)->Move();
	}
}
