#ifndef REDLIGHT_H
#define REDLIGHT_H

#include <iostream>
#include "Light.h"

using namespace std;

class RedLight : public Light
{

public:

    RedLight();

    ~RedLight();

    string get_color(void) const;  /* no set_color method -- unchangeable */

};

#endif
