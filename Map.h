#pragma once

#include <vector>
#include "Entities/Entity.h"
#include "Entities/Items/Tree.h"
#include "Entities/Items/Potion.h"
#include <iostream>
#include <SFML/Graphics/Drawable.hpp>
using namespace std;
class Map 
{
public:
	void createMap();
	std::vector<Entity> updateMap();
	void AddToMap(Entity* entity);
	vector<Entity*> GenerateFromArray(vector<vector<int>> v);
	void InitMap();
	void DrawMap();
	bool checkCollision(sf::FloatRect rect);
private:
	std::vector<Entity*> returnMap();
	std::vector<Entity*> Map;
};

