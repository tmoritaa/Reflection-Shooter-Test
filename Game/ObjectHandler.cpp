#include "ObjectHandler.h"
#include "../Definitions/Definitions.h"
#include <stdlib.h>

ObjectHandler::ObjectHandler()
{
	Circle* c = new Circle;
	c->x = SCREEN_WIDTH/2;
	c->y = SCREEN_HEIGHT/2;
	c->r = 10;

	SpriteID** mainAnimationList;
	mainAnimationList = (SpriteID**) malloc(sizeof(SpriteID*)*ANIMATIONSTATE_SIZE);
	
	// for now enter number of AnimationFrames manually.
	// Later parse file (maybe)
	SpriteID* mainAnimationIdle = (SpriteID*) malloc(sizeof(SpriteID)*2);
	
	SpriteID* mainAnimationLeft = (SpriteID*) malloc(sizeof(SpriteID)*1);

	SpriteID* mainAnimationRight = (SpriteID*) malloc(sizeof(SpriteID)*1);

	for (int i = 0; i < 2; i++)
	{
		mainAnimationIdle[i] = (SPRITEID_MAINIDLE1+i);
	}

	for (int i = 0; i < 1; i++)
	{
		mainAnimationLeft[i] = (SPRITEID_MAINLEFT1+i);
	}

	for (int i = 0; i < 1; i++)
	{
		mainAnimationRight[i] = (SPRITEID_MAINRIGHT1+i);
	}

	mainAnimationList[ANIMATIONSTATE_IDLE] = mainAnimationIdle;
	mainAnimationList[ANIMATIONSTATE_LEFT] = mainAnimationLeft;
	mainAnimationList[ANIMATIONSTATE_RIGHT] = mainAnimationRight;
	
	int* mainAnimationSize = (int*) malloc(ANIMATIONSTATE_SIZE*sizeof(AnimationState));

	for (int i = 0; i < ANIMATIONSTATE_SIZE; i++)
	{
		mainAnimationSize[i] = 0;
	}

	mainAnimationSize[ANIMATIONSTATE_IDLE] = 2;
	mainAnimationSize[ANIMATIONSTATE_LEFT] = 1;
	mainAnimationSize[ANIMATIONSTATE_RIGHT] = 1;

	m_main = new Object(c, mainAnimationList, mainAnimationSize);
}

Object* ObjectHandler::GetMain()
{
	return m_main;
}
