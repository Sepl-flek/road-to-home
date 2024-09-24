#include "playermove.h"

void PlayerMove(sf::Sprite& ship, sf::Vector2f& moveRec)
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

void playerAnim(sf::Sprite& ship, FrameAnime& FramePlanim, int traffic)
{
    FramePlanim.Frame += FramePlanim.Step;
    ship.setTextureRect(sf::IntRect(0, FramePlanim.Frame, 90, 90));
    if (traffic) if (FramePlanim.Frame > 0) FramePlanim.Step = -100;  else FramePlanim.Step = 0;
    else {
        if (FramePlanim.Frame == 800) FramePlanim.Step = 0;
        if (FramePlanim.Frame <= 700) FramePlanim.Step = 100;
    }
}
