#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "test.hpp"

int main()
{
    test();

#if defined(_DEBUG)
    std::cout << "Hello World!" << std::endl;
#endif

    sf::RenderWindow window;
    window.create(sf::VideoMode(200, 200), "SFML works!");

    sf::CircleShape shape(window.getSize().x / 2);
    shape.setFillColor(sf::Color::White);

    sf::Texture shapeTexture;
    shapeTexture.loadFromFile("resources/sfml.png");
    shape.setTexture(&shapeTexture);

    sf::Event event;

    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
