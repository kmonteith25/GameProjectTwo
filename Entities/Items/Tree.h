#pragma once

#include "../Items/Item.h"
#include "../../Animations/AnimatedSprite.h"
#include <SFML\System\Clock.hpp>

class Tree : public Item
{
public:
	Tree(float x, float y);
	~Tree();
	void startAnimation();
	void Update();
	AnimatedSprite getSprite();
private:
	Animation currentAnimation;
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
	float xPosition;
	float yPosition;
};
