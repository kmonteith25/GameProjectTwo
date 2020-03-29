#pragma once
#include "../Entity.h"
class GameMap;
class Character: public Entity
{
public:
	Character();
	Character(float x, float y);
	Character(float x, float y, GameMap* gamemap);
	virtual void Update();
	virtual void hit(int hitPoints) = 0;
	virtual int getHealth() = 0;
private:
	std::string spriteFile = "";
	virtual void animation() = 0;
	
};

