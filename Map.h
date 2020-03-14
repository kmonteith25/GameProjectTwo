#pragma once

#include <vector>
#include "Entities/Entity.h"
#include <iostream>

class Map
{
public:
	void createMap();
	std::vector<Entity> updateMap();
	void AddToMap(Entity* entity);
	bool checkCollision(sf::FloatRect rect);
private:
	std::vector<Entity*> returnMap();
	std::vector<Entity*> Map;
};

