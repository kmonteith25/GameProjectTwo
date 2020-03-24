#include "Hero.h"


Hero::Hero(GameMap* map)
{
    mapObject = map;
    setup();
}

Hero::~Hero()
{
}

int Hero::getHealth() {
    return health;
}

void Hero::setMoving(bool move) {
    moving = move;
}

bool Hero::isMoving() {
    return moving;
}

void Hero::hit(int hitPoints) {
    health -= hitPoints;
    color = sf::Color::Red;
    colorClock.restart();
}

void Hero::Move(string direction) {
    if (!isMoving()) {
        setMoving(true);
        mapObject->spawnEnemies();
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

void Hero::MoveLeft() {
    if (direction != "left") {
        direction = "left";
        currentAnimation = &walkingAnimationLeft;
        sprite.play((*currentAnimation));
        sprite.stop();
        setMoving(false);
        Sleep(100);
    }
    else {
        movement.x -= speed;
        startAnimation();
    }
}

void Hero::MoveRight() {
    if (direction != "right") {
        direction = "right";
        currentAnimation = &walkingAnimationRight;
        sprite.play((*currentAnimation));
        sprite.stop();
        setMoving(false);
        Sleep(100);
    }
    else {
        movement.x += speed;
        startAnimation();
    }
}

void Hero::MoveDown() {

    if (direction != "down") {
        direction = "down";
        currentAnimation = &walkingAnimationDown;
        sprite.play((*currentAnimation));
        sprite.stop();
        setMoving(false);
        Sleep(100);
    }
    else {
        movement.y += speed;
        startAnimation();
    }
}

void Hero::MoveUp() {

    if (direction != "up") {
        direction = "up";
        currentAnimation = &walkingAnimationUp;
        sprite.play((*currentAnimation));
        sprite.stop();
        setMoving(false);
        Sleep(100);
    }
    else {
        movement.y -= speed;
        startAnimation();
    }
}

void Hero::Shoot() {
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
        
        shots.push_back(new Magic(left,top,direction));
    }
}

void Hero::startAnimation() {
    sprite.play((*currentAnimation));
    animation_playing = true;
}

void Hero::Draw(sf::RenderWindow* Window) {
    Window->draw((*getSprite()));
   for (int i = 0; i < shots.size(); i++) {
      if(shots[i] != NULL) {
          bool checkCollide = mapObject->checkCollision(shots[i]->getSprite()->getGlobalBounds());
          Character* checkCollideEnemy = mapObject->checkCollisionEnemy(shots[i]->getSprite()->getGlobalBounds());
          if ((abs(shots[i]->getDistance())) < 100.0f && !checkCollide) {
              Window->draw((*shots[i]->getSprite()));
          }
          else {
              if (checkCollideEnemy) {
                  checkCollideEnemy->hit(10);
              }
              shots.empty();
              shots[i]->~Magic();
              shots.erase(shots.begin() + i);
          }
       }
      
    }
}



bool Hero::collision(Entity* Object2) {
    sf::FloatRect bounds = getSprite()->getGlobalBounds();
    float x1 = bounds.left;
    float y1 = bounds.top;
    float x2 = x1 + bounds.width;
    float y2 = y1 + bounds.height;
    sf::FloatRect bounds2 = Object2->getSprite()->getGlobalBounds();
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

AnimatedSprite* Hero::getSprite() {
    return &sprite;
}

void Hero::resetDistance() {
    sf::FloatRect bounds = getSprite()->getGlobalBounds();
    distanceX = 0;
    distanceY = 0; 
    startDistanceX = bounds.left;
    startDistanceY = bounds.top;
}
void Hero::Update(bool keyPress,sf::View* View) {
    sf::Vector2f tempMove;
    sf::Time frameTime = frameClock.restart();
    tempMove = movement * frameTime.asSeconds();
    
    sf::FloatRect bounds = getSprite()->getGlobalBounds();
    bounds.left += tempMove.x;
    bounds.top += tempMove.y;
    distanceX += tempMove.x;
    distanceY += tempMove.y;
    if (!mapObject->checkCollision(bounds)) {

        sprite.move(tempMove);
    }
    getSprite()->setColor(color);
    if (colorClock.getElapsedTime().asSeconds() > .25) {
        color = sf::Color(255, 255, 255, 255);
    }



    changeView(View);
    sprite.update(frameTime);
    if (abs(distanceX) >= 32 || abs(distanceY) >= 32) {
        movement.x = 0;
        movement.y = 0;
        sprite.stop();
        resetDistance();
        setMoving(false);
    }

    for (int i = 0; i < shots.size(); i++) {
        if (shots[i] != NULL) {
            shots[i]->Update();
        }
    }
    setKills(mapObject->getHeroKills());
    cout << kills << "\n" ;
}

void Hero::changeView(sf::View* View) {
    sf::FloatRect bounds = getSprite()->getGlobalBounds();
    float boundX = getSprite()->getPosition().x - (View->getSize().x/2.f);
    float boundY = getSprite()->getPosition().y - (View->getSize().y / 2.f);
    if (boundX > 0) {
        View->setCenter(getSprite()->getPosition().x,View->getCenter().y);
    }
    if (boundY > 0) {
        View->setCenter(View->getCenter().x, getSprite()->getPosition().y);
    }
}

void Hero::setPositionInitial() {
    tmx::FloatRect start = mapObject->getPlayerStartPosition();
    sprite.setPosition(start.left,start.top);
}

void Hero::setup() {
    spriteFile = "assets/sprites/trainerSprites.png";
    texture.loadFromFile(spriteFile);
    sprite.setFrameTime(sf::seconds(0.15));
    sprite.setScale(1.f, 1.f);
    setPositionInitial();

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


void Hero::setKills(int kills) {
    this->kills = kills;
}

void Hero::animation()
{
}

