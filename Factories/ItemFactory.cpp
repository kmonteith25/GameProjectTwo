#include "ItemFactory.h"

Item* ItemFactory::randomItem(float x, float y) {
	return new Potion(x,y);
}