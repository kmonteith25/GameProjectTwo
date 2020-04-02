#include "ItemFactory.h"

Item* ItemFactory::randomItem(float x, float y) {

	switch (0) {
	case 0:
		return new Potion(x, y);
		break;
	case 1:
		return new MagicPotion(x, y);
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	case 7:
		break;
	default:
		break;
	}

	
	
}