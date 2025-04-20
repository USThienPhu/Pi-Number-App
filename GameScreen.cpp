#include "GameScreen.hpp"
#include <memory>

void GameScreen::updateDisplayText() {
    displayText.setString(inputNumber);
    // Căn giữa text
    sf::FloatRect textBounds = displayText.getLocalBounds();
    displayText.setOrigin(textBounds.width / 2, textBounds.height / 2);
}

int GameScreen::run(sf::RenderWindow &wd)
{
    // Load background
    sf::Texture bgTexture;
    if (!bgTexture.loadFromFile("Asset\\GameBackground.jpg")) {
        std::cerr << "Error: Could not load background texture" << std::endl;
        return -1;
    }
    sf::Sprite backGround(bgTexture);
    backGround.setPosition(0, 0);

    // Load font cho display text
    if (!font.loadFromFile("Asset\\arial.ttf")) {
        font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf");
    }
    displayText.setFont(font);
    displayText.setCharacterSize(50);
    displayText.setFillColor(sf::Color::White);
    displayText.setPosition(wd.getSize().x / 2, 100); // Đặt vị trí ở giữa màn hình, phía trên
    inputNumber = ""; // Khởi tạo chuỗi rỗng
    updateDisplayText();

    // Tạo nút exit
    std::unique_ptr<Button> exitButton = std::make_unique<Button>("Asset\\exit.png");
    exitButton->setPosition(0, 0);

    // Tạo các nút số
    auto numberButtons = createNumberButtons(wd, 100.0f);

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
                if (exitButton->isMouseOver(wd))
                {
                    return 0; // Quay lại màn hình trước
                }
                
                // Kiểm tra xem có nút số nào được nhấn không
                for (int i = 0; i < numberButtons.size(); ++i) {
                    if (numberButtons[i]->isMouseOver(wd)) {
                        inputNumber += std::to_string(i + 1); // Thêm số vào chuỗi
                        updateDisplayText();
                        break;
                    }
                }
            }
        }

        wd.clear();
        wd.draw(backGround);
        wd.draw(displayText); // Vẽ text hiển thị số
        exitButton->draw(wd);

        for (const auto &button : numberButtons)
        {
            button->draw(wd);
        }
        wd.display();
    }
    return -1; // Đóng cửa sổ
}

std::vector<std::unique_ptr<Button>> GameScreen::createNumberButtons(sf::RenderWindow &wd, float buttonSize) {
    std::vector<std::unique_ptr<Button>> numberButtons;
    std::string texturePath = "Asset\\NumberButton.jpg";
    
    // Tạo danh sách các nút số từ 1 đến 9
    for (int i = 1; i <= 9; ++i) {
        auto button = std::make_unique<Button>(texturePath);
        button->setText(std::to_string(i), 20);
        button->setTextColor(sf::Color::White);
        numberButtons.push_back(std::move(button));
    }

    // Đặt vị trí các nút theo dạng lưới 3x3
    float startX = (wd.getSize().x - 3 * buttonSize) / 2; // Căn giữa theo chiều ngang
    float startY = (wd.getSize().y - 3 * buttonSize) / 2; // Căn giữa theo chiều dọc
    startY = startY + 150;
    
    for (int i = 0; i < 9; ++i) {
        float x = startX + (i % 3) * buttonSize; // Cột (0, 1, 2)
        float y = startY + (i / 3) * buttonSize; // Hàng (0, 1, 2)
        numberButtons[i]->setPosition(x, y);
        numberButtons[i]->setScale(0.25f, 0.25f);
    }

    return numberButtons;
}