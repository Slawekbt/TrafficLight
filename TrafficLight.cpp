#include "TrafficLight.h"



    TrafficLight :: TrafficLight()
    {
    }


    void TrafficLight :: set_coords_auto(int x_start, int y_start) // give first coordinates (of red light), rest will complete automaticly
    {
        Red.set_coords(x_start, y_start);
        Yellow.set_coords(x_start, y_start + 1);
        Green.set_coords(x_start, y_start + 2);
    }

    TrafficLight :: ~TrafficLight() /* Delete instance -- Delete Red, Yellow and Green, no need for
                       virtual destructors in Red, Yellow and Green because 'has-a-relationship' here */
    {

    }
