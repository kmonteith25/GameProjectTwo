#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <iostream>
#include <tmxlite/Map.hpp>
#include "Entities/Characters/Hero/Hero.h"
#include <TGUI/TGUI.hpp>
class EnemyFactory;

using namespace std;
class Game
{
public:
	
	Game();
	~Game();
	void setup();
	void userInputControlManager();
	void setupGameOver();
	void setupGameWin();
	void setupKillCounter();
	void gameLoop();
private:
	sf::RenderWindow Window;
	sf::View View;
	sf::FloatRect fBounds;

	sf::Text heroScore;
	sf::Font font;
	Hero* hero;
	GameMap* map;
	tgui::TextBox::Ptr winBox = tgui::TextBox::create();
	tgui::TextBox::Ptr gameoverBox = tgui::TextBox::create();
	tgui::Label::Ptr killCounter = tgui::Label::create();
	tgui::Label::Ptr killNumber = tgui::Label::create();
};

