#include <SFML/Graphics.hpp>
int main()
{
    sf::RenderWindow    Window(sf::VideoMode(1000, 768), "", sf::Style::Close);
    sf::View            View(Window.getDefaultView());
    sf::FloatRect       fBounds(0.f, 0.f, 1000.f, 1000.f); 
    sf::Texture     Texture;

    Texture.loadFromFile("assets/sprites/grassTile.jpg");
    sf::IntRect         iBounds(fBounds);
    Texture.setRepeated(true); 
    sf::Sprite          Sprite(Texture, iBounds);
    Sprite.setPosition(fBounds.left - 1000.f + View.getSize().x, fBounds.top - 1000.f + View.getSize().y);

    float viewOffsetY = 0;
    float spriteOffsetY = 0;
    float viewOffsetX = 0;
    float spriteOffsetX = 0;
    unsigned int textureHeight = Texture.getSize().y;
    unsigned int textureWidth = Texture.getSize().x;


    while (Window.isOpen()) {
        sf::Event event;
        while (Window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                Window.close();
        }
        View.setCenter(500.f-viewOffsetX, 500.f - viewOffsetY);
        //
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            viewOffsetY += 0.3f; 
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            viewOffsetY -= 0.3f; 

        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            viewOffsetX += 0.3f;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            viewOffsetX -= 0.3f;

        }
 
        spriteOffsetX = floor(viewOffsetX / textureHeight) * textureHeight;
        spriteOffsetY = floor(viewOffsetY / textureHeight) * textureWidth;
        Sprite.setPosition(fBounds.left - spriteOffsetX, fBounds.top - spriteOffsetY);

        Window.clear();
        Window.setView(View);
        Window.draw(Sprite);
        Window.display();

    }
}