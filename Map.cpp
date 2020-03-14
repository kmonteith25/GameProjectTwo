#include "Map.h"

void Map::AddToMap(Entity* entity) {
	Map.push_back(entity);
}

bool Map::checkCollision(sf::FloatRect bounds) {
    float x1 = bounds.left;
    float y1 = bounds.top;
    float x2 = x1 + bounds.width;
    float y2 = y1 + bounds.height;
    std::cout << Map.size() << "\n";
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
}
