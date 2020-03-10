#include "Game.h"
#include "Animations/Animation.h"
#include "Animations/AnimatedSprite.h"
#include "Entities/Characters/Hero/Hero.h"


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

    Hero hero = Hero();

    while (Window.isOpen()) {
        sf::Event event;
        while (Window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                Window.close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            hero.MoveUp();
            keyPress = true; 
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            hero.MoveDown();
            keyPress = true;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            hero.MoveLeft();
            keyPress = true;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            hero.MoveRight();
            keyPress = true;
        }

        
        Window.clear();
        Window.setView(View);
        Window.draw(Sprite);
        hero.Update(keyPress);
        Window.draw(hero.getSprite());
        Window.display();
        keyPress = false;

    }
}