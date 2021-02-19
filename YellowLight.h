#ifndef YELLOWLIGHT_H
#define YELLOWLIGHT_H

#include <iostream>
#include "Light.h"

using namespace std;

class YellowLight : public Light
{

public:

    YellowLight();
    ~YellowLight();

    string get_color(void) const; /* no set_color method -- unchangeable */

};


#endif
