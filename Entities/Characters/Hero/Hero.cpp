#include "Hero.h"


Hero::Hero()
{
    setup();
}

Hero::~Hero()
{
}

void Hero::MoveLeft() {
    currentAnimation = walkingAnimationLeft;
    movement.x -= speed;
    startAnimation();
}

void Hero::MoveRight() {
    movement.x += speed;
    currentAnimation = walkingAnimationRight;
    startAnimation();
}

void Hero::MoveDown() {
    movement.y += speed;
    currentAnimation = walkingAnimationDown;
    startAnimation();
}

void Hero::MoveUp() {
    movement.y -= speed;
    currentAnimation = walkingAnimationUp;
    startAnimation();
}

void Hero::startAnimation() {
    sprite.play(currentAnimation);
    animation_playing = true;
}

AnimatedSprite Hero::getSprite() {
    return sprite;
}

void Hero::Update(bool keyPress) {
    sf::Time frameTime = frameClock.restart();
    
    sprite.move(movement * frameTime.asSeconds());
    sprite.update(frameTime);
    
    movement.x = 0.0f;
    movement.y = 0.0f;

    if (!keyPress) {
        sprite.stop();
    }
}

void Hero::setup() {
    spriteFile = "assets/sprites/trainerSprites.png";
    texture.loadFromFile(spriteFile);
    sprite.setFrameTime(sf::seconds(0.1));
    sprite.setScale(1.5f, 1.5f);
    sprite.setPosition(100, 100);


    walkingAnimationRight.setSpriteSheet(texture);
    walkingAnimationRight.addFrame(sf::IntRect(0, 96, 32, 32));
    walkingAnimationRight.addFrame(sf::IntRect(32, 96, 32, 32));
    walkingAnimationRight.addFrame(sf::IntRect(64, 96, 32, 32));

    walkingAnimationLeft.setSpriteSheet(texture);
    walkingAnimationLeft.addFrame(sf::IntRect(0, 32, 32, 32));
    walkingAnimationLeft.addFrame(sf::IntRect(32, 32, 32, 32));
    walkingAnimationLeft.addFrame(sf::IntRect(64, 32, 32, 32));

    walkingAnimationUp.setSpriteSheet(texture);
    walkingAnimationUp.addFrame(sf::IntRect(0, 0, 32, 32));
    walkingAnimationUp.addFrame(sf::IntRect(32, 0, 32, 32));
    walkingAnimationUp.addFrame(sf::IntRect(64, 0, 32, 32));
    walkingAnimationUp.addFrame(sf::IntRect(32, 0, 32, 32));

    walkingAnimationDown.setSpriteSheet(texture);
    walkingAnimationDown.addFrame(sf::IntRect(0, 64, 32, 32));
    walkingAnimationDown.addFrame(sf::IntRect(32, 64, 32, 32));
    walkingAnimationDown.addFrame(sf::IntRect(64, 64, 32, 32));
    walkingAnimationDown.addFrame(sf::IntRect(32, 64, 32, 32));

    currentAnimation = walkingAnimationDown;
}

void Hero::animation()
{
}
