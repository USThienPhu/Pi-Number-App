#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <SFML/Graphics.hpp>
#include <string>

class Button {
private:
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Text text;
    sf::Font font;
    std::string texturePath;

public:
    Button(const std::string &texturePath);
    ~Button() = default;
    
    // Ngăn chặn sao chép
    Button(const Button&) = delete;
    Button& operator=(const Button&) = delete;
    
    void setPosition(sf::RenderWindow &wd, float offsetY = 0.0f, float offsetX = 0.0f);
    void setPosition(int x, int y);
    void draw(sf::RenderWindow &wd) const;
    void setScale(float scaleX, float scaleY);
    bool isMouseOver(sf::RenderWindow &wd) const;
    void setText(const std::string &str, unsigned int characterSize = 30);
    void setTextColor(const sf::Color &color);
};

#endif