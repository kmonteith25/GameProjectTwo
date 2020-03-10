#pragma once
#include "../Character.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../../../Animations/AnimatedSprite.h"
class Hero : public Character
{
public:
	Hero();
	~Hero();

	void MoveLeft();
	void MoveRight();

	void MoveDown();

	void MoveUp();
	void startAnimation();
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

	void setup();
	void animation();
};
