//
// Created by rudri on 5/18/2022.
//

#include "../include/factory.h"

bool component_factory::register_component(component_type rt, const callback_t& cb) {
    auto [_, result] = callback_map.insert({rt, cb});
    return result;
}

bool component_factory::unregister_component(component_type rt) {
    auto iter = callback_map.find(rt);
    return iter != end(callback_map);
}

component_t *component_factory::create_component(component_type rt, float x, float y, float width, float height) {
    return callback_map.at(rt)(x, y, width, height);
}

component_factory *component_factory::get_instance() {
    if (instance == nullptr) instance = new component_factory();
    return instance;
}

component_t* create_button(float x, float y, float width, float height) {
    return new button_t(x, y, width, height);
}
bool registered = component_factory::get_instance()->
        register_component(component_type::Button, create_button);
