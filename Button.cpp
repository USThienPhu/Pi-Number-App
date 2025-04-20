#include "Button.hpp"
#include <iostream>

Button::Button(const std::string &texturePath) {
    if (!texture.loadFromFile(texturePath)) {
        // Nếu không load được texture, thoát chương trình
        std::cerr << "Error: Could not load texture from " << texturePath << std::endl;
        exit(1);
    }
    sprite.setTexture(texture);
    
    // Load font
    if (!font.loadFromFile("Asset\\arial.ttf")) {
        // Nếu không tìm thấy font, tạo font mặc định
        font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf");
    }
    text.setFont(font);
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::White);
}

void Button::setPosition(sf::RenderWindow &wd, float offsetY, float offsetX) {
    sf::Vector2u windowSize = wd.getSize();
    sf::FloatRect buttonBounds = sprite.getGlobalBounds();
    float buttonX = (windowSize.x - buttonBounds.width) / 2 + offsetX;
    float buttonY = (windowSize.y - buttonBounds.height) / 2 + offsetY;
    sprite.setPosition(buttonX, buttonY);
    
    // Center text on button
    sf::FloatRect textBounds = text.getLocalBounds();
    text.setPosition(buttonX + (buttonBounds.width - textBounds.width) / 2,
                    buttonY + (buttonBounds.height - textBounds.height) / 2 - 5);
}

void Button::setPosition(int x, int y) {
    sprite.setPosition(x, y);
    
    // Center text on button
    sf::FloatRect buttonBounds = sprite.getGlobalBounds();
    sf::FloatRect textBounds = text.getLocalBounds();
    text.setPosition(x + (buttonBounds.width - textBounds.width) / 2,
                    y + (buttonBounds.height - textBounds.height) / 2 - 5);
}

void Button::draw(sf::RenderWindow &wd) const {
    wd.draw(sprite);
    wd.draw(text);
}

bool Button::isMouseOver(sf::RenderWindow &wd) const {
    sf::Vector2i mousePos = sf::Mouse::getPosition(wd);
    sf::FloatRect bounds = sprite.getGlobalBounds();
    return bounds.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
}

void Button::setScale(float scaleX, float scaleY) {
    sprite.setScale(scaleX, scaleY);
    // Update text position after scaling
    sf::Vector2f pos = sprite.getPosition();
    sf::FloatRect buttonBounds = sprite.getGlobalBounds();
    sf::FloatRect textBounds = text.getLocalBounds();
    text.setPosition(pos.x + (buttonBounds.width - textBounds.width) / 2,
                    pos.y + (buttonBounds.height - textBounds.height) / 2 - 5);
}

void Button::setText(const std::string &str, unsigned int characterSize) {
    text.setString(str);
    text.setCharacterSize(characterSize);
    // Update text position
    sf::Vector2f pos = sprite.getPosition();
    sf::FloatRect buttonBounds = sprite.getGlobalBounds();
    sf::FloatRect textBounds = text.getLocalBounds();
    text.setPosition(pos.x + (buttonBounds.width - textBounds.width) / 2,
                    pos.y + (buttonBounds.height - textBounds.height) / 2 - 5);
}

void Button::setTextColor(const sf::Color &color) {
    text.setFillColor(color);
}



