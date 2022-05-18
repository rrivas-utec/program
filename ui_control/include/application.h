#ifndef INC_2_APPLICATION_LAYER_LIBRARY_H
#define INC_2_APPLICATION_LAYER_LIBRARY_H

#include <string>
#include <vector>
#include "component.h"
using namespace std;

namespace utec {
    struct application {
        virtual void run() = 0;
    };


    class sfml_application: application {
        vector<component_t*> components;
    public:
        sfml_application();
        void run() override;
    };
}

#endif //INC_2_APPLICATION_LAYER_LIBRARY_H
