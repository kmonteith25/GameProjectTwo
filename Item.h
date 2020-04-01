#pragma once

#include "../../Animations/AnimatedSprite.h"
class Item 
{
public:
	virtual AnimatedSprite* getSprite();
	Item(float x, float y);
	Item();
	~Item();
};

