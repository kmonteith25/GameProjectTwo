#pragma once
#include "../Entity.h"

class Character: public Entity
{
public:
private:
	std::string spriteFile = "";
	virtual void animation() = 0;
};

