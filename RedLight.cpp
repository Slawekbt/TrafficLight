#include "RedLight.h"


RedLight :: RedLight()
    {
        color = "red";   /* protected from change -- unchangeable */
    }

RedLight ::  ~RedLight()
    {

    }

string RedLight :: get_color(void) const /* no set_color method -- unchangeable */
    {
        return color;
    }
