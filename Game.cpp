#include "Game.h"
#include "Animation.h"
#include "AnimatedSprite.h"


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

    float speed = 80.f;
    sf::Texture hero_texture;
    hero_texture.loadFromFile("assets/sprites/trainerSprites.png");
    sf::Sprite hero;
    hero.setTexture(hero_texture);
    hero.setPosition(100,100);
    hero.setTextureRect(sf::IntRect(64, 162, 32, 32));
    hero.setScale(1.5f, 1.5f);


    Animation walkingAnimationRight;
    walkingAnimationRight.setSpriteSheet(hero_texture);
    walkingAnimationRight.addFrame(sf::IntRect(64, 160, 32, 32));
    walkingAnimationRight.addFrame(sf::IntRect(64, 128, 32, 32));

    Animation walkingAnimationLeft;
    walkingAnimationLeft.setSpriteSheet(hero_texture);
    walkingAnimationLeft.addFrame(sf::IntRect(64, 228, 32, 32));
    walkingAnimationLeft.addFrame(sf::IntRect(64, 260, 32, 32));

    AnimatedSprite animatedSprite(sf::seconds(0.2), true, true);

    animatedSprite.setScale(1.5f, 1.5f);
    animatedSprite.setPosition(100,100);

    unsigned int textureHeight = Texture.getSize().y;
    unsigned int textureWidth = Texture.getSize().x;
    float viewOffsetY = 0;
    float spriteOffsetY = 0;
    float viewOffsetX = 0;
    float spriteOffsetX = 0;
    sf::Clock frameClock;

    bool keyPress = false;

    Animation* currentAnimation = &walkingAnimationRight;
   
    while (Window.isOpen()) {
        sf::Vector2f movement(0.f, 0.f);
        sf::Time frameTime = frameClock.restart();
        sf::Event event;
        while (Window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                Window.close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            movement.y -= speed;
            keyPress = true; 
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            movement.y += speed;
            keyPress = true;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            movement.x -= speed;
            currentAnimation = &walkingAnimationRight;
            keyPress = true;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            movement.x += speed;
            currentAnimation = &walkingAnimationLeft;
            keyPress = true;
        }
        animatedSprite.play(*currentAnimation);
        animatedSprite.move(movement * frameTime.asSeconds());
        animatedSprite.update(frameTime);

        if (keyPress == false) {
            animatedSprite.stop();
        }


        keyPress = false;
        spriteOffsetX = floor(viewOffsetX / textureWidth) * textureWidth;
        spriteOffsetY = floor(viewOffsetY / textureHeight) * textureHeight;
        //Sprite.setPosition(fBounds.left - spriteOffsetX, fBounds.top - spriteOffsetY);
        hero.setPosition(100 - viewOffsetX, 100 - viewOffsetY);
        Window.clear();
        Window.setView(View);
        Window.draw(Sprite);
        
        Window.draw(animatedSprite);
        Window.display();

    }
}