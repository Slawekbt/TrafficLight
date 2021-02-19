#include "GreenLight.h"

GreenLight :: GreenLight()
    {
        color = "green"; /* protected from change -- unchangeable */
    }

GreenLight :: ~GreenLight()
    {

    }

 string GreenLight :: get_color(void) const /* no set_color method -- unchangeable */
    {
        return color;
    }

