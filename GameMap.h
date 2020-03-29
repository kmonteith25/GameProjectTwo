#pragma once

#include <vector>
#include <iostream>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics.hpp>
#include <tmxlite/Layer.hpp>
#include <tmxlite/TileLayer.hpp>
#include "OrtoMap.h"
#include <chrono>
#include "Entities/Characters/Character.h"

using namespace std;
class GameMap
{
public:
	~GameMap();
	GameMap(sf::RenderWindow* Window);
	void createMap();
	void InitMap();
	void DrawMap(sf::RenderWindow* Window);
	bool checkCollision(sf::FloatRect rect);
	bool checkCollisionForEnemy(sf::FloatRect bounds);
	Character* checkCollisionEnemy(sf::FloatRect bounds);
	tmx::FloatRect getPlayerStartPosition();
	void setupEnemySpawnLocations();
	void spawnEnemies();
	void drawEnemies(sf::RenderWindow* Window);
	void increaseHeroKills(bool kill);
	int getHeroKills();
private:
	std::vector<tmx::FloatRect> enemySpawnLocations;
	std::array<std::array<Character*, 3>, 3> enemyGroups;
	string collisionNames[6] = {"trees","house","water","wall","hill","car"};

	int maxEnemiesGroup = 3;
	tmx::Map map;
	MapLayer* layerZero;
	MapLayer* layerOne;
	MapLayer* layerTwo; 
	MapLayer* layerThree;
	MapLayer* layerFour;
	tmx::ObjectGroup objectLayer;

	sf::RenderWindow* Window;

	int heroKills = 0;
};

