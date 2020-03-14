#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Animations/Animation.h"
#include "Animations/AnimatedSprite.h"
#include "Entities/Characters/Hero/Hero.h"
#include "Entities/Items/Potion.h"
#include "Entities/Items/Tree.h"
#include "Map.h"

using namespace std;
class Game
{
public:
	Game();
	~Game();
	void setup();
	void userInputControlManager();
	void InitMap();
	void initMap();
	void DrawMap();
	void gameLoop();
private:
	sf::RenderWindow Window;
	std::vector<Entity*> v = { new Tree(500,500),new Tree(500,200), new Tree(300,300) };
	sf::View View;
	sf::FloatRect fBounds;
	Map* map = new Map();
	

};

