#include "Header.hpp"


void RenderWindow(sf::Sprite sp, int x, int y, sf::Sprite &startBtn)
{
    sf::RenderWindow wd(sf::VideoMode(x, y), "Pi Number");

    while (wd.isOpen())
    {
        sf::Event ev;
        while (wd.pollEvent(ev))
        {
            if (ev.type == sf::Event::Closed)
            {
                wd.close();
            }
            if (ev.type == sf::Event::MouseButtonPressed && ev.mouseButton.button == sf::Mouse::Left) {
                if (isMouseOver(startBtn, wd)) {
                    std::cout << "Start Game!\n";
                }
            }
        }
        wd.clear();
        wd.draw(sp);
        wd.draw(startBtn);
        wd.display();
    }
}


bool isMouseOver(sf::Sprite &button, sf::RenderWindow& wd)
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(wd);
    sf::FloatRect bounds = button.getGlobalBounds();

    return bounds.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
}