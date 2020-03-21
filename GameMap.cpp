#include "GameMap.h"

GameMap::GameMap()
{
    InitMap();
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
    //setupEnemySpawnLocations();
    //spawnEnemies();
    objectLayer = map.getLayers()[3]->getLayerAs<tmx::ObjectGroup>();
       
}


void GameMap::DrawMap(sf::RenderWindow* Window) {
    //sf::Time duration = globalClock.getElapsedTime();
    //layerZero->update(duration);

    Window->clear(sf::Color::Black);
    Window->draw((*layerZero));
    Window->draw((*layerOne));
    Window->draw((*layerTwo));
    Window->draw((*layerThree));
    Window->draw((*layerFour));
    //drawEnemies(Window);
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
    return false;
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
    for (const auto& object : objects)
    {
        if (object.getName() == "enemySpawn") {
            enemySpawnLocations.push_back(object.getAABB());
        }
    }
}

void GameMap::spawnEnemies() {
    for (int i = 0; i < enemySpawnLocations.size(); i++) {
        if (enemyGroups[i].size() <= MAX_ENEMIES_PER_GROUP) {
            //spawn enemies
            for (int j = 0; j < MAX_ENEMIES_PER_GROUP; j++) {
                srand(time(NULL));
                int randomSpawn = rand() % 10;
                if (randomSpawn > 7) {
                    //spawn if greater than 7
                    srand(time(NULL));
                    int randomY = rand() % int(enemySpawnLocations[i].top);
                    int randomX = rand() % int(enemySpawnLocations[i].left);
                    enemyGroups[i][j] = EnemyFactory::randomEnemy(float(randomX),float(randomY));
                }

            }
        }
   }
}

void GameMap::drawEnemies(sf::RenderWindow* Window) {
    for (int i = 0; i < enemyGroups.size(); i++) {
        for (int j = 0; j < enemyGroups[i].size(); j++) {
            enemyGroups[i][j]->Update();
            Window->draw(enemyGroups[i][j]->getSprite());
        }
    }
}

/*bool GameMap::checkCollision(sf::FloatRect bounds) {
    float x1 = bounds.left;
    float y1 = bounds.top;
    float x2 = x1 + bounds.width;
    float y2 = y1 + bounds.height;
    for (auto& element : Map) {
        sf::FloatRect bounds2 = element->getSprite().getGlobalBounds();
        float x1T = bounds2.left;
        float y1T = bounds2.top;
        float x2T = x1T + bounds2.width;
        float y2T = y1T + bounds2.height;
        if (x1 < x2T && x2 > x1T && y1 < y2T && y2 > y1T) {
            return true;
        }
    }

    
    return false; 

}*/
