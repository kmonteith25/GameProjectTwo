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
    walkingAnimationRight.addFrame(sf::IntRect(0, 224, 32, 32));
    walkingAnimationRight.addFrame(sf::IntRect(32, 224, 32, 32));
    walkingAnimationRight.addFrame(sf::IntRect(64, 224, 32, 32));

    walkingAnimationLeft.setSpriteSheet(texture);
    walkingAnimationLeft.addFrame(sf::IntRect(0, 160, 32, 32));
    walkingAnimationLeft.addFrame(sf::IntRect(32, 160, 32, 32));
    walkingAnimationLeft.addFrame(sf::IntRect(64, 160, 32, 32));

    walkingAnimationUp.setSpriteSheet(texture);
    walkingAnimationUp.addFrame(sf::IntRect(0, 128, 32, 32));
    walkingAnimationUp.addFrame(sf::IntRect(32, 128, 32, 32));
    walkingAnimationUp.addFrame(sf::IntRect(64, 128, 32, 32));
    walkingAnimationUp.addFrame(sf::IntRect(32, 128, 32, 32));

    walkingAnimationDown.setSpriteSheet(texture);
    walkingAnimationDown.addFrame(sf::IntRect(0, 192, 32, 32));
    walkingAnimationDown.addFrame(sf::IntRect(32, 192, 32, 32));
    walkingAnimationDown.addFrame(sf::IntRect(64, 192, 32, 32));
    walkingAnimationDown.addFrame(sf::IntRect(32, 192, 32, 32));

    currentAnimation = walkingAnimationDown;
    sprite.play(currentAnimation);
    sprite.stop();
}

void Hero::animation()
{
}
