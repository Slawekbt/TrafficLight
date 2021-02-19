#ifndef TRAFFICLIGHT_H
#define TRAFFICLIGHT_H

#include <iostream>
#include "RedLight.h"
#include "YellowLight.h"
#include "GreenLight.h"

using namespace std;

class TrafficLight
{

public:

    GreenLight Green;
    YellowLight Yellow;
    RedLight Red;

    TrafficLight();


    void set_coords_auto(int x_start, int y_start); // give first coordinates (of red light), rest will complete automatically


    ~TrafficLight();/* Delete instance -- Delete Red, Yellow and Green, no need for
                       virtual destructors in Red, Yellow and Green because 'has-a-relationship' here */

};

#endif
