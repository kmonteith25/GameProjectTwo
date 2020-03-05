#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
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
	

};

