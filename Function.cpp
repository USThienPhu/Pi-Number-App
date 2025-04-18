#include "Header.hpp"

bool isMouseOver(sf::Sprite &button, sf::RenderWindow& wd)
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(wd);
    sf::FloatRect bounds = button.getGlobalBounds();

    return bounds.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
}




