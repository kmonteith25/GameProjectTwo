#include "FireChicken.h"
#include "../../GameMap.h"

FireChicken::FireChicken(float x, float y) {
    movement.x = 0;
    movement.y = 0;
    xPosition = x;
    yPosition = y;
    setup();
    startAnimation();
}

FireChicken::FireChicken(float x, float y,GameMap* gamemap) {
    movement.x = 0;
    movement.y = 0;
    xPosition = x;
    yPosition = y;
    setup();
    startAnimation();
    this->mapObject = gamemap;
}

FireChicken::FireChicken() {
    movement.x = 0;
    movement.y = 0;
}

FireChicken::~FireChicken()
{
}

int FireChicken::getHealth() {
    return health;
}

void FireChicken::hit(int hitPoints) {
    health -= hitPoints;
    color = sf::Color::Red;
    colorClock.restart();
}

void FireChicken::Move(string direction) {
    sprite.setOrigin({ sprite.getLocalBounds().width/2, 0 });
    sprite.setScale({ 1, 1 });
    if (!isMoving()) {
        setMoving(true);
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

}

void FireChicken::setMoving(bool move) {
    moving = move;
}

bool FireChicken::isMoving() {
    return moving;
}

void FireChicken::MoveLeft() {
    currentAnimation = &walkingAnimationLeft;
    movement.x -= speed;
    startAnimation();
    
}

void FireChicken::MoveRight() {
    movement.x += speed;
    currentAnimation = &walkingAnimationRight;
    sprite.setOrigin({ sprite.getLocalBounds().width / 2, 0 });
    sprite.setScale({ -1, 1 });
    startAnimation();
}

void FireChicken::MoveDown() {
    movement.y += speed;
    currentAnimation = &walkingAnimationDown;
    startAnimation();
}

void FireChicken::MoveUp() {
    movement.y -= speed;
    currentAnimation = &walkingAnimationUp;
    startAnimation();
}

void FireChicken::startAnimation() {
    sprite.play((*currentAnimation));
    animation_playing = true;
}


AnimatedSprite* FireChicken::getSprite() {
    return &sprite;
}

void FireChicken::randomMove() {
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int randomMove = (rand() % 4)+1;
    
    switch (randomMove) {
    case 1:
        Move("left");
        break;
    case 2:
        Move("right");
        break;
    case 3:
        Move("up");
        break;
    case 4:
        Move("down");
        break;

    }
    

}

void FireChicken::Update() {
    sf::Vector2f tempMove;
    sf::Time frameTime = frameClock.restart();
    tempMove = movement * frameTime.asSeconds();
    if (!isMoving()) {
        randomMove();
    }
    sf::FloatRect bounds = getSprite()->getGlobalBounds();
    bounds.left += tempMove.x;
    bounds.top += tempMove.y;
    distanceX += tempMove.x;
    distanceY += tempMove.y;
    if (!mapObject->checkCollisionForEnemy(bounds)) {

        sprite.move(tempMove);
    }
    getSprite()->setColor(color);
    if (colorClock.getElapsedTime().asSeconds() > .25) {
        color = sf::Color(255, 255, 255, 255);
    }
    sprite.update(frameTime);
    
    if (abs(distanceX) >= 32 || abs(distanceY) >= 32) {
        movement.x = 0;
        movement.y = 0;
        sprite.stop();
        resetDistance();
        setMoving(false);
        
    }
    
    getSprite()->setColor(color);
    if (colorClock.getElapsedTime().asSeconds() > .25) {
        color = sf::Color(255, 255, 255, 255);
    }
    sprite.update(frameTime);
}

void FireChicken::resetDistance() {
    sf::FloatRect bounds = getSprite()->getGlobalBounds();
    distanceX = 0;
    distanceY = 0;
    startDistanceX = bounds.left;
    startDistanceY = bounds.top;
}

void FireChicken::setup() {
    spriteFile = "assets/sprites/pokemon.png";
    texture.loadFromFile(spriteFile);
    sprite.setFrameTime(sf::seconds(0.4));
    sprite.setPosition(xPosition,yPosition);


    walkingAnimationRight.setSpriteSheet(texture);
    walkingAnimationRight.addFrame(sf::IntRect(0, 64, 32, 32));
    walkingAnimationRight.addFrame(sf::IntRect(0, 224, 32, 32));
    walkingAnimationRight.addFrame(sf::IntRect(0, 256, 32, 32));

    walkingAnimationLeft.setSpriteSheet(texture);
    walkingAnimationLeft.addFrame(sf::IntRect(0, 64, 32, 32));
    walkingAnimationLeft.addFrame(sf::IntRect(0, 224, 32, 32));
    walkingAnimationLeft.addFrame(sf::IntRect(0, 256, 32, 32));

    walkingAnimationUp.setSpriteSheet(texture);
    walkingAnimationUp.addFrame(sf::IntRect(0, 32, 32, 32));
    walkingAnimationUp.addFrame(sf::IntRect(0, 96, 32, 32));
    walkingAnimationUp.addFrame(sf::IntRect(0, 128, 32, 32));

    walkingAnimationDown.setSpriteSheet(texture);
    walkingAnimationDown.addFrame(sf::IntRect(0, 0, 32, 32));
    walkingAnimationDown.addFrame(sf::IntRect(0,160, 32, 32));
    walkingAnimationDown.addFrame(sf::IntRect(0, 192, 32, 32));

    currentAnimation = &walkingAnimationDown;
    sprite.play((*currentAnimation));
    //sprite.stop();
}

void FireChicken::animation()
{
}

