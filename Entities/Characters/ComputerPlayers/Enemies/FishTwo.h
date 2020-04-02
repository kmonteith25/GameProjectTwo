#pragma once
#include "../../Character.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../../../../Animations/AnimatedSprite.h"
#include <string>
#include "../../../../GameMap.h"
#include "../../../../Magic.h"
using namespace std;
class GameMap;
class FishTwo: public Character
{
public:
	FishTwo(float x, float y);
	FishTwo(float x, float y, GameMap* gamemap);
	FishTwo();
	~FishTwo();

	int getHealth();

	void generateItem();

	void hit(int hitPoints);

	void Move(string direction);

	void setMoving(bool move);

	bool isMoving();

	void MoveLeft();
	void MoveRight();

	void MoveDown();

	void MoveUp();
	void startAnimation();
	void Update(sf::RenderWindow* Window);

	Item* dropItem();

	void resetDistance();
	AnimatedSprite* getSprite();
	void followEnemy();
	void randomMove();
private:
	Animation* currentAnimation;
	Animation walkingAnimationRight;
	Animation walkingAnimationLeft;
	Animation walkingAnimationUp;
	Animation walkingAnimationDown;
	sf::Vector2f movement;
	sf::Clock frameClock;
	float speed = 25.f;

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
	void Shoot();
	float xPosition;
	void animation();
	float yPosition;

	sf::Color color;
	sf::Clock colorClock;
	int health = 50;

	string direction = "down";
	vector<Magic*> shots;

	Item* itemHold;
};


