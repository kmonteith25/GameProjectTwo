#pragma once
#include<iostream>
#include<vector>
#include<string>
#include "../Entity.h"
#include <SFML/Graphics.hpp>
class GameMap;
class Character: public Entity
{
public:
	Character();
	Character(float x, float y);
	Character(float x, float y, GameMap* gamemap);
	virtual void Update(sf::RenderWindow* Window);
	virtual void hit(int hitPoints) = 0;
	virtual int getHealth() = 0;
private:
	std::string spriteFile = "";
	virtual void animation() = 0;
	
};

