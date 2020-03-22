#include "Magic.h"

Magic::Magic(float x, float y) {
    xPosition = x;
    yPosition = y;
    setup();
    startAnimation();
}

Magic::Magic() {
}

Magic::~Magic()
{
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


AnimatedSprite Magic::getSprite() {
    return sprite;
}

void Magic::Update() {
    startAnimation();
    movement.x = 160.0f;
    movement.y = 0.0f;
    sf::Time frameTime = frameClock.restart();
    movement = movement * frameTime.asSeconds();
    sf::FloatRect bounds = getSprite().getGlobalBounds();
    bounds.left += movement.x;
    bounds.top += movement.y;
    //if (!mapObject->checkCollision(bounds)) {
      //  sprite.move(movement);

    //}
    sprite.move(movement);
    sprite.update(frameTime);

    

    sprite.update(frameTime);
}

void Magic::setup() {
    spriteFile = "assets/sprites/magic.png"; 
    texture.loadFromFile(spriteFile);
    sprite.setFrameTime(sf::seconds(0.1));
    sprite.setPosition(xPosition, yPosition);


    shootingAnimation.setSpriteSheet(texture);
    shootingAnimation.addFrame(sf::IntRect(164, 176, 25,25));
    
    currentAnimation = &shootingAnimation;
    sprite.setRotation(90.0f);
    sprite.play((*currentAnimation));
    //sprite.stop();
}

void Magic::animation()
{
}