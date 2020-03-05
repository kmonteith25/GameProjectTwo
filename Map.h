#pragma once

#include <list>
#include "GameElement.h"


class Map
{
public:
	std::list<GameElement> createMap();
	std::list<GameElement> updateMap();
};

