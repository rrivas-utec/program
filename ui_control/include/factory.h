//
// Created by rudri on 5/18/2022.
//

#ifndef PROGRAM_FACTORY_H
#define PROGRAM_FACTORY_H
#include "component.h"
#include "factory.h"
#include "button.h"
#include <functional>
#include <unordered_map>

enum class component_type {
    Button,
    Label
};

using callback_t = std::function<component_t*(float, float, float, float)>;
using callback_map_t = std::unordered_map<component_type, callback_t>;

class component_factory {
    callback_map_t callback_map;
    inline static component_factory* instance = nullptr;
    component_factory() = default;
public:
    static component_factory* get_instance();
    bool register_component(component_type rt, const callback_t& cb);
    bool unregister_component(component_type rt);
    component_t* create_component(component_type rt, float x, float y, float width, float height);
};

#endif //PROGRAM_FACTORY_H
