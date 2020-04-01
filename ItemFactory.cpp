#include "ItemFactory.h"

#include "../Entities/Items/Potion.h"
Item* ItemFactory::randomItem(float x, float y) {

	switch (1) {
	case 0:
		//potion = new Poition(x, y, gamemap);

		break;
	case 1:
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

	return new Potion(x,y);
}