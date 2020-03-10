#pragma once

#include <list>
#include "Entities/Entity.h"


class Map
{
public:
	std::list<Entity> createMap();
	std::list<Entity> updateMap();
};

