#pragma once
#include "../Entities/Items/MagicPotion.h"
#include "../Entities/Items/Potion.h"
#include "../Entities/Items/Item.h"
#include "../Entities/Items/Item.h"

class ItemFactory
{
public:
	ItemFactory();
	~ItemFactory();
	static Item* randomItem(float x,float y);
private:

};

