#pragma once
#include "../Character.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../../../Animations/AnimatedSprite.h"
#include <string>
#include "../../../Map.h"
using namespace std;

class Hero : public Character
{
public:
	Hero(Map* map);
	Hero();
	~Hero();

	void setMoving(bool move);

	bool isMoving();

	void Move(string direction);

	void MoveLeft();
	void MoveRight();

	void MoveDown();

	void MoveUp();
	void startAnimation();
	bool collision(Entity* Object2);
	void resetDistance();
	void Update(bool keyPress);
	AnimatedSprite getSprite();
private:
	Animation* currentAnimation;
	Animation walkingAnimationRight;
	Animation walkingAnimationLeft;
	Animation walkingAnimationUp;
	Animation walkingAnimationDown;
	sf::Vector2f movement;
	sf::Clock frameClock;
	float speed = 150.f;

	AnimatedSprite sprite;

	std::string spriteFile;

	sf::Texture texture;
	float distanceX = 0;
	float distanceY = 0;
	float startDistanceX = 0;
	float startDistanceY = 0;
	bool animation_playing = false;
	Map* mapObject;
	void setup();
	void animation();
	bool moving = false;
};
