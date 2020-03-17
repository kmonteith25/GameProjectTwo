#pragma once
#include <string>
#include "../Animations/AnimatedSprite.h"
class Entity
{
public:
	~Entity();
	Entity();
	Entity(float x, float y);
	virtual void Update();
	virtual AnimatedSprite getSprite();
private:
	std::string spriteFile = "";
	virtual void animation() = 0;
};

