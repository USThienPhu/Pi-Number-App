#include "GameScreen.hpp"

int GameScreen::run(sf::RenderWindow &wd)
{
    // Load background
    sf::Texture bgTexture;
    bgTexture.loadFromFile("Asset\\GameBackground.jpg");
    sf::Sprite backGround(bgTexture);
    backGround.setPosition(0, 0);

    // Tạo nút exit
    Button exitButton("Asset\\exit.png");
    exitButton.setPosition(0, 0);

    std::vector<Button> numberButtons = createNumberButtons(wd, 100.0f);

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
                if (exitButton.isMouseOver(wd))
                {
                    return 0; // Quay lại màn hình trước
                }
            }
        }

        wd.clear();
        wd.draw(backGround);
        exitButton.draw(wd);
        wd.display();
    }
    return -1; // Đóng cửa sổ
}

std::vector<Button> GameScreen::createNumberButtons(sf::RenderWindow &wd, float buttonSize) {
    std::vector<Button> numberButtons;
    std::string texturePath = "Asset\\NumberButton.jpg";
    // Tạo danh sách các nút số từ 1 đến 9
    for (int i = 1; i <= 9; ++i) {
        Button button(texturePath); // Sử dụng cùng một texture cho tất cả các nút
        numberButtons.push_back(button);
    }

    // Đặt vị trí các nút theo dạng lưới 3x3
    float startX = (wd.getSize().x - 3 * buttonSize) / 2; // Căn giữa theo chiều ngang
    float startY = (wd.getSize().y - 3 * buttonSize) / 2; // Căn giữa theo chiều dọc
    for (int i = 0; i < 9; ++i) {
        float x = startX + (i % 3) * buttonSize; // Cột (0, 1, 2)
        float y = startY + (i / 3) * buttonSize; // Hàng (0, 1, 2)
        numberButtons[i].setPosition(x, y);
    }

    return numberButtons;
}