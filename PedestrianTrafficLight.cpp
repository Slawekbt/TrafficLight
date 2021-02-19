#include "PedestrianTrafficLight.h"



PedestrianTrafficLight :: PedestrianTrafficLight()
    {

    }


PedestrianTrafficLight :: ~PedestrianTrafficLight()
    {}

void PedestrianTrafficLight :: set_coords_auto(int x_start, int y_start) // give first coordinates (of red light), rest will complete automaticly
    {
        Red.set_coords(x_start, y_start);
        Green.set_coords(x_start, y_start + 1);
    }
