#pragma once
#include "../Character.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../../../Animations/AnimatedSprite.h"
#include <string>
#include "../../../Magic.h"

using namespace std;

class Hero : public Character
{
public:
	Hero(GameMap* map);
	Hero();
	~Hero();

	int getHealth();

	void setMoving(bool move);

	bool isMoving();

	void hit(int hitPoints);

	bool isWin();

	bool winLocation();

	void Move(string direction);

	void MoveLeft();
	void MoveRight();

	void MoveDown();

	void MoveUp();
	void Shoot();
	void startAnimation();
	void Draw(sf::RenderWindow* Window);
	bool collision(Entity* Object2);
	void resetDistance();
	void Update(bool keyPress, sf::View* View);
	void changeView(sf::View* View);
	void setPositionInitial();
	AnimatedSprite* getSprite();
	
private:
	Animation* currentAnimation;
	Animation walkingAnimationRight;
	Animation walkingAnimationLeft;
	Animation walkingAnimationUp;
	Animation walkingAnimationDown;
	sf::Vector2f movement;
	sf::Clock frameClock;
	float speed = 70.f;

	AnimatedSprite sprite;

	std::string spriteFile;

	sf::Texture texture;
	float distanceX = 0;
	float distanceY = 0;
	float startDistanceX = 0;
	float startDistanceY = 0;
	bool moving = false;
	bool animation_playing = false;
	GameMap* mapObject;
	void setup();
	void animation();
	

	vector<Magic*> shots;
	sf::Color color;
	sf::Clock colorClock;
	string direction = "down";


	int health = 100;
	int kills = 0;
	
	void setKills(int kills);

};
