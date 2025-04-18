#ifndef _MENU_SCREEN_H_
#define _MENU_SCREEN_H_

#include "Screen.hpp"
#include "Button.hpp"


class MenuScreen : public Screen
{
private: 

public:
    int run(sf::RenderWindow &wd);
};


#endif