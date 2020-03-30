#include "Magic.h"


Magic::Magic(float x, float y)
{
}

Magic::Magic(float x, float y, string direction) {
    xPosition = x;
    yPosition = y;
    setSpeed(direction);
    setup();
    startAnimation();
   
        
}

Magic::Magic() {
}

Magic::~Magic()
{
}

void Magic::setSpeed(string direction) {
    speedX, speedY = 0;
    if (direction == "left") {
        speedX = -250;
        sprite.setRotation(90.0f);
    }
    else if (direction == "right") {
        speedX = 250;
        sprite.setRotation(90.0f);
    }
    else if (direction == "up") {
        speedY = -250;

    }
    else if (direction == "down") {
        speedY = 250;
    }

}

void Magic::Move(string direction) {
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

void Magic::MoveLeft() {
    movement.x -= speed;
    startAnimation();
}

void Magic::MoveRight() {
    movement.x += speed;
    startAnimation();
}

void Magic::MoveDown() {
    movement.y += speed;
    startAnimation();
}

void Magic::MoveUp() {
    movement.y -= speed;
    startAnimation();
}

void Magic::startAnimation() {
    sprite.play((*currentAnimation));
    animation_playing = true;

}


AnimatedSprite* Magic::getSprite() {
    return &sprite;
}

void Magic::Update() {
    startAnimation();
    movement.x = speedX;
    movement.y = speedY;
    sf::Time frameTime = frameClock.restart();
    movement = movement * frameTime.asSeconds();
    sf::FloatRect bounds = getSprite()->getGlobalBounds();
    bounds.left += movement.x;
    bounds.top += movement.y;
    distanceX += movement.x;
    distanceY += movement.y;
    sprite.move(movement);
    sprite.update(frameTime);
}

float Magic::getDistance() {
    return distanceX + distanceY;
}

void Magic::setup() {
    spriteFile = "assets/sprites/magic.png"; 
    texture.loadFromFile(spriteFile);
    sprite.setFrameTime(sf::seconds(0.1));
    sprite.setPosition(xPosition, yPosition);


    shootingAnimation.setSpriteSheet(texture);
    shootingAnimation.addFrame(sf::IntRect(164, 176, 25,25));
    
    currentAnimation = &shootingAnimation;
    
    sprite.play((*currentAnimation));
    //sprite.stop();
}

void Magic::animation()
{
}