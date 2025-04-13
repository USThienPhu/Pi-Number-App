#ifndef _Header_H_  
#define _Header_H_

#include <SFML/Graphics.hpp>
#include <iostream> 

bool isMouseOver(sf::Sprite &button, sf::RenderWindow& wd);
enum GameState { MENU, GAME };



class Screen
{
    private:
    public:
        virtual int run(sf::RenderWindow &wd) = 0;
        virtual ~Screen() = default;
};

class MenuScreen : public Screen
{
    private:
    public:
        int run(sf::RenderWindow &wd);
};

class GameScreen : public Screen
{
    private:
    public:
        int run(sf::RenderWindow &wd);
};



#endif