#include <SFML/Graphics.hpp>
#include <iostream> 

int main()
{
    sf::FileInputStream stream;
    if (!stream.open("Asset\\Background.jpg"))
    {
        std::cerr << "Failed to open file stream" << std::endl; 
        return -1;
    }
    sf::Texture tx;
    if (!tx.loadFromStream(stream))
    {
        std::cerr << "Failed to load image from stream" << std::endl; 
        return -1;
    }

    sf::Sprite sp(tx);
    sf::Vector2u sz = tx.getSize();
    int a_size = sz.x;
    int b_size = sz.y;

    sp.setPosition(0, 0);
    sf::RenderWindow wd(sf::VideoMode(a_size, b_size), "Nheo Phu");

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
