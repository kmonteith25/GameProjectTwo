#include "Game.h"
#include "GameMap.h"
#include "Entities/Characters/Hero/Hero.h"
#include "Entities/Items/Potion.h"

Game::Game()
{
}

Game::~Game()
{
}

void Game::setup()
{
    Window.create(sf::VideoMode(1000, 768), "Pokemon Killers", sf::Style::Close);
    View = sf::View(Window.getDefaultView());
    fBounds = sf::FloatRect(0.f, 0.f, 1000.f, 1000.f);
    font.loadFromFile("assets/fonts/Zelda.ttf");

}

void Game::userInputControlManager() {


}

void Game::updateHeroHealth() {
    heroScore.setFont(font);
    heroScore.setString(std::to_string(hero->getHealth())+"%");
    heroScore.setCharacterSize(65);
    heroScore.setFillColor(sf::Color::Red);
    heroScore.setPosition(0+ View.getCenter().x - (View.getSize().x / 2), (700+ View.getCenter().y - (View.getSize().y / 2)));
    Window.draw(heroScore);
}


void Game::gameLoop()
{
    
   
    sf::Clock globalClock;
    Potion* potion = new Potion(100.f,100.f);
    
    sf::Texture Texture;
    Texture.loadFromFile("assets/sprites/grassSprite.png");
    sf::IntRect iBounds(fBounds);
    Texture.setRepeated(true);
    sf::Sprite Sprite(Texture, iBounds);
    Sprite.setPosition(fBounds.left - 1000.f + View.getSize().x, fBounds.top - 1000.f + View.getSize().y);
    unsigned int textureHeight = Texture.getSize().y;
    unsigned int textureWidth = Texture.getSize().x;
    bool keyPress = false;
    sf::Music music;
    music.openFromFile("music.ogg");
    music.setLoop(true);
    music.setVolume(4);
    music.play();

    //sounds
    sf::SoundBuffer buffer;
    buffer.loadFromFile("magic.wav");
    sf::Sound sound;
    sound.setVolume(10);
    sound.setBuffer(buffer);   
    map = new GameMap(&Window);
    hero = new Hero(map); 
    map->setHero(hero);
    while (Window.isOpen()) {
        
        sf::Event event;
        while (Window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                Window.close();
            }
            else if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == 57) {
                    sound.play();
                    hero->Shoot();
                   
                }
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
        hero->Update(keyPress, &View);
        Window.clear();
        Window.setView(View);
        
        map->DrawMap(&Window);
        hero->Draw(&Window);
        updateHeroHealth();
        Window.display();

        keyPress = false;

    } 
}