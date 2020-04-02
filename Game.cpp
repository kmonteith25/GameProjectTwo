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

void Game::setupGameOver() {
    auto textRenderer = tgui::TextBoxRenderer();
    textRenderer.setBackgroundColor(sf::Color::Black);
    textRenderer.setPadding(40);
    textRenderer.setTextColor(sf::Color::White);
    gameoverBox->setSize(230, 175);

    gameoverBox->setRenderer(textRenderer.getData());
    gameoverBox->setPosition(Window.getSize().x / 2 - 150, Window.getSize().y / 2 - 100);

    gameoverBox->setText("GAME\nOVER");
    gameoverBox->setTextSize(38);
    gameoverBox->setVisible(false);

}

void Game::setupGameWin() {
    auto textRenderer = tgui::TextBoxRenderer();
    textRenderer.setBackgroundColor(sf::Color::Black);
    textRenderer.setPadding(40);
    textRenderer.setTextColor(sf::Color::White);
    winBox->setSize(230, 175);

    winBox->setRenderer(textRenderer.getData());
    winBox->setPosition(Window.getSize().x / 2 - 150, Window.getSize().y / 2 - 100);

    winBox->setText("YOU\nWIN");
    winBox->setTextSize(38);
    winBox->setVisible(false);

}

void Game::setupKillCounter() {
    killCounter->setPosition(Window.getSize().x - 150, Window.getSize().y - 100);

    killCounter->setText("Kills");
    killCounter->setTextSize(38);
    killCounter->setVisible(true);

    killNumber->setPosition(Window.getSize().x - 150, Window.getSize().y - 50);

    killNumber->setText("0");
    killNumber->setTextSize(38);
    killNumber->setVisible(true);
}

void Game::gameLoop()
{
    tgui::Gui gui(Window);
    sf::Clock globalClock;

    map = new GameMap(&Window);
    hero = new Hero(map);
    map->setHero(hero);
    
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
    music.setVolume(40);
    music.play();

    //sounds
    sf::SoundBuffer buffer;
    buffer.loadFromFile("magic.wav");
    sf::Sound sound;
    sound.setVolume(10);
    sound.setBuffer(buffer);   
    

    auto progressBar = tgui::ProgressBar::create();
 
    progressBar->setPosition(20, Window.getSize().y -50);
    progressBar->setSize(200, 20);
    
    gui.add(progressBar);


    
    setupGameOver();
    setupGameWin();
    setupKillCounter();
    gui.add(gameoverBox);
    gui.add(winBox);
    gui.add(killCounter);
    gui.add(killNumber);
    bool shoot = false;
    
    while (Window.isOpen()) {
        hero->Update(keyPress, &View);
        Window.clear();
        Window.setView(View);

        map->DrawMap(&Window);
        hero->Draw(&Window);

        gui.draw();
        Window.display();
        progressBar->setValue(hero->getHealth());
        keyPress = false;
        sf::Event event;
        while (Window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                Window.close();
            }
            else if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == 57) {
                    shoot = true;
                }
            }
        
        }
        if (hero->isWin()) {
            winBox->setVisible(true);
        }
        else if (hero->getHealth() <= 0) {
            gameoverBox->setVisible(true);
        }
        else {
            if (shoot) {
                sound.play();
                hero->Shoot();
                shoot = false;
                killNumber->setText(to_string(map->getHeroKills()));
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
            

        }
    }
       

}