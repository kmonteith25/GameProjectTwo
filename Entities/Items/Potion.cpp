#include "Potion.h"

Potion::Potion(float x, float y) {
    xPosition = x;
    yPosition = y;
    setup();
    startAnimation();
}

Potion::~Potion() {

}

AnimatedSprite Potion::getSprite() {
    return sprite;
}

void Potion::startAnimation() {
    sprite.play(currentAnimation);
    animation_playing = true;
}

void Potion::Update() {
    sf::Time frameTime = frameClock.restart();
    movement.x = 0.0f;
    movement.y = 0.0f;
    sprite.move(movement * frameTime.asSeconds());
    sprite.update(frameTime);

    
}

void Potion::setup() {
    spriteFile = "assets/sprites/potionSprites.png";
    texture.loadFromFile(spriteFile);
    sprite.setFrameTime(sf::seconds(6));
    sprite.setScale(.5f, .5f);
    sprite.setPosition(xPosition, yPosition);


    currentAnimation.setSpriteSheet(texture);
    currentAnimation.addFrame(sf::IntRect(96, 0, 48, 48));
}

void Potion::animation()
{
}