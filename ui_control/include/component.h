//
// Created by rudri on 5/18/2022.
//

#ifndef PROGRAM_COMPONENT_H
#define PROGRAM_COMPONENT_H

class component_t {
protected:
    float x = 0;
    float y = 0;
    float height = 0;
    float width = 0;
public:
    component_t(float x, float y, float height, float width);
    virtual void paint() = 0;
};


#endif //PROGRAM_COMPONENT_H
