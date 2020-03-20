#include "FishTwo.h"

FishTwo::FishTwo(float x, float y) {
    xPosition = x;
    yPosition = y;
    setup();
    startAnimation();
}

FishTwo::FishTwo() {
}

FishTwo::~FishTwo()
{
}

void FishTwo::Move(string direction) {
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

void FishTwo::MoveLeft() {
    currentAnimation = &walkingAnimationLeft;
    movement.x -= speed;
    startAnimation();
}

void FishTwo::MoveRight() {
    movement.x += speed;
    currentAnimation = &walkingAnimationRight;
    startAnimation();
}

void FishTwo::MoveDown() {
    movement.y += speed;
    currentAnimation = &walkingAnimationDown;
    startAnimation();
}

void FishTwo::MoveUp() {
    movement.y -= speed;
    currentAnimation = &walkingAnimationUp;
    startAnimation();
}

void FishTwo::startAnimation() {
    sprite.play((*currentAnimation));
    animation_playing = true;
}


AnimatedSprite FishTwo::getSprite() {
    return sprite;
}

void FishTwo::Update() {
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

    sprite.update(frameTime);
}

void FishTwo::setup() {
    spriteFile = "assets/sprites/pokemon.png"; // Sprite commented out untill added sprite for each specific pokemon 
    texture.loadFromFile(spriteFile);
    sprite.setFrameTime(sf::seconds(0.1));
    sprite.setScale(1.5f, 1.5f);
    sprite.setPosition(xPosition, yPosition);


    walkingAnimationDown.setSpriteSheet(texture);
    walkingAnimationDown.addFrame(sf::IntRect(448, 0, 32, 32));
    walkingAnimationDown.addFrame(sf::IntRect(448, 32, 32, 32));
    walkingAnimationDown.addFrame(sf::IntRect(448, 96, 32, 32));

    currentAnimation = &walkingAnimationDown;
    sprite.play((*currentAnimation));
    //sprite.stop();
}

void FishTwo::animation()
{
}