#include "Rodent.h"
#include "../../GameMap.h"
#include "../../../../Factories/ItemFactory.h"

Rodent::Rodent(float x, float y) {
    movement.x = 0;
    movement.y = 0;
    xPosition = x;
    yPosition = y;
    setup();
    startAnimation();
    generateItem();
}

Rodent::Rodent(float x, float y, GameMap* gamemap) {
    movement.x = 0;
    movement.y = 0;
    xPosition = x;
    yPosition = y;
    setup();
    startAnimation();
    this->mapObject = gamemap;
    generateItem();
}

Rodent::Rodent() {
    movement.x = 0;
    movement.y = 0;
}

Rodent::~Rodent()
{
}

int Rodent::getHealth() {
    return health;
}

void Rodent::generateItem() {
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int randomSpawn = rand() % 10;
    cout << randomSpawn << "\n";
    if (randomSpawn > 8) {
        itemHold = ItemFactory::randomItem(0, 0);
    }
}
void Rodent::hit(int hitPoints) {
    health -= hitPoints;
    color = sf::Color::Red;
    colorClock.restart();
}

void Rodent::Move(string direction) {
    sprite.setOrigin({ sprite.getLocalBounds().width / 2, 0 });
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

void Rodent::setMoving(bool move) {
    moving = move;
}

bool Rodent::isMoving() {
    return moving;
}

void Rodent::MoveLeft() {
    currentAnimation = &walkingAnimationLeft;
    movement.x -= speed;
    startAnimation();
    direction = "left";
}

void Rodent::MoveRight() {
    movement.x += speed;
    currentAnimation = &walkingAnimationRight;
    startAnimation();
    direction = "right";
}

void Rodent::MoveDown() {
    movement.y += speed;
    currentAnimation = &walkingAnimationDown;
    startAnimation();
    direction = "down";
}

void Rodent::MoveUp() {
    movement.y -= speed;
    currentAnimation = &walkingAnimationUp;
    startAnimation();
    direction = "up";
}

void Rodent::startAnimation() {
    sprite.play((*currentAnimation));
    animation_playing = true;
}


AnimatedSprite* Rodent::getSprite() {
    return &sprite;
}
void Rodent::followEnemy() {
    int heroX = mapObject->getHeroLocation().left;
    int heroY = mapObject->getHeroLocation().top;
    int enemyY = sprite.getGlobalBounds().top;
    int enemyX = sprite.getGlobalBounds().left;

    int differenceX = heroX - enemyX;
    int differenceY = heroY - enemyY;

    if (abs(differenceX) > abs(differenceY)) {
        if (differenceX > 0) {
            Move("right");
        }
        else {
            Move("left");
        }
    }
    else {
        if (differenceY > 0) {
            Move("down");
        }
        else {
            Move("up");
        }
    }

}


void Rodent::randomMove() {
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int randomMove = (rand() % 4) + 1;

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

void Rodent::Update(sf::RenderWindow* Window) {
    sf::Vector2f tempMove;
    sf::Time frameTime = frameClock.restart();

    tempMove = movement * frameTime.asSeconds();
    if (!isMoving()) {
        Shoot();
        // randomMove();
        followEnemy();
    }
    sf::FloatRect bounds = getSprite()->getGlobalBounds();
    bounds.left += tempMove.x;
    bounds.top += tempMove.y;
    distanceX += tempMove.x;
    distanceY += tempMove.y;
    if (!mapObject->checkCollisionForEnemy(bounds,this)) {

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
    for (int i = 0; i < shots.size(); i++) {
        if (shots[i] != NULL) {
            shots[i]->Update();
        }
    }
    for (int i = 0; i < shots.size(); i++) {
        if (shots[i] != NULL) {
            bool checkCollide = mapObject->checkCollision(shots[i]->getSprite()->getGlobalBounds());
            Character* collideHero = mapObject->checkCollisionHero(shots[i]->getSprite()->getGlobalBounds());

            if ((abs(shots[i]->getDistance())) < 100.0f && !checkCollide) {
                Window->draw((*shots[i]->getSprite()));
            }
            else {
                if (collideHero) {
                    collideHero->hit(3);
                }
                shots.empty();
                shots[i]->~Magic();
                shots.erase(shots.begin() + i);
            }
        }

    }
}

Item* Rodent::dropItem()
{
    if (itemHold != NULL) {
        itemHold->setLocation(sprite.getGlobalBounds().left, sprite.getGlobalBounds().top);
        return itemHold;
    }
    else {
        return NULL;
    }

}

void Rodent::resetDistance() {
    sf::FloatRect bounds = getSprite()->getGlobalBounds();
    distanceX = 0;
    distanceY = 0;
    startDistanceX = bounds.left;
    startDistanceY = bounds.top;
}

void Rodent::setup() {
    spriteFile = "assets/sprites/pokemon2.png";
    texture.loadFromFile(spriteFile);
    sprite.setFrameTime(sf::seconds(0.4));
    sprite.setPosition(xPosition, yPosition);


    walkingAnimationRight.setSpriteSheet(texture);
    walkingAnimationRight.addFrame(sf::IntRect(548, 196, 32, 32));
    walkingAnimationRight.addFrame(sf::IntRect(548, 228, 32, 32));

    walkingAnimationLeft.setSpriteSheet(texture);
    walkingAnimationLeft.addFrame(sf::IntRect(548, 128, 32, 32));
    walkingAnimationLeft.addFrame(sf::IntRect(548, 160, 32, 32));

    walkingAnimationUp.setSpriteSheet(texture);
    walkingAnimationUp.addFrame(sf::IntRect(516, 128, 32, 32));
    walkingAnimationUp.addFrame(sf::IntRect(516, 160, 32, 32));

    walkingAnimationDown.setSpriteSheet(texture);
    walkingAnimationDown.addFrame(sf::IntRect(516, 196, 32, 32));
    walkingAnimationDown.addFrame(sf::IntRect(516, 228, 32, 32));

    currentAnimation = &walkingAnimationDown;
    sprite.play((*currentAnimation));
    //sprite.stop();
}

void Rodent::Shoot() {
    if (shots.size() < 5) {
        //only allow five magics at a time
        sf::FloatRect heroLocation = getSprite()->getGlobalBounds();
        float left, top;
        left = heroLocation.left;
        top = heroLocation.top;
        if (direction == "left") {
            top = top + (heroLocation.height / 4);
        }
        else if (direction == "right") {
            top = top + (heroLocation.height / 4);
            left = left + heroLocation.width;
        }
        else if (direction == "down") {
            left = left + (heroLocation.width / 4);
            top = top + heroLocation.height;
        }
        else if (direction == "up") {
            left = left + (heroLocation.width / 4);
        }

        shots.push_back(new Magic(left, top, direction));
    }
}


void Rodent::animation()
{
}
