//
// Created by rudri on 5/13/2022.
//

#include <iostream>
#include "./control/include/control.h"
#include <SFML/Graphics.hpp>

using namespace std;


int main() {
//    utec::run();
    utec::run2();

}

/*
int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    sf::CircleShape circle(30);
    circle.setFillColor(sf::Color::Yellow);
    circle.setPosition(10, 10);

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event{};
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Blue);

        // draw everything here...
         window.draw(circle);

        // end the current frame
        window.display();
    }
    return 0;
}
*/