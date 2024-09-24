
#include "playermove.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Road to home");
    sf::Image icon;
    if (!icon.loadFromFile("pictures/icon.png")) {
        return 1;
    }
    window.setIcon(32, 32, icon.getPixelsPtr());
    // информациооная панель
    sf::Texture textureInfoPanel;
    textureInfoPanel.loadFromFile("pictures/Panel.png");
    sf::RectangleShape gameInfoPanel(sf::Vector2f(1280, 113));
    gameInfoPanel.setTexture(&textureInfoPanel);
    gameInfoPanel.setPosition(sf::Vector2f(0, 0));

    // бекграунд
    sf::Texture textureSpace;
    textureSpace.loadFromFile("pictures/newkos1.jpg");

    sf::RectangleShape gameSpace(sf::Vector2f(1280, 720));
    gameSpace.setTexture(&textureSpace);

    sf::RectangleShape gameSpace2(sf::Vector2f(1280, 720));
    gameSpace2.setTexture(&textureSpace);
    gameSpace2.setPosition(sf::Vector2f(1280, 0));

    sf::Vector2f pos;
    sf::Clock clock, clockAnim;
    float time, timeShip, timeBackground;
    //.........................................

    // космический корабль
    sf::Vector2f moveRec; // передвижеине игрока
    sf::Texture textureShip;
    textureShip.loadFromFile("pictures/player.png");
    sf::RectangleShape ship(sf::Vector2f(50,30));
    ship.setTexture(&textureShip);
    ship.setPosition(sf::Vector2f(80, 380));
    //.........................................
    //Анимация струи коробля
    int arrAnim[3] = { 9,59,103 };
    int frame = 2, stepAnim = -1;


    sf::Texture heroTexture;
    heroTexture.loadFromFile("pictures/anim.png");
    sf::Sprite heroSprite;
    heroSprite.setTexture(heroTexture);
    heroSprite.setTextureRect(sf::IntRect(0,103,85,43));
    
    while (window.isOpen()) 
    {
        sf::Event event;
        // time
        time = clock.getElapsedTime().asMicroseconds();
        time /= 6000;
        timeShip = time * 3;
        timeBackground = time;
        //.........................................

        clock.restart();
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            // управление кораблем
            switch (event.type)
            {
            case sf::Event::KeyPressed:
                if ((event.key.code == sf::Keyboard::S)) {
                    moveRec.y = 0.5 * timeShip;
                }
                if ((event.key.code == sf::Keyboard::W)) {
                    moveRec.y = -0.5 * timeShip;
                }
                if ((event.key.code == sf::Keyboard::A)) {
                    moveRec.x = -0.5 * timeShip;
                }
                if ((event.key.code == sf::Keyboard::D)) {
                    moveRec.x = 0.5 * timeShip;
                }
                break;

            case sf::Event::KeyReleased:
                if ((event.key.code == sf::Keyboard::S)) {
                    moveRec.y = 0;
                }
                if ((event.key.code == sf::Keyboard::W)) {
                    moveRec.y = 0;
                }
                if ((event.key.code == sf::Keyboard::A)) {
                    moveRec.x = 0;
                }
                if ((event.key.code == sf::Keyboard::D)) {
                    moveRec.x = 0;
                }
                break;

            default:
                break;
            }


        }


        if (clockAnim.getElapsedTime() > sf::milliseconds(100)) {
            clock.restart();
            frame += stepAnim;
            heroSprite.setTextureRect(sf::IntRect(0, arrAnim[frame], 85, 43));
            if (frame == 0) {
                stepAnim = 1;
            }
            if (frame == 2) {
                stepAnim = -1;
            }
        }
        heroSprite.setPosition(sf::Vector2f(ship.getPosition().x - 80, ship.getPosition().y - 4));
        // отрисоввка космаса
        gameSpace.move(-0.2 * timeBackground,0);
        pos = gameSpace.getPosition();
        if (pos.x < -1280) {
            gameSpace.setPosition(1280, pos.y);
        }

        gameSpace2.move(-0.2 * timeBackground, 0);
        pos = gameSpace2.getPosition();
        if (pos.x < -1280) {
            gameSpace2.setPosition(1280, pos.y);
        }
        //...........................................

        //Движение коробля
        PlayerMove(ship, moveRec);
        

        window.clear();
        window.draw(gameSpace);
        window.draw(gameSpace2);
        window.draw(gameInfoPanel);
        window.draw(ship);
        window.draw(heroSprite);
        window.display();

    }

    return 0;
}