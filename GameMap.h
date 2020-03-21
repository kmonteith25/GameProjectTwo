#pragma once

#include <vector>
#include "Entities/Entity.h"
#include "Entities/Items/Tree.h"
#include "Entities/Characters/Character.h"
#include "Entities/Items/Potion.h"
#include <iostream>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics.hpp>
#include "Factories/ItemFactory.h"
#include "Factories/EnemyFactory.h"
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
	void setupEnemySpawnLocations();
	void spawnEnemies();
	void drawEnemies(sf::RenderWindow* Window);
private:
	std::vector<Entity*> returnMap();

	std::vector<tmx::FloatRect> enemySpawnLocations;
	std::vector<vector<Character*>> enemyGroups;
	string collisionNames[6] = {"trees","house","water","wall","hill","car"};

	int MAX_ENEMIES_PER_GROUP = 3;
	tmx::Map map;
	MapLayer* layerZero;
	MapLayer* layerOne;
	MapLayer* layerTwo; 
	MapLayer* layerThree;
	MapLayer* layerFour;
	tmx::ObjectGroup objectLayer;
};

