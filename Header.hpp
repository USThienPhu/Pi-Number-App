#ifndef _Header_H_  
#define _Header_H_

#include <SFML/Graphics.hpp>
#include <iostream> 


void RenderWindow(sf::Sprite sp,sf::Sprite spG, int x, int y, sf::Sprite &startBtn);
bool isMouseOver(sf::Sprite &button, sf::RenderWindow& wd);
enum GameState { MENU, GAME };





#endif