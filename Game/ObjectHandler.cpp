#include "ObjectHandler.h"
#include <stdlib.h>
#include <cassert>

using namespace std;

ObjectHandler::~ObjectHandler()
{
	delete m_main;
}

Object* ObjectHandler::GetMain()
{
	return m_main;
}

void ObjectHandler::SetSPVector(SPVector _spVector)
{
	m_spVector = _spVector;
}

void ObjectHandler::Init()
{
	assert(m_spVector.size() != 0);

	for (int i = 0; i < m_spVector.size(); i++)
	{
		struct SpritePath sp = m_spVector[i];
		m_spriteLibraryKeys[sp.name] = i;
	}

	initMain();
}

void ObjectHandler::initMain()
{
	Circle* c = new Circle;
	c->x = SCREEN_WIDTH/2;
	c->y = SCREEN_HEIGHT/2;
	c->r = 10;

	int* mainAnimationSize = (int*) malloc(ANIMATIONSTATE_SIZE*sizeof(AnimationState));
	SpriteID** mainAnimationList = (SpriteID**) malloc(sizeof(SpriteID*)*ANIMATIONSTATE_SIZE);

	string spriteNames[] = {"mainidle1", "mainleft1", "mainright1"};
	int animationTotal = sizeof(spriteNames)/sizeof(spriteNames[0]);

	memset(mainAnimationSize, 0, ANIMATIONSTATE_SIZE*sizeof(AnimationState));
	memset(mainAnimationList, 0, sizeof(SpriteID*)*ANIMATIONSTATE_SIZE);

	for (int i = 0; i < animationTotal; i++)
	{
		// get number of frames per animation state type
		struct SpritePath sp = m_spVector[m_spriteLibraryKeys[spriteNames[i]]];
		mainAnimationSize[i] = sp.aniLength;

		SpriteID* mainAnimationTemp = (SpriteID*) malloc(sizeof(SpriteID)*mainAnimationSize[i]);
		memset(mainAnimationTemp, 0, sizeof(SpriteID)*mainAnimationSize[i]);

		for (int j = 0; j < mainAnimationSize[i]; j++)
		{
			mainAnimationTemp[j] = m_spriteLibraryKeys[spriteNames[i]] + j;
		}

		mainAnimationList[i] = mainAnimationTemp;
	}

	m_main = new Object(c, mainAnimationList, mainAnimationSize);
}
