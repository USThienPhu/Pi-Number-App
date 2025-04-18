#include "MenuScreen.hpp"
#include "Button.hpp"

int MenuScreen::run(sf::RenderWindow &wd)
{
    // Tạo background
    sf::Texture bgTexture;
    bgTexture.loadFromFile("Asset\\Background.jpg");
    sf::Sprite backGround(bgTexture);
    backGround.setPosition(0, 0);

    // Tạo nút start
    Button startButton("Asset\\start.png");
    startButton.setPosition(wd, -100, 0);

    while (wd.isOpen())
    {
        sf::Event event;

        while (wd.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                return -1;
            }
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
            {
                if (startButton.isMouseOver(wd))
                {
                    return 1; // Chuyển sang màn hình tiếp theo
                }
            }
        }

        wd.clear();
        wd.draw(backGround);
        startButton.draw(wd);
        wd.display();
    }
    return -1; // Đóng cửa sổ
}


