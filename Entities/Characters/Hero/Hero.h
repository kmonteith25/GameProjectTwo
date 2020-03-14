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

	void Move(string direction);

	void MoveLeft();
	void MoveRight();

	void MoveDown();

	void MoveUp();
	void startAnimation();
	bool collision(Entity* Object2);
	void Update(bool keyPress);
	AnimatedSprite getSprite();
private:
	Animation currentAnimation;
	Animation walkingAnimationRight;
	Animation walkingAnimationLeft;
	Animation walkingAnimationUp;
	Animation walkingAnimationDown;
	sf::Vector2f movement;
	sf::Clock frameClock;
	float speed = 80.f;

	AnimatedSprite sprite;

	std::string spriteFile;

	sf::Texture texture;
	int distanceX = 0;
	int distanceY = 0;

	bool animation_playing = false;
	Map* mapObject;
	void setup();
	void animation();
};
