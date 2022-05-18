#include "../include/control.h"
#include <iostream>
#include <string>
#include "../include/render.h"



void utec::run() {
    auto render = render::get_instance("Primera Instancia"); // Obtengo el objeto render
    auto window = render->get_window();
//    sf::CircleShape circle(30);
//    circle.setFillColor(sf::Color::Yellow);
//    circle.setPosition(10, 10);
//
//    // run the program as long as the window is open
//    while (window->isOpen())
//    {
//        // check all the window's events that were triggered since the last iteration of the loop
//        sf::Event event{};
//        while (window->pollEvent(event))
//        {
//            // "close requested" event: we close the window
//            if (event.type == sf::Event::Closed)
//                window->close();
//        }
//
//        // clear the window with black color
//        window->clear(sf::Color::Blue);
//
//        // draw everything here...
//        window->draw(circle);
//
//        // end the current frame
//        window->display();
//    }
}

void utec::run2() {
    auto render = render::get_instance("Segunda Instancia"); // Obtengo el objeto render
    auto window = render->get_window();
    sf::CircleShape circle(30);
    circle.setFillColor(sf::Color::Yellow);
    circle.setPosition(10, 10);

    // run the program as long as the window is open
    while (window->isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event{};
        while (window->pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window->close();
        }

        // clear the window with black color
        window->clear(sf::Color::Blue);

        // draw everything here...
        window->draw(circle);

        // end the current frame
        window->display();
    }
}
