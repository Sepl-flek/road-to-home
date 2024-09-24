
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
    sf::Clock clock, clockAnimPlay;
    float time, timeShip, timeBackground;
    //.........................................

    // космический корабль
    sf::Vector2f moveRec; // передвижеине игрока
    int traffic = 0;
    sf::Texture textureShip;

    FrameAnime FramePlanim;
    FramePlanim.Frame = 700;
    textureShip.loadFromFile("pictures/playeranim1.png");

    sf::Sprite ship;
    ship.setTexture(textureShip);
    ship.setTextureRect(sf::IntRect(0, FramePlanim.Frame, 90, 90));
    
    ship.setPosition(sf::Vector2f(80, 380));
    //.........................................
   
    
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
                    traffic = 2;
                }
                if ((event.key.code == sf::Keyboard::W)) {
                    moveRec.y = -0.5 * timeShip;
                    traffic = 1;
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
                    traffic = 0;
                }
                if ((event.key.code == sf::Keyboard::W)) {
                    moveRec.y = 0;
                    traffic = 0;
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


        if (clockAnimPlay.getElapsedTime() > sf::milliseconds(100)) {
            clockAnimPlay.restart();

            playerAnim(ship, FramePlanim, traffic);
           
        }
        


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
        
        window.display();

    }

    return 0;
}