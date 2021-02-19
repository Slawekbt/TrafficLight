#ifndef PEDESTRIANTRAFFICLIGHT_H
#define PEDESTRIANTRAFFICLIGHT_H

#include <iostream>
#include "RedLight.h"
#include "GreenLight.h"

using namespace std;

class PedestrianTrafficLight
{
public:

    GreenLight Green;
    RedLight Red;

    PedestrianTrafficLight();
    ~PedestrianTrafficLight();

    void set_coords_auto(int x_start, int y_start); // give first coordinates (of red light), rest will complete automaticly


};

#endif
