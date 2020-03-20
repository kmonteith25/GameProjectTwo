#include "Hero.h"


Hero::Hero(GameMap* map)
{
    mapObject = map;
    setup();
}

Hero::~Hero()
{
}

void Hero::setMoving(bool move) {
    moving = move;
}

bool Hero::isMoving() {
    return moving;
}

void Hero::Move(string direction) {
    if (!isMoving()) {
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
        setMoving(true);
    }
}

void Hero::MoveLeft() {
    currentAnimation = &walkingAnimationLeft;
    movement.x -= speed;
    startAnimation();
}

void Hero::MoveRight() {
    movement.x += speed;
    currentAnimation = &walkingAnimationRight;
    startAnimation();
}

void Hero::MoveDown() {
    movement.y += speed;
    currentAnimation = &walkingAnimationDown;
    startAnimation();
}

void Hero::MoveUp() {
    movement.y = -speed;
    currentAnimation = &walkingAnimationUp;
    startAnimation();
}

void Hero::startAnimation() {
    sprite.play((*currentAnimation));
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

void Hero::resetDistance() {
    sf::FloatRect bounds = getSprite().getGlobalBounds();
    distanceX = 0;
    distanceY = 0; 
    startDistanceX = bounds.left;
    startDistanceY = bounds.top;
}
void Hero::Update(bool keyPress) {
    sf::Vector2f tempMove;
    sf::Time frameTime = frameClock.restart();
    tempMove = movement * frameTime.asSeconds();
    sf::FloatRect bounds = getSprite().getGlobalBounds();
    bounds.left += tempMove.x;
    bounds.top += tempMove.y;
    distanceX += tempMove.x;
    distanceY += tempMove.y;
    if (!mapObject->checkCollision(bounds)) {
        sprite.move(tempMove);
        
    }
    sprite.update(frameTime);
    if (abs(distanceX) >= 32 || abs(distanceY) >= 32) {
        movement.x = 0;
        movement.y = 0;
        sprite.stop();
        resetDistance();
        setMoving(false);
    }
}

void Hero::setPosition(float x, float y) {
    sprite.setPosition(x,y);
}

void Hero::setup() {
    spriteFile = "assets/sprites/trainerSprites.png";
    texture.loadFromFile(spriteFile);
    sprite.setFrameTime(sf::seconds(0.15));
    sprite.setScale(1.f, 1.f);
    


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

    currentAnimation = &walkingAnimationDown;
    sprite.play((*currentAnimation));
    sprite.stop();
}

void Hero::animation()
{
}
