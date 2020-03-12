#include "Game.h"
#include "Animations/Animation.h"
#include "Animations/AnimatedSprite.h"
#include "Entities/Characters/Hero/Hero.h"
#include "Entities/Items/Potion.h"
#include "Entities/Items/Tree.h"


bool collision(Entity* Object1, Entity* Object2) {
    sf::FloatRect bounds = Object1->getSprite().getGlobalBounds();
    float x1 = bounds.left;
    float y1 = bounds.top;
    float x2 = x1 + bounds.width;
    float y2 = y1 + bounds.height;



    sf::FloatRect bounds2 = Object2->getSprite().getGlobalBounds();
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

Game::Game()
{
}

Game::~Game()
{
}

void Game::setup()
{
    Window.create(sf::VideoMode(1000, 768), "", sf::Style::Close);
    View = sf::View(Window.getDefaultView());

    fBounds = sf::FloatRect(0.f, 0.f, 1000.f, 1000.f);


}

void Game::userInputControlManager() {


}


void Game::gameLoop()
{
    sf::Texture Texture;
    Texture.loadFromFile("assets/sprites/grassTile.jpg");
    sf::IntRect         iBounds(fBounds);
    Texture.setRepeated(true);
    sf::Sprite          Sprite(Texture, iBounds);
    Sprite.setPosition(fBounds.left - 1000.f + View.getSize().x, fBounds.top - 1000.f + View.getSize().y);
    unsigned int textureHeight = Texture.getSize().y;
    unsigned int textureWidth = Texture.getSize().x;
    bool keyPress = false;

    Hero* hero = new Hero();
    Potion potion = Potion();
    Tree* tree = new Tree();
    
    while (Window.isOpen()) {
        tree->Update();
        sf::Event event;
        while (Window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                Window.close();
            }
        }
        
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
                hero->MoveUp();
                keyPress = true;

            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                hero->MoveDown();
                keyPress = true;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                hero->MoveLeft();
                keyPress = true;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                hero->MoveRight();
                keyPress = true;
            }

        if (!collision(hero, tree)) {
                hero->Update(keyPress);
        }
        Window.clear();
        Window.setView(View);
        Window.draw(Sprite);
        
        tree->Update();
        Window.draw(hero->getSprite());
        Window.draw(tree->getSprite());

        Window.display();
        keyPress = false;

    }
}