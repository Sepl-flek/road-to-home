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
    
    while (window.isOpen()) 
    {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.display();

    }

    return 0;
}