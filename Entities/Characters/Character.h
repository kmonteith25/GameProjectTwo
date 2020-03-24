#pragma once
#include<iostream>
#include<vector>
#include<string>
#include "../Entity.h"

class Character: public Entity
{
public:
	virtual void Update();





private:
	std::string spriteFile = "";
	virtual void animation() = 0;
};

//vector of items for each class 
//connect to enemy class & hero class 

