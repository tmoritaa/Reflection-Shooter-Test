// TODO:
// Create object creation factory for specific objects (mainObjects, enemyObject, etc.)
// Replace object init code with factory calls


#include "ObjectHandler.h"
#include "../Objects/CircleObject.h"
#include "../Objects/EnemyCircleObject.h"
#include "../Objects/RectObject.h"
#include "Strategy/MovementStrategy/MovementStrategyHeaders.h"
#include <stdlib.h>
#include <cassert>

using namespace std;

ObjectHandler::~ObjectHandler()
{
	for (list<Object*>::iterator i = m_objectList.begin(); i != m_objectList.end(); i++)
	{
		delete (*i);
		*i = NULL;
	}
}

CircleObject* ObjectHandler::GetMain()
{
	return m_main;
}

list<Object*>* ObjectHandler::GetObjectList()
{
	return &m_objectList;
}

list<Object*>* ObjectHandler::GetEnemyObjectList()
{
	return &m_enemyObjectList;
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
	initEnemyOne();
}

void ObjectHandler::initEnemyOne()
{
	Circle c;
	c.x = SCREEN_WIDTH/2;
	c.y = SCREEN_HEIGHT/2;
	c.r = 10;

	int* mainAnimationSize = (int*) malloc(ANIMATIONSTATE_SIZE*sizeof(AnimationState));
	SpriteID** mainAnimationList = (SpriteID**) malloc(sizeof(SpriteID*)*ANIMATIONSTATE_SIZE);

	string spriteNames[] = {"enemy1idle1"};
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

	LRMovementStrategy* mvStrat = new LRMovementStrategy;

	EnemyCircleObject* enemyOne = new EnemyCircleObject(c, mainAnimationList, mainAnimationSize, mvStrat);
	m_objectList.push_back((Object*)enemyOne);
	m_enemyObjectList.push_back((Object*)enemyOne);
}

void ObjectHandler::initMain()
{
	Circle c;
	c.x = SCREEN_WIDTH/6;
	c.y = SCREEN_HEIGHT/6;
	c.r = 10;

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

	m_main = new CircleObject(c, mainAnimationList, mainAnimationSize);
	m_objectList.push_back((Object*)m_main);
}
