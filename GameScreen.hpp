#ifndef _GAME_SCREEN_H_
#define _GAME_SCREEN_H_

#include "Screen.hpp"
#include "Button.hpp"
#include "Header.hpp"

class GameScreen : public Screen
{
    private:
    public:
        int run(sf::RenderWindow &wd);
        std::vector<Button> createNumberButtons(sf::RenderWindow &wd, float buttonSize);
};


#endif