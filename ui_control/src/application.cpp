#include "../include/application.h"
#include <iostream>
#include <string>
#include "../include/render.h"
#include "../include/factory.h"

void utec::sfml_application::run() {
    auto render = render::get_instance("Segunda Instancia"); // Obtengo el objeto render
    auto window = render->get_window();
//    sf::CircleShape circle(30);
//    circle.setFillColor(sf::Color::Yellow);
//    circle.setPosition(10, 10);

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
        for (const auto& c: components)
            c->paint();

        // end the current frame
        window->display();
    }
}

utec::sfml_application::sfml_application() {
    auto factory = component_factory::get_instance();
    components.push_back(factory->create_component(
            component_type::Button, 10, 20, 30, 40));
}
