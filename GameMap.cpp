#include "Factories/EnemyFactory.h"
#include "Factories/ItemFactory.h"
#include "Entities/Characters/Hero/Hero.h"
#include "GameMap.h"

GameMap::~GameMap()
{
}

GameMap::GameMap(sf::RenderWindow* Window) 
{
    
    this->Window = Window;
    InitMap();
}

void GameMap::setHero(Hero* hero) {
    this->hero = hero;
}

sf::FloatRect GameMap::getHeroLocation() {
    return hero->getSprite()->getGlobalBounds();
}

void GameMap::createMap()
{

}



void GameMap::InitMap() {

    map.load("map.tmx");
    layerZero = new MapLayer(map, 0);
    layerOne = new MapLayer(map, 1);
    layerTwo = new MapLayer(map, 2);
    layerThree = new MapLayer(map, 4);
    layerFour = new MapLayer(map, 5);

    objectLayer = map.getLayers()[3]->getLayerAs<tmx::ObjectGroup>();
    setupEnemySpawnLocations();
    setupItemSpawnLocations();
    spawnItems();
}


void GameMap::DrawMap(sf::RenderWindow* Window) {
    Window->draw((*layerZero));
    Window->draw((*layerOne));
    Window->draw((*layerTwo));
    Window->draw((*layerThree));
    Window->draw((*layerFour));
    
    drawEnemies(Window);
    drawItems(Window);
    
}
bool inArray(string array[],string query) {
   
    for (int i = 0; i <= array->size(); i++) {
        if (query == array[i]) {
            
            return true;
        }
    }
    return false;
}

bool GameMap::checkCollision(sf::FloatRect bounds)
{

    float x1 = bounds.left;
    float y1 = bounds.top;
    float x2 = x1 + bounds.width;
    float y2 = y1 + bounds.height;
    const auto& objects = objectLayer.getObjects();
    for (const auto& object : objects)
    {
        if(inArray(collisionNames,object.getType())) {
            
            tmx::FloatRect bounds2 = object.getAABB();
            float x1T = bounds2.left;
            float y1T = bounds2.top;
            float x2T = x1T + bounds2.width;
            float y2T = y1T + bounds2.height;
            if (x1 < x2T && x2 > x1T&& y1 < y2T && y2 > y1T) {
                return true;
            }
        }
    }
    if (checkCollisionEnemy(bounds)) {
        return true;
    }
    return false;
}

bool GameMap::checkCollisionForEnemy(sf::FloatRect bounds)
{

    float x1 = bounds.left;
    float y1 = bounds.top;
    float x2 = x1 + bounds.width;
    float y2 = y1 + bounds.height;
    const auto& objects = objectLayer.getObjects();
    for (const auto& object : objects)
    {
        if (inArray(collisionNames, object.getType()) || object.getType() == "enemyBounds") {
                tmx::FloatRect bounds2 = object.getAABB();
                float x1T = bounds2.left;
                float y1T = bounds2.top;
                float x2T = x1T + bounds2.width;
                float y2T = y1T + bounds2.height;
                if (x1 < x2T && x2 > x1T&& y1 < y2T && y2 > y1T) {
                    return true;
                }
        }
    }
    if (checkCollisionHero(bounds)) {
        return true;
    }
    return false;
}

Character* GameMap::checkCollisionEnemy(sf::FloatRect bounds) {
    float x1 = bounds.left;
    float y1 = bounds.top;
    float x2 = x1 + bounds.width;
    float y2 = y1 + bounds.height;
    for (int i = 0; i < enemyGroups.size(); i++) {
        for (int j = 0; j < enemyGroups[i].size(); j++) {
            if (enemyGroups[i][j] != NULL) {
                sf::FloatRect bounds2 = enemyGroups[i][j]->getSprite()->getGlobalBounds();
                float x1T = bounds2.left;
                float y1T = bounds2.top;
                float x2T = x1T + bounds2.width;
                float y2T = y1T + bounds2.height;
                if (x1 < x2T && x2 > x1T&& y1 < y2T && y2 > y1T) {
                    return enemyGroups[i][j];
                }
            }

        }
    }
    return NULL;
}

void GameMap::setHeroLocation(sf::FloatRect loc) {
    heroLocation = loc;
}

