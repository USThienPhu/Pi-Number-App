#include "Header.hpp"

bool isMouseOver(sf::Sprite &button, sf::RenderWindow& wd)
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(wd);
    sf::FloatRect bounds = button.getGlobalBounds();

    return bounds.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
}


int MenuScreen::run(sf::RenderWindow &wd)
{
    //Load background
    sf::Texture bg;
    bg.loadFromFile("Asset\\Background.jpg");
    sf::Sprite backGround(bg);

    //Load start button
    sf::Texture sb;
    sb.loadFromFile("Asset\\start.png");
    sf::Sprite startButton(sb);

    backGround.setPosition(0, 0);
    startButton.setPosition(0, 0);


    while(wd.isOpen())
    {
        sf::Event event;
        
        while(wd.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                return -1;
            }
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                if (isMouseOver(startButton, wd)) {
                    return 1;
                }
            }

        }

        wd.clear();
        wd.draw(backGround);
        wd.draw(startButton);
        wd.display();
    }
    return -1; // Ensure a return value in case the window closes unexpectedly
}


int GameScreen::run(sf::RenderWindow &wd)
{
    //Load background
    sf::Texture bg;
    bg.loadFromFile("Asset\\GameBackground.jpg");
    sf::Sprite backGround(bg);

    //Load start button
    sf::Texture exb;
    exb.loadFromFile("Asset\\exit.png");
    sf::Sprite exitButton(exb);

    while(wd.isOpen())
    {
        sf::Event event;
        
        while(wd.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                return -1;
            }
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                if (isMouseOver(exitButton, wd)) {
                    return 0;
                }
            }

        }

        wd.clear();
        wd.draw(backGround);
        wd.draw(exitButton);
        wd.display();
    }
    return -1; 
}
