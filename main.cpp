#include "Header.hpp"


int main()
{
    //Load ảnh vào texture
    sf::FileInputStream stream;
    stream.open("Asset\\Background.jpg");
    sf::Texture tx;
    tx.loadFromStream(stream);
    

    //Lấy size ảnh 
    sf::Sprite sp(tx);
    sf::Vector2u sz = tx.getSize();
    int a_size = sz.x;
    int b_size = sz.y;
    sp.setPosition(0, 0);

    //Mở cửa sổ
    sf::RenderWindow wd(sf::VideoMode(a_size, b_size), "Pi Number");

    while (wd.isOpen())
    {
        sf::Event ev;
        while (wd.pollEvent(ev))
        {
            if (ev.type == sf::Event::Closed)
            {
                wd.close();
            }
        }
        wd.clear();
        wd.draw(sp);
        wd.display();
    }

    return 0;
}
