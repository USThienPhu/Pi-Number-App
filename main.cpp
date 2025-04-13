#include "Header.hpp"


int main()
{
    //Load ảnh vào texture
    sf::FileInputStream stream;
    stream.open("Asset\\Background.jpg");
    sf::Texture tx;
    tx.loadFromStream(stream);
    sf::Font font;
    font.loadFromFile("Asset\\arial.ttf");

    //Lấy size ảnh và tạo Sprite
    sf::Sprite sp(tx);
    sf::Vector2u sz = tx.getSize();
    int a_size = sz.x;
    int b_size = sz.y;
    sp.setPosition(0, 0);

    //Tạo nút
    int btnX = 236;
    float centerX = (a_size - btnX) / 2.0f;

    sf::Texture strBtn;
    strBtn.loadFromFile("Asset\\start.png");
    sf::Sprite startBtn(strBtn);

    startBtn.setPosition(centerX, btnX);


    //Mở cửa sổ
    RenderWindow(sp, a_size, b_size, startBtn);

    return 0;
}