Character* GameMap::checkCollisionHero(sf::FloatRect bounds) {
    float x1 = bounds.left;
    float y1 = bounds.top;
    float x2 = x1 + bounds.width;
    float y2 = y1 + bounds.height;
    sf::FloatRect heroLocation = hero->getSprite()->getGlobalBounds();
    float x1T = heroLocation.left;
    float y1T = heroLocation.top;
    float x2T = x1T + heroLocation.width;
    float y2T = y1T + heroLocation.height;
    if (x1 < x2T && x2 > x1T&& y1 < y2T && y2 > y1T) {
        return hero;
     }
    return NULL;
}

tmx::FloatRect GameMap::getPlayerStartPosition() {
    const auto& objects = objectLayer.getObjects();
    for (const auto& object : objects)
    {
        if (object.getName() == "playerStart") {
            return object.getAABB();
        }
    }
}

void GameMap::setupEnemySpawnLocations() {
    const auto& objects = objectLayer.getObjects();
    int counter = 0;
    for (const auto& object : objects)
    {
        if (object.getType() == "enemySpawn") {
            enemySpawnLocations.push_back(object.getAABB());
        }
    }
}

void GameMap::setupItemSpawnLocations() {
    const auto& objects = objectLayer.getObjects();
    int counter = 0;
    for (const auto& object : objects)
    {
        if (object.getType() == "itemSpawn") {
            itemSpawnLocations.push_back(object.getAABB());
        }
    }
}

void GameMap::spawnItems() {
    for (int i = 0; i < itemSpawnLocations.size(); i++) {
        cout << "hell";
        if (items.size() < i) {
            srand(chrono::high_resolution_clock::now().time_since_epoch().count());
            int randomSpawn = rand() % 10;
            if (randomSpawn > 0) {
                //spawn if greater than 7
                tmx::FloatRect temp = itemSpawnLocations[i];
                cout << temp.top << "\n";
                cout << temp.left << "\n";
                items.push_back(ItemFactory::randomItem(temp.left,temp.top));
            }
        }


    }
}

void GameMap::drawItems(sf::RenderWindow* Window) {
    for (int i = 0; i < items.size(); i++) {
            if (items[i]!= NULL) {
               // if (items[i]->getHealth() <= 0) {
                  //  increaseHeroKills(true);
                 //   items[i]->~Item();
                  //  items[i] = NULL;
                //}
                //else {
                //    items[i]->Update(Window);
                    Window->draw((*items[i]->getSprite()));
               // }

            }
        }
    }


void GameMap::spawnEnemies() {
    for (int i = 0; i < enemySpawnLocations.size(); i++) {
        for (int j = 0; j < maxEnemiesGroup; j++) {
            if (enemyGroups[i][j] == NULL) {
                
                srand(chrono::high_resolution_clock::now().time_since_epoch().count());
                int randomSpawn = rand() % 10;
                if (randomSpawn > 7) {
                    //spawn if greater than 7
                    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
                    tmx::FloatRect temp = enemySpawnLocations[i];
                    int randomY = rand() % int(temp.height-64) + int(temp.top+32);
                    int randomX = rand() % int(temp.width-64) + int(temp.left+32);
                    enemyGroups[i][j] = EnemyFactory::randomEnemy(float(randomX), float(randomY),this);
                }
            }

        }
   }
}

void GameMap::drawEnemies(sf::RenderWindow* Window) {
    for (int i = 0; i < enemyGroups.size(); i++) {
        for (int j = 0; j < enemyGroups[i].size(); j++) {
            if(enemyGroups[i][j] != NULL) { 
                if (enemyGroups[i][j]->getHealth() <= 0) {
                    increaseHeroKills(true);
                    Item* droppedItem = enemyGroups[i][j]->dropItem();
                    if (droppedItem != NULL) {
                        items.push_back(droppedItem);
                    }
                    enemyGroups[i][j]->~Character();
                    enemyGroups[i][j] = NULL;
                }
                else {
                    enemyGroups[i][j]->Update(Window);
                    Window->draw((*enemyGroups[i][j]->getSprite()));
                }
            }
        }
    }
}


void GameMap::increaseHeroKills(bool kill)
{
    if (kill) {
        heroKills++;
    }
}

int GameMap::getHeroKills() {
    return heroKills;
}

