//
// Created by rudri on 5/17/2022.
//

#ifndef PROGRAM_RENDER_H
#define PROGRAM_RENDER_H

#include <SFML/Graphics.hpp>
#include <string>
using namespace std;

class render {
    sf::RenderWindow* window;
    inline static render* unique = nullptr; // 1. Atributo de clase

    // 2. Constructor Privado
    explicit render(const string& title) {
        window = new sf::RenderWindow(sf::VideoMode(800, 600), title);
    }

public:
    // 3. Metodo de clase
    static render* get_instance(const string& title) {
        if (unique == nullptr) unique = new render(title);
        return unique;
    }
    [[nodiscard]] sf::RenderWindow* get_window() const { return window; }
    ~render() { delete window; }
};


#endif //PROGRAM_RENDER_H
