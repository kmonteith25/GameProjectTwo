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
        tmx::FloatRect bounds2 = object.getAABB();
        float x1T = bounds2.left;
        float y1T = bounds2.top;
        float x2T = x1T + bounds2.width;
        float y2T = y1T + bounds2.height;
        if (x1 < x2T && x2 > x1T&& y1 < y2T && y2 > y1T) {
            return true;
        }
    }
    return false;
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
