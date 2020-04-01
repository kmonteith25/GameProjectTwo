#pragma once

#include "../Entity.h"

class Item : public Entity
{
public:
	virtual AnimatedSprite* getSprite();
	Item(float x, float y);
	Item();
	~Item();
	virtual void setLocation(float x, float y);
};

