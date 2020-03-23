#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <iostream>
#include "Animations/Animation.h"
#include "Animations/AnimatedSprite.h"
#include "Entities/Characters/Hero/Hero.h"
#include "Entities/Items/Potion.h"
#include "Entities/Items/Tree.h"
#include "GameMap.h"
#include <tmxlite/Map.hpp>
#include "Magic.h"

class EnemyFactory;

using namespace std;
class Game
{
public:
	
	Game();
	~Game();
	void setup();
	void userInputControlManager();
	void DrawMap(vector<Entity*> v);
	void InitMap();
	void initMap();
	void DrawMap();
	void gameLoop();
private:
	sf::RenderWindow Window;
	sf::View View;
	sf::FloatRect fBounds;
	GameMap* map = new GameMap(&Window);
};

