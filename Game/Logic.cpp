#include "Logic.h"

Logic::Logic(ObjectHandler* _pObjectHandler)
{
	m_pObjectHandler = _pObjectHandler;
}

void Logic::MoveObjects()
{
	// TODO:
	// get Object list from ObjectHandler
	// for now just get pointer to main
	Object* main = m_pObjectHandler->GetMain();

	main->Move();
}
