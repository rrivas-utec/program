//
// Created by rudri on 5/18/2022.
//

#include "button.h"

void button_t::paint() {
        auto rend = render::get_instance("");
        auto window = rend->get_window();
        sf::RectangleShape shape({width, height});
        shape.setPosition(x, y);
        shape.setFillColor(sf::Color::Yellow);
        window->draw(shape);
    }

