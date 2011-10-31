#ifndef _DEFINITIONS_H_
#define _DEFINITIONS_H_

// TODO
// maybe separate definitions based on relationship
const bool SUCCESS = false;
const bool FAILURE = true;

typedef unsigned char BYTE;
typedef unsigned int SpriteID;
typedef unsigned int AnimationState;

const unsigned int SCREEN_WIDTH = 640;
const unsigned int SCREEN_HEIGHT = 480;
const unsigned int SCREEN_BPP = 32;
const unsigned int FRAMERATE = 20;

const int GENERAL_VELOCITY = 1;

enum
{
	SPRITEID_MAINIDLE1 = 0,
	SPRITEID_MAINIDLE2,
	SPRITEID_MAINLEFT1,
	SPRITEID_MAINRIGHT1,
	SPRITEID_SIZE,
};

enum
{
	ANIMATIONSTATE_IDLE = 0,
	ANIMATIONSTATE_LEFT,
	ANIMATIONSTATE_RIGHT,
	ANIMATIONSTATE_UP,
	ANIMATIONSTATE_DOWN,
	ANIMATIONSTATE_OTHER1,
	ANIMATIONSTATE_OTHER2,
	ANIMATIONSTATE_OTHER3,
	ANIMATIONSTATE_SIZE,
};


#endif
