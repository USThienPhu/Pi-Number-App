#ifndef _SCREEN_H_
#define _SCREEN_H_

#include <SFML/Graphics.hpp>

class Screen
{
    private:
    public:
        virtual int run(sf::RenderWindow &wd) = 0;
        virtual ~Screen() = default;
};

#endif