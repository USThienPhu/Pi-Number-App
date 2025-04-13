#include "Header.hpp"


void RenderWindow(sf::Sprite sp,sf::Sprite spG, int x, int y, sf::Sprite &startBtn, sf::Sprite &Exit)
{
    sf::RenderWindow wd(sf::VideoMode(x, y), "Pi Number");

    GameState state = MENU;
    while (wd.isOpen())
    {
        sf::Event ev;
        while (wd.pollEvent(ev))
        {
            if (ev.type == sf::Event::Closed)
            {
                wd.close();
            }


            if (state == MENU)
            {
                if (ev.type == sf::Event::MouseButtonPressed && ev.mouseButton.button == sf::Mouse::Left) {
                    if (isMouseOver(startBtn, wd)) {
                        state = GAME;
                    }
                }
            }

            if (state == GAME)
            {
                if (ev.type == sf::Event::MouseButtonPressed && ev.mouseButton.button == sf::Mouse::Left)
                {
                    if (isMouseOver(Exit, wd))
                    {
                        state = MENU;
                    }
                }
            }
            
        }
        if (state == MENU)
        {
            wd.clear();
            wd.draw(sp);
            wd.draw(startBtn);
        }
        else if (state == GAME)
        {
            wd.clear();
            wd.draw(spG);
            wd.draw(Exit);
        }

        wd.display();
      
    }
}


bool isMouseOver(sf::Sprite &button, sf::RenderWindow& wd)
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(wd);
    sf::FloatRect bounds = button.getGlobalBounds();

    return bounds.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
}