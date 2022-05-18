//
// Created by rudri on 5/18/2022.
//

#ifndef PROGRAM_BUTTON_H
#define PROGRAM_BUTTON_H

#include "component.h"
#include "render.h"

class button_t: public component_t {
public:
    using component_t::component_t;
    void paint() override;
};


#endif //PROGRAM_BUTTON_H
