#pragma once
#include <string>

class Entity
{
public:
private:
	std::string spriteFile = "";
	virtual void animation() = 0;
};

