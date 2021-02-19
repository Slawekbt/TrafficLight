#ifndef GREENLIGHT_H
#define GREENLIGHT_H

#include <iostream>
#include "Light.h"

using namespace std;

class GreenLight : public Light
{
public:

    GreenLight();
    ~GreenLight();

    string get_color(void) const; /* no set_color method -- unchangeable */
};

#endif
