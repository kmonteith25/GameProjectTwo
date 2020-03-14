#include "Tree.h"


Tree::Tree(float x, float y) {
    xPosition = x;
    yPosition = y;
    setup();
    startAnimation();
}

Tree::~Tree() {

}

AnimatedSprite Tree::getSprite() {
    return sprite;
}

void Tree::startAnimation() {
    sprite.play(currentAnimation);
    animation_playing = true;
}

void Tree::Update() {
    sf::Time frameTime = frameClock.restart();
    movement.x = 0.0f;
    movement.y = 0.0f;
    sprite.move(movement * frameTime.asSeconds());
    sprite.update(frameTime);


}

void Tree::setup() {
    spriteFile = "assets/sprites/shrubs.png";
    texture.loadFromFile(spriteFile);
    sprite.setFrameTime(sf::seconds(6));
    //sprite.setScale(.5f, .5f);
    sprite.setPosition(xPosition, yPosition);


    currentAnimation.setSpriteSheet(texture);
    currentAnimation.addFrame(sf::IntRect(50, 192, 45, 65));
}

void Tree::animation()
{
}