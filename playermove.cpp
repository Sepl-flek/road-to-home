#include "playermove.h"

void PlayerMove(sf::RectangleShape &ship, sf::Vector2f& moveRec)
{
    ship.move(moveRec);
    sf::Vector2f pos = ship.getPosition();
    if (pos.x > 1200) ship.setPosition(1200, pos.y);
    if (pos.x < 50) ship.setPosition(50, pos.y);
    if (pos.y > 670) ship.setPosition(pos.x, 670);
    if (pos.y < 120) ship.setPosition(pos.x, 120);

    if (pos.x > 1200 && pos.y > 670) ship.setPosition(1200, 670);
    if (pos.x > 1200 && pos.y < 120) ship.setPosition(1200, 120);
    if (pos.x < 50 && pos.y > 670) ship.setPosition(50, 670);
    if (pos.x < 50 && pos.y < 120) ship.setPosition(50, 120);

}
