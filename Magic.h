#pragma once
#include "Entities/Entity.h"
#include <SFML\System\Clock.hpp>
#include "GameMap.h"
#include <SFML/Audio.hpp>

class Magic :public Entity
{
public:
	Magic(float x, float y);
	Magic(float x, float y, string direction);
	Magic();
	~Magic();

	void setSpeed(string direction);

	void Move(string direction);

	void MoveLeft();
	void MoveRight();

	void MoveDown();

	void MoveUp();
	void startAnimation();
	void Update();
	float getDistance();
	AnimatedSprite* getSprite();
private:
	Animation* currentAnimation;
	Animation shootingAnimation;

	sf::Vector2f movement;
	sf::Clock frameClock;
	float speed = 80.f;

	AnimatedSprite sprite;

	std::string spriteFile;

	sf::Texture texture;
	float distanceX = 0;
	float distanceY = 0;

	bool animation_playing = false;
	GameMap* mapObject;
	void setup();
	float xPosition;
	void animation();
	float yPosition;

	int speedX, speedY = 0;
};

