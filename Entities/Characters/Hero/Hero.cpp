#include "Hero.h"


Hero::Hero(Map* map)
{
    mapObject = map;
    setup();
}

Hero::~Hero()
{
}

void Hero::Move(string direction) {
        if (direction == "left") {
            MoveLeft();
        }
        else if (direction == "right") {
            MoveRight();
        }
        else if (direction == "up") {
            MoveUp();
        }
        else if (direction == "down") {
            MoveDown();
        }

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

bool Hero::collision(Entity* Object2) {
    sf::FloatRect bounds = getSprite().getGlobalBounds();
    float x1 = bounds.left;
    float y1 = bounds.top;
    float x2 = x1 + bounds.width;
    float y2 = y1 + bounds.height;
    sf::FloatRect bounds2 = Object2->getSprite().getGlobalBounds();
    float x1T = bounds2.left;
    float y1T = bounds2.top;
    float x2T = x1T + bounds2.width;
    float y2T = y1T + bounds2.height;

    if (x1 < x2T &&
        x2 > x1T&&
        y1 < y2T &&
        y2 > y1T) {
        return true;
    }
    return false;
}

AnimatedSprite Hero::getSprite() {
    return sprite;
}

void Hero::Update(bool keyPress) {
    sf::Time frameTime = frameClock.restart();
    movement = movement * frameTime.asSeconds();
    sf::FloatRect bounds = getSprite().getGlobalBounds();
    bounds.left += movement.x;
    bounds.top += movement.y;
    if (!mapObject->checkCollision(bounds)) {
        sprite.move(movement);
        
    }
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
