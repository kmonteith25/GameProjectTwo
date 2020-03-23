#include "Block.h"


Block::Block(float x, float y) {
    xPosition = x;
    yPosition = y;
    setup();
    startAnimation();
}

Block::Block() {
}

Block::~Block()
{
}

int Block::getHealth() {
    return health;
}

void Block::Move(string direction) {
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

void Block::MoveLeft() {
    currentAnimation = &walkingAnimationLeft;
    movement.x -= speed;
    startAnimation();
}

void Block::MoveRight() {
    movement.x += speed;
    currentAnimation = &walkingAnimationRight;
    startAnimation();
}

void Block::MoveDown() {
    movement.y += speed;
    currentAnimation = &walkingAnimationDown;
    startAnimation();
}

void Block::hit()
{
}

void Block::MoveUp() {
    movement.y -= speed;
    currentAnimation = &walkingAnimationUp;
    startAnimation();
}

void Block::startAnimation() {
    sprite.play((*currentAnimation));
    animation_playing = true;
}


AnimatedSprite* Block::getSprite() {
    return &sprite;
}

void Block::Update() {
    startAnimation();
    sf::Time frameTime = frameClock.restart();
    /* movement = movement * frameTime.asSeconds();
    sf::FloatRect bounds = getSprite().getGlobalBounds();
    bounds.left += movement.x;
    bounds.top += movement.y;
    if (!mapObject->checkCollision(bounds)) {
        sprite.move(movement);

    }
    sprite.update(frameTime);

    movement.x = 0.0f;
    movement.y = 0.0f; */
    getSprite()->setColor(color);
    if (colorClock.getElapsedTime().asSeconds() > .25) {
        color = sf::Color(255, 255, 255, 255);
    }
    sprite.update(frameTime);
}

void Block::setup() {
    spriteFile = "assets/sprites/pokemon.png"; // Sprite commented out untill added sprite for each specific pokemon 
    texture.loadFromFile(spriteFile);
    sprite.setFrameTime(sf::seconds(0.1));
    sprite.setScale(1.5f, 1.5f);
    sprite.setPosition(xPosition, yPosition);


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
    walkingAnimationDown.addFrame(sf::IntRect(0, 0, 32, 32));
    walkingAnimationDown.addFrame(sf::IntRect(0, 160, 32, 32));
    walkingAnimationDown.addFrame(sf::IntRect(0, 192, 32, 32));

    currentAnimation = &walkingAnimationDown;
    sprite.play((*currentAnimation));
    //sprite.stop();
}

void Block::hit(int hitPoints) {
    health -= hitPoints;
    color = sf::Color::Red;
    colorClock.restart();
}

void Block::animation()
{
}