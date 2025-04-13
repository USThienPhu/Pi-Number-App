#include "Header.hpp"


int main() {
    sf::RenderWindow window(sf::VideoMode(442, 786), "Game");

    std::vector<Screen*> screens;
    screens.push_back(new MenuScreen());
    screens.push_back(new GameScreen());

    int currentScreen = 0;

    while(currentScreen >= 0 && currentScreen < screens.size())
    {
        currentScreen = screens[currentScreen]->run(window);
        
    }


    
    return 0;
}