#pragma once
#include <string>
#include "../Animations/AnimatedSprite.h"
class Entity
{
public:
	virtual AnimatedSprite getSprite();
private:
	std::string spriteFile = "";
	virtual void animation() = 0;
};

