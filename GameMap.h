#pragma once

#include <vector>
#include "Entities/Entity.h"
#include "Entities/Items/Tree.h"
#include "Entities/Items/Potion.h"
#include <iostream>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics.hpp>
#include "Factories/ItemFactory.h"


#include <tmxlite/Layer.hpp>
#include <tmxlite/TileLayer.hpp>

#include "OrtoMap.h"

using namespace std;
class GameMap
{
public:
	GameMap();
	~GameMap();
	void createMap();
	std::vector<Entity> updateMap();
	void AddToMap(Entity* entity);
	vector<Entity*> GenerateFromArray(vector<vector<int>> v);
	void InitMap();
	void DrawMap(sf::RenderWindow* Window);
	bool checkCollision(sf::FloatRect rect);
	tmx::FloatRect getPlayerStartPosition();
private:
	std::vector<Entity*> returnMap();
	string collisionNames[6] = {"trees","house","water","wall","hill","car",};

	tmx::Map map;
	MapLayer* layerZero;
	MapLayer* layerOne;
	MapLayer* layerTwo; 
	MapLayer* layerThree;
	MapLayer* layerFour;
	tmx::ObjectGroup objectLayer;
};

