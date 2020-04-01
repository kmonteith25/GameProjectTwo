#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <iostream>
#include <tmxlite/Map.hpp>
#include "Entities/Characters/Hero/Hero.h"

class EnemyFactory;

using namespace std;
class Game
{
public:
	
	Game();
	~Game();
	void setup();
	void userInputControlManager();
	void gameLoop();
private:
	sf::RenderWindow Window;
	sf::View View;
	sf::FloatRect fBounds;

	sf::Text heroScore;
	sf::Font font;
	Hero* hero;
	GameMap* map;
};

