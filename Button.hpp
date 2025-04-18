#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <SFML/Graphics.hpp>

class Button {
private:
    sf::Sprite sprite;
    sf::Texture texture;
    

public:
    Button(const std::string &texturePath);
    void setPosition(sf::RenderWindow &wd, float offsetY = 0.0f, float offsetX = 0.0f);
    void setPosition(int x, int y);
    void draw(sf::RenderWindow &wd);
    void setScale(float scaleX, float scaleY);
    bool isMouseOver(sf::RenderWindow &wd);
};

#endif