#pragma once
#include "../../Character.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../../../../Animations/AnimatedSprite.h"
#include <string>
#include "../../../../GameMap.h"
using namespace std;
class GameMap;
class FireChicken : public Character
{
public:
		FireChicken(float x, float y);
		FireChicken(float x, float y,GameMap* gamemap);
		FireChicken();
		~FireChicken();

		int getHealth();

		void hit(int hitPoints);

		void Move(string direction);

		void setMoving(bool move);

		bool isMoving();

		void MoveLeft();
		void MoveRight();

		void MoveDown();

		void MoveUp();
		void startAnimation();
		void Update();
		void resetDistance();
		AnimatedSprite* getSprite();
		void randomMove();
	private:
		Animation* currentAnimation;
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
		float distanceX = 0;
		float distanceY = 0;
		float startDistanceX = 0;
		float startDistanceY = 0;
		bool moving = false;

		bool animation_playing = false;
		GameMap* mapObject;
		void setup();
		float xPosition;
		void animation();
		float yPosition;

		sf::Color color;
		sf::Clock colorClock;
		int health = 100;
	};


