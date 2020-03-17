#include "Map.h"

void Map::AddToMap(Entity* entity) {
	Map.push_back(entity);
}

vector<Entity*> Map::GenerateFromArray(vector<vector<int>> v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            Entity* e;
            if (v[i][j] == 0) {
               
            }
            else {
                e = new Tree(j * 32, i * 32);
                AddToMap(e);
            }
            
        }
    }
    return Map;
}

void Map::InitMap() {
    

}

void Map::DrawMap() {
/*    for (int i = 0; i < v.size(); i++) {
        v[i]->Update();
        Window.draw(v[i]->getSprite());
    }

    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            Entity* e;
            if (v[i][j] == 0) {
                e = new Tree(i * 32, j * 32);
            }
            map->AddToMap(e);
        }
   } */
}

bool Map::checkCollision(sf::FloatRect bounds) {
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
}
