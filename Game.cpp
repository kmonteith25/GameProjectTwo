#include "Game.h"


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
    
    
    sf::Clock globalClock;
    Hero* hero = new Hero(map);

    sf::Texture Texture;
    Texture.loadFromFile("assets/sprites/grassSprite.png");
    sf::IntRect         iBounds(fBounds);
    Texture.setRepeated(true);
    sf::Sprite          Sprite(Texture, iBounds);
    Sprite.setPosition(fBounds.left - 1000.f + View.getSize().x, fBounds.top - 1000.f + View.getSize().y);
    unsigned int textureHeight = Texture.getSize().y;
    unsigned int textureWidth = Texture.getSize().x;
    bool keyPress = false;

    sf::Music music;
    music.openFromFile("music.ogg");

    music.setVolume(50);
    music.play();
    
    while (Window.isOpen()) {
        sf::Event event;
        while (Window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                Window.close();
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            hero->Move("up");
            keyPress = true;

        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            hero->Move("down");
            keyPress = true;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            hero->Move("left");
            keyPress = true;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            hero->Move("right");
            keyPress = true;
        }
        Window.clear();
        Window.setView(View);
        Window.draw(Sprite);

        

        
        hero->Update(keyPress);
        map->DrawMap(&Window);
        Window.draw(hero->getSprite());

        Window.display();
        keyPress = false;

    } 
}