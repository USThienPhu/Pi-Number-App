#include "Button.hpp"

Button::Button(const std::string &texturePath) {
    texture.loadFromFile(texturePath);
    sprite.setTexture(texture);

    
}

void Button::setPosition(sf::RenderWindow &wd, float offsetY, float offsetX) {
    sf::Vector2u windowSize = wd.getSize();
    sf::FloatRect buttonBounds = sprite.getGlobalBounds();
    float buttonX = (windowSize.x - buttonBounds.width) / 2 + offsetX;
    float buttonY = (windowSize.y - buttonBounds.height) / 2 + offsetY;
    sprite.setPosition(buttonX, buttonY);
}

void Button::draw(sf::RenderWindow &wd) {
    wd.draw(sprite);
}

bool Button::isMouseOver(sf::RenderWindow &wd) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(wd);
    sf::FloatRect bounds = sprite.getGlobalBounds();
    return bounds.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
}

void Button::setPosition(int x, int y) {
    sprite.setPosition(x, y);
}

void Button::setScale(float scaleX, float scaleY) {
    sprite.setScale(scaleX, scaleY); 
}



