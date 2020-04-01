#pragma once


#include "../Entities/Items/Item.h"

class ItemFactory
{
public:
	ItemFactory();
	~ItemFactory();
	static Item* randomItem(float x,float y);
private:

};

