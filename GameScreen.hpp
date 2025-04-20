#ifndef _GAME_SCREEN_H_
#define _GAME_SCREEN_H_

#include "Screen.hpp"
#include "Button.hpp"
#include "Header.hpp"
#include <memory>
#include <vector>
#include <string>

class GameScreen : public Screen
{
    private:
        sf::Text displayText;
        sf::Font font;
        std::string inputNumber;
        void updateDisplayText();

    public:
        int run(sf::RenderWindow &wd);
        std::vector<std::unique_ptr<Button>> createNumberButtons(sf::RenderWindow &wd, float buttonSize);
};

#endif