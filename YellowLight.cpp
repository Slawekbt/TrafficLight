#include "YellowLight.h"

 YellowLight :: YellowLight()
    {
        color = "yellow";  /* protected from change -- unchangeable */
    }

YellowLight :: ~YellowLight()
    {

    }

string YellowLight :: get_color(void) const /* no set_color method -- unchangeable */
    {
        return color;
    }

