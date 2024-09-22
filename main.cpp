#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Road to home");
    sf::Image icon;
    if (!icon.loadFromFile("pictures/icon.png")) {
        return 1;
    }
    window.setIcon(32, 32, icon.getPixelsPtr());

    sf::Texture textureInfoPanel;
    textureInfoPanel.loadFromFile("pictures/Panel.png");
    sf::RectangleShape gameInfoPanel(sf::Vector2f(1280, 113));
    gameInfoPanel.setTexture(&textureInfoPanel);
    gameInfoPanel.setPosition(sf::Vector2f(0, 0));

    sf::Texture textureSpace;
    textureSpace.loadFromFile("pictures/newkos1.jpg");

    sf::RectangleShape gameSpace(sf::Vector2f(1280, 720));
    gameSpace.setTexture(&textureSpace);

    sf::RectangleShape gameSpace2(sf::Vector2f(1280, 720));
    gameSpace2.setTexture(&textureSpace);
    gameSpace2.setPosition(sf::Vector2f(1280, 0));

    sf::Vector2f pos;
    sf::Clock clock;
    float time;
    
    while (window.isOpen()) 
    {
        sf::Event event;
        time = clock.getElapsedTime().asMicroseconds();
        time /= 6000;
        clock.restart();
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        gameSpace.move(-0.2 * time,0);
        pos = gameSpace.getPosition();
        if (pos.x < -1280) {
            gameSpace.setPosition(1280, pos.y);
        }

        gameSpace2.move(-0.2 * time, 0);
        pos = gameSpace2.getPosition();
        if (pos.x < -1280) {
            gameSpace2.setPosition(1280, pos.y);
        }

        window.clear();
        window.draw(gameSpace);
        window.draw(gameSpace2);
        window.draw(gameInfoPanel);
        window.display();

    }

    return 0;
}