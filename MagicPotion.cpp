#include "MagicPotion.h"

MagicPotion::MagicPotion(float x, float y) {
    xPosition = x;
    yPosition = y;
    setup();
    startAnimation();
}

MagicPotion::~MagicPotion() {

}

AnimatedSprite* MagicPotion::getSprite() {
    return &sprite;
}

void MagicPotion::startAnimation() {
    sprite.play(currentAnimation);
    animation_playing = true;
}

void MagicPotion::Update() {

}

void MagicPotion::setup() {
    spriteFile = "assets/sprites/potionSprites.png";
    texture.loadFromFile(spriteFile);
    sprite.setFrameTime(sf::seconds(6));
    sprite.setScale(.5f, .5f);
    sprite.setPosition(xPosition, yPosition);


    currentAnimation.setSpriteSheet(texture);
    currentAnimation.addFrame(sf::IntRect(96, 196, 48, 48));
}

void MagicPotion::animation()
{
}

void MagicPotion::setLocation(float x, float y)
{
    sprite.setPosition(x, y);
    xPosition = x;
    yPosition = y;
}