#pragma once
#include "../Entity.h"

class Character: public Entity
{
public:
	virtual void Update();
	virtual void hit(int hitPoints) = 0;
	virtual int getHealth() = 0;
private:
	std::string spriteFile = "";
	virtual void animation() = 0;
	
};

